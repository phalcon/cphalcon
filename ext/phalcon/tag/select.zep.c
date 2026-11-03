
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
 * For the full copyright and license information, please view the LICENSE
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
	zend_bool _0, _4, _5, _6, _9, _3$$6, _7$$13, _8$$13, _10$$19, _11$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_20 = NULL, *_24 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, parameters_sub, *data = NULL, data_sub, __$null, code, escaper, id, name, options, params, useEmpty, value, emptyText, emptyValue, using, _2, _12, _13, _1$$5, _14$$22, _15$$22, _16$$22, _17$$22, _18$$22, _19$$23, _21$$23, _22$$23, _23$$25, _25$$25, _26$$25;

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&useEmpty);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&emptyText);
	ZVAL_UNDEF(&emptyValue);
	ZVAL_UNDEF(&using);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_14$$22);
	ZVAL_UNDEF(&_15$$22);
	ZVAL_UNDEF(&_16$$22);
	ZVAL_UNDEF(&_17$$22);
	ZVAL_UNDEF(&_18$$22);
	ZVAL_UNDEF(&_19$$23);
	ZVAL_UNDEF(&_21$$23);
	ZVAL_UNDEF(&_22$$23);
	ZVAL_UNDEF(&_23$$25);
	ZVAL_UNDEF(&_25$$25);
	ZVAL_UNDEF(&_26$$25);
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
	ZEPHIR_INIT_VAR(&emptyText);
	ZVAL_STRING(&emptyText, "");
	ZEPHIR_INIT_VAR(&emptyValue);
	ZVAL_STRING(&emptyValue, "");
	ZEPHIR_INIT_VAR(&using);
	ZVAL_NULL(&using);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		zephir_create_array(&params, 2, 0);
		zephir_array_fast_append(&params, parameters);
		zephir_array_fast_append(&params, data);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	zephir_memory_observe(&id);
	_0 = zephir_array_isset_long_fetch(&id, &params, 0, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		zephir_memory_observe(&_1$$5);
		zephir_array_fetch_string(&_1$$5, &params, SL("id"), PH_NOISY, "phalcon/Tag/Select.zep", 62);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_long(&params, 0, &_1$$5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&_2);
	zephir_array_fetch_long(&_2, &params, 0, PH_NOISY, "phalcon/Tag/Select.zep", 65);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_SELF(&id, "toStringValue", NULL, 0, &_2);
	zephir_check_call_status();
	if (!(zephir_memnstr_str(&id, SL("["), "phalcon/Tag/Select.zep", 70))) {
		_3$$6 = zephir_array_isset_value_string(&params, SL("id"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_3$$6)) {
			zephir_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_memory_observe(&name);
	_4 = zephir_array_isset_string_fetch(&name, &params, SL("name"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_4)) {
		zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		if (!(zephir_is_true(&name))) {
			zephir_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_memory_observe(&value);
	_5 = zephir_array_isset_string_fetch(&value, &params, SL("value"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_5)) {
		ZEPHIR_CALL_CE_STATIC(&value, phalcon_tag_ce, "getValue", NULL, 0, &id, &params);
		zephir_check_call_status();
	} else {
		zephir_array_unset_string(&params, SL("value"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&useEmpty);
	_6 = zephir_array_isset_string_fetch(&useEmpty, &params, SL("useEmpty"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_6) {
		ZEPHIR_OBS_NVAR(&emptyValue);
		_7$$13 = zephir_array_isset_string_fetch(&emptyValue, &params, SL("emptyValue"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_7$$13)) {
			ZEPHIR_INIT_NVAR(&emptyValue);
			ZVAL_STRING(&emptyValue, "");
		} else {
			zephir_array_unset_string(&params, SL("emptyValue"), PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_OBS_NVAR(&emptyText);
		_8$$13 = zephir_array_isset_string_fetch(&emptyText, &params, SL("emptyText"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_8$$13)) {
			ZEPHIR_INIT_NVAR(&emptyText);
			ZVAL_STRING(&emptyText, "Choose...");
		} else {
			zephir_array_unset_string(&params, SL("emptyText"), PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_array_unset_string(&params, SL("useEmpty"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&options);
	_9 = zephir_array_isset_long_fetch(&options, &params, 1, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_9)) {
		ZEPHIR_CPY_WRT(&options, data);
	}
	if (Z_TYPE_P(&options) == IS_OBJECT) {
		ZEPHIR_OBS_NVAR(&using);
		_10$$19 = zephir_array_isset_string_fetch(&using, &params, SL("using"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(!(_10$$19))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "The 'using' parameter is required", "phalcon/Tag/Select.zep", 115);
			return;
		}
		_11$$19 = Z_TYPE_P(&using) != IS_ARRAY;
		if (_11$$19) {
			_11$$19 = Z_TYPE_P(&using) != IS_OBJECT;
		}
		if (UNEXPECTED(_11$$19)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "The 'using' parameter should be an array", "phalcon/Tag/Select.zep", 121);
			return;
		}
	}
	zephir_array_unset_string(&params, SL("using"), PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "<select");
	ZEPHIR_CALL_CE_STATIC(&_12, phalcon_tag_ce, "renderAttributes", NULL, 0, &_13, &params);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZEPHIR_GET_CONSTANT(&_13, "PHP_EOL");
	ZEPHIR_INIT_VAR(&code);
	ZEPHIR_CONCAT_VSV(&code, &_12, ">", &_13);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&useEmpty)) {
		ZEPHIR_CALL_CE_STATIC(&_14$$22, phalcon_tag_ce, "getEscaperService", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&escaper, &_14$$22);
		ZEPHIR_CALL_METHOD(&_15$$22, &escaper, "attributes", NULL, 0, &emptyValue);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(&_14$$22, "echoOption", NULL, 0, &_15$$22);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_16$$22, &escaper, "html", NULL, 0, &emptyText);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_17$$22);
		ZEPHIR_GET_CONSTANT(&_17$$22, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_18$$22);
		ZEPHIR_CONCAT_VVSV(&_18$$22, &_14$$22, &_16$$22, "</option>", &_17$$22);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&code, &_18$$22);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(&options) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_21$$23);
		ZEPHIR_GET_CONSTANT(&_21$$23, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_22$$23);
		ZEPHIR_CONCAT_SV(&_22$$23, "</option>", &_21$$23);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_SELF(&_19$$23, "optionsFromResultset", &_20, 0, &options, &using, &value, &_22$$23);
		zephir_check_call_status();
		zephir_concat_self(&code, &_19$$23);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		if (Z_TYPE_P(&options) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_25$$25);
			ZEPHIR_GET_CONSTANT(&_25$$25, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_26$$25);
			ZEPHIR_CONCAT_SV(&_26$$25, "</option>", &_25$$25);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_SELF(&_23$$25, "optionsFromArray", &_24, 0, &options, &value, &_26$$25);
			zephir_check_call_status();
			zephir_concat_self(&code, &_23$$25);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_concat_self_str(&code, SL("</select>"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CONCAT_SVSVS(return_value, "\t<option ", &extra, "value=\"", &value_zv, "\">");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
	zval _20$$8, _41$$16;
	zend_bool _27, _13$$5, _35$$13;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_11 = NULL, *_12 = NULL, *_15 = NULL, *_28 = NULL, *_34 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *closeOption = NULL, *_3;
	zval *data_param = NULL, *value, value_sub, closeOption_zv, escapedText, escaper, optionText, optionValue, strOptionValue, strValue, code, escaped, _0, *_1, _26, _5$$4, _6$$4, _8$$4, _9$$4, _10$$3, _14$$6, _16$$6, _17$$6, _18$$7, _19$$7, _21$$9, _22$$9, _23$$9, _24$$10, _25$$10, _29$$12, _30$$12, _31$$12, _32$$12, _33$$11, _36$$14, _37$$14, _38$$14, _39$$15, _40$$15, _42$$17, _43$$17, _44$$17, _45$$18, _46$$18;
	zval data;

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&closeOption_zv);
	ZVAL_UNDEF(&escapedText);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&optionText);
	ZVAL_UNDEF(&optionValue);
	ZVAL_UNDEF(&strOptionValue);
	ZVAL_UNDEF(&strValue);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&escaped);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$11);
	ZVAL_UNDEF(&_36$$14);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_38$$14);
	ZVAL_UNDEF(&_39$$15);
	ZVAL_UNDEF(&_40$$15);
	ZVAL_UNDEF(&_42$$17);
	ZVAL_UNDEF(&_43$$17);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_45$$18);
	ZVAL_UNDEF(&_46$$18);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_41$$16);
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
	ZEPHIR_INIT_VAR(&escaped);
	ZVAL_STRING(&escaped, "");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_tag_ce, "getEscaperService", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&escaper, &_0);
	zephir_is_iterable(&data, 0, "phalcon/Tag/Select.zep", 245);
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
				ZEPHIR_CALL_SELF(&_6$$4, "optionsFromArray", &_7, 0, &optionText, value, &closeOption_zv);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZEPHIR_GET_CONSTANT(&_8$$4, "PHP_EOL");
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZEPHIR_CONCAT_SVSVVSV(&_9$$4, "\t<optgroup label=\"", &escaped, "\">", &_5$$4, &_6$$4, "\t</optgroup>", &_8$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&code, &_9$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				continue;
			}
			ZEPHIR_CALL_SELF(&_10$$3, "toStringValue", &_11, 0, &optionText);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&escapedText, &escaper, "html", &_12, 0, &_10$$3);
			zephir_check_call_status();
			if (Z_TYPE_P(value) == IS_ARRAY) {
				_13$$5 = zephir_fast_in_array(&optionValue, value);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_13$$5) {
					ZVAL_BOOL(&_16$$6, 1);
					ZEPHIR_CALL_SELF(&_14$$6, "echoOption", &_15, 0, &escaped, &_16$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_17$$6);
					ZEPHIR_CONCAT_VVV(&_17$$6, &_14$$6, &escapedText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_17$$6);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CALL_SELF(&_18$$7, "echoOption", &_15, 0, &escaped);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_19$$7);
					ZEPHIR_CONCAT_VVV(&_19$$7, &_18$$7, &escapedText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_19$$7);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				zephir_cast_to_string(&_20$$8, &optionValue);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&strOptionValue, &_20$$8);
				ZEPHIR_CALL_SELF(&strValue, "toStringValue", &_11, 0, value);
				zephir_check_call_status();
				if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
					ZVAL_BOOL(&_22$$9, 1);
					ZEPHIR_CALL_SELF(&_21$$9, "echoOption", &_15, 0, &escaped, &_22$$9);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_23$$9);
					ZEPHIR_CONCAT_VVV(&_23$$9, &_21$$9, &escapedText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_23$$9);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CALL_SELF(&_24$$10, "echoOption", &_15, 0, &escaped);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_25$$10);
					ZEPHIR_CONCAT_VVV(&_25$$10, &_24$$10, &escapedText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_25$$10);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		_27 = 1;
		while (1) {
			if (_27) {
				_27 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_26, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_26)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&optionValue, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&optionText, &data, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&escaped, &escaper, "attributes", &_28, 0, &optionValue);
				zephir_check_call_status();
				if (Z_TYPE_P(&optionText) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_29$$12);
					ZEPHIR_GET_CONSTANT(&_29$$12, "PHP_EOL");
					ZEPHIR_CALL_SELF(&_30$$12, "optionsFromArray", &_7, 0, &optionText, value, &closeOption_zv);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_31$$12);
					ZEPHIR_GET_CONSTANT(&_31$$12, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_32$$12);
					ZEPHIR_CONCAT_SVSVVSV(&_32$$12, "\t<optgroup label=\"", &escaped, "\">", &_29$$12, &_30$$12, "\t</optgroup>", &_31$$12);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_32$$12);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				ZEPHIR_CALL_SELF(&_33$$11, "toStringValue", &_11, 0, &optionText);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&escapedText, &escaper, "html", &_34, 0, &_33$$11);
				zephir_check_call_status();
				if (Z_TYPE_P(value) == IS_ARRAY) {
					_35$$13 = zephir_fast_in_array(&optionValue, value);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_35$$13) {
						ZVAL_BOOL(&_37$$14, 1);
						ZEPHIR_CALL_SELF(&_36$$14, "echoOption", &_15, 0, &escaped, &_37$$14);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_38$$14);
						ZEPHIR_CONCAT_VVV(&_38$$14, &_36$$14, &escapedText, &closeOption_zv);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&code, &_38$$14);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CALL_SELF(&_39$$15, "echoOption", &_15, 0, &escaped);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_40$$15);
						ZEPHIR_CONCAT_VVV(&_40$$15, &_39$$15, &escapedText, &closeOption_zv);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&code, &_40$$15);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					zephir_cast_to_string(&_41$$16, &optionValue);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&strOptionValue, &_41$$16);
					ZEPHIR_CALL_SELF(&strValue, "toStringValue", &_11, 0, value);
					zephir_check_call_status();
					if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
						ZVAL_BOOL(&_43$$17, 1);
						ZEPHIR_CALL_SELF(&_42$$17, "echoOption", &_15, 0, &escaped, &_43$$17);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_44$$17);
						ZEPHIR_CONCAT_VVV(&_44$$17, &_42$$17, &escapedText, &closeOption_zv);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&code, &_44$$17);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CALL_SELF(&_45$$18, "echoOption", &_15, 0, &escaped);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_46$$18);
						ZEPHIR_CONCAT_VVV(&_46$$18, &_45$$18, &escapedText, &closeOption_zv);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&code, &_46$$18);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
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
 *
 * ResultsetInterface does not extend Traversable, but every resultset
 * this is handed is iterable - the concrete Resultset implements
 * Iterator. The local annotation below states what the contract omits.
 */
