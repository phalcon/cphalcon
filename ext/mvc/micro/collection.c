
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"

/**
 * Phalcon\Mvc\Micro\Collection
 *
 * Groups handlers as controllers
 */


/**
 * Phalcon\Mvc\Micro\Collection initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Micro_Collection){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Micro, Collection, mvc_micro_collection, phalcon_mvc_micro_collection_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_micro_collection_ce, SL("_handlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_Micro_Collection, _addMap){


	
}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, get){

	zval *route_pattern, *handler, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "get", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, post){

	zval *route_pattern, *handler, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "post", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, put){

	zval *route_pattern, *handler, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "put", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, patch){

	zval *route_pattern, *handler, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "patch", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, head){

	zval *route_pattern, *handler, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "head", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, delete){

	zval *route_pattern, *handler, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "delete", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_CCTOR(route);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, options){

	zval *route_pattern, *handler, *method, *route;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &route_pattern, &handler) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "options", 1);
	
	PHALCON_INIT_VAR(route);
	PHALCON_CALL_METHOD_PARAMS_3(route, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_CCTOR(route);
}

