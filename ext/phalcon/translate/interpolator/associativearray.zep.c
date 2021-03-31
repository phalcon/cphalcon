
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
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Interpolator_AssociativeArray) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate\\Interpolator, AssociativeArray, phalcon, translate_interpolator_associativearray, phalcon_translate_interpolator_associativearray_method_entry, 0);

	zend_class_implements(phalcon_translate_interpolator_associativearray_ce, 1, phalcon_translate_interpolator_interpolatorinterface_ce);
	return SUCCESS;

}

/**
 * Replaces placeholders by the values passed
 */
PHP_METHOD(Phalcon_Translate_Interpolator_AssociativeArray, replacePlaceholders) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *translation_param = NULL, *placeholders_param = NULL, key, value, *_0, _1, _4$$3, _5$$3, _6$$4, _7$$4;
	zval translation;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&placeholders);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(translation)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(placeholders)
	ZEND_PARSE_PARAMETERS_END();

#endif


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


	zephir_is_iterable(&placeholders, 0, "phalcon/Translate/Interpolator/AssociativeArray.zep", 32);
	if (Z_TYPE_P(&placeholders) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&placeholders), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZEPHIR_CONCAT_SVS(&_5$$3, "%", &key, "%");
			zephir_fast_str_replace(&_4$$3, &_5$$3, &value, &translation);
			zephir_get_strval(&translation, &_4$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &placeholders, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &placeholders, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &placeholders, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &placeholders, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZEPHIR_CONCAT_SVS(&_7$$4, "%", &key, "%");
				zephir_fast_str_replace(&_6$$4, &_7$$4, &value, &translation);
				zephir_get_strval(&translation, &_6$$4);
			ZEPHIR_CALL_METHOD(NULL, &placeholders, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&translation);

}

