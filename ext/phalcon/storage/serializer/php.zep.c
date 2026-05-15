
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Php)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Serializer, Php, phalcon, storage_serializer_php, phalcon_storage_serializer_abstractserializer_ce, phalcon_storage_serializer_php_method_entry, 0);

	return SUCCESS;
}

/**
 * Serializes data
 *
 * @return string
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, serialize)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isserializable", NULL, 0, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_MEMBER_TYPED(getThis(), "data", IS_STRING);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 16, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Unserializes data
 *
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, unserialize)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data_sub, __$false, __$true, result, _0, _1, _2, _3;
	zval *data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isserializable", NULL, 0, data);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), data);
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_gettype(&_1, data);
	if (UNEXPECTED(!ZEPHIR_IS_STRING(&_1, "string"))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Data for the unserializer must of type string", "phalcon/Storage/Serializer/Php.zep", 49);
		return;
	}
	ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$false);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_closure_ex(&_2, NULL, phalcon_80__closure_ce, SL("__invoke"));
	ZVAL_LONG(&_3, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 150, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, this_ptr, "phpunserialize", NULL, 0, data);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 151);
	zephir_check_call_status();
	_4 = ZEPHIR_GLOBAL(warning).enable;
	if (!(_4)) {
		_4 = ZEPHIR_IS_FALSE_IDENTICAL(&result);
	}
	if (UNEXPECTED(_4)) {
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("isSuccess"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("isSuccess"), &__$false);
		}
		ZEPHIR_INIT_NVAR(&result);
		ZVAL_STRING(&result, "");
	} else {
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("isSuccess"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("isSuccess"), &__$false);
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &result);
	ZEPHIR_MM_RESTORE();
}

/**
 * @param string $data
 * @param array  $options
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, phpUnserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval data_zv, *options_param = NULL;
	zend_string *data = NULL;

	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		options_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("unserialize", NULL, 21, &data_zv, &options);
	zephir_check_call_status();
	RETURN_MM();
}

