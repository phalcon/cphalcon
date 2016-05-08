
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
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/hash.h"
#include "kernel/object.h"


/**
 * Phalcon\Di\Service\Builder
 *
 * This class builds instances based on complex definitions
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_Service_Builder) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Di\\Service, Builder, phalcon, di_service_builder, phalcon_di_service_builder_method_entry, 0);

	return SUCCESS;

}

/**
 * Resolves a constructor/call parameter
 *
 * @param \Phalcon\DiInterface dependencyInjector
 * @param int position
 * @param array argument
 * @return mixed
 */
PHP_METHOD(Phalcon_Di_Service_Builder, _buildParameter) {

	zval *_2$$3, *_5$$5, *_8$$8, *_11$$10, *_14$$13;
	zval *argument = NULL;
	int position, ZEPHIR_LAST_CALL_STATUS;
	zval *dependencyInjector, *position_param = NULL, *argument_param = NULL, *type = NULL, *name = NULL, *value = NULL, *instanceArguments = NULL, *_0$$3, _1$$3, *_3$$5, _4$$5, *_6$$8, _7$$8, *_9$$10, _10$$10, *_12$$13, _13$$13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dependencyInjector, &position_param, &argument_param);

	position = zephir_get_intval(position_param);
	argument = argument_param;


	ZEPHIR_OBS_VAR(type);
	if (!(zephir_array_isset_string_fetch(&type, argument, SS("type"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, phalcon_di_exception_ce);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, position);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "Argument at position ", &_1$$3, " must have a type");
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 9, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "phalcon/di/service/builder.zep", 49 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (ZEPHIR_IS_STRING(type, "service")) {
			ZEPHIR_OBS_VAR(name);
			if (!(zephir_array_isset_string_fetch(&name, argument, SS("name"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_3$$5);
				object_init_ex(_3$$5, phalcon_di_exception_ce);
				ZEPHIR_SINIT_VAR(_4$$5);
				ZVAL_LONG(&_4$$5, position);
				ZEPHIR_INIT_VAR(_5$$5);
				ZEPHIR_CONCAT_SV(_5$$5, "Service 'name' is required in parameter on position ", &_4$$5);
				ZEPHIR_CALL_METHOD(NULL, _3$$5, "__construct", NULL, 9, _5$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3$$5, "phalcon/di/service/builder.zep", 59 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The dependency injector container is not valid", "phalcon/di/service/builder.zep", 62);
				return;
			}
			ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "get", NULL, 0, name);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "parameter")) {
			ZEPHIR_OBS_VAR(value);
			if (!(zephir_array_isset_string_fetch(&value, argument, SS("value"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_6$$8);
				object_init_ex(_6$$8, phalcon_di_exception_ce);
				ZEPHIR_SINIT_VAR(_7$$8);
				ZVAL_LONG(&_7$$8, position);
				ZEPHIR_INIT_VAR(_8$$8);
				ZEPHIR_CONCAT_SV(_8$$8, "Service 'value' is required in parameter on position ", &_7$$8);
				ZEPHIR_CALL_METHOD(NULL, _6$$8, "__construct", NULL, 9, _8$$8);
				zephir_check_call_status();
				zephir_throw_exception_debug(_6$$8, "phalcon/di/service/builder.zep", 71 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(value);
		}
		if (ZEPHIR_IS_STRING(type, "instance")) {
			ZEPHIR_OBS_NVAR(name);
			if (!(zephir_array_isset_string_fetch(&name, argument, SS("className"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_9$$10);
				object_init_ex(_9$$10, phalcon_di_exception_ce);
				ZEPHIR_SINIT_VAR(_10$$10);
				ZVAL_LONG(&_10$$10, position);
				ZEPHIR_INIT_VAR(_11$$10);
				ZEPHIR_CONCAT_SV(_11$$10, "Service 'className' is required in parameter on position ", &_10$$10);
				ZEPHIR_CALL_METHOD(NULL, _9$$10, "__construct", NULL, 9, _11$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(_9$$10, "phalcon/di/service/builder.zep", 81 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The dependency injector container is not valid", "phalcon/di/service/builder.zep", 85);
				return;
			}
			ZEPHIR_OBS_VAR(instanceArguments);
			if (zephir_array_isset_string_fetch(&instanceArguments, argument, SS("arguments"), 0 TSRMLS_CC)) {
				ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "get", NULL, 0, name, instanceArguments);
				zephir_check_call_status();
				RETURN_MM();
			}
			ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "get", NULL, 0, name);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(_12$$13);
		object_init_ex(_12$$13, phalcon_di_exception_ce);
		ZEPHIR_SINIT_VAR(_13$$13);
		ZVAL_LONG(&_13$$13, position);
		ZEPHIR_INIT_VAR(_14$$13);
		ZEPHIR_CONCAT_SV(_14$$13, "Unknown service type in parameter on position ", &_13$$13);
		ZEPHIR_CALL_METHOD(NULL, _12$$13, "__construct", NULL, 9, _14$$13);
		zephir_check_call_status();
		zephir_throw_exception_debug(_12$$13, "phalcon/di/service/builder.zep", 104 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Resolves an array of parameters
 */
PHP_METHOD(Phalcon_Di_Service_Builder, _buildParameters) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL;
	zval *dependencyInjector, *arguments_param = NULL, *position = NULL, *argument = NULL, *buildArguments = NULL, **_2, *_3$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &dependencyInjector, &arguments_param);

	arguments = arguments_param;


	ZEPHIR_INIT_VAR(buildArguments);
	array_init(buildArguments);
	zephir_is_iterable(arguments, &_1, &_0, 0, 0, "phalcon/di/service/builder.zep", 119);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(position, _1, _0);
		ZEPHIR_GET_HVALUE(argument, _2);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "_buildparameter", &_4, 181, dependencyInjector, position, argument);
		zephir_check_call_status();
		zephir_array_append(&buildArguments, _3$$3, PH_SEPARATE, "phalcon/di/service/builder.zep", 117);
	}
	RETURN_CCTOR(buildArguments);

}

/**
 * Builds a service using a complex service definition
 *
 * @param \Phalcon\DiInterface dependencyInjector
 * @param array definition
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Di_Service_Builder, build) {

	HashTable *_3$$10, *_16$$19;
	HashPosition _2$$10, _15$$19;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL, *_25 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *definition = NULL;
	zval *dependencyInjector, *definition_param = NULL, *parameters = NULL, *className = NULL, *arguments = NULL, *paramCalls = NULL, *methodPosition = NULL, *method = NULL, *methodName = NULL, *methodCall = NULL, *instance = NULL, *propertyPosition = NULL, *property = NULL, *propertyName = NULL, *propertyValue = NULL, *_0$$8 = NULL, **_4$$10, *_5$$14 = NULL, *_6$$14 = NULL, *_8$$15 = NULL, *_9$$15 = NULL, *_10$$17 = NULL, *_11$$17 = NULL, *_12$$18 = NULL, *_13$$18 = NULL, *_14$$13 = NULL, **_17$$19, *_18$$23 = NULL, *_19$$23 = NULL, *_20$$24 = NULL, *_21$$24 = NULL, *_22$$25 = NULL, *_23$$25 = NULL, *_24$$22 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &dependencyInjector, &definition_param, &parameters);

	definition = definition_param;
	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(className);
	if (!(zephir_array_isset_string_fetch(&className, definition, SS("className"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Invalid service definition. Missing 'className' parameter", "phalcon/di/service/builder.zep", 140);
		return;
	}
	if (Z_TYPE_P(parameters) == IS_ARRAY) {
		if (zephir_fast_count_int(parameters TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(instance, className, parameters TSRMLS_CC);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(instance, className TSRMLS_CC);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_OBS_VAR(arguments);
		if (zephir_array_isset_string_fetch(&arguments, definition, SS("arguments"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_0$$8, this_ptr, "_buildparameters", &_1, 182, dependencyInjector, arguments);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(instance, className, _0$$8 TSRMLS_CC);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(instance, className TSRMLS_CC);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, definition, SS("calls"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(instance) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The definition has setter injection parameters but the constructor didn't return an instance", "phalcon/di/service/builder.zep", 177);
			return;
		}
		if (Z_TYPE_P(paramCalls) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Setter injection parameters must be an array", "phalcon/di/service/builder.zep", 181);
			return;
		}
		zephir_is_iterable(paramCalls, &_3$$10, &_2$$10, 0, 0, "phalcon/di/service/builder.zep", 233);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$10, (void**) &_4$$10, &_2$$10) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$10, &_2$$10)
		) {
			ZEPHIR_GET_HMKEY(methodPosition, _3$$10, _2$$10);
			ZEPHIR_GET_HVALUE(method, _4$$10);
			if (Z_TYPE_P(method) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(_5$$14);
				object_init_ex(_5$$14, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_6$$14);
				ZEPHIR_CONCAT_SV(_6$$14, "Method call must be an array on position ", methodPosition);
				ZEPHIR_CALL_METHOD(NULL, _5$$14, "__construct", &_7, 9, _6$$14);
				zephir_check_call_status();
				zephir_throw_exception_debug(_5$$14, "phalcon/di/service/builder.zep", 193 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(methodName);
			if (!(zephir_array_isset_string_fetch(&methodName, method, SS("method"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_8$$15);
				object_init_ex(_8$$15, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_9$$15);
				ZEPHIR_CONCAT_SV(_9$$15, "The method name is required on position ", methodPosition);
				ZEPHIR_CALL_METHOD(NULL, _8$$15, "__construct", &_7, 9, _9$$15);
				zephir_check_call_status();
				zephir_throw_exception_debug(_8$$15, "phalcon/di/service/builder.zep", 200 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(methodCall);
			zephir_create_array(methodCall, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(methodCall, instance);
			zephir_array_fast_append(methodCall, methodName);
			ZEPHIR_OBS_NVAR(arguments);
			if (zephir_array_isset_string_fetch(&arguments, method, SS("arguments"), 0 TSRMLS_CC)) {
				if (Z_TYPE_P(arguments) != IS_ARRAY) {
					ZEPHIR_INIT_NVAR(_10$$17);
					object_init_ex(_10$$17, phalcon_di_exception_ce);
					ZEPHIR_INIT_LNVAR(_11$$17);
					ZEPHIR_CONCAT_SV(_11$$17, "Call arguments must be an array ", methodPosition);
					ZEPHIR_CALL_METHOD(NULL, _10$$17, "__construct", &_7, 9, _11$$17);
					zephir_check_call_status();
					zephir_throw_exception_debug(_10$$17, "phalcon/di/service/builder.zep", 211 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_fast_count_int(arguments TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_12$$18);
					ZEPHIR_CALL_METHOD(&_13$$18, this_ptr, "_buildparameters", &_1, 182, dependencyInjector, arguments);
					zephir_check_call_status();
					ZEPHIR_CALL_USER_FUNC_ARRAY(_12$$18, methodCall, _13$$18);
					zephir_check_call_status();
					continue;
				}
			}
			ZEPHIR_INIT_NVAR(_14$$13);
			ZEPHIR_CALL_USER_FUNC(_14$$13, methodCall);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_NVAR(paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, definition, SS("properties"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(instance) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The definition has properties injection parameters but the constructor didn't return an instance", "phalcon/di/service/builder.zep", 241);
			return;
		}
		if (Z_TYPE_P(paramCalls) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Setter injection parameters must be an array", "phalcon/di/service/builder.zep", 245);
			return;
		}
		zephir_is_iterable(paramCalls, &_16$$19, &_15$$19, 0, 0, "phalcon/di/service/builder.zep", 279);
		for (
		  ; zephir_hash_get_current_data_ex(_16$$19, (void**) &_17$$19, &_15$$19) == SUCCESS
		  ; zephir_hash_move_forward_ex(_16$$19, &_15$$19)
		) {
			ZEPHIR_GET_HMKEY(propertyPosition, _16$$19, _15$$19);
			ZEPHIR_GET_HVALUE(property, _17$$19);
			if (Z_TYPE_P(property) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(_18$$23);
				object_init_ex(_18$$23, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_19$$23);
				ZEPHIR_CONCAT_SV(_19$$23, "Property must be an array on position ", propertyPosition);
				ZEPHIR_CALL_METHOD(NULL, _18$$23, "__construct", &_7, 9, _19$$23);
				zephir_check_call_status();
				zephir_throw_exception_debug(_18$$23, "phalcon/di/service/builder.zep", 257 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(propertyName);
			if (!(zephir_array_isset_string_fetch(&propertyName, property, SS("name"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_20$$24);
				object_init_ex(_20$$24, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_21$$24);
				ZEPHIR_CONCAT_SV(_21$$24, "The property name is required on position ", propertyPosition);
				ZEPHIR_CALL_METHOD(NULL, _20$$24, "__construct", &_7, 9, _21$$24);
				zephir_check_call_status();
				zephir_throw_exception_debug(_20$$24, "phalcon/di/service/builder.zep", 264 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(propertyValue);
			if (!(zephir_array_isset_string_fetch(&propertyValue, property, SS("value"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_22$$25);
				object_init_ex(_22$$25, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_23$$25);
				ZEPHIR_CONCAT_SV(_23$$25, "The property value is required on position ", propertyPosition);
				ZEPHIR_CALL_METHOD(NULL, _22$$25, "__construct", &_7, 9, _23$$25);
				zephir_check_call_status();
				zephir_throw_exception_debug(_22$$25, "phalcon/di/service/builder.zep", 271 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_24$$22, this_ptr, "_buildparameter", &_25, 181, dependencyInjector, propertyPosition, propertyValue);
			zephir_check_call_status();
			zephir_update_property_zval_zval(instance, propertyName, _24$$22 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(instance);

}

