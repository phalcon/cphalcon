
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
 * Turns a thrown exception into a response through the responder chain.
 *
 * The full diagnostic (class, message, file:line and the exception itself) goes
 * to the log with a correlation reference; the client receives only a generic
 * message plus that same reference, unless debug mode is on. Exceptions are
 * mapped to statuses deterministically: an exact class match first, then the
 * ancestor chain, so map ordering never matters.
 *
 * @phpstan-import-type adr_error_details from ADRTypes
 * @phpstan-import-type adr_exception_map from ADRTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_ErrorResponder)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR, ErrorResponder, phalcon, adr_errorresponder, phalcon_adr_errorresponder_method_entry, ZEND_ACC_FINAL_CLASS);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_errorresponder_ce, SL("chain"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Contracts\\ADR\\Responder\\Responder"));
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_adr_errorresponder_ce, SL("debug"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @phpstan-var adr_exception_map
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_errorresponder_ce, SL("exceptionMap"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_errorresponder_ce, SL("logger"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Contracts\\Logger\\Logger"));
	}

	return SUCCESS;
}

/**
 * @phpstan-param adr_exception_map $exceptionMap
 */
PHP_METHOD(Phalcon_ADR_ErrorResponder, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval exceptionMap;
	zend_bool debug;
	zval *chain, chain_sub, *logger, logger_sub, *debug_param = NULL, *exceptionMap_param = NULL, __$true, __$false, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&chain_sub);
	ZVAL_UNDEF(&logger_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&exceptionMap);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("chain", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("logger", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("debug", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("exceptionMap", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_OBJECT_OF_CLASS(chain, phalcon_contracts_adr_responder_responder_ce)
		Z_PARAM_OBJECT_OF_CLASS(logger, phalcon_contracts_logger_logger_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(debug)
		ZEPHIR_Z_PARAM_ARRAY(exceptionMap, exceptionMap_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 2, &chain, &logger, &debug_param, &exceptionMap_param);
	if (!debug_param) {
		debug = 0;
	} else {
		}
	if (!exceptionMap_param) {
		ZEPHIR_INIT_VAR(&exceptionMap);
		array_init(&exceptionMap);
	} else {
		zephir_get_arrval(&exceptionMap, exceptionMap_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 347, chain);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 348, logger);
	if (debug) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 349, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 349, &__$false);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "defaultmap", NULL, 322);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_add_function(&_1, &exceptionMap, &_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 350, &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_ADR_ErrorResponder, handle)
{
	zval _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *response, response_sub, *exception, exception_sub, status, ref, payload, _0, _1, _2, _3, _4, _5, _6, _8, _9, _10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&ref);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_7);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("logger", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("chain", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_http_requestinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(response, phalcon_http_responseinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &request, &response, &exception);
	ZEPHIR_CALL_METHOD(&ref, this_ptr, "correlationid", NULL, 323, request);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 348, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, exception, 0);
	ZEPHIR_CALL_METHOD(&_2, exception, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, exception, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, exception, "getline", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "%s: %s in %s:%d");
	ZEPHIR_CALL_FUNCTION(&_6, "sprintf", NULL, 146, &_5, &_1, &_2, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0);
	zephir_array_update_string(&_7, SL("exception"), exception, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_7, SL("ref"), &ref, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &_0, "error", NULL, 0, &_6, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, this_ptr, "resolvestatus", NULL, 324, exception);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	object_init_ex(&_5, phalcon_adr_payload_payload_ce);
	if (zephir_has_constructor(&_5)) {
		ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(&_8, &_5, "withstatus", NULL, 325, &status);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "details", NULL, 326, exception, &ref, &status);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&payload, &_8, "withresult", NULL, 0, &_9);
	zephir_check_call_status();
	zephir_read_property_cached(&_10, this_ptr, _zephir_prop_1, 347, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_10, "__invoke", NULL, 0, request, response, &payload);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_ErrorResponder, correlationId)
{
	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, id, _0, _1$$3, _2$$3;

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_http_requestinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "X-Request-Id");
	ZEPHIR_CALL_METHOD(&id, request, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&id)) {
		ZVAL_LONG(&_1$$3, 8);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "random_bytes", NULL, 327, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&id, "bin2hex", NULL, 328, &_2$$3);
		zephir_check_call_status();
	}
	zephir_cast_to_string(&_3, &id);
	RETURN_CTOR(&_3);
}

/**
 * @phpstan-return adr_exception_map
 */
PHP_METHOD(Phalcon_ADR_ErrorResponder, defaultMap)
{

	zephir_create_array(return_value, 2, 0);
	add_assoc_stringl_ex(return_value, SL("Phalcon\\ADR\\Exceptions\\RouteNotFound"), SL("NOT_FOUND"));
	add_assoc_stringl_ex(return_value, SL("Phalcon\\ADR\\Exceptions\\MethodNotAllowed"), SL("METHOD_NOT_ALLOWED"));
	return;
}

