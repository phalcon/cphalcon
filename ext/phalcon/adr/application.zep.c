
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "Zend/zend_closures.h"
#include "kernel/exception.h"
#include "kernel/array.h"


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
 * ADR composition root. Owns (or accepts) a container, exposes a small
 * registration surface that hides the container's definition API, configures
 * the convention router, and handles the request through the ADR flow.
 *
 * When no container is supplied one is created with the ADR defaults
 * (`AdrProvider`) registered. Type-hinted dependencies autowire; only scalar
 * parameters need to be declared via `define()`.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Application)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR, Application, phalcon, adr_application, phalcon_adr_application_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_adr_application_ce, SL("baseNamespace"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var Container
	 */
	zend_declare_property_null(phalcon_adr_application_ce, SL("container"), ZEND_ACC_PROTECTED);
	/**
	 * @var array<string, string[]>
	 */
	zend_declare_property_null(phalcon_adr_application_ce, SL("middlewareMap"), ZEND_ACC_PROTECTED);
	phalcon_adr_application_ce->create_object = zephir_init_properties_Phalcon_ADR_Application;

	zend_class_implements(phalcon_adr_application_ce, 1, phalcon_contracts_adr_application_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Application, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container = NULL, container_sub, __$null, _0$$3, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(container, phalcon_container_container_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &container);
	if (!container) {
		container = &container_sub;
		ZEPHIR_CPY_WRT(container, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(container);
	}
	if (Z_TYPE_P(container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_container_containerfactory_ce);
		if (zephir_has_constructor(&_0$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_adr_container_adrprovider_ce);
		if (zephir_has_constructor(&_2$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_CALL_METHOD(&_1$$3, &_0$$3, "addprovider", NULL, 301, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(container, &_1$$3, "newcontainer", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 329, container);
	ZEPHIR_MM_RESTORE();
}

/**
 * Bind an interface to a concrete class.
 */
PHP_METHOD(Phalcon_ADR_Application, bind)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval interfaceName_zv, concrete_zv, _0;
	zend_string *interfaceName = NULL, *concrete = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interfaceName_zv);
	ZVAL_UNDEF(&concrete_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(interfaceName)
		Z_PARAM_STR(concrete)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&interfaceName_zv);
	ZVAL_STR_COPY(&interfaceName_zv, interfaceName);
	zephir_memory_observe(&concrete_zv);
	ZVAL_STR_COPY(&concrete_zv, concrete);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 329, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "bind", NULL, 0, &interfaceName_zv, &concrete_zv);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Register a class together with explicit values for its constructor
 * parameters. Type-hinted dependencies autowire; only the supplied
 * (usually scalar) parameters are declared. Lazy values (e.g.
 * `new Phalcon\Container\Resolver\Lazy\Env(...)`) may be passed as values.
 */
PHP_METHOD(Phalcon_ADR_Application, define)
{
	zend_bool _6;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval className_zv, *parameters_param = NULL, definition, param, value, _0, *_1, _5;
	zend_string *className = NULL, *_3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&parameters);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(className)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		parameters_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 329, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&definition, &_0, "set", NULL, 0, &className_zv, &className_zv);
	zephir_check_call_status();
	zephir_is_iterable(&parameters, 0, "phalcon/ADR/Application.zep", 94);
	if (Z_TYPE_P(&parameters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parameters), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&param);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&param, _3);
			} else {
				ZVAL_LONG(&param, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_CALL_METHOD(NULL, &definition, "setargument", &_4, 0, &param, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parameters, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &parameters, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &parameters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&param, &parameters, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &parameters, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &definition, "setargument", &_7, 0, &param, &value);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&param);
	RETURN_THIS();
}

/**
 * Register a post-build extender (decorator) for a service.
 */
PHP_METHOD(Phalcon_ADR_Application, extend)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, *extender, extender_sub, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&extender_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJECT_OF_CLASS(extender, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	extender = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 329, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "extend", NULL, 0, &name_zv, extender);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Register a factory closure for a service.
 */
PHP_METHOD(Phalcon_ADR_Application, factory)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, *factory, factory_sub, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJECT_OF_CLASS(factory, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	factory = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 329, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &name_zv, factory);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Returns the underlying container for definition-level access.
 */
PHP_METHOD(Phalcon_ADR_Application, getContainer)
{

	RETURN_MEMBER(getThis(), "container");
}

/**
 * Routes the request, writes the matched attributes onto it, dispatches
 * the Action and returns the response. A single try/catch routes any error
 * through the error responder; if that itself fails, a bare 500 is returned
 * so nothing escapes uncaught.
 */
PHP_METHOD(Phalcon_ADR_Application, handle)
{
	zend_bool _17$$5;
	zend_string *_12$$5;
	zend_ulong _11$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL, *_15 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, router, dispatcher, events, match, response, key, value, exception, _0, _1, _2, _3, _4, _6, _30, _5$$3, _7$$4, _8$$6, _9$$5, *_10$$5, _16$$5, _20$$5, _21$$5, _13$$7, _18$$8, _22$$10, _23$$10, _24$$10, _25$$9, _26$$9, _27$$11, _28$$11, _29$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&dispatcher);
	ZVAL_UNDEF(&events);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_29$$11);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("baseNamespace", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("middlewareMap", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_contracts_http_attributerequest_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 329, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Contracts\\ADR\\Router\\Router");
	ZEPHIR_CALL_METHOD(&router, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 329, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Contracts\\ADR\\Dispatcher");
	ZEPHIR_CALL_METHOD(&dispatcher, &_2, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 329, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Contracts\\Events\\Manager");
	ZEPHIR_CALL_METHOD(&events, &_3, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 330, PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_4, "")) {
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_1, 330, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &router, "setbasenamespace", NULL, 0, &_5$$3);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_2, 331, PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_6)) {
		zephir_read_property_cached(&_7$$4, this_ptr, _zephir_prop_2, 331, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &router, "setmiddlewaremap", NULL, 0, &_7$$4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "application:beforeHandle");
	ZEPHIR_CALL_METHOD(NULL, &events, "fire", NULL, 0, &_1, this_ptr, request);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&match, &router, "match", NULL, 0, request);
		zephir_check_call_status_or_jump(try_end_1);
		if (Z_TYPE_P(&match) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_8$$6);
			object_init_ex(&_8$$6, phalcon_adr_exceptions_routenotfound_ce);
			ZEPHIR_CALL_METHOD(NULL, &_8$$6, "__construct", NULL, 302);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(&_8$$6, "phalcon/ADR/Application.zep", 152);
			goto try_end_1;

		}
		ZEPHIR_CALL_METHOD(&_9$$5, &match, "getattributes", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_is_iterable(&_9$$5, 0, "phalcon/ADR/Application.zep", 159);
		if (Z_TYPE_P(&_9$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_9$$5), _11$$5, _12$$5, _10$$5)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_12$$5 != NULL) { 
					ZVAL_STR_COPY(&key, _12$$5);
				} else {
					ZVAL_LONG(&key, _11$$5);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _10$$5);
				ZEPHIR_CALL_METHOD(&_13$$7, request, "getattributes", &_14, 0);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CALL_METHOD(NULL, &_13$$7, "set", &_15, 0, &key, &value);
				zephir_check_call_status_or_jump(try_end_1);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_9$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			_17$$5 = 1;
			while (1) {
				if (_17$$5) {
					_17$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_9$$5, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_16$$5, &_9$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_16$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &_9$$5, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &_9$$5, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_18$$8, request, "getattributes", &_19, 0);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CALL_METHOD(NULL, &_18$$8, "set", &_15, 0, &key, &value);
					zephir_check_call_status_or_jump(try_end_1);
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZEPHIR_CALL_METHOD(&_20$$5, &match, "getaction", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_21$$5, &match, "getmiddleware", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&response, &dispatcher, "dispatch", NULL, 0, &_20$$5, request, &_21$$5);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_OBJ(&_1, EG(exception));
		Z_ADDREF_P(&_1);
		if (zephir_is_instance_of(&_1, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&exception, &_1);

			/* try_start_2: */

				zephir_read_property_cached(&_22$$10, this_ptr, _zephir_prop_0, 329, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_24$$10);
				ZVAL_STRING(&_24$$10, "Phalcon\\ADR\\ErrorResponder");
				ZEPHIR_CALL_METHOD(&_23$$10, &_22$$10, "get", NULL, 0, &_24$$10);
				zephir_check_call_status_or_jump(try_end_2);
				ZEPHIR_INIT_NVAR(&_24$$10);
				object_init_ex(&_24$$10, phalcon_http_response_ce);
				ZEPHIR_CALL_METHOD(NULL, &_24$$10, "__construct", NULL, 303);
				zephir_check_call_status_or_jump(try_end_2);
				ZEPHIR_CALL_METHOD(&response, &_23$$10, "handle", NULL, 0, request, &_24$$10, &exception);
				zephir_check_call_status_or_jump(try_end_2);

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_VAR(&_25$$9);
				ZVAL_OBJ(&_25$$9, EG(exception));
				Z_ADDREF_P(&_25$$9);
				ZEPHIR_INIT_VAR(&_26$$9);
				if (zephir_is_instance_of(&_25$$9, SL("Throwable"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&_26$$9, &_25$$9);
					ZEPHIR_INIT_NVAR(&response);
					object_init_ex(&response, phalcon_http_response_ce);
					ZEPHIR_CALL_METHOD(NULL, &response, "__construct", NULL, 303);
					zephir_check_call_status();
					ZVAL_LONG(&_28$$11, 500);
					ZEPHIR_CALL_METHOD(&_27$$11, &response, "setstatuscode", NULL, 304, &_28$$11);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(&_29$$11);
					ZVAL_STRING(&_29$$11, "Internal Server Error");
					ZEPHIR_CALL_METHOD(NULL, &_27$$11, "setcontent", NULL, 0, &_29$$11);
					zephir_check_call_status();
				}
			}
		}
	}
	ZEPHIR_INIT_VAR(&_30);
	ZVAL_STRING(&_30, "application:afterHandle");
	ZEPHIR_CALL_METHOD(NULL, &events, "fire", NULL, 0, &_30, this_ptr, &response);
	zephir_check_call_status();
	RETURN_CCTOR(&response);
}

