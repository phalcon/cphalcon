
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
#include "kernel/string.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
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
	zval _0$$3, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultRoutes_param = NULL, _1$$3;
	zend_bool defaultRoutes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$3);
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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_2, 0, &_1$$3, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0);
		add_assoc_long_ex(&_3$$3, SL("task"), 1);
		add_assoc_long_ex(&_3$$3, SL("action"), 2);
		add_assoc_long_ex(&_3$$3, SL("params"), 3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+):delimiter([a-zA-Z0-9\\.\\_]+)(:delimiter.*)?$#");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_2, 0, &_1$$3, &_3$$3);
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
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 458, &pattern_zv, paths);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getRouteId", NULL, 459);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("routes"), &_0, &route);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getParameters", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a route object by its id
 */
PHP_METHOD(Phalcon_Cli_Router, getRouteById)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *id, id_sub, _0, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &id);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 517, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_value(&_0, id);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 517, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_3$$3);
		zephir_array_fetch(&_3$$3, &_2$$3, id, PH_NOISY, "phalcon/Cli/Router.zep", 179);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&_3$$3);
	}
	RETURN_MM_BOOL(0);
}

/**
 * Returns a route object by its name
 */
PHP_METHOD(Phalcon_Cli_Router, getRouteByName)
{
	zend_bool _7, _5$$3, _9$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, route, _0, *_1, _2, *_3, _6, _4$$3, _8$$5;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8$$5);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 517, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Cli/Router.zep", 198);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _3);
			ZEPHIR_CALL_METHOD(&_4$$3, &route, "getName", NULL, 0);
			zephir_check_call_status();
			_5$$3 = ZEPHIR_IS_EQUAL(&_4$$3, &name_zv);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_5$$3) {
				RETURN_CCTOR(&route);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$5, &route, "getName", NULL, 0);
				zephir_check_call_status();
				_9$$5 = ZEPHIR_IS_EQUAL(&_8$$5, &name_zv);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_9$$5) {
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
	zval _70$$56;
	zend_string *_17$$13, *_45$$33;
	zend_ulong _16$$13, _44$$33;
	zval _12$$10, _21$$16, _24$$19, _30$$22, _33$$25, _40$$30, _49$$36, _52$$39, _58$$42, _61$$45;
	zend_bool _66, _67, _68, _69, _1$$3, _35$$3, _8$$8, _26$$13, _18$$14, _19$$15, _22$$18, _27$$20, _28$$21, _31$$24, _36$$28, _54$$33, _46$$34, _47$$35, _50$$38, _55$$40, _56$$41, _59$$44;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_39 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, arguments_sub, __$true, __$false, __$null, moduleName, taskName, actionName, params, route, parts, pattern, routeFound, matches, paths, beforeMatch, converters, converter, part, position, matchPosition, strParams, _0, _4$$3, *_5$$3, _6$$3, *_7$$3, _34$$3, _2$$4, _3$$4, _9$$11, _10$$11, *_13$$13, _14$$13, *_15$$13, _25$$13, _20$$16, _23$$19, _29$$22, _32$$25, _37$$31, _38$$31, *_41$$33, _42$$33, *_43$$33, _53$$33, _48$$36, _51$$39, _57$$42, _60$$45, _62$$47, _63$$47, _64$$47, _65$$47, _71$$56, _72$$57, _73$$59;
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
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_34$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_23$$19);
	ZVAL_UNDEF(&_29$$22);
	ZVAL_UNDEF(&_32$$25);
	ZVAL_UNDEF(&_37$$31);
	ZVAL_UNDEF(&_38$$31);
	ZVAL_UNDEF(&_42$$33);
	ZVAL_UNDEF(&_53$$33);
	ZVAL_UNDEF(&_48$$36);
	ZVAL_UNDEF(&_51$$39);
	ZVAL_UNDEF(&_57$$42);
	ZVAL_UNDEF(&_60$$45);
	ZVAL_UNDEF(&_62$$47);
	ZVAL_UNDEF(&_63$$47);
	ZVAL_UNDEF(&_64$$47);
	ZVAL_UNDEF(&_65$$47);
	ZVAL_UNDEF(&_71$$56);
	ZVAL_UNDEF(&_72$$57);
	ZVAL_UNDEF(&_73$$59);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_24$$19);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_33$$25);
	ZVAL_UNDEF(&_40$$30);
	ZVAL_UNDEF(&_49$$36);
	ZVAL_UNDEF(&_52$$39);
	ZVAL_UNDEF(&_58$$42);
	ZVAL_UNDEF(&_61$$45);
	ZVAL_UNDEF(&_70$$56);
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
		_zephir_prop_0 = zend_string_init("matches", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("wasMatched", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("matchedRoute", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("routes", 6, 1);
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
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 518, &_0);
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 519, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 519, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 520, &__$null);
	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		_1$$3 = Z_TYPE_P(arguments) != IS_STRING;
		if (_1$$3) {
			_1$$3 = Z_TYPE_P(arguments) != IS_NULL;
		}
		if (UNEXPECTED(_1$$3)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_cli_router_exceptions_routerargumentsinvalidtype_ce);
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_gettype(&_3$$4, arguments);
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 460, &_3$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "phalcon/Cli/Router.zep", 240);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(arguments) == IS_NULL) {
			ZEPHIR_INIT_NVAR(arguments);
			ZVAL_STRING(arguments, "");
		}
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_3, 517, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4$$3) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_6$$3);
			zephir_string_to_char_array(&_6$$3, &_4$$3);
			_5$$3 = &_6$$3;
		} else {
			_5$$3 = &_4$$3;
		}
		zephir_is_iterable(_5$$3, 0, "phalcon/Cli/Router.zep", 352);
		if (Z_TYPE_P(_5$$3) == IS_ARRAY) {
			ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(_5$$3), _7$$3)
			{
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _7$$3);
				ZEPHIR_CALL_METHOD(&pattern, &route, "getCompiledPattern", NULL, 0);
				zephir_check_call_status();
				if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/Cli/Router.zep", 257)) {
					ZEPHIR_INIT_NVAR(&routeFound);
					zephir_preg_match(&routeFound, &pattern, arguments, &matches, 0, 0 , 0 );
				} else {
					_8$$8 = ZEPHIR_IS_EQUAL(&pattern, arguments);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&routeFound);
					ZVAL_BOOL(&routeFound, _8$$8);
				}
				if (zephir_is_true(&routeFound)) {
					ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getBeforeMatch", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
						if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
							ZEPHIR_INIT_NVAR(&_9$$11);
							object_init_ex(&_9$$11, phalcon_cli_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD(&_10$$11, &route, "getPattern", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &_9$$11, "__construct", &_11, 461, &_10$$11);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_9$$11, "phalcon/Cli/Router.zep", 274);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_12$$10);
						zephir_create_array(&_12$$10, 3, 0);
						zephir_array_fast_append(&_12$$10, arguments);
						zephir_array_fast_append(&_12$$10, &route);
						zephir_array_fast_append(&_12$$10, this_ptr);
						ZEPHIR_INIT_NVAR(&routeFound);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_12$$10);
						zephir_check_call_status();
					}
				}
				if (zephir_is_true(&routeFound)) {
					ZEPHIR_CALL_METHOD(&paths, &route, "getPaths", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&parts, &paths);
					if (Z_TYPE_P(&matches) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD(&converters, &route, "getConverters", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&paths) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_14$$13);
							zephir_string_to_char_array(&_14$$13, &paths);
							_13$$13 = &_14$$13;
						} else {
							_13$$13 = &paths;
						}
						zephir_is_iterable(_13$$13, 0, "phalcon/Cli/Router.zep", 339);
						if (Z_TYPE_P(_13$$13) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_13$$13), _16$$13, _17$$13, _15$$13)
							{
								ZEPHIR_INIT_NVAR(&part);
								if (_17$$13 != NULL) { 
									ZVAL_STR_COPY(&part, _17$$13);
								} else {
									ZVAL_LONG(&part, _16$$13);
								}
								ZEPHIR_INIT_NVAR(&position);
								ZVAL_COPY(&position, _15$$13);
								ZEPHIR_OBS_NVAR(&matchPosition);
								_18$$14 = zephir_array_isset_fetch(&matchPosition, &matches, &position, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_18$$14) {
									ZEPHIR_OBS_NVAR(&converter);
									_19$$15 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_19$$15) {
										ZEPHIR_INIT_NVAR(&_20$$16);
										ZEPHIR_INIT_NVAR(&_21$$16);
										zephir_create_array(&_21$$16, 1, 0);
										zephir_array_fast_append(&_21$$16, &matchPosition);
										ZEPHIR_CALL_USER_FUNC_ARRAY(&_20$$16, &converter, &_21$$16);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_20$$16, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} else {
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
								} else {
									ZEPHIR_OBS_NVAR(&converter);
									_22$$18 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_22$$18) {
										ZEPHIR_INIT_NVAR(&_23$$19);
										ZEPHIR_INIT_NVAR(&_24$$19);
										zephir_create_array(&_24$$19, 1, 0);
										zephir_array_fast_append(&_24$$19, &position);
										ZEPHIR_CALL_USER_FUNC_ARRAY(&_23$$19, &converter, &_24$$19);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_23$$19, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _13$$13, "rewind", NULL, 0);
							zephir_check_call_status();
							_26$$13 = 1;
							while (1) {
								if (_26$$13) {
									_26$$13 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _13$$13, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_25$$13, _13$$13, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_25$$13)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&part, _13$$13, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&position, _13$$13, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&matchPosition);
									_27$$20 = zephir_array_isset_fetch(&matchPosition, &matches, &position, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_27$$20) {
										ZEPHIR_OBS_NVAR(&converter);
										_28$$21 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (_28$$21) {
											ZEPHIR_INIT_NVAR(&_29$$22);
											ZEPHIR_INIT_NVAR(&_30$$22);
											zephir_create_array(&_30$$22, 1, 0);
											zephir_array_fast_append(&_30$$22, &matchPosition);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_29$$22, &converter, &_30$$22);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_29$$22, PH_COPY | PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										} else {
											zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&converter);
										_31$$24 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (_31$$24) {
											ZEPHIR_INIT_NVAR(&_32$$25);
											ZEPHIR_INIT_NVAR(&_33$$25);
											zephir_create_array(&_33$$25, 1, 0);
											zephir_array_fast_append(&_33$$25, &position);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_32$$25, &converter, &_33$$25);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_32$$25, PH_COPY | PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									}
							}
						}
						ZEPHIR_INIT_NVAR(&position);
						ZEPHIR_INIT_NVAR(&part);
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 518, &matches);
					}
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 520, &route);
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _5$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_35$$3 = 1;
			while (1) {
				if (_35$$3) {
					_35$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _5$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_34$$3, _5$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_34$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&route, _5$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&pattern, &route, "getCompiledPattern", NULL, 0);
					zephir_check_call_status();
					if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/Cli/Router.zep", 257)) {
						ZEPHIR_INIT_NVAR(&routeFound);
						zephir_preg_match(&routeFound, &pattern, arguments, &matches, 0, 0 , 0 );
					} else {
						_36$$28 = ZEPHIR_IS_EQUAL(&pattern, arguments);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&routeFound);
						ZVAL_BOOL(&routeFound, _36$$28);
					}
					if (zephir_is_true(&routeFound)) {
						ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getBeforeMatch", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
							if (UNEXPECTED(!(zephir_is_callable(&beforeMatch)))) {
								ZEPHIR_INIT_NVAR(&_37$$31);
								object_init_ex(&_37$$31, phalcon_cli_router_exceptions_beforematchnotcallable_ce);
								ZEPHIR_CALL_METHOD(&_38$$31, &route, "getPattern", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &_37$$31, "__construct", &_39, 461, &_38$$31);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_37$$31, "phalcon/Cli/Router.zep", 274);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_40$$30);
							zephir_create_array(&_40$$30, 3, 0);
							zephir_array_fast_append(&_40$$30, arguments);
							zephir_array_fast_append(&_40$$30, &route);
							zephir_array_fast_append(&_40$$30, this_ptr);
							ZEPHIR_INIT_NVAR(&routeFound);
							ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_40$$30);
							zephir_check_call_status();
						}
					}
					if (zephir_is_true(&routeFound)) {
						ZEPHIR_CALL_METHOD(&paths, &route, "getPaths", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&parts, &paths);
						if (Z_TYPE_P(&matches) == IS_ARRAY) {
							ZEPHIR_CALL_METHOD(&converters, &route, "getConverters", NULL, 0);
							zephir_check_call_status();
							if (Z_TYPE_P(&paths) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_42$$33);
								zephir_string_to_char_array(&_42$$33, &paths);
								_41$$33 = &_42$$33;
							} else {
								_41$$33 = &paths;
							}
							zephir_is_iterable(_41$$33, 0, "phalcon/Cli/Router.zep", 339);
							if (Z_TYPE_P(_41$$33) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_41$$33), _44$$33, _45$$33, _43$$33)
								{
									ZEPHIR_INIT_NVAR(&part);
									if (_45$$33 != NULL) { 
										ZVAL_STR_COPY(&part, _45$$33);
									} else {
										ZVAL_LONG(&part, _44$$33);
									}
									ZEPHIR_INIT_NVAR(&position);
									ZVAL_COPY(&position, _43$$33);
									ZEPHIR_OBS_NVAR(&matchPosition);
									_46$$34 = zephir_array_isset_fetch(&matchPosition, &matches, &position, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_46$$34) {
										ZEPHIR_OBS_NVAR(&converter);
										_47$$35 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (_47$$35) {
											ZEPHIR_INIT_NVAR(&_48$$36);
											ZEPHIR_INIT_NVAR(&_49$$36);
											zephir_create_array(&_49$$36, 1, 0);
											zephir_array_fast_append(&_49$$36, &matchPosition);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_48$$36, &converter, &_49$$36);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_48$$36, PH_COPY | PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										} else {
											zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									} else {
										ZEPHIR_OBS_NVAR(&converter);
										_50$$38 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (_50$$38) {
											ZEPHIR_INIT_NVAR(&_51$$39);
											ZEPHIR_INIT_NVAR(&_52$$39);
											zephir_create_array(&_52$$39, 1, 0);
											zephir_array_fast_append(&_52$$39, &position);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_51$$39, &converter, &_52$$39);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_51$$39, PH_COPY | PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _41$$33, "rewind", NULL, 0);
								zephir_check_call_status();
								_54$$33 = 1;
								while (1) {
									if (_54$$33) {
										_54$$33 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _41$$33, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_53$$33, _41$$33, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_53$$33)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&part, _41$$33, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&position, _41$$33, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_OBS_NVAR(&matchPosition);
										_55$$40 = zephir_array_isset_fetch(&matchPosition, &matches, &position, 0);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (_55$$40) {
											ZEPHIR_OBS_NVAR(&converter);
											_56$$41 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											if (_56$$41) {
												ZEPHIR_INIT_NVAR(&_57$$42);
												ZEPHIR_INIT_NVAR(&_58$$42);
												zephir_create_array(&_58$$42, 1, 0);
												zephir_array_fast_append(&_58$$42, &matchPosition);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_57$$42, &converter, &_58$$42);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_57$$42, PH_COPY | PH_SEPARATE);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											} else {
												zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											}
										} else {
											ZEPHIR_OBS_NVAR(&converter);
											_59$$44 = zephir_array_isset_fetch(&converter, &converters, &part, 0);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											if (_59$$44) {
												ZEPHIR_INIT_NVAR(&_60$$45);
												ZEPHIR_INIT_NVAR(&_61$$45);
												zephir_create_array(&_61$$45, 1, 0);
												zephir_array_fast_append(&_61$$45, &position);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_60$$45, &converter, &_61$$45);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_60$$45, PH_COPY | PH_SEPARATE);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											}
										}
								}
							}
							ZEPHIR_INIT_NVAR(&position);
							ZEPHIR_INIT_NVAR(&part);
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 518, &matches);
						}
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 520, &route);
						break;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&route);
		if (zephir_is_true(&routeFound)) {
			if (1) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 519, &__$true);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 519, &__$false);
			}
		} else {
			if (0) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 519, &__$true);
			} else {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 519, &__$false);
			}
			zephir_read_property_cached(&_62$$47, this_ptr, _zephir_prop_4, 521, PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 522, &_62$$47);
			zephir_read_property_cached(&_63$$47, this_ptr, _zephir_prop_6, 523, PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 524, &_63$$47);
			zephir_read_property_cached(&_64$$47, this_ptr, _zephir_prop_8, 525, PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 526, &_64$$47);
			zephir_read_property_cached(&_65$$47, this_ptr, _zephir_prop_10, 527, PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 528, &_65$$47);
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
	_66 = zephir_array_isset_string_fetch(&moduleName, &parts, SL("module"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_66) {
		zephir_array_unset_string(&parts, SL("module"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_OBS_NVAR(&moduleName);
		zephir_read_property_cached(&moduleName, this_ptr, _zephir_prop_4, 521, PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&taskName);
	_67 = zephir_array_isset_string_fetch(&taskName, &parts, SL("task"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_67) {
		zephir_array_unset_string(&parts, SL("task"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_OBS_NVAR(&taskName);
		zephir_read_property_cached(&taskName, this_ptr, _zephir_prop_6, 523, PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&actionName);
	_68 = zephir_array_isset_string_fetch(&actionName, &parts, SL("action"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_68) {
		zephir_array_unset_string(&parts, SL("action"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_OBS_NVAR(&actionName);
		zephir_read_property_cached(&actionName, this_ptr, _zephir_prop_8, 525, PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&params);
	_69 = zephir_array_isset_string_fetch(&params, &parts, SL("params"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_69) {
		if (Z_TYPE_P(&params) != IS_ARRAY) {
			zephir_cast_to_string(&_70$$56, &params);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_LONG(&_71$$56, 1);
			ZEPHIR_INIT_VAR(&strParams);
			zephir_substr(&strParams, &_70$$56, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			if (zephir_is_true(&strParams)) {
				ZEPHIR_CALL_CE_STATIC(&_72$$57, phalcon_cli_router_route_ce, "getDelimiter", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&params);
				zephir_fast_explode(&params, &_72$$57, &strParams, NULL);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_INIT_NVAR(&params);
				array_init(&params);
			}
		}
		zephir_array_unset_string(&parts, SL("params"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (!(ZEPHIR_IS_EMPTY(&params))) {
		ZEPHIR_INIT_VAR(&_73$$59);
		zephir_fast_array_merge(&_73$$59, &params, &parts);
		ZEPHIR_CPY_WRT(&params, &_73$$59);
	} else {
		ZEPHIR_CPY_WRT(&params, &parts);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 522, &moduleName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 524, &taskName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 526, &actionName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_11, 528, &params);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 525, &actionName_zv);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 521, &moduleName_zv);
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
	zend_bool _0, _1, _2, _3;
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
	_0 = zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 521, &module);
	}
	zephir_memory_observe(&task);
	_1 = zephir_array_isset_string_fetch(&task, &defaults, SL("task"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 523, &task);
	}
	zephir_memory_observe(&action);
	_2 = zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 525, &action);
	}
	zephir_memory_observe(&params);
	_3 = zephir_array_isset_string_fetch(&params, &defaults, SL("params"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 527, &params);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 523, &taskName_zv);
	RETURN_THISW();
}

/**
 * Checks if the router matches any of the defined routes
 */
PHP_METHOD(Phalcon_Cli_Router, wasMatched)
{

	RETURN_MEMBER(getThis(), "wasMatched");
}

