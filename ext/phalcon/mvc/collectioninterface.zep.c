
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\CollectionInterface
 *
 * Interface for Phalcon\Mvc\Collection
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_CollectionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, CollectionInterface, phalcon, mvc_collectioninterface, phalcon_mvc_collectioninterface_method_entry);

	return SUCCESS;

}

/**
 * Sets a value for the _id propery, creates a MongoId object if needed
 *
 * @param mixed id
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, setId);

/**
 * Returns the value of the _id property
 *
 * @return MongoId
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getId);

/**
 * Returns an array with reserved properties that cannot be part of the insert/update
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getReservedAttributes);

/**
 * Returns collection name mapped in the model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getSource);

/**
 * Sets a service in the services container that returns the Mongo database
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, setConnectionService);

/**
 * Retrieves a database connection
 *
 * @return MongoDb
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getConnection);

/**
 * Reads an attribute value by its name
 *
 * @param string attribute
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, readAttribute);

/**
 * Writes an attribute value by its name
 *
 * @param string attribute
 * @param mixed value
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, writeAttribute);

/**
 * Returns a cloned collection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, cloneResult);

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, fireEvent);

/**
 * Fires an event, implicitly listeners in the events manager are notified
 * This method stops if one of the callbacks/listeners returns boolean false
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, fireEventCancel);

/**
 * Check whether validation process has generated any messages
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, validationHasFailed);

/**
 * Returns all the validation messages
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getMessages);

/**
 * Appends a customized message on the validation process
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, appendMessage);

/**
 * Creates/Updates a collection based on the values in the atributes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, save);

/**
 * Find a document by its id
 *
 * @param string id
 * @return Phalcon\Mvc\Collection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, findById);

/**
 * Allows to query the first record that match the specified conditions
 *
 * @param array parameters
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, findFirst);

/**
 * Allows to query a set of records that match the specified conditions
 *
 * @param 	array parameters
 * @return  array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, find);

/**
 * Perform a count over a collection
 *
 * @param array parameters
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, count);

/**
 * Deletes a model instance. Returning true on success or false otherwise
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, delete);

