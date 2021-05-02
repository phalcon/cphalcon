
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cli\Router;

/**
 * Interface for Phalcon\Cli\Router\Route
 */
interface RouteInterface
{
    /**
     * Replaces placeholders from pattern returning a valid PCRE regular
     * expression
     */
    public function compilePattern(string! pattern) -> string;

    /**
     * Set the routing delimiter
     */
    public static function delimiter(string! delimiter = null);

    /**
     * Returns the route's pattern
     */
    public function getCompiledPattern() -> string;

    /**
     * Get routing delimiter
     */
    public static function getDelimiter() -> string;

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
     */
    public function getPaths() -> array;

    /**
     * Returns the route's pattern
     */
    public function getPattern() -> string;

    /**
     * Returns the paths using positions as keys and names as values
     */
    public function getReversedPaths() -> array;

    /**
     * Returns the route's id
     */
    public function getRouteId() -> string;

    /**
     * Reconfigure the route adding a new pattern and a set of paths
     *
     * @param string pattern
     * @param array|string|null paths
     *
     * @return void
     */
    public function reConfigure(string! pattern, var paths = null) -> void;

    /**
     * Resets the internal route id generator
     */
    public static function reset() -> void;

    /**
     * Sets the route's description
     */
    public function setDescription(string! description) -> <RouteInterface>;

    /**
     * Sets the route's name
     */
    public function setName(string name) -> <RouteInterface>;
}
