
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
 * common methods to transform intermediate code into its RDBMS related syntax
 */
abstract class Dialect implements DialectInterface
{

	protected _escapeChar;

	/**
	 * Generates the SQL for LIMIT clause
	 *
	 * <code>
	 *    $sql = $dialect->limit('SELECT * FROM robots', 10);
	 *    echo $sql; // SELECT * FROM robots LIMIT 10
	 *    
	 *    $sql = $dialect->limit('SELECT * FROM robots', 10, 300);
     *    echo $sql; // SELECT * FROM robots LIMIT 10 OFFSET 300
	 * </code>
	 */
	public function limit(string! sql, var limit, var offset = null) -> string
	{
		var limitSql;

		if limit != "" {

			let limitSql = " LIMIT " . limit;

			if offset != "" {
				let limitSql .= " OFFSET " . offset;
			}

			return sql . limitSql;

		} else {
			return sql;
		}
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
		var columns, column;
		let columns = [];

		for column in columnList {
			let columns[] = this->getSqlColumn(column);
		}

		return join(", ", columns);
	}

	/**
	 * Transforms an intermediate representation for a expression into a database system valid expression
	 */
	public function getSqlExpression(array! expression, string escapeChar = null) -> string
	{
		var type;

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
				return this->getSqlExpressionList(expression, escapeChar);

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
		return this->getSqlExpression([
			"type": "scalar",
			"table": table
		], escapeChar);
	}


	/**
	 * Transform an intermediate representation of a schema/columns into a database system valid expression
	 */
	public final function getSqlColumn(var column, string escapeChar = null) -> string
	{
		if typeof column != "array" {
			return this->escape(column, escapeChar);
		}

		return this->getSqlExpression([
			"type": "scalar",
			"column": column
		], escapeChar);
	}

