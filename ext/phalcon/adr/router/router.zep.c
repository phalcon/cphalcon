
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
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"


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
 * Convention router. `method + static path -> Action class`; the path tail
 * becomes positional request attributes. Middleware is resolved from a
 * namespace-prefix map (group semantics); global middleware stays on the
 * pipeline. No route table.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_Router)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Router, Router, phalcon, adr_router_router, phalcon_adr_router_router_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_adr_router_router_ce, SL("baseNamespace"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var array<string, string[]>
	 */
	zend_declare_property_null(phalcon_adr_router_router_ce, SL("middlewareMap"), ZEND_ACC_PROTECTED);
	phalcon_adr_router_router_ce->create_object = zephir_init_properties_Phalcon_ADR_Router_Router;

	zend_class_implements(phalcon_adr_router_router_ce, 1, phalcon_contracts_adr_router_router_ce);
	return SUCCESS;
}

/**
 * Every Action class this router would try for the given method and path,
 * in the order it tries them. The first that exists wins at match time.
 * The list is not filtered by existence.
 *
 * @return list<class-string>
 */
PHP_METHOD(Phalcon_ADR_Router_Router, candidatesFor)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method_zv, path_zv, _0, _1;
	zend_string *method = NULL, *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "derivecandidates", NULL, 330, &method_zv, &path_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 0);
	ZEPHIR_RETURN_CALL_FUNCTION("array_column", NULL, 331, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Router, match)
{
	zend_bool _9$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, path, method, located, verbs, other, _0, _5, *_6, _1$$3, _2$$3, _3$$3, _4$$3, _7$$4, _10$$4, _11$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&located);
	ZVAL_UNDEF(&verbs);
	ZVAL_UNDEF(&other);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_http_requestinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request);
	ZVAL_BOOL(&_0, 1);
	ZEPHIR_CALL_METHOD(&path, request, "geturi", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&method, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&located, this_ptr, "locate", NULL, 332, &method, &path);
	zephir_check_call_status();
	if (Z_TYPE_P(&located) == IS_ARRAY) {
		object_init_ex(return_value, phalcon_adr_router_routermatch_ce);
		zephir_array_fetch_long(&_1$$3, &located, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 61);
		zephir_array_fetch_long(&_2$$3, &located, 1, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 62);
		zephir_array_fetch_long(&_4$$3, &located, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 63);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "middlewarefor", NULL, 333, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 334, &_1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&verbs);
	zephir_create_array(&verbs, 5, 0);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "Get");
	zephir_array_fast_append(&verbs, &_5);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "Post");
	zephir_array_fast_append(&verbs, &_5);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "Put");
	zephir_array_fast_append(&verbs, &_5);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "Patch");
	zephir_array_fast_append(&verbs, &_5);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "Delete");
	zephir_array_fast_append(&verbs, &_5);
	zephir_is_iterable(&verbs, 0, "phalcon/ADR/Router/Router.zep", 74);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&verbs), _6)
	{
		ZEPHIR_INIT_NVAR(&other);
		ZVAL_COPY(&other, _6);
		ZEPHIR_CALL_FUNCTION(&_7$$4, "strcasecmp", &_8, 85, &other, &method);
		zephir_check_call_status();
		_9$$4 = !ZEPHIR_IS_LONG_IDENTICAL(&_7$$4, 0);
		if (_9$$4) {
			ZEPHIR_CALL_METHOD(&_10$$4, this_ptr, "locate", NULL, 332, &other, &path);
			zephir_check_call_status();
			_9$$4 = Z_TYPE_P(&_10$$4) == IS_ARRAY;
		}
		if (_9$$4) {
			ZEPHIR_INIT_NVAR(&_11$$5);
			object_init_ex(&_11$$5, phalcon_adr_exceptions_methodnotallowed_ce);
			ZEPHIR_CALL_METHOD(NULL, &_11$$5, "__construct", &_12, 335);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_11$$5, "phalcon/ADR/Router/Router.zep", 70);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&other);
	RETURN_MM_NULL();
}

