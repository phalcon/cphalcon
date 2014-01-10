
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

#include "mvc/micro/collectioninterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_micro_collectioninterface_ce;

static const zend_function_entry phalcon_mvc_micro_collectioninterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setPrefix, arginfo_phalcon_mvc_micro_collectioninterface_setprefix)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getPrefix, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getHandlers, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setHandler, arginfo_phalcon_mvc_micro_collectioninterface_sethandler)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setLazy, arginfo_phalcon_mvc_micro_collectioninterface_setlazy)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, isLazy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getHandler, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, map, arginfo_phalcon_mvc_micro_collectioninterface_map)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, get, arginfo_phalcon_mvc_micro_collectioninterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, post, arginfo_phalcon_mvc_micro_collectioninterface_post)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, put, arginfo_phalcon_mvc_micro_collectioninterface_put)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, patch, arginfo_phalcon_mvc_micro_collectioninterface_patch)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, head, arginfo_phalcon_mvc_micro_collectioninterface_head)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, delete, arginfo_phalcon_mvc_micro_collectioninterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, options, arginfo_phalcon_mvc_micro_collectioninterface_options)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Micro\CollectionInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Micro_CollectionInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Micro, CollectionInterface, mvc_micro_collectioninterface, phalcon_mvc_micro_collectioninterface_method_entry);

	return SUCCESS;
}

/**
 * Sets a prefix for all routes added to the collection
 *
 * @param string $prefix
 * @return Phalcon\Mvc\Micro\Collection
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, setPrefix);

/**
 * Returns the collection prefix if any
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, getPrefix);

/**
 * Returns the registered handlers
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, getHandlers);

/**
 * Sets the main handler
 *
 * @param mixed $handler
 * @param boolean $lazy
 * @return Phalcon\Mvc\Micro\Collection
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, setHandler);

/**
 * Sets if the main handler must be lazy loaded
 *
 * @param boolean $lazy
 * @return Phalcon\Mvc\Micro\Collection
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, setLazy);

/**
 * Returns if the main handler must be lazy loaded
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, isLazy);

/**
 * Returns the main handler
 *
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, getHandler);

/**
 * Maps a route to a handler
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, map);

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, get);

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, post);

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, put);

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, patch);

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, head);

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, delete);

/**
 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
 *
 * @param string $routePattern
 * @param callable $handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, options);

