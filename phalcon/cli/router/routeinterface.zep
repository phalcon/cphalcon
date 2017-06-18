
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
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

}