PHP_METHOD(Phalcon_ADR_Router_Router, setBaseNamespace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval baseNamespace_zv, _0, _1;
	zend_string *baseNamespace = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&baseNamespace_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("baseNamespace", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(baseNamespace)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&baseNamespace_zv);
	ZVAL_STR_COPY(&baseNamespace_zv, baseNamespace);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\\");
	zephir_fast_trim(&_0, &baseNamespace_zv, &_1, ZEPHIR_TRIM_RIGHT);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 360, &_0);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_ADR_Router_Router, setMiddlewareMap)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *middlewareMap_param = NULL;
	zval middlewareMap;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&middlewareMap);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("middlewareMap", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(middlewareMap, middlewareMap_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &middlewareMap_param);
	zephir_get_arrval(&middlewareMap, middlewareMap_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 361, &middlewareMap);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_ADR_Router_Router, camelize)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval segment_zv, _0, _2, _3, _4, _5, _6;
	zend_string *segment = NULL;

	ZVAL_UNDEF(&segment_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(segment)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&segment_zv);
	ZVAL_STR_COPY(&segment_zv, segment);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "-");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "_");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, " ");
	zephir_fast_str_replace(&_0, &_1, &_2, &segment_zv);
	ZEPHIR_CALL_FUNCTION(&_3, "ucwords", NULL, 336, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, " ");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "");
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_str_replace(&_6, &_4, &_5, &_3);
	RETURN_CCTOR(&_6);
}

/**
 * The single derivation of the routing convention. Every candidate is
 * paired with the request attributes it would leave behind, in try order.
 *
 * @return array<int, array{0: string, 1: array}>
 */
