
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

use Closure;
use Phalcon\ADR\Router\Exceptions\MethodNotAllowed;
use Phalcon\Contracts\ADR\Router\Router as RouterInterface;
use Phalcon\Contracts\ADR\Router\RouterMatch as RouterMatchInterface;
use Phalcon\Http\RequestInterface;

/**
 * The ADR router. Routes are registered by pattern + HTTP method (verb helpers
 * or `add()`), optionally grouped, and matched against the request. `match()`
 * returns a RouterMatch, `null` when nothing matches, or throws
 * MethodNotAllowed when a path matches but the method does not.
 */
final class Router implements RouterInterface
{
    /**
     * @var Route[]
     */
    protected routes = [];

    public function add(string pattern, string actionClass, array methods = []) -> <Route>
    {
        var route;

        let route          = new Route(pattern, actionClass, methods),
            this->routes[] = route;

        return route;
    }

    public function delete(string pattern, string actionClass) -> <Route>
    {
        return this->add(pattern, actionClass, ["DELETE"]);
    }

    public function get(string pattern, string actionClass) -> <Route>
    {
        return this->add(pattern, actionClass, ["GET"]);
    }

    public function group(string prefix, <Closure> configure) -> <Group>
    {
        var group;

        let group = new Group(prefix, this);
        call_user_func(configure, group);

        return group;
    }

    public function match(<RequestInterface> request) -> <RouterMatchInterface> | null
    {
        var uri, method, route, params, methodMismatch;

        let uri            = request->getURI(true),
            method         = request->getMethod(),
            methodMismatch = false;

        for route in this->routes {
            let params = route->matches(uri);

            if params !== false {
                if route->allowsMethod(method) {
                    return new RouterMatch(
                        route->getAction(),
                        params,
                        route->getMiddleware(),
                        route->getName()
                    );
                }

                let methodMismatch = true;
            }
        }

        if methodMismatch {
            throw new MethodNotAllowed("The request method is not allowed for the matched route.");
        }

        return null;
    }

    public function patch(string pattern, string actionClass) -> <Route>
    {
        return this->add(pattern, actionClass, ["PATCH"]);
    }

    public function post(string pattern, string actionClass) -> <Route>
    {
        return this->add(pattern, actionClass, ["POST"]);
    }

    public function put(string pattern, string actionClass) -> <Route>
    {
        return this->add(pattern, actionClass, ["PUT"]);
    }
}
