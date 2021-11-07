
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Di\Service\Builder
 *
 * This class builds instances based on complex definitions
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_Service_Builder)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Di\\Service, Builder, phalcon, di_service_builder, phalcon_di_service_builder_method_entry, 0);

	return SUCCESS;
}

/**
 * Builds a service using a complex service definition
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Di_Service_Builder, build)
{
	zend_string *_4$$10, *_28$$25;
	zend_ulong _3$$10, _27$$25;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_36 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *container, container_sub, *definition_param = NULL, *parameters = NULL, parameters_sub, __$null, className, arguments, paramCalls, methodPosition, method, methodName, methodCall, instance, propertyPosition, property, propertyName, propertyValue, _0$$8, *_1$$10, _2$$10, _5$$14, _6$$14, _8$$15, _9$$15, _10$$17, _11$$17, _12$$18, _13$$18, _14$$13, _15$$20, _16$$20, _17$$21, _18$$21, _19$$19, _24$$19, _20$$23, _21$$23, _22$$24, _23$$24, *_25$$25, _26$$25, _29$$29, _30$$29, _31$$30, _32$$30, _33$$31, _34$$31, _35$$28, _37$$33, _38$$33, _39$$34, _40$$34, _41$$35, _42$$35, _43$$32;
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
	ZVAL_UNDEF(&_0$$8);
	ZVAL_UNDEF(&_2$$10);
	ZVAL_UNDEF(&_5$$14);
	ZVAL_UNDEF(&_6$$14);
	ZVAL_UNDEF(&_8$$15);
	ZVAL_UNDEF(&_9$$15);
	ZVAL_UNDEF(&_10$$17);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_12$$18);
	ZVAL_UNDEF(&_13$$18);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$20);
	ZVAL_UNDEF(&_16$$20);
	ZVAL_UNDEF(&_17$$21);
	ZVAL_UNDEF(&_18$$21);
	ZVAL_UNDEF(&_19$$19);
	ZVAL_UNDEF(&_24$$19);
	ZVAL_UNDEF(&_20$$23);
	ZVAL_UNDEF(&_21$$23);
	ZVAL_UNDEF(&_22$$24);
	ZVAL_UNDEF(&_23$$24);
	ZVAL_UNDEF(&_26$$25);
	ZVAL_UNDEF(&_29$$29);
	ZVAL_UNDEF(&_30$$29);
	ZVAL_UNDEF(&_31$$30);
	ZVAL_UNDEF(&_32$$30);
	ZVAL_UNDEF(&_33$$31);
	ZVAL_UNDEF(&_34$$31);
	ZVAL_UNDEF(&_35$$28);
	ZVAL_UNDEF(&_37$$33);
	ZVAL_UNDEF(&_38$$33);
	ZVAL_UNDEF(&_39$$34);
	ZVAL_UNDEF(&_40$$34);
	ZVAL_UNDEF(&_41$$35);
	ZVAL_UNDEF(&_42$$35);
	ZVAL_UNDEF(&_43$$32);
	ZVAL_UNDEF(&definition);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
		Z_PARAM_ARRAY(definition)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &container, &definition_param, &parameters);
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_OBS_VAR(&className);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&className, &definition, SL("className"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Invalid service definition. Missing 'className' parameter", "phalcon/Di/Service/Builder.zep", 41);
		return;
	}
	if (Z_TYPE_P(parameters) == IS_ARRAY) {
		if (zephir_fast_count_int(parameters)) {
			ZEPHIR_INIT_VAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&instance, &className, parameters);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&instance, &className);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_OBS_VAR(&arguments);
		if (zephir_array_isset_string_fetch(&arguments, &definition, SL("arguments"), 0)) {
			ZEPHIR_CALL_METHOD(&_0$$8, this_ptr, "buildparameters", NULL, 217, container, &arguments);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&instance, &className, &_0$$8);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&instance, &className);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(&paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, &definition, SL("calls"), 0)) {
		if (UNEXPECTED(Z_TYPE_P(&instance) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The definition has setter injection parameters but the constructor didn't return an instance", "phalcon/Di/Service/Builder.zep", 83);
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&paramCalls) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Setter injection parameters must be an array", "phalcon/Di/Service/Builder.zep", 89);
			return;
		}
		zephir_is_iterable(&paramCalls, 0, "phalcon/Di/Service/Builder.zep", 148);
		if (Z_TYPE_P(&paramCalls) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paramCalls), _3$$10, _4$$10, _1$$10)
			{
				ZEPHIR_INIT_NVAR(&methodPosition);
				if (_4$$10 != NULL) { 
					ZVAL_STR_COPY(&methodPosition, _4$$10);
				} else {
					ZVAL_LONG(&methodPosition, _3$$10);
				}
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _1$$10);
				if (UNEXPECTED(Z_TYPE_P(&method) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_5$$14);
					object_init_ex(&_5$$14, phalcon_di_exception_ce);
					ZEPHIR_INIT_NVAR(&_6$$14);
					ZEPHIR_CONCAT_SV(&_6$$14, "Method call must be an array on position ", &methodPosition);
					ZEPHIR_CALL_METHOD(NULL, &_5$$14, "__construct", &_7, 8, &_6$$14);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_5$$14, "phalcon/Di/Service/Builder.zep", 103);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&methodName);
				if (UNEXPECTED(!(zephir_array_isset_string_fetch(&methodName, &method, SL("method"), 0)))) {
					ZEPHIR_INIT_NVAR(&_8$$15);
					object_init_ex(&_8$$15, phalcon_di_exception_ce);
					ZEPHIR_INIT_NVAR(&_9$$15);
					ZEPHIR_CONCAT_SV(&_9$$15, "The method name is required on position ", &methodPosition);
					ZEPHIR_CALL_METHOD(NULL, &_8$$15, "__construct", &_7, 8, &_9$$15);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$15, "phalcon/Di/Service/Builder.zep", 112);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&methodCall);
				zephir_create_array(&methodCall, 2, 0);
				zephir_array_fast_append(&methodCall, &instance);
				zephir_array_fast_append(&methodCall, &methodName);
				ZEPHIR_OBS_NVAR(&arguments);
				if (zephir_array_isset_string_fetch(&arguments, &method, SL("arguments"), 0)) {
					if (UNEXPECTED(Z_TYPE_P(&arguments) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_10$$17);
						object_init_ex(&_10$$17, phalcon_di_exception_ce);
						ZEPHIR_INIT_NVAR(&_11$$17);
						ZEPHIR_CONCAT_SV(&_11$$17, "Call arguments must be an array ", &methodPosition);
						ZEPHIR_CALL_METHOD(NULL, &_10$$17, "__construct", &_7, 8, &_11$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_10$$17, "phalcon/Di/Service/Builder.zep", 124);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_fast_count_int(&arguments)) {
						ZEPHIR_INIT_NVAR(&_12$$18);
						ZEPHIR_CALL_METHOD(&_13$$18, this_ptr, "buildparameters", NULL, 217, container, &arguments);
						zephir_check_call_status();
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_12$$18, &methodCall, &_13$$18);
						zephir_check_call_status();
						continue;
					}
				}
				ZEPHIR_INIT_NVAR(&_14$$13);
				ZEPHIR_CALL_USER_FUNC(&_14$$13, &methodCall);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &paramCalls, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$10, &paramCalls, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$10)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&methodPosition, &paramCalls, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&method, &paramCalls, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&method) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_15$$20);
						object_init_ex(&_15$$20, phalcon_di_exception_ce);
						ZEPHIR_INIT_NVAR(&_16$$20);
						ZEPHIR_CONCAT_SV(&_16$$20, "Method call must be an array on position ", &methodPosition);
						ZEPHIR_CALL_METHOD(NULL, &_15$$20, "__construct", &_7, 8, &_16$$20);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_15$$20, "phalcon/Di/Service/Builder.zep", 103);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&methodName);
					if (UNEXPECTED(!(zephir_array_isset_string_fetch(&methodName, &method, SL("method"), 0)))) {
						ZEPHIR_INIT_NVAR(&_17$$21);
						object_init_ex(&_17$$21, phalcon_di_exception_ce);
						ZEPHIR_INIT_NVAR(&_18$$21);
						ZEPHIR_CONCAT_SV(&_18$$21, "The method name is required on position ", &methodPosition);
						ZEPHIR_CALL_METHOD(NULL, &_17$$21, "__construct", &_7, 8, &_18$$21);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_17$$21, "phalcon/Di/Service/Builder.zep", 112);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_19$$19);
					zephir_create_array(&_19$$19, 2, 0);
					zephir_array_fast_append(&_19$$19, &instance);
					zephir_array_fast_append(&_19$$19, &methodName);
					ZEPHIR_CPY_WRT(&methodCall, &_19$$19);
					ZEPHIR_OBS_NVAR(&arguments);
					if (zephir_array_isset_string_fetch(&arguments, &method, SL("arguments"), 0)) {
						if (UNEXPECTED(Z_TYPE_P(&arguments) != IS_ARRAY)) {
							ZEPHIR_INIT_NVAR(&_20$$23);
							object_init_ex(&_20$$23, phalcon_di_exception_ce);
							ZEPHIR_INIT_NVAR(&_21$$23);
							ZEPHIR_CONCAT_SV(&_21$$23, "Call arguments must be an array ", &methodPosition);
							ZEPHIR_CALL_METHOD(NULL, &_20$$23, "__construct", &_7, 8, &_21$$23);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_20$$23, "phalcon/Di/Service/Builder.zep", 124);
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (zephir_fast_count_int(&arguments)) {
							ZEPHIR_INIT_NVAR(&_22$$24);
							ZEPHIR_CALL_METHOD(&_23$$24, this_ptr, "buildparameters", NULL, 217, container, &arguments);
							zephir_check_call_status();
							ZEPHIR_CALL_USER_FUNC_ARRAY(&_22$$24, &methodCall, &_23$$24);
							zephir_check_call_status();
							continue;
						}
					}
					ZEPHIR_INIT_NVAR(&_24$$19);
					ZEPHIR_CALL_USER_FUNC(&_24$$19, &methodCall);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &paramCalls, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&method);
		ZEPHIR_INIT_NVAR(&methodPosition);
	}
	ZEPHIR_OBS_NVAR(&paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, &definition, SL("properties"), 0)) {
		if (UNEXPECTED(Z_TYPE_P(&instance) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The definition has properties injection parameters but the constructor didn't return an instance", "phalcon/Di/Service/Builder.zep", 158);
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&paramCalls) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Setter injection parameters must be an array", "phalcon/Di/Service/Builder.zep", 164);
			return;
		}
		zephir_is_iterable(&paramCalls, 0, "phalcon/Di/Service/Builder.zep", 208);
		if (Z_TYPE_P(&paramCalls) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paramCalls), _27$$25, _28$$25, _25$$25)
			{
				ZEPHIR_INIT_NVAR(&propertyPosition);
				if (_28$$25 != NULL) { 
					ZVAL_STR_COPY(&propertyPosition, _28$$25);
				} else {
					ZVAL_LONG(&propertyPosition, _27$$25);
				}
				ZEPHIR_INIT_NVAR(&property);
				ZVAL_COPY(&property, _25$$25);
				if (UNEXPECTED(Z_TYPE_P(&property) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_29$$29);
					object_init_ex(&_29$$29, phalcon_di_exception_ce);
					ZEPHIR_INIT_NVAR(&_30$$29);
					ZEPHIR_CONCAT_SV(&_30$$29, "Property must be an array on position ", &propertyPosition);
					ZEPHIR_CALL_METHOD(NULL, &_29$$29, "__construct", &_7, 8, &_30$$29);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_29$$29, "phalcon/Di/Service/Builder.zep", 178);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&propertyName);
				if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyName, &property, SL("name"), 0)))) {
					ZEPHIR_INIT_NVAR(&_31$$30);
					object_init_ex(&_31$$30, phalcon_di_exception_ce);
					ZEPHIR_INIT_NVAR(&_32$$30);
					ZEPHIR_CONCAT_SV(&_32$$30, "The property name is required on position ", &propertyPosition);
					ZEPHIR_CALL_METHOD(NULL, &_31$$30, "__construct", &_7, 8, &_32$$30);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_31$$30, "phalcon/Di/Service/Builder.zep", 187);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&propertyValue);
				if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyValue, &property, SL("value"), 0)))) {
					ZEPHIR_INIT_NVAR(&_33$$31);
					object_init_ex(&_33$$31, phalcon_di_exception_ce);
					ZEPHIR_INIT_NVAR(&_34$$31);
					ZEPHIR_CONCAT_SV(&_34$$31, "The property value is required on position ", &propertyPosition);
					ZEPHIR_CALL_METHOD(NULL, &_33$$31, "__construct", &_7, 8, &_34$$31);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_33$$31, "phalcon/Di/Service/Builder.zep", 196);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_35$$28, this_ptr, "buildparameter", &_36, 218, container, &propertyPosition, &propertyValue);
				zephir_check_call_status();
				zephir_update_property_zval_zval(&instance, &propertyName, &_35$$28);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &paramCalls, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_26$$25, &paramCalls, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_26$$25)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&propertyPosition, &paramCalls, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&property, &paramCalls, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&property) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_37$$33);
						object_init_ex(&_37$$33, phalcon_di_exception_ce);
						ZEPHIR_INIT_NVAR(&_38$$33);
						ZEPHIR_CONCAT_SV(&_38$$33, "Property must be an array on position ", &propertyPosition);
						ZEPHIR_CALL_METHOD(NULL, &_37$$33, "__construct", &_7, 8, &_38$$33);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_37$$33, "phalcon/Di/Service/Builder.zep", 178);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&propertyName);
					if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyName, &property, SL("name"), 0)))) {
						ZEPHIR_INIT_NVAR(&_39$$34);
						object_init_ex(&_39$$34, phalcon_di_exception_ce);
						ZEPHIR_INIT_NVAR(&_40$$34);
						ZEPHIR_CONCAT_SV(&_40$$34, "The property name is required on position ", &propertyPosition);
						ZEPHIR_CALL_METHOD(NULL, &_39$$34, "__construct", &_7, 8, &_40$$34);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_39$$34, "phalcon/Di/Service/Builder.zep", 187);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&propertyValue);
					if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyValue, &property, SL("value"), 0)))) {
						ZEPHIR_INIT_NVAR(&_41$$35);
						object_init_ex(&_41$$35, phalcon_di_exception_ce);
						ZEPHIR_INIT_NVAR(&_42$$35);
						ZEPHIR_CONCAT_SV(&_42$$35, "The property value is required on position ", &propertyPosition);
						ZEPHIR_CALL_METHOD(NULL, &_41$$35, "__construct", &_7, 8, &_42$$35);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_41$$35, "phalcon/Di/Service/Builder.zep", 196);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_43$$32, this_ptr, "buildparameter", &_36, 218, container, &propertyPosition, &propertyValue);
					zephir_check_call_status();
					zephir_update_property_zval_zval(&instance, &propertyName, &_43$$32);
				ZEPHIR_CALL_METHOD(NULL, &paramCalls, "next", NULL, 0);
				zephir_check_call_status();
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
 * @return mixed
 */
