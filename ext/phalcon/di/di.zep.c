
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Di\Di is a component that implements Dependency Injection/Service
 * Location of services, and it's itself a container for them.
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
 *
 * @phpstan-import-type config_callbacks from ConfigTypes
 * @phpstan-import-type di_parameters from DiTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_Di)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Di, Di, phalcon, di_di, phalcon_di_di_method_entry, 0);

	/**
	 * List of service aliases
	 *
	 * @var array<string, string>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_di_di_ce, SL("aliases"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Latest DI build
	 *
	 * @var DiInterface|null
	 */
	zend_declare_property_null(phalcon_di_di_ce, SL("defaultContainer"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * Events Manager
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_di_di_ce, SL("eventsManager"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Events\\ManagerInterface"));
	}

	/**
	 * List of registered services
	 *
	 * @var ServiceInterface[]
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_di_di_ce, SL("services"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * List of shared instances
	 *
	 * @var array<string, mixed>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_di_di_ce, SL("sharedInstances"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

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
 *
 * @param list<mixed> $arguments
 */
PHP_METHOD(Phalcon_Di_Di, __call)
{
	zend_bool _4$$3, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval arguments;
	zval method_zv, *arguments_param = NULL, instance, possibleService, definition, _9, _0$$3, _1$$3, _3$$3, _6$$6, _7$$6, _8$$6;
	zend_string *method = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&possibleService);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&arguments);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("services", 8, 1);
	}

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
	zephir_memory_observe(&method_zv);
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
		ZEPHIR_CALL_FUNCTION(&possibleService, "lcfirst", &_2, 180, &_1$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 175, PH_NOISY_CC | PH_READONLY);
		_4$$3 = zephir_array_isset_value(&_3$$3, &possibleService);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_4$$3) {
			ZEPHIR_CALL_METHOD(&instance, this_ptr, "get", NULL, 0, &possibleService, &arguments);
			zephir_check_call_status();
			RETURN_CCTOR(&instance);
		}
	}
	if (zephir_start_with_str(&method_zv, SL("set"))) {
		zephir_memory_observe(&definition);
		_5$$5 = zephir_array_isset_long_fetch(&definition, &arguments, 0, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_5$$5) {
			ZVAL_LONG(&_6$$6, 3);
			ZEPHIR_INIT_VAR(&_7$$6);
			zephir_substr(&_7$$6, &method_zv, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_FUNCTION(&_8$$6, "lcfirst", &_2, 180, &_7$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_8$$6, &definition);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_CALL_CE_STATIC(&_9, phalcon_di_exception_ce, "undefinedMethod", NULL, 0, &method_zv);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_9, "phalcon/Di/Di.zep", 158);
	ZEPHIR_MM_RESTORE();
	return;
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
 * Resets the internal default DI
 */
PHP_METHOD(Phalcon_Di_Di, reset)
{
	zval __$null;

	ZVAL_NULL(&__$null);
	zephir_update_static_property_ce(phalcon_di_di_ce, ZEND_STRL("defaultContainer"), &__$null);
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
 * Attempts to register a service in the services container
 * Only is successful if a service hasn't been registered previously
 * with the same name
 */
PHP_METHOD(Phalcon_Di_Di, attempt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared, _1;
	zval name_zv, *definition, definition_sub, *shared_param = NULL, _0, _2, _3, _4, _5;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("services", 8, 1);
	}

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
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!shared_param) {
		shared = 0;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 175, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_value(&_0, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	if (shared) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 181, definition, &_3);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("services"), &name_zv, &_2);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 175, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_5);
	zephir_array_fetch(&_5, &_4, &name_zv, PH_NOISY, "phalcon/Di/Di.zep", 199);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&_5);
}

/**
 * Resolves the service based on its configuration
 */
