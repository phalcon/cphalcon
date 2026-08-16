
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 *
 * Implementation of this file has also been heavily influenced by Autoroute.
 *
 * @link    https://pmjones.io/adr/
 *
 * @link    https://github.com/pmjones/AutoRoute
 * @license https://github.com/pmjones/AutoRoute/blob/2.x/LICENSE.md
 */

namespace Phalcon\ADR\Router;

use Phalcon\Contracts\ADR\ADRTypes;
use Phalcon\Contracts\ADR\Router\RouterMatch as RouterMatchInterface;

/**
 * Immutable result of a successful route match.
 *
 * @phpstan-import-type adr_middleware_names from ADRTypes
 * @phpstan-import-type adr_route_attributes from ADRTypes
 */
final class RouterMatch implements RouterMatchInterface
{
    protected string action = "";
    protected array attributes = [];
    protected array middleware = [];
    protected ?string name = null;

    /**
     * @phpstan-param class-string          $action
     * @phpstan-param adr_route_attributes  $attributes
     * @phpstan-param adr_middleware_names  $middleware
     */
    public function __construct(
        string action,
        array attributes = [], 
        array middleware = [], 
        string name = null
    ) {
        let this->action     = action,
            this->attributes = attributes,
            this->middleware = middleware,
            this->name       = name;
    }

    /**
     * @phpstan-return class-string
     */
    public function getAction() -> string
    {
        return this->action;
    }

    /**
     * @phpstan-return adr_route_attributes
     */
    public function getAttributes() -> array
    {
        return this->attributes;
    }

    /**
     * @phpstan-return adr_middleware_names
     */
    public function getMiddleware() -> array
    {
        return this->middleware;
    }

    public function getName() -> string | null
    {
        return this->name;
    }
}
