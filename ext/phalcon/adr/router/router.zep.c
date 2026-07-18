
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
#include "kernel/exception.h"
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
	 * @var array<string, string>
	 */
	zend_declare_property_null(phalcon_adr_router_router_ce, SL("middlewareMap"), ZEND_ACC_PROTECTED);
	phalcon_adr_router_router_ce->create_object = zephir_init_properties_Phalcon_ADR_Router_Router;

	zend_class_implements(phalcon_adr_router_router_ce, 1, phalcon_contracts_adr_router_router_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Router_Router, match)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_10 = NULL, *_12 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _14$$3;
	zval *request, request_sub, uri, verb, segments, index, prefix, className, params, _0, _1, _2, _3, _4, _15, _5$$3, _6$$3, _7$$3, _8$$3, _11$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&verb);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_11$$4);
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
	ZEPHIR_INIT_VAR(&index);
	ZVAL_LONG(&index, zephir_fast_count_int(&segments));
	while (1) {
		if (!(ZEPHIR_GE_LONG(&index, 0))) {
			break;
		}
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_0, 358, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_7$$3, 0);
		ZEPHIR_CALL_FUNCTION(&_8$$3, "array_slice", &_9, 270, &segments, &_7$$3, &index);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "tonamespace", &_10, 320, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&prefix);
		ZEPHIR_CONCAT_VV(&prefix, &_5$$3, &_6$$3);
		ZEPHIR_INIT_NVAR(&className);
		ZEPHIR_CONCAT_VSV(&className, &prefix, "\\", &verb);
		if (zephir_class_exists(&className, 1)) {
			ZEPHIR_CALL_FUNCTION(&params, "array_slice", &_9, 270, &segments, &index);
			zephir_check_call_status();
			object_init_ex(return_value, phalcon_adr_router_routermatch_ce);
			ZEPHIR_CALL_METHOD(&_11$$4, this_ptr, "middlewarefor", &_12, 321, &className);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_13, 322, &className, &params, &_11$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		_14$$3 = (zephir_get_numberval(&index) - 1);
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_LONG(&index, _14$$3);
	}
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "routableunderanotherverb", NULL, 323, &segments);
	zephir_check_call_status();
	if (zephir_is_true(&_15)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_adr_router_exceptions_methodnotallowed_ce, "The request method is not allowed for the matched route.", "phalcon/ADR/Router/Router.zep", 62);
		return;
	}
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 358, &_0);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 359, &middlewareMap);
	RETURN_THIS();
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 359, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/ADR/Router/Router.zep", 95);
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
			zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_1, 358, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&full);
			ZEPHIR_CONCAT_VV(&full, &_4$$3, &prefix);
			ZVAL_LONG(&_5$$3, zephir_fast_strlen_ev(&full));
			ZEPHIR_CALL_FUNCTION(&_6$$3, "strncmp", &_7, 324, &className_zv, &full, &_5$$3);
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
				zephir_read_property_cached(&_11$$5, this_ptr, _zephir_prop_1, 358, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&full);
				ZEPHIR_CONCAT_VV(&full, &_11$$5, &prefix);
				ZVAL_LONG(&_12$$5, zephir_fast_strlen_ev(&full));
				ZEPHIR_CALL_FUNCTION(&_13$$5, "strncmp", &_7, 324, &className_zv, &full, &_12$$5);
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

