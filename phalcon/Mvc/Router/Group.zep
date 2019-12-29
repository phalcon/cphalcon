
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Router;

/**
 * Phalcon\Mvc\Router\Group
 *
 * Helper class to create a group of routes with common attributes
 *
 *```php
 * $router = new \Phalcon\Mvc\Router();
 *
 * //Create a group with a common module and controller
 * $blog = new Group(
 *     [
 *         "module"     => "blog",
 *         "controller" => "index",
 *     ]
 * );
 *
 * //All the routes start with /blog
 * $blog->setPrefix("/blog");
 *
 * //Add a route to the group
 * $blog->add(
 *     "/save",
 *     [
 *         "action" => "save",
 *     ]
 * );
 *
 * //Add another route to the group
 * $blog->add(
 *     "/edit/{id}",
 *     [
 *         "action" => "edit",
 *     ]
 * );
 *
 * //This route maps to a controller different than the default
 * $blog->add(
 *     "/blog",
 *     [
 *         "controller" => "about",
 *         "action"     => "index",
 *     ]
 * );
 *
 * //Add the group to the router
 * $router->mount($blog);
 *```
 */
class Group implements GroupInterface
{
    protected beforeMatch;
    protected hostname;
    protected paths;
    protected prefix;
    protected routes = [];

    /**
     * Phalcon\Mvc\Router\Group constructor
     */
    public function __construct(var paths = null)
    {
        if typeof paths == "array" || typeof paths == "string" {
            let this->paths = paths;
        }

        if method_exists(this, "initialize") {
            this->{"initialize"}(paths);
        }
    }

    /**
     * Adds a route to the router on any HTTP method
     *
     *```php
     * $router->add("/about", "About::index");
     *```
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function add(string! pattern, var paths = null, var httpMethods = null) -> <RouteInterface>
    {
        return this->addRoute(pattern, paths, httpMethods);
    }

    /**
     * Adds a route to the router that only match if the HTTP method is CONNECT
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addConnect(string! pattern, var paths = null) -> <RouteInterface>
    {
        return this->addRoute(pattern, paths, "CONNECT");
    }

    /**
     * Adds a route to the router that only match if the HTTP method is DELETE
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addDelete(string! pattern, var paths = null) -> <RouteInterface>
    {
        return this->addRoute(pattern, paths, "DELETE");
    }

    /**
     * Adds a route to the router that only match if the HTTP method is GET
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addGet(string! pattern, var paths = null) -> <RouteInterface>
    {
        return this->addRoute(pattern, paths, "GET");
    }

    /**
     * Adds a route to the router that only match if the HTTP method is HEAD
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addHead(string! pattern, var paths = null) -> <RouteInterface>
    {
        return this->addRoute(pattern, paths, "HEAD");
    }

    /**
     * Add a route to the router that only match if the HTTP method is OPTIONS
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addOptions(string! pattern, var paths = null) -> <RouteInterface>
    {
        return this->addRoute(pattern, paths, "OPTIONS");
    }

    /**
     * Adds a route to the router that only match if the HTTP method is PATCH
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addPatch(string! pattern, var paths = null) -> <RouteInterface>
    {
        return this->addRoute(pattern, paths, "PATCH");
    }

    /**
     * Adds a route to the router that only match if the HTTP method is POST
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addPost(string! pattern, var paths = null) -> <RouteInterface>
    {
        return this->addRoute(pattern, paths, "POST");
    }

    /**
     * Adds a route to the router that only match if the HTTP method is PURGE
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addPurge(string! pattern, var paths = null) -> <RouteInterface>
    {
        return this->addRoute(pattern, paths, "PURGE");
    }

    /**
     * Adds a route to the router that only match if the HTTP method is PUT
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addPut(string! pattern, var paths = null) -> <RouteInterface>
    {
        return this->addRoute(pattern, paths, "PUT");
    }

    /**
     * Adds a route to the router that only match if the HTTP method is TRACE
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    public function addTrace(string! pattern, var paths = null) -> <RouteInterface>
    {
        return this->addRoute(pattern, paths, "TRACE");
    }

    /**
     * Sets a callback that is called if the route is matched.
     * The developer can implement any arbitrary conditions here
     * If the callback returns false the route is treated as not matched
     */
     public function beforeMatch(callable beforeMatch) -> <GroupInterface>
    {
        let this->beforeMatch = beforeMatch;

        return this;
    }

    /**
     * Removes all the pre-defined routes
     */
    public function clear() -> void
    {
        let this->routes = [];
    }

    /**
     * Returns the 'before match' callback if any
     */
    public function getBeforeMatch() -> callable
    {
        return this->beforeMatch;
    }

    /**
     * Returns the hostname restriction
     */
    public function getHostname() -> string
    {
        return this->hostname;
    }

    /**
     * Returns the common paths defined for this group
     */
    public function getPaths() -> array | string
    {
        return this->paths;
    }

    /**
     * Returns the common prefix for all the routes
     */
    public function getPrefix() -> string
    {
        return this->prefix;
    }

    /**
     * Returns the routes added to the group
     */
    public function getRoutes() -> <RouteInterface[]>
    {
        return this->routes;
    }

    /**
     * Set a hostname restriction for all the routes in the group
     */
    public function setHostname(string hostname) -> <GroupInterface>
    {
        let this->hostname = hostname;

        return this;
    }

    /**
     * Set common paths for all the routes in the group
     */
    public function setPaths(var paths) -> <GroupInterface>
    {
        let this->paths = paths;

        return this;
    }

    /**
     * Set a common uri prefix for all the routes in this group
     */
    public function setPrefix(string prefix) -> <GroupInterface>
    {
        let this->prefix = prefix;

        return this;
    }

    /**
     * Adds a route applying the common attributes
     *
     * @param string|array paths = [
     *     'module => '',
     *     'controller' => '',
     *     'action' => '',
     *     'namespace' => ''
     * ]
     */
    protected function addRoute(string! pattern, var paths = null, var httpMethods = null) -> <RouteInterface>
    {
        var mergedPaths, route, defaultPaths, processedPaths;

        /**
         * Check if the paths need to be merged with current paths
         */
        let defaultPaths = this->paths;

        if typeof defaultPaths == "array" {
            if typeof paths == "string" {
                let processedPaths = Route::getRoutePaths(paths);
            } else {
                let processedPaths = paths;
            }

            if typeof processedPaths == "array" {
                /**
                 * Merge the paths with the default paths
                 */
                let mergedPaths = array_merge(defaultPaths, processedPaths);
            } else {
                let mergedPaths = defaultPaths;
            }
        } else {
            let mergedPaths = paths;
        }

        /**
         * Every route is internally stored as a Phalcon\Mvc\Router\Route
         */
        let route = new Route(this->prefix . pattern, mergedPaths, httpMethods),
            this->routes[] = route;

        route->setGroup(this);

        return route;
    }
}
