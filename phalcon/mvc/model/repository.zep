
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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

use Phalcon\Di;
use Phalcon\DiInterface;
use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon\Mvc\Model\Repository
 */
class Repository implements RepositoryInterface
{
	/**
	 * @var string
	 */
	protected _modelClass;

	/**
	 * @var ManagerInterface
	 */
	protected _modelsManager;

	public function __construct(string! modelClass, <ManagerInterface> modelsManager)
	{
		let this->_modelClass    = modelClass;
		let this->_modelsManager = modelsManager;
	}

	/**
	 * Query for a set of records that match the specified conditions
	 *
	 * <code>
	 * $robotsRepository = $modelsManager->getRepository(Robots::class);
	 *
	 * // How many robots are there?
	 * $robots = $robotsRepository->find();
	 *
	 * echo "There are ", count($robots), "\n";
	 *
	 * // How many mechanical robots are there?
	 * $robots = $robotsRepository->find(
	 *     "type = 'mechanical'"
	 * );
	 *
	 * echo "There are ", count($robots), "\n";
	 *
	 * // Get and print virtual robots ordered by name
	 * $robots = $robotsRepository->find(
	 *     [
	 *         "type = 'virtual'",
	 *         "order" => "name",
	 *     ]
	 * );
	 *
	 * foreach ($robots as $robot) {
	 *	 echo $robot->name, "\n";
	 * }
	 *
	 * // Get first 100 virtual robots ordered by name
	 * $robots = $robotsRepository->find(
	 *     [
	 *         "type = 'virtual'",
	 *         "order" => "name",
	 *         "limit" => 100,
	 *     ]
	 * );
	 *
	 * foreach ($robots as $robot) {
	 *	 echo $robot->name, "\n";
	 * }
	 * </code>
	 */
	public function find(var parameters = null) -> <ResultsetInterface>
	{
		var params, builder, query, bindParams, bindTypes, cache, resultset, hydration;

		if typeof parameters != "array" {
			let params = [];
			if parameters !== null {
				let params[] = parameters;
			}
		} else {
			let params = parameters;
		}

		/**
		 * Builds a query with the passed parameters
		 */
		let builder = this->_modelsManager->createBuilder(params);

		builder->from(this->_modelClass);

		let query = builder->getQuery();

		/**
		 * Check for bind parameters
		 */
		if fetch bindParams, params["bind"] {

			if typeof bindParams == "array" {
				query->setBindParams(bindParams, true);
			}

			if fetch bindTypes, params["bindTypes"] {
				if typeof bindTypes == "array" {
					query->setBindTypes(bindTypes, true);
				}
			}
		}

		/**
		 * Pass the cache options to the query
		 */
		if fetch cache, params["cache"] {
			query->cache(cache);
		}

		/**
		 * Execute the query passing the bind-params and casting-types
		 */
		let resultset = query->execute();

		/**
		 * Define an hydration mode
		 */
		if typeof resultset == "object" {
			if fetch hydration, params["hydration"] {
				resultset->setHydrateMode(hydration);
			}
		}

		return resultset;
	}

