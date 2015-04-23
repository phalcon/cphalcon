
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
 |          Stanislav Kiryukhin <korsar.zn@gmail.com>                     |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Db;

use Phalcon\Db\Exception;

/**
 * Phalcon\Db\Dialect
 *
 * This is the base class to each database dialect. This implements
 * common methods to transform intermediate code into its RDBM related syntax
 */
abstract class Dialect
{

	protected _escapeChar;

	/**
	 * Generates the SQL for LIMIT clause
	 *
	 *<code>
	 * $sql = $dialect->limit('SELECT * FROM robots', 10);
	 * echo $sql; // SELECT * FROM robots LIMIT 10
	 *</code>
	 */
	public function limit(string! sqlQuery, int number) -> string
	{
		if is_numeric(number) {
			return sqlQuery . " LIMIT " . number;
		}
		return sqlQuery;
	}

	/**
	 * Returns a SQL modified with a FOR UPDATE clause
	 *
	 *<code>
	 * $sql = $dialect->forUpdate('SELECT * FROM robots');
	 * echo $sql; // SELECT * FROM robots FOR UPDATE
	 *</code>
	 */
	public function forUpdate(string! sqlQuery) -> string
	{
		return sqlQuery . " FOR UPDATE";
	}

	/**
	 * Returns a SQL modified with a LOCK IN SHARE MODE clause
	 *
	 *<code>
	 * $sql = $dialect->sharedLock('SELECT * FROM robots');
	 * echo $sql; // SELECT * FROM robots LOCK IN SHARE MODE
	 *</code>
	 */
	public function sharedLock(string! sqlQuery) -> string
	{
		return sqlQuery . " LOCK IN SHARE MODE";
	}

	/**
	 * Gets a list of columns with escaped identifiers
	 *
	 *<code>
	 * echo $dialect->getColumnList(array('column1', 'column'));
	 *</code>
	 */
	public final function getColumnList(array! columnList) -> string
	{
		var strList, escapeChar, column;
		let strList = [],
			escapeChar = this->_escapeChar;
		for column in columnList {
			let strList[] = escapeChar . column . escapeChar;
		}
		return join(", ", strList);
	}

	/**
	 * Transforms an intermediate representation for a expression into a database system valid expression
	 */
	public function getSqlExpression(array! expression, var escapeChar = null) -> string
	{
		var type;
		
		if globals_get("db.escape_identifiers") {
			if escapeChar === null{
				let escapeChar = (string) this->_escapeChar;
			}
		}

		if !fetch type, expression["type"] {
			throw new Exception("Invalid SQL expression");
		}

		switch type {

			/**
			 * Resolve scalar column expressions
			 */
			case "scalar":
				return this->getSqlExpressionScalar(expression, escapeChar);

			/**
			 * Resolve object expressions
			 */
			case "object":
				return this->getSqlExpressionObject(expression, escapeChar);

			/**
			 * Resolve qualified expressions
			 */
			case "qualified":
				return this->getSqlExpressionQualified(expression, escapeChar);

			/**
			 * Resolve literal OR placeholder expressions
			 */
			case "literal":
			case "placeholder":
				return expression["value"];

			/**
			 * Resolve binary operations expressions
			 */
			case "binary-op":
				return this->getSqlExpressionBinaryOperations(expression, escapeChar);

			/**
			 * Resolve unary operations expressions
			 */
			case "unary-op":
				return this->getSqlExpressionUnaryOperations(expression, escapeChar);

			/**
			 * Resolve parentheses
			 */
			case "parentheses":
				return "(" . this->getSqlExpression(expression["left"], escapeChar) . ")";

			/**
			 * Resolve function calls
			 */
			case "functionCall":
				return this->getSqlExpressionFunctionCall(expression, escapeChar);

			/**
			 * Resolve lists
			 */
			case "list":
				return this->getSqlExpressionLists(expression, escapeChar);

			/**
			 * Resolve *
			 */
			case "all":
				return this->getSqlExpressionAll(expression, escapeChar);

			/**
			 * Resolve CAST of values
			 */
			case "cast":
				return this->getSqlExpressionCastValue(expression, escapeChar);

			/**
			 * Resolve CONVERT of values encodings
			 */
			case "convert":
				return this->getSqlExpressionConvertValue(expression, escapeChar);	
		}
		
		/**
		 * Expression type wasn't found
		 */
		throw new Exception("Invalid SQL expression type '" . type . "'");
	}

