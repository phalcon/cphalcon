
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"


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
 * CORS middleware. Inert by default: it emits nothing until an origin allowlist
 * is configured, and only for requests whose `Origin` is on it. The allowed
 * origin is always echoed back explicitly, so credentials are never paired with
 * a wildcard origin. Preflight `OPTIONS` requests are answered directly.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Middleware_CorsMiddleware)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Middleware, CorsMiddleware, phalcon, adr_middleware_corsmiddleware, phalcon_adr_middleware_corsmiddleware_method_entry, 0);

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_adr_middleware_corsmiddleware_ce, SL("allowCredentials"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @var array
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_middleware_corsmiddleware_ce, SL("allowedHeaders"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var array
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_middleware_corsmiddleware_ce, SL("allowedMethods"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var array
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_middleware_corsmiddleware_ce, SL("allowedOrigins"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var int
	 */
	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_adr_middleware_corsmiddleware_ce, SL("maxAge"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	zend_class_implements(phalcon_adr_middleware_corsmiddleware_ce, 1, phalcon_contracts_adr_middleware_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Middleware_CorsMiddleware, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL, _0, _1, _2, _3, _5, _7, _8, _9, _10;
	zval config, _4, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("allowedOrigins", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("allowedMethods", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("allowedHeaders", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("allowCredentials", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("maxAge", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(config, config_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &config_param);
	if (!config_param) {
		ZEPHIR_INIT_VAR(&config);
		array_init(&config);
	} else {
		zephir_get_arrval(&config, config_param);
	}
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "origins");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarrval", NULL, 0, &config, &_2, &_1);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 346, &_0);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 6, 0);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "GET");
	zephir_array_fast_append(&_4, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "POST");
	zephir_array_fast_append(&_4, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "PUT");
	zephir_array_fast_append(&_4, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "PATCH");
	zephir_array_fast_append(&_4, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "DELETE");
	zephir_array_fast_append(&_4, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "OPTIONS");
	zephir_array_fast_append(&_4, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "methods");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getarrval", NULL, 0, &config, &_2, &_4);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 347, &_3);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Content-Type");
	zephir_array_fast_append(&_6, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Authorization");
	zephir_array_fast_append(&_6, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "headers");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getarrval", NULL, 0, &config, &_2, &_6);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 348, &_5);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "credentials");
	ZVAL_BOOL(&_8, 0);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "bool");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getarrval", NULL, 0, &config, &_2, &_8, &_9);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 349, &_7);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "maxAge");
	ZVAL_LONG(&_8, 0);
	ZEPHIR_INIT_NVAR(&_9);
	ZVAL_STRING(&_9, "int");
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "getarrval", NULL, 0, &config, &_2, &_8, &_9);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 350, &_10);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_ADR_Middleware_CorsMiddleware, __invoke)
{
	zval _12$$5;
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *next, next_sub, origin, response, _0, _2, _3, _4, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4, _11$$5, _13$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&next_sub);
	ZVAL_UNDEF(&origin);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_12$$5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("allowedMethods", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("allowedHeaders", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("maxAge", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_contracts_http_attributerequest_ce)
		Z_PARAM_OBJECT_OF_CLASS(next, phalcon_contracts_adr_handler_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &request, &next);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Origin");
	ZEPHIR_CALL_METHOD(&origin, request, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	_1 = ZEPHIR_IS_EMPTY(&origin);
	if (!(_1)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "isallowed", NULL, 0, &origin);
		zephir_check_call_status();
		_1 = !zephir_is_true(&_2);
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(next, "__invoke", NULL, 0, request);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_3, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "OPTIONS");
	if (ZEPHIR_IS_IDENTICAL(&_4, &_3)) {
		ZEPHIR_INIT_VAR(&response);
		object_init_ex(&response, phalcon_http_response_ce);
		ZEPHIR_CALL_METHOD(NULL, &response, "__construct", NULL, 305);
		zephir_check_call_status();
		ZVAL_LONG(&_5$$4, 204);
		ZEPHIR_CALL_METHOD(NULL, &response, "setstatuscode", NULL, 306, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "applyheaders", NULL, 0, &response, &origin);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$4);
		zephir_read_property_cached(&_5$$4, this_ptr, _zephir_prop_0, 347, PH_NOISY_CC | PH_READONLY);
		zephir_fast_join_str(&_6$$4, SL(", "), &_5$$4);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "Access-Control-Allow-Methods");
		ZEPHIR_CALL_METHOD(NULL, &response, "setheader", NULL, 326, &_7$$4, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_7$$4);
		zephir_read_property_cached(&_8$$4, this_ptr, _zephir_prop_1, 348, PH_NOISY_CC | PH_READONLY);
		zephir_fast_join_str(&_7$$4, SL(", "), &_8$$4);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "Access-Control-Allow-Headers");
		ZEPHIR_CALL_METHOD(NULL, &response, "setheader", NULL, 326, &_9$$4, &_7$$4);
		zephir_check_call_status();
		zephir_read_property_cached(&_10$$4, this_ptr, _zephir_prop_2, 350, PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT_LONG(&_10$$4, 0)) {
			zephir_memory_observe(&_11$$5);
			zephir_read_property_cached(&_11$$5, this_ptr, _zephir_prop_2, 350, PH_NOISY_CC);
			zephir_cast_to_string(&_12$$5, &_11$$5);
			ZEPHIR_INIT_VAR(&_13$$5);
			ZVAL_STRING(&_13$$5, "Access-Control-Max-Age");
			ZEPHIR_CALL_METHOD(NULL, &response, "setheader", NULL, 326, &_13$$5, &_12$$5);
			zephir_check_call_status();
		}
		RETURN_CCTOR(&response);
	}
	ZEPHIR_CALL_METHOD(&response, next, "__invoke", NULL, 0, request);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "applyheaders", NULL, 0, &response, &origin);
	zephir_check_call_status();
	RETURN_CCTOR(&response);
}

PHP_METHOD(Phalcon_ADR_Middleware_CorsMiddleware, applyHeaders)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *origin = NULL;
	zval *response, response_sub, origin_zv, _0, _1, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&origin_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("allowCredentials", 16, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(response, phalcon_http_responseinterface_ce)
		Z_PARAM_STR(origin)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	response = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&origin_zv);
	ZVAL_STR_COPY(&origin_zv, origin);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Access-Control-Allow-Origin");
	ZEPHIR_CALL_METHOD(NULL, response, "setheader", NULL, 0, &_0, &origin_zv);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 349, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Access-Control-Allow-Credentials");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "true");
		ZEPHIR_CALL_METHOD(NULL, response, "setheader", NULL, 0, &_2$$3, &_3$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_ADR_Middleware_CorsMiddleware, isAllowed)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval origin_zv, __$true, _0, _1, _2, _3;
	zend_string *origin = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&origin_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("allowedOrigins", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(origin)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&origin_zv);
	ZVAL_STR_COPY(&origin_zv, origin);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 346, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "*");
	ZEPHIR_CALL_FUNCTION(&_2, "in_array", NULL, 87, &_1, &_0, &__$true);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 346, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 87, &origin_zv, &_3, &__$true);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param array       $collection
 * @param mixed       $index
 * @param mixed|null  $defaultValue
 * @param string|null $cast
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_ADR_Middleware_CorsMiddleware, getArrVal)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *cast = NULL;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, cast_zv, __$null, value;
	zval collection;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&cast_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_STR_OR_NULL(cast)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection_param = ZEND_CALL_ARG(execute_data, 1);
	index = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		defaultValue = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_get_arrval(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!cast) {
		ZEPHIR_INIT_VAR(&cast_zv);
	} else {
		zephir_memory_observe(&cast_zv);
	ZVAL_STR_COPY(&cast_zv, cast);
	}
	ZEPHIR_CPY_WRT(&value, defaultValue);
	if (1 == zephir_array_isset_value(&collection, index)) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_fetch(&value, &collection, index, PH_NOISY, "phalcon/Traits/Support/Helper/Arr/GetTrait.zep", 38);
	}
	if (!(ZEPHIR_IS_EMPTY(&cast_zv))) {
		ZEPHIR_MAKE_REF(&value);
		ZEPHIR_CALL_FUNCTION(NULL, "settype", NULL, 16, &value, &cast_zv);
		ZEPHIR_UNREF(&value);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&value);
}