	/**
	 * Query the first record that matches the specified conditions
	 *
	 * <code>
	 * $robotsRepository = $modelsManager->getRepository(Robots::class);
	 *
	 * // What's the first robot in robots table?
	 * $robot = $robotsRepository->findFirst();
	 *
	 * echo "The robot name is ", $robot->name;
	 *
	 * // What's the first mechanical robot in robots table?
	 * $robot = $robotsRepository->findFirst(
	 *     "type = 'mechanical'"
	 * );
	 *
	 * echo "The first mechanical robot name is ", $robot->name;
	 *
	 * // Get first virtual robot ordered by name
	 * $robot = $robotsRepository->findFirst(
	 *     [
	 *         "type = 'virtual'",
	 *         "order" => "name",
	 *     ]
	 * );
	 *
	 * echo "The first virtual robot name is ", $robot->name;
	 * </code>
	 *
	 * @param string|array parameters
	 */
	public function findFirst(var parameters = null) -> <ModelInterface>
	{
		var params, builder, query, bindParams, bindTypes, cache;

		if typeof parameters != "array" {
			let params = [];
			if parameters !== null {
				let params[] = parameters;
			}
		} else {
			let params = parameters;
		}

		/**
		 * Builds a query with the passed parameters
		 */
		let builder = this->_modelsManager->createBuilder(params);

		builder->from(this->_modelClass);

		/**
		 * We only want the first record
		 */
		builder->limit(1);

		let query = builder->getQuery();

		/**
		 * Check for bind parameters
		 */
		if fetch bindParams, params["bind"] {

			if typeof bindParams == "array" {
				query->setBindParams(bindParams, true);
			}

			if fetch bindTypes, params["bindTypes"] {
				if typeof bindTypes == "array" {
					query->setBindTypes(bindTypes, true);
				}
			}
		}

		/**
		 * Pass the cache options to the query
		 */
		if fetch cache, params["cache"] {
			query->cache(cache);
		}

		/**
		 * Return only the first row
		 */
		query->setUniqueRow(true);

		/**
		 * Execute the query passing the bind-params and casting-types
		 */
		return query->execute();
	}

	/**
	 * Counts how many records match the specified conditions
	 *
	 * <code>
	 * $robotsRepository = $modelsManager->getRepository(Robots::class);
	 *
	 * // How many robots are there?
	 * $number = $robotsRepository->count();
	 *
	 * echo "There are ", $number, "\n";
	 *
	 * // How many mechanical robots are there?
	 * $number = $robotsRepository->count("type = 'mechanical'");
	 *
	 * echo "There are ", $number, " mechanical robots\n";
	 * </code>
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public function count(var parameters = null)
	{
		var result;

		let result = this->_groupResult("COUNT", "rowcount", parameters);

		if typeof result == "string" {
			return (int) result;
		}

		return result;
	}

	/**
	 * Calculates the sum on a column for a result-set of rows that match the specified conditions
	 *
	 * <code>
	 * $robotsRepository = $modelsManager->getRepository(Robots::class);
	 *
	 * // How much are all robots?
	 * $sum = $robotsRepository->sum(
	 *     [
	 *         "column" => "price",
	 *     ]
	 * );
	 *
	 * echo "The total price of robots is ", $sum, "\n";
	 *
	 * // How much are mechanical robots?
	 * $sum = $robotsRepository->sum(
	 *     [
	 *         "type = 'mechanical'",
	 *         "column" => "price",
	 *     ]
	 * );
	 *
	 * echo "The total price of mechanical robots is  ", $sum, "\n";
	 * </code>
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public function sum(var parameters = null)
	{
		return this->_groupResult("SUM", "sumatory", parameters);
	}

	/**
	 * Returns the maximum value of a column for a result-set of rows that match the specified conditions
	 *
	 * <code>
	 * $robotsRepository = $modelsManager->getRepository(Robots::class);
	 *
	 * // What is the maximum robot id?
	 * $id = $robotsRepository->maximum(
	 *     [
	 *         "column" => "id",
	 *     ]
	 * );
	 *
	 * echo "The maximum robot id is: ", $id, "\n";
	 *
	 * // What is the maximum id of mechanical robots?
	 * $sum = $robotsRepository->maximum(
	 *     [
	 *         "type = 'mechanical'",
	 *         "column" => "id",
	 *     ]
	 * );
	 *
	 * echo "The maximum robot id of mechanical robots is ", $id, "\n";
	 * </code>
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public function maximum(var parameters = null)
	{
		return this->_groupResult("MAX", "maximum", parameters);
	}

	/**
	 * Returns the minimum value of a column for a result-set of rows that match the specified conditions
	 *
	 * <code>
	 * $robotsRepository = $modelsManager->getRepository(Robots::class);
	 *
	 * // What is the minimum robot id?
	 * $id = $robotsRepository->minimum(
	 *     [
	 *         "column" => "id",
	 *     ]
	 * );
	 *
	 * echo "The minimum robot id is: ", $id;
	 *
	 * // What is the minimum id of mechanical robots?
	 * $sum = $robotsRepository->minimum(
	 *     [
	 *         "type = 'mechanical'",
	 *         "column" => "id",
	 *     ]
	 * );
	 *
	 * echo "The minimum robot id of mechanical robots is ", $id;
	 * </code>
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public function minimum(parameters = null)
	{
		return this->_groupResult("MIN", "minimum", parameters);
	}

	/**
	 * Returns the average value on a column for a result-set of rows matching the specified conditions
	 *
	 * <code>
	 * $robotsRepository = $modelsManager->getRepository(Robots::class);
	 *
	 * // What's the average price of robots?
	 * $average = $robotsRepository->average(
	 *     [
	 *         "column" => "price",
	 *     ]
	 * );
	 *
	 * echo "The average price is ", $average, "\n";
	 *
	 * // What's the average price of mechanical robots?
	 * $average = $robotsRepository->average(
	 *     [
	 *         "type = 'mechanical'",
	 *         "column" => "price",
	 *     ]
	 * );
	 *
	 * echo "The average price of mechanical robots is ", $average, "\n";
	 * </code>
	 *
	 * @param array parameters
	 * @return double
	 */
	public function average(var parameters = null)
	{
		return this->_groupResult("AVG", "average", parameters);
	}

