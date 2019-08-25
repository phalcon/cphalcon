
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

	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("actionSuffix"), "Action", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("controllerSuffix"), "Controller", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("handlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("routePrefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &module_param, &handler_param, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(module_param) != IS_STRING && Z_TYPE_P(module_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'module' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(module_param) == IS_STRING)) {
		zephir_get_strval(&module, module_param);
	} else {
		ZEPHIR_INIT_VAR(&module);
		ZVAL_EMPTY_STRING(&module);
	}
	if (UNEXPECTED(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be of the type string") TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string") TSRMLS_CC);
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &handler_param, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be of the type string") TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string") TSRMLS_CC);
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

	zend_string *_18$$15, *_35$$35;
	zend_ulong _17$$15, _34$$35;
	zend_bool _8$$4, _26$$24;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_11 = NULL, *_14 = NULL, *_22 = NULL, *_29 = NULL, *_42 = NULL;
	zval *uri_param = NULL, __$null, annotationsService, handlers, controllerSuffix, scope, prefix, container, handler, controllerName, lowerControllerName, namespaceName, moduleName, handlerAnnotations, classAnnotations, annotations, annotation, methodAnnotations, method, collection, _0, _5, *_6, _7, _1$$3, _2$$3, _4$$3, _9$$4, _10$$9, *_12$$12, _13$$12, *_15$$15, _16$$15, _19$$16, *_20$$16, _21$$16, _23$$20, *_24$$20, _25$$20, _27$$24, _28$$29, *_30$$32, _31$$32, *_32$$35, _33$$35, _36$$36, *_37$$36, _38$$36, _39$$40, *_40$$40, _41$$40;
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
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_23$$20);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_27$$24);
	ZVAL_UNDEF(&_28$$29);
	ZVAL_UNDEF(&_31$$32);
	ZVAL_UNDEF(&_33$$35);
	ZVAL_UNDEF(&_36$$36);
	ZVAL_UNDEF(&_38$$36);
	ZVAL_UNDEF(&_39$$40);
	ZVAL_UNDEF(&_41$$40);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_EMPTY_STRING(&uri);
	}


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_router_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "the 'annotations' service");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_mvc_router_exception_ce, "containerservicenotfound", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 5, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Router/Annotations.zep", 97 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "annotations");
	ZEPHIR_CALL_METHOD(&annotationsService, &container, "getshared", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("handlers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&handlers, &_0);
	zephir_read_property(&_0, this_ptr, SL("controllerSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&controllerSuffix, &_0);
	zephir_is_iterable(&handlers, 0, "phalcon/Mvc/Router/Annotations.zep", 211);
	if (Z_TYPE_P(&handlers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handlers), _6)
		{
			ZEPHIR_INIT_NVAR(&scope);
			ZVAL_COPY(&scope, _6);
			if (Z_TYPE_P(&scope) != IS_ARRAY) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&prefix);
			zephir_array_fetch_long(&prefix, &scope, 0, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 114 TSRMLS_CC);
			_8$$4 = !(ZEPHIR_IS_EMPTY(&prefix));
			if (_8$$4) {
				_8$$4 = !(zephir_start_with(&uri, &prefix, NULL));
			}
			if (_8$$4) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch_long(&handler, &scope, 1, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 123 TSRMLS_CC);
			if (zephir_memnstr_str(&handler, SL("\\"), "phalcon/Mvc/Router/Annotations.zep", 125)) {
				ZEPHIR_INIT_NVAR(&controllerName);
				zephir_get_class_ns(&controllerName, &handler, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&namespaceName);
				zephir_get_ns_class(&namespaceName, &handler, 0 TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(&controllerName, &handler);
				ZEPHIR_OBS_NVAR(&namespaceName);
				zephir_fetch_property(&namespaceName, this_ptr, SL("defaultNamespace"), PH_SILENT_CC);
			}
			zephir_update_property_zval(this_ptr, SL("routePrefix"), &__$null);
			ZEPHIR_OBS_NVAR(&moduleName);
			zephir_array_isset_long_fetch(&moduleName, &scope, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_9$$4);
			ZEPHIR_CONCAT_VV(&_9$$4, &controllerName, &controllerSuffix);
			zephir_get_strval(&sufixed, &_9$$4);
			if (Z_TYPE_P(&namespaceName) != IS_NULL) {
				ZEPHIR_INIT_LNVAR(_10$$9);
				ZEPHIR_CONCAT_VSV(&_10$$9, &namespaceName, "\\", &sufixed);
				zephir_get_strval(&sufixed, &_10$$9);
			}
			ZEPHIR_CALL_METHOD(&handlerAnnotations, &annotationsService, "get", &_11, 0, &sufixed);
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
					zephir_is_iterable(&annotations, 0, "phalcon/Mvc/Router/Annotations.zep", 179);
					if (Z_TYPE_P(&annotations) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&annotations), _12$$12)
						{
							ZEPHIR_INIT_NVAR(&annotation);
							ZVAL_COPY(&annotation, _12$$12);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_14, 0, &controllerName, &annotation);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &annotations, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_13$$12, &annotations, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_13$$12)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&annotation, &annotations, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_14, 0, &controllerName, &annotation);
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
				zephir_is_iterable(&methodAnnotations, 0, "phalcon/Mvc/Router/Annotations.zep", 205);
				if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methodAnnotations), _17$$15, _18$$15, _15$$15)
					{
						ZEPHIR_INIT_NVAR(&method);
						if (_18$$15 != NULL) { 
							ZVAL_STR_COPY(&method, _18$$15);
						} else {
							ZVAL_LONG(&method, _17$$15);
						}
						ZEPHIR_INIT_NVAR(&collection);
						ZVAL_COPY(&collection, _15$$15);
						if (Z_TYPE_P(&collection) != IS_OBJECT) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&_19$$16, &collection, "getannotations", NULL, 0);
						zephir_check_call_status();
						zephir_is_iterable(&_19$$16, 0, "phalcon/Mvc/Router/Annotations.zep", 204);
						if (Z_TYPE_P(&_19$$16) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_19$$16), _20$$16)
							{
								ZEPHIR_INIT_NVAR(&annotation);
								ZVAL_COPY(&annotation, _20$$16);
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_22, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_19$$16, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_21$$16, &_19$$16, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_21$$16)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&annotation, &_19$$16, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_22, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
									zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &_19$$16, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&annotation);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &methodAnnotations, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_16$$15, &methodAnnotations, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_16$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&method, &methodAnnotations, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&collection, &methodAnnotations, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&collection) != IS_OBJECT) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&_23$$20, &collection, "getannotations", NULL, 0);
							zephir_check_call_status();
							zephir_is_iterable(&_23$$20, 0, "phalcon/Mvc/Router/Annotations.zep", 204);
							if (Z_TYPE_P(&_23$$20) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_23$$20), _24$$20)
								{
									ZEPHIR_INIT_NVAR(&annotation);
									ZVAL_COPY(&annotation, _24$$20);
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_22, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_23$$20, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_25$$20, &_23$$20, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_25$$20)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&annotation, &_23$$20, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_22, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &_23$$20, "next", NULL, 0);
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
				zephir_array_fetch_long(&prefix, &scope, 0, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 114 TSRMLS_CC);
				_26$$24 = !(ZEPHIR_IS_EMPTY(&prefix));
				if (_26$$24) {
					_26$$24 = !(zephir_start_with(&uri, &prefix, NULL));
				}
				if (_26$$24) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_long(&handler, &scope, 1, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 123 TSRMLS_CC);
				if (zephir_memnstr_str(&handler, SL("\\"), "phalcon/Mvc/Router/Annotations.zep", 125)) {
					ZEPHIR_INIT_NVAR(&controllerName);
					zephir_get_class_ns(&controllerName, &handler, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&namespaceName);
					zephir_get_ns_class(&namespaceName, &handler, 0 TSRMLS_CC);
				} else {
					ZEPHIR_CPY_WRT(&controllerName, &handler);
					ZEPHIR_OBS_NVAR(&namespaceName);
					zephir_fetch_property(&namespaceName, this_ptr, SL("defaultNamespace"), PH_SILENT_CC);
				}
				zephir_update_property_zval(this_ptr, SL("routePrefix"), &__$null);
				ZEPHIR_OBS_NVAR(&moduleName);
				zephir_array_isset_long_fetch(&moduleName, &scope, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_27$$24);
				ZEPHIR_CONCAT_VV(&_27$$24, &controllerName, &controllerSuffix);
				zephir_get_strval(&sufixed, &_27$$24);
				if (Z_TYPE_P(&namespaceName) != IS_NULL) {
					ZEPHIR_INIT_LNVAR(_28$$29);
					ZEPHIR_CONCAT_VSV(&_28$$29, &namespaceName, "\\", &sufixed);
					zephir_get_strval(&sufixed, &_28$$29);
				}
				ZEPHIR_CALL_METHOD(&handlerAnnotations, &annotationsService, "get", &_29, 0, &sufixed);
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
						zephir_is_iterable(&annotations, 0, "phalcon/Mvc/Router/Annotations.zep", 179);
						if (Z_TYPE_P(&annotations) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&annotations), _30$$32)
							{
								ZEPHIR_INIT_NVAR(&annotation);
								ZVAL_COPY(&annotation, _30$$32);
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_14, 0, &controllerName, &annotation);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &annotations, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_31$$32, &annotations, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_31$$32)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&annotation, &annotations, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_14, 0, &controllerName, &annotation);
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
					zephir_is_iterable(&methodAnnotations, 0, "phalcon/Mvc/Router/Annotations.zep", 205);
					if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methodAnnotations), _34$$35, _35$$35, _32$$35)
						{
							ZEPHIR_INIT_NVAR(&method);
							if (_35$$35 != NULL) { 
								ZVAL_STR_COPY(&method, _35$$35);
							} else {
								ZVAL_LONG(&method, _34$$35);
							}
							ZEPHIR_INIT_NVAR(&collection);
							ZVAL_COPY(&collection, _32$$35);
							if (Z_TYPE_P(&collection) != IS_OBJECT) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&_36$$36, &collection, "getannotations", NULL, 0);
							zephir_check_call_status();
							zephir_is_iterable(&_36$$36, 0, "phalcon/Mvc/Router/Annotations.zep", 204);
							if (Z_TYPE_P(&_36$$36) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_36$$36), _37$$36)
								{
									ZEPHIR_INIT_NVAR(&annotation);
									ZVAL_COPY(&annotation, _37$$36);
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_22, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_36$$36, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_38$$36, &_36$$36, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_38$$36)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&annotation, &_36$$36, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_22, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &_36$$36, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&annotation);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &methodAnnotations, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_33$$35, &methodAnnotations, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_33$$35)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&method, &methodAnnotations, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&collection, &methodAnnotations, "current", NULL, 0);
							zephir_check_call_status();
								if (Z_TYPE_P(&collection) != IS_OBJECT) {
									continue;
								}
								ZEPHIR_CALL_METHOD(&_39$$40, &collection, "getannotations", NULL, 0);
								zephir_check_call_status();
								zephir_is_iterable(&_39$$40, 0, "phalcon/Mvc/Router/Annotations.zep", 204);
								if (Z_TYPE_P(&_39$$40) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_39$$40), _40$$40)
									{
										ZEPHIR_INIT_NVAR(&annotation);
										ZVAL_COPY(&annotation, _40$$40);
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_22, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &_39$$40, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_41$$40, &_39$$40, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_41$$40)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&annotation, &_39$$40, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_22, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
											zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, &_39$$40, "next", NULL, 0);
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
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_router_annotations_ce, getThis(), "handle", &_42, 0, &uri);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks for annotations in the public methods of the controller
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processActionAnnotation) {

	zend_string *_10$$17, *_16$$20;
	zend_ulong _9$$17, _15$$20;
	zend_bool isRoute = 0, _6, _19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_17 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *module_param = NULL, *namespaceName_param = NULL, *controller_param = NULL, *action_param = NULL, *annotation, annotation_sub, name, actionName, routePrefix, paths, value, uri, route, methods, converts, param, convert, conversorParam, routeName, beforeMatch, _0, _1, _2, _3, _4, _5$$15, *_7$$17, _8$$17, *_13$$20, _14$$20;
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
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$15);
	ZVAL_UNDEF(&_8$$17);
	ZVAL_UNDEF(&_14$$20);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &module_param, &namespaceName_param, &controller_param, &action_param, &annotation);

	if (UNEXPECTED(Z_TYPE_P(module_param) != IS_STRING && Z_TYPE_P(module_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'module' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(module_param) == IS_STRING)) {
		zephir_get_strval(&module, module_param);
	} else {
		ZEPHIR_INIT_VAR(&module);
		ZVAL_EMPTY_STRING(&module);
	}
	if (UNEXPECTED(Z_TYPE_P(namespaceName_param) != IS_STRING && Z_TYPE_P(namespaceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'namespaceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(namespaceName_param) == IS_STRING)) {
		zephir_get_strval(&namespaceName, namespaceName_param);
	} else {
		ZEPHIR_INIT_VAR(&namespaceName);
		ZVAL_EMPTY_STRING(&namespaceName);
	}
	if (UNEXPECTED(Z_TYPE_P(controller_param) != IS_STRING && Z_TYPE_P(controller_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controller' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controller_param) == IS_STRING)) {
		zephir_get_strval(&controller, controller_param);
	} else {
		ZEPHIR_INIT_VAR(&controller);
		ZVAL_EMPTY_STRING(&controller);
	}
	if (UNEXPECTED(Z_TYPE_P(action_param) != IS_STRING && Z_TYPE_P(action_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'action' must be of the type string") TSRMLS_CC);
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
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("actionSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	zephir_fast_str_replace(&_0, &_1, &_2, &action TSRMLS_CC);
	ZEPHIR_INIT_VAR(&actionName);
	zephir_fast_strtolower(&actionName, &_0);
	zephir_read_property(&_3, this_ptr, SL("routePrefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&routePrefix, &_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "paths");
	ZEPHIR_CALL_METHOD(&paths, annotation, "getnamedargument", NULL, 0, &_4);
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
	ZVAL_LONG(&_3, 0);
	ZEPHIR_CALL_METHOD(&value, annotation, "getargument", NULL, 0, &_3);
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
		ZEPHIR_INIT_VAR(&_5$$15);
		ZVAL_STRING(&_5$$15, "methods");
		ZEPHIR_CALL_METHOD(&methods, annotation, "getnamedargument", NULL, 0, &_5$$15);
		zephir_check_call_status();
	}
	_6 = Z_TYPE_P(&methods) == IS_ARRAY;
	if (!(_6)) {
		_6 = Z_TYPE_P(&methods) == IS_STRING;
	}
	if (_6) {
		ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "converts");
	ZEPHIR_CALL_METHOD(&converts, annotation, "getnamedargument", NULL, 0, &_4);
	zephir_check_call_status();
	if (Z_TYPE_P(&converts) == IS_ARRAY) {
		zephir_is_iterable(&converts, 0, "phalcon/Mvc/Router/Annotations.zep", 324);
		if (Z_TYPE_P(&converts) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&converts), _9$$17, _10$$17, _7$$17)
			{
				ZEPHIR_INIT_NVAR(&param);
				if (_10$$17 != NULL) { 
					ZVAL_STR_COPY(&param, _10$$17);
				} else {
					ZVAL_LONG(&param, _9$$17);
				}
				ZEPHIR_INIT_NVAR(&convert);
				ZVAL_COPY(&convert, _7$$17);
				ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_11, 0, &param, &convert);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &converts, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_8$$17, &converts, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$17)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&param, &converts, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&convert, &converts, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_12, 0, &param, &convert);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &converts, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&convert);
		ZEPHIR_INIT_NVAR(&param);
	}
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "conversors");
	ZEPHIR_CALL_METHOD(&converts, annotation, "getnamedargument", NULL, 0, &_4);
	zephir_check_call_status();
	if (Z_TYPE_P(&converts) == IS_ARRAY) {
		zephir_is_iterable(&converts, 0, "phalcon/Mvc/Router/Annotations.zep", 335);
		if (Z_TYPE_P(&converts) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&converts), _15$$20, _16$$20, _13$$20)
			{
				ZEPHIR_INIT_NVAR(&conversorParam);
				if (_16$$20 != NULL) { 
					ZVAL_STR_COPY(&conversorParam, _16$$20);
				} else {
					ZVAL_LONG(&conversorParam, _15$$20);
				}
				ZEPHIR_INIT_NVAR(&convert);
				ZVAL_COPY(&convert, _13$$20);
				ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_17, 0, &conversorParam, &convert);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &converts, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_14$$20, &converts, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$20)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&conversorParam, &converts, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&convert, &converts, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_18, 0, &conversorParam, &convert);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &converts, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&convert);
		ZEPHIR_INIT_NVAR(&conversorParam);
	}
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "beforeMatch");
	ZEPHIR_CALL_METHOD(&beforeMatch, annotation, "getnamedargument", NULL, 0, &_4);
	zephir_check_call_status();
	_19 = Z_TYPE_P(&beforeMatch) == IS_ARRAY;
	if (!(_19)) {
		_19 = Z_TYPE_P(&beforeMatch) == IS_STRING;
	}
	if (_19) {
		ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "name");
	ZEPHIR_CALL_METHOD(&routeName, annotation, "getnamedargument", NULL, 0, &_4);
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &handler_param, &annotation);

	if (UNEXPECTED(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be of the type string") TSRMLS_CC);
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
		zephir_update_property_zval(this_ptr, SL("routePrefix"), &_1$$3);
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionSuffix_param);

	if (UNEXPECTED(Z_TYPE_P(actionSuffix_param) != IS_STRING && Z_TYPE_P(actionSuffix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionSuffix' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(actionSuffix_param) == IS_STRING)) {
		zephir_get_strval(&actionSuffix, actionSuffix_param);
	} else {
		ZEPHIR_INIT_VAR(&actionSuffix);
		ZVAL_EMPTY_STRING(&actionSuffix);
	}


	zephir_update_property_zval(this_ptr, SL("actionSuffix"), &actionSuffix);
	ZEPHIR_MM_RESTORE();

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerSuffix_param);

	if (UNEXPECTED(Z_TYPE_P(controllerSuffix_param) != IS_STRING && Z_TYPE_P(controllerSuffix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerSuffix' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerSuffix_param) == IS_STRING)) {
		zephir_get_strval(&controllerSuffix, controllerSuffix_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerSuffix);
		ZVAL_EMPTY_STRING(&controllerSuffix);
	}


	zephir_update_property_zval(this_ptr, SL("controllerSuffix"), &controllerSuffix);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Mvc_Router_Annotations(zend_class_entry *class_type TSRMLS_DC) {

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
		zephir_read_property(&_0, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("params"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("keyRouteIds"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("keyRouteIds"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("keyRouteNames"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("keyRouteNames"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("defaultParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("defaultParams"), &_7$$6);
		}
		zephir_read_property(&_8, this_ptr, SL("handlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval(this_ptr, SL("handlers"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

