
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
 * Phalcon\Mvc\Router\GroupInterface
 *
 *```php
 * $router = new \Phalcon\Mvc\Router();
 *
 * // Create a group with a common module and controller
 * $blog = new Group(
 *     [
 *         "module"     => "blog",
 *         "controller" => "index",
 *     ]
 * );
 *
 * // All the routes start with /blog
 * $blog->setPrefix("/blog");
 *
 * // Add a route to the group
 * $blog->add(
 *     "/save",
 *     [
 *         "action" => "save",
 *     ]
 * );
 *
 * // Add another route to the group
 * $blog->add(
 *     "/edit/{id}",
 *     [
 *         "action" => "edit",
 *     ]
 * );
 *
 * // This route maps to a controller different than the default
 * $blog->add(
 *     "/blog",
 *     [
 *         "controller" => "about",
 *         "action"     => "index",
 *     ]
 * );
 *
 * // Add the group to the router
 * $router->mount($blog);
 *```
 */
interface GroupInterface
{
    /**
     * Adds a route to the router on any HTTP method
     *
     *```php
     * router->add("/about", "About::index");
     *```
     *
     * @param string pattern
     * @param array|string|null paths
     * @param array|string|null httpMethods
     *
     * @return RouteInterface
     */
    public function add(string! pattern, var paths = null, var httpMethods = null) -> <RouteInterface>;

    /**
     * Adds a route to the router that only match if the HTTP method is CONNECT
     *
     * @param string pattern
     * @param array|string|null paths
     *
     * @return RouteInterface
     */
    public function addConnect(string! pattern, var paths = null) -> <RouteInterface>;

    /**
     * Adds a route to the router that only match if the HTTP method is DELETE
     *
     * @param string pattern
     * @param array|string|null paths
     *
     * @return RouteInterface
     */
    public function addDelete(string! pattern, var paths = null) -> <RouteInterface>;

    /**
     * Adds a route to the router that only match if the HTTP method is GET
     *
     * @param string pattern
     * @param array|string|null paths
     *
     * @return RouteInterface
     */
    public function addGet(string! pattern, var paths = null) -> <RouteInterface>;

    /**
     * Adds a route to the router that only match if the HTTP method is HEAD
     *
     * @param string pattern
     * @param array|string|null paths
     *
     * @return RouteInterface
     */
    public function addHead(string! pattern, var paths = null) -> <RouteInterface>;

    /**
     * Add a route to the router that only match if the HTTP method is OPTIONS
     *
     * @param string pattern
     * @param array|string|null paths
     *
     * @return RouteInterface
     */
    public function addOptions(string! pattern, var paths = null) -> <RouteInterface>;

    /**
     * Adds a route to the router that only match if the HTTP method is PATCH
     *
     * @param string pattern
     * @param array|string|null paths
     *
     * @return RouteInterface
     */
    public function addPatch(string! pattern, var paths = null) -> <RouteInterface>;

    /**
     * Adds a route to the router that only match if the HTTP method is POST
     *
     * @param string pattern
     * @param array|string|null paths
     *
     * @return RouteInterface
     */
    public function addPost(string! pattern, var paths = null) -> <RouteInterface>;

    /**
     * Adds a route to the router that only match if the HTTP method is PURGE
     *
     * @param string pattern
     * @param array|string|null paths
     *
     * @return RouteInterface
     */
    public function addPurge(string! pattern, var paths = null) -> <RouteInterface>;

    /**
     * Adds a route to the router that only match if the HTTP method is PUT
     *
     * @param string pattern
     * @param array|string|null paths
     *
     * @return RouteInterface
     */
    public function addPut(string! pattern, var paths = null) -> <RouteInterface>;

    /**
     * Adds a route to the router that only match if the HTTP method is TRACE
     *
     * @param string pattern
     * @param array|string|null paths
     *
     * @return RouteInterface
     */
    public function addTrace(string! pattern, var paths = null) -> <RouteInterface>;

    /**
     * Sets a callback that is called if the route is matched.
     * The developer can implement any arbitrary conditions here
     * If the callback returns false the route is treated as not matched
     */
    public function beforeMatch(callable beforeMatch) -> <GroupInterface>;

    /**
     * Removes all the pre-defined routes
     */
    public function clear() -> void;

    /**
     * Returns the 'before match' callback if any
     */
    public function getBeforeMatch() -> callable;

    /**
     * Returns the hostname restriction
     */
    public function getHostname() -> string;

    /**
     * Returns the common paths defined for this group
     */
    public function getPaths() -> array | string;

    /**
     * Returns the common prefix for all the routes
     */
    public function getPrefix() -> string;

    /**
     * Returns the routes added to the group
     */
    public function getRoutes() -> <RouteInterface[]>;

    /**
     * Set a hostname restriction for all the routes in the group
     */
    public function setHostname(string hostname) -> <GroupInterface>;

    /**
     * Set common paths for all the routes in the group
     *
     * @param array paths
     */
    public function setPaths(var paths) -> <GroupInterface>;

    /**
     * Set a common uri prefix for all the routes in this group
     */
    public function setPrefix(string prefix) -> <GroupInterface>;
}
