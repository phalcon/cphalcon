
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Assets;

use Phalcon\Assets\AssetInterface;
use Phalcon\Assets\Collection;
use Phalcon\Assets\FilterInterface;
use Phalcon\Assets\Manager;

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
interface AssetsTypes
{
}
