
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
 * Central registry of the array shapes used across the Config namespace.
 *
 * @phpstan-type config_data array<array-key, mixed>
 * @phpstan-type config_callbacks array<string, callable>
 * @phpstan-type config_options array{
 *     adapter?: string,
 *     filePath?: string,
 *     config?: config_data,
 *     mode?: string|null,
 *     callbacks?: config_callbacks|null,
 * }
 * @phpstan-type config_options_resolved array{
 *     adapter: string,
 *     filePath: string,
 *     config?: config_data,
 *     mode?: string|null,
 *     callbacks?: config_callbacks|null,
 * }
 * @phpstan-type config_extra_arguments array<string, array{
 *     option: string|null,
 *     default: mixed,
 * }>
 * @phpstan-type config_grouped_entries array<array-key, ConfigInterface|config_options|string>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Config_ConfigTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Config, ConfigTypes, phalcon, contracts_config_configtypes, NULL);

	return SUCCESS;
}

