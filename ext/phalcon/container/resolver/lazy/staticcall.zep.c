
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_StaticCall)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Container\\Resolver\\Lazy, StaticCall, phalcon, container_resolver_lazy_staticcall, phalcon_container_resolver_lazy_lazy_ce, phalcon_container_resolver_lazy_staticcall_method_entry, 0);

	/**
	 * @var array<array-key, mixed>
	 */
	zend_declare_property_null(phalcon_container_resolver_lazy_staticcall_ce, SL("arguments"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|Lazy
	 */
	zend_declare_property_null(phalcon_container_resolver_lazy_staticcall_ce, SL("className"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_container_resolver_lazy_staticcall_ce, SL("method"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * @param string|Lazy             $className
 * @param string                  $method
 * @param array<array-key, mixed> $arguments
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_StaticCall, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval arguments;
	zend_string *method = NULL;
	zval *className, className_sub, method_zv, *arguments_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_sub);
	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&arguments);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(className)
		Z_PARAM_STR(method)
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	className = ZEND_CALL_ARG(execute_data, 1);
	arguments_param = ZEND_CALL_ARG(execute_data, 3);
	ZVAL_STR(&method_zv, method);
	zephir_get_arrval(&arguments, arguments_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("className"), className);
	zephir_update_property_zval(this_ptr, ZEND_STRL("method"), &method_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("arguments"), &arguments);
	ZEPHIR_MM_RESTORE();
}

/**
 * Resolve a static method call
 *
 * @param object $ioc
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_StaticCall, resolve)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ioc, ioc_sub, className, arguments, _0, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(ioc)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &ioc);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("className"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&className, this_ptr, "resolveargument", NULL, 0, ioc, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&arguments, this_ptr, "resolvearguments", NULL, 0, ioc, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, &className);
	zephir_memory_observe(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("method"), PH_NOISY_CC);
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_2, &arguments);
	zephir_check_call_status();
	RETURN_MM();
}

