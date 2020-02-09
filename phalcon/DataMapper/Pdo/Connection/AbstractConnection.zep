
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

use BadMethodCallException;
use Phalcon\DataMapper\Pdo\Exception\CannotBindValue;
use Phalcon\DataMapper\Pdo\Profiler\ProfilerInterface;

/**
 * Provides array quoting, profiling, a new `perform()` method, new `fetch*()`
 * methods
 *
 * @property PDO               $pdo
 * @property ProfilerInterface $profiler
 */
abstract class AbstractConnection implements ConnectionInterface
{
    /**
     * @var PDO
     */
    protected pdo;

    /**
     * @var ProfilerInterface
     */
    protected profiler;

    /**
     * Proxies to PDO methods created for specific drivers; in particular,
     * `sqlite` and `pgsql`.
     *
     * @param string $name
     * @param array  $arguments
     *
     * @return mixed
     * @throws BadMethodCallException
     */
    public function __call(var name, array arguments)
    {
        var className, message;

        this->connect();

        if !method_exists(this->pdo, name) {
            let className = get_class(this),
                message   = "Class '" . className
                          . "' does not have a method '" . name . "'";

            throw new BadMethodCallException(message);
        }

        return call_user_func_array(
            [
                this->pdo,
                name
            ],
            arguments
        );
    }

    /**
     * Begins a transaction. If the profiler is enabled, the operation will
     * be recorded.
     *
     * @return bool
     */
    public function beginTransaction() -> bool
    {
        var result;

        this->connect();
        this->profiler->start(__FUNCTION__);

        let result = this->pdo->beginTransaction();

        this->profiler->finish();

        return result;
    }

    /**
     * Commits the existing transaction. If the profiler is enabled, the
     * operation will be recorded.
     *
     * @return bool
     */
    public function commit() -> bool
    {
        var result;

        this->connect();
        this->profiler->start(__FUNCTION__);

        let result = this->pdo->commit();

        this->profiler->finish();

        return result;
    }

    /**
     * Connects to the database.
     */
    abstract public function connect() -> void;

    /**
     * Disconnects from the database.
     */
    abstract public function disconnect() -> void;

    /**
     * Gets the most recent error code.
     *
     * @return string|null
     */
    public function errorCode() -> string | null
    {
        this->connect();

        return this->pdo->errorCode();
    }

    /**
     * Gets the most recent error info.
     *
     * @return array
     */
    public function errorInfo() -> array
    {
        this->connect();

        return this->pdo->errorInfo();
    }

    /**
     * Executes an SQL statement and returns the number of affected rows. If
     * the profiler is enabled, the operation will be recorded.
     *
     * @param string $statement
     *
     * @return int
     */
    public function exec(string statement) -> int
    {
        var affectedRows;

        this->connect();
        this->profiler->start(__FUNCTION__);

        let affectedRows = this->pdo->exec(statement);

        this->profiler->finish(statement);

        return affectedRows;
    }

    /**
     * Performs a statement and returns the number of affected rows.
     *
     * @param string $statement
     * @param array  $values
     *
     * @return int
     */
    public function fetchAffected(string statement, array values = []) -> int
    {
        var sth;

        let sth = this->perform(statement, values);

        return sth->rowCount();
    }

    /**
     * Fetches a sequential array of rows from the database; the rows are
     * returned as associative arrays.
     *
     * @param string $statement
     * @param array  $values
     *
     * @return array
     */
    public function fetchAll(string statement, array values = []) -> array
    {
        return this->fetchData(
            "fetchAll",
            [\PDO::FETCH_ASSOC],
            statement,
            values
        );
    }

