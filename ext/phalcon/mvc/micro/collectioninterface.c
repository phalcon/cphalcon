
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
/**
 * Phalcon\Mvc\Micro\CollectionInterface
 *
 * Interface for Phalcon\Mvc\Micro\Collection
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_CollectionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Micro, CollectionInterface, phalcon, mvc_micro_collectioninterface, phalcon_mvc_micro_collectioninterface_method_entry);


	return SUCCESS;

}

/**
 * Sets a prefix for all routes added to the collection
 *
 * @param string prefix
 * @return Phalcon\Mvc\Micro\Collection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, setPrefix);

/**
 * Returns the collection prefix if any
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, getPrefix);

/**
 * Returns the registered handlers
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, getHandlers);

/**
 * Sets the main handler
 *
 * @param mixed handler
 * @param boolean lazy
 * @return Phalcon\Mvc\Micro\Collection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, setHandler);

/**
 * Sets if the main handler must be lazy loaded
 *
 * @param boolean lazy
 * @return Phalcon\Mvc\Micro\Collection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, setLazy);

/**
 * Returns if the main handler must be lazy loaded
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, isLazy);

/**
 * Returns the main handler
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, getHandler);

/**
 * Maps a route to a handler
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, map);

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, get);

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, post);

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, put);

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, patch);

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, head);

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, delete);

/**
 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Router\RouteInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, options);