	/**
	 * Transform an intermediate representation of a schema/table into a database system valid expression
	 */
	public final function getSqlTable(var table, string escapeChar = null) -> string
	{
		array tableExpression;
		let tableExpression = [
			"type": "scalar",
			"column": [
				"type": "qualified"
				"name": table,
			]
		];

		if typeof table == "array" {
			/**
			 * The index "0" is the table name
			 */
			if isset table[0] {
				let tableExpression["column"]["name"] = table[0];
			}

			/**
			 * The index "1" is the schema name
			 */
			if isset table[1] {
				let tableExpression["column"]["domain"] = table[1];
			}

			/**
			 * The index "2" is the table alias
			 */
			if isset table[2] {
				tableExpression["sqlAlias"] = table[2];
			}
		}

		if escapeChar === null{
			let escapeChar = (string) this->_escapeChar;
		}

		/**
		 * Resolve table SQL
		 */
		return this->getSqlExpression(tableExpression, escapeChar);
	}

	/**
	 * Transform an intermediate representation of a schema/columns into a database system valid expression
	 */
	public final function getSqlColumn(array! column, string escapeChar = null) -> string
	{
		array columnExpression;
		let columnExpression = column;

		if !isset column["type"] {

			let tableExpression = [
				"type": "scalar",
				"column": null
			];

			/**
			 * The index "0" is the column field
			 */
			if typeof column[0] == "array" {
				let tableExpression["column"] = column[0];
			} elseif column[0] == "*" {
				let columnExpression["column"] = [
					"type": "all"
				];
			} else {
				let columnExpression["column"] = [
					"type": "qualified",
					"name": column[0],
				];
			}

			/**
			 * The index "1" is the domain column
			 */
			if isset column[1] {
				if typeof column[0] == "array" {
					let columnExpression["domain"] = column[1];
				} else {
					let columnExpression["column"]["domain"] = column[1];
				}
			}

			/**
			 * The index "2" is the column alias
			 */
			if !empty column[2] {
				let columnExpression["sqlAlias"] = column[2];
			}
		}

		/**
		 * Resolve column SQL
		 */
		return this->getSqlExpression(columnExpression, escapeChar);
	}

