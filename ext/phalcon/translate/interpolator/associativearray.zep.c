
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
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Interpolator_AssociativeArray) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate\\Interpolator, AssociativeArray, phalcon, translate_interpolator_associativearray, phalcon_translate_interpolator_associativearray_method_entry, 0);

	zend_class_implements(phalcon_translate_interpolator_associativearray_ce TSRMLS_CC, 1, phalcon_translate_interpolatorinterface_ce);
	return SUCCESS;

}

/**
 * Replaces placeholders by the values passed
 */
PHP_METHOD(Phalcon_Translate_Interpolator_AssociativeArray, replacePlaceholders) {

	zend_string *_4$$3;
	zend_ulong _3$$3;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *translation_param = NULL, *placeholders = NULL, placeholders_sub, __$null, key, value, *_1$$3, _2$$3, _5$$4, _6$$4, _7$$5, _8$$5;
	zval translation;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&placeholders_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translation_param, &placeholders);

	if (UNEXPECTED(Z_TYPE_P(translation_param) != IS_STRING && Z_TYPE_P(translation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translation' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(translation_param) == IS_STRING)) {
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
		_0 = ((zephir_fast_count_int(placeholders TSRMLS_CC)) ? 1 : 0);
	}
	if (_0) {
		zephir_is_iterable(placeholders, 0, "phalcon/translate/interpolator/associativearray.zep", 29);
		if (Z_TYPE_P(placeholders) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(placeholders), _3$$3, _4$$3, _1$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_4$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _4$$3);
				} else {
					ZVAL_LONG(&key, _3$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _1$$3);
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZEPHIR_INIT_LNVAR(_6$$4);
				ZEPHIR_CONCAT_SVS(&_6$$4, "%", &key, "%");
				zephir_fast_str_replace(&_5$$4, &_6$$4, &value, &translation TSRMLS_CC);
				zephir_get_strval(&translation, &_5$$4);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, placeholders, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, placeholders, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, placeholders, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, placeholders, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_7$$5);
					ZEPHIR_INIT_LNVAR(_8$$5);
					ZEPHIR_CONCAT_SVS(&_8$$5, "%", &key, "%");
					zephir_fast_str_replace(&_7$$5, &_8$$5, &value, &translation TSRMLS_CC);
					zephir_get_strval(&translation, &_7$$5);
				ZEPHIR_CALL_METHOD(NULL, placeholders, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	}
	RETURN_CTOR(&translation);

}

