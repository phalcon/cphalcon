
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\DiInterface;
use Phalcon\UrlInterface;
use Phalcon\Url\Exception;
use Phalcon\Mvc\RouterInterface;
use Phalcon\Mvc\Router\RouteInterface;
use Phalcon\Di\InjectionAwareInterface;

/**
 * Phalcon\Url
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

	/**
	 * @var null | string
	 */
	protected baseUri = null;

	/**
	 * @var null | string
	 */
	protected basePath = null;

	/**
	 * @var <DiInterface>
	 */
	protected container;

	protected router;

	/**
	 * @var null | string
	 */
	protected staticBaseUri = null;

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
	public function get(var uri = null, var args = null, bool local = null, var baseUri = null) -> string
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

			let router = <RouterInterface> this->router;

			/**
			 * Check if the router has not previously set
			 */
			if typeof router != "object" {

				let dependencyInjector = <DiInterface> this->container;
				if typeof dependencyInjector != "object" {
					throw new Exception("A dependency injector container is required to obtain the 'router' service");
				}

				let router = <RouterInterface> dependencyInjector->getShared("router"),
					this->router = router;
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
			if substr(baseUri, -1) == "/" && strlen(strUri) > 2 && strUri[0] == '/' && strUri[1] != '/' {
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
	 * Returns the base path
	 */
	public function getBasePath() -> string
	{
		return this->basePath;
	}

	/**
	 * Returns the prefix for all the generated urls. By default /
	 */
	public function getBaseUri() -> string
	{
		var baseUri, phpSelf, uri;

		let baseUri = this->baseUri;
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

			let this->baseUri = baseUri;
		}
		return baseUri;
	}

	/**
	 * Returns the DependencyInjector container
	 */
	public function getDI() -> <DiInterface>
	{
		return this->container;
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
	 * Returns the prefix for all the generated static urls. By default /
	 */
	public function getStaticBaseUri() -> string
	{
		var staticBaseUri;
		let staticBaseUri = this->staticBaseUri;
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
	public function setBasePath(string! basePath) -> <UrlInterface>
	{
		let this->basePath = basePath;
		return this;
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
	public function setBaseUri(string! baseUri) -> <UrlInterface>
	{
		let this->baseUri = baseUri;
		if this->staticBaseUri === null {
			let this->staticBaseUri = baseUri;
		}
		return this;
	}

	/**
	 * Sets the DependencyInjector container
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->container = dependencyInjector;
	}

	/**
	 * Sets a prefix for all static URLs generated
	 *
	 *<code>
	 * $url->setStaticBaseUri("/invo/");
	 *</code>
	 */
	public function setStaticBaseUri(string! staticBaseUri) -> <UrlInterface>
	{
		let this->staticBaseUri = staticBaseUri;
		return this;
	}

	/**
	 * Generates a local path
	 */
	public function path(string path = null) -> string
	{
		return this->basePath . path;
	}
}