    /**
     * Fetches an associative array of rows from the database; the rows are
     * returned as associative arrays, and the array of rows is keyed on the
     * first column of each row.
     *
     * If multiple rows have the same first column value, the last row with
     * that value will overwrite earlier rows. This method is more resource
     * intensive and should be avoided if possible.
     *
     * @param string $statement
     * @param array  $values
     *
     * @return array
     */
    public function fetchAssoc(string statement, array values = []) -> array
    {
        var data, row, sth;

        let data = [],
            sth  = this->perform(statement, values);

        let row = sth->$fetch(\PDO::FETCH_ASSOC);
        while (row) {
            let data[current(row)] = row;
            let row = sth->$fetch(\PDO::FETCH_ASSOC);
        }

        return data;
    }

    /**
     * Fetches a column of rows as a sequential array (default first one).
     *
     * @param string $statement
     * @param array  $values
     * @param int    $column
     *
     * @return array
     */
    public function fetchColumn(
        string statement,
        array values = [],
        int column = 0
    ) -> array {
        return this->fetchData(
            "fetchAll",
            [\PDO::FETCH_COLUMN, column],
            statement,
            values
        );
    }

    /**
     * Fetches multiple from the database as an associative array. The first
     * column will be the index key. The default flags are
     * PDO::FETCH_ASSOC | PDO::FETCH_GROUP
     *
     * @param string $statement
     * @param array  $values
     * @param int    $flags
     *
     * @return array
     */
    public function fetchGroup(
        string statement,
        array values = [],
        int flags = \PDO::FETCH_ASSOC
    ) -> array {
        return this->fetchData(
            "fetchAll",
            [\PDO::FETCH_GROUP | flags],
            statement,
            values
        );
    }

    /**
     * Fetches one row from the database as an object where the column values
     * are mapped to object properties.
     *
     * Since PDO injects property values before invoking the constructor, any
     * initializations for defaults that you potentially have in your object's
     * constructor, will override the values that have been injected by
     * `fetchObject`. The default object returned is `\stdClass`
     *
     * @param string $statement
     * @param array  $values
     * @param string $class
     * @param array  $arguments
     *
     * @return object
     */
    public function fetchObject(
        string statement,
        array values = [],
        string className = "stdClass",
        array arguments = []
    ) -> object {
        var sth;

        let sth = this->perform(statement, values);

        return sth->fetchObject(className, arguments);
    }

    /**
     * Fetches a sequential array of rows from the database; the rows are
     * returned as objects where the column values are mapped to object
     * properties.
     *
     * Since PDO injects property values before invoking the constructor, any
     * initializations for defaults that you potentially have in your object's
     * constructor, will override the values that have been injected by
     * `fetchObject`. The default object returned is `\stdClass`
     *
     * @param string $statement
     * @param array  $values
     * @param string $class
     * @param array  $arguments
     *
     * @return array
     */
    public function fetchObjects(
        string statement,
        array values = [],
        string className = "stdClass",
        array arguments = []
    ) -> array {
        var sth;

        let sth = this->perform(statement, values);

        return sth->fetchAll(\PDO::FETCH_CLASS, className, arguments);
    }

    /**
     * Fetches one row from the database as an associative array.
     *
     * @param string $statement
     * @param array  $values
     *
     * @return array
     */
    public function fetchOne(string statement, array values = []) -> array
    {
        return this->fetchData(
            "fetch",
            [\PDO::FETCH_ASSOC],
            statement,
            values
        );
    }

    /**
     * Fetches an associative array of rows as key-value pairs (first column is
     * the key, second column is the value).
     *
     * @param string $statement
     * @param array  $values
     *
     * @return array
     */
    public function fetchPairs(string statement, array values = []) -> array
    {
        return this->fetchData(
            "fetchAll",
            [\PDO::FETCH_KEY_PAIR],
            statement,
            values
        );
    }

    /**
     * Fetches the very first value (i.e., first column of the first row).
     *
     * @param string $statement
     * @param array  $values
     *
     * @return mixed
     */
    public function fetchValue(string statement, array values = [])
    {
        var sth;

        let sth = this->perform(statement, values);

        return sth->fetchColumn(0);
    }

