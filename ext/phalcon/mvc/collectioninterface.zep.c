
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
 * Interface for Phalcon\Mvc\Collection
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_CollectionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, CollectionInterface, phalcon, mvc_collectioninterface, phalcon_mvc_collectioninterface_method_entry);

	return SUCCESS;

}

/**
 * Appends a customized message on the validation process
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, appendMessage);

/**
 * Returns a cloned collection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, cloneResult);

/**
 * Perform a count over a collection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, count);

/**
 * Deletes a model instance. Returning true on success or false otherwise
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, delete);

/**
 * Allows to query a set of records that match the specified conditions
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, find);

/**
 * Find a document by its id
 *
 * @param string id
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, findById);

/**
 * Allows to query the first record that match the specified conditions
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, findFirst);

/**
 * Fires an event, implicitly calls behaviors and listeners in the events
 * manager are notified
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, fireEvent);

/**
 * Fires an event, implicitly listeners in the events manager are notified
 * This method stops if one of the callbacks/listeners returns bool false
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, fireEventCancel);

/**
 * Retrieves a database connection
 *
 * @return MongoDb
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getConnection);

/**
 * Returns one of the DIRTY_STATE_* constants telling if the record exists
 * in the database or not
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getDirtyState);

/**
 * Returns the value of the _id property
 *
 * @return MongoId
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getId);

/**
 * Returns all the validation messages
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getMessages);

/**
 * Returns an array with reserved properties that cannot be part of the
 * insert/update
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getReservedAttributes);

/**
 * Returns collection name mapped in the model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getSource);

/**
 * Creates/Updates a collection based on the values in the attributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, save);

/**
 * Sets a service in the services container that returns the Mongo database
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, setConnectionService);

/**
 * Sets the dirty state of the object using one of the DIRTY_STATE_*
 * constants
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, setDirtyState);

/**
 * Sets a value for the _id property, creates a MongoId object if needed
 *
 * @param mixed id
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, setId);

/**
 * Check whether validation process has generated any messages
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, validationHasFailed);

