
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Router;

/**
 * Phalcon\Mvc\Router\RouteInterface
 *
 * Interface for Phalcon\Mvc\Router\Route
 */
interface RouteInterface
{

	/**
	 * Phalcon\Mvc\Router\Route constructor
	 */
	public function __construct(string! pattern, var paths = null, var httpMethods = null);

	/**
	 * Replaces placeholders from pattern returning a valid PCRE regular expression
	 */
	public function compilePattern(string! pattern) -> string;

	/**
	 * Set one or more HTTP methods that constraint the matching of the route
	 */
	public function via(var httpMethods) -> void;

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
	 * Sets a set of HTTP methods that constraint the matching of the route
	 */
	public function setHttpMethods(var httpMethods) -> string | array;

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
	 * Returns the HTTP methods that constraint matching the route
	 */
	public function getHttpMethods() -> string | array;

	/**
	 * Resets the internal route id generator
	 */
	public static function reset() -> void;

}
