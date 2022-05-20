
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


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
 * $logger = new \Phalcon\Logger\Adapter\Stream('app/logs/test.log');
 *
 * $logger->log('This is a message');
 * $logger->log(\Phalcon\Logger::ERROR, 'This is an error');
 * $logger->error('This is another error');
 *
 * $logger->close();
 *```
 *
 * @property resource|null $handler
 * @property string        $mode
 * @property string        $name
 * @property array         $options
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
	 * The file open mode. Defaults to 'ab'
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
 * Stream constructor.
 *
 * @param string $name
 * @param array  $options
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *name_param = NULL, *options_param = NULL, mode, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
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
	zephir_get_strval(&name, name_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	if (1 == zephir_array_isset_string(&options, SL("mode"))) {
		ZEPHIR_OBS_VAR(&mode);
		zephir_array_fetch_string(&mode, &options, SL("mode"), PH_NOISY, "phalcon/Logger/Adapter/Stream.zep", 82);
	} else {
		ZEPHIR_INIT_NVAR(&mode);
		ZVAL_STRING(&mode, "ab");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "r");
	ZEPHIR_CALL_FUNCTION(&_1, "mb_strpos", NULL, 82, &mode, &_0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Adapter cannot be opened in read mode", "phalcon/Logger/Adapter/Stream.zep", 84);
		return;
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
 *
 * @param Item $item
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, process)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, __$null, message, _0, _9, _10, _11, _1$$3, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4, _7$$4, _8$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
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
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("mode"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "phpfopen", NULL, 0, &_2$$3, &_3$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &_1$$3);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
		if (!(Z_TYPE_P(&_4$$3) == IS_RESOURCE)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &__$null);
			ZEPHIR_INIT_VAR(&_5$$4);
			object_init_ex(&_5$$4, spl_ce_LogicException);
			zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_7$$4, this_ptr, ZEND_STRL("mode"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_8$$4);
			ZEPHIR_CONCAT_SVSVS(&_8$$4, "The file '", &_6$$4, "' cannot be opened with mode '", &_7$$4, "'");
			ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 401, &_8$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$4, "phalcon/Logger/Adapter/Stream.zep", 128);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "getformatteditem", NULL, 0, item);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_GET_CONSTANT(&_10, "PHP_EOL");
	ZEPHIR_INIT_VAR(&message);
	ZEPHIR_CONCAT_VV(&message, &_9, &_10);
	zephir_read_property(&_11, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	zephir_fwrite(NULL, &_11, &message);
	ZEPHIR_MM_RESTORE();
}

/**
 * @todo to be removed when we get traits
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filename_param = NULL, *mode_param = NULL;
	zval filename, mode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&mode);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &filename_param, &mode_param);
	zephir_get_strval(&filename, filename_param);
	zephir_get_strval(&mode, mode_param);


	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 134, &filename, &mode);
	zephir_check_call_status();
	RETURN_MM();
}

