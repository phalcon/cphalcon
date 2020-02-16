
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
use Phalcon\Helper\Arr;

/**
 * Class Select
 *
 * @property string $asAlias
 * @property bool   $forUpdate
 *
 * @method int    fetchAffected()
 * @method array  fetchAll()
 * @method array  fetchAssoc()
 * @method array  fetchColumn(int $column = 0)
 * @method array  fetchGroup(int $flags = PDO::FETCH_ASSOC)
 * @method object fetchObject(string $class = 'stdClass', array $arguments = [])
 * @method array  fetchObjects(string $class = 'stdClass', array $arguments = [])
 * @method array  fetchOne()
 * @method array  fetchPairs()
 * @method mixed  fetchValue()
 */
class Select extends AbstractConditions
{
    const JOIN_INNER   = "INNER";
    const JOIN_LEFT    = "LEFT";
    const JOIN_NATURAL = "NATURAL";
    const JOIN_RIGHT   = "RIGHT";

    /**
     * @var string
     */
    protected asAlias = "";

    /**
     * @var bool
     */
    protected forUpdate = false;

    /**
     * Proxied methods to the connection
     *
     * @param string $method
     * @param array  $params
     *
     * @return mixed
     */
    public function __call(string method, array params)
    {
        array proxied;

        let proxied = [
            "fetchAffected" : true,
            "fetchAll"      : true,
            "fetchAssoc"    : true,
            "fetchCol"      : true,
            "fetchGroup"    : true,
            "fetchObject"   : true,
            "fetchObjects"  : true,
            "fetchOne"      : true,
            "fetchPairs"    : true,
            "fetchValue"    : true
        ];

        if likely isset proxied[method] {
            return call_user_func_array(
                [
                    this->connection,
                    method
                ],
                array_merge(
                    [
                        this->getStatement(),
                        this->getBindValues()
                    ],
                    params
                )
            );
        }

        throw new BadMethodCallException(
            "Unknown method: [" . method . "]"
        );
    }

    /**
     * Sets a `AND` for a `HAVING` condition
     *
     * @param string     $condition
     * @param mixed|null $value
     * @param int        $type
     *
     * @return Select
     */
    public function andHaving(
        string condition,
        var value = null,
        int type = -1
    ) -> <Select> {
        this->having(condition, value, type);

        return this;
    }

    /**
     * The `AS` statement for the query - useful in sub-queries
     *
     * @param string $asAlias
     *
     * @return Select
     */
    public function asAlias(string asAlias) -> <Select>
    {
        let this->asAlias = asAlias;

        return this;
    }

    /**
     * Concatenates to the most recent `HAVING` clause
     *
     * @param string     $condition
     * @param mixed|null $value
     * @param int        $type
     *
     * @return Select
     */
    public function catHaving(
        string condition,
        var value = null,
        int type = -1
    ) -> <Select> {
        this->appendCondition("HAVING", condition, value, type);

        return this;
    }

    /**
     * Concatenates to the most recent `JOIN` clause
     *
     * @param string     $condition
     * @param mixed|null $value
     * @param int        $type
     *
     * @return Select
     */
    public function catJoin(
        string condition,
        var value = null,
        int type = -1
    ) -> <Select> {
        var end, key;

        if !empty value {
            let condition .= this->bind->bindInline(value, type);
        }

        let end = Arr::lastKey(this->store["FROM"]),
            key = Arr::lastKey(this->store["FROM"][end]);

        let this->store["FROM"][end][key] = this->store["FROM"][end][key] . condition;

        return this;
    }

    /**
     * The columns to select from. If a key is set in an array element, the
     * key will be used as the alias
     *
     * @param string ...$column
     *
     * @return Select
     */
    public function columns() -> <Select>
    {
        let this->store["COLUMNS"] = array_merge(
            this->store["COLUMNS"],
            func_get_args()
        );

        return this;
    }

    /**
     * @param bool $enable
     *
     * @return Select
     */
    public function distinct(bool enable = true) -> <Select>
    {
        this->setFlag("DISTINCT", enable);

        return this;
    }

    /**
     * Adds table(s) in the query
     *
     * @param string $table
     *
     * @return Select
     */
    public function from(string table) -> <Select>
    {
        let this->store["FROM"][] = [table];

        return this;
    }

    /**
     * Enable the `FOR UPDATE` for the query
     *
     * @param bool $enable
     *
     * @return Select
     */
    public function forUpdate(bool enable = true) -> <Select>
    {
        let this->forUpdate = enable;

        return this;
    }

