
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Listener that enforces the active Phalcon\Auth access gate on each Micro
 * route execution. Attach to the events manager:
 *
 *   $eventsManager->attach('micro', new AuthMicroListener($manager));
 *   $app->setEventsManager($eventsManager);
 *
 * The action name is the matched route's name, falling back to the route
 * pattern when the route is unnamed. The ACL component is the configured
 * component name (default 'Micro'). redirectTo() is ignored - Micro has no
 * forward mechanism.
 *
 * No-op when no active access has been set on the manager.
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Micro_AuthMicroListener)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Micro, AuthMicroListener, phalcon, auth_micro_authmicrolistener, phalcon_auth_abstractauthdispatcherlistener_ce, phalcon_auth_micro_authmicrolistener_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_auth_micro_authmicrolistener_ce, SL("componentName"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Micro_AuthMicroListener, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *componentName = NULL;
	zval *manager, manager_sub, componentName_zv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager_sub);
	ZVAL_UNDEF(&componentName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(manager, phalcon_contracts_auth_manager_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(componentName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	manager = ZEND_CALL_ARG(execute_data, 1);
	if (!componentName) {
		componentName = zend_string_init(ZEND_STRL("Micro"), 0);
		zephir_memory_observe(&componentName_zv);
		ZVAL_STR(&componentName_zv, componentName);
	} else {
		zephir_memory_observe(&componentName_zv);
	ZVAL_STR_COPY(&componentName_zv, componentName);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_auth_micro_authmicrolistener_ce, getThis(), "__construct", NULL, 0, manager);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("componentName"), &componentName_zv);
	ZEPHIR_MM_RESTORE();
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Micro_AuthMicroListener, beforeExecuteRoute)
{
	zval _2;
	zval _1;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *application, application_sub, actionName, route, router, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&application_sub);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(event, phalcon_events_event_ce)
		Z_PARAM_OBJECT_OF_CLASS(application, phalcon_mvc_micro_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &event, &application);
	ZEPHIR_CALL_METHOD(&router, application, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "getmatchedroute", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&route) == IS_NULL) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&actionName, &route, "getname", NULL, 0);
	zephir_check_call_status();
	_0 = Z_TYPE_P(&actionName) == IS_NULL;
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING_IDENTICAL(&actionName, "");
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&actionName, &route, "getpattern", NULL, 0);
		zephir_check_call_status();
	}
	zephir_cast_to_string(&_1, &actionName);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_memory_observe(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("componentName"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("handler"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_4, &router, "getparams", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL("params"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "enforce", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Micro_AuthMicroListener, getActionType)
{

	RETURN_STRING("route");
}

