
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

use PDO;
use PDOStatement;

/**
 * An interface to the native PDO object.
 */
interface PdoInterface
{
    /**
     * Return an array of available PDO drivers (empty array if none available)
     */
    public static function getAvailableDrivers() -> array;
    
    /**
     * Begins a transaction. If the profiler is enabled, the operation will
     * be recorded.
     */
    public function beginTransaction() -> bool;

    /**
     * Commits the existing transaction. If the profiler is enabled, the
     * operation will be recorded.
     */
    public function commit() -> bool;

    /**
     * Gets the most recent error code.
     */
    public function errorCode() -> string | null;

    /**
     * Gets the most recent error info.
     */
    public function errorInfo() -> array;

    /**
     * Executes an SQL statement and returns the number of affected rows. If
     * the profiler is enabled, the operation will be recorded.
     */
    public function exec(string statement) -> int;

    /**
     * Retrieve a database connection attribute
     */
    public function getAttribute(int attribute) -> var;

    /**
     * Is a transaction currently active? If the profiler is enabled, the
     * operation will be recorded. If the profiler is enabled, the operation
     * will be recorded.
     */
    public function inTransaction() -> bool;

    /**
     * Returns the last inserted autoincrement sequence value. If the profiler
     * is enabled, the operation will be recorded.
     */
    public function lastInsertId(string name = null) -> string;

    /**
     * Prepares an SQL statement for execution.
     */
    public function prepare(string statement, array options = []) -> false | <PDOStatement>;

    /**
     * Queries the database and returns a PDOStatement. If the profiler is
     * enabled, the operation will be recorded.
     */
    public function query(string statement) -> false | <PDOStatement>;

    /**
     * Quotes a value for use in an SQL statement. This differs from
     * `PDO::quote()` in that it will convert an array into a string of
     * comma-separated quoted values. The default type is `PDO::PARAM_STR`
     */
    public function quote(var value, int type = \PDO::PARAM_STR) -> string;

    /**
     * Rolls back the current transaction, and restores autocommit mode. If the
     * profiler is enabled, the operation will be recorded.
     */
    public function rollBack() -> bool;

    /**
     * Set a database connection attribute
     */
    public function setAttribute(int attribute, var value) -> bool;
}