/**
 * @phpstan-return adr_error_details
 */
PHP_METHOD(Phalcon_ADR_ErrorResponder, details)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval status;
	zend_string *ref = NULL;
	zval *exception, exception_sub, ref_zv, *status_param = NULL, _0, _2, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&ref_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&status);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("debug", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
		Z_PARAM_STR(ref)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(status_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	exception = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		status_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&ref_zv);
	ZVAL_STR_COPY(&ref_zv, ref);
	if (!status_param) {
		ZEPHIR_INIT_VAR(&status);
		ZVAL_STRING(&status, "ERROR");
	} else {
		zephir_get_strval(&status, status_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 349, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_create_array(return_value, 3, 0);
		ZEPHIR_CALL_METHOD(&_1$$3, exception, "getmessage", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(return_value, SL("message"), &_1$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_1$$3, exception, "gettraceasstring", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(return_value, SL("trace"), &_1$$3, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(return_value, SL("ref"), &ref_zv, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "reason", NULL, 329, &status);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("message"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("ref"), &ref_zv, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * The message that goes with the status. Reporting `Internal Server Error`
 * next to a `404` tells the client the opposite of what happened.
 */
PHP_METHOD(Phalcon_ADR_ErrorResponder, reason)
{
	zval reasons;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval status_zv, _0;
	zend_string *status = NULL;

	ZVAL_UNDEF(&status_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&reasons);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(status)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&status_zv);
	ZVAL_STR_COPY(&status_zv, status);
	ZEPHIR_INIT_VAR(&reasons);
	zephir_create_array(&reasons, 10, 0);
	add_assoc_stringl_ex(&reasons, SL("FAILURE"), SL("Bad Request"));
	add_assoc_stringl_ex(&reasons, SL("METHOD_NOT_ALLOWED"), SL("Method Not Allowed"));
	add_assoc_stringl_ex(&reasons, SL("NOT_ACCEPTED"), SL("Not Acceptable"));
	add_assoc_stringl_ex(&reasons, SL("NOT_AUTHENTICATED"), SL("Unauthorized"));
	add_assoc_stringl_ex(&reasons, SL("NOT_AUTHORIZED"), SL("Forbidden"));
	add_assoc_stringl_ex(&reasons, SL("NOT_CREATED"), SL("Unprocessable Entity"));
	add_assoc_stringl_ex(&reasons, SL("NOT_DELETED"), SL("Unprocessable Entity"));
	add_assoc_stringl_ex(&reasons, SL("NOT_FOUND"), SL("Not Found"));
	add_assoc_stringl_ex(&reasons, SL("NOT_UPDATED"), SL("Unprocessable Entity"));
	add_assoc_stringl_ex(&reasons, SL("NOT_VALID"), SL("Unprocessable Entity"));
	ZEPHIR_INIT_VAR(&_0);
	if (zephir_array_isset_value(&reasons, &status_zv)) {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch(&_0, &reasons, &status_zv, PH_NOISY, "phalcon/ADR/ErrorResponder.zep", 160);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "Internal Server Error");
	}
	RETURN_CCTOR(&_0);
}

PHP_METHOD(Phalcon_ADR_ErrorResponder, resolveStatus)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, className, ancestor, ancestors, _0, _3, _4, _5, _6, *_7, _1$$3, _2$$3, _8$$4, _9$$5, _10$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&ancestor);
	ZVAL_UNDEF(&ancestors);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("exceptionMap", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &exception);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, exception, 0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 350, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_0, &className)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 350, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &className, PH_NOISY | PH_READONLY, "phalcon/ADR/ErrorResponder.zep", 170);
		RETURN_CTOR(&_2$$3);
	}
	ZEPHIR_CALL_FUNCTION(&_3, "class_parents", NULL, 330, exception);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "array_values", NULL, 28, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "class_implements", NULL, 331, exception);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_6, "array_values", NULL, 28, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&ancestors);
	zephir_fast_array_merge(&ancestors, &_4, &_6);
	zephir_is_iterable(&ancestors, 0, "phalcon/ADR/ErrorResponder.zep", 184);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&ancestors), _7)
	{
		ZEPHIR_INIT_NVAR(&ancestor);
		ZVAL_COPY(&ancestor, _7);
		zephir_read_property_cached(&_8$$4, this_ptr, _zephir_prop_0, 350, PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_value(&_8$$4, &ancestor)) {
			zephir_read_property_cached(&_9$$5, this_ptr, _zephir_prop_0, 350, PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_10$$5, &_9$$5, &ancestor, PH_NOISY | PH_READONLY, "phalcon/ADR/ErrorResponder.zep", 180);
			RETURN_CTOR(&_10$$5);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&ancestor);
	RETURN_MM_STRING("ERROR");
}

