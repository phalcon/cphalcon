
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"
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

PHP_METHOD(Phalcon_ADR_Router_Router, match)
{
	zend_bool _14$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, uri, verb, segments, located, verbs, other, className, _0, _1, _2, _3, _4, _12, *_13, _5$$3, _6$$4, _7$$4, _8$$5, _9$$5, _10$$5, _11$$5, _15$$6, _16$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&verb);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&located);
	ZVAL_UNDEF(&verbs);
	ZVAL_UNDEF(&other);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$7);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("baseNamespace", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_http_requestinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request);
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(&_0, request, "geturi", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/");
	ZEPHIR_INIT_VAR(&uri);
	zephir_fast_trim(&uri, &_0, &_2, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CALL_METHOD(&_4, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	zephir_fast_strtolower(&_3, &_4);
	ZEPHIR_INIT_VAR(&verb);
	zephir_ucfirst(&verb, &_3);
	if (ZEPHIR_IS_STRING_IDENTICAL(&uri, "")) {
		ZEPHIR_INIT_VAR(&segments);
		array_init(&segments);
	} else {
		ZEPHIR_INIT_NVAR(&segments);
		zephir_fast_explode_str(&segments, SL("/"), &uri, LONG_MAX);
	}
	if (ZEPHIR_IS_EMPTY(&segments)) {
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_0, 360, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&className);
		ZEPHIR_CONCAT_VSV(&className, &_5$$3, "\\", &verb);
		if (zephir_class_exists(&className, 1)) {
			object_init_ex(return_value, phalcon_adr_router_routermatch_ce);
			ZEPHIR_INIT_VAR(&_6$$4);
			array_init(&_6$$4);
			ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "middlewarefor", NULL, 328, &className);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 329, &className, &_6$$4, &_7$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&located, this_ptr, "locate", NULL, 330, &segments, &verb);
	zephir_check_call_status();
	if (Z_TYPE_P(&located) == IS_ARRAY) {
		object_init_ex(return_value, phalcon_adr_router_routermatch_ce);
		zephir_array_fetch_long(&_8$$5, &located, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 64);
		zephir_array_fetch_long(&_9$$5, &located, 1, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 65);
		zephir_array_fetch_long(&_11$$5, &located, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 66);
		ZEPHIR_CALL_METHOD(&_10$$5, this_ptr, "middlewarefor", NULL, 328, &_11$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 329, &_8$$5, &_9$$5, &_10$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&verbs);
	zephir_create_array(&verbs, 5, 0);
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "Get");
	zephir_array_fast_append(&verbs, &_12);
	ZEPHIR_INIT_NVAR(&_12);
	ZVAL_STRING(&_12, "Post");
	zephir_array_fast_append(&verbs, &_12);
	ZEPHIR_INIT_NVAR(&_12);
	ZVAL_STRING(&_12, "Put");
	zephir_array_fast_append(&verbs, &_12);
	ZEPHIR_INIT_NVAR(&_12);
	ZVAL_STRING(&_12, "Patch");
	zephir_array_fast_append(&verbs, &_12);
	ZEPHIR_INIT_NVAR(&_12);
	ZVAL_STRING(&_12, "Delete");
	zephir_array_fast_append(&verbs, &_12);
	zephir_is_iterable(&verbs, 0, "phalcon/ADR/Router/Router.zep", 77);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&verbs), _13)
	{
		ZEPHIR_INIT_NVAR(&other);
		ZVAL_COPY(&other, _13);
		_14$$6 = !ZEPHIR_IS_IDENTICAL(&other, &verb);
		if (_14$$6) {
			ZEPHIR_CALL_METHOD(&_15$$6, this_ptr, "locate", NULL, 330, &segments, &other);
			zephir_check_call_status();
			_14$$6 = Z_TYPE_P(&_15$$6) == IS_ARRAY;
		}
		if (_14$$6) {
			ZEPHIR_INIT_NVAR(&_16$$7);
			object_init_ex(&_16$$7, phalcon_adr_exceptions_methodnotallowed_ce);
			ZEPHIR_CALL_METHOD(NULL, &_16$$7, "__construct", &_17, 331);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_16$$7, "phalcon/ADR/Router/Router.zep", 73);
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
	ZEPHIR_CALL_FUNCTION(&_3, "ucwords", NULL, 332, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, " ");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "");
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_str_replace(&_6, &_4, &_5, &_3);
	RETURN_CCTOR(&_6);
}

