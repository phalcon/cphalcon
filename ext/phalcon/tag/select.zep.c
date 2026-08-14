
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
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/iterator.h"
#include "Zend/zend_closures.h"


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
 *
 * @phpstan-import-type tag_parameters from BaseTag
 * @phpstan-import-type tag_select_data from BaseTag
 */
ZEPHIR_INIT_CLASS(Phalcon_Tag_Select)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Tag, Select, phalcon, tag_select, phalcon_tag_select_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;
}

/**
 * Generates a SELECT tag
 *
 * @phpstan-param tag_parameters|string $parameters
 *
 * @param array|string $parameters = [
 *     'id' => '',
 *     'name' => '',
 *     'value' => '',
 *     'useEmpty' => false,
 *     'emptyValue' => '',
 *     'emptyText' => '',
 * ]
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Tag_Select, selectField)
{
	zend_bool _2$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, parameters_sub, *data = NULL, data_sub, __$null, params, name, id, value, useEmpty, code, emptyValue, emptyText, options, using, _1, _3, _4, _0$$5, _5$$22, _6$$22, _7$$22, _8$$23, _10$$23, _11$$23, _12$$25, _14$$25, _15$$25;

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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_5$$22);
	ZVAL_UNDEF(&_6$$22);
	ZVAL_UNDEF(&_7$$22);
	ZVAL_UNDEF(&_8$$23);
	ZVAL_UNDEF(&_10$$23);
	ZVAL_UNDEF(&_11$$23);
	ZVAL_UNDEF(&_12$$25);
	ZVAL_UNDEF(&_14$$25);
	ZVAL_UNDEF(&_15$$25);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(parameters)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&id);
	if (!(zephir_array_isset_long_fetch(&id, &params, 0, 0))) {
		zephir_array_fetch_string(&_0$$5, &params, SL("id"), PH_NOISY | PH_READONLY, "phalcon/Tag/Select.zep", 60);
		zephir_array_update_long(&params, 0, &_0$$5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	zephir_array_fetch_long(&_1, &params, 0, PH_NOISY | PH_READONLY, "phalcon/Tag/Select.zep", 63);
	ZEPHIR_CALL_SELF(&id, "tostringvalue", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_memnstr_str(&id, SL("["), "phalcon/Tag/Select.zep", 68))) {
		if (!(zephir_array_isset_value_string(&params, SL("id")))) {
			zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_memory_observe(&name);
	if (!(zephir_array_isset_string_fetch(&name, &params, SL("name"), 0))) {
		zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
	} else {
		if (!(zephir_is_true(&name))) {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_memory_observe(&value);
	if (!(zephir_array_isset_string_fetch(&value, &params, SL("value"), 0))) {
		ZEPHIR_CALL_CE_STATIC(&value, phalcon_tag_ce, "getvalue", NULL, 0, &id, &params);
		zephir_check_call_status();
	} else {
		zephir_array_unset_string(&params, SL("value"), PH_SEPARATE);
	}
	zephir_memory_observe(&useEmpty);
	if (zephir_array_isset_string_fetch(&useEmpty, &params, SL("useEmpty"), 0)) {
		zephir_memory_observe(&emptyValue);
		if (!(zephir_array_isset_string_fetch(&emptyValue, &params, SL("emptyValue"), 0))) {
			ZEPHIR_INIT_NVAR(&emptyValue);
			ZVAL_STRING(&emptyValue, "");
		} else {
			zephir_array_unset_string(&params, SL("emptyValue"), PH_SEPARATE);
		}
		zephir_memory_observe(&emptyText);
		if (!(zephir_array_isset_string_fetch(&emptyText, &params, SL("emptyText"), 0))) {
			ZEPHIR_INIT_NVAR(&emptyText);
			ZVAL_STRING(&emptyText, "Choose...");
		} else {
			zephir_array_unset_string(&params, SL("emptyText"), PH_SEPARATE);
		}
		zephir_array_unset_string(&params, SL("useEmpty"), PH_SEPARATE);
	}
	zephir_memory_observe(&options);
	if (!(zephir_array_isset_long_fetch(&options, &params, 1, 0))) {
		ZEPHIR_CPY_WRT(&options, data);
	}
	if (Z_TYPE_P(&options) == IS_OBJECT) {
		zephir_memory_observe(&using);
		if (UNEXPECTED(!(zephir_array_isset_string_fetch(&using, &params, SL("using"), 0)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "The 'using' parameter is required", "phalcon/Tag/Select.zep", 113);
			return;
		}
		_2$$19 = Z_TYPE_P(&using) != IS_ARRAY;
		if (_2$$19) {
			_2$$19 = Z_TYPE_P(&using) != IS_OBJECT;
		}
		if (UNEXPECTED(_2$$19)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "The 'using' parameter should be an array", "phalcon/Tag/Select.zep", 119);
			return;
		}
	}
	zephir_array_unset_string(&params, SL("using"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "<select");
	ZEPHIR_CALL_CE_STATIC(&_3, phalcon_tag_ce, "renderattributes", NULL, 0, &_4, &params);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZEPHIR_GET_CONSTANT(&_4, "PHP_EOL");
	ZEPHIR_INIT_VAR(&code);
	ZEPHIR_CONCAT_VSV(&code, &_3, ">", &_4);
	if (zephir_is_true(&useEmpty)) {
		ZEPHIR_CALL_SELF(&_5$$22, "echooption", NULL, 0, &emptyValue);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$22);
		ZEPHIR_GET_CONSTANT(&_6$$22, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_7$$22);
		ZEPHIR_CONCAT_VVSV(&_7$$22, &_5$$22, &emptyText, "</option>", &_6$$22);
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

PHP_METHOD(Phalcon_Tag_Select, echoOption)
{
	zval extra;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool selected;
	zval value_zv, *selected_param = NULL, _0;
	zend_string *value = NULL;

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&extra);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(selected)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		selected_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	if (!selected_param) {
		selected = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	if (selected) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "selected=\"selected\" ");
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "");
	}
	zephir_get_strval(&extra, &_0);
	ZEPHIR_CONCAT_SVSVS(return_value, "\t<option ", &extra, "value=\"", &value_zv, "\">");
	RETURN_MM();
}

/**
 * Reduces an arbitrary option value to the string the markup needs.
 * Option data is user supplied, so anything that cannot be expressed as
 * a string reads back as an empty string rather than aborting the tag.
 */
