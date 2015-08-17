
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


/**
 * Phalcon\Translate\Adapter\NativeArray
 *
 * Allows to define translation lists using PHP arrays
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_NativeArray) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, NativeArray, phalcon, translate_adapter_nativearray, phalcon_translate_adapter_ce, phalcon_translate_adapter_nativearray_method_entry, 0);

	zend_declare_property_null(phalcon_translate_adapter_nativearray_ce, SL("_translate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_translate_adapter_nativearray_ce TSRMLS_CC, 1, phalcon_translate_adapterinterface_ce);
	zend_class_implements(phalcon_translate_adapter_nativearray_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Phalcon\Translate\Adapter\NativeArray constructor
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL, *data;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	options = options_param;



	ZEPHIR_CALL_PARENT(NULL, phalcon_translate_adapter_nativearray_ce, this_ptr, "__construct", &_0, 425, options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(data);
	if (!(zephir_array_isset_string_fetch(&data, options, SS("content"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Translation content was not provided", "phalcon/translate/adapter/nativearray.zep", 46);
		return;
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Translation data must be an array", "phalcon/translate/adapter/nativearray.zep", 50);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_translate"), data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the translation related to the given key
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, query) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *placeholders = NULL, *translation = NULL, *_0;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index_param, &placeholders);

	if (unlikely(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}
	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(translation);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_translate"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&translation, _0, index, 0 TSRMLS_CC))) {
		ZEPHIR_CPY_WRT(translation, index);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, 0, translation, placeholders);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether is defined a translation key in the internal array
 */
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, exists) {

	zval *index_param = NULL, *_0;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (unlikely(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_translate"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, index));

}

