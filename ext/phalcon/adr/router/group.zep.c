
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * A group of routes sharing a path prefix and middleware. Routes registered
 * through the group get the prefix prepended and the group's middleware
 * flattened onto them (set middleware before adding routes).
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_Group)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Router, Group, phalcon, adr_router_group, phalcon_adr_router_group_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_adr_router_group_ce, SL("prefix"), ZEND_ACC_PROTECTED);
	/**
	 * @var Router
	 */
	zend_declare_property_null(phalcon_adr_router_group_ce, SL("router"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_adr_router_group_ce, SL("middleware"), ZEND_ACC_PROTECTED);
	phalcon_adr_router_group_ce->create_object = zephir_init_properties_Phalcon_ADR_Router_Group;

	zend_class_implements(phalcon_adr_router_group_ce, 1, phalcon_contracts_adr_router_group_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Router_Group, __construct)
{
	zval prefix_zv, *router, router_sub;
	zend_string *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&router_sub);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("prefix", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("router", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(prefix)
		Z_PARAM_OBJECT_OF_CLASS(router, phalcon_adr_router_router_ce)
	ZEND_PARSE_PARAMETERS_END();
	router = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&prefix_zv, prefix);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 349, &prefix_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 350, router);
}

PHP_METHOD(Phalcon_ADR_Router_Group, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval methods;
	zval pattern_zv, actionClass_zv, *methods_param = NULL, route, _0, _1, _2, _3;
	zend_string *pattern = NULL, *actionClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&actionClass_zv);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&methods);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("router", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("prefix", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("middleware", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_STR(actionClass)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(methods, methods_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		methods_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	zephir_memory_observe(&actionClass_zv);
	ZVAL_STR_COPY(&actionClass_zv, actionClass);
	if (!methods_param) {
		ZEPHIR_INIT_VAR(&methods);
		array_init(&methods);
	} else {
		zephir_get_arrval(&methods, methods_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 350, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 349, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_1, &pattern_zv);
	ZEPHIR_CALL_METHOD(&route, &_0, "add", NULL, 0, &_2, &actionClass_zv, &methods);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 351, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &route, "pushmiddleware", NULL, 0, &_3);
	zephir_check_call_status();
	RETURN_CCTOR(&route);
}

PHP_METHOD(Phalcon_ADR_Router_Group, delete)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, actionClass_zv, _1;
	zend_string *pattern = NULL, *actionClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&actionClass_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_STR(actionClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	zephir_memory_observe(&actionClass_zv);
	ZVAL_STR_COPY(&actionClass_zv, actionClass);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "DELETE");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, &actionClass_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Group, get)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, actionClass_zv, _1;
	zend_string *pattern = NULL, *actionClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&actionClass_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_STR(actionClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	zephir_memory_observe(&actionClass_zv);
	ZVAL_STR_COPY(&actionClass_zv, actionClass);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "GET");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, &actionClass_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Group, patch)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, actionClass_zv, _1;
	zend_string *pattern = NULL, *actionClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&actionClass_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_STR(actionClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	zephir_memory_observe(&actionClass_zv);
	ZVAL_STR_COPY(&actionClass_zv, actionClass);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "PATCH");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, &actionClass_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Group, post)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, actionClass_zv, _1;
	zend_string *pattern = NULL, *actionClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&actionClass_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_STR(actionClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	zephir_memory_observe(&actionClass_zv);
	ZVAL_STR_COPY(&actionClass_zv, actionClass);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "POST");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, &actionClass_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Group, put)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, actionClass_zv, _1;
	zend_string *pattern = NULL, *actionClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&actionClass_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_STR(actionClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	zephir_memory_observe(&actionClass_zv);
	ZVAL_STR_COPY(&actionClass_zv, actionClass);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "PUT");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &pattern_zv, &actionClass_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Router_Group, withMiddleware)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval classes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classes);
	ZEND_PARSE_PARAMETERS_START(0, -1)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZEPHIR_INIT_VAR(&classes);
	zephir_get_args_from(&classes, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "pushmiddleware", NULL, 0, &classes);
	zephir_check_call_status();
	RETURN_THIS();
}

PHP_METHOD(Phalcon_ADR_Router_Group, getMiddleware)
{

	RETURN_MEMBER_TYPED(getThis(), "middleware", IS_ARRAY);
}

PHP_METHOD(Phalcon_ADR_Router_Group, pushMiddleware)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *classes_param = NULL, item, *_0, _1;
	zval classes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(classes, classes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &classes_param);
	zephir_get_arrval(&classes, classes_param);
	zephir_is_iterable(&classes, 0, "phalcon/ADR/Router/Traits/HasMiddleware.zep", 39);
	if (Z_TYPE_P(&classes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&classes), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			zephir_update_property_array_append(this_ptr, SL("middleware"), &item);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &classes, "rewind", NULL, 0);
		zephir_check_call_status();
		_2 = 1;
		while (1) {
			if (_2) {
				_2 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &classes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_1, &classes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &classes, "current", NULL, 0);
			zephir_check_call_status();
				zephir_update_property_array_append(this_ptr, SL("middleware"), &item);
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Phalcon_ADR_Router_Group(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("middleware"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("middleware"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

