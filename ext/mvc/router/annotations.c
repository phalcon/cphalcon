
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Mvc\Router\Annotations
 *
 * A router that reads routes annotations from classes/resources
 *
 *<code>
 * $di['router'] = function() {
 *
 *		//Use the annotations router
 *		$router = new \Phalcon\Mvc\Router\Annotations();
 *
 *		//This will do the same as above but only if the handled uri starts with /robots
 * 		$router->addResource('Robots', '/robots');
 *
 * 		return $router;
 *	};
 *</code>
 */


/**
 * Phalcon\Mvc\Router\Annotations initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Router_Annotations){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Router, Annotations, mvc_router_annotations, "phalcon\\mvc\\router", phalcon_mvc_router_annotations_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("_handlers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_router_annotations_ce, SL("_processed"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("_controllerSufix"), "Controller", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("_actionSufix"), "Action", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("_routePrefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Adds a resource to the annotations handler
 * A resource is a class that contains routing annotations
 *
 * @param string $handler
 * @param string $prefix
 * @return Phalcon\Mvc\Router\Annotations
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addResource){

	zval *handler, *prefix = NULL, *scope;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &handler, &prefix) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!prefix) {
		PHALCON_INIT_VAR(prefix);
	}
	
	if (Z_TYPE_P(handler) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "The handler must be a class name");
		return;
	}
	
	PHALCON_INIT_VAR(scope);
	array_init_size(scope, 2);
	phalcon_array_append(&scope, prefix, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&scope, handler, PH_SEPARATE TSRMLS_CC);
	phalcon_update_property_array_append(this_ptr, SL("_handlers"), scope TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_processed"), 0 TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Produce the routing parameters from the rewrite information
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, handle){

	zval *uri = NULL, *real_uri = NULL, *processed, *annotations_service = NULL;
	zval *handlers, *controller_sufix, *scope = NULL, *prefix = NULL;
	zval *dependency_injector = NULL, *service = NULL, *handler = NULL;
	zval *sufixed = NULL, *handler_annotations = NULL, *class_annotations = NULL;
	zval *annotations = NULL, *annotation = NULL, *method_annotations = NULL;
	zval *lowercased = NULL, *collection = NULL, *method = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3;
	HashPosition hp0, hp1, hp2, hp3;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &uri) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!uri) {
		PHALCON_INIT_VAR(uri);
	}
	
	if (!zend_is_true(uri)) {
		/** 
		 * If 'uri' isn't passed as parameter it reads $_GET['_url']
		 */
		PHALCON_INIT_VAR(real_uri);
		PHALCON_CALL_METHOD(real_uri, this_ptr, "_getrewriteuri");
	} else {
		PHALCON_CPY_WRT(real_uri, uri);
	}
	
	PHALCON_OBS_VAR(processed);
	phalcon_read_property(&processed, this_ptr, SL("_processed"), PH_NOISY_CC);
	if (!zend_is_true(processed)) {
	
		PHALCON_INIT_VAR(annotations_service);
	
		PHALCON_OBS_VAR(handlers);
		phalcon_read_property(&handlers, this_ptr, SL("_handlers"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(controller_sufix);
		phalcon_read_property(&controller_sufix, this_ptr, SL("_controllerSufix"), PH_NOISY_CC);
	
		if (!phalcon_is_iterable(handlers, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(scope);
	
			if (Z_TYPE_P(scope) == IS_ARRAY) { 
	
				/** 
				 * A prefix (if any) must be in position 0
				 */
				PHALCON_OBS_NVAR(prefix);
				phalcon_array_fetch_long(&prefix, scope, 0, PH_NOISY_CC);
				if (Z_TYPE_P(prefix) == IS_STRING) {
					if (!phalcon_start_with(real_uri, prefix, NULL)) {
						zend_hash_move_forward_ex(ah0, &hp0);
						continue;
					}
				}
	
				if (Z_TYPE_P(annotations_service) != IS_OBJECT) {
	
					PHALCON_OBS_NVAR(dependency_injector);
					phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
						PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'annotations' service");
						return;
					}
	
					PHALCON_INIT_NVAR(service);
					ZVAL_STRING(service, "annotations", 1);
	
					PHALCON_INIT_NVAR(annotations_service);
					PHALCON_CALL_METHOD_PARAMS_1(annotations_service, dependency_injector, "getshared", service);
				}
	
				/** 
				 * The controller must be in position 1
				 */
				PHALCON_OBS_NVAR(handler);
				phalcon_array_fetch_long(&handler, scope, 1, PH_NOISY_CC);
				phalcon_update_property_null(this_ptr, SL("_routePrefix") TSRMLS_CC);
	
				PHALCON_INIT_NVAR(sufixed);
				PHALCON_CONCAT_VV(sufixed, handler, controller_sufix);
	
				PHALCON_INIT_NVAR(handler_annotations);
				PHALCON_CALL_METHOD_PARAMS_1(handler_annotations, annotations_service, "get", sufixed);
	
				/** 
				 * Process class annotations
				 */
				PHALCON_INIT_NVAR(class_annotations);
				PHALCON_CALL_METHOD(class_annotations, handler_annotations, "getclassannotations");
				if (Z_TYPE_P(class_annotations) == IS_OBJECT) {
	
					PHALCON_INIT_NVAR(annotations);
					PHALCON_CALL_METHOD(annotations, class_annotations, "getannotations");
					if (Z_TYPE_P(annotations) == IS_ARRAY) { 
	
						if (!phalcon_is_iterable(annotations, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
							return;
						}
	
						while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
							PHALCON_GET_FOREACH_VALUE(annotation);
	
							PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "processcontrollerannotation", handler, annotation);
	
							zend_hash_move_forward_ex(ah1, &hp1);
						}
	
					}
				}
	
				/** 
				 * Process method annotations
				 */
				PHALCON_INIT_NVAR(method_annotations);
				PHALCON_CALL_METHOD(method_annotations, handler_annotations, "getmethodsannotations");
				if (Z_TYPE_P(method_annotations) == IS_ARRAY) { 
	
					PHALCON_INIT_NVAR(lowercased);
					phalcon_fast_strtolower(lowercased, handler);
	
					if (!phalcon_is_iterable(method_annotations, &ah2, &hp2, 0, 0 TSRMLS_CC)) {
						return;
					}
	
					while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
						PHALCON_GET_FOREACH_KEY(method, ah2, hp2);
						PHALCON_GET_FOREACH_VALUE(collection);
	
						if (Z_TYPE_P(collection) == IS_OBJECT) {
	
							PHALCON_INIT_NVAR(annotations);
							PHALCON_CALL_METHOD(annotations, collection, "getannotations");
	
							if (!phalcon_is_iterable(annotations, &ah3, &hp3, 0, 0 TSRMLS_CC)) {
								return;
							}
	
							while (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) == SUCCESS) {
	
								PHALCON_GET_FOREACH_VALUE(annotation);
	
								PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "processactionannotation", lowercased, method, annotation);
	
								zend_hash_move_forward_ex(ah3, &hp3);
							}
	
						}
	
						zend_hash_move_forward_ex(ah2, &hp2);
					}
	
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		phalcon_update_property_bool(this_ptr, SL("_processed"), 1 TSRMLS_CC);
	}
	
	/** 
	 * Call the parent handle method()
	 */
	PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon\\Mvc\\Router\\Annotations", "handle", real_uri);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks for annotations in the controller docblock
 *
 * @param string $handler
 * @param Phalcon\Annotations\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processControllerAnnotation){

	zval *handler, *annotation, *lowercased, *name;
	zval *position, *value;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &handler, &annotation) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(lowercased);
	phalcon_fast_strtolower(lowercased, handler);
	
	PHALCON_INIT_VAR(name);
	PHALCON_CALL_METHOD(name, annotation, "getname");
	
	/** 
	 * @RoutePrefix add a prefix for all the routes defined in the model
	 */
	if (PHALCON_IS_STRING(name, "RoutePrefix")) {
		PHALCON_INIT_VAR(position);
		ZVAL_LONG(position, 0);
	
		PHALCON_INIT_VAR(value);
		PHALCON_CALL_METHOD_PARAMS_1(value, annotation, "getargument", position);
		phalcon_update_property_zval(this_ptr, SL("_routePrefix"), value TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks for annotations in the public methods of the controller
 *
 * @param string $controller
 * @param string $action
 * @param Phalcon\Annotations\Annotation $annotation
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processActionAnnotation){

	zval *controller, *action, *annotation, *is_route = NULL;
	zval *methods = NULL, *name, *action_sufix, *empty_str;
	zval *real_action_name, *action_name, *route_prefix;
	zval *parameter = NULL, *paths = NULL, *position, *value, *uri = NULL, *route;
	zval *converts, *convert = NULL, *param = NULL, *route_name;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &controller, &action, &annotation) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(is_route);
	ZVAL_BOOL(is_route, 0);
	
	PHALCON_INIT_VAR(methods);
	
	PHALCON_INIT_VAR(name);
	PHALCON_CALL_METHOD(name, annotation, "getname");
	
	/** 
	 * Find if the route is for adding routes
	 */
	if (PHALCON_IS_STRING(name, "Route")) {
		ZVAL_BOOL(is_route, 1);
	} else {
		if (PHALCON_IS_STRING(name, "Get")) {
			ZVAL_BOOL(is_route, 1);
	
			ZVAL_STRING(methods, "GET", 1);
		} else {
			if (PHALCON_IS_STRING(name, "Post")) {
				ZVAL_BOOL(is_route, 1);
	
				PHALCON_INIT_NVAR(methods);
				ZVAL_STRING(methods, "POST", 1);
			} else {
				if (PHALCON_IS_STRING(name, "Put")) {
					ZVAL_BOOL(is_route, 1);
	
					PHALCON_INIT_NVAR(methods);
					ZVAL_STRING(methods, "PUT", 1);
				} else {
					if (PHALCON_IS_STRING(name, "Options")) {
						ZVAL_BOOL(is_route, 1);
	
						PHALCON_INIT_NVAR(methods);
						ZVAL_STRING(methods, "OPTIONS", 1);
					}
				}
			}
		}
	}
	
	if (PHALCON_IS_TRUE(is_route)) {
	
		PHALCON_OBS_VAR(action_sufix);
		phalcon_read_property(&action_sufix, this_ptr, SL("_actionSufix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(empty_str);
		ZVAL_STRING(empty_str, "", 1);
	
		PHALCON_INIT_VAR(real_action_name);
		phalcon_fast_str_replace(real_action_name, action_sufix, empty_str, action TSRMLS_CC);
	
		PHALCON_INIT_VAR(action_name);
		phalcon_fast_strtolower(action_name, real_action_name);
	
		PHALCON_OBS_VAR(route_prefix);
		phalcon_read_property(&route_prefix, this_ptr, SL("_routePrefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(parameter);
		ZVAL_STRING(parameter, "paths", 1);
	
		/** 
		 * Check for existing paths in the annotation
		 */
		PHALCON_INIT_VAR(paths);
		PHALCON_CALL_METHOD_PARAMS_1(paths, annotation, "getnamedparameter", parameter);
		if (Z_TYPE_P(paths) != IS_ARRAY) { 
			PHALCON_INIT_NVAR(paths);
			array_init(paths);
		}
	
		phalcon_array_update_string(&paths, SL("controller"), &controller, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&paths, SL("action"), &action_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		PHALCON_INIT_VAR(position);
		ZVAL_LONG(position, 0);
	
		PHALCON_INIT_VAR(value);
		PHALCON_CALL_METHOD_PARAMS_1(value, annotation, "getargument", position);
	
		/** 
		 * Create the route using the prefix
		 */
		if (Z_TYPE_P(value) != IS_NULL) {
			if (!PHALCON_IS_STRING(value, "/")) {
				PHALCON_INIT_VAR(uri);
				PHALCON_CONCAT_VV(uri, route_prefix, value);
			} else {
				PHALCON_CPY_WRT(uri, route_prefix);
			}
		} else {
			PHALCON_INIT_NVAR(uri);
			PHALCON_CONCAT_VV(uri, route_prefix, action_name);
		}
	
		/** 
		 * Add the route to the router
		 */
		PHALCON_INIT_VAR(route);
		PHALCON_CALL_METHOD_PARAMS_2(route, this_ptr, "add", uri, paths);
		if (Z_TYPE_P(methods) == IS_NULL) {
	
			PHALCON_INIT_NVAR(parameter);
			ZVAL_STRING(parameter, "methods", 1);
	
			PHALCON_INIT_NVAR(methods);
			PHALCON_CALL_METHOD_PARAMS_1(methods, annotation, "getnamedparameter", parameter);
			if (Z_TYPE_P(methods) == IS_ARRAY) { 
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(route, "via", methods);
			} else {
				if (Z_TYPE_P(methods) == IS_STRING) {
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(route, "via", methods);
				}
			}
		} else {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(route, "via", methods);
		}
	
		PHALCON_INIT_NVAR(parameter);
		ZVAL_STRING(parameter, "converts", 1);
	
		PHALCON_INIT_VAR(converts);
		PHALCON_CALL_METHOD_PARAMS_1(converts, annotation, "getnamedparameter", parameter);
		if (Z_TYPE_P(converts) == IS_ARRAY) { 
	
			if (!phalcon_is_iterable(converts, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_KEY(param, ah0, hp0);
				PHALCON_GET_FOREACH_VALUE(convert);
	
				PHALCON_CALL_METHOD_PARAMS_2_NORETURN(route, "convert", param, convert);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	
		PHALCON_INIT_NVAR(parameter);
		ZVAL_STRING(parameter, "name", 1);
	
		PHALCON_INIT_VAR(route_name);
		PHALCON_CALL_METHOD_PARAMS_1(route_name, annotation, "getnamedparameter", parameter);
		if (Z_TYPE_P(route_name) == IS_STRING) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(route, "setname", route_name);
		}
	
		RETURN_MM_TRUE;
	}
	
	PHALCON_MM_RESTORE();
}