PHP_METHOD(Phalcon_Di_Service_Builder, buildParameter)
{
	zval _2$$3, _5$$5, _8$$8, _11$$10, _14$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval argument;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, *position_param = NULL, *argument_param = NULL, type, name, value, instanceArguments, _0$$3, _1$$3, _3$$5, _4$$5, _6$$8, _7$$8, _9$$10, _10$$10, _12$$13, _13$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&instanceArguments);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_14$$13);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
		Z_PARAM_LONG(position)
		Z_PARAM_ARRAY(argument)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &container, &position_param, &argument_param);
	position = zephir_get_intval(position_param);
	ZEPHIR_OBS_COPY_OR_DUP(&argument, argument_param);


	ZEPHIR_OBS_VAR(&type);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&type, &argument, SL("type"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_di_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_LONG(&_1$$3, position);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Argument at position ", &_1$$3, " must have a type");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 8, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Di/Service/Builder.zep", 228);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (ZEPHIR_IS_STRING(&type, "service")) {
			ZEPHIR_OBS_VAR(&name);
			if (UNEXPECTED(!(zephir_array_isset_string_fetch(&name, &argument, SL("name"), 0)))) {
				ZEPHIR_INIT_VAR(&_3$$5);
				object_init_ex(&_3$$5, phalcon_di_exception_ce);
				ZEPHIR_INIT_VAR(&_4$$5);
				ZVAL_LONG(&_4$$5, position);
				ZEPHIR_INIT_VAR(&_5$$5);
				ZEPHIR_CONCAT_SV(&_5$$5, "Service 'name' is required in parameter on position ", &_4$$5);
				ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 8, &_5$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$5, "phalcon/Di/Service/Builder.zep", 241);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(Z_TYPE_P(container) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The dependency injector container is not valid", "phalcon/Di/Service/Builder.zep", 247);
				return;
			}
			ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "parameter")) {
			ZEPHIR_OBS_VAR(&value);
			if (UNEXPECTED(!(zephir_array_isset_string_fetch(&value, &argument, SL("value"), 0)))) {
				ZEPHIR_INIT_VAR(&_6$$8);
				object_init_ex(&_6$$8, phalcon_di_exception_ce);
				ZEPHIR_INIT_VAR(&_7$$8);
				ZVAL_LONG(&_7$$8, position);
				ZEPHIR_INIT_VAR(&_8$$8);
				ZEPHIR_CONCAT_SV(&_8$$8, "Service 'value' is required in parameter on position ", &_7$$8);
				ZEPHIR_CALL_METHOD(NULL, &_6$$8, "__construct", NULL, 8, &_8$$8);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$8, "phalcon/Di/Service/Builder.zep", 259);
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(&value);
		}
		if (ZEPHIR_IS_STRING(&type, "instance")) {
			ZEPHIR_OBS_NVAR(&name);
			if (UNEXPECTED(!(zephir_array_isset_string_fetch(&name, &argument, SL("className"), 0)))) {
				ZEPHIR_INIT_VAR(&_9$$10);
				object_init_ex(&_9$$10, phalcon_di_exception_ce);
				ZEPHIR_INIT_VAR(&_10$$10);
				ZVAL_LONG(&_10$$10, position);
				ZEPHIR_INIT_VAR(&_11$$10);
				ZEPHIR_CONCAT_SV(&_11$$10, "Service 'className' is required in parameter on position ", &_10$$10);
				ZEPHIR_CALL_METHOD(NULL, &_9$$10, "__construct", NULL, 8, &_11$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_9$$10, "phalcon/Di/Service/Builder.zep", 272);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(Z_TYPE_P(container) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The dependency injector container is not valid", "phalcon/Di/Service/Builder.zep", 278);
				return;
			}
			ZEPHIR_OBS_VAR(&instanceArguments);
			if (zephir_array_isset_string_fetch(&instanceArguments, &argument, SL("arguments"), 0)) {
				ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name, &instanceArguments);
				zephir_check_call_status();
				RETURN_MM();
			}
			ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_12$$13);
		object_init_ex(&_12$$13, phalcon_di_exception_ce);
		ZEPHIR_INIT_VAR(&_13$$13);
		ZVAL_LONG(&_13$$13, position);
		ZEPHIR_INIT_VAR(&_14$$13);
		ZEPHIR_CONCAT_SV(&_14$$13, "Unknown service type in parameter on position ", &_13$$13);
		ZEPHIR_CALL_METHOD(NULL, &_12$$13, "__construct", NULL, 8, &_14$$13);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_12$$13, "phalcon/Di/Service/Builder.zep", 300);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();
}

