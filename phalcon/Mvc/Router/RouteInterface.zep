
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
 * Interface for Phalcon\Mvc\Router\Route
 */
interface RouteInterface
{
    /**
     * Replaces placeholders from pattern returning a valid PCRE regular expression
     */
    public function compilePattern(string! pattern) -> string;

    /**
     * Adds a converter to perform an additional transformation for certain parameter.
     */
    public function convert(string! name, var converter) -> <RouteInterface>;

    /**
     * Returns the route's pattern
     */
    public function getCompiledPattern() -> string;

    /**
     * Returns the hostname restriction if any
     */
    public function getHostname() -> string | null;

    /**
     * Returns the HTTP methods that constraint matching the route
     */
    public function getHttpMethods() -> array | string | null;

    /**
     * Returns the route's name
     */
    public function getName() -> string | null;

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
     */
    public function reConfigure(string! pattern, var paths = null) -> void;

    /**
     * Resets the internal route id generator
     */
    public static function reset() -> void;

    /**
     * Sets a hostname restriction to the route
     */
    public function setHostname(string hostname) -> <RouteInterface>;

    /**
     * Sets a set of HTTP methods that constraint the matching of the route
     */
    public function setHttpMethods(var httpMethods) -> <RouteInterface>;

    /**
     * Sets the route's name
     */
    public function setName(string name) -> <RouteInterface>;

    /**
     * Sets the route's id (intended for restoring cached routes)
     */
    public function setRouteId(string! routeId) -> <RouteInterface>;

    /**
     * Set one or more HTTP methods that constraint the matching of the route
     */
    public function via(var httpMethods) -> <RouteInterface>;
}
