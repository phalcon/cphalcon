
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

namespace Phalcon\Mvc\Model;

/**
 * Phalcon\Mvc\Model\ManagerInterface
 *
 * Interface for Phalcon\Mvc\Model\Manager
 */
interface ManagerInterface
{

	/**
	 * Initializes a model in the model manager
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 */
	public function initialize(model);

	/**
	 * Returns the mapped source for a model
	 *
	 * @param Phalcon\Mvc\Model model
	 * @return string
	 */
	public function getModelSource(<Phalcon\Mvc\ModelInterface> model);

	/**
	 * Sets the mapped schema for a model
	 *
	 * @param Phalcon\Mvc\Model model
	 * @param string schema
	 * @return string
	 */
	public function setModelSchema(<Phalcon\Mvc\ModelInterface> model, schema);

	/**
	 * Returns the mapped schema for a model
	 *
	 * @param Phalcon\Mvc\Model model
	 * @return string
	 */
	public function getModelSchema(<Phalcon\Mvc\ModelInterface> model);

	/**
	 * Sets both write and read connection service for a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string connectionService
	 */
	public function setConnectionService(<Phalcon\Mvc\ModelInterface> model, string connectionService);

	/**
	 * Sets read connection service for a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string connectionService
	 */
	public function setReadConnectionService(<Phalcon\Mvc\ModelInterface> model, string connectionService);

	/**
	 * Returns the connection service name used to read data related to a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string
	 */
	public function getReadConnectionService(<Phalcon\Mvc\ModelInterface> model);

	/**
	 * Sets write connection service for a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string connectionService
	 */
	public function setWriteConnectionService(<Phalcon\Mvc\ModelInterface> model, string connectionService);

	/**
	 * Returns the connection service name used to write data related to a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string
	 */
	public function getWriteConnectionService(<Phalcon\Mvc\ModelInterface> model);

	/**
	 * Returns the connection to read data related to a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @return Phalcon\Db\AdapterInterface
	 */
	public function getReadConnection(<Phalcon\Mvc\ModelInterface> model);

	/**
	 * Returns the connection to write data related to a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @return Phalcon\Db\AdapterInterface
	 */
	public function getWriteConnection(<Phalcon\Mvc\ModelInterface> model);

	/**
	 * Check of a model is already initialized
	 *
	 * @param string modelName
	 * @return boolean
	 */
	public function isInitialized(modelName);

	/**
	 * Get last initialized model
	 *
	 * @return Phalcon\Mvc\ModelInterface
	 */
	public function getLastInitialized();

	/**
	 * Loads a model throwing an exception if it doesn't exist
	 *
	 * @param  string modelName
	 * @param  boolean newInstance
	 * @return Phalcon\Mvc\ModelInterface
	 */
	public function load(string modelName, boolean newInstance=false);

	/**
	 * Setup a 1-1 relation between two models
	 *
	 * @param   Phalcon\Mvc\ModelInterface model
	 * @param	mixed fields
	 * @param	string referencedModel
	 * @param	mixed referencedFields
	 * @param	array options
	 * @return  Phalcon\Mvc\Model\RelationInterface
	 */
	public function addHasOne(model, fields, referencedModel, referencedFields, options=null);

	/**
	 * Setup a relation reverse 1-1  between two models
	 *
	 * @param 	Phalcon\Mvc\ModelInterface model
	 * @param	mixed fields
	 * @param	string referencedModel
	 * @param	mixed referencedFields
	 * @param	array options
	 * @return 	Phalcon\Mvc\Model\RelationInterface
	 */
	public function addBelongsTo(model, fields, referencedModel, referencedFields, options=null);

	/**
	 * Setup a relation 1-n between two models
	 *
	 * @param 	Phalcon\Mvc\ModelInterface model
	 * @param	mixed fields
	 * @param	string referencedModel
	 * @param	mixed referencedFields
	 * @param	array options
	 * @return 	Phalcon\Mvc\Model\RelationInterface
	 */
	public function addHasMany(model, fields, referencedModel, referencedFields, options=null);

	/**
	 * Checks whether a model has a belongsTo relation with another model
	 *
	 * @param 	string modelName
	 * @param 	string modelRelation
	 * @return 	boolean
	 */
	public function existsBelongsTo(modelName, modelRelation);

