
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */
/**
 * Shared enforcement algorithm for the Cli, Mvc and Micro auth listeners.
 * The subclass provides the action name and context from its event source,
 * the action-kind label used in the access-denied exception, and (Mvc only)
 * a forward handler for Access::redirectTo().
 *
 * Enforcement is fail-open: when the manager has no active access
 * (Manager::getAccess() === null) every dispatch is allowed. A policy
 * activated via Manager::access() persists across forwards and nested
 * dispatches in the same request until it is replaced.
 *
 * @phpstan-import-type AccessContext from Access
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_AbstractAuthDispatcherListener)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth, AbstractAuthDispatcherListener, phalcon, auth_abstractauthdispatcherlistener, phalcon_auth_abstractauthdispatcherlistener_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var Manager
	 */
	zend_declare_property_null(phalcon_auth_abstractauthdispatcherlistener_ce, SL("manager"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_AbstractAuthDispatcherListener, __construct)
{
	zval *manager, manager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(manager, phalcon_contracts_auth_manager_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &manager);
	zephir_update_property_zval(this_ptr, ZEND_STRL("manager"), manager);
}

/**
 * Returns the kind label used by AccessDenied (e.g. 'task', 'action',
 * 'route').
 */
PHP_METHOD(Phalcon_Auth_AbstractAuthDispatcherListener, getActionType)
{
}

/**
 * Runs the access check for the given action name. Returns true when
 * the dispatch should proceed, false when a forward was issued, and
 * throws when access is denied without a redirect target.
 *
 * The guard is fetched only when an access is active, so the no-op
 * path works without a default guard.
 *
 * @phpstan-param AccessContext $context
 * @phpstan-param callable|null $forwardHandler
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_AbstractAuthDispatcherListener, enforce)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval actionName_zv, *context_param = NULL, *forwardHandler = NULL, forwardHandler_sub, __$null, access, target, _0, _1, _2, _3, _4, _5;
	zend_string *actionName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName_zv);
	ZVAL_UNDEF(&forwardHandler_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&context);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(actionName)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(context, context_param)
		Z_PARAM_ZVAL_OR_NULL(forwardHandler)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		forwardHandler = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&actionName_zv);
	ZVAL_STR_COPY(&actionName_zv, actionName);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}
	if (!forwardHandler) {
		forwardHandler = &forwardHandler_sub;
		forwardHandler = &__$null;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&access, &_0, "getaccess", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&access) == IS_NULL) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "guard", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &access, "isallowed", NULL, 0, &_3, &actionName_zv, &context);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(forwardHandler) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&target, &access, "redirectto", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&target) != IS_NULL) {
			ZEPHIR_CALL_ZVAL_FUNCTION(NULL, forwardHandler, NULL, 0, &target);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, phalcon_auth_exceptions_accessdenied_ce);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getactiontype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 80, &_5, &actionName_zv);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_4, "phalcon/Auth/AbstractAuthDispatcherListener.zep", 89);
	ZEPHIR_MM_RESTORE();
	return;
}

