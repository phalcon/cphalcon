
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

namespace Phalcon\Mvc\Model\Query;

use Phalcon\Di;
use Phalcon\DiInterface;
use Phalcon\Mvc\Model\Query;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Query\BuilderInterface;
use Phalcon\Di\InjectionAwareInterface;

/**
 * Phalcon\Mvc\Model\Query\Builder
 *
 * Helps to create PHQL queries using an OO interface
 *
 *<code>
 * $params = array(
 *    'models'     => array('Users'),
 *    'columns'    => array('id', 'name', 'status'),
 *    'conditions' => array(
 *        array(
 *            "created > :min: AND created < :max:",
 *            array("min" => '2013-01-01',   'max' => '2014-01-01'),
 *            array("min" => PDO::PARAM_STR, 'max' => PDO::PARAM_STR),
 *        ),
 *    ),
 *    // or 'conditions' => "created > '2013-01-01' AND created < '2014-01-01'",
 *    'group'      => array('id', 'name'),
 *    'having'     => "name = 'Kamil'",
 *    'order'      => array('name', 'id'),
 *    'limit'      => 20,
 *    'offset'     => 20,
 *    // or 'limit' => array(20, 20),
 *);
 *$queryBuilder = new \Phalcon\Mvc\Model\Query\Builder($params);
 *</code>
 */
