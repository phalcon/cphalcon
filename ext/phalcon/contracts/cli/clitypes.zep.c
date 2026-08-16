
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
 * Central registry of the array shapes used across the Cli namespace.
 *
 * @phpstan-type cli_arguments array<array-key, mixed>|string
 * @phpstan-type cli_options array<array-key, mixed>
 * @phpstan-type cli_parameters array<array-key, mixed>
 * @phpstan-type cli_router_defaults array{
 *     module?: string,
 *     task?: string,
 *     action?: string,
 *     params?: cli_parameters,
 * }
 * @phpstan-type cli_route_paths array<string, int|string>
 * @phpstan-type cli_route_converters array<array-key, callable>
 * @phpstan-type cli_routes array<string, Route>
 * @phpstan-type cli_route_reversed_paths array<int|string, string>
 * @phpstan-type cli_route_named_params array<string, int>
 * @phpstan-type cli_route_extracted array{0: string, 1: cli_route_named_params}
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Cli_CliTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Cli, CliTypes, phalcon, contracts_cli_clitypes, NULL);

	return SUCCESS;
}

