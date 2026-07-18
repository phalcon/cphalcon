
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
#include "Zend/zend_closures.h"
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
 * The ADR router. Routes are registered by pattern + HTTP method (verb helpers
 * or `add()`), optionally grouped, and matched against the request. `match()`
 * returns a RouterMatch, `null` when nothing matches, or throws
 * MethodNotAllowed when a path matches but the method does not.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_Router)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Router, Router, phalcon, adr_router_router, phalcon_adr_router_router_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var Route[]
	 */
	zend_declare_property_null(phalcon_adr_router_router_ce, SL("routes"), ZEND_ACC_PROTECTED);
	phalcon_adr_router_router_ce->create_object = zephir_init_properties_Phalcon_ADR_Router_Router;

	zend_class_implements(phalcon_adr_router_router_ce, 1, phalcon_contracts_adr_router_router_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Router_Router, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval methods;
	zval pattern_zv, actionClass_zv, *methods_param = NULL, route;
	zend_string *pattern = NULL, *actionClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&actionClass_zv);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&methods);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_STR(actionClass)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(methods, methods_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		methods_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	zephir_memory_observe(&actionClass_zv);
	ZVAL_STR_COPY(&actionClass_zv, actionClass);
	if (!methods_param) {
		ZEPHIR_INIT_VAR(&methods);
		array_init(&methods);
	} else {
		zephir_get_arrval(&methods, methods_param);
	}
	ZEPHIR_INIT_VAR(&route);
	object_init_ex(&route, phalcon_adr_router_route_ce);
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 308, &pattern_zv, &actionClass_zv, &methods);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("routes"), &route);
	RETURN_CCTOR(&route);
}

PHP_METHOD(Phalcon_ADR_Router_Router, delete)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, actionClass_zv, _1;
	zend_string *pattern = NULL, *actionClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&actionClass_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_STR(actionClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	zephir_memory_observe(&actionClass_zv);
	ZVAL_STR_COPY(&actionClass_zv, actionClass);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "DELETE");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 309, &pattern_zv, &actionClass_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Router, get)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, actionClass_zv, _1;
	zend_string *pattern = NULL, *actionClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&actionClass_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_STR(actionClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	zephir_memory_observe(&actionClass_zv);
	ZVAL_STR_COPY(&actionClass_zv, actionClass);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "GET");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 309, &pattern_zv, &actionClass_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Router, group)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval prefix_zv, *configure, configure_sub, group;
	zend_string *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&configure_sub);
	ZVAL_UNDEF(&group);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(prefix)
		Z_PARAM_OBJECT_OF_CLASS(configure, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	configure = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&prefix_zv);
	ZVAL_STR_COPY(&prefix_zv, prefix);
	ZEPHIR_INIT_VAR(&group);
	object_init_ex(&group, phalcon_adr_router_group_ce);
	ZEPHIR_CALL_METHOD(NULL, &group, "__construct", NULL, 310, &prefix_zv, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", NULL, 80, configure, &group);
	zephir_check_call_status();
	RETURN_CCTOR(&group);
}

PHP_METHOD(Phalcon_ADR_Router_Router, match)
{
	zend_bool methodMismatch = 0, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, uri, method, route, params, _0, *_1, _7, _2$$4, _3$$5, _4$$5, _5$$5, _9$$7, _10$$8, _11$$8, _12$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_http_requestinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request);
	ZVAL_BOOL(&_0, 1);
	ZEPHIR_CALL_METHOD(&uri, request, "geturi", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&method, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	methodMismatch = 0;
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 356, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/ADR/Router/Router.zep", 90);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _1);
			ZEPHIR_CALL_METHOD(&params, &route, "matches", NULL, 0, &uri);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&params)) {
				ZEPHIR_CALL_METHOD(&_2$$4, &route, "allowsmethod", NULL, 0, &method);
				zephir_check_call_status();
				if (zephir_is_true(&_2$$4)) {
					object_init_ex(return_value, phalcon_adr_router_routermatch_ce);
					ZEPHIR_CALL_METHOD(&_3$$5, &route, "getaction", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_4$$5, &route, "getmiddleware", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_5$$5, &route, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_6, 311, &_3$$5, &params, &_4$$5, &_5$$5);
					zephir_check_call_status();
					RETURN_MM();
				}
				methodMismatch = 1;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&params, &route, "matches", NULL, 0, &uri);
				zephir_check_call_status();
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&params)) {
					ZEPHIR_CALL_METHOD(&_9$$7, &route, "allowsmethod", NULL, 0, &method);
					zephir_check_call_status();
					if (zephir_is_true(&_9$$7)) {
						object_init_ex(return_value, phalcon_adr_router_routermatch_ce);
						ZEPHIR_CALL_METHOD(&_10$$8, &route, "getaction", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_11$$8, &route, "getmiddleware", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_12$$8, &route, "getname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_6, 311, &_10$$8, &params, &_11$$8, &_12$$8);
						zephir_check_call_status();
						RETURN_MM();
					}
					methodMismatch = 1;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	if (methodMismatch) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_adr_router_exceptions_methodnotallowed_ce, "The request method is not allowed for the matched route.", "phalcon/ADR/Router/Router.zep", 91);
		return;
	}
	RETURN_MM_NULL();
}

PHP_METHOD(Phalcon_ADR_Router_Router, patch)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, actionClass_zv, _1;
	zend_string *pattern = NULL, *actionClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&actionClass_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_STR(actionClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	zephir_memory_observe(&actionClass_zv);
	ZVAL_STR_COPY(&actionClass_zv, actionClass);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "PATCH");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 309, &pattern_zv, &actionClass_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Router, post)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, actionClass_zv, _1;
	zend_string *pattern = NULL, *actionClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&actionClass_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_STR(actionClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	zephir_memory_observe(&actionClass_zv);
	ZVAL_STR_COPY(&actionClass_zv, actionClass);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "POST");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 309, &pattern_zv, &actionClass_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Router, put)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, actionClass_zv, _1;
	zend_string *pattern = NULL, *actionClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&actionClass_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_STR(actionClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	zephir_memory_observe(&actionClass_zv);
	ZVAL_STR_COPY(&actionClass_zv, actionClass);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "PUT");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 309, &pattern_zv, &actionClass_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_ADR_Router_Router(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("routes"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

