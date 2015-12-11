
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\Router\RouteInterface
 *
 * Interface for Phalcon\Mvc\Router\Route
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_RouteInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Router, RouteInterface, phalcon, mvc_router_routeinterface, phalcon_mvc_router_routeinterface_method_entry);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Router\Route constructor
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, __construct);

/**
 * Replaces placeholders from pattern returning a valid PCRE regular expression
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, compilePattern);

/**
 * Set one or more HTTP methods that constraint the matching of the route
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, via);

/**
 * Reconfigure the route adding a new pattern and a set of paths
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, reConfigure);

/**
 * Returns the route's name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getName);

/**
 * Sets the route's name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, setName);

/**
 * Sets a set of HTTP methods that constraint the matching of the route
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, setHttpMethods);

/**
 * Returns the route's id
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getRouteId);

/**
 * Returns the route's pattern
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getPattern);

/**
 * Returns the route's pattern
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getCompiledPattern);

/**
 * Returns the paths
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getPaths);

/**
 * Returns the paths using positions as keys and names as values
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getReversedPaths);

/**
 * Returns the HTTP methods that constraint matching the route
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getHttpMethods);

/**
 * Resets the internal route id generator
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, reset);

