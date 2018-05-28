
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 * Sets a transaction related to the Model instance
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setTransaction);

/**
 * Returns table name mapped in the model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getSource);

/**
 * Returns schema name where table mapped is located
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getSchema);

/**
 * Sets both read/write connection services
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setConnectionService);

/**
 * Sets the DependencyInjection connection service used to write data
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setWriteConnectionService);

/**
 * Sets the DependencyInjection connection service used to read data
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setReadConnectionService);

/**
 * Returns DependencyInjection connection service used to read data
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getReadConnectionService);

/**
 * Returns DependencyInjection connection service used to write data
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getWriteConnectionService);

/**
 * Gets internal database connection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getReadConnection);

/**
 * Gets internal database connection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getWriteConnection);

/**
 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setDirtyState);

/**
 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getDirtyState);

/**
 * Assigns values to a model from an array
 *
 * @param array columnMap
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, assign);

/**
 * Assigns values to a model from an array returning a new model
 *
 * @param \Phalcon\Mvc\Model base
 * @param array columnMap
 * @return \Phalcon\Mvc\Model result
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, cloneResultMap);

/**
 * Assigns values to a model from an array returning a new model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, cloneResult);

/**
 * Returns an hydrated result based on the data and the column map
 *
 * @param array columnMap
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, cloneResultMapHydrate);

/**
 * Allows to query a set of records that match the specified conditions
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, find);

/**
 * Allows to query the first record that match the specified conditions
 *
 * @param array parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, findFirst);

/**
 * Create a criteria for a specific model
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
 * Allows to calculate a sum on a column that match the specified conditions
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
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, fireEvent);

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 * This method stops if one of the callbacks/listeners returns boolean false
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, fireEventCancel);

/**
 * Appends a customized message on the validation process
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, appendMessage);

/**
 * Check whether validation process has generated any messages
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, validationHasFailed);

/**
 * Returns array of validation messages
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getMessages);

/**
 * Inserts or updates a model instance. Returning true on success or false otherwise.
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, save);

/**
 * Inserts a model instance. If the instance already exists in the persistence it will throw an exception
 * Returning true on success or false otherwise.
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, create);

/**
 * Updates a model instance. If the instance doesn't exist in the persistence it will throw an exception
 * Returning true on success or false otherwise.
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, update);

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, delete);

/**
 * Returns the type of the latest operation performed by the ORM
 * Returns one of the OP_* class constants
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getOperationMade);

/**
 * Refreshes the model attributes re-querying the record from the database
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, refresh);

/**
 * Skips the current operation forcing a success state
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, skipOperation);

/**
 * Returns related records based on defined relations
 *
 * @param array arguments
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getRelated);

/**
 * Sets the record's snapshot data.
 * This method is used internally to set snapshot data when the model was set up to keep snapshot data
 *
 * @param array columnMap
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setSnapshotData);

