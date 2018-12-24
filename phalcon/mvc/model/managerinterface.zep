
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Db\AdapterInterface;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\RelationInterface;
use Phalcon\Mvc\Model\Query\BuilderInterface;
use Phalcon\Mvc\Model\QueryInterface;

/**
 * Phalcon\Mvc\Model\ManagerInterface
 *
 * Interface for Phalcon\Mvc\Model\Manager
 */
interface ManagerInterface
{

	/**
	 * Initializes a model in the model manager
	 */
	public function initialize(<ModelInterface> model);

	/**
	 * Sets the mapped source for a model
	 */
	public function setModelSource(<ModelInterface> model, string! source) -> void;

	/**
	 * Returns the mapped source for a model
	 */
	public function getModelSource(<ModelInterface> model) -> string;

	/**
	 * Sets the mapped schema for a model
	 */
	public function setModelSchema(<ModelInterface> model, string! schema);

	/**
	 * Returns the mapped schema for a model
	 */
	public function getModelSchema(<ModelInterface> model) -> string;

	/**
	 * Sets both write and read connection service for a model
	 */
	public function setConnectionService(<ModelInterface> model, string! connectionService);

	/**
	 * Sets read connection service for a model
	 */
	public function setReadConnectionService(<ModelInterface> model, string! connectionService);

	/**
	 * Returns the connection service name used to read data related to a model
	 */
	public function getReadConnectionService(<ModelInterface> model) -> string;

	/**
	 * Sets write connection service for a model
	 */
	public function setWriteConnectionService(<ModelInterface> model, string! connectionService);

	/**
	 * Returns the connection service name used to write data related to a model
	 */
	public function getWriteConnectionService(<ModelInterface> model) -> string;

	/**
	 * Returns the connection to read data related to a model
	 */
	public function getReadConnection(<ModelInterface> model) -> <AdapterInterface>;

	/**
	 * Returns the connection to write data related to a model
	 */
	public function getWriteConnection(<ModelInterface> model) -> <AdapterInterface>;

	/**
	 * Check of a model is already initialized
	 */
	public function isInitialized(string! modelName) -> bool;

	/**
	 * Get last initialized model
	 */
	public function getLastInitialized() -> <ModelInterface>;

	/**
	 * Loads a model throwing an exception if it doesn't exist
	 */
	public function load(string modelName) -> <ModelInterface>;

	/**
	 * Setup a 1-1 relation between two models
	 *
	 * @param	mixed  fields
	 * @param	mixed  referencedFields
	 * @param	array  options
	 */
	public function addHasOne(<ModelInterface> model, fields, string! referencedModel, referencedFields, options = null) -> <RelationInterface>;

	/**
	 * Setup a relation reverse 1-1  between two models
	 *
	 * @param	mixed  fields
	 * @param	mixed  referencedFields
	 * @param	array  options
	 */
	public function addBelongsTo(<ModelInterface> model, fields, string! referencedModel, referencedFields, options = null) -> <RelationInterface>;

	/**
	 * Setup a relation 1-n between two models
	 *
	 * @param	mixed  fields
	 * @param	mixed  referencedFields
	 * @param	array  options
	 */
	public function addHasMany(<ModelInterface> model, fields, string! referencedModel, referencedFields, options = null) -> <RelationInterface>;

	/**
	 * Checks whether a model has a belongsTo relation with another model
	 */
	public function existsBelongsTo(string! modelName, string! modelRelation) -> bool;

	/**
	 * Checks whether a model has a hasMany relation with another model
	 */
	public function existsHasMany(string! modelName, string! modelRelation) -> bool;

	/**
	 * Checks whether a model has a hasOne relation with another model
	 */
	public function existsHasOne(string! modelName, string! modelRelation) -> bool;

	/**
	 * Gets belongsTo related records from a model
	 *
	 * @param string modelRelation
	 * @param array  parameters
	 */
	public function getBelongsToRecords(string! method, string! modelName, var modelRelation, <ModelInterface> record, parameters = null) -> <ResultsetInterface> | bool;

	/**
	 * Gets hasMany related records from a model
	 *
	 * @param string modelRelation
	 * @param array  parameters
	 */
	public function getHasManyRecords(string! method, string! modelName, var modelRelation, <ModelInterface> record, parameters = null) -> <ResultsetInterface> | bool;

	/**
	 * Gets belongsTo related records from a model
	 *
	 * @param string modelRelation
	 * @param array  parameters
	 */
	public function getHasOneRecords(string! method, string! modelName, var modelRelation, <ModelInterface> record, parameters = null) -> <ModelInterface> | bool;

	/**
	 * Gets belongsTo relations defined on a model
	 */
	public function getBelongsTo(<ModelInterface> model) -> <RelationInterface[]> | array;

