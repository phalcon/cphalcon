
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


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
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Router)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli, Router, phalcon, cli_router, phalcon_di_abstractinjectionaware_ce, phalcon_cli_router_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cli_router_ce, SL("action"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cli_router_ce, SL("defaultAction"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cli_router_ce, SL("defaultModule"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_cli_router_ce, SL("defaultParams"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cli_router_ce, SL("defaultTask"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var RouteInterface|null
	 */
	zend_declare_property_null(phalcon_cli_router_ce, SL("matchedRoute"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_cli_router_ce, SL("matches"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cli_router_ce, SL("module"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_cli_router_ce, SL("params"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_cli_router_ce, SL("routes"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cli_router_ce, SL("task"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_cli_router_ce, SL("wasMatched"), 0, ZEND_ACC_PROTECTED);
	phalcon_cli_router_ce->create_object = zephir_init_properties_Phalcon_Cli_Router;

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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultRoutes_param = NULL, route, _1$$3, _2$$3, _4$$3;
	zend_bool defaultRoutes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
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
		ZEPHIR_INIT_VAR(&route);
		object_init_ex(&route, phalcon_cli_router_route_ce);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		add_assoc_long_ex(&_0$$3, SL("task"), 1);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+)[:delimiter]{0,1}$#");
		ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 382, &_1$$3, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, &route, "getrouteid", NULL, 383);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("routes"), &_2$$3, &route);
		ZEPHIR_INIT_NVAR(&route);
		object_init_ex(&route, phalcon_cli_router_route_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0);
		add_assoc_long_ex(&_3$$3, SL("task"), 1);
		add_assoc_long_ex(&_3$$3, SL("action"), 2);
		add_assoc_long_ex(&_3$$3, SL("params"), 3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+):delimiter([a-zA-Z0-9\\.\\_]+)(:delimiter.*)?$#");
		ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 382, &_1$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, &route, "getrouteid", NULL, 383);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("routes"), &_4$$3, &route);
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
 * @phpstan-param array|string|null $paths
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
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 382, &pattern_zv, paths);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 383);
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
 */
PHP_METHOD(Phalcon_Cli_Router, getParameters)
{

	RETURN_MEMBER_TYPED(getThis(), "params", IS_ARRAY);
}

/**
 * Returns processed extra params
 *
 * @deprecated Use {@see getParameters()} instead.
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
 *
 * @phpstan-param string $id
 */
PHP_METHOD(Phalcon_Cli_Router, getRouteById)
{
	zval *id, id_sub, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &id);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_0, id)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, id, PH_NOISY | PH_READONLY, "phalcon/Cli/Router.zep", 211);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Cli/Router.zep", 230);
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
 * @param array|string|null arguments
 */
PHP_METHOD(Phalcon_Cli_Router, handle)
{
	zval _44$$55;
	zend_string *_11$$12, *_29$$32;
	zend_ulong _10$$12, _28$$32;
	zval _8$$9, _13$$15, _15$$18, _19$$21, _21$$24, _26$$29, _31$$35, _33$$38, _37$$41, _39$$44;
	zend_bool _0$$3, _23$$3, _17$$12, _35$$32;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, arguments_sub, __$true, __$false, __$null, moduleName, taskName, actionName, params, route, parts, pattern, routeFound, matches, paths, beforeMatch, converters, converter, part, position, matchPosition, strParams, _3$$3, *_4$$3, _22$$3, _1$$4, _2$$4, _5$$10, _6$$10, *_9$$12, _16$$12, _12$$15, _14$$18, _18$$21, _20$$24, _24$$30, _25$$30, *_27$$32, _34$$32, _30$$35, _32$$38, _36$$41, _38$$44, _40$$46, _41$$46, _42$$46, _43$$46, _45$$55, _46$$56, _47$$58;
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
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_18$$21);
	ZVAL_UNDEF(&_20$$24);
	ZVAL_UNDEF(&_24$$30);
	ZVAL_UNDEF(&_25$$30);
	ZVAL_UNDEF(&_34$$32);
	ZVAL_UNDEF(&_30$$35);
	ZVAL_UNDEF(&_32$$38);
	ZVAL_UNDEF(&_36$$41);
	ZVAL_UNDEF(&_38$$44);
	ZVAL_UNDEF(&_40$$46);
	ZVAL_UNDEF(&_41$$46);
	ZVAL_UNDEF(&_42$$46);
	ZVAL_UNDEF(&_43$$46);
	ZVAL_UNDEF(&_45$$55);
	ZVAL_UNDEF(&_46$$56);
	ZVAL_UNDEF(&_47$$58);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_19$$21);
	ZVAL_UNDEF(&_21$$24);
	ZVAL_UNDEF(&_26$$29);
	ZVAL_UNDEF(&_31$$35);
	ZVAL_UNDEF(&_33$$38);
	ZVAL_UNDEF(&_37$$41);
	ZVAL_UNDEF(&_39$$44);
	ZVAL_UNDEF(&_44$$55);
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
		arguments = &__$null;
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("wasMatched"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("wasMatched"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("matchedRoute"), &__$null);
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
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 384, &_2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Cli/Router.zep", 269);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_3$$3, 0, "phalcon/Cli/Router.zep", 373);
		if (Z_TYPE_P(&_3$$3) == IS_ARRAY) {
			ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(&_3$$3), _4$$3)
			{
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _4$$3);
				ZEPHIR_CALL_METHOD(&pattern, &route, "getcompiledpattern", NULL, 0);
				zephir_check_call_status();
				if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/Cli/Router.zep", 278)) {
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
							ZEPHIR_INIT_NVAR(&_5$$10);
							object_init_ex(&_5$$10, phalcon_cli_router_exceptions_beforematchnotcallable_ce);
							ZEPHIR_CALL_METHOD(&_6$$10, &route, "getpattern", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &_5$$10, "__construct", &_7, 385, &_6$$10);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_5$$10, "phalcon/Cli/Router.zep", 295);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_8$$9);
						zephir_create_array(&_8$$9, 3, 0);
						zephir_array_fast_append(&_8$$9, arguments);
						zephir_array_fast_append(&_8$$9, &route);
						zephir_array_fast_append(&_8$$9, this_ptr);
						ZEPHIR_INIT_NVAR(&routeFound);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_8$$9);
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
						zephir_is_iterable(&paths, 0, "phalcon/Cli/Router.zep", 360);
						if (Z_TYPE_P(&paths) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _10$$12, _11$$12, _9$$12)
							{
								ZEPHIR_INIT_NVAR(&part);
								if (_11$$12 != NULL) { 
									ZVAL_STR_COPY(&part, _11$$12);
								} else {
									ZVAL_LONG(&part, _10$$12);
								}
								ZEPHIR_INIT_NVAR(&position);
								ZVAL_COPY(&position, _9$$12);
								ZEPHIR_OBS_NVAR(&matchPosition);
								if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
									ZEPHIR_OBS_NVAR(&converter);
									if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
										ZEPHIR_INIT_NVAR(&_12$$15);
										ZEPHIR_INIT_NVAR(&_13$$15);
										zephir_create_array(&_13$$15, 1, 0);
										zephir_array_fast_append(&_13$$15, &matchPosition);
										ZEPHIR_CALL_USER_FUNC_ARRAY(&_12$$15, &converter, &_13$$15);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_12$$15, PH_COPY | PH_SEPARATE);
									} else {
										zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
									}
								} else {
									ZEPHIR_OBS_NVAR(&converter);
									if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
										ZEPHIR_INIT_NVAR(&_14$$18);
										ZEPHIR_INIT_NVAR(&_15$$18);
										zephir_create_array(&_15$$18, 1, 0);
										zephir_array_fast_append(&_15$$18, &position);
										ZEPHIR_CALL_USER_FUNC_ARRAY(&_14$$18, &converter, &_15$$18);
										zephir_check_call_status();
										zephir_array_update_zval(&parts, &part, &_14$$18, PH_COPY | PH_SEPARATE);
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
							zephir_check_call_status();
							_17$$12 = 1;
							while (1) {
								if (_17$$12) {
									_17$$12 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &paths, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_16$$12, &paths, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_16$$12)) {
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
											ZEPHIR_INIT_NVAR(&_18$$21);
											ZEPHIR_INIT_NVAR(&_19$$21);
											zephir_create_array(&_19$$21, 1, 0);
											zephir_array_fast_append(&_19$$21, &matchPosition);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_18$$21, &converter, &_19$$21);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_18$$21, PH_COPY | PH_SEPARATE);
										} else {
											zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
										}
									} else {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_20$$24);
											ZEPHIR_INIT_NVAR(&_21$$24);
											zephir_create_array(&_21$$24, 1, 0);
											zephir_array_fast_append(&_21$$24, &position);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_20$$24, &converter, &_21$$24);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_20$$24, PH_COPY | PH_SEPARATE);
										}
									}
							}
						}
						ZEPHIR_INIT_NVAR(&position);
						ZEPHIR_INIT_NVAR(&part);
						zephir_update_property_zval(this_ptr, ZEND_STRL("matches"), &matches);
					}
					zephir_update_property_zval(this_ptr, ZEND_STRL("matchedRoute"), &route);
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
					if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/Cli/Router.zep", 278)) {
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
								ZEPHIR_INIT_NVAR(&_24$$30);
								object_init_ex(&_24$$30, phalcon_cli_router_exceptions_beforematchnotcallable_ce);
								ZEPHIR_CALL_METHOD(&_25$$30, &route, "getpattern", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &_24$$30, "__construct", &_7, 385, &_25$$30);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_24$$30, "phalcon/Cli/Router.zep", 295);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_26$$29);
							zephir_create_array(&_26$$29, 3, 0);
							zephir_array_fast_append(&_26$$29, arguments);
							zephir_array_fast_append(&_26$$29, &route);
							zephir_array_fast_append(&_26$$29, this_ptr);
							ZEPHIR_INIT_NVAR(&routeFound);
							ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_26$$29);
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
							zephir_is_iterable(&paths, 0, "phalcon/Cli/Router.zep", 360);
							if (Z_TYPE_P(&paths) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _28$$32, _29$$32, _27$$32)
								{
									ZEPHIR_INIT_NVAR(&part);
									if (_29$$32 != NULL) { 
										ZVAL_STR_COPY(&part, _29$$32);
									} else {
										ZVAL_LONG(&part, _28$$32);
									}
									ZEPHIR_INIT_NVAR(&position);
									ZVAL_COPY(&position, _27$$32);
									ZEPHIR_OBS_NVAR(&matchPosition);
									if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0)) {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_30$$35);
											ZEPHIR_INIT_NVAR(&_31$$35);
											zephir_create_array(&_31$$35, 1, 0);
											zephir_array_fast_append(&_31$$35, &matchPosition);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_30$$35, &converter, &_31$$35);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_30$$35, PH_COPY | PH_SEPARATE);
										} else {
											zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
										}
									} else {
										ZEPHIR_OBS_NVAR(&converter);
										if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
											ZEPHIR_INIT_NVAR(&_32$$38);
											ZEPHIR_INIT_NVAR(&_33$$38);
											zephir_create_array(&_33$$38, 1, 0);
											zephir_array_fast_append(&_33$$38, &position);
											ZEPHIR_CALL_USER_FUNC_ARRAY(&_32$$38, &converter, &_33$$38);
											zephir_check_call_status();
											zephir_array_update_zval(&parts, &part, &_32$$38, PH_COPY | PH_SEPARATE);
										}
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &paths, "rewind", NULL, 0);
								zephir_check_call_status();
								_35$$32 = 1;
								while (1) {
									if (_35$$32) {
										_35$$32 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, &paths, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_34$$32, &paths, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_34$$32)) {
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
												ZEPHIR_INIT_NVAR(&_36$$41);
												ZEPHIR_INIT_NVAR(&_37$$41);
												zephir_create_array(&_37$$41, 1, 0);
												zephir_array_fast_append(&_37$$41, &matchPosition);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_36$$41, &converter, &_37$$41);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_36$$41, PH_COPY | PH_SEPARATE);
											} else {
												zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
											}
										} else {
											ZEPHIR_OBS_NVAR(&converter);
											if (zephir_array_isset_fetch(&converter, &converters, &part, 0)) {
												ZEPHIR_INIT_NVAR(&_38$$44);
												ZEPHIR_INIT_NVAR(&_39$$44);
												zephir_create_array(&_39$$44, 1, 0);
												zephir_array_fast_append(&_39$$44, &position);
												ZEPHIR_CALL_USER_FUNC_ARRAY(&_38$$44, &converter, &_39$$44);
												zephir_check_call_status();
												zephir_array_update_zval(&parts, &part, &_38$$44, PH_COPY | PH_SEPARATE);
											}
										}
								}
							}
							ZEPHIR_INIT_NVAR(&position);
							ZEPHIR_INIT_NVAR(&part);
							zephir_update_property_zval(this_ptr, ZEND_STRL("matches"), &matches);
						}
						zephir_update_property_zval(this_ptr, ZEND_STRL("matchedRoute"), &route);
						break;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&route);
		if (zephir_is_true(&routeFound)) {
			if (1) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("wasMatched"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("wasMatched"), &__$false);
			}
		} else {
			if (0) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("wasMatched"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("wasMatched"), &__$false);
			}
			zephir_read_property(&_40$$46, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval(this_ptr, ZEND_STRL("module"), &_40$$46);
			zephir_read_property(&_41$$46, this_ptr, ZEND_STRL("defaultTask"), PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval(this_ptr, ZEND_STRL("task"), &_41$$46);
			zephir_read_property(&_42$$46, this_ptr, ZEND_STRL("defaultAction"), PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval(this_ptr, ZEND_STRL("action"), &_42$$46);
			zephir_read_property(&_43$$46, this_ptr, ZEND_STRL("defaultParams"), PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &_43$$46);
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
		zephir_read_property(&moduleName, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&taskName);
	if (zephir_array_isset_string_fetch(&taskName, &parts, SL("task"), 0)) {
		zephir_array_unset_string(&parts, SL("task"), PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(&taskName);
		zephir_read_property(&taskName, this_ptr, ZEND_STRL("defaultTask"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&actionName);
	if (zephir_array_isset_string_fetch(&actionName, &parts, SL("action"), 0)) {
		zephir_array_unset_string(&parts, SL("action"), PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(&actionName);
		zephir_read_property(&actionName, this_ptr, ZEND_STRL("defaultAction"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&params);
	if (zephir_array_isset_string_fetch(&params, &parts, SL("params"), 0)) {
		if (Z_TYPE_P(&params) != IS_ARRAY) {
			zephir_cast_to_string(&_44$$55, &params);
			ZVAL_LONG(&_45$$55, 1);
			ZEPHIR_INIT_VAR(&strParams);
			zephir_substr(&strParams, &_44$$55, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			if (zephir_is_true(&strParams)) {
				ZEPHIR_CALL_CE_STATIC(&_46$$56, phalcon_cli_router_route_ce, "getdelimiter", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&params);
				zephir_fast_explode(&params, &_46$$56, &strParams, LONG_MAX);
			} else {
				ZEPHIR_INIT_NVAR(&params);
				array_init(&params);
			}
		}
		zephir_array_unset_string(&parts, SL("params"), PH_SEPARATE);
	}
	if (zephir_fast_count_int(&params)) {
		ZEPHIR_INIT_VAR(&_47$$58);
		zephir_fast_array_merge(&_47$$58, &params, &parts);
		ZEPHIR_CPY_WRT(&params, &_47$$58);
	} else {
		ZEPHIR_CPY_WRT(&params, &parts);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("module"), &moduleName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("task"), &taskName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("action"), &actionName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &params);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&actionName_zv, actionName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultAction"), &actionName_zv);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(moduleName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&moduleName_zv, moduleName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultModule"), &moduleName_zv);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(defaults, defaults_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &defaults_param);
	ZEPHIR_OBS_COPY_OR_DUP(&defaults, defaults_param);
	zephir_memory_observe(&module);
	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultModule"), &module);
	}
	zephir_memory_observe(&task);
	if (zephir_array_isset_string_fetch(&task, &defaults, SL("task"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultTask"), &task);
	}
	zephir_memory_observe(&action);
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultAction"), &action);
	}
	zephir_memory_observe(&params);
	if (zephir_array_isset_string_fetch(&params, &defaults, SL("params"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultParams"), &params);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(taskName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&taskName_zv, taskName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultTask"), &taskName_zv);
	RETURN_THISW();
}

/**
 * Checks if the router matches any of the defined routes
 */
PHP_METHOD(Phalcon_Cli_Router, wasMatched)
{

	RETURN_MEMBER(getThis(), "wasMatched");
}

zend_object *zephir_init_properties_Phalcon_Cli_Router(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	

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
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("params"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("matches"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("matches"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("defaultParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("defaultParams"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

