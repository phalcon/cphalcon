
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Router\GroupInterface
 *
 *```php
 * $router = new \Phalcon\Mvc\Router();
 *
 * // Create a group with a common module and controller
 * $blog = new Group(
 *     [
 *         "module"     => "blog",
 *         "controller" => "index",
 *     ]
 * );
 *
 * // All the routes start with /blog
 * $blog->setPrefix("/blog");
 *
 * // Add a route to the group
 * $blog->add(
 *     "/save",
 *     [
 *         "action" => "save",
 *     ]
 * );
 *
 * // Add another route to the group
 * $blog->add(
 *     "/edit/{id}",
 *     [
 *         "action" => "edit",
 *     ]
 * );
 *
 * // This route maps to a controller different than the default
 * $blog->add(
 *     "/blog",
 *     [
 *         "controller" => "about",
 *         "action"     => "index",
 *     ]
 * );
 *
 * // Add the group to the router
 * $router->mount($blog);
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_GroupInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Router, GroupInterface, phalcon, mvc_router_groupinterface, phalcon_mvc_router_groupinterface_method_entry);

	return SUCCESS;
}

/**
 * Adds a route to the router on any HTTP method
 *
 *```php
 * router->add("/about", "About::index");
 *```
 *
 * @param string pattern
 * @param array|string|null paths
 * @param array|string|null httpMethods
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, add);
/**
 * Adds a route to the router that only match if the HTTP method is CONNECT
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addConnect);
/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addDelete);
/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addGet);
/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addHead);
/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addOptions);
/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addPatch);
/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addPost);
/**
 * Adds a route to the router that only match if the HTTP method is PURGE
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addPurge);
/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addPut);
/**
 * Adds a route to the router that only match if the HTTP method is TRACE
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addTrace);
/**
 * Sets a callback that is called if the route is matched.
 * The developer can implement any arbitrary conditions here
 * If the callback returns false the route is treated as not matched
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, beforeMatch);
/**
 * Removes all the pre-defined routes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, clear);
/**
 * Returns the 'before match' callback if any
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, getBeforeMatch);
/**
 * Returns the hostname restriction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, getHostname);
/**
 * Returns the common paths defined for this group
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, getPaths);
/**
 * Returns the common prefix for all the routes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, getPrefix);
/**
 * Returns the routes added to the group
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, getRoutes);
/**
 * Set a hostname restriction for all the routes in the group
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, setHostname);
/**
 * Set common paths for all the routes in the group
 *
 * @param array paths
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, setPaths);
/**
 * Set a common uri prefix for all the routes in this group
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, setPrefix);
