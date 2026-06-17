
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
 * Interface for Phalcon\Cli\Dispatcher
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Cli\Dispatcher} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_DispatcherInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Cli, DispatcherInterface, phalcon, cli_dispatcherinterface, NULL);

	zend_class_implements(phalcon_cli_dispatcherinterface_ce, 1, phalcon_contracts_cli_dispatcher_ce);
	return SUCCESS;
}