PHP_METHOD(Phalcon_Tag_Select, toStringValue)
{
	zval _2$$3;
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *value, value_sub;

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &value);
	_0 = zephir_is_scalar(value);
	if (!(_0)) {
		_1 = Z_TYPE_P(value) == IS_OBJECT;
		if (_1) {
			_1 = zephir_is_instance_of(value, SL("Stringable"));
		}
		_0 = _1;
	}
	if (_0) {
		zephir_cast_to_string(&_2$$3, value);
		RETURN_CTOR(&_2$$3);
	}
	RETURN_MM_STRING("");
}

/**
 * Generate the OPTION tags based on an array
 *
 * @phpstan-param tag_select_data $data
 */
PHP_METHOD(Phalcon_Tag_Select, optionsFromArray)
{
	zval _19$$8, _39$$16;
	zend_bool _26;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_11 = NULL, *_12 = NULL, *_14 = NULL, *_27 = NULL, *_33 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *closeOption = NULL, *_3;
	zval *data_param = NULL, *value, value_sub, closeOption_zv, strValue, strOptionValue, code, optionValue, optionText, escaped, escapedText, escaper, _0, *_1, _25, _5$$4, _6$$4, _8$$4, _9$$4, _10$$3, _13$$6, _15$$6, _16$$6, _17$$7, _18$$7, _20$$9, _21$$9, _22$$9, _23$$10, _24$$10, _28$$12, _29$$12, _30$$12, _31$$12, _32$$11, _34$$14, _35$$14, _36$$14, _37$$15, _38$$15, _40$$17, _41$$17, _42$$17, _43$$18, _44$$18;
	zval data;

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&closeOption_zv);
	ZVAL_UNDEF(&strValue);
	ZVAL_UNDEF(&strOptionValue);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&optionValue);
	ZVAL_UNDEF(&optionText);
	ZVAL_UNDEF(&escaped);
	ZVAL_UNDEF(&escapedText);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$11);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_36$$14);
	ZVAL_UNDEF(&_37$$15);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_41$$17);
	ZVAL_UNDEF(&_42$$17);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_44$$18);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_39$$16);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_ZVAL(value)
		Z_PARAM_STR(closeOption)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data_param = ZEND_CALL_ARG(execute_data, 1);
	value = ZEND_CALL_ARG(execute_data, 2);
	zephir_get_arrval(&data, data_param);
	zephir_memory_observe(&closeOption_zv);
	ZVAL_STR_COPY(&closeOption_zv, closeOption);
	ZEPHIR_INIT_VAR(&code);
	ZVAL_STRING(&code, "");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_tag_ce, "getescaperservice", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&escaper, &_0);
	zephir_is_iterable(&data, 0, "phalcon/Tag/Select.zep", 241);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&optionValue);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&optionValue, _3);
			} else {
				ZVAL_LONG(&optionValue, _2);
			}
			ZEPHIR_INIT_NVAR(&optionText);
			ZVAL_COPY(&optionText, _1);
			ZEPHIR_CALL_METHOD(&escaped, &escaper, "attributes", &_4, 0, &optionValue);
			zephir_check_call_status();
			if (Z_TYPE_P(&optionText) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZEPHIR_GET_CONSTANT(&_5$$4, "PHP_EOL");
				ZEPHIR_CALL_SELF(&_6$$4, "optionsfromarray", &_7, 0, &optionText, value, &closeOption_zv);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZEPHIR_GET_CONSTANT(&_8$$4, "PHP_EOL");
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZEPHIR_CONCAT_SVSVVSV(&_9$$4, "\t<optgroup label=\"", &escaped, "\">", &_5$$4, &_6$$4, "\t</optgroup>", &_8$$4);
				zephir_concat_self(&code, &_9$$4);
				continue;
			}
			ZEPHIR_CALL_SELF(&_10$$3, "tostringvalue", &_11, 0, &optionText);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&escapedText, &escaper, "html", &_12, 0, &_10$$3);
			zephir_check_call_status();
			if (Z_TYPE_P(value) == IS_ARRAY) {
				if (zephir_fast_in_array(&optionValue, value)) {
					ZVAL_BOOL(&_15$$6, 1);
					ZEPHIR_CALL_SELF(&_13$$6, "echooption", &_14, 0, &escaped, &_15$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_16$$6);
					ZEPHIR_CONCAT_VVV(&_16$$6, &_13$$6, &escapedText, &closeOption_zv);
					zephir_concat_self(&code, &_16$$6);
				} else {
					ZEPHIR_CALL_SELF(&_17$$7, "echooption", &_14, 0, &escaped);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_18$$7);
					ZEPHIR_CONCAT_VVV(&_18$$7, &_17$$7, &escapedText, &closeOption_zv);
					zephir_concat_self(&code, &_18$$7);
				}
			} else {
				zephir_cast_to_string(&_19$$8, &optionValue);
				ZEPHIR_CPY_WRT(&strOptionValue, &_19$$8);
				ZEPHIR_CALL_SELF(&strValue, "tostringvalue", &_11, 0, value);
				zephir_check_call_status();
				if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
					ZVAL_BOOL(&_21$$9, 1);
					ZEPHIR_CALL_SELF(&_20$$9, "echooption", &_14, 0, &escaped, &_21$$9);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_22$$9);
					ZEPHIR_CONCAT_VVV(&_22$$9, &_20$$9, &escapedText, &closeOption_zv);
					zephir_concat_self(&code, &_22$$9);
				} else {
					ZEPHIR_CALL_SELF(&_23$$10, "echooption", &_14, 0, &escaped);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_24$$10);
					ZEPHIR_CONCAT_VVV(&_24$$10, &_23$$10, &escapedText, &closeOption_zv);
					zephir_concat_self(&code, &_24$$10);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		_26 = 1;
		while (1) {
			if (_26) {
				_26 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_25, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_25)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&optionValue, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&optionText, &data, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&escaped, &escaper, "attributes", &_27, 0, &optionValue);
				zephir_check_call_status();
				if (Z_TYPE_P(&optionText) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_28$$12);
					ZEPHIR_GET_CONSTANT(&_28$$12, "PHP_EOL");
					ZEPHIR_CALL_SELF(&_29$$12, "optionsfromarray", &_7, 0, &optionText, value, &closeOption_zv);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_30$$12);
					ZEPHIR_GET_CONSTANT(&_30$$12, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_31$$12);
					ZEPHIR_CONCAT_SVSVVSV(&_31$$12, "\t<optgroup label=\"", &escaped, "\">", &_28$$12, &_29$$12, "\t</optgroup>", &_30$$12);
					zephir_concat_self(&code, &_31$$12);
					continue;
				}
				ZEPHIR_CALL_SELF(&_32$$11, "tostringvalue", &_11, 0, &optionText);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&escapedText, &escaper, "html", &_33, 0, &_32$$11);
				zephir_check_call_status();
				if (Z_TYPE_P(value) == IS_ARRAY) {
					if (zephir_fast_in_array(&optionValue, value)) {
						ZVAL_BOOL(&_35$$14, 1);
						ZEPHIR_CALL_SELF(&_34$$14, "echooption", &_14, 0, &escaped, &_35$$14);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_36$$14);
						ZEPHIR_CONCAT_VVV(&_36$$14, &_34$$14, &escapedText, &closeOption_zv);
						zephir_concat_self(&code, &_36$$14);
					} else {
						ZEPHIR_CALL_SELF(&_37$$15, "echooption", &_14, 0, &escaped);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_38$$15);
						ZEPHIR_CONCAT_VVV(&_38$$15, &_37$$15, &escapedText, &closeOption_zv);
						zephir_concat_self(&code, &_38$$15);
					}
				} else {
					zephir_cast_to_string(&_39$$16, &optionValue);
					ZEPHIR_CPY_WRT(&strOptionValue, &_39$$16);
					ZEPHIR_CALL_SELF(&strValue, "tostringvalue", &_11, 0, value);
					zephir_check_call_status();
					if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
						ZVAL_BOOL(&_41$$17, 1);
						ZEPHIR_CALL_SELF(&_40$$17, "echooption", &_14, 0, &escaped, &_41$$17);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_42$$17);
						ZEPHIR_CONCAT_VVV(&_42$$17, &_40$$17, &escapedText, &closeOption_zv);
						zephir_concat_self(&code, &_42$$17);
					} else {
						ZEPHIR_CALL_SELF(&_43$$18, "echooption", &_14, 0, &escaped);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_44$$18);
						ZEPHIR_CONCAT_VVV(&_44$$18, &_43$$18, &escapedText, &closeOption_zv);
						zephir_concat_self(&code, &_44$$18);
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&optionText);
	ZEPHIR_INIT_NVAR(&optionValue);
	RETURN_CCTOR(&code);
}

