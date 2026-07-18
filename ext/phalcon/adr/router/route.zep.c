
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/main.h"
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
 * A route registered with the router. Compiles a `/posts/{id}` style pattern to
 * a regular expression (with `{name:regex}` constraints supported) and matches
 * the request path against it, extracting the named parameters.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_Route)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Router, Route, phalcon, adr_router_route, phalcon_adr_router_route_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_adr_router_route_ce, SL("action"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_adr_router_route_ce, SL("compiled"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_adr_router_route_ce, SL("methods"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_adr_router_route_ce, SL("name"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_adr_router_route_ce, SL("middleware"), ZEND_ACC_PROTECTED);
	phalcon_adr_router_route_ce->create_object = zephir_init_properties_Phalcon_ADR_Router_Route;

	zend_class_implements(phalcon_adr_router_route_ce, 1, phalcon_contracts_adr_router_route_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Router_Route, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval methods;
	zval pattern_zv, action_zv, *methods_param = NULL, _0;
	zend_string *pattern = NULL, *action = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&action_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&methods);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("action", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("methods", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("compiled", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_STR(action)
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
	zephir_memory_observe(&action_zv);
	ZVAL_STR_COPY(&action_zv, action);
	if (!methods_param) {
		ZEPHIR_INIT_VAR(&methods);
		array_init(&methods);
	} else {
		zephir_get_arrval(&methods, methods_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 361, &action_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 362, &methods);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "compile", NULL, 0, &pattern_zv);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 363, &_0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_ADR_Router_Route, allowsMethod)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method_zv, __$true, _0, _2, _3;
	zend_string *method = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("methods", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(method)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 362, PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_IS_EMPTY(&_0);
	if (!(_1)) {
		zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 362, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_3, "in_array", NULL, 87, &method_zv, &_2, &__$true);
		zephir_check_call_status();
		_1 = zephir_is_true(&_3);
	}
	RETURN_MM_BOOL(_1);
}

PHP_METHOD(Phalcon_ADR_Router_Route, getAction)
{

	RETURN_MEMBER_TYPED(getThis(), "action", IS_STRING);
}

PHP_METHOD(Phalcon_ADR_Router_Route, getName)
{

	RETURN_MEMBER(getThis(), "name");
}

PHP_METHOD(Phalcon_ADR_Router_Route, matches)
{
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, matches, params, key, value, _0, _1, *_2;
	zend_string *uri = NULL, *_4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_zv);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("compiled", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 363, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_preg_match(&_1, &_0, &uri_zv, &matches, 0, 0 , 0 );
	if (!(zephir_is_true(&_1))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	zephir_is_iterable(&matches, 0, "phalcon/ADR/Router/Route.zep", 85);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&matches), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&key, _4);
		} else {
			ZVAL_LONG(&key, _3);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _2);
		if (Z_TYPE_P(&key) == IS_STRING) {
			zephir_array_update_zval(&params, &key, &value, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&params);
}

PHP_METHOD(Phalcon_ADR_Router_Route, withMiddleware)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval classes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classes);
	ZEND_PARSE_PARAMETERS_START(0, -1)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZEPHIR_INIT_VAR(&classes);
	zephir_get_args_from(&classes, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "pushmiddleware", NULL, 0, &classes);
	zephir_check_call_status();
	RETURN_THIS();
}

PHP_METHOD(Phalcon_ADR_Router_Route, withName)
{
	zval name_zv;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("name", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 364, &name_zv);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_ADR_Router_Route, compile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, compiled, _0, _1, _2;
	zend_string *pattern = NULL;

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&compiled);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(pattern)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "#\\{([a-zA-Z_][a-zA-Z0-9_]*):([^{}]+)\\}#");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "(?<$1>$2)");
	ZEPHIR_CALL_FUNCTION(&compiled, "preg_replace", NULL, 90, &_0, &_1, &pattern_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "#\\{([a-zA-Z_][a-zA-Z0-9_]*)\\}#");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "(?<$1>[^/]+)");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", NULL, 90, &_0, &_1, &compiled);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&compiled, &_2);
	ZEPHIR_CONCAT_SVS(return_value, "#^", &compiled, "$#");
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Route, getMiddleware)
{

	RETURN_MEMBER_TYPED(getThis(), "middleware", IS_ARRAY);
}

PHP_METHOD(Phalcon_ADR_Router_Route, pushMiddleware)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *classes_param = NULL, item, *_0, _1;
	zval classes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(classes, classes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &classes_param);
	zephir_get_arrval(&classes, classes_param);
	zephir_is_iterable(&classes, 0, "phalcon/ADR/Router/Traits/HasMiddleware.zep", 39);
	if (Z_TYPE_P(&classes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&classes), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			zephir_update_property_array_append(this_ptr, SL("middleware"), &item);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &classes, "rewind", NULL, 0);
		zephir_check_call_status();
		_2 = 1;
		while (1) {
			if (_2) {
				_2 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &classes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_1, &classes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &classes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_update_property_array_append(this_ptr, SL("middleware"), &item);
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Phalcon_ADR_Router_Route(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("middleware"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("middleware"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

