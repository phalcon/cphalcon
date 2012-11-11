
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Mvc\ModelInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_ModelInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc, ModelInterface, mvc_modelinterface, phalcon_mvc_modelinterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model constructor
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param string $managerService
 * @param string $dbService
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, __construct);

/**
 * Sets a transaction related to the Model instance
 *
 * @param Phalcon\Mvc\Model\TransactionInterface $transaction
 * @return Phalcon\Mvc\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, setTransaction);

/**
 * Returns table name mapped in the model
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, getSource);

/**
 * Returns schema name where table mapped is located
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, getSchema);

/**
 * Sets the DependencyInjection connection service
 *
 * @param string $connectionService
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, setConnectionService);

/**
 * Returns DependencyInjection connection service
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, getConnectionService);

/**
 * Forces that model doesn't need to be checked if exists before store it
 *
 * @param boolean $forceExists
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, setForceExists);

/**
 * Gets internal database connection
 *
 * @return Phalcon\Db\AdapterInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, getConnection);

/**
 * Assigns values to a model from an array returning a new model
 *
 * @param array $result
 * @param Phalcon\Mvc\Model $base
 * @return Phalcon\Mvc\Model $result
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, dumpResult);

/**
 * Allows to query a set of records that match the specified conditions
 *
 * @param 	array $parameters
 * @return  Phalcon\Mvc\Model\ResultsetInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, find);

/**
 * Allows to query the first record that match the specified conditions
 *
 * @param array $parameters
 * @return Phalcon\Mvc\Model
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, findFirst);

/**
 * Create a criteria for a especific model
 *
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, query);

/**
 * Allows to count how many records match the specified conditions
 *
 * @param array $parameters
 * @return int
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, count);

/**
 * Allows to a calculate a summatory on a column that match the specified conditions
 *
 * @param array $parameters
 * @return double
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, sum);

/**
 * Allows to get the maximum value of a column that match the specified conditions
 *
 * @param array $parameters
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, maximum);

/**
 * Allows to get the minimum value of a column that match the specified conditions
 *
 * @param array $parameters
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, minimum);

/**
 * Allows to calculate the average value on a column matching the specified conditions
 *
 * @param array $parameters
 * @return double
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, average);

/**
 * Appends a customized message on the validation process
 *
 * @param Phalcon\Mvc\Model\MessageInterface $message
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, appendMessage);

/**
 * Check whether validation process has generated any messages
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, validationHasFailed);

/**
 * Returns all the validation messages
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, getMessages);

/**
 * Inserts or updates a model instance. Returning true on success or false otherwise.
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, save);

/**
 * Inserts a model instance. If the instance already exists in the persistance it will throw an exception
 * Returning true on success or false otherwise.
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, create);

/**
 * Updates a model instance. If the instance doesn't exists in the persistance it will throw an exception
 * Returning true on success or false otherwise.
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, update);

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, delete);

/**
 * Returns the type of the latest operation performed by the ORM
 * Returns one of the OP_* class constants
 *
 * @return int
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, getOperationMade);

/**
 * Reads an attribute value by its name
 *
 * @param string $attribute
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, readAttribute);

/**
 * Writes an attribute value by its name
 *
 * @param string $attribute
 * @param mixed $value
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, writeAttribute);

/**
 * Returns related records based on defined relations
 *
 * @param string $modelName
 * @param array $arguments
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModelInterface, getRelated);

