
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

	zend_class_implements(phalcon_translate_interpolator_associativearray_ce TSRMLS_CC, 1, phalcon_translate_interpolator_interpolatorinterface_ce);
	return SUCCESS;

}

/**
 * Replaces placeholders by the values passed
 */
PHP_METHOD(Phalcon_Translate_Interpolator_AssociativeArray, replacePlaceholders) {

	zend_string *_2;
	zend_ulong _1;
	zval placeholders;
	zval *translation_param = NULL, *placeholders_param = NULL, key, value, *_0, _3$$3, _4$$3;
	zval translation;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&placeholders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translation_param, &placeholders_param);

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
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	zephir_is_iterable(&placeholders, 0, "phalcon/Translate/Interpolator/AssociativeArray.zep", 32);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&placeholders), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SVS(&_4$$3, "%", &key, "%");
		zephir_fast_str_replace(&_3$$3, &_4$$3, &value, &translation TSRMLS_CC);
		zephir_get_strval(&translation, &_3$$3);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&translation);

}

