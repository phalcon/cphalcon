
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


ZEPHIR_INIT_CLASS(Phalcon_Translate_Interpolator_AssociativeArray) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate\\Interpolator, AssociativeArray, phalcon, translate_interpolator_associativearray, phalcon_translate_interpolator_associativearray_method_entry, 0);

	zend_class_implements(phalcon_translate_interpolator_associativearray_ce TSRMLS_CC, 1, phalcon_translate_interpolatorinterface_ce);
	return SUCCESS;

}

/**
 * Replaces placeholders by the values passed
 */
PHP_METHOD(Phalcon_Translate_Interpolator_AssociativeArray, replacePlaceholders) {

	HashTable *_2$$3;
	HashPosition _1$$3;
	zend_bool _0;
	zval *translation_param = NULL, *placeholders = NULL, *key = NULL, *value = NULL, **_3$$3, *_4$$4 = NULL, *_5$$4 = NULL;
	zval *translation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &translation_param, &placeholders);

	if (UNEXPECTED(Z_TYPE_P(translation_param) != IS_STRING && Z_TYPE_P(translation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'translation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(translation_param) == IS_STRING)) {
		zephir_get_strval(translation, translation_param);
	} else {
		ZEPHIR_INIT_VAR(translation);
		ZVAL_EMPTY_STRING(translation);
	}
	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(placeholders) == IS_ARRAY;
	if (_0) {
		_0 = ((zephir_fast_count_int(placeholders TSRMLS_CC)) ? 1 : 0);
	}
	if (_0) {
		zephir_is_iterable(placeholders, &_2$$3, &_1$$3, 0, 0, "phalcon/translate/interpolator/associativearray.zep", 38);
		for (
		  ; zend_hash_get_current_data_ex(_2$$3, (void**) &_3$$3, &_1$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_2$$3, &_1$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _2$$3, _1$$3);
			ZEPHIR_GET_HVALUE(value, _3$$3);
			ZEPHIR_INIT_NVAR(_4$$4);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SVS(_5$$4, "%", key, "%");
			zephir_fast_str_replace(&_4$$4, _5$$4, value, translation TSRMLS_CC);
			zephir_get_strval(translation, _4$$4);
		}
	}
	RETURN_CTOR(translation);

}

