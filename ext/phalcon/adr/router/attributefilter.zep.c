
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
#include "kernel/concat.h"
#include "kernel/string.h"
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
 * @link    https://pmjones.io/adr/
 */
/**
 * Reads an Action's optional static `params()` declaration and transforms the
 * router's positional tail segments: regex match (miss => RouteNotFound), cast
 * to a scalar type, then an optional converter closure. Declaration order names
 * the attributes; a declared parameter with no segment is skipped; surplus
 * segments pass through under their positional keys. An Action without
 * `params()` is returned unchanged.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_AttributeFilter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Router, AttributeFilter, phalcon, adr_router_attributefilter, phalcon_adr_router_attributefilter_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(phalcon_adr_router_attributefilter_ce, 1, phalcon_contracts_adr_router_attributefilter_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Router_AttributeFilter, filter)
{
	zend_bool _14, _24;
	zend_ulong _3, _21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_10 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, index;
	zval attributes, result, _0;
	zval actionClass_zv, *attributes_param = NULL, convert, item, key, name, params, pattern, rule, segment, type, value, _1, *_2, _13, *_20, _23, _5$$7, _6$$7, _7$$7, _8$$8, _11$$9, _15$$12, _16$$12, _17$$12, _18$$13, _19$$14;
	zend_string *actionClass = NULL, *_4, *_22;
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
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$14);
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
	zephir_is_iterable(&params, 0, "phalcon/ADR/Router/AttributeFilter.zep", 70);
	if (Z_TYPE_P(&params) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&params), _3, _4, _2)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&rule);
			ZVAL_COPY(&rule, _2);
			if (zephir_array_isset_value_long(&attributes, index)) {
				ZEPHIR_OBS_NVAR(&segment);
				zephir_array_fetch_long(&segment, &attributes, index, PH_NOISY, "phalcon/ADR/Router/AttributeFilter.zep", 46);
				if (zephir_array_isset_value_string(&rule, SL("match"))) {
					ZEPHIR_OBS_NVAR(&pattern);
					zephir_array_fetch_string(&pattern, &rule, SL("match"), PH_NOISY, "phalcon/ADR/Router/AttributeFilter.zep", 49);
					ZEPHIR_INIT_NVAR(&_5$$7);
					ZEPHIR_INIT_NVAR(&_6$$7);
					ZEPHIR_CONCAT_SVS(&_6$$7, "#^(?:", &pattern, ")$#");
					ZEPHIR_INIT_NVAR(&_7$$7);
					zephir_preg_match(&_7$$7, &_6$$7, &segment, &_5$$7, 0, 0 , 0 );
					if (!(zephir_is_true(&_7$$7))) {
						ZEPHIR_INIT_NVAR(&_8$$8);
						object_init_ex(&_8$$8, phalcon_adr_exceptions_routenotfound_ce);
						ZEPHIR_CALL_METHOD(NULL, &_8$$8, "__construct", &_9, 302);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_8$$8, "phalcon/ADR/Router/AttributeFilter.zep", 52);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (zephir_array_isset_value_string(&rule, SL("type"))) {
					ZEPHIR_OBS_NVAR(&type);
					zephir_array_fetch_string(&type, &rule, SL("type"), PH_NOISY, "phalcon/ADR/Router/AttributeFilter.zep", 56);
				} else {
					ZEPHIR_INIT_NVAR(&type);
					ZVAL_STRING(&type, "string");
				}
				ZEPHIR_CALL_METHOD(&value, this_ptr, "cast", &_10, 328, &segment, &type);
				zephir_check_call_status();
				if (zephir_array_isset_value_string(&rule, SL("convert"))) {
					ZEPHIR_OBS_NVAR(&convert);
					zephir_array_fetch_string(&convert, &rule, SL("convert"), PH_NOISY, "phalcon/ADR/Router/AttributeFilter.zep", 60);
					ZEPHIR_CALL_FUNCTION(&_11$$9, "call_user_func", &_12, 80, &convert, &value);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&value, &_11$$9);
				}
				zephir_array_update_zval(&result, &name, &value, PH_COPY | PH_SEPARATE);
			}
			index++;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &params, "rewind", NULL, 0);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &params, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_13, &params, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &params, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&rule, &params, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_array_isset_value_long(&attributes, index)) {
					ZEPHIR_OBS_NVAR(&segment);
					zephir_array_fetch_long(&segment, &attributes, index, PH_NOISY, "phalcon/ADR/Router/AttributeFilter.zep", 46);
					if (zephir_array_isset_value_string(&rule, SL("match"))) {
						ZEPHIR_OBS_NVAR(&pattern);
						zephir_array_fetch_string(&pattern, &rule, SL("match"), PH_NOISY, "phalcon/ADR/Router/AttributeFilter.zep", 49);
						ZEPHIR_INIT_NVAR(&_15$$12);
						ZEPHIR_INIT_NVAR(&_16$$12);
						ZEPHIR_CONCAT_SVS(&_16$$12, "#^(?:", &pattern, ")$#");
						ZEPHIR_INIT_NVAR(&_17$$12);
						zephir_preg_match(&_17$$12, &_16$$12, &segment, &_15$$12, 0, 0 , 0 );
						if (!(zephir_is_true(&_17$$12))) {
							ZEPHIR_INIT_NVAR(&_18$$13);
							object_init_ex(&_18$$13, phalcon_adr_exceptions_routenotfound_ce);
							ZEPHIR_CALL_METHOD(NULL, &_18$$13, "__construct", &_9, 302);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_18$$13, "phalcon/ADR/Router/AttributeFilter.zep", 52);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					if (zephir_array_isset_value_string(&rule, SL("type"))) {
						ZEPHIR_OBS_NVAR(&type);
						zephir_array_fetch_string(&type, &rule, SL("type"), PH_NOISY, "phalcon/ADR/Router/AttributeFilter.zep", 56);
					} else {
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_STRING(&type, "string");
					}
					ZEPHIR_CALL_METHOD(&value, this_ptr, "cast", &_10, 328, &segment, &type);
					zephir_check_call_status();
					if (zephir_array_isset_value_string(&rule, SL("convert"))) {
						ZEPHIR_OBS_NVAR(&convert);
						zephir_array_fetch_string(&convert, &rule, SL("convert"), PH_NOISY, "phalcon/ADR/Router/AttributeFilter.zep", 60);
						ZEPHIR_CALL_FUNCTION(&_19$$14, "call_user_func", &_12, 80, &convert, &value);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&value, &_19$$14);
					}
					zephir_array_update_zval(&result, &name, &value, PH_COPY | PH_SEPARATE);
				}
				index++;
		}
	}
	ZEPHIR_INIT_NVAR(&rule);
	ZEPHIR_INIT_NVAR(&name);
	zephir_is_iterable(&attributes, 0, "phalcon/ADR/Router/AttributeFilter.zep", 76);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _21, _22, _20)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_22 != NULL) { 
				ZVAL_STR_COPY(&key, _22);
			} else {
				ZVAL_LONG(&key, _21);
			}
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _20);
			if (ZEPHIR_GE_LONG(&key, index)) {
				zephir_array_update_zval(&result, &key, &item, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		_24 = 1;
		while (1) {
			if (_24) {
				_24 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_23, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
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
	do {
		if (ZEPHIR_IS_STRING(&type_zv, "int")) {
			RETURN_MM_LONG(zephir_get_intval(&value_zv));
		}
		if (ZEPHIR_IS_STRING(&type_zv, "float")) {
			ZEPHIR_RETURN_CALL_FUNCTION("floatval", NULL, 32, &value_zv);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_FUNCTION("strval", NULL, 329, &value_zv);
		zephir_check_call_status();
		RETURN_MM();
	} while(0);

}

