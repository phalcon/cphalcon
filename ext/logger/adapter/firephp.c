
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#include "logger/adapter/firephp.h"
#include "logger/adapter.h"
#include "logger/adapterinterface.h"
#include "logger/formatter/firephp.h"

#include <main/SAPI.h>
#include <ext/standard/php_smart_str.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"

/**
 * Phalcon\Logger\Adapter\Firephp
 *
 * Sends logs to FirePHP
 *
 *<code>
 *	$logger = new \Phalcon\Logger\Adapter\Firephp("");
 *	$logger->log("This is a message");
 *	$logger->log("This is an error", \Phalcon\Logger::ERROR);
 *	$logger->error("This is another error");
 *</code>
 */
zend_class_entry *phalcon_logger_adapter_firephp_ce;

PHP_METHOD(Phalcon_Logger_Adapter_Firephp, getFormatter);
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, logInternal);
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, close);

static const zend_function_entry phalcon_logger_adapter_firephp_method_entry[] = {
	PHP_ME(Phalcon_Logger_Adapter_Firephp, getFormatter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Firephp, logInternal, arginfo_phalcon_logger_adapter_loginternal, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger_Adapter_Firephp, close, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Logger\Adapter\Firephp initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Adapter_Firephp){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, Firephp, logger_adapter_firephp, phalcon_logger_adapter_ce, phalcon_logger_adapter_firephp_method_entry, 0);

	zend_declare_property_bool(phalcon_logger_adapter_firephp_ce, SL("_initialized"), 0, ZEND_ACC_PRIVATE | ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_long(phalcon_logger_adapter_firephp_ce, SL("_index"), 1, ZEND_ACC_PRIVATE | ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(phalcon_logger_adapter_firephp_ce TSRMLS_CC, 1, phalcon_logger_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Returns the internal formatter
 *
 * @return Phalcon\Logger\FormatterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, getFormatter){

	zval *formatter;

	formatter = phalcon_fetch_nproperty_this(this_ptr, SL("_formatter"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(formatter) != IS_OBJECT) {
		object_init_ex(return_value, phalcon_logger_formatter_firephp_ce);
		phalcon_update_property_this(this_ptr, SL("_formatter"), return_value TSRMLS_CC);
		return;
	}

	RETURN_ZVAL(formatter, 1, 0);
}

/**
 * Writes the log to the stream itself
 *
 * @param string $message
 * @param int $type
 * @param int $time
 * @param array $context
 * @see http://www.firephp.org/Wiki/Reference/Protocol
 */
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, logInternal){

	zval *message, *type, *time, *context, *formatter = NULL, *applied_format = NULL;
	zval *initialized, *index;
	sapi_header_line h = { NULL, 0, 0 };
	smart_str str      = { NULL, 0, 0 };
	int size, offset;
	int separate_index = 0;
	size_t num_bytes;
	const int chunk = 4500;

	/* If headers has already been sent, we can do nothing. Exit early. */
	if (SG(headers_sent)) {
		RETURN_FALSE;
	}

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &message, &type, &time, &context);

	PHALCON_CALL_METHOD(&formatter, this_ptr, "getformatter");

	initialized = phalcon_fetch_static_property_ce(phalcon_logger_adapter_firephp_ce, SL("_initialized") TSRMLS_CC);
	if (!zend_is_true(initialized)) {
		/**
		 * Send the required initialization headers.
		 * Use Zend API here so that the user can see the progress and because
		 * if we delegate this to Phalcon and there will be a fatal errors,
		 * chances are that the headers will never ne sent.
		 */
		h.line     = "X-Wf-Protocol-1: http://meta.wildfirehq.org/Protocol/JsonStream/0.2";
		h.line_len = sizeof("X-Wf-Protocol-1: http://meta.wildfirehq.org/Protocol/JsonStream/0.2")-1;
		sapi_header_op(SAPI_HEADER_REPLACE, &h TSRMLS_CC);

		h.line     = "X-Wf-1-Plugin-1: http://meta.firephp.org/Wildfire/Plugin/FirePHP/Library-FirePHPCore/0.3";
		h.line_len = sizeof("X-Wf-1-Plugin-1: http://meta.firephp.org/Wildfire/Plugin/FirePHP/Library-FirePHPCore/0.3")-1;
		sapi_header_op(SAPI_HEADER_REPLACE, &h TSRMLS_CC);

		h.line     = "X-Wf-1-Structure-1: http://meta.firephp.org/Wildfire/Structure/FirePHP/FirebugConsole/0.1";
		h.line_len = sizeof("X-Wf-1-Structure-1: http://meta.firephp.org/Wildfire/Structure/FirePHP/FirebugConsole/0.1")-1;
		sapi_header_op(SAPI_HEADER_REPLACE, &h TSRMLS_CC);

		ZVAL_TRUE(initialized); /* This will also update the property because "initialized" was not separated */
	}

	PHALCON_CALL_METHOD(&applied_format, formatter, "format", message, type, time, context);
	convert_to_string(applied_format);

	index = phalcon_fetch_static_property_ce(phalcon_logger_adapter_firephp_ce, SL("_index") TSRMLS_CC);
	assert(Z_TYPE_P(index) == IS_LONG);

	if (Z_REFCOUNT_P(index) > 1) {
		PHALCON_INIT_VAR(index);
		separate_index = 1;
	}

	size   = Z_STRLEN_P(applied_format);
	offset = 0;

	/**
	 * We need to send the data in chunks not exceeding 5,000 bytes.
	 * Allocate the smart string once to avoid performance penalties.
	 */
	smart_str_alloc4(&str, (uint)(size > chunk ? chunk : size), 0, num_bytes);

	while (size > 0) {
		smart_str_appends(&str, "X-Wf-1-1-1-");
		smart_str_append_long(&str, Z_LVAL_P(index));
		smart_str_appends(&str, ": ");
		num_bytes = size > chunk ? chunk : size;

		if (offset) {
			/* This is not the first chunk, prepend the payload with "|" */
			smart_str_appendc(&str, '|');
		}

		/* Grab the chunk from the encoded string */
		smart_str_appendl(&str, Z_STRVAL_P(applied_format) + offset, num_bytes);

		size   -= num_bytes;
		offset += num_bytes;

		if (size) {
			/* If we have more data to send, append "|/" */
			smart_str_appendl(&str, "|\\", 2);
		}

		smart_str_0(&str); /* Not strictly necessary but just to be safe */

		/* Send the result */
		h.line     = str.c;
		h.line_len = str.len;
		sapi_header_op(SAPI_HEADER_REPLACE, &h TSRMLS_CC);

		ZVAL_LONG(index, Z_LVAL_P(index)+1);

		/**
		 * Do not free and then reallocate memory. Just pretend the string
		 * is empty. We will take care of deallocation later.
		 */
		str.len = 0;
	}

	if (separate_index) {
		phalcon_update_static_property_ce(phalcon_logger_adapter_firephp_ce, SL("_index"), index TSRMLS_CC);
	}

	/* Deallocate the smnart string if it is not empty */
	if (str.c) {
		smart_str_free(&str);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Closes the logger
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, close){

	RETURN_TRUE;
}

