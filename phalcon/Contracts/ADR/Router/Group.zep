
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

namespace Phalcon\Contracts\ADR\Router;

/**
 * A group of routes sharing a path prefix and middleware. Group middleware is
 * flattened onto each route as it is registered.
 */
interface Group
{
    public function withMiddleware(string... classes) -> <Group>;
}
