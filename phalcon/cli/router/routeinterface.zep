
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cli\Router;

/**
 * Phalcon\Cli\Router\RouteInterface
 *
 * Interface for Phalcon\Cli\Router\Route
 */
interface RouteInterface
{
	/**
	 * Replaces placeholders from pattern returning a valid PCRE regular expression
	 */
	public function compilePattern(string! pattern) -> string;

	/**
	 * Reconfigure the route adding a new pattern and a set of paths
	 */
	public function reConfigure(string! pattern, var paths = null) -> void;

	/**
	 * Returns the route's name
	 */
	public function getName() -> string;

	/**
	 * Sets the route's name
	 */
	public function setName(string name) -> void;

	/**
	 * Returns the route's id
	 */
	public function getRouteId() -> string;

	/**
	 * Returns the route's pattern
	 */
	public function getPattern() -> string;

	/**
	 * Returns the route's pattern
	 */
	public function getCompiledPattern() -> string;

	/**
	 * Returns the paths
	 */
	public function getPaths() -> array;

	/**
	 * Returns the paths using positions as keys and names as values
	 */
	public function getReversedPaths() -> array;

	/**
	 * Resets the internal route id generator
	 */
	public static function reset() -> void;

	/**
	 * Set the routing delimiter
	 */
	public static function delimiter(string! delimiter = null);

	/**
	 * Get routing delimiter
	 */
	public static function getDelimiter() -> string;
}
