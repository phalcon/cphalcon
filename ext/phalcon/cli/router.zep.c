
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Cli\Router is the standard framework router. Routing is the process
 * of taking a command-line arguments and decomposing it into parameters to
 * determine which module, task, and action of that task should receive the
 * request.
 *
 *```php
 * $router = new \Phalcon\Cli\Router();
 *
 * $router->handle(
 *     [
 *         "module" => "main",
 *         "task"   => "videos",
 *         "action" => "process",
 *     ]
 * );
 *
 * echo $router->getTaskName();
 *```
 * @phpstan-import-type cli_parameters from CliTypes
 * @phpstan-import-type cli_router_defaults from CliTypes
 * @phpstan-import-type cli_routes from CliTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Router)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli, Router, phalcon, cli_router, phalcon_di_abstractinjectionaware_ce, phalcon_cli_router_method_entry, 0);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_cli_router_ce, SL("action"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_cli_router_ce, SL("defaultAction"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_cli_router_ce, SL("defaultModule"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * @phpstan-var cli_parameters
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_cli_router_ce, SL("defaultParams"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_cli_router_ce, SL("defaultTask"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_cli_router_ce, SL("matchedRoute"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Cli\\Router\\RouteInterface"));
	}

	/**
	 * @var array<array-key, string>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_cli_router_ce, SL("matches"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_cli_router_ce, SL("module"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * @phpstan-var cli_parameters
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_cli_router_ce, SL("params"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var cli_routes
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_cli_router_ce, SL("routes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_cli_router_ce, SL("task"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_cli_router_ce, SL("wasMatched"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	zend_class_implements(phalcon_cli_router_ce, 1, phalcon_cli_routerinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Cli\Router constructor
 */
PHP_METHOD(Phalcon_Cli_Router, __construct)
{
	zval _0$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultRoutes_param = NULL, _1$$3;
	zend_bool defaultRoutes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(defaultRoutes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &defaultRoutes_param);
	if (!defaultRoutes_param) {
		defaultRoutes = 1;
	} else {
		}
	if (defaultRoutes) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		add_assoc_long_ex(&_0$$3, SL("task"), 1);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+)[:delimiter]{0,1}$#");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_1$$3, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 3, 0);
		add_assoc_long_ex(&_2$$3, SL("task"), 1);
		add_assoc_long_ex(&_2$$3, SL("action"), 2);
		add_assoc_long_ex(&_2$$3, SL("params"), 3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+):delimiter([a-zA-Z0-9\\.\\_]+)(:delimiter.*)?$#");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds a route to the router
 *
 *```php
 * $router->add("/about", "About::main");
 *```
 *
 * @phpstan-param mixed $paths
 */
PHP_METHOD(Phalcon_Cli_Router, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, *paths = NULL, paths_sub, __$null, route, _0;
	zend_string *pattern = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		paths = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	ZEPHIR_INIT_VAR(&route);
	object_init_ex(&route, phalcon_cli_router_route_ce);
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 455, &pattern_zv, paths);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 456);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("routes"), &_0, &route);
	RETURN_CCTOR(&route);
}

/**
 * Returns processed action name
 */
PHP_METHOD(Phalcon_Cli_Router, getActionName)
{

	RETURN_MEMBER_TYPED(getThis(), "action", IS_STRING);
}

/**
 * Returns the route that matches the handled URI
 */
PHP_METHOD(Phalcon_Cli_Router, getMatchedRoute)
{

	RETURN_MEMBER(getThis(), "matchedRoute");
}

/**
 * Returns the sub expressions in the regular expression matched
 *
 * @return array<array-key, string>
 */
PHP_METHOD(Phalcon_Cli_Router, getMatches)
{

	RETURN_MEMBER_TYPED(getThis(), "matches", IS_ARRAY);
}

/**
 * Returns processed module name
 */
PHP_METHOD(Phalcon_Cli_Router, getModuleName)
{

	RETURN_MEMBER_TYPED(getThis(), "module", IS_STRING);
}

/**
 * Returns processed extra params
 *
 * @phpstan-return cli_parameters
 */
PHP_METHOD(Phalcon_Cli_Router, getParameters)
{

	RETURN_MEMBER_TYPED(getThis(), "params", IS_ARRAY);
}

/**
 * Returns processed extra params
 *
 * @deprecated Use {@see getParameters()} instead.
 *
 * @phpstan-return cli_parameters
 */
PHP_METHOD(Phalcon_Cli_Router, getParams)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getparameters", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a route object by its id
 */
PHP_METHOD(Phalcon_Cli_Router, getRouteById)
{
	zval *id, id_sub, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &id);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 501, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_0, id)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 501, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, id, PH_NOISY | PH_READONLY, "phalcon/Cli/Router.zep", 179);
		RETURN_CTORW(&_2$$3);
	}
	RETURN_BOOL(0);
}

