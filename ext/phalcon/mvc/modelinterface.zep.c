
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
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\ModelInterface
 *
 * Interface for Phalcon\Mvc\Model
 *
 * @template T
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_ModelInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, ModelInterface, phalcon, mvc_modelinterface, phalcon_mvc_modelinterface_method_entry);

	return SUCCESS;
}

/**
 * Appends a customized message on the validation process
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, appendMessage);
/**
 * Assigns values to a model from an array
 *
 * @param array data
 * @param mixed whiteList
 * @param mixed dataColumnMap Array to transform keys of data to another
 *
 * @return ModelInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, assign);
/**
 * Allows to calculate the average value on a column matching the specified
 * conditions
 *
 * @param array parameters
 * @return ResultsetInterface|float
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, average);
/**
 * Assigns values to a model from an array returning a new model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, cloneResult);
/**
 * Assigns values to a model from an array returning a new model
 *
 * @param ModelInterface|\Phalcon\Mvc\Model\Row base
 * @param mixed columnMap
 * @param int dirtyState
 * @param bool keepSnapshots
 *
 * @return ModelInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, cloneResultMap);
/**
 * Returns an hydrated result based on the data and the column map
 *
 * @param array columnMap
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, cloneResultMapHydrate);
/**
 * Allows to count how many records match the specified conditions
 *
 * Returns an integer for simple queries or a ResultsetInterface
 * instance for when the GROUP condition is used. The results will
 * contain the count of each group.
 *
 * @param array|string|null parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, count);
/**
 * Inserts a model instance. If the instance already exists in the
 * persistence it will throw an exception. Returning true on success or
 * false otherwise.
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, create);
/**
 * Deletes a model instance. Returning true on success or false otherwise.
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, delete);
/**
 * Allows to query a set of records that match the specified conditions
 *
 * @param array|string|int|null parameters
 *
 * @return T[]|\Phalcon\Mvc\Model\Resultset<int, T>
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, find);
/**
 * Allows to query the first record that match the specified conditions
 *
 * @param array parameters
 * @return T|\Phalcon\Mvc\ModelInterface|\Phalcon\Mvc\Model\Row|null
 *
 * TODO: Current method signature must be reviewed in v5. As it must return only ?ModelInterface (it also returns Row).
 * @see https://github.com/phalcon/cphalcon/issues/15212
 * @see https://github.com/phalcon/cphalcon/issues/15883
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, findFirst);
/**
 * Fires an event, implicitly calls behaviors and listeners in the events
 * manager are notified
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, fireEvent);
/**
 * Fires an event, implicitly calls behaviors and listeners in the events
 * manager are notified. This method stops if one of the callbacks/listeners
 * returns bool false
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, fireEventCancel);
/**
 * Returns one of the DIRTY_STATE_* constants telling if the record exists
 * in the database or not
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getDirtyState);
/**
 * Returns array of validation messages
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getMessages);
/**
 * Returns the models meta-data service related to the entity instance.
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getModelsMetaData);
/**
 * Returns the type of the latest operation performed by the ORM
 * Returns one of the OP_* class constants
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getOperationMade);
/**
 * Gets internal database connection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getReadConnection);
/**
 * Returns DependencyInjection connection service used to read data
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getReadConnectionService);
/**
 * Returns related records based on defined relations
 *
 * @param string alias
 * @param array arguments
 * @return \Phalcon\Mvc\Model\Resultset\Simple|false
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getRelated);
/**
 * Returns schema name where table mapped is located
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getSchema);
/**
 * Returns table name mapped in the model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getSource);
/**
 * Gets internal database connection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getWriteConnection);
/**
 * Returns DependencyInjection connection service used to write data
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, getWriteConnectionService);
/**
 * Allows to get the maximum value of a column that match the specified
 * conditions
 *
 * @param array parameters
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, maximum);
/**
 * Allows to get the minimum value of a column that match the specified
 * conditions
 *
 * @param array parameters
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, minimum);
/**
 * Create a criteria for a specific model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, query);
/**
 * Refreshes the model attributes re-querying the record from the database
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, refresh);
/**
 * Inserts or updates a model instance. Returning true on success or false
 * otherwise.
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, save);
/**
 * Sets both read/write connection services
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setConnectionService);
/**
 * Sets the dirty state of the object using one of the DIRTY_STATE_*
 * constants
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setDirtyState);
/**
 * Sets the DependencyInjection connection service used to read data
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setReadConnectionService);
/**
 * Sets the record's snapshot data. This method is used internally to set
 * snapshot data when the model was set up to keep snapshot data
 *
 * @param array columnMap
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setSnapshotData);
/**
 * Sets a transaction related to the Model instance
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setTransaction);
/**
 * Sets the DependencyInjection connection service used to write data
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, setWriteConnectionService);
/**
 * Skips the current operation forcing a success state
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, skipOperation);
/**
 * Allows to calculate a sum on a column that match the specified conditions
 *
 * @param array parameters
 * @return float|ResultsetInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, sum);
/**
 * Check whether validation process has generated any messages
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, validationHasFailed);
/**
 * Updates a model instance. If the instance doesn't exist in the
 * persistence it will throw an exception. Returning true on success or
 * false otherwise.
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModelInterface, update);
