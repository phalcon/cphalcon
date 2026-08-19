
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
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * Central registry of the array shapes used across the ADR namespace.
 *
 * This is a type registry, not a contract. It declares no members and must
 * not be implemented; it exists only so that every shape below has a single
 * definition, imported where it is needed with a phpstan-import-type tag
 * naming this interface as the source.
 *
 * Alias names are prefixed with `adr_` because PHPStan resolves imported
 * type names per file and has no namespacing for them: the prefix is what
 * keeps generic names such as `middleware_map` from clashing with an alias
 * imported from another namespace into the same file.
 *
 * @phpstan-type adr_param_rule array{
 *     match?: string,
 *     type?: string,
 *     convert?: callable,
 * }
 * @phpstan-type adr_action_params array<string, adr_param_rule>
 * @phpstan-type adr_route_attributes array<array-key, string>
 * @phpstan-type adr_filtered_attributes array<array-key, mixed>
 * @phpstan-type adr_route_candidate array{0: string, 1: list<string>}
 * @phpstan-type adr_located_route array{0: class-string, 1: list<string>}
 * @phpstan-type adr_middleware_names list<class-string>
 * @phpstan-type adr_middleware_map array<string, adr_middleware_names>
 * @phpstan-type adr_exception_map array<string, string>
 * @phpstan-type adr_error_details array{
 *     message: string,
 *     trace?: string,
 *     ref: string,
 * }
 * @phpstan-type adr_status_map array<string, int>
 * @phpstan-type adr_input_data array<array-key, mixed>
 * @phpstan-type adr_view_data array{
 *     extras: mixed,
 *     result: mixed,
 *     messages: mixed,
 *     status: mixed,
 * }
 * @phpstan-type adr_definition_params array<string, mixed>
 * @phpstan-type adr_cors_config array{
 *     origins?: list<string>,
 *     methods?: list<string>,
 *     headers?: list<string>,
 *     credentials?: bool,
 *     maxAge?: int,
 * }
 * @phpstan-type adr_allowed_methods array<int, string>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_ADRTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\ADR, ADRTypes, phalcon, contracts_adr_adrtypes, NULL);

	return SUCCESS;
}

