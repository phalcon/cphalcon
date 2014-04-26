
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/object.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Tag\Select
 *
 * Generates a SELECT html tag using a static array of values or a Phalcon\Mvc\Model resultset
 */
ZEPHIR_INIT_CLASS(Phalcon_Tag_Select) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Tag, Select, phalcon, tag_select, phalcon_tag_select_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Generates a SELECT tag
 *
 * @param array parameters
 * @param array data
 */
PHP_METHOD(Phalcon_Tag_Select, selectField) {

	zend_bool _5;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_11 = NULL, *_12 = NULL;
	zval *parameters, *data = NULL, *params = NULL, *name, *id, *value = NULL, *useEmpty = NULL, *code, *emptyValue = NULL, *emptyText = NULL, *key = NULL, *avalue = NULL, *options = NULL, *closeOption, *using, *_0, **_4, *_6 = NULL, *_7, *_8, *_9, *_10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &data);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		array_init_size(params, 3);
		zephir_array_fast_append(params, parameters);
		zephir_array_fast_append(params, data);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_OBS_VAR(id);
	if (!(zephir_array_isset_long_fetch(&id, params, 0, 0 TSRMLS_CC))) {
		zephir_array_fetch_string(&_0, params, SL("id"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_update_long(&params, 0, &_0, PH_COPY | PH_SEPARATE, "phalcon/tag/select.zep", 50);
	}
	ZEPHIR_OBS_VAR(name);
	if (!(zephir_array_isset_string_fetch(&name, params, SS("name"), 0 TSRMLS_CC))) {
		zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		if (!(zephir_is_true(name))) {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	if (!(zephir_memnstr_str(id, SL("["), "phalcon/tag/select.zep", 64))) {
		if (!(zephir_array_isset_string(params, SS("id")))) {
			zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_VAR(value);
	if (!(zephir_array_isset_string_fetch(&value, params, SS("value"), 0 TSRMLS_CC))) {
		ZEPHIR_CALL_CE_STATIC(&value, phalcon_tag_ce, "getvalue", &_1, id, params);
		zephir_check_call_status();
	} else {
		zephir_array_unset_string(&params, SS("value"), PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(useEmpty);
	ZVAL_BOOL(useEmpty, 0);
	ZEPHIR_OBS_NVAR(useEmpty);
	if (zephir_array_isset_string_fetch(&useEmpty, params, SS("useEmpty"), 0 TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(emptyValue);
		if (!(zephir_array_isset_string_fetch(&emptyValue, params, SS("emptyValue"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(emptyValue);
			ZVAL_STRING(emptyValue, "", 1);
		} else {
			zephir_array_unset_string(&params, SS("emptyValue"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(emptyText);
		if (!(zephir_array_isset_string_fetch(&emptyText, params, SS("emptyText"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(emptyText);
			ZVAL_STRING(emptyText, "Choose...", 1);
		} else {
			zephir_array_unset_string(&params, SS("emptyText"), PH_SEPARATE);
		}
		zephir_array_unset_string(&params, SS("useEmpty"), PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(code);
	ZVAL_STRING(code, "<select", 1);
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_is_iterable(params, &_3, &_2, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HMKEY(key, _3, _2);
			ZEPHIR_GET_HVALUE(avalue, _4);
			_5 = Z_TYPE_P(key) != IS_LONG;
			if (_5) {
				_5 = Z_TYPE_P(avalue) != IS_ARRAY;
			}
			if (_5) {
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SVSVS(_6, " ", key, "=\"", avalue, "\"");
				zephir_concat_self(&code, _6 TSRMLS_CC);
			}
		}
	}
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_GET_CONSTANT(_7, "PHP_EOL");
	ZEPHIR_INIT_LNVAR(_6);
	ZEPHIR_CONCAT_SV(_6, ">", _7);
	zephir_concat_self(&code, _6 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_GET_CONSTANT(_8, "PHP_EOL");
	ZEPHIR_INIT_VAR(closeOption);
	ZEPHIR_CONCAT_SV(closeOption, "</option>", _8);
	if (zephir_is_true(useEmpty)) {
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_CONCAT_SVSVV(_9, "\t<option value=\"", emptyValue, "\">", emptyText, closeOption);
		zephir_concat_self(&code, _9 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(options);
	if (!(zephir_array_isset_long_fetch(&options, params, 1, 0 TSRMLS_CC))) {
		ZEPHIR_CPY_WRT(options, data);
	}
	if (Z_TYPE_P(options) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(using);
		if (!(zephir_array_isset_string_fetch(&using, params, SS("using"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "The 'using' parameter is required", "phalcon/tag/select.zep", 123);
			return;
		} else {
			_5 = Z_TYPE_P(using) != IS_ARRAY;
			if (_5) {
				_5 = Z_TYPE_P(using) != IS_OBJECT;
			}
			if (_5) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "The 'using' parameter should be an Array", "phalcon/tag/select.zep", 126);
				return;
			}
		}
		ZEPHIR_CALL_SELF(&_10, "_optionsfromresultset", &_11, options, using, value, closeOption);
		zephir_check_call_status();
		zephir_concat_self(&code, _10 TSRMLS_CC);
	} else {
		if (Z_TYPE_P(options) == IS_ARRAY) {
			ZEPHIR_CALL_SELF(&_10, "_optionsfromarray", &_12, options, value, closeOption);
			zephir_check_call_status();
			zephir_concat_self(&code, _10 TSRMLS_CC);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Invalid data provided to SELECT helper", "phalcon/tag/select.zep", 142);
			return;
		}
	}
	zephir_concat_self_str(&code, SL("</select>") TSRMLS_CC);
	RETURN_CCTOR(code);

}

/**
 * Generate the OPTION tags based on a resulset
 *
 * @param Phalcon\Mvc\Model resultset
 * @param array using
 * @param mixed value
 * @param string closeOption
 */
PHP_METHOD(Phalcon_Tag_Select, _optionsFromResultset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *resultset, *using, *value, *closeOption, *code, *params = NULL, *option = NULL, *usingZero = NULL, *usingOne = NULL, *optionValue = NULL, *optionText = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &resultset, &using, &value, &closeOption);



	ZEPHIR_INIT_VAR(code);
	ZVAL_STRING(code, "", 1);
	ZEPHIR_INIT_VAR(params);
	ZVAL_NULL(params);
	ZEPHIR_CALL_METHOD(NULL, resultset, "rewind", NULL);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, resultset, "valid",  NULL);
		zephir_check_call_status();
		if (!(!ZEPHIR_IS_FALSE(_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&option, resultset, "current",  NULL);
		zephir_check_call_status();
		if (Z_TYPE_P(using) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(usingZero);
			zephir_array_fetch_long(&usingZero, using, 0, PH_NOISY TSRMLS_CC);
			ZEPHIR_OBS_NVAR(usingOne);
			zephir_array_fetch_long(&usingOne, using, 1, PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(option) == IS_OBJECT) {
				if ((zephir_method_exists_ex(option, SS("readattribute") TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&optionValue, option, "readattribute", NULL, usingZero);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&optionText, option, "readattribute", NULL, usingOne);
					zephir_check_call_status();
				} else {
					ZEPHIR_OBS_NVAR(optionValue);
					zephir_read_property(&optionValue, option, SL("usingZero"), PH_NOISY_CC);
					ZEPHIR_OBS_NVAR(optionText);
					zephir_read_property(&optionText, option, SL("usingOne"), PH_NOISY_CC);
				}
			} else {
				if (Z_TYPE_P(option) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(optionValue);
					zephir_array_fetch(&optionValue, option, usingZero, PH_NOISY TSRMLS_CC);
					ZEPHIR_OBS_NVAR(optionText);
					zephir_array_fetch(&optionText, option, usingOne, PH_NOISY TSRMLS_CC);
				} else {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Resultset returned an invalid value", "phalcon/tag/select.zep", 192);
					return;
				}
			}
			if (Z_TYPE_P(value) == IS_ARRAY) {
				if (zephir_fast_in_array(optionValue, value TSRMLS_CC)) {
					ZEPHIR_INIT_LNVAR(_1);
					ZEPHIR_CONCAT_SVSVV(_1, "\t<option selected=\"selected\" value=\"", optionValue, "\">", optionText, closeOption);
					zephir_concat_self(&code, _1 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_1);
					ZEPHIR_CONCAT_SVSVV(_1, "\t<option value=\"", optionValue, "\">", optionText, closeOption);
					zephir_concat_self(&code, _1 TSRMLS_CC);
				}
			} else {
				if (ZEPHIR_IS_EQUAL(optionValue, value)) {
					ZEPHIR_INIT_LNVAR(_1);
					ZEPHIR_CONCAT_SVSVV(_1, "\t<option selected=\"selected\" value=\"", optionValue, "\">", optionText, closeOption);
					zephir_concat_self(&code, _1 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_1);
					ZEPHIR_CONCAT_SVSVV(_1, "\t<option value=\"", optionValue, "\">", optionText, closeOption);
					zephir_concat_self(&code, _1 TSRMLS_CC);
				}
			}
		} else {
			if (Z_TYPE_P(using) == IS_OBJECT) {
				if (Z_TYPE_P(params) == IS_NULL) {
					ZEPHIR_INIT_NVAR(params);
					array_init(params);
				}
				zephir_array_update_long(&params, 0, &option, PH_COPY | PH_SEPARATE, "phalcon/tag/select.zep", 221);
				ZEPHIR_INIT_NVAR(_2);
				ZEPHIR_CALL_USER_FUNC_ARRAY(_2, using, params);
				zephir_check_call_status();
				zephir_concat_self(&code, _2 TSRMLS_CC);
			}
		}
		ZEPHIR_CALL_METHOD(NULL, resultset, "next", NULL);
		zephir_check_call_status();
	}
	RETURN_CCTOR(code);

}

/**
 * Generate the OPTION tags based on an array
 *
 * @param array data
 * @param mixed value
 * @param string closeOption
 */
PHP_METHOD(Phalcon_Tag_Select, _optionsFromArray) {

	HashTable *_1;
	HashPosition _0;
	zval *data, *value, *closeOption, *code, *optionValue = NULL, *optionText = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data, &value, &closeOption);



	ZEPHIR_INIT_VAR(code);
	ZVAL_STRING(code, "", 1);
	zephir_is_iterable(data, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(optionValue, _1, _0);
		ZEPHIR_GET_HVALUE(optionText, _2);
		if (Z_TYPE_P(value) == IS_ARRAY) {
			if (zephir_fast_in_array(optionValue, value TSRMLS_CC)) {
				ZEPHIR_INIT_LNVAR(_3);
				ZEPHIR_CONCAT_SVSVV(_3, "\t<option selected=\"selected\" value=\"", optionValue, "\">", optionText, closeOption);
				zephir_concat_self(&code, _3 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_3);
				ZEPHIR_CONCAT_SVSVV(_3, "\t<option value=\"", optionValue, "\">", optionText, closeOption);
				zephir_concat_self(&code, _3 TSRMLS_CC);
			}
		} else {
			if (ZEPHIR_IS_EQUAL(optionValue, value)) {
				ZEPHIR_INIT_LNVAR(_3);
				ZEPHIR_CONCAT_SVSVV(_3, "\t<option selected=\"selected\" value=\"", optionValue, "\">", optionText, closeOption);
				zephir_concat_self(&code, _3 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_3);
				ZEPHIR_CONCAT_SVSVV(_3, "\t<option value=\"", optionValue, "\">", optionText, closeOption);
				zephir_concat_self(&code, _3 TSRMLS_CC);
			}
		}
	}
	RETURN_CCTOR(code);

}

