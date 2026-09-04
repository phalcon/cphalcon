
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
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
 *
 * Implementation of this file has also been heavily influenced by Autoroute.
 *
 * @link    https://pmjones.io/adr/
 *
 * @link    https://github.com/pmjones/AutoRoute
 * @license https://github.com/pmjones/AutoRoute/blob/2.x/LICENSE.md
 */
/**
 * Convention router. `method + static path -> Action class`; the path tail
 * becomes positional request attributes. Middleware is resolved from a
 * namespace-prefix map (group semantics); global middleware stays on the
 * pipeline. No route table.
 *
 * ## The convention
 *
 * Every static path segment is a namespace segment, and the class name is the
 * verb followed by all of those segments concatenated:
 *
 *     GET  /                      -> Get
 *     GET  /profiles              -> Profiles\GetProfiles
 *     GET  /company/all           -> Company\All\GetCompanyAll
 *     GET  /company/all/7         -> Company\All\GetCompanyAll  with ["7"]
 *     POST /session/forgot-password -> Session\ForgotPassword\PostSessionForgotPassword
 *
 * ## Guarantees
 *
 * - One path names exactly one class; that class names exactly one path.
 * - The derived name must equal the declared class name byte for byte. A
 *   class that only resolves case-insensitively is not a match.
 * - `classFor()` and `pathFor()` are pure functions of their input. Neither
 *   touches the filesystem, and neither consults any Action but the one it was
 *   given, so adding or deleting an Action can never move another one's URL.
 * - There is no candidate list and no first-that-exists. Nothing can be
 *   shadowed.
 *
 * ## Constraints - these are load-bearing, not style
 *
 * - **Arguments always trail the static path.** `/album/edit/1`, never
 *   `/album/1/edit`. A class name encodes which segments exist, not where a
 *   value sits among them; putting an argument in the middle would require
 *   consulting some other Action to find the boundary, and that is exactly the
 *   coupling this convention exists to avoid.
 * - **`params()` never affects routing.** It constrains, casts and converts
 *   attributes after a match. A wrong declaration is a validation bug, never a
 *   404.
 * - **No route table, no compile step, no cache.** Resolution is a string
 *   derivation plus one `class_exists`. In PHP's shared-nothing model a table
 *   must be rebuilt or reloaded on every request, and that cost dominates
 *   matching - which is why this router is faster in practice than a cached
 *   table-driven one.
 * - **Nothing may be layered onto the naming convention** to express argument
 *   position, arity or ordering. Any such declaration is a path template in
 *   disguise, and a path template belongs in a declared-route router, not here.
 *
 * The cost of all of this is `/album/edit/1` rather than `/album/1/edit`. That
 * is a spelling difference, not a capability one - and it is not a deviation
 * from any standard. REST is Fielding's dissertation, not an RFC; RFC 3986 and
 * RFC 9110 both leave path structure entirely to the origin server.
 *
 * @phpstan-import-type adr_action_params from ADRTypes
 * @phpstan-import-type adr_located_route from ADRTypes
 * @phpstan-import-type adr_middleware_map from ADRTypes
 * @phpstan-import-type adr_middleware_names from ADRTypes
 * @phpstan-import-type adr_route_candidate from ADRTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_Router)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Router, Router, phalcon, adr_router_router, phalcon_adr_router_router_method_entry, ZEND_ACC_FINAL_CLASS);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_adr_router_router_ce, SL("actionDirectory"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_adr_router_router_ce, SL("baseNamespace"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * @phpstan-var adr_middleware_map
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_adr_router_router_ce, SL("middlewareMap"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "-", sizeof("-") - 1);
		zephir_declare_typed_property(phalcon_adr_router_router_ce, SL("wordSeparator"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	zend_class_implements(phalcon_adr_router_router_ce, 1, phalcon_contracts_adr_router_router_ce);
	return SUCCESS;
}

/**
 * Every Action class this router would try for the given method and path,
 * in the order it tries them. The first that exists wins at match time.
 * Namespace descent consults the filesystem, so the list depends on the
 * action directory.
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "derivecandidates", NULL, 342, &method_zv, &path_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 0);
	ZEPHIR_RETURN_CALL_FUNCTION("array_column", NULL, 343, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * The class this convention names for a fully static path, derived without
 * consulting the filesystem.
 *
 * candidatesFor() cannot answer this. It walks the action directory to find
 * where static segments end, so a path whose directories do not exist yet
 * yields nothing - and a generator needs the name precisely in order to
 * create them. Every static segment is a namespace segment, so the answer
 * is unambiguous and pathFor() inverts it exactly.
 *
 * Placeholders are the caller's concern: pass the static prefix only.
 */