PHP_METHOD(Phalcon_ADR_Router_Router, deriveCandidates)
{
	zval _3$$3, _19$$4, _15$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _21$$4;
	zephir_fcall_cache_entry *_6 = NULL, *_11 = NULL, *_13 = NULL;
	zval method_zv, path_zv, candidates, uri, verb, segments, index, last, prev, head, resourceName, operation, className, _0, _1, _2$$3, _4$$3, _5$$4, _17$$4, _18$$4, _20$$4, _7$$5, _8$$5, _9$$5, _10$$5, _12$$5, _14$$5, _16$$5;
	zend_string *method = NULL, *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&candidates);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&verb);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&last);
	ZVAL_UNDEF(&prev);
	ZVAL_UNDEF(&head);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&operation);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_15$$5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("baseNamespace", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	ZEPHIR_INIT_VAR(&candidates);
	array_init(&candidates);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/");
	ZEPHIR_INIT_VAR(&uri);
	zephir_fast_trim(&uri, &path_zv, &_0, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &method_zv);
	ZEPHIR_INIT_VAR(&verb);
	zephir_ucfirst(&verb, &_1);
	if (ZEPHIR_IS_STRING_IDENTICAL(&uri, "")) {
		ZEPHIR_INIT_VAR(&segments);
		array_init(&segments);
	} else {
		ZEPHIR_INIT_NVAR(&segments);
		zephir_fast_explode_str(&segments, SL("/"), &uri, LONG_MAX);
	}
	if (ZEPHIR_IS_EMPTY(&segments)) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 360, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&className);
		ZEPHIR_CONCAT_VSV(&className, &_2$$3, "\\", &verb);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 2, 0);
		zephir_array_fast_append(&_3$$3, &className);
		ZEPHIR_INIT_VAR(&_4$$3);
		array_init(&_4$$3);
		zephir_array_fast_append(&_3$$3, &_4$$3);
		zephir_array_append(&candidates, &_3$$3, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 114);
		RETURN_CCTOR(&candidates);
	}
	ZEPHIR_INIT_VAR(&index);
	ZVAL_LONG(&index, zephir_fast_count_int(&segments));
	while (1) {
		if (!(ZEPHIR_GE_LONG(&index, 1))) {
			break;
		}
		ZEPHIR_INIT_NVAR(&last);
		ZVAL_LONG(&last, (zephir_get_numberval(&index) - 1));
		ZVAL_LONG(&_5$$4, 0);
		ZEPHIR_CALL_FUNCTION(&head, "array_slice", &_6, 271, &segments, &_5$$4, &index);
		zephir_check_call_status();
		if (ZEPHIR_GE_LONG(&index, 2)) {
			ZEPHIR_INIT_NVAR(&prev);
			ZVAL_LONG(&prev, (zephir_get_numberval(&index) - 2));
			ZEPHIR_OBS_NVAR(&resourceName);
			zephir_array_fetch(&resourceName, &head, &prev, PH_NOISY, "phalcon/ADR/Router/Router.zep", 127);
			ZEPHIR_OBS_NVAR(&operation);
			zephir_array_fetch(&operation, &head, &last, PH_NOISY, "phalcon/ADR/Router/Router.zep", 128);
			zephir_read_property_cached(&_7$$5, this_ptr, _zephir_prop_0, 360, PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_9$$5, 0);
			ZEPHIR_CALL_FUNCTION(&_10$$5, "array_slice", &_6, 271, &head, &_9$$5, &last);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8$$5, this_ptr, "tonamespace", &_11, 337, &_10$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "camelize", &_13, 338, &resourceName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_14$$5, this_ptr, "camelize", &_13, 338, &operation);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&className);
			ZEPHIR_CONCAT_VVSVVV(&className, &_7$$5, &_8$$5, "\\", &verb, &_12$$5, &_14$$5);
			ZEPHIR_INIT_NVAR(&_15$$5);
			zephir_create_array(&_15$$5, 2, 0);
			zephir_array_fast_append(&_15$$5, &className);
			ZEPHIR_CALL_FUNCTION(&_16$$5, "array_slice", &_6, 271, &segments, &index);
			zephir_check_call_status();
			zephir_array_fast_append(&_15$$5, &_16$$5);
			zephir_array_append(&candidates, &_15$$5, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 132);
		}
		ZEPHIR_OBS_NVAR(&resourceName);
		zephir_array_fetch(&resourceName, &head, &last, PH_NOISY, "phalcon/ADR/Router/Router.zep", 135);
		zephir_read_property_cached(&_5$$4, this_ptr, _zephir_prop_0, 360, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_17$$4, this_ptr, "tonamespace", &_11, 337, &head);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_18$$4, this_ptr, "camelize", &_13, 338, &resourceName);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&className);
		ZEPHIR_CONCAT_VVSVV(&className, &_5$$4, &_17$$4, "\\", &verb, &_18$$4);
		ZEPHIR_INIT_NVAR(&_19$$4);
		zephir_create_array(&_19$$4, 2, 0);
		zephir_array_fast_append(&_19$$4, &className);
		ZEPHIR_CALL_FUNCTION(&_20$$4, "array_slice", &_6, 271, &segments, &index);
		zephir_check_call_status();
		zephir_array_fast_append(&_19$$4, &_20$$4);
		zephir_array_append(&candidates, &_19$$4, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 139);
		_21$$4 = (zephir_get_numberval(&index) - 1);
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_LONG(&index, _21$$4);
	}
	RETURN_CCTOR(&candidates);
}

