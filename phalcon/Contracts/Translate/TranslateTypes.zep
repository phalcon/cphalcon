
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Translate;

/**
 * Central registry of the array shapes used across the Translate namespace.
 *
 * @phpstan-type translate_placeholders array<string, string>
 * @phpstan-type translate_data array<string, string>
 * @phpstan-type translate_adapter_options array{
 *     defaultInterpolator?: string,
 *     triggerError?: bool,
 * }
 * @phpstan-type translate_array_options array{
 *     defaultInterpolator?: string,
 *     triggerError?: bool,
 *     content?: mixed,
 * }
 * @phpstan-type translate_csv_options array{
 *     defaultInterpolator?: string,
 *     triggerError?: bool,
 *     content?: string,
 *     delimiter?: string,
 *     enclosure?: string,
 *     escape?: string,
 * }
 * @phpstan-type translate_gettext_options array{
 *     defaultInterpolator?: string,
 *     triggerError?: bool,
 *     locale?: array<array-key, string>,
 *     defaultDomain?: string,
 *     directory?: translate_data|string,
 *     category?: int,
 * }
 * @phpstan-type translate_gettext_defaults array{
 *     category: int,
 *     defaultDomain: string,
 * }
 * @phpstan-type translate_factory_config array{
 *     adapter: string,
 *     options?: array<string, mixed>,
 * }
 */
interface TranslateTypes
{
}
