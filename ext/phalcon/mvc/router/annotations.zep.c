
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Router\Annotations
 *
 * A router that reads routes annotations from classes/resources
 *
 * ```php
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
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Annotations) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Router, Annotations, phalcon, mvc_router_annotations, phalcon_mvc_router_ce, phalcon_mvc_router_annotations_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("actionSuffix"), "Action", ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("actionPreformatCallback"), ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("controllerSuffix"), "Controller", ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("handlers"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("routePrefix"), ZEND_ACC_PROTECTED);

	phalcon_mvc_router_annotations_ce->create_object = zephir_init_properties_Phalcon_Mvc_Router_Annotations;

	return SUCCESS;

}

/**
 * Adds a resource to the annotations handler
 * A resource is a class that contains routing annotations
 * The class is located in a module
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addModuleResource) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *module_param = NULL, *handler_param = NULL, *prefix_param = NULL;
	zval module, handler, prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(module)
		Z_PARAM_STR(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(prefix)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &module_param, &handler_param, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(module_param) != IS_STRING && Z_TYPE_P(module_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'module' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(module_param) == IS_STRING)) {
		zephir_get_strval(&module, module_param);
	} else {
		ZEPHIR_INIT_VAR(&module);
		ZVAL_EMPTY_STRING(&module);
	}
	if (UNEXPECTED(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be of the type string"));
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string"));
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
	zephir_create_array(&_0, 3, 0);
	zephir_array_fast_append(&_0, &prefix);
	zephir_array_fast_append(&_0, &handler);
	zephir_array_fast_append(&_0, &module);
	zephir_update_property_array_append(this_ptr, SL("handlers"), &_0);
	RETURN_THIS();

}

/**
 * Adds a resource to the annotations handler
 * A resource is a class that contains routing annotations
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addResource) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handler_param = NULL, *prefix_param = NULL;
	zval handler, prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(prefix)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &handler_param, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be of the type string"));
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string"));
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
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, &prefix);
	zephir_array_fast_append(&_0, &handler);
	zephir_update_property_array_append(this_ptr, SL("handlers"), &_0);
	RETURN_THIS();

}

/**
 * Return the registered resources
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, getResources) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "handlers");

}

/**
 * Produce the routing parameters from the rewrite information
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, handle) {

	zend_string *_24$$18, *_45$$41;
	zend_ulong _23$$18, _44$$41;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL, *_10 = NULL, *_17 = NULL, *_20 = NULL, *_28 = NULL, *_39 = NULL, *_52 = NULL;
	zval *uri_param = NULL, __$null, annotationsService, handlers, controllerSuffix, scope, prefix, route, compiledPattern, container, handler, controllerName, lowerControllerName, namespaceName, moduleName, handlerAnnotations, classAnnotations, annotations, annotation, methodAnnotations, method, collection, _0, _5, *_6, _7, _1$$3, _2$$3, _4$$3, _9$$6, _11$$6, _12$$6, _13$$7, _14$$7, _15$$4, _16$$12, *_18$$15, _19$$15, *_21$$18, _22$$18, _25$$19, *_26$$19, _27$$19, _29$$23, *_30$$23, _31$$23, _32$$29, _33$$29, _34$$29, _35$$30, _36$$30, _37$$27, _38$$35, *_40$$38, _41$$38, *_42$$41, _43$$41, _46$$42, *_47$$42, _48$$42, _49$$46, *_50$$46, _51$$46;
	zval uri, sufixed;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&sufixed);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&annotationsService);
	ZVAL_UNDEF(&handlers);
	ZVAL_UNDEF(&controllerSuffix);
	ZVAL_UNDEF(&scope);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&compiledPattern);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&lowerControllerName);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&handlerAnnotations);
	ZVAL_UNDEF(&classAnnotations);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&annotation);
	ZVAL_UNDEF(&methodAnnotations);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_25$$19);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_29$$23);
	ZVAL_UNDEF(&_31$$23);
	ZVAL_UNDEF(&_32$$29);
	ZVAL_UNDEF(&_33$$29);
	ZVAL_UNDEF(&_34$$29);
	ZVAL_UNDEF(&_35$$30);
	ZVAL_UNDEF(&_36$$30);
	ZVAL_UNDEF(&_37$$27);
	ZVAL_UNDEF(&_38$$35);
	ZVAL_UNDEF(&_41$$38);
	ZVAL_UNDEF(&_43$$41);
	ZVAL_UNDEF(&_46$$42);
	ZVAL_UNDEF(&_48$$42);
	ZVAL_UNDEF(&_49$$46);
	ZVAL_UNDEF(&_51$$46);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_EMPTY_STRING(&uri);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "the 'annotations' service");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_mvc_router_exception_ce, "containerservicenotfound", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Router/Annotations.zep", 99);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "annotations");
	ZEPHIR_CALL_METHOD(&annotationsService, &container, "getshared", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handlers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&handlers, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("controllerSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&controllerSuffix, &_0);
	zephir_is_iterable(&handlers, 0, "phalcon/Mvc/Router/Annotations.zep", 236);
	if (Z_TYPE_P(&handlers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handlers), _6)
		{
			ZEPHIR_INIT_NVAR(&scope);
			ZVAL_COPY(&scope, _6);
			if (Z_TYPE_P(&scope) != IS_ARRAY) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&prefix);
			zephir_array_fetch_long(&prefix, &scope, 0, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 116);
			if (!(ZEPHIR_IS_EMPTY(&prefix))) {
				ZEPHIR_INIT_NVAR(&route);
				object_init_ex(&route, phalcon_mvc_router_route_ce);
				ZEPHIR_CALL_METHOD(NULL, &route, "__construct", &_8, 118, &prefix);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_9$$6, &route, "getcompiledpattern", &_10, 509);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZVAL_STRING(&_11$$6, "$#");
				ZEPHIR_INIT_NVAR(&_12$$6);
				ZVAL_STRING(&_12$$6, "#");
				ZEPHIR_INIT_NVAR(&compiledPattern);
				zephir_fast_str_replace(&compiledPattern, &_11$$6, &_12$$6, &_9$$6);
				if (zephir_memnstr_str(&compiledPattern, SL("^"), "phalcon/Mvc/Router/Annotations.zep", 133)) {
					ZEPHIR_INIT_NVAR(&_13$$7);
					ZEPHIR_INIT_NVAR(&_14$$7);
					zephir_preg_match(&_14$$7, &compiledPattern, &uri, &_13$$7, 0, 0 , 0 );
					if (!(zephir_is_true(&_14$$7))) {
						continue;
					}
				} else if (!(zephir_start_with(&uri, &prefix, NULL))) {
					continue;
				}
			}
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch_long(&handler, &scope, 1, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 148);
			if (zephir_memnstr_str(&handler, SL("\\"), "phalcon/Mvc/Router/Annotations.zep", 150)) {
				ZEPHIR_INIT_NVAR(&controllerName);
				zephir_get_class_ns(&controllerName, &handler, 0);
				ZEPHIR_INIT_NVAR(&namespaceName);
				zephir_get_ns_class(&namespaceName, &handler, 0);
			} else {
				ZEPHIR_CPY_WRT(&controllerName, &handler);
				ZEPHIR_OBS_NVAR(&namespaceName);
				zephir_fetch_property(&namespaceName, this_ptr, SL("defaultNamespace"), PH_SILENT_CC);
			}
			zephir_update_property_zval(this_ptr, ZEND_STRL("routePrefix"), &__$null);
			ZEPHIR_OBS_NVAR(&moduleName);
			zephir_array_isset_long_fetch(&moduleName, &scope, 2, 0);
			ZEPHIR_INIT_NVAR(&_15$$4);
			ZEPHIR_CONCAT_VV(&_15$$4, &controllerName, &controllerSuffix);
			zephir_get_strval(&sufixed, &_15$$4);
			if (Z_TYPE_P(&namespaceName) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_16$$12);
				ZEPHIR_CONCAT_VSV(&_16$$12, &namespaceName, "\\", &sufixed);
				zephir_get_strval(&sufixed, &_16$$12);
			}
			ZEPHIR_CALL_METHOD(&handlerAnnotations, &annotationsService, "get", &_17, 0, &sufixed);
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
					zephir_is_iterable(&annotations, 0, "phalcon/Mvc/Router/Annotations.zep", 204);
					if (Z_TYPE_P(&annotations) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&annotations), _18$$15)
						{
							ZEPHIR_INIT_NVAR(&annotation);
							ZVAL_COPY(&annotation, _18$$15);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_20, 0, &controllerName, &annotation);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &annotations, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_19$$15, &annotations, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_19$$15)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&annotation, &annotations, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_20, 0, &controllerName, &annotation);
								zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &annotations, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&annotation);
				}
			}
			ZEPHIR_CALL_METHOD(&methodAnnotations, &handlerAnnotations, "getmethodsannotations", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&lowerControllerName);
				zephir_uncamelize(&lowerControllerName, &controllerName, NULL  );
				zephir_is_iterable(&methodAnnotations, 0, "phalcon/Mvc/Router/Annotations.zep", 230);
				if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methodAnnotations), _23$$18, _24$$18, _21$$18)
					{
						ZEPHIR_INIT_NVAR(&method);
						if (_24$$18 != NULL) { 
							ZVAL_STR_COPY(&method, _24$$18);
						} else {
							ZVAL_LONG(&method, _23$$18);
						}
						ZEPHIR_INIT_NVAR(&collection);
						ZVAL_COPY(&collection, _21$$18);
						if (Z_TYPE_P(&collection) != IS_OBJECT) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&_25$$19, &collection, "getannotations", NULL, 0);
						zephir_check_call_status();
						zephir_is_iterable(&_25$$19, 0, "phalcon/Mvc/Router/Annotations.zep", 229);
						if (Z_TYPE_P(&_25$$19) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_25$$19), _26$$19)
							{
								ZEPHIR_INIT_NVAR(&annotation);
								ZVAL_COPY(&annotation, _26$$19);
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_25$$19, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_27$$19, &_25$$19, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_27$$19)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&annotation, &_25$$19, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
									zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &_25$$19, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&annotation);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &methodAnnotations, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_22$$18, &methodAnnotations, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_22$$18)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&method, &methodAnnotations, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&collection, &methodAnnotations, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&collection) != IS_OBJECT) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&_29$$23, &collection, "getannotations", NULL, 0);
							zephir_check_call_status();
							zephir_is_iterable(&_29$$23, 0, "phalcon/Mvc/Router/Annotations.zep", 229);
							if (Z_TYPE_P(&_29$$23) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_29$$23), _30$$23)
								{
									ZEPHIR_INIT_NVAR(&annotation);
									ZVAL_COPY(&annotation, _30$$23);
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_29$$23, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_31$$23, &_29$$23, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_31$$23)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&annotation, &_29$$23, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &_29$$23, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&annotation);
						ZEPHIR_CALL_METHOD(NULL, &methodAnnotations, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&collection);
				ZEPHIR_INIT_NVAR(&method);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &handlers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &handlers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&scope, &handlers, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&scope) != IS_ARRAY) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&prefix);
				zephir_array_fetch_long(&prefix, &scope, 0, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 116);
				if (!(ZEPHIR_IS_EMPTY(&prefix))) {
					ZEPHIR_INIT_NVAR(&route);
					object_init_ex(&route, phalcon_mvc_router_route_ce);
					ZEPHIR_CALL_METHOD(NULL, &route, "__construct", &_8, 118, &prefix);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_32$$29, &route, "getcompiledpattern", &_10, 509);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_33$$29);
					ZVAL_STRING(&_33$$29, "$#");
					ZEPHIR_INIT_NVAR(&_34$$29);
					ZVAL_STRING(&_34$$29, "#");
					ZEPHIR_INIT_NVAR(&compiledPattern);
					zephir_fast_str_replace(&compiledPattern, &_33$$29, &_34$$29, &_32$$29);
					if (zephir_memnstr_str(&compiledPattern, SL("^"), "phalcon/Mvc/Router/Annotations.zep", 133)) {
						ZEPHIR_INIT_NVAR(&_35$$30);
						ZEPHIR_INIT_NVAR(&_36$$30);
						zephir_preg_match(&_36$$30, &compiledPattern, &uri, &_35$$30, 0, 0 , 0 );
						if (!(zephir_is_true(&_36$$30))) {
							continue;
						}
					} else if (!(zephir_start_with(&uri, &prefix, NULL))) {
						continue;
					}
				}
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_long(&handler, &scope, 1, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 148);
				if (zephir_memnstr_str(&handler, SL("\\"), "phalcon/Mvc/Router/Annotations.zep", 150)) {
					ZEPHIR_INIT_NVAR(&controllerName);
					zephir_get_class_ns(&controllerName, &handler, 0);
					ZEPHIR_INIT_NVAR(&namespaceName);
					zephir_get_ns_class(&namespaceName, &handler, 0);
				} else {
					ZEPHIR_CPY_WRT(&controllerName, &handler);
					ZEPHIR_OBS_NVAR(&namespaceName);
					zephir_fetch_property(&namespaceName, this_ptr, SL("defaultNamespace"), PH_SILENT_CC);
				}
				zephir_update_property_zval(this_ptr, ZEND_STRL("routePrefix"), &__$null);
				ZEPHIR_OBS_NVAR(&moduleName);
				zephir_array_isset_long_fetch(&moduleName, &scope, 2, 0);
				ZEPHIR_INIT_NVAR(&_37$$27);
				ZEPHIR_CONCAT_VV(&_37$$27, &controllerName, &controllerSuffix);
				zephir_get_strval(&sufixed, &_37$$27);
				if (Z_TYPE_P(&namespaceName) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_38$$35);
					ZEPHIR_CONCAT_VSV(&_38$$35, &namespaceName, "\\", &sufixed);
					zephir_get_strval(&sufixed, &_38$$35);
				}
				ZEPHIR_CALL_METHOD(&handlerAnnotations, &annotationsService, "get", &_39, 0, &sufixed);
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
						zephir_is_iterable(&annotations, 0, "phalcon/Mvc/Router/Annotations.zep", 204);
						if (Z_TYPE_P(&annotations) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&annotations), _40$$38)
							{
								ZEPHIR_INIT_NVAR(&annotation);
								ZVAL_COPY(&annotation, _40$$38);
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_20, 0, &controllerName, &annotation);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &annotations, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_41$$38, &annotations, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_41$$38)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&annotation, &annotations, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_20, 0, &controllerName, &annotation);
									zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &annotations, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&annotation);
					}
				}
				ZEPHIR_CALL_METHOD(&methodAnnotations, &handlerAnnotations, "getmethodsannotations", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&lowerControllerName);
					zephir_uncamelize(&lowerControllerName, &controllerName, NULL  );
					zephir_is_iterable(&methodAnnotations, 0, "phalcon/Mvc/Router/Annotations.zep", 230);
					if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methodAnnotations), _44$$41, _45$$41, _42$$41)
						{
							ZEPHIR_INIT_NVAR(&method);
							if (_45$$41 != NULL) { 
								ZVAL_STR_COPY(&method, _45$$41);
							} else {
								ZVAL_LONG(&method, _44$$41);
							}
							ZEPHIR_INIT_NVAR(&collection);
							ZVAL_COPY(&collection, _42$$41);
							if (Z_TYPE_P(&collection) != IS_OBJECT) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&_46$$42, &collection, "getannotations", NULL, 0);
							zephir_check_call_status();
							zephir_is_iterable(&_46$$42, 0, "phalcon/Mvc/Router/Annotations.zep", 229);
							if (Z_TYPE_P(&_46$$42) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_46$$42), _47$$42)
								{
									ZEPHIR_INIT_NVAR(&annotation);
									ZVAL_COPY(&annotation, _47$$42);
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_46$$42, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_48$$42, &_46$$42, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_48$$42)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&annotation, &_46$$42, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &_46$$42, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&annotation);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &methodAnnotations, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_43$$41, &methodAnnotations, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_43$$41)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&method, &methodAnnotations, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&collection, &methodAnnotations, "current", NULL, 0);
							zephir_check_call_status();
								if (Z_TYPE_P(&collection) != IS_OBJECT) {
									continue;
								}
								ZEPHIR_CALL_METHOD(&_49$$46, &collection, "getannotations", NULL, 0);
								zephir_check_call_status();
								zephir_is_iterable(&_49$$46, 0, "phalcon/Mvc/Router/Annotations.zep", 229);
								if (Z_TYPE_P(&_49$$46) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_49$$46), _50$$46)
									{
										ZEPHIR_INIT_NVAR(&annotation);
										ZVAL_COPY(&annotation, _50$$46);
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &_49$$46, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_51$$46, &_49$$46, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_51$$46)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&annotation, &_49$$46, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
											zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, &_49$$46, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&annotation);
							ZEPHIR_CALL_METHOD(NULL, &methodAnnotations, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&collection);
					ZEPHIR_INIT_NVAR(&method);
				}
			ZEPHIR_CALL_METHOD(NULL, &handlers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&scope);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_router_annotations_ce, getThis(), "handle", &_52, 0, &uri);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks for annotations in the public methods of the controller
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processActionAnnotation) {

	zend_string *_12$$18, *_18$$21;
	zend_ulong _11$$18, _17$$21;
	zend_bool isRoute = 0, _8, _21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_14 = NULL, *_19 = NULL, *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *module_param = NULL, *namespaceName_param = NULL, *controller_param = NULL, *action_param = NULL, *annotation, annotation_sub, name, proxyActionName, actionName, routePrefix, paths, value, uri, route, methods, converts, param, convert, converterParam, routeName, beforeMatch, _0, _1, _2, _5, _6, _3$$6, _4$$6, _7$$16, *_9$$18, _10$$18, *_15$$21, _16$$21;
	zval module, namespaceName, controller, action;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&annotation_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&proxyActionName);
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
	ZVAL_UNDEF(&converterParam);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$16);
	ZVAL_UNDEF(&_10$$18);
	ZVAL_UNDEF(&_16$$21);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_STR(module)
		Z_PARAM_STR(namespaceName)
		Z_PARAM_STR(controller)
		Z_PARAM_STR(action)
		Z_PARAM_OBJECT_OF_CLASS(annotation, phalcon_annotations_annotation_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &module_param, &namespaceName_param, &controller_param, &action_param, &annotation);

	if (UNEXPECTED(Z_TYPE_P(module_param) != IS_STRING && Z_TYPE_P(module_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'module' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(module_param) == IS_STRING)) {
		zephir_get_strval(&module, module_param);
	} else {
		ZEPHIR_INIT_VAR(&module);
		ZVAL_EMPTY_STRING(&module);
	}
	if (UNEXPECTED(Z_TYPE_P(namespaceName_param) != IS_STRING && Z_TYPE_P(namespaceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'namespaceName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(namespaceName_param) == IS_STRING)) {
		zephir_get_strval(&namespaceName, namespaceName_param);
	} else {
		ZEPHIR_INIT_VAR(&namespaceName);
		ZVAL_EMPTY_STRING(&namespaceName);
	}
	if (UNEXPECTED(Z_TYPE_P(controller_param) != IS_STRING && Z_TYPE_P(controller_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controller' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controller_param) == IS_STRING)) {
		zephir_get_strval(&controller, controller_param);
	} else {
		ZEPHIR_INIT_VAR(&controller);
		ZVAL_EMPTY_STRING(&controller);
	}
	if (UNEXPECTED(Z_TYPE_P(action_param) != IS_STRING && Z_TYPE_P(action_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'action' must be of the type string"));
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
		if (ZEPHIR_IS_STRING(&name, "Get") || ZEPHIR_IS_STRING(&name, "Post") || ZEPHIR_IS_STRING(&name, "Put") || ZEPHIR_IS_STRING(&name, "Patch") || ZEPHIR_IS_STRING(&name, "Delete") || ZEPHIR_IS_STRING(&name, "Options")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(&methods);
			zephir_fast_strtoupper(&methods, &name);
			break;
		}
	} while(0);

	if (!(isRoute)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("actionSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_INIT_VAR(&proxyActionName);
	zephir_fast_str_replace(&proxyActionName, &_0, &_1, &action);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("routePrefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&routePrefix, &_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("actionPreformatCallback"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_2) != IS_NULL) {
		zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("actionPreformatCallback"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_4$$6, "call_user_func", NULL, 276, &_3$$6, &proxyActionName);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&proxyActionName, &_4$$6);
	}
	ZEPHIR_INIT_VAR(&actionName);
	zephir_fast_strtolower(&actionName, &proxyActionName);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "paths");
	ZEPHIR_CALL_METHOD(&paths, annotation, "getnamedargument", NULL, 0, &_5);
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
	ZVAL_LONG(&_6, 0);
	ZEPHIR_CALL_METHOD(&value, annotation, "getargument", NULL, 0, &_6);
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
	if (Z_TYPE_P(&methods) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_7$$16);
		ZVAL_STRING(&_7$$16, "methods");
		ZEPHIR_CALL_METHOD(&methods, annotation, "getnamedargument", NULL, 0, &_7$$16);
		zephir_check_call_status();
	}
	_8 = Z_TYPE_P(&methods) == IS_ARRAY;
	if (!(_8)) {
		_8 = Z_TYPE_P(&methods) == IS_STRING;
	}
	if (_8) {
		ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "converts");
	ZEPHIR_CALL_METHOD(&converts, annotation, "getnamedargument", NULL, 0, &_5);
	zephir_check_call_status();
	if (Z_TYPE_P(&converts) == IS_ARRAY) {
		zephir_is_iterable(&converts, 0, "phalcon/Mvc/Router/Annotations.zep", 355);
		if (Z_TYPE_P(&converts) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&converts), _11$$18, _12$$18, _9$$18)
			{
				ZEPHIR_INIT_NVAR(&param);
				if (_12$$18 != NULL) { 
					ZVAL_STR_COPY(&param, _12$$18);
				} else {
					ZVAL_LONG(&param, _11$$18);
				}
				ZEPHIR_INIT_NVAR(&convert);
				ZVAL_COPY(&convert, _9$$18);
				ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_13, 0, &param, &convert);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &converts, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_10$$18, &converts, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$18)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&param, &converts, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&convert, &converts, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_14, 0, &param, &convert);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &converts, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&convert);
		ZEPHIR_INIT_NVAR(&param);
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "converters");
	ZEPHIR_CALL_METHOD(&converts, annotation, "getnamedargument", NULL, 0, &_5);
	zephir_check_call_status();
	if (Z_TYPE_P(&converts) == IS_ARRAY) {
		zephir_is_iterable(&converts, 0, "phalcon/Mvc/Router/Annotations.zep", 366);
		if (Z_TYPE_P(&converts) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&converts), _17$$21, _18$$21, _15$$21)
			{
				ZEPHIR_INIT_NVAR(&converterParam);
				if (_18$$21 != NULL) { 
					ZVAL_STR_COPY(&converterParam, _18$$21);
				} else {
					ZVAL_LONG(&converterParam, _17$$21);
				}
				ZEPHIR_INIT_NVAR(&convert);
				ZVAL_COPY(&convert, _15$$21);
				ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_19, 0, &converterParam, &convert);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &converts, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_16$$21, &converts, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_16$$21)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&converterParam, &converts, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&convert, &converts, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_20, 0, &converterParam, &convert);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &converts, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&convert);
		ZEPHIR_INIT_NVAR(&converterParam);
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "beforeMatch");
	ZEPHIR_CALL_METHOD(&beforeMatch, annotation, "getnamedargument", NULL, 0, &_5);
	zephir_check_call_status();
	_21 = Z_TYPE_P(&beforeMatch) == IS_ARRAY;
	if (!(_21)) {
		_21 = Z_TYPE_P(&beforeMatch) == IS_STRING;
	}
	if (_21) {
		ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "name");
	ZEPHIR_CALL_METHOD(&routeName, annotation, "getnamedargument", NULL, 0, &_5);
	zephir_check_call_status();
	if (Z_TYPE_P(&routeName) == IS_STRING) {
		ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &routeName);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Checks for annotations in the controller docblock
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processControllerAnnotation) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *handler_param = NULL, *annotation, annotation_sub, _0, _1$$3, _2$$3;
	zval handler;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&annotation_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(handler)
		Z_PARAM_OBJECT_OF_CLASS(annotation, phalcon_annotations_annotation_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &handler_param, &annotation);

	if (UNEXPECTED(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be of the type string"));
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("routePrefix"), &_1$$3);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Changes the action method suffix
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setActionSuffix) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *actionSuffix_param = NULL;
	zval actionSuffix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionSuffix);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionSuffix)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionSuffix_param);

	if (UNEXPECTED(Z_TYPE_P(actionSuffix_param) != IS_STRING && Z_TYPE_P(actionSuffix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionSuffix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(actionSuffix_param) == IS_STRING)) {
		zephir_get_strval(&actionSuffix, actionSuffix_param);
	} else {
		ZEPHIR_INIT_VAR(&actionSuffix);
		ZVAL_EMPTY_STRING(&actionSuffix);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("actionSuffix"), &actionSuffix);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the action preformat callback
 * $action here already without suffix 'Action'
 *
 * ```php
 * // Array as callback
 * $annotationRouter->setActionPreformatCallback([Text::class, 'uncamelize']);
 *
 * // Function as callback
 * $annotationRouter->setActionPreformatCallback(function(action){
 *     return action;
 * });
 *
 * // String as callback
 * $annotationRouter->setActionPreformatCallback('strtolower');
 *
 * // If empty method constructor called [null], sets uncamelize with - delimiter
 * $annotationRouter->setActionPreformatCallback();
 * ```
 *
 * @param callable|string|null $callback
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setActionPreformatCallback) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *callback = NULL, callback_sub, __$null, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &callback);

	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}


	if (EXPECTED(zephir_is_callable(callback))) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("actionPreformatCallback"), callback);
	} else if (Z_TYPE_P(callback) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_INIT_NVAR(&_0$$4);
		zephir_create_closure_ex(&_0$$4, NULL, phalcon_9__closure_ce, SL("__invoke"));
		zephir_update_property_zval(this_ptr, ZEND_STRL("actionPreformatCallback"), &_0$$4);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "The 'callback' parameter must be either a callable or NULL.", "phalcon/Mvc/Router/Annotations.zep", 440);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @return callable|string|null
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, getActionPreformatCallback) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "actionPreformatCallback");

}

/**
 * Changes the controller class suffix
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setControllerSuffix) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *controllerSuffix_param = NULL;
	zval controllerSuffix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerSuffix);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(controllerSuffix)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerSuffix_param);

	if (UNEXPECTED(Z_TYPE_P(controllerSuffix_param) != IS_STRING && Z_TYPE_P(controllerSuffix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerSuffix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerSuffix_param) == IS_STRING)) {
		zephir_get_strval(&controllerSuffix, controllerSuffix_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerSuffix);
		ZVAL_EMPTY_STRING(&controllerSuffix);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("controllerSuffix"), &controllerSuffix);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Mvc_Router_Annotations(zend_class_entry *class_type) {

		zval _0, _2, _4, _6, _8, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("params"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("keyRouteIds"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("keyRouteIds"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("keyRouteNames"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("keyRouteNames"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("defaultParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("defaultParams"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("handlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("handlers"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

