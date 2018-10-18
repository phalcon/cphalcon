
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (http://www.phalconphp.com)       |
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
 |          Stanislav Kiryukhin <korsar.zn@gmail.com>                     |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Db;

/**
 * Phalcon\Db\Dialect
 *
 * This is the base class to each database dialect. This implements
 * common methods to transform intermediate code into its RDBMS related syntax
 */
abstract class Dialect implements DialectInterface
{

	protected _escapeChar;

	protected _customFunctions;

	/**
	 * Registers custom SQL functions
	 */
	public function registerCustomFunction(string name, callable customFunction) -> <Dialect>
	{
		let this->_customFunctions[name] = customFunction;
		return this;
	}

	/**
	 * Returns registered functions
	 */
	public function getCustomFunctions() -> array
	{
		return this->_customFunctions;
	}

	/**
	 * Escape Schema
	 */
	public final function escapeSchema(string! str, string escapeChar = null) -> string
	{
		if !globals_get("db.escape_identifiers") {
			return str;
		}

		if escapeChar == "" {
			let escapeChar = (string) this->_escapeChar;
		}

		return escapeChar . trim(str, escapeChar) . escapeChar;
	}

	/**
	 * Escape identifiers
	 */
	public final function escape(string! str, string escapeChar = null) -> string
	{
		var parts, key, part, newParts;

		if !globals_get("db.escape_identifiers") {
			return str;
		}

		if escapeChar == "" {
			let escapeChar = (string) this->_escapeChar;
		}

		if !memstr(str, ".") {

			if escapeChar != "" && str != "*" {
				return escapeChar . str_replace(escapeChar, escapeChar . escapeChar, str) . escapeChar;
			}

			return str;
		}

		let parts = (array) explode(".", trim(str, escapeChar));

		let newParts = parts;
		for key, part in parts {

			if escapeChar == "" || part == "" || part == "*" {
				continue;
			}

			let newParts[key] = escapeChar . str_replace(escapeChar, escapeChar . escapeChar, part) . escapeChar;
		}

		return implode(".", newParts);
	}

	/**
	 * Generates the SQL for LIMIT clause
	 *
	 * <code>
	 * $sql = $dialect->limit("SELECT * FROM robots", 10);
	 * echo $sql; // SELECT * FROM robots LIMIT 10
	 *
	 * $sql = $dialect->limit("SELECT * FROM robots", [10, 50]);
	 * echo $sql; // SELECT * FROM robots LIMIT 10 OFFSET 50
	 * </code>
	 */
	public function limit(string! sqlQuery, var number) -> string
	{
		if typeof number == "array" {

			let sqlQuery .= " LIMIT " . number[0];

			if isset number[1] && strlen(number[1]) {
				let sqlQuery .= " OFFSET " . number[1];
			}

			return sqlQuery;
		}

		return sqlQuery . " LIMIT " . number;
	}

	/**
	 * Returns a SQL modified with a FOR UPDATE clause
	 *
	 *<code>
	 * $sql = $dialect->forUpdate("SELECT * FROM robots");
	 * echo $sql; // SELECT * FROM robots FOR UPDATE
	 *</code>
	 */
	public function forUpdate(string! sqlQuery) -> string
	{
		return sqlQuery . " FOR UPDATE";
	}

	/**
	 * Gets a list of columns with escaped identifiers
	 *
	 * <code>
	 * echo $dialect->getColumnList(
	 *     [
	 *         "column1",
	 *         "column",
	 *     ]
	 * );
	 * </code>
	 */
	public final function getColumnList(array! columnList, string escapeChar = null, bindCounts = null) -> string
	{
		var columns, column;
		let columns = [];

		for column in columnList {
			let columns[] = this->getSqlColumn(column, escapeChar, bindCounts);
		}

		return join(", ", columns);
	}

	/**
	 * Resolve Column expressions
	 */
	public final function getSqlColumn(var column, string escapeChar = null, bindCounts = null) -> string
	{
		var columnExpression, columnAlias, columnField, columnDomain;

		if typeof column != "array" {
			return this->prepareQualified(column, null, escapeChar);
		}

		if !isset column["type"] {

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
		} else {
			let columnExpression = column;
		}

		/**
		 * Resolve column expressions
		 */
		let column = this->getSqlExpression(columnExpression, escapeChar, bindCounts);

		/**
		 * Escape alias and concatenate to value SQL
		 */
		if fetch columnAlias, columnExpression["sqlAlias"] || fetch columnAlias, columnExpression["alias"] {
			return this->prepareColumnAlias(column, columnAlias, escapeChar);
		}

		return this->prepareColumnAlias(column, null, escapeChar);
	}

	/**
	 * Transforms an intermediate representation for an expression into a database system valid expression
	 */
	public function getSqlExpression(array! expression, string escapeChar = null, bindCounts = null) -> string
	{
		int i;
		var type, times, postTimes, placeholders, rawValue, value;

		if !fetch type, expression["type"] {
			throw new Exception("Invalid SQL expression");
		}

		switch type {

			/**
			 * Resolve scalar column expressions
			 */
			case "scalar":
				return this->getSqlExpressionScalar(expression, escapeChar, bindCounts);

			/**
			 * Resolve object expressions
			 */
			case "object":
				return this->getSqlExpressionObject(expression, escapeChar, bindCounts);

			/**
			 * Resolve qualified expressions
			 */
			case "qualified":
				return this->getSqlExpressionQualified(expression, escapeChar);

			/**
			 * Resolve literal OR placeholder expressions
			 */
			case "literal":
				return expression["value"];

			case "placeholder":
				if fetch times, expression["times"] {

					let placeholders = [],
						rawValue = expression["rawValue"],
						value = expression["value"];

					if fetch postTimes, bindCounts[rawValue] {
						let times = postTimes;
					}

					for i in range(1, times) {
						let placeholders[] = value . (i - 1);
					}

					return join(", ", placeholders);
				}
				return expression["value"];

			/**
			 * Resolve binary operations expressions
			 */
			case "binary-op":
				return this->getSqlExpressionBinaryOperations(expression, escapeChar, bindCounts);

			/**
			 * Resolve unary operations expressions
			 */
			case "unary-op":
				return this->getSqlExpressionUnaryOperations(expression, escapeChar, bindCounts);

			/**
			 * Resolve parentheses
			 */
			case "parentheses":
				return "(" . this->getSqlExpression(expression["left"], escapeChar, bindCounts) . ")";

			/**
			 * Resolve function calls
			 */
			case "functionCall":
				return this->getSqlExpressionFunctionCall(expression, escapeChar, bindCounts);

			/**
			 * Resolve lists
			 */
			case "list":
				return this->getSqlExpressionList(expression, escapeChar, bindCounts);

			/**
			 * Resolve *
			 */
			case "all":
				return this->getSqlExpressionAll(expression, escapeChar);

			/**
			 * Resolve SELECT
			 */
			case "select":
				return "(" . this->select(expression["value"]) . ")";

			/**
			 * Resolve CAST of values
			 */
			case "cast":
				return this->getSqlExpressionCastValue(expression, escapeChar, bindCounts);

			/**
			 * Resolve CONVERT of values encodings
			 */
			case "convert":
				return this->getSqlExpressionConvertValue(expression, escapeChar, bindCounts);

			case "case":
				return this->getSqlExpressionCase(expression, escapeChar, bindCounts);
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
		var tableName, schemaName, aliasName;

		if typeof table == "array" {

			/**
			 * The index "0" is the table name
			 */
			let tableName = table[0];

			/**
			 * The index "1" is the schema name
			 */
			fetch schemaName, table[1];

			/**
			 * The index "2" is the table alias
			 */
			fetch aliasName, table[2];

			return this->prepareTable(tableName, schemaName, aliasName, escapeChar);
		}

		return this->escape(table, escapeChar);
	}

	/**
	 * Builds a SELECT statement
	 */
	public function select(array! definition) -> string
	{
		var tables, columns, sql, distinct, joins, where, escapeChar,
			groupBy, having, orderBy, limit, forUpdate, bindCounts;

		if !fetch tables, definition["tables"] {
			throw new Exception("The index 'tables' is required in the definition array");
		}

		if !fetch columns, definition["columns"] {
			throw new Exception("The index 'columns' is required in the definition array");
		}

		if fetch distinct, definition["distinct"] {

			if distinct {
				let sql = "SELECT DISTINCT";
			} else {
				let sql = "SELECT ALL";
			}

		} else {
			let sql = "SELECT";
		}

		fetch bindCounts, definition["bindCounts"];

		let escapeChar = this->_escapeChar;

		/**
		 * Resolve COLUMNS
		 */
		let sql .= " " . this->getColumnList(columns, escapeChar, bindCounts);

		/**
		 * Resolve FROM
		 */
		let sql .= " " . this->getSqlExpressionFrom(tables, escapeChar);

		/**
		 * Resolve JOINs
		 */
		if fetch joins, definition["joins"] && joins {
			let sql .= " " . this->getSqlExpressionJoins(definition["joins"], escapeChar, bindCounts);
		}

		/**
		 * Resolve WHERE
		 */
		if fetch where, definition["where"] && where {
			let sql .= " " . this->getSqlExpressionWhere(where, escapeChar, bindCounts);
		}

		/**
		 * Resolve GROUP BY
		 */
		if fetch groupBy, definition["group"] && groupBy {
			let sql .= " " . this->getSqlExpressionGroupBy(groupBy, escapeChar);
		}

		/**
		 * Resolve HAVING
		 */
		if fetch having, definition["having"] && having {
			let sql .= " " . this->getSqlExpressionHaving(having, escapeChar, bindCounts);
		}

		/**
		 * Resolve ORDER BY
		 */
		if fetch orderBy, definition["order"] && orderBy {
			let sql .= " " . this->getSqlExpressionOrderBy(orderBy, escapeChar, bindCounts);
		}

		/**
		 * Resolve LIMIT
		 */
		if fetch limit, definition["limit"] && limit {
			let sql = this->getSqlExpressionLimit(["sql": sql, "value": limit], escapeChar, bindCounts);
		}

		/**
		 * Resolve FOR UPDATE
		 */
		if fetch forUpdate, definition["forUpdate"] && forUpdate {
			let sql .= " FOR UPDATE";
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
	 * Resolve Column expressions
	 */
	protected final function getSqlExpressionScalar(array! expression, string escapeChar = null, bindCounts = null) -> string
	{
		var value;

		if isset expression["column"] {
			return this->getSqlColumn(expression["column"]);
		}

		if !fetch value, expression["value"] {
			throw new Exception("Invalid SQL expression");
		}

		if typeof value == "array" {
			return this->getSqlExpression(value, escapeChar, bindCounts);
		}

		return value;
	}

	/**
	 * Resolve object expressions
	 */
	protected final function getSqlExpressionObject(array! expression, string escapeChar = null, bindCounts = null) -> string
	{
		var domain = null, objectExpression;

		let objectExpression = [
			"type": "all"
		];

		if (fetch domain, expression["column"] || fetch domain, expression["domain"]) && domain != "" {
			let objectExpression["domain"] = domain;
		}

		return this->getSqlExpression(objectExpression, escapeChar, bindCounts);
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

		return this->prepareQualified(column, domain, escapeChar);
	}

	/**
	 * Resolve binary operations expressions
	 */
	protected final function getSqlExpressionBinaryOperations(array! expression, string escapeChar = null, bindCounts = null) -> string
	{
		var left, right;

		let left  = this->getSqlExpression(expression["left"], escapeChar, bindCounts),
			right = this->getSqlExpression(expression["right"], escapeChar, bindCounts);

		return left . " " . expression["op"] . " " . right;
	}

	/**
	 * Resolve unary operations expressions
	 */
	protected final function getSqlExpressionUnaryOperations(array! expression, string escapeChar = null, bindCounts = null) -> string
	{
		var left, right;

		/**
		 * Some unary operators use the left operand...
		 */
		if fetch left, expression["left"] {
			return this->getSqlExpression(left, escapeChar, bindCounts) . " " . expression["op"];
		}

		/**
		 * ...Others use the right operand
		 */
		if fetch right, expression["right"] {
			return expression["op"] . " " . this->getSqlExpression(right, escapeChar, bindCounts);
		}

		throw new Exception("Invalid SQL-unary expression");
	}

	/**
	 * Resolve function calls
	 */
	protected final function getSqlExpressionFunctionCall(array! expression, string escapeChar = null, bindCounts) -> string
	{
		var name, customFunction, arguments;

		let name = expression["name"];

		if fetch customFunction, this->_customFunctions[name] {
			return {customFunction}(this, expression, escapeChar);
		}

		if fetch arguments, expression["arguments"] && typeof arguments == "array" {

			let arguments = this->getSqlExpression([
				"type": "list",
				"parentheses": false,
				"value": arguments
			], escapeChar, bindCounts);

			if isset expression["distinct"] && expression["distinct"] {
				return name . "(DISTINCT " . arguments . ")";
			}

			return name . "(" . arguments . ")";
		}

		return name . "()";
	}

	/**
	 * Resolve Lists
	 */
	protected final function getSqlExpressionList(array! expression, string escapeChar = null, bindCounts = null) -> string
	{
		var items, item, values, separator;

		let items = [];
		let separator = ", ";

		if isset expression["separator"] {
			let separator = expression["separator"];
		}

		if (fetch values, expression[0] || fetch values, expression["value"]) && typeof values == "array" {

			for item in values {
				let items[] = this->getSqlExpression(item, escapeChar, bindCounts);
			}

			if isset expression["parentheses"] && expression["parentheses"] === false {
				return join(separator, items);
			}

			return "(" . join(separator, items) . ")";
		}

		throw new Exception("Invalid SQL-list expression");
	}

	/**
	 * Resolve *
	 */
	protected final function getSqlExpressionAll(array! expression, string escapeChar = null) -> string
	{
		var domain;

		fetch domain, expression["domain"];

		return this->prepareQualified("*", domain, escapeChar);
	}

	/**
	 * Resolve CAST of values
	 */
	protected final function getSqlExpressionCastValue(array! expression, string escapeChar = null, bindCounts = null) -> string
	{
		var left, right;

		let left  = this->getSqlExpression(expression["left"], escapeChar, bindCounts),
			right = this->getSqlExpression(expression["right"], escapeChar, bindCounts);

		return "CAST(" . left . " AS " . right . ")";
	}

	/**
	 * Resolve CONVERT of values encodings
	 */
	protected final function getSqlExpressionConvertValue(array! expression, string escapeChar = null, bindCounts = null) -> string
	{
		var left, right;

		let left  = this->getSqlExpression(expression["left"], escapeChar, bindCounts),
			right = this->getSqlExpression(expression["right"], escapeChar, bindCounts);

		return "CONVERT(" . left . " USING " . right . ")";
	}

	/**
	 * Resolve CASE expressions
	 */
	protected final function getSqlExpressionCase(array! expression, string escapeChar = null, bindCounts = null) -> string
	{
		var sql, whenClause;

		let sql = "CASE " . this->getSqlExpression(expression["expr"], escapeChar, bindCounts);

		for whenClause in expression["when-clauses"] {
			if whenClause["type"] == "when" {
				let sql .= " WHEN " .
						this->getSqlExpression(whenClause["expr"], escapeChar, bindCounts) .
						" THEN " .
						this->getSqlExpression(whenClause["then"], escapeChar, bindCounts);
			} else {
				let sql .= " ELSE " . this->getSqlExpression(whenClause["expr"], escapeChar, bindCounts);
			}
		}

		return sql . " END";
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
				let tables[] = this->getSqlTable(table, escapeChar);
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
	protected final function getSqlExpressionJoins(var expression, string escapeChar = null, bindCounts = null) -> string
	{
		var condition, join, sql = "", joinCondition, joinTable, joinType = "", joinConditionsArray;

		for join in expression {

			/**
			 * Check if the join has conditions
			 */
			if fetch joinConditionsArray, join["conditions"] && !empty joinConditionsArray {

				if !isset joinConditionsArray[0] {
					let joinCondition = this->getSqlExpression(joinConditionsArray, escapeChar, bindCounts);
				} else {

					let joinCondition = [];

					for condition in joinConditionsArray {
						let joinCondition[] = this->getSqlExpression(condition, escapeChar, bindCounts);
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
	protected final function getSqlExpressionWhere(var expression, string escapeChar = null, bindCounts = null) -> string
	{
		var whereSql;

		if typeof expression == "array" {
			let whereSql = this->getSqlExpression(expression, escapeChar, bindCounts);
		} else {
			let whereSql = expression;
		}

		return "WHERE " . whereSql;
	}

	/**
	 * Resolve a GROUP BY clause
	 */
	protected final function getSqlExpressionGroupBy(var expression, string escapeChar = null, bindCounts = null) -> string
	{
		var field, fields;

		if typeof expression == "array" {

			let fields = [];

			for field in expression {
				if unlikely typeof field != "array" {
					throw new Exception("Invalid SQL-GROUP-BY expression");
				}

				let fields[] = this->getSqlExpression(field, escapeChar, bindCounts);
			}

			let fields = join(", ", fields);

		} else {
			let fields = expression;
		}

		return "GROUP BY " . fields;
	}

	/**
	 * Resolve a HAVING clause
	 */
	protected final function getSqlExpressionHaving(array! expression, string escapeChar = null, bindCounts = null) -> string
	{
		return "HAVING " . this->getSqlExpression(expression, escapeChar, bindCounts);
	}

	/**
	 * Resolve an ORDER BY clause
	 */
	protected final function getSqlExpressionOrderBy(var expression, string escapeChar = null, bindCounts = null) -> string
	{
		var field, fields, type, fieldSql = null;

		if typeof expression == "array" {

			let fields = [];

			for field in expression {

				if unlikely typeof field != "array" {
					throw new Exception("Invalid SQL-ORDER-BY expression");
				}

				let fieldSql = this->getSqlExpression(field[0], escapeChar, bindCounts);

				/**
				 * In the numeric 1 position could be a ASC/DESC clause
				 */
				if fetch type, field[1] && type != "" {
					let fieldSql .= " " . type;
				}

				let fields[] = fieldSql;
			}

			let fields = join(", ", fields);

		} else {
			let fields = expression;
		}

		return "ORDER BY " . fields;
	}

	/**
	 * Resolve a LIMIT clause
	 */
	protected final function getSqlExpressionLimit(var expression, string escapeChar = null, bindCounts = null) -> string
	{
		var sql = "", value, limit, offset = null;
		let value = expression["value"];

		if isset expression["sql"] {
			let sql = expression["sql"];
		}

		if typeof value == "array" {

			if typeof value["number"] == "array" {
				let limit = this->getSqlExpression(value["number"], escapeChar, bindCounts);
			} else {
				let limit = value["number"];
			}

			/**
			 * Check for an OFFSET condition
			 */
			if fetch offset, value["offset"] && typeof offset == "array" {
				let offset = this->getSqlExpression(offset, escapeChar, bindCounts);
			}

		} else {
			let limit = value;
		}

		return this->limit(sql, [limit, offset]);
	}

	/**
	 * Prepares column for this RDBMS
	 */
	protected function prepareColumnAlias(string! qualified, string alias = null, string escapeChar = null) -> string
	{
		if alias != "" {
			return qualified . " AS " . this->escape(alias, escapeChar);
		}
		return qualified;
	}

	/**
	 * Prepares table for this RDBMS
	 */
	protected function prepareTable(string! table, string schema = null, string alias = null, string escapeChar = null) -> string
	{
		let table = this->escape(table, escapeChar);

		/**
		 * Schema
		 */
		if schema != "" {
			let table = this->escapeSchema(schema, escapeChar) . "." . table;
		}

		/**
		 * Alias
		 */
		if alias != "" {
			let table = table . " AS " . this->escape(alias, escapeChar);
		}

		return table;
	}

	/**
	 * Prepares qualified for this RDBMS
	 */
	protected function prepareQualified(string! column, string domain = null, string escapeChar = null) -> string
	{
		if domain != "" {
			return this->escape(domain . "." . column, escapeChar);
		}

		return this->escape(column, escapeChar);
	}
}
