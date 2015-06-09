
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
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Mvc\Router\Annotations
 *
 * A router that reads routes annotations from classes/resources
 *
 *<code>
 * $di['router'] = function() {
 *
 *		//Use the annotations router
 *		$router = new Annotations(false);
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
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addResource) {

	zval *_0;
	zval *handler_param = NULL, *prefix_param = NULL;
	zval *handler = NULL, *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &handler_param, &prefix_param);

	if (unlikely(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(handler_param) == IS_STRING)) {
		zephir_get_strval(handler, handler_param);
	} else {
		ZEPHIR_INIT_VAR(handler);
		ZVAL_EMPTY_STRING(handler);
	}
	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	} else {
	if (unlikely(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
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
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addModuleResource) {

	zval *_0;
	zval *module_param = NULL, *handler_param = NULL, *prefix_param = NULL;
	zval *module = NULL, *handler = NULL, *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &module_param, &handler_param, &prefix_param);

	if (unlikely(Z_TYPE_P(module_param) != IS_STRING && Z_TYPE_P(module_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'module' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(module_param) == IS_STRING)) {
		zephir_get_strval(module, module_param);
	} else {
		ZEPHIR_INIT_VAR(module);
		ZVAL_EMPTY_STRING(module);
	}
	if (unlikely(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(handler_param) == IS_STRING)) {
		zephir_get_strval(handler, handler_param);
	} else {
		ZEPHIR_INIT_VAR(handler);
		ZVAL_EMPTY_STRING(handler);
	}
	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	} else {
	if (unlikely(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, prefix);
	zephir_array_fast_append(_0, handler);
	zephir_array_fast_append(_0, module);
	zephir_update_property_array_append(this_ptr, SL("_handlers"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_processed"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Produce the routing parameters from the rewrite information
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, handle) {

	zephir_fcall_cache_entry *_9 = NULL, *_17 = NULL, *_18 = NULL;
	HashTable *_2, *_7, *_11, *_15;
	HashPosition _1, _6, _10, _14;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *realUri = NULL, *annotationsService = NULL, *handlers, *controllerSuffix, *scope = NULL, *prefix = NULL, *dependencyInjector = NULL, *handler = NULL, *controllerName = NULL, *lowerControllerName = NULL, *namespaceName = NULL, *moduleName = NULL, *sufixed = NULL, *handlerAnnotations = NULL, *classAnnotations = NULL, *annotations = NULL, *annotation = NULL, *methodAnnotations = NULL, *lowercased = NULL, *method = NULL, *collection = NULL, *_0, **_3, *_4, *_5 = NULL, **_8, **_12, *_13 = NULL, **_16;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	} else {
	if (unlikely(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	}
	}


	if (!(uri && Z_STRLEN_P(uri))) {
		ZEPHIR_CALL_METHOD(&realUri, this_ptr, "getrewriteuri", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(realUri, uri);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_processed"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(annotationsService);
		ZVAL_NULL(annotationsService);
		ZEPHIR_OBS_VAR(handlers);
		zephir_read_property_this(&handlers, this_ptr, SL("_handlers"), PH_NOISY_CC);
		if (Z_TYPE_P(handlers) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(controllerSuffix);
			zephir_read_property_this(&controllerSuffix, this_ptr, SL("_controllerSuffix"), PH_NOISY_CC);
			zephir_is_iterable(handlers, &_2, &_1, 0, 0, "phalcon/mvc/router/annotations.zep", 208);
			for (
			  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HVALUE(scope, _3);
				if (Z_TYPE_P(scope) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(prefix);
					zephir_array_fetch_long(&prefix, scope, 0, PH_NOISY, "phalcon/mvc/router/annotations.zep", 117 TSRMLS_CC);
					if (!(ZEPHIR_IS_EMPTY(prefix))) {
						if (!(zephir_start_with(realUri, prefix, NULL))) {
							continue;
						}
					}
					if (Z_TYPE_P(annotationsService) != IS_OBJECT) {
						_4 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
						ZEPHIR_CPY_WRT(dependencyInjector, _4);
						if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'annotations' service", "phalcon/mvc/router/annotations.zep", 129);
							return;
						}
						ZEPHIR_INIT_NVAR(_5);
						ZVAL_STRING(_5, "annotations", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(&annotationsService, dependencyInjector, "getshared", NULL, 0, _5);
						zephir_check_temp_parameter(_5);
						zephir_check_call_status();
					}
					ZEPHIR_OBS_NVAR(handler);
					zephir_array_fetch_long(&handler, scope, 1, PH_NOISY, "phalcon/mvc/router/annotations.zep", 138 TSRMLS_CC);
					if (zephir_memnstr_str(handler, SL("\\"), "phalcon/mvc/router/annotations.zep", 140)) {
						ZEPHIR_INIT_NVAR(controllerName);
						zephir_get_class_ns(controllerName, handler, 0 TSRMLS_CC);
						ZEPHIR_INIT_NVAR(lowerControllerName);
						zephir_uncamelize(lowerControllerName, controllerName);
						ZEPHIR_INIT_NVAR(namespaceName);
						zephir_get_ns_class(namespaceName, handler, 0 TSRMLS_CC);
					} else {
						ZEPHIR_CPY_WRT(controllerName, handler);
						ZEPHIR_INIT_NVAR(lowerControllerName);
						zephir_uncamelize(lowerControllerName, controllerName);
						ZEPHIR_INIT_NVAR(namespaceName);
						ZVAL_NULL(namespaceName);
					}
					zephir_update_property_this(this_ptr, SL("_routePrefix"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
					ZEPHIR_OBS_NVAR(moduleName);
					zephir_array_isset_long_fetch(&moduleName, scope, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(sufixed);
					ZEPHIR_CONCAT_VV(sufixed, handler, controllerSuffix);
					ZEPHIR_CALL_METHOD(&handlerAnnotations, annotationsService, "get", NULL, 0, sufixed);
					zephir_check_call_status();
					if (Z_TYPE_P(handlerAnnotations) == IS_OBJECT) {
						ZEPHIR_CALL_METHOD(&classAnnotations, handlerAnnotations, "getclassannotations", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(classAnnotations) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD(&annotations, classAnnotations, "getannotations", NULL, 0);
							zephir_check_call_status();
							if (Z_TYPE_P(annotations) == IS_ARRAY) {
								zephir_is_iterable(annotations, &_7, &_6, 0, 0, "phalcon/mvc/router/annotations.zep", 187);
								for (
								  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
								  ; zephir_hash_move_forward_ex(_7, &_6)
								) {
									ZEPHIR_GET_HVALUE(annotation, _8);
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_9, 0, controllerName, annotation);
									zephir_check_call_status();
								}
							}
						}
						ZEPHIR_CALL_METHOD(&methodAnnotations, handlerAnnotations, "getmethodsannotations", NULL, 0);
						zephir_check_call_status();
						if (Z_TYPE_P(methodAnnotations) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(lowercased);
							zephir_uncamelize(lowercased, handler);
							zephir_is_iterable(methodAnnotations, &_11, &_10, 0, 0, "phalcon/mvc/router/annotations.zep", 203);
							for (
							  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
							  ; zephir_hash_move_forward_ex(_11, &_10)
							) {
								ZEPHIR_GET_HMKEY(method, _11, _10);
								ZEPHIR_GET_HVALUE(collection, _12);
								if (Z_TYPE_P(collection) == IS_OBJECT) {
									ZEPHIR_CALL_METHOD(&_13, collection, "getannotations", NULL, 0);
									zephir_check_call_status();
									zephir_is_iterable(_13, &_15, &_14, 0, 0, "phalcon/mvc/router/annotations.zep", 201);
									for (
									  ; zephir_hash_get_current_data_ex(_15, (void**) &_16, &_14) == SUCCESS
									  ; zephir_hash_move_forward_ex(_15, &_14)
									) {
										ZEPHIR_GET_HVALUE(annotation, _16);
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_17, 0, moduleName, namespaceName, lowerControllerName, method, annotation);
										zephir_check_call_status();
									}
								}
							}
						}
					}
				}
			}
		}
		zephir_update_property_this(this_ptr, SL("_processed"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_router_annotations_ce, this_ptr, "handle", &_18, 356, realUri);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks for annotations in the controller docblock
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processControllerAnnotation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *handler_param = NULL, *annotation, *_0 = NULL, *_1 = NULL, *_2;
	zval *handler = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &handler_param, &annotation);

	if (unlikely(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(handler_param) == IS_STRING)) {
		zephir_get_strval(handler, handler_param);
	} else {
		ZEPHIR_INIT_VAR(handler);
		ZVAL_EMPTY_STRING(handler);
	}


	ZEPHIR_CALL_METHOD(&_0, annotation, "getname", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(_0, "RoutePrefix")) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_CALL_METHOD(&_1, annotation, "getargument", NULL, 0, _2);
		zephir_check_call_status();
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

	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL;
	HashTable *_5, *_9;
	HashPosition _4, _8;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool isRoute;
	zval *module_param = NULL, *namespaceName_param = NULL, *controller_param = NULL, *action_param = NULL, *annotation, *name = NULL, *actionName, *routePrefix, *paths = NULL, *value = NULL, *uri = NULL, *route = NULL, *methods = NULL, *converts = NULL, *param = NULL, *convert = NULL, *conversorParam = NULL, *routeName = NULL, *_0, *_1, _2, *_3 = NULL, **_6, **_10;
	zval *module = NULL, *namespaceName = NULL, *controller = NULL, *action = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &module_param, &namespaceName_param, &controller_param, &action_param, &annotation);

	if (unlikely(Z_TYPE_P(module_param) != IS_STRING && Z_TYPE_P(module_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'module' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(module_param) == IS_STRING)) {
		zephir_get_strval(module, module_param);
	} else {
		ZEPHIR_INIT_VAR(module);
		ZVAL_EMPTY_STRING(module);
	}
	if (unlikely(Z_TYPE_P(namespaceName_param) != IS_STRING && Z_TYPE_P(namespaceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'namespaceName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(namespaceName_param) == IS_STRING)) {
		zephir_get_strval(namespaceName, namespaceName_param);
	} else {
		ZEPHIR_INIT_VAR(namespaceName);
		ZVAL_EMPTY_STRING(namespaceName);
	}
	if (unlikely(Z_TYPE_P(controller_param) != IS_STRING && Z_TYPE_P(controller_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controller' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(controller_param) == IS_STRING)) {
		zephir_get_strval(controller, controller_param);
	} else {
		ZEPHIR_INIT_VAR(controller);
		ZVAL_EMPTY_STRING(controller);
	}
	if (unlikely(Z_TYPE_P(action_param) != IS_STRING && Z_TYPE_P(action_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'action' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(action_param) == IS_STRING)) {
		zephir_get_strval(action, action_param);
	} else {
		ZEPHIR_INIT_VAR(action);
		ZVAL_EMPTY_STRING(action);
	}


	isRoute = 0;
	ZEPHIR_INIT_VAR(methods);
	ZVAL_NULL(methods);
	ZEPHIR_CALL_METHOD(&name, annotation, "getname", NULL, 0);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_STRING(name, "Route")) {
			isRoute = 1;
			break;
		}
		if (ZEPHIR_IS_STRING(name, "Get")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(methods);
			ZVAL_STRING(methods, "GET", 1);
			break;
		}
		if (ZEPHIR_IS_STRING(name, "Post")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(methods);
			ZVAL_STRING(methods, "POST", 1);
			break;
		}
		if (ZEPHIR_IS_STRING(name, "Put")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(methods);
			ZVAL_STRING(methods, "PUT", 1);
			break;
		}
		if (ZEPHIR_IS_STRING(name, "Delete")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(methods);
			ZVAL_STRING(methods, "DELETE", 1);
			break;
		}
		if (ZEPHIR_IS_STRING(name, "Options")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(methods);
			ZVAL_STRING(methods, "OPTIONS", 1);
			break;
		}
	} while(0);

	if (isRoute == 1) {
		ZEPHIR_INIT_VAR(_0);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "", 0);
		zephir_fast_str_replace(&_0, _1, &_2, action TSRMLS_CC);
		ZEPHIR_INIT_VAR(actionName);
		zephir_fast_strtolower(actionName, _0);
		ZEPHIR_OBS_VAR(routePrefix);
		zephir_read_property_this(&routePrefix, this_ptr, SL("_routePrefix"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "paths", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&paths, annotation, "getnamedargument", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (Z_TYPE_P(paths) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(paths);
			array_init(paths);
		}
		if (!(ZEPHIR_IS_EMPTY(module))) {
			zephir_array_update_string(&paths, SL("module"), &module, PH_COPY | PH_SEPARATE);
		}
		if (!(ZEPHIR_IS_EMPTY(namespaceName))) {
			zephir_array_update_string(&paths, SL("namespace"), &namespaceName, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&paths, SL("controller"), &controller, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&paths, SL("action"), &actionName, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_CALL_METHOD(&value, annotation, "getargument", NULL, 0, _3);
		zephir_check_call_status();
		if (Z_TYPE_P(value) != IS_NULL) {
			if (!ZEPHIR_IS_STRING(value, "/")) {
				ZEPHIR_INIT_VAR(uri);
				ZEPHIR_CONCAT_VV(uri, routePrefix, value);
			} else {
				if (Z_TYPE_P(routePrefix) != IS_NULL) {
					ZEPHIR_CPY_WRT(uri, routePrefix);
				} else {
					ZEPHIR_CPY_WRT(uri, value);
				}
			}
		} else {
			ZEPHIR_INIT_NVAR(uri);
			ZEPHIR_CONCAT_VV(uri, routePrefix, actionName);
		}
		ZEPHIR_CALL_METHOD(&route, this_ptr, "add", NULL, 0, uri, paths);
		zephir_check_call_status();
		if (Z_TYPE_P(methods) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, route, "via", NULL, 0, methods);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "methods", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&methods, annotation, "getnamedargument", NULL, 0, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			if (Z_TYPE_P(methods) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, route, "via", NULL, 0, methods);
				zephir_check_call_status();
			} else {
				if (Z_TYPE_P(methods) == IS_STRING) {
					ZEPHIR_CALL_METHOD(NULL, route, "via", NULL, 0, methods);
					zephir_check_call_status();
				}
			}
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "converts", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&converts, annotation, "getnamedargument", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (Z_TYPE_P(converts) == IS_ARRAY) {
			zephir_is_iterable(converts, &_5, &_4, 0, 0, "phalcon/mvc/router/annotations.zep", 359);
			for (
			  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_5, &_4)
			) {
				ZEPHIR_GET_HMKEY(param, _5, _4);
				ZEPHIR_GET_HVALUE(convert, _6);
				ZEPHIR_CALL_METHOD(NULL, route, "convert", &_7, 0, param, convert);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "conversors", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&converts, annotation, "getnamedargument", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (Z_TYPE_P(converts) == IS_ARRAY) {
			zephir_is_iterable(converts, &_9, &_8, 0, 0, "phalcon/mvc/router/annotations.zep", 369);
			for (
			  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
			  ; zephir_hash_move_forward_ex(_9, &_8)
			) {
				ZEPHIR_GET_HMKEY(conversorParam, _9, _8);
				ZEPHIR_GET_HVALUE(convert, _10);
				ZEPHIR_CALL_METHOD(NULL, route, "convert", &_11, 0, conversorParam, convert);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "name", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&routeName, annotation, "getnamedargument", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (Z_TYPE_P(routeName) == IS_STRING) {
			ZEPHIR_CALL_METHOD(NULL, route, "setname", NULL, 0, routeName);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Changes the controller class suffix
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setControllerSuffix) {

	zval *controllerSuffix_param = NULL;
	zval *controllerSuffix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerSuffix_param);

	if (unlikely(Z_TYPE_P(controllerSuffix_param) != IS_STRING && Z_TYPE_P(controllerSuffix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerSuffix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(controllerSuffix_param) == IS_STRING)) {
		zephir_get_strval(controllerSuffix, controllerSuffix_param);
	} else {
		ZEPHIR_INIT_VAR(controllerSuffix);
		ZVAL_EMPTY_STRING(controllerSuffix);
	}


	zephir_update_property_this(this_ptr, SL("_controllerSuffix"), controllerSuffix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Changes the action method suffix
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setActionSuffix) {

	zval *actionSuffix_param = NULL;
	zval *actionSuffix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionSuffix_param);

	if (unlikely(Z_TYPE_P(actionSuffix_param) != IS_STRING && Z_TYPE_P(actionSuffix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionSuffix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(actionSuffix_param) == IS_STRING)) {
		zephir_get_strval(actionSuffix, actionSuffix_param);
	} else {
		ZEPHIR_INIT_VAR(actionSuffix);
		ZVAL_EMPTY_STRING(actionSuffix);
	}


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

