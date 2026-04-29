
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Phalcon\Di\Di is a component that implements Dependency Injection/Service
 * Location of services and it's itself a container for them.
 *
 * Since Phalcon is highly decoupled, Phalcon\Di\Di is essential to integrate the
 * different components of the framework. The developer can also use this
 * component to inject dependencies and manage global instances of the different
 * classes used in the application.
 *
 * Basically, this component implements the `Inversion of Control` pattern.
 * Applying this, the objects do not receive their dependencies using setters or
 * constructors, but requesting a service dependency injector. This reduces the
 * overall complexity, since there is only one way to get the required
 * dependencies within a component.
 *
 * Additionally, this pattern increases testability in the code, thus making it
 * less prone to errors.
 *
 *```php
 * use Phalcon\Di\Di;
 * use Phalcon\Http\Request;
 *
 * $di = new Di();
 *
 * // Using a string definition
 * $di->set("request", Request::class, true);
 *
 * // Using an anonymous function
 * $di->setShared(
 *     "request",
 *     function () {
 *         return new Request();
 *     }
 * );
 *
 * $request = $di->getRequest();
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_Di)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Di, Di, phalcon, di_di, phalcon_di_di_method_entry, 0);

	/**
	 * List of service aliases
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_di_di_ce, SL("aliases"), ZEND_ACC_PROTECTED);
	/**
	 * Latest DI build
	 *
	 * @var DiInterface|null
	 */
	zend_declare_property_null(phalcon_di_di_ce, SL("defaultContainer"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * Events Manager
	 *
	 * @var ManagerInterface|null
	 */
	zend_declare_property_null(phalcon_di_di_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	/**
	 * List of registered services
	 *
	 * @var ServiceInterface[]
	 */
	zend_declare_property_null(phalcon_di_di_ce, SL("services"), ZEND_ACC_PROTECTED);
	/**
	 * List of shared instances
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_di_di_ce, SL("sharedInstances"), ZEND_ACC_PROTECTED);
	phalcon_di_di_ce->create_object = zephir_init_properties_Phalcon_Di_Di;

	zend_class_implements(phalcon_di_di_ce, 1, phalcon_di_diinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Di\Di constructor
 */
PHP_METHOD(Phalcon_Di_Di, __construct)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	zephir_read_static_property_ce(&_0, phalcon_di_di_ce, SL("defaultContainer"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_update_static_property_ce(phalcon_di_di_ce, ZEND_STRL("defaultContainer"), this_ptr);
	}
}

/**
 * Magic method to get or set services using setters/getters
 */
PHP_METHOD(Phalcon_Di_Di, __call)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments;
	zval method_zv, *arguments_param = NULL, instance, possibleService, definition, _6, _0$$3, _1$$3, _2$$3, _3$$6, _4$$6, _5$$6;
	zend_string *method = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&possibleService);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&arguments);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(method)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		arguments_param = ZEND_CALL_ARG(execute_data, 2);
	}
	ZVAL_STR_COPY(&method_zv, method);
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}
	if (zephir_start_with_str(&method_zv, SL("get"))) {
		ZVAL_LONG(&_0$$3, 3);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_substr(&_1$$3, &method_zv, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&possibleService, "lcfirst", NULL, 82, &_1$$3);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_2$$3, &possibleService)) {
			ZEPHIR_CALL_METHOD(&instance, this_ptr, "get", NULL, 0, &possibleService, &arguments);
			zephir_check_call_status();
			RETURN_CCTOR(&instance);
		}
	}
	if (zephir_start_with_str(&method_zv, SL("set"))) {
		zephir_memory_observe(&definition);
		if (zephir_array_isset_long_fetch(&definition, &arguments, 0, 0)) {
			ZVAL_LONG(&_3$$6, 3);
			ZEPHIR_INIT_VAR(&_4$$6);
			zephir_substr(&_4$$6, &method_zv, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_FUNCTION(&_5$$6, "lcfirst", NULL, 82, &_4$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_5$$6, &definition);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_CALL_CE_STATIC(&_6, phalcon_di_exception_ce, "undefinedmethod", NULL, 0, &method_zv);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_6, "phalcon/Di/Di.zep", 149);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Attempts to register a service in the services container
 * Only is successful if a service hasn't been registered previously
 * with the same name
 */
PHP_METHOD(Phalcon_Di_Di, attempt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared;
	zval name_zv, *definition, definition_sub, *shared_param = NULL, _0, _1, _2, _3, _4;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(definition)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(shared)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		shared_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR_COPY(&name_zv, name);
	if (!shared_param) {
		shared = 0;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name_zv)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	if (shared) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 83, definition, &_2);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("services"), &name_zv, &_1);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Di/Di.zep", 165);
	RETURN_CTOR(&_4);
}

/**
 * Resolves the service based on its configuration
 */
PHP_METHOD(Phalcon_Di_Di, get)
{
	zval _8$$5, _18$$18;
	zend_bool _2$$3, _15$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *parameters = NULL, parameters_sub, __$null, service, isShared, instance, _0, _1, _6, _16, _3$$3, _4$$4, _5$$4, _7$$5, _9$$5, _10$$7, _11$$7, _12$$9, _14$$12, _17$$18, _19$$18;
	zval name, _13$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&isShared);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_17$$18);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_18$$18);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(name_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &name_param, &parameters);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	ZEPHIR_INIT_VAR(&instance);
	ZVAL_NULL(&instance);
	ZEPHIR_INIT_NVAR(&instance);
	ZVAL_NULL(&instance);
	ZEPHIR_INIT_VAR(&service);
	ZVAL_NULL(&service);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvealias", NULL, 84, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	ZEPHIR_OBS_NVAR(&service);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&service, &_1, &name, 0)) {
		ZEPHIR_CALL_METHOD(&isShared, &service, "isshared", NULL, 0);
		zephir_check_call_status();
		_2$$3 = zephir_is_true(&isShared);
		if (_2$$3) {
			zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("sharedInstances"), PH_NOISY_CC | PH_READONLY);
			_2$$3 = zephir_array_isset(&_3$$3, &name);
		}
		if (_2$$3) {
			zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("sharedInstances"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_5$$4, &_4$$4, &name, PH_NOISY | PH_READONLY, "phalcon/Di/Di.zep", 191);
			RETURN_CTOR(&_5$$4);
		}
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_6) != IS_NULL) {
		zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_8$$5);
		zephir_create_array(&_8$$5, 2, 0);
		zephir_array_update_string(&_8$$5, SL("name"), &name, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_8$$5, SL("parameters"), parameters, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "di:beforeServiceResolve");
		ZEPHIR_CALL_METHOD(&instance, &_7$$5, "fire", NULL, 0, &_9$$5, this_ptr, &_8$$5);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&instance) == IS_NULL) {
		if (Z_TYPE_P(&service) != IS_NULL) {

			/* try_start_1: */

				ZEPHIR_CALL_METHOD(&instance, &service, "resolve", NULL, 0, parameters, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);

			try_end_1:

			if (EG(exception)) {
				ZEPHIR_INIT_VAR(&_10$$7);
				ZVAL_OBJ(&_10$$7, EG(exception));
				Z_ADDREF_P(&_10$$7);
				ZEPHIR_INIT_VAR(&_11$$7);
				if (zephir_instance_of_ev(&_10$$7, phalcon_di_exception_serviceresolutionexception_ce)) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&_11$$7, &_10$$7);
					ZEPHIR_INIT_VAR(&_12$$9);
					object_init_ex(&_12$$9, phalcon_di_exception_ce);
					ZEPHIR_INIT_VAR(&_13$$9);
					ZEPHIR_CONCAT_SVS(&_13$$9, "Service '", &name, "' cannot be resolved");
					ZEPHIR_CALL_METHOD(NULL, &_12$$9, "__construct", NULL, 32, &_13$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_12$$9, "phalcon/Di/Di.zep", 218);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_is_true(&isShared)) {
				zephir_update_property_array(this_ptr, SL("sharedInstances"), &name, &instance);
			}
		} else {
			if (UNEXPECTED(!(zephir_class_exists(&name, 1)))) {
				ZEPHIR_CALL_CE_STATIC(&_14$$12, phalcon_di_exception_ce, "servicenotfound", NULL, 0, &name);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_14$$12, "phalcon/Di/Di.zep", 231);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_15$$11 = Z_TYPE_P(parameters) == IS_ARRAY;
			if (_15$$11) {
				_15$$11 = ((zephir_fast_count_int(parameters)) ? 1 : 0);
			}
			if (_15$$11) {
				ZEPHIR_INIT_NVAR(&instance);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&instance, &name, parameters);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&instance);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&instance, &name);
				zephir_check_call_status();
			}
		}
	}
	if (Z_TYPE_P(&instance) == IS_OBJECT) {
		if (zephir_instance_of_ev(&instance, phalcon_di_injectionawareinterface_ce)) {
			ZEPHIR_CALL_METHOD(NULL, &instance, "setdi", NULL, 0, this_ptr);
			zephir_check_call_status();
		}
		if (zephir_instance_of_ev(&instance, phalcon_di_initializationawareinterface_ce)) {
			ZEPHIR_CALL_METHOD(NULL, &instance, "initialize", NULL, 0);
			zephir_check_call_status();
		}
	}
	zephir_read_property(&_16, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_16) != IS_NULL) {
		zephir_read_property(&_17$$18, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_18$$18);
		zephir_create_array(&_18$$18, 3, 0);
		zephir_array_update_string(&_18$$18, SL("name"), &name, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_18$$18, SL("parameters"), parameters, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_18$$18, SL("instance"), &instance, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_19$$18);
		ZVAL_STRING(&_19$$18, "di:afterServiceResolve");
		ZEPHIR_CALL_METHOD(NULL, &_17$$18, "fire", NULL, 0, &_19$$18, this_ptr, &_18$$18);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&instance);
}

/**
 * Return the alias based on a passed key. Returns an empty string if
 * the alias does not exist
 *
 * @param string $name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Di_Di, getAlias)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, _0, _1, _2;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &name_zv)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch(&_0, &_2, &name_zv, PH_NOISY, "phalcon/Di/Di.zep", 285);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "");
	}
	RETURN_CCTOR(&_0);
}

/**
 * Return the latest DI created
 */
PHP_METHOD(Phalcon_Di_Di, getDefault)
{
	zval _0;

	ZVAL_UNDEF(&_0);
	zephir_read_static_property_ce(&_0, phalcon_di_di_ce, SL("defaultContainer"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Di_Di, getInternalEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Returns a service definition without resolving
 */
PHP_METHOD(Phalcon_Di_Di, getRaw)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getservice", NULL, 0, &name_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getdefinition", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a Phalcon\Di\Service instance
 */
PHP_METHOD(Phalcon_Di_Di, getService)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1, _3, _4, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvealias", NULL, 84, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "has", NULL, 0, &name);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_di_exception_ce, "servicenotfound", NULL, 0, &name);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Di/Di.zep", 325);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "phalcon/Di/Di.zep", 328);
	RETURN_CTOR(&_4);
}

/**
 * Return the services registered in the DI
 */
PHP_METHOD(Phalcon_Di_Di, getServices)
{

	RETURN_MEMBER(getThis(), "services");
}

/**
 * Resolves a service, the resolved service is stored in the DI, subsequent
 * requests for this service will return the same instance
 */
PHP_METHOD(Phalcon_Di_Di, getShared)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *parameters = NULL, parameters_sub, __$null, _0, _1, _3, _4, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(name_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &name_param, &parameters);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvealias", NULL, 84, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("sharedInstances"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &name))) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "get", NULL, 0, &name, parameters);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("sharedInstances"), &name, &_2$$3);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("sharedInstances"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "phalcon/Di/Di.zep", 355);
	RETURN_CTOR(&_4);
}

/**
 * Loads services from a Config object.
 */
PHP_METHOD(Phalcon_Di_Di, loadFromConfig)
{
	zend_bool _4$$3, _8$$4;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, services, name, service, *_0, _1, _5$$3, _6$$3, _9$$4, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&services);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(config, phalcon_config_configinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_CALL_METHOD(&services, config, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&services, 0, "phalcon/Di/Di.zep", 374);
	if (Z_TYPE_P(&services) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&services), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&service);
			ZVAL_COPY(&service, _0);
			_4$$3 = zephir_array_isset_string(&service, SL("shared"));
			if (_4$$3) {
				ZEPHIR_OBS_NVAR(&_5$$3);
				zephir_array_fetch_string(&_5$$3, &service, SL("shared"), PH_NOISY, "phalcon/Di/Di.zep", 372);
				_4$$3 = zephir_is_true(&_5$$3);
			}
			ZVAL_BOOL(&_6$$3, _4$$3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_7, 0, &name, &service, &_6$$3);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &services, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &services, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &services, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&service, &services, "current", NULL, 0);
			zephir_check_call_status();
				_8$$4 = zephir_array_isset_string(&service, SL("shared"));
				if (_8$$4) {
					ZEPHIR_OBS_NVAR(&_9$$4);
					zephir_array_fetch_string(&_9$$4, &service, SL("shared"), PH_NOISY, "phalcon/Di/Di.zep", 372);
					_8$$4 = zephir_is_true(&_9$$4);
				}
				ZVAL_BOOL(&_10$$4, _8$$4);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_7, 0, &name, &service, &_10$$4);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &services, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&service);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();
}

/**
 * Loads services from a php config file.
 *
 * ```php
 * $di->loadFromPhp("path/services.php");
 * ```
 *
 * And the services can be specified in the file as:
 *
 * ```php
 * return [
 *      'myComponent' => [
 *          'className' => '\Acme\Components\MyComponent',
 *          'shared' => true,
 *      ],
 *      'group' => [
 *          'className' => '\Acme\Group',
 *          'arguments' => [
 *              [
 *                  'type' => 'service',
 *                  'service' => 'myComponent',
 *              ],
 *          ],
 *      ],
 *      'user' => [
 *          'className' => '\Acme\User',
 *      ],
 * ];
 * ```
 *
 * @link https://docs.phalcon.io/latest/di/
 */
PHP_METHOD(Phalcon_Di_Di, loadFromPhp)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filePath_zv, services;
	zend_string *filePath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath_zv);
	ZVAL_UNDEF(&services);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filePath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&filePath_zv, filePath);
	ZEPHIR_INIT_VAR(&services);
	object_init_ex(&services, phalcon_config_adapter_php_ce);
	ZEPHIR_CALL_METHOD(NULL, &services, "__construct", NULL, 85, &filePath_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadfromconfig", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Loads services from a yaml file.
 *
 * ```php
 * $di->loadFromYaml(
 *     "path/services.yaml",
 *     [
 *         "!approot" => function ($value) {
 *             return dirname(__DIR__) . $value;
 *         }
 *     ]
 * );
 * ```
 *
 * And the services can be specified in the file as:
 *
 * ```php
 * myComponent:
 *     className: \Acme\Components\MyComponent
 *     shared: true
 *
 * group:
 *     className: \Acme\Group
 *     arguments:
 *         - type: service
 *           name: myComponent
 *
 * user:
 *    className: \Acme\User
 * ```
 *
 * @link https://docs.phalcon.io/latest/di/
 */
PHP_METHOD(Phalcon_Di_Di, loadFromYaml)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval callbacks;
	zval filePath_zv, *callbacks_param = NULL, services;
	zend_string *filePath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath_zv);
	ZVAL_UNDEF(&services);
	ZVAL_UNDEF(&callbacks);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filePath)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY_OR_NULL(callbacks, callbacks_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		callbacks_param = ZEND_CALL_ARG(execute_data, 2);
	}
	ZVAL_STR_COPY(&filePath_zv, filePath);
	if (!callbacks_param) {
		ZEPHIR_INIT_VAR(&callbacks);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&callbacks, callbacks_param);
	}
	ZEPHIR_INIT_VAR(&services);
	object_init_ex(&services, phalcon_config_adapter_yaml_ce);
	ZEPHIR_CALL_METHOD(NULL, &services, "__construct", NULL, 86, &filePath_zv, &callbacks);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadfromconfig", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Check whether the DI contains a service by a name
 */
PHP_METHOD(Phalcon_Di_Di, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvealias", NULL, 84, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_1, &name));
}

/**
 * Allows to obtain a shared service using the array syntax
 *
 *```php
 * var_dump($di["request"]);
 *```
 */
PHP_METHOD(Phalcon_Di_Di, offsetGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_sub;
	zval *name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getshared", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check if a service is registered using the array syntax
 */
PHP_METHOD(Phalcon_Di_Di, offsetExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_sub;
	zval *name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Allows to register a shared service using the array syntax
 *
 *```php
 * $di["request"] = new \Phalcon\Http\Request();
 *```
 */
PHP_METHOD(Phalcon_Di_Di, offsetSet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval offset_sub, value_sub;
	zval *offset, *value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(offset)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &offset, &value);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setshared", NULL, 0, offset, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Removes a service from the services container using the array syntax
 */
PHP_METHOD(Phalcon_Di_Di, offsetUnset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_sub;
	zval *name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Registers a service provider.
 *
 * ```php
 * use Phalcon\Di\DiInterface;
 * use Phalcon\Di\ServiceProviderInterface;
 *
 * class SomeServiceProvider implements ServiceProviderInterface
 * {
 *     public function register(DiInterface $di)
 *     {
 *         $di->setShared(
 *             'service',
 *             function () {
 *                 // ...
 *             }
 *         );
 *     }
 * }
 * ```
 */
PHP_METHOD(Phalcon_Di_Di, register)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider, provider_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(provider, phalcon_di_serviceproviderinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &provider);
	ZEPHIR_CALL_METHOD(NULL, provider, "register", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Removes a service in the services container
 * It also removes any shared instance created for the service
 */
PHP_METHOD(Phalcon_Di_Di, remove)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, aliases, services, sharedInstances, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&aliases);
	ZVAL_UNDEF(&services);
	ZVAL_UNDEF(&sharedInstances);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&aliases, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&services, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("sharedInstances"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sharedInstances, &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "resolvealias", NULL, 84, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_1);
	zephir_array_unset(&aliases, &name, PH_SEPARATE);
	zephir_array_unset(&services, &name, PH_SEPARATE);
	zephir_array_unset(&sharedInstances, &name, PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("services"), &services);
	zephir_update_property_zval(this_ptr, ZEND_STRL("sharedInstances"), &sharedInstances);
	ZEPHIR_MM_RESTORE();
}

/**
 * Resets the internal default DI
 */
PHP_METHOD(Phalcon_Di_Di, reset)
{
	zval __$null;

	ZVAL_NULL(&__$null);
	zephir_update_static_property_ce(phalcon_di_di_ce, ZEND_STRL("defaultContainer"), &__$null);
}

/**
 * Registers a service in the services container
 */
PHP_METHOD(Phalcon_Di_Di, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared;
	zval *name_param = NULL, *definition, definition_sub, *shared_param = NULL, _0, _1, _2, _3, _4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(name_param)
		Z_PARAM_ZVAL(definition)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(shared)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &name_param, &definition, &shared_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	if (!shared_param) {
		shared = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvealias", NULL, 84, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	if (shared) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 83, definition, &_2);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("services"), &name, &_1);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "phalcon/Di/Di.zep", 584);
	RETURN_CTOR(&_4);
}

/**
 * Sets one or more aliases to the given name.
 *
 * @param string       $name
 * @param string|array $aliases
 *
 * @return Di
 * @throws Exception
 */
PHP_METHOD(Phalcon_Di_Di, setAlias)
{
	zend_bool _5$$5, _10$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, *aliases, aliases_sub, alias, currentAliases, localAliases, _0, *_3, _4, _1$$3, _2$$4, _6$$5, _7$$7, _8$$7, _11$$8, _12$$10, _13$$10;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&aliases_sub);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&currentAliases);
	ZVAL_UNDEF(&localAliases);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(aliases)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	aliases = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &name_zv);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_CE_STATIC(&_1$$3, phalcon_di_exception_ce, "servicenotfound", NULL, 0, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Di/Di.zep", 601);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&currentAliases);
	zephir_read_property(&currentAliases, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(&localAliases, aliases);
	if (Z_TYPE_P(&localAliases) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 1, 0);
		zephir_array_fast_append(&_2$$4, &localAliases);
		ZEPHIR_CPY_WRT(&localAliases, &_2$$4);
	}
	zephir_is_iterable(&localAliases, 0, "phalcon/Di/Di.zep", 622);
	if (Z_TYPE_P(&localAliases) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&localAliases), _3)
		{
			ZEPHIR_INIT_NVAR(&alias);
			ZVAL_COPY(&alias, _3);
			if (Z_TYPE_P(&alias) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Alias name must be a string", "phalcon/Di/Di.zep", 612);
				return;
			}
			_5$$5 = 1 == zephir_array_isset(&currentAliases, &alias);
			if (!(_5$$5)) {
				ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "has", NULL, 0, &alias);
				zephir_check_call_status();
				_5$$5 = ZEPHIR_IS_TRUE_IDENTICAL(&_6$$5);
			}
			if (_5$$5) {
				ZEPHIR_INIT_NVAR(&_7$$7);
				object_init_ex(&_7$$7, phalcon_di_exception_ce);
				ZEPHIR_INIT_NVAR(&_8$$7);
				ZEPHIR_CONCAT_SVS(&_8$$7, "Alias '", &alias, "' is already in use by an existing service");
				ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", &_9, 32, &_8$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$7, "phalcon/Di/Di.zep", 616);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&currentAliases, &alias, &name_zv, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &localAliases, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &localAliases, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&alias, &localAliases, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&alias) != IS_STRING) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Alias name must be a string", "phalcon/Di/Di.zep", 612);
					return;
				}
				_10$$8 = 1 == zephir_array_isset(&currentAliases, &alias);
				if (!(_10$$8)) {
					ZEPHIR_CALL_METHOD(&_11$$8, this_ptr, "has", NULL, 0, &alias);
					zephir_check_call_status();
					_10$$8 = ZEPHIR_IS_TRUE_IDENTICAL(&_11$$8);
				}
				if (_10$$8) {
					ZEPHIR_INIT_NVAR(&_12$$10);
					object_init_ex(&_12$$10, phalcon_di_exception_ce);
					ZEPHIR_INIT_NVAR(&_13$$10);
					ZEPHIR_CONCAT_SVS(&_13$$10, "Alias '", &alias, "' is already in use by an existing service");
					ZEPHIR_CALL_METHOD(NULL, &_12$$10, "__construct", &_9, 32, &_13$$10);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_12$$10, "phalcon/Di/Di.zep", 616);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&currentAliases, &alias, &name_zv, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &localAliases, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&alias);
	zephir_update_property_zval(this_ptr, ZEND_STRL("aliases"), &currentAliases);
	RETURN_THIS();
}

/**
 * Set a default dependency injection container to be obtained into static
 * methods
 */
PHP_METHOD(Phalcon_Di_Di, setDefault)
{
	zval *container, container_sub;

	ZVAL_UNDEF(&container_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &container);
	zephir_update_static_property_ce(phalcon_di_di_ce, ZEND_STRL("defaultContainer"), container);
}

/**
 * Sets the internal event manager
 */
PHP_METHOD(Phalcon_Di_Di, setInternalEventsManager)
{
	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);
	zephir_update_property_zval(this_ptr, ZEND_STRL("eventsManager"), eventsManager);
}

/**
 * Sets a service using a raw Phalcon\Di\Service definition
 */
PHP_METHOD(Phalcon_Di_Di, setService)
{
	zval name_zv, *rawDefinition, rawDefinition_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&rawDefinition_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJECT_OF_CLASS(rawDefinition, phalcon_di_serviceinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	rawDefinition = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("services"), &name_zv, rawDefinition);
	RETVAL_ZVAL(rawDefinition, 1, 0);
	return;
}

/**
 * Registers an "always shared" service in the services container
 */
PHP_METHOD(Phalcon_Di_Di, setShared)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, *definition, definition_sub, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(definition)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR_COPY(&name_zv, name);
	ZVAL_BOOL(&_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &name_zv, definition, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolve an alias to its actual service name
 *
 * @param string $name
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Di_Di, resolveAlias)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	zval name_zv, __$true, current, seen, _0, _1$$4, _2$$4, _3$$4, _6$$3, _7$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&seen);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CPY_WRT(&current, &name_zv);
	ZEPHIR_INIT_VAR(&seen);
	array_init(&seen);
	while (1) {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset(&_0, &current))) {
			break;
		}
		if (zephir_array_isset(&seen, &current)) {
			ZEPHIR_INIT_NVAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_di_exception_ce);
			ZEPHIR_INIT_NVAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "Circular alias reference detected while resolving '%s'");
			ZEPHIR_CALL_FUNCTION(&_3$$4, "sprintf", &_4, 73, &_2$$4, &name_zv);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", &_5, 32, &_3$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Di/Di.zep", 683);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&seen, &current, &__$true, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_7$$3, &_6$$3, &current, PH_NOISY | PH_READONLY, "phalcon/Di/Di.zep", 686);
		ZEPHIR_CPY_WRT(&current, &_7$$3);
	}
	RETURN_CCTOR(&current);
}

zend_object *zephir_init_properties_Phalcon_Di_Di(zend_class_entry *class_type)
{
		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("sharedInstances"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("sharedInstances"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("services"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("aliases"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

