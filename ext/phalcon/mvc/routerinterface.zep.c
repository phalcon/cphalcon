
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, setDefaultModule);

/**
 * Sets the default controller name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, setDefaultController);

/**
 * Sets the default action name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, setDefaultAction);

/**
 * Sets an array of default paths
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, setDefaults);

/**
 * Handles routing information received from the rewrite engine
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, handle);

/**
 * Adds a route to the router on any HTTP method
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, add);

/**
 * Adds a route to the router that only match if the HTTP method is GET
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addGet);

/**
 * Adds a route to the router that only match if the HTTP method is POST
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addPost);

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addPut);

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addPatch);

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addDelete);

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addOptions);

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, addHead);

/**
 * Mounts a group of routes in the router
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, mount);

/**
 * Removes all the defined routes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, clear);

/**
 * Returns processed module name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getModuleName);

/**
 * Returns processed namespace name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getNamespaceName);

/**
 * Returns processed controller name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getControllerName);

/**
 * Returns processed action name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getActionName);

/**
 * Returns processed extra params
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getParams);

/**
 * Returns the route that matchs the handled URI
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getMatchedRoute);

/**
 * Return the sub expressions in the regular expression matched
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getMatches);

/**
 * Check if the router macthes any of the defined routes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, wasMatched);

/**
 * Return all the routes defined in the router
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getRoutes);

/**
 * Returns a route object by its id
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getRouteById);

/**
 * Returns a route object by its name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_RouterInterface, getRouteByName);

