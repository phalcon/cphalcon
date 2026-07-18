
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
 * A registered route. Fluent, mutating configuration returned from the router's
 * registration methods.
 */
interface Route
{
    public function withMiddleware(string... classes) -> <Route>;

    public function withName(string name) -> <Route>;
}