/**
 * Resolves an array of parameters
 */
PHP_METHOD(Phalcon_Di_Service_Builder, buildParameters)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, buildArguments;
	zval *container, container_sub, *arguments_param = NULL, position, argument, *_0, _1, _4$$3, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&buildArguments);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &container, &arguments_param);
	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);


	ZEPHIR_INIT_VAR(&buildArguments);
	array_init(&buildArguments);
	zephir_is_iterable(&arguments, 0, "phalcon/Di/Service/Builder.zep", 322);
	if (Z_TYPE_P(&arguments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&arguments), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&position);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&position, _3);
			} else {
				ZVAL_LONG(&position, _2);
			}
			ZEPHIR_INIT_NVAR(&argument);
			ZVAL_COPY(&argument, _0);
			ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "buildparameter", &_5, 218, container, &position, &argument);
			zephir_check_call_status();
			zephir_array_append(&buildArguments, &_4$$3, PH_SEPARATE, "phalcon/Di/Service/Builder.zep", 319);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arguments, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &arguments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&position, &arguments, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&argument, &arguments, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "buildparameter", &_5, 218, container, &position, &argument);
				zephir_check_call_status();
				zephir_array_append(&buildArguments, &_6$$4, PH_SEPARATE, "phalcon/Di/Service/Builder.zep", 319);
			ZEPHIR_CALL_METHOD(NULL, &arguments, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&argument);
	ZEPHIR_INIT_NVAR(&position);
	RETURN_CTOR(&buildArguments);
}