PHP_METHOD(Phalcon_ADR_Router_Router, classFor)
{
	zval parts;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method_zv, path_zv, segment, segments, uri, verb, _0, _1, *_3, _4, *_5, _8, _9, _10, _2$$3, _6$$4;
	zend_string *method = NULL, *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&segment);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&verb);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&parts);
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
	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
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
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 371, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CONCAT_VSV(return_value, &_2$$3, "\\", &verb);
		RETURN_MM();
	}
	if (Z_TYPE_P(&segments) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &segments);
		_3 = &_4;
	} else {
		_3 = &segments;
	}
	zephir_is_iterable(_3, 0, "phalcon/ADR/Router/Router.zep", 139);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
	{
		ZEPHIR_INIT_NVAR(&segment);
		ZVAL_COPY(&segment, _5);
		ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "camelize", &_7, 344, &segment);
		zephir_check_call_status();
		zephir_array_append(&parts, &_6$$4, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 136);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&segment);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_0, 371, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_9);
	zephir_fast_join_str(&_9, SL("\\"), &parts);
	ZEPHIR_INIT_VAR(&_10);
	zephir_fast_join_str(&_10, SL(""), &parts);
	ZEPHIR_CONCAT_VSVSVV(return_value, &_8, "\\", &_9, "\\", &verb, &_10);
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Router, match)
{
	zend_bool _18, _13$$5, _20$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, path, method, located, other, _0, _2, _7, *_8, _9, *_10, _17, _1$$3, _3$$4, _4$$4, _5$$4, _6$$4, _11$$5, _14$$5, _15$$6, _19$$7, _21$$7, _22$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&located);
	ZVAL_UNDEF(&other);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$8);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("actionDirectory", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_http_requestinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 372, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING_IDENTICAL(&_0, "")) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_adr_exceptions_actiondirectorynotset_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 345);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/ADR/Router/Router.zep", 149);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_CALL_METHOD(&path, request, "geturi", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&method, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&located, this_ptr, "locate", NULL, 346, &method, &path);
	zephir_check_call_status();
	if (Z_TYPE_P(&located) == IS_ARRAY) {
		object_init_ex(return_value, phalcon_adr_router_routermatch_ce);
		zephir_array_fetch_long(&_3$$4, &located, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 158);
		zephir_array_fetch_long(&_4$$4, &located, 1, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 159);
		zephir_array_fetch_long(&_6$$4, &located, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 160);
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "middlewarefor", NULL, 347, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 348, &_3$$4, &_4$$4, &_5$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "verbs", NULL, 349);
	zephir_check_call_status();
	if (Z_TYPE_P(&_7) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_9);
		zephir_string_to_char_array(&_9, &_7);
		_8 = &_9;
	} else {
		_8 = &_7;
	}
	zephir_is_iterable(_8, 0, "phalcon/ADR/Router/Router.zep", 170);
	if (Z_TYPE_P(_8) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_8), _10)
		{
			ZEPHIR_INIT_NVAR(&other);
			ZVAL_COPY(&other, _10);
			ZEPHIR_CALL_FUNCTION(&_11$$5, "strcasecmp", &_12, 87, &other, &method);
			zephir_check_call_status();
			_13$$5 = !ZEPHIR_IS_LONG_IDENTICAL(&_11$$5, 0);
			if (_13$$5) {
				ZEPHIR_CALL_METHOD(&_14$$5, this_ptr, "locate", NULL, 346, &other, &path);
				zephir_check_call_status();
				_13$$5 = Z_TYPE_P(&_14$$5) == IS_ARRAY;
			}
			if (_13$$5) {
				ZEPHIR_INIT_NVAR(&_15$$6);
				object_init_ex(&_15$$6, phalcon_adr_exceptions_methodnotallowed_ce);
				ZEPHIR_CALL_METHOD(NULL, &_15$$6, "__construct", &_16, 350);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_15$$6, "phalcon/ADR/Router/Router.zep", 166);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _8, "rewind", NULL, 0);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _8, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_17, _8, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&other, _8, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_19$$7, "strcasecmp", &_12, 87, &other, &method);
				zephir_check_call_status();
				_20$$7 = !ZEPHIR_IS_LONG_IDENTICAL(&_19$$7, 0);
				if (_20$$7) {
					ZEPHIR_CALL_METHOD(&_21$$7, this_ptr, "locate", NULL, 346, &other, &path);
					zephir_check_call_status();
					_20$$7 = Z_TYPE_P(&_21$$7) == IS_ARRAY;
				}
				if (_20$$7) {
					ZEPHIR_INIT_NVAR(&_22$$8);
					object_init_ex(&_22$$8, phalcon_adr_exceptions_methodnotallowed_ce);
					ZEPHIR_CALL_METHOD(NULL, &_22$$8, "__construct", &_16, 350);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_22$$8, "phalcon/ADR/Router/Router.zep", 166);
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&other);
	RETURN_MM_NULL();
}

