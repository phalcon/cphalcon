
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Defines translation lists using PHP arrays
 *
 * @phpstan-import-type translate_array_options from TranslateTypes
 * @phpstan-import-type translate_data from TranslateTypes
 * @phpstan-import-type translate_placeholders from TranslateTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_NativeArray)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, NativeArray, phalcon, translate_adapter_nativearray, phalcon_translate_adapter_abstractadapter_ce, phalcon_translate_adapter_nativearray_method_entry, 0);

	/**
	 * @phpstan-var translate_data
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_translate_adapter_nativearray_ce, SL("translate"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

/**
 * NativeArray constructor.
 *
 * @phpstan-param translate_array_options $options
 *
 * @throws InvalidDataType
 * @throws MissingContent
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *interpolator, interpolator_sub, *options_param = NULL, data, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interpolator_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("translate", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(interpolator, phalcon_translate_interpolatorfactory_ce)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &interpolator, &options_param);
	zephir_get_arrval(&options, options_param);
	ZEPHIR_CALL_PARENT(NULL, phalcon_translate_adapter_nativearray_ce, getThis(), "__construct", NULL, 0, interpolator, &options);
	zephir_check_call_status();
	zephir_memory_observe(&data);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&data, &options, SL("content"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_translate_exceptions_missingcontent_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Translate/Adapter/NativeArray.zep", 50);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_translate_exceptions_invaliddatatype_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Translate/Adapter/NativeArray.zep", 54);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1393, &data);
	ZEPHIR_MM_RESTORE();
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @deprecated
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, exists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval index_zv;
	zend_string *index = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&index_zv);
	ZVAL_STR_COPY(&index_zv, index);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &index_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check whether is defined a translation key in the internal array
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, has)
{
	zval index_zv, _0;
	zend_string *index = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("translate", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&index_zv, index);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1393, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, &index_zv));
}

/**
 * Returns the translation related to the given key
 *
 * @phpstan-param translate_placeholders $placeholders
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, query)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval translateKey_zv, *placeholders_param = NULL, translation, _0;
	zend_string *translateKey = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey_zv);
	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("translate", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(translateKey)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(placeholders, placeholders_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		placeholders_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&translateKey_zv);
	ZVAL_STR_COPY(&translateKey_zv, translateKey);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}
	zephir_memory_observe(&translation);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1393, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&translation, &_0, &translateKey_zv, 0))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "notfound", NULL, 0, &translateKey_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, 0, &translation, &placeholders);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the internal array
 *
 * @phpstan-return translate_data
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, toArray)
{

	RETURN_MEMBER_TYPED(getThis(), "translate", IS_ARRAY);
}

