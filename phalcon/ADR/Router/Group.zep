
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

namespace Phalcon\ADR\Router;

use Phalcon\ADR\Router\Traits\HasMiddleware;
use Phalcon\Contracts\ADR\Router\Group as GroupInterface;
use Phalcon\Contracts\ADR\Router\Route as RouteInterface;

/**
 * A group of routes sharing a path prefix and middleware. Routes registered
 * through the group get the prefix prepended and the group's middleware
 * flattened onto them (set middleware before adding routes).
 */
class Group implements GroupInterface
{
    use HasMiddleware;

    /**
     * @var string
     */
    protected prefix;

    /**
     * @var Router
     */
    protected router;

    public function __construct(string prefix, <Router> router)
    {
        let this->prefix = prefix,
            this->router = router;
    }

    public function add(string pattern, string actionClass, array methods = []) -> <RouteInterface>
    {
        var route;

        let route = this->router->add(this->prefix . pattern, actionClass, methods);
        route->pushMiddleware(this->middleware);

        return route;
    }

    public function delete(string pattern, string actionClass) -> <RouteInterface>
    {
        return this->add(pattern, actionClass, ["DELETE"]);
    }

    public function get(string pattern, string actionClass) -> <RouteInterface>
    {
        return this->add(pattern, actionClass, ["GET"]);
    }

    public function patch(string pattern, string actionClass) -> <RouteInterface>
    {
        return this->add(pattern, actionClass, ["PATCH"]);
    }

    public function post(string pattern, string actionClass) -> <RouteInterface>
    {
        return this->add(pattern, actionClass, ["POST"]);
    }

    public function put(string pattern, string actionClass) -> <RouteInterface>
    {
        return this->add(pattern, actionClass, ["PUT"]);
    }

    public function withMiddleware(string... classes) -> <GroupInterface>
    {
        this->pushMiddleware(classes);

        return this;
    }
}
