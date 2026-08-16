/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Application;

use Closure;

/**
 * Central registry of the array shapes used across the Application namespace.
 *
 * @phpstan-type application_module_definition array{
 *     className?: string,
 *     path?: string,
 * }
 * @phpstan-type application_modules array<string, Closure|application_module_definition>
 */
interface ApplicationTypes
{
}
