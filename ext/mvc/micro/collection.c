
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

#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Mvc\Micro\Collection
 *
 * Groups Micro-Mvc handlers as controllers
 *
 *<code>
 *
 * $app = new Phalcon\Mvc\Micro();
 *
 * $collection = new Phalcon\Mvc\Micro\Collection();
 *
 * $collection->setHandler(new PostsController());
 *
 * $collection->get('/posts/edit/{id}', 'edit');
 *
 * $app->mount($collection);
 *
 *</code>
 *
 */


/**
 * Phalcon\Mvc\Micro\Collection initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Micro_Collection){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Micro, Collection, mvc_micro_collection, phalcon_mvc_micro_collection_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_micro_collection_ce, SL("_prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_collection_ce, SL("_lazy"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_collection_ce, SL("_handler"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_collection_ce, SL("_handlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_micro_collection_ce TSRMLS_CC, 1, phalcon_mvc_micro_collectioninterface_ce);

	return SUCCESS;
}

/**
 * Internal function to add a handler to the group
 *
 * @param string|array $method
 * @param string $routePattern
 * @param mixed $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, _addMap){

	zval *method, *route_pattern, *handler, *handler_definition;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &method, &route_pattern, &handler);
	
	PHALCON_INIT_VAR(handler_definition);
	array_init_size(handler_definition, 3);
	phalcon_array_append(&handler_definition, method, PH_SEPARATE);
	phalcon_array_append(&handler_definition, route_pattern, PH_SEPARATE);
	phalcon_array_append(&handler_definition, handler, PH_SEPARATE);
	phalcon_update_property_array_append(this_ptr, SL("_handlers"), handler_definition TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a prefix for all routes added to the collection
 *
 * @param string $prefix
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setPrefix){

	zval *prefix;

	phalcon_fetch_params(0, 1, 0, &prefix);
	
	phalcon_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the collection prefix if any
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getPrefix){


	RETURN_MEMBER(this_ptr, "_prefix");
}

/**
 * Returns the registered handlers
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandlers){


	RETURN_MEMBER(this_ptr, "_handlers");
}

/**
 * Sets the main handler
 *
 * @param mixed $handler
 * @param boolean $lazy
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setHandler){

	zval *handler, *lazy = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &handler, &lazy);
	
	if (!lazy) {
		PHALCON_INIT_VAR(lazy);
		ZVAL_BOOL(lazy, 0);
	}
	
	phalcon_update_property_this(this_ptr, SL("_handler"), handler TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_lazy"), lazy TSRMLS_CC);
	RETURN_THIS();
}

/**
 * Sets if the main handler must be lazy loaded
 *
 * @param boolean $lazy
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setLazy){

	zval *lazy;

	phalcon_fetch_params(0, 1, 0, &lazy);
	
	phalcon_update_property_this(this_ptr, SL("_lazy"), lazy TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns if the main handler must be lazy loaded
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, isLazy){


	RETURN_MEMBER(this_ptr, "_lazy");
}

/**
 * Returns the main handler
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandler){


	RETURN_MEMBER(this_ptr, "_handler");
}

/**
 * Maps a route to a handler
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, map){

	zval *route_pattern, *handler, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	PHALCON_INIT_VAR(method);
	phalcon_call_method_p3(return_value, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_MM();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, get){

	zval *route_pattern, *handler, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "GET", 1);
	phalcon_call_method_p3(return_value, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_MM();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, post){

	zval *route_pattern, *handler, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "POST", 1);
	phalcon_call_method_p3(return_value, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_MM();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, put){

	zval *route_pattern, *handler, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "PUT", 1);
	phalcon_call_method_p3(return_value, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_MM();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, patch){

	zval *route_pattern, *handler, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "PATCH", 1);
	phalcon_call_method_p3(return_value, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_MM();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, head){

	zval *route_pattern, *handler, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "HEAD", 1);
	phalcon_call_method_p3(return_value, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_MM();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, delete){

	zval *route_pattern, *handler, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "DELETE", 1);
	phalcon_call_method_p3(return_value, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_MM();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, options){

	zval *route_pattern, *handler, *method;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &route_pattern, &handler);
	
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "OPTIONS", 1);
	phalcon_call_method_p3(return_value, this_ptr, "_addmap", method, route_pattern, handler);
	RETURN_MM();
}

