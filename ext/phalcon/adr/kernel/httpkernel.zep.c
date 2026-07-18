
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
 * Concrete default HTTP kernel. Boots the ADR provider and runs the application
 * with the framework defaults; subclass to override `loadEnvironment()` or
 * `registerProviders()`.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Kernel_HttpKernel)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\ADR\\Kernel, HttpKernel, phalcon, adr_kernel_httpkernel, phalcon_adr_kernel_abstracthttpkernel_ce, NULL, 0);

	return SUCCESS;
}

