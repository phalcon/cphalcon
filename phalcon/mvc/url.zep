
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
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

namespace Phalcon\Mvc;

use Phalcon\DiInterface;
use Phalcon\Mvc\UrlInterface;
use Phalcon\Mvc\Url\Exception;
use Phalcon\Mvc\RouterInterface;
use Phalcon\Mvc\Router\RouteInterface;
use Phalcon\Di\InjectionAwareInterface;

/**
 * Phalcon\Mvc\Url
 *
 * This components helps in the generation of: URIs, URLs and Paths
 *
 *<code>
 * // Generate a URL appending the URI to the base URI
 * echo $url->get("products/edit/1");
 *
 * // Generate a URL for a predefined route
 * echo $url->get(
 *     [
 *         "for"   => "blog-post",
 *         "title" => "some-cool-stuff",
 *         "year"  => "2012",
 *     ]
 * );
 *</code>
 */
class Url implements UrlInterface, InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _baseUri = null;

	protected _staticBaseUri = null;

	protected _basePath = null;

	protected _router;

	/**
	 * Sets the DependencyInjector container
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the DependencyInjector container
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets a prefix for all the URIs to be generated
	 *
	 *<code>
	 * $url->setBaseUri("/invo/");
	 *
	 * $url->setBaseUri("/invo/index.php/");
	 *</code>
	 */
	public function setBaseUri(string! baseUri) -> <Url>
	{
		let this->_baseUri = baseUri;
		if this->_staticBaseUri === null {
			let this->_staticBaseUri = baseUri;
		}
		return this;
	}

	/**
	 * Sets a prefix for all static URLs generated
	 *
	 *<code>
	 * $url->setStaticBaseUri("/invo/");
	 *</code>
	 */
	public function setStaticBaseUri(string! staticBaseUri) -> <Url>
	{
		let this->_staticBaseUri = staticBaseUri;
		return this;
	}

	/**
	 * Returns the prefix for all the generated urls. By default /
	 */
	public function getBaseUri() -> string
	{
		var baseUri, phpSelf, uri;

		let baseUri = this->_baseUri;
		if baseUri === null {

			if fetch phpSelf, _SERVER["PHP_SELF"] {
				let uri = phalcon_get_uri(phpSelf);
			} else {
				let uri = null;
			}

			if !uri {
				let baseUri = "/";
			} else {
				let baseUri = "/" . uri ."/";
			}

			let this->_baseUri = baseUri;
		}
		return baseUri;
	}

	/**
	 * Returns the prefix for all the generated static urls. By default /
	 */
	public function getStaticBaseUri() -> string
	{
		var staticBaseUri;
		let staticBaseUri = this->_staticBaseUri;
		if staticBaseUri !== null {
			return staticBaseUri;
		}
		return this->getBaseUri();
	}

	/**
	 * Sets a base path for all the generated paths
	 *
	 *<code>
	 * $url->setBasePath("/var/www/htdocs/");
	 *</code>
	 */
	public function setBasePath(string! basePath) -> <Url>
	{
		let this->_basePath = basePath;
		return this;
	}

	/**
	 * Returns the base path
	 */
	public function getBasePath() -> string
	{
		return this->_basePath;
	}

	/**
	 * Generates a URL
	 *
	 *<code>
	 * // Generate a URL appending the URI to the base URI
	 * echo $url->get("products/edit/1");
	 *
	 * // Generate a URL for a predefined route
	 * echo $url->get(
	 *     [
	 *         "for"   => "blog-post",
	 *         "title" => "some-cool-stuff",
	 *         "year"  => "2015",
	 *     ]
	 * );
	 *
	 * // Generate a URL with GET arguments (/show/products?id=1&name=Carrots)
	 * echo $url->get(
	 *     "show/products",
	 *     [
	 *         "id"   => 1,
	 *         "name" => "Carrots",
	 *     ]
	 * );
	 *
	 * // Generate an absolute URL by setting the third parameter as false.
	 * echo $url->get(
	 *     "https://phalconphp.com/",
	 *     null,
	 *     false
	 * );
	 *</code>
	 */
	public function get(var uri = null, var args = null, var local = null, var baseUri = null) -> string
	{
		string strUri;
		var router, dependencyInjector, routeName, route, queryString;

		if local == null {
			if typeof uri == "string" && (memstr(uri, "//") || memstr(uri, ":")) {
				if preg_match("#^((//)|([a-z0-9]+://)|([a-z0-9]+:))#i", uri) {
					let local = false;
				} else {
					let local = true;
				}
			} else {
				let local = true;
			}
		}

		if typeof baseUri != "string" {
			let baseUri = this->getBaseUri();
		}

		if typeof uri == "array" {

			if !fetch routeName, uri["for"] {
				throw new Exception("It's necessary to define the route name with the parameter 'for'");
			}

			let router = <RouterInterface> this->_router;

			/**
			 * Check if the router has not previously set
			 */
			if typeof router != "object" {

				let dependencyInjector = <DiInterface> this->_dependencyInjector;
				if typeof dependencyInjector != "object" {
					throw new Exception("A dependency injector container is required to obtain the 'router' service");
				}

				let router = <RouterInterface> dependencyInjector->getShared("router"),
					this->_router = router;
			}

			/**
			 * Every route is uniquely differenced by a name
			 */
			let route = <RouteInterface> router->getRouteByName(routeName);
			if typeof route != "object" {
				throw new Exception("Cannot obtain a route using the name '" . routeName . "'");
			}

			/**
			 * Replace the patterns by its variables
			 */
			let uri = phalcon_replace_paths(route->getPattern(), route->getReversedPaths(), uri);
		}

		if local {
			let strUri = (string) uri;
			if baseUri == "/" && strlen(strUri) > 2 && strUri[0] == '/' && strUri[1] != '/' {
				let uri = baseUri . substr(strUri, 1);
			} else {
				if baseUri == "/" && strlen(strUri) == 1 && strUri[0] == '/' {
					let uri = baseUri;
				} else {
					let uri = baseUri . strUri;
				}
			}
		}

		if args {
			let queryString = http_build_query(args);
			if typeof queryString == "string" && strlen(queryString) {
				if strpos(uri, "?") !== false {
					let uri .= "&" . queryString;
				} else {
					let uri .= "?" . queryString;
				}
			}
		}

		return uri;
	}

	/**
	 * Generates a URL for a static resource
	 *
	 *<code>
	 * // Generate a URL for a static resource
	 * echo $url->getStatic("img/logo.png");
	 *
	 * // Generate a URL for a static predefined route
	 * echo $url->getStatic(
	 *     [
	 *         "for" => "logo-cdn",
	 *     ]
	 * );
	 *</code>
	 */
	public function getStatic(var uri = null) -> string
	{
		return this->get(uri, null, null, this->getStaticBaseUri());
	}

	/**
	 * Generates a local path
	 */
	public function path(string path = null) -> string
	{
		return this->_basePath . path;
	}
}
