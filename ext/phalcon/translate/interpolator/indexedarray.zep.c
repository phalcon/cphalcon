
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Interpolator_IndexedArray) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate\\Interpolator, IndexedArray, phalcon, translate_interpolator_indexedarray, phalcon_translate_interpolator_indexedarray_method_entry, 0);

	zend_class_implements(phalcon_translate_interpolator_indexedarray_ce TSRMLS_CC, 1, phalcon_translate_interpolatorinterface_ce);
	return SUCCESS;

}

/**
 * Replaces placeholders by the values passed
 */
PHP_METHOD(Phalcon_Translate_Interpolator_IndexedArray, replacePlaceholders) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *translation_param = NULL, *placeholders = NULL, placeholders_sub, __$null, _1$$3;
	zval translation;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&placeholders_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$3);

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
		ZEPHIR_MAKE_REF(placeholders);
		ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 391, placeholders, &translation);
		ZEPHIR_UNREF(placeholders);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "sprintf");
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_1$$3, placeholders);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(&translation);

}