	/**
	 * Builds a SELECT statement
	 */
	public function select(array! definition) -> string
	{
		var tables, columns, escapeChar, selectedTables, sqlJoin, joinExpressions, joinCondition,
			joinConditionsArray, tablesSql, columnsSql, table, sql, joins, join, sqlTable, whereConditions,
			groupFields, groupField, groupItems, havingConditions,
			orderFields, orderItem, orderItems, orderSqlItem, sqlOrderType,
			orderSqlItemType, limitValue, limitNumber, limitNumberValue, offset, offsetNumber;

		if !fetch tables, definition["tables"] {
			throw new Exception("The index 'tables' is required in the definition array");
		}

		if !fetch columns, definition["columns"] {
			throw new Exception("The index 'columns' is required in the definition array");
		}

		if globals_get("db.escape_identifiers") {
			let escapeChar = this->_escapeChar;
		} else {
			let escapeChar = null;
		}

		/**
		 * Resolve SQL columns
		 */
		if typeof columns == "array" {

			array selectedColumns = [];
			var column;

			for column in columns {
				let selectedColumns[] = this->getSqlColumn(column, escapeChar);
			}

			let columnsSql = join(", ", selectedColumns);
		} else {
			let columnsSql = columns;
		}

		/**
		 * Check and escape tables
		 */
		if typeof tables == "array" {
			let selectedTables = [];
			for table in tables {
				let selectedTables[] = this->getSqlTable(table, escapeChar);
			}
			let tablesSql = join(", ", selectedTables);
		} else {
			let tablesSql = tables;
		}

		let sql = "SELECT " . columnsSql . " FROM " . tablesSql;

		/**
		 * Check for joins
		 */
		if fetch joins, definition["joins"] {
			for join in joins {

				let sqlTable = this->getSqlTable(join["source"], escapeChar),
					selectedTables[] = sqlTable,
					sqlJoin = " " . join["type"] . " JOIN " . sqlTable;

				/**
				 * Check if the join has conditions
				 */
				if fetch joinConditionsArray, join["conditions"] {
					if count(joinConditionsArray) {
						if !isset joinConditionsArray[0] {
							let sqlJoin .= " ON " . this->getSqlExpression(joinConditionsArray, escapeChar) . " ";
						} else {
							let joinExpressions = [];
							for joinCondition in joinConditionsArray {
								let joinExpressions[] = this->getSqlExpression(joinCondition, escapeChar);
							}
							let sqlJoin .= " ON " . join(" AND ", joinExpressions) . " ";
						}
					}
				}
				let sql .= sqlJoin;
			}
		}

		/**
		 * Check for a WHERE clause
		 */
		if fetch whereConditions, definition["where"] {
			if typeof whereConditions == "array" {
				let sql .= " WHERE " . this->getSqlExpression(whereConditions, escapeChar);
			} else {
				let sql .= " WHERE " . whereConditions;
			}
		}

		/**
		 * Check for a GROUP clause
		 */
		if fetch groupFields, definition["group"]{

			let groupItems = [];
			for groupField in groupFields {
				if typeof groupField == "array" {
					let groupItems[] = this->getSqlExpression(groupField, escapeChar);
				} else {
					throw new Exception("?");
				}
			}
			let sql .= " GROUP BY " . join(", ", groupItems);

			/**
			 * Check for a HAVING clause
			 */
			if fetch havingConditions, definition["having"] {
				if typeof havingConditions == "array" {
					let sql .= " HAVING " . this->getSqlExpression(havingConditions, escapeChar);
				} else {
					throw new Exception("?");
				}
			}
		}

		/**
		 * Check for a ORDER clause
		 */
		if fetch orderFields, definition["order"]{
			let orderItems = [];
			for orderItem in orderFields {

				if typeof orderItem == "array" {
					let orderSqlItem = this->getSqlExpression(orderItem[0], escapeChar);
				} else {
					throw new Exception("?");
				}

				/**
				 * In the numeric 1 position could be a ASC/DESC clause
				 */
				if fetch sqlOrderType, orderItem[1] {
					let orderSqlItemType = orderSqlItem . " " . sqlOrderType;
				} else {
					let orderSqlItemType = orderSqlItem;
				}

				let orderItems[] = orderSqlItemType;
			}
			let sql .= " ORDER BY " . join(", ", orderItems);
		}

		/**
		 * Check for a LIMIT condition
		 */
		if fetch limitValue, definition["limit"] {

			if typeof limitValue == "array" {

				let limitNumberValue = limitValue["number"];
				if typeof limitNumberValue == "array" {
					let limitNumber = this->getSqlExpression(limitNumberValue, escapeChar);
				} else {
					let limitNumber = limitNumberValue;
				}

				/**
				 * Check for a OFFSET condition
				 */
				if fetch offset, limitValue["offset"] {
					if typeof offset == "array" {
						let offsetNumber = this->getSqlExpression(offset, escapeChar);
					} else {
						let offsetNumber = offset;
					}
					let sql .= " LIMIT " . limitNumber . " OFFSET " . offsetNumber;
				} else {
					let sql .= " LIMIT " . limitNumber;
				}
			} else {
				let sql .= " LIMIT " . limitValue;
			}
		}

		return sql;
	}

	/**
	 * Checks whether the platform supports savepoints
	 */
	public function supportsSavepoints() -> boolean
	{
		return true;
	}

	/**
	 * Checks whether the platform supports releasing savepoints.
	 */
	public function supportsReleaseSavepoints() -> boolean
	{
		return this->supportsSavePoints();
	}

	/**
	 * Generate SQL to create a new savepoint
	 */
	public function createSavepoint(string! name) -> string
	{
		return "SAVEPOINT " . name;
	}

	/**
	 * Generate SQL to release a savepoint
	 */
	public function releaseSavepoint(string! name) -> string
	{
		return "RELEASE SAVEPOINT " . name;
	}

	/**
	 * Generate SQL to rollback a savepoint
	 */
	public function rollbackSavepoint(string! name) -> string
	{
		return "ROLLBACK TO SAVEPOINT " . name;
	}

	/**
	 * Resolve scalar expressions
	 */
	protected final function getSqlExpressionScalar(array! expression, string escapeChar = null) -> string
	{
		if escapeChar === null && globals_get("db.escape_identifiers") {
			let escapeChar = (string) this->_escapeChar;
		}

		var column, domain, columnAlias, columnSql, columnAliasSql;
		let column = expression["column"];

		/**
		 * Resolve column SQL
		 */
		let columnSql = this->getSqlExpression(column);

		/**
		 * Escape domain and concatenate to column SQL
		 */
		if fetch domain, expression["domain"] && domain {
			if globals_get("db.escape_identifiers") {
				let domain = escapeChar . domain . escapeChar;
			}

			let columnSql = domain . "." . columnSql;
		}

		/**
		 * Escape alias and concatenate to column SQL
		 */
		if fetch columnAlias, expression["sqlAlias"] && columnAlias {
			if globals_get("db.escape_identifiers") {
				let columnAliasSql = escapeChar . columnAlias . escapeChar;
			} else {
				let columnAliasSql = columnAlias;
			}

			if column["type"] != "qualified" || columnAlias != column["name"] {
				let columnSql = columnSql . " AS " . columnAliasSql;
			}
		}

		return columnSql;
	}