PHP_METHOD(Phalcon_Tag_Select, optionsFromResultset)
{
	zend_bool _9$$12;
	zend_object_iterator *_3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_8 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *closeOption = NULL;
	zval *resultset, resultset_sub, *using, using_sub, *value, value_sub, closeOption_zv, escaper, executed, option, optionText, optionValue, strOptionValue, strValue, code, params, usingOne, usingZero, _2, _0$$3, _1$$3, _4$$6, _7$$6, _10$$13, _12$$13, _13$$13, _14$$14, _15$$14, _16$$16, _17$$16, _18$$16, _19$$17, _20$$17, _21$$19;

	ZVAL_UNDEF(&resultset_sub);
	ZVAL_UNDEF(&using_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&closeOption_zv);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&executed);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&optionText);
	ZVAL_UNDEF(&optionValue);
	ZVAL_UNDEF(&strOptionValue);
	ZVAL_UNDEF(&strValue);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&usingOne);
	ZVAL_UNDEF(&usingZero);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$19);
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
	ZEPHIR_INIT_VAR(&usingOne);
	ZVAL_STRING(&usingOne, "");
	ZEPHIR_INIT_VAR(&usingZero);
	ZVAL_STRING(&usingZero, "");
	if (Z_TYPE_P(using) == IS_ARRAY) {
		if (UNEXPECTED(zephir_fast_count_int(using) != 2)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Parameter 'using' requires two values", "phalcon/Tag/Select.zep", 270);
			return;
		}
		zephir_memory_observe(&_0$$3);
		zephir_array_fetch_long(&_0$$3, using, 0, PH_NOISY, "phalcon/Tag/Select.zep", 273);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_SELF(&usingZero, "toStringValue", NULL, 0, &_0$$3);
		zephir_check_call_status();
		zephir_memory_observe(&_1$$3);
		zephir_array_fetch_long(&_1$$3, using, 1, PH_NOISY, "phalcon/Tag/Select.zep", 274);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_SELF(&usingOne, "toStringValue", NULL, 0, &_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_CE_STATIC(&_2, phalcon_tag_ce, "getEscaperService", NULL, 0);
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
					ZEPHIR_CALL_METHOD(&optionValue, &option, "readAttribute", NULL, 0, &usingZero);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&optionText, &option, "readAttribute", NULL, 0, &usingOne);
					zephir_check_call_status();
				} else {
					ZEPHIR_OBS_NVAR(&optionValue);
					zephir_read_property_zval(&optionValue, &option, &usingZero, PH_NOISY_CC);
					ZEPHIR_OBS_NVAR(&optionText);
					zephir_read_property_zval(&optionText, &option, &usingOne, PH_NOISY_CC);
				}
			} else {
				if (UNEXPECTED(Z_TYPE_P(&option) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_tag_exception_ce, "Resultset returned an invalid value", "phalcon/Tag/Select.zep", 293);
					return;
				}
				ZEPHIR_OBS_NVAR(&optionValue);
				zephir_array_fetch(&optionValue, &option, &usingZero, PH_NOISY, "phalcon/Tag/Select.zep", 296);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&optionText);
				zephir_array_fetch(&optionText, &option, &usingOne, PH_NOISY, "phalcon/Tag/Select.zep", 297);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_CALL_SELF(&_4$$6, "toStringValue", &_5, 0, &optionValue);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&optionValue, &escaper, "attributes", &_6, 0, &_4$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_SELF(&_7$$6, "toStringValue", &_5, 0, &optionText);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&optionText, &escaper, "html", &_8, 0, &_7$$6);
			zephir_check_call_status();
			if (Z_TYPE_P(value) == IS_ARRAY) {
				_9$$12 = zephir_fast_in_array(&optionValue, value);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_9$$12) {
					ZVAL_BOOL(&_12$$13, 1);
					ZEPHIR_CALL_SELF(&_10$$13, "echoOption", &_11, 0, &optionValue, &_12$$13);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_13$$13);
					ZEPHIR_CONCAT_VVV(&_13$$13, &_10$$13, &optionText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_13$$13);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CALL_SELF(&_14$$14, "echoOption", &_11, 0, &optionValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_15$$14);
					ZEPHIR_CONCAT_VVV(&_15$$14, &_14$$14, &optionText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_15$$14);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				ZEPHIR_CPY_WRT(&strOptionValue, &optionValue);
				ZEPHIR_CALL_SELF(&strValue, "toStringValue", &_5, 0, value);
				zephir_check_call_status();
				if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
					ZVAL_BOOL(&_17$$16, 1);
					ZEPHIR_CALL_SELF(&_16$$16, "echoOption", &_11, 0, &strOptionValue, &_17$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_18$$16);
					ZEPHIR_CONCAT_VVV(&_18$$16, &_16$$16, &optionText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_18$$16);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CALL_SELF(&_19$$17, "echoOption", &_11, 0, &strOptionValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_20$$17);
					ZEPHIR_CONCAT_VVV(&_20$$17, &_19$$17, &optionText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_20$$17);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		} else {
			if (zephir_is_instance_of(using, SL("Closure"))) {
				if (Z_TYPE_P(&params) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&params);
					array_init(&params);
				}
				zephir_array_update_long(&params, 0, &option, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&executed);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&executed, using, &params);
				zephir_check_call_status();
				ZEPHIR_CALL_SELF(&_21$$19, "toStringValue", &_5, 0, &executed);
				zephir_check_call_status();
				zephir_concat_self(&code, &_21$$19);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	zend_iterator_dtor(_3);
	}
	RETURN_CCTOR(&code);
}

