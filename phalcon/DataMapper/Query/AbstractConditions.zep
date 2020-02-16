
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

use Phalcon\Helper\Arr;

/**
 * Class AbstractConditions
 */
abstract class AbstractConditions extends AbstractQuery
{
    /**
     * Sets the `LIMIT` clause
     *
     * @param int $limit
     *
     * @return AbstractConditions
     */
    public function limit(int limit) -> <AbstractConditions>
    {
        let this->store["LIMIT"] = limit;

        return this;
    }

    /**
     * Sets the `OFFSET` clause
     *
     * @param int $offset
     *
     * @return AbstractConditions
     */
    public function offset(int offset) -> <AbstractConditions>
    {
        let this->store["OFFSET"] = offset;

        return this;
    }

    /**
     * Sets a `AND` for a `WHERE` condition
     *
     * @param string     $condition
     * @param mixed|null $value
     * @param int        $type
     *
     * @return AbstractConditions
     */
    public function andWhere(
        string condition,
        var value = null,
        int type = -1
    ) -> <AbstractConditions> {
        this->where(condition, value, type);

        return this;
    }

    /**
     * Concatenates to the most recent `WHERE` clause
     *
     * @param string     $condition
     * @param mixed|null $value
     * @param int        $type
     *
     * @return AbstractConditions
     */
    public function appendWhere(
        string condition,
        var value = null,
        int type = -1
    ) -> <AbstractConditions> {
        this->appendCondition("WHERE", condition, value, type);

        return this;
    }

    /**
     * Sets the `ORDER BY`
     *
     * @param array|string $orderBy
     *
     * @return AbstractConditions
     */
    public function orderBy(var orderBy) -> <AbstractConditions>
    {
        this->processValue("ORDER", orderBy);

        return this;
    }

    /**
     * Sets a `OR` for a `WHERE` condition
     *
     * @param string     $condition
     * @param mixed|null $value
     * @param int        $type
     *
     * @return AbstractConditions
     */
    public function orWhere(
        string condition,
        var value = null,
        int type = -1
    ) -> <AbstractConditions> {
        this->addCondition("WHERE", "OR ", condition, value, type);

        return this;
    }

    /**
     * Sets a `WHERE` condition
     *
     * @param string     $condition
     * @param mixed|null $value
     * @param int        $type
     *
     * @return AbstractConditions
     */
    public function where(
        string condition,
        var value = null,
        int type = -1
    ) -> <AbstractConditions> {
        this->addCondition("WHERE", "AND ", condition, value, type);

        return this;
    }

    /**
     * @param array $columnsValues
     *
     * @return AbstractConditions
     */
    public function whereEquals(array columnsValues) -> <AbstractConditions>
    {
        var key, value;

        for key, value in columnsValues {
            if is_numeric(key) {
                this->where(value);
            } elseif null === value {
                this->where(key . " IS NULL");
            } elseif typeof value === "array"  {
                this->where(key . " IN ", value);
            } else {
                this->where(key . " = ", value);
            }
        }

        return this;
    }

    /**
     * Appends a conditional
     *
     * @param string     $store
     * @param string     $andor
     * @param string     $condition
     * @param mixed|null $value
     * @param int        $type
     */
    protected function addCondition(
        string store,
        string andor,
        string condition,
        var value = null,
        int type = -1
    ) -> void {
        if !empty value {
            let condition .= this->bindInline(value, type);
        }

        if empty this->store[store] {
            let andor = "";
        }

        let this->store[store][] = andor . condition;
    }

    /**
     * Builds a `BY` list
     *
     * @param string $type
     *
     * @return string
     */
    protected function buildBy(string type) -> string
    {
        if empty this->store[type] {
            return "";
        }

        return " " . type . " BY"
            . this->indent(this->store[type], ",");
    }

    /**
     * Builds the conditional string
     *
     * @param string $type
     *
     * @return string
     */
    protected function buildCondition(string type) -> string
    {
        if empty this->store[type] {
            return "";
        }

        return " " . type
            . this->indent(this->store[type]);
    }

    /**
     * Builds the early `LIMIT` clause - MS SQLServer
     *
     * @return string
     */
    protected function buildLimitEarly() -> string
    {
        string limit = "";

        if (
            "sqlsrv" === this->connection->getDriverName() &&
            this->store["LIMIT"] > 0 &&
            0 === this->store["OFFSET"]
        ) {
            let limit = " TOP " . this->store["LIMIT"];
        }

        return limit;
    }

    /**
     * Builds the `LIMIT` clause
     *
     * @return string
     */
    protected function buildLimit() -> string
    {
        var method, suffix;

        let suffix = this->connection->getDriverName();

        if "sqlsrv" !== suffix {
            let suffix = "common";
        }

        let method = "buildLimit" . ucfirst(suffix);

        return this->{method}();
    }

    /**
     * Builds the `LIMIT` clause for all drivers
     *
     * @return string
     */

    protected function buildLimitCommon() -> string
    {
        string limit = "";

        if 0 !== this->store["LIMIT"] {
            let limit .= "LIMIT " . this->store["LIMIT"];
        }

        if 0 !== this->store["OFFSET"] {
            let limit .= " OFFSET " . this->store["OFFSET"];
        }

        if "" !== limit {
            let limit = " " . ltrim(limit);
        }

        return limit;
    }

    /**
     * Builds the `LIMIT` clause for MSSQLServer
     *
     * @return string
     */
    protected function buildLimitSqlsrv() -> string
    {
        string limit = "";

        if this->store["LIMIT"] > 0 && this->store["OFFSET"] > 0 {
            let limit = " OFFSET " . this->store["OFFSET"] . " ROWS"
                . " FETCH NEXT " . this->store["LIMIT"] . " ROWS ONLY";
        }

        return limit;
    }

    /**
     * Concatenates a conditional
     *
     * @param string $store
     * @param string $condition
     * @param mixed  $value
     * @param int    $type
     */
    protected function appendCondition(
        string store,
        string condition,
        var value = null,
        int type = -1
    ) -> void {
        var key;

        if !empty value {
            let condition .= this->bindInline(value, type);
        }

        if empty this->store[store] {
            let this->store[store][] = "";
        }

        let key = Arr::lastKey(this->store[store]);

        let this->store[store][key] = this->store[store][key] . condition;
    }

    /**
     * Processes a value (array or string) and merges it with the store
     *
     * @param string       $store
     * @param array|string $data
     */
    protected function processValue(string store, var data) -> void
    {
        if typeof data === "string" {
            let data = [data];
        }

        if typeof data === "array" {
            let this->store[store] = array_merge(
                this->store[store],
                data
            );
        }
    }
}
