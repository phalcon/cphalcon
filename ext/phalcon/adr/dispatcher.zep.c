
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
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
 * Resolves the Action (and middleware) through the container, wraps it in the
 * pipeline and runs it, firing the `pipeline:*` events. Global middleware is
 * resolved once and cached; only route middleware resolves per request.
 *
 * The container resolution is the one deliberate Service Locator: it uses the
 * resolve-only `IocContainer` contract, so a container swap is a two-method
 * adapter. Everything else is constructor-injected.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Dispatcher)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR, Dispatcher, phalcon, adr_dispatcher, phalcon_adr_dispatcher_method_entry, ZEND_ACC_FINAL_CLASS);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_dispatcher_ce, SL("container"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Contracts\\Container\\Ioc\\IocContainer"));
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_dispatcher_ce, SL("events"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Contracts\\Events\\Manager"));
	}

	/**
	 * @var array
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_adr_dispatcher_ce, SL("globalMiddleware"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var array|null
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_adr_dispatcher_ce, SL("resolvedGlobal"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY|MAY_BE_NULL, NULL, 0);
	}

	zend_class_implements(phalcon_adr_dispatcher_ce, 1, phalcon_contracts_adr_dispatcher_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Dispatcher, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval globalMiddleware;
	zval *container, container_sub, *events, events_sub, *globalMiddleware_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&events_sub);
	ZVAL_UNDEF(&globalMiddleware);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("events", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("globalMiddleware", 16, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_contracts_container_ioc_ioccontainer_ce)
		Z_PARAM_OBJECT_OF_CLASS(events, phalcon_contracts_events_manager_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(globalMiddleware, globalMiddleware_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &container, &events, &globalMiddleware_param);
	if (!globalMiddleware_param) {
		ZEPHIR_INIT_VAR(&globalMiddleware);
		array_init(&globalMiddleware);
	} else {
		zephir_get_arrval(&globalMiddleware, globalMiddleware_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 338, container);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 339, events);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 340, &globalMiddleware);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_ADR_Dispatcher, dispatch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval routeMiddleware;
	zval actionClass_zv, *request, request_sub, *routeMiddleware_param = NULL, action, middleware, terminal, pipeline, response, _0, _2, _3, _4, _5, _6, _7, _1$$3;
	zend_string *actionClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionClass_zv);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&middleware);
	ZVAL_UNDEF(&terminal);
	ZVAL_UNDEF(&pipeline);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&routeMiddleware);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("events", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(actionClass)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_contracts_http_attributerequest_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(routeMiddleware, routeMiddleware_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	request = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		routeMiddleware_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&actionClass_zv);
	ZVAL_STR_COPY(&actionClass_zv, actionClass);
	if (!routeMiddleware_param) {
		ZEPHIR_INIT_VAR(&routeMiddleware);
		array_init(&routeMiddleware);
	} else {
		zephir_get_arrval(&routeMiddleware, routeMiddleware_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 338, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&action, &_0, "getservice", NULL, 0, &actionClass_zv);
	zephir_check_call_status();
	if (!(zephir_instance_of_ev(&action, phalcon_contracts_adr_action_ce))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_adr_exceptions_notanaction_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 307, &actionClass_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/ADR/Dispatcher.zep", 66);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "resolveglobal", NULL, 308);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "resolveall", NULL, 309, &routeMiddleware);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&middleware);
	zephir_fast_array_merge(&middleware, &_2, &_3);
	ZEPHIR_INIT_VAR(&terminal);
	object_init_ex(&terminal, phalcon_adr_eventfulhandler_ce);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 339, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &terminal, "__construct", NULL, 310, &action, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&pipeline);
	object_init_ex(&pipeline, phalcon_adr_pipeline_ce);
	ZEPHIR_CALL_METHOD(NULL, &pipeline, "__construct", NULL, 311, &middleware, &terminal);
	zephir_check_call_status();
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 339, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "pipeline:beforeDispatch");
	ZEPHIR_CALL_METHOD(NULL, &_5, "fire", NULL, 0, &_6, this_ptr, request);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &pipeline, "__invoke", NULL, 312, request);
	zephir_check_call_status();
	zephir_read_property_cached(&_7, this_ptr, _zephir_prop_1, 339, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "pipeline:afterDispatch");
	ZEPHIR_CALL_METHOD(NULL, &_7, "fire", NULL, 0, &_6, this_ptr, &response);
	zephir_check_call_status();
	RETURN_CCTOR(&response);
}

PHP_METHOD(Phalcon_ADR_Dispatcher, resolveAll)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *classes_param = NULL, className, *_0, _3, _1$$3, _2$$3, _5$$4, _6$$4;
	zval classes, result;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(classes, classes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &classes_param);
	zephir_get_arrval(&classes, classes_param);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&classes, 0, "phalcon/ADR/Dispatcher.zep", 91);
	if (Z_TYPE_P(&classes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&classes), _0)
		{
			ZEPHIR_INIT_NVAR(&className);
			ZVAL_COPY(&className, _0);
			zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 338, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_2$$3, &_1$$3, "getservice", NULL, 0, &className);
			zephir_check_call_status();
			zephir_array_append(&result, &_2$$3, PH_SEPARATE, "phalcon/ADR/Dispatcher.zep", 88);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &classes, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &classes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &classes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&className, &classes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property_cached(&_5$$4, this_ptr, _zephir_prop_0, 338, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_6$$4, &_5$$4, "getservice", NULL, 0, &className);
				zephir_check_call_status();
				zephir_array_append(&result, &_6$$4, PH_SEPARATE, "phalcon/ADR/Dispatcher.zep", 88);
		}
	}
	ZEPHIR_INIT_NVAR(&className);
	RETURN_CTOR(&result);
}

PHP_METHOD(Phalcon_ADR_Dispatcher, resolveGlobal)
{
	zval _0, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("resolvedGlobal", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("globalMiddleware", 16, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 341, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_1, 340, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "resolveall", NULL, 309, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 341, &_1$$3);
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "resolvedGlobal", IS_ARRAY);
}

