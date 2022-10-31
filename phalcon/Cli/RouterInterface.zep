
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cli;

use Phalcon\Cli\Router\RouteInterface;

/**
 * Interface for Phalcon\Cli\Router
 */
interface RouterInterface
{
    /**
     * Adds a route to the router on any HTTP method
     */
    public function add(string! pattern, var paths = null) -> <RouteInterface>;

    /**
     * Returns processed action name
     */
    public function getActionName() -> string;

    /**
     * Returns the route that matches the handled URI
     */
    public function getMatchedRoute() -> <RouteInterface> | null;

    /**
     * Return the sub expressions in the regular expression matched
     */
    public function getMatches() -> array;

    /**
     * Returns processed module name
     */
    public function getModuleName() -> string;

    /**
     * Returns processed extra params
     * @todo deprecate this in the future
     */
    public function getParams() -> array;

    /**
     * Returns processed extra params
     */
    public function getParameters() -> array;

    /**
     * Returns a route object by its id
     */
    public function getRouteById(var id) -> <RouteInterface>;

    /**
     * Returns a route object by its name
     */
    public function getRouteByName(string! name) -> <RouteInterface>;

    /**
     * Return all the routes defined in the router
     */
    public function getRoutes() -> <RouteInterface[]>;

    /**
     * Returns processed task name
     */
    public function getTaskName() -> string;

    /**
     * Handles routing information received from the rewrite engine
     *
     * @param array arguments
     */
    public function handle(arguments = null);

    /**
     * Sets the default action name
     */
    public function setDefaultAction(string! actionName) -> void;

    /**
     * Sets the name of the default module
     */
    public function setDefaultModule(string! moduleName) -> void;

    /**
     * Sets an array of default paths
     */
    public function setDefaults(array! defaults) -> void;

    /**
     * Sets the default task name
     */
    public function setDefaultTask(string! taskName) -> void;

    /**
     * Check if the router matches any of the defined routes
     */
    public function wasMatched() -> bool;
}
