
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
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
 * Convention router. `method + static path -> Action class`; the path tail
 * becomes positional request attributes. Middleware is resolved from a
 * namespace-prefix map (group semantics); global middleware stays on the
 * pipeline. No route table.
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 362, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING_IDENTICAL(&_0, "")) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_adr_exceptions_actiondirectorynotset_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 332);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/ADR/Router/Router.zep", 56);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_CALL_METHOD(&path, request, "geturi", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&method, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&located, this_ptr, "locate", NULL, 333, &method, &path);
	zephir_check_call_status();
	if (Z_TYPE_P(&located) == IS_ARRAY) {
		object_init_ex(return_value, phalcon_adr_router_routermatch_ce);
		zephir_array_fetch_long(&_3$$4, &located, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 65);
		zephir_array_fetch_long(&_4$$4, &located, 1, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 66);
		zephir_array_fetch_long(&_6$$4, &located, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 67);
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "middlewarefor", NULL, 334, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 335, &_3$$4, &_4$$4, &_5$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "verbs", NULL, 336);
	zephir_check_call_status();
	zephir_is_iterable(&_7, 0, "phalcon/ADR/Router/Router.zep", 77);
	if (Z_TYPE_P(&_7) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_7), _8)
		{
			ZEPHIR_INIT_NVAR(&other);
			ZVAL_COPY(&other, _8);
			ZEPHIR_CALL_FUNCTION(&_9$$5, "strcasecmp", &_10, 85, &other, &method);
			zephir_check_call_status();
			_11$$5 = !ZEPHIR_IS_LONG_IDENTICAL(&_9$$5, 0);
			if (_11$$5) {
				ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "locate", NULL, 333, &other, &path);
				zephir_check_call_status();
				_11$$5 = Z_TYPE_P(&_12$$5) == IS_ARRAY;
			}
			if (_11$$5) {
				ZEPHIR_INIT_NVAR(&_13$$6);
				object_init_ex(&_13$$6, phalcon_adr_exceptions_methodnotallowed_ce);
				ZEPHIR_CALL_METHOD(NULL, &_13$$6, "__construct", &_14, 337);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_13$$6, "phalcon/ADR/Router/Router.zep", 73);
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
					ZEPHIR_CALL_METHOD(&_19$$7, this_ptr, "locate", NULL, 333, &other, &path);
					zephir_check_call_status();
					_18$$7 = Z_TYPE_P(&_19$$7) == IS_ARRAY;
				}
				if (_18$$7) {
					ZEPHIR_INIT_NVAR(&_20$$8);
					object_init_ex(&_20$$8, phalcon_adr_exceptions_methodnotallowed_ce);
					ZEPHIR_CALL_METHOD(NULL, &_20$$8, "__construct", &_14, 337);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_20$$8, "phalcon/ADR/Router/Router.zep", 73);
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
	zval _14$$5, _22$$8;
	zend_bool _16, _28;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_25 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, __$true, last, operation, part, parts, path, prefix, remainder, resourceName, verb, _0, _1, _2, _3, _7, *_8, _15, *_23, _27, _4$$4, _5$$4, _6$$4, _9$$5, _10$$5, _11$$5, _12$$5, _13$$5, _17$$8, _18$$8, _19$$8, _20$$8, _21$$8, _24$$12, _26$$12, _29$$13, _30$$13, _31$$14, _32$$14;
	zend_string *className = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&last);
	ZVAL_UNDEF(&operation);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&remainder);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&verb);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_22$$8);
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
	ZEPHIR_INIT_VAR(&operation);
	ZVAL_NULL(&operation);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 363, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&prefix);
	ZEPHIR_CONCAT_VS(&prefix, &_0, "\\");
	ZVAL_LONG(&_1, zephir_fast_strlen_ev(&prefix));
	ZEPHIR_CALL_FUNCTION(&_2, "strncmp", NULL, 338, &className_zv, &prefix, &_1);
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
	ZEPHIR_CALL_FUNCTION(&last, "array_pop", NULL, 339, &parts);
	ZEPHIR_UNREF(&parts);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&parts)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "verbs", NULL, 336);
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
	ZEPHIR_MAKE_REF(&parts);
	ZEPHIR_CALL_FUNCTION(&resourceName, "end", NULL, 340, &parts);
	ZEPHIR_UNREF(&parts);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "verbs", NULL, 336);
	zephir_check_call_status();
	zephir_is_iterable(&_7, 0, "phalcon/ADR/Router/Router.zep", 118);
	if (Z_TYPE_P(&_7) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_7), _8)
		{
			ZEPHIR_INIT_NVAR(&verb);
			ZVAL_COPY(&verb, _8);
			ZVAL_LONG(&_9$$5, zephir_fast_strlen_ev(&verb));
			ZEPHIR_CALL_FUNCTION(&_10$$5, "strncmp", NULL, 338, &last, &verb, &_9$$5);
			zephir_check_call_status();
			if (!ZEPHIR_IS_LONG_IDENTICAL(&_10$$5, 0)) {
				continue;
			}
			ZVAL_LONG(&_9$$5, zephir_fast_strlen_ev(&verb));
			ZEPHIR_INIT_NVAR(&remainder);
			zephir_substr(&remainder, &last, zephir_get_intval(&_9$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZVAL_LONG(&_11$$5, zephir_fast_strlen_ev(&resourceName));
			ZEPHIR_CALL_FUNCTION(&_12$$5, "strncmp", NULL, 338, &remainder, &resourceName, &_11$$5);
			zephir_check_call_status();
			if (!ZEPHIR_IS_LONG_IDENTICAL(&_12$$5, 0)) {
				continue;
			}
			ZVAL_LONG(&_11$$5, (zephir_fast_strlen_ev(&verb) + zephir_fast_strlen_ev(&resourceName)));
			ZEPHIR_INIT_NVAR(&_13$$5);
			zephir_substr(&_13$$5, &last, zephir_get_intval(&_11$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			zephir_cast_to_string(&_14$$5, &_13$$5);
			ZEPHIR_CPY_WRT(&operation, &_14$$5);
			break;
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
			ZEPHIR_CALL_METHOD(&verb, &_7, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_LONG(&_17$$8, zephir_fast_strlen_ev(&verb));
				ZEPHIR_CALL_FUNCTION(&_18$$8, "strncmp", NULL, 338, &last, &verb, &_17$$8);
				zephir_check_call_status();
				if (!ZEPHIR_IS_LONG_IDENTICAL(&_18$$8, 0)) {
					continue;
				}
				ZVAL_LONG(&_17$$8, zephir_fast_strlen_ev(&verb));
				ZEPHIR_INIT_NVAR(&remainder);
				zephir_substr(&remainder, &last, zephir_get_intval(&_17$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZVAL_LONG(&_19$$8, zephir_fast_strlen_ev(&resourceName));
				ZEPHIR_CALL_FUNCTION(&_20$$8, "strncmp", NULL, 338, &remainder, &resourceName, &_19$$8);
				zephir_check_call_status();
				if (!ZEPHIR_IS_LONG_IDENTICAL(&_20$$8, 0)) {
					continue;
				}
				ZVAL_LONG(&_19$$8, (zephir_fast_strlen_ev(&verb) + zephir_fast_strlen_ev(&resourceName)));
				ZEPHIR_INIT_NVAR(&_21$$8);
				zephir_substr(&_21$$8, &last, zephir_get_intval(&_19$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				zephir_cast_to_string(&_22$$8, &_21$$8);
				ZEPHIR_CPY_WRT(&operation, &_22$$8);
				break;
		}
	}
	ZEPHIR_INIT_NVAR(&verb);
	if (Z_TYPE_P(&operation) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&path);
	ZVAL_STRING(&path, "");
	zephir_is_iterable(&parts, 0, "phalcon/ADR/Router/Router.zep", 127);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parts), _23)
		{
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _23);
			ZEPHIR_CALL_METHOD(&_24$$12, this_ptr, "decamelize", &_25, 341, &part);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_26$$12);
			ZEPHIR_CONCAT_VSV(&_26$$12, &path, "/", &_24$$12);
			ZEPHIR_CPY_WRT(&path, &_26$$12);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parts, "rewind", NULL, 0);
		zephir_check_call_status();
		_28 = 1;
		while (1) {
			if (_28) {
				_28 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_27, &parts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_27)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&part, &parts, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_29$$13, this_ptr, "decamelize", &_25, 341, &part);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_30$$13);
				ZEPHIR_CONCAT_VSV(&_30$$13, &path, "/", &_29$$13);
				ZEPHIR_CPY_WRT(&path, &_30$$13);
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&operation, "")) {
		ZEPHIR_CALL_METHOD(&_31$$14, this_ptr, "decamelize", &_25, 341, &operation);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_32$$14);
		ZEPHIR_CONCAT_VSV(&_32$$14, &path, "/", &_31$$14);
		ZEPHIR_CPY_WRT(&path, &_32$$14);
	}
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 362, &_0);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 363, &_0);
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
	ZEPHIR_CALL_FUNCTION(&_2, "ucwords", NULL, 342, &segment_zv, &_1);
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
 * The single derivation of the routing convention. Path segments are
 * consumed as namespace segments while the matching directory exists; the
 * class at the stopping depth is probed, preceded by the fused operation
 * form when exactly one segment remains. Every candidate is paired with the
 * request attributes it would leave behind.
 *
 * @return array<int, array{0: string, 1: array}>
 */