PHP_METHOD(Phalcon_ADR_Router_Router, methodFor)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, verb, _0;
	zend_string *className = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&verb);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	ZEPHIR_CALL_METHOD(&verb, this_ptr, "verbof", NULL, 351, &className_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(&verb) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_NULL(&_0);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_fast_strtoupper(&_0, &verb);
	}
	RETURN_CCTOR(&_0);
}

PHP_METHOD(Phalcon_ADR_Router_Router, pathFor)
{
	zend_bool _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, name, names, part, parts, path, _0, _1, _2, _3, *_4, _5, *_6, _10, _14, *_15, _16, *_17, _7$$5, _9$$5, _12$$6, _13$$6, _18$$7;
	zend_string *className = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_18$$7);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("baseNamespace", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "verbof", NULL, 351, &className_zv);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_NULL) {
		RETURN_MM_NULL();
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 371, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, (zephir_fast_strlen_ev(&_1) + 1));
	ZEPHIR_INIT_VAR(&_3);
	zephir_substr(&_3, &className_zv, zephir_get_intval(&_2), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("\\"), &_3, LONG_MAX);
	ZEPHIR_MAKE_REF(&parts);
	ZEPHIR_CALL_FUNCTION(NULL, "array_pop", NULL, 352, &parts);
	ZEPHIR_UNREF(&parts);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&parts)) {
		RETURN_MM_STRING("/");
	}
	ZEPHIR_INIT_VAR(&path);
	ZVAL_STRING(&path, "");
	if (Z_TYPE_P(&parts) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &parts);
		_4 = &_5;
	} else {
		_4 = &parts;
	}
	zephir_is_iterable(_4, 0, "phalcon/ADR/Router/Router.zep", 216);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4), _6)
		{
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _6);
			ZEPHIR_CALL_METHOD(&_7$$5, this_ptr, "decamelize", &_8, 353, &part);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_9$$5);
			ZEPHIR_CONCAT_VSV(&_9$$5, &path, "/", &_7$$5);
			ZEPHIR_CPY_WRT(&path, &_9$$5);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_10, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&part, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_12$$6, this_ptr, "decamelize", &_8, 353, &part);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$6);
				ZEPHIR_CONCAT_VSV(&_13$$6, &path, "/", &_12$$6);
				ZEPHIR_CPY_WRT(&path, &_13$$6);
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "actionparams", NULL, 354, &className_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&names);
	zephir_array_keys(&names, &_14);
	if (Z_TYPE_P(&names) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_16);
		zephir_string_to_char_array(&_16, &names);
		_15 = &_16;
	} else {
		_15 = &names;
	}
	zephir_is_iterable(_15, 0, "phalcon/ADR/Router/Router.zep", 222);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_15), _17)
	{
		ZEPHIR_INIT_NVAR(&name);
		ZVAL_COPY(&name, _17);
		ZEPHIR_INIT_NVAR(&_18$$7);
		ZEPHIR_CONCAT_VSVS(&_18$$7, &path, "/{", &name, "}");
		ZEPHIR_CPY_WRT(&path, &_18$$7);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&path);
}