PHP_METHOD(Phalcon_Di_Di, get)
{
	zval _11$$6, _20$$20;
	zend_bool _1, _4, _5$$4, _7$$4, _8$$4, _17$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *parameters = NULL, parameters_sub, __$null, service, isShared, instance, _0, _3, _9, _18, _2$$3, _6$$4, _10$$6, _12$$6, _13$$8, _14$$8, _15$$10, _16$$14, _19$$20, _21$$20;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&isShared);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_19$$20);
	ZVAL_UNDEF(&_21$$20);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_20$$20);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("services", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("sharedInstances", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("eventsManager", 13, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(name_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &name_param, &parameters);
	zephir_get_strval(&name, name_param);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	ZEPHIR_INIT_VAR(&service);
	ZVAL_NULL(&service);
	ZEPHIR_INIT_VAR(&isShared);
	ZVAL_BOOL(&isShared, 0);
	ZEPHIR_INIT_VAR(&instance);
	ZVAL_NULL(&instance);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_value(&_0, &name);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "resolveAlias", NULL, 182, &name);
		zephir_check_call_status();
		zephir_get_strval(&name, &_2$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_OBS_NVAR(&service);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 175, PH_NOISY_CC | PH_READONLY);
	_4 = zephir_array_isset_fetch(&service, &_3, &name, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_4) {
		ZEPHIR_CALL_METHOD(&isShared, &service, "isShared", NULL, 0);
		zephir_check_call_status();
		_5$$4 = zephir_is_true(&isShared);
		if (_5$$4) {
			ZEPHIR_OBS_NVAR(&instance);
			zephir_read_property_cached(&_6$$4, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
			_7$$4 = zephir_array_isset_fetch(&instance, &_6$$4, &name, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_5$$4 = _7$$4;
		}
		_8$$4 = _5$$4;
		if (_8$$4) {
			_8$$4 = Z_TYPE_P(&instance) != IS_NULL;
		}
		if (_8$$4) {
			RETURN_CCTOR(&instance);
		}
	}
	zephir_read_property_cached(&_9, this_ptr, _zephir_prop_3, 178, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_9) != IS_NULL) {
		zephir_read_property_cached(&_10$$6, this_ptr, _zephir_prop_3, 178, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_11$$6);
		zephir_create_array(&_11$$6, 2, 0);
		zephir_array_update_string(&_11$$6, SL("name"), &name, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_11$$6, SL("parameters"), parameters, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_12$$6);
		ZVAL_STRING(&_12$$6, "di:beforeServiceResolve");
		ZEPHIR_CALL_METHOD(&instance, &_10$$6, "fire", NULL, 0, &_12$$6, this_ptr, &_11$$6);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&instance) == IS_NULL) {
		if (Z_TYPE_P(&service) != IS_NULL) {

			/* try_start_1: */

				ZEPHIR_CALL_METHOD(&instance, &service, "resolve", NULL, 0, parameters, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);

			try_end_1:

			if (EG(exception)) {
				ZEPHIR_INIT_VAR(&_13$$8);
				ZVAL_OBJ(&_13$$8, EG(exception));
				Z_ADDREF_P(&_13$$8);
				ZEPHIR_INIT_VAR(&_14$$8);
				if (zephir_instance_of_ev(&_13$$8, phalcon_di_exception_serviceresolutionexception_ce)) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&_14$$8, &_13$$8);
					ZEPHIR_INIT_VAR(&_15$$10);
					object_init_ex(&_15$$10, phalcon_di_exceptions_servicecannotberesolved_ce);
					ZEPHIR_CALL_METHOD(NULL, &_15$$10, "__construct", NULL, 183, &name);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_15$$10, "phalcon/Di/Di.zep", 252);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_is_true(&isShared)) {
				zephir_update_property_array(this_ptr, SL("sharedInstances"), &name, &instance);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} else {
			if (UNEXPECTED(!(zephir_class_exists(&name, 1)))) {
				ZEPHIR_CALL_CE_STATIC(&_16$$14, phalcon_di_exception_ce, "serviceNotFound", NULL, 0, &name);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_16$$14, "phalcon/Di/Di.zep", 265);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_17$$13 = Z_TYPE_P(parameters) == IS_ARRAY;
			if (_17$$13) {
				_17$$13 = !(ZEPHIR_IS_EMPTY(parameters));
			}
			if (_17$$13) {
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
			ZEPHIR_CALL_METHOD(NULL, &instance, "setDI", NULL, 0, this_ptr);
			zephir_check_call_status();
		}
		if (zephir_instance_of_ev(&instance, phalcon_di_initializationawareinterface_ce)) {
			ZEPHIR_CALL_METHOD(NULL, &instance, "initialize", NULL, 0);
			zephir_check_call_status();
		}
	}
	zephir_read_property_cached(&_18, this_ptr, _zephir_prop_3, 178, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_18) != IS_NULL) {
		zephir_read_property_cached(&_19$$20, this_ptr, _zephir_prop_3, 178, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_20$$20);
		zephir_create_array(&_20$$20, 3, 0);
		zephir_array_update_string(&_20$$20, SL("name"), &name, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_20$$20, SL("parameters"), parameters, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_20$$20, SL("instance"), &instance, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_21$$20);
		ZVAL_STRING(&_21$$20, "di:afterServiceResolve");
		ZEPHIR_CALL_METHOD(NULL, &_19$$20, "fire", NULL, 0, &_21$$20, this_ptr, &_20$$20);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&instance);
}

