
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
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Dispatcher\AbstractDispatcher
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Dispatcher\Dispatcher} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Dispatcher_DispatcherInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Dispatcher, DispatcherInterface, phalcon, dispatcher_dispatcherinterface, NULL);

	zend_class_implements(phalcon_dispatcher_dispatcherinterface_ce, 1, phalcon_contracts_dispatcher_dispatcher_ce);
	return SUCCESS;
}

