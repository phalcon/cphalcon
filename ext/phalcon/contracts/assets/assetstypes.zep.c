
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
 * Central registry of the array shapes used across the Assets namespace.
 *
 * @phpstan-type assets_asset_list array<int, AssetInterface>
 * @phpstan-type assets_asset_map array<string, AssetInterface>
 * @phpstan-type assets_attributes array<string, string>
 * @phpstan-type assets_callback array{0: Manager, 1: 'cssLink'|'jsLink'}
 * @phpstan-type assets_codes array<array-key, AssetInterface>
 * @phpstan-type assets_collections array<string, Collection>
 * @phpstan-type assets_filters array<int, FilterInterface>
 * @phpstan-type assets_options array{
 *     sourceBasePath?: string,
 *     targetBasePath?: string
 * }
 * @phpstan-type assets_parameters array{
 *     local?: bool,
 *     type?: string,
 *     rel?: string,
 *     string?: string,
 *     0?: string,
 *     1?: string
 * }
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Assets_AssetsTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Assets, AssetsTypes, phalcon, contracts_assets_assetstypes, NULL);

	return SUCCESS;
}

