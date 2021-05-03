
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
    /**
     * @var callable
     */
    protected handler;

    /**
     * @var array
     */
    protected handlers = [];

    /**
     * @var bool
     */
    protected lazy = false;

    /**
     * @var string
     */
    protected prefix = "";

    /**
     * Maps a route to a handler that only matches if the HTTP method is DELETE.
     *
     * @param string routePattern
     * @param callable handler
     * @param string|null name
     *
     * @return CollectionInterface
     */
    public function delete(string! routePattern, callable handler, string name = null) -> <CollectionInterface>
    {
        this->addMap("DELETE", routePattern, handler, name);

        return this;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is GET.
     *
     * @param string routePattern
     * @param callable handler
     * @param string|null name
     *
     * @return CollectionInterface
     */
    public function get(string! routePattern, callable handler, string name = null) -> <CollectionInterface>
    {
        this->addMap("GET", routePattern, handler, name);

        return this;
    }

    /**
     * Returns the main handler
     *
     * @return mixed
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
     * @param string routePattern
     * @param callable|string handler
     * @param string|null name
     *
     * @return CollectionInterface
     */
    public function head(string! routePattern, callable handler, string name = null) -> <CollectionInterface>
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
     * @param string routePattern
     * @param callable handler
     * @param string|null name
     *
     * @return CollectionInterface
     */
    public function map(string! routePattern, callable handler, string name = null) -> <CollectionInterface>
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
     * @param string routePattern
     * @param callable handler
     * @param string|array method
     * @param string|null name
     *
     * @return CollectionInterface
     */
    public function mapVia(string! routePattern, callable handler, var method, string name = null) -> <CollectionInterface>
    {
        this->addMap(method, routePattern, handler, name);

        return this;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is
     * OPTIONS.
     *
     * @param string routePattern
     * @param callable handler
     * @param string|null name
     *
     * @return CollectionInterface
     */
    public function options(string! routePattern, callable handler, string name = null) -> <CollectionInterface>
    {
        this->addMap("OPTIONS", routePattern, handler, name);

        return this;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is PATCH.
     *
     * @param string routePattern
     * @param callable handler
     * @param string|null name
     *
     * @return CollectionInterface
     */
    public function patch(string! routePattern, callable handler, string name = null) -> <CollectionInterface>
    {
        this->addMap("PATCH", routePattern, handler, name);

        return this;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is POST.
     *
     * @param string routePattern
     * @param callable handler
     * @param string|null name
     *
     * @return CollectionInterface
     */
    public function post(string! routePattern, callable handler, string name = null) -> <CollectionInterface>
    {
        this->addMap("POST", routePattern, handler, name);

        return this;
    }

    /**
     * Maps a route to a handler that only matches if the HTTP method is PUT.
     *
     * @param string routePattern
     * @param callable handler
     * @param string|null name
     *
     * @return CollectionInterface
     */
    public function put(string! routePattern, callable handler, string name = null) -> <CollectionInterface>
    {
        this->addMap("PUT", routePattern, handler, name);

        return this;
    }

    /**
     * Sets the main handler.
     *
     * @param mixed handler
     * @param bool lazy
     *
     * @return CollectionInterface
     */
    public function setHandler(var handler, bool lazy = false) -> <CollectionInterface>
    {
        let this->handler = handler,
            this->lazy = lazy;

        return this;
    }

    /**
     * Sets if the main handler must be lazy loaded
     *
     * @param bool lazy
     *
     * @return CollectionInterface
     */
    public function setLazy(bool! lazy) -> <CollectionInterface>
    {
        let this->lazy = lazy;

        return this;
    }

    /**
     * Sets a prefix for all routes added to the collection
     *
     * @param string prefix
     *
     * @return CollectionInterface
     */
    public function setPrefix(string! prefix) -> <CollectionInterface>
    {
        let this->prefix = prefix;

        return this;
    }

    /**
     * Internal function to add a handler to the group.
     *
     * @param string|array method
     * @param string routePattern
     * @param callable handler
     * @param string name
     */
    protected function addMap(var method, string! routePattern, callable handler, string name) -> void
    {
        let this->handlers[] = [method, routePattern, handler, name];
    }
}