	/**
	 * Generate a PHQL SELECT statement for an aggregate
	 *
	 * @param array parameters
	 */
	protected function _groupResult(string! functionName, string! alias, var parameters) -> <ResultsetInterface>
	{
		var params, distinctColumn, groupColumn, columns,
			bindParams, bindTypes, resultset, cache, firstRow, groupColumns,
			builder, query, manager;

		let manager = this->_modelsManager;

		if typeof parameters != "array" {
			let params = [];
			if parameters !== null {
				let params[] = parameters;
			}
		} else {
			let params = parameters;
		}

		if !fetch groupColumn, params["column"] {
			let groupColumn = "*";
		}

		/**
		 * Builds the columns to query according to the received parameters
		 */
		if fetch distinctColumn, params["distinct"] {
			let columns = functionName . "(DISTINCT " . distinctColumn . ") AS " . alias;
		} else {
			if fetch groupColumns, params["group"] {
				let columns = groupColumns . ", " . functionName . "(" . groupColumn . ") AS " . alias;
			} else {
				let columns = functionName . "(" . groupColumn . ") AS " . alias;
			}
		}

		/**
		 * Builds a query with the passed parameters
		 */
		let builder = manager->createBuilder(params);
		builder->columns(columns);
		builder->from(this->_modelClass);

		let query = builder->getQuery();

		/**
		 * Check for bind parameters
		 */
		let bindParams = null, bindTypes = null;
		if fetch bindParams, params["bind"] {
			fetch bindTypes, params["bindTypes"];
		}

		/**
		 * Pass the cache options to the query
		 */
		if fetch cache, params["cache"] {
			query->cache(cache);
		}

		/**
		 * Execute the query
		 */
		let resultset = query->execute(bindParams, bindTypes);

		/**
		 * Return the full resultset if the query is grouped
		 */
		if isset params["group"] {
			return resultset;
		}

		/**
		 * Return only the value in the first result
		 */
		let firstRow = resultset->getFirst();
		return firstRow->{alias};
	}

	/**
	 * Create a criteria for a specific model
	 */
	public function query(<DiInterface> dependencyInjector = null) -> <Criteria>
	{
		var criteria;

		/**
		 * Use the global dependency injector if there is no one defined
		 */
		if typeof dependencyInjector != "object" {
			let dependencyInjector = Di::getDefault();
		}

		/**
		 * Gets Criteria instance from DI container
		 */
		if dependencyInjector instanceof DiInterface {
			let criteria = <CriteriaInterface> dependencyInjector->get("Phalcon\\Mvc\\Model\\Criteria");
		} else {
			let criteria = new Criteria();

			criteria->setDI(dependencyInjector);
		}

		criteria->setModelName(this->_modelClass);

		return criteria;
	}

