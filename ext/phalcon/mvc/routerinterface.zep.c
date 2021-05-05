
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
 * Interface for Phalcon\Mvc\Router
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_RouterInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, RouterInterface, phalcon, mvc_routerinterface, phalcon_mvc_routerinterface_method_entry);

	return SUCCESS;
}

/**
 * Adds a route to the router on any HTTP method
 *
 * @param string pattern
 * @param array|string|null paths
 * @param array|string|null httpMethods
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, add);
/**
 * Attach Route object to the routes stack.
 *
 * @param RouteInterface route
 * @param int position
 *
 * @return RouterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, attach);
/**
 * Adds a route to the router that only match if the HTTP method is CONNECT
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addConnect);
/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addDelete);
/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addHead);
/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addGet);
/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addOptions);
/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addPatch);
/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addPost);
/**
 * Adds a route to the router that only match if the HTTP method is PURGE
 * (Squid and Varnish support)
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addPurge);
/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addPut);
/**
 * Adds a route to the router that only match if the HTTP method is TRACE
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addTrace);
/**
 * Removes all the defined routes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, clear);
/**
 * Returns processed action name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getActionName);
/**
 * Returns processed controller name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getControllerName);
/**
 * Returns the route that matches the handled URI
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getMatchedRoute);
/**
 * Return the sub expressions in the regular expression matched
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getMatches);
/**
 * Returns processed module name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getModuleName);
/**
 * Returns processed namespace name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getNamespaceName);
/**
 * Returns processed extra params
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getParams);
/**
 * Return all the routes defined in the router
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getRoutes);
/**
 * Returns a route object by its id
 *
 * @return RouteInterface|bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getRouteById);
/**
 * Returns a route object by its name
 *
 * @return RouteInterface|bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getRouteByName);
/**
 * Handles routing information received from the rewrite engine
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, handle);
/**
 * Mounts a group of routes in the router
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, mount);
/**
 * Sets the default action name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, setDefaultAction);
/**
 * Sets the default controller name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, setDefaultController);
/**
 * Sets the name of the default module
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, setDefaultModule);
/**
 * Sets an array of default paths
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, setDefaults);
/**
 * Check if the router matches any of the defined routes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, wasMatched);
