
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

use Phalcon\Mvc\Model\CriteriaInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\DiInterface;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Db\Column;

/**
 * Phalcon\Mvc\Model\Criteria
 *
 * This class is used to build the array parameter required by
 * Phalcon\Mvc\Model::find() and Phalcon\Mvc\Model::findFirst()
 * using an object-oriented interface.
 *
 *<code>
 *$robots = Robots::query()
 *    ->where("type = :type:")
 *    ->andWhere("year < 2000")
 *    ->bind(array("type" => "mechanical"))
 *    ->limit(5, 10)
 *    ->orderBy("name")
 *    ->execute();
 *</code>
 */
class Criteria implements CriteriaInterface, InjectionAwareInterface
{

	protected _model;

	protected _params;

	protected _bindParams;

	protected _bindTypes;

	protected _hiddenParamNumber = 0;

	/**
	 * Sets the DependencyInjector container
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_params["di"] = dependencyInjector;
	}

	/**
	 * Returns the DependencyInjector container
	 */
	public function getDI() -> <DiInterface> | null
	{
		var dependencyInjector;
		if fetch dependencyInjector, this->_params["di"] {
			return dependencyInjector;
		}
		return null;
	}

	/**
	 * Set a model on which the query will be executed
	 */
	public function setModelName(string! modelName) -> <Criteria>
	{
		let this->_model = modelName;
		return this;
	}

	/**
	 * Returns an internal model name on which the criteria will be applied
	 */
	public function getModelName() -> string
	{
		return this->_model;
	}

	/**
	 * Sets the bound parameters in the criteria
	 * This method replaces all previously set bound parameters
	 */
	public function bind(array! bindParams) -> <Criteria>
	{
		let this->_params["bind"] = bindParams;
		return this;
	}

	/**
	 * Sets the bind types in the criteria
	 * This method replaces all previously set bound parameters
	 */
	public function bindTypes(array! bindTypes) -> <Criteria>
	{
		let this->_params["bindTypes"] = bindTypes;
		return this;
	}

	/**
	 * Sets the columns to be queried
	 *
	 *<code>
	 *	$criteria->columns(array('id', 'name'));
	 *</code>
	 *
	 * @param string|array columns
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function columns(var columns) -> <Criteria>
	{
		let this->_params["columns"] = columns;
		return this;
	}

	/**
	 * Adds a INNER join to the query
	 *
	 *<code>
	 *	$criteria->join('Robots');
	 *	$criteria->join('Robots', 'r.id = RobotsParts.robots_id');
	 *	$criteria->join('Robots', 'r.id = RobotsParts.robots_id', 'r');
	 *	$criteria->join('Robots', 'r.id = RobotsParts.robots_id', 'r', 'LEFT');
	 *</code>
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @param string type
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function join(string! model, conditions = null, alias = null, type = null) -> <Criteria>
	{
		var join, mergedJoins, currentJoins;

		let join = [model, conditions, alias, type];
		if fetch currentJoins, this->_params["joins"] {
			if typeof currentJoins == "array" {
				let mergedJoins = array_merge(currentJoins, [join]);
			} else {
				let mergedJoins = [join];
			}
		} else {
			let mergedJoins = [join];
		}

		let this->_params["joins"] = mergedJoins;

		return this;
	}

	/**
	 * Adds a INNER join to the query
	 *
	 *<code>
	 *	$criteria->innerJoin('Robots');
	 *	$criteria->innerJoin('Robots', 'r.id = RobotsParts.robots_id');
	 *	$criteria->innerJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
	 *</code>
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function innerJoin(string! model, conditions = null, alias = null) -> <Criteria>
	{
		return this->join(model, conditions, alias, "INNER");
	}

	/**
	 * Adds a LEFT join to the query
	 *
	 *<code>
	 *	$criteria->leftJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
	 *</code>
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function leftJoin(string! model, conditions = null, alias = null) -> <Criteria>
	{
		return this->join(model, conditions, alias, "LEFT");
	}

	/**
	 * Adds a RIGHT join to the query
	 *
	 *<code>
	 *	$criteria->rightJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
	 *</code>
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function rightJoin(string! model, conditions = null, alias = null) -> <Criteria>
	{
		return this->join(model, conditions, alias, "RIGHT");
	}

	/**
	 * Sets the conditions parameter in the criteria
	 *
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function where(string! conditions, bindParams = null, bindTypes = null) -> <Criteria>
	{
		var currentBindParams, mergedParams, mergedParamsTypes, currentBindTypes;

		let this->_params["conditions"] = conditions;

		/**
		 * Update or merge existing bound parameters
		 */
		if typeof bindParams == "array" {
			if fetch currentBindParams, this->_params["bind"] {
				let mergedParams = array_merge(currentBindParams, bindParams);
			} else {
				let mergedParams = bindParams;
			}
			let this->_params["bind"] = mergedParams;
		}

