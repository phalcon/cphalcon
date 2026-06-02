
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_Env)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Container\\Resolver\\Lazy, Env, phalcon, container_resolver_lazy_env, phalcon_container_resolver_lazy_lazy_ce, phalcon_container_resolver_lazy_env_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_container_resolver_lazy_env_ce, SL("varname"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_container_resolver_lazy_env_ce, SL("vartype"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * @param string      $varname
 * @param string|null $vartype
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_Env, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval varname_zv, vartype_zv;
	zend_string *varname = NULL, *vartype = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&varname_zv);
	ZVAL_UNDEF(&vartype_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(varname)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(vartype)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&varname_zv);
	ZVAL_STR_COPY(&varname_zv, varname);
	if (!vartype) {
		ZEPHIR_INIT_VAR(&vartype_zv);
	} else {
		zephir_memory_observe(&vartype_zv);
	ZVAL_STR_COPY(&vartype_zv, vartype);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("varname"), &varname_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("vartype"), &vartype_zv);
	ZEPHIR_MM_RESTORE();
}

/**
 * Resolve an environment variable
 *
 * @param object $ioc
 *
 * @return mixed
 * @throws EnvNotDefined
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_Env, resolve)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ioc, ioc_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(ioc)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &ioc);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getenv", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cast", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Cast a value to the defined type (if any)
 *
 * @param string $value
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_Env, cast)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &value);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("vartype"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("vartype"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_MAKE_REF(value);
		ZEPHIR_CALL_FUNCTION(NULL, "settype", NULL, 13, value, &_1$$3);
		ZEPHIR_UNREF(value);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();
}

/**
 * Return the env value
 *
 * @return string
 * @throws EnvNotDefined
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_Env, getEnv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _ENV, envs, _0, _1, _4, _5, _2$$3, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_ENV);
	ZVAL_UNDEF(&envs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_ENV, SL("_ENV"));

	ZEPHIR_CALL_FUNCTION(&_0, "getenv", NULL, 138);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&envs);
	zephir_fast_array_merge(&envs, &_ENV, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("varname"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&envs, &_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_container_exceptions_envnotdefined_ce);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("varname"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 139, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Container/Resolver/Lazy/Env.zep", 98);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_5);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("varname"), PH_NOISY_CC);
	zephir_array_fetch(&_4, &envs, &_5, PH_NOISY | PH_READONLY, "phalcon/Container/Resolver/Lazy/Env.zep", 101);
	RETURN_CTOR(&_4);
}

