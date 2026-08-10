
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */

namespace Phalcon\DataMapper\Pdo\Connection;

use Phalcon\DataMapper\Pdo\Profiler\ProfilerInterface;

/**
 * Provides array quoting, profiling, a new `perform()` method, new `fetch*()`
 * methods
 */
interface ConnectionInterface extends PdoInterface
{
    /**
     * Connects to the database.
     */
    public function connect() -> void;

    /**
     * Disconnects from the database.
     */
    public function disconnect() -> void;

    /**
     * Performs a statement and returns the number of affected rows.
     */
    public function fetchAffected(string statement, array values = []) -> int;

    /**
     * Fetches a sequential array of rows from the database; the rows are
     * returned as associative arrays.
     */
    public function fetchAll(string statement, array values = []) -> array;

    /**
     * Fetches an associative array of rows from the database; the rows are
     * returned as associative arrays, and the array of rows is keyed on the
     * first column of each row.
     *
     * If multiple rows have the same first column value, the last row with
     * that value will overwrite earlier rows. This method is more resource
     * intensive and should be avoided if possible.
     */
    public function fetchAssoc(string statement, array values = []) -> array;

    /**
     * Fetches a column of rows as a sequential array (default first one).
     */
    public function fetchColumn(
        string statement,
        array values = [],
        int column = 0
    ) -> array;

    /**
     * Fetches multiple from the database as an associative array. The first
     * column will be the index key. The default flags are
     * PDO::FETCH_ASSOC | PDO::FETCH_GROUP
     */
    public function fetchGroup(
        string statement,
        array values = [],
        int flags = \PDO::FETCH_ASSOC
    ) -> array;

    /**
     * Fetches one row from the database as an object where the column values
     * are mapped to object properties.
     *
     * Since PDO injects property values before invoking the constructor, any
     * initializations for defaults that you potentially have in your object's
     * constructor, will override the values that have been injected by
     * `fetchObject`. The default object returned is `\stdClass`
     */
    public function fetchObject(
        string statement,
        array values = [],
        string className = "stdClass",
        array arguments = []
    ) -> object;

    /**
     * Fetches a sequential array of rows from the database; the rows are
     * returned as objects where the column values are mapped to object
     * properties.
     *
     * Since PDO injects property values before invoking the constructor, any
     * initializations for defaults that you potentially have in your object's
     * constructor, will override the values that have been injected by
     * `fetchObject`. The default object returned is `\stdClass`
     */
    public function fetchObjects(
        string statement,
        array values = [],
        string className = "stdClass",
        array arguments = []
    ) -> array;

    /**
     * Fetches one row from the database as an associative array.
     */
    public function fetchOne(string statement, array values = []) -> array;

    /**
     * Fetches an associative array of rows as key-value pairs (first column is
     * the key, second column is the value).
     */
    public function fetchPairs(string statement, array values = []) -> array;

    /**
     * Fetches the very first value (i.e., first column of the first row).
     */
    public function fetchValue(string statement, array values = []) -> var;

    /**
     * Return the inner PDO (if any)
     */
    public function getAdapter() -> <\PDO>;

    /**
     * Returns the Profiler instance.
     */
    public function getProfiler() -> <ProfilerInterface>;

    /**
     * Is the PDO connection active?
     */
    public function isConnected() -> bool;

    /**
     * Performs a query with bound values and returns the resulting
     * PDOStatement; array values will be passed through `quote()` and their
     * respective placeholders will be replaced in the query string. If the
     * profiler is enabled, the operation will be recorded.
     */
    public function perform(string statement, array values = []) -> <\PDOStatement>;

    /**
     * Sets the Profiler instance.
     */
    public function setProfiler(<ProfilerInterface> profiler);
}
