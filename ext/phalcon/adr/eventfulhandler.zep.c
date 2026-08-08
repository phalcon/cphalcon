
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
 * The terminal handler of the pipeline: fires the `adr:*` events around the
 * Action's execution.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_EventfulHandler)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR, EventfulHandler, phalcon, adr_eventfulhandler, phalcon_adr_eventfulhandler_method_entry, ZEND_ACC_FINAL_CLASS);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_eventfulhandler_ce, SL("action"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Contracts\\ADR\\Action"));
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_eventfulhandler_ce, SL("events"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Contracts\\Events\\Manager"));
	}

	zend_class_implements(phalcon_adr_eventfulhandler_ce, 1, phalcon_contracts_adr_handler_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_EventfulHandler, __construct)
{
	zval *action, action_sub, *events, events_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&action_sub);
	ZVAL_UNDEF(&events_sub);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("action", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("events", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(action, phalcon_contracts_adr_action_ce)
		Z_PARAM_OBJECT_OF_CLASS(events, phalcon_contracts_events_manager_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &action, &events);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 345, action);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 346, events);
}

PHP_METHOD(Phalcon_ADR_EventfulHandler, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, response, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("events", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("action", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_contracts_http_attributerequest_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 346, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 345, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "adr:beforeExecuteAction");
	ZEPHIR_CALL_METHOD(NULL, &_0, "fire", NULL, 0, &_2, &_1, request);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 345, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&response, &_3, "__invoke", NULL, 0, request);
	zephir_check_call_status();
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 346, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 345, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "adr:afterExecuteAction");
	ZEPHIR_CALL_METHOD(NULL, &_4, "fire", NULL, 0, &_2, &_5, &response);
	zephir_check_call_status();
	RETURN_CCTOR(&response);
}

