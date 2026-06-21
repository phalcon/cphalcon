
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/file.h"


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
 * $logger->log(\Phalcon\Logger\Enum::ERROR, 'This is an error');
 * $logger->error('This is another error');
 *
 * $logger->close();
 *```
 *
 * @property resource|null $handler
 * @property string        $mode
 * @property string        $name
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
	return SUCCESS;
}

/**
 * Stream constructor.
 *
 * @param string $name
 * @param array  $options
 *
 * @throws InvalidStreamMode
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval name_zv, *options_param = NULL, mode, _0, _1, _2$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		options_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	if (1 == zephir_array_isset_value_string(&options, SL("mode"))) {
		zephir_memory_observe(&mode);
		zephir_array_fetch_string(&mode, &options, SL("mode"), PH_NOISY, "phalcon/Logger/Adapter/Stream.zep", 74);
	} else {
		ZEPHIR_INIT_NVAR(&mode);
		ZVAL_STRING(&mode, "ab");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "r");
	ZEPHIR_CALL_FUNCTION(&_1, "mb_strpos", NULL, 179, &mode, &_0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_logger_adapter_exceptions_invalidstreammode_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Logger/Adapter/Stream.zep", 76);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("mode"), &mode);
	ZEPHIR_MM_RESTORE();
}

/**
 * Closes the stream
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, close)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$null, handler, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&handler, &_1$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &__$null);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phpfclose", NULL, 0, &handler);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);
}

/**
 * Stream name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, getName)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
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
	zval *item, item_sub, __$null, fileHandler, message, _0, _6, _7, _8, _1$$3, _2$$3, _3$$4, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&fileHandler);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &item);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_RESOURCE)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("mode"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&fileHandler, this_ptr, "phpfopen", NULL, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
		if (!(Z_TYPE_P(&fileHandler) == IS_RESOURCE)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &__$null);
			ZEPHIR_INIT_VAR(&_3$$4);
			object_init_ex(&_3$$4, phalcon_logger_adapter_exceptions_fileopenfailed_ce);
			zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("mode"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 0, &_4$$4, &_5$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$4, "phalcon/Logger/Adapter/Stream.zep", 124);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &fileHandler);
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getformatteditem", NULL, 0, item);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_GET_CONSTANT(&_7, "PHP_EOL");
	ZEPHIR_INIT_VAR(&message);
	ZEPHIR_CONCAT_VV(&message, &_6, &_7);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "phpfwrite", NULL, 0, &_8, &message);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @todo to be removed when we get traits
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, phpFclose)
{
	zval *handle, handle_sub;

	ZVAL_UNDEF(&handle_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle);
	RETURN_BOOL(zephir_fclose(handle));
}

/**
 * @todo to be removed when we get traits
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, mode_zv;
	zend_string *filename = NULL, *mode = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&mode_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	zephir_memory_observe(&mode_zv);
	ZVAL_STR_COPY(&mode_zv, mode);
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 251, &filename_zv, &mode_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @todo to be removed when we get traits
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, phpFwrite)
{
	zend_string *message = NULL;
	zval *handle, handle_sub, message_zv;

	ZVAL_UNDEF(&handle_sub);
	ZVAL_UNDEF(&message_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(handle)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	handle = ZEND_CALL_ARG(execute_data, 1);
	ZVAL_STR(&message_zv, message);
	zephir_fwrite(return_value, handle, &message_zv);
	return;
}

