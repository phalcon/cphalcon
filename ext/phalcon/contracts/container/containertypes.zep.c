
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
 * Central registry of the array shapes used across the Container namespace.
 *
 * @phpstan-type container_aliases array<string, string>
 * @phpstan-type container_arguments array<array-key, mixed>
 * @phpstan-type container_csv_values array<int, mixed>
 * @phpstan-type container_extenders array<array-key, callable>
 * @phpstan-type container_instance_lifetimes array<string, string>
 * @phpstan-type container_instances array<string, object>
 * @phpstan-type container_parameters array<string, mixed>
 * @phpstan-type container_processors list<Processor>
 * @phpstan-type container_providers array<array-key, Provider>
 * @phpstan-type container_reflection_parameters list<ReflectionParameter>
 * @phpstan-type container_resolved_arguments array<int, mixed>
 * @phpstan-type container_service_names array<int, string>
 * @phpstan-type container_service_tags array<string, list<string>>
 * @phpstan-type container_services array<string, ServiceDefinition>
 * @phpstan-type container_tagged_services list<mixed>
 * @phpstan-type container_tags array<array-key, string>
 * @phpstan-type container_values array<array-key, mixed>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Container_ContainerTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Container, ContainerTypes, phalcon, contracts_container_containertypes, NULL);

	return SUCCESS;
}

