
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
	 *
	 * @param string pattern
	 * @param array paths
	 * @param array|string httpMethods
	 */
	public function __construct(pattern, paths=null, httpMethods=null);

	/**
	 * Replaces placeholders from pattern returning a valid PCRE regular expression
	 *
	 * @param string pattern
	 * @return string
	 */
	public function compilePattern(pattern);

	/**
	 * Set one or more HTTP methods that constraint the matching of the route
	 *
	 * @param string|array httpMethods
	 */
	public function via(httpMethods);

	/**
	 * Reconfigure the route adding a new pattern and a set of paths
	 *
	 * @param string pattern
	 * @param array paths
	 */
	public function reConfigure(pattern, paths=null);

	/**
	 * Returns the route's name
	 *
	 * @return string
	 */
	public function getName();

	/**
	 * Sets the route's name
	 *
	 * @param string name
	 */
	public function setName(name);

	/**
	 * Sets a set of HTTP methods that constraint the matching of the route
	 *
	 * @param string|array httpMethods
	 */
	public function setHttpMethods(httpMethods);

	/**
	 * Returns the route's id
	 *
	 * @return string
	 */
	public function getRouteId();

	/**
	 * Returns the route's pattern
	 *
	 * @return string
	 */
	public function getPattern();

	/**
	 * Returns the route's pattern
	 *
	 * @return string
	 */
	public function getCompiledPattern();

	/**
	 * Returns the paths
	 *
	 * @return array
	 */
	public function getPaths();

	/**
	 * Returns the paths using positions as keys and names as values
	 *
	 * @return array
	 */
	public function getReversedPaths();

	/**
	 * Returns the HTTP methods that constraint matching the route
	 *
	 * @return string|array
	 */
	public function getHttpMethods();

	/**
	 * Resets the internal route id generator
	 */
	public static function reset();

}