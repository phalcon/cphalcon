
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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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
 * Builds a service using a complex service definition
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Di_Service_Builder, build) {

	zend_string *_3$$10, *_16$$19;
	zend_ulong _2$$10, _15$$19;
	zephir_fcall_cache_entry *_6 = NULL, *_24 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *container, container_sub, *definition_param = NULL, *parameters = NULL, parameters_sub, __$null, className, arguments, paramCalls, methodPosition, method, methodName, methodCall, instance, propertyPosition, property, propertyName, propertyValue, _0$$8, *_1$$10, _4$$14, _5$$14, _7$$15, _8$$15, _9$$17, _10$$17, _11$$18, _12$$18, _13$$13, *_14$$19, _17$$23, _18$$23, _19$$24, _20$$24, _21$$25, _22$$25, _23$$22;
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
	ZVAL_UNDEF(&_4$$14);
	ZVAL_UNDEF(&_5$$14);
	ZVAL_UNDEF(&_7$$15);
	ZVAL_UNDEF(&_8$$15);
	ZVAL_UNDEF(&_9$$17);
	ZVAL_UNDEF(&_10$$17);
	ZVAL_UNDEF(&_11$$18);
	ZVAL_UNDEF(&_12$$18);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_17$$23);
	ZVAL_UNDEF(&_18$$23);
	ZVAL_UNDEF(&_19$$24);
	ZVAL_UNDEF(&_20$$24);
	ZVAL_UNDEF(&_21$$25);
	ZVAL_UNDEF(&_22$$25);
	ZVAL_UNDEF(&_23$$22);
	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &container, &definition_param, &parameters);

	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_OBS_VAR(&className);
	if (!(zephir_array_isset_string_fetch(&className, &definition, SL("className"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Invalid service definition. Missing 'className' parameter", "phalcon/Di/Service/Builder.zep", 39);
		return;
	}
	if (Z_TYPE_P(parameters) == IS_ARRAY) {
		if (zephir_fast_count_int(parameters TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&instance, &className, parameters TSRMLS_CC);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&instance, &className TSRMLS_CC);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_OBS_VAR(&arguments);
		if (zephir_array_isset_string_fetch(&arguments, &definition, SL("arguments"), 0)) {
			ZEPHIR_CALL_METHOD(&_0$$8, this_ptr, "buildparameters", NULL, 169, container, &arguments);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&instance, &className, &_0$$8 TSRMLS_CC);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&instance);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&instance, &className TSRMLS_CC);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(&paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, &definition, SL("calls"), 0)) {
		if (Z_TYPE_P(&instance) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The definition has setter injection parameters but the constructor didn't return an instance", "phalcon/Di/Service/Builder.zep", 78);
			return;
		}
		if (Z_TYPE_P(&paramCalls) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Setter injection parameters must be an array", "phalcon/Di/Service/Builder.zep", 82);
			return;
		}
		zephir_is_iterable(&paramCalls, 0, "phalcon/Di/Service/Builder.zep", 134);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paramCalls), _2$$10, _3$$10, _1$$10)
		{
			ZEPHIR_INIT_NVAR(&methodPosition);
			if (_3$$10 != NULL) { 
				ZVAL_STR_COPY(&methodPosition, _3$$10);
			} else {
				ZVAL_LONG(&methodPosition, _2$$10);
			}
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_COPY(&method, _1$$10);
			if (Z_TYPE_P(&method) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_4$$14);
				object_init_ex(&_4$$14, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_5$$14);
				ZEPHIR_CONCAT_SV(&_5$$14, "Method call must be an array on position ", &methodPosition);
				ZEPHIR_CALL_METHOD(NULL, &_4$$14, "__construct", &_6, 1, &_5$$14);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$14, "phalcon/Di/Service/Builder.zep", 94 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&methodName);
			if (!(zephir_array_isset_string_fetch(&methodName, &method, SL("method"), 0))) {
				ZEPHIR_INIT_NVAR(&_7$$15);
				object_init_ex(&_7$$15, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_8$$15);
				ZEPHIR_CONCAT_SV(&_8$$15, "The method name is required on position ", &methodPosition);
				ZEPHIR_CALL_METHOD(NULL, &_7$$15, "__construct", &_6, 1, &_8$$15);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$15, "phalcon/Di/Service/Builder.zep", 101 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&methodCall);
			zephir_create_array(&methodCall, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&methodCall, &instance);
			zephir_array_fast_append(&methodCall, &methodName);
			ZEPHIR_OBS_NVAR(&arguments);
			if (zephir_array_isset_string_fetch(&arguments, &method, SL("arguments"), 0)) {
				if (Z_TYPE_P(&arguments) != IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_9$$17);
					object_init_ex(&_9$$17, phalcon_di_exception_ce);
					ZEPHIR_INIT_LNVAR(_10$$17);
					ZEPHIR_CONCAT_SV(&_10$$17, "Call arguments must be an array ", &methodPosition);
					ZEPHIR_CALL_METHOD(NULL, &_9$$17, "__construct", &_6, 1, &_10$$17);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$17, "phalcon/Di/Service/Builder.zep", 112 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_fast_count_int(&arguments TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(&_11$$18);
					ZEPHIR_CALL_METHOD(&_12$$18, this_ptr, "buildparameters", NULL, 169, container, &arguments);
					zephir_check_call_status();
					ZEPHIR_CALL_USER_FUNC_ARRAY(&_11$$18, &methodCall, &_12$$18);
					zephir_check_call_status();
					continue;
				}
			}
			ZEPHIR_INIT_NVAR(&_13$$13);
			ZEPHIR_CALL_USER_FUNC(&_13$$13, &methodCall);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&method);
		ZEPHIR_INIT_NVAR(&methodPosition);
	}
	ZEPHIR_OBS_NVAR(&paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, &definition, SL("properties"), 0)) {
		if (Z_TYPE_P(&instance) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The definition has properties injection parameters but the constructor didn't return an instance", "phalcon/Di/Service/Builder.zep", 144);
			return;
		}
		if (Z_TYPE_P(&paramCalls) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Setter injection parameters must be an array", "phalcon/Di/Service/Builder.zep", 148);
			return;
		}
		zephir_is_iterable(&paramCalls, 0, "phalcon/Di/Service/Builder.zep", 182);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paramCalls), _15$$19, _16$$19, _14$$19)
		{
			ZEPHIR_INIT_NVAR(&propertyPosition);
			if (_16$$19 != NULL) { 
				ZVAL_STR_COPY(&propertyPosition, _16$$19);
			} else {
				ZVAL_LONG(&propertyPosition, _15$$19);
			}
			ZEPHIR_INIT_NVAR(&property);
			ZVAL_COPY(&property, _14$$19);
			if (Z_TYPE_P(&property) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_17$$23);
				object_init_ex(&_17$$23, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_18$$23);
				ZEPHIR_CONCAT_SV(&_18$$23, "Property must be an array on position ", &propertyPosition);
				ZEPHIR_CALL_METHOD(NULL, &_17$$23, "__construct", &_6, 1, &_18$$23);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_17$$23, "phalcon/Di/Service/Builder.zep", 160 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&propertyName);
			if (!(zephir_array_isset_string_fetch(&propertyName, &property, SL("name"), 0))) {
				ZEPHIR_INIT_NVAR(&_19$$24);
				object_init_ex(&_19$$24, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_20$$24);
				ZEPHIR_CONCAT_SV(&_20$$24, "The property name is required on position ", &propertyPosition);
				ZEPHIR_CALL_METHOD(NULL, &_19$$24, "__construct", &_6, 1, &_20$$24);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_19$$24, "phalcon/Di/Service/Builder.zep", 167 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&propertyValue);
			if (!(zephir_array_isset_string_fetch(&propertyValue, &property, SL("value"), 0))) {
				ZEPHIR_INIT_NVAR(&_21$$25);
				object_init_ex(&_21$$25, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_22$$25);
				ZEPHIR_CONCAT_SV(&_22$$25, "The property value is required on position ", &propertyPosition);
				ZEPHIR_CALL_METHOD(NULL, &_21$$25, "__construct", &_6, 1, &_22$$25);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_21$$25, "phalcon/Di/Service/Builder.zep", 174 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_23$$22, this_ptr, "buildparameter", &_24, 170, container, &propertyPosition, &propertyValue);
			zephir_check_call_status();
			zephir_update_property_zval_zval(&instance, &propertyName, &_23$$22 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
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
PHP_METHOD(Phalcon_Di_Service_Builder, buildParameter) {

	zval _2$$3, _5$$5, _8$$8, _11$$10, _14$$13;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &container, &position_param, &argument_param);

	position = zephir_get_intval(position_param);
	ZEPHIR_OBS_COPY_OR_DUP(&argument, argument_param);


	ZEPHIR_OBS_VAR(&type);
	if (!(zephir_array_isset_string_fetch(&type, &argument, SL("type"), 0))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_di_exception_ce);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, position);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Argument at position ", &_1$$3, " must have a type");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Di/Service/Builder.zep", 200 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (ZEPHIR_IS_STRING(&type, "service")) {
			ZEPHIR_OBS_VAR(&name);
			if (!(zephir_array_isset_string_fetch(&name, &argument, SL("name"), 0))) {
				ZEPHIR_INIT_VAR(&_3$$5);
				object_init_ex(&_3$$5, phalcon_di_exception_ce);
				ZEPHIR_SINIT_VAR(_4$$5);
				ZVAL_LONG(&_4$$5, position);
				ZEPHIR_INIT_VAR(&_5$$5);
				ZEPHIR_CONCAT_SV(&_5$$5, "Service 'name' is required in parameter on position ", &_4$$5);
				ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 1, &_5$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$5, "phalcon/Di/Service/Builder.zep", 210 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(container) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The dependency injector container is not valid", "phalcon/Di/Service/Builder.zep", 213);
				return;
			}
			ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &name);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "parameter")) {
			ZEPHIR_OBS_VAR(&value);
			if (!(zephir_array_isset_string_fetch(&value, &argument, SL("value"), 0))) {
				ZEPHIR_INIT_VAR(&_6$$8);
				object_init_ex(&_6$$8, phalcon_di_exception_ce);
				ZEPHIR_SINIT_VAR(_7$$8);
				ZVAL_LONG(&_7$$8, position);
				ZEPHIR_INIT_VAR(&_8$$8);
				ZEPHIR_CONCAT_SV(&_8$$8, "Service 'value' is required in parameter on position ", &_7$$8);
				ZEPHIR_CALL_METHOD(NULL, &_6$$8, "__construct", NULL, 1, &_8$$8);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$8, "phalcon/Di/Service/Builder.zep", 222 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(&value);
		}
		if (ZEPHIR_IS_STRING(&type, "instance")) {
			ZEPHIR_OBS_NVAR(&name);
			if (!(zephir_array_isset_string_fetch(&name, &argument, SL("className"), 0))) {
				ZEPHIR_INIT_VAR(&_9$$10);
				object_init_ex(&_9$$10, phalcon_di_exception_ce);
				ZEPHIR_SINIT_VAR(_10$$10);
				ZVAL_LONG(&_10$$10, position);
				ZEPHIR_INIT_VAR(&_11$$10);
				ZEPHIR_CONCAT_SV(&_11$$10, "Service 'className' is required in parameter on position ", &_10$$10);
				ZEPHIR_CALL_METHOD(NULL, &_9$$10, "__construct", NULL, 1, &_11$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_9$$10, "phalcon/Di/Service/Builder.zep", 232 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(container) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The dependency injector container is not valid", "phalcon/Di/Service/Builder.zep", 236);
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
		ZEPHIR_SINIT_VAR(_13$$13);
		ZVAL_LONG(&_13$$13, position);
		ZEPHIR_INIT_VAR(&_14$$13);
		ZEPHIR_CONCAT_SV(&_14$$13, "Unknown service type in parameter on position ", &_13$$13);
		ZEPHIR_CALL_METHOD(NULL, &_12$$13, "__construct", NULL, 1, &_14$$13);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_12$$13, "phalcon/Di/Service/Builder.zep", 255 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Resolves an array of parameters
 */
PHP_METHOD(Phalcon_Di_Service_Builder, buildParameters) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments;
	zval *container, container_sub, *arguments_param = NULL, position, argument, buildArguments, *_0, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&buildArguments);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&arguments);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &container, &arguments_param);

	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);


	ZEPHIR_INIT_VAR(&buildArguments);
	array_init(&buildArguments);
	zephir_is_iterable(&arguments, 0, "phalcon/Di/Service/Builder.zep", 270);
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
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "buildparameter", &_4, 170, container, &position, &argument);
		zephir_check_call_status();
		zephir_array_append(&buildArguments, &_3$$3, PH_SEPARATE, "phalcon/Di/Service/Builder.zep", 268);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&argument);
	ZEPHIR_INIT_NVAR(&position);
	RETURN_CCTOR(&buildArguments);

}

