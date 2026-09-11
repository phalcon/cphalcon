
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Di;

/**
 * Central registry of the array shapes used across the Di namespace.
 * @phpstan-type di_parameters array<array-key, mixed>
 * @phpstan-type di_service_argument array{
 *     type?: string,
 *     name?: string,
 *     className?: string,
 *     value?: mixed,
 *     arguments?: di_parameters,
 * }
 * @phpstan-type di_service_call array{
 *     method?: string,
 *     arguments?: array<int, di_service_argument>,
 * }
 * @phpstan-type di_service_property array{
 *     name?: string,
 *     value?: di_service_argument,
 * }
 * @phpstan-type di_service_definition array{
 *     className?: string,
 *     arguments?: array<int, di_service_argument>,
 *     calls?: array<int, di_service_call>,
 *     properties?: array<int, di_service_property>,
 *     shared?: bool,
 * }
 */
interface DiTypes
{
}
