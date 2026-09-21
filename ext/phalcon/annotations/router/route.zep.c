
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
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Marks a method as a route. It is the attribute form of `@Route`.
 *
 * The annotations service never makes an instance of this class. It reads the
 * arguments with ReflectionAttribute::getArguments(). The class gives the
 * name, the targets and the signature that an IDE and a static analyzer read.
 *
 * @phpstan-import-type annotations_route_before_match from AnnotationsTypes
 * @phpstan-import-type annotations_route_converters from AnnotationsTypes
 * @phpstan-import-type annotations_route_methods from AnnotationsTypes
 * @phpstan-import-type annotations_route_paths from AnnotationsTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Router_Route)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations\\Router, Route, phalcon, annotations_router_route, phalcon_annotations_router_route_method_entry, 0);

	{
		zend_attribute *_za = zephir_add_class_attribute(phalcon_annotations_router_route_ce, SL("Attribute"), 1);
		zval _zc0;
		ZVAL_LONG(&_zc0, 68);
		zephir_attribute_set_arg(_za, 0, NULL, 0, &_zc0);
	}

	/**
	 * @var array|string|null
	 *
	 * @phpstan-var annotations_route_before_match
	 */
	zend_declare_property_null(phalcon_annotations_router_route_ce, SL("beforeMatch"), ZEND_ACC_PUBLIC);
	/**
	 * @var array
	 *
	 * @phpstan-var annotations_route_converters
	 */
	zend_declare_property_null(phalcon_annotations_router_route_ce, SL("converters"), ZEND_ACC_PUBLIC);
	/**
	 * @var array|string|null
	 *
	 * @phpstan-var annotations_route_methods
	 */
	zend_declare_property_null(phalcon_annotations_router_route_ce, SL("methods"), ZEND_ACC_PUBLIC);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_annotations_router_route_ce, SL("name"), ZEND_ACC_PUBLIC);
	/**
	 * @var array
	 *
	 * @phpstan-var annotations_route_paths
	 */
	zend_declare_property_null(phalcon_annotations_router_route_ce, SL("paths"), ZEND_ACC_PUBLIC);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_annotations_router_route_ce, SL("route"), ZEND_ACC_PUBLIC);
	return SUCCESS;
}

/**
 * @phpstan-param annotations_route_methods      $methods
 * @phpstan-param annotations_route_paths        $paths
 * @phpstan-param annotations_route_converters   $converters
 * @phpstan-param annotations_route_before_match $beforeMatch
 */
PHP_METHOD(Phalcon_Annotations_Router_Route, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval paths, converters;
	zval route_zv, *methods = NULL, methods_sub, name_zv, *paths_param = NULL, *converters_param = NULL, *beforeMatch = NULL, beforeMatch_sub, __$null;
	zend_string *route = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_zv);
	ZVAL_UNDEF(&methods_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&beforeMatch_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&converters);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("route", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("methods", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("name", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("paths", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("converters", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("beforeMatch", 11, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 6)
		Z_PARAM_STR(route)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(methods)
		Z_PARAM_STR_OR_NULL(name)
		ZEPHIR_Z_PARAM_ARRAY(paths, paths_param)
		ZEPHIR_Z_PARAM_ARRAY(converters, converters_param)
		Z_PARAM_ZVAL_OR_NULL(beforeMatch)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		methods = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 3) {
		paths_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		converters_param = ZEND_CALL_ARG(execute_data, 5);
	}
	if (ZEND_NUM_ARGS() > 5) {
		beforeMatch = ZEND_CALL_ARG(execute_data, 6);
	}
	zephir_memory_observe(&route_zv);
	ZVAL_STR_COPY(&route_zv, route);
	if (!methods) {
		methods = &methods_sub;
		methods = &__$null;
	}
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	if (!paths_param) {
		ZEPHIR_INIT_VAR(&paths);
		array_init(&paths);
	} else {
		zephir_get_arrval(&paths, paths_param);
	}
	if (!converters_param) {
		ZEPHIR_INIT_VAR(&converters);
		array_init(&converters);
	} else {
		zephir_get_arrval(&converters, converters_param);
	}
	if (!beforeMatch) {
		beforeMatch = &beforeMatch_sub;
		beforeMatch = &__$null;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 39, &route_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 40, methods);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 41, &name_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 42, &paths);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 43, &converters);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 44, beforeMatch);
	ZEPHIR_MM_RESTORE();
}

