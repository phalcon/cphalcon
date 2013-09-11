
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

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
 * Phalcon\Mvc\CollectionInterface
 *
 * Interface for Phalcon\Mvc\Collection
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_CollectionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, CollectionInterface, phalcon, mvc_collectioninterface, phalcon_mvc_collectioninterface_method_entry);


	return SUCCESS;

}

/**
 * Phalcon\Mvc\Collection
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, __construct);

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
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getReservedAttributes);

/**
 * Returns collection name mapped in the model
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getSource);

/**
 * Sets a service in the services container that returns the Mongo database
 *
 * @param string connectionService
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
 *
 * @param Phalcon\Mvc\Collection collection
 * @param array document
 * @return Phalcon\Mvc\Collection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, cloneResult);

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 *
 * @param string eventName
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, fireEvent);

/**
 * Fires an event, implicitly listeners in the events manager are notified
 * This method stops if one of the callbacks/listeners returns boolean false
 *
 * @param string eventName
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, fireEventCancel);

/**
 * Check whether validation process has generated any messages
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, validationHasFailed);

/**
 * Returns all the validation messages
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getMessages);

/**
 * Appends a customized message on the validation process
 *
 * @param Phalcon\Mvc\Model\MessageInterface message
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, appendMessage);

/**
 * Creates/Updates a collection based on the values in the atributes
 *
 * @return boolean
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
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_CollectionInterface, delete);

