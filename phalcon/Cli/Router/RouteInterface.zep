
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cli\Router;

use Phalcon\Contracts\Cli\CliTypes;

/**
 * Interface for Phalcon\Cli\Router\Route
 *
 * Note: `Phalcon\Cli\Router` always constructs and returns the concrete
 * `Phalcon\Cli\Router\Route`, and there is no injection point for an externally
 * built route, so this interface is a marker for type hints rather than an
 * implementable contract. The fluent route API used in practice -
 * `beforeMatch()`, `getBeforeMatch()`, `convert()`, and `getConverters()` - is
 * declared on the concrete `Route` class, not here.
 *
 * @phpstan-import-type cli_route_paths from CliTypes
 * @phpstan-import-type cli_route_reversed_paths from CliTypes
 */
interface RouteInterface
{
    /**
     * Set the routing delimiter
     */
    public static function delimiter( string delimiter = null);

    /**
     * Get routing delimiter
     */
    public static function getDelimiter() -> string;

    /**
     * Resets the internal route id generator
     */
    public static function reset() -> void;

    /**
     * Replaces placeholders from pattern returning a valid PCRE regular
     * expression
     */
    public function compilePattern( string pattern) -> string;

    /**
     * Returns the route's pattern
     */
    public function getCompiledPattern() -> string;

    /**
     * Returns the route's description
     */
    public function getDescription() -> string;

    /**
     * Returns the route's name
     */
    public function getName() -> string;

    /**
     * Returns the paths
     *
     * @phpstan-return cli_route_paths
     */
    public function getPaths() -> array;

    /**
     * Returns the route's pattern
     */
    public function getPattern() -> string;

    /**
     * Returns the paths using positions as keys and names as values
     *
     * @phpstan-return cli_route_reversed_paths
     */
    public function getReversedPaths() -> array;

    /**
     * Returns the route's id
     */
    public function getRouteId() -> string;

    /**
     * Reconfigure the route adding a new pattern and a set of paths
     *
     * @param array|string|null paths
     *
     * @return void
     */
    public function reConfigure( string pattern, var paths = null) -> void;

    /**
     * Sets the route's description
     */
    public function setDescription( string description) -> <RouteInterface>;

    /**
     * Sets the route's name
     */
    public function setName(string name) -> <RouteInterface>;
}
