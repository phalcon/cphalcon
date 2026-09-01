
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Support;

/**
 * Central registry of the array shapes used across the Support namespace.
 *
 * @phpstan-type support_collection array<array-key, mixed>
 * @phpstan-type support_helper_services array<string, class-string>
 * @phpstan-type support_debug_styles array<string, string>
 * @phpstan-type support_debug_templates array<string, string>
 * @phpstan-type support_debug_blacklist array{
 *     request: array<string, int>,
 *     server: array<string, int>,
 * }
 * @phpstan-type support_debug_blacklist_input array{
 *     request?: array<array-key, string>,
 *     server?: array<array-key, string>,
 * }
 * @phpstan-type support_debug_superglobal array<array-key, mixed>
 * @phpstan-type support_debug_included_files array<array-key, string>
 * @phpstan-type support_debug_args array<array-key, mixed>
 * @phpstan-type support_debug_variable array{
 *     0: mixed,
 *     1: array<array-key, mixed>,
 *     2: int,
 * }
 * @phpstan-type support_debug_variables array<array-key, support_debug_variable>
 * @phpstan-type support_debug_fragment array{
 *     mode: string,
 *     firstLine: int,
 *     line: int,
 *     lastLine: int,
 *     lines: array<int, string>,
 * }
 * @phpstan-type support_debug_trace array{
 *     function: string,
 *     line?: int,
 *     file?: string,
 *     class?: class-string,
 *     type?: string,
 *     args?: array<array-key, mixed>,
 *     object?: object,
 * }
 */
interface SupportTypes
{
}
