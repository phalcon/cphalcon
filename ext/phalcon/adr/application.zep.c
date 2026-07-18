
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
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * Routes the request, writes the matched attributes onto it, dispatches the
 * Action and returns the response. A single try/catch routes any error through
 * the error responder; if that itself fails, a bare 500 is returned so nothing
 * escapes uncaught.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Application)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR, Application, phalcon, adr_application, phalcon_adr_application_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var DispatcherInterface
	 */
	zend_declare_property_null(phalcon_adr_application_ce, SL("dispatcher"), ZEND_ACC_PROTECTED);
	/**
	 * @var ErrorResponder
	 */
	zend_declare_property_null(phalcon_adr_application_ce, SL("errorResponder"), ZEND_ACC_PROTECTED);
	/**
	 * @var Manager
	 */
	zend_declare_property_null(phalcon_adr_application_ce, SL("events"), ZEND_ACC_PROTECTED);
	/**
	 * @var RouterInterface
	 */
	zend_declare_property_null(phalcon_adr_application_ce, SL("router"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_adr_application_ce, 1, phalcon_contracts_adr_application_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Application, __construct)
{
	zval *router, router_sub, *dispatcher, dispatcher_sub, *errorResponder, errorResponder_sub, *events, events_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&router_sub);
	ZVAL_UNDEF(&dispatcher_sub);
	ZVAL_UNDEF(&errorResponder_sub);
	ZVAL_UNDEF(&events_sub);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("router", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("dispatcher", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("errorResponder", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("events", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(router, phalcon_contracts_adr_router_router_ce)
		Z_PARAM_OBJECT_OF_CLASS(dispatcher, phalcon_contracts_adr_dispatcher_ce)
		Z_PARAM_OBJECT_OF_CLASS(errorResponder, phalcon_adr_errorresponder_ce)
		Z_PARAM_OBJECT_OF_CLASS(events, phalcon_contracts_events_manager_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &router, &dispatcher, &errorResponder, &events);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 329, router);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 330, dispatcher);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 331, errorResponder);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 332, events);
}

PHP_METHOD(Phalcon_ADR_Application, handle)
{
	zend_bool _13$$3;
	zend_string *_8$$3;
	zend_ulong _7$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_11 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, match, response, key, value, exception, _0, _1, _26, _27, _2$$3, _5$$3, *_6$$3, _12$$3, _16$$3, _17$$3, _18$$3, _3$$4, _4$$4, _9$$5, _14$$6, _19$$8, _20$$8, _21$$7, _22$$7, _23$$9, _24$$9, _25$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("events", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("router", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("dispatcher", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("errorResponder", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_contracts_http_attributerequestinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 332, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "application:beforeHandle");
	ZEPHIR_CALL_METHOD(NULL, &_0, "fire", NULL, 0, &_1, this_ptr, request);
	zephir_check_call_status();

	/* try_start_1: */

		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_1, 329, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&match, &_2$$3, "match", NULL, 0, request);
		zephir_check_call_status_or_jump(try_end_1);
		if (Z_TYPE_P(&match) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			object_init_ex(&_3$$4, phalcon_adr_router_exceptions_routenotfound_ce);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "No route matched the request.");
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 8, &_4$$4);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(&_3$$4, "phalcon/ADR/Application.zep", 76);
			goto try_end_1;

		}
		ZEPHIR_CALL_METHOD(&_5$$3, &match, "getattributes", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_is_iterable(&_5$$3, 0, "phalcon/ADR/Application.zep", 83);
		if (Z_TYPE_P(&_5$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_5$$3), _7$$3, _8$$3, _6$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_8$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _8$$3);
				} else {
					ZVAL_LONG(&key, _7$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _6$$3);
				ZEPHIR_CALL_METHOD(&_9$$5, request, "getattributes", &_10, 0);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CALL_METHOD(NULL, &_9$$5, "set", &_11, 0, &key, &value);
				zephir_check_call_status_or_jump(try_end_1);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_5$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_13$$3 = 1;
			while (1) {
				if (_13$$3) {
					_13$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_5$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_12$$3, &_5$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_12$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &_5$$3, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &_5$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_14$$6, request, "getattributes", &_15, 0);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CALL_METHOD(NULL, &_14$$6, "set", &_11, 0, &key, &value);
					zephir_check_call_status_or_jump(try_end_1);
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		zephir_read_property_cached(&_16$$3, this_ptr, _zephir_prop_2, 330, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_17$$3, &match, "getaction", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_18$$3, &match, "getmiddleware", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&response, &_16$$3, "dispatch", NULL, 0, &_17$$3, request, &_18$$3);
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

				zephir_read_property_cached(&_19$$8, this_ptr, _zephir_prop_3, 331, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_20$$8);
				object_init_ex(&_20$$8, phalcon_http_response_ce);
				ZEPHIR_CALL_METHOD(NULL, &_20$$8, "__construct", NULL, 300);
				zephir_check_call_status_or_jump(try_end_2);
				ZEPHIR_CALL_METHOD(&response, &_19$$8, "handle", NULL, 0, request, &_20$$8, &exception);
				zephir_check_call_status_or_jump(try_end_2);

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_VAR(&_21$$7);
				ZVAL_OBJ(&_21$$7, EG(exception));
				Z_ADDREF_P(&_21$$7);
				ZEPHIR_INIT_VAR(&_22$$7);
				if (zephir_is_instance_of(&_21$$7, SL("Throwable"))) {
					zend_clear_exception();
					ZEPHIR_CPY_WRT(&_22$$7, &_21$$7);
					ZEPHIR_INIT_NVAR(&response);
					object_init_ex(&response, phalcon_http_response_ce);
					ZEPHIR_CALL_METHOD(NULL, &response, "__construct", NULL, 300);
					zephir_check_call_status();
					ZVAL_LONG(&_24$$9, 500);
					ZEPHIR_CALL_METHOD(&_23$$9, &response, "setstatuscode", NULL, 301, &_24$$9);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(&_25$$9);
					ZVAL_STRING(&_25$$9, "Internal Server Error");
					ZEPHIR_CALL_METHOD(NULL, &_23$$9, "setcontent", NULL, 0, &_25$$9);
					zephir_check_call_status();
				}
			}
		}
	}
	zephir_read_property_cached(&_26, this_ptr, _zephir_prop_0, 332, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_27);
	ZVAL_STRING(&_27, "application:afterHandle");
	ZEPHIR_CALL_METHOD(NULL, &_26, "fire", NULL, 0, &_27, this_ptr, &response);
	zephir_check_call_status();
	RETURN_CCTOR(&response);
}

