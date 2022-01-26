
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Result;

use Phalcon\Db\Enum;
use Phalcon\Db\ResultInterface;
use Phalcon\Db\Adapter\AdapterInterface;

%{
#include <ext/pdo/php_pdo_driver.h>
}%

/**
 * Encapsulates the resultset internals
 *
 * ```php
 * $result = $connection->query("SELECT * FROM robots ORDER BY name");
 *
 * $result->setFetchMode(
 *     \Phalcon\Db\Enum::FETCH_NUM
 * );
 *
 * while ($robot = $result->fetchArray()) {
 *     print_r($robot);
 * }
 * ```
 */
class PdoResult implements ResultInterface
{
    /**
     * @var array
     */
    protected bindParams = [];

    /**
     * @var array
     */
    protected bindTypes = [];

    /**
     * @var AdapterInterface
     */
    protected connection;

    /**
     * Active fetch mode
     *
     * @var int
     */
    protected fetchMode = Enum::FETCH_OBJ;

    /**
     * Internal resultset
     *
     * @var \PDOStatement
     */
    protected pdoStatement;

    /**
     * @var mixed
     * TODO: Check if this property is used
     */
    protected result;

    /**
     * @var bool
     */
    protected rowCount = false;

    /**
     * @var string|null
     */
    protected sqlStatement = null;

    /**
     * Phalcon\Db\Result\Pdo constructor
     */
    public function __construct(<AdapterInterface> connection, <\PDOStatement> result,
        sqlStatement = null, bindParams = null, bindTypes = null)
    {
        let this->connection = connection,
            this->pdoStatement = result,
            this->sqlStatement = sqlStatement,
            this->bindParams = bindParams,
            this->bindTypes = bindTypes;
    }

    /**
     * Moves internal resultset cursor to another position letting us to fetch a
     * certain row
     *
     *```php
     * $result = $connection->query(
     *     "SELECT * FROM robots ORDER BY name"
     * );
     *
     * // Move to third row on result
     * $result->dataSeek(2);
     *
     * // Fetch third row
     * $row = $result->fetch();
     *```
     *
     * @param int number
     *
     * @return void
     */
    public function dataSeek(int number) -> void
    {
        var connection, pdo, sqlStatement, bindParams, statement;
        long n;

        let connection = this->connection,
            pdo = connection->getInternalHandler(),
            sqlStatement = this->sqlStatement,
            bindParams = this->bindParams;

        /**
         * PDO doesn't support scrollable cursors, so we need to re-execute the
         * statement
         */
        if typeof bindParams == "array" {
            let statement = pdo->prepare(sqlStatement);

            if typeof statement == "object" {
                let statement = connection->executePrepared(
                    statement,
                    bindParams,
                    this->bindTypes
                );
            }
        } else {
            let statement = pdo->query(sqlStatement);
        }

        let this->pdoStatement = statement;

        let n = -1,
            number--;

        while n != number {
            statement->$fetch();

            let n++;
        }
    }

    /**
     * Allows to execute the statement again. Some database systems don't
     * support scrollable cursors. So, as cursors are forward only, we need to
     * execute the cursor again to fetch rows from the beginning
     */
    public function execute() -> bool
    {
        return this->pdoStatement->execute();
    }

    /**
     * Fetches an array/object of strings that corresponds to the fetched row,
     * or FALSE if there are no more rows. This method is affected by the active
     * fetch flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`
     *
     *```php
     * $result = $connection->query("SELECT * FROM robots ORDER BY name");
     *
     * $result->setFetchMode(
     *     \Phalcon\Enum::FETCH_OBJ
     * );
     *
     * while ($robot = $result->fetch()) {
     *     echo $robot->name;
     * }
     *```
     */
    public function $fetch(var fetchStyle = null, var cursorOrientation = null, var cursorOffset = null)
    {
        return this->pdoStatement->$fetch(
            fetchStyle,
            cursorOrientation,
            cursorOffset
        );
    }

