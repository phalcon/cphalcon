
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

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_adr_application_ce, SL("actionDirectory"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_adr_application_ce, SL("baseNamespace"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_application_ce, SL("container"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Container\\Container"));
	}

	/**
	 * @var array<string, string[]>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_adr_application_ce, SL("middlewareMap"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_adr_application_ce, SL("wordSeparator"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

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

		ZEPHIR_CALL_METHOD(&_1$$3, &_0$$3, "addprovider", NULL, 303, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(container, &_1$$3, "newcontainer", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 330, container);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 330, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 330, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&definition, &_0, "set", NULL, 0, &className_zv, &className_zv);
	zephir_check_call_status();
	zephir_is_iterable(&parameters, 0, "phalcon/ADR/Application.zep", 90);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 330, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 330, PH_NOISY_CC | PH_READONLY);
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
	zend_bool _25$$7;
	zend_string *_20$$7;
	zend_ulong _19$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_22 = NULL, *_23 = NULL, *_27 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, attributes, dispatcher, events, exception, key, match, response, router, value, _0, _1, _2, _3, _4, _6, _8, _10, _38, _5$$3, _7$$4, _9$$5, _11$$6, _12$$8, _13$$7, _14$$7, _15$$7, _16$$7, _17$$7, *_18$$7, _24$$7, _28$$7, _29$$7, _21$$9, _26$$10, _30$$12, _31$$12, _32$$12, _33$$11, _34$$11, _35$$13, _36$$13, _37$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&dispatcher);
	ZVAL_UNDEF(&events);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$11);
	ZVAL_UNDEF(&_34$$11);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_37$$13);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("baseNamespace", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("middlewareMap", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("actionDirectory", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("wordSeparator", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_contracts_http_attributerequest_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 330, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Contracts\\ADR\\Router\\Router");
	ZEPHIR_CALL_METHOD(&router, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 330, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Contracts\\ADR\\Dispatcher");
	ZEPHIR_CALL_METHOD(&dispatcher, &_2, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 330, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Contracts\\Events\\Manager");
	ZEPHIR_CALL_METHOD(&events, &_3, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 331, PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_4, "")) {
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_1, 331, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &router, "setbasenamespace", NULL, 0, &_5$$3);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_2, 332, PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_6))) {
		zephir_read_property_cached(&_7$$4, this_ptr, _zephir_prop_2, 332, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &router, "setmiddlewaremap", NULL, 0, &_7$$4);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_3, 333, PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_8, "")) {
		zephir_read_property_cached(&_9$$5, this_ptr, _zephir_prop_3, 333, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &router, "setactiondirectory", NULL, 0, &_9$$5);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_10, this_ptr, _zephir_prop_4, 334, PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_10, "")) {
		zephir_read_property_cached(&_11$$6, this_ptr, _zephir_prop_4, 334, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &router, "setwordseparator", NULL, 0, &_11$$6);
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
			ZEPHIR_INIT_VAR(&_12$$8);
			object_init_ex(&_12$$8, phalcon_adr_exceptions_routenotfound_ce);
			ZEPHIR_CALL_METHOD(NULL, &_12$$8, "__construct", NULL, 304);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(&_12$$8, "phalcon/ADR/Application.zep", 157);
			goto try_end_1;

		}
		zephir_read_property_cached(&_13$$7, this_ptr, _zephir_prop_0, 330, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_15$$7);
		ZVAL_STRING(&_15$$7, "Phalcon\\Contracts\\ADR\\Router\\AttributeFilter");
		ZEPHIR_CALL_METHOD(&_14$$7, &_13$$7, "get", NULL, 0, &_15$$7);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_16$$7, &match, "getaction", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_17$$7, &match, "getattributes", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&attributes, &_14$$7, "filter", NULL, 0, &_16$$7, &_17$$7);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_is_iterable(&attributes, 0, "phalcon/ADR/Application.zep", 168);
		if (Z_TYPE_P(&attributes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _19$$7, _20$$7, _18$$7)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_20$$7 != NULL) { 
					ZVAL_STR_COPY(&key, _20$$7);
				} else {
					ZVAL_LONG(&key, _19$$7);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _18$$7);
				ZEPHIR_CALL_METHOD(&_21$$9, request, "getattributes", &_22, 0);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CALL_METHOD(NULL, &_21$$9, "set", &_23, 0, &key, &value);
				zephir_check_call_status_or_jump(try_end_1);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
			zephir_check_call_status();
			_25$$7 = 1;
			while (1) {
				if (_25$$7) {
					_25$$7 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_24$$7, &attributes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_24$$7)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_26$$10, request, "getattributes", &_27, 0);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CALL_METHOD(NULL, &_26$$10, "set", &_23, 0, &key, &value);
					zephir_check_call_status_or_jump(try_end_1);
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZEPHIR_CALL_METHOD(&_28$$7, &match, "getaction", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_29$$7, &match, "getmiddleware", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&response, &dispatcher, "dispatch", NULL, 0, &_28$$7, request, &_29$$7);
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

				zephir_read_property_cached(&_30$$12, this_ptr, _zephir_prop_0, 330, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_32$$12);
				ZVAL_STRING(&_32$$12, "Phalcon\\ADR\\ErrorResponder");
				ZEPHIR_CALL_METHOD(&_31$$12, &_30$$12, "get", NULL, 0, &_32$$12);
				zephir_check_call_status_or_jump(try_end_2);
				ZEPHIR_INIT_NVAR(&_32$$12);
				object_init_ex(&_32$$12, phalcon_http_response_ce);
				ZEPHIR_CALL_METHOD(NULL, &_32$$12, "__construct", NULL, 305);
				zephir_check_call_status_or_jump(try_end_2);
				ZEPHIR_CALL_METHOD(&response, &_31$$12, "handle", NULL, 0, request, &_32$$12, &exception);
				zephir_check_call_status_or_jump(try_end_2);

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_VAR(&_33$$11);
				ZVAL_OBJ(&_33$$11, EG(exception));
				Z_ADDREF_P(&_33$$11);
				ZEPHIR_INIT_VAR(&_34$$11);
				if (zephir_is_instance_of(&_33$$11, SL("Throwable"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&_34$$11, &_33$$11);
					ZEPHIR_INIT_NVAR(&response);
					object_init_ex(&response, phalcon_http_response_ce);
					ZEPHIR_CALL_METHOD(NULL, &response, "__construct", NULL, 305);
					zephir_check_call_status();
					ZVAL_LONG(&_36$$13, 500);
					ZEPHIR_CALL_METHOD(&_35$$13, &response, "setstatuscode", NULL, 306, &_36$$13);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(&_37$$13);
					ZVAL_STRING(&_37$$13, "Internal Server Error");
					ZEPHIR_CALL_METHOD(NULL, &_35$$13, "setcontent", NULL, 0, &_37$$13);
					zephir_check_call_status();
				}
			}
		}
	}
	ZEPHIR_INIT_VAR(&_38);
	ZVAL_STRING(&_38, "application:afterHandle");
	ZEPHIR_CALL_METHOD(NULL, &events, "fire", NULL, 0, &_38, this_ptr, &response);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 332, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_0, &prefix_zv)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 332, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&list);
		zephir_array_fetch(&list, &_1$$3, &prefix_zv, PH_NOISY, "phalcon/ADR/Application.zep", 200);
	}
	zephir_array_append(&list, &guard_zv, PH_SEPARATE, "phalcon/ADR/Application.zep", 203);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 330, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &name_zv, definition);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Set the filesystem root that backs the base namespace.
 */
PHP_METHOD(Phalcon_ADR_Application, setActionDirectory)
{
	zval actionDirectory_zv;
	zend_string *actionDirectory = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionDirectory_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("actionDirectory", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionDirectory)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&actionDirectory_zv, actionDirectory);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 333, &actionDirectory_zv);
	RETURN_THISW();
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 331, &baseNamespace_zv);
	RETURN_THISW();
}

/**
 * Set the single delimiter between words in a path segment.
 */
PHP_METHOD(Phalcon_ADR_Application, setWordSeparator)
{
	zval wordSeparator_zv;
	zend_string *wordSeparator = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&wordSeparator_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("wordSeparator", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(wordSeparator)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&wordSeparator_zv, wordSeparator);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 334, &wordSeparator_zv);
	RETURN_THISW();
}

