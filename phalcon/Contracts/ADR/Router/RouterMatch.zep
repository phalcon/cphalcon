
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
 * The result of matching a request against the router: the Action class, the
 * extracted route attributes, the route's middleware and its optional name.
 */
interface RouterMatch
{
    public function getAction() -> string;

    public function getAttributes() -> array;

    public function getMiddleware() -> array;

    public function getName() -> string | null;
}
