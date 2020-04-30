
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
 * Phalcon\Translate\Adapter\NativeArray
 *
 * Allows to define translation lists using PHP arrays
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_NativeArray) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, NativeArray, phalcon, translate_adapter_nativearray, phalcon_translate_adapter_abstractadapter_ce, phalcon_translate_adapter_nativearray_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_translate_adapter_nativearray_ce, SL("translate"), ZEND_ACC_PRIVATE);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_translate_adapter_nativearray_ce, SL("triggerError"), 0, ZEND_ACC_PRIVATE);

	zend_class_implements(phalcon_translate_adapter_nativearray_ce, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Phalcon\Translate\Adapter\NativeArray constructor
 *
 * @param array options = [
 *     'content' => '',
 *     'triggerError' => false
 * ]
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval options;
	zval *interpolator, interpolator_sub, *options_param = NULL, __$true, __$false, data, error;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interpolator_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &interpolator, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	ZEPHIR_CALL_PARENT(NULL, phalcon_translate_adapter_nativearray_ce, getThis(), "__construct", &_0, 0, interpolator, &options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&data);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&data, &options, SL("content"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Translation content was not provided", "phalcon/Translate/Adapter/NativeArray.zep", 49);
		return;
	}
	ZEPHIR_OBS_VAR(&error);
	if (zephir_array_isset_string_fetch(&error, &options, SL("triggerError"), 0)) {
		if (zephir_get_boolval(&error)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("triggerError"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("triggerError"), &__$false);
		}
	}
	if (UNEXPECTED(Z_TYPE_P(&data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Translation data must be an array", "phalcon/Translate/Adapter/NativeArray.zep", 57);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("translate"), &data);
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether is defined a translation key in the internal array
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, exists) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index_param = NULL, _0;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (UNEXPECTED(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(&index, index_param);
	} else {
		ZEPHIR_INIT_VAR(&index);
		ZVAL_EMPTY_STRING(&index);
	}


	zephir_read_property(&_0, this_ptr, SL("translate"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &index));

}

/**
 * Whenever a key is not found this method will be called
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, notFound) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, _0, _1$$3;
	zval index, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (UNEXPECTED(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(&index, index_param);
	} else {
		ZEPHIR_INIT_VAR(&index);
		ZVAL_EMPTY_STRING(&index);
	}


	zephir_read_property(&_0, this_ptr, SL("triggerError"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_translate_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Cannot find translation key: ", &index);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 6, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Translate/Adapter/NativeArray.zep", 77);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&index);

}

/**
 * Returns the translation related to the given key
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, query) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *index_param = NULL, *placeholders_param = NULL, translation, _0;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index_param, &placeholders_param);

	if (UNEXPECTED(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(&index, index_param);
	} else {
		ZEPHIR_INIT_VAR(&index);
		ZVAL_EMPTY_STRING(&index);
	}
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	ZEPHIR_OBS_VAR(&translation);
	zephir_read_property(&_0, this_ptr, SL("translate"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&translation, &_0, &index, 0))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "notfound", NULL, 0, &index);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, 0, &translation, &placeholders);
	zephir_check_call_status();
	RETURN_MM();

}

