
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
	 * @var array<string, string[]>
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "derivecandidates", NULL, 330, &method_zv, &path_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 0);
	ZEPHIR_RETURN_CALL_FUNCTION("array_column", NULL, 331, &_0, &_1);
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
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method_zv, path_zv, segment, segments, uri, verb, _0, _1, *_3, _6, _7, _8, _2$$3, _4$$4;
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
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
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 362, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CONCAT_VSV(return_value, &_2$$3, "\\", &verb);
		RETURN_MM();
	}
	zephir_is_iterable(&segments, 0, "phalcon/ADR/Router/Router.zep", 130);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&segments), _3)
	{
		ZEPHIR_INIT_NVAR(&segment);
		ZVAL_COPY(&segment, _3);
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "camelize", &_5, 332, &segment);
		zephir_check_call_status();
		zephir_array_append(&parts, &_4$$4, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 127);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&segment);
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_0, 362, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_join_str(&_7, SL("\\"), &parts);
	ZEPHIR_INIT_VAR(&_8);
	zephir_fast_join_str(&_8, SL(""), &parts);
	ZEPHIR_CONCAT_VSVSVV(return_value, &_6, "\\", &_7, "\\", &verb, &_8);
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Router, match)
{
	zend_bool _16, _11$$5, _18$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, path, method, located, other, _0, _2, _7, *_8, _15, _1$$3, _3$$4, _4$$4, _5$$4, _6$$4, _9$$5, _12$$5, _13$$6, _17$$7, _19$$7, _20$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&located);
	ZVAL_UNDEF(&other);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$8);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 363, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING_IDENTICAL(&_0, "")) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_adr_exceptions_actiondirectorynotset_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 333);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/ADR/Router/Router.zep", 140);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_CALL_METHOD(&path, request, "geturi", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&method, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&located, this_ptr, "locate", NULL, 334, &method, &path);
	zephir_check_call_status();
	if (Z_TYPE_P(&located) == IS_ARRAY) {
		object_init_ex(return_value, phalcon_adr_router_routermatch_ce);
		zephir_array_fetch_long(&_3$$4, &located, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 149);
		zephir_array_fetch_long(&_4$$4, &located, 1, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 150);
		zephir_array_fetch_long(&_6$$4, &located, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 151);
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "middlewarefor", NULL, 335, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 336, &_3$$4, &_4$$4, &_5$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "verbs", NULL, 337);
	zephir_check_call_status();
	zephir_is_iterable(&_7, 0, "phalcon/ADR/Router/Router.zep", 161);
	if (Z_TYPE_P(&_7) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_7), _8)
		{
			ZEPHIR_INIT_NVAR(&other);
			ZVAL_COPY(&other, _8);
			ZEPHIR_CALL_FUNCTION(&_9$$5, "strcasecmp", &_10, 85, &other, &method);
			zephir_check_call_status();
			_11$$5 = !ZEPHIR_IS_LONG_IDENTICAL(&_9$$5, 0);
			if (_11$$5) {
				ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "locate", NULL, 334, &other, &path);
				zephir_check_call_status();
				_11$$5 = Z_TYPE_P(&_12$$5) == IS_ARRAY;
			}
			if (_11$$5) {
				ZEPHIR_INIT_NVAR(&_13$$6);
				object_init_ex(&_13$$6, phalcon_adr_exceptions_methodnotallowed_ce);
				ZEPHIR_CALL_METHOD(NULL, &_13$$6, "__construct", &_14, 338);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_13$$6, "phalcon/ADR/Router/Router.zep", 157);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_7, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_7, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, &_7, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&other, &_7, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_17$$7, "strcasecmp", &_10, 85, &other, &method);
				zephir_check_call_status();
				_18$$7 = !ZEPHIR_IS_LONG_IDENTICAL(&_17$$7, 0);
				if (_18$$7) {
					ZEPHIR_CALL_METHOD(&_19$$7, this_ptr, "locate", NULL, 334, &other, &path);
					zephir_check_call_status();
					_18$$7 = Z_TYPE_P(&_19$$7) == IS_ARRAY;
				}
				if (_18$$7) {
					ZEPHIR_INIT_NVAR(&_20$$8);
					object_init_ex(&_20$$8, phalcon_adr_exceptions_methodnotallowed_ce);
					ZEPHIR_CALL_METHOD(NULL, &_20$$8, "__construct", &_14, 338);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_20$$8, "phalcon/ADR/Router/Router.zep", 157);
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&other);
	RETURN_MM_NULL();
}

