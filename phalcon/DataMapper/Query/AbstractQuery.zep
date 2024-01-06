
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
 * @link    https://github.com/atlasphp/Atlas.Query
 * @license https://github.com/atlasphp/Atlas.Qyert/blob/1.x/LICENSE.md
 */

namespace Phalcon\DataMapper\Query;

use Phalcon\DataMapper\Pdo\Connection;

/**
 * Class AbstractQuery
 */
abstract class AbstractQuery
{
    /**
     * @var Bind
     */
    protected bind;

    /**
     * @var Connection
     */
    protected connection;

    /**
     * @var array
     */
    protected store = [];

    /**
     * AbstractQuery constructor.
     *
     * @param Connection $connection
     * @param Bind       $bind
     */
    public function __construct(<Connection> connection, <Bind> bind)
    {
        let this->bind           = bind,
            this->connection     = connection,
            this->store["UNION"] = [];

        this->reset();
    }

    /**
     * Binds a value inline
     *
     * @param mixed $value
     * @param int   $type
     *
     * @return string
     */
    public function bindInline(var value, int type = -1) -> string
    {
        return this->bind->bindInline(value, type);
    }

    /**
     * Binds a value - auto-detects the type if necessary
     *
     * @param string $key
     * @param mixed  $value
     * @param int    $type
     *
     * @return AbstractQuery
     */
    public function bindValue(
        string key,
        var value,
        int type = -1
    ) -> <AbstractQuery> {
        this->bind->setValue(key, value, type);

        return this;
    }

    /**
     * Binds an array of values
     *
     * @param array $values
     *
     * @return AbstractQuery
     */
    public function bindValues(array values) -> <AbstractQuery>
    {
        this->bind->setValues(values);

        return this;
    }

    /**
     * Returns all the bound values
     *
     * @return array
     */
    public function getBindValues() -> array
    {
        return this->bind->toArray();
    }

    /**
     * Return the generated statement
     *
     * @return string
     */
    abstract public function getStatement() -> string;

    /**
     * Performs a statement in the connection
     *
     * @return \PDOStatement
     */
    public function perform()
    {
        return this->connection->perform(
            this->getStatement(),
            this->getBindValues()
        );
    }

    /**
     * Sets a flag for the query such as "DISTINCT"
     *
     * @param string $flag
     * @param bool   $enable
     */
    public function setFlag(string flag, bool enable = true) -> void
    {
        var flags;

        if enable {
            let this->store["FLAGS"][flag] = true;
        } else {
            let flags = this->store["FLAGS"];

            unset flags[flag];

            let this->store["FLAGS"] = flags;
        }
    }

    /**
     * Quotes the identifier
     *
     * @param string $name
     * @param int    $type
     *
     * @return string
     */
    public function quoteIdentifier(
        string name,
        int type = \PDO::PARAM_STR
    ) -> string {
        return this->connection->quote(name, type);
    }

    /**
     * Resets the internal array
     */
    public function reset() -> <AbstractQuery>
    {
        let this->store["COLUMNS"] = [],
            this->store["FLAGS"]   = [],
            this->store["FROM"]    = [],
            this->store["GROUP"]   = [],
            this->store["HAVING"]  = [],
            this->store["LIMIT"]   = 0,
            this->store["ORDER"]   = [],
            this->store["OFFSET"]  = 0,
            this->store["WHERE"]   = [];

        return this;
    }

    /**
     * Resets the columns
     */
    public function resetColumns() -> <AbstractQuery>
    {
        let this->store["COLUMNS"] = [];

        return this;
    }

    /**
     * Resets the from
     */
    public function resetFrom() -> <AbstractQuery>
    {
        let this->store["FROM"] = [];

        return this;
    }

    /**
     * Resets the where
     */
    public function resetWhere() -> <AbstractQuery>
    {
        let this->store["WHERE"] = [];

        return this;
    }

    /**
     * Resets the group by
     */
    public function resetGroupBy() -> <AbstractQuery>
    {
        let this->store["GROUP"] = [];

        return this;
    }

    /**
     * Resets the having
     */
    public function resetHaving() -> <AbstractQuery>
    {
        let this->store["HAVING"] = [];

        return this;
    }

    /**
     * Resets the order by
     */
    public function resetOrderBy() -> <AbstractQuery>
    {
        let this->store["ORDER"] = [];

        return this;
    }

    /**
     * Resets the limit and offset
     */
    public function resetLimit() -> <AbstractQuery>
    {
        let this->store["LIMIT"]  = 0,
            this->store["OFFSET"] = 0;

        return this;
    }

    /**
     * Resets the flags
     */
    public function resetFlags() -> <AbstractQuery>
    {
        let this->store["FLAGS"] = [];

        return this;
    }

    /**
     * Builds the flags statement(s)
     *
     * @return string
     */
    protected function buildFlags()
    {
        if  empty this->store["FLAGS"] {
            return "";
        }

        return " " . implode(" ", array_keys(this->store["FLAGS"]));
    }

    /**
     * Builds the `RETURNING` clause
     *
     * @return string
     */
    protected function buildReturning() -> string
    {
        if empty this->store["RETURNING"] {
            return "";
        }

        return " RETURNING" . this->indent(this->store["RETURNING"], ",");
    }

    /**
     * Indents a collection
     *
     * @param array  $collection
     * @param string $glue
     *
     * @return string
     */
    protected function indent(array collection, string glue = "") -> string
    {
        if empty collection {
            return "";
        }

        return " " . implode(glue . " ", collection);
    }
}
