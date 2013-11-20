
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/hash.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\Router\Annotations
 *
 * A router that reads routes annotations from classes/resources
 *
 *<code>
 * $di['router'] = function() {
 *
 *		//Use the annotations router
 *		$router = new \Phalcon\Mvc\Router\Annotations(false);
 *
 *		//This will do the same as above but only if the handled uri starts with /robots
 * 		$router->addResource('Robots', '/robots');
 *
 * 		return $router;
 *	};
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Annotations) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Router, Annotations, phalcon, mvc_router_annotations, phalcon_mvc_router_ce, phalcon_mvc_router_annotations_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("_handlers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_router_annotations_ce, SL("_processed"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("_controllerSuffix"), "Controller", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("_actionSuffix"), "Action", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("_routePrefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Adds a resource to the annotations handler
 * A resource is a class that contains routing annotations
 *
 * @param string handler
 * @param string prefix
 * @return Phalcon\Mvc\Router\Annotations
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addResource) {

	zval *handler_param = NULL, *prefix_param = NULL, *_0;
	zval *handler = NULL, *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &handler_param, &prefix_param);

		if (Z_TYPE_P(handler_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		handler = handler_param;

	if (!prefix_param || Z_TYPE_P(prefix_param) == IS_NULL) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_array_fast_append(_0, prefix);
	zephir_array_fast_append(_0, handler);
	zephir_update_property_array_append(this_ptr, SL("_handlers"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_processed"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a resource to the annotations handler
 * A resource is a class that contains routing annotations
 * The class is located in a module
 *
 * @param string module
 * @param string handler
 * @param string prefix
 * @return Phalcon\Mvc\Router\Annotations
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addModuleResource) {

	zval *module_param = NULL, *handler_param = NULL, *prefix_param = NULL, *_0;
	zval *module = NULL, *handler = NULL, *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &module_param, &handler_param, &prefix_param);

		if (Z_TYPE_P(module_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'module' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		module = module_param;

		if (Z_TYPE_P(handler_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		handler = handler_param;

	if (!prefix_param || Z_TYPE_P(prefix_param) == IS_NULL) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_array_fast_append(_0, prefix);
	zephir_array_fast_append(_0, handler);
	zephir_array_fast_append(_0, module);
	zephir_update_property_array_append(this_ptr, SL("_handlers"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_processed"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Produce the routing parameters from the rewrite information
 *
 * @param string uri
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, handle) {

	zend_function *_6 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_14 = NULL, *_15 = NULL, *_19 = NULL, *_23 = NULL;
	HashTable *_2, *_12, *_17, *_21;
	HashPosition _1, _11, _16, _20;
	zval *uri_param = NULL, *realUri = NULL, *annotationsService = NULL, *handlers, *controllerSuffix, *scope = NULL, *prefix, *dependencyInjector = NULL, *handler, *controllerName = NULL, *lowerControllerName = NULL, *namespaceName = NULL, *moduleName = NULL, *sufixed = NULL, *handlerAnnotations = NULL, *classAnnotations = NULL, *annotations = NULL, *annotation = NULL, *methodAnnotations = NULL, *lowercased = NULL, *method = NULL, *collection = NULL, *_0, **_3, *_4, *_5 = NULL, *_7 = NULL, **_13, **_18, **_22;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param || Z_TYPE_P(uri_param) == IS_NULL) {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	} else {
		zephir_get_strval(uri, uri_param);
	}


	if (!(uri && Z_STRLEN_P(uri))) {
		ZEPHIR_INIT_VAR(realUri);
		zephir_call_method(realUri, this_ptr, "getrewriteuri");
	} else {
		ZEPHIR_CPY_WRT(realUri, uri);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_processed"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(annotationsService);
		ZVAL_NULL(annotationsService);
		handlers = zephir_fetch_nproperty_this(this_ptr, SL("_handlers"), PH_NOISY_CC);
		if ((Z_TYPE_P(handlers) == IS_ARRAY)) {
			controllerSuffix = zephir_fetch_nproperty_this(this_ptr, SL("_controllerSuffix"), PH_NOISY_CC);
			zephir_is_iterable(handlers, &_2, &_1, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
				; zend_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HVALUE(scope, _3);
				if ((Z_TYPE_P(scope) == IS_ARRAY)) {
					zephir_array_fetch_long(&prefix, scope, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					if ((Z_TYPE_P(prefix) == IS_STRING)) {
						if (zephir_start_with(realUri, prefix, 0)) {
							continue;
						}
					}
					if ((Z_TYPE_P(annotationsService) == IS_OBJECT)) {
						_4 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
						ZEPHIR_CPY_WRT(dependencyInjector, _4);
						if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
							ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'annotations' service");
							return;
						}
						ZEPHIR_INIT_NVAR(_5);
						ZVAL_STRING(_5, "annotations", 1);
						ZEPHIR_INIT_NVAR(annotationsService);
						zephir_call_method_p1_cache(annotationsService, dependencyInjector, "getshared", &_6, _5);
					}
					zephir_array_fetch_long(&handler, scope, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_INIT_NVAR(lowerControllerName);
					ZEPHIR_INIT_NVAR(namespaceName);
					ZEPHIR_INIT_NVAR(_5);
					ZVAL_STRING(_5, "\\", 1);
					ZEPHIR_INIT_NVAR(_7);
					zephir_call_func_p2(_7, "memnstr", handler, _5);
					if (zephir_is_true(_7)) {
						ZEPHIR_INIT_NVAR(controllerName);
						zephir_call_func_p1(controllerName, "get_class_ns", handler);
						zephir_call_func_p1(lowerControllerName, "phalcon_uncamelize", controllerName);
						zephir_call_func_p1(namespaceName, "get_ns_class", handler);
					} else {
						ZEPHIR_CPY_WRT(controllerName, handler);
						zephir_call_func_p1(lowerControllerName, "phalcon_uncamelize", controllerName);
						ZVAL_NULL(namespaceName);
					}
					zephir_update_property_this(this_ptr, SL("_routePrefix"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
					ZEPHIR_OBS_NVAR(moduleName);
					if (!(zephir_array_isset_long_fetch(&moduleName, scope, 2, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(moduleName);
						ZVAL_NULL(moduleName);
					}
					ZEPHIR_INIT_NVAR(sufixed);
					ZEPHIR_CONCAT_VV(sufixed, handler, controllerSuffix);
					ZEPHIR_INIT_NVAR(handlerAnnotations);
					zephir_call_method_p1_cache(handlerAnnotations, annotationsService, "get", &_8, sufixed);
					ZEPHIR_INIT_NVAR(classAnnotations);
					zephir_call_method_cache(classAnnotations, handlerAnnotations, "getclassannotations", &_9);
					if ((Z_TYPE_P(classAnnotations) == IS_OBJECT)) {
						ZEPHIR_INIT_NVAR(annotations);
						zephir_call_method_cache(annotations, classAnnotations, "getannotations", &_10);
						if ((Z_TYPE_P(annotations) == IS_ARRAY)) {
							zephir_is_iterable(annotations, &_12, &_11, 0, 0);
							for (
								; zend_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
								; zend_hash_move_forward_ex(_12, &_11)
							) {
								ZEPHIR_GET_HVALUE(annotation, _13);
								zephir_call_method_p2_cache_noret(this_ptr, "processcontrollerannotation", &_14, controllerName, annotation);
							}
						}
					}
					ZEPHIR_INIT_NVAR(methodAnnotations);
					zephir_call_method_cache(methodAnnotations, handlerAnnotations, "getmethodsannotations", &_15);
					if ((Z_TYPE_P(methodAnnotations) == IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(lowercased);
						zephir_call_func_p1(lowercased, "phalcon_uncamelize", handler);
						zephir_is_iterable(methodAnnotations, &_17, &_16, 0, 0);
						for (
							; zend_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
							; zend_hash_move_forward_ex(_17, &_16)
						) {
							ZEPHIR_GET_HMKEY(method, _17, _16);
							ZEPHIR_GET_HVALUE(collection, _18);
							if ((Z_TYPE_P(collection) == IS_OBJECT)) {
								ZEPHIR_INIT_NVAR(_5);
								zephir_call_method_cache(_5, collection, "getannotations", &_19);
								zephir_is_iterable(_5, &_21, &_20, 0, 0);
								for (
									; zend_hash_get_current_data_ex(_21, (void**) &_22, &_20) == SUCCESS
									; zend_hash_move_forward_ex(_21, &_20)
								) {
									ZEPHIR_GET_HVALUE(annotation, _22);
									zephir_call_method_p5_cache_noret(this_ptr, "processactionannotation", &_23, moduleName, namespaceName, lowerControllerName, method, annotation);
								}
							}
						}
					}
				}
			}
		}
		zephir_update_property_this(this_ptr, SL("_processed"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	zephir_call_parent_p1_noret(this_ptr, phalcon_mvc_router_annotations_ce, "handle", realUri);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks for annotations in the controller docblock
 *
 * @param string handler
 * @param Phalcon\Annotations\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processControllerAnnotation) {

	zval *handler_param = NULL, *annotation, *_0, *_1, *_2;
	zval *handler = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &handler_param, &annotation);

		if (Z_TYPE_P(handler_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		handler = handler_param;



	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, annotation, "getname");
	if (ZEPHIR_IS_STRING(_0, "RoutePrefix")) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 0);
		zephir_call_method_p1(_1, annotation, "getargument", _2);
		zephir_update_property_this(this_ptr, SL("_routePrefix"), _1 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks for annotations in the public methods of the controller
 *
 * @param string module
 * @param string namespaceName
 * @param string controller
 * @param string action
 * @param Phalcon\Annotations\Annotation annotation
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processActionAnnotation) {

	zend_function *_7 = NULL, *_11 = NULL;
	HashTable *_5, *_9;
	HashPosition _4, _8;
	zend_bool isRoute;
	zval *module_param = NULL, *namespaceName_param = NULL, *controller_param = NULL, *action_param = NULL, *annotation, *name, *actionName, *routePrefix, *paths = NULL, *value, *uri = NULL, *route, *methods, *converts = NULL, *param = NULL, *convert = NULL, *conversorParam = NULL, *routeName, *_0, _1, *_2, *_3 = NULL, **_6, **_10;
	zval *module = NULL, *namespaceName = NULL, *controller = NULL, *action = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &module_param, &namespaceName_param, &controller_param, &action_param, &annotation);

		if (Z_TYPE_P(module_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'module' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		module = module_param;

		if (Z_TYPE_P(namespaceName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'namespaceName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		namespaceName = namespaceName_param;

		if (Z_TYPE_P(controller_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controller' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		controller = controller_param;

		if (Z_TYPE_P(action_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'action' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		action = action_param;



	isRoute = 0;
	ZEPHIR_INIT_VAR(methods);
	ZVAL_NULL(methods);
	ZEPHIR_INIT_VAR(name);
	zephir_call_method(name, annotation, "getname");
	if (ZEPHIR_IS_STRING(name, "Route")) {
		isRoute = 1;
	} else {
		if (ZEPHIR_IS_STRING(name, "Get")) {
			isRoute = 1;
			ZEPHIR_INIT_BNVAR(methods);
			ZVAL_STRING(methods, "GET", 1);
		} else {
			if (ZEPHIR_IS_STRING(name, "Post")) {
				isRoute = 1;
				ZEPHIR_INIT_BNVAR(methods);
				ZVAL_STRING(methods, "POST", 1);
			} else {
				if (ZEPHIR_IS_STRING(name, "Put")) {
					isRoute = 1;
					ZEPHIR_INIT_BNVAR(methods);
					ZVAL_STRING(methods, "PUT", 1);
				} else {
					if (ZEPHIR_IS_STRING(name, "Options")) {
						isRoute = 1;
						ZEPHIR_INIT_BNVAR(methods);
						ZVAL_STRING(methods, "OPTIONS", 1);
					}
				}
			}
		}
	}
	if ((isRoute == 1)) {
		ZEPHIR_INIT_VAR(actionName);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "", 0);
		ZEPHIR_INIT_VAR(_2);
		zephir_call_func_p3(_2, "str_replace", _0, &_1, action);
		zephir_fast_strtolower(actionName, _2);
		routePrefix = zephir_fetch_nproperty_this(this_ptr, SL("_routePrefix"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "paths", 1);
		ZEPHIR_INIT_VAR(paths);
		zephir_call_method_p1(paths, annotation, "getnamedargument", _3);
		if ((Z_TYPE_P(paths) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(paths);
			array_init(paths);
		}
		if (!((0 == 0))) {
			zephir_array_update_string(&paths, SL("module"), &module, PH_COPY | PH_SEPARATE);
		}
		if (!((0 == 0))) {
			zephir_array_update_string(&paths, SL("namespace"), &namespaceName, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&paths, SL("controller"), &controller, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&paths, SL("action"), &actionName, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_INIT_VAR(value);
		zephir_call_method_p1(value, annotation, "getargument", _3);
		if (((0 == 1) != 0)) {
			if (!ZEPHIR_IS_STRING(value, "/")) {
				ZEPHIR_INIT_VAR(uri);
				ZEPHIR_CONCAT_VV(uri, routePrefix, value);
			} else {
				ZEPHIR_CPY_WRT(uri, routePrefix);
			}
		} else {
			ZEPHIR_INIT_NVAR(uri);
			ZEPHIR_CONCAT_VV(uri, routePrefix, actionName);
		}
		ZEPHIR_INIT_VAR(route);
		zephir_call_method_p2(route, this_ptr, "add", uri, paths);
		if ((Z_TYPE_P(methods) != IS_NULL)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "methods", 1);
			ZEPHIR_INIT_BNVAR(methods);
			zephir_call_method_p1(methods, annotation, "getnamedargument", _3);
			if ((Z_TYPE_P(methods) == IS_ARRAY)) {
				zephir_call_method_p1_noret(route, "via", methods);
			} else {
				if ((Z_TYPE_P(methods) == IS_STRING)) {
					zephir_call_method_p1_noret(route, "via", methods);
				}
			}
		} else {
			zephir_call_method_p1_noret(route, "via", methods);
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "converts", 1);
		ZEPHIR_INIT_VAR(converts);
		zephir_call_method_p1(converts, annotation, "getnamedargument", _3);
		if ((Z_TYPE_P(converts) != IS_ARRAY)) {
			zephir_is_iterable(converts, &_5, &_4, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
				; zend_hash_move_forward_ex(_5, &_4)
			) {
				ZEPHIR_GET_HMKEY(param, _5, _4);
				ZEPHIR_GET_HVALUE(convert, _6);
				zephir_call_method_p2_cache_noret(route, "convert", &_7, param, convert);
			}
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "conversors", 1);
		ZEPHIR_INIT_NVAR(converts);
		zephir_call_method_p1(converts, annotation, "getnamedargument", _3);
		if ((Z_TYPE_P(converts) != IS_ARRAY)) {
			zephir_is_iterable(converts, &_9, &_8, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
				; zend_hash_move_forward_ex(_9, &_8)
			) {
				ZEPHIR_GET_HMKEY(conversorParam, _9, _8);
				ZEPHIR_GET_HVALUE(convert, _10);
				zephir_call_method_p2_cache_noret(route, "convert", &_11, conversorParam, convert);
			}
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "name", 1);
		ZEPHIR_INIT_VAR(routeName);
		zephir_call_method_p1(routeName, annotation, "getnamedargument", _3);
		if ((Z_TYPE_P(routeName) == IS_STRING)) {
			zephir_call_method_p1_noret(route, "setname", routeName);
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Changes the controller class suffix
 *
 * @param string controllerSuffix
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setControllerSuffix) {

	zval *controllerSuffix_param = NULL;
	zval *controllerSuffix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerSuffix_param);

		if (Z_TYPE_P(controllerSuffix_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerSuffix' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		controllerSuffix = controllerSuffix_param;



	zephir_update_property_this(this_ptr, SL("_controllerSuffix"), controllerSuffix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Changes the action method suffix
 *
 * @param string actionSuffix
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setActionSuffix) {

	zval *actionSuffix_param = NULL;
	zval *actionSuffix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionSuffix_param);

		if (Z_TYPE_P(actionSuffix_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionSuffix' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		actionSuffix = actionSuffix_param;



	zephir_update_property_this(this_ptr, SL("_actionSuffix"), actionSuffix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the registered resources
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, getResources) {


	RETURN_MEMBER(this_ptr, "_handlers");

}

