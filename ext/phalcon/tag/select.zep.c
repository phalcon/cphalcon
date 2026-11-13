
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, parameters_sub, *data = NULL, data_sub, __$null, code, escaper, id, name, options, params, useEmpty, value, emptyText, emptyValue, using, _2, _12, _13, _1$$5, _14$$22, _15$$22, _16$$22, _17$$22, _18$$22, _19$$23, _20$$23, _21$$23, _22$$25, _23$$25, _24$$25;

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
	ZVAL_UNDEF(&_20$$23);
	ZVAL_UNDEF(&_21$$23);
	ZVAL_UNDEF(&_22$$25);
	ZVAL_UNDEF(&_23$$25);
	ZVAL_UNDEF(&_24$$25);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
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
	ZEPHIR_CALL_SELF_CACHED(&id, "toStringValue", &_zephir_call_cache[0], &_2);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(&value, phalcon_tag_ce, "getValue", &_zephir_call_cache[1], &id, &params);
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
	ZEPHIR_CALL_CE_STATIC_CACHED(&_12, phalcon_tag_ce, "renderAttributes", &_zephir_call_cache[2], &_13, &params);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(&_14$$22, phalcon_tag_ce, "getEscaperService", &_zephir_call_cache[3]);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&escaper, &_14$$22);
		ZEPHIR_CALL_METHOD_CACHED(&_15$$22, &escaper, "attributes", &_zephir_call_cache[4], &emptyValue);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF_CACHED(&_14$$22, "echoOption", &_zephir_call_cache[5], &_15$$22);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_16$$22, &escaper, "html", &_zephir_call_cache[6], &emptyText);
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
		ZEPHIR_INIT_VAR(&_20$$23);
		ZEPHIR_GET_CONSTANT(&_20$$23, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_21$$23);
		ZEPHIR_CONCAT_SV(&_21$$23, "</option>", &_20$$23);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_SELF_CACHED(&_19$$23, "optionsFromResultset", &_zephir_call_cache[7], &options, &using, &value, &_21$$23);
		zephir_check_call_status();
		zephir_concat_self(&code, &_19$$23);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		if (Z_TYPE_P(&options) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_23$$25);
			ZEPHIR_GET_CONSTANT(&_23$$25, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_24$$25);
			ZEPHIR_CONCAT_SV(&_24$$25, "</option>", &_23$$25);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_SELF_CACHED(&_22$$25, "optionsFromArray", &_zephir_call_cache[8], &options, &value, &_24$$25);
			zephir_check_call_status();
			zephir_concat_self(&code, &_22$$25);
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
	zval _15$$8, _34$$16;
	zend_bool _22, _9$$5, _28$$13;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *closeOption = NULL, *_3;
	zval *data_param = NULL, *value, value_sub, closeOption_zv, escapedText, escaper, optionText, optionValue, strOptionValue, strValue, code, escaped, _0, *_1, _21, _4$$4, _5$$4, _6$$4, _7$$4, _8$$3, _10$$6, _11$$6, _12$$6, _13$$7, _14$$7, _16$$9, _17$$9, _18$$9, _19$$10, _20$$10, _23$$12, _24$$12, _25$$12, _26$$12, _27$$11, _29$$14, _30$$14, _31$$14, _32$$15, _33$$15, _35$$17, _36$$17, _37$$17, _38$$18, _39$$18;
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
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&_36$$17);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_38$$18);
	ZVAL_UNDEF(&_39$$18);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_34$$16);
	ZEND_TLS zephir_method_cache _zephir_call_cache[24];
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
	ZEPHIR_CALL_CE_STATIC_CACHED(&_0, phalcon_tag_ce, "getEscaperService", &_zephir_call_cache[0]);
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
			ZEPHIR_CALL_METHOD_CACHED(&escaped, &escaper, "attributes", &_zephir_call_cache[1], &optionValue);
			zephir_check_call_status();
			if (Z_TYPE_P(&optionText) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_4$$4);
				ZEPHIR_GET_CONSTANT(&_4$$4, "PHP_EOL");
				ZEPHIR_CALL_SELF_CACHED(&_5$$4, "optionsFromArray", &_zephir_call_cache[2], &optionText, value, &closeOption_zv);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZEPHIR_GET_CONSTANT(&_6$$4, "PHP_EOL");
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZEPHIR_CONCAT_SVSVVSV(&_7$$4, "\t<optgroup label=\"", &escaped, "\">", &_4$$4, &_5$$4, "\t</optgroup>", &_6$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&code, &_7$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				continue;
			}
			ZEPHIR_CALL_SELF_CACHED(&_8$$3, "toStringValue", &_zephir_call_cache[3], &optionText);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&escapedText, &escaper, "html", &_zephir_call_cache[4], &_8$$3);
			zephir_check_call_status();
			if (Z_TYPE_P(value) == IS_ARRAY) {
				_9$$5 = zephir_fast_in_array(&optionValue, value);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_9$$5) {
					ZVAL_BOOL(&_11$$6, 1);
					ZEPHIR_CALL_SELF_CACHED(&_10$$6, "echoOption", &_zephir_call_cache[5], &escaped, &_11$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_12$$6);
					ZEPHIR_CONCAT_VVV(&_12$$6, &_10$$6, &escapedText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_12$$6);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CALL_SELF_CACHED(&_13$$7, "echoOption", &_zephir_call_cache[6], &escaped);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_14$$7);
					ZEPHIR_CONCAT_VVV(&_14$$7, &_13$$7, &escapedText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_14$$7);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				zephir_cast_to_string(&_15$$8, &optionValue);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&strOptionValue, &_15$$8);
				ZEPHIR_CALL_SELF_CACHED(&strValue, "toStringValue", &_zephir_call_cache[7], value);
				zephir_check_call_status();
				if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
					ZVAL_BOOL(&_17$$9, 1);
					ZEPHIR_CALL_SELF_CACHED(&_16$$9, "echoOption", &_zephir_call_cache[8], &escaped, &_17$$9);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_18$$9);
					ZEPHIR_CONCAT_VVV(&_18$$9, &_16$$9, &escapedText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_18$$9);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CALL_SELF_CACHED(&_19$$10, "echoOption", &_zephir_call_cache[9], &escaped);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_20$$10);
					ZEPHIR_CONCAT_VVV(&_20$$10, &_19$$10, &escapedText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_20$$10);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &data, "rewind", &_zephir_call_cache[10]);
		zephir_check_call_status();
		_22 = 1;
		while (1) {
			if (_22) {
				_22 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &data, "next", &_zephir_call_cache[11]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_21, &data, "valid", &_zephir_call_cache[12]);
			zephir_check_call_status();
			if (!zend_is_true(&_21)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&optionValue, &data, "key", &_zephir_call_cache[13]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&optionText, &data, "current", &_zephir_call_cache[14]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&escaped, &escaper, "attributes", &_zephir_call_cache[15], &optionValue);
				zephir_check_call_status();
				if (Z_TYPE_P(&optionText) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_23$$12);
					ZEPHIR_GET_CONSTANT(&_23$$12, "PHP_EOL");
					ZEPHIR_CALL_SELF_CACHED(&_24$$12, "optionsFromArray", &_zephir_call_cache[16], &optionText, value, &closeOption_zv);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_25$$12);
					ZEPHIR_GET_CONSTANT(&_25$$12, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_26$$12);
					ZEPHIR_CONCAT_SVSVVSV(&_26$$12, "\t<optgroup label=\"", &escaped, "\">", &_23$$12, &_24$$12, "\t</optgroup>", &_25$$12);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_26$$12);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				ZEPHIR_CALL_SELF_CACHED(&_27$$11, "toStringValue", &_zephir_call_cache[17], &optionText);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&escapedText, &escaper, "html", &_zephir_call_cache[18], &_27$$11);
				zephir_check_call_status();
				if (Z_TYPE_P(value) == IS_ARRAY) {
					_28$$13 = zephir_fast_in_array(&optionValue, value);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_28$$13) {
						ZVAL_BOOL(&_30$$14, 1);
						ZEPHIR_CALL_SELF_CACHED(&_29$$14, "echoOption", &_zephir_call_cache[19], &escaped, &_30$$14);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_31$$14);
						ZEPHIR_CONCAT_VVV(&_31$$14, &_29$$14, &escapedText, &closeOption_zv);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&code, &_31$$14);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CALL_SELF_CACHED(&_32$$15, "echoOption", &_zephir_call_cache[20], &escaped);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_33$$15);
						ZEPHIR_CONCAT_VVV(&_33$$15, &_32$$15, &escapedText, &closeOption_zv);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&code, &_33$$15);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					zephir_cast_to_string(&_34$$16, &optionValue);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&strOptionValue, &_34$$16);
					ZEPHIR_CALL_SELF_CACHED(&strValue, "toStringValue", &_zephir_call_cache[21], value);
					zephir_check_call_status();
					if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
						ZVAL_BOOL(&_36$$17, 1);
						ZEPHIR_CALL_SELF_CACHED(&_35$$17, "echoOption", &_zephir_call_cache[22], &escaped, &_36$$17);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_37$$17);
						ZEPHIR_CONCAT_VVV(&_37$$17, &_35$$17, &escapedText, &closeOption_zv);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&code, &_37$$17);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CALL_SELF_CACHED(&_38$$18, "echoOption", &_zephir_call_cache[23], &escaped);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_39$$18);
						ZEPHIR_CONCAT_VVV(&_39$$18, &_38$$18, &escapedText, &closeOption_zv);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&code, &_39$$18);
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
	zend_bool _6$$12;
	zend_object_iterator *_3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *closeOption = NULL;
	zval *resultset, resultset_sub, *using, using_sub, *value, value_sub, closeOption_zv, escaper, executed, option, optionText, optionValue, strOptionValue, strValue, code, params, usingOne, usingZero, _2, _0$$3, _1$$3, _4$$6, _5$$6, _7$$13, _8$$13, _9$$13, _10$$14, _11$$14, _12$$16, _13$$16, _14$$16, _15$$17, _16$$17, _17$$19;

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
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$16);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_15$$17);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_17$$19);
	ZEND_TLS zephir_method_cache _zephir_call_cache[15];
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
		ZEPHIR_CALL_SELF_CACHED(&usingZero, "toStringValue", &_zephir_call_cache[0], &_0$$3);
		zephir_check_call_status();
		zephir_memory_observe(&_1$$3);
		zephir_array_fetch_long(&_1$$3, using, 1, PH_NOISY, "phalcon/Tag/Select.zep", 274);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_SELF_CACHED(&usingOne, "toStringValue", &_zephir_call_cache[1], &_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_CE_STATIC_CACHED(&_2, phalcon_tag_ce, "getEscaperService", &_zephir_call_cache[2]);
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
					ZEPHIR_CALL_METHOD_CACHED(&optionValue, &option, "readAttribute", &_zephir_call_cache[3], &usingZero);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&optionText, &option, "readAttribute", &_zephir_call_cache[4], &usingOne);
					zephir_check_call_status();
				} else {
					ZEPHIR_OBS_NVAR(&optionValue);
					zephir_read_property_zval(&optionValue, &option, &usingZero, PH_NOISY_CC);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&optionText);
					zephir_read_property_zval(&optionText, &option, &usingOne, PH_NOISY_CC);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
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
			ZEPHIR_CALL_SELF_CACHED(&_4$$6, "toStringValue", &_zephir_call_cache[5], &optionValue);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&optionValue, &escaper, "attributes", &_zephir_call_cache[6], &_4$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_SELF_CACHED(&_5$$6, "toStringValue", &_zephir_call_cache[7], &optionText);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&optionText, &escaper, "html", &_zephir_call_cache[8], &_5$$6);
			zephir_check_call_status();
			if (Z_TYPE_P(value) == IS_ARRAY) {
				_6$$12 = zephir_fast_in_array(&optionValue, value);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_6$$12) {
					ZVAL_BOOL(&_8$$13, 1);
					ZEPHIR_CALL_SELF_CACHED(&_7$$13, "echoOption", &_zephir_call_cache[9], &optionValue, &_8$$13);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_9$$13);
					ZEPHIR_CONCAT_VVV(&_9$$13, &_7$$13, &optionText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_9$$13);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CALL_SELF_CACHED(&_10$$14, "echoOption", &_zephir_call_cache[10], &optionValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_11$$14);
					ZEPHIR_CONCAT_VVV(&_11$$14, &_10$$14, &optionText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_11$$14);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				ZEPHIR_CPY_WRT(&strOptionValue, &optionValue);
				ZEPHIR_CALL_SELF_CACHED(&strValue, "toStringValue", &_zephir_call_cache[11], value);
				zephir_check_call_status();
				if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
					ZVAL_BOOL(&_13$$16, 1);
					ZEPHIR_CALL_SELF_CACHED(&_12$$16, "echoOption", &_zephir_call_cache[12], &strOptionValue, &_13$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_14$$16);
					ZEPHIR_CONCAT_VVV(&_14$$16, &_12$$16, &optionText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_14$$16);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CALL_SELF_CACHED(&_15$$17, "echoOption", &_zephir_call_cache[13], &strOptionValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_16$$17);
					ZEPHIR_CONCAT_VVV(&_16$$17, &_15$$17, &optionText, &closeOption_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_16$$17);
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
				ZEPHIR_CALL_SELF_CACHED(&_17$$19, "toStringValue", &_zephir_call_cache[14], &executed);
				zephir_check_call_status();
				zephir_concat_self(&code, &_17$$19);
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