PHP_METHOD(Phalcon_ADR_Router_Router, routableUnderAnotherVerb)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _9$$3;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zval *segments_param = NULL, index, prefix, verb, verbs, _0, _1$$3, _2$$3, _3$$3, _4$$3, *_7$$3, _8$$4;
	zval segments;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&verb);
	ZVAL_UNDEF(&verbs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("baseNamespace", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(segments, segments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &segments_param);
	zephir_get_arrval(&segments, segments_param);
	ZEPHIR_INIT_VAR(&verbs);
	zephir_create_array(&verbs, 5, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Get");
	zephir_array_fast_append(&verbs, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Post");
	zephir_array_fast_append(&verbs, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Put");
	zephir_array_fast_append(&verbs, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Patch");
	zephir_array_fast_append(&verbs, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Delete");
	zephir_array_fast_append(&verbs, &_0);
	ZEPHIR_INIT_VAR(&index);
	ZVAL_LONG(&index, zephir_fast_count_int(&segments));
	while (1) {
		if (!(ZEPHIR_GE_LONG(&index, 0))) {
			break;
		}
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 358, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "array_slice", &_5, 270, &segments, &_3$$3, &index);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "tonamespace", &_6, 320, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&prefix);
		ZEPHIR_CONCAT_VV(&prefix, &_1$$3, &_2$$3);
		zephir_is_iterable(&verbs, 0, "phalcon/ADR/Router/Router.zep", 114);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&verbs), _7$$3)
		{
			ZEPHIR_INIT_NVAR(&verb);
			ZVAL_COPY(&verb, _7$$3);
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZEPHIR_CONCAT_VSV(&_8$$4, &prefix, "\\", &verb);
			if (zephir_class_exists(&_8$$4, 1)) {
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&verb);
		_9$$3 = (zephir_get_numberval(&index) - 1);
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_LONG(&index, _9$$3);
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Phalcon_ADR_Router_Router, toNamespace)
{
	zend_bool _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *segments_param = NULL, segment, parts, *_0, _9, _18, _1$$3, _2$$3, _4$$3, _5$$3, _7$$3, _8$$3, _11$$4, _12$$4, _14$$4, _15$$4, _16$$4, _17$$4;
	zval segments, _3$$3, _13$$4;

	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&segment);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(segments, segments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &segments_param);
	zephir_get_arrval(&segments, segments_param);
	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	zephir_is_iterable(&segments, 0, "phalcon/ADR/Router/Router.zep", 129);
	if (Z_TYPE_P(&segments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&segments), _0)
		{
			ZEPHIR_INIT_NVAR(&segment);
			ZVAL_COPY(&segment, _0);
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			zephir_create_array(&_3$$3, 2, 0);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "-");
			zephir_array_fast_append(&_3$$3, &_4$$3);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "_");
			zephir_array_fast_append(&_3$$3, &_4$$3);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, " ");
			zephir_fast_str_replace(&_2$$3, &_3$$3, &_4$$3, &segment);
			ZEPHIR_CALL_FUNCTION(&_5$$3, "ucwords", &_6, 325, &_2$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZVAL_STRING(&_7$$3, " ");
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "");
			zephir_fast_str_replace(&_1$$3, &_7$$3, &_8$$3, &_5$$3);
			zephir_array_append(&parts, &_1$$3, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 126);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &segments, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &segments, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, &segments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&segment, &segments, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$4);
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZEPHIR_INIT_NVAR(&_13$$4);
				zephir_create_array(&_13$$4, 2, 0);
				ZEPHIR_INIT_NVAR(&_14$$4);
				ZVAL_STRING(&_14$$4, "-");
				zephir_array_fast_append(&_13$$4, &_14$$4);
				ZEPHIR_INIT_NVAR(&_14$$4);
				ZVAL_STRING(&_14$$4, "_");
				zephir_array_fast_append(&_13$$4, &_14$$4);
				ZEPHIR_INIT_NVAR(&_14$$4);
				ZVAL_STRING(&_14$$4, " ");
				zephir_fast_str_replace(&_12$$4, &_13$$4, &_14$$4, &segment);
				ZEPHIR_CALL_FUNCTION(&_15$$4, "ucwords", &_6, 325, &_12$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$4);
				ZVAL_STRING(&_16$$4, " ");
				ZEPHIR_INIT_NVAR(&_17$$4);
				ZVAL_STRING(&_17$$4, "");
				zephir_fast_str_replace(&_11$$4, &_16$$4, &_17$$4, &_15$$4);
				zephir_array_append(&parts, &_11$$4, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 126);
		}
	}
	ZEPHIR_INIT_NVAR(&segment);
	if (ZEPHIR_IS_EMPTY(&parts)) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_INIT_VAR(&_18);
	zephir_fast_join_str(&_18, SL("\\"), &parts);
	ZEPHIR_CONCAT_SV(return_value, "\\", &_18);
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

