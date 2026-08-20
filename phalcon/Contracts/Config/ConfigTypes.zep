
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Config;

use Phalcon\Config\ConfigInterface;

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
interface ConfigTypes
{
}
