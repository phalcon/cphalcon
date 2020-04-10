
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
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Interpolator_IndexedArray) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate\\Interpolator, IndexedArray, phalcon, translate_interpolator_indexedarray, phalcon_translate_interpolator_indexedarray_method_entry, 0);

	zend_class_implements(phalcon_translate_interpolator_indexedarray_ce, 1, phalcon_translate_interpolator_interpolatorinterface_ce);
	return SUCCESS;

}

/**
 * Replaces placeholders by the values passed
 */
PHP_METHOD(Phalcon_Translate_Interpolator_IndexedArray, replacePlaceholders) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *translation_param = NULL, *placeholders_param = NULL, _0$$3;
	zval translation;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&placeholders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translation_param, &placeholders_param);

	if (UNEXPECTED(Z_TYPE_P(translation_param) != IS_STRING && Z_TYPE_P(translation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translation' must be of the type string"));
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


	if (zephir_fast_count_int(&placeholders)) {
		ZEPHIR_MAKE_REF(&placeholders);
		ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 499, &placeholders, &translation);
		ZEPHIR_UNREF(&placeholders);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "sprintf");
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0$$3, &placeholders);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(&translation);

}

