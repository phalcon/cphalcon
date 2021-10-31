
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/iterator.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Tag\Select
 *
 * Generates a SELECT HTML tag using a static array of values or a
 * Phalcon\Mvc\Model resultset
 */
ZEPHIR_INIT_CLASS(Phalcon_Tag_Select)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Tag, Select, phalcon, tag_select, phalcon_tag_select_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;
}

/**
 * Generates a SELECT tag
 *
 * @param array parameters = [
 *     'id' => '',
 *     'name' => '',
 *     'value' => '',
 *     'useEmpty' => false,
 *     'emptyValue' => '',
 *     'emptyText' => '',
 * ]
 * @param array data
 */
PHP_METHOD(Phalcon_Tag_Select, selectField)
{
	zend_bool _2$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_9 = NULL, *_13 = NULL;
	zval *parameters, parameters_sub, *data = NULL, data_sub, __$null, params, name, id, value, useEmpty, code, emptyValue, emptyText, options, using, _3, _5, _0$$5, _6$$22, _7$$22, _8$$23, _10$$23, _11$$23, _12$$25, _14$$25, _15$$25;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&useEmpty);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&emptyValue);
	ZVAL_UNDEF(&emptyText);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&using);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_6$$22);
	ZVAL_UNDEF(&_7$$22);
	ZVAL_UNDEF(&_8$$23);
	ZVAL_UNDEF(&_10$$23);
	ZVAL_UNDEF(&_11$$23);
	ZVAL_UNDEF(&_12$$25);
	ZVAL_UNDEF(&_14$$25);
	ZVAL_UNDEF(&_15$$25);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(parameters)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &data);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 2, 0);
		zephir_array_fast_append(&params, parameters);
		zephir_array_fast_append(&params, data);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_OBS_VAR(&id);
	if (!(zephir_array_isset_long_fetch(&id, &params, 0, 0))) {
		zephir_array_fetch_string(&_0$$5, &params, SL("id"), PH_NOISY | PH_READONLY, "phalcon/Tag/Select.zep", 50);
		zephir_array_update_long(&params, 0, &_0$$5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	if (!(zephir_memnstr_str(&id, SL("["), "phalcon/Tag/Select.zep", 56))) {
		if (!(zephir_array_isset_string(&params, SL("id")))) {
			zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_VAR(&name);
	if (!(zephir_array_isset_string_fetch(&name, &params, SL("name"), 0))) {
		zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		if (!(zephir_is_true(&name))) {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_VAR(&value);
	if (!(zephir_array_isset_string_fetch(&value, &params, SL("value"), 0))) {
		ZEPHIR_CALL_CE_STATIC(&value, phalcon_tag_ce, "getvalue", &_1, 0, &id, &params);
		zephir_check_call_status();
	} else {
		zephir_array_unset_string(&params, SL("value"), PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&useEmpty);
	if (zephir_array_isset_string_fetch(&useEmpty, &params, SL("useEmpty"), 0)) {
		ZEPHIR_OBS_VAR(&emptyValue);
		if (!(zephir_array_isset_string_fetch(&emptyValue, &params, SL("emptyValue"), 0))) {
			ZEPHIR_INIT_NVAR(&emptyValue);
			ZVAL_STRING(&emptyValue, "");
		} else {
			zephir_array_unset_string(&params, SL("emptyValue"), PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&emptyText);
		if (!(zephir_array_isset_string_fetch(&emptyText, &params, SL("emptyText"), 0))) {
			ZEPHIR_INIT_NVAR(&emptyText);
			ZVAL_STRING(&emptyText, "Choose...");
		} else {
			zephir_array_unset_string(&params, SL("emptyText"), PH_SEPARATE);
		}
		zephir_array_unset_string(&params, SL("useEmpty"), PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&options);
	if (!(zephir_array_isset_long_fetch(&options, &params, 1, 0))) {
		ZEPHIR_CPY_WRT(&options, data);
	}
	if (Z_TYPE_P(&options) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(&using);
		if (UNEXPECTED(!(zephir_array_isset_string_fetch(&using, &params, SL("using"), 0)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "The 'using' parameter is required", "phalcon/Tag/Select.zep", 101);
			return;
		}
		_2$$19 = Z_TYPE_P(&using) != IS_ARRAY;
		if (_2$$19) {
			_2$$19 = Z_TYPE_P(&using) != IS_OBJECT;
		}
		if (UNEXPECTED(_2$$19)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "The 'using' parameter should be an array", "phalcon/Tag/Select.zep", 107);
			return;
		}
	}
	zephir_array_unset_string(&params, SL("using"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "<select");
	ZEPHIR_CALL_CE_STATIC(&_3, phalcon_tag_ce, "renderattributes", &_4, 0, &_5, &params);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	ZEPHIR_GET_CONSTANT(&_5, "PHP_EOL");
	ZEPHIR_INIT_VAR(&code);
	ZEPHIR_CONCAT_VSV(&code, &_3, ">", &_5);
	if (zephir_is_true(&useEmpty)) {
		ZEPHIR_INIT_VAR(&_6$$22);
		ZEPHIR_GET_CONSTANT(&_6$$22, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_7$$22);
		ZEPHIR_CONCAT_SVSVSV(&_7$$22, "\t<option value=\"", &emptyValue, "\">", &emptyText, "</option>", &_6$$22);
		zephir_concat_self(&code, &_7$$22);
	}
	if (Z_TYPE_P(&options) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_10$$23);
		ZEPHIR_GET_CONSTANT(&_10$$23, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_11$$23);
		ZEPHIR_CONCAT_SV(&_11$$23, "</option>", &_10$$23);
		ZEPHIR_CALL_SELF(&_8$$23, "optionsfromresultset", &_9, 0, &options, &using, &value, &_11$$23);
		zephir_check_call_status();
		zephir_concat_self(&code, &_8$$23);
	} else {
		if (Z_TYPE_P(&options) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_14$$25);
			ZEPHIR_GET_CONSTANT(&_14$$25, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_15$$25);
			ZEPHIR_CONCAT_SV(&_15$$25, "</option>", &_14$$25);
			ZEPHIR_CALL_SELF(&_12$$25, "optionsfromarray", &_13, 0, &options, &value, &_15$$25);
			zephir_check_call_status();
			zephir_concat_self(&code, &_12$$25);
		}
	}
	zephir_concat_self_str(&code, SL("</select>"));
	RETURN_CCTOR(&code);
}

/**
 * Generate the OPTION tags based on an array
 */
PHP_METHOD(Phalcon_Tag_Select, optionsFromArray)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval closeOption, _12$$8, _13$$8, _22$$16, _23$$16;
	zval *data_param = NULL, *value, value_sub, *closeOption_param = NULL, strValue, strOptionValue, code, optionValue, optionText, escaped, *_0, _1, _5$$4, _6$$4, _8$$4, _9$$4, _10$$6, _11$$7, _14$$9, _15$$10, _16$$12, _17$$12, _18$$12, _19$$12, _20$$14, _21$$15, _24$$17, _25$$18;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&strValue);
	ZVAL_UNDEF(&strOptionValue);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&optionValue);
	ZVAL_UNDEF(&optionText);
	ZVAL_UNDEF(&escaped);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&closeOption);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$16);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY(data)
		Z_PARAM_ZVAL(value)
		Z_PARAM_STR(closeOption)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data_param, &value, &closeOption_param);
	zephir_get_arrval(&data, data_param);
	zephir_get_strval(&closeOption, closeOption_param);


	ZEPHIR_INIT_VAR(&code);
	ZVAL_STRING(&code, "");
	zephir_is_iterable(&data, 0, "phalcon/Tag/Select.zep", 186);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&optionValue);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&optionValue, _3);
			} else {
				ZVAL_LONG(&optionValue, _2);
			}
			ZEPHIR_INIT_NVAR(&optionText);
			ZVAL_COPY(&optionText, _0);
			ZEPHIR_CALL_FUNCTION(&escaped, "htmlspecialchars", &_4, 256, &optionValue);
			zephir_check_call_status();
			if (Z_TYPE_P(&optionText) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZEPHIR_GET_CONSTANT(&_5$$4, "PHP_EOL");
				ZEPHIR_CALL_SELF(&_6$$4, "optionsfromarray", &_7, 0, &optionText, value, &closeOption);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZEPHIR_GET_CONSTANT(&_8$$4, "PHP_EOL");
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZEPHIR_CONCAT_SVSVVSV(&_9$$4, "\t<optgroup label=\"", &escaped, "\">", &_5$$4, &_6$$4, "\t</optgroup>", &_8$$4);
				zephir_concat_self(&code, &_9$$4);
				continue;
			}
			if (Z_TYPE_P(value) == IS_ARRAY) {
				if (zephir_fast_in_array(&optionValue, value)) {
					ZEPHIR_INIT_NVAR(&_10$$6);
					ZEPHIR_CONCAT_SVSVV(&_10$$6, "\t<option selected=\"selected\" value=\"", &escaped, "\">", &optionText, &closeOption);
					zephir_concat_self(&code, &_10$$6);
				} else {
					ZEPHIR_INIT_NVAR(&_11$$7);
					ZEPHIR_CONCAT_SVSVV(&_11$$7, "\t<option value=\"", &escaped, "\">", &optionText, &closeOption);
					zephir_concat_self(&code, &_11$$7);
				}
			} else {
				zephir_cast_to_string(&_12$$8, &optionValue);
				ZEPHIR_CPY_WRT(&strOptionValue, &_12$$8);
				zephir_cast_to_string(&_13$$8, value);
				ZEPHIR_CPY_WRT(&strValue, &_13$$8);
				if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
					ZEPHIR_INIT_NVAR(&_14$$9);
					ZEPHIR_CONCAT_SVSVV(&_14$$9, "\t<option selected=\"selected\" value=\"", &escaped, "\">", &optionText, &closeOption);
					zephir_concat_self(&code, &_14$$9);
				} else {
					ZEPHIR_INIT_NVAR(&_15$$10);
					ZEPHIR_CONCAT_SVSVV(&_15$$10, "\t<option value=\"", &escaped, "\">", &optionText, &closeOption);
					zephir_concat_self(&code, &_15$$10);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&optionValue, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&optionText, &data, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&escaped, "htmlspecialchars", &_4, 256, &optionValue);
				zephir_check_call_status();
				if (Z_TYPE_P(&optionText) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_16$$12);
					ZEPHIR_GET_CONSTANT(&_16$$12, "PHP_EOL");
					ZEPHIR_CALL_SELF(&_17$$12, "optionsfromarray", &_7, 0, &optionText, value, &closeOption);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_18$$12);
					ZEPHIR_GET_CONSTANT(&_18$$12, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_19$$12);
					ZEPHIR_CONCAT_SVSVVSV(&_19$$12, "\t<optgroup label=\"", &escaped, "\">", &_16$$12, &_17$$12, "\t</optgroup>", &_18$$12);
					zephir_concat_self(&code, &_19$$12);
					continue;
				}
				if (Z_TYPE_P(value) == IS_ARRAY) {
					if (zephir_fast_in_array(&optionValue, value)) {
						ZEPHIR_INIT_NVAR(&_20$$14);
						ZEPHIR_CONCAT_SVSVV(&_20$$14, "\t<option selected=\"selected\" value=\"", &escaped, "\">", &optionText, &closeOption);
						zephir_concat_self(&code, &_20$$14);
					} else {
						ZEPHIR_INIT_NVAR(&_21$$15);
						ZEPHIR_CONCAT_SVSVV(&_21$$15, "\t<option value=\"", &escaped, "\">", &optionText, &closeOption);
						zephir_concat_self(&code, &_21$$15);
					}
				} else {
					zephir_cast_to_string(&_22$$16, &optionValue);
					ZEPHIR_CPY_WRT(&strOptionValue, &_22$$16);
					zephir_cast_to_string(&_23$$16, value);
					ZEPHIR_CPY_WRT(&strValue, &_23$$16);
					if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
						ZEPHIR_INIT_NVAR(&_24$$17);
						ZEPHIR_CONCAT_SVSVV(&_24$$17, "\t<option selected=\"selected\" value=\"", &escaped, "\">", &optionText, &closeOption);
						zephir_concat_self(&code, &_24$$17);
					} else {
						ZEPHIR_INIT_NVAR(&_25$$18);
						ZEPHIR_CONCAT_SVSVV(&_25$$18, "\t<option value=\"", &escaped, "\">", &optionText, &closeOption);
						zephir_concat_self(&code, &_25$$18);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&optionText);
	ZEPHIR_INIT_NVAR(&optionValue);
	RETURN_CCTOR(&code);
}