    /**
     * Return the inner PDO (if any)
     *
     * @return PDO
     */
    public function getAdapter() -> <\PDO>
    {
        this->connect();

        return this->pdo;
    }

    /**
     * Retrieve a database connection attribute
     *
     * @param int $attribute
     *
     * @return mixed
     */
    public function getAttribute(int attribute) -> var
    {
        this->connect();

        return this->pdo->getAttribute(attribute);
    }

    /**
     * Return an array of available PDO drivers (empty array if none available)
     *
     * @return array
     */
    public static function getAvailableDrivers() -> array
    {
        return \PDO::getAvailableDrivers();
    }

    /**
     * Return the driver name
     *
     * @return string
     */
    public function getDriverName() -> string
    {
        this->connect();

        return this->pdo->getAttribute(\PDO::ATTR_DRIVER_NAME);
    }

    /**
     * Returns the Profiler instance.
     *
     * @return ProfilerInterface
     */
    public function getProfiler() -> <ProfilerInterface>
    {
        return this->profiler;
    }

    /**
     * Gets the quote parameters based on the driver
     *
     * @param string $driver
     *
     * @return array
     */
    public function getQuoteNames(string driver = "") -> array
    {
        var option;
        array quotes;

        let option = driver;
        if empty option {
            let option = this->getDriverName();
        }

        switch option {
            case "mysql":
                let quotes = [
                    "prefix"  : "`",
                    "suffix"  : "`",
                    "find"    : "`",
                    "replace" : "``"
                ];
                break;

            case "sqlsrv":
                let quotes = [
                    "prefix"  : "[",
                    "suffix"  : "]",
                    "find"    : "]",
                    "replace" : "]["
                ];
                break;

            default:
                let quotes = [
                    "prefix"  : "\"",
                    "suffix"  : "\"",
                    "find"    : "\"",
                    "replace" : "\"\""
                ];
                break;
        }

        return quotes;
    }

    /**
     * Is a transaction currently active? If the profiler is enabled, the
     * operation will be recorded. If the profiler is enabled, the operation
     * will be recorded.
     *
     * @return bool
     */
    public function inTransaction() -> bool
    {
        var result;

        this->connect();
        this->profiler->start(__FUNCTION__);

        let result = this->pdo->inTransaction();

        this->profiler->finish();

        return result;
    }

    /**
     * Is the PDO connection active?
     *
     * @return bool
     */
    public function isConnected() -> bool
    {
        return (bool) this->pdo;
    }

    /**
     * Returns the last inserted autoincrement sequence value. If the profiler
     * is enabled, the operation will be recorded.
     *
     * @param string $name
     *
     * @return string
     */
    public function lastInsertId(string name = null) -> string
    {
        var result;

        this->connect();

        this->profiler->start(__FUNCTION__);

        let result = this->pdo->lastInsertId(name);

        this->profiler->finish();

        return (string) result;
    }

    /**
     * Performs a query with bound values and returns the resulting
     * PDOStatement; array values will be passed through `quote()` and their
     * respective placeholders will be replaced in the query string. If the
     * profiler is enabled, the operation will be recorded.
     *
     * @param string $statement
     * @param array  $values
     *
     * @return PDOStatement
     */
    public function perform(
        string statement,
        array values = []
    ) -> <\PDOStatement> {
        var name, sth, value;

        this->connect();

        this->profiler->start(__FUNCTION__);

        let sth = this->prepare(statement);
        for name, value in values {
            this->performBind(sth, name, value);
        }

        sth->execute();

        this->profiler->finish(statement, values);

        return sth;
    }

    /**
     * Prepares an SQL statement for execution.
     *
     * @param string $statement
     * @param array  $options
     *
     * @return PDOStatement|false
     */
    public function prepare(
        string statement,
        array options = []
    ) -> \PDOStatement | bool {
        var sth;

        this->connect();

        this->profiler->start(__FUNCTION__);

        let sth = this->pdo->prepare(statement, options);

        this->profiler->finish(sth->queryString);

        return sth;
    }

