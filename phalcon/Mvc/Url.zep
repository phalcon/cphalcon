
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc;

use Phalcon\Di\DiInterface;
use Phalcon\Di\AbstractInjectionAware;
use Phalcon\Mvc\RouterInterface;
use Phalcon\Mvc\Router\RouteInterface;
use Phalcon\Mvc\Url\Exception;
use Phalcon\Mvc\Url\UrlInterface;

/**
 * This components helps in the generation of: URIs, URLs and Paths
 *
 *```php
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
 *```
 */
class Url extends AbstractInjectionAware implements UrlInterface
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
     * @var RouterInterface | null
     */
    protected router = null;

    /**
     * @var null | string
     */
    protected staticBaseUri = null;

    public function __construct(<RouterInterface> router = null)
    {
        let this->router = router;
    }

    /**
     * Generates a URL
     *
     *```php
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
     *     "https://phalcon.io/",
     *     null,
     *     false
     * );
     *```
     *
     * @param array|string uri = [
     *     'for' => '',
     * ]
     */
    public function get(var uri = null, var args = null, bool local = null, var baseUri = null) -> string
    {
        string strUri;
        var router, container, routeName, route, queryString;

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
            if unlikely !fetch routeName, uri["for"] {
                throw new Exception(
                    "It's necessary to define the route name with the parameter 'for'"
                );
            }

            let router = this->router;

            /**
             * Check if the router has not previously set
             */
            if unlikely !router {
                let container = <DiInterface> this->container;

                if unlikely typeof container != "object" {
                    throw new Exception(
                        "A dependency injection container is required to access the 'router' service"
                    );
                }

                if unlikely !container->has("router") {
                    throw new Exception(
                        "A dependency injection container is required to access the 'router' service"
                    );
                }

                let router       = <RouterInterface> container->getShared("router"),
                    this->router = router;
            }

            /**
             * Every route is uniquely differenced by a name
             */
            let route = <RouteInterface> router->getRouteByName(routeName);

            if unlikely typeof route != "object" {
                throw new Exception(
                    "Cannot obtain a route using the name '" . routeName . "'"
                );
            }

            /**
             * Replace the patterns by its variables
             */
            let uri = phalcon_replace_paths(
                route->getPattern(),
                route->getReversedPaths(),
                uri
            );
        }

        if local {
            let strUri = (string) uri;
            let uri = preg_replace("#(?<!:)//+#", "/", baseUri . strUri);
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
     * Generates a URL for a static resource
     *
     *```php
     * // Generate a URL for a static resource
     * echo $url->getStatic("img/logo.png");
     *
     * // Generate a URL for a static predefined route
     * echo $url->getStatic(
     *     [
     *         "for" => "logo-cdn",
     *     ]
     * );
     *```
     *
     * @param array|string uri = [
     *     'for' => ''
     * ]
     */
    public function getStatic(var uri = null) -> string
    {
        return this->get(
            uri,
            null,
            null,
            this->getStaticBaseUri()
        );
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
     *```php
     * $url->setBasePath("/var/www/htdocs/");
     *```
     */
    public function setBasePath(string! basePath) -> <UrlInterface>
    {
        let this->basePath = basePath;

        return this;
    }

    /**
     * Sets a prefix for all the URIs to be generated
     *
     *```php
     * $url->setBaseUri("/invo/");
     *
     * $url->setBaseUri("/invo/index.php/");
     *```
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
     * Sets a prefix for all static URLs generated
     *
     *```php
     * $url->setStaticBaseUri("/invo/");
     *```
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