/**
 * Return the alias based on a passed key. Returns an empty string if
 * the alias does not exist
 */
PHP_METHOD(Phalcon_Di_Di, getAlias)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, _0, _1, _3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC | PH_READONLY);
	_2 = zephir_array_isset_value(&_1, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch(&_0, &_3, &name_zv, PH_NOISY, "phalcon/Di/Di.zep", 315);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "");
	}
	RETURN_CCTOR(&_0);
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
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getService", NULL, 0, &name_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getDefinition", NULL, 0);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("services", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolveAlias", NULL, 182, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "has", NULL, 0, &name);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_di_exception_ce, "serviceNotFound", NULL, 0, &name);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Di/Di.zep", 347);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 175, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_4);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY, "phalcon/Di/Di.zep", 350);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&_4);
}

/**
 * Return the services registered in the DI
 */
PHP_METHOD(Phalcon_Di_Di, getServices)
{

	RETURN_MEMBER_TYPED(getThis(), "services", IS_ARRAY);
}

/**
 * Resolves a service, the resolved service is stored in the DI, subsequent
 * requests for this service will return the same instance
 */
PHP_METHOD(Phalcon_Di_Di, getShared)
{
	zend_bool _1, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *parameters = NULL, parameters_sub, __$null, instance, _0, _3, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("sharedInstances", 15, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(name_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &name_param, &parameters);
	zephir_get_strval(&name, name_param);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_value(&_0, &name);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "resolveAlias", NULL, 182, &name);
		zephir_check_call_status();
		zephir_get_strval(&name, &_2$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&instance);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 177, PH_NOISY_CC | PH_READONLY);
	_4 = zephir_array_isset_fetch(&instance, &_3, &name, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = _4;
	if (_5) {
		_5 = Z_TYPE_P(&instance) != IS_NULL;
	}
	if (_5) {
		RETURN_CCTOR(&instance);
	}
	ZEPHIR_CALL_METHOD(&instance, this_ptr, "get", NULL, 0, &name, parameters);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("sharedInstances"), &name, &instance);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&instance);
}

/**
 * Check whether the DI contains a service by a name
 */
PHP_METHOD(Phalcon_Di_Di, has)
{
	zend_bool _1, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _3, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("services", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_value(&_0, &name);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "resolveAlias", NULL, 182, &name);
		zephir_check_call_status();
		zephir_get_strval(&name, &_2$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 175, PH_NOISY_CC | PH_READONLY);
	_4 = zephir_array_isset_value(&_3, &name);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(_4);
}

/**
 * Check whether the DI has a cached shared instance for a service name.
 *
 * Unlike `has()`, which reports on the service *definition* registry,
 * this method reports only on the resolved-instance cache populated by
 * `getShared()`.
 */
