
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

namespace Phalcon\Db\Result;

use Phalcon\Db;
use Phalcon\Db\ResultInterface;

%{
#include <ext/pdo/php_pdo_driver.h>
}%

/**
 * Phalcon\Db\Result\Pdo
 *
 * Encapsulates the resultset internals
 *
 * <code>
 * $result = $connection->query("SELECT * FROM robots ORDER BY name");
 *
 * $result->setFetchMode(
 *     \Phalcon\Db::FETCH_NUM
 * );
 *
 * while ($robot = $result->fetchArray()) {
 *     print_r($robot);
 * }
 * </code>
 */
class Pdo implements ResultInterface
{

	protected _connection;

	protected _result;

	/**
	 * Active fetch mode
	 */
	protected _fetchMode = Db::FETCH_OBJ;

	/**
	 * Internal resultset
	 *
	 * @var \PDOStatement
	 */
	protected _pdoStatement;

	protected _sqlStatement;

	protected _bindParams;

	protected _bindTypes;

	protected _rowCount = false;

	/**
	 * Phalcon\Db\Result\Pdo constructor
	 *
	 * @param \Phalcon\Db\AdapterInterface connection
	 * @param \PDOStatement result
	 * @param string sqlStatement
	 * @param array bindParams
	 * @param array bindTypes
	 */
	public function __construct(<Db\AdapterInterface> connection, <\PDOStatement> result,
		sqlStatement = null, bindParams = null, bindTypes = null)
	{

		let this->_connection = connection,
			this->_pdoStatement = result;

		if sqlStatement !== null {
			let this->_sqlStatement = sqlStatement;
		}
		if bindParams !== null {
			let this->_bindParams = bindParams;
		}
		if bindTypes !== null {
			let this->_bindTypes = bindTypes;
		}
	}

	/**
	 * Allows to execute the statement again. Some database systems don't support scrollable cursors,
	 * So, as cursors are forward only, we need to execute the cursor again to fetch rows from the begining
	 */
	public function execute() -> boolean
	{
		return this->_pdoStatement->execute();
	}

	/**
	 * Fetches an array/object of strings that corresponds to the fetched row, or FALSE if there are no more rows.
	 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
	 *
	 *<code>
	 * $result = $connection->query("SELECT * FROM robots ORDER BY name");
	 *
	 * $result->setFetchMode(
	 *     \Phalcon\Db::FETCH_OBJ
	 * );
	 *
	 * while ($robot = $result->fetch()) {
	 *     echo $robot->name;
	 * }
	 *</code>
	 */
	public function $fetch(var fetchStyle = null, var cursorOrientation = null, var cursorOffset = null)
	{
		return this->_pdoStatement->$fetch(fetchStyle, cursorOrientation, cursorOffset);
	}

	/**
	 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
	 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
	 *
	 *<code>
	 * $result = $connection->query("SELECT * FROM robots ORDER BY name");
	 *
	 * $result->setFetchMode(
	 *     \Phalcon\Db::FETCH_NUM
	 * );
	 *
	 * while ($robot = result->fetchArray()) {
	 *     print_r($robot);
	 * }
	 *</code>
	 */
	public function fetchArray()
	{
		return this->_pdoStatement->$fetch();
	}

	/**
	 * Returns an array of arrays containing all the records in the result
	 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
	 *
	 *<code>
	 * $result = $connection->query(
	 *     "SELECT * FROM robots ORDER BY name"
	 * );
	 *
	 * $robots = $result->fetchAll();
	 *</code>
	 */
	public function fetchAll(var fetchStyle = null, var fetchArgument = null, var ctorArgs = null) -> array
	{
		var pdoStatement;

		let pdoStatement = this->_pdoStatement;

		if typeof fetchStyle == "integer" {

			if fetchStyle == Db::FETCH_CLASS {
				return pdoStatement->fetchAll(fetchStyle, fetchArgument, ctorArgs);
			}

			if fetchStyle == Db::FETCH_COLUMN {
				return pdoStatement->fetchAll(fetchStyle, fetchArgument);
			}

			if fetchStyle == Db::FETCH_FUNC {
				return pdoStatement->fetchAll(fetchStyle, fetchArgument);
			}

			return pdoStatement->fetchAll(fetchStyle);
		}

		return pdoStatement->fetchAll();
	}