    /**
     * Returns an array of arrays containing all the records in the result
     * This method is affected by the active fetch flag set using
     * `Phalcon\Db\Result\Pdo::setFetchMode()`
     *
     *```php
     * $result = $connection->query(
     *     "SELECT * FROM robots ORDER BY name"
     * );
     *
     * $robots = $result->fetchAll();
     *```
     */
    public function fetchAll(var fetchStyle = null, var fetchArgument = null, var ctorArgs = null) -> array
    {
        var pdoStatement;

        let pdoStatement = this->pdoStatement;

        if typeof fetchStyle != "integer" {
            return pdoStatement->fetchAll();
        }

        if fetchStyle == Enum::FETCH_CLASS {
            return pdoStatement->fetchAll(
                fetchStyle,
                fetchArgument,
                ctorArgs
            );
        }

        if fetchStyle == Enum::FETCH_COLUMN || fetchStyle == Enum::FETCH_FUNC {
            return pdoStatement->fetchAll(fetchStyle, fetchArgument);
        }

        return pdoStatement->fetchAll(fetchStyle);
    }

    /**
     * Returns an array of strings that corresponds to the fetched row, or FALSE
     * if there are no more rows. This method is affected by the active fetch
     * flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`
     *
     *```php
     * $result = $connection->query("SELECT * FROM robots ORDER BY name");
     *
     * $result->setFetchMode(
     *     \Phalcon\Enum::FETCH_NUM
     * );
     *
     * while ($robot = result->fetchArray()) {
     *     print_r($robot);
     * }
     *```
     */
    public function fetchArray()
    {
        return this->pdoStatement->$fetch();
    }

    /**
     * Gets the internal PDO result object
     */
    public function getInternalResult() -> <\PDOStatement>
    {
        return this->pdoStatement;
    }

    /**
     * Gets number of rows returned by a resultset
     *
     *```php
     * $result = $connection->query(
     *     "SELECT * FROM robots ORDER BY name"
     * );
     *
     * echo "There are ", $result->numRows(), " rows in the resultset";
     *```
     */
    public function numRows() -> int
    {
        var sqlStatement, rowCount, connection, type, pdoStatement, matches,
            result, row;

        let rowCount = this->rowCount;

        if rowCount === false {
            let connection = this->connection,
                type = connection->getType();

            /**
             * MySQL and PostgreSQL properly returns the number of records
             */
            if type == "mysql" || type == "pgsql" {
                let pdoStatement = this->pdoStatement,
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
                let sqlStatement = this->sqlStatement;

                /**
                 * If the sql_statement starts with SELECT COUNT(*) we don't
                 * make the count
                 */
                if !starts_with(sqlStatement, "SELECT COUNT(*) ") {
                    let matches = null;

                    if preg_match("/^SELECT\\s+(.*)/i", sqlStatement, matches) {
                        let result = connection->query(
                            "SELECT COUNT(*) \"numrows\" FROM (SELECT " . matches[1] . ")",
                            this->bindParams,
                            this->bindTypes
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
            let this->rowCount = rowCount;
        }

        return rowCount;
    }

    /**
     * Changes the fetching mode affecting Phalcon\Db\Result\Pdo::fetch()
     *
     *```php
     * // Return array with integer indexes
     * $result->setFetchMode(
     *     \Phalcon\Enum::FETCH_NUM
     * );
     *
     * // Return associative array without integer indexes
     * $result->setFetchMode(
     *     \Phalcon\Enum::FETCH_ASSOC
     * );
     *
     * // Return associative array together with integer indexes
     * $result->setFetchMode(
     *     \Phalcon\Enum::FETCH_BOTH
     * );
     *
     * // Return an object
     * $result->setFetchMode(
     *     \Phalcon\Enum::FETCH_OBJ
     * );
     *```
     */
    public function setFetchMode(int fetchMode, var colNoOrClassNameOrObject = null, var ctorargs = null) -> bool
    {
        var pdoStatement;

        let pdoStatement = this->pdoStatement;

        if fetchMode == Enum::FETCH_CLASS || fetchMode == Enum::FETCH_INTO {
            if !pdoStatement->setFetchMode(fetchMode, colNoOrClassNameOrObject, ctorargs) {
                return false;
            }
        } elseif fetchMode == Enum::FETCH_COLUMN {
            if !pdoStatement->setFetchMode(fetchMode, colNoOrClassNameOrObject) {
                return false;
            }
        } else {
            if !pdoStatement->setFetchMode(fetchMode) {
                return false;
            }
        }

        let this->fetchMode = fetchMode;

        return true;
    }
}
