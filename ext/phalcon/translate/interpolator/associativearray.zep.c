
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
#include "kernel/hash.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Phalcon_Translate_Interpolator_AssociativeArray) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate\\Interpolator, AssociativeArray, phalcon, translate_interpolator_associativearray, phalcon_translate_interpolator_associativearray_method_entry, 0);

	zend_class_implements(phalcon_translate_interpolator_associativearray_ce TSRMLS_CC, 1, phalcon_translate_interpolatorinterface_ce);
	return SUCCESS;

}

/**
 * Replaces placeholders by the values passed
 */
PHP_METHOD(Phalcon_Translate_Interpolator_AssociativeArray, replacePlaceholders) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zend_bool _0;
	zval *translation_param = NULL, *placeholders = NULL, placeholders_sub, __$null, key, value, *_1$$3, _4$$4, _5$$4;
	zval translation;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&placeholders_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

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


	_0 = Z_TYPE_P(placeholders) == IS_ARRAY;
	if (_0) {
		_0 = (zephir_fast_count_int(placeholders TSRMLS_CC)) ? 1 : 0;
	}
	if (_0) {
		zephir_is_iterable(placeholders, 0, "phalcon/translate/interpolator/associativearray.zep", 38);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(placeholders), _2$$3, _3$$3, _1$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _3$$3);
			} else {
				ZVAL_LONG(&key, _2$$3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1$$3);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SVS(&_5$$4, "%", &key, "%");
			zephir_fast_str_replace(&_4$$4, &_5$$4, &value, &translation TSRMLS_CC);
			zephir_get_strval(&translation, &_4$$4);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	}
	RETURN_CTOR(translation);

}

