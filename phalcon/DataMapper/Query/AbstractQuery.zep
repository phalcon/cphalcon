
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

use PDO;
use PDOStatement;
use Phalcon\DataMapper\Pdo\Connection;

/**
 * Class AbstractQuery
 */
abstract class AbstractQuery
{
    protected <Bind> bind;
    protected <Connection> connection;
    protected array store = [];

    /**
     * AbstractQuery constructor.
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
     */
    public function bindInline(var value, int type = -1) -> string
    {
        return this->bind->bindInline(value, type);
    }

    /**
     * Binds a value - auto-detects the type if necessary
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
     */
    public function bindValues(array values) -> <AbstractQuery>
    {
        this->bind->setValues(values);

        return this;
    }

    /**
     * Returns all the bound values
     */
    public function getBindValues() -> array
    {
        return this->bind->toArray();
    }

    /**
     * Return the generated statement
     */
    abstract public function getStatement() -> string;

    /**
     * Performs a statement in the connection
     */
    public function perform() -> <PDOStatement>
    {
        return this->connection->perform(
            this->getStatement(),
            this->getBindValues()
        );
    }

    /**
     * Quotes the identifier
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
    public function reset() -> void
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
    }

    /**
     * Resets the columns
     */
    public function resetColumns() -> void
    {
        let this->store["COLUMNS"] = [];
    }

    /**
     * Resets the flags
     */
    public function resetFlags() -> void
    {
        let this->store["FLAGS"] = [];
    }

    /**
     * Resets the from
     */
    public function resetFrom() -> void
    {
        let this->store["FROM"] = [];
    }

    /**
     * Resets the group by
     */
    public function resetGroupBy() -> void
    {
        let this->store["GROUP"] = [];
    }

    /**
     * Resets the having
     */
    public function resetHaving() -> void
    {
        let this->store["HAVING"] = [];
    }

    /**
     * Resets the limit and offset
     */
    public function resetLimit() -> void
    {
        let this->store["LIMIT"]  = 0,
            this->store["OFFSET"] = 0;
    }

    /**
     * Resets the order by
     */
    public function resetOrderBy() -> void
    {
        let this->store["ORDER"] = [];
    }

    /**
     * Resets the where
     */
    public function resetWhere() -> void
    {
        let this->store["WHERE"] = [];
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
