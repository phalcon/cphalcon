
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

#include "logger/formatter/firephp.h"
#include "logger/formatter.h"
#include "logger/formatterinterface.h"

#include <ext/standard/php_smart_str.h>
#include <Zend/zend_builtin_functions.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"


/**
 * Phalcon\Logger\Formatter\Firephp
 *
 * Formats messages so that they can be sent to FirePHP
 */
zend_class_entry *phalcon_logger_formatter_firephp_ce;

PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getTypeString);
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getShowBacktrace);
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, setShowBacktrace);
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, enableLabels);
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, labelsEnabled);
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, format);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_firephp_empty, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_firephp_setshowbacktrace, 0, 0, 0)
	ZEND_ARG_INFO(0, show)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_firephp_enablelabels, 0, 0, 0)
	ZEND_ARG_INFO(0, enable)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_logger_formatter_firephp_method_entry[] = {
	PHP_ME(Phalcon_Logger_Formatter_Firephp, getTypeString, arginfo_phalcon_logger_formatter_gettypestring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, getShowBacktrace, arginfo_phalcon_logger_formatter_firephp_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, setShowBacktrace, arginfo_phalcon_logger_formatter_firephp_setshowbacktrace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, enableLabels, arginfo_phalcon_logger_formatter_firephp_enablelabels, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, labelsEnabled, arginfo_phalcon_logger_formatter_firephp_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, format, arginfo_phalcon_logger_formatterinterface_format, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Logger\Formatter\Firephp initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Formatter_Firephp){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Firephp, logger_formatter_firephp, phalcon_logger_formatter_ce, phalcon_logger_formatter_firephp_method_entry, 0);

	zend_declare_property_bool(phalcon_logger_formatter_firephp_ce, SL("_showBacktrace"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_logger_formatter_firephp_ce, SL("_enableLabels"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_logger_formatter_firephp_ce TSRMLS_CC, 1, phalcon_logger_formatterinterface_ce);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getShowBacktrace) {

	RETURN_MEMBER(getThis(), "_showBacktrace");
}

PHP_METHOD(Phalcon_Logger_Formatter_Firephp, setShowBacktrace) {

	zval **show;

	phalcon_fetch_params_ex(1, 0, &show);

	PHALCON_ENSURE_IS_BOOL(show);
	phalcon_update_property_this(getThis(), SL("_showBacktrace"), *show TSRMLS_CC);
}

PHP_METHOD(Phalcon_Logger_Formatter_Firephp, enableLabels) {

	zval **enable;

	phalcon_fetch_params_ex(1, 0, &enable);

	PHALCON_ENSURE_IS_BOOL(enable);
	phalcon_update_property_this(getThis(), SL("_enableLabels"), *enable TSRMLS_CC);
}

PHP_METHOD(Phalcon_Logger_Formatter_Firephp, labelsEnabled) {

	RETURN_MEMBER(getThis(), "_enableLabels");
}

/**
 * Returns the string meaning of a logger constant
 *
 * @param  integer $type
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getTypeString) {

	static const char* lut[10] = {
		"ERROR", "ERROR", "WARN", "ERROR", "WARN",
		"INFO",  "INFO",  "LOG",  "INFO",  "LOG"
	};

	zval **type;
	int itype;

	phalcon_fetch_params_ex(1, 0, &type);
	PHALCON_ENSURE_IS_LONG(type);

	itype = Z_LVAL_PP(type);
	if (itype > 0 && itype < 10) {
		RETURN_STRING(lut[itype], 1);
	}

	RETURN_STRING("CUSTOM", 1);
}

/**
 * Applies a format to a message before sending it to the log
 *
 * @param string $message
 * @param int $type
 * @param int $timestamp
 * @param array $context
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_Firephp, format) {

	zval *message, *type, *type_str = NULL, *timestamp, *context, *interpolated = NULL;
	zval *payload, *body, *backtrace = NULL, *meta, *encoded;
	zval *show_backtrace, *enable_labels;
	int i_show_backtrace, i_enable_labels;
	smart_str result = { NULL, 0, 0 };
	uint i;
	Bucket *p;

	phalcon_fetch_params(0, 4, 0, &message, &type, &timestamp, &context);

	/*
	 * We intentionally do not use Phalcon's MM for better performance.
	 * All variables allocated with ALLOC_INIT_ZVAL() will have
	 * their reference count set to 1 and therefore they can be nicely
	 * put into the result array; when that array will be destroyed,
	 * all inserted variables will be automatically destroyed, too
	 * and we will just save some time by not using Z_ADDREF_P and Z_DELREF_P
	 */

	if (Z_TYPE_P(context) == IS_ARRAY) {
		PHALCON_CALL_METHODW(&interpolated, this_ptr, "interpolate", message, context);
	}
	else {
		interpolated = message;
		Z_ADDREF_P(interpolated);
	}

	{
		zval *params[] = { type };
		if (FAILURE == phalcon_call_method(&type_str, this_ptr, "gettypestring", 1, params TSRMLS_CC)) {
			zval_ptr_dtor(&interpolated);
			return;
		}
	}

	show_backtrace   = phalcon_fetch_nproperty_this(getThis(), SL("_showBacktrace"), PH_NOISY TSRMLS_CC);
	enable_labels    = phalcon_fetch_nproperty_this(getThis(), SL("_enableLabels"), PH_NOISY TSRMLS_CC);
	i_show_backtrace = zend_is_true(show_backtrace);
	i_enable_labels  = zend_is_true(enable_labels);

	/*
	 * Get the backtrace. This differs for different PHP versions.
	 * 5.3.6+ allows us to skip the function arguments which will save some memory
	 * For 5.4+ there is an extra argument.
	 */
	if (i_show_backtrace) {
		ALLOC_INIT_ZVAL(backtrace);

#if PHP_VERSION_ID < 50306
		zend_fetch_debug_backtrace(backtrace, 1, 0 TSRMLS_CC);
#elif PHP_VERSION_ID < 50400
		zend_fetch_debug_backtrace(backtrace, 1, DEBUG_BACKTRACE_IGNORE_ARGS TSRMLS_CC);
#else
		zend_fetch_debug_backtrace(backtrace, 1, DEBUG_BACKTRACE_IGNORE_ARGS, 0 TSRMLS_CC);
#endif

		if (Z_TYPE_P(backtrace) == IS_ARRAY) {
			HashPosition pos;
			HashTable *ht = Z_ARRVAL_P(backtrace);
			zval **ppzval;
			int found = 0;
			ulong idx;
			char *key;
			uint key_len;

			/*
			 * At this point we know that the backtrace is the array.
			 * Again, we intentionally do not use Phalcon's API because we know
			 * that we are working with the array / hash table and thus we can
			 * save some time by omitting Z_TYPE_P(x) == IS_ARRAY checks
			 */

			for (
				zend_hash_internal_pointer_reset_ex(ht, &pos);
				zend_hash_has_more_elements_ex(ht, &pos) == SUCCESS;
			) {
				zend_hash_get_current_data_ex(ht, (void**)&ppzval, &pos);
				zend_hash_get_current_key_ex(ht, &key, &key_len, &idx, 0, &pos);
				zend_hash_move_forward_ex(ht, &pos);

				if (Z_TYPE_PP(ppzval) == IS_ARRAY) {
					/*
					 * Here we need to skip the latest calls into Phalcon's core.
					 * Calls to Zend internal functions will have "file" index not set.
					 * We remove these entries from the array.
					 */
					if (!found && !zend_hash_quick_exists(Z_ARRVAL_PP(ppzval), SS("file"), zend_inline_hash_func(SS("file")))) {
						zend_hash_index_del(ht, idx);
					}
					else {
						/*
						 * Remove args and object indices. They usually give
						 * too much information; this is not suitable to send
						 * in the HTTP headers
						 */
						zend_hash_quick_del(Z_ARRVAL_PP(ppzval), "args", sizeof("args"), zend_inline_hash_func(SS("args")));
						zend_hash_quick_del(Z_ARRVAL_PP(ppzval), "object", sizeof("object"), zend_inline_hash_func(SS("object")));
						found = 1;
					}
				}
			}

			/*
			 * Now we need to renumber the hash table because we removed several
			 * heading elements. If we don't do this, json_encode() will convert
			 * this array to a JavaScript object which is an unwanted side effect
			 */
			p = ht->pListHead;
			i = 0;
			while (p != NULL) {
				p->nKeyLength = 0;
				p->h = i++;
				p = p->pListNext;
			}

			ht->nNextFreeElement = i;
			zend_hash_rehash(ht);
		}
	}

	/*
	 * The result will looks like this:
	 *
	 * array(
	 *     array('Type' => 'message type', 'Label' => 'message'),
	 *     array('backtrace' => array(backtrace goes here)
	 * )
	 */
	MAKE_STD_ZVAL(payload);
	array_init_size(payload, 2);

	MAKE_STD_ZVAL(meta);
	array_init_size(meta, 4);
	add_assoc_zval_ex(meta, SS("Type"), type_str);

	if (i_show_backtrace && Z_TYPE_P(backtrace) == IS_ARRAY) {
		zval **ppzval;

		if (likely(SUCCESS == zend_hash_index_find(Z_ARRVAL_P(backtrace), 0, (void**)&ppzval)) && likely(Z_TYPE_PP(ppzval) == IS_ARRAY)) {
			zval **file = NULL, **line = NULL;

			zend_hash_quick_find(Z_ARRVAL_PP(ppzval), SS("file"), zend_inline_hash_func(SS("file")), (void**)&file);
			zend_hash_quick_find(Z_ARRVAL_PP(ppzval), SS("line"), zend_inline_hash_func(SS("line")), (void**)&line);

			if (likely(file != NULL)) {
				Z_ADDREF_PP(file);
				add_assoc_zval_ex(meta, SS("File"), *file);
			}

			if (likely(line != NULL)) {
				Z_ADDREF_PP(line);
				add_assoc_zval_ex(meta, SS("Line"), *line);
			}
		}
	}

	if (i_enable_labels) {
		add_assoc_zval_ex(meta, SS("Label"), interpolated);
	}

	if (!i_enable_labels && !i_show_backtrace) {
		body = interpolated;
	}
	else if (i_enable_labels && !i_show_backtrace) {
		MAKE_STD_ZVAL(body);
		ZVAL_EMPTY_STRING(body);
	}
	else {
		MAKE_STD_ZVAL(body);
		array_init_size(body, 2);

		if (i_show_backtrace) {
			add_assoc_zval_ex(body, SS("backtrace"), backtrace);
		}

		if (!i_enable_labels) {
			add_assoc_zval_ex(body, SS("message"), interpolated);
		}
	}

	add_next_index_zval(payload, meta);
	add_next_index_zval(payload, body);

	/* Convert everything to JSON */
	ALLOC_INIT_ZVAL(encoded);
	if (FAILURE == phalcon_json_encode(encoded, payload, 0 TSRMLS_CC)) {
		zval_ptr_dtor(&payload);
		zval_ptr_dtor(&encoded);
		return;
	}

	/* As promised, kill the payload and all associated elements */
	zval_ptr_dtor(&payload);

	/*
	 * We don't want to use Phalcon's concatenation API because it
	 * requires the memory manager. Therefore we fall back to using smart strings.
	 * smart_str_alloc4() will allocate all required memory amount (plus some more)
	 * in one go and this allows us to avoid performance penalties due to
	 * memory reallocations.
	 */
	if (Z_TYPE_P(encoded) == IS_STRING && Z_STRVAL_P(encoded) != NULL) {
		smart_str_alloc4(&result, (uint)(Z_STRLEN_P(encoded) + 2 + 5), 0, i);

		/*
		 * The format is:
		 *
		 * <size>|[meta,body]|
		 *
		 * Meta and body are contained in encoded inside the array, as required
		 * by the protocol specification
		 * @see http://www.firephp.org/Wiki/Reference/Protocol
		 */
		smart_str_append_long(&result, Z_STRLEN_P(encoded));
		smart_str_appendc(&result, '|');
		smart_str_appendl(&result, Z_STRVAL_P(encoded), Z_STRLEN_P(encoded));
		smart_str_appendc(&result, '|');
		smart_str_0(&result);
	}

	/* We don't need the JSON message anymore */
	zval_ptr_dtor(&encoded);
	/* Do not free the smart string because we steal its data for zval */
	RETURN_STRINGL(result.c, result.len, 0);
}
