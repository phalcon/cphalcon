
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Translate\Adapter
 *
 * Base class for Phalcon\Translate adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate, Adapter, phalcon, translate_adapter, phalcon_translate_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

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
	zval *translateKey_param = NULL, *placeholders = NULL;
	zval *translateKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translateKey_param, &placeholders);

	if (unlikely(Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(translateKey_param) == IS_STRING)) {
		zephir_get_strval(translateKey, translateKey_param);
	} else {
		ZEPHIR_INIT_VAR(translateKey);
		ZVAL_EMPTY_STRING(translateKey);
	}
	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, translateKey, placeholders);
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
	zval *translateKey_param = NULL, *placeholders = NULL;
	zval *translateKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translateKey_param, &placeholders);

	if (unlikely(Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(translateKey_param) == IS_STRING)) {
		zephir_get_strval(translateKey, translateKey_param);
	} else {
		ZEPHIR_INIT_VAR(translateKey);
		ZVAL_EMPTY_STRING(translateKey);
	}
	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, translateKey, placeholders);
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

	zval *offset, *value;

	zephir_fetch_params(0, 2, 0, &offset, &value);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_translate_exception_ce, "Translate is an immutable ArrayAccess object", "phalcon/translate/adapter.zep", 64);
	return;

}

/**
 * Check whether a translation key exists
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *translateKey_param = NULL;
	zval *translateKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &translateKey_param);

	if (unlikely(Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(translateKey_param) == IS_STRING)) {
		zephir_get_strval(translateKey, translateKey_param);
	} else {
		ZEPHIR_INIT_VAR(translateKey);
		ZVAL_EMPTY_STRING(translateKey);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "exists", NULL, 0, translateKey);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unsets a translation from the dictionary
 *
 * @param string offset
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetUnset) {

	zval *offset;

	zephir_fetch_params(0, 1, 0, &offset);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_translate_exception_ce, "Translate is an immutable ArrayAccess object", "phalcon/translate/adapter.zep", 82);
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
	zval *translateKey_param = NULL, *_0;
	zval *translateKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &translateKey_param);

	if (unlikely(Z_TYPE_P(translateKey_param) != IS_STRING && Z_TYPE_P(translateKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translateKey' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(translateKey_param) == IS_STRING)) {
		zephir_get_strval(translateKey, translateKey_param);
	} else {
		ZEPHIR_INIT_VAR(translateKey);
		ZVAL_EMPTY_STRING(translateKey);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_NULL(_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, translateKey, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Replaces placeholders by the values passed	
 */
PHP_METHOD(Phalcon_Translate_Adapter, replacePlaceholders) {

	HashTable *_1;
	HashPosition _0;
	zval *translation_param = NULL, *placeholders = NULL, *key = NULL, *value = NULL, **_2, *_3 = NULL, *_4 = NULL;
	zval *translation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translation_param, &placeholders);

	if (unlikely(Z_TYPE_P(translation_param) != IS_STRING && Z_TYPE_P(translation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(translation_param) == IS_STRING)) {
		zephir_get_strval(translation, translation_param);
	} else {
		ZEPHIR_INIT_VAR(translation);
		ZVAL_EMPTY_STRING(translation);
	}
	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(placeholders) == IS_ARRAY) {
		if (zephir_fast_count_int(placeholders TSRMLS_CC)) {
			zephir_is_iterable(placeholders, &_1, &_0, 0, 0, "phalcon/translate/adapter.zep", 108);
			for (
			  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			  ; zephir_hash_move_forward_ex(_1, &_0)
			) {
				ZEPHIR_GET_HMKEY(key, _1, _0);
				ZEPHIR_GET_HVALUE(value, _2);
				ZEPHIR_INIT_NVAR(_3);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "%", key, "%");
				zephir_fast_str_replace(&_3, _4, value, translation TSRMLS_CC);
				zephir_get_strval(translation, _3);
			}
		}
	}
	RETURN_CTOR(translation);

}