		/**
		 * Update or merge existing bind types parameters
		 */
		if typeof bindTypes == "array" {
			if fetch currentBindTypes, this->_params["bindTypes"] {
				let mergedParamsTypes = array_merge(currentBindTypes, bindTypes);
			} else {
				let mergedParamsTypes = bindTypes;
			}
			let this->_params["bindTypes"] = mergedParamsTypes;
		}

		return this;
	}

	/**
	 * Appends a condition to the current conditions using an AND operator (deprecated)
	 *
	 * @deprecated 1.0.0
	 * @see \Phalcon\Mvc\Model\Criteria::andWhere()
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function addWhere(string! conditions, bindParams = null, bindTypes = null) -> <Criteria>
	{
		return this->andWhere(conditions, bindParams, bindTypes);
	}

	/**
	 * Appends a condition to the current conditions using an AND operator
	 *
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function andWhere(string! conditions, bindParams = null, bindTypes = null) -> <Criteria>
	{
		var currentBindParams, mergedParams, mergedParamsTypes, currentBindTypes, params, currentConditions;

		let params = this->_params;
		if fetch currentConditions, params["conditions"] {
			let this->_params["conditions"] = "(" . currentConditions . ") AND (" . conditions . ")";
		} else {
			let this->_params["conditions"] = conditions;
		}

		/**
		 * Update or merge existing bound parameters
		 */
		if typeof bindParams == "array" {
			if fetch currentBindParams, params["bind"] {
				let mergedParams = array_merge(currentBindParams, bindParams);
			} else {
				let mergedParams = bindParams;
			}
			let this->_params["bind"] = mergedParams;
		}

		/**
		 * Update or merge existing bind types parameters
		 */
		if typeof bindTypes == "array" {
			if fetch currentBindTypes, params["bindTypes"] {
				let mergedParamsTypes = array_merge(currentBindTypes, bindTypes);
			} else {
				let mergedParamsTypes = bindTypes;
			}
			let this->_params["bindTypes"] = mergedParamsTypes;
		}

		return this;
	}

	/**
	 * Appends a condition to the current conditions using an OR operator
	 *
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function orWhere(string! conditions, bindParams = null, bindTypes = null) -> <Criteria>
	{
		var currentBindParams, mergedParams, mergedParamsTypes, currentBindTypes, params, currentConditions;

		let params = this->_params;
		if fetch currentConditions, params["conditions"] {
			let this->_params["conditions"] = "(" . currentConditions . ") OR (" . conditions . ")";
		} else {
			let this->_params["conditions"] = conditions;
		}

		/**
		 * Update or merge existing bound parameters
		 */
		if typeof bindParams == "array" {
			if fetch currentBindParams, params["bind"] {
				let mergedParams = array_merge(currentBindParams, bindParams);
			} else {
				let mergedParams = bindParams;
			}
			let this->_params["bind"] = mergedParams;
		}

		/**
		 * Update or merge existing bind types parameters
		 */
		if typeof bindTypes == "array" {
			if fetch currentBindTypes, params["bindTypes"] {
				let mergedParamsTypes = array_merge(currentBindTypes, bindTypes);
			} else {
				let mergedParamsTypes = bindTypes;
			}
			let this->_params["bindTypes"] = mergedParamsTypes;
		}

		return this;
	}

	/**
	 * Appends a BETWEEN condition to the current conditions
	 *
	 *<code>
	 *	$criteria->betweenWhere('price', 100.25, 200.50);
	 *</code>
	 *
	 * @param string expr
	 * @param mixed minimum
	 * @param mixed maximum
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function betweenWhere(string! expr, minimum, maximum) -> <Criteria>
	{
		var hiddenParam, minimumKey, nextHiddenParam, maximumKey;

		let hiddenParam = this->_hiddenParamNumber, nextHiddenParam = hiddenParam + 1;

		/**
		 * Minimum key with auto bind-params
		 */
		let minimumKey = "phb" . hiddenParam;

		/**
		 * Maximum key with auto bind-params
		 */
		let maximumKey = "phb" . nextHiddenParam;

		/**
		 * Create a standard BETWEEN condition with bind params
		 * Append the BETWEEN to the current conditions using and "and"
		 */
		this->andWhere(
			expr . " BETWEEN :" . minimumKey . ": AND :" . maximumKey . ":",
			[minimumKey: minimum, maximumKey: maximum]
		);

		let nextHiddenParam++, this->_hiddenParamNumber = nextHiddenParam;

		return this;
	}

	/**
	 * Appends a NOT BETWEEN condition to the current conditions
	 *
	 *<code>
	 *	$criteria->notBetweenWhere('price', 100.25, 200.50);
	 *</code>
	 *
	 * @param string expr
	 * @param mixed minimum
	 * @param mixed maximum
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function notBetweenWhere(string! expr, minimum, maximum) -> <Criteria>
	{
		var hiddenParam, nextHiddenParam, minimumKey, maximumKey;

		let hiddenParam = this->_hiddenParamNumber;

		let nextHiddenParam = hiddenParam + 1;

		/**
		 * Minimum key with auto bind-params
		 */
		let minimumKey = "phb" . hiddenParam;

		/**
		 * Maximum key with auto bind-params
		 */
		let maximumKey = "phb" . nextHiddenParam;

		/**
		 * Create a standard BETWEEN condition with bind params
		 * Append the BETWEEN to the current conditions using and "and"
		 */
		this->andWhere(
			expr . " NOT BETWEEN :" . minimumKey . ": AND :"  . maximumKey . ":",
			[minimumKey: minimum, maximumKey: maximum]
		);

		let nextHiddenParam++;

		let this->_hiddenParamNumber = nextHiddenParam;

		return this;
	}

	/**
	 * Appends an IN condition to the current conditions
	 *
	 *<code>
	 *	$criteria->inWhere('id', [1, 2, 3]);
	 *</code>
	 */
	public function inWhere(string! expr, array! values) -> <Criteria>
	{
		var hiddenParam, bindParams, bindKeys, value, key, queryKey;

		let hiddenParam = this->_hiddenParamNumber;

		let bindParams = [];
		let bindKeys = [];

		for value in values {

			/**
			 * Key with auto bind-params
			 */
			let key = "phi" . hiddenParam;

			let queryKey = ":" . key . ":";

			let bindKeys[] = queryKey, bindParams[key] = value;

			let hiddenParam++;
		}

		/**
		 * Create a standard IN condition with bind params
		 * Append the IN to the current conditions using and "and"
		 */
		this->andWhere(expr . " IN (" . join(", ", bindKeys) . ")", bindParams);

		let this->_hiddenParamNumber = hiddenParam;

		return this;
	}

	/**
	 * Appends a NOT IN condition to the current conditions
	 *
	 *<code>
	 *	$criteria->notInWhere('id', [1, 2, 3]);
	 *</code>
	 */
	public function notInWhere(string! expr, array! values) -> <Criteria>
	{
		var hiddenParam, bindParams, bindKeys, value, key;

		let hiddenParam = this->_hiddenParamNumber;

		let bindParams = [], bindKeys = [];
		for value in values {

			/**
			 * Key with auto bind-params
			 */
			let key = "phi" . hiddenParam,
				bindKeys[] = ":" . key . ":",
				bindParams[key] = value;

			let hiddenParam++;
		}

		/**
		 * Create a standard IN condition with bind params
		 * Append the IN to the current conditions using and "and"
		 */
		this->andWhere(expr . " NOT IN (" . join(", ", bindKeys) . ")", bindParams);
		let this->_hiddenParamNumber = hiddenParam;

		return this;
	}

	/**
	 * Adds the conditions parameter to the criteria
	 */
	public function conditions(string! conditions) -> <Criteria>
	{
		let this->_params["conditions"] = conditions;
		return this;
	}

	/**
	 * Adds the order-by parameter to the criteria (deprecated)
	 *
	 * @deprecated 1.2.1
	 * @see \Phalcon\Mvc\Model\Criteria::orderBy()
	 */
	public function order(string! orderColumns) -> <Criteria>
	{
		let this->_params["order"] = orderColumns;
		return this;
	}

	/**
	 * Adds the order-by parameter to the criteria
	 */
	public function orderBy(string! orderColumns) -> <Criteria>
	{
		let this->_params["order"] = orderColumns;
		return this;
	}

	/**
	 * Adds the limit parameter to the criteria
	 *
	 * @param int limit
	 * @param int offset
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function limit(int limit, var offset = null) -> <Criteria>
	{
		if typeof offset == "null" {
			let this->_params["limit"] = limit;
		} else {
			let this->_params["limit"] = ["number": limit, "offset": offset];
		}

		return this;
	}

	/**
	 * Adds the "for_update" parameter to the criteria
	 */
	public function forUpdate(boolean forUpdate = true) -> <Criteria>
	{
		let this->_params["for_update"] = forUpdate;
		return this;
	}

	/**
	 * Adds the "shared_lock" parameter to the criteria
	 */
	public function sharedLock(boolean sharedLock = true) -> <Criteria>
	{
		let this->_params["shared_lock"] = sharedLock;
		return this;
	}

	/**
	 * Sets the cache options in the criteria
	 * This method replaces all previously set cache options
	 */
	public function cache(array! cache) -> <Criteria>
	{
		let this->_params["cache"] = cache;
		return this;
	}

	/**
	 * Returns the conditions parameter in the criteria
	 */
	public function getWhere() -> string | null
	{
		var conditions;
		if fetch conditions, this->_params["conditions"] {
			return conditions;
		}
		return null;
	}

	/**
	 * Returns the columns to be queried
	 *
	 * @return string|array|null
	 */
	public function getColumns() -> string | null
	{
		var columns;
		if fetch columns, this->_params["columns"] {
			return columns;
		}
		return null;
	}

	/**
	 * Returns the conditions parameter in the criteria
	 */
	public function getConditions() -> string | null
	{
		var conditions;
		if fetch conditions, this->_params["conditions"] {
			return conditions;
		}
		return null;
	}

	/**
	 * Returns the limit parameter in the criteria, which will be
	 * an integer if limit was set without an offset,
	 * an array with 'number' and 'offset' keys if an offset was set with the limit,
	 * or null if limit has not been set.
	 *
	 * @return int|array|null
	 */
	public function getLimit() -> string | null
	{
		var limit;
		if fetch limit, this->_params["limit"] {
			return limit;
		}
		return null;
	}

	/**
	 * Returns the order parameter in the criteria
	 */
	public function getOrder() -> string | null
	{
		var order;
		if fetch order, this->_params["order"] {
			return order;
		}
		return null;
	}

	/**
	 * Returns all the parameters defined in the criteria
	 *
	 * @return array
	 */
	public function getParams()
	{
		return this->_params;
	}

	/**
	 * Builds a Phalcon\Mvc\Model\Criteria based on an input array like _POST
	 */
	public static function fromInput(<DiInterface> dependencyInjector, string! modelName, array! data) -> <Criteria>
	{
		var conditions, field, value, type, metaData, model, dataTypes, bind, criteria;

		let conditions = [];
		if count(data) {

			let metaData = dependencyInjector->getShared("modelsMetadata");

			let model = new {modelName}();
			let dataTypes = metaData->getDataTypes(model);

			/**
			 * We look for attributes in the array passed as data
			 */
			let bind = [];
			for field, value in data {
				if fetch type, dataTypes[field] {
					if value !== null && value !== "" {
						if type == Column::TYPE_VARCHAR {
							/**
							 * For varchar types we use LIKE operator
							 */
							let conditions[] = field . " LIKE :" . field . ":", bind[field] = "%" . value . "%";
						} else {
							/**
							 * For the rest of data types we use a plain = operator
							 */
							let conditions[] = field . "=:" . field . ":", bind[field] = value;
						}
					}
				}
			}
		}

		/**
		 * Create an object instance and pass the paramaters to it
		 */
		let criteria = new self();
		if count(conditions) {
			criteria->where(join(" AND ", conditions));
			criteria->bind(bind);
		}

		criteria->setModelName(modelName);
		return criteria;
	}

	/**
	 * Executes a find using the parameters built with the criteria
	 */
	public function execute() -> <ResultsetInterface>
	{
		var model;
		let model = this->getModelName();
		if typeof model != "string" {
			throw new Exception("Model name must be string");
		}
		return {model}::find(this->getParams());
	}
}