/**
 * Generate the OPTION tags based on a resultset
 */
PHP_METHOD(Phalcon_Tag_Select, optionsFromResultset)
{
	zend_object_iterator *_3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *closeOption = NULL;
	zval *resultset, resultset_sub, *using, using_sub, *value, value_sub, closeOption_zv, code, escaper, executed, params, option, usingZero, usingOne, optionValue, optionText, strValue, strOptionValue, _2, _0$$3, _1$$3, _4$$6, _7$$6, _9$$13, _11$$13, _12$$13, _13$$14, _14$$14, _15$$16, _16$$16, _17$$16, _18$$17, _19$$17, _20$$19;

	ZVAL_UNDEF(&resultset_sub);
	ZVAL_UNDEF(&using_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&closeOption_zv);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&executed);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&usingZero);
	ZVAL_UNDEF(&usingOne);
	ZVAL_UNDEF(&optionValue);
	ZVAL_UNDEF(&optionText);
	ZVAL_UNDEF(&strValue);
	ZVAL_UNDEF(&strOptionValue);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_20$$19);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(resultset, phalcon_mvc_model_resultsetinterface_ce)
		Z_PARAM_ZVAL(using)
		Z_PARAM_ZVAL(value)
		Z_PARAM_STR(closeOption)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	resultset = ZEND_CALL_ARG(execute_data, 1);
	using = ZEND_CALL_ARG(execute_data, 2);
	value = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&closeOption_zv);
	ZVAL_STR_COPY(&closeOption_zv, closeOption);
	ZEPHIR_INIT_VAR(&code);
	ZVAL_STRING(&code, "");
	ZEPHIR_INIT_VAR(&params);
	ZVAL_NULL(&params);
	if (Z_TYPE_P(using) == IS_ARRAY) {
		if (UNEXPECTED(zephir_fast_count_int(using) != 2)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Parameter 'using' requires two values", "phalcon/Tag/Select.zep", 262);
			return;
		}
		zephir_array_fetch_long(&_0$$3, using, 0, PH_NOISY | PH_READONLY, "phalcon/Tag/Select.zep", 265);
		ZEPHIR_CALL_SELF(&usingZero, "tostringvalue", NULL, 0, &_0$$3);
		zephir_check_call_status();
		zephir_array_fetch_long(&_1$$3, using, 1, PH_NOISY | PH_READONLY, "phalcon/Tag/Select.zep", 266);
		ZEPHIR_CALL_SELF(&usingOne, "tostringvalue", NULL, 0, &_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_CE_STATIC(&_2, phalcon_tag_ce, "getescaperservice", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&escaper, &_2);
	_3 = zephir_get_iterator(resultset);
	if (EXPECTED(_3 != NULL)) {
		_3->funcs->rewind(_3);
		for (;_3->funcs->valid(_3) == SUCCESS && !EG(exception); _3->funcs->move_forward(_3)) {
		{
			ZEPHIR_ITERATOR_COPY(&option, _3);
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
					zephir_read_property_zval(&optionValue, &option, &usingZero, PH_NOISY_CC);
					ZEPHIR_OBS_NVAR(&optionText);
					zephir_read_property_zval(&optionText, &option, &usingOne, PH_NOISY_CC);
				}
			} else {
				if (UNEXPECTED(Z_TYPE_P(&option) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Resultset returned an invalid value", "phalcon/Tag/Select.zep", 285);
					return;
				}
				ZEPHIR_OBS_NVAR(&optionValue);
				zephir_array_fetch(&optionValue, &option, &usingZero, PH_NOISY, "phalcon/Tag/Select.zep", 288);
				ZEPHIR_OBS_NVAR(&optionText);
				zephir_array_fetch(&optionText, &option, &usingOne, PH_NOISY, "phalcon/Tag/Select.zep", 289);
			}
			ZEPHIR_CALL_SELF(&_4$$6, "tostringvalue", &_5, 0, &optionValue);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&optionValue, &escaper, "attributes", &_6, 0, &_4$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_SELF(&_7$$6, "tostringvalue", &_5, 0, &optionText);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&optionText, &escaper, "html", &_8, 0, &_7$$6);
			zephir_check_call_status();
			if (Z_TYPE_P(value) == IS_ARRAY) {
				if (zephir_fast_in_array(&optionValue, value)) {
					ZVAL_BOOL(&_11$$13, 1);
					ZEPHIR_CALL_SELF(&_9$$13, "echooption", &_10, 0, &optionValue, &_11$$13);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_12$$13);
					ZEPHIR_CONCAT_VVV(&_12$$13, &_9$$13, &optionText, &closeOption_zv);
					zephir_concat_self(&code, &_12$$13);
				} else {
					ZEPHIR_CALL_SELF(&_13$$14, "echooption", &_10, 0, &optionValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_14$$14);
					ZEPHIR_CONCAT_VVV(&_14$$14, &_13$$14, &optionText, &closeOption_zv);
					zephir_concat_self(&code, &_14$$14);
				}
			} else {
				ZEPHIR_CPY_WRT(&strOptionValue, &optionValue);
				ZEPHIR_CALL_SELF(&strValue, "tostringvalue", &_5, 0, value);
				zephir_check_call_status();
				if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
					ZVAL_BOOL(&_16$$16, 1);
					ZEPHIR_CALL_SELF(&_15$$16, "echooption", &_10, 0, &strOptionValue, &_16$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_17$$16);
					ZEPHIR_CONCAT_VVV(&_17$$16, &_15$$16, &optionText, &closeOption_zv);
					zephir_concat_self(&code, &_17$$16);
				} else {
					ZEPHIR_CALL_SELF(&_18$$17, "echooption", &_10, 0, &strOptionValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_19$$17);
					ZEPHIR_CONCAT_VVV(&_19$$17, &_18$$17, &optionText, &closeOption_zv);
					zephir_concat_self(&code, &_19$$17);
				}
			}
		} else {
			if (zephir_is_instance_of(using, SL("Closure"))) {
				if (Z_TYPE_P(&params) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&params);
					array_init(&params);
				}
				zephir_array_update_long(&params, 0, &option, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				ZEPHIR_INIT_NVAR(&executed);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&executed, using, &params);
				zephir_check_call_status();
				ZEPHIR_CALL_SELF(&_20$$19, "tostringvalue", &_5, 0, &executed);
				zephir_check_call_status();
				zephir_concat_self(&code, &_20$$19);
			}
		}
	}
	zend_iterator_dtor(_3);
	}
	RETURN_CCTOR(&code);
}

