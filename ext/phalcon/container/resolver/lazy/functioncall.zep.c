
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
ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_FunctionCall)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Container\\Resolver\\Lazy, FunctionCall, phalcon, container_resolver_lazy_functioncall, phalcon_container_resolver_lazy_lazy_ce, phalcon_container_resolver_lazy_functioncall_method_entry, 0);

	/**
	 * @var array<array-key, mixed>
	 */
	zend_declare_property_null(phalcon_container_resolver_lazy_functioncall_ce, SL("arguments"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_container_resolver_lazy_functioncall_ce, SL("functionName"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * @param string                  $functionName
 * @param array<array-key, mixed> $arguments
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_FunctionCall, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval arguments;
	zval functionName_zv, *arguments_param = NULL;
	zend_string *functionName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&functionName_zv);
	ZVAL_UNDEF(&arguments);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(functionName)
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	arguments_param = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&functionName_zv, functionName);
	zephir_get_arrval(&arguments, arguments_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("functionName"), &functionName_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("arguments"), &arguments);
	ZEPHIR_MM_RESTORE();
}

/**
 * Resolve a function
 *
 * @param object $ioc
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_FunctionCall, resolve)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ioc, ioc_sub, arguments, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(ioc)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &ioc);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&arguments, this_ptr, "resolvearguments", NULL, 0, ioc, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("functionName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_1, &arguments);
	zephir_check_call_status();
	RETURN_MM();
}

