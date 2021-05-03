
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
 * Interface for Phalcon\Cli\Router\Route
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Router_RouteInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Cli\\Router, RouteInterface, phalcon, cli_router_routeinterface, phalcon_cli_router_routeinterface_method_entry);

	return SUCCESS;
}

/**
 * Replaces placeholders from pattern returning a valid PCRE regular
 * expression
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, compilePattern);
/**
 * Set the routing delimiter
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, delimiter);
/**
 * Returns the route's pattern
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, getCompiledPattern);
/**
 * Get routing delimiter
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, getDelimiter);
/**
 * Returns the route's description
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, getDescription);
/**
 * Returns the route's name
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, getName);
/**
 * Returns the paths
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, getPaths);
/**
 * Returns the route's pattern
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, getPattern);
/**
 * Returns the paths using positions as keys and names as values
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, getReversedPaths);
/**
 * Returns the route's id
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, getRouteId);
/**
 * Reconfigure the route adding a new pattern and a set of paths
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, reConfigure);
/**
 * Resets the internal route id generator
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, reset);
/**
 * Sets the route's description
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, setDescription);
/**
 * Sets the route's name
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_Router_RouteInterface, setName);
