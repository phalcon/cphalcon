
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * Phalcon\Translate\Adapter
 *
 * Base class for Phalcon\Translate adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate, Adapter, phalcon, translate_adapter, phalcon_translate_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var Phalcon\Translate\InterpolatorInterface
	 */
	zend_declare_property_null(phalcon_translate_adapter_ce, SL("_interpolator"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Translate_Adapter, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, interpolator;
	zval options;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&interpolator);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZEPHIR_OBS_VAR_ONCE(&options);
	ZVAL_COPY(&options, options_param);


	ZEPHIR_OBS_VAR(&interpolator);
	if (!(zephir_array_isset_string_fetch(&interpolator, &options, SL("interpolator"), 0))) {
		ZEPHIR_INIT_NVAR(&interpolator);
		object_init_ex(&interpolator, phalcon_translate_interpolator_associativearray_ce);
		if (zephir_has_constructor(&interpolator TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &interpolator, "__construct", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setinterpolator", NULL, 0, &interpolator);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Translate_Adapter, setInterpolator) {

	zval *interpolator, interpolator_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&interpolator_sub);

	zephir_fetch_params(0, 1, 0, &interpolator);



	zephir_update_property_zval(this_ptr, SL("_interpolator"), interpolator);
	RETURN_THISW();

}

/**
 * Returns the translation string of the given key
 *
 * @param string  translateKey
 * @param array   placeholders
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter, t) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *translateKey_param = NULL, *placeholders = NULL, placeholders_sub, __$null;
	zval translateKey;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&translateKey);
	ZVAL_UNDEF(&placeholders_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translateKey_param, &placeholders);

	if (unlikely(Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(translateKey_param) == IS_STRING)) {
		zephir_get_strval(&translateKey, translateKey_param);
	} else {
		ZEPHIR_INIT_VAR(&translateKey);
		ZVAL_EMPTY_STRING(&translateKey);
	}
	if (!placeholders) {
		placeholders = &placeholders_sub;
		placeholders = &__$null;
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, &translateKey, placeholders);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the translation string of the given key (alias of method 't')
 *
 * @param string  translateKey
 * @param array   placeholders
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter, _) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *translateKey_param = NULL, *placeholders = NULL, placeholders_sub, __$null;
	zval translateKey;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&translateKey);
	ZVAL_UNDEF(&placeholders_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translateKey_param, &placeholders);

	if (unlikely(Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(translateKey_param) == IS_STRING)) {
		zephir_get_strval(&translateKey, translateKey_param);
	} else {
		ZEPHIR_INIT_VAR(&translateKey);
		ZVAL_EMPTY_STRING(&translateKey);
	}
	if (!placeholders) {
		placeholders = &placeholders_sub;
		placeholders = &__$null;
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, &translateKey, placeholders);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets a translation value
 *
 * @param string offset
 * @param string value
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetSet) {

	zval *offset, offset_sub, *value, value_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 2, 0, &offset, &value);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_translate_exception_ce, "Translate is an immutable ArrayAccess object", "phalcon/translate/adapter.zep", 86);
	return;

}

/**
 * Check whether a translation key exists
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *translateKey_param = NULL;
	zval translateKey;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&translateKey);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &translateKey_param);

	if (unlikely(Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(translateKey_param) == IS_STRING)) {
		zephir_get_strval(&translateKey, translateKey_param);
	} else {
		ZEPHIR_INIT_VAR(&translateKey);
		ZVAL_EMPTY_STRING(&translateKey);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "exists", NULL, 0, &translateKey);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unsets a translation from the dictionary
 *
 * @param string offset
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetUnset) {

	zval *offset, offset_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&offset_sub);

	zephir_fetch_params(0, 1, 0, &offset);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_translate_exception_ce, "Translate is an immutable ArrayAccess object", "phalcon/translate/adapter.zep", 104);
	return;

}

/**
 * Returns the translation related to the given key
 *
 * @param  string translateKey
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *translateKey_param = NULL, _0;
	zval translateKey;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&translateKey);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &translateKey_param);

	if (unlikely(Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(translateKey_param) == IS_STRING)) {
		zephir_get_strval(&translateKey, translateKey_param);
	} else {
		ZEPHIR_INIT_VAR(&translateKey);
		ZVAL_EMPTY_STRING(&translateKey);
	}


	ZVAL_NULL(&_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, &translateKey, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Replaces placeholders by the values passed
 */
PHP_METHOD(Phalcon_Translate_Adapter, replacePlaceholders) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *translation_param = NULL, *placeholders = NULL, placeholders_sub, __$null, _0;
	zval translation;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&placeholders_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translation_param, &placeholders);

	if (unlikely(Z_TYPE_P(translation_param) != IS_STRING && Z_TYPE_P(translation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(translation_param) == IS_STRING)) {
		zephir_get_strval(&translation, translation_param);
	} else {
		ZEPHIR_INIT_VAR(&translation);
		ZVAL_EMPTY_STRING(&translation);
	}
	if (!placeholders) {
		placeholders = &placeholders_sub;
		placeholders = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_interpolator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "replaceplaceholders", NULL, 0, &translation, placeholders);
	zephir_check_call_status();
	RETURN_MM();

}

