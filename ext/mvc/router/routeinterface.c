
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Mvc\Router\RouteInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Router_RouteInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Router, RouteInterface, mvc_router_routeinterface, phalcon_mvc_router_routeinterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Router\Route constructor
 *
 * @param string $pattern
 * @param array $paths
 * @param array|string $httpMethods
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, __construct);

/**
 * Replaces placeholders from pattern returning a valid PCRE regular expression
 *
 * @param string $pattern
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, compilePattern);

/**
 * Set one or more HTTP methods that constraint the matching of the route
 *
 * @param string|array $httpMethods
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, via);

/**
 * Reconfigure the route adding a new pattern and a set of paths
 *
 * @param string $pattern
 * @param array $paths
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, reConfigure);

/**
 * Returns the route's name
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getName);

/**
 * Sets the route's name
 *
 * @param string $name
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, setName);

/**
 * Sets a set of HTTP methods that constraint the matching of the route
 *
 * @param string|array $httpMethods
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, setHttpMethods);

/**
 * Returns the route's id
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getRouteId);

/**
 * Returns the route's pattern
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getPattern);

/**
 * Returns the route's pattern
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getCompiledPattern);

/**
 * Returns the paths
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getPaths);

/**
 * Returns the HTTP methods that constraint matching the route
 *
 * @return string|array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, getHttpMethods);

/**
 * Resets the internal route id generator
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Router_RouteInterface, reset);

