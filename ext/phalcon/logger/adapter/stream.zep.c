
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Logger\Adapter\Stream
 *
 * Adapter to store logs in plain text files
 *
 *```php
 * $logger = new \Phalcon\Logger\Adapter\Stream("app/logs/test.log");
 *
 * $logger->log("This is a message");
 * $logger->log(\Phalcon\Logger::ERROR, "This is an error");
 * $logger->error("This is another error");
 *
 * $logger->close();
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Stream)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, Stream, phalcon, logger_adapter_stream, phalcon_logger_adapter_abstractadapter_ce, phalcon_logger_adapter_stream_method_entry, 0);

	/**
	 * Stream handler resource
	 *
	 * @var resource|null
	 */
	zend_declare_property_null(phalcon_logger_adapter_stream_ce, SL("handler"), ZEND_ACC_PROTECTED);
	/**
	 * The file open mode. Defaults to "ab"
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_adapter_stream_ce, SL("mode"), "ab", ZEND_ACC_PROTECTED);
	/**
	 * Stream name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_logger_adapter_stream_ce, SL("name"), ZEND_ACC_PROTECTED);
	/**
	 * Path options
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_logger_adapter_stream_ce, SL("options"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Stream name
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, getName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "name");
}

/**
 * Constructor. Accepts the name and some options
 *
 * @param array options = [
 *     'mode' => 'ab'
 * ]
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zval *name_param = NULL, *options_param = NULL, mode;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &options_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_OBS_VAR(&mode);
	if (zephir_array_isset_string_fetch(&mode, &options, SL("mode"), 0)) {
		if (zephir_memnstr_str(&mode, SL("r"), "phalcon/Logger/Adapter/Stream.zep", 79)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Adapter cannot be opened in read mode", "phalcon/Logger/Adapter/Stream.zep", 80);
			return;
		}
	}
	if (Z_TYPE_P(&mode) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&mode);
		ZVAL_STRING(&mode, "ab");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	zephir_update_property_zval(this_ptr, ZEND_STRL("mode"), &mode);
	ZEPHIR_MM_RESTORE();
}

/**
 * Closes the stream
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, close)
{
	zend_bool result;
	zval __$null, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);



	result = 1;
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_RESOURCE) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
		result = zephir_fclose(&_1$$3);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &__$null);
	RETURN_BOOL(result);
}

/**
 * Processes the message i.e. writes it to the file
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, process)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, __$null, message, _0, _10, _1$$3, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_RESOURCE)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("mode"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "fopen", NULL, 90, &_1$$3, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &_3$$3);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
		if (!(Z_TYPE_P(&_4$$3) == IS_RESOURCE)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &__$null);
			ZEPHIR_INIT_VAR(&_5$$4);
			object_init_ex(&_5$$4, spl_ce_UnexpectedValueException);
			zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_7$$4, this_ptr, ZEND_STRL("mode"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "The file '%s' cannot be opened with mode '%s'");
			ZEPHIR_CALL_FUNCTION(&_9$$4, "sprintf", NULL, 135, &_8$$4, &_6$$4, &_7$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 361, &_9$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$4, "phalcon/Logger/Adapter/Stream.zep", 127);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD(&message, this_ptr, "getformatteditem", NULL, 0, item);
	zephir_check_call_status();
	zephir_read_property(&_10, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	zephir_fwrite(NULL, &_10, &message);
	ZEPHIR_MM_RESTORE();
}

