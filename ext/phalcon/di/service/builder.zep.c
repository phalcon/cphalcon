
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Di\Service\Builder
 *
 * This class builds instances based on complex definitions
 *
 * @phpstan-import-type di_parameters from DiTypes
 * @phpstan-import-type di_service_argument from DiTypes
 * @phpstan-import-type di_service_definition from DiTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_Service_Builder)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Di\\Service, Builder, phalcon, di_service_builder, phalcon_di_service_builder_method_entry, 0);

	return SUCCESS;
}

/**
 * Builds a service using a complex service definition
 *
 * @phpstan-param di_service_definition $definition
 * @phpstan-param di_parameters|null    $parameters
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Di_Service_Builder, build)
{
	zend_string *_11$$10, *_40$$25;
	zend_ulong _10$$10, _39$$25;
	zend_bool _0, _4, _33, _2$$7, _22$$10, _13$$13, _15$$13, _24$$19, _27$$19, _48$$25, _42$$28, _44$$28, _50$$32, _52$$32;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *container, container_sub, *definition_param = NULL, *parameters = NULL, parameters_sub, __$null, className, arguments, paramCalls, methodPosition, method, methodName, methodCall, instance, propertyPosition, property, propertyName, propertyValue, _1$$3, _3$$8, _5$$11, _6$$12, *_7$$10, _8$$10, *_9$$10, _21$$10, _12$$14, _20$$13, _14$$15, _16$$17, _17$$17, _18$$18, _19$$18, _23$$20, _26$$19, _32$$19, _25$$21, _28$$23, _29$$23, _30$$24, _31$$24, _34$$26, _35$$27, *_36$$25, _37$$25, *_38$$25, _47$$25, _41$$29, _46$$28, _43$$30, _45$$31, _49$$33, _54$$32, _51$$34, _53$$35;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&paramCalls);
	ZVAL_UNDEF(&methodPosition);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&methodCall);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&propertyPosition);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&propertyName);
	ZVAL_UNDEF(&propertyValue);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_23$$20);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_32$$19);
	ZVAL_UNDEF(&_25$$21);
	ZVAL_UNDEF(&_28$$23);
	ZVAL_UNDEF(&_29$$23);
	ZVAL_UNDEF(&_30$$24);
	ZVAL_UNDEF(&_31$$24);
	ZVAL_UNDEF(&_34$$26);
	ZVAL_UNDEF(&_35$$27);
	ZVAL_UNDEF(&_37$$25);
	ZVAL_UNDEF(&_47$$25);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_46$$28);
	ZVAL_UNDEF(&_43$$30);
	ZVAL_UNDEF(&_45$$31);
	ZVAL_UNDEF(&_49$$33);
	ZVAL_UNDEF(&_54$$32);
	ZVAL_UNDEF(&_51$$34);
	ZVAL_UNDEF(&_53$$35);
	ZVAL_UNDEF(&definition);
	ZEND_TLS zephir_method_cache _zephir_call_cache[32];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
		ZEPHIR_Z_PARAM_ARRAY(definition, definition_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &container, &definition_param, &parameters);
	zephir_get_arrval(&definition, definition_param);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	zephir_memory_observe(&className);
	_0 = zephir_array_isset_string_fetch(&className, &definition, SL("className"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_di_exceptions_missingclassnameparameter_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Di/Service/Builder.zep", 59);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(parameters) == IS_ARRAY) {
		if (!(ZEPHIR_IS_EMPTY(parameters))) {
			ZEPHIR_INIT_VAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&instance, &className, parameters);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&instance, &className);
			zephir_check_call_status();
		}
	} else {
		zephir_memory_observe(&arguments);
		_2$$7 = zephir_array_isset_string_fetch(&arguments, &definition, SL("arguments"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_2$$7) {
			ZEPHIR_CALL_METHOD_CACHED(&_3$$8, this_ptr, "buildParameters", &_zephir_call_cache[1], container, &arguments);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&instance, &className, &_3$$8);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&instance, &className);
			zephir_check_call_status();
		}
	}
	zephir_memory_observe(&paramCalls);
	_4 = zephir_array_isset_string_fetch(&paramCalls, &definition, SL("calls"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_4) {
		if (UNEXPECTED(Z_TYPE_P(&instance) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_5$$11);
			object_init_ex(&_5$$11, phalcon_di_exceptions_setterinjectionrequiresinstance_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$11, "__construct", &_zephir_call_cache[2]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$11, "phalcon/Di/Service/Builder.zep", 94);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&paramCalls) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_6$$12);
			object_init_ex(&_6$$12, phalcon_di_exceptions_setterparametersmustbearray_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$12, "__construct", &_zephir_call_cache[3]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$12, "phalcon/Di/Service/Builder.zep", 98);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&paramCalls) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_8$$10);
			zephir_string_to_char_array(&_8$$10, &paramCalls);
			_7$$10 = &_8$$10;
		} else {
			_7$$10 = &paramCalls;
		}
		zephir_is_iterable(_7$$10, 0, "phalcon/Di/Service/Builder.zep", 150);
		if (Z_TYPE_P(_7$$10) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_7$$10), _10$$10, _11$$10, _9$$10)
			{
				ZEPHIR_INIT_NVAR(&methodPosition);
				if (_11$$10 != NULL) { 
					ZVAL_STR_COPY(&methodPosition, _11$$10);
				} else {
					ZVAL_LONG(&methodPosition, _10$$10);
				}
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _9$$10);
				if (UNEXPECTED(Z_TYPE_P(&method) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_12$$14);
					object_init_ex(&_12$$14, phalcon_di_exceptions_methodcallmustbearray_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_12$$14, "__construct", &_zephir_call_cache[4], &methodPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_12$$14, "phalcon/Di/Service/Builder.zep", 109);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&methodName);
				_13$$13 = zephir_array_isset_string_fetch(&methodName, &method, SL("method"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_13$$13))) {
					ZEPHIR_INIT_NVAR(&_14$$15);
					object_init_ex(&_14$$15, phalcon_di_exceptions_methodnamerequired_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_14$$15, "__construct", &_zephir_call_cache[5], &methodPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_14$$15, "phalcon/Di/Service/Builder.zep", 116);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&methodCall);
				zephir_create_array(&methodCall, 2, 0);
				zephir_array_fast_append(&methodCall, &instance);
				zephir_array_fast_append(&methodCall, &methodName);
				ZEPHIR_OBS_NVAR(&arguments);
				_15$$13 = zephir_array_isset_string_fetch(&arguments, &method, SL("arguments"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_15$$13) {
					if (UNEXPECTED(Z_TYPE_P(&arguments) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_16$$17);
						object_init_ex(&_16$$17, phalcon_di_exceptions_callargumentsmustbearray_ce);
						ZVAL_LONG(&_17$$17, zephir_get_intval(&methodPosition));
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_16$$17, "__construct", &_zephir_call_cache[6], &_17$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_16$$17, "phalcon/Di/Service/Builder.zep", 126);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(ZEPHIR_IS_EMPTY(&arguments))) {
						ZEPHIR_INIT_NVAR(&_18$$18);
						ZEPHIR_CALL_METHOD_CACHED(&_19$$18, this_ptr, "buildParameters", &_zephir_call_cache[7], container, &arguments);
						zephir_check_call_status();
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_18$$18, &methodCall, &_19$$18);
						zephir_check_call_status();
						continue;
					}
				}
				ZEPHIR_INIT_NVAR(&_20$$13);
				ZEPHIR_CALL_USER_FUNC(&_20$$13, &methodCall);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _7$$10, "rewind", &_zephir_call_cache[8]);
			zephir_check_call_status();
			_22$$10 = 1;
			while (1) {
				if (_22$$10) {
					_22$$10 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _7$$10, "next", &_zephir_call_cache[9]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_21$$10, _7$$10, "valid", &_zephir_call_cache[10]);
				zephir_check_call_status();
				if (!zend_is_true(&_21$$10)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&methodPosition, _7$$10, "key", &_zephir_call_cache[11]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&method, _7$$10, "current", &_zephir_call_cache[12]);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&method) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_23$$20);
						object_init_ex(&_23$$20, phalcon_di_exceptions_methodcallmustbearray_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_23$$20, "__construct", &_zephir_call_cache[13], &methodPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_23$$20, "phalcon/Di/Service/Builder.zep", 109);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&methodName);
					_24$$19 = zephir_array_isset_string_fetch(&methodName, &method, SL("method"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_24$$19))) {
						ZEPHIR_INIT_NVAR(&_25$$21);
						object_init_ex(&_25$$21, phalcon_di_exceptions_methodnamerequired_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_25$$21, "__construct", &_zephir_call_cache[14], &methodPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_25$$21, "phalcon/Di/Service/Builder.zep", 116);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_26$$19);
					zephir_create_array(&_26$$19, 2, 0);
					zephir_array_fast_append(&_26$$19, &instance);
					zephir_array_fast_append(&_26$$19, &methodName);
					ZEPHIR_CPY_WRT(&methodCall, &_26$$19);
					ZEPHIR_OBS_NVAR(&arguments);
					_27$$19 = zephir_array_isset_string_fetch(&arguments, &method, SL("arguments"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_27$$19) {
						if (UNEXPECTED(Z_TYPE_P(&arguments) != IS_ARRAY)) {
							ZEPHIR_INIT_NVAR(&_28$$23);
							object_init_ex(&_28$$23, phalcon_di_exceptions_callargumentsmustbearray_ce);
							ZVAL_LONG(&_29$$23, zephir_get_intval(&methodPosition));
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_28$$23, "__construct", &_zephir_call_cache[15], &_29$$23);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_28$$23, "phalcon/Di/Service/Builder.zep", 126);
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (!(ZEPHIR_IS_EMPTY(&arguments))) {
							ZEPHIR_INIT_NVAR(&_30$$24);
							ZEPHIR_CALL_METHOD_CACHED(&_31$$24, this_ptr, "buildParameters", &_zephir_call_cache[16], container, &arguments);
							zephir_check_call_status();
							ZEPHIR_CALL_USER_FUNC_ARRAY(&_30$$24, &methodCall, &_31$$24);
							zephir_check_call_status();
							continue;
						}
					}
					ZEPHIR_INIT_NVAR(&_32$$19);
					ZEPHIR_CALL_USER_FUNC(&_32$$19, &methodCall);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&method);
		ZEPHIR_INIT_NVAR(&methodPosition);
	}
	ZEPHIR_OBS_NVAR(&paramCalls);
	_33 = zephir_array_isset_string_fetch(&paramCalls, &definition, SL("properties"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_33) {
		if (UNEXPECTED(Z_TYPE_P(&instance) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_34$$26);
			object_init_ex(&_34$$26, phalcon_di_exceptions_propertyinjectionrequiresinstance_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_34$$26, "__construct", &_zephir_call_cache[17]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_34$$26, "phalcon/Di/Service/Builder.zep", 157);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&paramCalls) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_35$$27);
			object_init_ex(&_35$$27, phalcon_di_exceptions_setterparametersmustbearray_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_35$$27, "__construct", &_zephir_call_cache[18]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_35$$27, "phalcon/Di/Service/Builder.zep", 161);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&paramCalls) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_37$$25);
			zephir_string_to_char_array(&_37$$25, &paramCalls);
			_36$$25 = &_37$$25;
		} else {
			_36$$25 = &paramCalls;
		}
		zephir_is_iterable(_36$$25, 0, "phalcon/Di/Service/Builder.zep", 198);
		if (Z_TYPE_P(_36$$25) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_36$$25), _39$$25, _40$$25, _38$$25)
			{
				ZEPHIR_INIT_NVAR(&propertyPosition);
				if (_40$$25 != NULL) { 
					ZVAL_STR_COPY(&propertyPosition, _40$$25);
				} else {
					ZVAL_LONG(&propertyPosition, _39$$25);
				}
				ZEPHIR_INIT_NVAR(&property);
				ZVAL_COPY(&property, _38$$25);
				if (UNEXPECTED(Z_TYPE_P(&property) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_41$$29);
					object_init_ex(&_41$$29, phalcon_di_exceptions_propertymustbearray_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_41$$29, "__construct", &_zephir_call_cache[19], &propertyPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_41$$29, "phalcon/Di/Service/Builder.zep", 172);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&propertyName);
				_42$$28 = zephir_array_isset_string_fetch(&propertyName, &property, SL("name"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_42$$28))) {
					ZEPHIR_INIT_NVAR(&_43$$30);
					object_init_ex(&_43$$30, phalcon_di_exceptions_propertynamerequired_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_43$$30, "__construct", &_zephir_call_cache[20], &propertyPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_43$$30, "phalcon/Di/Service/Builder.zep", 179);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&propertyValue);
				_44$$28 = zephir_array_isset_string_fetch(&propertyValue, &property, SL("value"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_44$$28))) {
					ZEPHIR_INIT_NVAR(&_45$$31);
					object_init_ex(&_45$$31, phalcon_di_exceptions_propertyvaluerequired_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_45$$31, "__construct", &_zephir_call_cache[21], &propertyPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_45$$31, "phalcon/Di/Service/Builder.zep", 186);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_46$$28, this_ptr, "buildParameter", &_zephir_call_cache[22], container, &propertyPosition, &propertyValue);
				zephir_check_call_status();
				zephir_update_property_zval_zval(&instance, &propertyName, &_46$$28);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _36$$25, "rewind", &_zephir_call_cache[23]);
			zephir_check_call_status();
			_48$$25 = 1;
			while (1) {
				if (_48$$25) {
					_48$$25 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _36$$25, "next", &_zephir_call_cache[24]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_47$$25, _36$$25, "valid", &_zephir_call_cache[25]);
				zephir_check_call_status();
				if (!zend_is_true(&_47$$25)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&propertyPosition, _36$$25, "key", &_zephir_call_cache[26]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&property, _36$$25, "current", &_zephir_call_cache[27]);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&property) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_49$$33);
						object_init_ex(&_49$$33, phalcon_di_exceptions_propertymustbearray_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_49$$33, "__construct", &_zephir_call_cache[28], &propertyPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_49$$33, "phalcon/Di/Service/Builder.zep", 172);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&propertyName);
					_50$$32 = zephir_array_isset_string_fetch(&propertyName, &property, SL("name"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_50$$32))) {
						ZEPHIR_INIT_NVAR(&_51$$34);
						object_init_ex(&_51$$34, phalcon_di_exceptions_propertynamerequired_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_51$$34, "__construct", &_zephir_call_cache[29], &propertyPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_51$$34, "phalcon/Di/Service/Builder.zep", 179);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&propertyValue);
					_52$$32 = zephir_array_isset_string_fetch(&propertyValue, &property, SL("value"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_52$$32))) {
						ZEPHIR_INIT_NVAR(&_53$$35);
						object_init_ex(&_53$$35, phalcon_di_exceptions_propertyvaluerequired_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_53$$35, "__construct", &_zephir_call_cache[30], &propertyPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_53$$35, "phalcon/Di/Service/Builder.zep", 186);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&_54$$32, this_ptr, "buildParameter", &_zephir_call_cache[31], container, &propertyPosition, &propertyValue);
					zephir_check_call_status();
					zephir_update_property_zval_zval(&instance, &propertyName, &_54$$32);
			}
		}
		ZEPHIR_INIT_NVAR(&property);
		ZEPHIR_INIT_NVAR(&propertyPosition);
	}
	RETURN_CCTOR(&instance);
}

/**
 * Resolves a constructor/call parameter
 *
 * @phpstan-param di_service_argument $argument
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Di_Service_Builder, buildParameter)
{
	zend_bool _0, _3$$4, _7$$6, _11$$8, _15$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval argument;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, *position_param = NULL, *argument_param = NULL, type, name, value, instanceArguments, _1$$3, _2$$3, _4$$5, _5$$5, _6$$5, _8$$7, _9$$7, _10$$7, _12$$9, _13$$9, _14$$9, _16$$11, _17$$11;

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&instanceArguments);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&argument);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
		Z_PARAM_LONG(position)
		ZEPHIR_Z_PARAM_ARRAY(argument, argument_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &container, &position_param, &argument_param);
	zephir_get_arrval(&argument, argument_param);
	zephir_memory_observe(&type);
	_0 = zephir_array_isset_string_fetch(&type, &argument, SL("type"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_di_exceptions_argumenttyperequired_ce);
		ZVAL_LONG(&_2$$3, position);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0], &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Di/Service/Builder.zep", 218);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_STRING(&type, "service")) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_STRING(&type, "parameter")) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_STRING(&type, "instance")) { goto zephir_switch_0_clause_2; }
	goto zephir_switch_0_clause_3;
	zephir_switch_0_clause_0: ;
		zephir_memory_observe(&name);
		_3$$4 = zephir_array_isset_string_fetch(&name, &argument, SL("name"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(!(_3$$4))) {
			ZEPHIR_INIT_VAR(&_4$$5);
			object_init_ex(&_4$$5, phalcon_di_exceptions_missingparameterkey_ce);
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "name");
			ZVAL_LONG(&_6$$5, position);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$5, "__construct", &_zephir_call_cache[1], &_5$$5, &_6$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$5, "phalcon/Di/Service/Builder.zep", 228);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_RETURN_CALL_METHOD_CACHED(container, "get", &_zephir_call_cache[2], &name);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_1: ;
		zephir_memory_observe(&value);
		_7$$6 = zephir_array_isset_string_fetch(&value, &argument, SL("value"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(!(_7$$6))) {
			ZEPHIR_INIT_VAR(&_8$$7);
			object_init_ex(&_8$$7, phalcon_di_exceptions_missingparameterkey_ce);
			ZEPHIR_INIT_VAR(&_9$$7);
			ZVAL_STRING(&_9$$7, "value");
			ZVAL_LONG(&_10$$7, position);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_8$$7, "__construct", &_zephir_call_cache[3], &_9$$7, &_10$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_8$$7, "phalcon/Di/Service/Builder.zep", 238);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&value);
	zephir_switch_0_clause_2: ;
		ZEPHIR_OBS_NVAR(&name);
		_11$$8 = zephir_array_isset_string_fetch(&name, &argument, SL("className"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(!(_11$$8))) {
			ZEPHIR_INIT_VAR(&_12$$9);
			object_init_ex(&_12$$9, phalcon_di_exceptions_missingparameterkey_ce);
			ZEPHIR_INIT_VAR(&_13$$9);
			ZVAL_STRING(&_13$$9, "className");
			ZVAL_LONG(&_14$$9, position);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_12$$9, "__construct", &_zephir_call_cache[4], &_13$$9, &_14$$9);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_12$$9, "phalcon/Di/Service/Builder.zep", 248);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&instanceArguments);
		_15$$8 = zephir_array_isset_string_fetch(&instanceArguments, &argument, SL("arguments"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_15$$8) {
			ZEPHIR_RETURN_CALL_METHOD_CACHED(container, "get", &_zephir_call_cache[5], &name, &instanceArguments);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_METHOD_CACHED(container, "get", &_zephir_call_cache[6], &name);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_3: ;
		ZEPHIR_INIT_VAR(&_16$$11);
		object_init_ex(&_16$$11, phalcon_di_exceptions_unknownservicetype_ce);
		ZVAL_LONG(&_17$$11, position);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_16$$11, "__construct", &_zephir_call_cache[7], &_17$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_16$$11, "phalcon/Di/Service/Builder.zep", 268);
		ZEPHIR_MM_RESTORE();
		return;

}

/**
 * Resolves an array of parameters
 *
 * @phpstan-param array<int, di_service_argument> $arguments
 *
 * @phpstan-return list<mixed>
 */
