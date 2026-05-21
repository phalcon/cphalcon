
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Annotations)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Router, Annotations, phalcon, mvc_router_annotations, phalcon_mvc_router_ce, phalcon_mvc_router_annotations_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("actionSuffix"), "Action", ZEND_ACC_PROTECTED);
	/**
	 * @var callable|string|null
	 */
	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("actionPreformatCallback"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("controllerSuffix"), "Controller", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("handlers"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("routePrefix"), "", ZEND_ACC_PROTECTED);
	phalcon_mvc_router_annotations_ce->create_object = zephir_init_properties_Phalcon_Mvc_Router_Annotations;

	return SUCCESS;
}

/**
 * Adds a resource to the annotations handler
 * A resource is a class that contains routing annotations
 * The class is located in a module
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addModuleResource)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval module_zv, handler_zv, prefix_zv;
	zend_string *module = NULL, *handler = NULL, *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&module_zv);
	ZVAL_UNDEF(&handler_zv);
	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(module)
		Z_PARAM_STR(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&module_zv);
	ZVAL_STR_COPY(&module_zv, module);
	zephir_memory_observe(&handler_zv);
	ZVAL_STR_COPY(&handler_zv, handler);
	if (!prefix) {
		ZEPHIR_INIT_VAR(&prefix_zv);
	} else {
	zephir_memory_observe(&prefix_zv);
	ZVAL_STR_COPY(&prefix_zv, prefix);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	zephir_array_fast_append(&_0, &prefix_zv);
	zephir_array_fast_append(&_0, &handler_zv);
	zephir_array_fast_append(&_0, &module_zv);
	zephir_update_property_array_append(this_ptr, SL("handlers"), &_0);
	RETURN_THIS();
}

/**
 * Adds a resource to the annotations handler
 * A resource is a class that contains routing annotations
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addResource)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval handler_zv, prefix_zv;
	zend_string *handler = NULL, *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_zv);
	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&handler_zv);
	ZVAL_STR_COPY(&handler_zv, handler);
	if (!prefix) {
		ZEPHIR_INIT_VAR(&prefix_zv);
	} else {
	zephir_memory_observe(&prefix_zv);
	ZVAL_STR_COPY(&prefix_zv, prefix);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, &prefix_zv);
	zephir_array_fast_append(&_0, &handler_zv);
	zephir_update_property_array_append(this_ptr, SL("handlers"), &_0);
	RETURN_THIS();
}

/**
 * Return the registered resources
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, getResources)
{

	RETURN_MEMBER_TYPED(getThis(), "handlers", IS_ARRAY);
}

/**
 * Produce the routing parameters from the rewrite information
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, handle)
{
	zend_ulong _23$$19, _47$$43;
	zval sufixed;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_17 = NULL, *_20 = NULL, *_28 = NULL, *_42 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, __$null, annotationsService, handlers, controllerSuffix, scope, prefix, route, compiledPattern, container, handler, controllerName, lowerControllerName, namespaceName, moduleName, handlerAnnotations, classAnnotations, annotations, annotation, methodAnnotations, method, collection, _0, _2, *_3, _4, _1$$3, _6$$6, _8$$6, _9$$6, _10$$7, _11$$7, _12$$11, _13$$11, _14$$11, _15$$4, _16$$13, *_18$$16, _19$$16, *_21$$19, _22$$19, _25$$20, *_26$$20, _27$$20, _29$$24, *_30$$24, _31$$24, _32$$30, _33$$30, _34$$30, _35$$31, _36$$31, _37$$35, _38$$35, _39$$35, _40$$28, _41$$37, *_43$$40, _44$$40, *_45$$43, _46$$43, _49$$44, *_50$$44, _51$$44, _52$$48, *_53$$48, _54$$48;
	zend_string *uri = NULL, *_24$$19, *_48$$43;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_zv);
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_27$$20);
	ZVAL_UNDEF(&_29$$24);
	ZVAL_UNDEF(&_31$$24);
	ZVAL_UNDEF(&_32$$30);
	ZVAL_UNDEF(&_33$$30);
	ZVAL_UNDEF(&_34$$30);
	ZVAL_UNDEF(&_35$$31);
	ZVAL_UNDEF(&_36$$31);
	ZVAL_UNDEF(&_37$$35);
	ZVAL_UNDEF(&_38$$35);
	ZVAL_UNDEF(&_39$$35);
	ZVAL_UNDEF(&_40$$28);
	ZVAL_UNDEF(&_41$$37);
	ZVAL_UNDEF(&_44$$40);
	ZVAL_UNDEF(&_46$$43);
	ZVAL_UNDEF(&_49$$44);
	ZVAL_UNDEF(&_51$$44);
	ZVAL_UNDEF(&_52$$48);
	ZVAL_UNDEF(&_54$$48);
	ZVAL_UNDEF(&sufixed);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_router_exceptions_annotationsserviceunavailable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Router/Annotations.zep", 114);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handlers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&handlers, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("controllerSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&controllerSuffix, &_0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "annotations");
	ZEPHIR_CALL_METHOD(&annotationsService, &container, "getshared", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_is_iterable(&handlers, 0, "phalcon/Mvc/Router/Annotations.zep", 262);
	if (Z_TYPE_P(&handlers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handlers), _3)
		{
			ZEPHIR_INIT_NVAR(&scope);
			ZVAL_COPY(&scope, _3);
			if (Z_TYPE_P(&scope) != IS_ARRAY) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&prefix);
			zephir_array_fetch_long(&prefix, &scope, 0, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 129);
			if (!(ZEPHIR_IS_EMPTY(&prefix))) {
				ZEPHIR_INIT_NVAR(&route);
				object_init_ex(&route, phalcon_mvc_router_route_ce);
				ZEPHIR_CALL_METHOD(NULL, &route, "__construct", &_5, 182, &prefix);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$6, &route, "getcompiledpattern", &_7, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_8$$6);
				ZVAL_STRING(&_8$$6, "$#");
				ZEPHIR_INIT_NVAR(&_9$$6);
				ZVAL_STRING(&_9$$6, "#");
				ZEPHIR_INIT_NVAR(&compiledPattern);
				zephir_fast_str_replace(&compiledPattern, &_8$$6, &_9$$6, &_6$$6);
				if (zephir_memnstr_str(&compiledPattern, SL("^"), "phalcon/Mvc/Router/Annotations.zep", 146)) {
					ZEPHIR_INIT_NVAR(&_10$$7);
					ZEPHIR_INIT_NVAR(&_11$$7);
					zephir_preg_match(&_11$$7, &compiledPattern, &uri_zv, &_10$$7, 0, 0 , 0 );
					if (!(zephir_is_true(&_11$$7))) {
						continue;
					}
				} else if (!(zephir_start_with(&uri_zv, &prefix, NULL))) {
					continue;
				}
			}
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch_long(&handler, &scope, 1, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 161);
			if (zephir_memnstr_str(&handler, SL("\\"), "phalcon/Mvc/Router/Annotations.zep", 163)) {
				ZEPHIR_INIT_NVAR(&controllerName);
				zephir_get_class_ns(&controllerName, &handler, 0);
				ZEPHIR_INIT_NVAR(&namespaceName);
				zephir_get_ns_class(&namespaceName, &handler, 0);
				if (zephir_end_with(&controllerName, &controllerSuffix, NULL)) {
					ZVAL_LONG(&_12$$11, 0);
					ZVAL_LONG(&_13$$11, (zephir_fast_strlen_ev(&controllerName) - zephir_fast_strlen_ev(&controllerSuffix)));
					ZEPHIR_INIT_NVAR(&_14$$11);
					zephir_substr(&_14$$11, &controllerName, 0 , zephir_get_intval(&_13$$11), 0);
					ZEPHIR_CPY_WRT(&controllerName, &_14$$11);
				}
			} else {
				ZEPHIR_CPY_WRT(&controllerName, &handler);
				ZEPHIR_OBS_NVAR(&namespaceName);
				zephir_fetch_property(&namespaceName, this_ptr, SL("defaultNamespace"), PH_SILENT_CC);
			}
			zephir_update_property_zval(this_ptr, ZEND_STRL("routePrefix"), &__$null);
			ZEPHIR_OBS_NVAR(&moduleName);
			zephir_array_isset_long_fetch(&moduleName, &scope, 2, 0);
			ZEPHIR_INIT_NVAR(&_15$$4);
			if (Z_TYPE_P(&moduleName) != IS_NULL) {
				ZEPHIR_CPY_WRT(&_15$$4, &moduleName);
			} else {
				ZEPHIR_INIT_NVAR(&_15$$4);
				ZVAL_STRING(&_15$$4, "");
			}
			ZEPHIR_CPY_WRT(&moduleName, &_15$$4);
			ZEPHIR_INIT_NVAR(&_15$$4);
			ZEPHIR_CONCAT_VV(&_15$$4, &controllerName, &controllerSuffix);
			zephir_get_strval(&sufixed, &_15$$4);
			if (Z_TYPE_P(&namespaceName) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_16$$13);
				ZEPHIR_CONCAT_VSV(&_16$$13, &namespaceName, "\\", &sufixed);
				zephir_get_strval(&sufixed, &_16$$13);
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
					zephir_is_iterable(&annotations, 0, "phalcon/Mvc/Router/Annotations.zep", 230);
					if (Z_TYPE_P(&annotations) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&annotations), _18$$16)
						{
							ZEPHIR_INIT_NVAR(&annotation);
							ZVAL_COPY(&annotation, _18$$16);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_20, 0, &controllerName, &annotation);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &annotations, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_19$$16, &annotations, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_19$$16)) {
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
				zephir_uncamelize(&lowerControllerName, &controllerName, NULL );
				zephir_is_iterable(&methodAnnotations, 0, "phalcon/Mvc/Router/Annotations.zep", 256);
				if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methodAnnotations), _23$$19, _24$$19, _21$$19)
					{
						ZEPHIR_INIT_NVAR(&method);
						if (_24$$19 != NULL) { 
							ZVAL_STR_COPY(&method, _24$$19);
						} else {
							ZVAL_LONG(&method, _23$$19);
						}
						ZEPHIR_INIT_NVAR(&collection);
						ZVAL_COPY(&collection, _21$$19);
						if (Z_TYPE_P(&collection) != IS_OBJECT) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&_25$$20, &collection, "getannotations", NULL, 0);
						zephir_check_call_status();
						zephir_is_iterable(&_25$$20, 0, "phalcon/Mvc/Router/Annotations.zep", 255);
						if (Z_TYPE_P(&_25$$20) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_25$$20), _26$$20)
							{
								ZEPHIR_INIT_NVAR(&annotation);
								ZVAL_COPY(&annotation, _26$$20);
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_25$$20, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_27$$20, &_25$$20, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_27$$20)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&annotation, &_25$$20, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
									zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &_25$$20, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&annotation);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &methodAnnotations, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_22$$19, &methodAnnotations, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_22$$19)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&method, &methodAnnotations, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&collection, &methodAnnotations, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&collection) != IS_OBJECT) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&_29$$24, &collection, "getannotations", NULL, 0);
							zephir_check_call_status();
							zephir_is_iterable(&_29$$24, 0, "phalcon/Mvc/Router/Annotations.zep", 255);
							if (Z_TYPE_P(&_29$$24) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_29$$24), _30$$24)
								{
									ZEPHIR_INIT_NVAR(&annotation);
									ZVAL_COPY(&annotation, _30$$24);
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_29$$24, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_31$$24, &_29$$24, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_31$$24)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&annotation, &_29$$24, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &_29$$24, "next", NULL, 0);
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
			ZEPHIR_CALL_METHOD(&_4, &handlers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&scope, &handlers, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&scope) != IS_ARRAY) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&prefix);
				zephir_array_fetch_long(&prefix, &scope, 0, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 129);
				if (!(ZEPHIR_IS_EMPTY(&prefix))) {
					ZEPHIR_INIT_NVAR(&route);
					object_init_ex(&route, phalcon_mvc_router_route_ce);
					ZEPHIR_CALL_METHOD(NULL, &route, "__construct", &_5, 182, &prefix);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_32$$30, &route, "getcompiledpattern", &_7, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_33$$30);
					ZVAL_STRING(&_33$$30, "$#");
					ZEPHIR_INIT_NVAR(&_34$$30);
					ZVAL_STRING(&_34$$30, "#");
					ZEPHIR_INIT_NVAR(&compiledPattern);
					zephir_fast_str_replace(&compiledPattern, &_33$$30, &_34$$30, &_32$$30);
					if (zephir_memnstr_str(&compiledPattern, SL("^"), "phalcon/Mvc/Router/Annotations.zep", 146)) {
						ZEPHIR_INIT_NVAR(&_35$$31);
						ZEPHIR_INIT_NVAR(&_36$$31);
						zephir_preg_match(&_36$$31, &compiledPattern, &uri_zv, &_35$$31, 0, 0 , 0 );
						if (!(zephir_is_true(&_36$$31))) {
							continue;
						}
					} else if (!(zephir_start_with(&uri_zv, &prefix, NULL))) {
						continue;
					}
				}
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_long(&handler, &scope, 1, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 161);
				if (zephir_memnstr_str(&handler, SL("\\"), "phalcon/Mvc/Router/Annotations.zep", 163)) {
					ZEPHIR_INIT_NVAR(&controllerName);
					zephir_get_class_ns(&controllerName, &handler, 0);
					ZEPHIR_INIT_NVAR(&namespaceName);
					zephir_get_ns_class(&namespaceName, &handler, 0);
					if (zephir_end_with(&controllerName, &controllerSuffix, NULL)) {
						ZVAL_LONG(&_37$$35, 0);
						ZVAL_LONG(&_38$$35, (zephir_fast_strlen_ev(&controllerName) - zephir_fast_strlen_ev(&controllerSuffix)));
						ZEPHIR_INIT_NVAR(&_39$$35);
						zephir_substr(&_39$$35, &controllerName, 0 , zephir_get_intval(&_38$$35), 0);
						ZEPHIR_CPY_WRT(&controllerName, &_39$$35);
					}
				} else {
					ZEPHIR_CPY_WRT(&controllerName, &handler);
					ZEPHIR_OBS_NVAR(&namespaceName);
					zephir_fetch_property(&namespaceName, this_ptr, SL("defaultNamespace"), PH_SILENT_CC);
				}
				zephir_update_property_zval(this_ptr, ZEND_STRL("routePrefix"), &__$null);
				ZEPHIR_OBS_NVAR(&moduleName);
				zephir_array_isset_long_fetch(&moduleName, &scope, 2, 0);
				ZEPHIR_INIT_NVAR(&_40$$28);
				if (Z_TYPE_P(&moduleName) != IS_NULL) {
					ZEPHIR_CPY_WRT(&_40$$28, &moduleName);
				} else {
					ZEPHIR_INIT_NVAR(&_40$$28);
					ZVAL_STRING(&_40$$28, "");
				}
				ZEPHIR_CPY_WRT(&moduleName, &_40$$28);
				ZEPHIR_INIT_NVAR(&_40$$28);
				ZEPHIR_CONCAT_VV(&_40$$28, &controllerName, &controllerSuffix);
				zephir_get_strval(&sufixed, &_40$$28);
				if (Z_TYPE_P(&namespaceName) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_41$$37);
					ZEPHIR_CONCAT_VSV(&_41$$37, &namespaceName, "\\", &sufixed);
					zephir_get_strval(&sufixed, &_41$$37);
				}
				ZEPHIR_CALL_METHOD(&handlerAnnotations, &annotationsService, "get", &_42, 0, &sufixed);
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
						zephir_is_iterable(&annotations, 0, "phalcon/Mvc/Router/Annotations.zep", 230);
						if (Z_TYPE_P(&annotations) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&annotations), _43$$40)
							{
								ZEPHIR_INIT_NVAR(&annotation);
								ZVAL_COPY(&annotation, _43$$40);
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_20, 0, &controllerName, &annotation);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &annotations, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_44$$40, &annotations, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_44$$40)) {
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
					zephir_uncamelize(&lowerControllerName, &controllerName, NULL );
					zephir_is_iterable(&methodAnnotations, 0, "phalcon/Mvc/Router/Annotations.zep", 256);
					if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methodAnnotations), _47$$43, _48$$43, _45$$43)
						{
							ZEPHIR_INIT_NVAR(&method);
							if (_48$$43 != NULL) { 
								ZVAL_STR_COPY(&method, _48$$43);
							} else {
								ZVAL_LONG(&method, _47$$43);
							}
							ZEPHIR_INIT_NVAR(&collection);
							ZVAL_COPY(&collection, _45$$43);
							if (Z_TYPE_P(&collection) != IS_OBJECT) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&_49$$44, &collection, "getannotations", NULL, 0);
							zephir_check_call_status();
							zephir_is_iterable(&_49$$44, 0, "phalcon/Mvc/Router/Annotations.zep", 255);
							if (Z_TYPE_P(&_49$$44) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_49$$44), _50$$44)
								{
									ZEPHIR_INIT_NVAR(&annotation);
									ZVAL_COPY(&annotation, _50$$44);
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_49$$44, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_51$$44, &_49$$44, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_51$$44)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&annotation, &_49$$44, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &_49$$44, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&annotation);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &methodAnnotations, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_46$$43, &methodAnnotations, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_46$$43)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&method, &methodAnnotations, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&collection, &methodAnnotations, "current", NULL, 0);
							zephir_check_call_status();
								if (Z_TYPE_P(&collection) != IS_OBJECT) {
									continue;
								}
								ZEPHIR_CALL_METHOD(&_52$$48, &collection, "getannotations", NULL, 0);
								zephir_check_call_status();
								zephir_is_iterable(&_52$$48, 0, "phalcon/Mvc/Router/Annotations.zep", 255);
								if (Z_TYPE_P(&_52$$48) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_52$$48), _53$$48)
									{
										ZEPHIR_INIT_NVAR(&annotation);
										ZVAL_COPY(&annotation, _53$$48);
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &_52$$48, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_54$$48, &_52$$48, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_54$$48)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&annotation, &_52$$48, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_28, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
											zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, &_52$$48, "next", NULL, 0);
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
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_router_annotations_ce, getThis(), "handle", NULL, 0, &uri_zv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks for annotations in the public methods of the controller
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processActionAnnotation)
{
	zend_ulong _11$$18, _17$$21;
	zend_bool isRoute = 0, _8, _21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_14 = NULL, *_19 = NULL, *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval module_zv, namespaceName_zv, controller_zv, action_zv, *annotation, annotation_sub, name, proxyActionName, actionName, routePrefix, paths, value, uri, route, methods, converts, param, convert, converterParam, routeName, beforeMatch, _0, _1, _2, _5, _6, _3$$6, _4$$6, _7$$16, *_9$$18, _10$$18, *_15$$21, _16$$21;
	zend_string *module = NULL, *namespaceName = NULL, *controller = NULL, *action = NULL, *_12$$18, *_18$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&module_zv);
	ZVAL_UNDEF(&namespaceName_zv);
	ZVAL_UNDEF(&controller_zv);
	ZVAL_UNDEF(&action_zv);
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
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_STR(module)
		Z_PARAM_STR(namespaceName)
		Z_PARAM_STR(controller)
		Z_PARAM_STR(action)
		Z_PARAM_OBJECT_OF_CLASS(annotation, phalcon_annotations_annotation_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	annotation = ZEND_CALL_ARG(execute_data, 5);
	zephir_memory_observe(&module_zv);
	ZVAL_STR_COPY(&module_zv, module);
	zephir_memory_observe(&namespaceName_zv);
	ZVAL_STR_COPY(&namespaceName_zv, namespaceName);
	zephir_memory_observe(&controller_zv);
	ZVAL_STR_COPY(&controller_zv, controller);
	zephir_memory_observe(&action_zv);
	ZVAL_STR_COPY(&action_zv, action);
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
	zephir_fast_str_replace(&proxyActionName, &_0, &_1, &action_zv);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("routePrefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&routePrefix, &_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("actionPreformatCallback"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_2) != IS_NULL) {
		zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("actionPreformatCallback"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_4$$6, "call_user_func", NULL, 292, &_3$$6, &proxyActionName);
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
	if (!(ZEPHIR_IS_EMPTY(&module_zv))) {
		zephir_array_update_string(&paths, SL("module"), &module_zv, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(&namespaceName_zv))) {
		zephir_array_update_string(&paths, SL("namespace"), &namespaceName_zv, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_string(&paths, SL("controller"), &controller_zv, PH_COPY | PH_SEPARATE);
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
		zephir_is_iterable(&converts, 0, "phalcon/Mvc/Router/Annotations.zep", 385);
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
		zephir_is_iterable(&converts, 0, "phalcon/Mvc/Router/Annotations.zep", 396);
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
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks for annotations in the controller docblock
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processControllerAnnotation)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval handler_zv, *annotation, annotation_sub, _0, _1$$3, _2$$3;
	zend_string *handler = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_zv);
	ZVAL_UNDEF(&annotation_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(handler)
		Z_PARAM_OBJECT_OF_CLASS(annotation, phalcon_annotations_annotation_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	annotation = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&handler_zv);
	ZVAL_STR_COPY(&handler_zv, handler);
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
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setActionSuffix)
{
	zval actionSuffix_zv;
	zend_string *actionSuffix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionSuffix_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionSuffix)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&actionSuffix_zv, actionSuffix);
	zephir_update_property_zval(this_ptr, ZEND_STRL("actionSuffix"), &actionSuffix_zv);
	RETURN_THISW();
}

/**
 * Sets the action preformat callback
 * $action here already without suffix 'Action'
 *
 * ```php
 * // Array as callback
 * $annotationRouter->setActionPreformatCallback(
 *      [
 *          new Uncamelize(),
 *          '__invoke'
 *      ]
 *  );
 *
 * // Function as callback
 * $annotationRouter->setActionPreformatCallback(
 *     function ($action) {
 *         return $action;
 *     }
 * );
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
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setActionPreformatCallback)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback = NULL, callback_sub, __$null, _0$$4, _1$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(callback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		zephir_create_closure_ex(&_0$$4, NULL, phalcon_79__closure_ce, SL("__invoke"));
		zephir_update_property_zval(this_ptr, ZEND_STRL("actionPreformatCallback"), &_0$$4);
	} else {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, phalcon_mvc_router_exceptions_invalidcallbackparameter_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "phalcon/Mvc/Router/Annotations.zep", 475);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * @return callable|string|null
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, getActionPreformatCallback)
{

	RETURN_MEMBER(getThis(), "actionPreformatCallback");
}

/**
 * Changes the controller class suffix
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setControllerSuffix)
{
	zval controllerSuffix_zv;
	zend_string *controllerSuffix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerSuffix_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(controllerSuffix)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&controllerSuffix_zv, controllerSuffix);
	zephir_update_property_zval(this_ptr, ZEND_STRL("controllerSuffix"), &controllerSuffix_zv);
	RETURN_THISW();
}

zend_object *zephir_init_properties_Phalcon_Mvc_Router_Annotations(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _12, _14, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9, _15$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$10);
	

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
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("methodRoutes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("methodRoutes"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("matches"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("matches"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("keyRouteIds"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("keyRouteIds"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("keyRouteNames"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("keyRouteNames"), &_11$$8);
		}
		zephir_read_property_ex(&_12, this_ptr, ZEND_STRL("defaultParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("defaultParams"), &_13$$9);
		}
		zephir_read_property_ex(&_14, this_ptr, ZEND_STRL("handlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_14) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_15$$10);
			array_init(&_15$$10);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("handlers"), &_15$$10);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

