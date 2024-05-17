
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
#include "kernel/operators.h"
#include "kernel/object.h"
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
 * Class NativeArray
 *
 * Defines translation lists using PHP arrays
 *
 * @package Phalcon\Translate\Adapter
 *
 * @property array $translate
 * @property bool  $triggerError
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_NativeArray)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, NativeArray, phalcon, translate_adapter_nativearray, phalcon_translate_adapter_abstractadapter_ce, phalcon_translate_adapter_nativearray_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_translate_adapter_nativearray_ce, SL("translate"), ZEND_ACC_PRIVATE);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_translate_adapter_nativearray_ce, SL("triggerError"), 0, ZEND_ACC_PRIVATE);
	phalcon_translate_adapter_nativearray_ce->create_object = zephir_init_properties_Phalcon_Translate_Adapter_NativeArray;

	zend_class_implements(phalcon_translate_adapter_nativearray_ce, 1, zend_ce_arrayaccess);
	return SUCCESS;
}

/**
 * NativeArray constructor.
 *
 * @param InterpolatorFactory $interpolator
 * @param array               $options = [
 *                                'content'      => '',
 *                                'triggerError' => false
 *                            ]
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *interpolator, interpolator_sub, *options_param = NULL, __$true, __$false, data, error;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interpolator_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(interpolator, phalcon_translate_interpolatorfactory_ce)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &interpolator, &options_param);
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	ZEPHIR_CALL_PARENT(NULL, phalcon_translate_adapter_nativearray_ce, getThis(), "__construct", NULL, 0, interpolator, &options);
	zephir_check_call_status();
	zephir_memory_observe(&data);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&data, &options, SL("content"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Translation content was not provided", "phalcon/Translate/Adapter/NativeArray.zep", 58);
		return;
	}
	zephir_memory_observe(&error);
	if (zephir_array_isset_string_fetch(&error, &options, SL("triggerError"), 0)) {
		if (zephir_get_boolval(&error)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("triggerError"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("triggerError"), &__$false);
		}
	}
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Translation data must be an array", "phalcon/Translate/Adapter/NativeArray.zep", 66);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("translate"), &data);
	ZEPHIR_MM_RESTORE();
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param string $index
 *
 * @return bool
 * @deprecated
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, exists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &index_param);
	if (UNEXPECTED(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(&index, index_param);
	} else {
		ZEPHIR_INIT_VAR(&index);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &index);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param string $index
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index_param = NULL, _0;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &index_param);
	if (UNEXPECTED(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(&index, index_param);
	} else {
		ZEPHIR_INIT_VAR(&index);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("translate"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &index));
}

/**
 * Whenever a key is not found this method will be called
 *
 * @param string $index
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, notFound)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, _0, _1$$3;
	zval index, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &index_param);
	if (UNEXPECTED(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(&index, index_param);
	} else {
		ZEPHIR_INIT_VAR(&index);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("triggerError"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_translate_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Cannot find translation key: ", &index);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 33, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Translate/Adapter/NativeArray.zep", 108);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&index);
}

/**
 * Returns the translation related to the given key
 *
 * @param string $translateKey
 * @param array  $placeholders
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, query)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *translateKey_param = NULL, *placeholders_param = NULL, translation, _0;
	zval translateKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey);
	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(translateKey)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(placeholders)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &translateKey_param, &placeholders_param);
	if (UNEXPECTED(Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(translateKey_param) == IS_STRING)) {
		zephir_get_strval(&translateKey, translateKey_param);
	} else {
		ZEPHIR_INIT_VAR(&translateKey);
	}
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}
	zephir_memory_observe(&translation);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("translate"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&translation, &_0, &translateKey, 0))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "notfound", NULL, 0, &translateKey);
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
 * @return array
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, toArray)
{

	RETURN_MEMBER(getThis(), "translate");
}

zend_object *zephir_init_properties_Phalcon_Translate_Adapter_NativeArray(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("translate"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("translate"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

