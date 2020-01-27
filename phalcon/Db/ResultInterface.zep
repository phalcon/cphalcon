
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db;

/**
 * Interface for Phalcon\Db\Result objects
 */
interface ResultInterface
{
    /**
     * Moves internal resultset cursor to another position letting us to fetch a
     * certain row
     */
    public function dataSeek(long number);

    /**
     * Allows to execute the statement again. Some database systems don't
     * support scrollable cursors. So, as cursors are forward only, we need to
     * execute the cursor again to fetch rows from the beginning
     */
    public function execute() -> bool;

    /**
     * Fetches an array/object of strings that corresponds to the fetched row,
     * or FALSE if there are no more rows. This method is affected by the active
     * fetch flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`
     */
    public function $fetch() -> var;

    /**
     * Returns an array of arrays containing all the records in the result. This
     * method is affected by the active fetch flag set using
     * `Phalcon\Db\Result\Pdo::setFetchMode()`
     */
    public function fetchAll() -> array;

    /**
     * Returns an array of strings that corresponds to the fetched row, or FALSE
     * if there are no more rows. This method is affected by the active fetch
     * flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`
     */
    public function fetchArray() -> var;

    /**
     * Gets the internal PDO result object
     */
    public function getInternalResult() -> <\PDOStatement>;

    /**
     * Gets number of rows returned by a resultset
     */
    public function numRows() -> int;

    /**
     * Changes the fetching mode affecting Phalcon\Db\Result\Pdo::fetch()
     */
    public function setFetchMode(int fetchMode) -> bool;
}
