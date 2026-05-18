
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
 * Phalcon\Events\ManagerInterface
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Events\Manager} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_ManagerInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Events, ManagerInterface, phalcon, events_managerinterface, NULL);

	zend_class_implements(phalcon_events_managerinterface_ce, 1, phalcon_contracts_events_manager_ce);
	return SUCCESS;
}