/**
 * Generate the OPTION tags based on a resultset
 *
 * @param array using
 */
PHP_METHOD(Phalcon_Tag_Select, optionsFromResultset)
{
	zend_object_iterator *_2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_5 = NULL;
	zval closeOption, _8$$15, _9$$15;
	zval *resultset, resultset_sub, *using, using_sub, *value, value_sub, *closeOption_param = NULL, code, params, option, usingZero, usingOne, escaper, optionValue, optionText, strValue, strOptionValue, _0, _3$$6, _6$$13, _7$$14, _10$$16, _11$$17, _12$$19;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resultset_sub);
	ZVAL_UNDEF(&using_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&usingZero);
	ZVAL_UNDEF(&usingOne);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&optionValue);
	ZVAL_UNDEF(&optionText);
	ZVAL_UNDEF(&strValue);
	ZVAL_UNDEF(&strOptionValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_6$$13);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_10$$16);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_12$$19);
	ZVAL_UNDEF(&closeOption);
	ZVAL_UNDEF(&_8$$15);
	ZVAL_UNDEF(&_9$$15);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(resultset, phalcon_mvc_model_resultsetinterface_ce)
		Z_PARAM_ZVAL(using)
		Z_PARAM_ZVAL(value)
		Z_PARAM_STR(closeOption)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &resultset, &using, &value, &closeOption_param);
	zephir_get_strval(&closeOption, closeOption_param);


	ZEPHIR_INIT_VAR(&code);
	ZVAL_STRING(&code, "");
	ZEPHIR_INIT_VAR(&params);
	ZVAL_NULL(&params);
	if (Z_TYPE_P(using) == IS_ARRAY) {
		if (UNEXPECTED(zephir_fast_count_int(using) != 2)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Parameter 'using' requires two values", "phalcon/Tag/Select.zep", 209);
			return;
		}
		ZEPHIR_OBS_VAR(&usingZero);
		zephir_array_fetch_long(&usingZero, using, 0, PH_NOISY, "phalcon/Tag/Select.zep", 212);
		ZEPHIR_OBS_VAR(&usingOne);
		zephir_array_fetch_long(&usingOne, using, 1, PH_NOISY, "phalcon/Tag/Select.zep", 213);
	}
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_tag_ce, "getescaperservice", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&escaper, &_0);
	_2 = zephir_get_iterator(resultset);
	_2->funcs->rewind(_2);
	for (;_2->funcs->valid(_2) == SUCCESS && !EG(exception); _2->funcs->move_forward(_2)) {
		{
			ZEPHIR_ITERATOR_COPY(&option, _2);
		}
		if (Z_TYPE_P(using) == IS_ARRAY) {
			if (Z_TYPE_P(&option) == IS_OBJECT) {
				if ((zephir_method_exists_ex(&option, ZEND_STRL("readattribute")) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&optionValue, &option, "readattribute", NULL, 0, &usingZero);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&optionText, &option, "readattribute", NULL, 0, &usingOne);
					zephir_check_call_status();
				} else {
					ZEPHIR_OBS_NVAR(&optionValue);
					zephir_read_property(&optionValue, &option, ZEND_STRL("usingZero"), PH_NOISY_CC);
					ZEPHIR_OBS_NVAR(&optionText);
					zephir_read_property(&optionText, &option, ZEND_STRL("usingOne"), PH_NOISY_CC);
				}
			} else {
				if (UNEXPECTED(Z_TYPE_P(&option) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Resultset returned an invalid value", "phalcon/Tag/Select.zep", 232);
					return;
				}
				ZEPHIR_OBS_NVAR(&optionValue);
				zephir_array_fetch(&optionValue, &option, &usingZero, PH_NOISY, "phalcon/Tag/Select.zep", 235);
				ZEPHIR_OBS_NVAR(&optionText);
				zephir_array_fetch(&optionText, &option, &usingOne, PH_NOISY, "phalcon/Tag/Select.zep", 236);
			}
			ZEPHIR_CALL_METHOD(&_3$$6, &escaper, "escapehtmlattr", &_4, 0, &optionValue);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&optionValue, &_3$$6);
			ZEPHIR_CALL_METHOD(&_3$$6, &escaper, "escapehtml", &_5, 0, &optionText);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&optionText, &_3$$6);
			if (Z_TYPE_P(value) == IS_ARRAY) {
				if (zephir_fast_in_array(&optionValue, value)) {
					ZEPHIR_INIT_NVAR(&_6$$13);
					ZEPHIR_CONCAT_SVSVV(&_6$$13, "\t<option selected=\"selected\" value=\"", &optionValue, "\">", &optionText, &closeOption);
					zephir_concat_self(&code, &_6$$13);
				} else {
					ZEPHIR_INIT_NVAR(&_7$$14);
					ZEPHIR_CONCAT_SVSVV(&_7$$14, "\t<option value=\"", &optionValue, "\">", &optionText, &closeOption);
					zephir_concat_self(&code, &_7$$14);
				}
			} else {
				zephir_cast_to_string(&_8$$15, &optionValue);
				ZEPHIR_CPY_WRT(&strOptionValue, &_8$$15);
				zephir_cast_to_string(&_9$$15, value);
				ZEPHIR_CPY_WRT(&strValue, &_9$$15);
				if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
					ZEPHIR_INIT_NVAR(&_10$$16);
					ZEPHIR_CONCAT_SVSVV(&_10$$16, "\t<option selected=\"selected\" value=\"", &strOptionValue, "\">", &optionText, &closeOption);
					zephir_concat_self(&code, &_10$$16);
				} else {
					ZEPHIR_INIT_NVAR(&_11$$17);
					ZEPHIR_CONCAT_SVSVV(&_11$$17, "\t<option value=\"", &strOptionValue, "\">", &optionText, &closeOption);
					zephir_concat_self(&code, &_11$$17);
				}
			}
		} else {
			if (Z_TYPE_P(using) == IS_OBJECT) {
				if (Z_TYPE_P(&params) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&params);
					array_init(&params);
				}
				zephir_array_update_long(&params, 0, &option, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				ZEPHIR_INIT_NVAR(&_12$$19);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_12$$19, using, &params);
				zephir_check_call_status();
				zephir_concat_self(&code, &_12$$19);
			}
		}
	}
	zend_iterator_dtor(_2);
	RETURN_CCTOR(&code);
}

