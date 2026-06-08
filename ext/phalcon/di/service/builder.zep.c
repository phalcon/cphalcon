
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
	zend_bool _18$$10, _41$$25;
	zend_string *_6$$10, *_31$$25;
	zend_ulong _5$$10, _30$$25;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_10 = NULL, *_13 = NULL, *_33 = NULL, *_35 = NULL, *_37 = NULL, *_39 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *container, container_sub, *definition_param = NULL, *parameters = NULL, parameters_sub, __$null, className, arguments, paramCalls, methodPosition, method, methodName, methodCall, instance, propertyPosition, property, propertyName, propertyValue, _0$$3, _1$$8, _2$$11, _3$$12, *_4$$10, _17$$10, _7$$14, _9$$15, _11$$17, _12$$17, _14$$18, _15$$18, _16$$13, _19$$20, _20$$21, _21$$19, _26$$19, _22$$23, _23$$23, _24$$24, _25$$24, _27$$26, _28$$27, *_29$$25, _40$$25, _32$$29, _34$$30, _36$$31, _38$$28, _42$$33, _43$$34, _44$$35, _45$$32;
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
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_9$$15);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_19$$20);
	ZVAL_UNDEF(&_20$$21);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_22$$23);
	ZVAL_UNDEF(&_23$$23);
	ZVAL_UNDEF(&_24$$24);
	ZVAL_UNDEF(&_25$$24);
	ZVAL_UNDEF(&_27$$26);
	ZVAL_UNDEF(&_28$$27);
	ZVAL_UNDEF(&_40$$25);
	ZVAL_UNDEF(&_32$$29);
	ZVAL_UNDEF(&_34$$30);
	ZVAL_UNDEF(&_36$$31);
	ZVAL_UNDEF(&_38$$28);
	ZVAL_UNDEF(&_42$$33);
	ZVAL_UNDEF(&_43$$34);
	ZVAL_UNDEF(&_44$$35);
	ZVAL_UNDEF(&_45$$32);
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 452);
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
			ZEPHIR_CALL_METHOD(&_1$$8, this_ptr, "buildparameters", NULL, 453, container, &arguments);
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
			ZEPHIR_CALL_METHOD(NULL, &_2$$11, "__construct", NULL, 454);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$11, "phalcon/Di/Service/Builder.zep", 87);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&paramCalls) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_3$$12);
			object_init_ex(&_3$$12, phalcon_di_exceptions_setterparametersmustbearray_ce);
			ZEPHIR_CALL_METHOD(NULL, &_3$$12, "__construct", NULL, 455);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$12, "phalcon/Di/Service/Builder.zep", 91);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_is_iterable(&paramCalls, 0, "phalcon/Di/Service/Builder.zep", 143);
		if (Z_TYPE_P(&paramCalls) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paramCalls), _5$$10, _6$$10, _4$$10)
			{
				ZEPHIR_INIT_NVAR(&methodPosition);
				if (_6$$10 != NULL) { 
					ZVAL_STR_COPY(&methodPosition, _6$$10);
				} else {
					ZVAL_LONG(&methodPosition, _5$$10);
				}
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _4$$10);
				if (UNEXPECTED(Z_TYPE_P(&method) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_7$$14);
					object_init_ex(&_7$$14, phalcon_di_exceptions_methodcallmustbearray_ce);
					ZEPHIR_CALL_METHOD(NULL, &_7$$14, "__construct", &_8, 456, &methodPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_7$$14, "phalcon/Di/Service/Builder.zep", 102);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&methodName);
				if (UNEXPECTED(!(zephir_array_isset_string_fetch(&methodName, &method, SL("method"), 0)))) {
					ZEPHIR_INIT_NVAR(&_9$$15);
					object_init_ex(&_9$$15, phalcon_di_exceptions_methodnamerequired_ce);
					ZEPHIR_CALL_METHOD(NULL, &_9$$15, "__construct", &_10, 457, &methodPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$15, "phalcon/Di/Service/Builder.zep", 109);
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
						ZEPHIR_INIT_NVAR(&_11$$17);
						object_init_ex(&_11$$17, phalcon_di_exceptions_callargumentsmustbearray_ce);
						ZVAL_LONG(&_12$$17, zephir_get_intval(&methodPosition));
						ZEPHIR_CALL_METHOD(NULL, &_11$$17, "__construct", &_13, 458, &_12$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_11$$17, "phalcon/Di/Service/Builder.zep", 119);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_fast_count_int(&arguments)) {
						ZEPHIR_INIT_NVAR(&_14$$18);
						ZEPHIR_CALL_METHOD(&_15$$18, this_ptr, "buildparameters", NULL, 453, container, &arguments);
						zephir_check_call_status();
						ZEPHIR_CALL_USER_FUNC_ARRAY(&_14$$18, &methodCall, &_15$$18);
						zephir_check_call_status();
						continue;
					}
				}
				ZEPHIR_INIT_NVAR(&_16$$13);
				ZEPHIR_CALL_USER_FUNC(&_16$$13, &methodCall);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &paramCalls, "rewind", NULL, 0);
			zephir_check_call_status();
			_18$$10 = 1;
			while (1) {
				if (_18$$10) {
					_18$$10 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &paramCalls, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_17$$10, &paramCalls, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_17$$10)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&methodPosition, &paramCalls, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&method, &paramCalls, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&method) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_19$$20);
						object_init_ex(&_19$$20, phalcon_di_exceptions_methodcallmustbearray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_19$$20, "__construct", &_8, 456, &methodPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_19$$20, "phalcon/Di/Service/Builder.zep", 102);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&methodName);
					if (UNEXPECTED(!(zephir_array_isset_string_fetch(&methodName, &method, SL("method"), 0)))) {
						ZEPHIR_INIT_NVAR(&_20$$21);
						object_init_ex(&_20$$21, phalcon_di_exceptions_methodnamerequired_ce);
						ZEPHIR_CALL_METHOD(NULL, &_20$$21, "__construct", &_10, 457, &methodPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_20$$21, "phalcon/Di/Service/Builder.zep", 109);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_21$$19);
					zephir_create_array(&_21$$19, 2, 0);
					zephir_array_fast_append(&_21$$19, &instance);
					zephir_array_fast_append(&_21$$19, &methodName);
					ZEPHIR_CPY_WRT(&methodCall, &_21$$19);
					ZEPHIR_OBS_NVAR(&arguments);
					if (zephir_array_isset_string_fetch(&arguments, &method, SL("arguments"), 0)) {
						if (UNEXPECTED(Z_TYPE_P(&arguments) != IS_ARRAY)) {
							ZEPHIR_INIT_NVAR(&_22$$23);
							object_init_ex(&_22$$23, phalcon_di_exceptions_callargumentsmustbearray_ce);
							ZVAL_LONG(&_23$$23, zephir_get_intval(&methodPosition));
							ZEPHIR_CALL_METHOD(NULL, &_22$$23, "__construct", &_13, 458, &_23$$23);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_22$$23, "phalcon/Di/Service/Builder.zep", 119);
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (zephir_fast_count_int(&arguments)) {
							ZEPHIR_INIT_NVAR(&_24$$24);
							ZEPHIR_CALL_METHOD(&_25$$24, this_ptr, "buildparameters", NULL, 453, container, &arguments);
							zephir_check_call_status();
							ZEPHIR_CALL_USER_FUNC_ARRAY(&_24$$24, &methodCall, &_25$$24);
							zephir_check_call_status();
							continue;
						}
					}
					ZEPHIR_INIT_NVAR(&_26$$19);
					ZEPHIR_CALL_USER_FUNC(&_26$$19, &methodCall);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&method);
		ZEPHIR_INIT_NVAR(&methodPosition);
	}
	ZEPHIR_OBS_NVAR(&paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, &definition, SL("properties"), 0)) {
		if (UNEXPECTED(Z_TYPE_P(&instance) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_27$$26);
			object_init_ex(&_27$$26, phalcon_di_exceptions_propertyinjectionrequiresinstance_ce);
			ZEPHIR_CALL_METHOD(NULL, &_27$$26, "__construct", NULL, 459);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_27$$26, "phalcon/Di/Service/Builder.zep", 150);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&paramCalls) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_28$$27);
			object_init_ex(&_28$$27, phalcon_di_exceptions_setterparametersmustbearray_ce);
			ZEPHIR_CALL_METHOD(NULL, &_28$$27, "__construct", NULL, 455);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_28$$27, "phalcon/Di/Service/Builder.zep", 154);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_is_iterable(&paramCalls, 0, "phalcon/Di/Service/Builder.zep", 191);
		if (Z_TYPE_P(&paramCalls) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paramCalls), _30$$25, _31$$25, _29$$25)
			{
				ZEPHIR_INIT_NVAR(&propertyPosition);
				if (_31$$25 != NULL) { 
					ZVAL_STR_COPY(&propertyPosition, _31$$25);
				} else {
					ZVAL_LONG(&propertyPosition, _30$$25);
				}
				ZEPHIR_INIT_NVAR(&property);
				ZVAL_COPY(&property, _29$$25);
				if (UNEXPECTED(Z_TYPE_P(&property) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_32$$29);
					object_init_ex(&_32$$29, phalcon_di_exceptions_propertymustbearray_ce);
					ZEPHIR_CALL_METHOD(NULL, &_32$$29, "__construct", &_33, 460, &propertyPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_32$$29, "phalcon/Di/Service/Builder.zep", 165);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&propertyName);
				if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyName, &property, SL("name"), 0)))) {
					ZEPHIR_INIT_NVAR(&_34$$30);
					object_init_ex(&_34$$30, phalcon_di_exceptions_propertynamerequired_ce);
					ZEPHIR_CALL_METHOD(NULL, &_34$$30, "__construct", &_35, 461, &propertyPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_34$$30, "phalcon/Di/Service/Builder.zep", 172);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&propertyValue);
				if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyValue, &property, SL("value"), 0)))) {
					ZEPHIR_INIT_NVAR(&_36$$31);
					object_init_ex(&_36$$31, phalcon_di_exceptions_propertyvaluerequired_ce);
					ZEPHIR_CALL_METHOD(NULL, &_36$$31, "__construct", &_37, 462, &propertyPosition);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_36$$31, "phalcon/Di/Service/Builder.zep", 179);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_38$$28, this_ptr, "buildparameter", &_39, 463, container, &propertyPosition, &propertyValue);
				zephir_check_call_status();
				zephir_update_property_zval_zval(&instance, &propertyName, &_38$$28);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &paramCalls, "rewind", NULL, 0);
			zephir_check_call_status();
			_41$$25 = 1;
			while (1) {
				if (_41$$25) {
					_41$$25 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &paramCalls, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_40$$25, &paramCalls, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_40$$25)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&propertyPosition, &paramCalls, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&property, &paramCalls, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(Z_TYPE_P(&property) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_42$$33);
						object_init_ex(&_42$$33, phalcon_di_exceptions_propertymustbearray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_42$$33, "__construct", &_33, 460, &propertyPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_42$$33, "phalcon/Di/Service/Builder.zep", 165);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&propertyName);
					if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyName, &property, SL("name"), 0)))) {
						ZEPHIR_INIT_NVAR(&_43$$34);
						object_init_ex(&_43$$34, phalcon_di_exceptions_propertynamerequired_ce);
						ZEPHIR_CALL_METHOD(NULL, &_43$$34, "__construct", &_35, 461, &propertyPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_43$$34, "phalcon/Di/Service/Builder.zep", 172);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&propertyValue);
					if (UNEXPECTED(!(zephir_array_isset_string_fetch(&propertyValue, &property, SL("value"), 0)))) {
						ZEPHIR_INIT_NVAR(&_44$$35);
						object_init_ex(&_44$$35, phalcon_di_exceptions_propertyvaluerequired_ce);
						ZEPHIR_CALL_METHOD(NULL, &_44$$35, "__construct", &_37, 462, &propertyPosition);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_44$$35, "phalcon/Di/Service/Builder.zep", 179);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_45$$32, this_ptr, "buildparameter", &_39, 463, container, &propertyPosition, &propertyValue);
					zephir_check_call_status();
					zephir_update_property_zval_zval(&instance, &propertyName, &_45$$32);
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 464, &_1$$3);
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
				ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 465, &_3$$5, &_4$$5);
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
				ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", NULL, 465, &_6$$7, &_7$$7);
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
				ZEPHIR_CALL_METHOD(NULL, &_8$$9, "__construct", NULL, 465, &_9$$9, &_10$$9);
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
		ZEPHIR_CALL_METHOD(NULL, &_11$$11, "__construct", NULL, 466, &_12$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$11, "phalcon/Di/Service/Builder.zep", 259);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

}

/**
 * Resolves an array of parameters
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
	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);
	ZEPHIR_INIT_VAR(&buildArguments);
	array_init(&buildArguments);
	zephir_is_iterable(&arguments, 0, "phalcon/Di/Service/Builder.zep", 281);
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
			ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "buildparameter", &_4, 463, container, &position, &argument);
			zephir_check_call_status();
			zephir_array_append(&buildArguments, &_3$$3, PH_SEPARATE, "phalcon/Di/Service/Builder.zep", 278);
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
				ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "buildparameter", &_4, 463, container, &position, &argument);
				zephir_check_call_status();
				zephir_array_append(&buildArguments, &_7$$4, PH_SEPARATE, "phalcon/Di/Service/Builder.zep", 278);
		}
	}
	ZEPHIR_INIT_NVAR(&argument);
	ZEPHIR_INIT_NVAR(&position);
	RETURN_CTOR(&buildArguments);
}

