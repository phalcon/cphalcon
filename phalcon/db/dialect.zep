
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Db;

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
	 *
	 * @param string sqlQuery
	 * @param int number
	 * @return string
	 */
	public function limit(string sqlQuery, int number) -> string
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
	 *
	 * @param	string sqlQuery
	 * @return	string
	 */
	public function forUpdate(string sqlQuery) -> string
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
	 *
	 * @param	string sqlQuery
	 * @return	string
	 */
	public function sharedLock(string sqlQuery) -> string
	{
		return sqlQuery . " LOCK IN SHARE MODE";
	}

	/**
	 * Gets a list of columns with escaped identifiers
	 *
	 *<code>
	 * echo $dialect->getColumnList(array('column1', 'column'));
	 *</code>
	 *
	 * @param	array columnList
	 * @return	string
	 */
	public function getColumnList(columnList) -> string
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
	 *
	 * @param array expression
	 * @param string escapeChar
	 * @return string
	 */
	public function getSqlExpression(expression, string escapeChar=null) -> string
	{
		var type, domain, operator, left, right, name, sqlItems,
			escapedName, sqlArguments, arguments, argument, items, item;

		if globals_get("db.escape_identifiers") {
			if escapeChar === null{
				let escapeChar = (string) this->_escapeChar;
			}
		}

		if typeof expression != "array" {
			throw new Phalcon\Db\Exception("Invalid SQL expression");
		}

		if !fetch type, expression["type"] {
			throw new Phalcon\Db\Exception("Invalid SQL expression");
		}

		/**
		 * Resolve qualified expressions
		 */
		if type == "qualified" {

			let name = expression["name"];
			if globals_get("db.escape_identifiers") {
				let escapedName = escapeChar . name . escapeChar;
			} else {
				let escapedName = name;
			}

			/**
			 * A domain could be a table/schema
			 */
			if fetch domain, expression["domain"] {
				if globals_get("db.escape_identifiers") {
					return escapeChar . domain . escapeChar . "." . escapedName;
				} else {
					return domain . "." . escapedName;
				}
			}

			return escapedName;
		}

		/**
		 * Resolve literal expressions
		 */
		if type == "literal" {
			return expression["value"];
		}

		/**
		 * Resolve binary operations expressions
		 */
		if type == "binary-op" {

			let left = this->getSqlExpression(expression["left"], escapeChar),
				right = this->getSqlExpression(expression["right"], escapeChar);

			return left . " " . expression["op"] . " " . right;
		}

		/**
		 * Resolve unary operations expressions
		 */
		if type == "unary-op" {

			let operator = expression["op"];

			/**
			 * Some unary operators uses the left operand...
			 */
			if fetch left, expression["left"] {
				return this->getSqlExpression(left, escapeChar) . operator;
			}

			/**
			 * ...Others uses the right operand
			 */
			if fetch right, expression["right"] {
				return this->getSqlExpression(right, escapeChar) . operator;
			}
		}

		/**
		 * Resolve placeholder
		 */
		if type == "placeholder" {
			return expression["value"];
		}

		/**
		 * Resolve parentheses
		 */
		if type == "parentheses" {
			return "(" . this->getSqlExpression(expression["left"], escapeChar) . ")";
		}

		/**
		 * Resolve function calls
		 */
		if type == "functionCall" {
			let name = expression["name"],
				sqlArguments = [];
			if fetch arguments, expression["arguments"] {
				for argument in arguments {
					let sqlArguments[] = this->getSqlExpression(argument, escapeChar);
				}
				return name . "(" . join(", ", sqlArguments) . ")";
			} else {
				return name . "()";
			}
		}

		/**
		 * Resolve lists
		 */
		if type == "list" {
			let sqlItems = [],
				items = expression[0];
			for item in items {
				let sqlItems[] = this->getSqlExpression(item, escapeChar);
			}
			return "(" . join(", ", sqlItems) . ")";
		}

		/**
		 * Resolve *
		 */
		if type == "all" {
			return "*";
		}

		/**
		 * Resolve CAST of values
		 */
		if type == "cast" {

			let left = this->getSqlExpression(expression["left"], escapeChar),
				right = this->getSqlExpression(expression["right"], escapeChar);

			return "CAST(" . left . " AS " . right . ")";
		}

		/**
		 * Resolve CONVERT of values encodings
		 */
		if type == "convert"{

			let left = this->getSqlExpression(expression["left"], escapeChar),
				right = this->getSqlExpression(expression["right"], escapeChar);

			return "CONVERT(" . left . " USING " . right . ")";
		}

		/**
		 * Expression type wasn't found
		 */
		throw new Phalcon\Db\Exception("Invalid SQL expression type '" . type . "'");
	}

	/**
	 * Transform an intermediate representation for a schema/table into a database system valid expression
	 *
	 * @param array table
	 * @param string escapeChar
	 * @return string
	 */
	public function getSqlTable(table, string escapeChar=null) -> string
	{
		var sqlTable, sqlSchema, aliasName, sqlTableAlias,
			schemaName, tableName;

		if escapeChar === null{
			let escapeChar = (string) this->_escapeChar;
		}

		if typeof table == "array" {

			/**
			 * The index "0" is the table name
			 */
			let tableName = table[0];

			if globals_get("db.escape_identifiers") {
				let sqlTable = escapeChar . tableName . escapeChar;
			} else {
				let sqlTable = tableName;
			}

			/**
			 * The index "1" is the schema name
			 */
			let schemaName = table[1];
			if typeof schemaName != "array" {
				if globals_get("db.escape_identifiers") {
					let sqlSchema = escapeChar . schemaName.escapeChar . "." . sqlTable;
				} else {
					let sqlSchema = schemaName . "." . sqlTable;
				}
			} else {
				let sqlSchema = sqlTable;
			}

			/**
			 * The index "2" is the table alias
			 */
			if fetch aliasName, table[2] {
				if globals_get("db.escape_identifiers") {
					let sqlTableAlias = sqlSchema . " AS " . escapeChar . aliasName . escapeChar;
				} else {
					let sqlTableAlias = sqlSchema . " AS " . aliasName;
				}
			} else {
				let sqlTableAlias = sqlSchema;
			}

			return sqlTableAlias;
		}

		if globals_get("db.escape_identifiers") {
			return escapeChar . table . escapeChar;
		}

		return table;
	}

	/**
	 * Builds a SELECT statement
	 *
	 * @param array definition
	 * @return string
	 */
	public function select(definition) -> string
	{
		var tables, columns, escapeChar, columnItem, column,
			selectedColumns, columnSql, columnDomainSql, columnAlias,
			selectedTables, sqlJoin, joinExpressions, joinCondition,
			joinConditionsArray, tablesSql, columnDomain, columnAliasSql,
			columnsSql, table, sql, joins, join, sqlTable, whereConditions,
			groupFields, groupField, groupItems, havingConditions,
			orderFields, orderItem, orderItems, orderSqlItem, sqlOrderType,
			orderSqlItemType, limitValue, number, offset;

		if typeof definition == "array" {
			throw new Phalcon\Db\Exception("Invalid SELECT definition");
		}

		if !fetch tables, definition["tables"] {
			throw new Phalcon\Db\Exception("The index 'tables' is required in the definition array");
		}

		if !fetch columns, definition["columns"] {
			throw new Phalcon\Db\Exception("The index 'columns' is required in the definition array");
		}

		if globals_get("db.escape_identifiers") {
			let escapeChar = this->_escapeChar;
		} else {
			let escapeChar = null;
		}

		let columns = definition["columns"];
		if typeof columns == "array" {

			let selectedColumns = [];
			for column in columns {

				/**
				 * Escape column name
				 */
				let columnItem = column[0];
				if typeof columnItem == "array" {
					let columnSql = this->getSqlExpression(columnItem, escapeChar);
				} else {
					if columnItem == "*" {
						let columnSql = columnItem;
					} else {
						if globals_get("db.escape_identifiers") {
							let columnSql = escapeChar . columnItem . escapeChar;
						} else {
							let columnSql = columnItem;
						}
					}
				}

				/**
				 * Escape column domain
				 */
				if fetch columnDomain, column[1] {
					if columnDomain {
						if globals_get("db.escape_identifiers") {
							let columnDomainSql = escapeChar . columnDomain . escapeChar . "." . columnSql;
						} else {
							let columnDomainSql = columnDomain . "." . columnSql;
						}
					} else {
						let columnDomainSql = columnSql;
					}
				} else {
					let columnDomainSql = columnSql;
				}

				/**
				 * Escape column alias
				 */
				if fetch columnAlias, column[2] {
					if columnAlias {
						if globals_get("db.escape_identifiers") {
							let columnAliasSql = columnDomainSql . " AS " . escapeChar . columnAlias . escapeChar;
						} else {
							let columnAliasSql = columnDomainSql . " AS " . columnAlias;
						}
					} else {
						let columnAliasSql = columnDomainSql;
					}
				} else {
					let columnAliasSql = columnDomainSql;
				}
				let selectedColumns[] = columnAliasSql;
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
						let joinExpressions = [];
						for joinCondition in joinConditionsArray {
							let joinExpressions[] = this->getSqlExpression(joinCondition, escapeChar);
						}
						let sqlJoin .= " ON " . join(" AND ", joinExpressions) . " ";
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
				let groupItems[] = this->getSqlExpression(groupField, escapeChar);
			}
			let sql .= " GROUP BY " . join(", ", groupItems);

			/**
			 * Check for a HAVING clause
			 */
			if fetch havingConditions,  definition["having"] {
				let sql .= " HAVING " . this->getSqlExpression(havingConditions, escapeChar);
			}
		}

		/**
		 * Check for a ORDER clause
		 */
		if fetch orderFields, definition["order"]{
			let orderItems = [];
			for orderItem in orderFields {

				let orderSqlItem = this->getSqlExpression(orderItem[0], escapeChar);

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

				let number = limitValue["number"];

				/**
				 * Check for a OFFSET condition
				 */
				if fetch offset, limitValue["offset"] {
					let sql .= " LIMIT " . number . " OFFSET " . offset;
				} else {
					let sql .= " LIMIT " . number;
				}
			} else {
				let sql .= " LIMIT " . limitValue;
			}
		}

		return sql;
	}

	/**
	 * Checks whether the platform supports savepoints
	 *
	 * @return boolean
	 */
	public function supportsSavepoints() -> boolean
	{
		return true;
	}

	/**
	 * Checks whether the platform supports releasing savepoints.
	 *
	 * @return boolean
	 */
	public function supportsReleaseSavepoints()
	{
		return this->supportsSavePoints();
	}

	/**
	 * Generate SQL to create a new savepoint
	 *
	 * @param string name
	 * @return string
	 */
	public function createSavepoint(string name) -> string
	{
		return "SAVEPOINT " . name;
	}

	/**
	 * Generate SQL to release a savepoint
	 *
	 * @param string name
	 * @return string
	 */
	public function releaseSavepoint(string name) -> string
	{
		return "RELEASE SAVEPOINT " . name;
	}

	/**
	 * Generate SQL to rollback a savepoint
	 *
	 * @param string name
	 * @return string
	 */
	public function rollbackSavepoint(string name) -> string
	{
		return "ROLLBACK TO SAVEPOINT " . name;
	}

}
