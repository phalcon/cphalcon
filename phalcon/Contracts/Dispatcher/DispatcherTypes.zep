/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Dispatcher;

/**
 * Central registry of the array shapes used across the Dispatcher namespace.
 *
 * @phpstan-type dispatcher_params array<array-key, mixed>
 * @phpstan-type dispatcher_forward array{
 *     namespace?: string,
 *     controller?: string,
 *     task?: string,
 *     action?: string,
 *     params?: dispatcher_params,
 * }
 * @phpstan-type dispatcher_method_map array<string, string>
 * @phpstan-type dispatcher_handler_hashes array<string, bool>
 * @phpstan-type dispatcher_handler_hooks array{0: bool, 1: bool, 2: bool, 3: bool}
 * @phpstan-type dispatcher_hook_cache array<string, dispatcher_handler_hooks>
 * @phpstan-type dispatcher_bound_models array<array-key, mixed>
 */
interface DispatcherTypes
{
}