PHP_METHOD(Phalcon_ADR_Router_Router, pathFor)
{
	zend_bool _12, _20;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, __$true, candidate, last, name, names, part, parts, path, prefix, verb, _0, _1, _2, _3, _7, *_8, _11, *_15, _19, _23, *_24, _4$$4, _5$$4, _6$$4, _9$$5, _10$$5, _13$$7, _14$$7, _16$$10, _18$$10, _21$$11, _22$$11, _25$$12;
	zend_string *className = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&candidate);
	ZVAL_UNDEF(&last);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&verb);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_25$$12);
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
	ZEPHIR_INIT_VAR(&verb);
	ZVAL_NULL(&verb);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 362, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&prefix);
	ZEPHIR_CONCAT_VS(&prefix, &_0, "\\");
	ZVAL_LONG(&_1, zephir_fast_strlen_ev(&prefix));
	ZEPHIR_CALL_FUNCTION(&_2, "strncmp", NULL, 339, &className_zv, &prefix, &_1);
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
	ZEPHIR_CALL_FUNCTION(&last, "array_pop", NULL, 340, &parts);
	ZEPHIR_UNREF(&parts);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&parts)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "verbs", NULL, 337);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_6$$4, "in_array", NULL, 87, &last, &_5$$4, &__$true);
		zephir_check_call_status();
		if (zephir_is_true(&_6$$4)) {
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "/");
		} else {
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_NULL(&_4$$4);
		}
		RETURN_CCTOR(&_4$$4);
	}
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "verbs", NULL, 337);
	zephir_check_call_status();
	zephir_is_iterable(&_7, 0, "phalcon/ADR/Router/Router.zep", 196);
	if (Z_TYPE_P(&_7) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_7), _8)
		{
			ZEPHIR_INIT_NVAR(&candidate);
			ZVAL_COPY(&candidate, _8);
			ZEPHIR_INIT_NVAR(&_9$$5);
			zephir_fast_join_str(&_9$$5, SL(""), &parts);
			ZEPHIR_INIT_NVAR(&_10$$5);
			ZEPHIR_CONCAT_VV(&_10$$5, &candidate, &_9$$5);
			if (ZEPHIR_IS_IDENTICAL(&last, &_10$$5)) {
				ZEPHIR_CPY_WRT(&verb, &candidate);
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_7, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_7, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, &_7, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&candidate, &_7, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$7);
				zephir_fast_join_str(&_13$$7, SL(""), &parts);
				ZEPHIR_INIT_NVAR(&_14$$7);
				ZEPHIR_CONCAT_VV(&_14$$7, &candidate, &_13$$7);
				if (ZEPHIR_IS_IDENTICAL(&last, &_14$$7)) {
					ZEPHIR_CPY_WRT(&verb, &candidate);
					break;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&candidate);
	if (Z_TYPE_P(&verb) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&path);
	ZVAL_STRING(&path, "");
	zephir_is_iterable(&parts, 0, "phalcon/ADR/Router/Router.zep", 215);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parts), _15)
		{
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _15);
			ZEPHIR_CALL_METHOD(&_16$$10, this_ptr, "decamelize", &_17, 341, &part);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_18$$10);
			ZEPHIR_CONCAT_VSV(&_18$$10, &path, "/", &_16$$10);
			ZEPHIR_CPY_WRT(&path, &_18$$10);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parts, "rewind", NULL, 0);
		zephir_check_call_status();
		_20 = 1;
		while (1) {
			if (_20) {
				_20 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_19, &parts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_19)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&part, &parts, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_21$$11, this_ptr, "decamelize", &_17, 341, &part);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_22$$11);
				ZEPHIR_CONCAT_VSV(&_22$$11, &path, "/", &_21$$11);
				ZEPHIR_CPY_WRT(&path, &_22$$11);
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	ZEPHIR_CALL_METHOD(&_23, this_ptr, "actionparams", NULL, 342, &className_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&names);
	zephir_array_keys(&names, &_23);
	zephir_is_iterable(&names, 0, "phalcon/ADR/Router/Router.zep", 221);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&names), _24)
	{
		ZEPHIR_INIT_NVAR(&name);
		ZVAL_COPY(&name, _24);
		ZEPHIR_INIT_NVAR(&_25$$12);
		ZEPHIR_CONCAT_VSVS(&_25$$12, &path, "/{", &name, "}");
		ZEPHIR_CPY_WRT(&path, &_25$$12);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 363, &_0);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 362, &_0);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 364, &middlewareMap);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 365, &wordSeparator_zv);
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
 * @return array<string, array<string, mixed>>
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 365, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 365, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_2, "ucwords", NULL, 343, &segment_zv, &_1);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 365, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "$1", &_0, "$2");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/([a-z0-9])([A-Z])/");
	ZEPHIR_CALL_FUNCTION(&_3, "preg_replace", NULL, 90, &_2, &_1, &part_zv);
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
 * @return array<int, array{0: string, 1: array}>
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
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 362, PH_NOISY_CC | PH_READONLY);
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
		zephir_array_fetch_long(&_5$$4, &segments, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 330);
		ZEPHIR_CALL_METHOD(&segment, this_ptr, "camelize", &_6, 332, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&candidate);
		ZEPHIR_CONCAT_VSV(&candidate, &subNamespace, "\\", &segment);
		ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "hassubnamespace", &_8, 344, &candidate);
		zephir_check_call_status();
		if (!(zephir_is_true(&_7$$4))) {
			break;
		}
		ZEPHIR_CPY_WRT(&subNamespace, &candidate);
		zephir_array_append(&parts, &segment, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 338);
		ZEPHIR_MAKE_REF(&segments);
		ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_9, 40, &segments);
		ZEPHIR_UNREF(&segments);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_EMPTY(&parts)) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_read_property_cached(&_10, this_ptr, _zephir_prop_0, 362, PH_NOISY_CC | PH_READONLY);
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
	if (zephir_memnstr_str(&subNamespace_zv, SL(".."), "phalcon/ADR/Router/Router.zep", 361)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 363, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/");
	zephir_fast_str_replace(&_1, &_2, &_3, &subNamespace_zv);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_1);
	ZEPHIR_RETURN_CALL_FUNCTION("is_dir", NULL, 295, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Router, locate)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method_zv, path_zv, candidate, candidates, *_0, _2, _1$$3, _4$$5;
	zend_string *method = NULL, *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&candidate);
	ZVAL_UNDEF(&candidates);
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
	zephir_is_iterable(&candidates, 0, "phalcon/ADR/Router/Router.zep", 382);
	if (Z_TYPE_P(&candidates) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&candidates), _0)
		{
			ZEPHIR_INIT_NVAR(&candidate);
			ZVAL_COPY(&candidate, _0);
			zephir_array_fetch_long(&_1$$3, &candidate, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 377);
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
				zephir_array_fetch_long(&_4$$5, &candidate, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 377);
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
	zval stacked;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, full, list, prefix, _0, *_1, _9, _4$$3, _5$$3, _6$$3, _8$$4, _11$$5, _12$$5, _13$$5, _14$$6;
	zend_string *className = NULL, *_3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&full);
	ZVAL_UNDEF(&list);
	ZVAL_UNDEF(&prefix);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 364, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/ADR/Router/Router.zep", 398);
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
			zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_1, 362, PH_NOISY_CC | PH_READONLY);
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
				zephir_read_property_cached(&_11$$5, this_ptr, _zephir_prop_1, 362, PH_NOISY_CC | PH_READONLY);
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
	RETURN_CTOR(&stacked);
}

/**
 * The HTTP verbs the convention recognises, in class-name form.
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