	/**
	 * Gets number of rows returned by a resultset
	 *
	 *<code>
	 * $result = $connection->query(
	 *     "SELECT * FROM robots ORDER BY name"
	 * );
	 *
	 * echo "There are ", $result->numRows(), " rows in the resultset";
	 *</code>
	 */
	public function numRows() -> int
	{
		var sqlStatement, rowCount, connection, type,
			pdoStatement, matches, result, row;

		let rowCount = this->_rowCount;
		if rowCount === false {

			let connection = this->_connection,
				type = connection->getType();

			/**
			 * MySQL library properly returns the number of records PostgreSQL too
			 */
			if type == "mysql" || type == "pgsql" {
				let pdoStatement = this->_pdoStatement,
					rowCount = pdoStatement->rowCount();
			}

			/**
			 * We should get the count using a new statement :(
			 */
			if rowCount === false {

				/**
				 * SQLite/SQLServer returns resultsets that to the client eyes
				 * (PDO) has an arbitrary number of rows, so we need to perform
				 * an extra count to know that
				 */
				let sqlStatement = this->_sqlStatement;

				/**
				 * If the sql_statement starts with SELECT COUNT(*) we don't make the count
				 */
				if !starts_with(sqlStatement, "SELECT COUNT(*) ") {

					let matches = null;
					if preg_match("/^SELECT\\s+(.*)/i", sqlStatement, matches) {
						let result = connection->query(
							"SELECT COUNT(*) \"numrows\" FROM (SELECT " . matches[1] . ")",
							this->_bindParams,
							this->_bindTypes
						);

						let row = result->$fetch(),
							rowCount = row["numrows"];
					}
				} else {
					let rowCount = 1;
				}
			}

			/**
			 * Update the value to avoid further calculations
			 */
			let this->_rowCount = rowCount;
		}
		return rowCount;
	}

	/**
	 * Moves internal resultset cursor to another position letting us to fetch a certain row
	 *
	 *<code>
	 * $result = $connection->query(
	 *     "SELECT * FROM robots ORDER BY name"
	 * );
	 *
	 * // Move to third row on result
	 * $result->dataSeek(2);
	 *
	 * // Fetch third row
	 * $row = $result->fetch();
	 *</code>
	 */
	public function dataSeek(long number) -> void
	{
		var connection, pdo, sqlStatement, bindParams, statement;
		long n;

		let connection = this->_connection,
			pdo = connection->getInternalHandler(),
			sqlStatement = this->_sqlStatement,
			bindParams = this->_bindParams;

		/**
		 * PDO doesn't support scrollable cursors, so we need to re-execute the statement
		 */
		if typeof bindParams == "array" {
			let statement = pdo->prepare(sqlStatement);
			if typeof statement == "object" {
				let statement = connection->executePrepared(statement, bindParams, this->_bindTypes);
			}
		} else {
			let statement = pdo->query(sqlStatement);
		}

		let this->_pdoStatement = statement;

		let n = -1, number--;
		while n != number {
			statement->$fetch();
			let n++;
		}
	}

	/**
	 * Changes the fetching mode affecting Phalcon\Db\Result\Pdo::fetch()
	 *
	 *<code>
	 * // Return array with integer indexes
	 * $result->setFetchMode(
	 *     \Phalcon\Db::FETCH_NUM
	 * );
	 *
	 * // Return associative array without integer indexes
	 * $result->setFetchMode(
	 *     \Phalcon\Db::FETCH_ASSOC
	 * );
	 *
	 * // Return associative array together with integer indexes
	 * $result->setFetchMode(
	 *     \Phalcon\Db::FETCH_BOTH
	 * );
	 *
	 * // Return an object
	 * $result->setFetchMode(
	 *     \Phalcon\Db::FETCH_OBJ
	 * );
	 *</code>
	 */
	public function setFetchMode(int fetchMode, var colNoOrClassNameOrObject = null, var ctorargs = null) -> boolean
	{
		var pdoStatement;

		let pdoStatement = this->_pdoStatement;

		if fetchMode == Db::FETCH_CLASS {
			if pdoStatement->setFetchMode(fetchMode, colNoOrClassNameOrObject, ctorargs) {
				let this->_fetchMode = fetchMode;
				return true;
			}
			return false;
		}

		if fetchMode == Db::FETCH_INTO {
			if pdoStatement->setFetchMode(fetchMode, colNoOrClassNameOrObject) {
				let this->_fetchMode = fetchMode;
				return true;
			}
			return false;
		}

		if fetchMode == Db::FETCH_COLUMN {
			if pdoStatement->setFetchMode(fetchMode, colNoOrClassNameOrObject) {
				let this->_fetchMode = fetchMode;
				return true;
			}
			return false;
		}

		if pdoStatement->setFetchMode(fetchMode) {
			let this->_fetchMode = fetchMode;
			return true;
		}
		return false;
	}

	/**
	 * Gets the internal PDO result object
	 */
	public function getInternalResult() -> <\PDOStatement>
	{
		return this->_pdoStatement;
	}
}