PHP_METHOD(Phalcon_ADR_Router_Router, locate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _14$$3;
	zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL, *_8 = NULL;
	zend_string *verb = NULL;
	zval *segments_param = NULL, verb_zv, index, last, prev, head, resourceName, operation, className, _0$$3, _11$$3, _12$$3, _2$$4, _3$$4, _4$$4, _5$$4, _7$$4, _9$$4, _10$$5, _13$$6;
	zval segments;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&verb_zv);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&last);
	ZVAL_UNDEF(&prev);
	ZVAL_UNDEF(&head);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&operation);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_13$$6);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("baseNamespace", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(segments, segments_param)
		Z_PARAM_STR(verb)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	segments_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&segments, segments_param);
	zephir_memory_observe(&verb_zv);
	ZVAL_STR_COPY(&verb_zv, verb);
	ZEPHIR_INIT_VAR(&index);
	ZVAL_LONG(&index, zephir_fast_count_int(&segments));
	while (1) {
		if (!(ZEPHIR_GE_LONG(&index, 1))) {
			break;
		}
		ZEPHIR_INIT_NVAR(&last);
		ZVAL_LONG(&last, (zephir_get_numberval(&index) - 1));
		ZVAL_LONG(&_0$$3, 0);
		ZEPHIR_CALL_FUNCTION(&head, "array_slice", &_1, 271, &segments, &_0$$3, &index);
		zephir_check_call_status();
		if (ZEPHIR_GE_LONG(&index, 2)) {
			ZEPHIR_INIT_NVAR(&prev);
			ZVAL_LONG(&prev, (zephir_get_numberval(&index) - 2));
			ZEPHIR_OBS_NVAR(&resourceName);
			zephir_array_fetch(&resourceName, &head, &prev, PH_NOISY, "phalcon/ADR/Router/Router.zep", 111);
			ZEPHIR_OBS_NVAR(&operation);
			zephir_array_fetch(&operation, &head, &last, PH_NOISY, "phalcon/ADR/Router/Router.zep", 112);
			zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_0, 360, PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_4$$4, 0);
			ZEPHIR_CALL_FUNCTION(&_5$$4, "array_slice", &_1, 271, &head, &_4$$4, &last);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "tonamespace", &_6, 333, &_5$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "camelize", &_8, 334, &resourceName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "camelize", &_8, 334, &operation);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&className);
			ZEPHIR_CONCAT_VVSVVV(&className, &_2$$4, &_3$$4, "\\", &verb_zv, &_7$$4, &_9$$4);
			if (zephir_class_exists(&className, 1)) {
				zephir_create_array(return_value, 2, 0);
				zephir_array_fast_append(return_value, &className);
				ZEPHIR_CALL_FUNCTION(&_10$$5, "array_slice", &_1, 271, &segments, &index);
				zephir_check_call_status();
				zephir_array_fast_append(return_value, &_10$$5);
				RETURN_MM();
			}
		}
		ZEPHIR_OBS_NVAR(&resourceName);
		zephir_array_fetch(&resourceName, &head, &last, PH_NOISY, "phalcon/ADR/Router/Router.zep", 122);
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 360, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_11$$3, this_ptr, "tonamespace", &_6, 333, &head);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_12$$3, this_ptr, "camelize", &_8, 334, &resourceName);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&className);
		ZEPHIR_CONCAT_VVSVV(&className, &_0$$3, &_11$$3, "\\", &verb_zv, &_12$$3);
		if (zephir_class_exists(&className, 1)) {
			zephir_create_array(return_value, 2, 0);
			zephir_array_fast_append(return_value, &className);
			ZEPHIR_CALL_FUNCTION(&_13$$6, "array_slice", &_1, 271, &segments, &index);
			zephir_check_call_status();
			zephir_array_fast_append(return_value, &_13$$6);
			RETURN_MM();
		}
		_14$$3 = (zephir_get_numberval(&index) - 1);
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_LONG(&index, _14$$3);
	}
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
	zephir_is_iterable(&_0, 0, "phalcon/ADR/Router/Router.zep", 150);
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
			ZEPHIR_CALL_FUNCTION(&_6$$3, "strncmp", &_7, 335, &className_zv, &full, &_5$$3);
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
				ZEPHIR_CALL_FUNCTION(&_13$$5, "strncmp", &_7, 335, &className_zv, &full, &_12$$5);
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
	zephir_is_iterable(&segments, 0, "phalcon/ADR/Router/Router.zep", 162);
	if (Z_TYPE_P(&segments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&segments), _0)
		{
			ZEPHIR_INIT_NVAR(&segment);
			ZVAL_COPY(&segment, _0);
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "camelize", &_2, 334, &segment);
			zephir_check_call_status();
			zephir_array_append(&parts, &_1$$3, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 159);
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
				ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "camelize", &_2, 334, &segment);
				zephir_check_call_status();
				zephir_array_append(&parts, &_5$$4, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 159);
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