class Builder implements BuilderInterface, InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _columns;

	protected _models;

	protected _joins;

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
			singleCondition, singleParams, singleTypes, with;

		if typeof params == "array" {

			/**
			 * Process conditions
			 */
			if fetch conditions, params[0] {
				let this->_conditions = conditions;
			} else {
				if fetch conditions, params["conditions"] {
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
						let this->_bindParams = mergedParams;
						let this->_bindTypes  = mergedTypes;
					} else {
						let this->_conditions = conditions;
					}
				}
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
			 * Check if the resultset must be eager loaded
			 */
			if fetch with, params["with"] {
				let this->_with = with;
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
	 * @param bool|null distinct
	 * @return Phalcon\Mvc\Model\Query\BuilderInterface
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
	 *	$builder->columns(array('id', 'name'));
	 *</code>
	 *
	 * @param string|array columns
	 * @return Phalcon\Mvc\Model\Query\Builder
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
	 *	$builder->from('Robots');
	 *	$builder->from(array('Robots', 'RobotsParts'));
	 *</code>
	 *
	 * @param string|array models
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function from(var models) -> <Builder>
	{
		let this->_models = models;
		return this;
	}

	/**
	 * Add a model to take part of the query
	 *
	 *<code>
	 *	$builder->addFrom('Robots', 'r');
	 *</code>
	 *
	 * @param string model
	 * @param string alias
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function addFrom(var model, var alias = null) -> <Builder>
	{
		var models, currentModel;

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
	 * Adds a INNER join to the query
	 *
	 *<code>
	 *	$builder->join('Robots');
	 *	$builder->join('Robots', 'r.id = RobotsParts.robots_id');
	 *	$builder->join('Robots', 'r.id = RobotsParts.robots_id', 'r');
	 *	$builder->join('Robots', 'r.id = RobotsParts.robots_id', 'r', 'INNER');
	 *</code>
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @param string type
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function join(string! model, var conditions = null, var alias = null, var type = null) -> <Builder>
	{
		let this->_joins[] = [model, conditions, alias, type];
		return this;
	}

	/**
	 * Adds a INNER join to the query
	 *
	 *<code>
	 *	$builder->innerJoin('Robots');
	 *	$builder->innerJoin('Robots', 'r.id = RobotsParts.robots_id');
	 *	$builder->innerJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
	 *</code>
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @param string type
	 * @return Phalcon\Mvc\Model\Query\Builder
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
	 *	$builder->leftJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
	 *</code>
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @return Phalcon\Mvc\Model\Query\Builder
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
	 *	$builder->rightJoin('Robots', 'r.id = RobotsParts.robots_id', 'r');
	 *</code>
	 *
	 * @param string model
	 * @param string conditions
	 * @param string alias
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function rightJoin(string! model, var conditions = null, var alias = null) -> <Builder>
	{
		let this->_joins[] = [model, conditions, alias, "RIGHT"];
		return this;
	}

	/**
	 * Sets the query conditions
	 *
	 *<code>
	 *	$builder->where(100);
	 *	$builder->where('name = "Peter"');
	 *	$builder->where('name = :name: AND id > :id:', array('name' => 'Peter', 'id' => 100));
	 *</code>
	 *
	 * @param mixed conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function where(var conditions, var bindParams = null, var bindTypes = null) -> <Builder>
	{
		var currentBindParams, currentBindTypes, mergedParams, mergedTypes;

		let this->_conditions = conditions;

		/**
		 * Merge the bind params to the current ones
		 */
		if typeof bindParams == "array" {
			let currentBindParams = this->_bindParams;
			if typeof currentBindParams == "array" {
				let mergedParams = currentBindParams + bindParams;
			} else {
				let mergedParams = bindParams;
			}
			let this->_bindParams = mergedParams;
		}

		/**
		 * Merge the bind types to the current ones
		 */
		if typeof bindTypes == "array" {
			let currentBindTypes = this->_bindTypes;
			if typeof currentBindParams == "array" {
				let mergedTypes = currentBindTypes + bindTypes;
			} else {
				let mergedTypes = bindTypes;
			}
			let this->_bindTypes = mergedTypes;
		}

		return this;
	}

	/**
	 * Appends a condition to the current conditions using a AND operator
	 *
	 *<code>
	 *	$builder->andWhere('name = "Peter"');
	 *	$builder->andWhere('name = :name: AND id > :id:', array('name' => 'Peter', 'id' => 100));
	 *</code>
	 *
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function andWhere(string! conditions, var bindParams = null, var bindTypes = null) -> <Builder>
	{
		var currentBindParams, currentBindTypes, mergedParams,
			mergedTypes, currentConditions, newConditions;

		let currentConditions = this->_conditions;

		/**
		 * Nest the condition to current ones or set as unique
		 */
		if currentConditions {
			let newConditions = "(" . currentConditions . ") AND (" . conditions . ")";
		} else {
			let newConditions = conditions;
		}
		let this->_conditions = newConditions;

		/**
		 * Merge the bind params to the current ones
		 */
		if typeof bindParams == "array" {
			let currentBindParams = this->_bindParams;
			if typeof currentBindParams == "array" {
				let mergedParams = currentBindParams + bindParams;
			} else {
				let mergedParams = bindParams;
			}
			let this->_bindParams = mergedParams;
		}

		/**
		 * Merge the bind types to the current ones
		 */
		if typeof bindTypes == "array" {
			let currentBindTypes = this->_bindTypes;
			if typeof currentBindParams == "array" {
				let mergedTypes = currentBindTypes + bindTypes;
			} else {
				let mergedTypes = bindTypes;
			}
			let this->_bindTypes = mergedTypes;
		}

		return this;
	}

	/**
	 * Appends a condition to the current conditions using a OR operator
	 *
	 *<code>
	 *	$builder->orWhere('name = "Peter"');
	 *	$builder->orWhere('name = :name: AND id > :id:', array('name' => 'Peter', 'id' => 100));
	 *</code>
	 *
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function orWhere(string! conditions, var bindParams = null, var bindTypes = null) -> <Builder>
	{
		var currentBindParams, currentBindTypes, mergedParams,
			mergedTypes, currentConditions;

		/**
		 * Nest the condition to current ones or set as unique
		 */
		let currentConditions = this->_conditions;
		if currentConditions {
			let this->_conditions = "(" . currentConditions . ") OR (" . conditions . ")";
		} else {
			let this->_conditions = conditions;
		}

		/**
		 * Merge the bind params to the current ones
		 */
		if typeof bindParams == "array" {
			let currentBindParams = this->_bindParams;
			if typeof currentBindParams == "array" {
				let mergedParams = currentBindParams + bindParams;
			} else {
				let mergedParams = bindParams;
			}
			let this->_bindParams = mergedParams;
		}

		/**
		 * Merge the bind types to the current ones
		 */
		if typeof bindTypes == "array" {
			let currentBindTypes = this->_bindTypes;
			if typeof currentBindParams == "array" {
				let mergedTypes = currentBindTypes + bindTypes;
			} else {
				let mergedTypes = bindTypes;
			}
			let this->_bindTypes = mergedTypes;
		}

		return this;
	}

	/**
	 * Appends a BETWEEN condition to the current conditions
	 *
	 *<code>
	 *	$builder->betweenWhere('price', 100.25, 200.50);
	 *</code>
	 *
	 * @param string expr
	 * @param mixed minimum
	 * @param mixed maximum
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function betweenWhere(string! expr, var minimum, var maximum) -> <Builder>
	{
		var hiddenParam, nextHiddenParam, minimumKey, maximumKey;

		let hiddenParam = this->_hiddenParamNumber,
			nextHiddenParam = hiddenParam + 1;

		/**
		 * Minimum key with auto bind-params and
		 * Maximum key with auto bind-params
		 */
		let minimumKey = "phb" . hiddenParam,
			maximumKey = "phb" . nextHiddenParam;

		/**
		 * Create a standard BETWEEN condition with bind params
		 * Append the BETWEEN to the current conditions using and "and"
		 */
		this->andWhere(
			expr . " BETWEEN :" . minimumKey . ": AND :" . maximumKey . ":",
			[minimumKey: minimum, maximumKey: maximum]
		);

		let nextHiddenParam++,
			this->_hiddenParamNumber = nextHiddenParam;

		return this;
	}

	/**
	 * Appends a NOT BETWEEN condition to the current conditions
	 *
	 *<code>
	 *	$builder->notBetweenWhere('price', 100.25, 200.50);
	 *</code>
	 *
	 * @param string expr
	 * @param mixed minimum
	 * @param mixed maximum
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function notBetweenWhere(string! expr, var minimum, var maximum) -> <Builder>
	{
		var hiddenParam, nextHiddenParam, minimumKey, maximumKey;

		let hiddenParam = this->_hiddenParamNumber,
			nextHiddenParam = hiddenParam + 1;

		/**
		 * Minimum key with auto bind-params and
		 * Maximum key with auto bind-params
		 */
		let minimumKey = "phb" . hiddenParam,
			maximumKey = "phb" . nextHiddenParam;

		/**
		 * Create a standard BETWEEN condition with bind params
		 * Append the NOT BETWEEN to the current conditions using and "and"
		 */
		this->andWhere(
			expr . " NOT BETWEEN :" . minimumKey . ": AND :" . maximumKey . ":",
			[minimumKey: minimum, maximumKey: maximum]
		);

		let nextHiddenParam++,
			this->_hiddenParamNumber = nextHiddenParam;

		return this;
	}

	/**
	 * Appends an IN condition to the current conditions
	 *
	 *<code>
	 *	$builder->inWhere('id', [1, 2, 3]);
	 *</code>
	 */
	public function inWhere(string! expr, array! values) -> <Builder>
	{
		var key, queryKey, value, bindKeys, bindParams;
		int hiddenParam;

		let hiddenParam = (int) this->_hiddenParamNumber;

		let bindParams = [], bindKeys = [];
		for value in values {

			/**
			 * Key with auto bind-params
			 */
			let key = "phi" . hiddenParam,
				queryKey = ":" . key . ":",
				bindKeys[] = queryKey,
				bindParams[key] = value,
				hiddenParam++;
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
	 *	$builder->notInWhere('id', [1, 2, 3]);
	 *</code>
	 */
	public function notInWhere(string! expr, array! values) -> <Builder>
	{
		var key, queryKey, value, bindKeys, bindParams;
		int hiddenParam;

		let hiddenParam = (int) this->_hiddenParamNumber;

		let bindParams = [], bindKeys = [];
		for value in values {

			/**
			 * Key with auto bind-params
			 */
			let key = "phi" . hiddenParam,
				queryKey = ":" . key . ":",
				bindKeys[] = queryKey,
				bindParams[key] = value,
				hiddenParam++;
		}

		/**
		 * Create a standard NOT IN condition with bind params
		 * Append the NOT IN to the current conditions using and "and"
		 */
		this->andWhere(expr . " NOT IN (" . join(", ", bindKeys) . ")", bindParams);

		let this->_hiddenParamNumber = hiddenParam;

		return this;
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
	 * Sets a ORDER BY condition clause
	 *
	 *<code>
	 *	$builder->orderBy('Robots.name');
	 *	$builder->orderBy(array('1', 'Robots.name'));
	 *</code>
	 *
	 * @param string|array orderBy
	 * @return Phalcon\Mvc\Model\Query\Builder
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
	 * Sets a HAVING condition clause. You need to escape PHQL reserved words using [ and ] delimiters
	 *
	 *<code>
	 *	$builder->having('SUM(Robots.price) > 0');
	 *</code>
	 */
	public function having(string! having) -> <Builder>
	{
		let this->_having = having;
		return this;
	}

	/**
	 * Return the current having clause
	 *
	 * @return string|array
	 */
	public function getHaving()
	{
		return this->_having;
	}

	/**
	 * Sets a LIMIT clause, optionally a offset clause
	 *
	 *<code>
	 *	$builder->limit(100);
	 *	$builder->limit(100, 20);
	 *</code>
	 */
	public function limit(int limit = null, int offset = null) -> <Builder>
	{
		let this->_limit = limit;
		if offset {
			let this->_offset = offset;
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
	 *	$builder->offset(30);
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
	 *	$builder->groupBy(array('Robots.name'));
	 *</code>
	 *
	 * @param string|array group
	 * @return Phalcon\Mvc\Model\Query\Builder
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
			limit, number, offset, distinct, withModels;
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
				modelInstance = new {model}(dependencyInjector);

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

					let conditions = "[" . model . "].[" . attributeField . "] = " . conditions,
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
						let selectedColumns[] = column . " AS " . columnAlias;
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
						let selectedColumn = "[" . model . "].*";
					} else {
						let selectedColumn = "[" . modelColumnAlias . "].*";
					}
					let selectedColumns[] = selectedColumn;
				}

				let phql .= join(", ", selectedColumns);
			} else {
				let phql .= "[" . models . "].*";
			}
		}

		let withModels = this->_with;
		if typeof withModels == "array" {

			let selectedColumns = [];
			for model in withModels {
				let selectedColumns[] = "[" . model . "].*";
			}

			let phql .= ", " . join(", ", selectedColumns);
		}

		/**
		 * Join multiple models or use a single one if it is a string
		 */
		if typeof models == "array" {

			let selectedModels = [];
			for modelAlias, model in models {

				if typeof modelAlias == "string" {
					if memstr(model, "[") {
						let selectedModel = model . " AS [" . modelAlias . "]";
					} else {
						let selectedModel = "[" . model . "] AS [" . modelAlias . "]";
					}
				} else {
					if memstr(model, "[") {
						let selectedModel = model;
					} else {
						let selectedModel = "[" . model . "]";
					}
				}

				let selectedModels[] = selectedModel;
			}

			let phql .= " FROM " . join(", ", selectedModels);

		} else {

			if memstr(models, "[") {
				let phql .= " FROM " . models . "";
			} else {
				let phql .= " FROM [" . models . "]";
			}
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
					if memstr(joinModel, "[") {
						let phql .= " " . joinType . " JOIN " . joinModel;
					} else {
						let phql .= " " . joinType . " JOIN [" . joinModel . "]";
					}
				} else {
					if memstr(joinModel, "[") {
						let phql .= " JOIN " . joinModel . "";
					} else {
						let phql .= " JOIN [" . joinModel . "]";
					}
				}

				/**
				 * Alias comes first
				 */
				if joinAlias {
					let phql .= " AS [" . joinAlias . "]";
				}

				/**
				 * Conditions then
				 */
				if joinConditions {
					let phql .= " ON " . joinConditions;
				}
			}
		}

		/**
		 * Only append conditions if it"s string
		 */
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
			if typeof group == "array" {
				let groupItems = [];
				for groupItem in group {
					if is_numeric(groupItem) {
						let groupItems[] = groupItem;
					} else {
						if memstr(groupItem, ".") {
							let groupItems[] = groupItem;
						} else {
							let groupItems[] = "[" . groupItem . "]";
						}
					}
				}
				let phql .= " GROUP BY " . join(", ", groupItems);
			} else {
				if is_numeric(group) {
					let phql .= " GROUP BY ".group;
				} else {
					if memstr(group, ".") {
						let phql .= " GROUP BY ".group;
					} else {
						if memstr(group, ",") {
							let group = str_replace(" ", "", group);
							let groupItems = explode(",", group);
							let phql .= " GROUP BY [" . join("], [", groupItems) . "]";
						} else {
							let phql .= " GROUP BY [" . group . "]";
						}
					}
				}
			}
		}

		let having = this->_having;
		if having !== null {
			if !empty having {
				let phql .= " HAVING ".having;
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
					if is_numeric(orderItem) {
						let orderItems[] = orderItem;
					} else {
						if memstr(orderItem, ".") {
							let orderItems[] = orderItem;
						} else {
							let orderItems[] = "[" . orderItem . "]";
						}
					}
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
			if typeof limit == "array" {
				let number = limit["number"];
				if fetch offset, limit["offset"] {
					if is_numeric(offset) {
						let phql .= " LIMIT " . number . " OFFSET " . offset;
					} else {
						let phql .= " LIMIT " . number . " OFFSET 0";
					}
				} else {
					let phql .= " LIMIT " . number;
				}
			} else {
				if is_numeric(limit) {
					let phql .= " LIMIT " . limit,
						offset = this->_offset;
					if offset !== null {
						if is_numeric(offset) {
							let phql .= " OFFSET " . offset;
						} else {
							let phql .= " OFFSET 0";
						}
					}
				}
			}
		}

		return phql;
	}

	/**
	 * Returns the query built
	 */
	public function getQuery() -> <Query>
	{
		var query, bindParams, bindTypes;

		let query = new Query(this->getPhql(), this->_dependencyInjector);

		/**
		 * Set default bind params
		 */
		let bindParams = this->_bindParams;
		if typeof bindParams == "array" {
			query->setBindParams(bindParams);
		}

		/**
		 * Set default bind params
		 */
		let bindTypes = this->_bindTypes;
		if typeof bindTypes == "array" {
			query->setBindTypes(bindTypes);
		}

		return query;
	}
}
