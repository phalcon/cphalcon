
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
ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_NewInstance)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Container\\Resolver\\Lazy, NewInstance, phalcon, container_resolver_lazy_newinstance, phalcon_container_resolver_lazy_lazy_ce, phalcon_container_resolver_lazy_newinstance_method_entry, 0);

	/**
	 * @var string|Lazy
	 */
	zend_declare_property_null(phalcon_container_resolver_lazy_newinstance_ce, SL("id"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * @param string|Lazy $id
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_NewInstance, __construct)
{
	zval *id, id_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &id);
	zephir_update_property_zval(this_ptr, ZEND_STRL("id"), id);
}

/**
 * Resolve a new instance
 *
 * @param object $ioc
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_NewInstance, resolve)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ioc, ioc_sub, id, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(ioc)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &ioc);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("id"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&id, this_ptr, "resolveargument", NULL, 0, ioc, &_0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(ioc, "new", NULL, 0, &id);
	zephir_check_call_status();
	RETURN_MM();
}

