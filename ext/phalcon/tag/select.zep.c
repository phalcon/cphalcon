
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

	zend_bool _2$$21;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_9 = NULL, *_13 = NULL;
	zval *parameters, *data = NULL, *params = NULL, *name = NULL, *id = NULL, *value = NULL, *useEmpty = NULL, *code = NULL, *emptyValue = NULL, *emptyText = NULL, *options = NULL, *using = NULL, *_3 = NULL, *_5 = NULL, *_0$$5, *_6$$23, *_7$$23, *_8$$24 = NULL, *_10$$24, *_11$$24, *_12$$26 = NULL, *_14$$26, *_15$$26;

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
		zephir_array_fetch_string(&_0$$5, params, SL("id"), PH_NOISY | PH_READONLY, "phalcon/tag/select.zep", 52 TSRMLS_CC);
		zephir_array_update_long(&params, 0, &_0$$5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	if (!(zephir_memnstr_str(id, SL("["), "phalcon/tag/select.zep", 58))) {
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
		ZEPHIR_CALL_CE_STATIC(&value, phalcon_tag_ce, "getvalue", &_1, 6, id, params);
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "The 'using' parameter is required", "phalcon/tag/select.zep", 105);
			return;
		} else {
			_2$$21 = Z_TYPE_P(using) != IS_ARRAY;
			if (_2$$21) {
				_2$$21 = Z_TYPE_P(using) != IS_OBJECT;
			}
			if (_2$$21) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "The 'using' parameter should be an array", "phalcon/tag/select.zep", 108);
				return;
			}
		}
	}
	zephir_array_unset_string(&params, SS("using"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "<select", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_3, phalcon_tag_ce, "renderattributes", &_4, 4, _5, params);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_5);
	ZEPHIR_GET_CONSTANT(_5, "PHP_EOL");
	ZEPHIR_INIT_VAR(code);
	ZEPHIR_CONCAT_VSV(code, _3, ">", _5);
	if (zephir_is_true(useEmpty)) {
		ZEPHIR_INIT_VAR(_6$$23);
		ZEPHIR_GET_CONSTANT(_6$$23, "PHP_EOL");
		ZEPHIR_INIT_VAR(_7$$23);
		ZEPHIR_CONCAT_SVSVSV(_7$$23, "\t<option value=\"", emptyValue, "\">", emptyText, "</option>", _6$$23);
		zephir_concat_self(&code, _7$$23 TSRMLS_CC);
	}
	if (Z_TYPE_P(options) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_10$$24);
		ZEPHIR_GET_CONSTANT(_10$$24, "PHP_EOL");
		ZEPHIR_INIT_VAR(_11$$24);
		ZEPHIR_CONCAT_SV(_11$$24, "</option>", _10$$24);
		ZEPHIR_CALL_SELF(&_8$$24, "_optionsfromresultset", &_9, 457, options, using, value, _11$$24);
		zephir_check_call_status();
		zephir_concat_self(&code, _8$$24 TSRMLS_CC);
	} else {
		if (Z_TYPE_P(options) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_14$$26);
			ZEPHIR_GET_CONSTANT(_14$$26, "PHP_EOL");
			ZEPHIR_INIT_VAR(_15$$26);
			ZEPHIR_CONCAT_SV(_15$$26, "</option>", _14$$26);
			ZEPHIR_CALL_SELF(&_12$$26, "_optionsfromarray", &_13, 458, options, value, _15$$26);
			zephir_check_call_status();
			zephir_concat_self(&code, _12$$26 TSRMLS_CC);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Invalid data provided to SELECT helper", "phalcon/tag/select.zep", 139);
			return;
		}
	}
	zephir_concat_self_str(&code, SL("</select>") TSRMLS_CC);
	RETURN_CCTOR(code);

}

/**
 * Generate the OPTION tags based on a resultset
 *
 * @param \Phalcon\Mvc\Model\Resultset resultset
 * @param array using
 * @param mixed value
 * @param string closeOption
 */
