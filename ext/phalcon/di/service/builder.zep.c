
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"


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
	zend_string *_7$$10, *_31$$25;
	zend_ulong _6$$10, _30$$25;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL, *_14 = NULL, *_33 = NULL, *_35 = NULL, *_37 = NULL, *_39 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *container, container_sub, *definition_param = NULL, *parameters = NULL, parameters_sub, __$null, className, arguments, paramCalls, methodPosition, method, methodName, methodCall, instance, propertyPosition, property, propertyName, propertyValue, _0$$3, _1$$8, _2$$11, _3$$12, *_4$$10, _5$$10, _8$$14, _10$$15, _12$$17, _13$$17, _15$$18, _16$$18, _17$$13, _18$$20, _19$$21, _20$$19, _25$$19, _21$$23, _22$$23, _23$$24, _24$$24, _26$$26, _27$$27, *_28$$25, _29$$25, _32$$29, _34$$30, _36$$31, _38$$28, _40$$33, _41$$34, _42$$35, _43$$32;
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
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$8);
	ZVAL_UNDEF(&_2$$11);
	ZVAL_UNDEF(&_3$$12);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_13$$17);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_16$$18);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$20);
	ZVAL_UNDEF(&_19$$21);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_25$$19);
	ZVAL_UNDEF(&_21$$23);
	ZVAL_UNDEF(&_22$$23);
	ZVAL_UNDEF(&_23$$24);
	ZVAL_UNDEF(&_24$$24);
	ZVAL_UNDEF(&_26$$26);
	ZVAL_UNDEF(&_27$$27);
	ZVAL_UNDEF(&_29$$25);
	ZVAL_UNDEF(&_32$$29);
	ZVAL_UNDEF(&_34$$30);
	ZVAL_UNDEF(&_36$$31);
	ZVAL_UNDEF(&_38$$28);
	ZVAL_UNDEF(&_40$$33);
	ZVAL_UNDEF(&_41$$34);
	ZVAL_UNDEF(&_42$$35);
	ZVAL_UNDEF(&_43$$32);
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
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	zephir_memory_observe(&className);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&className, &definition, SL("className"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_di_exceptions_missingclassnameparameter_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 369);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Di/Service/Builder.zep", 52);
		ZEPHIR_MM_RESTORE();
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
		zephir_memory_observe(&arguments);
		if (zephir_array_isset_string_fetch(&arguments, &definition, SL("arguments"), 0)) {
			ZEPHIR_CALL_METHOD(&_1$$8, this_ptr, "buildparameters", NULL, 370, container, &arguments);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&instance, &className, &_1$$8);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&instance, &className);
			zephir_check_call_status();
		}
	}
	zephir_memory_observe(&paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, &definition, SL("calls"), 0)) {
		if (UNEXPECTED(Z_TYPE_P(&instance) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_2$$11);
			object_init_ex(&_2$$11, phalcon_di_exceptions_setterinjectionrequiresinstance_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$11, "__construct", NULL, 371);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$11, "phalcon/Di/Service/Builder.zep", 87);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&paramCalls) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_3$$12);
			object_init_ex(&_3$$12, phalcon_di_exceptions_setterparametersmustbearray_ce);
			ZEPHIR_CALL_METHOD(NULL, &_3$$12, "__construct", NULL, 372);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$12, "phalcon/Di/Service/Builder.zep", 91);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_is_iterable(&paramCalls, 0, "phalcon/Di/Service/Builder.zep", 143);
		if (Z_TYPE_P(&paramCalls) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paramCalls), _6$$10, _7$$10, _4$$10)
			{
				ZEPHIR_INIT_NVAR(&methodPosition);
				if (_7$$10 != NULL) { 
					ZVAL_STR_COPY(&methodPosition, _7$$10);
				} else {
					ZVAL_LONG(&methodPosition, _6$$10);
				}
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _4$$10);
				if (UNEXPECTED(Z_TYPE_P(&method) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_8$$14);
					object_init_ex(&_8$$14, phalcon_di_exceptions_methodcallmustbearray_ce);
					ZEPHIR_CALL_METHOD(NULL, &_8$$14, "__construct", &_9, 373, &methodPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$14, "phalcon/Di/Service/Builder.zep", 102);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&methodName);
				if (UNEXPECTED(!(zephir_array_isset_string_fetch(&methodName, &method, SL("method"), 0)))) {
					ZEPHIR_INIT_NVAR(&_10$$15);
					object_init_ex(&_10$$15, phalcon_di_exceptions_methodnamerequired_ce);
					ZEPHIR_CALL_METHOD(NULL, &_10$$15, "__construct", &_11, 374, &methodPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$15, "phalcon/Di/Service/Builder.zep", 109);
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
						ZEPHIR_INIT_NVAR(&_12$$17);
						object_init_ex(&_12$$17, phalcon_di_exceptions_callargumentsmustbearray_ce);
						ZVAL_LONG(&_13$$17, zephir_get_intval(&methodPosition));
						ZEPHIR_CALL_METHOD(NULL, &_12$$17, "__construct", &_14, 375, &_13$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_12$$17, "phalcon/Di/Service/Builder.zep", 119);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_fast_count_int(&arguments)) {
						ZEPHIR_INIT_NVAR(&_15$$18);
						ZEPHIR_CALL_METHOD(&_16$$18, this_ptr, "buildparameters", NULL, 370, container, &arguments);
						zephir_check_call_status();
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_15$$18, &methodCall, &_16$$18);
						zephir_check_call_status();
						continue;
					}
				}
				ZEPHIR_INIT_NVAR(&_17$$13);
				ZEPHIR_CALL_USER_FUNC(&_17$$13, &methodCall);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &paramCalls, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$10, &paramCalls, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$10)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&methodPosition, &paramCalls, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&method, &paramCalls, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&method) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_18$$20);
						object_init_ex(&_18$$20, phalcon_di_exceptions_methodcallmustbearray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_18$$20, "__construct", &_9, 373, &methodPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_18$$20, "phalcon/Di/Service/Builder.zep", 102);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&methodName);
					if (UNEXPECTED(!(zephir_array_isset_string_fetch(&methodName, &method, SL("method"), 0)))) {
						ZEPHIR_INIT_NVAR(&_19$$21);
						object_init_ex(&_19$$21, phalcon_di_exceptions_methodnamerequired_ce);
						ZEPHIR_CALL_METHOD(NULL, &_19$$21, "__construct", &_11, 374, &methodPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_19$$21, "phalcon/Di/Service/Builder.zep", 109);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_20$$19);
					zephir_create_array(&_20$$19, 2, 0);
					zephir_array_fast_append(&_20$$19, &instance);
					zephir_array_fast_append(&_20$$19, &methodName);
					ZEPHIR_CPY_WRT(&methodCall, &_20$$19);
					ZEPHIR_OBS_NVAR(&arguments);
					if (zephir_array_isset_string_fetch(&arguments, &method, SL("arguments"), 0)) {
						if (UNEXPECTED(Z_TYPE_P(&arguments) != IS_ARRAY)) {
							ZEPHIR_INIT_NVAR(&_21$$23);
							object_init_ex(&_21$$23, phalcon_di_exceptions_callargumentsmustbearray_ce);
							ZVAL_LONG(&_22$$23, zephir_get_intval(&methodPosition));
							ZEPHIR_CALL_METHOD(NULL, &_21$$23, "__construct", &_14, 375, &_22$$23);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_21$$23, "phalcon/Di/Service/Builder.zep", 119);
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (zephir_fast_count_int(&arguments)) {
							ZEPHIR_INIT_NVAR(&_23$$24);
							ZEPHIR_CALL_METHOD(&_24$$24, this_ptr, "buildparameters", NULL, 370, container, &arguments);
							zephir_check_call_status();
							ZEPHIR_CALL_USER_FUNC_ARRAY(&_23$$24, &methodCall, &_24$$24);
							zephir_check_call_status();
							continue;
						}
					}
					ZEPHIR_INIT_NVAR(&_25$$19);
					ZEPHIR_CALL_USER_FUNC(&_25$$19, &methodCall);
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
			ZEPHIR_INIT_VAR(&_26$$26);
			object_init_ex(&_26$$26, phalcon_di_exceptions_propertyinjectionrequiresinstance_ce);
			ZEPHIR_CALL_METHOD(NULL, &_26$$26, "__construct", NULL, 376);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_26$$26, "phalcon/Di/Service/Builder.zep", 150);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&paramCalls) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_27$$27);
			object_init_ex(&_27$$27, phalcon_di_exceptions_setterparametersmustbearray_ce);
			ZEPHIR_CALL_METHOD(NULL, &_27$$27, "__construct", NULL, 372);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_27$$27, "phalcon/Di/Service/Builder.zep", 154);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_is_iterable(&paramCalls, 0, "phalcon/Di/Service/Builder.zep", 191);
		if (Z_TYPE_P(&paramCalls) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paramCalls), _30$$25, _31$$25, _28$$25)
			{
				ZEPHIR_INIT_NVAR(&propertyPosition);
				if (_31$$25 != NULL) { 
					ZVAL_STR_COPY(&propertyPosition, _31$$25);
				} else {
					ZVAL_LONG(&propertyPosition, _30$$25);
				}
				ZEPHIR_INIT_NVAR(&property);
				ZVAL_COPY(&property, _28$$25);
				if (UNEXPECTED(Z_TYPE_P(&property) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_32$$29);
					object_init_ex(&_32$$29, phalcon_di_exceptions_propertymustbearray_ce);
					ZEPHIR_CALL_METHOD(NULL, &_32$$29, "__construct", &_33, 377, &propertyPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_32$$29, "phalcon/Di/Service/Builder.zep", 165);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&propertyName);
				if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyName, &property, SL("name"), 0)))) {
					ZEPHIR_INIT_NVAR(&_34$$30);
					object_init_ex(&_34$$30, phalcon_di_exceptions_propertynamerequired_ce);
					ZEPHIR_CALL_METHOD(NULL, &_34$$30, "__construct", &_35, 378, &propertyPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_34$$30, "phalcon/Di/Service/Builder.zep", 172);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&propertyValue);
				if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyValue, &property, SL("value"), 0)))) {
					ZEPHIR_INIT_NVAR(&_36$$31);
					object_init_ex(&_36$$31, phalcon_di_exceptions_propertyvaluerequired_ce);
					ZEPHIR_CALL_METHOD(NULL, &_36$$31, "__construct", &_37, 379, &propertyPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_36$$31, "phalcon/Di/Service/Builder.zep", 179);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_38$$28, this_ptr, "buildparameter", &_39, 380, container, &propertyPosition, &propertyValue);
				zephir_check_call_status();
				zephir_update_property_zval_zval(&instance, &propertyName, &_38$$28);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &paramCalls, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_29$$25, &paramCalls, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_29$$25)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&propertyPosition, &paramCalls, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&property, &paramCalls, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&property) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_40$$33);
						object_init_ex(&_40$$33, phalcon_di_exceptions_propertymustbearray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_40$$33, "__construct", &_33, 377, &propertyPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_40$$33, "phalcon/Di/Service/Builder.zep", 165);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&propertyName);
					if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyName, &property, SL("name"), 0)))) {
						ZEPHIR_INIT_NVAR(&_41$$34);
						object_init_ex(&_41$$34, phalcon_di_exceptions_propertynamerequired_ce);
						ZEPHIR_CALL_METHOD(NULL, &_41$$34, "__construct", &_35, 378, &propertyPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_41$$34, "phalcon/Di/Service/Builder.zep", 172);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&propertyValue);
					if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyValue, &property, SL("value"), 0)))) {
						ZEPHIR_INIT_NVAR(&_42$$35);
						object_init_ex(&_42$$35, phalcon_di_exceptions_propertyvaluerequired_ce);
						ZEPHIR_CALL_METHOD(NULL, &_42$$35, "__construct", &_37, 379, &propertyPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_42$$35, "phalcon/Di/Service/Builder.zep", 179);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_43$$32, this_ptr, "buildparameter", &_39, 380, container, &propertyPosition, &propertyValue);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval argument;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, *position_param = NULL, *argument_param = NULL, type, name, value, instanceArguments, _0$$3, _1$$3, _2$$5, _3$$5, _4$$5, _5$$7, _6$$7, _7$$7, _8$$9, _9$$9, _10$$9, _11$$11, _12$$11;

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&instanceArguments);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&argument);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
		Z_PARAM_LONG(position)
		ZEPHIR_Z_PARAM_ARRAY(argument, argument_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &container, &position_param, &argument_param);
	ZEPHIR_OBS_COPY_OR_DUP(&argument, argument_param);
	zephir_memory_observe(&type);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&type, &argument, SL("type"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_di_exceptions_argumenttyperequired_ce);
		ZVAL_LONG(&_1$$3, position);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 381, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Di/Service/Builder.zep", 209);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (ZEPHIR_IS_STRING(&type, "service")) {
			zephir_memory_observe(&name);
			if (UNEXPECTED(!(zephir_array_isset_string_fetch(&name, &argument, SL("name"), 0)))) {
				ZEPHIR_INIT_VAR(&_2$$5);
				object_init_ex(&_2$$5, phalcon_di_exceptions_missingparameterkey_ce);
				ZEPHIR_INIT_VAR(&_3$$5);
				ZVAL_STRING(&_3$$5, "name");
				ZVAL_LONG(&_4$$5, position);
				ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 382, &_3$$5, &_4$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_2$$5, "phalcon/Di/Service/Builder.zep", 219);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "parameter")) {
			zephir_memory_observe(&value);
			if (UNEXPECTED(!(zephir_array_isset_string_fetch(&value, &argument, SL("value"), 0)))) {
				ZEPHIR_INIT_VAR(&_5$$7);
				object_init_ex(&_5$$7, phalcon_di_exceptions_missingparameterkey_ce);
				ZEPHIR_INIT_VAR(&_6$$7);
				ZVAL_STRING(&_6$$7, "value");
				ZVAL_LONG(&_7$$7, position);
				ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", NULL, 382, &_6$$7, &_7$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$7, "phalcon/Di/Service/Builder.zep", 229);
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(&value);
		}
		if (ZEPHIR_IS_STRING(&type, "instance")) {
			ZEPHIR_OBS_NVAR(&name);
			if (UNEXPECTED(!(zephir_array_isset_string_fetch(&name, &argument, SL("className"), 0)))) {
				ZEPHIR_INIT_VAR(&_8$$9);
				object_init_ex(&_8$$9, phalcon_di_exceptions_missingparameterkey_ce);
				ZEPHIR_INIT_VAR(&_9$$9);
				ZVAL_STRING(&_9$$9, "className");
				ZVAL_LONG(&_10$$9, position);
				ZEPHIR_CALL_METHOD(NULL, &_8$$9, "__construct", NULL, 382, &_9$$9, &_10$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_8$$9, "phalcon/Di/Service/Builder.zep", 239);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&instanceArguments);
			if (zephir_array_isset_string_fetch(&instanceArguments, &argument, SL("arguments"), 0)) {
				ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name, &instanceArguments);
				zephir_check_call_status();
				RETURN_MM();
			}
			ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_11$$11);
		object_init_ex(&_11$$11, phalcon_di_exceptions_unknownservicetype_ce);
		ZVAL_LONG(&_12$$11, position);
		ZEPHIR_CALL_METHOD(NULL, &_11$$11, "__construct", NULL, 383, &_12$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$11, "phalcon/Di/Service/Builder.zep", 259);
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &container, &arguments_param);
	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);
	ZEPHIR_INIT_VAR(&buildArguments);
	array_init(&buildArguments);
	zephir_is_iterable(&arguments, 0, "phalcon/Di/Service/Builder.zep", 281);
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
			ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "buildparameter", &_5, 380, container, &position, &argument);
			zephir_check_call_status();
			zephir_array_append(&buildArguments, &_4$$3, PH_SEPARATE, "phalcon/Di/Service/Builder.zep", 278);
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
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "buildparameter", &_5, 380, container, &position, &argument);
				zephir_check_call_status();
				zephir_array_append(&buildArguments, &_6$$4, PH_SEPARATE, "phalcon/Di/Service/Builder.zep", 278);
			ZEPHIR_CALL_METHOD(NULL, &arguments, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&argument);
	ZEPHIR_INIT_NVAR(&position);
	RETURN_CTOR(&buildArguments);
}

