
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
 * $result = $connection->query("SELECT * FROM co_invoices ORDER BY inv_title");
 *
 * $result->setFetchMode(
 *     \Phalcon\Db\Enum::FETCH_NUM
 * );
 *
 * while ($invoice = $result->fetchArray()) {
 *     print_r($invoice);
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
    protected fetchMode = Enum::FETCH_DEFAULT;

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
     * @var int|null
     */
    protected rowCount = null;

    /**
     * @var string|null
     */
    protected sqlStatement = null;

    /**
     * Phalcon\Db\Result\Pdo constructor
     */
    public function __construct(
        <AdapterInterface> connection,
        <\PDOStatement> result,
        sqlStatement = null,
        bindParams = null,
        bindTypes = null
    ) {
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
     *     "SELECT * FROM co_invoices ORDER BY inv_title"
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
         * PDO does not support scrollable cursors, so we need to re-execute the
         * statement
         */
        if typeof bindParams === "array" {
            let statement = pdo->prepare(sqlStatement);

            if typeof statement === "object" {
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
            statement->$fetch(this->fetchMode);

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
        let this->rowCount = null;
        return this->pdoStatement->execute();
    }

    /**
     * Fetches an array/object of strings that corresponds to the fetched row,
     * or FALSE if there are no more rows. This method is affected by the active
     * fetch flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`
     *
     *```php
     * $result = $connection->query("SELECT * FROM co_invoices ORDER BY inv_title");
     *
     * $result->setFetchMode(
     *     \Phalcon\Enum::FETCH_OBJ
     * );
     *
     * while ($invoice = $result->fetch()) {
     *     echo $invoice->inv_title;
     * }
     *```
     */
    public function $fetch(
        int fetchStyle = null,
        int cursorOrientation = Enum::FETCH_ORI_NEXT,
        int cursorOffset = 0
    ) {
        var mode;

        let mode = typeof fetchStyle === "int" ? fetchStyle : this->fetchMode;

        return this->pdoStatement->$fetch(
            mode,
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
     *     "SELECT * FROM co_invoices ORDER BY inv_title"
     * );
     *
     * $invoices = $result->fetchAll();
     *```
     *
     * @param int                      $mode
     * @param int|string|callable|null $fetchArgument
     * @param array|null               $constructorArgs
     */
    public function fetchAll(
        int mode = Enum::FETCH_DEFAULT,
        var fetchArgument = Enum::FETCH_ORI_NEXT,
        var constructorArgs = null
    ) -> array {
        if mode == Enum::FETCH_CLASS {
            return this->pdoStatement->fetchAll(mode, fetchArgument, constructorArgs);
        }

        if mode == Enum::FETCH_COLUMN || mode == Enum::FETCH_FUNC {
            return this->pdoStatement->fetchAll(mode, fetchArgument);
        }

        return this->pdoStatement->fetchAll(mode);
    }

    /**
     * Returns an array of strings that corresponds to the fetched row, or FALSE
     * if there are no more rows. This method is affected by the active fetch
     * flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`
     *
     *```php
     * $result = $connection->query("SELECT * FROM co_invoices ORDER BY inv_title");
     *
     * $result->setFetchMode(
     *     \Phalcon\Enum::FETCH_NUM
     * );
     *
     * while ($invoice = result->fetchArray()) {
     *     print_r($invoice);
     * }
     *```
     */
    public function fetchArray()
    {
        return this->pdoStatement->$fetch(this->fetchMode);
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
     *     "SELECT * FROM co_invoices ORDER BY inv_title"
     * );
     *
     * echo "There are ", $result->numRows(), " rows in the resultset";
     *```
     */
    public function numRows() -> int
    {
        var connection, pdoStatement, result, row, rowCount, sqlStatement, type;

        let rowCount = this->rowCount;

        if rowCount !== null {
            return rowCount;
        }

        let connection = this->connection,
            type       = connection->getType();

        /**
         * MySQL and PostgreSQL properly return the number of records, and keep
         * doing so once the cursor has been advanced
         */
        if type === "mysql" || type === "pgsql" {
            let pdoStatement   = this->pdoStatement,
                rowCount       = (int) pdoStatement->rowCount(),
                this->rowCount = rowCount;

            return rowCount;
        }

        /**
         * SQLite returns resultsets that to the client eyes (PDO) have an
         * arbitrary number of rows - it is a streaming cursor and does not know
         * the count until the result has been stepped to the end. So the count
         * costs an extra statement.
         *
         * The original statement is wrapped verbatim rather than taken apart
         * and rebuilt: any SELECT is a valid subquery, which keeps multi-line
         * statements and common table expressions working, and makes a wrapped
         * `SELECT COUNT(*) ... GROUP BY` report its number of groups instead of
         * a hard-coded 1.
         */
        let sqlStatement = this->sqlStatement,
            result       = connection->query(
                "SELECT COUNT(*) \"numrows\" FROM (" . sqlStatement . ")",
                this->bindParams,
                this->bindTypes
            ),
            row          = result->$fetch(),
            rowCount     = (int) row["numrows"];

        /**
         * Update the value to avoid further calculations
         */
        let this->rowCount = rowCount;

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
    public function setFetchMode(
        int fetchMode,
        var colNoOrClassNameOrObject = null,
        var ctorargs = null
    ) -> bool {
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