	/**
	 * Gets hasMany relations defined on a model
	 */
	public function getHasMany(<ModelInterface> model) -> <RelationInterface[]> | array;

	/**
	 * Gets hasOne relations defined on a model
	 */
	public function getHasOne(<ModelInterface> model) -> <RelationInterface[]> | array;

	/**
	 * Gets hasOne relations defined on a model
	 */
	public function getHasOneAndHasMany(<ModelInterface> model) -> <RelationInterface[]>;

	/**
	 * Query all the relationships defined on a model
	 */
	public function getRelations(string! modelName) -> <RelationInterface[]>;

	/**
	 * Query the relations between two models
	 */
	public function getRelationsBetween(string! first, string! second) -> <RelationInterface[]> | bool;

	/**
	 * Creates a Phalcon\Mvc\Model\Query without execute it
	 */
	public function createQuery(string! phql) -> <QueryInterface>;

	/**
	 * Creates a Phalcon\Mvc\Model\Query and execute it
	 *
	 * @param array $placeholders
	 */
	public function executeQuery(string! phql, var placeholders = null) -> <QueryInterface>;

	/**
	 * Creates a Phalcon\Mvc\Model\Query\Builder
	 *
	 * @param string $params
	 */
	public function createBuilder(params = null) -> <BuilderInterface>;

	/**
	 * Binds a behavior to a model
	 */
	public function addBehavior(<ModelInterface> model, <\Phalcon\Mvc\Model\BehaviorInterface> behavior);

	/**
	 * Receives events generated in the models and dispatches them to an events-manager if available
	 * Notify the behaviors that are listening in the model
	 *
	 * @param string $eventName
	 */
	public function notifyEvent(string! eventName, <ModelInterface> model);

	/**
	 * Dispatch an event to the listeners and behaviors
	 * This method expects that the endpoint listeners/behaviors returns true
	 * meaning that a least one is implemented
	 *
	 * @param array data
	 * @return bool
	 */
	public function missingMethod(<ModelInterface> model, string! eventName, data);

	/**
	 * Returns the last query created or executed in the models manager
	 */
	public function getLastQuery() -> <QueryInterface>;

	/**
	 * Returns a relation by its alias
	 */
	public function getRelationByAlias(string! modelName, string! alias) -> <Relation> | bool;

	/**
	 * Check whether a model property is declared as public.
	 *
	 * <code>
	 * $isPublic = $manager->isVisibleModelProperty(
	 *     new Robots(),
	 *     "name"
	 * );
	 * </code>
	 */
	public final function isVisibleModelProperty(<ModelInterface> model, string property) -> bool;

	/**
	 * Sets if a model must keep snapshots
	 */
	public function keepSnapshots(<ModelInterface> model, bool keepSnapshots) -> void;

	/**
	 * Checks if a model is keeping snapshots for the queried records
	 */
	public function isKeepingSnapshots(<ModelInterface> model) -> bool;

	/**
	 * Sets if a model must use dynamic update instead of the all-field update
	 */
	public function useDynamicUpdate(<ModelInterface> model, bool dynamicUpdate);

	/**
	 * Checks if a model is using dynamic update instead of all-field update
	 */
	public function isUsingDynamicUpdate(<ModelInterface> model) -> bool;

	/**
	 * Setups a relation n-m between two models
	 *
	 * @param	string fields
	 * @param	string intermediateFields
	 * @param	string intermediateReferencedFields
	 * @param	string referencedFields
	 * @param   array options
	 */
	public function addHasManyToMany(<ModelInterface> model, var fields, string! intermediateModel,
		var intermediateFields, var intermediateReferencedFields, string! referencedModel, var referencedFields, var options = null) -> <RelationInterface>;

	/**
	 * Checks whether a model has a hasManyToMany relation with another model
	 */
	public function existsHasManyToMany(string! modelName, string! modelRelation) -> bool;

	/**
	 * Helper method to query records based on a relation definition
	 *
	 * @return \Phalcon\Mvc\Model\Resultset\Simple|Phalcon\Mvc\Model\Resultset\Simple|int|false
	 */
	public function getRelationRecords(<RelationInterface> relation, string! method, <ModelInterface> record, var parameters = null);

	/**
	 * Gets hasManyToMany relations defined on a model
	 */
	public function getHasManyToMany(<ModelInterface> model) -> <RelationInterface[]> | array;

	/**
	 * Registers shorter aliases for namespaces in PHQL statements
	 */
	public function registerNamespaceAlias(string alias, string namespaceName) -> void;

	/**
	 * Returns a real namespace from its alias
	 */
	public function getNamespaceAlias(string! alias) -> string;
}