PHP_METHOD(Phalcon_Di_Di, hasShared)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("sharedInstances", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolveAlias", NULL, 182, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 177, PH_NOISY_CC | PH_READONLY);
	_2 = zephir_array_isset_value(&_1, &name);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(_2);
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
	zephir_memory_observe(&filePath_zv);
	ZVAL_STR_COPY(&filePath_zv, filePath);
	ZEPHIR_INIT_VAR(&services);
	object_init_ex(&services, phalcon_config_adapter_php_ce);
	ZEPHIR_CALL_METHOD(NULL, &services, "__construct", NULL, 184, &filePath_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadFromConfig", NULL, 0, &services);
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
 * @phpstan-param config_callbacks|null $callbacks
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
	zephir_memory_observe(&filePath_zv);
	ZVAL_STR_COPY(&filePath_zv, filePath);
	if (!callbacks_param) {
		ZEPHIR_INIT_VAR(&callbacks);
	} else {
		zephir_get_arrval(&callbacks, callbacks_param);
	}
	ZEPHIR_INIT_VAR(&services);
	object_init_ex(&services, phalcon_config_adapter_yaml_ce);
	ZEPHIR_CALL_METHOD(NULL, &services, "__construct", NULL, 185, &filePath_zv, &callbacks);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadFromConfig", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getShared", NULL, 0, name);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setShared", NULL, 0, offset, value);
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
	zend_bool _10;
	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, alias, aliases, services, sharedInstances, target, _0, _1, *_3, _4, *_5, _9, _8$$3, _11$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&aliases);
	ZVAL_UNDEF(&services);
	ZVAL_UNDEF(&sharedInstances);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_11$$5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("services", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("sharedInstances", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&aliases, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 175, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&services, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 177, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sharedInstances, &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "resolveAlias", &_2, 182, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_unset(&services, &name, PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_unset(&sharedInstances, &name, PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &_0);
		_3 = &_4;
	} else {
		_3 = &_0;
	}
	zephir_is_iterable(_3, 0, "phalcon/Di/Di.zep", 602);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_3), _6, _7, _5)
		{
			ZEPHIR_INIT_NVAR(&alias);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&alias, _7);
			} else {
				ZVAL_LONG(&alias, _6);
			}
			ZEPHIR_INIT_NVAR(&target);
			ZVAL_COPY(&target, _5);
			ZEPHIR_CALL_METHOD(&_8$$3, this_ptr, "resolveAlias", &_2, 182, &target);
			zephir_check_call_status();
			if (ZEPHIR_IS_IDENTICAL(&name, &_8$$3)) {
				zephir_array_unset(&aliases, &alias, PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&alias, _3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&target, _3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "resolveAlias", &_2, 182, &target);
				zephir_check_call_status();
				if (ZEPHIR_IS_IDENTICAL(&name, &_11$$5)) {
					zephir_array_unset(&aliases, &alias, PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&target);
	ZEPHIR_INIT_NVAR(&alias);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 176, &aliases);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 175, &services);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 177, &sharedInstances);
	ZEPHIR_MM_RESTORE();
}

/**
 * Removes the cached shared instance for a service, leaving the service
 * definition intact so the next `getShared()` call rebuilds it.
 */
PHP_METHOD(Phalcon_Di_Di, removeShared)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, sharedInstances, service, _0, _1, _3$$3, _4$$4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&sharedInstances);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("sharedInstances", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("services", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 177, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sharedInstances, &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "resolveAlias", NULL, 182, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_unset(&sharedInstances, &name, PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 177, &sharedInstances);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 175, PH_NOISY_CC | PH_READONLY);
	_2 = zephir_array_isset_value(&_0, &name);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_1, 175, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&service);
		zephir_array_fetch(&service, &_3$$3, &name, PH_NOISY, "phalcon/Di/Di.zep", 632);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (zephir_instance_of_ev(&service, phalcon_di_service_ce)) {
			ZVAL_NULL(&_4$$4);
			ZEPHIR_CALL_METHOD(NULL, &service, "setSharedInstance", NULL, 0, &_4$$4);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Registers a service in the services container
 */
PHP_METHOD(Phalcon_Di_Di, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared, _1;
	zval *name_param = NULL, *definition, definition_sub, *shared_param = NULL, _0, _3, _4, _5, _6, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("services", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(name_param)
		Z_PARAM_ZVAL(definition)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(shared)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &name_param, &definition, &shared_param);
	zephir_get_strval(&name, name_param);
	if (!shared_param) {
		shared = 0;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_value(&_0, &name);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "resolveAlias", NULL, 182, &name);
		zephir_check_call_status();
		zephir_get_strval(&name, &_2$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, phalcon_di_service_ce);
	if (shared) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 181, definition, &_4);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("services"), &name, &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 175, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_6);
	zephir_array_fetch(&_6, &_5, &name, PH_NOISY, "phalcon/Di/Di.zep", 654);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&_6);
}