/**
 * Returns a route object by its name
 */
PHP_METHOD(Phalcon_Cli_Router, getRouteByName)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, route, _0, *_1, _3, _2$$3, _5$$5;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 501, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Cli/Router.zep", 198);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _1);
			ZEPHIR_CALL_METHOD(&_2$$3, &route, "getname", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EQUAL(&_2$$3, &name_zv)) {
				RETURN_CCTOR(&route);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$5, &route, "getname", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_EQUAL(&_5$$5, &name_zv)) {
					RETURN_CCTOR(&route);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	RETURN_MM_BOOL(0);
}

/**
 * Returns all the routes defined in the router
 *
 * @phpstan-return cli_routes
 */
PHP_METHOD(Phalcon_Cli_Router, getRoutes)
{

	RETURN_MEMBER_TYPED(getThis(), "routes", IS_ARRAY);
}

/**
 * Returns processed task name
 */
PHP_METHOD(Phalcon_Cli_Router, getTaskName)
{

	RETURN_MEMBER_TYPED(getThis(), "task", IS_STRING);
}

/**
 * Handles routing information received from command-line arguments
 *
 * @phpstan-param mixed $arguments
 */
PHP_METHOD(Phalcon_Cli_Router, handle)
{
	zval _44$$56;
	zend_string *_11$$13, *_29$$33;
	zend_ulong _10$$13, _28$$33;
	zval _8$$10, _13$$16, _15$$19, _19$$22, _21$$25, _26$$30, _31$$36, _33$$39, _37$$42, _39$$45;
	zend_bool _0$$3, _23$$3, _17$$13, _35$$33;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, arguments_sub, __$true, __$false, __$null, moduleName, taskName, actionName, params, route, parts, pattern, routeFound, matches, paths, beforeMatch, converters, converter, part, position, matchPosition, strParams, _3$$3, *_4$$3, _22$$3, _1$$4, _2$$4, _5$$11, _6$$11, *_9$$13, _16$$13, _12$$16, _14$$19, _18$$22, _20$$25, _24$$31, _25$$31, *_27$$33, _34$$33, _30$$36, _32$$39, _36$$42, _38$$45, _40$$47, _41$$47, _42$$47, _43$$47, _45$$56, _46$$57, _47$$59;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&taskName);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&routeFound);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&converters);
	ZVAL_UNDEF(&converter);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&matchPosition);
	ZVAL_UNDEF(&strParams);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_12$$16);
	ZVAL_UNDEF(&_14$$19);
	ZVAL_UNDEF(&_18$$22);
	ZVAL_UNDEF(&_20$$25);
	ZVAL_UNDEF(&_24$$31);
	ZVAL_UNDEF(&_25$$31);
	ZVAL_UNDEF(&_34$$33);
	ZVAL_UNDEF(&_30$$36);
	ZVAL_UNDEF(&_32$$39);
	ZVAL_UNDEF(&_36$$42);
	ZVAL_UNDEF(&_38$$45);
	ZVAL_UNDEF(&_40$$47);
	ZVAL_UNDEF(&_41$$47);
	ZVAL_UNDEF(&_42$$47);
	ZVAL_UNDEF(&_43$$47);
	ZVAL_UNDEF(&_45$$56);
	ZVAL_UNDEF(&_46$$57);
	ZVAL_UNDEF(&_47$$59);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_15$$19);
	ZVAL_UNDEF(&_19$$22);
	ZVAL_UNDEF(&_21$$25);
	ZVAL_UNDEF(&_26$$30);
	ZVAL_UNDEF(&_31$$36);
	ZVAL_UNDEF(&_33$$39);
	ZVAL_UNDEF(&_37$$42);
	ZVAL_UNDEF(&_39$$45);
	ZVAL_UNDEF(&_44$$56);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	static zend_string *_zephir_prop_11 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("wasMatched", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("matchedRoute", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("routes", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("matches", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("defaultModule", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("module", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("defaultTask", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("task", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("defaultAction", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("action", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("defaultParams", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_11)) {
		_zephir_prop_11 = zend_string_init("params", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(arguments)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &arguments);
	if (!arguments) {
		arguments = &arguments_sub;
		ZEPHIR_CPY_WRT(arguments, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(arguments);
	}
	ZEPHIR_INIT_VAR(&routeFound);
	ZVAL_BOOL(&routeFound, 0);
	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 502, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 502, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 503, &__$null);
	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		_0$$3 = Z_TYPE_P(arguments) != IS_STRING;
		if (_0$$3) {
			_0$$3 = Z_TYPE_P(arguments) != IS_NULL;
		}
		if (UNEXPECTED(_0$$3)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_cli_router_exceptions_routerargumentsinvalidtype_ce);
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_gettype(&_2$$4, arguments);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 457, &_2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Cli/Router.zep", 239);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(arguments) == IS_NULL) {
			ZEPHIR_INIT_NVAR(arguments);
			ZVAL_STRING(arguments, "");
		}
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_2, 501, PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_3$$3, 0, "phalcon/Cli/Router.zep", 351);
		if (Z_TYPE_P(&_3$$3) == IS_ARRAY) {
			ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(&_3$$3), _4$$3)
			{
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _4$$3);
				ZEPHIR_CALL_METHOD(&pattern, &route, "getcompiledpattern", NULL, 0);
				zephir_check_call_status();
				if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/Cli/Router.zep", 256)) {
					ZEPHIR_INIT_NVAR(&routeFound);
					zephir_preg_match(&routeFound, &pattern, arguments, &matches, 0, 0 , 0 );
				} else {
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, arguments));
				}
				if (zephir_is_true(&routeFound)) {
					ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getbeforematch", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
							ZEPHIR_INIT_NVAR(&_5$$11);
							object_init_ex(&_5$$11, phalcon_cli_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD(&_6$$11, &route, "getpattern", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &_5$$11, "__construct", &_7, 458, &_6$$11);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_5$$11, "phalcon/Cli/Router.zep", 273);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_8$$10);
						zephir_create_array(&_8$$10, 3, 0);
						zephir_array_fast_append(&_8$$10, arguments);
						zephir_array_fast_append(&_8$$10, &route);
						zephir_array_fast_append(&_8$$10, this_ptr);
						ZEPHIR_INIT_NVAR(&routeFound);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_8$$10);
						zephir_check_call_status();
					}
				}
				if (zephir_is_true(&routeFound)) {
					ZEPHIR_CALL_METHOD(&paths, &route, "getpaths", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&parts, &paths);
					if (Z_TYPE_P(&matches) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD(&converters, &route, "getconverters", NULL, 0);
						zephir_check_call_status();
						zephir_is_iterable(&paths, 0, "phalcon/Cli/Router.zep", 338);
						if (Z_TYPE_P(&paths) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _10$$13, _11$$13, _9$$13)
							{
								ZEPHIR_INIT_NVAR(&part);
								if (_11$$13 != NULL) { 
									ZVAL_STR_COPY(&part, _11$$13);
								} else {
									ZVAL_LONG(&part, _10$$13);
								}
								ZEPHIR_INIT_NVAR(&position);
								ZVAL_COPY(&position, _9$$13);
								ZEPHIR_OBS_NVAR(&matchPosition);
								if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
									ZEPHIR_OBS_NVAR(&converter);
									if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
										ZEPHIR_INIT_NVAR(&_12$$16);
										ZEPHIR_INIT_NVAR(&_13$$16);
										zephir_create_array(&_13$$16, 1, 0);
										zephir_array_fast_append(&_13$$16, &matchPosition);
										ZEPHIR_CALL_USER_FUNC_ARRAY(&_12$$16, &converter, &_13$$16);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_12$$16, PH_COPY | PH_SEPARATE);
									} else {
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
									}
								} else {
									ZEPHIR_OBS_NVAR(&converter);
									if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
										ZEPHIR_INIT_NVAR(&_14$$19);
										ZEPHIR_INIT_NVAR(&_15$$19);
										zephir_create_array(&_15$$19, 1, 0);
										zephir_array_fast_append(&_15$$19, &position);
										ZEPHIR_CALL_USER_FUNC_ARRAY(&_14$$19, &converter, &_15$$19);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_14$$19, PH_COPY | PH_SEPARATE);
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
							zephir_check_call_status();
							_17$$13 = 1;
							while (1) {
								if (_17$$13) {
									_17$$13 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &paths, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_16$$13, &paths, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_16$$13)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&part, &paths, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&position, &paths, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&matchPosition);
									if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_18$$22);
											ZEPHIR_INIT_NVAR(&_19$$22);
											zephir_create_array(&_19$$22, 1, 0);
											zephir_array_fast_append(&_19$$22, &matchPosition);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_18$$22, &converter, &_19$$22);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_18$$22, PH_COPY | PH_SEPARATE);
										} else {
											zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
										}
									} else {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_20$$25);
											ZEPHIR_INIT_NVAR(&_21$$25);
											zephir_create_array(&_21$$25, 1, 0);
											zephir_array_fast_append(&_21$$25, &position);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_20$$25, &converter, &_21$$25);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_20$$25, PH_COPY | PH_SEPARATE);
										}
									}
							}
						}
						ZEPHIR_INIT_NVAR(&position);
						ZEPHIR_INIT_NVAR(&part);
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 504, &matches);
					}
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 503, &route);
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_3$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_23$$3 = 1;
			while (1) {
				if (_23$$3) {
					_23$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_3$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_22$$3, &_3$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_22$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&route, &_3$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&pattern, &route, "getcompiledpattern", NULL, 0);
					zephir_check_call_status();
					if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/Cli/Router.zep", 256)) {
						ZEPHIR_INIT_NVAR(&routeFound);
						zephir_preg_match(&routeFound, &pattern, arguments, &matches, 0, 0 , 0 );
					} else {
						ZEPHIR_INIT_NVAR(&routeFound);
						ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, arguments));
					}
					if (zephir_is_true(&routeFound)) {
						ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getbeforematch", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
							if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
								ZEPHIR_INIT_NVAR(&_24$$31);
								object_init_ex(&_24$$31, phalcon_cli_router_exceptions_beforematchnotcallable_ce);
								ZEPHIR_CALL_METHOD(&_25$$31, &route, "getpattern", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &_24$$31, "__construct", &_7, 458, &_25$$31);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_24$$31, "phalcon/Cli/Router.zep", 273);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_26$$30);
							zephir_create_array(&_26$$30, 3, 0);
							zephir_array_fast_append(&_26$$30, arguments);
							zephir_array_fast_append(&_26$$30, &route);
							zephir_array_fast_append(&_26$$30, this_ptr);
							ZEPHIR_INIT_NVAR(&routeFound);
							ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_26$$30);
							zephir_check_call_status();
						}
					}
					if (zephir_is_true(&routeFound)) {
						ZEPHIR_CALL_METHOD(&paths, &route, "getpaths", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&parts, &paths);
						if (Z_TYPE_P(&matches) == IS_ARRAY) {
							ZEPHIR_CALL_METHOD(&converters, &route, "getconverters", NULL, 0);
							zephir_check_call_status();
							zephir_is_iterable(&paths, 0, "phalcon/Cli/Router.zep", 338);
							if (Z_TYPE_P(&paths) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _28$$33, _29$$33, _27$$33)
								{
									ZEPHIR_INIT_NVAR(&part);
									if (_29$$33 != NULL) { 
										ZVAL_STR_COPY(&part, _29$$33);
									} else {
										ZVAL_LONG(&part, _28$$33);
									}
									ZEPHIR_INIT_NVAR(&position);
									ZVAL_COPY(&position, _27$$33);
									ZEPHIR_OBS_NVAR(&matchPosition);
									if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_30$$36);
											ZEPHIR_INIT_NVAR(&_31$$36);
											zephir_create_array(&_31$$36, 1, 0);
											zephir_array_fast_append(&_31$$36, &matchPosition);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_30$$36, &converter, &_31$$36);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_30$$36, PH_COPY | PH_SEPARATE);
										} else {
											zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
										}
									} else {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_32$$39);
											ZEPHIR_INIT_NVAR(&_33$$39);
											zephir_create_array(&_33$$39, 1, 0);
											zephir_array_fast_append(&_33$$39, &position);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_32$$39, &converter, &_33$$39);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_32$$39, PH_COPY | PH_SEPARATE);
										}
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
								zephir_check_call_status();
								_35$$33 = 1;
								while (1) {
									if (_35$$33) {
										_35$$33 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, &paths, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_34$$33, &paths, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_34$$33)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&part, &paths, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&position, &paths, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_OBS_NVAR(&matchPosition);
										if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_INIT_NVAR(&_36$$42);
												ZEPHIR_INIT_NVAR(&_37$$42);
												zephir_create_array(&_37$$42, 1, 0);
												zephir_array_fast_append(&_37$$42, &matchPosition);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_36$$42, &converter, &_37$$42);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_36$$42, PH_COPY | PH_SEPARATE);
											} else {
												zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
											}
										} else {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_INIT_NVAR(&_38$$45);
												ZEPHIR_INIT_NVAR(&_39$$45);
												zephir_create_array(&_39$$45, 1, 0);
												zephir_array_fast_append(&_39$$45, &position);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_38$$45, &converter, &_39$$45);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_38$$45, PH_COPY | PH_SEPARATE);
											}
										}
								}
							}
							ZEPHIR_INIT_NVAR(&position);
							ZEPHIR_INIT_NVAR(&part);
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 504, &matches);
						}
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 503, &route);
						break;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&route);
		if (zephir_is_true(&routeFound)) {
			if (1) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 502, &__$true);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 502, &__$false);
			}
		} else {
			if (0) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 502, &__$true);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 502, &__$false);
			}
			zephir_read_property_cached(&_40$$47, this_ptr, _zephir_prop_4, 505, PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 506, &_40$$47);
			zephir_read_property_cached(&_41$$47, this_ptr, _zephir_prop_6, 507, PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 508, &_41$$47);
			zephir_read_property_cached(&_42$$47, this_ptr, _zephir_prop_8, 509, PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 510, &_42$$47);
			zephir_read_property_cached(&_43$$47, this_ptr, _zephir_prop_10, 511, PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 512, &_43$$47);
			RETURN_THIS();
		}
	} else {
		ZEPHIR_CPY_WRT(&parts, arguments);
	}
	ZEPHIR_INIT_VAR(&moduleName);
	ZVAL_NULL(&moduleName);
	ZEPHIR_INIT_VAR(&taskName);
	ZVAL_NULL(&taskName);
	ZEPHIR_INIT_VAR(&actionName);
	ZVAL_NULL(&actionName);
	ZEPHIR_OBS_NVAR(&moduleName);
	if (zephir_array_isset_string_fetch(&moduleName, &parts, SL("module"), 0)) {
		zephir_array_unset_string(&parts, SL("module"), PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(&moduleName);
		zephir_read_property_cached(&moduleName, this_ptr, _zephir_prop_4, 505, PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&taskName);
	if (zephir_array_isset_string_fetch(&taskName, &parts, SL("task"), 0)) {
		zephir_array_unset_string(&parts, SL("task"), PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(&taskName);
		zephir_read_property_cached(&taskName, this_ptr, _zephir_prop_6, 507, PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&actionName);
	if (zephir_array_isset_string_fetch(&actionName, &parts, SL("action"), 0)) {
		zephir_array_unset_string(&parts, SL("action"), PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(&actionName);
		zephir_read_property_cached(&actionName, this_ptr, _zephir_prop_8, 509, PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&params);
	if (zephir_array_isset_string_fetch(&params, &parts, SL("params"), 0)) {
		if (Z_TYPE_P(&params) != IS_ARRAY) {
			zephir_cast_to_string(&_44$$56, &params);
			ZVAL_LONG(&_45$$56, 1);
			ZEPHIR_INIT_VAR(&strParams);
			zephir_substr(&strParams, &_44$$56, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			if (zephir_is_true(&strParams)) {
				ZEPHIR_CALL_CE_STATIC(&_46$$57, phalcon_cli_router_route_ce, "getdelimiter", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&params);
				zephir_fast_explode(&params, &_46$$57, &strParams, LONG_MAX);
			} else {
				ZEPHIR_INIT_NVAR(&params);
				array_init(&params);
			}
		}
		zephir_array_unset_string(&parts, SL("params"), PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(&params))) {
		ZEPHIR_INIT_VAR(&_47$$59);
		zephir_fast_array_merge(&_47$$59, &params, &parts);
		ZEPHIR_CPY_WRT(&params, &_47$$59);
	} else {
		ZEPHIR_CPY_WRT(&params, &parts);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 506, &moduleName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 508, &taskName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 510, &actionName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 512, &params);
	RETURN_THIS();
}

/**
 * Sets the default action name
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultAction)
{
	zval actionName_zv;
	zend_string *actionName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultAction", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&actionName_zv, actionName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 509, &actionName_zv);
	RETURN_THISW();
}

/**
 * Sets the name of the default module
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultModule)
{
	zval moduleName_zv;
	zend_string *moduleName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultModule", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(moduleName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&moduleName_zv, moduleName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 505, &moduleName_zv);
	RETURN_THISW();
}

/**
 * Sets an array of default paths. If a route is missing a path the router
 * will use the defined here. This method must not be used to set a 404
 * route
 *
 *```php
 * $router->setDefaults(
 *     [
 *         "module" => "common",
 *         "action" => "index",
 *     ]
 * );
 *```
 *
 * @phpstan-param cli_router_defaults $defaults
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaults)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *defaults_param = NULL, module, task, action, params;
	zval defaults;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&task);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&params);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultModule", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("defaultTask", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("defaultAction", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("defaultParams", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(defaults, defaults_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &defaults_param);
	zephir_get_arrval(&defaults, defaults_param);
	zephir_memory_observe(&module);
	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 505, &module);
	}
	zephir_memory_observe(&task);
	if (zephir_array_isset_string_fetch(&task, &defaults, SL("task"), 0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 507, &task);
	}
	zephir_memory_observe(&action);
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 509, &action);
	}
	zephir_memory_observe(&params);
	if (zephir_array_isset_string_fetch(&params, &defaults, SL("params"), 0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 511, &params);
	}
	RETURN_THIS();
}

/**
 * Sets the default controller name
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultTask)
{
	zval taskName_zv;
	zend_string *taskName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&taskName_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultTask", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(taskName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&taskName_zv, taskName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 507, &taskName_zv);
	RETURN_THISW();
}

/**
 * Checks if the router matches any of the defined routes
 */
PHP_METHOD(Phalcon_Cli_Router, wasMatched)
{

	RETURN_MEMBER(getThis(), "wasMatched");
}

