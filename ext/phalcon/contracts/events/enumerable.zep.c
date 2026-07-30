
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
 * Optional capability contract for an events manager that can report every
 * attached listener in one call. Callers detect support with `instanceof`.
 *
 * Deliberately separate from Manager rather than a member of it: adding a
 * member to a published interface breaks every implementor, so a second,
 * narrow interface states the capability without touching the first.
 *
 * Tooling that reports on an events manager type-hints this instead of the
 * concrete Manager, so it depends on a published contract rather than on an
 * implementation detail that is free to change.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Events_Enumerable)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Events, Enumerable, phalcon, contracts_events_enumerable, phalcon_contracts_events_enumerable_method_entry);

	return SUCCESS;
}

/**
 * Returns every event type that currently has at least one listener,
 * mapped to that type's listeners. Types contributed by subscribers are
 * included, because addSubscriber() attaches through the regular listener
 * pipeline.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Enumerable, getListenerMap);
