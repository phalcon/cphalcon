
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

use Phalcon\Contracts\ADR\ADRTypes;

/**
 * The result of matching a request against the router: the Action class, the
 * extracted route attributes, the route's middleware and its optional name.
 *
 * @phpstan-import-type adr_middleware_names from ADRTypes
 * @phpstan-import-type adr_route_attributes from ADRTypes
 */
interface RouterMatch
{
    /**
     * @phpstan-return class-string
     */
    public function getAction() -> string;

    /**
     * @phpstan-return adr_route_attributes
     */
    public function getAttributes() -> array;

    /**
     * @phpstan-return adr_middleware_names
     */
    public function getMiddleware() -> array;

    public function getName() -> string | null;
}
