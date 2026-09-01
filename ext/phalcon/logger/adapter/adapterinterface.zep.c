
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Logger\AdapterInterface
 *
 * Interface for Phalcon\Logger adapters
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Logger\Adapter\Adapter} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_AdapterInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Logger\\Adapter, AdapterInterface, phalcon, logger_adapter_adapterinterface, NULL);

	zend_class_implements(phalcon_logger_adapter_adapterinterface_ce, 1, phalcon_contracts_logger_adapter_adapter_ce);
	return SUCCESS;
}