    /**
     * Queries the database and returns a PDOStatement. If the profiler is
     * enabled, the operation will be recorded.
     *
     * @param string $statement
     * @param mixed  ...$fetch
     *
     * @return PDOStatement|false
     */
    public function query(string statement) -> \PDOStatement | bool
    {
        var sth;

        this->connect();

        this->profiler->start(__FUNCTION__);

        let sth = call_user_func_array(
            [
                this->pdo,
                "query"
            ],
            func_get_args()
        );

        this->profiler->finish(sth->queryString);

        return sth;
    }

    /**
     * Quotes a value for use in an SQL statement. This differs from
     * `PDO::quote()` in that it will convert an array into a string of
     * comma-separated quoted values. The default type is `PDO::PARAM_STR`
     *
     * @param mixed $value
     * @param int   $type
     *
     * @return string The quoted value.
     */
    public function quote(var value, int type = \PDO::PARAM_STR) -> string
    {
        var element, key, quotes;
        array elements = [];

        this->connect();

        let element = value,
            quotes  = this->getQuoteNames();

        if typeof element !== "array" {
            let element = (string) element;

            return quotes["prefix"] . element . quotes["suffix"];
        }

        // quote array values, not keys, then combine with commas
        for key, element in value {
            let element       = (string) element,
                elements[key] = quotes["prefix"] . element . quotes["suffix"];
        }

        return implode(", ", elements);
    }

    /**
     * Rolls back the current transaction, and restores autocommit mode. If the
     * profiler is enabled, the operation will be recorded.
     *
     * @return bool
     */
    public function rollBack() -> bool
    {
        var result;

        this->connect();

        this->profiler->start(__FUNCTION__);

        let result = this->pdo->rollBack();

        this->profiler->finish();

        return result;
    }

    /**
     * Set a database connection attribute
     *
     * @param int   $attribute
     * @param mixed $value
     *
     * @return bool
     */
    public function setAttribute(int attribute, var value) -> bool
    {
        this->connect();

        return this->pdo->setAttribute(attribute, value);
    }

    /**
     * Sets the Profiler instance.
     *
     * @param ProfilerInterface $profiler
     */
    public function setProfiler(<ProfilerInterface> profiler)
    {
        let this->profiler = profiler;
    }

    /**
     * Bind a value using the proper PDO::PARAM_* type.
     *
     * @param PDOStatement $statement
     * @param mixed        $name
     * @param mixed        $arguments
     */
    protected function performBind(
        <\PDOStatement> statement,
        var name,
        var arguments
    ) -> void {
        var key, parameters, type;

        let key = name;
        if typeof key === "integer" {
            let key = key + 1;
        }

        if typeof arguments === "array" {
            if isset arguments[1] {
                let type = arguments[1];
            } else {
                let type = \PDO::PARAM_STR;
            }

            if type === \PDO::PARAM_BOOL && typeof arguments[0] === "boolean" {
                let arguments[0] = arguments[0] ? "1" : "0";
            }

            let parameters = array_merge([key], arguments);
        } else {
            let parameters = [key, arguments];
        }

        call_user_func_array(
            [
                statement,
                "bindValue"
            ],
            parameters
        );
    }

    /**
     * Helper method to get data from PDO based on the method passed
     *
     * @param string $method
     * @param array  $arguments
     * @param string $statement
     * @param array  $values
     *
     * @return array
     */
    protected function fetchData(
        string method,
        array arguments,
        string statement,
        array values = []
    ) -> array {
        var result, sth;

        let sth    = this->perform(statement, values),
            result = call_user_func_array(
                [
                    sth,
                    method
                ],
                arguments
            );

        /**
         * If this returns boolean or anything other than an array, return
         * an empty array back
         */
        if typeof result !== "array" {
            let result = [];
        }

        return result;
    }
}
