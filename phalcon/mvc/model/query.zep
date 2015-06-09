
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
 |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model;

use Phalcon\DiInterface;
use Phalcon\Db\RawValue;
use Phalcon\Mvc\Model\Row;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\ManagerInterface;
use Phalcon\Mvc\Model\QueryInterface;
use Phalcon\Cache\BackendInterface;
use Phalcon\Mvc\Model\Query\Status;
use Phalcon\Mvc\Model\Resultset\Complex;
use Phalcon\Mvc\Model\Query\StatusInterface;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\Model\RelationInterface;

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
class Query implements QueryInterface, InjectionAwareInterface
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
	 * Phalcon\Mvc\Model\Query constructor
	 *
	 * @param string phql
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function __construct(phql = null, <DiInterface> dependencyInjector = null)
	{
		if typeof phql != "null" {
			let this->_phql = phql;
		}

		if typeof dependencyInjector == "object" {
			this->setDI(dependencyInjector);
		}
	}

	/**
	 * Sets the dependency injection container
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		var manager, metaData;

		let manager = dependencyInjector->getShared("modelsManager");
		if typeof manager != "object" {
			throw new Exception("Injected service 'modelsManager' is invalid");
		}

		let metaData = dependencyInjector->getShared("modelsMetadata");
		if typeof metaData != "object" {
			throw new Exception("Injected service 'modelsMetaData' is invalid");
		}

		let this->_manager = manager,
			this->_metaData = metaData;

		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the dependency injection container
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Tells to the query if only the first row in the resultset must be returned
	 */
	public function setUniqueRow(boolean uniqueRow) -> <Query>
	{
		let this->_uniqueRow = uniqueRow;
		return this;
	}

	/**
	 * Check if the query is programmed to get only the first row in the resultset
	 */
	public function getUniqueRow() -> boolean
	{
		return this->_uniqueRow;
	}

	/**
	 * Replaces the model's name to its source name in a qualifed-name expression
	 */
	protected final function _getQualified(array! expr) -> array
	{
		var columnName, sqlColumnAliases, metaData, sqlAliases,
			source, sqlAliasesModelsInstances, realColumnName, columnDomain,
			model, models, columnMap, hasModel, className;
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
		if fetch columnDomain, expr["domain"] {

			let sqlAliases = this->_sqlAliases;

			/**
			 * The column has a domain, we need to check if it's an alias
			 */
			if !fetch source, sqlAliases[columnDomain] {
				throw new Exception("Unknown model or alias '" . columnDomain . "' (1), when preparing: " . this->_phql);
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
				 * We need the model instance to retrieve the reversed column map
				 */
				if !fetch model, sqlAliasesModelsInstances[columnDomain] {
					throw new Exception("There is no model related to model or alias '" . columnDomain . "', when executing: " . this->_phql);
				}

				let columnMap = metaData->getReverseColumnMap(model);
			} else {
				let columnMap = null;
			}

			if typeof columnMap == "array" {
				if !fetch realColumnName, columnMap[columnName] {
					throw new Exception("Column '" . columnName . "' doesn't belong to the model or alias '" . columnDomain . "', when executing: ". this->_phql);
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
						throw new Exception("The column '" . columnName . "' is ambiguous, when preparing: " . this->_phql);
					}
					let hasModel = model;
				}
			}

			/**
			 * After check in every model, the column does not belong to any of the selected models
			 */
			if hasModel === false {
				throw new Exception("Column '" . columnName . "' doesn't belong to any of the selected models (1), when preparing: " . this->_phql);
			}

			/**
			 * Check if the _models property is correctly prepared
			 */
			let models = this->_models;
			if typeof models != "array" {
				throw new Exception("The models list was not loaded correctly");
			}

			/**
			 * Obtain the model's source from the _models list
			 */
			let className = get_class(hasModel);
			if !fetch source, models[className] {
				throw new Exception("Can't obtain model's source from models list: '" . className . "', when preparing: " . this->_phql);
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
					throw new Exception("Column '" . columnName . "' doesn't belong to any of the selected models (3), when preparing: " . this->_phql);
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
	 */
	protected final function _getCallArgument(array! argument) -> array
	{
		if argument["type"] == PHQL_T_STARALL {
			return ["type": "all"];
		}
		return this->_getExpression(argument);
	}

	/**
	 * Resolves a expression in a single call argument
	 */
	protected final function _getCaseExpression(array! expr) -> array
	{
		var whenClauses, whenExpr;

		let whenClauses = [];
		for whenExpr in expr["right"] {
			if isset whenExpr["right"] {
				let whenClauses[] = [
					"type": "when",
					"expr": this->_getExpression(whenExpr["left"]),
					"then": this->_getExpression(whenExpr["right"])
				];
			} else {
				let whenClauses[] = [
					"type": "else",
					"expr": this->_getExpression(whenExpr["left"])
				];
			}
		}

		return [
			"type"        : "case",
			"expr"        : this->_getExpression(expr["left"]),
			"when-clauses": whenClauses
		];
	}

	/**
	 * Resolves a expression in a single call argument
	 */
	protected final function _getFunctionCall(array! expr) -> array
	{
		var arguments, distinct, argument, functionArgs;

		if fetch arguments, expr["arguments"] {

			if isset expr["distinct"] {
				let distinct = 1;
			} else {
				let distinct = 0;
			}

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

			if distinct {
				return [
					"type"     : "functionCall",
					"name"     : expr["name"],
					"arguments": functionArgs,
					"distinct" : distinct
				];
			} else {
				return [
					"type"     : "functionCall",
					"name"     : expr["name"],
					"arguments": functionArgs
				];
			}
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
	protected final function _getExpression(expr, boolean quoting = true) -> string
	{
		var exprType, exprLeft, exprRight, left = null, right = null, listItems, exprListItem,
			exprReturn, tempNotQuoting, value, escapedValue, exprValue;

		if fetch exprType, expr["type"] {

			let tempNotQuoting = true;

			if exprType != PHQL_T_CASE {

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

				case PHQL_T_NOTEQUALS:
					let exprReturn = ["type": "binary-op", "op": "<>", "left": left, "right": right];
					break;

				case PHQL_T_LESSEQUAL:
					let exprReturn = ["type": "binary-op", "op": "<=", "left": left, "right": right];
					break;

				case PHQL_T_GREATEREQUAL:
					let exprReturn = ["type": "binary-op", "op": ">=", "left": left, "right": right];
					break;

				case PHQL_T_AND:
					let exprReturn = ["type": "binary-op", "op": "AND", "left": left, "right": right];
					break;

				case PHQL_T_OR:
					let exprReturn = ["type": "binary-op", "op": "OR", "left": left, "right": right];
					break;

				case PHQL_T_QUALIFIED:
					let exprReturn = this->_getQualified(expr);
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

				case PHQL_T_BITWISE_AND:
					let exprReturn = ["type": "binary-op", "op": "&", "left": left, "right": right];
					break;

				case PHQL_T_BITWISE_OR:
					let exprReturn = ["type": "binary-op", "op": "|", "left": left, "right": right];
					break;

				case PHQL_T_ENCLOSED:
				case PHQL_T_SUBQUERY:
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

				case PHQL_T_NTPLACEHOLDER:
					let exprReturn = ["type": "placeholder", "value": str_replace("?", ":", expr["value"])];
					break;

				case PHQL_T_STPLACEHOLDER:
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

				case PHQL_T_ISNULL:
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

				case PHQL_T_EXISTS:
					let exprReturn = ["type": "unary-op", "op": "EXISTS", "right": right];
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

				case PHQL_T_CASE:
					let exprReturn = this->_getCaseExpression(expr);
					break;

				case PHQL_T_SELECT:
					let exprReturn = ["type": "select", "value": this->_prepareSelect(expr, true)];
					break;

				default:
					throw new Exception("Unknown expression type " . exprType);
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

		throw new Exception("Unknown expression");
	}

	/**
	 * Resolves a column from its intermediate representation into an array used to determine
	 * if the resultset produced is simple or complex
	 *
	 * @param array column
	 * @return array
	 */
	protected final function _getSelectColumn(array! column)
	{
		var sqlColumns, columnType, sqlAliases, modelName, source,
			columnDomain, sqlColumnAlias, preparedAlias, sqlExprColumn,
			sqlAliasesModels, sqlColumn, columnData, balias;

		if !fetch columnType, column["type"] {
			throw new Exception("Corrupted SELECT AST");
		}

		let sqlColumns = [];

		/**
		 * Check for select * (all)
		 */
		if columnType == PHQL_T_STARALL {
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
			throw new Exception("Corrupted SELECT AST");
		}

		/**
		 * Check if selected column is qualified.*, ex: robots.*
		 */
		if columnType == PHQL_T_DOMAINALL {

			let sqlAliases = this->_sqlAliases;

			/**
			 * We only allow the alias.*
			 */
			let columnDomain = column["column"];

			if !fetch source, sqlAliases[columnDomain] {
				throw new Exception("Unknown model or alias '" . columnDomain . "' (2), when preparing: " . this->_phql);
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
			 * If the best alias is the model name we lowercase the first letter
			 */
			if columnDomain == modelName {
				let preparedAlias = lcfirst(modelName);
			} else {
				let preparedAlias = columnDomain;
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

		throw new Exception("Unknown type of column " . columnType);
	}

	/**
	 * Resolves a table in a SELECT statement checking if the model exists
	 *
	 * @param Phalcon\Mvc\Model\ManagerInterface manager
	 * @param array qualifiedName
	 * @return string
	 */
	protected final function _getTable(<ManagerInterface> manager, qualifiedName)
	{
		var modelName, model, source, schema;

		if !fetch modelName, qualifiedName["name"] {
			throw new Exception("Corrupted SELECT AST");
		}

		let model = manager->load(modelName),
			source = model->getSource(),
			schema = model->getSchema();

		if schema {
			return [schema, source];
		}

		return source;
	}

	/**
	 * Resolves a JOIN clause checking if the associated models exist
	 *
	 * @param Phalcon\Mvc\Model\ManagerInterface manager
	 * @param array join
	 * @return array
	 */
	protected final function _getJoin(<ManagerInterface> manager, join) -> array
	{
		var qualified, modelName, realModelName, nsAlias, source, model, schema;

		if fetch qualified, join["qualified"] {

			if qualified["type"] == 355 {

				let modelName = qualified["name"];

				if memstr(modelName, ":") {
					let nsAlias = explode(":", modelName);
					let realModelName = manager->getNamespaceAlias(nsAlias[0]) . "\\" . nsAlias[1];
				} else {
					let realModelName = modelName;
				}

				let model = manager->load(realModelName, true),
					source = model->getSource(),
					schema = model->getSchema();

				return [
					"schema"   : schema,
					"source"   : source,
					"modelName": realModelName,
					"model"    : model
				];
			}
		}

		throw new Exception("Corrupted SELECT AST");
	}

	/**
	 * Resolves a JOIN type
	 *
	 * @param array join
	 * @return string
	 */
	protected final function _getJoinType(join) -> string
	{
		var type;

		if !fetch type, join["type"] {
			throw new Exception("Corrupted SELECT AST");
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

		throw new Exception("Unknown join type " . type . ", when preparing: " . this->_phql);
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
	protected final function _getSingleJoin(string! joinType, joinSource, modelAlias, joinAlias, <RelationInterface> relation) -> array
	{
		var fields, referencedFields, sqlJoinConditions = null,
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
				[
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
				]
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
					throw new Exception("The number of fields must be equal to the number of referenced fields in join " . modelAlias . "-" . joinAlias . ", when preparing: " . this->_phql);
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
	protected final function _getMultiJoin(joinType, joinSource, modelAlias, joinAlias, <RelationInterface> relation) -> array
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
					throw new Exception("The number of fields must be equal to the number of referenced fields in join " . modelAlias . "-" . joinAlias . ", when preparing: " . this->_phql);
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
	protected final function _getJoins(select)
	{
		var models, sqlAliases, sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances,
			modelsInstances, fromModels, sqlJoins, joinModels, joinSources, joinTypes, joinPreCondition,
			joinPrepared, manager, selectJoins, joinItem, joins, joinData, schema, source, model,
			realModelName, completeSource, joinType, aliasExpr, alias, joinAliasName, joinExpr,
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
				realModelName = joinData["modelName"],
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
					throw new Exception("Cannot use '" . alias . "' as join alias because it was already used, when preparing: " . this->_phql);
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
				let joinModels[alias] = realModelName;

				/**
				 * Update model: alias
				 */
				let sqlModelsAliases[realModelName] = alias;

				/**
				 * Update model: model
				 */
				let sqlAliasesModels[alias] = realModelName;

				/**
				 * Update alias: model
				 */
				let sqlAliasesModelsInstances[alias] = model;

				/**
				 * Update model: alias
				 */
				let models[realModelName] = alias;

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
				if isset joinModels[realModelName] {
					throw new Exception("Cannot use '" . realModelName . "' as join alias because it was already used, when preparing: " . this->_phql);
				}

				/**
				 * Set the join type
				 */
				let joinTypes[realModelName] = joinType;

				/**
				 * Update model: source
				 */
				let sqlAliases[realModelName] = source;

				/**
				 * Update model: source
				 */
				let joinModels[realModelName] = source;

				/**
				 * Update model: model
				 */
				let sqlModelsAliases[realModelName] = realModelName;

				/**
				 * Update model: model
				 */
				let sqlAliasesModels[realModelName] = realModelName;

				/**
				 * Update model: model instance
				 */
				let sqlAliasesModelsInstances[realModelName] = model;

				/**
				 * Update model: source
				 */
				let models[realModelName] = source;

				/**
				 * Complete source related to a model
				 */
				let joinSources[realModelName] = completeSource;

				/**
				 * Complete source related to a model
				 */
				let joinPrepared[realModelName] = joinItem;
			}

			let modelsInstances[realModelName] = model;
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

		for fromModelName, _ in fromModels {

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
								throw new Exception("There is more than one relation between models '" . fromModelName . "' and '" . joinModel . "', the join must be done using an alias, when preparing: " . this->_phql);
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
	 * @param array|string $order
	 * @return array
	 */
	protected final function _getOrderClause(order) -> array
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
				if orderSort == PHQL_T_ASC {
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
	protected final function _getGroupClause(group) -> array
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
	 * Returns a processed limit clause for a SELECT statement
	 *
	 * @param array $limit
	 * @return array
	 */
	protected final function _getLimitClause(limitClause) -> array
	{
		var number, offset;
		array limit = [];

		if fetch number, limitClause["number"] {
			let limit["number"] = this->_getExpression(number);
		}

		if fetch offset, limitClause["offset"] {
			let limit["offset"] = this->_getExpression(offset);
		}

		return limit;
	}

	/**
	 * Analyzes a SELECT intermediate code and produces an array to be executed later
	 */
	protected final function _prepareSelect(var ast = null, var merge = null) -> array
	{
		int position;
		var sqlModels, sqlTables, sqlAliases, sqlColumns, select, tables, columns,
			sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances,
			models, modelsInstances, selectedModels, manager, metaData,
			selectedModel, qualifiedName, modelName, nsAlias, realModelName, model,
			schema, source, completeSource, alias, joins, sqlJoins, selectColumns,
			sqlColumnAliases, column, sqlColumn, sqlSelect, distinct, having, where,
			groupBy, order, limit;

		if empty ast {
			let ast = this->_ast;
		}

		if typeof merge == "null" {
			let merge = false;
		}

		if !fetch select, ast["select"] {
			let select = ast;
		}

		if !fetch tables, select["tables"] {
			throw new Exception("Corrupted SELECT AST");
		}

		if !fetch columns, select["columns"] {
			throw new Exception("Corrupted SELECT AST");
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

		if typeof manager != "object" {
			throw new Exception("A models-manager is required to execute the query");
		}

		if typeof metaData != "object" {
			throw new Exception("A meta-data is required to execute the query");
		}

		/**
		 * Processing selected columns
		 */
		for selectedModel in selectedModels {

			let qualifiedName = selectedModel["qualifiedName"],
				modelName = qualifiedName["name"];

			/**
			 * Check if the table have a namespace alias
			 */
			if memstr(modelName, ":") {
				let nsAlias = explode(":", modelName);
				let realModelName = manager->getNamespaceAlias(nsAlias[0]) . "\\" . nsAlias[1];
			} else {
				let realModelName = modelName;
			}

			/**
			 * Load a model instance from the models manager
			 */
			let model = manager->load(realModelName, true);

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
					throw new Exception("Alias '" . alias . "' is already used, when preparing: " . this->_phql);
				}

				let sqlAliases[alias] = alias,
					sqlAliasesModels[alias] = realModelName,
					sqlModelsAliases[realModelName] = alias,
					sqlAliasesModelsInstances[alias] = model;

				/**
				 * Append or convert complete source to an array
				 */
				if typeof completeSource == "array" {
					let completeSource[] = alias;
				} else {
					let completeSource = [source, null, alias];
				}
				let models[realModelName] = alias;

			} else {
				let sqlAliases[realModelName] = source,
					sqlAliasesModels[realModelName] = realModelName,
					sqlModelsAliases[realModelName] = realModelName,
					sqlAliasesModelsInstances[realModelName] = model,
					models[realModelName] = source;
			}

			let sqlModels[] = realModelName,
				sqlTables[] = completeSource,
				modelsInstances[realModelName] = model;
		}

		/**
		 * Assign Models/Tables information
		 */
		if !merge {
			let this->_models = models,
				this->_modelsInstances = modelsInstances,
				this->_sqlAliases = sqlAliases,
				this->_sqlAliasesModels = sqlAliasesModels,
				this->_sqlModelsAliases = sqlModelsAliases,
				this->_sqlAliasesModelsInstances = sqlAliasesModelsInstances,
				this->_modelsInstances = modelsInstances;
		} else {
			let this->_models = array_merge(this->_models, models),
				this->_modelsInstances = array_merge(this->_modelsInstances, modelsInstances),
				this->_sqlAliases = array_merge(this->_sqlAliases, sqlAliases),
				this->_sqlAliasesModels = array_merge(this->_sqlAliasesModels, sqlAliasesModels),
				this->_sqlModelsAliases = array_merge(this->_sqlModelsAliases, sqlModelsAliases),
				this->_sqlAliasesModelsInstances = array_merge(this->_sqlAliasesModelsInstances, sqlAliasesModelsInstances),
				this->_modelsInstances = array_merge(this->_modelsInstances, modelsInstances);
		}

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

		if fetch distinct, select["distinct"] {
			let sqlSelect["distinct"] = distinct;
		}

		if count(sqlJoins) {
			let sqlSelect["joins"] = sqlJoins;
		}

		/**
		 * Process "WHERE" clause if any
		 */
		if fetch where, ast["where"] {
			let sqlSelect["where"] = this->_getExpression(where);
		}

		/**
		 * Process "GROUP BY" clause if any
		 */
		if fetch groupBy, ast["groupBy"] {
			let sqlSelect["group"] = this->_getGroupClause(groupBy);
		}

		/**
		 * Process "HAVING" clause if any
		 */
		if fetch having , ast["having"] {
			let sqlSelect["having"] = this->_getExpression(having);
		}

		/**
		 * Process "ORDER BY" clause if any
		 */
		if fetch order, ast["orderBy"] {
			let sqlSelect["order"] = this->_getOrderClause(order);
		}

		/**
		 * Process "LIMIT" clause if any
		 */
		if fetch limit, ast["limit"] {
			let sqlSelect["limit"] = this->_getLimitClause(limit);
		}

		return sqlSelect;
	}

	/**
	 * Analyzes an INSERT intermediate code and produces an array to be executed later
	 */
	protected final function _prepareInsert() -> array
	{
		var ast, qualifiedName, nsAlias, manager, modelName, model, source, schema,
			exprValues, exprValue, sqlInsert, metaData, fields,
			sqlFields, field, name, realModelName;
		boolean notQuoting;

		let ast = this->_ast;

		if !isset ast["qualifiedName"] {
			throw new Exception("Corrupted INSERT AST");
		}

		if !isset ast["values"] {
			throw new Exception("Corrupted INSERT AST");
		}

		let qualifiedName = ast["qualifiedName"];

		/**
		 * Check if the related model exists
		 */
		if !isset qualifiedName["name"] {
			throw new Exception("Corrupted INSERT AST");
		}

		let manager = this->_manager,
			modelName = qualifiedName["name"];

		/**
		 * Check if the table have a namespace alias
		 */
		if memstr(modelName, ":") {
			let nsAlias = explode(":", modelName);
			let realModelName = manager->getNamespaceAlias(nsAlias[0]) . "\\" . nsAlias[1];
		} else {
			let realModelName = modelName;
		}

		let model = manager->load(realModelName, true),
			source = model->getSource(),
			schema = model->getSchema();

		if schema {
			let source = [schema, source];
		}

		let notQuoting = false,
		    exprValues = [];

		for exprValue in ast["values"] {

			/**
			 * Resolve every expression in the "values" clause
			 */
			let exprValues[] = [
				"type" : exprValue["type"],
				"value": this->_getExpression(exprValue, notQuoting)
			];
		}

		let sqlInsert = [
			"model": modelName,
			"table": source
		];

		let metaData = this->_metaData;

		if fetch fields, ast["fields"] {
			let sqlFields = [];
			for field in fields {

				let name = field["name"];

				/**
				 * Check that inserted fields are part of the model
				 */
				if !metaData->hasAttribute(model, name) {
					throw new Exception("The model '" . modelName . "' doesn't have the attribute '" . name . "', when preparing: " . this->_phql);
				}

				/**
				 * Add the file to the insert list
				 */
				let sqlFields[] = name;
			}

			let sqlInsert["fields"] = sqlFields;
		}

		let sqlInsert["values"] = exprValues;

		return sqlInsert;
	}

	/**
	 * Analyzes an UPDATE intermediate code and produces an array to be executed later
	 */
	protected final function _prepareUpdate() -> array
	{
		var ast, update, tables, values, modelsInstances, models,
			sqlTables, sqlAliases, sqlAliasesModelsInstances, updateTables,
			nsAlias, realModelName, completeSource, sqlModels, manager,
			table, qualifiedName, modelName, model, source, schema, alias,
			sqlFields, sqlValues, updateValues, updateValue, exprColumn, sqlUpdate,
			where, limit;
		boolean notQuoting;

		let ast = this->_ast;

		if !fetch update, ast["update"] {
			throw new Exception("Corrupted UPDATE AST");
		}

		if !fetch tables, update["tables"] {
			throw new Exception("Corrupted UPDATE AST");
		}

		if !fetch values, update["values"] {
			throw new Exception("Corrupted UPDATE AST");
		}

		/**
		 * We use these arrays to store info related to models, alias and its sources. With them we can rename columns later
		 */
		let models = [],
			modelsInstances = [];

		let sqlTables = [],
			sqlModels = [],
			sqlAliases = [],
			sqlAliasesModelsInstances = [];

		if !isset tables[0] {
			let updateTables = [tables];
		} else {
			let updateTables = tables;
		}

		let manager = this->_manager;
		for table in updateTables {

			let qualifiedName = table["qualifiedName"],
				modelName = qualifiedName["name"];

			/**
			 * Check if the table have a namespace alias
			 */
			if memstr(modelName, ":") {
				let nsAlias = explode(":", modelName);
				let realModelName = manager->getNamespaceAlias(nsAlias[0]) . "\\" . nsAlias[1];
			} else {
				let realModelName = modelName;
			}

			/**
			 * Load a model instance from the models manager
			 */
			let model = manager->load(realModelName, true),
				source = model->getSource(),
				schema = model->getSchema();

			/**
			 * Create a full source representation including schema
			 */
			if schema {
				let completeSource = [source, schema];
			} else {
				let completeSource = [source, null];
			}

			/**
			 * Check if the table is aliased
			 */
			if fetch alias, table["alias"] {
				let sqlAliases[alias] = alias,
					completeSource[] = alias,
					sqlTables[] = completeSource,
					sqlAliasesModelsInstances[alias] = model,
					models[alias] = realModelName;
			} else {
				let sqlAliases[realModelName] = source,
					sqlAliasesModelsInstances[realModelName] = model,
					sqlTables[] = source,
					models[realModelName] = source;
			}

			let sqlModels[] = realModelName,
				modelsInstances[realModelName] = model;
		}

		/**
		 * Update the models/alias/sources in the object
		 */
		let this->_models = models,
			this->_modelsInstances = modelsInstances,
			this->_sqlAliases = sqlAliases,
			this->_sqlAliasesModelsInstances = sqlAliasesModelsInstances;

		let sqlFields = [], sqlValues = [];

		if !isset values[0] {
			let updateValues = [values];
		} else {
			let updateValues = values;
		}

		let notQuoting = false;
		for updateValue in updateValues {

			let sqlFields[] = this->_getExpression(updateValue["column"], notQuoting),
				exprColumn = updateValue["expr"],
				sqlValues[] = [
					"type" : exprColumn["type"],
					"value": this->_getExpression(exprColumn, notQuoting)
				];

		}

		let sqlUpdate = [
			"tables": sqlTables,
			"models": sqlModels,
			"fields": sqlFields,
			"values": sqlValues
		];

		if fetch where, ast["where"] {
			let sqlUpdate["where"] = this->_getExpression(where, true);
		}

		if fetch limit, ast["limit"] {
			let sqlUpdate["limit"] = this->_getLimitClause(limit);
		}

		return sqlUpdate;
	}

	/**
	 * Analyzes a DELETE intermediate code and produces an array to be executed later
	 */
	protected final function _prepareDelete() -> array
	{
		var ast, delete, tables, models, modelsInstances,
			sqlTables, sqlModels, sqlAliases, sqlAliasesModelsInstances,
			deleteTables, manager, table, qualifiedName, modelName, nsAlias,
			realModelName, model, source, schema, completeSource, alias,
			sqlDelete, where, limit;

		let ast = this->_ast;

		if !fetch delete, ast["delete"] {
			throw new Exception("Corrupted DELETE AST");
		}

		if !fetch tables, delete["tables"] {
			throw new Exception("Corrupted DELETE AST");
		}

		/**
		 * We use these arrays to store info related to models, alias and its sources. With them we can rename columns later
		 */
		let models = [], modelsInstances = [];

		let sqlTables = [],
			sqlModels = [],
			sqlAliases = [],
			sqlAliasesModelsInstances = [];

		if !isset tables[0] {
			let deleteTables = [tables];
		} else {
			let deleteTables = tables;
		}

		let manager = this->_manager;
		for table in deleteTables {

			let qualifiedName = table["qualifiedName"],
				modelName = qualifiedName["name"];

			/**
			 * Check if the table have a namespace alias
			 */
			/**
			 * Check if the table have a namespace alias
			 */
			if memstr(modelName, ":") {
				let nsAlias = explode(":", modelName);
				let realModelName = manager->getNamespaceAlias(nsAlias[0]) . "\\" . nsAlias[1];
			} else {
				let realModelName = modelName;
			}

			/**
			 * Load a model instance from the models manager
			 */
			let model = manager->load(realModelName, true),
				source = model->getSource(),
				schema = model->getSchema();

			if schema {
				let completeSource = [source, schema];
			} else {
				let completeSource = [source, null];
			}

			if fetch alias, table["alias"] {
				let sqlAliases[alias] = alias,
					completeSource[] = alias,
					sqlTables[] = completeSource,
					sqlAliasesModelsInstances[alias] = model,
					models[alias] = realModelName;
			} else {
				let sqlAliases[realModelName] = source,
					sqlAliasesModelsInstances[realModelName] = model,
					sqlTables[] = source,
					models[realModelName] = source;
			}

			let sqlModels[] = realModelName,
				modelsInstances[realModelName] = model;
		}

		/**
		 * Update the models/alias/sources in the object
		 */
		let this->_models = models,
			this->_modelsInstances = modelsInstances,
			this->_sqlAliases = sqlAliases,
			this->_sqlAliasesModelsInstances = sqlAliasesModelsInstances;

		let sqlDelete = [],
			sqlDelete["tables"] = sqlTables,
			sqlDelete["models"] = sqlModels;

		if fetch where, ast["where"] {
			let sqlDelete["where"] = this->_getExpression(where, true);
		}

		if fetch limit, ast["limit"] {
			let sqlDelete["limit"] = this->_getLimitClause(limit);
		}

		return sqlDelete;
	}

	/**
	 * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang generating another
	 * intermediate representation that could be executed by Phalcon\Mvc\Model\Query
	 */
	public function parse() -> array
	{
		var intermediate, phql, ast, irPhql, uniqueId, type;

		let intermediate = this->_intermediate;
		if typeof intermediate == "array" {
			return intermediate;
		}

		/**
		 * This function parses the PHQL statement
		 */
		let phql = this->_phql,
			ast = phql_parse_phql(phql);

		let irPhql = null, uniqueId = null;

		if typeof ast == "array" {

			/**
			 * Check if the prepared PHQL is already cached
			 * Parsed ASTs have a unique id
			 */
			if fetch uniqueId, ast["id"] {
				if fetch irPhql, self::_irPhqlCache[uniqueId] {
					if typeof irPhql == "array" {
						//Assign the type to the query
						let this->_type = ast["type"];
						return irPhql;
					}
				}
			}

			/**
			 * A valid AST must have a type
			 */
			if fetch type, ast["type"] {

				let this->_ast = ast,
					this->_type = type;

				switch type {

					case PHQL_T_SELECT:
						let irPhql = this->_prepareSelect();
						break;

					case PHQL_T_INSERT:
						let irPhql = this->_prepareInsert();
						break;

					case PHQL_T_UPDATE:
						let irPhql = this->_prepareUpdate();
						break;

					case PHQL_T_DELETE:
						let irPhql = this->_prepareDelete();
						break;

					default:
						throw new Exception("Unknown statement " . type . ", when preparing: " . phql);
				}
			}
		}

		if typeof irPhql != "array" {
			throw new Exception("Corrupted AST");
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
	 */
	public function getCache() -> <BackendInterface>
	{
		return this->_cache;
	}

	/**
	 * Executes the SELECT intermediate representation producing a Phalcon\Mvc\Model\Resultset
	 */
	protected final function _executeSelect(var intermediate, var bindParams, var bindTypes, boolean simulate = false) -> <ResultsetInterface> | array
	{

		var manager, modelName, models, model, connection, connectionTypes,
			columns, column, selectColumns, simpleColumnMap, metaData, aliasCopy,
			sqlColumn, attributes, instance, columnMap, attribute,
			columnAlias, sqlAlias, dialect, sqlSelect,
			processed, wildcard, value, processedTypes, typeWildcard, result,
			resultData, cache, resultObject, columns1;
		boolean haveObjects, haveScalars, isComplex, isSimpleStd, isKeepingSnapshots;
		int numberObjects;

		let manager = this->_manager;

		/**
		 * Get a database connection
		 */
		let connectionTypes = [];
		let models = intermediate["models"];

		for modelName in models {
			/**
			 * Load model if it is not loaded
			 */
			if !fetch model, this->_modelsInstances[modelName] {
				let model = manager->load(modelName, true),
					this->_modelsInstances[modelName] = model;
			}

			/**
			 * Get database connection
			 */
			if method_exists(model, "selectReadConnection") {
				// use selectReadConnection() if implemented in extended Model class
				let connection = model->selectReadConnection(intermediate, bindParams, bindTypes);
				if typeof connection != "object" {
					throw new Exception("'selectReadConnection' didn't return a valid connection");
				}
			} else {
				let connection = model->getReadConnection();
			}

			/**
			 * More than one type of connection is not allowed
			 */
			let connectionTypes[connection->getType()] = true;
			if count(connectionTypes) == 2 {
				throw new Exception("Cannot use models of different database systems in the same query");
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
		let columns1 = columns;

		for column in columns {

			if typeof column != "array" {
				throw new Exception("Invalid column definition");
			}

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
		let instance = null,
			selectColumns = [],
			simpleColumnMap = [],
			metaData = this->_metaData;

		for aliasCopy, column in columns {

			let sqlColumn = column["column"];

			/**
			 * Complete objects are treated in a different way
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
					let columns1[aliasCopy]["instance"] = instance,
						columns1[aliasCopy]["attributes"] = attributes,
						columns1[aliasCopy]["columnMap"] = columnMap;

					/**
					 * Check if the model keeps snapshots
					 */
					let isKeepingSnapshots = (boolean) manager->isKeepingSnapshots(instance);
					if isKeepingSnapshots {
						let columns1[aliasCopy]["keepSnapshots"] = isKeepingSnapshots;
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
			if isComplex === false && isSimpleStd === true {
				if fetch sqlAlias, column["sqlAlias"] {
					let simpleColumnMap[sqlAlias] = aliasCopy;
				} else {
					let simpleColumnMap[aliasCopy] = aliasCopy;
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
				if typeof wildcard == "integer" {
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
				if typeof wildcard == "integer" {
					let processedTypes[":" . typeWildcard] = value;
				} else {
					let processedTypes[typeWildcard] = value;
				}
			}
		} else {
			let processedTypes = bindTypes;
		}

		/**
		 * Return the SQL to be executed instead of execute it
		 */
		if simulate {
			return [
				"sql"       : sqlSelect,
				"bind"      : processed,
				"bindTypes" : processedTypes
			];
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
				let resultObject = new Row();

				/**
				 * Standard objects can"t keep snapshots
				 */
				let isKeepingSnapshots = false;

			} else {

				if typeof instance == "object" {
					let resultObject = instance;
				} else {
					let resultObject = model;
				}

				/**
				 * Get the column map
				 */
				let simpleColumnMap = metaData->getColumnMap(model);

				/**
				 * Check if the model keeps snapshots
				 */
				let isKeepingSnapshots = (boolean) manager->isKeepingSnapshots(model);
			}

			/**
			 * Simple resultsets contains only complete objects
			 */
			return new Simple(simpleColumnMap, resultObject, resultData, cache, isKeepingSnapshots);
		}

		/**
		 * Complex resultsets may contain complete objects and scalars
		 */
		return new Complex(columns1, resultData, cache);
	}

	/**
	 * Executes the INSERT intermediate representation producing a Phalcon\Mvc\Model\Query\Status
	 *
	 * @param array intermediate
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Query\StatusInterface
	 */
	protected final function _executeInsert(var intermediate, var bindParams, var bindTypes) -> <StatusInterface>
	{
		var modelName, manager, connection, metaData, attributes,
			fields, columnMap, dialect, insertValues, number, value, model,
			values, exprValue, insertValue, wildcard, fieldName, attributeName,
			insertModel;
		boolean automaticFields;

		let modelName = intermediate["model"];

		let manager = this->_manager;
		if !fetch model, this->_modelsInstances[modelName] {
			let model = manager->load(modelName, true);
		}

		/**
		 * Get the model connection
		 */
		if method_exists(model, "selectWriteConnection") {
			let connection = model->selectWriteConnection(intermediate, bindParams, bindTypes);
			if typeof connection != "object" {
				throw new Exception("'selectWriteConnection' didn't return a valid connection");
			}
		} else {
			let connection = model->getWriteConnection();
		}

		let metaData = this->_metaData, attributes = metaData->getAttributes(model);

		let automaticFields = false;

		/**
		 * The "fields" index may already have the fields to be used in the query
		 */
		if !fetch fields, intermediate["fields"] {
			let automaticFields = true,
				fields = attributes;
			if globals_get("orm.column_renaming") {
				let columnMap = metaData->getColumnMap(model);
			} else {
				let columnMap = null;
			}
		}

		let values = intermediate["values"];

		/**
		 * The number of calculated values must be equal to the number of fields in the model
		 */
		if count(fields) != count(values) {
			throw new Exception("The column count does not match the values count");
		}

		/**
		 * Get the dialect to resolve the SQL expressions
		 */
		let dialect = connection->getDialect();

		let insertValues = [];
		for number, value in values {

			let exprValue = value["value"];
			switch value["type"] {

				case PHQL_T_STRING:
				case PHQL_T_INTEGER:
				case PHQL_T_DOUBLE:
					let insertValue = dialect->getSqlExpression(exprValue);
					break;

				case PHQL_T_NULL:
					let insertValue = null;
					break;

				case PHQL_T_NPLACEHOLDER:
				case PHQL_T_SPLACEHOLDER:

					if typeof bindParams != "array" {
						throw new Exception("Bound parameter cannot be replaced because placeholders is not an array");
					}

					let wildcard = str_replace(":", "", dialect->getSqlExpression(exprValue));
					if !fetch insertValue, bindParams[wildcard] {
						throw new Exception("Bound parameter '" . wildcard . "' cannot be replaced because it isn't in the placeholders list");
					}

					break;

				default:
					let insertValue = new RawValue(dialect->getSqlExpression(exprValue));
					break;
			}

			let fieldName = fields[number];

			/**
			 * If the user didn't define a column list we assume all the model's attributes as columns
			 */
			if automaticFields === true {
				if typeof columnMap == "array" {
					if !fetch attributeName, columnMap[fieldName] {
						throw new Exception("Column '" . fieldName . "' isn't part of the column map");
					}
				} else {
					let attributeName = fieldName;
				}
			} else {
				let attributeName = fieldName;
			}

			let insertValues[attributeName] = insertValue;
		}

		/**
		 * Get a base model from the Models Manager
		 * Clone the base model
		 */
		let insertModel = clone manager->load(modelName);

		/**
		 * Call 'create' to ensure that an insert is performed
		 * Return the insertation status
		 */
		return new Status(insertModel->create(insertValues), insertModel);
	}

	/**
	 * Executes the UPDATE intermediate representation producing a Phalcon\Mvc\Model\Query\Status
	 *
	 * @param array intermediate
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Query\StatusInterface
	 */
	protected final function _executeUpdate(var intermediate, var bindParams, var bindTypes) -> <StatusInterface>
	{
		var models, modelName, model, connection, dialect,
			fields, values, updateValues, fieldName, value,
			selectBindParams, selectBindTypes, number, field,
			records, exprValue, updateValue, wildcard, record;

		let models = intermediate["models"];

		if isset models[1] {
			throw new Exception("Updating several models at the same time is still not supported");
		}

		let modelName = models[0];

		/**
		 * Load the model from the modelsManager or from the _modelsInstances property
		 */
		if !fetch model, this->_modelsInstances[modelName] {
			let model = this->_manager->load(modelName);
		}

		if method_exists(model, "selectWriteConnection") {
			let connection = model->selectWriteConnection(intermediate, bindParams, bindTypes);
			if typeof connection != "object" {
				throw new Exception("'selectWriteConnection' didn't return a valid connection");
			}
		} else {
			let connection = model->getWriteConnection();
		}

		let dialect = connection->getDialect();

		let fields = intermediate["fields"],
			values = intermediate["values"];

		/**
		 * updateValues is applied to every record
		 */
		let updateValues = [];

		/**
		 * If a placeholder is unused in the update values, we assume that it's used in the SELECT
		 */
		let selectBindParams = bindParams,
			selectBindTypes = bindTypes;

		for number, field in fields {

			let value = values[number],
				exprValue = value["value"];

			if isset field["balias"] {
				let fieldName = field["balias"];
			} else {
				let fieldName = field["name"];
			}

			switch value["type"] {

				case PHQL_T_STRING:
				case PHQL_T_INTEGER:
				case PHQL_T_DOUBLE:
					let updateValue = dialect->getSqlExpression(exprValue);
					break;

				case PHQL_T_NULL:
					let updateValue = null;
					break;

				case PHQL_T_NPLACEHOLDER:
				case PHQL_T_SPLACEHOLDER:

					if typeof bindParams != "array" {
						throw new Exception("Bound parameter cannot be replaced because placeholders is not an array");
					}

					let wildcard = str_replace(":", "", dialect->getSqlExpression(exprValue));
					if fetch updateValue, bindParams[wildcard] {
						unset selectBindParams[wildcard];
						unset selectBindTypes[wildcard];
					} else {
						throw new Exception("Bound parameter '" . wildcard . "' cannot be replaced because it's not in the placeholders list");
					}
					break;

				default:
					let updateValue = new RawValue(dialect->getSqlExpression(exprValue));
					break;
			}

			let updateValues[fieldName] = updateValue;
		}

		/**
		 * We need to query the records related to the update
		 */
		let records = this->_getRelatedRecords(model, intermediate, selectBindParams, selectBindTypes);

		/**
		 * If there are no records to apply the update we return success
		 */
		if !count(records) {
			return new Status(true);
		}

		if method_exists(model, "selectWriteConnection") {
			let connection = model->selectWriteConnection(intermediate, bindParams, bindTypes);
			if typeof connection != "object" {
				throw new Exception("'selectWriteConnection' didn't return a valid connection");
			}
		} else {
			let connection = model->getWriteConnection();
		}

		/**
		 * Create a transaction in the write connection
		 */
		connection->begin();

		for record in iterator(records) {

			/**
			 * We apply the executed values to every record found
			 */
			if !record->update(updateValues) {

				/**
				 * Rollback the transaction on failure
				 */
				connection->rollback();

				return new Status(false, record);
			}
		}

		/**
		 * Commit transaction on success
		 */
		connection->commit();

		return new Status(true);
	}

	/**
	 * Executes the DELETE intermediate representation producing a Phalcon\Mvc\Model\Query\Status
	 *
	 * @param array intermediate
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Query\StatusInterface
	 */
	protected final function _executeDelete(var intermediate, var bindParams, var bindTypes) -> <StatusInterface>
	{
		var models, modelName, model, records, connection, record;

		let models = intermediate["models"];

		if isset models[1] {
			throw new Exception("Delete from several models at the same time is still not supported");
		}

		let modelName = models[0];

		/**
		 * Load the model from the modelsManager or from the _modelsInstances property
		 */
		if !fetch model, this->_modelsInstances[modelName] {
			let model = this->_manager->load(modelName);
		}

		/**
		 * Get the records to be deleted
		 */
		let records = this->_getRelatedRecords(model, intermediate, bindParams, bindTypes);

		/**
		 * If there are no records to delete we return success
		 */
		if !count(records) {
			return new Status(true);
		}

		if method_exists(model, "selectWriteConnection") {
			let connection = model->selectWriteConnection(intermediate, bindParams, bindTypes);
			if typeof connection != "object" {
				throw new Exception("'selectWriteConnection' didn't return a valid connection");
			}
		} else {
			let connection = model->getWriteConnection();
		}

		/**
		 * Create a transaction in the write connection
		 */
		connection->begin();

		for record in iterator(records) {

			/**
			 * We delete every record found
			 */
			if !record->delete() {

				/**
				 * Rollback the transaction
				 */
				connection->rollback();

				return new Status(false, record);
			}
		}

		/**
		 * Commit the transaction
		 */
		connection->commit();

		/**
		 * Create a status to report the deletion status
		 */
		return new Status(true);
	}

	/**
	 * Query the records on which the UPDATE/DELETE operation well be done
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param array intermediate
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\ResultsetInterface
	 */
	protected final function _getRelatedRecords(<ModelInterface> model, var intermediate, var bindParams, var bindTypes)
	 -> <ResultsetInterface>
	{
		var selectIr, whereConditions, limitConditions, query;

		/**
		 * Instead of create a PHQL string statement we manually create the IR representation
		 */
		let selectIr = [
			"columns": [[
				"type"  : "object",
				"model" : get_class(model),
				"column": model->getSource()
			]],
			"models":  intermediate["models"],
			"tables":  intermediate["tables"]
		];

		/**
		 * Check if a WHERE clause was especified
		 */
		if fetch whereConditions, intermediate["where"] {
			let selectIr["where"] = whereConditions;
		}

		/**
		 * Check if a LIMIT clause was especified
		 */
		if fetch limitConditions, intermediate["limit"] {
			let selectIr["limit"] = limitConditions;
		}

		/**
		 * We create another Phalcon\Mvc\Model\Query to get the related records
		 */
		let query = new self();
		query->setDI(this->_dependencyInjector);
		query->setType(PHQL_T_SELECT);
		query->setIntermediate(selectIr);

		return query->execute(bindParams, bindTypes);
	}

	/**
	 * Executes a parsed PHQL statement
	 *
	 * @param array bindParams
	 * @param array bindTypes
	 * @return mixed
	 */
	public function execute(var bindParams = null, var bindTypes = null)
	{
		var uniqueRow, cacheOptions, key, cacheService,
			cache, result, preparedResult, defaultBindParams, mergedParams,
			defaultBindTypes, mergedTypes, type, lifetime, intermediate;

		let uniqueRow = this->_uniqueRow;

		let cacheOptions = this->_cacheOptions;
		if typeof cacheOptions != "null" {

			if typeof cacheOptions != "array" {
				throw new Exception("Invalid caching options");
			}

			/**
			 * The user must set a cache key
			 */
			if !fetch key, cacheOptions["key"] {
				throw new Exception("A cache key must be provided to identify the cached resultset in the cache backend");
			}

			/**
			 * By defaut use use 3600 seconds (1 hour) as cache lifetime
			 */
			if !fetch lifetime, cacheOptions["lifetime"] {
				let lifetime = 3600;
			}

			/**
			 * "modelsCache" is the default name for the models cache service
			 */
			if !fetch cacheService, cacheOptions["service"] {
				let cacheService = "modelsCache";
			}

			let cache = this->_dependencyInjector->getShared(cacheService);
			if typeof cache != "object" {
				throw new Exception("Cache service must be an object");
			}

			let result = cache->get(key, lifetime);
			if result !== null {

				if typeof result != "object" {
					throw new Exception("Cache didn't return a valid resultset");
				}

				result->setIsFresh(false);

				/**
				 * Check if only the first row must be returned
				 */
				if uniqueRow {
					let preparedResult = result->getFirst();
				} else {
					let preparedResult = result;
				}

				return preparedResult;
			}

			let this->_cache = cache;
		}

		/**
		 * The statement is parsed from its PHQL string or a previously processed IR
		 */
		let intermediate = this->parse();

		/**
		 * Check for default bind parameters and merge them with the passed ones
		 */
		let defaultBindParams = this->_bindParams;
		if typeof defaultBindParams == "array" {
			if typeof bindParams == "array" {
				let mergedParams = defaultBindParams + bindParams;
			} else {
				let mergedParams = defaultBindParams;
			}
		} else {
			let mergedParams = bindParams;
		}

		/**
		 * Check for default bind types and merge them with the passed ones
		 */
		let defaultBindTypes = this->_bindTypes;
		if typeof defaultBindTypes == "array" {
			if typeof bindTypes == "array" {
				let mergedTypes = defaultBindTypes + bindTypes;
			} else {
				let mergedTypes = defaultBindTypes;
			}
		} else {
			let mergedTypes = bindTypes;
		}

		if typeof mergedParams != "null" && typeof mergedParams != "array" {
			throw new Exception("Bound parameters must be an array");
		}

		if typeof mergedTypes != "null" && typeof mergedTypes != "array" {
			throw new Exception("Bound parameter types must be an array");
		}

		let type = this->_type;
		switch type {

			case PHQL_T_SELECT:
				let result = this->_executeSelect(intermediate, mergedParams, mergedTypes);
				break;

			case PHQL_T_INSERT:
				let result = this->_executeInsert(intermediate, mergedParams, mergedTypes);
				break;

			case PHQL_T_UPDATE:
				let result = this->_executeUpdate(intermediate, mergedParams, mergedTypes);
				break;

			case PHQL_T_DELETE:
				let result = this->_executeDelete(intermediate, mergedParams, mergedTypes);
				break;

			default:
				throw new Exception("Unknown statement " . type);
		}

		/**
		 * We store the resultset in the cache if any
		 */
		if cacheOptions !== null {

			/**
			 * Only PHQL SELECTs can be cached
			 */
			if type != PHQL_T_SELECT {
				throw new Exception("Only PHQL statements that return resultsets can be cached");
			}

			cache->save(key, result, lifetime);
		}

		/**
		 * Check if only the first row must be returned
		 */
		if uniqueRow {
			let preparedResult = result->getFirst();
		} else {
			let preparedResult = result;
		}

		return preparedResult;
	}

	/**
	 * Executes the query returning the first result
	 *
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Ṕhalcon\Mvc\ModelInterface
	 */
	public function getSingleResult(var bindParams = null, var bindTypes = null)
	{
		/**
		 * The query is already programmed to return just one row
		 */
		if this->_uniqueRow {
			return this->execute(bindParams, bindTypes);
		}

		return this->execute(bindParams, bindTypes)->getFirst();
	}

	/**
	 * Sets the type of PHQL statement to be executed
	 */
	public function setType(int type) -> <Query>
	{
		let this->_type = type;
		return this;
	}

	/**
	 * Gets the type of PHQL statement executed
	 */
	public function getType() -> int
	{
		return this->_type;
	}

	/**
	 * Set default bind parameters
	 */
	public function setBindParams(array! bindParams) -> <Query>
	{
		let this->_bindParams = bindParams;
		return this;
	}

	/**
	 * Returns default bind params
	 *
	 * @return array
	 */
	public function getBindParams()
	{
		return this->_bindParams;
	}

	/**
	 * Set default bind parameters
	 */
	public function setBindTypes(array! bindTypes) -> <Query>
	{
		let this->_bindTypes = bindTypes;
		return this;
	}

	/**
	 * Returns default bind types
	 *
	 * @return array
	 */
	public function getBindTypes()
	{
		return this->_bindTypes;
	}

	/**
	 * Allows to set the IR to be executed
	 */
	public function setIntermediate(array! intermediate) -> <Query>
	{
		let this->_intermediate = intermediate;
		return this;
	}

	/**
	 * Returns the intermediate representation of the PHQL statement
	 *
	 * @return array
	 */
	public function getIntermediate()
	{
		return this->_intermediate;
	}

	/**
	 * Sets the cache parameters of the query
	 */
	public function cache(cacheOptions) -> <Query>
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
	 * Returns the SQL to be generated by the internal PHQL (only works in SELECT statements)
	 */
	public function getSql() -> array
	{
		var intermediate;

		/**
		 * The statement is parsed from its PHQL string or a previously processed IR
		 */
		let intermediate = this->parse();

		if this->_type == PHQL_T_SELECT {
			return this->_executeSelect(intermediate, this->_bindParams, this->_bindTypes, true);
		}

		throw new Exception("This type of statement generates multiple SQL statements");
	}
}
