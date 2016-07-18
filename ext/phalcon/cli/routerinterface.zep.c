
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Cli\RouterInterface
 *
 * Interface for Phalcon\Cli\Router
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_RouterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Cli, RouterInterface, phalcon, cli_routerinterface, phalcon_cli_routerinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the name of the default module
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, setDefaultModule);

/**
 * Sets the default task name
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, setDefaultTask);

/**
 * Sets the default action name
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, setDefaultAction);

/**
 * Sets an array of default paths
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, setDefaults);

/**
 * Handles routing information received from the rewrite engine
 *
 * @param array arguments
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, handle);

/**
 * Adds a route to the router on any HTTP method
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, add);

/**
 * Returns processed module name
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, getModuleName);

/**
 * Returns processed task name
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, getTaskName);

/**
 * Returns processed action name
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, getActionName);

/**
 * Returns processed extra params
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, getParams);

/**
 * Returns the route that matches the handled URI
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, getMatchedRoute);

/**
 * Return the sub expressions in the regular expression matched
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, getMatches);

/**
 * Check if the router matches any of the defined routes
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, wasMatched);

/**
 * Return all the routes defined in the router
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, getRoutes);

/**
 * Returns a route object by its id
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, getRouteById);

/**
 * Returns a route object by its name
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_RouterInterface, getRouteByName);