PHP_METHOD(Phalcon_Di_Service_Builder, buildParameters)
{
	zend_bool _5;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, buildArguments;
	zval *container, container_sub, *arguments_param = NULL, position, argument, *_0, _4, _3$$3, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&buildArguments);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &container, &arguments_param);
	zephir_get_arrval(&arguments, arguments_param);
	ZEPHIR_INIT_VAR(&buildArguments);
	array_init(&buildArguments);
	zephir_is_iterable(&arguments, 0, "phalcon/Di/Service/Builder.zep", 294);
	if (Z_TYPE_P(&arguments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&arguments), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&position);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&position, _2);
			} else {
				ZVAL_LONG(&position, _1);
			}
			ZEPHIR_INIT_NVAR(&argument);
			ZVAL_COPY(&argument, _0);
			ZEPHIR_CALL_METHOD_CACHED(&_3$$3, this_ptr, "buildParameter", &_zephir_call_cache[0], container, &position, &argument);
			zephir_check_call_status();
			zephir_array_append(&buildArguments, &_3$$3, PH_SEPARATE, "phalcon/Di/Service/Builder.zep", 291);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &arguments, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &arguments, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_4, &arguments, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&position, &arguments, "key", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&argument, &arguments, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_6$$4, this_ptr, "buildParameter", &_zephir_call_cache[6], container, &position, &argument);
				zephir_check_call_status();
				zephir_array_append(&buildArguments, &_6$$4, PH_SEPARATE, "phalcon/Di/Service/Builder.zep", 291);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&argument);
	ZEPHIR_INIT_NVAR(&position);
	RETURN_CTOR(&buildArguments);
}

