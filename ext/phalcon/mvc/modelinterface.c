
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
 * Phalcon\Mvc\ModelInterface
 *
 * Interface for Phalcon\Mvc\Model
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_ModelInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, ModelInterface, phalcon, mvc_modelinterface, phalcon_mvc_modelinterface_method_entry);


	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model constructor
 *
 * @param Phalcon\DiInterface dependencyInjector
 * @param Phalcon\Mvc\Model\ManagerInterface modelsManager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, __construct);

/**
 * Sets a transaction related to the Model instance
 *
 * @param Phalcon\Mvc\Model\TransactionInterface transaction
 * @return Phalcon\Mvc\ModelInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setTransaction);

/**
 * Returns table name mapped in the model
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getSource);

/**
 * Returns schema name where table mapped is located
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getSchema);

/**
 * Sets both read/write connection services
 *
 * @param string connectionService
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setConnectionService);

/**
 * Sets the DependencyInjection connection service used to write data
 *
 * @param string connectionService
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setWriteConnectionService);

/**
 * Sets the DependencyInjection connection service used to read data
 *
 * @param string connectionService
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setReadConnectionService);

/**
 * Returns DependencyInjection connection service used to read data
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getReadConnectionService);

/**
 * Returns DependencyInjection connection service used to write data
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getWriteConnectionService);

/**
 * Gets internal database connection
 *
 * @return Phalcon\Db\AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getReadConnection);

/**
 * Gets internal database connection
 *
 * @return Phalcon\Db\AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getWriteConnection);

/**
 * Assigns values to a model from an array
 *
 * @param Phalcon\Mvc\Model object
 * @param array data
 * @param array columnMap
 * @return Phalcon\Mvc\Model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, assign);

/**
 * Assigns values to a model from an array returning a new model
 *
 * @param Phalcon\Mvc\Model base
 * @param array data
 * @param array columnMap
 * @param int dirtyState
 * @param boolean keepSnapshots
 * @return Phalcon\Mvc\Model result
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, cloneResultMap);

/**
 * Assigns values to a model from an array returning a new model
 *
 * @param Phalcon\Mvc\Model base
 * @param array data
 * @param int dirtyState
 * @return Phalcon\Mvc\Model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, cloneResult);

/**
 * Returns an hydrated result based on the data and the column map
 *
 * @param array data
 * @param array columnMap
 * @param int hydrationMode
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, cloneResultMapHydrate);

/**
 * Allows to query a set of records that match the specified conditions
 *
 * @param 	array parameters
 * @return  Phalcon\Mvc\Model\ResultsetInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, find);

/**
 * Allows to query the first record that match the specified conditions
 *
 * @param array parameters
 * @return Phalcon\Mvc\ModelInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, findFirst);

/**
 * Create a criteria for a especific model
 *
 * @param Phalcon\DiInterface dependencyInjector
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, query);

/**
 * Allows to count how many records match the specified conditions
 *
 * @param array parameters
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, count);

/**
 * Allows to calculate a summatory on a column that match the specified conditions
 *
 * @param array parameters
 * @return double
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, sum);

/**
 * Allows to get the maximum value of a column that match the specified conditions
 *
 * @param array parameters
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, maximum);

/**
 * Allows to get the minimum value of a column that match the specified conditions
 *
 * @param array parameters
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, minimum);

/**
 * Allows to calculate the average value on a column matching the specified conditions
 *
 * @param array parameters
 * @return double
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, average);

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 *
 * @param string eventName
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, fireEvent);

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 * This method stops if one of the callbacks/listeners returns boolean false
 *
 * @param string eventName
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, fireEventCancel);

/**
 * Appends a customized message on the validation process
 *
 * @param Phalcon\Mvc\Model\MessageInterface message
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, appendMessage);

/**
 * Check whether validation process has generated any messages
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, validationHasFailed);

/**
 * Returns all the validation messages
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getMessages);

/**
 * Inserts or updates a model instance. Returning true on success or false otherwise.
 *
 * @param  array data
 * @param  array whiteList
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, save);

/**
 * Inserts a model instance. If the instance already exists in the persistance it will throw an exception
 * Returning true on success or false otherwise.
 *
 * @param  array data
 * @param  array whiteList
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, create);

/**
 * Updates a model instance. If the instance doesn't exist in the persistance it will throw an exception
 * Returning true on success or false otherwise.
 *
 * @param  array data
 * @param  array whiteList
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, update);

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, delete);

/**
 * Returns the type of the latest operation performed by the ORM
 * Returns one of the OP_* class constants
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getOperationMade);

/**
 * Refreshes the model attributes re-querying the record from the database
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, refresh);

/**
 * Reads an attribute value by its name
 *
 * @param string attribute
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, readAttribute);

/**
 * Writes an attribute value by its name
 *
 * @param string attribute
 * @param mixed value
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, writeAttribute);

/**
 * Returns related records based on defined relations
 *
 * @param string alias
 * @param array arguments
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getRelated);

