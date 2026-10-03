
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Marks a method as a PATCH route. It is the attribute form of `@Patch`.
 *
 * @phpstan-import-type annotations_route_before_match from AnnotationsTypes
 * @phpstan-import-type annotations_route_converters from AnnotationsTypes
 * @phpstan-import-type annotations_route_paths from AnnotationsTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Router_Patch)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Annotations\\Router, Patch, phalcon, annotations_router_patch, phalcon_annotations_router_route_ce, phalcon_annotations_router_patch_method_entry, 0);

	{
		zend_attribute *_za = zephir_add_class_attribute(phalcon_annotations_router_patch_ce, SL("Attribute"), 1);
		zval _zc0;
		ZVAL_LONG(&_zc0, 68);
		zephir_attribute_set_arg(_za, 0, NULL, 0, &_zc0);
	}

	return SUCCESS;
}

/**
 * @phpstan-param annotations_route_paths        $paths
 * @phpstan-param annotations_route_converters   $converters
 * @phpstan-param annotations_route_before_match $beforeMatch
 */
PHP_METHOD(Phalcon_Annotations_Router_Patch, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval paths, converters;
	zval route_zv, name_zv, *paths_param = NULL, *converters_param = NULL, *beforeMatch = NULL, beforeMatch_sub, __$null, _0;
	zend_string *route = NULL, *name = NULL;

	ZVAL_UNDEF(&route_zv);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&beforeMatch_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&converters);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(route)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
		ZEPHIR_Z_PARAM_ARRAY(paths, paths_param)
		ZEPHIR_Z_PARAM_ARRAY(converters, converters_param)
		Z_PARAM_ZVAL_OR_NULL(beforeMatch)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		paths_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		converters_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		beforeMatch = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&route_zv);
	ZVAL_STR_COPY(&route_zv, route);
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
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PATCH");
	ZEPHIR_CALL_PARENT(NULL, phalcon_annotations_router_patch_ce, getThis(), "__construct", NULL, 0, &route_zv, &_0, &name_zv, &paths, &converters, beforeMatch);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