PHP_METHOD(Phalcon_Tag_Select, _optionsFromResultset) {

	zval *_8$$16 = NULL, *_9$$16 = NULL;
	zend_object_iterator *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_5 = NULL;
	zval *resultset, *using, *value, *closeOption, *code = NULL, *params = NULL, *option = NULL, *usingZero = NULL, *usingOne = NULL, *escaper = NULL, *optionValue = NULL, *optionText = NULL, *strValue = NULL, *strOptionValue = NULL, *_0 = NULL, *_3$$6 = NULL, *_6$$14 = NULL, *_7$$15 = NULL, *_10$$17 = NULL, *_11$$18 = NULL, *_12$$20 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &resultset, &using, &value, &closeOption);



	ZEPHIR_INIT_VAR(code);
	ZVAL_STRING(code, "", 1);
	ZEPHIR_INIT_VAR(params);
	ZVAL_NULL(params);
	if (Z_TYPE_P(using) == IS_ARRAY) {
		if (zephir_fast_count_int(using TSRMLS_CC) != 2) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Parameter 'using' requires two values", "phalcon/tag/select.zep", 166);
			return;
		}
		ZEPHIR_OBS_VAR(usingZero);
		zephir_array_fetch_long(&usingZero, using, 0, PH_NOISY, "phalcon/tag/select.zep", 168 TSRMLS_CC);
		ZEPHIR_OBS_VAR(usingOne);
		zephir_array_fetch_long(&usingOne, using, 1, PH_NOISY, "phalcon/tag/select.zep", 168 TSRMLS_CC);
	}
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_tag_ce, "getescaperservice", &_1, 459);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(escaper, _0);
	_2 = zephir_get_iterator(resultset TSRMLS_CC);
	_2->funcs->rewind(_2 TSRMLS_CC);
	for (;_2->funcs->valid(_2 TSRMLS_CC) == SUCCESS && !EG(exception); _2->funcs->move_forward(_2 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_2->funcs->get_current_data(_2, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
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
					zephir_array_fetch(&optionValue, option, usingZero, PH_NOISY, "phalcon/tag/select.zep", 187 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(optionText);
					zephir_array_fetch(&optionText, option, usingOne, PH_NOISY, "phalcon/tag/select.zep", 188 TSRMLS_CC);
				} else {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Resultset returned an invalid value", "phalcon/tag/select.zep", 190);
					return;
				}
			}
			ZEPHIR_CALL_METHOD(&_3$$6, escaper, "escapehtmlattr", &_4, 0, optionValue);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(optionValue, _3$$6);
			ZEPHIR_CALL_METHOD(&_3$$6, escaper, "escapehtml", &_5, 0, optionText);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(optionText, _3$$6);
			if (Z_TYPE_P(value) == IS_ARRAY) {
				if (zephir_fast_in_array(optionValue, value TSRMLS_CC)) {
					ZEPHIR_INIT_LNVAR(_6$$14);
					ZEPHIR_CONCAT_SVSVV(_6$$14, "\t<option selected=\"selected\" value=\"", optionValue, "\">", optionText, closeOption);
					zephir_concat_self(&code, _6$$14 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_7$$15);
					ZEPHIR_CONCAT_SVSVV(_7$$15, "\t<option value=\"", optionValue, "\">", optionText, closeOption);
					zephir_concat_self(&code, _7$$15 TSRMLS_CC);
				}
			} else {
				zephir_get_strval(_8$$16, optionValue);
				ZEPHIR_CPY_WRT(strOptionValue, _8$$16);
				zephir_get_strval(_9$$16, value);
				ZEPHIR_CPY_WRT(strValue, _9$$16);
				if (ZEPHIR_IS_IDENTICAL(strOptionValue, strValue)) {
					ZEPHIR_INIT_LNVAR(_10$$17);
					ZEPHIR_CONCAT_SVSVV(_10$$17, "\t<option selected=\"selected\" value=\"", strOptionValue, "\">", optionText, closeOption);
					zephir_concat_self(&code, _10$$17 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_11$$18);
					ZEPHIR_CONCAT_SVSVV(_11$$18, "\t<option value=\"", strOptionValue, "\">", optionText, closeOption);
					zephir_concat_self(&code, _11$$18 TSRMLS_CC);
				}
			}
		} else {
			if (Z_TYPE_P(using) == IS_OBJECT) {
				if (Z_TYPE_P(params) == IS_NULL) {
					ZEPHIR_INIT_NVAR(params);
					array_init(params);
				}
				zephir_array_update_long(&params, 0, &option, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				ZEPHIR_INIT_NVAR(_12$$20);
				ZEPHIR_CALL_USER_FUNC_ARRAY(_12$$20, using, params);
				zephir_check_call_status();
				zephir_concat_self(&code, _12$$20 TSRMLS_CC);
			}
		}
	}
	_2->funcs->dtor(_2 TSRMLS_CC);
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

	zval *_11$$8 = NULL, *_12$$8 = NULL;
	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	zval *data, *value, *closeOption, *strValue = NULL, *strOptionValue = NULL, *code = NULL, *optionValue = NULL, *optionText = NULL, *escaped = NULL, **_2, *_4$$4 = NULL, *_5$$4 = NULL, *_7$$4 = NULL, *_8$$4 = NULL, *_9$$6 = NULL, *_10$$7 = NULL, *_13$$9 = NULL, *_14$$10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data, &value, &closeOption);



	ZEPHIR_INIT_VAR(code);
	ZVAL_STRING(code, "", 1);
	zephir_is_iterable(data, &_1, &_0, 0, 0, "phalcon/tag/select.zep", 274);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(optionValue, _1, _0);
		ZEPHIR_GET_HVALUE(optionText, _2);
		ZEPHIR_CALL_FUNCTION(&escaped, "htmlspecialchars", &_3, 204, optionValue);
		zephir_check_call_status();
		if (Z_TYPE_P(optionText) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_4$$4);
			ZEPHIR_GET_CONSTANT(_4$$4, "PHP_EOL");
			ZEPHIR_CALL_SELF(&_5$$4, "_optionsfromarray", &_6, 458, optionText, value, closeOption);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_7$$4);
			ZEPHIR_GET_CONSTANT(_7$$4, "PHP_EOL");
			ZEPHIR_INIT_LNVAR(_8$$4);
			ZEPHIR_CONCAT_SVSVVSV(_8$$4, "\t<optgroup label=\"", escaped, "\">", _4$$4, _5$$4, "\t</optgroup>", _7$$4);
			zephir_concat_self(&code, _8$$4 TSRMLS_CC);
			continue;
		}
		if (Z_TYPE_P(value) == IS_ARRAY) {
			if (zephir_fast_in_array(optionValue, value TSRMLS_CC)) {
				ZEPHIR_INIT_LNVAR(_9$$6);
				ZEPHIR_CONCAT_SVSVV(_9$$6, "\t<option selected=\"selected\" value=\"", escaped, "\">", optionText, closeOption);
				zephir_concat_self(&code, _9$$6 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_10$$7);
				ZEPHIR_CONCAT_SVSVV(_10$$7, "\t<option value=\"", escaped, "\">", optionText, closeOption);
				zephir_concat_self(&code, _10$$7 TSRMLS_CC);
			}
		} else {
			zephir_get_strval(_11$$8, optionValue);
			ZEPHIR_CPY_WRT(strOptionValue, _11$$8);
			zephir_get_strval(_12$$8, value);
			ZEPHIR_CPY_WRT(strValue, _12$$8);
			if (ZEPHIR_IS_IDENTICAL(strOptionValue, strValue)) {
				ZEPHIR_INIT_LNVAR(_13$$9);
				ZEPHIR_CONCAT_SVSVV(_13$$9, "\t<option selected=\"selected\" value=\"", escaped, "\">", optionText, closeOption);
				zephir_concat_self(&code, _13$$9 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_14$$10);
				ZEPHIR_CONCAT_SVSVV(_14$$10, "\t<option value=\"", escaped, "\">", optionText, closeOption);
				zephir_concat_self(&code, _14$$10 TSRMLS_CC);
			}
		}
	}
	RETURN_CCTOR(code);

}

