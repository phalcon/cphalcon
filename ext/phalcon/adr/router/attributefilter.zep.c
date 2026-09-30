
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 *
 * Implementation of this file has also been heavily influenced by Autoroute.
 *
 * @link    https://pmjones.io/adr/
 *
 * @link    https://github.com/pmjones/AutoRoute
 * @license https://github.com/pmjones/AutoRoute/blob/2.x/LICENSE.md
 */
/**
 * Reads an Action's optional static `params()` declaration and transforms the
 * router's positional tail segments: regex match (miss => RouteNotFound), cast
 * to a scalar type, then an optional converter closure. Declaration order names
 * the attributes; a declared parameter with no segment is skipped; surplus
 * segments pass through under their positional keys. An Action without
 * `params()` is returned unchanged.
 *
 * @phpstan-import-type adr_filtered_attributes from ADRTypes
 * @phpstan-import-type adr_route_attributes from ADRTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_AttributeFilter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Router, AttributeFilter, phalcon, adr_router_attributefilter, phalcon_adr_router_attributefilter_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(phalcon_adr_router_attributefilter_ce, 1, phalcon_contracts_adr_router_attributefilter_ce);
	return SUCCESS;
}

/**
 * @phpstan-param class-string          $actionClass
 * @phpstan-param adr_route_attributes  $attributes
 *
 * @phpstan-return adr_filtered_attributes
 */
PHP_METHOD(Phalcon_ADR_Router_AttributeFilter, filter)
{
	zend_bool _18;
	zend_ulong _4, _15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_11 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, index;
	zval attributes, result, _0;
	zval actionClass_zv, *attributes_param = NULL, convert, item, key, name, params, pattern, rule, segment, type, value, _1, *_2, *_3, *_14, _17, _6$$7, _7$$7, _8$$7, _9$$8, _12$$9;
	zend_string *actionClass = NULL, *_5, *_16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionClass_zv);
	ZVAL_UNDEF(&convert);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&rule);
	ZVAL_UNDEF(&segment);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(actionClass)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	attributes_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&actionClass_zv);
	ZVAL_STR_COPY(&actionClass_zv, actionClass);
	zephir_get_arrval(&attributes, attributes_param);
	index = 0;
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	if (!((zephir_method_exists_ex(&actionClass_zv, ZEND_STRL("params")) == SUCCESS))) {
		RETURN_CTOR(&attributes);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, &actionClass_zv);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "params");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&params);
	ZEPHIR_CALL_USER_FUNC(&params, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&params) != IS_ARRAY) {
		RETURN_CTOR(&attributes);
	}
	if (Z_TYPE_P(&params) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_1);
		zephir_string_to_char_array(&_1, &params);
		_2 = &_1;
	} else {
		_2 = &params;
	}
	zephir_is_iterable(_2, 0, "phalcon/ADR/Router/AttributeFilter.zep", 86);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_2), _4, _5, _3)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_5 != NULL) { 
			ZVAL_STR_COPY(&name, _5);
		} else {
			ZVAL_LONG(&name, _4);
		}
		ZEPHIR_INIT_NVAR(&rule);
		ZVAL_COPY(&rule, _3);
		if (zephir_array_isset_value_long(&attributes, index)) {
			ZEPHIR_OBS_NVAR(&segment);
			zephir_array_fetch_long(&segment, &attributes, index, PH_NOISY, "phalcon/ADR/Router/AttributeFilter.zep", 62);
			if (zephir_array_isset_value_string(&rule, SL("match"))) {
				ZEPHIR_OBS_NVAR(&pattern);
				zephir_array_fetch_string(&pattern, &rule, SL("match"), PH_NOISY, "phalcon/ADR/Router/AttributeFilter.zep", 65);
				ZEPHIR_INIT_NVAR(&_6$$7);
				ZEPHIR_INIT_NVAR(&_7$$7);
				ZEPHIR_CONCAT_SVS(&_7$$7, "#^(?:", &pattern, ")$#");
				ZEPHIR_INIT_NVAR(&_8$$7);
				zephir_preg_match(&_8$$7, &_7$$7, &segment, &_6$$7, 0, 0 , 0 );
				if (!(zephir_is_true(&_8$$7))) {
					ZEPHIR_INIT_NVAR(&_9$$8);
					object_init_ex(&_9$$8, phalcon_adr_exceptions_routenotfound_ce);
					ZEPHIR_CALL_METHOD(NULL, &_9$$8, "__construct", &_10, 314);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$8, "phalcon/ADR/Router/AttributeFilter.zep", 68);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_array_isset_value_string(&rule, SL("type"))) {
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_string(&type, &rule, SL("type"), PH_NOISY, "phalcon/ADR/Router/AttributeFilter.zep", 72);
			} else {
				ZEPHIR_INIT_NVAR(&type);
				ZVAL_STRING(&type, "string");
			}
			ZEPHIR_CALL_METHOD(&value, this_ptr, "cast", &_11, 340, &segment, &type);
			zephir_check_call_status();
			if (zephir_array_isset_value_string(&rule, SL("convert"))) {
				ZEPHIR_OBS_NVAR(&convert);
				zephir_array_fetch_string(&convert, &rule, SL("convert"), PH_NOISY, "phalcon/ADR/Router/AttributeFilter.zep", 76);
				ZEPHIR_CALL_FUNCTION(&_12$$9, "call_user_func", &_13, 82, &convert, &value);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_12$$9);
			}
			zephir_array_update_zval(&result, &name, &value, PH_COPY | PH_SEPARATE);
		}
		index++;
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&rule);
	ZEPHIR_INIT_NVAR(&name);
	zephir_is_iterable(&attributes, 0, "phalcon/ADR/Router/AttributeFilter.zep", 92);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _15, _16, _14)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_16 != NULL) { 
				ZVAL_STR_COPY(&key, _16);
			} else {
				ZVAL_LONG(&key, _15);
			}
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _14);
			if (ZEPHIR_GE_LONG(&key, index)) {
				zephir_array_update_zval(&result, &key, &item, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_17, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&item, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_GE_LONG(&key, index)) {
					zephir_array_update_zval(&result, &key, &item, PH_COPY | PH_SEPARATE);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&result);
}

PHP_METHOD(Phalcon_ADR_Router_AttributeFilter, cast)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value_zv, type_zv;
	zend_string *value = NULL, *type = NULL;

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&type_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(value)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	if (ZEPHIR_IS_STRING(&type_zv, "int")) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_STRING(&type_zv, "float")) { goto zephir_switch_0_clause_1; }
	goto zephir_switch_0_clause_2;
	zephir_switch_0_clause_0: ;
		RETURN_MM_LONG(zephir_get_intval(&value_zv));
	zephir_switch_0_clause_1: ;
		ZEPHIR_RETURN_CALL_FUNCTION("floatval", NULL, 33, &value_zv);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_2: ;
		ZEPHIR_RETURN_CALL_FUNCTION("strval", NULL, 341, &value_zv);
		zephir_check_call_status();
		RETURN_MM();

}

