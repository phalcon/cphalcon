
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
use Phalcon\Contracts\Cli\CliTypes;

/**
 * Interface for Phalcon\Cli\Router
 *
 * @phpstan-import-type cli_parameters from CliTypes
 * @phpstan-import-type cli_router_defaults from CliTypes
 */
interface RouterInterface
{
    /**
     * Adds a route to the router on any HTTP method
     *
     * @phpstan-param mixed $paths
     */
    public function add( string pattern, var paths = null) -> <RouteInterface>;

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
     *
     * @return array<array-key, string>
     */
    public function getMatches() -> array;

    /**
     * Returns processed module name
     */
    public function getModuleName() -> string;

    /**
     * Returns processed extra params
     *
     * @phpstan-return cli_parameters
     */
    public function getParameters() -> array;

    /**
     * Returns processed extra params
     *
     * @deprecated Use getParameters() instead
     *
     * @phpstan-return cli_parameters
     */
    public function getParams() -> array;

    /**
     * Returns a route object by its id
     *
     * @todo change param type to string
     * @phpstan-param string $id
     */
    public function getRouteById(var id) -> bool | <RouteInterface>;

    /**
     * Returns a route object by its name
     */
    public function getRouteByName( string name) -> bool | <RouteInterface>;

    /**
     * Return all the routes defined in the router
     */
    public function getRoutes() -> <RouteInterface[]>;

    /**
     * Returns processed task name
     */
    public function getTaskName() -> string;

    /**
     * Handles routing information received from the rewrite engine.
     *
     * When `arguments` is a string (or null), it is matched against the
     * registered routes. When it is an array, matching is bypassed entirely:
     * the array is treated as the already-resolved module/task/action/params,
     * so `wasMatched()` stays false and `getMatchedRoute()` returns null even
     * though routing succeeded.
     *
     * @param array|string|null arguments
     */
    public function handle(arguments = null);

    /**
     * Sets the default action name
     */
    public function setDefaultAction( string actionName) -> <RouterInterface>;

    /**
     * Sets the name of the default module
     */
    public function setDefaultModule( string moduleName) -> <RouterInterface>;

    /**
     * Sets an array of default paths
     *
     * @phpstan-param cli_router_defaults $defaults
     */
    public function setDefaults( array defaults) -> <RouterInterface>;

    /**
     * Sets the default task name
     */
    public function setDefaultTask( string taskName) -> <RouterInterface>;

    /**
     * Check if the router matches any of the defined routes
     */
    public function wasMatched() -> bool;
}
