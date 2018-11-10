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

namespace Phalcon\Mvc\Model\Query;

use Phalcon\Di;
use Phalcon\Db\Column;
use Phalcon\DiInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\Model\QueryInterface;
use Phalcon\Mvc\Model\Query\BuilderInterface;

/**
 * Phalcon\Mvc\Model\Query\Builder
 *
 * Helps to create PHQL queries using an OO interface
 *
 *<code>
 * $params = [
 *     "models"     => ["Users"],
 *     "columns"    => ["id", "name", "status"],
 *     "conditions" => [
 *         [
 *             "created > :min: AND created < :max:",
 *             [
 *                 "min" => "2013-01-01",
 *                 "max" => "2014-01-01",
 *             ],
 *             [
 *                 "min" => PDO::PARAM_STR,
 *                 "max" => PDO::PARAM_STR,
 *             ],
 *         ],
 *     ],
 *     // or "conditions" => "created > '2013-01-01' AND created < '2014-01-01'",
 *     "group"      => ["id", "name"],
 *     "having"     => "name = 'Kamil'",
 *     "order"      => ["name", "id"],
 *     "limit"      => 20,
 *     "offset"     => 20,
 *     // or "limit" => [20, 20],
 * ];
 *
 * $queryBuilder = new \Phalcon\Mvc\Model\Query\Builder($params);
 *</code>
 */
