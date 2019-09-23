
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Micro;

/**
 * Phalcon\Mvc\Micro\Collection
 *
 * Groups Micro-Mvc handlers as controllers
 *
 *```php
 * $app = new \Phalcon\Mvc\Micro();
 *
 * $collection = new Collection();
 *
 * $collection->setHandler(
 *     new PostsController()
 * );
 *
 * $collection->get("/posts/edit/{id}", "edit");
 *
 * $app->mount($collection);
 *```
 */
class Collection implements CollectionInterface
{
    protected handler;

    protected handlers = [];

    protected lazy;

    protected prefix;

    /**
     * Maps a route to a handler that only matches if the HTTP method is DELETE.
     *
     * @param callable|string handler
     */
    public function delete(string! routePattern, var handler, string name = null) -> <CollectionInterface>
    {
        this->addMap("DELETE", routePattern, handler, name);

        return this;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is GET.
     *
     * @param callable|string handler
     */
    public function get(string! routePattern, var handler, string name = null) -> <CollectionInterface>
    {
        this->addMap("GET", routePattern, handler, name);

        return this;
    }

    /**
     * Returns the main handler
     */
    public function getHandler() -> var
    {
        return this->handler;
    }

    /**
     * Returns the registered handlers
     */
    public function getHandlers() -> array
    {
        return this->handlers;
    }

    /**
     * Returns the collection prefix if any
     */
    public function getPrefix() -> string
    {
        return this->prefix;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is HEAD.
     *
     * @param callable|string handler
     */
    public function head(string! routePattern, var handler, string name = null) -> <CollectionInterface>
    {
        this->addMap("HEAD", routePattern, handler, name);

        return this;
    }

    /**
     * Returns if the main handler must be lazy loaded
     */
    public function isLazy() -> bool
    {
        return this->lazy;
    }

    /**
     * Maps a route to a handler.
     *
     * @param callable|string handler
     */
    public function map(string! routePattern, var handler, string name = null) -> <CollectionInterface>
    {
        this->addMap(null, routePattern, handler, name);

        return this;
    }

    /**
     * Maps a route to a handler via methods.
     *
     * ```php
     * $collection->mapVia(
     *     "/test",
     *     "indexAction",
     *     ["POST", "GET"],
     *     "test"
     * );
     * ```
     *
     * @param callable handler
     * @param string|array method
     */
    public function mapVia(string! routePattern, var handler, var method, string name = null) -> <CollectionInterface>
    {
        this->addMap(method, routePattern, handler, name);

        return this;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is
     * OPTIONS.
     *
     * @param callable|string handler
     */
    public function options(string! routePattern, var handler, string name = null) -> <CollectionInterface>
    {
        this->addMap("OPTIONS", routePattern, handler, name);

        return this;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is PATCH.
     *
     * @param callable|string handler
     */
    public function patch(string! routePattern, var handler, string name = null) -> <CollectionInterface>
    {
        this->addMap("PATCH", routePattern, handler, name);

        return this;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is POST.
     *
     * @param callable|string handler
     */
    public function post(string! routePattern, var handler, string name = null) -> <CollectionInterface>
    {
        this->addMap("POST", routePattern, handler, name);

        return this;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is PUT.
     *
     * @param callable|string handler
     */
    public function put(string! routePattern, var handler, string name = null) -> <CollectionInterface>
    {
        this->addMap("PUT", routePattern, handler, name);

        return this;
    }

    /**
     * Sets the main handler.
     *
     * @param callable|string handler
     */
    public function setHandler(var handler, bool lazy = false) -> <CollectionInterface>
    {
        let this->handler = handler,
            this->lazy = lazy;

        return this;
    }

    /**
     * Sets if the main handler must be lazy loaded
     */
    public function setLazy(bool! lazy) -> <CollectionInterface>
    {
        let this->lazy = lazy;

        return this;
    }

    /**
     * Sets a prefix for all routes added to the collection
     */
    public function setPrefix(string! prefix) -> <CollectionInterface>
    {
        let this->prefix = prefix;

        return this;
    }

    /**
     * Internal function to add a handler to the group.
     *
     * @param string|array    method
     * @param callable|string handler
     */
    protected function addMap(var method, string! routePattern, var handler, string name)
    {
        let this->handlers[] = [method, routePattern, handler, name];
    }
}
