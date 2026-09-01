
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
 * Phalcon\Mvc\DispatcherInterface
 *
 * Interface for Phalcon\Mvc\Dispatcher
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Mvc\Dispatcher} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_DispatcherInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, DispatcherInterface, phalcon, mvc_dispatcherinterface, NULL);

	zend_class_implements(phalcon_mvc_dispatcherinterface_ce, 1, phalcon_contracts_mvc_dispatcher_ce);
	return SUCCESS;
}

