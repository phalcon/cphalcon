
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
 |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model;

/**
 * Phalcon\Mvc\Model\Query
 *
 * This class takes a PHQL intermediate representation and executes it.
 *
 *<code>
 *
 * $phql = "SELECT c.price*0.16 AS taxes, c.* FROM Cars AS c JOIN Brands AS b
 *          WHERE b.name = :name: ORDER BY c.name";
 *
 * $result = manager->executeQuery($phql, array(
 *   "name": "Lamborghini"
 * ));
 *
 * foreach ($result as $row) {
 *   echo "Name: ", $row->cars->name, "\n";
 *   echo "Price: ", $row->cars->price, "\n";
 *   echo "Taxes: ", $row->taxes, "\n";
 * }
 *
 *</code>
 */
class Query //implements Phalcon\Mvc\Model\QueryInterface, Phalcon\Di\InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _manager;

	protected _metaData;

	protected _type;

	protected _phql;

	protected _ast;

	protected _intermediate;

	protected _models;

	protected _sqlAliases;

	protected _sqlAliasesModels;

	protected _sqlModelsAliases;

	protected _sqlAliasesModelsInstances;

	protected _sqlColumnAliases;

	protected _modelsInstances;

	protected _cache;

	protected _cacheOptions;

	protected _uniqueRow;

	protected _bindParams;

	protected _bindTypes;

	static protected _irPhqlCache;

	const TYPE_SELECT = 309;

	const TYPE_INSERT = 306;

	const TYPE_UPDATE = 300;

	const TYPE_DELETE = 303;

	/**
	 * Sets the dependency injection container
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<Phalcon\DiInterface> dependencyInjector)
	{
		var manager, metaData;

		let manager = dependencyInjector->getShared("modelsManager");
		if typeof manager != "object" {
			throw new Phalcon\Mvc\Model\Exception("Injected service 'modelsManager' is invalid");
		}

		let metaData = dependencyInjector->getShared("modelsMetadata");
		if typeof metaData != "object" {
			throw new Phalcon\Mvc\Model\Exception("Injected service 'modelsMetaData' is invalid");
		}

		let this->_manager = manager,
			this->_metaData = metaData;

		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the dependency injection container
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <Phalcon\DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Tells to the query if only the first row in the resultset must be returned
	 *
	 * @param boolean uniqueRow
	 * @return Phalcon\Mvc\Model\Query
	 */
	public function setUniqueRow(boolean uniqueRow) -> <Phalcon\Mvc\Model\Query>
	{
		let this->_uniqueRow = uniqueRow;
		return this;
	}

	/**
	 * Check if the query is programmed to get only the first row in the resultset
	 *
	 * @return boolean
	 */
	public function getUniqueRow() -> boolean
	{
		return this->_uniqueRow;
	}

	/**
	 * Replaces the model's name to its source name in a qualifed-name expression
	 *
	 * @param array expr
	 * @return string
	 */
	protected function _getQualified(expr)
	{
		var columnName, sqlColumnAliases, metaData, sqlAliases,
			source, sqlAliasesModelsInstances, realColumnName, columnDomain,
			model, models, columnMap, hasModel;
		int number;

		let columnName = expr["name"];

		/**
		 * Check if the qualified name is a column alias
		 */
		let sqlColumnAliases = this->_sqlColumnAliases;
		if isset sqlColumnAliases[columnName] {
			return [
				"type": "qualified",
				"name": columnName
			];
		}

		let metaData = this->_metaData;

		/**
		 * Check if the qualified name has a domain
		 */
		if isset expr["domain"] {

			let sqlAliases = this->_sqlAliases;

			/**
			 * The column has a domain, we need to check if it"s an alias
			 */
			let columnDomain = expr["domain"];
			if !fetch source, sqlAliases[columnDomain] {
				throw new Phalcon\Mvc\Model\Exception("Unknown model or alias '" . columnDomain . "' (1), when preparing: " . this->_phql);
			}

			/**
			 * Change the selected column by its real name on its mapped table
			 */
			if globals_get("orm.column_renaming") {

				/**
				 * Retrieve the corresponding model by its alias
				 */
				let sqlAliasesModelsInstances = this->_sqlAliasesModelsInstances;

				/**
				 * We need to model instance to retrieve the reversed column map
				 */
				if !fetch model, sqlAliasesModelsInstances[columnDomain] {
					throw new Phalcon\Mvc\Model\Exception("There is no model related to model or alias '" . columnDomain . "', when executing: " . this->_phql);
				}

				let columnMap = metaData->getReverseColumnMap(model);
			} else {
				let columnMap = null;
			}

			if typeof columnMap == "array" {
				if !fetch realColumnName, columnMap[columnName] {
					throw new Phalcon\Mvc\Model\Exception("Column '" . columnName . "' doesn't belong to the model or alias '" . columnDomain . "', when executing: ". this->_phql);
				}
			} else {
				let realColumnName = columnName;
			}

		} else {

			/**
			 * If the column IR doesn't have a domain, we must check for ambiguities
			 */
			let number = 0, hasModel = false;
			for model in this->_modelsInstances {

				/**
				 * Check if the atribute belongs to the current model
				 */
				if metaData->hasAttribute(model, columnName) {
					let number++;
					if number > 1 {
						throw new Phalcon\Mvc\Model\Exception("The column '" . columnName . "' is ambiguous, when preparing: " . this->_phql);
					}
					let hasModel = model;
				}
			}

			/**
			 * After check in every model, the column does not belong to any of the selected models
			 */
			if hasModel === false {
				throw new Phalcon\Mvc\Model\Exception("Column '" . columnName . "' doesn't belong to any of the selected models (1), when preparing: " . this->_phql);
			}

			/**
			 * Check if the _models property is correctly prepared
			 */
			let models = this->_models;
			if typeof models != "array" {
				throw new Phalcon\Mvc\Model\Exception("The models list was not loaded correctly");
			}

			/**
			 * Obtain the model's source from the _models list
			 */
			if !fetch source, models[get_class(hasModel)] {
				throw new Phalcon\Mvc\Model\Exception("Column '" . columnName . "' doesn't belong to any of the selected models (2), when preparing: " . this->_phql);
			}

			/**
			 * Rename the column
			 */
			if globals_get("orm.column_renaming") {
				let columnMap = metaData->getReverseColumnMap(hasModel);
			} else {
				let columnMap = null;
			}

			if typeof columnMap == "array" {
				/**
				 * The real column name is in the column map
				 */
				if !fetch realColumnName, columnMap[columnName] {
					throw new Phalcon\Mvc\Model\Exception("Column '" . columnName . "' doesn't belong to any of the selected models (3), when preparing: " . this->_phql);
				}
			} else {
				let realColumnName = columnName;
			}

		}

		/**
		 * Create an array with the qualified info
		 */
		return [
			"type"  : "qualified",
			"domain": source,
			"name"  : realColumnName,
			"balias": columnName
		];
	}

	/**
	 * Resolves a expression in a single call argument
	 *
	 * @param array argument
	 * @return string
	 */
	protected function _getCallArgument(argument)
	{
		if argument["type"] == PHQL_T_ALL {
			return ["type": "all"];
		}
		return this->_getExpression(argument);
	}

	/**
	 * Resolves a expression in a single call argument
	 *
	 * @param array expr
	 * @return array
	 */
	protected function _getFunctionCall(expr)
	{
		var arguments, argument, functionArgs;

		if fetch arguments, expr["arguments"] {
			if isset arguments[0] {
				/**
				 * There are more than one argument
				 */
				let functionArgs = [];
				for argument in arguments {
					let functionArgs[] = this->_getCallArgument(argument);
				}
			} else {
				/**
				 * There is only one argument
				 */
				let functionArgs = [this->_getCallArgument(arguments)];
			}
			return [
				"type"     : "functionCall",
				"name"     : expr["name"],
				"arguments": functionArgs
			];
		}

		return [
			"type": "functionCall",
			"name": expr["name"]
		];
	}

	/**
	 * Resolves an expression from its intermediate code into a string
	 *
	 * @param array expr
	 * @param boolean quoting
	 * @return string
	 */
	protected function _getExpression(expr, boolean quoting=true) -> string
	{
		var exprType, exprLeft, exprRight, left, right, listItems, exprListItem,
			exprReturn, tempNotQuoting, value, escapedValue, exprValue;

		if fetch exprType, expr["type"] {

			let tempNotQuoting = true;

			/**
			 * Resolving the left part of the expression if any
			 */
			if fetch exprLeft, expr["left"] {
				let left = this->_getExpression(exprLeft, tempNotQuoting);
			}

			/**
			 * Resolving the right part of the expression if any
			 */
			if fetch exprRight, expr["right"] {
				let right = this->_getExpression(exprRight, tempNotQuoting);
			}

			/**
			 * Every node in the AST has a unique integer type
			 */
			switch exprType {
				case PHQL_T_LESS:
					let exprReturn = ["type": "binary-op", "op": "<", "left": left, "right": right];
					break;
				case PHQL_T_EQUALS:
					let exprReturn = ["type": "binary-op", "op": "=", "left": left, "right": right];
					break;
				case PHQL_T_GREATER:
					let exprReturn = ["type": "binary-op", "op": ">", "left": left, "right": right];
					break;
				case 270:
					let exprReturn = ["type": "binary-op", "op": "<>", "left": left, "right": right];
					break;
				case 271:
					let exprReturn = ["type": "binary-op", "op": "<=", "left": left, "right": right];
					break;
				case 272:
					let exprReturn = ["type": "binary-op", "op": ">=", "left": left, "right": right];
					break;
				case PHQL_T_AND:
					let exprReturn = ["type": "binary-op", "op": "AND", "left": left, "right": right];
					break;
				case PHQL_T_OR:
					let exprReturn = ["type": "binary-op", "op": "OR", "left": left, "right": right];
					break;
				case 355:
					let exprReturn = this->_getQualified(expr);
					break;
				case 359:
					//let exprReturn = this->_getAliased(expr);
					break;
				case PHQL_T_ADD:
					let exprReturn = ["type": "binary-op", "op": "+", "left": left, "right": right];
					break;
				case PHQL_T_SUB:
					let exprReturn = ["type": "binary-op", "op": "-", "left": left, "right": right];
					break;
				case PHQL_T_MUL:
					let exprReturn = ["type": "binary-op", "op": "*", "left": left, "right": right];
					break;
				case PHQL_T_DIV:
					let exprReturn = ["type": "binary-op", "op": "/", "left": left, "right": right];
					break;
				case PHQL_T_MOD:
					let exprReturn = ["type": "binary-op", "op": "%", "left": left, "right": right];
					break;
				case 38:
					let exprReturn = ["type": "binary-op", "op": "&", "left": left, "right": right];
					break;
				case 124:
					let exprReturn = ["type": "binary-op", "op": "|", "left": left, "right": right];
					break;
				case PHQL_T_ENCLOSED:
					let exprReturn = ["type": "parentheses", "left": left];
					break;
				case PHQL_T_MINUS:
					let exprReturn = ["type": "unary-op", "op": "-", "right": right];
					break;
				case PHQL_T_INTEGER:
				case PHQL_T_DOUBLE:
					let exprReturn = ["type": "literal", "value": expr["value"]];
					break;
				case PHQL_T_TRUE:
					let exprReturn = ["type": "literal", "value": "TRUE"];
					break;
				case PHQL_T_FALSE:
					let exprReturn = ["type": "literal", "value": "FALSE"];
					break;
				case PHQL_T_STRING:
					let value = expr["value"];
					if quoting === true {
						/**
						 * Check if static literals have single quotes and escape them
						 */
						if memstr(value, "'") {
							let escapedValue = phalcon_orm_singlequotes(value);
						} else {
							let escapedValue = value;
						}
						let exprValue = "'" . escapedValue . "'";
					} else {
						let exprValue = value;
					}
					let exprReturn = ["type": "literal", "value": exprValue];
					break;
				case PHQL_T_NPLACEHOLDER:
					let exprReturn = ["type": "placeholder", "value": str_replace("?", ":", expr["value"])];
					break;
				case PHQL_T_SPLACEHOLDER:
					let exprReturn = ["type": "placeholder", "value": ":" . expr["value"]];
					break;
				case PHQL_T_NULL:
					let exprReturn = ["type": "literal", "value": "NULL"];
					break;
				case PHQL_T_LIKE:
					let exprReturn = ["type": "binary-op", "op": "LIKE", "left": left, "right": right];
					break;
				case PHQL_T_NLIKE:
					let exprReturn = ["type": "binary-op", "op": "NOT LIKE", "left": left, "right": right];
					break;
				case PHQL_T_ILIKE:
					let exprReturn = ["type": "binary-op", "op": "ILIKE", "left": left, "right": right];
					break;
				case PHQL_T_NILIKE:
					let exprReturn = ["type": "binary-op", "op": "NOT ILIKE", "left": left, "right": right];
					break;
				case PHQL_T_NOT:
					let exprReturn = ["type": "unary-op", "op": "NOT ", "right": right];
					break;
				case 365:
					let exprReturn = ["type": "unary-op", "op": " IS NULL", "left": left];
					break;
				case PHQL_T_ISNOTNULL:
					let exprReturn = ["type": "unary-op", "op": " IS NOT NULL", "left": left];
					break;
				case PHQL_T_IN:
					let exprReturn = ["type": "binary-op", "op": "IN", "left": left, "right": right];
					break;
				case PHQL_T_NOTIN:
					let exprReturn = ["type": "binary-op", "op": "NOT IN", "left": left, "right": right];
					break;
				case PHQL_T_DISTINCT:
					let exprReturn = ["type": "unary-op", "op": "DISTINCT ", "right": right];
					break;
				case PHQL_T_BETWEEN:
					let exprReturn = ["type": "binary-op", "op": "BETWEEN", "left": left, "right": right];
					break;
				case PHQL_T_AGAINST:
					let exprReturn = ["type": "binary-op", "op": "AGAINST", "left": left, "right": right];
					break;
				case PHQL_T_CAST:
					let exprReturn = ["type": "cast", "left": left, "right": right];
					break;
				case PHQL_T_CONVERT:
					let exprReturn = ["type": "convert", "left": left, "right": right];
					break;
				case PHQL_T_RAW_QUALIFIED:
					let exprReturn = ["type": "literal", "value": expr["name"]];
					break;
				case PHQL_T_FCALL:
					let exprReturn = this->_getFunctionCall(expr);
					break;
				default:
					throw new Phalcon\Mvc\Model\Exception("Unknown expression type " . exprType);
			}

			return exprReturn;
		}

		/**
		 * It's a qualified column
		 */
		if isset expr["domain"] {
			return this->_getQualified(expr);
		}

		/**
		 * If the expression doesn't have a type it's a list of nodes
		 */
		if isset expr[0] {
			let listItems = [];
			for exprListItem in expr {
				let listItems[] = this->_getExpression(exprListItem);
			}
			return ["type": "list", listItems];
		}

		throw new Phalcon\Mvc\Model\Exception("Unknown expression");
	}

	/**
	 * Resolves a column from its intermediate representation into an array used to determine
	 * if the resulset produced is simple or complex
	 *
	 * @param array column
	 * @return array
	 */
	protected function _getSelectColumn(column)
	{
		var sqlColumns, columnType, sqlAliases, modelName, source,
			columnDomain, sqlColumnAlias, bestAlias, preparedAlias, sqlExprColumn,
			sqlAliasesModels, sqlModelsAliases, sqlColumn, columnData, balias;

		if !fetch columnType, column["type"] {
			throw new Phalcon\Mvc\Model\Exception("Corrupted SELECT AST");
		}

		let sqlColumns = [];

		/**
		 * Check for select * (all)
		 */
		if columnType == PHQL_T_ALL {
			for modelName, source in this->_models {
				let sqlColumns[] = [
					"type"  : "object",
					"model" : modelName,
					"column": source
				];
			}
			return sqlColumns;
		}

		if !isset column["column"] {
			throw new Phalcon\Mvc\Model\Exception("Corrupted SELECT AST");
		}

		/**
		 * Check if selected column is qualified.*
		 */
		if columnType == PHQL_T_DOMAINALL {

			let sqlAliases = this->_sqlAliases;

			/**
			 * We only allow the alias.*
			 */
			let columnDomain = column["column"];

			if !fetch source, sqlAliases[columnDomain] {
				throw new Phalcon\Mvc\Model\Exception("Unknown model or alias '" . columnDomain . "' (2), when preparing: " . this->_phql);
			}

			/**
			 * Get the SQL alias if any
			 */
			let sqlColumnAlias = source;

			/**
			 * Get the real source name
			 */
			let sqlAliasesModels = this->_sqlAliasesModels,
				modelName = sqlAliasesModels[columnDomain];

			/**
			 * Get the best alias for the column
			 */
			let sqlModelsAliases = this->_sqlModelsAliases,
				bestAlias = sqlModelsAliases[modelName];

			/**
			 * If the best alias is the model name we lowercase the first letter
			 */
			if bestAlias == modelName {
				let preparedAlias = lcfirst(modelName);
			} else {
				let preparedAlias = bestAlias;
			}

			/**
			 * Each item is a complex type returning a complete object
			 */
			let sqlColumns[] = [
				"type":  "object",
				"model":  modelName,
				"column": sqlColumnAlias,
				"balias": preparedAlias
			];

			return sqlColumns;
		}

		/**
		 * Check for columns qualified and not qualified
		 */
		if columnType == PHQL_T_EXPR {

			/**
			 * The sql_column is a scalar type returning a simple string
			 */
			let sqlColumn = ["type": "scalar"],
				columnData = column["column"],
				sqlExprColumn = this->_getExpression(columnData);

			/**
			 * Create balias and sqlAlias
			 */
			if fetch balias, sqlExprColumn["balias"] {
				let sqlColumn["balias"] = balias,
					sqlColumn["sqlAlias"] = balias;
			}

			let sqlColumn["column"] = sqlExprColumn,
				sqlColumns[] = sqlColumn;

			return sqlColumns;
		}

		throw new Phalcon\Mvc\Model\Exception("Unknown type of column " . columnType);
	}

	/**
	 * Resolves a table in a SELECT statement checking if the model exists
	 *
	 * @param Phalcon\Mvc\Model\ManagerInterface manager
	 * @param array qualifiedName
	 * @return string
	 */
	protected function _getTable(<Phalcon\Mvc\Model\ManagerInterface> manager, qualifiedName)
	{
		var modelName, model, source, schema;

		if fetch modelName, qualifiedName["name"] {

			let model = manager->load(modelName),
				source = model->getSource(),
				schema = model->getSchema();

			if schema {
				return [schema, source];
			}

			return source;
		}

		throw new Phalcon\Mvc\Model\Exception("Corrupted SELECT AST");
	}

	/**
	 * Resolves a JOIN clause checking if the associated models exist
	 *
	 * @param Phalcon\Mvc\Model\ManagerInterface manager
	 * @param array join
	 * @return array
	 */
	protected function _getJoin(<Phalcon\Mvc\Model\ManagerInterface> manager, join)
	{

		var qualified, modelName, source, model, schema;

		if fetch qualified, join["qualified"] {

			if qualified["type"] == 355 {

				let modelName = qualified["name"],
					model = manager->load(modelName),
					source = model->getSource(),
					schema = model->getSchema();

				return [
					"schema"   : schema,
					"source"   : source,
					"modelName": modelName,
					"model"    : model
				];
			}
		}

		throw new Phalcon\Mvc\Model\Exception("Corrupted SELECT AST");
	}

	/**
	 * Resolves a JOIN type
	 *
	 * @param array join
	 * @return string
	 */
	protected function _getJoinType(join) -> string
	{
		var type;

		if !fetch type, join["type"] {
			throw new Phalcon\Mvc\Model\Exception("Corrupted SELECT AST");
		}

		switch type {
			case PHQL_T_INNERJOIN:
				return "INNER";
			case PHQL_T_LEFTJOIN:
				return "LEFT";
			case PHQL_T_RIGHTJOIN:
				return "RIGHT";
			case PHQL_T_CROSSJOIN:
				return "CROSS";
			case PHQL_T_FULLJOIN:
				return "FULL OUTER";
		}

		throw new Phalcon\Mvc\Model\Exception("Unknown join type " . type . ", when preparing: " . this->_phql);
	}

	/**
	 * Resolves joins involving has-one/belongs-to/has-many relations
	 *
	 * @param string joinType
	 * @param string joinSource
	 * @param string modelAlias
	 * @param string joinAlias
	 * @param Phalcon\Mvc\Model\RelationInterface relation
	 * @return array
	 */
	protected function _getSingleJoin(string! joinType, joinSource, modelAlias, joinAlias,
		<Phalcon\Mvc\Model\RelationInterface> relation)
	{
		var fields, referencedFields, sqlJoinConditions,
			sqlJoinPartialConditions, position, field, referencedField;

		/**
		 * Local fields in the 'from' relation
		 */
		let fields = relation->getFields();

		/**
		 * Referenced fields in the joined relation
		 */
		let referencedFields = relation->getReferencedFields();

		if typeof fields != "array" {

			/**
			 * Create the left part of the expression
			 * Create a binary operation for the join conditions
			 * Create the right part of the expression
			 */
			let sqlJoinConditions = [
				"type"     : "binary-op",
				"op"       : "=",
				"left"     : this->_getQualified([
					"type"   : 355,
					"domain" : modelAlias,
					"name"   : fields
				]),
				"right"    : this->_getQualified([
					"type"   : "qualified",
					"domain" : joinAlias,
					"name"   : referencedFields
				])
			];

		} else {

			/**
			 * Resolve the compound operation
			 */
			let sqlJoinPartialConditions = [];
			for position, field in fields {

				/**
				 * Get the referenced field in the same position
				 */
				if !fetch referencedField, referencedFields[position] {
					throw new Phalcon\Mvc\Model\Exception("The number of fields must be equal to the number of referenced fields in join " . modelAlias . "-" . joinAlias . ", when preparing: " . this->_phql);
				}

				/**
				 * Create the left part of the expression
				 * Create the right part of the expression
				 * Create a binary operation for the join conditions
				 */
				let sqlJoinPartialConditions[] = [
					"type" : "binary-op",
					"op"   : "=",
					"left" : this->_getQualified([
						"type"   : 355,
						"domain" : modelAlias,
						"name"   : field
					]),
					"right"      : this->_getQualified([
						"type"   : "qualified",
						"domain" : joinAlias,
						"name"   : referencedField
					])
				];
			}

		}

		/**
		 * A single join
		 */
		return [
			"type"       : joinType,
			"source"     : joinSource,
			"conditions" : sqlJoinConditions
		];
	}

	/**
	 * Resolves joins involving many-to-many relations
	 *
	 * @param string joinType
	 * @param string joinSource
	 * @param string modelAlias
	 * @param string joinAlias
	 * @param Phalcon\Mvc\Model\RelationInterface relation
	 * @return array
	 */
	protected function _getMultiJoin(joinType, joinSource, modelAlias, joinAlias,
		<Phalcon\Mvc\Model\RelationInterface> relation)
	{
		var sqlJoins, fields, referencedFields,
			intermediateModelName, intermediateModel, intermediateSource,
			intermediateSchema, intermediateFields, intermediateReferencedFields,
			referencedModelName, manager, field, position, intermediateField,
			sqlEqualsJoinCondition;

		let sqlJoins = [];

		/**
		 * Local fields in the 'from' relation
		 */
		let fields = relation->getFields();

		/**
		 * Referenced fields in the joined relation
		 */
		let referencedFields = relation->getReferencedFields();

		/**
		 * Intermediate model
		 */
		let intermediateModelName = relation->getIntermediateModel();

		let manager = this->_manager;

		/**
		 * Get the intermediate model instance
		 */
		let intermediateModel = manager->load(intermediateModelName);

		/**
		 * Source of the related model
		 */
		let intermediateSource = intermediateModel->getSource();

		/**
		 * Schema of the related model
		 */
		let intermediateSchema = intermediateModel->getSchema();

		//intermediateFullSource = array(intermediateSchema, intermediateSource);

		/**
		 * Update the internal sqlAliases to set up the intermediate model
		 */
		let this->_sqlAliases[intermediateModelName] = intermediateSource;

		/**
		 * Update the internal _sqlAliasesModelsInstances to rename columns if necessary
		 */
		let this->_sqlAliasesModelsInstances[intermediateModelName] = intermediateModel;

		/**
		 * Fields that join the 'from' model with the 'intermediate' model
		 */
		let intermediateFields = relation->getIntermediateFields();

		/**
		 * Fields that join the 'intermediate' model with the intermediate model
		 */
		let intermediateReferencedFields = relation->getIntermediateReferencedFields();

		/**
		 * Intermediate model
		 */
		let referencedModelName = relation->getReferencedModel();

		if typeof fields == "array" {
			for field, position in fields {

				if !isset referencedFields[position] {
					throw new Phalcon\Mvc\Model\Exception("The number of fields must be equal to the number of referenced fields in join " . modelAlias . "-" . joinAlias . ", when preparing: " . this->_phql);
				}

				/**
				 * Get the referenced field in the same position
				 */
				let intermediateField = intermediateFields[position];

				/**
				 * Create a binary operation for the join conditions
				 */
				let sqlEqualsJoinCondition = [
					"type" : "binary-op",
					"op" : "=",
					"left" : this->_getQualified([
						"type" : 355,
						"domain" : modelAlias,
						"name" : field
					]),
					"right" : this->_getQualified([
						"type" : "qualified",
						"domain" : joinAlias,
						"name" : referencedFields
					])
				];

				//let sqlJoinPartialConditions[] = sqlEqualsJoinCondition;
			}

		} else {

			/**
			 * Create the left part of the expression
			 * Create the right part of the expression
			 * Create a binary operation for the join conditions
			 * A single join
			 */
			let sqlJoins = [

				[
					"type" : joinType,
					"source" : intermediateSource,
					"conditions" : [[
						"type" : "binary-op",
						"op" : "=",
						"left" : this->_getQualified([
							"type" : 355,
							"domain" : modelAlias,
							"name" : fields
						]),
						"right" : this->_getQualified([
							"type" : "qualified",
							"domain" : intermediateModelName,
							"name" : intermediateFields
						])
					]]
				],

				/**
				 * Create the left part of the expression
				 * Create the right part of the expression
				 * Create a binary operation for the join conditions
				 * A single join
				 */
				[
					"type" : joinType,
					"source" : joinSource,
					"conditions" : [[
						"type" : "binary-op",
						"op" : "=",
						"left" : this->_getQualified([
							"type" : 355,
							"domain" : intermediateModelName,
							"name" : intermediateReferencedFields
						]),
						"right" : this->_getQualified([
							"type" : "qualified",
							"domain" : referencedModelName,
							"name" : referencedFields
						])
					]]
				]
			];
		}

		return sqlJoins;
	}

	/**
	 * Processes the JOINs in the query returning an internal representation for the database dialect
	 *
	 * @param array select
	 * @return array
	 */
	protected function _getJoins(select)
	{
		var models, sqlAliases, sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances,
			modelsInstances, fromModels, sqlJoins, joinModels, joinSources, joinTypes, joinPreCondition,
			joinPrepared, manager, selectJoins, joinItem, joins, joinData, schema, source, model,
			modelName, completeSource, joinType, aliasExpr, alias, joinAliasName, joinExpr,
			fromModelName, joinAlias, joinModel, joinSource, preCondition, modelNameAlias,
			relation, relations, modelAlias, sqlJoin;

		let models = this->_models,
			sqlAliases = this->_sqlAliases,
			sqlAliasesModels = this->_sqlAliasesModels,
			sqlModelsAliases = this->_sqlModelsAliases,
			sqlAliasesModelsInstances = this->_sqlAliasesModelsInstances,
			modelsInstances = this->_modelsInstances,
			fromModels = models;

		let sqlJoins = [],
			joinModels = [],
			joinSources = [],
			joinTypes = [],
			joinPreCondition = [],
			joinPrepared = [];

		let manager = this->_manager;

		let joins = select["joins"];
		if !isset joins[0] {
			let selectJoins = [joins];
		} else {
			let selectJoins = joins;
		}

		for joinItem in selectJoins {

			/**
			 * Check join alias
			 */
			let joinData = this->_getJoin(manager, joinItem),
				source = joinData["source"],
				schema = joinData["schema"],
				model = joinData["model"],
				modelName = joinData["modelName"],
				completeSource = [source, schema];

			/**
			 * Check join alias
			 */
			let joinType = this->_getJoinType(joinItem);

			/**
			 * Process join alias
			 */
			if fetch aliasExpr, joinItem["alias"] {

				let alias = aliasExpr["name"];

				/**
				 * Check if alias is unique
				 */
				if isset joinModels[alias] {
					throw new Phalcon_Mvc_Model_Exception("Cannot use '" . alias . "' as join alias because it was already used, when preparing: " . this->_phql);
				}

				/**
				 * Add the alias to the source
				 */
				let completeSource[] = alias;

				/**
				 * Set the join type
				 */
				let joinTypes[alias] = joinType;

				/**
				 * Update alias: alias
				 */
				let sqlAliases[alias] = alias;

				/**
				 * Update model: alias
				 */
				let joinModels[alias] = modelName;

				/**
				 * Update model: alias
				 */
				let sqlModelsAliases[modelName] = alias;

				/**
				 * Update model: model
				 */
				let sqlAliasesModels[alias] = modelName;

				/**
				 * Update alias: model
				 */
				let sqlAliasesModelsInstances[alias] = model;

				/**
				 * Update model: alias
				 */
				let models[modelName] = alias;

				/**
				 * Complete source related to a model
				 */
				let joinSources[alias] = completeSource;

				/**
				 * Complete source related to a model
				 */
				let joinPrepared[alias] = joinItem;

			} else {

				/**
				 * Check if alias is unique
				 */
				if isset joinModels[modelName] {
					throw new Phalcon\Mvc\Model\Exception("Cannot use '" . modelName . "' as join alias because it was already used, when preparing: " . this->_phql);
				}

				/**
				 * Set the join type
				 */
				let joinTypes[modelName] = joinType;

				/**
				 * Update model: source
				 */
				let sqlAliases[modelName] = source;

				/**
				 * Update model: source
				 */
				let joinModels[modelName] = source;

				/**
				 * Update model: model
				 */
				let sqlModelsAliases[modelName] = modelName;

				/**
				 * Update model: model
				 */
				let sqlAliasesModels[modelName] = modelName;

				/**
				 * Update model: model instance
				 */
				let sqlAliasesModelsInstances[modelName] = model;

				/**
				 * Update model: source
				 */
				let models[modelName] = source;

				/**
				 * Complete source related to a model
				 */
				let joinSources[modelName] = completeSource;

				/**
				 * Complete source related to a model
				 */
				let joinPrepared[modelName] = joinItem;
			}

			let modelsInstances[modelName] = model;
		}

		/**
		 * Update temporary properties
		 */
		let this->_models = models,
			this->_sqlAliases = sqlAliases,
			this->_sqlAliasesModels = sqlAliasesModels,
			this->_sqlModelsAliases = sqlModelsAliases,
			this->_sqlAliasesModelsInstances = sqlAliasesModelsInstances,
			this->_modelsInstances = modelsInstances;

		for joinAliasName, joinItem in joinPrepared {

			/**
			 * Check for predefined conditions
			 */
			if fetch joinExpr, joinItem["conditions"] {
				let joinPreCondition[joinAliasName] = this->_getExpression(joinExpr);
			}
		}

		/**
		 * Create join relationships dynamically
		 */
		let manager = this->_manager;

		for fromModelName, source in fromModels {

			for joinAlias, joinModel in joinModels {

				/**
				 * Real source name for joined model
				 */
				let joinSource = joinSources[joinAlias];

				/**
				 * Join type is: LEFT, RIGHT, INNER, etc
				 */
				let joinType = joinTypes[joinAlias];

				/**
				 * Check if the model already have pre-defined conditions
				 */
				if !fetch preCondition, joinPreCondition[joinAlias] {

					/**
					 * Get the model name from its source
					 */
					let modelNameAlias = sqlAliasesModels[joinAlias];

					/**
					 * Check if the joined model is an alias
					 */
					let relation = manager->getRelationByAlias(fromModelName, modelNameAlias);
					if relation === false {

						/**
						 * Check for relations between models
						 */
						let relations = manager->getRelationsBetween(fromModelName, modelNameAlias);
						if typeof relations == "array" {

							/**
							 * More than one relation must throw an exception
							 */
							if count(relations) != 1 {
								throw new Phalcon\Mvc\Model\Exception("There is more than one relation between models '" . modelName . "' and '" . joinModel . "', the join must be done using an alias, when preparing: " . this->_phql);
							}

							/**
							 * Get the first relationship
							 */
							let relation = relations[0];
						}
					}

					/*
					 * Valid relations are objects
					 */
					if typeof relation == "object" {

						/**
						 * Get the related model alias of the left part
						 */
						let modelAlias = sqlModelsAliases[fromModelName];

						/**
						 * Generate the conditions based on the type of join
						 */
						if !relation->isThrough() {
							let sqlJoin = this->_getSingleJoin(joinType, joinSource, modelAlias, joinAlias, relation);
						} else {
							let sqlJoin = this->_getMultiJoin(joinType, joinSource, modelAlias, joinAlias, relation);
						}

						/**
						 * Append or merge joins
						 */
						if isset sqlJoin[0] {
							let sqlJoins = array_merge(sqlJoins, sqlJoin);
						} else {
							let sqlJoins[] = sqlJoin;
						}

					} else {

						/**
						 * Join without conditions because no relation has been found between the models
						 */
						let sqlJoins[] = [
							"type": joinType,
							"source": joinSource,
							"conditions": []
						];
					}
				} else {

					/**
					 * Get the conditions stablished by the developer
					 * Join with conditions stablished by the developer
					 */
					let sqlJoins[] = [
						"type": joinType,
						"source": joinSource,
						"conditions": [preCondition]
					];
				}
			}
		}

		return sqlJoins;
	}

	/**
	 * Returns a processed order clause for a SELECT statement
	 *
	 * @param array $order
	 * @return string
	 */
	protected function _getOrderClause(order)
	{
		var orderColumns, orderParts, orderItem, orderPartExpr,
			orderSort, orderPartSort;

		if !isset order[0] {
			let orderColumns = [order];
		} else {
			let orderColumns = order;
		}

		let orderParts = [];
		for orderItem in orderColumns {

			let orderPartExpr = this->_getExpression(orderItem["column"]);

			/**
			 * Check if the order has a predefined ordering mode
			 */
			if fetch orderSort, orderItem["sort"] {
				if orderSort == 327{
					let orderPartSort = [orderPartExpr, "ASC"];
				} else {
					let orderPartSort = [orderPartExpr, "DESC"];
				}
			} else {
				let orderPartSort = [orderPartExpr];
			}

			let orderParts[] = orderPartSort;
		}

		return orderParts;
	}

	/**
	 * Returns a processed group clause for a SELECT statement
	 *
	 * @param array $group
	 * @return array
	 */
	protected function _getGroupClause(group)
	{
		var groupItem, groupParts;

		if isset group[0] {
			/**
			 * The select is gruped by several columns
			 */
			let groupParts = [];
			for groupItem in group {
				let groupParts[] = this->_getExpression(groupItem);
			}
		} else {
			let groupParts = [this->_getExpression(group)];
		}
		return groupParts;
	}

	/**
	 * Analyzes a SELECT intermediate code and produces an array to be executed later
	 *
	 * @return array
	 */
	protected function _prepareSelect()
	{
		var ast, sqlModels, sqlTables, sqlAliases, sqlColumns, select, tables, columns,
			sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances,
			models, modelsInstances, selectedModels, manager, metaData,
			selectedModel, qualifiedName, modelName, nsAlias, realModelName, model,
			schema, source, completeSource, alias, joins, sqlJoins, selectColumns,
			sqlColumnAliases, column, sqlColumn, sqlSelect, having, where,
			groupBy, order, limit;
		int position;

		let ast = this->_ast,
			select = ast["select"];

		if !fetch tables, select["tables"] {
			throw new Phalcon\Mvc\Model\Exception("Corrupted SELECT AST");
		}

		if !fetch columns, select["columns"] {
			throw new Phalcon\Mvc\Model\Exception("Corrupted SELECT AST");
		}

		/**
		 * sql_models are all the models that are using in the query
		 */
		let sqlModels = [];

		/**
		 * sql_tables are all the mapped sources regarding the models in use
		 */
		let sqlTables = [];

		/**
		 * sql_aliases are the aliases as keys and the mapped sources as values
		 */
		let sqlAliases = [];

		/**
		 * sql_columns are all every column expression
		 */
		let sqlColumns = [];

		/**
		 * sqlAliasesModels are the aliases as keys and the model names as values
		 */
		let sqlAliasesModels = [];

		/**
		 * sqlAliasesModels are the model names as keys and the aliases as values
		 */
		let sqlModelsAliases = [];

		/**
		 * sqlAliasesModelsInstances are the aliases as keys and the model instances as values
		 */
		let sqlAliasesModelsInstances = [];

		/**
		 * Models information
		 */
		let models = [],
			modelsInstances = [];

		if !isset tables[0] {
			let selectedModels = [tables];
		} else {
			let selectedModels = tables;
		}

		let manager = this->_manager,
			metaData = this->_metaData;

		/**
		 * Processing selected columns
		 */
		for selectedModel in selectedModels {

			let qualifiedName = selectedModel["qualifiedName"],
				modelName = qualifiedName["name"];

			/**
			 * Check if the table have a namespace alias
			 */
			if fetch nsAlias, qualifiedName["ns-alias"] {

				/**
				 * Get the real namespace alias
				 * Create the real namespaced name
				 */
				let realModelName = manager->getNamespaceAlias(nsAlias) . "\\" . modelName;

			} else {
				let realModelName = modelName;
			}

			/**
			 * Load a model instance from the models manager
			 */
			let model = manager->load(realModelName);

			/**
			 * Define a complete schema/source
			 */
			let schema = model->getSchema(),
				source = model->getSource();

			/**
			 * Obtain the real source including the schema
			 */
			if schema {
				let completeSource = [source, schema];
			} else {
				let completeSource = source;
			}

			/**
			 * If an alias is defined for a model the model cannot be referenced in the column list
			 */
			if fetch alias, selectedModel["alias"] {

				/**
				 * Check that the alias hasn"t been used before
				 */
				if isset sqlAliases[alias] {
					throw new Phalcon\Mvc\Model\Exception("Alias '" . alias . "' is already used, when preparing: " . this->_phql);
				}

				let sqlAliasesModels[alias] = modelName,
					sqlModelsAliases[modelName] = alias,
					sqlAliasesModelsInstances[alias] = model;

				/**
				 * Append or convert complete source to an array
				 */
				if typeof completeSource == "array" {
					let completeSource[] = alias;
				} else {
					let completeSource = [source, null, alias];
				}
				let models[modelName] = alias;

			} else {
				let sqlAliases[modelName] = source,
					sqlAliasesModels[modelName] = modelName,
					sqlModelsAliases[modelName] = modelName,
					sqlAliasesModelsInstances[modelName] = model,
					models[modelName] = source;
			}

			let sqlModels[] = modelName,
				sqlTables[] = completeSource,
				modelsInstances[modelName] = model;
		}

		/**
		 * Assign Models/Tables information
		 */
		let this->_models = models,
			this->_modelsInstances = modelsInstances,
			this->_sqlAliases = sqlAliases,
			this->_sqlAliasesModels = sqlAliasesModels,
			this->_sqlModelsAliases = sqlModelsAliases,
			this->_sqlAliasesModelsInstances = sqlAliasesModelsInstances,
			this->_modelsInstances = modelsInstances;

		/**
		 * Processing joins
		 */
		if fetch joins, select["joins"] {
			if count(joins) {
				let sqlJoins = this->_getJoins(select);
			} else {
				let sqlJoins = [];
			}
		} else {
			let sqlJoins = [];
		}

		/**
		 * Processing selected columns
		 */
		if !isset columns[0] {
			let selectColumns = [columns];
		} else {
			let selectColumns = columns;
		}

		/**
		 * Resolve selected columns
		 */
		let position = 0,
			sqlColumnAliases = [];

		for column in selectColumns {

			for sqlColumn in this->_getSelectColumn(column) {

				/**
				 * If "alias" is set, the user had defined a alias for the column
				 */
				if fetch alias, column["alias"] {

					/**
					 * The best alias is the one provided by the user
					 */
					let sqlColumn["balias"] = alias,
						sqlColumn["sqlAlias"] = alias,
						sqlColumns[alias] = sqlColumn,
						sqlColumnAliases[alias] = true;

				} else {
					/**
					 * "balias" is the best alias selected for the column
					 */
					if fetch alias, sqlColumn["balias"] {
						let sqlColumns[alias] = sqlColumn;
					} else {
						if sqlColumn["type"] == "scalar" {
							let sqlColumns["_" . position] = sqlColumn;
						} else {
							let sqlColumns[] = sqlColumn;
						}
					}
				}

				let position++;
			}
		}
		let this->_sqlColumnAliases = sqlColumnAliases;

		/**
		 * sqlSelect is the final prepared SELECT
		 */
		let sqlSelect = [
			"models" : sqlModels,
			"tables" : sqlTables,
			"columns": sqlColumns
		];

		if count(sqlJoins) {
			let sqlSelect["joins"] = sqlJoins;
		}

		/**
		 * Process WHERE clause if any
		 */
		if fetch where, ast["where"] {
			let sqlSelect["where"] = this->_getExpression(where);
		}

		/**
		 * Process GROUP BY clause if any
		 */
		if fetch groupBy, ast["groupBy"] {
			let sqlSelect["group"] = this->_getGroupClause(groupBy);
		}

		/**
		 * Process HAVING clause if any
		 */
		if fetch having , ast["having"] {
			let sqlSelect["having"] = this->_getExpression(having);
		}

		/**
		 * Process ORDER BY clause if any
		 */
		if fetch order, ast["orderBy"] {
			let sqlSelect["order"] = this->_getOrderClause(order);
		}

		/**
		 * Process LIMIT clause if any
		 */
		if fetch limit, ast["limit"] {
			let sqlSelect["limit"] = limit;
		}

		return sqlSelect;
	}

	/**
	 * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang generating another
	 * intermediate representation that could be executed by Phalcon\Mvc\Model\Query
	 *
	 * @return array
	 */
	public function parse()
	{
		var intermediate, phql, ast, irPhql, irPhqlCache, uniqueId, type;

		let intermediate = this->_intermediate;
		if typeof intermediate == "array" {
			return intermediate;
		}

		/**
		 * This function parses the PHQL statement
		 */
		let phql = this->_phql,
			ast = phql_parse_phql();

		let irPhql = null,
			irPhqlCache = null,
			uniqueId = null;

		if typeof ast == "array" {

			/**
			 * Check if the prepared PHQL is already cached
			 * Parsed ASTs have a unique id
			 */
			if fetch uniqueId, ast["id"] {
				if fetch irPhql, self::_irPhqlCache[uniqueId] {
					if typeof irPhql == "array" {
						/**
						 * Assign the type to the query
						 */
						let this->_type = ast["type"];
						return irPhql;
					}
				}
			}

			/**
			 * A valid AST must have a type
			 */
			if fetch type, ast["type"] {

				let this->_type = type;
				switch type {
					case 309:
						let irPhql = this->_prepareSelect();
						break;
					case 306:
						//let irPhql = this->_prepareInsert();
						break;
					case 300:
						//let irPhql = this->_prepareUpdate();
						break;
					case 303:
						//let irPhql = this->_prepareDelete();
						break;
					default:
						throw new Phalcon\Mvc\Model\Exception("Unknown statement " . type . ", when preparing: " . phql);
				}
			}
		}

		if typeof irPhql != "array" {
			throw new Phalcon\Mvc\Model\Exception("Corrupted AST");
		}

		/**
		 * Store the prepared AST in the cache
		 */
		if typeof uniqueId == "int" {
			let self::_irPhqlCache[uniqueId] = irPhql;
		}

		let this->_intermediate = irPhql;
		return irPhql;
	}

	/**
	 * Returns the current cache backend instance
	 *
	 * @return Phalcon\Cache\BackendInterface
	 */
	public function getCache()
	{
		return this->_cache;
	}

	/**
	 * Executes the SELECT intermediate representation producing a Phalcon\Mvc\Model\Resultset
	 *
	 * @param array intermediate
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\ResultsetInterface
	 */
	protected function _executeSelect(intermediate, bindParams, bindTypes) -> <Phalcon\Mvc\Model\ResultsetInterface>
	{

		var manager, modelName, models, model, connection, connections,
			columns, column, selectColumns, simpleColumnMap, metaData, aliasCopy,
			sqlColumn, attributes, instance, columnMap, attribute,
			isKeepingSnapshots, columnAlias, sqlAlias, dialect, sqlSelect,
			processed, wildcard, value, processedTypes, typeWildcard, result,
			resultData, cache, resultObject;
		boolean haveObjects, haveScalars, isComplex, isSimpleStd;
		int numberObjects;

		let manager = this->_manager;

		let models = intermediate["models"];

		if count(models) == 1 {

			/**
			 * Load first model if is not loaded
			 */
			let modelName = models[0];
			if !fetch model, this->_modelsInstances[modelName] {
				let model = manager->load(modelName),
					this->_modelsInstances[modelName] = model;
			}

			/**
			 * The 'selectConnection' method could be implemented in a
			 */
			if method_exists(model, "selectReadConnection") {
				let connection = model->selectReadConnection(intermediate, bindParams, bindTypes);
				if typeof connection != "object" {
					throw new Phalcon\Mvc\Model\Exception("'selectReadConnection' didn't return a valid connection");
				}
			} else {

				/**
				 * Get the current connection to the model
				 */
				let connection = model->getReadConnection();
			}

		} else {

			/**
			 * Check if all the models belongs to the same connection
			 */
			let connections = [];
			for modelName in models {

				if !fetch model, this->_modelsInstances[modelName] {
					let model = manager->load(modelName),
						this->_modelsInstances[modelName] = model;
				}

				/**
				 * Get the models connection
				 * Mark the type of connection in the connection flags
				 */
				let connection = model->getReadConnection(),
					connections[connection->getType()] = true;

				/**
				 * More than one type of connection is not allowed
				 */
				if count(connections) == 2 {
					throw new Phalcon\Mvc\Model\Exception("Cannot use models of different database systems in the same query");
				}

			}
		}

		let columns = intermediate["columns"];

		let haveObjects = false,
			haveScalars = false,
			isComplex = false;

		/**
		 * Check if the resultset have objects and how many of them have
		 */
		let numberObjects = 0;
		for column in columns {

			if column["type"] == "scalar" {
				if !isset column["balias"] {
					let isComplex = true;
				}
				let haveScalars = true;
			} else {
				let haveObjects = true, numberObjects++;
			}
		}

		/**
		 * Check if the resultset to return is complex or simple
		 */
		if isComplex === false {
			if haveObjects === true {
				if haveScalars === true {
					let isComplex = true;
				} else {
					if numberObjects == 1 {
						let isSimpleStd = false;
					} else {
						let isComplex = true;
					}
				}
			} else {
				let isSimpleStd = true;
			}
		}

		/**
		 * Processing selected columns
		 */
		let selectColumns = [],
			simpleColumnMap = [],
			metaData = this->_metaData;

		for aliasCopy, column in columns {

			let sqlColumn = column["column"];

			/**
			 * Complete objects are treaded in a different way
			 */
			if column["type"] == "object" {

				let modelName = column["model"];

				/**
				 * Base instance
				 */
				if !fetch instance, this->_modelsInstances[modelName] {
					let instance = manager->load(modelName),
						this->_modelsInstances[modelName] = instance;
				}

				let attributes = metaData->getAttributes(instance);
				if isComplex === true {

					/**
					 * If the resultset is complex we open every model into their columns
					 */
					if globals_get("orm.column_renaming") {
						let columnMap = metaData->getColumnMap(instance);
					} else {
						let columnMap = null;
					}

					/**
					 * Add every attribute in the model to the generated select
				 	 */
					for attribute in attributes {
						let selectColumns[] = [attribute, sqlColumn, "_" . sqlColumn . "_" . attribute];
					}

					/**
					 * We cache required meta-data to make its future access faster
					 */
					let columns[aliasCopy]["instance"] = instance,
						columns[aliasCopy]["attributes"] = attributes,
						columns[aliasCopy]["columnMap"] = columnMap;

					/**
					 * Check if the model keeps snapshots
					 */
					let isKeepingSnapshots = manager->isKeepingSnapshots(instance);
					if isKeepingSnapshots {
						let columns[aliasCopy]["keepSnapshots"] = isKeepingSnapshots;
					}

				} else {

					/**
					 * Query only the columns that are registered as attributes in the metaData
					 */
					for attribute in attributes {
						let selectColumns[] = [attribute, sqlColumn];
					}
				}
			} else {

				/**
 				 * Create an alias if the column doesn"t have one
				 */
				if typeof aliasCopy == "int" {
					let columnAlias = [sqlColumn, null];
				} else {
					let columnAlias = [sqlColumn, null, aliasCopy];
				}
				let selectColumns[] = columnAlias;
			}

			/**
			 * Simulate a column map
			 */
			if isComplex === false {
				if isSimpleStd === true {
					if fetch sqlAlias, column["sqlAlias"] {
						let simpleColumnMap[sqlAlias] = aliasCopy;
					} else {
						let simpleColumnMap[aliasCopy] = aliasCopy;
					}
				}
			}
		}

		let intermediate["columns"] = selectColumns;

		/**
		 * The corresponding SQL dialect generates the SQL statement based accordingly with the database system
		 */
		let dialect = connection->getDialect(),
			sqlSelect = dialect->select(intermediate);

		/**
		 * Replace the placeholders
		 */
		if typeof bindParams == "array" {
			let processed = [];
			for wildcard, value in bindParams {
				if typeof wildcard == "int" {
					let processed[":" . wildcard] = value;
				} else {
					let processed[wildcard] = value;
				}
			}
		} else {
			let processed = bindParams;
		}

		/**
		 * Replace the bind Types
		 */
		if typeof bindTypes == "array" {
			let processedTypes = [];
			for typeWildcard, value in bindTypes {
				if typeof typeWildcard == "string" {
					let processedTypes[":" . typeWildcard] = value;
				} else {
					let processedTypes[typeWildcard] = value;
				}
			}
		} else {
			let processedTypes = bindTypes;
		}

		/**
		 * Execute the query
		 */
		let result = connection->query(sqlSelect, processed, processedTypes);

		/**
		 * Check if the query has data
		 */
		if result->numRows(result) {
			let resultData = result;
		} else {
			let resultData = false;
		}

		/**
		 * Choose a resultset type
		 */
		let cache = this->_cache;
		if isComplex === false {

			/**
			 * Select the base object
			 */
			if isSimpleStd === true {

				/**
				 * If the result is a simple standard object use an Phalcon\Mvc\Model\Row as base
				 */
				let resultObject = new Phalcon\Mvc\Model\Row();

				/**
				 * Standard objects can"t keep snapshots
				 */
				let isKeepingSnapshots = false;

			} else {

				let resultObject = model;

				/**
				 * Get the column map
				 */
				let simpleColumnMap = metaData->getColumnMap(model);

				/**
				 * Check if the model keeps snapshots
				 */
				let isKeepingSnapshots = manager->isKeepingSnapshots(model);
			}

			/**
			 * Simple resultsets contains only complete objects
			 */
			return new Phalcon\Mvc\Model\Resultset_Simple(simpleColumnMap, resultObject, resultData, cache, isKeepingSnapshots);
		}

		/**
		 * Complex resultsets may contain complete objects and scalars
		 */
		return new Phalcon\Mvc\Model\Resultset\Complex(columns, resultData, cache);
	}

	/**
	 * Sets the cache parameters of the query
	 *
	 * @param array cacheOptions
	 * @return Phalcon\Mvc\Model\Query
	 */
	public function cache(cacheOptions) -> <Phalcon\Mvc\Model\Query>
	{
		let this->_cacheOptions = cacheOptions;
		return this;
	}

	/**
	 * Returns the current cache options
	 *
	 * @param array
	 */
	public function getCacheOptions()
	{
		return this->_cacheOptions;
	}

	/**
	 * Executes a parsed PHQL statement
	 *
	 * @param array bindParams
	 * @param array bindTypes
	 * @return mixed
	 */
	public function execute(bindParams=null, bindTypes=null)
	{

	}

}