	/**
	 * Builds a SELECT statement
	 */
	public function select(array! definition) -> string
	{
		var tables, columns, sql;
		var distinct, joins, where, groupBy, having, orderBy, limit;

		if !fetch tables, definition["tables"] {
			throw new Exception("The index 'tables' is required in the definition array");
		}

		if !fetch columns, definition["columns"] {
			throw new Exception("The index 'columns' is required in the definition array");
		}

		if fetch distinct, definition["distinct"] && distinct {

			if distinct {
				let sql = "SELECT DISTINCT";
			} else {
				let sql = "SELECT ALL";
			}

		} else {
			let sql = "SELECT";
		}

		/**
		 * Resolve COLUMNS
		 */
		let sql .= " " . this->getColumnList(columns);

		/**
		 * Resolve FROM
		 */
		let sql .= " " . this->getSqlExpressionFrom(tables);

		/**
		 * Resolve JOINs
		 */
		if fetch joins, definition["joins"] && joins {
			let sql .= " " . this->getSqlExpressionJoins(definition["joins"]);
		}

		/**
		 * Resolve WHERE
		 */
		if fetch where, definition["where"] && where {
			let sql .= " " . this->getSqlExpressionWhere(where);
		}

		/**
		 * Resolve GROUP BY
		 */
		if fetch groupBy, definition["group"] && groupBy {
			let sql .= " " . this->getSqlExpressionGroupBy(groupBy);
		}

		/**
		 * Resolve HAVING
		 */
		if fetch having, definition["having"] && having {
			let sql .= " " . this->getSqlExpressionHaving(having);
		}

		/**
		 * Resolve ORDER BY
		 */
		if fetch orderBy, definition["order"] && orderBy {
			let sql .= " " . this->getSqlExpressionOrderBy(orderBy);
		}

		/**
		 * Resolve LIMIT
		 */
		if fetch limit, definition["limit"] && limit {
			
			var number, offset = null;
	
			if typeof limit == "array" {
	
				if typeof limit["number"] == "array" {
					let number = this->getSqlExpression(limit["number"]);
				} else {
					let number = limit["number"];
				}

				/**
				 * Check for a OFFSET condition
				 */
				if fetch offset, limit["offset"] && typeof offset == "array" {
					let offset = this->getSqlExpression(offset);
				}

			} else {
				let number = limit;
			}

			let sql = this->limit(sql, number, offset);
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
	 * Escape identifiers
	 */
	public final function escape(string! str, string escapeChar = null) -> string
	{
		if str == "" || str == "*" || !globals_get("db.escape_identifiers") {
			return str;
		}

		if escapeChar == "" {
			let escapeChar = (string) this->_escapeChar;
		}

		return escapeChar . str . escapeChar;
	}

	/**
	 * Resolve scalar expressions
	 */
	protected final function getSqlExpressionScalar(array! expression, string escapeChar = null) -> string
	{
		if isset expression["column"] {
			return this->getSqlExpressionScalarColumn(expression, escapeChar);
		}

		if isset expression["table"] {
			return this->getSqlExpressionScalarTable(expression, escapeChar);
		}

		if isset expression["value"] {
			return this->getSqlExpressionScalarValue(expression, escapeChar);
		}

		throw new Exception("Invalid Scalar expression");
	}

	/**
	 * Resolve Column expressions
	 */
	protected final function getSqlExpressionScalarColumn(array! expression, string escapeChar = null) -> string
	{
		var column, columnExpression, columnAlias;
		let columnExpression = expression["column"];

		if !isset columnExpression["type"] {

			var columnField, columnDomain;
			let column = columnExpression;

			/**
			 * The index "0" is the column field
			 */
			let columnField = column[0];

			if typeof columnField == "array" {
				let columnExpression = [
					"type": "scalar",
					"value": columnField
				];

			} elseif columnField == "*" {
				let columnExpression = [
					"type": "all"
				];

			} else {
				let columnExpression = [
					"type": "qualified",
					"name": columnField
				];
			}

			/**
			 * The index "1" is the domain column
			 */
			if fetch columnDomain, column[1] && columnDomain != "" {
				let columnExpression["domain"] = columnDomain;
			}

			/**
			 * The index "2" is the column alias
			 */
			if fetch columnAlias, column[2] && columnAlias {
				let columnExpression["sqlAlias"] = columnAlias;
			}
		}

		/**
		 * Resolve column expressions
		 */
		let column = this->getSqlExpression(columnExpression);

		/**
		 * Escape alias and concatenate to value SQL
		 */
		if fetch columnAlias, columnExpression["sqlAlias"] || fetch columnAlias, columnExpression["alias"] {
			return this->prepareColumn(column, columnAlias);
		} else {
			return this->prepareColumn(column);
		}
	}

	/**
	 * Resolve Table expressions
	 */
	protected final function getSqlExpressionScalarTable(array! expression, string escapeChar = null) -> string
	{
		var table;
		let table = expression["table"];

		if typeof table == "array" {

			var tableName, schemaName, aliasName;

			/**
			 * The index "0" is the table name
			 */
			let tableName = table[0];

			/**
			 * The index "1" is the schema name
			 */
			if !fetch schemaName, table[1] {
				let schemaName = null;
			}

			/**
			 * The index "2" is the table alias
			 */
			if !fetch aliasName, table[2] {
				let aliasName = null;
			}

			return this->prepareTable(tableName, schemaName, aliasName);
		} else {
			return table;
		}
	}

	/**
	 * Resolve Column expressions
	 */
	protected final function getSqlExpressionScalarValue(array! expression, string escapeChar = null) -> string
	{
		var value;

		if typeof expression["value"] == "array" {
			let value = this->getSqlExpression(expression["value"], escapeChar);
		} else {
			let value = expression["value"];
		}

		return value;
	}

	/**
	 * Resolve object expressions
	 */
	protected final function getSqlExpressionObject(array! expression, string escapeChar = null) -> string
	{
		var domain = null, objectExpression;

		let objectExpression = [
			"type": "all"
		];

		if (fetch domain, expression["balias"] || fetch domain, expression["domain"]) && domain != "" {
			let objectExpression["domain"] = domain;
		}

		return this->getSqlExpression(objectExpression, escapeChar);
	}

	/**
	 * Resolve qualified expressions
	 */
	protected final function getSqlExpressionQualified(array! expression, string escapeChar = null) -> string
	{
		var column, domain;
		let column = expression["name"];

		/**
		 * A domain could be a table/schema
		 */
		if !fetch domain, expression["domain"] {
			let domain = null;
		}

		return this->prepareQualified(column, domain);
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
			return this->getSqlExpression(left, escapeChar) . " " . expression["op"];
		}

		/**
		 * ...Others use the right operand
		 */
		if fetch right, expression["right"] {
			return expression["op"] . " " . this->getSqlExpression(right, escapeChar);
		}

		throw new Exception("Invalid SQL-unary expression");
	}

	/**
	 * Resolve function calls
	 */
	protected final function getSqlExpressionFunctionCall(array! expression, string escapeChar = null) -> string
	{
		var arguments;

		if fetch arguments, expression["arguments"] && typeof arguments == "array" {

			let arguments = this->getSqlExpression([
				"type": "list",
				"parentheses": false,
				"value": arguments
			], escapeChar);

			return expression["name"] . "(" . arguments . ")";
		}

		return expression["name"] . "()";
	}

	/**
	 * Resolve Lists
	 */
	protected final function getSqlExpressionList(array! expression, string escapeChar = null) -> string
	{
		var items, item, values, separator;

		let items = [];
		let separator = ", ";

		if isset expression["separator"] {
			let separator = expression["separator"];
		}

		if (fetch values, expression[0] || fetch values, expression["value"]) && typeof values == "array" {

			for item in values {
				let items[] = this->getSqlExpression(item, escapeChar);
			}

			if isset expression["parentheses"] && expression["parentheses"] === false {
				return join(separator, items);
			} else {
				return "(" . join(separator, items) . ")";
			}
		}

		throw new Exception("Invalid SQL-list expression");
	}

	/**
	 * Resolve *
	 */
	protected final function getSqlExpressionAll(array! expression, string escapeChar = null) -> string
	{
		var domain;

		if !fetch domain, expression["domain"] {
			let domain = null;
		}

		return this->prepareQualified("*", domain);
	}

	/**
	 * Resolve CAST of values
	 */
	protected final function getSqlExpressionCastValue(array! expression, string escapeChar = null) -> string
	{
		var left, right;

		let left  = this->getSqlExpression(expression["left"], escapeChar),
			right = this->getSqlExpression(expression["right"], escapeChar);

		return "CAST(" . left . " AS " . right . ")";
	}

	/**
	 * Resolve CONVERT of values encodings
	 */
	protected final function getSqlExpressionConvertValue(array! expression, string escapeChar = null) -> string
	{
		var left, right;

		let left  = this->getSqlExpression(expression["left"], escapeChar),
			right = this->getSqlExpression(expression["right"], escapeChar);

		return "CONVERT(" . left . " USING " . right . ")";
	}

	/**
	 * Resolve a FROM clause
	 */
	protected final function getSqlExpressionFrom(var expression, string escapeChar = null) -> string
	{
		var table, tables;

		if typeof expression == "array" {

			let tables = [];

			for table in expression {
				let tables[] = this->getSqlTable(table);
			}

			let tables = join(", ", tables);

		} else {
			let tables = expression;
		}

		return "FROM " . tables;
	}

	/**
	 * Resolve a JOINs clause
	 */
	protected final function getSqlExpressionJoins(var expression, string escapeChar = null) -> string
	{
		var join, sql = "", joinCondition, joinTable, joinType = "", joinConditionsArray;

		for join in expression {

			/**
			 * Check if the join has conditions
			 */
			if fetch joinConditionsArray, join["conditions"] && !empty joinConditionsArray {

				if !isset joinConditionsArray[0] {
					let joinCondition = this->getSqlExpression(joinConditionsArray, escapeChar);
				} else {

					var condition;
					let joinCondition = [];

					for condition in joinConditionsArray {
						let joinCondition[] = this->getSqlExpression(condition, escapeChar);
					}

					let joinCondition = join(" AND ", joinCondition);
				}
			} else {
				let joinCondition = 1;
			}

			if fetch joinType, join["type"] && joinType {
				let joinType .= " ";
			}

			let joinTable = this->getSqlTable(join["source"], escapeChar);

			let sql .= " " . joinType . "JOIN " . joinTable . " ON " . joinCondition;
		}

		return sql;
	}


	/**
	 * Resolve a WHERE clause
	 */
	protected final function getSqlExpressionWhere(var expression, string escapeChar = null) -> string
	{
		var whereSql;

		if typeof expression == "array" {
			let whereSql = this->getSqlExpression(expression, escapeChar);
		} else {
			let whereSql = expression;
		}

		return "WHERE " . whereSql;
	}

	/**
	 * Resolve a GROUP BY clause
	 */
	protected final function getSqlExpressionGroupBy(var expression, string escapeChar = null) -> string
	{
		var filed, fields;

		if typeof expression == "array" {

			let fields = [];

			for filed in expression {
				if unlikely typeof filed != "array" {
					throw new Exception("Invalid SQL-GROUP-BY expression");
				} else {
					let fields[] = this->getSqlExpression(filed, escapeChar);
				}
			}

			let fields = join(", ", fields);

		} else {
			let fields = expression;
		}

		return  "GROUP BY " . fields;
	}

	/**
	 * Resolve a HAVING clause
	 */
	protected final function getSqlExpressionHaving(var expression, string escapeChar = null) -> string
	{
		if typeof expression == "array" {
			return "HAVING " . this->getSqlExpression(expression, escapeChar);
		} else {
			throw new Exception("Invalid SQL-HAVING expression");
		}
	}

	/**
	* Resolve a ORDER BY clause
	*/
	protected final function getSqlExpressionOrderBy(var expression, string escapeChar = null) -> string
	{
		var filed, fields, type, fieldSql = null;

		if typeof expression == "array" {

			let fields = [];

			for filed in expression {

				if unlikely typeof filed != "array" {
					throw new Exception("Invalid SQL-ORDER-BY expression");
				} else {
					let fieldSql = this->getSqlExpression(filed[0], escapeChar);
				}

				/**
				 * In the numeric 1 position could be a ASC/DESC clause
				 */
				if fetch type, filed[1] && type != "" {
					let fieldSql .= " " . type;
				}

				let fields[] = fieldSql;
			}

			let fields = join(", ", fields);

		} else {
			let fields = expression;
		}

		return  "ORDER BY " . fields;
	}
	
	/**
	 * Prepares column for this RDBMS
	 */
	protected function prepareColumn(string! qualified, string alias = null) -> string
	{
		if alias != "" {
			return qualified . " AS " . this->escape(alias);
		} else {
			return qualified;
		}
	}

	/**
	 * Prepares table for this RDBMS
	 */
	protected function prepareTable(string! table, string schema = null, string alias = null) -> string
	{
		/**
		 * Schema
		 */
		let table = this->escape(table);

		/**
		 * Schema
		 */
		if schema != "" {
			let table = this->escape(schema) . "." . table;
		}

		/**
		 * Alias
		 */
		if alias != "" {
			let table = table . " AS " . this->escape(alias);
		}

		return table;
	}

	/**
	 * Prepares qualified for this RDBMS
	 */
	protected function prepareQualified(string! column, string domain = null) -> string
	{
		let column = this->escape(column);

		if domain != "" {
			return this->escape(domain) . "." . column;
		} else {
			return column;
		}
	}
}