	/**
	 * Handles method calls when a method is not implemented
	 */
	public function __call(string method, array arguments) -> var
	{
		var extraMethod, type, value, model, attributes, field, extraMethodFirst, metaData, modelClass,
			success, matches;

		let modelClass = this->_modelClass;

		let success = preg_match("/^(find|findFirst|count)By(.+)$/", method, matches);

		/**
		 * The method doesn't exist throw an exception
		 */
		if success !== 1 {
			throw new Exception(
				"The method '" . method . "' doesn't exist on model '" . modelClass . "'"
			);
		}

		let type = matches[1];
		let extraMethod = matches[2];

		if !fetch value, arguments[0] {
			throw new Exception("The method '" . method . "' requires one argument");
		}

		let model = new {modelClass}(),
			metaData = model->getModelsMetaData();

		/**
		 * Get the attributes
		 */
		let attributes = metaData->getReverseColumnMap(model);

		if typeof attributes != "array" {
			let attributes = metaData->getDataTypes(model);
		}

		/**
		 * Check if the extra-method is an attribute
		 */
		if isset attributes[extraMethod] {
			let field = extraMethod;
		} else {
			/**
			 * Lowercase the first letter of the extra-method
			 */
			let extraMethodFirst = lcfirst(extraMethod);

			if isset attributes[extraMethodFirst] {
				let field = extraMethodFirst;
			} else {
				/**
				 * Get the possible real method name
				 */
				let field = uncamelize(extraMethod);

				if !isset attributes[field] {
					throw new Exception("Cannot resolve attribute '" . extraMethod . "' in the model");
				}
			}
		}

		/**
		 * Execute the query
		 */
		return this->{type}([
			"conditions": "[" . field . "] = ?0",
			"bind"		: [value]
		]);
	}

	/**
	 * Setup a 1-1 relation between two models
	 *
	 *<code>
	 * use Phalcon\Mvc\Model\Repository;
	 *
	 * class RobotsRepository extends Repository
	 * {
	 *     public function initialize()
	 *     {
	 *         $this->hasOne("id", RobotsDescription::class, "robots_id");
	 *     }
	 * }
	 *</code>
	 */
	protected function hasOne(var fields, string! referenceModel, var referencedFields, options = null) -> <Relation>
	{
		return (<ManagerInterface> this->_modelsManager)->addHasOne(this->_modelClass, fields, referenceModel, referencedFields, options);
	}

	/**
	 * Setup a reverse 1-1 or n-1 relation between two models
	 *
	 *<code>
	 * use Phalcon\Mvc\Model\Repository;
	 *
	 * class RobotsPartsRepository extends Repository
	 * {
	 *     public function initialize()
	 *     {
	 *         $this->belongsTo("robots_id", Robots::class, "id");
	 *     }
	 * }
	 *</code>
	 */
	protected function belongsTo(var fields, string! referenceModel, var referencedFields, options = null) -> <Relation>
	{
		return (<ManagerInterface> this->_modelsManager)->addBelongsTo(
			this->_modelClass,
			fields,
			referenceModel,
			referencedFields,
			options
		);
	}

	/**
	 * Setup a 1-n relation between two models
	 *
	 *<code>
	 * use Phalcon\Mvc\Model\Repository;
	 *
	 * class RobotsRepository extends Repository
	 * {
	 *     public function initialize()
	 *     {
	 *         $this->hasMany("id", RobotsParts::class, "robots_id");
	 *     }
	 * }
	 *</code>
	 */
	protected function hasMany(var fields, string! referenceModel, var referencedFields, options = null) -> <Relation>
	{
		return (<ManagerInterface> this->_modelsManager)->addHasMany(
			this->_modelClass,
			fields,
			referenceModel,
			referencedFields,
			options
		);
	}

