
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
 *   "name" => "Lamborghini"
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
			 * Resolving left part of the expression if any
			 */
			if fetch exprLeft, expr["left"] {
				let left = this->_getExpression(exprLeft, tempNotQuoting);
			}

			/**
			 * Resolving right part of the expression if any
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
				case 61:
					let exprReturn = ["type": "binary-op", "op": "=", "left": left, "right": right];
					break;
				case 62:
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
				case 266:
					let exprReturn = ["type": "binary-op", "op": "AND", "left": left, "right": right];
					break;
				case 267:
					let exprReturn = ["type": "binary-op", "op": "OR", "left": left, "right": right];
					break;
				case 355:
					let exprReturn = this->_getQualified(expr);
					break;
				case 359:
					//let exprReturn = this->_getAliased(expr);
					break;
				case 43:
					let exprReturn = ["type": "binary-op", "op": "+", "left": left, "right": right];
					break;
				case 45:
					let exprReturn = ["type": "binary-op", "op": "-", "left": left, "right": right];
					break;
				case 42:
					let exprReturn = ["type": "binary-op", "op": "*", "left": left, "right": right];
					break;
				case 47:
					let exprReturn = ["type": "binary-op", "op": "/", "left": left, "right": right];
					break;
				case 37:
					let exprReturn = ["type": "binary-op", "op": "%", "left": left, "right": right];
					break;
				case 38:
					let exprReturn = ["type": "binary-op", "op": "&", "left": left, "right": right];
					break;
				case 124:
					let exprReturn = ["type": "binary-op", "op": "|", "left": left, "right": right];
					break;
				case 356:
					let exprReturn = ["type": "parentheses", "left": left];
					break;
				case 367:
					let exprReturn = ["type": "unary-op", "op": "-", "right": right];
					break;
				case 258:
				case 259:
					let exprReturn = ["type": "literal", "value": expr["value"]];
					break;
				case 333:
					let exprReturn = ["type": "literal", "value": "TRUE"];
					break;
				case 334:
					let exprReturn = ["type": "literal", "value": "FALSE"];
					break;
				case 260:
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
				case 273:
					let exprReturn = ["type": "placeholder", "value": str_replace("?", ":", expr["value"])];
					break;
				case 274:
					let exprReturn = ["type": "placeholder", "value": ":" . expr["value"]];
					break;
				case 322:
					let exprReturn = ["type": "literal", "value": "NULL"];
					break;
				case 268:
					let exprReturn = ["type": "binary-op", "op": "LIKE", "left": left, "right": right];
					break;
				case 351:
					let exprReturn = ["type": "binary-op", "op": "NOT LIKE", "left": left, "right": right];
					break;
				case 275:
					let exprReturn = ["type": "binary-op", "op": "ILIKE", "left": left, "right": right];
					break;
				case 357:
					let exprReturn = ["type": "binary-op", "op": "NOT ILIKE", "left": left, "right": right];
					break;
				case 33:
					let exprReturn = ["type": "unary-op", "op": "NOT ", "right": right];
					break;
				case 365:
					let exprReturn = ["type": "unary-op", "op": " IS NULL", "left": left];
					break;
				case 366:
					let exprReturn = ["type": "unary-op", "op": " IS NOT NULL", "left": left];
					break;
				case 315:
					let exprReturn = ["type": "binary-op", "op": "IN", "left": left, "right": right];
					break;
				case 323:
					let exprReturn = ["type": "binary-op", "op": "NOT IN", "left": left, "right": right];
					break;
				case 330:
					let exprReturn = ["type": "unary-op", "op": "DISTINCT ", "right": right];
					break;
				case 331:
					let exprReturn = ["type": "binary-op", "op": "BETWEEN", "left": left, "right": right];
					break;
				case 276:
					let exprReturn = ["type": "binary-op", "op": "AGAINST", "left": left, "right": right];
					break;
				case 332:
					let exprReturn = ["type": "cast", "left": left, "right": right];
					break;
				case 335:
					let exprReturn = ["type": "convert", "left": left, "right": right];
					break;
				case 358:
					let exprReturn = ["type": "literal", "value": expr["name"]];
					break;
				case 350:
					let exprReturn = this->_getFunctionCall(expr);
					break;
				default:
					throw new Phalcon\Mvc\Model\Exception("Unknown expression type " . exprType);
			}

			return exprReturn;
		}

		/**
		 * Is a qualified column
		 */
		if isset expr["domain"] {
			return this->_getQualified(expr);
		}

		/**
		 * Is the expression doesn't have a type it's a list of nodes
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
