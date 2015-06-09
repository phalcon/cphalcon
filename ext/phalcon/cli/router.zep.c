
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
#include "kernel/hash.h"
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
 *	$router = new \Phalcon\Cli\Router();
 *	$router->handle(array(
 *		'module' => 'main',
 *		'task' => 'videos',
 *		'action' => 'process'
 *	));
 *	echo $router->getTaskName();
 *</code>
 *
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

	zend_class_implements(phalcon_cli_router_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cli\Router constructor
 */
PHP_METHOD(Phalcon_Cli_Router, __construct) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1, *_4;
	zval *defaultRoutes_param = NULL, *routes, *_0 = NULL, *_2 = NULL, *_5;
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
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_cli_router_route_ce);
		ZEPHIR_INIT_VAR(_1);
		zephir_create_array(_1, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(_1, SS("task"), 1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+)[:delimiter]{0,1}$#", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_3, 56, _2, _1);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_append(&routes, _0, PH_SEPARATE, "phalcon/cli/router.zep", 90);
		ZEPHIR_INIT_NVAR(_2);
		object_init_ex(_2, phalcon_cli_router_route_ce);
		ZEPHIR_INIT_VAR(_4);
		zephir_create_array(_4, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(_4, SS("task"), 1);
		add_assoc_long_ex(_4, SS("action"), 2);
		add_assoc_long_ex(_4, SS("params"), 3);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+):delimiter([a-zA-Z0-9\\.\\_]+)(:delimiter.*)*$#", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_3, 56, _5, _4);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		zephir_array_append(&routes, _2, PH_SEPARATE, "phalcon/cli/router.zep", 96);
	}
	ZEPHIR_INIT_NVAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_params"), _0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("_defaultParams"), _2 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_routes"), routes TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Cli_Router, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Cli_Router, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

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


	zephir_update_property_this(this_ptr, SL("_defaultModule"), moduleName TSRMLS_CC);
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


	zephir_update_property_this(this_ptr, SL("_defaultTask"), taskName TSRMLS_CC);
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


	zephir_update_property_this(this_ptr, SL("_defaultAction"), actionName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets an array of default paths. If a route is missing a path the router will use the defined here
 * This method must not be used to set a 404 route
 *
 *<code>
 * $router->setDefaults(array(
 *		'module' => 'common',
 *		'action' => 'index'
 * ));
 *</code>
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaults) {

	zval *defaults_param = NULL, *module, *task, *action, *params;
	zval *defaults = NULL;

	zephir_fetch_params(0, 1, 0, &defaults_param);

	defaults = defaults_param;



	if (zephir_array_isset_string_fetch(&module, defaults, SS("module"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultModule"), module TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&task, defaults, SS("task"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultTask"), task TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&action, defaults, SS("action"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultAction"), action TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&params, defaults, SS("params"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultParams"), params TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Handles routing information received from command-line arguments
 *
 * @param array arguments
 */
PHP_METHOD(Phalcon_Cli_Router, handle) {

	zephir_fcall_cache_entry *_18 = NULL;
	zval *_15 = NULL;
	zval *_5 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_3, *_7;
	HashPosition _2, _6;
	zend_bool _0;
	zval *arguments = NULL, *moduleName = NULL, *taskName = NULL, *actionName = NULL, *params = NULL, *route = NULL, *parts = NULL, *pattern = NULL, *routeFound = NULL, *matches, *paths = NULL, *beforeMatch = NULL, *converters = NULL, *converter = NULL, *part = NULL, *position = NULL, *matchPosition = NULL, *strParams, *_1, **_4, **_8, *_9 = NULL, *_11, *_12, *_13, *_14, _16, *_17 = NULL;

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
	zephir_update_property_this(this_ptr, SL("_wasMatched"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_matchedRoute"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		_0 = Z_TYPE_P(arguments) != IS_STRING;
		if (_0) {
			_0 = Z_TYPE_P(arguments) != IS_NULL;
		}
		if (_0) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_router_exception_ce, "Arguments must be an array or string", "phalcon/cli/router.zep", 204);
			return;
		}
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
		zephir_is_iterable(_1, &_3, &_2, 0, 1, "phalcon/cli/router.zep", 304);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_backwards_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(route, _4);
			ZEPHIR_CALL_METHOD(&pattern, route, "getcompiledpattern", NULL, 0);
			zephir_check_call_status();
			if (zephir_memnstr_str(pattern, SL("^"), "phalcon/cli/router.zep", 214)) {
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
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/cli/router.zep", 232);
						return;
					}
					ZEPHIR_INIT_NVAR(_5);
					zephir_create_array(_5, 3, 0 TSRMLS_CC);
					zephir_array_fast_append(_5, arguments);
					zephir_array_fast_append(_5, route);
					zephir_array_fast_append(_5, this_ptr);
					ZEPHIR_INIT_NVAR(routeFound);
					ZEPHIR_CALL_USER_FUNC_ARRAY(routeFound, beforeMatch, _5);
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
					zephir_is_iterable(paths, &_7, &_6, 0, 0, "phalcon/cli/router.zep", 293);
					for (
					  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
					  ; zephir_hash_move_forward_ex(_7, &_6)
					) {
						ZEPHIR_GET_HMKEY(part, _7, _6);
						ZEPHIR_GET_HVALUE(position, _8);
						ZEPHIR_OBS_NVAR(matchPosition);
						if (zephir_array_isset_fetch(&matchPosition, matches, position, 0 TSRMLS_CC)) {
							if (Z_TYPE_P(converters) == IS_ARRAY) {
								ZEPHIR_OBS_NVAR(converter);
								if (zephir_array_isset_fetch(&converter, converters, part, 0 TSRMLS_CC)) {
									ZEPHIR_INIT_NVAR(_9);
									ZEPHIR_INIT_NVAR(_5);
									zephir_create_array(_5, 1, 0 TSRMLS_CC);
									zephir_array_fast_append(_5, matchPosition);
									ZEPHIR_CALL_USER_FUNC_ARRAY(_9, converter, _5);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, part, &_9, PH_COPY | PH_SEPARATE);
									continue;
								}
							}
							zephir_array_update_zval(&parts, part, &matchPosition, PH_COPY | PH_SEPARATE);
						} else {
							if (Z_TYPE_P(converters) == IS_ARRAY) {
								ZEPHIR_OBS_NVAR(converter);
								if (zephir_array_isset_fetch(&converter, converters, part, 0 TSRMLS_CC)) {
									ZEPHIR_INIT_NVAR(_9);
									ZEPHIR_INIT_NVAR(_10);
									zephir_create_array(_10, 1, 0 TSRMLS_CC);
									zephir_array_fast_append(_10, position);
									ZEPHIR_CALL_USER_FUNC_ARRAY(_9, converter, _10);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, part, &_9, PH_COPY | PH_SEPARATE);
								}
							}
						}
					}
					zephir_update_property_this(this_ptr, SL("_matches"), matches TSRMLS_CC);
				}
				zephir_update_property_this(this_ptr, SL("_matchedRoute"), route TSRMLS_CC);
				break;
			}
		}
		if (zephir_is_true(routeFound)) {
			zephir_update_property_this(this_ptr, SL("_wasMatched"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_wasMatched"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultModule"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_module"), _11 TSRMLS_CC);
			_12 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultTask"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_task"), _12 TSRMLS_CC);
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_action"), _13 TSRMLS_CC);
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultParams"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_params"), _14 TSRMLS_CC);
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
	if (zephir_is_true(routeFound)) {
		ZEPHIR_OBS_NVAR(params);
		if (zephir_array_isset_string_fetch(&params, parts, SS("params"), 0 TSRMLS_CC)) {
			if (Z_TYPE_P(params) != IS_ARRAY) {
				zephir_get_strval(_15, params);
				ZEPHIR_SINIT_VAR(_16);
				ZVAL_LONG(&_16, 1);
				ZEPHIR_INIT_VAR(strParams);
				zephir_substr(strParams, _15, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				if (zephir_is_true(strParams)) {
					ZEPHIR_CALL_CE_STATIC(&_17, phalcon_cli_router_route_ce, "getdelimiter", &_18, 54);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(params);
					zephir_fast_explode(params, _17, strParams, LONG_MAX TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(params);
					array_init(params);
				}
			}
			zephir_array_unset_string(&parts, SS("params"), PH_SEPARATE);
		}
		if (zephir_fast_count_int(params TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_9);
			zephir_fast_array_merge(_9, &(params), &(parts) TSRMLS_CC);
			ZEPHIR_CPY_WRT(params, _9);
		} else {
			ZEPHIR_CPY_WRT(params, parts);
		}
	} else {
		ZEPHIR_CPY_WRT(params, parts);
	}
	zephir_update_property_this(this_ptr, SL("_module"), moduleName TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_task"), taskName TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_action"), actionName TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a route to the router
 *
 *<code>
 * $router->add('/about', 'About::main');
 *</code>
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Cli\Router\Route
 */
PHP_METHOD(Phalcon_Cli_Router, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *route;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
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
	ZEPHIR_CALL_METHOD(NULL, route, "__construct", NULL, 56, pattern, paths);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_routes"), route TSRMLS_CC);
	RETURN_CCTOR(route);

}

/**
 * Returns proccesed module name
 */
PHP_METHOD(Phalcon_Cli_Router, getModuleName) {


	RETURN_MEMBER(this_ptr, "_module");

}

/**
 * Returns proccesed task name
 */
PHP_METHOD(Phalcon_Cli_Router, getTaskName) {


	RETURN_MEMBER(this_ptr, "_task");

}

/**
 * Returns proccesed action name
 */
PHP_METHOD(Phalcon_Cli_Router, getActionName) {


	RETURN_MEMBER(this_ptr, "_action");

}

/**
 * Returns proccesed extra params
 *
 * @return array
 */
PHP_METHOD(Phalcon_Cli_Router, getParams) {


	RETURN_MEMBER(this_ptr, "_params");

}

/**
 * Returns the route that matchs the handled URI
 */
PHP_METHOD(Phalcon_Cli_Router, getMatchedRoute) {


	RETURN_MEMBER(this_ptr, "_matchedRoute");

}

/**
 * Returns the sub expressions in the regular expression matched
 *
 * @return array
 */
PHP_METHOD(Phalcon_Cli_Router, getMatches) {


	RETURN_MEMBER(this_ptr, "_matches");

}

/**
 * Checks if the router macthes any of the defined routes
 */
PHP_METHOD(Phalcon_Cli_Router, wasMatched) {


	RETURN_MEMBER(this_ptr, "_wasMatched");

}

/**
 * Returns all the routes defined in the router
 */
PHP_METHOD(Phalcon_Cli_Router, getRoutes) {


	RETURN_MEMBER(this_ptr, "_routes");

}

/**
 * Returns a route object by its id
 *
 * @param int id
 * @return Phalcon\Cli\Router\Route
 */
PHP_METHOD(Phalcon_Cli_Router, getRouteById) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *id, *route = NULL, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/cli/router.zep", 486);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(route, _3);
		ZEPHIR_CALL_METHOD(&_4, route, "getrouteid", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(_4, id)) {
			RETURN_CCTOR(route);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns a route object by its name
 */
PHP_METHOD(Phalcon_Cli_Router, getRouteByName) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *name_param = NULL, *route = NULL, *_0, **_3, *_4 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/cli/router.zep", 501);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(route, _3);
		ZEPHIR_CALL_METHOD(&_4, route, "getname", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(_4, name)) {
			RETURN_CCTOR(route);
		}
	}
	RETURN_MM_BOOL(0);

}