PHP_METHOD(Phalcon_ADR_Router_Router, deriveCandidates)
{
	zval candidates, _19, _3$$3, _14$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, depth;
	zval method_zv, path_zv, candidate, className, parts, resourceName, subNamespace, segments, uri, verb, _0, _1, _11, _12, _13, _2$$3, _4$$3, _5$$4, _6$$4, _8$$4, _15$$7, _16$$7, _17$$7, _18$$7;
	zend_string *method = NULL, *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&candidate);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&subNamespace);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&verb);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&candidates);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_14$$7);
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
	depth = 0;
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
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 363, PH_NOISY_CC | PH_READONLY);
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
		zephir_array_fetch_long(&_6$$4, &segments, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 210);
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "camelize", &_7, 343, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&candidate);
		ZEPHIR_CONCAT_VSV(&candidate, &subNamespace, "\\", &_5$$4);
		ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "hassubnamespace", &_9, 344, &candidate);
		zephir_check_call_status();
		if (!(zephir_is_true(&_8$$4))) {
			break;
		}
		ZEPHIR_CPY_WRT(&subNamespace, &candidate);
		depth = (depth + 1);
		ZEPHIR_MAKE_REF(&segments);
		ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_10, 40, &segments);
		ZEPHIR_UNREF(&segments);
		zephir_check_call_status();
	}
	if (depth == 0) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "\\");
	zephir_fast_trim(&_11, &subNamespace, &_12, ZEPHIR_TRIM_LEFT);
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("\\"), &_11, LONG_MAX);
	ZEPHIR_MAKE_REF(&parts);
	ZEPHIR_CALL_FUNCTION(&resourceName, "end", NULL, 340, &parts);
	ZEPHIR_UNREF(&parts);
	zephir_check_call_status();
	zephir_read_property_cached(&_13, this_ptr, _zephir_prop_0, 363, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&className);
	ZEPHIR_CONCAT_VVSVV(&className, &_13, &subNamespace, "\\", &verb, &resourceName);
	if (zephir_fast_count_int(&segments) == 1) {
		ZEPHIR_INIT_VAR(&_14$$7);
		zephir_create_array(&_14$$7, 2, 0);
		zephir_array_fetch_long(&_16$$7, &segments, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 231);
		ZEPHIR_CALL_METHOD(&_15$$7, this_ptr, "camelize", &_7, 343, &_16$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_17$$7);
		ZEPHIR_CONCAT_VV(&_17$$7, &className, &_15$$7);
		zephir_array_fast_append(&_14$$7, &_17$$7);
		ZEPHIR_INIT_VAR(&_18$$7);
		array_init(&_18$$7);
		zephir_array_fast_append(&_14$$7, &_18$$7);
		zephir_array_append(&candidates, &_14$$7, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 231);
	}
	ZEPHIR_INIT_VAR(&_19);
	zephir_create_array(&_19, 2, 0);
	zephir_array_fast_append(&_19, &className);
	zephir_array_fast_append(&_19, &segments);
	zephir_array_append(&candidates, &_19, PH_SEPARATE, "phalcon/ADR/Router/Router.zep", 234);
	RETURN_CTOR(&candidates);
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
	if (zephir_memnstr_str(&subNamespace_zv, SL(".."), "phalcon/ADR/Router/Router.zep", 241)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 362, PH_NOISY_CC | PH_READONLY);
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
	zephir_is_iterable(&candidates, 0, "phalcon/ADR/Router/Router.zep", 262);
	if (Z_TYPE_P(&candidates) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&candidates), _0)
		{
			ZEPHIR_INIT_NVAR(&candidate);
			ZVAL_COPY(&candidate, _0);
			zephir_array_fetch_long(&_1$$3, &candidate, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 257);
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
				zephir_array_fetch_long(&_4$$5, &candidate, 0, PH_NOISY | PH_READONLY, "phalcon/ADR/Router/Router.zep", 257);
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
	zephir_is_iterable(&_0, 0, "phalcon/ADR/Router/Router.zep", 278);
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
			zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_1, 363, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&full);
			ZEPHIR_CONCAT_VV(&full, &_4$$3, &prefix);
			ZVAL_LONG(&_5$$3, zephir_fast_strlen_ev(&full));
			ZEPHIR_CALL_FUNCTION(&_6$$3, "strncmp", &_7, 338, &className_zv, &full, &_5$$3);
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
				zephir_read_property_cached(&_11$$5, this_ptr, _zephir_prop_1, 363, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&full);
				ZEPHIR_CONCAT_VV(&full, &_11$$5, &prefix);
				ZVAL_LONG(&_12$$5, zephir_fast_strlen_ev(&full));
				ZEPHIR_CALL_FUNCTION(&_13$$5, "strncmp", &_7, 338, &className_zv, &full, &_12$$5);
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