class Builder implements BuilderInterface, InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _columns;

	protected _models;

	protected _joins;

	/**
	 * @deprecated Will be removed in version 4.0.0
	 */
	protected _with;

	protected _conditions;

	protected _group;

	protected _having;

	protected _order;

	protected _limit;

	protected _offset;

	protected _forUpdate;

	protected _sharedLock;

	protected _bindParams;

	protected _bindTypes;

	protected _distinct;

	protected _hiddenParamNumber = 0;

	/**
	 * Phalcon\Mvc\Model\Query\Builder constructor
	 */
	public function __construct(var params = null, <DiInterface> dependencyInjector = null)
	{
		var conditions, columns, groupClause, havingClause, limitClause,
			forUpdate, sharedLock, orderClause, offsetClause, joinsClause,
			singleConditionArray, limit, offset, fromClause,
			mergedConditions, mergedParams, mergedTypes,
			singleCondition, singleParams, singleTypes,
			distinct, bind, bindTypes;

		if typeof params == "array" {

			/**
			 * Process conditions
			 */
			if fetch conditions, params[0] {
				let this->_conditions = conditions;
			} else {
				if fetch conditions, params["conditions"] {
					let this->_conditions = conditions;
				}
			}

			if typeof conditions == "array" {

				let mergedConditions = [];
				let mergedParams     = [];
				let mergedTypes      = [];
				for singleConditionArray in conditions {

					if typeof singleConditionArray == "array" {

						fetch singleCondition, singleConditionArray[0];
						fetch singleParams, singleConditionArray[1];
						fetch singleTypes, singleConditionArray[2];

						if typeof singleCondition == "string" {
							let mergedConditions[] = singleCondition;
						}

						if typeof singleParams == "array" {
							let mergedParams = mergedParams + singleParams;
						}

						if typeof singleTypes == "array" {
							let mergedTypes = mergedTypes + singleTypes;
						}
					}
				}

				let this->_conditions = implode(" AND ", mergedConditions);

				if typeof mergedParams == "array" {
					let this->_bindParams = mergedParams;
				}

				if typeof mergedTypes == "array" {
					let this->_bindTypes  = mergedTypes;
				}
			}

			/**
			 * Assign bind types
			 */
			if fetch bind, params["bind"] {
				let this->_bindParams = bind;
			}

			if fetch bindTypes, params["bindTypes"] {
				let this->_bindTypes = bindTypes;
			}

			/**
			 * Assign SELECT DISTINCT / SELECT ALL clause
			 */
			if fetch distinct, params["distinct"] {
				let this->_distinct = distinct;
			}

			/**
			 * Assign FROM clause
			 */
			if fetch fromClause, params["models"] {
				let this->_models = fromClause;
			}

			/**
			 * Assign COLUMNS clause
			 */
			if fetch columns, params["columns"] {
				let this->_columns = columns;
			}

			/**
			 * Assign JOIN clause
			 */
			if fetch joinsClause, params["joins"] {
				let this->_joins = joinsClause;
			}

			/**
			 * Assign GROUP clause
			 */
			if fetch groupClause, params["group"] {
				let this->_group = groupClause;
			}

			/**
			 * Assign HAVING clause
			 */
			if fetch havingClause, params["having"] {
				let this->_having = havingClause;
			}

			/**
			 * Assign ORDER clause
			 */
			if fetch orderClause, params["order"] {
				let this->_order = orderClause;
			}

			/**
			 * Assign LIMIT clause
			 */
			if fetch limitClause, params["limit"] {
				if typeof limitClause == "array" {
					if fetch limit, limitClause[0] {
						if is_int(limit) {
							let this->_limit = limit;
						}
						if fetch offset, limitClause[1] {
							if is_int(offset) {
								let this->_offset = offset;
							}
						}
					} else {
						let this->_limit = limitClause;
					}
				} else {
					let this->_limit = limitClause;
				}
			}

			/**
			 * Assign OFFSET clause
			 */
			if fetch offsetClause, params["offset"] {
				let this->_offset = offsetClause;
			}

			/**
			 * Assign FOR UPDATE clause
			 */
			if fetch forUpdate, params["for_update"] {
				let this->_forUpdate = forUpdate;
			}

			/**
			 * Assign SHARED LOCK clause
			 */
			if fetch sharedLock, params["shared_lock"] {
				let this->_sharedLock = sharedLock;
			}
		} else {
			if typeof params == "string" && params !== "" {
				let this->_conditions = params;
			}
		}

		/**
		 * Update the dependency injector if any
		 */
		if typeof dependencyInjector == "object" {
			let this->_dependencyInjector = dependencyInjector;
		}
	}

	/**
	 * Sets the DependencyInjector container
	 */
	public function setDI(<DiInterface> dependencyInjector) -> <Builder>
	{
		let this->_dependencyInjector = dependencyInjector;
		return this;
	}

	/**
	 * Returns the DependencyInjector container
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets SELECT DISTINCT / SELECT ALL flag
	 *
	 *<code>
	 * $builder->distinct("status");
	 * $builder->distinct(null);
	 *</code>
	 */
	 public function distinct(var distinct) -> <Builder>
	 {
	 	let this->_distinct = distinct;
	 	return this;
	 }

	/**
	 * Returns SELECT DISTINCT / SELECT ALL flag
	 */
	public function getDistinct() -> boolean
	{
		return this->_distinct;
	}

	/**
	 * Sets the columns to be queried
	 *
	 *<code>
	 * $builder->columns("id, name");
	 *
	 * $builder->columns(
	 *     [
	 *         "id",
	 *         "name",
	 *     ]
	 * );
	 *
	 * $builder->columns(
	 *     [
	 *         "name",
	 *         "number" => "COUNT(*)",
	 *     ]
	 * );
	 *</code>
	 */
	public function columns(var columns) -> <Builder>
	{
		let this->_columns = columns;
		return this;
	}

	/**
	 * Return the columns to be queried
	 *
	 * @return string|array
	 */
	public function getColumns()
	{
		return this->_columns;
	}

	/**
	 * Sets the models who makes part of the query
	 *
	 *<code>
	 * $builder->from("Robots");
	 *
	 * $builder->from(
	 *     [
	 *         "Robots",
	 *         "RobotsParts",
	 *     ]
	 * );
	 *
	 * $builder->from(
	 *     [
	 *         "r"  => "Robots",
	 *         "rp" => "RobotsParts",
	 *     ]
	 * );
	 *</code>
	 */
	public function from(var models) -> <Builder>
	{
		let this->_models = models;
		return this;
	}

	/**
	 * Add a model to take part of the query
	 *
	 * NOTE: The third parameter $with is deprecated and will be removed in future releases.
	 *
	 *<code>
	 * // Load data from models Robots
	 * $builder->addFrom("Robots");
	 *
	 * // Load data from model 'Robots' using 'r' as alias in PHQL
	 * $builder->addFrom("Robots", "r");
	 *</code>
	 */
	public function addFrom(var model, var alias = null, var with = null) -> <Builder>
	{
		var models, currentModel;

		if typeof with != "null" {
			trigger_error(
				"The third parameter 'with' is deprecated and will be removed in future releases.",
				E_DEPRECATED
			);
		}

		let models = this->_models;
		if typeof models != "array" {
			if typeof models != "null" {
				let currentModel = models,
					models = [currentModel];
			} else {
				let models = [];
			}
		}

		if typeof alias == "string" {
			let models[alias] = model;
		} else {
			let models[] = model;
		}

		let this->_models = models;
		return this;
	}

	/**
	 * Return the models who makes part of the query
	 *
	 * @return string|array
	 */
	public function getFrom()
	{
		return this->_models;
	}

	/**
	 * Adds an :type: join (by default type - INNER) to the query
	 *
	 *<code>
	 * // Inner Join model 'Robots' with automatic conditions and alias
	 * $builder->join("Robots");
	 *
	 * // Inner Join model 'Robots' specifying conditions
	 * $builder->join("Robots", "Robots.id = RobotsParts.robots_id");
	 *
	 * // Inner Join model 'Robots' specifying conditions and alias
	 * $builder->join("Robots", "r.id = RobotsParts.robots_id", "r");
	 *
	 * // Left Join model 'Robots' specifying conditions, alias and type of join
	 * $builder->join("Robots", "r.id = RobotsParts.robots_id", "r", "LEFT");
	 *</code>
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @param string type
	 * @return \Phalcon\Mvc\Model\Query\Builder
	 */
	public function join(string! model, var conditions = null, var alias = null, var type = null) -> <Builder>
	{
		let this->_joins[] = [model, conditions, alias, type];
		return this;
	}

	/**
	 * Adds an INNER join to the query
	 *
	 *<code>
	 * // Inner Join model 'Robots' with automatic conditions and alias
	 * $builder->innerJoin("Robots");
	 *
	 * // Inner Join model 'Robots' specifying conditions
	 * $builder->innerJoin("Robots", "Robots.id = RobotsParts.robots_id");
	 *
	 * // Inner Join model 'Robots' specifying conditions and alias
	 * $builder->innerJoin("Robots", "r.id = RobotsParts.robots_id", "r");
	 *</code>
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @param string type
	 * @return \Phalcon\Mvc\Model\Query\Builder
	 */
	public function innerJoin(string! model, var conditions = null, var alias = null) -> <Builder>
	{
		let this->_joins[] = [model, conditions, alias, "INNER"];
		return this;
	}

	/**
	 * Adds a LEFT join to the query
	 *
	 *<code>
	 * $builder->leftJoin("Robots", "r.id = RobotsParts.robots_id", "r");
	 *</code>
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @return \Phalcon\Mvc\Model\Query\Builder
	 */
	public function leftJoin(string! model, var conditions = null, var alias = null) -> <Builder>
	{
		let this->_joins[] = [model, conditions, alias, "LEFT"];
		return this;
	}

	/**
	 * Adds a RIGHT join to the query
	 *
	 *<code>
	 * $builder->rightJoin("Robots", "r.id = RobotsParts.robots_id", "r");
	 *</code>
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @return \Phalcon\Mvc\Model\Query\Builder
	 */
	public function rightJoin(string! model, var conditions = null, var alias = null) -> <Builder>
	{
		let this->_joins[] = [model, conditions, alias, "RIGHT"];
		return this;
	}

	/**
	 * Return join parts of the query
	 *
	 * @return array
	 */
	public function getJoins()
	{
		return this->_joins;
	}

	/**
	 * Sets the query WHERE conditions
	 *
	 *<code>
	 * $builder->where(100);
	 *
	 * $builder->where("name = 'Peter'");
	 *
	 * $builder->where(
	 *     "name = :name: AND id > :id:",
	 *     [
	 *         "name" => "Peter",
	 *         "id"   => 100,
	 *     ]
	 * );
	 *</code>
	 *
	 * @param mixed conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return \Phalcon\Mvc\Model\Query\Builder
	 */
	public function where(var conditions, var bindParams = null, var bindTypes = null) -> <Builder>
	{
		var currentBindParams, currentBindTypes;

		let this->_conditions = conditions;

		/**
		 * Merge the bind params to the current ones
		 */
		if typeof bindParams == "array" {
			let currentBindParams = this->_bindParams;
			if typeof currentBindParams == "array" {
				let this->_bindParams = currentBindParams + bindParams;
			} else {
				let this->_bindParams = bindParams;
			}
		}

		/**
		 * Merge the bind types to the current ones
		 */
		if typeof bindTypes == "array" {
			let currentBindTypes = this->_bindTypes;
			if typeof currentBindTypes == "array" {
				let this->_bindTypes = currentBindTypes + bindTypes;
			} else {
				let this->_bindTypes = bindTypes;
			}
		}

		return this;
	}

	/**
	 * Appends a condition to the current WHERE conditions using a AND operator
	 *
	 *<code>
	 * $builder->andWhere("name = 'Peter'");
	 *
	 * $builder->andWhere(
	 *     "name = :name: AND id > :id:",
	 *     [
	 *         "name" => "Peter",
	 *         "id"   => 100,
	 *     ]
	 * );
	 *</code>
	 *
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return \Phalcon\Mvc\Model\Query\Builder
	 */
	public function andWhere(string! conditions, var bindParams = null, var bindTypes = null) -> <Builder>
	{
		var currentConditions;

		let currentConditions = this->_conditions;

		/**
		 * Nest the condition to current ones or set as unique
		 */
		if currentConditions {
			let conditions = "(" . currentConditions . ") AND (" . conditions . ")";
		}

		return this->where(conditions, bindParams, bindTypes);
	}

	/**
	 * Appends a condition to the current conditions using an OR operator
	 *
	 *<code>
	 * $builder->orWhere("name = 'Peter'");
	 *
	 * $builder->orWhere(
	 *     "name = :name: AND id > :id:",
	 *     [
	 *         "name" => "Peter",
	 *         "id"   => 100,
	 *     ]
	 * );
	 *</code>
	 *
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return \Phalcon\Mvc\Model\Query\Builder
	 */
	public function orWhere(string! conditions, var bindParams = null, var bindTypes = null) -> <Builder>
	{
		var currentConditions;

		let currentConditions = this->_conditions;

		/**
		 * Nest the condition to current ones or set as unique
		 */
		if currentConditions {
			let conditions = "(" . currentConditions . ") OR (" . conditions . ")";
		}

		return this->where(conditions, bindParams, bindTypes);
	}

	/**
	 * Appends a BETWEEN condition to the current WHERE conditions
	 *
	 *<code>
	 * $builder->betweenWhere("price", 100.25, 200.50);
	 *</code>
	 */
	public function betweenWhere(string! expr, var minimum, var maximum, string! operator = BuilderInterface::OPERATOR_AND) -> <Builder>
	{
		return this->_conditionBetween("Where", operator, expr, minimum, maximum);
	}

	/**
	 * Appends a NOT BETWEEN condition to the current WHERE conditions
	 *
	 *<code>
	 * $builder->notBetweenWhere("price", 100.25, 200.50);
	 *</code>
	 */
	public function notBetweenWhere(string! expr, var minimum, var maximum, string! operator = BuilderInterface::OPERATOR_AND) -> <Builder>
	{
		return this->_conditionNotBetween("Where", operator, expr, minimum, maximum);
	}

	/**
	 * Appends an IN condition to the current WHERE conditions
	 *
	 *<code>
	 * $builder->inWhere("id", [1, 2, 3]);
	 *</code>
	 */
	public function inWhere(string! expr, array! values, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
	{
		return this->_conditionIn("Where", operator, expr, values);
	}

	/**
	 * Appends a NOT IN condition to the current WHERE conditions
	 *
	 *<code>
	 * $builder->notInWhere("id", [1, 2, 3]);
	 *</code>
	 */
	public function notInWhere(string! expr, array! values, string! operator = BuilderInterface::OPERATOR_AND) -> <BuilderInterface>
	{
		return this->_conditionNotIn("Where", operator, expr, values);
	}

	/**
	 * Return the conditions for the query
	 *
	 * @return string|array
	 */
	public function getWhere()
	{
		return this->_conditions;
	}

	/**
	 * Sets an ORDER BY condition clause
	 *
	 *<code>
	 * $builder->orderBy("Robots.name");
	 * $builder->orderBy(["1", "Robots.name"]);
	 * $builder->orderBy(["Robots.name DESC"]);
	 *</code>
	 *
	 * @param string|array orderBy
	 * @return \Phalcon\Mvc\Model\Query\Builder
	 */
	public function orderBy(var orderBy) -> <Builder>
	{
		let this->_order = orderBy;
		return this;
	}

	/**
	 * Returns the set ORDER BY clause
	 *
	 * @return string|array
	 */
	public function getOrderBy()
	{
		return this->_order;
	}

	/**
	 * Sets the HAVING condition clause
	 *
	 *<code>
	 * $builder->having("SUM(Robots.price) > 0");
	 *
	 * $builder->having(
	 *     "SUM(Robots.price) > :sum:",
	 *     [
	 *         "sum" => 100,
	 *     ]
	 * );
	 *</code>
	 *
	 * @param mixed conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return \Phalcon\Mvc\Model\Query\Builder
	 */
	public function having(var conditions, var bindParams = null, var bindTypes = null) -> <Builder>
	{
		var currentBindParams, currentBindTypes;

		let this->_having = conditions;

		/**
		 * Merge the bind params to the current ones
		 */
		if typeof bindParams == "array" {
			let currentBindParams = this->_bindParams;
			if typeof currentBindParams == "array" {
				let this->_bindParams = currentBindParams + bindParams;
			} else {
				let this->_bindParams = bindParams;
			}
		}

		/**
		 * Merge the bind types to the current ones
		 */
		if typeof bindTypes == "array" {
			let currentBindTypes = this->_bindTypes;
			if typeof currentBindTypes == "array" {
				let this->_bindTypes = currentBindTypes + bindTypes;
			} else {
				let this->_bindTypes = bindTypes;
			}
		}

		return this;
	}

	/**
	 * Appends a condition to the current HAVING conditions clause using a AND operator
	 *
	 *<code>
	 * $builder->andHaving("SUM(Robots.price) > 0");
	 *
	 * $builder->andHaving(
	 *     "SUM(Robots.price) > :sum:",
	 *     [
	 *         "sum" => 100,
	 *     ]
	 * );
	 *</code>
	 *
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return \Phalcon\Mvc\Model\Query\Builder
	 */
	public function andHaving(string! conditions, var bindParams = null, var bindTypes = null) -> <Builder>
	{
		var currentConditions;

		let currentConditions = this->_having;

		/**
		 * Nest the condition to current ones or set as unique
		 */
		if currentConditions {
			let conditions = "(" . currentConditions . ") AND (" . conditions . ")";
		}

		return this->having(conditions, bindParams, bindTypes);
	}

	/**
	 * Appends a condition to the current HAVING conditions clause using an OR operator
	 *
	 *<code>
	 * $builder->orHaving("SUM(Robots.price) > 0");
	 *
	 * $builder->orHaving(
	 *     "SUM(Robots.price) > :sum:",
	 *     [
	 *         "sum" => 100,
	 *     ]
	 * );
	 *</code>
	 *
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return \Phalcon\Mvc\Model\Query\Builder
	 */
	public function orHaving(string! conditions, var bindParams = null, var bindTypes = null) -> <Builder>
	{
		var currentConditions;

		let currentConditions = this->_having;

		/**
		 * Nest the condition to current ones or set as unique
		 */
		if currentConditions {
			let conditions = "(" . currentConditions . ") OR (" . conditions . ")";
		}

		return this->having(conditions, bindParams, bindTypes);
	}

	/**
	 * Appends a BETWEEN condition to the current HAVING conditions clause
	 *
	 *<code>
	 * $builder->betweenHaving("SUM(Robots.price)", 100.25, 200.50);
	 *</code>
	 */
	public function betweenHaving(string! expr, var minimum, var maximum, string! operator = BuilderInterface::OPERATOR_AND) -> <Builder>
	{
		return this->_conditionBetween("Having", operator, expr, minimum, maximum);
	}

	/**
	 * Appends a NOT BETWEEN condition to the current HAVING conditions clause
	 *
	 *<code>
	 * $builder->notBetweenHaving("SUM(Robots.price)", 100.25, 200.50);
	 *</code>
	 */
	public function notBetweenHaving(string! expr, var minimum, var maximum, string! operator = BuilderInterface::OPERATOR_AND) -> <Builder>
	{
		return this->_conditionNotBetween("Having", operator, expr, minimum, maximum);
	}

	/**
	 * Appends an IN condition to the current HAVING conditions clause
	 *
	 *<code>
	 * $builder->inHaving("SUM(Robots.price)", [100, 200]);
	 *</code>
	 */
	public function inHaving(string! expr, array! values, string! operator = BuilderInterface::OPERATOR_AND) -> <Builder>
	{
		return this->_conditionIn("Having", operator, expr, values);
	}

	/**
	 * Appends a NOT IN condition to the current HAVING conditions clause
	 *
	 *<code>
	 * $builder->notInHaving("SUM(Robots.price)", [100, 200]);
	 *</code>
	 */
	public function notInHaving(string! expr, array! values, string! operator = BuilderInterface::OPERATOR_AND) -> <Builder>
	{
		return this->_conditionNotIn("Having", operator, expr, values);
	}

	/**
	 * Return the current having clause
	 *
	 * @return string
	 */
	public function getHaving()
	{
		return this->_having;
	}

	/**
	 * Sets a FOR UPDATE clause
	 *
	 *<code>
	 * $builder->forUpdate(true);
	 *</code>
	 */
	public function forUpdate(boolean forUpdate) -> <Builder>
	{
		let this->_forUpdate = forUpdate;
		return this;
	}

	/**
	 * Sets a LIMIT clause, optionally an offset clause
	 *
	 * <code>
	 * $builder->limit(100);
	 * $builder->limit(100, 20);
	 * $builder->limit("100", "20");
	 * </code>
	 */
	public function limit(int limit, var offset = null) -> <Builder>
	{
		let limit = abs(limit);

		if unlikely limit == 0 {
			return this;
		}

		let this->_limit = limit;

		if is_numeric(offset) {
			let this->_offset = abs((int) offset);
		}

		return this;
	}

	/**
	 * Returns the current LIMIT clause
	 *
	 * @return string|array
	 */
	public function getLimit()
	{
		return this->_limit;
	}

	/**
	 * Sets an OFFSET clause
	 *
	 *<code>
	 * $builder->offset(30);
	 *</code>
	 */
	public function offset(int offset) -> <Builder>
	{
		let this->_offset = offset;
		return this;
	}

	/**
	 * Returns the current OFFSET clause
	 *
	 * @return string|array
	 */
	public function getOffset()
	{
		return this->_offset;
	}

	/**
	 * Sets a GROUP BY clause
	 *
	 *<code>
	 * $builder->groupBy(
	 *     [
	 *         "Robots.name",
	 *     ]
	 * );
	 *</code>
	 *
	 * @param string|array group
	 * @return \Phalcon\Mvc\Model\Query\Builder
	 */
	public function groupBy(var group) -> <Builder>
	{
		let this->_group = group;
		return this;
	}

	/**
	 * Returns the GROUP BY clause
	 *
	 * @return string
	 */
	public function getGroupBy()
	{
		return this->_group;
	}

	/**
	 * Returns a PHQL statement built based on the builder parameters
	 *
	 * @return string
	 */
	public final function getPhql() -> string
	{
		var dependencyInjector, models, conditions, model, metaData,
			modelInstance, primaryKeys, firstPrimaryKey, columnMap, modelAlias,
			attributeField, phql, column, columns, selectedColumns, selectedColumn,
			selectedModel, selectedModels, columnAlias, modelColumnAlias,
			joins, join, joinModel, joinConditions, joinAlias, joinType, group,
			groupItems, groupItem, having, order, orderItems, orderItem,
			limit, number, offset, forUpdate, distinct;
		boolean noPrimary;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			let dependencyInjector = Di::getDefault(),
				this->_dependencyInjector = dependencyInjector;
		}

		let models = this->_models;
		if typeof models == "array" {
			if !count(models) {
				throw new Exception("At least one model is required to build the query");
			}
		} else {
			if !models {
				throw new Exception("At least one model is required to build the query");
			}
		}

		let conditions = this->_conditions;

		if is_numeric(conditions) {

			/**
			 * If the conditions is a single numeric field. We internally create a condition using the related primary key
			 */
			if typeof models == "array" {
				if count(models) > 1 {
					throw new Exception("Cannot build the query. Invalid condition");
				}
				let model = models[0];
			} else {
				let model = models;
			}

			/**
			 * Get the models metadata service to obtain the column names, column map and primary key
			 */
			let metaData = dependencyInjector->getShared("modelsMetadata"),
				modelInstance = new {model}(null, dependencyInjector);

			let noPrimary = true,
				primaryKeys = metaData->getPrimaryKeyAttributes(modelInstance);
			if count(primaryKeys) {

				if fetch firstPrimaryKey, primaryKeys[0] {

					/**
					 * The PHQL contains the renamed columns if available
					 */
					if globals_get("orm.column_renaming") {
						let columnMap = metaData->getColumnMap(modelInstance);
					} else {
						let columnMap = null;
					}

					if typeof columnMap == "array" {
						if !fetch attributeField, columnMap[firstPrimaryKey] {
							throw new Exception("Column '" . firstPrimaryKey . "' isn't part of the column map");
						}
					} else {
						let attributeField = firstPrimaryKey;
					}

					let conditions = this->autoescape(model) . "." . this->autoescape(attributeField) . " = " . conditions,
						noPrimary = false;
				}
			}

			/**
			 * A primary key is mandatory in these cases
			 */
			if noPrimary === true {
				throw new Exception("Source related to this model does not have a primary key defined");
			}
		}

		let distinct = this->_distinct;
		if typeof distinct != "null" && typeof distinct == "bool" {
			if distinct {
				let phql = "SELECT DISTINCT ";
			} else {
				let phql = "SELECT ALL ";
			}
		} else {
			let phql = "SELECT ";
		}

		let columns = this->_columns;
		if typeof columns !== "null" {

			/**
			 * Generate PHQL for columns
			 */
			if typeof columns == "array" {

				let selectedColumns = [];
				for columnAlias, column in columns {
					if typeof columnAlias == "integer" {
						let selectedColumns[] = column;
					} else {
						let selectedColumns[] = column . " AS " . this->autoescape(columnAlias);
					}
				}

				let phql .= join(", ", selectedColumns);

			} else {
				let phql .= columns;
			}

		} else {

			/**
			 * Automatically generate an array of models
			 */
			if typeof models == "array" {

				let selectedColumns = [];
				for modelColumnAlias, model in models {
					if typeof modelColumnAlias == "integer" {
						let selectedColumn = this->autoescape(model) . ".*";
					} else {
						let selectedColumn = this->autoescape(modelColumnAlias) . ".*";
					}
					let selectedColumns[] = selectedColumn;
				}

				let phql .= join(", ", selectedColumns);
			} else {
				let phql .= this->autoescape(models) . ".*";
			}
		}

		/**
		 * Join multiple models or use a single one if it is a string
		 */
		if typeof models == "array" {

			let selectedModels = [];
			for modelAlias, model in models {

				if typeof modelAlias == "string" {
					let selectedModel = this->autoescape(model) . " AS " . this->autoescape(modelAlias);
				} else {
					let selectedModel = this->autoescape(model);
				}

				let selectedModels[] = selectedModel;
			}

			let phql .= " FROM " . join(", ", selectedModels);

		} else {
			let phql .= " FROM " . this->autoescape(models);
		}

		/**
		 * Check if joins were passed to the builders
		 */
		let joins = this->_joins;
		if typeof joins == "array" {

			for join in joins {

				/**
				 * The joined table is in the first place of the array
				 */
				let joinModel = join[0];

				/**
				 * The join conditions are in the second place of the array
				 */
				let joinConditions = join[1];

				/**
				 * The join alias is in the second place of the array
				 */
				let joinAlias = join[2];

				/**
				 * Join type
				 */
				let joinType = join[3];

				/**
				 * Create the join according to the type
				 */
				if joinType {
					let phql .= " " . joinType . " JOIN " . this->autoescape(joinModel);
				} else {
					let phql .= " JOIN " . this->autoescape(joinModel);
				}

				/**
				 * Alias comes first
				 */
				if joinAlias {
					let phql .= " AS " . this->autoescape(joinAlias);
				}

				/**
				 * Conditions then
				 */
				if joinConditions {
					let phql .= " ON " . joinConditions;
				}
			}
		}

		// Only append where conditions if it's string
		if typeof conditions == "string" {
			if !empty conditions {
				let phql .= " WHERE " . conditions;
			}
		}

		/**
		 * Process group parameters
		 */
		let group = this->_group;
		if group !== null {
			if typeof group == "string" {
				if memstr(group, ",") {
					let group = str_replace(" ", "", group);
				}

				let group = explode(",", group);
			}

			let groupItems = [];
			for groupItem in group {
				let groupItems[] = this->autoescape(groupItem);
			}

			let phql .= " GROUP BY " . join(", ", groupItems);
		}

		/**
		 * Process having clause
		 */
		let having = this->_having;
		if having !== null {
			if !empty having {
				let phql .= " HAVING " . having;
			}
		}

		/**
		 * Process order clause
		 */
		let order = this->_order;
		if order !== null {
			if typeof order == "array" {
				let orderItems = [];
				for orderItem in order {
					/**
					 * For case 'ORDER BY 1'
					 */
					if typeof orderItem == "integer" {
						let orderItems[] = orderItem;

						continue;
					}

					if memstr(orderItem, " ") !== 0 {
						var itemExplode;
						let itemExplode = explode(" ", orderItem);
						let orderItems[] = this->autoescape(itemExplode[0]) . " " . itemExplode[1];

						continue;
					}

					let orderItems[] = this->autoescape(orderItem);
				}

				let phql .= " ORDER BY " . join(", ", orderItems);
			} else {
				let phql .= " ORDER BY " . order;
			}
		}

		/**
		 * Process limit parameters
		 */
		let limit = this->_limit;
		if limit !== null {

			let number = null;
			if typeof limit == "array" {

				let number = limit["number"];
				if fetch offset, limit["offset"] {
					if !is_numeric(offset) {
						let offset = 0;
					}
				}

			} else {
				if is_numeric(limit) {
					let number = limit,
						offset = this->_offset;
					if offset !== null {
						if !is_numeric(offset) {
							let offset = 0;
						}
					}
				}
			}

			if is_numeric(number) {

				let phql .= " LIMIT :APL0:",
					this->_bindParams["APL0"] = intval(number, 10),
					this->_bindTypes["APL0"] = Column::BIND_PARAM_INT;

				if is_numeric(offset) {
					let phql .= " OFFSET :APL1:",
						this->_bindParams["APL1"] = intval(offset, 10),
						this->_bindTypes["APL1"] = Column::BIND_PARAM_INT;
				}
			}
		}

		let forUpdate = this->_forUpdate;
		if typeof forUpdate === "boolean" {
			if forUpdate {
				let phql .= " FOR UPDATE";
			}
		}

		return phql;
	}

	/**
	 * Returns the query built
	 */
	public function getQuery() -> <QueryInterface>
	{
		var query, bindParams, bindTypes, phql, dependencyInjector;

		let phql = this->getPhql();

		let dependencyInjector = <DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injection object is required to access ORM services");
		}

		/**
		 * Gets Query instance from DI container
		 */
		let query = <QueryInterface> dependencyInjector->get(
			"Phalcon\\Mvc\\Model\\Query",
			[phql, dependencyInjector]
		);

		// Set default bind params
		let bindParams = this->_bindParams;
		if typeof bindParams == "array" {
			query->setBindParams(bindParams);
		}

		// Set default bind types
		let bindTypes = this->_bindTypes;
		if typeof bindTypes == "array" {
			query->setBindTypes(bindTypes);
		}

		if typeof this->_sharedLock === "boolean" {
			query->setSharedLock(this->_sharedLock);
		}

		return query;
	}

	/**
	 * Automatically escapes identifiers but only if they need to be escaped.
	 */
	final public function autoescape(string identifier) -> string
	{
		if memstr(identifier, "[") || memstr(identifier, ".") || is_numeric(identifier) {
			return identifier;
		}

		return "[" . identifier . "]";
	}

	/**
	 * Appends a BETWEEN condition
	 */
	protected function _conditionBetween(string! clause, string! operator, string! expr, var minimum, var maximum) -> <Builder>
	{
		var hiddenParam, nextHiddenParam, minimumKey, maximumKey, operatorMethod;

		if (operator !== Builder::OPERATOR_AND && operator !== Builder::OPERATOR_OR) {
			throw new Exception(sprintf("Operator % is not available.", operator));
		}

		let operatorMethod = operator . clause;

		let hiddenParam = this->_hiddenParamNumber,
			nextHiddenParam = hiddenParam + 1;

		/**
		 * Minimum key with auto bind-params and
		 * Maximum key with auto bind-params
		 */
		let minimumKey = "AP" . hiddenParam,
			maximumKey = "AP" . nextHiddenParam;

		/**
		 * Create a standard BETWEEN condition with bind params
		 * Append the BETWEEN to the current conditions using and "and"
		 */

		this->{operatorMethod}(
			expr . " BETWEEN :" . minimumKey . ": AND :" . maximumKey . ":",
			[minimumKey: minimum, maximumKey: maximum]
		);

		let nextHiddenParam++,
			this->_hiddenParamNumber = nextHiddenParam;

		return this;
	}

	/**
	 * Appends a NOT BETWEEN condition
	 */
	protected function _conditionNotBetween(string! clause, string! operator, string! expr, var minimum, var maximum) -> <Builder>
	{
		var hiddenParam, nextHiddenParam, minimumKey, maximumKey, operatorMethod;

		if (operator !== Builder::OPERATOR_AND && operator !== Builder::OPERATOR_OR) {
			throw new Exception(sprintf("Operator % is not available.", operator));
		}

		let operatorMethod = operator . clause;

		let hiddenParam = this->_hiddenParamNumber,
			nextHiddenParam = hiddenParam + 1;

		/**
		 * Minimum key with auto bind-params and
		 * Maximum key with auto bind-params
		 */
		let minimumKey = "AP" . hiddenParam,
			maximumKey = "AP" . nextHiddenParam;

		/**
		 * Create a standard BETWEEN condition with bind params
		 * Append the NOT BETWEEN to the current conditions using and "and"
		 */
		this->{operatorMethod}(
			expr . " NOT BETWEEN :" . minimumKey . ": AND :" . maximumKey . ":",
			[minimumKey: minimum, maximumKey: maximum]
		);

		let nextHiddenParam++,
			this->_hiddenParamNumber = nextHiddenParam;

		return this;
	}

	/**
	 * Appends an IN condition
	 */
	protected function _conditionIn(string! clause, string! operator, string! expr, array! values) -> <Builder>
	{
		var key, queryKey, value, bindKeys, bindParams, operatorMethod;
		int hiddenParam;

		if (operator !== Builder::OPERATOR_AND && operator !== Builder::OPERATOR_OR) {
			throw new Exception(sprintf("Operator % is not available.", operator));
		}

		let operatorMethod = operator . clause;

		if !count(values) {
			this->{operatorMethod}(expr . " != " . expr);
			return this;
		}

		let hiddenParam = (int) this->_hiddenParamNumber;

		let bindParams = [], bindKeys = [];
		for value in values {

			/**
			 * Key with auto bind-params
			 */
			let key = "AP" . hiddenParam,
				queryKey = ":" . key . ":",
				bindKeys[] = queryKey,
				bindParams[key] = value,
				hiddenParam++;
		}

		/**
		 * Create a standard IN condition with bind params
		 * Append the IN to the current conditions using and "and"
		 */
		this->{operatorMethod}(expr . " IN (" . join(", ", bindKeys) . ")", bindParams);

		let this->_hiddenParamNumber = hiddenParam;

		return this;
	}

	/**
	 * Appends a NOT IN condition
	 */
	protected function _conditionNotIn(string! clause, string! operator, string! expr, array! values) -> <Builder>
	{
		var key, queryKey, value, bindKeys, bindParams, operatorMethod;
		int hiddenParam;

		if (operator !== Builder::OPERATOR_AND && operator !== Builder::OPERATOR_OR) {
			throw new Exception(sprintf("Operator % is not available.", operator));
		}

		let operatorMethod = operator . clause;

		if !count(values) {
			this->{operatorMethod}(expr . " != " . expr);
			return this;
		}

		let hiddenParam = (int) this->_hiddenParamNumber;

		let bindParams = [], bindKeys = [];
		for value in values {

			/**
			 * Key with auto bind-params
			 */
			let key = "AP" . hiddenParam,
				queryKey = ":" . key . ":",
				bindKeys[] = queryKey,
				bindParams[key] = value,
				hiddenParam++;
		}

		/**
		 * Create a standard NOT IN condition with bind params
		 * Append the NOT IN to the current conditions using and "and"
		 */
		this->{operatorMethod}(expr . " NOT IN (" . join(", ", bindKeys) . ")", bindParams);

		let this->_hiddenParamNumber = hiddenParam;

		return this;
	}

}
