
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */

namespace Phalcon\ADR\Front;

/**
 * Concrete default HTTP front controller. Boots the ADR provider and runs the
 * application with the framework defaults; subclass to override
 * `loadEnvironment()` or `registerProviders()`.
 */
class HttpFront extends AbstractHttpFront
{
}
