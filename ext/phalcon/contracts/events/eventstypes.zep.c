
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
 * Central registry of the array shapes used across the Events namespace.
 * @phpstan-type events_listener array{0: mixed, 1: int, 2: int, 3?: string|null}
 * @phpstan-type events_method_exists_cache array<string, array<string, bool>>
 * @phpstan-type events_name_cache array<string, array{0: string, 1: string}>
 * @phpstan-type events_queue list<events_listener>
 * @phpstan-type events_storage array<string, events_queue>
 * @phpstan-type events_subscriber_listener array{0: string, 1?: int}
 * @phpstan-type events_subscriber_entry string|events_subscriber_listener|list<events_subscriber_listener>
 * @phpstan-type events_subscribed_events array<string, events_subscriber_entry>
 * @phpstan-type events_subscriber_events_cache array<string, events_subscribed_events>
 * @phpstan-type events_subscribers array<int, Subscriber>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Events_EventsTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Events, EventsTypes, phalcon, contracts_events_eventstypes, NULL);

	return SUCCESS;
}

