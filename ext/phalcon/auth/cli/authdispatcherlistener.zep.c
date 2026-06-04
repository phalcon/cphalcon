
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Auth_Cli_AuthDispatcherListener)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Cli, AuthDispatcherListener, phalcon, auth_cli_authdispatcherlistener, phalcon_auth_abstractauthdispatcherlistener_ce, phalcon_auth_cli_authdispatcherlistener_method_entry, 0);

	return SUCCESS;
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Cli_AuthDispatcherListener, beforeExecuteRoute)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *dispatcher, dispatcher_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&dispatcher_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(event, phalcon_events_event_ce)
		Z_PARAM_OBJECT_OF_CLASS(dispatcher, phalcon_cli_dispatcher_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &event, &dispatcher);
	ZEPHIR_CALL_METHOD(&_0, dispatcher, "getactionname", NULL, 0);
	zephir_check_call_status();
	zephir_cast_to_string(&_1, &_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "enforce", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Cli_AuthDispatcherListener, getActionType)
{

	RETURN_STRING("task");
}

