
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

namespace Phalcon\DM\Pdo\Connection;

use BadMethodCallException;
use PDO;
use PDOStatement;
use Phalcon\DM\Pdo\Exception\CannotBindValue;
use Phalcon\DM\Pdo\Parser\ParserInterface;
use Phalcon\DM\Pdo\Profiler\ProfilerInterface;

/**
 * Provides array quoting, profiling, a new `perform()` method, new `fetch*()`
 * methods
 *
 * @property array             $args
 * @property ParserInterface   $parser
 * @property PDO               $pdo
 * @property ProfilerInterface $profiler
 */
abstract class AbstractConnection implements ConnectionInterface
{
    /**
     * @var ParserInterface
     */
    protected parser;

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

            throw new BadMethodCallException($message);
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
     * @throws CannotBindValue
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
     * @throws CannotBindValue
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
     * @throws CannotBindValue
     */
    public function fetchAssoc(string statement, array values = []) -> array
    {
        var data, row, sth;

        let data = [],
            sth  = this->perform(statement, values);

        while (row = sth->$fetch(\PDO::FETCH_ASSOC)) {
            let data[current(row)] = row;
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
     * @throws CannotBindValue
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
     * @throws CannotBindValue
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
     * @throws CannotBindValue
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
     * @throws CannotBindValue
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
     * @throws CannotBindValue
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
     * @throws CannotBindValue
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
     * @throws CannotBindValue
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
    public function getAdapter() -> <PDO>
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
    public function getAttribute(int attribute)
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
     * Returns the Parser instance.
     *
     * @return ParserInterface
     */
    public function getParser() -> <ParserInterface>
    {
        return this->parser;
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

        let option = driver;
        if empty option {
            let option = this->getDriverName();
        }

        switch option {
            case "mysql":
                return [
                    "prefix"  : "`",
                    "suffix"  : "`",
                    "find"    : "`",
                    "replace" : "``",
                ];

            case "sqlsrv":
                return [
                    "prefix"  : "[",
                    "suffix"  : "]",
                    "find"    : "]",
                    "replace" : "][",
                ];

            default:
                return [
                    "prefix"  : "\"",
                    "suffix"  : "\"",
                    "find"    : "\"",
                    "replace" : "\"\"",
                ];
        }
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
     * @throws CannotBindValue
     */
    public function perform(string statement, array values = []) -> <PDOStatement>
    {
        var sth;

        this->connect();

        let sth = this->prepareWithValues(statement, values);

        this->profiler->start(__FUNCTION__);
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
    public function prepare(string statement, array options = [])
    {
        this->connect();

        return this->pdo->prepare(statement, options);
    }

    /**
     * Prepares an SQL statement with bound values. The method only binds values
     * that have associated placeholders in the statement. It also binds
     * sequential (question-mark) placeholders. If a placeholder is an array, it
     * is converted to a comma separated string to be used with a `IN`
     * condition.
     *
     * @param string $statement
     * @param array  $values
     *
     * @return PDOStatement|false
     * @throws CannotBindValue
     */
    public function prepareWithValues(string statement, array values = []) -> <PDOStatement>
    {
        var key, parser, parts, statement, value, values;
        array valueNames = [];

        // if there are no values to bind ...
        if empty values {
            // ... use the normal preparation
            return this->prepare(statement);
        }

        this->connect();

        let parser = clone this->parser;

        /**
         * $values can be an array with value in the first element and the type
         * in the second
         */
        for key, value in values {
            if typeof value === "array" {
                let valueNames[key] = value[0];
            } else {
                let valueNames[key] = value;
            }
        }

        let parts     = parser->rebuild(statement, valueNames),
            statement = parts[0],
            values    = parts[1],
            statement = this->pdo->prepare(statement);

        /**
         * Bind placeholders to values
         */
        for key, value in values {
            this->bindValue(statement, key, value);
        }

        return statement;
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
    public function query(string $statement)
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
        var element, key;
        array values;

        this->connect();

        // non-array quoting
        if typeof value !== "array" {
            return this->pdo->quote((string) value, type);
        }

        // quote array values, not keys, then combine with commas
        for key, element in value {
            let values[key] = this->pdo->quote((string) element, type);
        }

        return implode(", ", values);
    }

    /**
     * Quotes a multi-part (dotted) identifier name.
     *
     * @param string $name
     *
     * @return string
     */
    public function quoteName(string name) -> string
    {
        if (strpos(name, '.') === false) {
            return this->quoteSingleName(name);
        }

        return implode(
            ".",
            array_map(
                [
                    this,
                    "quoteSingleName"
                ],
                explode(".", $name)
            )
        );
    }

    /**
     * Quotes a single identifier name based on the driver
     *
     * @param string $name
     *
     * @return string
     */
    public function quoteSingleName(string name) -> string
    {
        var name, quote;

        let quote = this->getQuoteNames(),
            name  = str_replace(
                quote["find"],
                quote["replace"],
                name
            );

        return quote["prefix"] . name . quote["suffix"];
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
     * Sets the Parser instance.
     *
     * @param ParserInterface $parser
     */
    public function setParser(<ParserInterface> parser)
    {
        let this->parser = parser;
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
     * @param mixed        $key
     * @param mixed        $value
     *
     * @return bool
     * @throws CannotBindValue
     */
    protected function bindValue(<PDOStatement> statement, var key, var value) -> bool
    {
        var type;

        if typeof value === "integer" {
            return statement->bindValue(key, value, \PDO::PARAM_INT);
        }

        if typeof value === "boolean" {
            return statement->bindValue(key, value, \PDO::PARAM_BOOL);
        }

        if null === value {
            return statement->bindValue(key, value, \PDO::PARAM_NULL);
        }

        if !is_scalar(value) {
            let type = gettype(value);
            throw new CannotBindValue(
                "Cannot bind value of type '" . type .
                "' to placeholder '" . key . "'"
            );
        }

        return statement->bindValue(key, value);
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
     * @throws CannotBindValue
     */
    protected function fetchData(
        string method,
        array arguments,
        string statement,
        array values = []
    ) {
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

    /**
     * Returns a new Parser instance.
     *
     * @param string $driver
     *
     * @return ParserInterface
     */
    protected function newParser(string driver) -> <ParserInterface>
    {
        var definition;

        let definition = sprintf(
            "\\Phalcon\\DM\Pdo\\Parser\\%sParser",
            ucfirst(driver)
        );

        return create_instance(definition);
    }
}