PHP_METHOD(Phalcon_ADR_Router_Router, setActionDirectory)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval actionDirectory_zv, _0, _1;
	zend_string *actionDirectory = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionDirectory_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("actionDirectory", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionDirectory)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&actionDirectory_zv);
	ZVAL_STR_COPY(&actionDirectory_zv, actionDirectory);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, &actionDirectory_zv, &_1, ZEPHIR_TRIM_RIGHT);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 372, &_0);
	RETURN_THIS();
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 371, &_0);
	RETURN_THIS();
}

/**
 * @phpstan-param adr_middleware_map $middlewareMap
 */
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 373, &middlewareMap);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_ADR_Router_Router, setWordSeparator)
{
	zval wordSeparator_zv;
	zend_string *wordSeparator = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&wordSeparator_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("wordSeparator", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(wordSeparator)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&wordSeparator_zv, wordSeparator);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 374, &wordSeparator_zv);
	RETURN_THISW();
}

/**
 * An Action's declared positional parameters, or an empty array when it
 * declares none.
 *
 * This is what lets an argument sit *between* two static segments: the
 * walk needs to know how many segments a level consumes before it can
 * carry on matching. `params()` is static and already exists for filtering
 * and casting, so nothing new is asked of an Action - but declaring it now
 * decides routing, not just validation.
 *
 * @phpstan-return adr_action_params
 */
PHP_METHOD(Phalcon_ADR_Router_Router, actionParams)
{
	zval _1;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, params, _2;
	zend_string *className = NULL;

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	_0 = !(zephir_class_exists(&className_zv, 1));
	if (!(_0)) {
		_0 = !((zephir_method_exists_ex(&className_zv, ZEND_STRL("params")) == SUCCESS));
	}
	if (_0) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	zephir_array_fast_append(&_1, &className_zv);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "params");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&params);
	ZEPHIR_CALL_USER_FUNC(&params, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	if (Z_TYPE_P(&params) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&_2, &params);
	} else {
		ZEPHIR_INIT_NVAR(&_2);
		array_init(&_2);
	}
	RETURN_CCTOR(&_2);
}

PHP_METHOD(Phalcon_ADR_Router_Router, camelize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval segment_zv, _0, _1, _2, _3, _4;
	zend_string *segment = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&segment_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("wordSeparator", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(segment)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&segment_zv);
	ZVAL_STR_COPY(&segment_zv, segment);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 374, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 374, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_2, "ucwords", NULL, 355, &segment_zv, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_str_replace(&_4, &_0, &_3, &_2);
	RETURN_CCTOR(&_4);
}

PHP_METHOD(Phalcon_ADR_Router_Router, decamelize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval part_zv, _0, _1, _2, _3;
	zend_string *part = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&part_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("wordSeparator", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(part)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&part_zv);
	ZVAL_STR_COPY(&part_zv, part);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 374, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "$1", &_0, "$2");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/([a-z0-9])([A-Z])/");
	ZEPHIR_CALL_FUNCTION(&_3, "preg_replace", NULL, 6, &_2, &_1, &part_zv);
	zephir_check_call_status();
	zephir_fast_strtolower(return_value, &_3);
	RETURN_MM();
}

