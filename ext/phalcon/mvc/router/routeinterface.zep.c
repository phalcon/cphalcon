
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
 * Phalcon\Mvc\Router\RouteInterface
 *
 * Interface for Phalcon\Mvc\Router\Route
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_RouteInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Router, RouteInterface, phalcon, mvc_router_routeinterface, phalcon_mvc_router_routeinterface_method_entry);

	return SUCCESS;

}

/**
 * Replaces placeholders from pattern returning a valid PCRE regular expression
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, compilePattern);
/**
 * Adds a converter to perform an additional transformation for certain parameter.
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, convert);
/**
 * Returns the route's pattern
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getCompiledPattern);
/**
 * Returns the hostname restriction if any
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getHostname);
/**
 * Returns the HTTP methods that constraint matching the route
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getHttpMethods);
/**
 * Returns the route's name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getName);
/**
 * Returns the paths
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getPaths);
/**
 * Returns the route's pattern
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getPattern);
/**
 * Returns the paths using positions as keys and names as values
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getReversedPaths);
/**
 * Returns the route's id
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getRouteId);
/**
 * Sets a hostname restriction to the route
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, setHostname);
/**
 * Sets a set of HTTP methods that constraint the matching of the route
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, setHttpMethods);
/**
 * Sets the route's name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, setName);
/**
 * Reconfigure the route adding a new pattern and a set of paths
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, reConfigure);
/**
 * Resets the internal route id generator
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, reset);
/**
 * Set one or more HTTP methods that constraint the matching of the route
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, via);
