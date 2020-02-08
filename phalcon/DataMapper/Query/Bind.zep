
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

namespace Phalcon\DM\Query;

use PDO;

/**
 * Class Bind
 *
 * @property int   $bindCount
 * @property array $store
 */
class Bind
{
    /**
     * @var int
     */
    protected bindCount = 0;

    /**
     * @var array
     */
    protected store = [];

    /**
     * @param mixed $value
     * @param int   $type
     *
     * @return string
     */
    public function bind(var value, int type = -1) -> string
    {
        if value instanceof Select {
            return "(" . value->getStatement() . ")";
        }

        if typeof value === "array" {
            return this->bindArray(value, type);
        }

        let this->bindCount = this->bindCount + 1,
            key             = "__" . this->bindCount . "__";

        this->setValue(key, value, type);

        return ":" . key;
    }

    /**
     * Removes a value from the store
     *
     * @param string $key
     */
    public function remove(string key) -> void
    {
        unset this->store[key];
    }

    /**
     * Sets a value
     *
     * @param string $key
     * @param mixed  $value
     * @param int    $type
     */
    public function setValue(string key, var value, int type = -1) -> void
    {
        if type === -1 {
            let type = this->getType(value);
        }

        let this->store[key] = [value, type];
    }

    /**
     * Sets values from an array
     *
     * @param array $values
     * @param int   $type
     */
    public function setValues(array values, int type = -1) -> void
    {
        var key, value;

        for key, value in values {
            this->setValue(key, value, type);
        }
    }

    /**
     * Returns the internal collection
     *
     * @return array
     */
    public function toArray() -> array
    {
        return this->store;
    }

    /**
     * Auto detects the PDO type
     *
     * @param mixed $value
     *
     * @return int
     */
    protected function getType(var value) -> int
    {
        if null === value {
            return \PDO::PARAM_NULL;
        }

        if typeof value === "boolean" {
            return \PDO::PARAM_BOOL;
        }

        if typeof value === "integer" {
            return \PDO::PARAM_INT;
        }

        return \PDO::PARAM_STR;
    }

    /**
     * Processes an array - if passed as an `inline` parameter
     *
     * @param array $array
     * @param int   $type
     *
     * @return string
     */
    protected function bindArray(array data, int type) -> string
    {
        var key, value;
        array keys;

        let keys = [];
        for value in data {
            let this->bindCount = this->bindCount + 1,
                key             = "__" . this->bindCount . "__";

            this->setValue(key, value, type);

            let keys[] = ":" . key;
        }

        return "(" . implode(", ", keys) . ")";
    }
}