/**
 * The single derivation of the routing convention.
 *
 * Every static path segment becomes a namespace segment, and the class name
 * is the verb followed by all of those segments concatenated - so
 * `/company/all` is `Company\All\GetCompanyAll` and nothing else. One path
 * yields exactly one class, and pathFor() inverts it exactly.
 *
 * Segments are consumed while the matching directory exists; whatever
 * remains is a dynamic argument. That walk decides where static ends and
 * dynamic begins - it no longer chooses between competing class shapes,
 * because there is only one.
 *
 * @phpstan-return list<adr_route_candidate>
 */
PHP_METHOD(Phalcon_ADR_Router_Router, deriveCandidates)
{
	zval parts, _12, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method_zv, path_zv, candidate, className, segment, subNamespace, segments, uri, verb, _0, _1, _10, _11, _2$$3, _4$$3, _5$$4, _7$$4;
	zend_string *method = NULL, *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&candidate);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&segment);
	ZVAL_UNDEF(&subNamespace);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&verb);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_3$$3);
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
	ZEPHIR_INIT_VAR(&subNamespace);
	ZVAL_STRING(&subNamespace, "");
	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
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
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 371, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&className);
		ZEPHIR_CONCAT_VSV(&className, &_2$$3, "\\", &verb);
		zephir_create_array(return_value, 1, 0);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 2, 0);
		zephir_array_fast_append(&_3$$3, &className);
		ZEPHIR_INIT_VAR(&_4$$3);
		array_init(&_4$$3);
		zephir_array_fast_append(&_3$$3, &_4$$3);
		zephir_array_fast_append(return_value, &_3$$3);
		RETURN_MM();
	}
	while (1) {
		if (!(!(ZEPHIR_IS_EMPTY(&segments)))) {
			break;
		}
		zephir_array_fetch_long(&_5$$4, &segments, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 334);
		ZEPHIR_CALL_METHOD(&segment, this_ptr, "camelize", &_6, 344, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&candidate);
		ZEPHIR_CONCAT_VSV(&candidate, &subNamespace, "\\", &segment);
		ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "hassubnamespace", &_8, 356, &candidate);
		zephir_check_call_status();
		if (!(zephir_is_true(&_7$$4))) {
			break;
		}
		ZEPHIR_CPY_WRT(&subNamespace, &candidate);
		zephir_array_append(&parts, &segment, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 342);
		ZEPHIR_MAKE_REF(&segments);
		ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_9, 41, &segments);
		ZEPHIR_UNREF(&segments);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_EMPTY(&parts)) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_read_property_cached(&_10, this_ptr, _zephir_prop_0, 371, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_11);
	zephir_fast_join_str(&_11, SL(""), &parts);
	ZEPHIR_INIT_NVAR(&className);
	ZEPHIR_CONCAT_VVSVV(&className, &_10, &subNamespace, "\\", &verb, &_11);
	zephir_create_array(return_value, 1, 0);
	ZEPHIR_INIT_VAR(&_12);
	zephir_create_array(&_12, 2, 0);
	zephir_array_fast_append(&_12, &className);
	zephir_array_fast_append(&_12, &segments);
	zephir_array_fast_append(return_value, &_12);
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Router, hasSubNamespace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval subNamespace_zv, _0, _1, _2, _3, _4;
	zend_string *subNamespace = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subNamespace_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("actionDirectory", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(subNamespace)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&subNamespace_zv);
	ZVAL_STR_COPY(&subNamespace_zv, subNamespace);
	if (zephir_memnstr_str(&subNamespace_zv, SL(".."), "phalcon/ADR/Router/Router.zep", 365)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 372, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/");
	zephir_fast_str_replace(&_1, &_2, &_3, &subNamespace_zv);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_1);
	ZEPHIR_RETURN_CALL_FUNCTION("is_dir", NULL, 166, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @phpstan-return adr_located_route|null
 */
PHP_METHOD(Phalcon_ADR_Router_Router, locate)
{
	zend_bool _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method_zv, path_zv, candidate, candidates, reflection, *_0, _1, *_2, _9, _3$$3, _4$$3, _6$$3, _8$$3, _11$$6, _12$$6, _13$$6, _14$$6;
	zend_string *method = NULL, *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&candidate);
	ZVAL_UNDEF(&candidates);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
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
	ZEPHIR_CALL_METHOD(&candidates, this_ptr, "derivecandidates", NULL, 342, &method_zv, &path_zv);
	zephir_check_call_status();
	if (Z_TYPE_P(&candidates) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_string_to_char_array(&_1, &candidates);
		_0 = &_1;
	} else {
		_0 = &candidates;
	}
	zephir_is_iterable(_0, 0, "phalcon/ADR/Router/Router.zep", 401);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0), _2)
		{
			ZEPHIR_INIT_NVAR(&candidate);
			ZVAL_COPY(&candidate, _2);
			zephir_array_fetch_long(&_3$$3, &candidate, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 385);
			if (!(zephir_class_exists(&_3$$3, 1))) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&reflection);
			object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
			zephir_array_fetch_long(&_4$$3, &candidate, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 395);
			ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", &_5, 251, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6$$3, &reflection, "getname", &_7, 253);
			zephir_check_call_status();
			zephir_array_fetch_long(&_8$$3, &candidate, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 396);
			if (ZEPHIR_IS_IDENTICAL(&_6$$3, &_8$$3)) {
				RETURN_CCTOR(&candidate);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _0, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, _0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&candidate, _0, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_long(&_11$$6, &candidate, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 385);
				if (!(zephir_class_exists(&_11$$6, 1))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&reflection);
				object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
				zephir_array_fetch_long(&_12$$6, &candidate, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 395);
				ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", &_5, 251, &_12$$6);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_13$$6, &reflection, "getname", &_7, 253);
				zephir_check_call_status();
				zephir_array_fetch_long(&_14$$6, &candidate, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 396);
				if (ZEPHIR_IS_IDENTICAL(&_13$$6, &_14$$6)) {
					RETURN_CCTOR(&candidate);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&candidate);
	RETURN_MM_NULL();
}

