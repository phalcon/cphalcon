
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

namespace Phalcon\Mvc;

/**
 * Phalcon\Mvc\Url
 *
 * This components aids in the generation of: URIs, URLs and Paths
 *
 *<code>
 *
 * //Generate a URL appending the URI to the base URI
 * echo $url->get('products/edit/1');
 *
 * //Generate a URL for a predefined route
 * echo $url->get(array('for' => 'blog-post', 'title' => 'some-cool-stuff', 'year' => '2012'));
 *
 *</code>
 */
class Url //implements Phalcon\Mvc\UrlInterface, Phalcon\Di\InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _baseUri = null;

	protected _staticBaseUri = null;

	protected _basePath = null;

	protected _router;

	/**
	 * Sets the DependencyInjector container
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<Phalcon\DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the DependencyInjector container
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <Phalcon\DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets a prefix for all the URIs to be generated
     *
	 *<code>
	 *	$url->setBaseUri('/invo/');
	 *	$url->setBaseUri('/invo/index.php/');
	 *</code>
	 *
	 * @param string baseUri
	 * @return Phalcon\Mvc\Url
	 */
	public function setBaseUri(string baseUri) -> <Phalcon\Mvc\Url>
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
	 *	$url->setStaticBaseUri('/invo/');
	 *</code>
	 *
	 * @param string staticBaseUri
	 * @return Phalcon\Mvc\Url
	 */
	public function setStaticBaseUri(string staticBaseUri) -> <Phalcon\Mvc\Url>
	{
		let this->_staticBaseUri = staticBaseUri;
		return this;
	}

	/**
	 * Returns the prefix for all the generated urls. By default /
	 *
	 * @return string
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
	 *
	 * @return string
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
	 *	$url->setBasePath('/var/www/htdocs/');
	 *</code>
	 *
	 * @param string basePath
	 * @return Phalcon\Mvc\Url
	 */
	public function setBasePath(string basePath) -> <Phalcon\Mvc\Url>
	{
		let this->_basePath = basePath;
		return this;
	}

	/**
	 * Returns the base path
	 *
	 * @return string
	 */
	public function getBasePath() -> string
	{
		return this->_basePath;
	}

	private function replacePaths(pattern, paths, uri)
	{

	}

	/**
	 * Generates a URL
	 *
	 *<code>
	 *
	 * //Generate a URL appending the URI to the base URI
	 * echo $url->get('products/edit/1');
	 *
	 * //Generate a URL for a predefined route
	 * echo $url->get(array('for' => 'blog-post', 'title' => 'some-cool-stuff', 'year' => '2012'));
	 *
	 *</code>
	 *
	 * @param string|array uri
	 * @return string
	 */
	public function get(var uri=null)
	{
		var baseUri, router, dependencyInjector, routeName, route;

		let baseUri = this->getBaseUri();

		if typeof uri == "array" {

			if !fetch routeName, uri["for"] {
				throw new Phalcon\Mvc\Url\Exception("It's necessary to define the route name with the parameter 'for'");
			}

			let router =  <Phalcon\Mvc\RouterInterface> this->_router;

			/**
			 * Check if the router has not previously set
			 */
			if typeof router != "object" {

				let dependencyInjector = <Phalcon\DiInterface> this->_dependencyInjector;
				if typeof dependencyInjector != "object" {
					throw new Phalcon\Mvc\Url\Exception("A dependency injector container is required to obtain the 'router' service");
				}

				let router = <Phalcon\Mvc\RouterInterface> dependencyInjector->getShared("router"),
					this->_router = router;
			}

			/**
			 * Every route is uniquely differenced by a name
			 */
			let route = <Phalcon\Mvc\Router\RouteInterface> router->getRouteByName(routeName);
			if typeof route != "object" {
				throw new Phalcon\Mvc\Url\Exception("Cannot obtain a route using the name '" . routeName . "'");
			}

			/**
			 * Replace the patterns by its variables
			 */
			return baseUri . this->replacePaths(route->getPattern(), route->getReversedPaths(), uri);
		}

		return baseUri . uri;
	}

	/**
	 * Generates a URL for a static resource
	 *
	 * @param string|array uri
	 * @return string
	 */
	public function getStatic(uri=null) -> string
	{
		var staticBaseUri;
		let staticBaseUri = this->_staticBaseUri;
		if staticBaseUri !== null {
			return staticBaseUri . uri;
		}
		return this->getBaseUri() . uri;
	}

	/**
	 * Generates a local path
	 *
	 * @param string path
	 * @return string
	 */
	public function path(path=null) -> string
	{
		return this->_basePath . path;
	}

}