/**
 * Sets one or more aliases to the given name.
 *
 * @param array<array-key, mixed>|string $aliases
 *
 * @return Di
 * @throws Exception
 */
PHP_METHOD(Phalcon_Di_Di, setAlias)
{
	zend_bool _15, _9$$5, _10$$5, _18$$8, _19$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_8 = NULL, *_13 = NULL, *_17 = NULL, *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, *aliases, aliases_sub, alias, currentAliases, localAliases, _0, *_4, _5, *_6, _14, _2$$3, _3$$4, _7$$6, _11$$5, _12$$7, _16$$9, _20$$8, _21$$10;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&aliases_sub);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&currentAliases);
	ZVAL_UNDEF(&localAliases);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$10);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(aliases)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	aliases = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", &_1, 0, &name_zv);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_di_exception_ce, "serviceNotFound", NULL, 0, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Di/Di.zep", 670);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&currentAliases);
	zephir_read_property_cached(&currentAliases, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC);
	ZEPHIR_CPY_WRT(&localAliases, aliases);
	if (Z_TYPE_P(&localAliases) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_create_array(&_3$$4, 1, 0);
		zephir_array_fast_append(&_3$$4, &localAliases);
		ZEPHIR_CPY_WRT(&localAliases, &_3$$4);
	}
	if (Z_TYPE_P(&localAliases) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &localAliases);
		_4 = &_5;
	} else {
		_4 = &localAliases;
	}
	zephir_is_iterable(_4, 0, "phalcon/Di/Di.zep", 691);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4), _6)
		{
			ZEPHIR_INIT_NVAR(&alias);
			ZVAL_COPY(&alias, _6);
			if (Z_TYPE_P(&alias) != IS_STRING) {
				ZEPHIR_INIT_NVAR(&_7$$6);
				object_init_ex(&_7$$6, phalcon_di_exceptions_aliasnamemustbestring_ce);
				ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", &_8, 186);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$6, "phalcon/Di/Di.zep", 681);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_9$$5 = zephir_array_isset_value(&currentAliases, &alias);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_10$$5 = 1 == _9$$5;
			if (!(_10$$5)) {
				ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "has", &_1, 0, &alias);
				zephir_check_call_status();
				_10$$5 = ZEPHIR_IS_TRUE_IDENTICAL(&_11$$5);
			}
			if (_10$$5) {
				ZEPHIR_INIT_NVAR(&_12$$7);
				object_init_ex(&_12$$7, phalcon_di_exceptions_aliasalreadyinuse_ce);
				ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", &_13, 187, &alias);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_12$$7, "phalcon/Di/Di.zep", 685);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&currentAliases, &alias, &name_zv, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_15 = 1;
		while (1) {
			if (_15) {
				_15 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_14, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&alias, _4, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&alias) != IS_STRING) {
					ZEPHIR_INIT_NVAR(&_16$$9);
					object_init_ex(&_16$$9, phalcon_di_exceptions_aliasnamemustbestring_ce);
					ZEPHIR_CALL_METHOD(NULL, &_16$$9, "__construct", &_17, 186);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_16$$9, "phalcon/Di/Di.zep", 681);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_18$$8 = zephir_array_isset_value(&currentAliases, &alias);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_19$$8 = 1 == _18$$8;
				if (!(_19$$8)) {
					ZEPHIR_CALL_METHOD(&_20$$8, this_ptr, "has", &_1, 0, &alias);
					zephir_check_call_status();
					_19$$8 = ZEPHIR_IS_TRUE_IDENTICAL(&_20$$8);
				}
				if (_19$$8) {
					ZEPHIR_INIT_NVAR(&_21$$10);
					object_init_ex(&_21$$10, phalcon_di_exceptions_aliasalreadyinuse_ce);
					ZEPHIR_CALL_METHOD(NULL, &_21$$10, "__construct", &_22, 187, &alias);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_21$$10, "phalcon/Di/Di.zep", 685);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&currentAliases, &alias, &name_zv, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&alias);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 176, &currentAliases);
	RETURN_THIS();
}

