
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, which is a
 * Composer dependency, and from service-interop and resolver-interop. The
 * latter two are copied and re-implemented here: service-interop is not yet
 * published on Packagist, and resolver-interop requires PHP 8.4 (this project
 * targets PHP 8.1). Once both packages become available and compatible, the
 * copies will be replaced with the actual Composer dependencies.
 *
 * @link    https://github.com/capsulephp/di
 * @license https://github.com/capsulephp/di/blob/3.x/LICENSE.md
 *
 * @link    https://github.com/ioc-interop/interface
 * @license https://github.com/ioc-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/service-interop/interface
 * @license https://github.com/service-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/resolver-interop/interface/tree/1.x
 * @license https://github.com/resolver-interop/interface/blob/1.x/LICENSE.md
 */
ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_LazyFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Container\\Resolver\\Lazy, LazyFactory, phalcon, container_resolver_lazy_lazyfactory, phalcon_container_resolver_lazy_lazyfactory_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array<array-key, mixed> $values
 *
 * @return ArrayValues
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, arrayValues)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL;
	zval values;

	ZVAL_UNDEF(&values);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &values_param);
	zephir_get_arrval(&values, values_param);
	object_init_ex(return_value, phalcon_container_resolver_lazy_arrayvalues_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 404, &values);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, call)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callableObject, callableObject_sub;

	ZVAL_UNDEF(&callableObject_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callableObject)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &callableObject);
	object_init_ex(return_value, phalcon_container_resolver_lazy_call_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 405, callableObject);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, callableGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval id_zv;
	zend_string *id = NULL;

	ZVAL_UNDEF(&id_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&id_zv);
	ZVAL_STR_COPY(&id_zv, id);
	object_init_ex(return_value, phalcon_container_resolver_lazy_callableget_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 406, &id_zv);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, callableNew)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval id_zv;
	zend_string *id = NULL;

	ZVAL_UNDEF(&id_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&id_zv);
	ZVAL_STR_COPY(&id_zv, id);
	object_init_ex(return_value, phalcon_container_resolver_lazy_callablenew_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 407, &id_zv);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, csEnv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, type_zv;
	zend_string *name = NULL, *type = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&type_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!type) {
		ZEPHIR_INIT_VAR(&type_zv);
	} else {
		zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	}
	object_init_ex(return_value, phalcon_container_resolver_lazy_csenv_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 408, &name_zv, &type_zv);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, env)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, type_zv;
	zend_string *name = NULL, *type = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&type_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!type) {
		ZEPHIR_INIT_VAR(&type_zv);
	} else {
		zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	}
	object_init_ex(return_value, phalcon_container_resolver_lazy_env_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 408, &name_zv, &type_zv);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, envDefault)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultValue;
	zval name_zv, defaultValue_sub, type_zv;
	zend_string *name = NULL, *type = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&type_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(defaultValue)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	defaultValue = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!type) {
		ZEPHIR_INIT_VAR(&type_zv);
	} else {
		zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	}
	object_init_ex(return_value, phalcon_container_resolver_lazy_envdefault_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 409, &name_zv, defaultValue, &type_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string                  $function
 * @param array<array-key, mixed> $args
 *
 * @return FunctionCall
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, functionCall)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval functionName_zv, *args_param = NULL;
	zend_string *functionName = NULL;

	ZVAL_UNDEF(&functionName_zv);
	ZVAL_UNDEF(&args);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(functionName)
		ZEPHIR_Z_PARAM_ARRAY(args, args_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	args_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&functionName_zv);
	ZVAL_STR_COPY(&functionName_zv, functionName);
	zephir_get_arrval(&args, args_param);
	object_init_ex(return_value, phalcon_container_resolver_lazy_functioncall_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 410, &functionName_zv, &args);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval id_zv;
	zend_string *id = NULL;

	ZVAL_UNDEF(&id_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&id_zv);
	ZVAL_STR_COPY(&id_zv, id);
	object_init_ex(return_value, phalcon_container_resolver_lazy_get_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 411, &id_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string                  $id
 * @param string                  $method
 * @param array<array-key, mixed> $args
 *
 * @return GetCall
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, getCall)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval id_zv, method_zv, *args_param = NULL;
	zend_string *id = NULL, *method = NULL;

	ZVAL_UNDEF(&id_zv);
	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&args);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(id)
		Z_PARAM_STR(method)
		ZEPHIR_Z_PARAM_ARRAY(args, args_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	args_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&id_zv);
	ZVAL_STR_COPY(&id_zv, id);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	zephir_get_arrval(&args, args_param);
	object_init_ex(return_value, phalcon_container_resolver_lazy_getcall_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 412, &id_zv, &method_zv, &args);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string                  $id
 * @param string                  $method
 * @param array<array-key, mixed> $args
 *
 * @return NewCall
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, newCall)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval id_zv, method_zv, *args_param = NULL;
	zend_string *id = NULL, *method = NULL;

	ZVAL_UNDEF(&id_zv);
	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&args);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(id)
		Z_PARAM_STR(method)
		ZEPHIR_Z_PARAM_ARRAY(args, args_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	args_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&id_zv);
	ZVAL_STR_COPY(&id_zv, id);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	zephir_get_arrval(&args, args_param);
	object_init_ex(return_value, phalcon_container_resolver_lazy_newcall_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 413, &id_zv, &method_zv, &args);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval id_zv;
	zend_string *id = NULL;

	ZVAL_UNDEF(&id_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&id_zv);
	ZVAL_STR_COPY(&id_zv, id);
	object_init_ex(return_value, phalcon_container_resolver_lazy_newinstance_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 414, &id_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string                  $className
 * @param string                  $method
 * @param array<array-key, mixed> $args
 *
 * @return StaticCall
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, staticCall)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval className_zv, method_zv, *args_param = NULL;
	zend_string *className = NULL, *method = NULL;

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&args);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(className)
		Z_PARAM_STR(method)
		ZEPHIR_Z_PARAM_ARRAY(args, args_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	args_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	zephir_get_arrval(&args, args_param);
	object_init_ex(return_value, phalcon_container_resolver_lazy_staticcall_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 415, &className_zv, &method_zv, &args);
	zephir_check_call_status();
	RETURN_MM();
}

