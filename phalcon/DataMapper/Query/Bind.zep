
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

use Phalcon\Contracts\DataMapper\DataMapperTypes;

/**
 * Class Bind
 *
 * @phpstan-import-type datamapper_bind_store from DataMapperTypes
 * @phpstan-import-type datamapper_bind_values from DataMapperTypes
 * @phpstan-import-type datamapper_values from DataMapperTypes
 */
class Bind
{
    /**
     * @var int
     */
    protected inlineCount = 0;

    /**
     * @var array
     *
     * @phpstan-var datamapper_bind_store
     */
    protected store = [];

    /**
     * @param mixed $value
     * @param int   $type
     *
     * @return string
     */
    public function bindInline(var value, int type = -1) -> string
    {
        var key;

        if typeof value === "object" && value instanceof Select {
            return "(" . value->getStatement() . ")";
        }

        if typeof value === "array" {
            return this->inlineArray(value, type);
        }

        let this->inlineCount = this->inlineCount + 1;

        let key = "__" . this->inlineCount . "__";

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
        var store;

        let store = this->store;

        unset store[key];

        let this->store = store;
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
        var localType;

        let localType = type;
        if localType === -1 {
            let localType = this->getType(value);
        }

        let this->store[key] = [value, localType];
    }

    /**
     * Sets values from an array
     *
     * @param array $values
     * @param int   $type
     *
     * @phpstan-param datamapper_bind_values $values
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
     *
     * @phpstan-return datamapper_bind_store
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
     *
     * @phpstan-param datamapper_values $data
     */
    protected function inlineArray(array data, int type) -> string
    {
        var key, value;
        array keys = [];

        for value in data {
            let this->inlineCount = this->inlineCount + 1;

            let key = "__" . this->inlineCount . "__";

            this->setValue(key, value, type);

            let keys[] = ":" . key;
        }

        return "(" . implode(", ", keys) . ")";
    }
}
