
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include "php.h"
#include "../php_ext.h"
#include "../ext.h"

#include "kernel/main.h"


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
/**
 * Phalcon\Mvc\RouterInterface
 *
 * Interface for Phalcon\Mvc\Router
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_RouterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, RouterInterface, phalcon, mvc_routerinterface, phalcon_mvc_routerinterface_method_entry);


	return SUCCESS;

}

/**
 * Sets the name of the default module
 *
 * @param string moduleName
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, setDefaultModule);

/**
 * Sets the default controller name
 *
 * @param string controllerName
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, setDefaultController);

/**
 * Sets the default action name
 *
 * @param string actionName
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, setDefaultAction);

/**
 * Sets an array of default paths
 *
 * @param array defaults
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, setDefaults);

/**
 * Handles routing information received from the rewrite engine
 *
 * @param string uri
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, handle);

/**
 * Adds a route to the router on any HTTP method
 *
 * @param string pattern
 * @param string/array paths
 * @param string httpMethods
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, add);

/**
 * Adds a route to the router that only match if the HTTP method is GET
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addGet);

/**
 * Adds a route to the router that only match if the HTTP method is POST
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addPost);

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addPut);

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addDelete);

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addOptions);

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 *
 * @param string pattern
 * @param string/array paths
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addHead);

/**
 * Removes all the defined routes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, clear);

/**
 * Returns processed module name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getModuleName);

/**
 * Returns processed controller name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getControllerName);

/**
 * Returns processed action name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getActionName);

/**
 * Returns processed extra params
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getParams);

/**
 * Returns the route that matchs the handled URI
 *
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getMatchedRoute);

/**
 * Return the sub expressions in the regular expression matched
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getMatches);

/**
 * Check if the router macthes any of the defined routes
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, wasMatched);

/**
 * Return all the routes defined in the router
 *
 * @return Phalcon\Mvc\Router\RouteInterface[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getRoutes);

/**
 * Returns a route object by its id
 *
 * @param string id
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getRouteById);

/**
 * Returns a route object by its name
 *
 * @param string name
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getRouteByName);