	/**
	 * Checks whether a model has a hasMany relation with another model
	 *
	 * @param 	string modelName
	 * @param 	string modelRelation
	 * @return 	boolean
	 */
	public function existsHasMany(modelName, modelRelation);

	/**
	 * Checks whether a model has a hasOne relation with another model
	 *
	 * @param 	string modelName
	 * @param 	string modelRelation
	 * @return 	boolean
	 */
	public function existsHasOne(modelName, modelRelation);

	/**
	 * Gets belongsTo related records from a model
	 *
	 * @param string method
	 * @param string modelName
	 * @param string modelRelation
	 * @param Phalcon\Mvc\Model record
	 * @param array parameters
	 * @return Phalcon\Mvc\Model\ResultsetInterface
	 */
	public function getBelongsToRecords(method, modelName, modelRelation, record, parameters=null);

	/**
	 * Gets hasMany related records from a model
	 *
	 * @param string method
	 * @param string modelName
	 * @param string modelRelation
	 * @param Phalcon\Mvc\Model record
	 * @param array parameters
	 * @return Phalcon\Mvc\Model\ResultsetInterface
	 */
	public function getHasManyRecords(method, modelName, modelRelation, record, parameters=null);

	/**
	 * Gets belongsTo related records from a model
	 *
	 * @param string method
	 * @param string modelName
	 * @param string modelRelation
	 * @param Phalcon\Mvc\Model record
	 * @param array parameters
	 * @return Phalcon\Mvc\Model\ResultsetInterface
	 */
	public function getHasOneRecords(method, modelName, modelRelation, record, parameters=null);

	/**
	 * Gets belongsTo relations defined on a model
	 *
	 * @param  Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getBelongsTo(model);

	/**
	 * Gets hasMany relations defined on a model
	 *
	 * @param  Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getHasMany(model);

	/**
	 * Gets hasOne relations defined on a model
	 *
	 * @param  Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getHasOne(model);

	/**
	 * Gets hasOne relations defined on a model
	 *
	 * @param  Phalcon\Mvc\ModelInterface model
	 * @return array
	 */
	public function getHasOneAndHasMany(model);

	/**
	 * Query all the relationships defined on a model
	 *
	 * @param string modelName
	 * @return Phalcon\Mvc\Model\RelationInterface[]
	 */
	public function getRelations(modelName);

	/**
	 * Query the relations between two models
	 *
	 * @param string first
	 * @param string second
	 * @return array
	 */
	public function getRelationsBetween(first, second);

	/**
	 * Creates a Phalcon\Mvc\Model\Query without execute it
	 *
	 * @param string phql
	 * @return Phalcon\Mvc\Model\QueryInterface
	 */
	public function createQuery(phql);

	/**
	 * Creates a Phalcon\Mvc\Model\Query and execute it
	 *
	 * @param string phql
	 * @param array placeholders
	 * @return Phalcon\Mvc\Model\QueryInterface
	 */
	public function executeQuery(phql, placeholders=null);

	/**
	 * Creates a Phalcon\Mvc\Model\Query\Builder
	 *
	 * @param string params
	 * @return Phalcon\Mvc\Model\Query\BuilderInterface
	 */
	public function createBuilder(params=null);

	/**
	 * Binds a behavior to a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param Phalcon\Mvc\Model\BehaviorInterface behavior
	 */
	public function addBehavior(model, behavior);

	/**
	 * Receives events generated in the models and dispatches them to a events-manager if available
	 * Notify the behaviors that are listening in the model
	 *
	 * @param string eventName
	 * @param Phalcon\Mvc\ModelInterface model
	 */
	public function notifyEvent(eventName, model);

	/**
	 * Dispatch a event to the listeners and behaviors
	 * This method expects that the endpoint listeners/behaviors returns true
	 * meaning that a least one is implemented
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string eventName
	 * @param array data
	 * @return boolean
	 */
	public function missingMethod(model, eventName, data);

	/**
	 * Returns the last query created or executed in the
	 *
	 * @return Phalcon\Mvc\Model\QueryInterface
	 */
	public function getLastQuery();

}