/**
 * @phpstan-return adr_middleware_names
 */
PHP_METHOD(Phalcon_ADR_Router_Router, middlewareFor)
{
	zend_bool _12;
	zend_ulong _4;
	zval stacked;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, full, list, prefix, _0, *_1, _2, *_3, _11, _6$$3, _7$$3, _8$$3, _10$$4, _13$$5, _14$$5, _15$$5, _16$$6;
	zend_string *className = NULL, *_5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&full);
	ZVAL_UNDEF(&list);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&stacked);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 373, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/ADR/Router/Router.zep", 420);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&prefix);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&prefix, _5);
			} else {
				ZVAL_LONG(&prefix, _4);
			}
			ZEPHIR_INIT_NVAR(&list);
			ZVAL_COPY(&list, _3);
			zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_1, 371, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&full);
			ZEPHIR_CONCAT_VV(&full, &_6$$3, &prefix);
			ZVAL_LONG(&_7$$3, zephir_fast_strlen_ev(&full));
			ZEPHIR_CALL_FUNCTION(&_8$$3, "strncmp", &_9, 357, &className_zv, &full, &_7$$3);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_8$$3, 0)) {
				ZEPHIR_INIT_NVAR(&_10$$4);
				zephir_fast_array_merge(&_10$$4, &stacked, &list);
				ZEPHIR_CPY_WRT(&stacked, &_10$$4);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&prefix, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&list, _1, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property_cached(&_13$$5, this_ptr, _zephir_prop_1, 371, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&full);
				ZEPHIR_CONCAT_VV(&full, &_13$$5, &prefix);
				ZVAL_LONG(&_14$$5, zephir_fast_strlen_ev(&full));
				ZEPHIR_CALL_FUNCTION(&_15$$5, "strncmp", &_9, 357, &className_zv, &full, &_14$$5);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_15$$5, 0)) {
					ZEPHIR_INIT_NVAR(&_16$$6);
					zephir_fast_array_merge(&_16$$6, &stacked, &list);
					ZEPHIR_CPY_WRT(&stacked, &_16$$6);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&list);
	ZEPHIR_INIT_NVAR(&prefix);
	RETURN_CTOR(&stacked);
}

