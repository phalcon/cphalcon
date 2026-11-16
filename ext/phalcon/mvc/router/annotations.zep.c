
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
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
 *         // This will do the same as above but only if the handled uri starts with /invoices
 *         $router->addResource("Invoices", "/invoices");
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
	 *
	 * @phpstan-var callable|string|null
	 */
	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("actionPreformatCallback"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("controllerSuffix"), "Controller", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 *
	 * @phpstan-var list<array{0: string|null, 1: string, 2?: string}>
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
 *
 * @phpstan-return static
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Adds a resource to the annotations handler
 * A resource is a class that contains routing annotations
 *
 * @phpstan-return static
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Return the registered resources
 *
 * @phpstan-return list<array{0: string|null, 1: string, 2?: string}>
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
	zend_ulong _24$$19, _61$$43;
	zend_bool _41, _13$$4, _20$$16, _33$$19, _31$$20, _39$$24, _50$$28, _57$$40, _70$$43, _68$$44, _76$$48;
	zval sufixed;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, __$null, annotationsService, handlers, controllerSuffix, scope, prefix, route, compiledPattern, container, handler, controllerName, lowerControllerName, namespaceName, moduleName, handlerAnnotations, classAnnotations, annotations, annotation, methodAnnotations, method, collection, _0, _2, *_3, *_4, _40, _1$$3, _5$$6, _6$$6, _7$$6, _8$$7, _9$$7, _10$$11, _11$$11, _12$$11, _14$$4, _15$$13, *_16$$16, _17$$16, *_18$$16, _19$$16, *_21$$19, _22$$19, *_23$$19, _32$$19, _26$$20, *_27$$20, _28$$20, *_29$$20, _30$$20, _34$$24, *_35$$24, _36$$24, *_37$$24, _38$$24, _42$$30, _43$$30, _44$$30, _45$$31, _46$$31, _47$$35, _48$$35, _49$$35, _51$$28, _52$$37, *_53$$40, _54$$40, *_55$$40, _56$$40, *_58$$43, _59$$43, *_60$$43, _69$$43, _63$$44, *_64$$44, _65$$44, *_66$$44, _67$$44, _71$$48, *_72$$48, _73$$48, *_74$$48, _75$$48;
	zend_string *uri = NULL, *_25$$19, *_62$$43;
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
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_32$$19);
	ZVAL_UNDEF(&_26$$20);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_34$$24);
	ZVAL_UNDEF(&_36$$24);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_42$$30);
	ZVAL_UNDEF(&_43$$30);
	ZVAL_UNDEF(&_44$$30);
	ZVAL_UNDEF(&_45$$31);
	ZVAL_UNDEF(&_46$$31);
	ZVAL_UNDEF(&_47$$35);
	ZVAL_UNDEF(&_48$$35);
	ZVAL_UNDEF(&_49$$35);
	ZVAL_UNDEF(&_51$$28);
	ZVAL_UNDEF(&_52$$37);
	ZVAL_UNDEF(&_54$$40);
	ZVAL_UNDEF(&_56$$40);
	ZVAL_UNDEF(&_59$$43);
	ZVAL_UNDEF(&_69$$43);
	ZVAL_UNDEF(&_63$$44);
	ZVAL_UNDEF(&_65$$44);
	ZVAL_UNDEF(&_67$$44);
	ZVAL_UNDEF(&_71$$48);
	ZVAL_UNDEF(&_73$$48);
	ZVAL_UNDEF(&_75$$48);
	ZVAL_UNDEF(&sufixed);
	ZEND_TLS zephir_method_cache _zephir_call_cache[69];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("handlers", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("controllerSuffix", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("routePrefix", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1157, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_router_exceptions_annotationsserviceunavailable_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Router/Annotations.zep", 124);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1158, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&handlers, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1159, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&controllerSuffix, &_0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "annotations");
	ZEPHIR_CALL_METHOD_CACHED(&annotationsService, &container, "getShared", &_zephir_call_cache[1], &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&handlers) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_2);
		zephir_string_to_char_array(&_2, &handlers);
		_3 = &_2;
	} else {
		_3 = &handlers;
	}
	zephir_is_iterable(_3, 0, "phalcon/Mvc/Router/Annotations.zep", 272);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _4)
		{
			ZEPHIR_INIT_NVAR(&scope);
			ZVAL_COPY(&scope, _4);
			if (Z_TYPE_P(&scope) != IS_ARRAY) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&prefix);
			zephir_array_fetch_long(&prefix, &scope, 0, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 139);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(ZEPHIR_IS_EMPTY(&prefix))) {
				ZEPHIR_INIT_NVAR(&route);
				object_init_ex(&route, phalcon_mvc_router_route_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "__construct", &_zephir_call_cache[2], &prefix);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_5$$6, &route, "getCompiledPattern", &_zephir_call_cache[3]);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$6);
				ZVAL_STRING(&_6$$6, "$#");
				ZEPHIR_INIT_NVAR(&_7$$6);
				ZVAL_STRING(&_7$$6, "#");
				ZEPHIR_INIT_NVAR(&compiledPattern);
				zephir_fast_str_replace(&compiledPattern, &_6$$6, &_7$$6, &_5$$6);
				if (zephir_memnstr_str(&compiledPattern, SL("^"), "phalcon/Mvc/Router/Annotations.zep", 156)) {
					ZEPHIR_INIT_NVAR(&_8$$7);
					ZEPHIR_INIT_NVAR(&_9$$7);
					zephir_preg_match(&_9$$7, &compiledPattern, &uri_zv, &_8$$7, 0, 0 , 0 );
					if (!(zephir_is_true(&_9$$7))) {
						continue;
					}
				} else if (!(zephir_start_with(&uri_zv, &prefix, NULL))) {
					continue;
				}
			}
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch_long(&handler, &scope, 1, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 171);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_memnstr_str(&handler, SL("\\"), "phalcon/Mvc/Router/Annotations.zep", 173)) {
				ZEPHIR_INIT_NVAR(&controllerName);
				zephir_get_class_ns(&controllerName, &handler, 0);
				ZEPHIR_INIT_NVAR(&namespaceName);
				zephir_get_ns_class(&namespaceName, &handler, 0);
				if (zephir_end_with(&controllerName, &controllerSuffix, NULL)) {
					ZVAL_LONG(&_10$$11, 0);
					ZVAL_LONG(&_11$$11, (zephir_fast_strlen_ev(&controllerName) - zephir_fast_strlen_ev(&controllerSuffix)));
					ZEPHIR_INIT_NVAR(&_12$$11);
					zephir_substr(&_12$$11, &controllerName, 0 , zephir_get_intval(&_11$$11), 0);
					ZEPHIR_CPY_WRT(&controllerName, &_12$$11);
				}
			} else {
				ZEPHIR_CPY_WRT(&controllerName, &handler);
				ZEPHIR_OBS_NVAR(&namespaceName);
				zephir_fetch_property(&namespaceName, this_ptr, SL("defaultNamespace"), PH_SILENT_CC);
			}
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1160, &__$null);
			ZEPHIR_OBS_NVAR(&moduleName);
			_13$$4 = zephir_array_isset_long_fetch(&moduleName, &scope, 2, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_13$$4;
			ZEPHIR_INIT_NVAR(&_14$$4);
			if (Z_TYPE_P(&moduleName) != IS_NULL) {
				ZEPHIR_CPY_WRT(&_14$$4, &moduleName);
			} else {
				ZEPHIR_INIT_NVAR(&_14$$4);
				ZVAL_STRING(&_14$$4, "");
			}
			ZEPHIR_CPY_WRT(&moduleName, &_14$$4);
			ZEPHIR_INIT_NVAR(&_14$$4);
			ZEPHIR_CONCAT_VV(&_14$$4, &controllerName, &controllerSuffix);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_get_strval(&sufixed, &_14$$4);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&namespaceName) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_15$$13);
				ZEPHIR_CONCAT_VSV(&_15$$13, &namespaceName, "\\", &sufixed);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_get_strval(&sufixed, &_15$$13);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_CALL_METHOD_CACHED(&handlerAnnotations, &annotationsService, "get", &_zephir_call_cache[4], &sufixed);
			zephir_check_call_status();
			if (Z_TYPE_P(&handlerAnnotations) != IS_OBJECT) {
				continue;
			}
			ZEPHIR_CALL_METHOD_CACHED(&classAnnotations, &handlerAnnotations, "getClassAnnotations", &_zephir_call_cache[5]);
			zephir_check_call_status();
			if (Z_TYPE_P(&classAnnotations) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD_CACHED(&annotations, &classAnnotations, "getAnnotations", &_zephir_call_cache[6]);
				zephir_check_call_status();
				if (Z_TYPE_P(&annotations) == IS_ARRAY) {
					if (Z_TYPE_P(&annotations) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_17$$16);
						zephir_string_to_char_array(&_17$$16, &annotations);
						_16$$16 = &_17$$16;
					} else {
						_16$$16 = &annotations;
					}
					zephir_is_iterable(_16$$16, 0, "phalcon/Mvc/Router/Annotations.zep", 240);
					if (Z_TYPE_P(_16$$16) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_16$$16), _18$$16)
						{
							ZEPHIR_INIT_NVAR(&annotation);
							ZVAL_COPY(&annotation, _18$$16);
							ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processControllerAnnotation", &_zephir_call_cache[7], &controllerName, &annotation);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _16$$16, "rewind", &_zephir_call_cache[8]);
						zephir_check_call_status();
						_20$$16 = 1;
						while (1) {
							if (_20$$16) {
								_20$$16 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _16$$16, "next", &_zephir_call_cache[9]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_19$$16, _16$$16, "valid", &_zephir_call_cache[10]);
							zephir_check_call_status();
							if (!zend_is_true(&_19$$16)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&annotation, _16$$16, "current", &_zephir_call_cache[11]);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processControllerAnnotation", &_zephir_call_cache[12], &controllerName, &annotation);
								zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&annotation);
				}
			}
			ZEPHIR_CALL_METHOD_CACHED(&methodAnnotations, &handlerAnnotations, "getMethodsAnnotations", &_zephir_call_cache[13]);
			zephir_check_call_status();
			if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&lowerControllerName);
				zephir_uncamelize(&lowerControllerName, &controllerName, NULL );
				if (Z_TYPE_P(&methodAnnotations) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_22$$19);
					zephir_string_to_char_array(&_22$$19, &methodAnnotations);
					_21$$19 = &_22$$19;
				} else {
					_21$$19 = &methodAnnotations;
				}
				zephir_is_iterable(_21$$19, 0, "phalcon/Mvc/Router/Annotations.zep", 266);
				if (Z_TYPE_P(_21$$19) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_21$$19), _24$$19, _25$$19, _23$$19)
					{
						ZEPHIR_INIT_NVAR(&method);
						if (_25$$19 != NULL) { 
							ZVAL_STR_COPY(&method, _25$$19);
						} else {
							ZVAL_LONG(&method, _24$$19);
						}
						ZEPHIR_INIT_NVAR(&collection);
						ZVAL_COPY(&collection, _23$$19);
						if (Z_TYPE_P(&collection) != IS_OBJECT) {
							continue;
						}
						ZEPHIR_CALL_METHOD_CACHED(&_26$$20, &collection, "getAnnotations", &_zephir_call_cache[14]);
						zephir_check_call_status();
						if (Z_TYPE_P(&_26$$20) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_28$$20);
							zephir_string_to_char_array(&_28$$20, &_26$$20);
							_27$$20 = &_28$$20;
						} else {
							_27$$20 = &_26$$20;
						}
						zephir_is_iterable(_27$$20, 0, "phalcon/Mvc/Router/Annotations.zep", 265);
						if (Z_TYPE_P(_27$$20) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_27$$20), _29$$20)
							{
								ZEPHIR_INIT_NVAR(&annotation);
								ZVAL_COPY(&annotation, _29$$20);
								ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processActionAnnotation", &_zephir_call_cache[15], &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _27$$20, "rewind", &_zephir_call_cache[16]);
							zephir_check_call_status();
							_31$$20 = 1;
							while (1) {
								if (_31$$20) {
									_31$$20 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _27$$20, "next", &_zephir_call_cache[17]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_30$$20, _27$$20, "valid", &_zephir_call_cache[18]);
								zephir_check_call_status();
								if (!zend_is_true(&_30$$20)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&annotation, _27$$20, "current", &_zephir_call_cache[19]);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processActionAnnotation", &_zephir_call_cache[20], &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
									zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&annotation);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _21$$19, "rewind", &_zephir_call_cache[21]);
					zephir_check_call_status();
					_33$$19 = 1;
					while (1) {
						if (_33$$19) {
							_33$$19 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _21$$19, "next", &_zephir_call_cache[22]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_32$$19, _21$$19, "valid", &_zephir_call_cache[23]);
						zephir_check_call_status();
						if (!zend_is_true(&_32$$19)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&method, _21$$19, "key", &_zephir_call_cache[24]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&collection, _21$$19, "current", &_zephir_call_cache[25]);
						zephir_check_call_status();
							if (Z_TYPE_P(&collection) != IS_OBJECT) {
								continue;
							}
							ZEPHIR_CALL_METHOD_CACHED(&_34$$24, &collection, "getAnnotations", &_zephir_call_cache[26]);
							zephir_check_call_status();
							if (Z_TYPE_P(&_34$$24) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_36$$24);
								zephir_string_to_char_array(&_36$$24, &_34$$24);
								_35$$24 = &_36$$24;
							} else {
								_35$$24 = &_34$$24;
							}
							zephir_is_iterable(_35$$24, 0, "phalcon/Mvc/Router/Annotations.zep", 265);
							if (Z_TYPE_P(_35$$24) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_35$$24), _37$$24)
								{
									ZEPHIR_INIT_NVAR(&annotation);
									ZVAL_COPY(&annotation, _37$$24);
									ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processActionAnnotation", &_zephir_call_cache[27], &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _35$$24, "rewind", &_zephir_call_cache[28]);
								zephir_check_call_status();
								_39$$24 = 1;
								while (1) {
									if (_39$$24) {
										_39$$24 = 0;
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _35$$24, "next", &_zephir_call_cache[29]);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD_CACHED(&_38$$24, _35$$24, "valid", &_zephir_call_cache[30]);
									zephir_check_call_status();
									if (!zend_is_true(&_38$$24)) {
										break;
									}
									ZEPHIR_CALL_METHOD_CACHED(&annotation, _35$$24, "current", &_zephir_call_cache[31]);
									zephir_check_call_status();
										ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processActionAnnotation", &_zephir_call_cache[32], &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&annotation);
					}
				}
				ZEPHIR_INIT_NVAR(&collection);
				ZEPHIR_INIT_NVAR(&method);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "rewind", &_zephir_call_cache[33]);
		zephir_check_call_status();
		_41 = 1;
		while (1) {
			if (_41) {
				_41 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "next", &_zephir_call_cache[34]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_40, _3, "valid", &_zephir_call_cache[35]);
			zephir_check_call_status();
			if (!zend_is_true(&_40)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&scope, _3, "current", &_zephir_call_cache[36]);
			zephir_check_call_status();
				if (Z_TYPE_P(&scope) != IS_ARRAY) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&prefix);
				zephir_array_fetch_long(&prefix, &scope, 0, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 139);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(ZEPHIR_IS_EMPTY(&prefix))) {
					ZEPHIR_INIT_NVAR(&route);
					object_init_ex(&route, phalcon_mvc_router_route_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "__construct", &_zephir_call_cache[37], &prefix);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_42$$30, &route, "getCompiledPattern", &_zephir_call_cache[38]);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_43$$30);
					ZVAL_STRING(&_43$$30, "$#");
					ZEPHIR_INIT_NVAR(&_44$$30);
					ZVAL_STRING(&_44$$30, "#");
					ZEPHIR_INIT_NVAR(&compiledPattern);
					zephir_fast_str_replace(&compiledPattern, &_43$$30, &_44$$30, &_42$$30);
					if (zephir_memnstr_str(&compiledPattern, SL("^"), "phalcon/Mvc/Router/Annotations.zep", 156)) {
						ZEPHIR_INIT_NVAR(&_45$$31);
						ZEPHIR_INIT_NVAR(&_46$$31);
						zephir_preg_match(&_46$$31, &compiledPattern, &uri_zv, &_45$$31, 0, 0 , 0 );
						if (!(zephir_is_true(&_46$$31))) {
							continue;
						}
					} else if (!(zephir_start_with(&uri_zv, &prefix, NULL))) {
						continue;
					}
				}
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_long(&handler, &scope, 1, PH_NOISY, "phalcon/Mvc/Router/Annotations.zep", 171);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_memnstr_str(&handler, SL("\\"), "phalcon/Mvc/Router/Annotations.zep", 173)) {
					ZEPHIR_INIT_NVAR(&controllerName);
					zephir_get_class_ns(&controllerName, &handler, 0);
					ZEPHIR_INIT_NVAR(&namespaceName);
					zephir_get_ns_class(&namespaceName, &handler, 0);
					if (zephir_end_with(&controllerName, &controllerSuffix, NULL)) {
						ZVAL_LONG(&_47$$35, 0);
						ZVAL_LONG(&_48$$35, (zephir_fast_strlen_ev(&controllerName) - zephir_fast_strlen_ev(&controllerSuffix)));
						ZEPHIR_INIT_NVAR(&_49$$35);
						zephir_substr(&_49$$35, &controllerName, 0 , zephir_get_intval(&_48$$35), 0);
						ZEPHIR_CPY_WRT(&controllerName, &_49$$35);
					}
				} else {
					ZEPHIR_CPY_WRT(&controllerName, &handler);
					ZEPHIR_OBS_NVAR(&namespaceName);
					zephir_fetch_property(&namespaceName, this_ptr, SL("defaultNamespace"), PH_SILENT_CC);
				}
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1160, &__$null);
				ZEPHIR_OBS_NVAR(&moduleName);
				_50$$28 = zephir_array_isset_long_fetch(&moduleName, &scope, 2, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_50$$28;
				ZEPHIR_INIT_NVAR(&_51$$28);
				if (Z_TYPE_P(&moduleName) != IS_NULL) {
					ZEPHIR_CPY_WRT(&_51$$28, &moduleName);
				} else {
					ZEPHIR_INIT_NVAR(&_51$$28);
					ZVAL_STRING(&_51$$28, "");
				}
				ZEPHIR_CPY_WRT(&moduleName, &_51$$28);
				ZEPHIR_INIT_NVAR(&_51$$28);
				ZEPHIR_CONCAT_VV(&_51$$28, &controllerName, &controllerSuffix);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_get_strval(&sufixed, &_51$$28);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&namespaceName) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_52$$37);
					ZEPHIR_CONCAT_VSV(&_52$$37, &namespaceName, "\\", &sufixed);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_get_strval(&sufixed, &_52$$37);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_CALL_METHOD_CACHED(&handlerAnnotations, &annotationsService, "get", &_zephir_call_cache[39], &sufixed);
				zephir_check_call_status();
				if (Z_TYPE_P(&handlerAnnotations) != IS_OBJECT) {
					continue;
				}
				ZEPHIR_CALL_METHOD_CACHED(&classAnnotations, &handlerAnnotations, "getClassAnnotations", &_zephir_call_cache[40]);
				zephir_check_call_status();
				if (Z_TYPE_P(&classAnnotations) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD_CACHED(&annotations, &classAnnotations, "getAnnotations", &_zephir_call_cache[41]);
					zephir_check_call_status();
					if (Z_TYPE_P(&annotations) == IS_ARRAY) {
						if (Z_TYPE_P(&annotations) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_54$$40);
							zephir_string_to_char_array(&_54$$40, &annotations);
							_53$$40 = &_54$$40;
						} else {
							_53$$40 = &annotations;
						}
						zephir_is_iterable(_53$$40, 0, "phalcon/Mvc/Router/Annotations.zep", 240);
						if (Z_TYPE_P(_53$$40) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_53$$40), _55$$40)
							{
								ZEPHIR_INIT_NVAR(&annotation);
								ZVAL_COPY(&annotation, _55$$40);
								ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processControllerAnnotation", &_zephir_call_cache[42], &controllerName, &annotation);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _53$$40, "rewind", &_zephir_call_cache[43]);
							zephir_check_call_status();
							_57$$40 = 1;
							while (1) {
								if (_57$$40) {
									_57$$40 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _53$$40, "next", &_zephir_call_cache[44]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_56$$40, _53$$40, "valid", &_zephir_call_cache[45]);
								zephir_check_call_status();
								if (!zend_is_true(&_56$$40)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&annotation, _53$$40, "current", &_zephir_call_cache[46]);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processControllerAnnotation", &_zephir_call_cache[47], &controllerName, &annotation);
									zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&annotation);
					}
				}
				ZEPHIR_CALL_METHOD_CACHED(&methodAnnotations, &handlerAnnotations, "getMethodsAnnotations", &_zephir_call_cache[48]);
				zephir_check_call_status();
				if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&lowerControllerName);
					zephir_uncamelize(&lowerControllerName, &controllerName, NULL );
					if (Z_TYPE_P(&methodAnnotations) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_59$$43);
						zephir_string_to_char_array(&_59$$43, &methodAnnotations);
						_58$$43 = &_59$$43;
					} else {
						_58$$43 = &methodAnnotations;
					}
					zephir_is_iterable(_58$$43, 0, "phalcon/Mvc/Router/Annotations.zep", 266);
					if (Z_TYPE_P(_58$$43) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_58$$43), _61$$43, _62$$43, _60$$43)
						{
							ZEPHIR_INIT_NVAR(&method);
							if (_62$$43 != NULL) { 
								ZVAL_STR_COPY(&method, _62$$43);
							} else {
								ZVAL_LONG(&method, _61$$43);
							}
							ZEPHIR_INIT_NVAR(&collection);
							ZVAL_COPY(&collection, _60$$43);
							if (Z_TYPE_P(&collection) != IS_OBJECT) {
								continue;
							}
							ZEPHIR_CALL_METHOD_CACHED(&_63$$44, &collection, "getAnnotations", &_zephir_call_cache[49]);
							zephir_check_call_status();
							if (Z_TYPE_P(&_63$$44) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_65$$44);
								zephir_string_to_char_array(&_65$$44, &_63$$44);
								_64$$44 = &_65$$44;
							} else {
								_64$$44 = &_63$$44;
							}
							zephir_is_iterable(_64$$44, 0, "phalcon/Mvc/Router/Annotations.zep", 265);
							if (Z_TYPE_P(_64$$44) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_64$$44), _66$$44)
								{
									ZEPHIR_INIT_NVAR(&annotation);
									ZVAL_COPY(&annotation, _66$$44);
									ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processActionAnnotation", &_zephir_call_cache[50], &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _64$$44, "rewind", &_zephir_call_cache[51]);
								zephir_check_call_status();
								_68$$44 = 1;
								while (1) {
									if (_68$$44) {
										_68$$44 = 0;
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _64$$44, "next", &_zephir_call_cache[52]);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD_CACHED(&_67$$44, _64$$44, "valid", &_zephir_call_cache[53]);
									zephir_check_call_status();
									if (!zend_is_true(&_67$$44)) {
										break;
									}
									ZEPHIR_CALL_METHOD_CACHED(&annotation, _64$$44, "current", &_zephir_call_cache[54]);
									zephir_check_call_status();
										ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processActionAnnotation", &_zephir_call_cache[55], &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&annotation);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _58$$43, "rewind", &_zephir_call_cache[56]);
						zephir_check_call_status();
						_70$$43 = 1;
						while (1) {
							if (_70$$43) {
								_70$$43 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _58$$43, "next", &_zephir_call_cache[57]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_69$$43, _58$$43, "valid", &_zephir_call_cache[58]);
							zephir_check_call_status();
							if (!zend_is_true(&_69$$43)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&method, _58$$43, "key", &_zephir_call_cache[59]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&collection, _58$$43, "current", &_zephir_call_cache[60]);
							zephir_check_call_status();
								if (Z_TYPE_P(&collection) != IS_OBJECT) {
									continue;
								}
								ZEPHIR_CALL_METHOD_CACHED(&_71$$48, &collection, "getAnnotations", &_zephir_call_cache[61]);
								zephir_check_call_status();
								if (Z_TYPE_P(&_71$$48) == IS_STRING) {
									ZEPHIR_INIT_NVAR(&_73$$48);
									zephir_string_to_char_array(&_73$$48, &_71$$48);
									_72$$48 = &_73$$48;
								} else {
									_72$$48 = &_71$$48;
								}
								zephir_is_iterable(_72$$48, 0, "phalcon/Mvc/Router/Annotations.zep", 265);
								if (Z_TYPE_P(_72$$48) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_72$$48), _74$$48)
									{
										ZEPHIR_INIT_NVAR(&annotation);
										ZVAL_COPY(&annotation, _74$$48);
										ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processActionAnnotation", &_zephir_call_cache[62], &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _72$$48, "rewind", &_zephir_call_cache[63]);
									zephir_check_call_status();
									_76$$48 = 1;
									while (1) {
										if (_76$$48) {
											_76$$48 = 0;
										} else {
											ZEPHIR_CALL_METHOD_CACHED(NULL, _72$$48, "next", &_zephir_call_cache[64]);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD_CACHED(&_75$$48, _72$$48, "valid", &_zephir_call_cache[65]);
										zephir_check_call_status();
										if (!zend_is_true(&_75$$48)) {
											break;
										}
										ZEPHIR_CALL_METHOD_CACHED(&annotation, _72$$48, "current", &_zephir_call_cache[66]);
										zephir_check_call_status();
											ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processActionAnnotation", &_zephir_call_cache[67], &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
											zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&annotation);
						}
					}
					ZEPHIR_INIT_NVAR(&collection);
					ZEPHIR_INIT_NVAR(&method);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&scope);
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_mvc_router_annotations_ce, getThis(), "handle", &_zephir_call_cache[68], &uri_zv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks for annotations in the public methods of the controller
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processActionAnnotation)
{
	zend_ulong _11$$18, _18$$21;
	zend_bool isRoute = 0, _7, _22, _14$$18, _21$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval module_zv, namespaceName_zv, controller_zv, action_zv, *annotation, annotation_sub, name, proxyActionName, actionName, routePrefix, paths, value, uri, route, methods, converts, param, convert, converterParam, routeName, beforeMatch, _0, _1, _2, _5, _3$$6, _4$$6, _6$$16, *_8$$18, _9$$18, *_10$$18, _13$$18, *_15$$21, _16$$21, *_17$$21, _20$$21;
	zend_string *module = NULL, *namespaceName = NULL, *controller = NULL, *action = NULL, *_12$$18, *_19$$21;
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
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$16);
	ZVAL_UNDEF(&_9$$18);
	ZVAL_UNDEF(&_13$$18);
	ZVAL_UNDEF(&_16$$21);
	ZVAL_UNDEF(&_20$$21);
	ZEND_TLS zephir_method_cache _zephir_call_cache[26];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("actionSuffix", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("routePrefix", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("actionPreformatCallback", 23, 1);
	}

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
	ZEPHIR_CALL_METHOD_CACHED(&name, annotation, "getName", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&name, "Route")) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_STRING(&name, "Connect")) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_STRING(&name, "Delete")) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_STRING(&name, "Get")) { goto zephir_switch_0_clause_3; }
	if (ZEPHIR_IS_STRING(&name, "Head")) { goto zephir_switch_0_clause_4; }
	if (ZEPHIR_IS_STRING(&name, "Options")) { goto zephir_switch_0_clause_5; }
	if (ZEPHIR_IS_STRING(&name, "Patch")) { goto zephir_switch_0_clause_6; }
	if (ZEPHIR_IS_STRING(&name, "Post")) { goto zephir_switch_0_clause_7; }
	if (ZEPHIR_IS_STRING(&name, "Purge")) { goto zephir_switch_0_clause_8; }
	if (ZEPHIR_IS_STRING(&name, "Put")) { goto zephir_switch_0_clause_9; }
	if (ZEPHIR_IS_STRING(&name, "Trace")) { goto zephir_switch_0_clause_10; }
	goto zephir_switch_0_end;
	zephir_switch_0_clause_0: ;
		isRoute = 1;
		goto zephir_switch_0_end;
	zephir_switch_0_clause_1: ;
	zephir_switch_0_clause_2: ;
	zephir_switch_0_clause_3: ;
	zephir_switch_0_clause_4: ;
	zephir_switch_0_clause_5: ;
	zephir_switch_0_clause_6: ;
	zephir_switch_0_clause_7: ;
	zephir_switch_0_clause_8: ;
	zephir_switch_0_clause_9: ;
	zephir_switch_0_clause_10: ;
		isRoute = 1;
		ZEPHIR_INIT_NVAR(&methods);
		zephir_fast_strtoupper(&methods, &name);
		goto zephir_switch_0_end;
	zephir_switch_0_end: ;

	if (!(isRoute)) {
		RETURN_MM_NULL();
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1161, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_INIT_VAR(&proxyActionName);
	zephir_fast_str_replace(&proxyActionName, &_0, &_1, &action_zv);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 1160, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&routePrefix, &_2);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_2, 1162, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_2) != IS_NULL) {
		zephir_read_property_cached(&_3$$6, this_ptr, _zephir_prop_2, 1162, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_4$$6, "call_user_func", NULL, 34, &_3$$6, &proxyActionName);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&proxyActionName, &_4$$6);
	}
	ZEPHIR_INIT_VAR(&actionName);
	zephir_fast_strtolower(&actionName, &proxyActionName);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "paths");
	ZEPHIR_CALL_METHOD_CACHED(&paths, annotation, "getNamedArgument", &_zephir_call_cache[1], &_5);
	zephir_check_call_status();
	if (Z_TYPE_P(&paths) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&paths);
		array_init(&paths);
	}
	if (!(ZEPHIR_IS_EMPTY(&module_zv))) {
		zephir_array_update_string(&paths, SL("module"), &module_zv, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (!(ZEPHIR_IS_EMPTY(&namespaceName_zv))) {
		zephir_array_update_string(&paths, SL("namespace"), &namespaceName_zv, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_array_update_string(&paths, SL("controller"), &controller_zv, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&paths, SL("action"), &actionName, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "route");
	ZEPHIR_CALL_METHOD_CACHED(&value, this_ptr, "resolveArgument", &_zephir_call_cache[2], annotation, &_5);
	zephir_check_call_status();
	if (Z_TYPE_P(&value) != IS_NULL) {
		if (!ZEPHIR_IS_STRING(&value, "/")) {
			ZEPHIR_INIT_VAR(&uri);
			ZEPHIR_CONCAT_VV(&uri, &routePrefix, &value);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&route, this_ptr, "add", &_zephir_call_cache[3], &uri, &paths);
	zephir_check_call_status();
	if (Z_TYPE_P(&methods) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_6$$16);
		ZVAL_STRING(&_6$$16, "methods");
		ZEPHIR_CALL_METHOD_CACHED(&methods, annotation, "getNamedArgument", &_zephir_call_cache[4], &_6$$16);
		zephir_check_call_status();
	}
	_7 = Z_TYPE_P(&methods) == IS_ARRAY;
	if (!(_7)) {
		_7 = Z_TYPE_P(&methods) == IS_STRING;
	}
	if (_7) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "via", &_zephir_call_cache[5], &methods);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "converts");
	ZEPHIR_CALL_METHOD_CACHED(&converts, annotation, "getNamedArgument", &_zephir_call_cache[6], &_5);
	zephir_check_call_status();
	if (Z_TYPE_P(&converts) == IS_ARRAY) {
		if (Z_TYPE_P(&converts) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_9$$18);
			zephir_string_to_char_array(&_9$$18, &converts);
			_8$$18 = &_9$$18;
		} else {
			_8$$18 = &converts;
		}
		zephir_is_iterable(_8$$18, 0, "phalcon/Mvc/Router/Annotations.zep", 399);
		if (Z_TYPE_P(_8$$18) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_8$$18), _11$$18, _12$$18, _10$$18)
			{
				ZEPHIR_INIT_NVAR(&param);
				if (_12$$18 != NULL) { 
					ZVAL_STR_COPY(&param, _12$$18);
				} else {
					ZVAL_LONG(&param, _11$$18);
				}
				ZEPHIR_INIT_NVAR(&convert);
				ZVAL_COPY(&convert, _10$$18);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "convert", &_zephir_call_cache[7], &param, &convert);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _8$$18, "rewind", &_zephir_call_cache[8]);
			zephir_check_call_status();
			_14$$18 = 1;
			while (1) {
				if (_14$$18) {
					_14$$18 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _8$$18, "next", &_zephir_call_cache[9]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_13$$18, _8$$18, "valid", &_zephir_call_cache[10]);
				zephir_check_call_status();
				if (!zend_is_true(&_13$$18)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&param, _8$$18, "key", &_zephir_call_cache[11]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&convert, _8$$18, "current", &_zephir_call_cache[12]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "convert", &_zephir_call_cache[13], &param, &convert);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&convert);
		ZEPHIR_INIT_NVAR(&param);
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "converters");
	ZEPHIR_CALL_METHOD_CACHED(&converts, annotation, "getNamedArgument", &_zephir_call_cache[14], &_5);
	zephir_check_call_status();
	if (Z_TYPE_P(&converts) == IS_ARRAY) {
		if (Z_TYPE_P(&converts) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_16$$21);
			zephir_string_to_char_array(&_16$$21, &converts);
			_15$$21 = &_16$$21;
		} else {
			_15$$21 = &converts;
		}
		zephir_is_iterable(_15$$21, 0, "phalcon/Mvc/Router/Annotations.zep", 410);
		if (Z_TYPE_P(_15$$21) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_15$$21), _18$$21, _19$$21, _17$$21)
			{
				ZEPHIR_INIT_NVAR(&converterParam);
				if (_19$$21 != NULL) { 
					ZVAL_STR_COPY(&converterParam, _19$$21);
				} else {
					ZVAL_LONG(&converterParam, _18$$21);
				}
				ZEPHIR_INIT_NVAR(&convert);
				ZVAL_COPY(&convert, _17$$21);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "convert", &_zephir_call_cache[15], &converterParam, &convert);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _15$$21, "rewind", &_zephir_call_cache[16]);
			zephir_check_call_status();
			_21$$21 = 1;
			while (1) {
				if (_21$$21) {
					_21$$21 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _15$$21, "next", &_zephir_call_cache[17]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_20$$21, _15$$21, "valid", &_zephir_call_cache[18]);
				zephir_check_call_status();
				if (!zend_is_true(&_20$$21)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&converterParam, _15$$21, "key", &_zephir_call_cache[19]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&convert, _15$$21, "current", &_zephir_call_cache[20]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "convert", &_zephir_call_cache[21], &converterParam, &convert);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&convert);
		ZEPHIR_INIT_NVAR(&converterParam);
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "beforeMatch");
	ZEPHIR_CALL_METHOD_CACHED(&beforeMatch, annotation, "getNamedArgument", &_zephir_call_cache[22], &_5);
	zephir_check_call_status();
	_22 = Z_TYPE_P(&beforeMatch) == IS_ARRAY;
	if (!(_22)) {
		_22 = Z_TYPE_P(&beforeMatch) == IS_STRING;
	}
	if (_22) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "beforeMatch", &_zephir_call_cache[23], &beforeMatch);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "name");
	ZEPHIR_CALL_METHOD_CACHED(&routeName, annotation, "getNamedArgument", &_zephir_call_cache[24], &_5);
	zephir_check_call_status();
	if (Z_TYPE_P(&routeName) == IS_STRING) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &route, "setName", &_zephir_call_cache[25], &routeName);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routePrefix", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(handler)
		Z_PARAM_OBJECT_OF_CLASS(annotation, phalcon_annotations_annotation_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	annotation = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&handler_zv);
	ZVAL_STR_COPY(&handler_zv, handler);
	ZEPHIR_CALL_METHOD_CACHED(&_0, annotation, "getName", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&_0, "RoutePrefix")) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "prefix");
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "resolveArgument", &_zephir_call_cache[1], annotation, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1160, &_1$$3);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Changes the action method suffix
 *
 * @phpstan-return static
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setActionSuffix)
{
	zval actionSuffix_zv;
	zend_string *actionSuffix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionSuffix_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("actionSuffix", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionSuffix)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&actionSuffix_zv, actionSuffix);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1161, &actionSuffix_zv);
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
 *
 * @phpstan-return static
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("actionPreformatCallback", 23, 1);
	}

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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1162, callback);
	} else if (Z_TYPE_P(callback) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_INIT_NVAR(&_0$$4);
		zephir_create_closure_ex(&_0$$4, NULL, phalcon_94__closure_ce, SL("__invoke"));
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1162, &_0$$4);
	} else {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, phalcon_mvc_router_exceptions_invalidcallbackparameter_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$5, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "phalcon/Mvc/Router/Annotations.zep", 493);
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
 *
 * @phpstan-return static
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setControllerSuffix)
{
	zval controllerSuffix_zv;
	zend_string *controllerSuffix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerSuffix_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("controllerSuffix", 16, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(controllerSuffix)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&controllerSuffix_zv, controllerSuffix);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1159, &controllerSuffix_zv);
	RETURN_THISW();
}

/**
 * Returns the argument at position 0, or the named one when position 0
 * is not there.
 *
 * A docblock puts the value at position 0. An attribute puts it at
 * position 0 too, unless the developer writes the name as a named
 * argument.
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, resolveArgument)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL;
	zval *annotation, annotation_sub, name_zv, value, _0;

	ZVAL_UNDEF(&annotation_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(annotation, phalcon_annotations_annotation_ce)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	annotation = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD_CACHED(&value, annotation, "getArgument", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&value) == IS_NULL) {
		ZEPHIR_CALL_METHOD_CACHED(&value, annotation, "getArgument", &_zephir_call_cache[1], &name_zv);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&value);
}

zend_object *zephir_init_properties_Phalcon_Mvc_Router_Annotations(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("handlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("handlers"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

