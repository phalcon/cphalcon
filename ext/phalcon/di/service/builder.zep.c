
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
	zend_string *_13$$10, *_49$$25;
	zend_ulong _12$$10, _48$$25;
	zend_bool _0, _5, _41, _2$$7, _27$$10, _16$$13, _19$$13, _30$$19, _34$$19, _61$$25, _52$$28, _55$$28, _64$$32, _67$$32;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL, *_15 = NULL, *_18 = NULL, *_22 = NULL, *_29 = NULL, *_32 = NULL, *_37 = NULL, *_44 = NULL, *_51 = NULL, *_54 = NULL, *_57 = NULL, *_59 = NULL, *_63 = NULL, *_66 = NULL, *_69 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *container, container_sub, *definition_param = NULL, *parameters = NULL, parameters_sub, __$null, className, arguments, paramCalls, methodPosition, method, methodName, methodCall, instance, propertyPosition, property, propertyName, propertyValue, _1$$3, _3$$8, _6$$11, _7$$12, *_9$$10, _10$$10, *_11$$10, _26$$10, _14$$14, _25$$13, _17$$15, _20$$17, _21$$17, _23$$18, _24$$18, _28$$20, _33$$19, _40$$19, _31$$21, _35$$23, _36$$23, _38$$24, _39$$24, _42$$26, _43$$27, *_45$$25, _46$$25, *_47$$25, _60$$25, _50$$29, _58$$28, _53$$30, _56$$31, _62$$33, _70$$32, _65$$34, _68$$35;
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
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_23$$18);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_33$$19);
	ZVAL_UNDEF(&_40$$19);
	ZVAL_UNDEF(&_31$$21);
	ZVAL_UNDEF(&_35$$23);
	ZVAL_UNDEF(&_36$$23);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_39$$24);
	ZVAL_UNDEF(&_42$$26);
	ZVAL_UNDEF(&_43$$27);
	ZVAL_UNDEF(&_46$$25);
	ZVAL_UNDEF(&_60$$25);
	ZVAL_UNDEF(&_50$$29);
	ZVAL_UNDEF(&_58$$28);
	ZVAL_UNDEF(&_53$$30);
	ZVAL_UNDEF(&_56$$31);
	ZVAL_UNDEF(&_62$$33);
	ZVAL_UNDEF(&_70$$32);
	ZVAL_UNDEF(&_65$$34);
	ZVAL_UNDEF(&_68$$35);
	ZVAL_UNDEF(&definition);
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
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
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
			ZEPHIR_CALL_METHOD(&_3$$8, this_ptr, "buildParameters", &_4, 0, container, &arguments);
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
	_5 = zephir_array_isset_string_fetch(&paramCalls, &definition, SL("calls"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		if (UNEXPECTED(Z_TYPE_P(&instance) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_6$$11);
			object_init_ex(&_6$$11, phalcon_di_exceptions_setterinjectionrequiresinstance_ce);
			ZEPHIR_CALL_METHOD(NULL, &_6$$11, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$11, "phalcon/Di/Service/Builder.zep", 94);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&paramCalls) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_7$$12);
			object_init_ex(&_7$$12, phalcon_di_exceptions_setterparametersmustbearray_ce);
			ZEPHIR_CALL_METHOD(NULL, &_7$$12, "__construct", &_8, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$12, "phalcon/Di/Service/Builder.zep", 98);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&paramCalls) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_10$$10);
			zephir_string_to_char_array(&_10$$10, &paramCalls);
			_9$$10 = &_10$$10;
		} else {
			_9$$10 = &paramCalls;
		}
		zephir_is_iterable(_9$$10, 0, "phalcon/Di/Service/Builder.zep", 150);
		if (Z_TYPE_P(_9$$10) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_9$$10), _12$$10, _13$$10, _11$$10)
			{
				ZEPHIR_INIT_NVAR(&methodPosition);
				if (_13$$10 != NULL) { 
					ZVAL_STR_COPY(&methodPosition, _13$$10);
				} else {
					ZVAL_LONG(&methodPosition, _12$$10);
				}
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _11$$10);
				if (UNEXPECTED(Z_TYPE_P(&method) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_14$$14);
					object_init_ex(&_14$$14, phalcon_di_exceptions_methodcallmustbearray_ce);
					ZEPHIR_CALL_METHOD(NULL, &_14$$14, "__construct", &_15, 0, &methodPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_14$$14, "phalcon/Di/Service/Builder.zep", 109);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&methodName);
				_16$$13 = zephir_array_isset_string_fetch(&methodName, &method, SL("method"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_16$$13))) {
					ZEPHIR_INIT_NVAR(&_17$$15);
					object_init_ex(&_17$$15, phalcon_di_exceptions_methodnamerequired_ce);
					ZEPHIR_CALL_METHOD(NULL, &_17$$15, "__construct", &_18, 0, &methodPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_17$$15, "phalcon/Di/Service/Builder.zep", 116);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&methodCall);
				zephir_create_array(&methodCall, 2, 0);
				zephir_array_fast_append(&methodCall, &instance);
				zephir_array_fast_append(&methodCall, &methodName);
				ZEPHIR_OBS_NVAR(&arguments);
				_19$$13 = zephir_array_isset_string_fetch(&arguments, &method, SL("arguments"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_19$$13) {
					if (UNEXPECTED(Z_TYPE_P(&arguments) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_20$$17);
						object_init_ex(&_20$$17, phalcon_di_exceptions_callargumentsmustbearray_ce);
						ZVAL_LONG(&_21$$17, zephir_get_intval(&methodPosition));
						ZEPHIR_CALL_METHOD(NULL, &_20$$17, "__construct", &_22, 0, &_21$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_20$$17, "phalcon/Di/Service/Builder.zep", 126);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(ZEPHIR_IS_EMPTY(&arguments))) {
						ZEPHIR_INIT_NVAR(&_23$$18);
						ZEPHIR_CALL_METHOD(&_24$$18, this_ptr, "buildParameters", &_4, 0, container, &arguments);
						zephir_check_call_status();
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_23$$18, &methodCall, &_24$$18);
						zephir_check_call_status();
						continue;
					}
				}
				ZEPHIR_INIT_NVAR(&_25$$13);
				ZEPHIR_CALL_USER_FUNC(&_25$$13, &methodCall);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _9$$10, "rewind", NULL, 0);
			zephir_check_call_status();
			_27$$10 = 1;
			while (1) {
				if (_27$$10) {
					_27$$10 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _9$$10, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_26$$10, _9$$10, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_26$$10)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&methodPosition, _9$$10, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&method, _9$$10, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&method) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_28$$20);
						object_init_ex(&_28$$20, phalcon_di_exceptions_methodcallmustbearray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_28$$20, "__construct", &_29, 0, &methodPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_28$$20, "phalcon/Di/Service/Builder.zep", 109);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&methodName);
					_30$$19 = zephir_array_isset_string_fetch(&methodName, &method, SL("method"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_30$$19))) {
						ZEPHIR_INIT_NVAR(&_31$$21);
						object_init_ex(&_31$$21, phalcon_di_exceptions_methodnamerequired_ce);
						ZEPHIR_CALL_METHOD(NULL, &_31$$21, "__construct", &_32, 0, &methodPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_31$$21, "phalcon/Di/Service/Builder.zep", 116);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_33$$19);
					zephir_create_array(&_33$$19, 2, 0);
					zephir_array_fast_append(&_33$$19, &instance);
					zephir_array_fast_append(&_33$$19, &methodName);
					ZEPHIR_CPY_WRT(&methodCall, &_33$$19);
					ZEPHIR_OBS_NVAR(&arguments);
					_34$$19 = zephir_array_isset_string_fetch(&arguments, &method, SL("arguments"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_34$$19) {
						if (UNEXPECTED(Z_TYPE_P(&arguments) != IS_ARRAY)) {
							ZEPHIR_INIT_NVAR(&_35$$23);
							object_init_ex(&_35$$23, phalcon_di_exceptions_callargumentsmustbearray_ce);
							ZVAL_LONG(&_36$$23, zephir_get_intval(&methodPosition));
							ZEPHIR_CALL_METHOD(NULL, &_35$$23, "__construct", &_37, 0, &_36$$23);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_35$$23, "phalcon/Di/Service/Builder.zep", 126);
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (!(ZEPHIR_IS_EMPTY(&arguments))) {
							ZEPHIR_INIT_NVAR(&_38$$24);
							ZEPHIR_CALL_METHOD(&_39$$24, this_ptr, "buildParameters", &_4, 0, container, &arguments);
							zephir_check_call_status();
							ZEPHIR_CALL_USER_FUNC_ARRAY(&_38$$24, &methodCall, &_39$$24);
							zephir_check_call_status();
							continue;
						}
					}
					ZEPHIR_INIT_NVAR(&_40$$19);
					ZEPHIR_CALL_USER_FUNC(&_40$$19, &methodCall);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&method);
		ZEPHIR_INIT_NVAR(&methodPosition);
	}
	ZEPHIR_OBS_NVAR(&paramCalls);
	_41 = zephir_array_isset_string_fetch(&paramCalls, &definition, SL("properties"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_41) {
		if (UNEXPECTED(Z_TYPE_P(&instance) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_42$$26);
			object_init_ex(&_42$$26, phalcon_di_exceptions_propertyinjectionrequiresinstance_ce);
			ZEPHIR_CALL_METHOD(NULL, &_42$$26, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_42$$26, "phalcon/Di/Service/Builder.zep", 157);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&paramCalls) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_43$$27);
			object_init_ex(&_43$$27, phalcon_di_exceptions_setterparametersmustbearray_ce);
			ZEPHIR_CALL_METHOD(NULL, &_43$$27, "__construct", &_44, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_43$$27, "phalcon/Di/Service/Builder.zep", 161);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&paramCalls) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_46$$25);
			zephir_string_to_char_array(&_46$$25, &paramCalls);
			_45$$25 = &_46$$25;
		} else {
			_45$$25 = &paramCalls;
		}
		zephir_is_iterable(_45$$25, 0, "phalcon/Di/Service/Builder.zep", 198);
		if (Z_TYPE_P(_45$$25) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_45$$25), _48$$25, _49$$25, _47$$25)
			{
				ZEPHIR_INIT_NVAR(&propertyPosition);
				if (_49$$25 != NULL) { 
					ZVAL_STR_COPY(&propertyPosition, _49$$25);
				} else {
					ZVAL_LONG(&propertyPosition, _48$$25);
				}
				ZEPHIR_INIT_NVAR(&property);
				ZVAL_COPY(&property, _47$$25);
				if (UNEXPECTED(Z_TYPE_P(&property) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_50$$29);
					object_init_ex(&_50$$29, phalcon_di_exceptions_propertymustbearray_ce);
					ZEPHIR_CALL_METHOD(NULL, &_50$$29, "__construct", &_51, 0, &propertyPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_50$$29, "phalcon/Di/Service/Builder.zep", 172);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&propertyName);
				_52$$28 = zephir_array_isset_string_fetch(&propertyName, &property, SL("name"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_52$$28))) {
					ZEPHIR_INIT_NVAR(&_53$$30);
					object_init_ex(&_53$$30, phalcon_di_exceptions_propertynamerequired_ce);
					ZEPHIR_CALL_METHOD(NULL, &_53$$30, "__construct", &_54, 0, &propertyPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_53$$30, "phalcon/Di/Service/Builder.zep", 179);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&propertyValue);
				_55$$28 = zephir_array_isset_string_fetch(&propertyValue, &property, SL("value"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_55$$28))) {
					ZEPHIR_INIT_NVAR(&_56$$31);
					object_init_ex(&_56$$31, phalcon_di_exceptions_propertyvaluerequired_ce);
					ZEPHIR_CALL_METHOD(NULL, &_56$$31, "__construct", &_57, 0, &propertyPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_56$$31, "phalcon/Di/Service/Builder.zep", 186);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_58$$28, this_ptr, "buildParameter", &_59, 0, container, &propertyPosition, &propertyValue);
				zephir_check_call_status();
				zephir_update_property_zval_zval(&instance, &propertyName, &_58$$28);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _45$$25, "rewind", NULL, 0);
			zephir_check_call_status();
			_61$$25 = 1;
			while (1) {
				if (_61$$25) {
					_61$$25 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _45$$25, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_60$$25, _45$$25, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_60$$25)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&propertyPosition, _45$$25, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&property, _45$$25, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&property) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_62$$33);
						object_init_ex(&_62$$33, phalcon_di_exceptions_propertymustbearray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_62$$33, "__construct", &_63, 0, &propertyPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_62$$33, "phalcon/Di/Service/Builder.zep", 172);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&propertyName);
					_64$$32 = zephir_array_isset_string_fetch(&propertyName, &property, SL("name"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_64$$32))) {
						ZEPHIR_INIT_NVAR(&_65$$34);
						object_init_ex(&_65$$34, phalcon_di_exceptions_propertynamerequired_ce);
						ZEPHIR_CALL_METHOD(NULL, &_65$$34, "__construct", &_66, 0, &propertyPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_65$$34, "phalcon/Di/Service/Builder.zep", 179);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&propertyValue);
					_67$$32 = zephir_array_isset_string_fetch(&propertyValue, &property, SL("value"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_67$$32))) {
						ZEPHIR_INIT_NVAR(&_68$$35);
						object_init_ex(&_68$$35, phalcon_di_exceptions_propertyvaluerequired_ce);
						ZEPHIR_CALL_METHOD(NULL, &_68$$35, "__construct", &_69, 0, &propertyPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_68$$35, "phalcon/Di/Service/Builder.zep", 186);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_70$$32, this_ptr, "buildParameter", &_59, 0, container, &propertyPosition, &propertyValue);
					zephir_check_call_status();
					zephir_update_property_zval_zval(&instance, &propertyName, &_70$$32);
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
	zend_bool _0, _3$$4, _8$$6, _13$$8, _18$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_12 = NULL, *_17 = NULL;
	zval argument;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, *position_param = NULL, *argument_param = NULL, type, name, value, instanceArguments, _1$$3, _2$$3, _4$$5, _5$$5, _6$$5, _9$$7, _10$$7, _11$$7, _14$$9, _15$$9, _16$$9, _19$$11, _20$$11;

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
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&argument);
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
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &_2$$3);
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
			ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", &_7, 0, &_5$$5, &_6$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$5, "phalcon/Di/Service/Builder.zep", 228);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_1: ;
		zephir_memory_observe(&value);
		_8$$6 = zephir_array_isset_string_fetch(&value, &argument, SL("value"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(!(_8$$6))) {
			ZEPHIR_INIT_VAR(&_9$$7);
			object_init_ex(&_9$$7, phalcon_di_exceptions_missingparameterkey_ce);
			ZEPHIR_INIT_VAR(&_10$$7);
			ZVAL_STRING(&_10$$7, "value");
			ZVAL_LONG(&_11$$7, position);
			ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", &_12, 0, &_10$$7, &_11$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$7, "phalcon/Di/Service/Builder.zep", 238);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&value);
	zephir_switch_0_clause_2: ;
		ZEPHIR_OBS_NVAR(&name);
		_13$$8 = zephir_array_isset_string_fetch(&name, &argument, SL("className"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(!(_13$$8))) {
			ZEPHIR_INIT_VAR(&_14$$9);
			object_init_ex(&_14$$9, phalcon_di_exceptions_missingparameterkey_ce);
			ZEPHIR_INIT_VAR(&_15$$9);
			ZVAL_STRING(&_15$$9, "className");
			ZVAL_LONG(&_16$$9, position);
			ZEPHIR_CALL_METHOD(NULL, &_14$$9, "__construct", &_17, 0, &_15$$9, &_16$$9);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_14$$9, "phalcon/Di/Service/Builder.zep", 248);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&instanceArguments);
		_18$$8 = zephir_array_isset_string_fetch(&instanceArguments, &argument, SL("arguments"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_18$$8) {
			ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name, &instanceArguments);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_3: ;
		ZEPHIR_INIT_VAR(&_19$$11);
		object_init_ex(&_19$$11, phalcon_di_exceptions_unknownservicetype_ce);
		ZVAL_LONG(&_20$$11, position);
		ZEPHIR_CALL_METHOD(NULL, &_19$$11, "__construct", NULL, 0, &_20$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_19$$11, "phalcon/Di/Service/Builder.zep", 268);
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
	zend_bool _6;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, buildArguments;
	zval *container, container_sub, *arguments_param = NULL, position, argument, *_0, _5, _3$$3, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&buildArguments);
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
			ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "buildParameter", &_4, 0, container, &position, &argument);
			zephir_check_call_status();
			zephir_array_append(&buildArguments, &_3$$3, PH_SEPARATE, "phalcon/Di/Service/Builder.zep", 291);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arguments, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &arguments, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &arguments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&position, &arguments, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&argument, &arguments, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "buildParameter", &_4, 0, container, &position, &argument);
				zephir_check_call_status();
				zephir_array_append(&buildArguments, &_7$$4, PH_SEPARATE, "phalcon/Di/Service/Builder.zep", 291);
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

