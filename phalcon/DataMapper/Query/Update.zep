
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
 * Class Update
 */
class Update extends AbstractConditions
{
    /**
     * Update constructor.
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
     * Sets a column for the `UPDATE` query
     *
     * @param string $column
     *
     * @return this
     */
    public function column() -> <Update>
    {
        var arguments, column, type, value;

        let arguments = func_get_args();

        if (0 === count(arguments)) {
            throw new BadMethodCallException(
                "The column name must be specified"
            );
        }

        let column = arguments[0];

        let this->store["COLUMNS"][column] = ":" . column;

        if isset(arguments[1]) && !empty(arguments[1]) {
            let value = $arguments[1],
                type  = -1;
            if isset arguments[2] {
                let type = arguments[2];
            }

            this->bind->setValue(column, value, type);
        }

        return this;
    }

    /**
     * Mass sets columns and values for the `UPDATE`
     *
     * @param array $columns
     *
     * @return this
     */
    public function columns(array columns) -> <Update>
    {
        var column, value;

        for column, value in columns {
            if typeof column === "integer" {
                call_user_func_array(
                    [
                        this,
                        "column"
                    ],
                    [
                        value
                    ]
                );
            } else {
                call_user_func_array(
                    [
                        this,
                        "column"
                    ],
                    [
                        column,
                        value
                    ]
                );
            }
        }
        return this;
    }

    /**
     * Adds table(s) in the query
     *
     * @param string $table
     *
     * @return Update
     */
    public function from(string table) -> <Update>
    {
        let this->store["FROM"] = table;

        return this;
    }

    /**
     * @return string
     */
    public function getStatement() -> string
    {
        return "UPDATE"
            . this->buildFlags()
            . " " . this->store["FROM"]
            . this->buildColumns()
            . this->buildCondition("WHERE")
            . this->buildReturning();
    }

    /**
     * Whether the query has columns or not
     *
     * @return bool
     */
    public function hasColumns() -> bool
    {
        return count(this->store["COLUMNS"]) > 0;
    }

    /**
     * Adds the `RETURNING` clause
     *
     * @param string ...$columns
     *
     * @return Update
     */
    public function returning() -> <Update>
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
     * @return Update
     */
    public function set(string column, var value = null) -> <Update>
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
        var column, value;
        array assignments = [];

        for column, value in this->store["COLUMNS"] {
            let assignments[] = this->quoteIdentifier(column) . " = " . value;
        }

        return " SET" . this->indent(assignments, ",");
    }
}