/**
 * The class-name-form verb the given Action class carries, or null when the
 * class is not one this convention would have produced.
 *
 * The class name is the verb followed by every namespace segment, so the
 * namespace alone reconstructs the static path and the class name only has
 * to agree with it. Anything that does not agree is not a class this
 * convention would ever have produced.
 *
 * Shared by pathFor() and methodFor() so that rule is stated once.
 */
PHP_METHOD(Phalcon_ADR_Router_Router, verbOf)
{
	zend_bool _14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, __$true, candidate, last, parts, prefix, _0, _1, _2, _3, _7, *_8, _9, *_10, _13, _4$$4, _5$$4, _6$$4, _11$$5, _12$$5, _15$$7, _16$$7;
	zend_string *className = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&candidate);
	ZVAL_UNDEF(&last);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("baseNamespace", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 371, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&prefix);
	ZEPHIR_CONCAT_VS(&prefix, &_0, "\\");
	ZVAL_LONG(&_1, zephir_fast_strlen_ev(&prefix));
	ZEPHIR_CALL_FUNCTION(&_2, "strncmp", NULL, 357, &className_zv, &prefix, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_2, 0)) {
		RETURN_MM_NULL();
	}
	ZVAL_LONG(&_1, zephir_fast_strlen_ev(&prefix));
	ZEPHIR_INIT_VAR(&_3);
	zephir_substr(&_3, &className_zv, zephir_get_intval(&_1), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("\\"), &_3, LONG_MAX);
	ZEPHIR_MAKE_REF(&parts);
	ZEPHIR_CALL_FUNCTION(&last, "array_pop", NULL, 352, &parts);
	ZEPHIR_UNREF(&parts);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&parts)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "verbs", NULL, 349);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_6$$4, "in_array", NULL, 89, &last, &_5$$4, &__$true);
		zephir_check_call_status();
		if (zephir_is_true(&_6$$4)) {
			ZEPHIR_CPY_WRT(&_4$$4, &last);
		} else {
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_NULL(&_4$$4);
		}
		RETURN_CCTOR(&_4$$4);
	}
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "verbs", NULL, 349);
	zephir_check_call_status();
	if (Z_TYPE_P(&_7) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_9);
		zephir_string_to_char_array(&_9, &_7);
		_8 = &_9;
	} else {
		_8 = &_7;
	}
	zephir_is_iterable(_8, 0, "phalcon/ADR/Router/Router.zep", 457);
	if (Z_TYPE_P(_8) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_8), _10)
		{
			ZEPHIR_INIT_NVAR(&candidate);
			ZVAL_COPY(&candidate, _10);
			ZEPHIR_INIT_NVAR(&_11$$5);
			zephir_fast_join_str(&_11$$5, SL(""), &parts);
			ZEPHIR_INIT_NVAR(&_12$$5);
			ZEPHIR_CONCAT_VV(&_12$$5, &candidate, &_11$$5);
			if (ZEPHIR_IS_IDENTICAL(&last, &_12$$5)) {
				RETURN_CCTOR(&candidate);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _8, "rewind", NULL, 0);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _8, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_13, _8, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&candidate, _8, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$7);
				zephir_fast_join_str(&_15$$7, SL(""), &parts);
				ZEPHIR_INIT_NVAR(&_16$$7);
				ZEPHIR_CONCAT_VV(&_16$$7, &candidate, &_15$$7);
				if (ZEPHIR_IS_IDENTICAL(&last, &_16$$7)) {
					RETURN_CCTOR(&candidate);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&candidate);
	RETURN_MM_NULL();
}

/**
 * The HTTP verbs the convention recognizes, in class-name form.
 *
 * @return list<string>
 */
PHP_METHOD(Phalcon_ADR_Router_Router, verbs)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_create_array(return_value, 5, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Get");
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Post");
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Put");
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Patch");
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Delete");
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();
}

