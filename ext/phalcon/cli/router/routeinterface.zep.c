
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Cli\Router\RouteInterface
 *
 * Interface for Phalcon\Cli\Router\Route
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Router_RouteInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Cli\\Router, RouteInterface, phalcon, cli_router_routeinterface, phalcon_cli_router_routeinterface_method_entry);

	return SUCCESS;

}

/**
 * Replaces placeholders from pattern returning a valid PCRE regular expression
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, compilePattern);

/**
 * Reconfigure the route adding a new pattern and a set of paths
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, reConfigure);

/**
 * Returns the route's name
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, getName);

/**
 * Sets the route's name
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, setName);

/**
 * Returns the route's id
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, getRouteId);

/**
 * Returns the route's pattern
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, getPattern);

/**
 * Returns the route's pattern
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, getCompiledPattern);

/**
 * Returns the paths
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, getPaths);

/**
 * Returns the paths using positions as keys and names as values
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, getReversedPaths);

/**
 * Resets the internal route id generator
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, reset);

