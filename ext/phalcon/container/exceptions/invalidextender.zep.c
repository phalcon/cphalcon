
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
#include "kernel/fcall.h"
#include "kernel/concat.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Container_Exceptions_InvalidExtender)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Container\\Exceptions, InvalidExtender, phalcon, container_exceptions_invalidextender, phalcon_container_exceptions_exception_ce, phalcon_container_exceptions_invalidextender_method_entry, 0);

	return SUCCESS;
}

/**
 * Invalid extender (not callable)
 *
 * @param string $service
 * @param string $key
 *
 * @return static
 */
PHP_METHOD(Phalcon_Container_Exceptions_InvalidExtender, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval service_zv, key_zv;
	zend_string *service = NULL, *key = NULL;

	ZVAL_UNDEF(&service_zv);
	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(service)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&service_zv);
	ZVAL_STR_COPY(&service_zv, service);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVSVS(&_0, "Extender at key '", &key_zv, "' for service '", &service_zv, "' is not callable");
	ZEPHIR_CALL_PARENT(NULL, phalcon_container_exceptions_invalidextender_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

