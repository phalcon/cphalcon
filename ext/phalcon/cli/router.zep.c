
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/**
 * Phalcon\Cli\Router
 *
 * <p>Phalcon\Cli\Router is the standard framework router. Routing is the
 * process of taking a command-line arguments and
 * decomposing it into parameters to determine which module, task, and
 * action of that task should receive the request</p>
 *
 *<code>
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
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Router) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cli, Router, phalcon, cli_router, phalcon_cli_router_method_entry, 0);

	zend_declare_property_null(phalcon_cli_router_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("_module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("_task"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("_defaultTask"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("_defaultAction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("_defaultParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("_routes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("_matchedRoute"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("_matches"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_cli_router_ce, SL("_wasMatched"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_cli_router_ce->create_object = zephir_init_properties_Phalcon_Cli_Router;

	zend_class_implements(phalcon_cli_router_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cli\Router constructor
 */
PHP_METHOD(Phalcon_Cli_Router, __construct) {

	zval *_1$$3, *_3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultRoutes_param = NULL, *routes = NULL, *_0$$3, *_2$$3 = NULL, *_4$$3;
	zend_bool defaultRoutes;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultRoutes_param);

	if (!defaultRoutes_param) {
		defaultRoutes = 1;
	} else {
		defaultRoutes = zephir_get_boolval(defaultRoutes_param);
	}


	ZEPHIR_INIT_VAR(routes);
	array_init(routes);
	if (defaultRoutes == 1) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, phalcon_cli_router_route_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(_1$$3, SS("task"), 1);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+)[:delimiter]{0,1}$#", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 145, _2$$3, _1$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, _0$$3, PH_SEPARATE, "phalcon/cli/router.zep", 93);
		ZEPHIR_INIT_NVAR(_2$$3);
		object_init_ex(_2$$3, phalcon_cli_router_route_ce);
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_create_array(_3$$3, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(_3$$3, SS("task"), 1);
		add_assoc_long_ex(_3$$3, SS("action"), 2);
		add_assoc_long_ex(_3$$3, SS("params"), 3);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+):delimiter([a-zA-Z0-9\\.\\_]+)(:delimiter.*)*$#", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 145, _4$$3, _3$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, _2$$3, PH_SEPARATE, "phalcon/cli/router.zep", 99);
	}
	zephir_update_property_this(getThis(), SL("_routes"), routes TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Cli_Router, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Cli_Router, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets the name of the default module
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultModule) {

	zval *moduleName_param = NULL;
	zval *moduleName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	zephir_get_strval(moduleName, moduleName_param);


	zephir_update_property_this(getThis(), SL("_defaultModule"), moduleName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the default controller name
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultTask) {

	zval *taskName_param = NULL;
	zval *taskName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskName_param);

	zephir_get_strval(taskName, taskName_param);


	zephir_update_property_this(getThis(), SL("_defaultTask"), taskName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the default action name
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultAction) {

	zval *actionName_param = NULL;
	zval *actionName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

	zephir_get_strval(actionName, actionName_param);


	zephir_update_property_this(getThis(), SL("_defaultAction"), actionName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets an array of default paths. If a route is missing a path the router will use the defined here
 * This method must not be used to set a 404 route
 *
 *<code>
 * $router->setDefaults(
 *     [
 *         "module" => "common",
 *         "action" => "index",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaults) {

	zval *defaults_param = NULL, *module = NULL, *task = NULL, *action = NULL, *params = NULL;
	zval *defaults = NULL;

	zephir_fetch_params(0, 1, 0, &defaults_param);

	defaults = defaults_param;


	if (zephir_array_isset_string_fetch(&module, defaults, SS("module"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_defaultModule"), module TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&task, defaults, SS("task"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_defaultTask"), task TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&action, defaults, SS("action"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_defaultAction"), action TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&params, defaults, SS("params"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_defaultParams"), params TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Handles routing information received from command-line arguments
 *
 * @param array arguments
 */
PHP_METHOD(Phalcon_Cli_Router, handle) {

	zval *_17$$30 = NULL;
	zval *_5$$9 = NULL, *_10$$16 = NULL, *_12$$19 = NULL;
	HashTable *_3$$3, *_7$$12;
	HashPosition _2$$3, _6$$12;
	zend_bool _0$$3;
	zephir_fcall_cache_entry *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, *moduleName = NULL, *taskName = NULL, *actionName = NULL, *params = NULL, *route = NULL, *parts = NULL, *pattern = NULL, *routeFound = NULL, *matches = NULL, *paths = NULL, *beforeMatch = NULL, *converters = NULL, *converter = NULL, *part = NULL, *position = NULL, *matchPosition = NULL, *strParams = NULL, *_1$$3, **_4$$3, **_8$$12, *_9$$16 = NULL, *_11$$19 = NULL, *_13$$21, *_14$$21, *_15$$21, *_16$$21, _18$$30, *_19$$31 = NULL, *_21$$33;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(routeFound);
	ZVAL_BOOL(routeFound, 0);
	ZEPHIR_INIT_VAR(parts);
	array_init(parts);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);
	if (0) {
		zephir_update_property_this(getThis(), SL("_wasMatched"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_wasMatched"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	zephir_update_property_this(getThis(), SL("_matchedRoute"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		_0$$3 = Z_TYPE_P(arguments) != IS_STRING;
		if (_0$$3) {
			_0$$3 = Z_TYPE_P(arguments) != IS_NULL;
		}
		if (_0$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_router_exception_ce, "Arguments must be an array or string", "phalcon/cli/router.zep", 207);
			return;
		}
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
		zephir_is_iterable(_1$$3, &_3$$3, &_2$$3, 0, 1, "phalcon/cli/router.zep", 307);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_backwards_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HVALUE(route, _4$$3);
			ZEPHIR_CALL_METHOD(&pattern, route, "getcompiledpattern", NULL, 0);
			zephir_check_call_status();
			if (zephir_memnstr_str(pattern, SL("^"), "phalcon/cli/router.zep", 217)) {
				ZEPHIR_INIT_NVAR(routeFound);
				zephir_preg_match(routeFound, pattern, arguments, matches, 0, 0 , 0  TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(routeFound);
				ZVAL_BOOL(routeFound, ZEPHIR_IS_EQUAL(pattern, arguments));
			}
			if (zephir_is_true(routeFound)) {
				ZEPHIR_CALL_METHOD(&beforeMatch, route, "getbeforematch", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(beforeMatch) != IS_NULL) {
					if (!(zephir_is_callable(beforeMatch TSRMLS_CC))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/cli/router.zep", 235);
						return;
					}
					ZEPHIR_INIT_NVAR(_5$$9);
					zephir_create_array(_5$$9, 3, 0 TSRMLS_CC);
					zephir_array_fast_append(_5$$9, arguments);
					zephir_array_fast_append(_5$$9, route);
					zephir_array_fast_append(_5$$9, this_ptr);
					ZEPHIR_INIT_NVAR(routeFound);
					ZEPHIR_CALL_USER_FUNC_ARRAY(routeFound, beforeMatch, _5$$9);
					zephir_check_call_status();
				}
			}
			if (zephir_is_true(routeFound)) {
				ZEPHIR_CALL_METHOD(&paths, route, "getpaths", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(parts, paths);
				if (Z_TYPE_P(matches) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(&converters, route, "getconverters", NULL, 0);
					zephir_check_call_status();
					zephir_is_iterable(paths, &_7$$12, &_6$$12, 0, 0, "phalcon/cli/router.zep", 296);
					for (
					  ; zend_hash_get_current_data_ex(_7$$12, (void**) &_8$$12, &_6$$12) == SUCCESS
					  ; zend_hash_move_forward_ex(_7$$12, &_6$$12)
					) {
						ZEPHIR_GET_HMKEY(part, _7$$12, _6$$12);
						ZEPHIR_GET_HVALUE(position, _8$$12);
						ZEPHIR_OBS_NVAR(matchPosition);
						if (zephir_array_isset_fetch(&matchPosition, matches, position, 0 TSRMLS_CC)) {
							if (Z_TYPE_P(converters) == IS_ARRAY) {
								ZEPHIR_OBS_NVAR(converter);
								if (zephir_array_isset_fetch(&converter, converters, part, 0 TSRMLS_CC)) {
									ZEPHIR_INIT_NVAR(_9$$16);
									ZEPHIR_INIT_NVAR(_10$$16);
									zephir_create_array(_10$$16, 1, 0 TSRMLS_CC);
									zephir_array_fast_append(_10$$16, matchPosition);
									ZEPHIR_CALL_USER_FUNC_ARRAY(_9$$16, converter, _10$$16);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, part, &_9$$16, PH_COPY | PH_SEPARATE);
									continue;
								}
							}
							zephir_array_update_zval(&parts, part, &matchPosition, PH_COPY | PH_SEPARATE);
						} else {
							if (Z_TYPE_P(converters) == IS_ARRAY) {
								ZEPHIR_OBS_NVAR(converter);
								if (zephir_array_isset_fetch(&converter, converters, part, 0 TSRMLS_CC)) {
									ZEPHIR_INIT_NVAR(_11$$19);
									ZEPHIR_INIT_NVAR(_12$$19);
									zephir_create_array(_12$$19, 1, 0 TSRMLS_CC);
									zephir_array_fast_append(_12$$19, position);
									ZEPHIR_CALL_USER_FUNC_ARRAY(_11$$19, converter, _12$$19);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, part, &_11$$19, PH_COPY | PH_SEPARATE);
								}
							}
						}
					}
					zephir_update_property_this(getThis(), SL("_matches"), matches TSRMLS_CC);
				}
				zephir_update_property_this(getThis(), SL("_matchedRoute"), route TSRMLS_CC);
				break;
			}
		}
		if (zephir_is_true(routeFound)) {
			if (1) {
				zephir_update_property_this(getThis(), SL("_wasMatched"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_this(getThis(), SL("_wasMatched"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
		} else {
			if (0) {
				zephir_update_property_this(getThis(), SL("_wasMatched"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_this(getThis(), SL("_wasMatched"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
			_13$$21 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultModule"), PH_NOISY_CC);
			zephir_update_property_this(getThis(), SL("_module"), _13$$21 TSRMLS_CC);
			_14$$21 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultTask"), PH_NOISY_CC);
			zephir_update_property_this(getThis(), SL("_task"), _14$$21 TSRMLS_CC);
			_15$$21 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			zephir_update_property_this(getThis(), SL("_action"), _15$$21 TSRMLS_CC);
			_16$$21 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultParams"), PH_NOISY_CC);
			zephir_update_property_this(getThis(), SL("_params"), _16$$21 TSRMLS_CC);
			RETURN_THIS();
		}
	} else {
		ZEPHIR_CPY_WRT(parts, arguments);
	}
	ZEPHIR_INIT_VAR(moduleName);
	ZVAL_NULL(moduleName);
	ZEPHIR_INIT_VAR(taskName);
	ZVAL_NULL(taskName);
	ZEPHIR_INIT_VAR(actionName);
	ZVAL_NULL(actionName);
	ZEPHIR_OBS_NVAR(moduleName);
	if (zephir_array_isset_string_fetch(&moduleName, parts, SS("module"), 0 TSRMLS_CC)) {
		zephir_array_unset_string(&parts, SS("module"), PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(moduleName);
		zephir_read_property_this(&moduleName, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(taskName);
	if (zephir_array_isset_string_fetch(&taskName, parts, SS("task"), 0 TSRMLS_CC)) {
		zephir_array_unset_string(&parts, SS("task"), PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(taskName);
		zephir_read_property_this(&taskName, this_ptr, SL("_defaultTask"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(actionName);
	if (zephir_array_isset_string_fetch(&actionName, parts, SS("action"), 0 TSRMLS_CC)) {
		zephir_array_unset_string(&parts, SS("action"), PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(actionName);
		zephir_read_property_this(&actionName, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(params);
	if (zephir_array_isset_string_fetch(&params, parts, SS("params"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(params) != IS_ARRAY) {
			zephir_get_strval(_17$$30, params);
			ZEPHIR_SINIT_VAR(_18$$30);
			ZVAL_LONG(&_18$$30, 1);
			ZEPHIR_INIT_VAR(strParams);
			zephir_substr(strParams, _17$$30, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			if (zephir_is_true(strParams)) {
				ZEPHIR_CALL_CE_STATIC(&_19$$31, phalcon_cli_router_route_ce, "getdelimiter", &_20, 144);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(params);
				zephir_fast_explode(params, _19$$31, strParams, LONG_MAX TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(params);
				array_init(params);
			}
		}
		zephir_array_unset_string(&parts, SS("params"), PH_SEPARATE);
	}
	if (zephir_fast_count_int(params TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_21$$33);
		zephir_fast_array_merge(_21$$33, &(params), &(parts) TSRMLS_CC);
		ZEPHIR_CPY_WRT(params, _21$$33);
	} else {
		ZEPHIR_CPY_WRT(params, parts);
	}
	zephir_update_property_this(getThis(), SL("_module"), moduleName TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_task"), taskName TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_action"), actionName TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_params"), params TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a route to the router
 *
 *<code>
 * $router->add("/about", "About::main");
 *</code>
 *
 * @param string pattern
 * @param string/array paths
 * @return \Phalcon\Cli\Router\Route
 */
PHP_METHOD(Phalcon_Cli_Router, add) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *route = NULL;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(route);
	object_init_ex(route, phalcon_cli_router_route_ce);
	ZEPHIR_CALL_METHOD(NULL, route, "__construct", NULL, 145, pattern, paths);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_routes"), route TSRMLS_CC);
	RETURN_CCTOR(route);

}

/**
 * Returns processed module name
 */
PHP_METHOD(Phalcon_Cli_Router, getModuleName) {

	

	RETURN_MEMBER(getThis(), "_module");

}

/**
 * Returns processed task name
 */
PHP_METHOD(Phalcon_Cli_Router, getTaskName) {

	

	RETURN_MEMBER(getThis(), "_task");

}

/**
 * Returns processed action name
 */
PHP_METHOD(Phalcon_Cli_Router, getActionName) {

	

	RETURN_MEMBER(getThis(), "_action");

}

/**
 * Returns processed extra params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Cli_Router, getParams) {

	

	RETURN_MEMBER(getThis(), "_params");

}

/**
 * Returns the route that matches the handled URI
 */
PHP_METHOD(Phalcon_Cli_Router, getMatchedRoute) {

	

	RETURN_MEMBER(getThis(), "_matchedRoute");

}

/**
 * Returns the sub expressions in the regular expression matched
 *
 * @return array
 */
PHP_METHOD(Phalcon_Cli_Router, getMatches) {

	

	RETURN_MEMBER(getThis(), "_matches");

}

/**
 * Checks if the router matches any of the defined routes
 */
PHP_METHOD(Phalcon_Cli_Router, wasMatched) {

	

	RETURN_MEMBER(getThis(), "_wasMatched");

}

/**
 * Returns all the routes defined in the router
 */
PHP_METHOD(Phalcon_Cli_Router, getRoutes) {

	

	RETURN_MEMBER(getThis(), "_routes");

}

/**
 * Returns a route object by its id
 *
 * @param int id
 * @return \Phalcon\Cli\Router\Route
 */
PHP_METHOD(Phalcon_Cli_Router, getRouteById) {

	HashTable *_2;
	HashPosition _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, *route = NULL, *_0, **_3, *_4$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/cli/router.zep", 485);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(route, _3);
		ZEPHIR_CALL_METHOD(&_4$$3, route, "getrouteid", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(_4$$3, id)) {
			RETURN_CCTOR(route);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns a route object by its name
 */
PHP_METHOD(Phalcon_Cli_Router, getRouteByName) {

	HashTable *_2;
	HashPosition _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *route = NULL, *_0, **_3, *_4$$3 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/cli/router.zep", 500);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(route, _3);
		ZEPHIR_CALL_METHOD(&_4$$3, route, "getname", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(_4$$3, name)) {
			RETURN_CCTOR(route);
		}
	}
	RETURN_MM_BOOL(0);

}

zend_object_value zephir_init_properties_Phalcon_Cli_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_1$$3, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultParams"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_defaultParams"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("_params"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

