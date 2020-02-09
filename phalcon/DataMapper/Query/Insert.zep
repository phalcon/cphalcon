
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

use BadMethodCallException;
use Phalcon\DataMapper\Pdo\Connection;

/**
 * Class Insert
 */
class Insert extends AbstractQuery
{
    /**
     * Insert constructor.
     *
     * @param Connection $connection
     * @param Bind       $bind
     */
    public function __construct(<Connection> connection, <Bind> bind)
    {
        parent::__construct(connection, bind);

        let this->store["FROM"]      = "",
            this->store["RETURNING"] = [];
    }

    /**
     * Sets a column for the `INSERT` query
     *
     * @param string $column
     *
     * @return this
     */
    public function column(string column, var value = null, int type = -1) -> <Insert>
    {
        let this->store["COLUMNS"][column] = ":" . column;

        if null !== value {
            this->bind->setValue(column, value, type);
        }

        return this;
    }

    /**
     * Mass sets columns and values for the `INSERT`
     *
     * @param array $columns
     *
     * @return this
     */
    public function columns(array columns) -> <Insert>
    {
        var column, value;

        for column, value in columns {
            if typeof column === "integer" {
                this->column(value);
            } else {
                this->column(column, value);
            }
        }

        return this;
    }

    /**
     * Adds table(s) in the query
     *
     * @param string $table
     *
     * @return Insert
     */
    public function into(string table) -> <Insert>
    {
        let this->store["FROM"] = table;

        return this;
    }

    /**
     * Returns the id of the last inserted record
     *
     * @param string|null $name
     *
     * @return string
     */
    public function getLastInsertId(string name = null) -> string
    {
        return this->connection->lastInsertId(name);
    }

    /**
     * @return string
     */
    public function getStatement() -> string
    {
        return "INSERT"
            . this->buildFlags()
            . " INTO " . this->store["FROM"]
            . this->buildColumns()
            . this->buildReturning();
    }

    /**
     * Adds the `RETURNING` clause
     *
     * @param string ...$columns
     *
     * @return Insert
     */
    public function returning() -> <Insert>
    {
        let this->store["RETURNING"] = array_merge(
            this->store["RETURNING"],
            func_get_args()
        );

        return this;
    }

    /**
     * Resets the internal store
     */
    public function reset() -> void
    {
        parent::reset();

        let this->store["FROM"]      = "",
            this->store["RETURNING"] = [];
    }

    /**
     * Sets a column = value condition
     *
     * @param string     $column
     * @param mixed|null $value
     *
     * @return Insert
     */
    public function set(string column, var value = null) -> <Insert>
    {
        if null === value {
            let value = "NULL";
        }

        let this->store["COLUMNS"][column] = value;

        this->bind->remove(column);

        return this;
    }

    /**
     * Builds the column list
     *
     * @return string
     */
    private function buildColumns() -> string
    {
        var column;
        array columns = [];

        for column, _ in this->store["COLUMNS"] {
            let columns[] = this->quoteIdentifier(column);
        }

        return " ("
            . ltrim(this->indent(columns, ","))
            . ") VALUES ("
            . ltrim(this->indent(array_values(this->store["COLUMNS"]), ","))
            . ")";
    }
}