    /**
     * Returns the compiled SQL statement
     *
     * @return string
     */
    public function getStatement() -> string
    {
        return implode("", this->store["UNION"]) . this->getCurrentStatement();
    }

    /**
     * Sets the `GROUP BY`
     *
     * @param array|string $groupBy
     *
     * @return Select
     */
    public function groupBy(var groupBy) -> <Select>
    {
        this->processValue("GROUP", groupBy);

        return this;
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
     * Sets a `HAVING` condition
     *
     * @param string     $condition
     * @param mixed|null $value
     * @param int        $type
     *
     * @return Select
     */
    public function having(
        string condition,
        var value = null,
        int type = -1
    ) -> <Select> {
        this->addCondition("HAVING", "AND ", condition, value, type);

        return this;
    }

    /**
     * Sets a 'JOIN' condition
     *
     * @param string     $join
     * @param string     $table
     * @param string     $condition
     * @param mixed|null $value
     * @param int        $type
     *
     * @return Select
     */
    public function join(
        string join,
        string table,
        string condition,
        var value = null,
        int type = -1
    ) -> <Select> {
        var key;

        let join = strtoupper(trim(join));
        if substr(join, -4) !== "JOIN" {
            let join .= " JOIN";
        }

        let condition = ltrim(condition);

        if (
            "" !== condition
            && strtoupper(substr(condition, 0, 3)) !== "ON "
            && strtoupper(substr(condition, 0, 6)) !== "USING "
        ) {
            let condition = "ON " . condition;
        }

        if !empty value {
            let condition .= this->bind->bindInline(value, type);
        }

        let key = Arr::lastKey(this->store["FROM"]);

        let this->store["FROM"][key][] = join . " " . table . " " . condition;

        return this;
    }

    /**
     * Sets a `OR` for a `HAVING` condition
     *
     * @param string     $condition
     * @param mixed|null $value
     * @param int        $type
     *
     * @return Select
     */
    public function orHaving(
        string condition,
        var value = null,
        int type = -1
    ) -> <Select> {
        this->addCondition("HAVING", "OR ", condition, value, type);

        return this;
    }

    /**
     * Resets the internal collections
     *
     * @return Select
     */
    public function reset() -> <Select>
    {
        parent::reset();

        let this->asAlias   = "",
            this->forUpdate = false;

        return this;
    }

    /**
     * Start a sub-select
     *
     * @return Select
     */
    public function subSelect() -> <Select>
    {
        return new Select(this->connection, this->bind);
    }

    /**
     * Start a `UNION`
     *
     * @return Select
     */
    public function union() -> <Select>
    {
        let this->store["UNION"][] = this->getCurrentStatement(" UNION ");

        this->reset();

        return this;
    }

    /**
     * Start a `UNION ALL`
     *
     * @return Select
     */
    public function unionAll() -> <Select>
    {
        let this->store["UNION"][] = this->getCurrentStatement(" UNION ALL ");

        this->reset();

        return this;
    }

    /**
     * Statement builder
     *
     * @param string $suffix
     *
     * @return string
     */
    protected function getCurrentStatement(string suffix = "") -> string
    {
        var statement;
        string forUpdate = "";

        if this->forUpdate {
            let forUpdate = " FOR UPDATE";
        }

        let statement = "SELECT"
            . this->buildFlags()
            . this->buildLimitEarly()
            . this->buildColumns()
            . this->buildFrom()
            . this->buildCondition("WHERE")
            . this->buildBy("GROUP")
            . this->buildCondition("HAVING")
            . this->buildBy("ORDER")
            . this->buildLimit()
            . forUpdate;

        if unlikely ("" !== this->asAlias) {
            let statement = "(" . statement . ") AS " . this->asAlias;
        }

        return statement . suffix;
    }

    /**
     * Builds the columns list
     *
     * @return string
     */
    private function buildColumns() -> string
    {
        var columns;

        if !this->hasColumns() {
            let columns = ["*"];
        } else {
            let columns = this->store["COLUMNS"];
        }

        return this->indent(columns, ",");
    }

    /**
     * Builds the from list
     *
     * @return string
     */
    private function buildFrom() -> string
    {
        var table;
        array from = [];

        if empty this->store["FROM"] {
            return "";
        }

        for table in this->store["FROM"] {
            let from[] = array_shift(table) . this->indent(table);
        }

        return " FROM" . this->indent(from, ",");
    }
}
