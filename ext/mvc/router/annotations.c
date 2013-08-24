
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
#include "kernel/hash.h"
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
 *		$router = new \Phalcon\Mvc\Router\Annotations(false);
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

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Router, Annotations, mvc_router_annotations, phalcon_mvc_router_ce, phalcon_mvc_router_annotations_method_entry, 0);

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
 * @param string $handler
 * @param string $prefix
 * @return Phalcon\Mvc\Router\Annotations
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addResource){

	zval *handler, *prefix = NULL, *scope;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &handler, &prefix);
	
	if (!prefix) {
		PHALCON_INIT_VAR(prefix);
	}
	
	if (Z_TYPE_P(handler) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "The handler must be a class name");
		return;
	}
	
	PHALCON_INIT_VAR(scope);
	array_init_size(scope, 2);
	phalcon_array_append(&scope, prefix, PH_SEPARATE);
	phalcon_array_append(&scope, handler, PH_SEPARATE);
	phalcon_update_property_array_append(this_ptr, SL("_handlers"), scope TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_processed"), 0 TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Adds a resource to the annotations handler
 * A resource is a class that contains routing annotations
 * The class is located in a module
 *
 * @param string $module
 * @param string $handler
 * @param string $prefix
 * @return Phalcon\Mvc\Router\Annotations
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addModuleResource){

	zval *module, *handler, *prefix = NULL, *scope;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &module, &handler, &prefix);
	
	if (!prefix) {
		PHALCON_INIT_VAR(prefix);
	}
	
	if (Z_TYPE_P(module) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "The module is not a valid string");
		return;
	}
	if (Z_TYPE_P(handler) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "The handler must be a class name");
		return;
	}
	
	PHALCON_INIT_VAR(scope);
	array_init_size(scope, 3);
	phalcon_array_append(&scope, prefix, PH_SEPARATE);
	phalcon_array_append(&scope, handler, PH_SEPARATE);
	phalcon_array_append(&scope, module, PH_SEPARATE);
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
	zval *handlers, *controller_suffix, *scope = NULL, *prefix = NULL;
	zval *dependency_injector = NULL, *service = NULL, *handler = NULL;
	zval *controller_name = NULL;
	zval *namespace_name = NULL, *module_name = NULL, *suffixed = NULL;
	zval *handler_annotations = NULL, *class_annotations = NULL;
	zval *annotations = NULL, *annotation = NULL, *method_annotations = NULL;
	zval *collection = NULL, *method = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3;
	HashPosition hp0, hp1, hp2, hp3;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &uri);
	
	if (!uri) {
		PHALCON_INIT_VAR(uri);
	}
	
	if (!zend_is_true(uri)) {
		/** 
		 * If 'uri' isn't passed as parameter it reads $_GET['_url']
		 */
		PHALCON_INIT_VAR(real_uri);
		phalcon_call_method(real_uri, this_ptr, "getrewriteuri");
	} else {
		PHALCON_CPY_WRT(real_uri, uri);
	}
	
	PHALCON_OBS_VAR(processed);
	phalcon_read_property_this(&processed, this_ptr, SL("_processed"), PH_NOISY_CC);
	if (!zend_is_true(processed)) {
	
		PHALCON_INIT_VAR(annotations_service);
	
		PHALCON_OBS_VAR(handlers);
		phalcon_read_property_this(&handlers, this_ptr, SL("_handlers"), PH_NOISY_CC);
		if (Z_TYPE_P(handlers) == IS_ARRAY) { 
	
			PHALCON_OBS_VAR(controller_suffix);
			phalcon_read_property_this(&controller_suffix, this_ptr, SL("_controllerSuffix"), PH_NOISY_CC);
	
			phalcon_is_iterable(handlers, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HVALUE(scope);
	
				if (Z_TYPE_P(scope) == IS_ARRAY) { 
	
					/** 
					 * A prefix (if any) must be in position 0
					 */
					PHALCON_OBS_NVAR(prefix);
					phalcon_array_fetch_long(&prefix, scope, 0, PH_NOISY);
					if (Z_TYPE_P(prefix) == IS_STRING) {
						if (!phalcon_start_with(real_uri, prefix, NULL)) {
							zend_hash_move_forward_ex(ah0, &hp0);
							continue;
						}
					}
	
					if (Z_TYPE_P(annotations_service) != IS_OBJECT) {
	
						PHALCON_OBS_NVAR(dependency_injector);
						phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
						if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
							PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'annotations' service");
							return;
						}
	
						PHALCON_INIT_NVAR(service);
						ZVAL_STRING(service, "annotations", 1);
	
						PHALCON_INIT_NVAR(annotations_service);
						phalcon_call_method_p1(annotations_service, dependency_injector, "getshared", service);
						PHALCON_VERIFY_INTERFACE(annotations_service, phalcon_annotations_adapterinterface_ce);
					}
	
					/** 
					 * The controller must be in position 1
					 */
					PHALCON_OBS_NVAR(handler);
					phalcon_array_fetch_long(&handler, scope, 1, PH_NOISY);
					if (phalcon_memnstr_str(handler, SL("\\"))) {
						/** 
						 * Extract the real class name from the namespaced class
						 */
						PHALCON_INIT_NVAR(controller_name);
						phalcon_get_class_ns(controller_name, handler, 0 TSRMLS_CC);
	
						/** 
						 * Extract the namespace from the namespaced class
						 */
						PHALCON_INIT_NVAR(namespace_name);
						phalcon_get_ns_class(namespace_name, handler, 0 TSRMLS_CC);
					} else {
						PHALCON_CPY_WRT(controller_name, handler);
	
						PHALCON_INIT_NVAR(namespace_name);
					}
	
					phalcon_update_property_null(this_ptr, SL("_routePrefix") TSRMLS_CC);
	
					/** 
					 * Check if the scope has a module associated
					 */
					if (phalcon_array_isset_long(scope, 2)) {
						PHALCON_OBS_NVAR(module_name);
						phalcon_array_fetch_long(&module_name, scope, 2, PH_NOISY);
					} else {
						PHALCON_INIT_NVAR(module_name);
					}
	
					PHALCON_INIT_NVAR(suffixed);
					PHALCON_CONCAT_VV(suffixed, handler, controller_suffix);
	
					/** 
					 * Get the annotations from the class
					 */
					PHALCON_INIT_NVAR(handler_annotations);
					phalcon_call_method_p1(handler_annotations, annotations_service, "get", suffixed);
	
					/** 
					 * Process class annotations
					 */
					PHALCON_INIT_NVAR(class_annotations);
					phalcon_call_method(class_annotations, handler_annotations, "getclassannotations");
					if (Z_TYPE_P(class_annotations) == IS_OBJECT) {
	
						/** 
						 * Process class annotations
						 */
						PHALCON_INIT_NVAR(annotations);
						phalcon_call_method(annotations, class_annotations, "getannotations");
						if (Z_TYPE_P(annotations) == IS_ARRAY) { 
	
							phalcon_is_iterable(annotations, &ah1, &hp1, 0, 0);
	
							while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
								PHALCON_GET_HVALUE(annotation);
	
								phalcon_call_method_p2_noret(this_ptr, "processcontrollerannotation", controller_name, annotation);
	
								zend_hash_move_forward_ex(ah1, &hp1);
							}
	
						}
					}
	
					/** 
					 * Process method annotations
					 */
					PHALCON_INIT_NVAR(method_annotations);
					phalcon_call_method(method_annotations, handler_annotations, "getmethodsannotations");
					if (Z_TYPE_P(method_annotations) == IS_ARRAY) { 
	
						phalcon_is_iterable(method_annotations, &ah2, &hp2, 0, 0);
	
						while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
							PHALCON_GET_HKEY(method, ah2, hp2);
							PHALCON_GET_HVALUE(collection);
	
							if (Z_TYPE_P(collection) == IS_OBJECT) {
	
								PHALCON_INIT_NVAR(annotations);
								phalcon_call_method(annotations, collection, "getannotations");
	
								phalcon_is_iterable(annotations, &ah3, &hp3, 0, 0);
	
								while (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) == SUCCESS) {
	
									PHALCON_GET_HVALUE(annotation);
	
									phalcon_call_method_p5_noret(this_ptr, "processactionannotation", module_name, namespace_name, controller_name, method, annotation);
	
									zend_hash_move_forward_ex(ah3, &hp3);
								}
	
							}
	
							zend_hash_move_forward_ex(ah2, &hp2);
						}
	
					}
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	
		phalcon_update_property_bool(this_ptr, SL("_processed"), 1 TSRMLS_CC);
	}
	
	/** 
	 * Call the parent handle method()
	 */
	phalcon_call_parent_p1_noret(this_ptr, phalcon_mvc_router_annotations_ce, "handle", real_uri);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks for annotations in the controller docblock
 *
 * @param string $handler
 * @param Phalcon\Annotations\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processControllerAnnotation){

	zval *handler, *annotation, *name, *position, *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &handler, &annotation);
	
	PHALCON_INIT_VAR(name);
	phalcon_call_method(name, annotation, "getname");
	
	/** 
	 * @RoutePrefix add a prefix for all the routes defined in the model
	 */
	if (PHALCON_IS_STRING(name, "RoutePrefix")) {
		PHALCON_INIT_VAR(position);
		ZVAL_LONG(position, 0);
	
		PHALCON_INIT_VAR(value);
		phalcon_call_method_p1(value, annotation, "getargument", position);
		phalcon_update_property_this(this_ptr, SL("_routePrefix"), value TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks for annotations in the public methods of the controller
 *
 * @param string $module
 * @param string $namespace
 * @param string $controller
 * @param string $action
 * @param Phalcon\Annotations\Annotation $annotation
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processActionAnnotation){

	zval *module, *namespace, *controller, *action;
	zval *annotation, *methods = NULL, *name;
	zval *empty_str, *real_action_name, *action_name;
	zval *parameter = NULL, *paths = NULL, *position;
	zval *value, *uri = NULL, *route, *converts = NULL, *convert = NULL, *param = NULL;
	zval *conversor_param = NULL, *route_name;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int is_route = 1;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 5, 0, &module, &namespace, &controller, &action, &annotation);
	
	PHALCON_INIT_VAR(methods);
	
	PHALCON_INIT_VAR(name);
	phalcon_call_method(name, annotation, "getname");
	
	/** 
	 * Find if the route is for adding routes
	 */
	if (PHALCON_IS_STRING(name, "Route")) {
		is_route = 1;
	} else if (PHALCON_IS_STRING(name, "Get")) {
		is_route = 1;
		ZVAL_STRING(methods, "GET", 1);
	} else if (PHALCON_IS_STRING(name, "Post")) {
		is_route = 1;
		ZVAL_STRING(methods, "POST", 1);
	} else if (PHALCON_IS_STRING(name, "Put")) {
		is_route = 1;
		ZVAL_STRING(methods, "PUT", 1);
	} else if (PHALCON_IS_STRING(name, "Options")) {
		is_route = 1;
		ZVAL_STRING(methods, "OPTIONS", 1);
	}
	
	if (is_route) {
		zval *action_suffix, *route_prefix;

		action_suffix = phalcon_fetch_nproperty_this(this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
		route_prefix  = phalcon_fetch_nproperty_this(this_ptr, SL("_routePrefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(empty_str);
		ZVAL_EMPTY_STRING(empty_str);
	
		PHALCON_INIT_VAR(real_action_name);
		phalcon_fast_str_replace(real_action_name, action_suffix, empty_str, action);
	
		PHALCON_INIT_VAR(action_name);
		phalcon_fast_strtolower(action_name, real_action_name);
	
		PHALCON_INIT_VAR(parameter);
		ZVAL_STRING(parameter, "paths", 1);
	
		/** 
		 * Check for existing paths in the annotation
		 */
		PHALCON_INIT_VAR(paths);
		phalcon_call_method_p1(paths, annotation, "getnamedparameter", parameter);
		if (Z_TYPE_P(paths) != IS_ARRAY) { 
			PHALCON_INIT_NVAR(paths);
			array_init(paths);
		}
	
		/** 
		 * Update the module if any
		 */
		if (Z_TYPE_P(module) == IS_STRING) {
			phalcon_array_update_string(&paths, SL("module"), &module, PH_COPY | PH_SEPARATE);
		}
	
		/** 
		 * Update the namespace if any
		 */
		if (Z_TYPE_P(namespace) == IS_STRING) {
			phalcon_array_update_string(&paths, SL("namespace"), &namespace, PH_COPY | PH_SEPARATE);
		}
	
		phalcon_array_update_string(&paths, SL("controller"), &controller, PH_COPY | PH_SEPARATE);
		phalcon_array_update_string(&paths, SL("action"), &action_name, PH_COPY | PH_SEPARATE);
		add_assoc_bool_ex(paths, SS("exact"), 1);
	
		PHALCON_INIT_VAR(position);
		ZVAL_LONG(position, 0);
	
		PHALCON_INIT_VAR(value);
		phalcon_call_method_p1(value, annotation, "getargument", position);
	
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
		phalcon_call_method_p2(route, this_ptr, "add", uri, paths);
		if (Z_TYPE_P(methods) == IS_NULL) {
	
			PHALCON_INIT_NVAR(parameter);
			ZVAL_STRING(parameter, "methods", 1);
	
			PHALCON_INIT_NVAR(methods);
			phalcon_call_method_p1(methods, annotation, "getnamedparameter", parameter);
			if (Z_TYPE_P(methods) == IS_ARRAY) { 
				phalcon_call_method_p1_noret(route, "via", methods);
			} else {
				if (Z_TYPE_P(methods) == IS_STRING) {
					phalcon_call_method_p1_noret(route, "via", methods);
				}
			}
		} else {
			phalcon_call_method_p1_noret(route, "via", methods);
		}
	
		PHALCON_INIT_NVAR(parameter);
		ZVAL_STRING(parameter, "converts", 1);
	
		PHALCON_INIT_VAR(converts);
		phalcon_call_method_p1(converts, annotation, "getnamedparameter", parameter);
		if (Z_TYPE_P(converts) == IS_ARRAY) { 
	
			phalcon_is_iterable(converts, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HKEY(param, ah0, hp0);
				PHALCON_GET_HVALUE(convert);
	
				phalcon_call_method_p2_noret(route, "convert", param, convert);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	
		PHALCON_INIT_NVAR(parameter);
		ZVAL_STRING(parameter, "conversors", 1);
	
		PHALCON_INIT_NVAR(converts);
		phalcon_call_method_p1(converts, annotation, "getnamedparameter", parameter);
		if (Z_TYPE_P(converts) == IS_ARRAY) { 
	
			phalcon_is_iterable(converts, &ah1, &hp1, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
				PHALCON_GET_HKEY(conversor_param, ah1, hp1);
				PHALCON_GET_HVALUE(convert);
	
				phalcon_call_method_p2_noret(route, "convert", conversor_param, convert);
	
				zend_hash_move_forward_ex(ah1, &hp1);
			}
	
		}
	
		PHALCON_INIT_NVAR(parameter);
		ZVAL_STRING(parameter, "name", 1);
	
		PHALCON_INIT_VAR(route_name);
		phalcon_call_method_p1(route_name, annotation, "getnamedparameter", parameter);
		if (Z_TYPE_P(route_name) == IS_STRING) {
			phalcon_call_method_p1_noret(route, "setname", route_name);
		}
	
		RETURN_MM_TRUE;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Changes the controller class suffix
 *
 * @param string $controllerSuffix
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setControllerSuffix){

	zval *controller_suffix;

	phalcon_fetch_params(0, 1, 0, &controller_suffix);
	
	phalcon_update_property_this(this_ptr, SL("_controllerSuffix"), controller_suffix TSRMLS_CC);
	
}

/**
 * Changes the action method suffix
 *
 * @param string $actionSuffix
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setActionSuffix){

	zval *action_suffix;

	phalcon_fetch_params(0, 1, 0, &action_suffix);
	
	phalcon_update_property_this(this_ptr, SL("_actionSuffix"), action_suffix TSRMLS_CC);
	
}

/**
 * Return the registered resources
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, getResources){


	RETURN_MEMBER(this_ptr, "_handlers");
}