	/**
	 * Setup an n-n relation between two models, through an intermediate relation
	 *
	 *<code>
	 * use Phalcon\Mvc\Model\Repository;
	 *
	 * class RobotsRepository extends Repository
	 * {
	 *     public function initialize()
	 *     {
	 *         // Setup a many-to-many relation to Parts through RobotsParts
	 *         $this->hasManyToMany(
	 *             "id",
	 *             RobotsParts::class,
	 *             "robots_id",
	 *             "parts_id",
	 *             Parts::class,
	 *             "id",
	 *         );
	 *     }
	 * }
	 *</code>
	 *
	 * @param	string|array fields
	 * @param	string|array intermediateFields
	 * @param	string|array intermediateReferencedFields
	 * @param   string|array referencedFields
	 * @param   array options
	 */
	protected function hasManyToMany(var fields, string! intermediateModel, var intermediateFields, var intermediateReferencedFields,
		string! referenceModel, var referencedFields, options = null) -> <Relation>
	{
		return (<ManagerInterface> this->_modelsManager)->addHasManyToMany(
			this->_modelClass,
			fields,
			intermediateModel,
			intermediateFields,
			intermediateReferencedFields,
			referenceModel,
			referencedFields,
			options
		);
	}

	/**
	 * Sets if a model must use dynamic update instead of the all-field update
	 *
	 *<code>
	 * use Phalcon\Mvc\Model\Repository;
	 *
	 * class RobotsRepository extends Repository
	 * {
	 *     public function initialize()
	 *     {
	 *         $this->useDynamicUpdate(true);
	 *     }
	 * }
	 *</code>
	 */
	protected function useDynamicUpdate(boolean dynamicUpdate) -> void
	{
		(<ManagerInterface> this->_modelsManager)->useDynamicUpdate(this->_modelClass, dynamicUpdate);
	}

	/**
	 * Sets the table name to which model should be mapped
	 */
	protected function setSource(string! source) -> void
	{
		(<ManagerInterface> this->_modelsManager)->setModelSource(this->_modelClass, source);
	}

	/**
	 * Returns the table name mapped in the model
	 */
	public function getSource() -> string
	{
		return (<ManagerInterface> this->_modelsManager)->getModelSource(this->_modelClass);
	}

	/**
	 * Sets schema name where the mapped table is located
	 */
	protected function setSchema(string! schema) -> void
	{
		(<ManagerInterface> this->_modelsManager)->setModelSchema(this->_modelClass, schema);
	}

	/**
	 * Returns schema name where the mapped table is located
	 */
	public function getSchema() -> string
	{
		return (<ManagerInterface> this->_modelsManager)->getModelSchema(this->_modelClass);
	}

	/**
	 * Sets the DependencyInjection connection service name
	 */
	public function setConnectionService(string! connectionService) -> <Repository>
	{
		(<ManagerInterface> this->_modelsManager)->setConnectionService(this->_modelClass, connectionService);
		return this;
	}

	/**
	 * Sets the DependencyInjection connection service name used to read data
	 */
	public function setReadConnectionService(string! connectionService) -> <Repository>
	{
		(<ManagerInterface> this->_modelsManager)->setReadConnectionService(this->_modelClass, connectionService);
		return this;
	}

	/**
	 * Sets the DependencyInjection connection service name used to write data
	 */
	public function setWriteConnectionService(string! connectionService) -> <Repository>
	{
		return (<ManagerInterface> this->_modelsManager)->setWriteConnectionService(this->_modelClass, connectionService);
	}

	/**
	 * Returns the DependencyInjection connection service name used to read data related the model
	 */
	public function getReadConnectionService() -> string
	{
		return (<ManagerInterface> this->_modelsManager)->getReadConnectionService(this->_modelClass);
	}

	/**
	 * Returns the DependencyInjection connection service name used to write data related to the model
	 */
	public function getWriteConnectionService() -> string
	{
		return (<ManagerInterface> this->_modelsManager)->getWriteConnectionService(this->_modelClass);
	}
}