/**
 * Sets the internal event manager
 */
PHP_METHOD(Phalcon_Di_Di, setInternalEventsManager)
{
	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 178, eventsManager);
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
	if (UNEXPECTED(EG(exception))) {
		return;
	}
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
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZVAL_BOOL(&_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &name_zv, definition, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Loads services from a Config object.
 */
PHP_METHOD(Phalcon_Di_Di, loadFromConfig)
{
	zend_bool _12, _5$$3, _6$$3, _7$$3, _13$$4, _14$$4, _15$$4;
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, services, name, service, *_0, _1, *_2, _11, _8$$3, _9$$3, _16$$4, _17$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&services);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(config, phalcon_config_configinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_CALL_METHOD(&services, config, "toArray", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&services) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_string_to_char_array(&_1, &services);
		_0 = &_1;
	} else {
		_0 = &services;
	}
	zephir_is_iterable(_0, 0, "phalcon/Di/Di.zep", 737);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_0), _3, _4, _2)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&service);
			ZVAL_COPY(&service, _2);
			_5$$3 = Z_TYPE_P(&service) == IS_ARRAY;
			if (_5$$3) {
				_6$$3 = zephir_array_isset_value_string(&service, SL("shared"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_5$$3 = _6$$3;
			}
			_7$$3 = _5$$3;
			if (_7$$3) {
				ZEPHIR_OBS_NVAR(&_8$$3);
				zephir_array_fetch_string(&_8$$3, &service, SL("shared"), PH_NOISY, "phalcon/Di/Di.zep", 735);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_7$$3 = zephir_is_true(&_8$$3);
			}
			ZVAL_BOOL(&_9$$3, _7$$3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_10, 0, &name, &service, &_9$$3);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _0, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, _0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, _0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&service, _0, "current", NULL, 0);
			zephir_check_call_status();
				_13$$4 = Z_TYPE_P(&service) == IS_ARRAY;
				if (_13$$4) {
					_14$$4 = zephir_array_isset_value_string(&service, SL("shared"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_13$$4 = _14$$4;
				}
				_15$$4 = _13$$4;
				if (_15$$4) {
					ZEPHIR_OBS_NVAR(&_16$$4);
					zephir_array_fetch_string(&_16$$4, &service, SL("shared"), PH_NOISY, "phalcon/Di/Di.zep", 735);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_15$$4 = zephir_is_true(&_16$$4);
				}
				ZVAL_BOOL(&_17$$4, _15$$4);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_10, 0, &name, &service, &_17$$4);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&service);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();
}

/**
 * Resolve an alias to its actual service name
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Di_Di, resolveAlias)
{
	zend_bool _1, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, __$true, current, seen, _0, _5$$3, _6$$3, _3$$4;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&seen);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_3$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CPY_WRT(&current, &name_zv);
	ZEPHIR_INIT_VAR(&seen);
	array_init(&seen);
	while (1) {
		zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC | PH_READONLY);
		_1 = zephir_array_isset_value(&_0, &current);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_1)) {
			break;
		}
		_2$$3 = zephir_array_isset_value(&seen, &current);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_2$$3) {
			ZEPHIR_INIT_NVAR(&_3$$4);
			object_init_ex(&_3$$4, phalcon_di_exceptions_circularaliasreference_ce);
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", &_4, 188, &name_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$4, "phalcon/Di/Di.zep", 753);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&seen, &current, &__$true, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_0, 176, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_6$$3);
		zephir_array_fetch(&_6$$3, &_5$$3, &current, PH_NOISY, "phalcon/Di/Di.zep", 756);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&current, &_6$$3);
	}
	RETURN_CCTOR(&current);
}

