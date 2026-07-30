
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
 * Optional capability contract for a container that can report the services it
 * holds. Callers detect support with `instanceof`.
 *
 * Deliberately separate from Collection rather than a member of it. Collection
 * mirrors the service-interop surface, which has no notion of enumeration, and
 * adding a member to a published interface breaks every implementor. A second,
 * narrow interface states the capability without touching the first.
 *
 * Carries no interop attribution because nothing here is copied: enumeration is
 * Phalcon's own addition.
 *
 * Tooling that reports on a container type-hints this instead of the concrete
 * Container, so it depends on a published contract rather than on an
 * implementation detail that is free to change.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Container_Service_Enumerable)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Container\\Service, Enumerable, phalcon, contracts_container_service_enumerable, phalcon_contracts_container_service_enumerable_method_entry);

	return SUCCESS;
}

/**
 * Returns the names of every registered service definition. Names that
 * only exist as an alias, a pre-set instance or a parameter are not
 * included.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Container_Service_Enumerable, getServiceNames);