/**
 * Attach a guard (middleware) to every Action under a namespace prefix.
 */
PHP_METHOD(Phalcon_ADR_Application, secureWith)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval guard_zv, prefix_zv, list, _0, _1$$3;
	zend_string *guard = NULL, *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&guard_zv);
	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&list);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("middlewareMap", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(guard)
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&guard_zv);
	ZVAL_STR_COPY(&guard_zv, guard);
	zephir_memory_observe(&prefix_zv);
	ZVAL_STR_COPY(&prefix_zv, prefix);
	ZEPHIR_INIT_VAR(&list);
	array_init(&list);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 331, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_0, &prefix_zv)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 331, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&list);
		zephir_array_fetch(&list, &_1$$3, &prefix_zv, PH_NOISY, "phalcon/ADR/Application.zep", 193);
	}
	zephir_array_append(&list, &guard_zv, PH_SEPARATE, "phalcon/ADR/Application.zep", 196);
	zephir_update_property_array(this_ptr, SL("middlewareMap"), &prefix_zv, &list);
	RETURN_THIS();
}

/**
 * Register a service with a raw definition (class-string, closure or value).
 */
PHP_METHOD(Phalcon_ADR_Application, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, *definition, definition_sub, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(definition)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 329, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &name_zv, definition);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Set the base namespace the convention router derives Actions from.
 */
PHP_METHOD(Phalcon_ADR_Application, setBaseNamespace)
{
	zval baseNamespace_zv;
	zend_string *baseNamespace = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&baseNamespace_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("baseNamespace", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(baseNamespace)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&baseNamespace_zv, baseNamespace);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 330, &baseNamespace_zv);
	RETURN_THISW();
}

zend_object *zephir_init_properties_Phalcon_ADR_Application(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("middlewareMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("middlewareMap"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

