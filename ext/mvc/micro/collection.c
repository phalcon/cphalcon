
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/micro/collection.h"
#include "mvc/micro/collectioninterface.h"
#include "interned-strings.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
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
zend_class_entry *phalcon_mvc_micro_collection_ce;

PHP_METHOD(Phalcon_Mvc_Micro_Collection, setPrefix);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getPrefix);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandlers);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setHandler);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setLazy);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, isLazy);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandler);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, map);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, get);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, post);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, put);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, patch);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, head);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, delete);
PHP_METHOD(Phalcon_Mvc_Micro_Collection, options);

static const zend_function_entry phalcon_mvc_micro_collection_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Micro_Collection, setPrefix, arginfo_phalcon_mvc_micro_collectioninterface_setprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, getHandlers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, setHandler, arginfo_phalcon_mvc_micro_collectioninterface_sethandler, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, setLazy, arginfo_phalcon_mvc_micro_collectioninterface_setlazy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, isLazy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, getHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, map, arginfo_phalcon_mvc_micro_collectioninterface_map, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, get, arginfo_phalcon_mvc_micro_collectioninterface_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, post, arginfo_phalcon_mvc_micro_collectioninterface_post, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, put, arginfo_phalcon_mvc_micro_collectioninterface_put, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, patch, arginfo_phalcon_mvc_micro_collectioninterface_patch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, head, arginfo_phalcon_mvc_micro_collectioninterface_head, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, delete, arginfo_phalcon_mvc_micro_collectioninterface_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, options, arginfo_phalcon_mvc_micro_collectioninterface_options, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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
 * @param string|null $method
 * @param string $routePattern
 * @param mixed $handler
 * @param string $name
 */
void phalcon_mvc_collection_addmap(zval *this_ptr, const char *method, zval *route_pattern, zval *handler, zval *name TSRMLS_DC)
{
	zval *handler_definition;
	zval *z_method;

	MAKE_STD_ZVAL(z_method);
	if (method) {
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(z_method, method);
	}
	else {
		ZVAL_NULL(z_method);
	}

	Z_ADDREF_P(route_pattern);
	Z_ADDREF_P(handler);

	PHALCON_ALLOC_GHOST_ZVAL(handler_definition);
	array_init_size(handler_definition, 3 + (name != NULL ? 1 : 0));
	add_next_index_zval(handler_definition, z_method);
	add_next_index_zval(handler_definition, route_pattern);
	add_next_index_zval(handler_definition, handler);
	if (name) {
		Z_ADDREF_P(name);
		add_next_index_zval(handler_definition, name);
	}
	else {
		add_next_index_null(handler_definition);
	}

	phalcon_update_property_array_append(this_ptr, SL("_handlers"), handler_definition TSRMLS_CC);
}

/**
 * Sets a prefix for all routes added to the collection
 *
 * @param string $prefix
 * @return Phalcon\Mvc\Micro\CollectionInterface
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
 * @return Phalcon\Mvc\Micro\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setHandler){

	zval *handler, *lazy = NULL;

	phalcon_fetch_params(0, 1, 1, &handler, &lazy);
	
	if (!lazy) {
		lazy = PHALCON_GLOBAL(z_false);
	}
	
	phalcon_update_property_this(this_ptr, SL("_handler"), handler TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_lazy"), lazy TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Sets if the main handler must be lazy loaded
 *
 * @param boolean $lazy
 * @return Phalcon\Mvc\Micro\CollectionInterface
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
 * @param string $name
 * @return Phalcon\Mvc\Micro\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, map){

	zval *route_pattern, *handler, *name = NULL;

	phalcon_fetch_params(0, 2, 1, &route_pattern, &handler, &name);
	
	phalcon_mvc_collection_addmap(getThis(), NULL, route_pattern, handler, name TSRMLS_CC);
	RETURN_ZVAL(getThis(), 1, 0);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param string $routePattern
 * @param callable $handler
 * @param string $name
 * @return Phalcon\Mvc\Micro\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, get){

	zval *route_pattern, *handler, *name = NULL;

	phalcon_fetch_params(0, 2, 1, &route_pattern, &handler, &name);
	
	phalcon_mvc_collection_addmap(getThis(), phalcon_interned_GET, route_pattern, handler, name TSRMLS_CC);
	RETURN_ZVAL(getThis(), 1, 0);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param string $routePattern
 * @param callable $handler
 * @param string $name
 * @return Phalcon\Mvc\Micro\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, post){

	zval *route_pattern, *handler, *name = NULL;

	phalcon_fetch_params(0, 2, 0, &route_pattern, &handler, &name);
	
	phalcon_mvc_collection_addmap(getThis(), phalcon_interned_POST, route_pattern, handler, name TSRMLS_CC);
	RETURN_ZVAL(getThis(), 1, 0);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 *
 * @param string $routePattern
 * @param callable $handler
 * @param string $name
 * @return Phalcon\Mvc\Micro\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, put){

	zval *route_pattern, *handler, *name = NULL;

	phalcon_fetch_params(0, 2, 0, &route_pattern, &handler, &name);
	
	phalcon_mvc_collection_addmap(getThis(), phalcon_interned_PUT, route_pattern, handler, name TSRMLS_CC);
	RETURN_ZVAL(getThis(), 1, 0);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH
 *
 * @param string $routePattern
 * @param callable $handler
 * @param string $name
 * @return Phalcon\Mvc\Micro\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, patch){

	zval *route_pattern, *handler, *name = NULL;

	phalcon_fetch_params(0, 2, 0, &route_pattern, &handler, &name);
	
	phalcon_mvc_collection_addmap(getThis(), phalcon_interned_PATCH, route_pattern, handler, name TSRMLS_CC);
	RETURN_ZVAL(getThis(), 1, 0);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 *
 * @param string $routePattern
 * @param callable $handler
 * @param string $name
 * @return Phalcon\Mvc\Micro\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, head){

	zval *route_pattern, *handler, *name = NULL;

	phalcon_fetch_params(0, 2, 0, &route_pattern, &handler, &name);
	
	phalcon_mvc_collection_addmap(getThis(), phalcon_interned_HEAD, route_pattern, handler, name TSRMLS_CC);
	RETURN_ZVAL(getThis(), 1, 0);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 *
 * @param string $routePattern
 * @param callable $handler
 * @param string $name
 * @return Phalcon\Mvc\Micro\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, delete){

	zval *route_pattern, *handler, *name = NULL;

	phalcon_fetch_params(0, 2, 0, &route_pattern, &handler, &name);
	
	phalcon_mvc_collection_addmap(getThis(), phalcon_interned_DELETE, route_pattern, handler, name TSRMLS_CC);
	RETURN_ZVAL(getThis(), 1, 0);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
 *
 * @param string $routePattern
 * @param callable $handler
 * @param string $name
 * @return Phalcon\Mvc\Micro\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, options){

	zval *route_pattern, *handler, *name = NULL;

	phalcon_fetch_params(0, 2, 0, &route_pattern, &handler, &name);
	
	phalcon_mvc_collection_addmap(getThis(), phalcon_interned_OPTIONS, route_pattern, handler, name TSRMLS_CC);
	RETURN_ZVAL(getThis(), 1, 0);
}