PHP_METHOD(Phalcon_ADR_Router_Router, locate)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method_zv, path_zv, candidates, candidate, *_0, _2, _1$$3, _4$$5;
	zend_string *method = NULL, *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&candidates);
	ZVAL_UNDEF(&candidate);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$5);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	ZEPHIR_CALL_METHOD(&candidates, this_ptr, "derivecandidates", NULL, 330, &method_zv, &path_zv);
	zephir_check_call_status();
	zephir_is_iterable(&candidates, 0, "phalcon/ADR/Router/Router.zep", 159);
	if (Z_TYPE_P(&candidates) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&candidates), _0)
		{
			ZEPHIR_INIT_NVAR(&candidate);
			ZVAL_COPY(&candidate, _0);
			zephir_array_fetch_long(&_1$$3, &candidate, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 154);
			if (zephir_class_exists(&_1$$3, 1)) {
				RETURN_CCTOR(&candidate);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &candidates, "rewind", NULL, 0);
		zephir_check_call_status();
		_3 = 1;
		while (1) {
			if (_3) {
				_3 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &candidates, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_2, &candidates, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&candidate, &candidates, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_long(&_4$$5, &candidate, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 154);
				if (zephir_class_exists(&_4$$5, 1)) {
					RETURN_CCTOR(&candidate);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&candidate);
	RETURN_MM_NULL();
}

PHP_METHOD(Phalcon_ADR_Router_Router, middlewareFor)
{
	zend_bool _10;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, prefix, list, full, stacked, _0, *_1, _9, _4$$3, _5$$3, _6$$3, _8$$4, _11$$5, _12$$5, _13$$5, _14$$6;
	zend_string *className = NULL, *_3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&list);
	ZVAL_UNDEF(&full);
	ZVAL_UNDEF(&stacked);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("middlewareMap", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("baseNamespace", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	ZEPHIR_INIT_VAR(&stacked);
	array_init(&stacked);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 361, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/ADR/Router/Router.zep", 175);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&prefix);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&prefix, _3);
			} else {
				ZVAL_LONG(&prefix, _2);
			}
			ZEPHIR_INIT_NVAR(&list);
			ZVAL_COPY(&list, _1);
			zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_1, 360, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&full);
			ZEPHIR_CONCAT_VV(&full, &_4$$3, &prefix);
			ZVAL_LONG(&_5$$3, zephir_fast_strlen_ev(&full));
			ZEPHIR_CALL_FUNCTION(&_6$$3, "strncmp", &_7, 339, &className_zv, &full, &_5$$3);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_6$$3, 0)) {
				ZEPHIR_INIT_NVAR(&_8$$4);
				zephir_fast_array_merge(&_8$$4, &stacked, &list);
				ZEPHIR_CPY_WRT(&stacked, &_8$$4);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&prefix, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&list, &_0, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property_cached(&_11$$5, this_ptr, _zephir_prop_1, 360, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&full);
				ZEPHIR_CONCAT_VV(&full, &_11$$5, &prefix);
				ZVAL_LONG(&_12$$5, zephir_fast_strlen_ev(&full));
				ZEPHIR_CALL_FUNCTION(&_13$$5, "strncmp", &_7, 339, &className_zv, &full, &_12$$5);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_13$$5, 0)) {
					ZEPHIR_INIT_NVAR(&_14$$6);
					zephir_fast_array_merge(&_14$$6, &stacked, &list);
					ZEPHIR_CPY_WRT(&stacked, &_14$$6);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&list);
	ZEPHIR_INIT_NVAR(&prefix);
	RETURN_CCTOR(&stacked);
}

PHP_METHOD(Phalcon_ADR_Router_Router, toNamespace)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *segments_param = NULL, segment, parts, *_0, _3, _6, _1$$3, _5$$4;
	zval segments;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&segment);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(segments, segments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &segments_param);
	zephir_get_arrval(&segments, segments_param);
	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	zephir_is_iterable(&segments, 0, "phalcon/ADR/Router/Router.zep", 187);
	if (Z_TYPE_P(&segments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&segments), _0)
		{
			ZEPHIR_INIT_NVAR(&segment);
			ZVAL_COPY(&segment, _0);
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "camelize", &_2, 338, &segment);
			zephir_check_call_status();
			zephir_array_append(&parts, &_1$$3, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 184);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &segments, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &segments, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &segments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&segment, &segments, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "camelize", &_2, 338, &segment);
				zephir_check_call_status();
				zephir_array_append(&parts, &_5$$4, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 184);
		}
	}
	ZEPHIR_INIT_NVAR(&segment);
	if (ZEPHIR_IS_EMPTY(&parts)) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_join_str(&_6, SL("\\"), &parts);
	ZEPHIR_CONCAT_SV(return_value, "\\", &_6);
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("middlewareMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("middlewareMap"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

