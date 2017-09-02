
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


/**
 * Phalcon\Mvc\Router\Annotations
 *
 * A router that reads routes annotations from classes/resources
 *
 * <code>
 * use Phalcon\Mvc\Router\Annotations;
 *
 * $di->setShared(
 *     "router",
 *     function() {
 *         // Use the annotations router
 *         $router = new Annotations(false);
 *
 *         // This will do the same as above but only if the handled uri starts with /robots
 *         $router->addResource("Robots", "/robots");
 *
 *         return $router;
 *     }
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Annotations) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Router, Annotations, phalcon, mvc_router_annotations, phalcon_mvc_router_ce, phalcon_mvc_router_annotations_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("_handlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("_controllerSuffix"), "Controller", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("_actionSuffix"), "Action", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("_routePrefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_router_annotations_ce->create_object = zephir_init_properties_Phalcon_Mvc_Router_Annotations;
	return SUCCESS;

}

/**
 * Adds a resource to the annotations handler
 * A resource is a class that contains routing annotations
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addResource) {

	zval _0;
	zval *handler_param = NULL, *prefix_param = NULL;
	zval handler, prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &handler_param, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(handler_param) == IS_STRING)) {
		zephir_get_strval(&handler, handler_param);
	} else {
		ZEPHIR_INIT_VAR(&handler);
		ZVAL_EMPTY_STRING(&handler);
	}
	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_EMPTY_STRING(&prefix);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, &prefix);
	zephir_array_fast_append(&_0, &handler);
	zephir_update_property_array_append(this_ptr, SL("_handlers"), &_0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a resource to the annotations handler
 * A resource is a class that contains routing annotations
 * The class is located in a module
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addModuleResource) {

	zval _0;
	zval *module_param = NULL, *handler_param = NULL, *prefix_param = NULL;
	zval module, handler, prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &module_param, &handler_param, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(module_param) != IS_STRING && Z_TYPE_P(module_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'module' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(module_param) == IS_STRING)) {
		zephir_get_strval(&module, module_param);
	} else {
		ZEPHIR_INIT_VAR(&module);
		ZVAL_EMPTY_STRING(&module);
	}
	if (UNEXPECTED(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(handler_param) == IS_STRING)) {
		zephir_get_strval(&handler, handler_param);
	} else {
		ZEPHIR_INIT_VAR(&handler);
		ZVAL_EMPTY_STRING(&handler);
	}
	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_EMPTY_STRING(&prefix);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, &prefix);
	zephir_array_fast_append(&_0, &handler);
	zephir_array_fast_append(&_0, &module);
	zephir_update_property_array_append(this_ptr, SL("_handlers"), &_0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Produce the routing parameters from the rewrite information
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, handle) {

	zend_string *_10$$14;
	zend_ulong _9$$14;
	zend_bool _3$$4;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_13 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, __$null, annotationsService, handlers, controllerSuffix, scope, prefix, dependencyInjector, handler, controllerName, lowerControllerName, namespaceName, moduleName, sufixed, handlerAnnotations, classAnnotations, annotations, annotation, methodAnnotations, method, collection, _0, _1, *_2, _4$$9, *_6$$12, *_8$$14, _11$$16, *_12$$16;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&annotationsService);
	ZVAL_UNDEF(&handlers);
	ZVAL_UNDEF(&controllerSuffix);
	ZVAL_UNDEF(&scope);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&lowerControllerName);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&sufixed);
	ZVAL_UNDEF(&handlerAnnotations);
	ZVAL_UNDEF(&classAnnotations);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&annotation);
	ZVAL_UNDEF(&methodAnnotations);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_11$$16);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_EMPTY_STRING(&uri);
	}


	zephir_read_property(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'annotations' service", "phalcon/mvc/router/annotations.zep", 95);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "annotations");
	ZEPHIR_CALL_METHOD(&annotationsService, &dependencyInjector, "getshared", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&handlers);
	zephir_read_property(&handlers, this_ptr, SL("_handlers"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&controllerSuffix);
	zephir_read_property(&controllerSuffix, this_ptr, SL("_controllerSuffix"), PH_NOISY_CC);
	zephir_is_iterable(&handlers, 0, "phalcon/mvc/router/annotations.zep", 196);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handlers), _2)
	{
		ZEPHIR_INIT_NVAR(&scope);
		ZVAL_COPY(&scope, _2);
		if (Z_TYPE_P(&scope) != IS_ARRAY) {
			continue;
		}
		ZEPHIR_OBS_NVAR(&prefix);
		zephir_array_fetch_long(&prefix, &scope, 0, PH_NOISY, "phalcon/mvc/router/annotations.zep", 113 TSRMLS_CC);
		_3$$4 = !(ZEPHIR_IS_EMPTY(&prefix));
		if (_3$$4) {
			_3$$4 = !(zephir_start_with(&uri, &prefix, NULL));
		}
		if (_3$$4) {
			continue;
		}
		ZEPHIR_OBS_NVAR(&handler);
		zephir_array_fetch_long(&handler, &scope, 1, PH_NOISY, "phalcon/mvc/router/annotations.zep", 122 TSRMLS_CC);
		if (zephir_memnstr_str(&handler, SL("\\"), "phalcon/mvc/router/annotations.zep", 124)) {
			ZEPHIR_INIT_NVAR(&controllerName);
			zephir_get_class_ns(&controllerName, &handler, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&namespaceName);
			zephir_get_ns_class(&namespaceName, &handler, 0 TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(&controllerName, &handler);
			ZEPHIR_OBS_NVAR(&namespaceName);
			zephir_fetch_property(&namespaceName, this_ptr, SL("_defaultNamespace"), PH_SILENT_CC);
		}
		zephir_update_property_zval(this_ptr, SL("_routePrefix"), &__$null);
		ZEPHIR_OBS_NVAR(&moduleName);
		zephir_array_isset_long_fetch(&moduleName, &scope, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&sufixed);
		ZEPHIR_CONCAT_VV(&sufixed, &controllerName, &controllerSuffix);
		if (Z_TYPE_P(&namespaceName) != IS_NULL) {
			ZEPHIR_INIT_LNVAR(_4$$9);
			ZEPHIR_CONCAT_VSV(&_4$$9, &namespaceName, "\\", &sufixed);
			ZEPHIR_CPY_WRT(&sufixed, &_4$$9);
		}
		ZEPHIR_CALL_METHOD(&handlerAnnotations, &annotationsService, "get", &_5, 0, &sufixed);
		zephir_check_call_status();
		if (Z_TYPE_P(&handlerAnnotations) != IS_OBJECT) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&classAnnotations, &handlerAnnotations, "getclassannotations", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&classAnnotations) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&annotations, &classAnnotations, "getannotations", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&annotations) == IS_ARRAY) {
				zephir_is_iterable(&annotations, 0, "phalcon/mvc/router/annotations.zep", 173);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&annotations), _6$$12)
				{
					ZEPHIR_INIT_NVAR(&annotation);
					ZVAL_COPY(&annotation, _6$$12);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_7, 0, &controllerName, &annotation);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&annotation);
			}
		}
		ZEPHIR_CALL_METHOD(&methodAnnotations, &handlerAnnotations, "getmethodsannotations", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&lowerControllerName);
			zephir_uncamelize(&lowerControllerName, &controllerName, NULL  );
			zephir_is_iterable(&methodAnnotations, 0, "phalcon/mvc/router/annotations.zep", 190);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methodAnnotations), _9$$14, _10$$14, _8$$14)
			{
				ZEPHIR_INIT_NVAR(&method);
				if (_10$$14 != NULL) { 
					ZVAL_STR_COPY(&method, _10$$14);
				} else {
					ZVAL_LONG(&method, _9$$14);
				}
				ZEPHIR_INIT_NVAR(&collection);
				ZVAL_COPY(&collection, _8$$14);
				if (Z_TYPE_P(&collection) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_11$$16, &collection, "getannotations", NULL, 0);
					zephir_check_call_status();
					zephir_is_iterable(&_11$$16, 0, "phalcon/mvc/router/annotations.zep", 188);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_11$$16), _12$$16)
					{
						ZEPHIR_INIT_NVAR(&annotation);
						ZVAL_COPY(&annotation, _12$$16);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_13, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&annotation);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&collection);
			ZEPHIR_INIT_NVAR(&method);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&scope);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_router_annotations_ce, getThis(), "handle", &_14, 0, &uri);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks for annotations in the controller docblock
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processControllerAnnotation) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *handler_param = NULL, *annotation, annotation_sub, _0, _1$$3, _2$$3;
	zval handler;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&annotation_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &handler_param, &annotation);

	if (UNEXPECTED(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(handler_param) == IS_STRING)) {
		zephir_get_strval(&handler, handler_param);
	} else {
		ZEPHIR_INIT_VAR(&handler);
		ZVAL_EMPTY_STRING(&handler);
	}


	ZEPHIR_CALL_METHOD(&_0, annotation, "getname", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&_0, "RoutePrefix")) {
		ZVAL_LONG(&_2$$3, 0);
		ZEPHIR_CALL_METHOD(&_1$$3, annotation, "getargument", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_routePrefix"), &_1$$3);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks for annotations in the public methods of the controller
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processActionAnnotation) {

	zend_string *_9$$23, *_13$$25;
	zend_ulong _8$$23, _12$$25;
	zend_bool isRoute = 0, _15$$10, _6$$21;
	zephir_fcall_cache_entry *_10 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *module_param = NULL, *namespaceName_param = NULL, *controller_param = NULL, *action_param = NULL, *annotation, annotation_sub, name, actionName, routePrefix, paths, value, uri, route, methods, converts, param, convert, conversorParam, routeName, beforeMatch, _0$$10, _1$$10, _2$$10, _3$$10, _4$$10, _5$$21, *_7$$23, *_11$$25;
	zval module, namespaceName, controller, action;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&annotation_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&routePrefix);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&converts);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&convert);
	ZVAL_UNDEF(&conversorParam);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&_0$$10);
	ZVAL_UNDEF(&_1$$10);
	ZVAL_UNDEF(&_2$$10);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$21);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &module_param, &namespaceName_param, &controller_param, &action_param, &annotation);

	if (UNEXPECTED(Z_TYPE_P(module_param) != IS_STRING && Z_TYPE_P(module_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'module' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(module_param) == IS_STRING)) {
		zephir_get_strval(&module, module_param);
	} else {
		ZEPHIR_INIT_VAR(&module);
		ZVAL_EMPTY_STRING(&module);
	}
	if (UNEXPECTED(Z_TYPE_P(namespaceName_param) != IS_STRING && Z_TYPE_P(namespaceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'namespaceName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(namespaceName_param) == IS_STRING)) {
		zephir_get_strval(&namespaceName, namespaceName_param);
	} else {
		ZEPHIR_INIT_VAR(&namespaceName);
		ZVAL_EMPTY_STRING(&namespaceName);
	}
	if (UNEXPECTED(Z_TYPE_P(controller_param) != IS_STRING && Z_TYPE_P(controller_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controller' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controller_param) == IS_STRING)) {
		zephir_get_strval(&controller, controller_param);
	} else {
		ZEPHIR_INIT_VAR(&controller);
		ZVAL_EMPTY_STRING(&controller);
	}
	if (UNEXPECTED(Z_TYPE_P(action_param) != IS_STRING && Z_TYPE_P(action_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'action' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(action_param) == IS_STRING)) {
		zephir_get_strval(&action, action_param);
	} else {
		ZEPHIR_INIT_VAR(&action);
		ZVAL_EMPTY_STRING(&action);
	}


	isRoute = 0;
	ZEPHIR_INIT_VAR(&methods);
	ZVAL_NULL(&methods);
	ZEPHIR_CALL_METHOD(&name, annotation, "getname", NULL, 0);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_STRING(&name, "Route")) {
			isRoute = 1;
			break;
		}
		if (ZEPHIR_IS_STRING(&name, "Get")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(&methods);
			ZVAL_STRING(&methods, "GET");
			break;
		}
		if (ZEPHIR_IS_STRING(&name, "Post")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(&methods);
			ZVAL_STRING(&methods, "POST");
			break;
		}
		if (ZEPHIR_IS_STRING(&name, "Put")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(&methods);
			ZVAL_STRING(&methods, "PUT");
			break;
		}
		if (ZEPHIR_IS_STRING(&name, "Patch")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(&methods);
			ZVAL_STRING(&methods, "PATCH");
			break;
		}
		if (ZEPHIR_IS_STRING(&name, "Delete")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(&methods);
			ZVAL_STRING(&methods, "DELETE");
			break;
		}
		if (ZEPHIR_IS_STRING(&name, "Options")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(&methods);
			ZVAL_STRING(&methods, "OPTIONS");
			break;
		}
	} while(0);

	if (isRoute == 1) {
		ZEPHIR_INIT_VAR(&_0$$10);
		zephir_read_property(&_1$$10, this_ptr, SL("_actionSuffix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$10);
		ZVAL_STRING(&_2$$10, "");
		zephir_fast_str_replace(&_0$$10, &_1$$10, &_2$$10, &action TSRMLS_CC);
		ZEPHIR_INIT_VAR(&actionName);
		zephir_fast_strtolower(&actionName, &_0$$10);
		ZEPHIR_OBS_VAR(&routePrefix);
		zephir_read_property(&routePrefix, this_ptr, SL("_routePrefix"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_3$$10);
		ZVAL_STRING(&_3$$10, "paths");
		ZEPHIR_CALL_METHOD(&paths, annotation, "getnamedargument", NULL, 0, &_3$$10);
		zephir_check_call_status();
		if (Z_TYPE_P(&paths) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&paths);
			array_init(&paths);
		}
		if (!(ZEPHIR_IS_EMPTY(&module))) {
			zephir_array_update_string(&paths, SL("module"), &module, PH_COPY | PH_SEPARATE);
		}
		if (!(ZEPHIR_IS_EMPTY(&namespaceName))) {
			zephir_array_update_string(&paths, SL("namespace"), &namespaceName, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&paths, SL("controller"), &controller, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&paths, SL("action"), &actionName, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_4$$10, 0);
		ZEPHIR_CALL_METHOD(&value, annotation, "getargument", NULL, 0, &_4$$10);
		zephir_check_call_status();
		if (Z_TYPE_P(&value) != IS_NULL) {
			if (!ZEPHIR_IS_STRING(&value, "/")) {
				ZEPHIR_INIT_VAR(&uri);
				ZEPHIR_CONCAT_VV(&uri, &routePrefix, &value);
			} else {
				if (Z_TYPE_P(&routePrefix) != IS_NULL) {
					ZEPHIR_CPY_WRT(&uri, &routePrefix);
				} else {
					ZEPHIR_CPY_WRT(&uri, &value);
				}
			}
		} else {
			ZEPHIR_INIT_NVAR(&uri);
			ZEPHIR_CONCAT_VV(&uri, &routePrefix, &actionName);
		}
		ZEPHIR_CALL_METHOD(&route, this_ptr, "add", NULL, 0, &uri, &paths);
		zephir_check_call_status();
		if (Z_TYPE_P(&methods) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_5$$21);
			ZVAL_STRING(&_5$$21, "methods");
			ZEPHIR_CALL_METHOD(&methods, annotation, "getnamedargument", NULL, 0, &_5$$21);
			zephir_check_call_status();
			_6$$21 = Z_TYPE_P(&methods) == IS_ARRAY;
			if (!(_6$$21)) {
				_6$$21 = Z_TYPE_P(&methods) == IS_STRING;
			}
			if (_6$$21) {
				ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&_3$$10);
		ZVAL_STRING(&_3$$10, "converts");
		ZEPHIR_CALL_METHOD(&converts, annotation, "getnamedargument", NULL, 0, &_3$$10);
		zephir_check_call_status();
		if (Z_TYPE_P(&converts) == IS_ARRAY) {
			zephir_is_iterable(&converts, 0, "phalcon/mvc/router/annotations.zep", 334);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&converts), _8$$23, _9$$23, _7$$23)
			{
				ZEPHIR_INIT_NVAR(&param);
				if (_9$$23 != NULL) { 
					ZVAL_STR_COPY(&param, _9$$23);
				} else {
					ZVAL_LONG(&param, _8$$23);
				}
				ZEPHIR_INIT_NVAR(&convert);
				ZVAL_COPY(&convert, _7$$23);
				ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_10, 0, &param, &convert);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&convert);
			ZEPHIR_INIT_NVAR(&param);
		}
		ZEPHIR_INIT_NVAR(&_3$$10);
		ZVAL_STRING(&_3$$10, "conversors");
		ZEPHIR_CALL_METHOD(&converts, annotation, "getnamedargument", NULL, 0, &_3$$10);
		zephir_check_call_status();
		if (Z_TYPE_P(&converts) == IS_ARRAY) {
			zephir_is_iterable(&converts, 0, "phalcon/mvc/router/annotations.zep", 344);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&converts), _12$$25, _13$$25, _11$$25)
			{
				ZEPHIR_INIT_NVAR(&conversorParam);
				if (_13$$25 != NULL) { 
					ZVAL_STR_COPY(&conversorParam, _13$$25);
				} else {
					ZVAL_LONG(&conversorParam, _12$$25);
				}
				ZEPHIR_INIT_NVAR(&convert);
				ZVAL_COPY(&convert, _11$$25);
				ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_14, 0, &conversorParam, &convert);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&convert);
			ZEPHIR_INIT_NVAR(&conversorParam);
		}
		ZEPHIR_INIT_NVAR(&_3$$10);
		ZVAL_STRING(&_3$$10, "beforeMatch");
		ZEPHIR_CALL_METHOD(&beforeMatch, annotation, "getnamedargument", NULL, 0, &_3$$10);
		zephir_check_call_status();
		_15$$10 = Z_TYPE_P(&beforeMatch) == IS_ARRAY;
		if (!(_15$$10)) {
			_15$$10 = Z_TYPE_P(&beforeMatch) == IS_STRING;
		}
		if (_15$$10) {
			ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_3$$10);
		ZVAL_STRING(&_3$$10, "name");
		ZEPHIR_CALL_METHOD(&routeName, annotation, "getnamedargument", NULL, 0, &_3$$10);
		zephir_check_call_status();
		if (Z_TYPE_P(&routeName) == IS_STRING) {
			ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &routeName);
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
	zval controllerSuffix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerSuffix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerSuffix_param);

	if (UNEXPECTED(Z_TYPE_P(controllerSuffix_param) != IS_STRING && Z_TYPE_P(controllerSuffix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerSuffix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerSuffix_param) == IS_STRING)) {
		zephir_get_strval(&controllerSuffix, controllerSuffix_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerSuffix);
		ZVAL_EMPTY_STRING(&controllerSuffix);
	}


	zephir_update_property_zval(this_ptr, SL("_controllerSuffix"), &controllerSuffix);
	ZEPHIR_MM_RESTORE();

}

/**
 * Changes the action method suffix
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setActionSuffix) {

	zval *actionSuffix_param = NULL;
	zval actionSuffix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionSuffix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionSuffix_param);

	if (UNEXPECTED(Z_TYPE_P(actionSuffix_param) != IS_STRING && Z_TYPE_P(actionSuffix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionSuffix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(actionSuffix_param) == IS_STRING)) {
		zephir_get_strval(&actionSuffix, actionSuffix_param);
	} else {
		ZEPHIR_INIT_VAR(&actionSuffix);
		ZVAL_EMPTY_STRING(&actionSuffix);
	}


	zephir_update_property_zval(this_ptr, SL("_actionSuffix"), &actionSuffix);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the registered resources
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, getResources) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_handlers");

}

zend_object *zephir_init_properties_Phalcon_Mvc_Router_Annotations(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_defaultParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_defaultParams"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_params"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("_handlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("_handlers"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