	/**
	 * Resolve qualified expressions
	 */
	protected final function getSqlExpressionQualified(array! expression, string escapeChar = null) -> string
	{
		var column, domain;
		let column = expression["name"];
		
		if column != "*" && globals_get("db.escape_identifiers") {
			let column = escapeChar . column . escapeChar;
		}

		/**
		 * A domain could be a table/schema
		 */
		if fetch domain, expression["domain"] && domain {
			if globals_get("db.escape_identifiers") {
				return escapeChar . domain . escapeChar . "." . column;
			} else {
				return domain . "." . column;
			}
		}

		return column;
	}

	/**
	 * Resolve object expressions
	 */
	protected final function getSqlExpressionObject(array! expression, string escapeChar = null) -> string
	{
		return this->getSqlExpression([
			"type": "all",
			"domain": expression["balias"]
		], escapeChar);
	}

	/**
	 * Resolve binary operations expressions
	 */
	protected final function getSqlExpressionBinaryOperations(array! expression, string escapeChar = null) -> string
	{
		var left, right;

		let left  = this->getSqlExpression(expression["left"], escapeChar),
			right = this->getSqlExpression(expression["right"], escapeChar);

		return left . " " . expression["op"] . " " . right;
	}

	/**
	 * Resolve unary operations expressions
	 */
	protected final function getSqlExpressionUnaryOperations(array! expression, string escapeChar = null) -> string
	{
		var left, right;

		/**
		 * Some unary operators use the left operand...
		 */
		if fetch left, expression["left"] {
			return this->getSqlExpression(left, escapeChar) . expression["op"];
		}

		/**
		 * ...Others use the right operand
		 */
		if fetch right, expression["right"] {
			return expression["op"] . this->getSqlExpression(right, escapeChar);
		}

		throw new Exception("Invalid SQL-unary expression");
	}
	
	/**
	 * Resolve function calls
	 */
	protected final function getSqlExpressionFunctionCall(array! expression, string escapeChar = null) -> string
	{
		var arguments, argument;
		array sqlArguments = [];
		
		if fetch arguments, expression["arguments"] {
			for argument in arguments {
				let sqlArguments[] = this->getSqlExpression(argument, escapeChar);
			}
			
			return expression["name"] . "(" . join(", ", sqlArguments) . ")";
		}
		
		return expression["name"] . "()";
	}
	
	/**
	 * Resolve Lists
	 */
	protected final function getSqlExpressionLists(array! expression, string escapeChar = null) -> string
	{
		var item;
		array sqlItems = [];
		
		for item in expression[0] {
			let sqlItems[] = this->getSqlExpression(item, escapeChar);
		}
		
		return "(" . join(", ", sqlItems) . ")";
	}

	/**
	 * Resolve *
	 */
	protected final function getSqlExpressionAll(array! expression, string escapeChar = null) -> string
	{
		var domain;

		if fetch domain, expression["domain"] && domain {
			if globals_get("db.escape_identifiers") {
				return escapeChar . domain . escapeChar . ".*";
			} else {
				return domain . ".*";
			}
		}

		return "*";
	}
	
	/**
	 * Resolve CAST of values
	 */
	protected final function getSqlExpressionCastValue(array! expression, string escapeChar = null) -> string
	{
		var left, right;
	
		let left = this->getSqlExpression(expression["left"], escapeChar),
			right = this->getSqlExpression(expression["right"], escapeChar);
		
		return "CAST(" . left . " AS " . right . ")";
	}
	
	/**
	 * Resolve CONVERT of values encodings
	 */
	protected final function getSqlExpressionConvertValue(array! expression, string escapeChar = null) -> string
	{
		var left, right;
	
		let left = this->getSqlExpression(expression["left"], escapeChar),
			right = this->getSqlExpression(expression["right"], escapeChar);
		
		return "CONVERT(" . left . " USING " . right . ")";
	}
}
