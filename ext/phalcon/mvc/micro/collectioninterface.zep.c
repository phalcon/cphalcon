
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
 * Phalcon\Mvc\Micro\CollectionInterface
 *
 * Interface for Phalcon\Mvc\Micro\Collection
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_CollectionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Micro, CollectionInterface, phalcon, mvc_micro_collectioninterface, phalcon_mvc_micro_collectioninterface_method_entry);

	return SUCCESS;

}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, delete);
/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, get);
/**
 * Returns the main handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, getHandler);
/**
 * Returns the registered handlers
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, getHandlers);
/**
 * Returns the collection prefix if any
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, getPrefix);
/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, head);
/**
 * Returns if the main handler must be lazy loaded
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, isLazy);
/**
 * Maps a route to a handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, map);
/**
 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, options);
/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, patch);
/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, post);
/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, put);
/**
 * Sets the main handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, setHandler);
/**
 * Sets if the main handler must be lazy loaded
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, setLazy);
/**
 * Sets a prefix for all routes added to the collection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Micro_CollectionInterface, setPrefix);
