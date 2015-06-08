
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/iterator.h"
#include "kernel/object.h"
#include "kernel/hash.h"


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

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_9 = NULL, *_10 = NULL;
	zval *parameters, *data = NULL, *params = NULL, *name, *id, *value = NULL, *useEmpty, *code, *emptyValue = NULL, *emptyText = NULL, *options = NULL, *using, *_0, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &data);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		zephir_create_array(params, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(params, parameters);
		zephir_array_fast_append(params, data);
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_OBS_VAR(id);
	if (!(zephir_array_isset_long_fetch(&id, params, 0, 0 TSRMLS_CC))) {
		zephir_array_fetch_string(&_0, params, SL("id"), PH_NOISY | PH_READONLY, "phalcon/tag/select.zep", 51 TSRMLS_CC);
		zephir_array_update_long(&params, 0, &_0, PH_COPY | PH_SEPARATE, "phalcon/tag/select.zep", 51);
	}
	if (!(zephir_memnstr_str(id, SL("["), "phalcon/tag/select.zep", 57))) {
		if (!(zephir_array_isset_string(params, SS("id")))) {
			zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_VAR(name);
	if (!(zephir_array_isset_string_fetch(&name, params, SS("name"), 0 TSRMLS_CC))) {
		zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		if (!(zephir_is_true(name))) {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_VAR(value);
	if (!(zephir_array_isset_string_fetch(&value, params, SS("value"), 0 TSRMLS_CC))) {
		ZEPHIR_CALL_CE_STATIC(&value, phalcon_tag_ce, "getvalue", &_1, 172, id, params);
		zephir_check_call_status();
	} else {
		zephir_array_unset_string(&params, SS("value"), PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(useEmpty);
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
	ZEPHIR_OBS_VAR(options);
	if (!(zephir_array_isset_long_fetch(&options, params, 1, 0 TSRMLS_CC))) {
		ZEPHIR_CPY_WRT(options, data);
	}
	if (Z_TYPE_P(options) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(using);
		if (!(zephir_array_isset_string_fetch(&using, params, SS("using"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "The 'using' parameter is required", "phalcon/tag/select.zep", 104);
			return;
		} else {
			_2 = Z_TYPE_P(using) != IS_ARRAY;
			if (_2) {
				_2 = Z_TYPE_P(using) != IS_OBJECT;
			}
			if (_2) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "The 'using' parameter should be an array", "phalcon/tag/select.zep", 107);
				return;
			}
		}
	}
	zephir_array_unset_string(&params, SS("using"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "<select", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_3, phalcon_tag_ce, "renderattributes", &_4, 170, _5, params);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_5);
	ZEPHIR_GET_CONSTANT(_5, "PHP_EOL");
	ZEPHIR_INIT_VAR(code);
	ZEPHIR_CONCAT_VSV(code, _3, ">", _5);
	if (zephir_is_true(useEmpty)) {
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_GET_CONSTANT(_6, "PHP_EOL");
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SVSVSV(_7, "\t<option value=\"", emptyValue, "\">", emptyText, "</option>", _6);
		zephir_concat_self(&code, _7 TSRMLS_CC);
	}
	if (Z_TYPE_P(options) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_6);
		ZEPHIR_GET_CONSTANT(_6, "PHP_EOL");
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_SV(_7, "</option>", _6);
		ZEPHIR_CALL_SELF(&_8, "_optionsfromresultset", &_9, 411, options, using, value, _7);
		zephir_check_call_status();
		zephir_concat_self(&code, _8 TSRMLS_CC);
	} else {
		if (Z_TYPE_P(options) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_6);
			ZEPHIR_GET_CONSTANT(_6, "PHP_EOL");
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_CONCAT_SV(_7, "</option>", _6);
			ZEPHIR_CALL_SELF(&_8, "_optionsfromarray", &_10, 412, options, value, _7);
			zephir_check_call_status();
			zephir_concat_self(&code, _8 TSRMLS_CC);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Invalid data provided to SELECT helper", "phalcon/tag/select.zep", 138);
			return;
		}
	}
	zephir_concat_self_str(&code, SL("</select>") TSRMLS_CC);
	RETURN_CCTOR(code);

}

/**
 * Generate the OPTION tags based on a resultset
 *
 * @param Phalcon\Mvc\Model\Resultset resultset
 * @param array using
 * @param mixed value
 * @param string closeOption
 */
PHP_METHOD(Phalcon_Tag_Select, _optionsFromResultset) {

	zval *_2 = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_object_iterator *_0;
	zval *resultset, *using, *value, *closeOption, *code, *params = NULL, *option = NULL, *usingZero, *usingOne, *optionValue = NULL, *optionText = NULL, *strValue = NULL, *strOptionValue = NULL, *_1 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &resultset, &using, &value, &closeOption);



	ZEPHIR_INIT_VAR(code);
	ZVAL_STRING(code, "", 1);
	ZEPHIR_INIT_VAR(params);
	ZVAL_NULL(params);
	if (Z_TYPE_P(using) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(usingZero);
		zephir_array_fetch_long(&usingZero, using, 0, PH_NOISY, "phalcon/tag/select.zep", 164 TSRMLS_CC);
		ZEPHIR_OBS_VAR(usingOne);
		zephir_array_fetch_long(&usingOne, using, 1, PH_NOISY, "phalcon/tag/select.zep", 164 TSRMLS_CC);
	}
	_0 = zephir_get_iterator(resultset TSRMLS_CC);
	_0->funcs->rewind(_0 TSRMLS_CC);
	for (;_0->funcs->valid(_0 TSRMLS_CC) == SUCCESS && !EG(exception); _0->funcs->move_forward(_0 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_0->funcs->get_current_data(_0, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(option, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		if (Z_TYPE_P(using) == IS_ARRAY) {
			if (Z_TYPE_P(option) == IS_OBJECT) {
				if ((zephir_method_exists_ex(option, SS("readattribute") TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&optionValue, option, "readattribute", NULL, 0, usingZero);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&optionText, option, "readattribute", NULL, 0, usingOne);
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
					zephir_array_fetch(&optionValue, option, usingZero, PH_NOISY, "phalcon/tag/select.zep", 181 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(optionText);
					zephir_array_fetch(&optionText, option, usingOne, PH_NOISY, "phalcon/tag/select.zep", 182 TSRMLS_CC);
				} else {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Resultset returned an invalid value", "phalcon/tag/select.zep", 184);
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
				zephir_get_strval(_2, optionValue);
				ZEPHIR_CPY_WRT(strOptionValue, _2);
				zephir_get_strval(_3, value);
				ZEPHIR_CPY_WRT(strValue, _3);
				if (ZEPHIR_IS_IDENTICAL(strOptionValue, strValue)) {
					ZEPHIR_INIT_LNVAR(_1);
					ZEPHIR_CONCAT_SVSVV(_1, "\t<option selected=\"selected\" value=\"", strOptionValue, "\">", optionText, closeOption);
					zephir_concat_self(&code, _1 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_1);
					ZEPHIR_CONCAT_SVSVV(_1, "\t<option value=\"", strOptionValue, "\">", optionText, closeOption);
					zephir_concat_self(&code, _1 TSRMLS_CC);
				}
			}
		} else {
			if (Z_TYPE_P(using) == IS_OBJECT) {
				if (Z_TYPE_P(params) == IS_NULL) {
					ZEPHIR_INIT_NVAR(params);
					array_init(params);
				}
				zephir_array_update_long(&params, 0, &option, PH_COPY | PH_SEPARATE, "phalcon/tag/select.zep", 215);
				ZEPHIR_INIT_NVAR(_4);
				ZEPHIR_CALL_USER_FUNC_ARRAY(_4, using, params);
				zephir_check_call_status();
				zephir_concat_self(&code, _4 TSRMLS_CC);
			}
		}
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *_0 = NULL, *_4 = NULL;
	zval *data, *value, *closeOption, *strValue = NULL, *strOptionValue = NULL, *code, *optionValue = NULL, *optionText = NULL, *escaped = NULL, **_3, *_6 = NULL, *_7 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data, &value, &closeOption);



	ZEPHIR_INIT_VAR(code);
	ZVAL_STRING(code, "", 1);
	zephir_get_strval(_0, value);
	ZEPHIR_CPY_WRT(strValue, _0);
	zephir_is_iterable(data, &_2, &_1, 0, 0, "phalcon/tag/select.zep", 262);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(optionValue, _2, _1);
		ZEPHIR_GET_HVALUE(optionText, _3);
		zephir_get_strval(_4, optionValue);
		ZEPHIR_CPY_WRT(strOptionValue, _4);
		ZEPHIR_CALL_FUNCTION(&escaped, "htmlspecialchars", &_5, 155, optionValue);
		zephir_check_call_status();
		if (Z_TYPE_P(optionText) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_6);
			ZEPHIR_GET_CONSTANT(_6, "PHP_EOL");
			ZEPHIR_CALL_SELF(&_7, "_optionsfromarray", &_8, 412, optionText, value, closeOption);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_9);
			ZEPHIR_GET_CONSTANT(_9, "PHP_EOL");
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_SVSVVSV(_10, "\t<optgroup label=\"", escaped, "\">", _6, _7, "\t</optgroup>", _9);
			zephir_concat_self(&code, _10 TSRMLS_CC);
		} else {
			if (Z_TYPE_P(value) == IS_ARRAY) {
				if (zephir_fast_in_array(optionValue, value TSRMLS_CC)) {
					ZEPHIR_INIT_LNVAR(_10);
					ZEPHIR_CONCAT_SVSVV(_10, "\t<option selected=\"selected\" value=\"", escaped, "\">", optionText, closeOption);
					zephir_concat_self(&code, _10 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_11);
					ZEPHIR_CONCAT_SVSVV(_11, "\t<option value=\"", escaped, "\">", optionText, closeOption);
					zephir_concat_self(&code, _11 TSRMLS_CC);
				}
			} else {
				if (ZEPHIR_IS_IDENTICAL(strOptionValue, strValue)) {
					ZEPHIR_INIT_LNVAR(_11);
					ZEPHIR_CONCAT_SVSVV(_11, "\t<option selected=\"selected\" value=\"", escaped, "\">", optionText, closeOption);
					zephir_concat_self(&code, _11 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_11);
					ZEPHIR_CONCAT_SVSVV(_11, "\t<option value=\"", escaped, "\">", optionText, closeOption);
					zephir_concat_self(&code, _11 TSRMLS_CC);
				}
			}
		}
	}
	RETURN_CCTOR(code);

}

