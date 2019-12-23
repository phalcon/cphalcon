
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\JWT\Token;

/**
 * Class Item
 */
class Item extends AbstractItem
{
    /**
     * Item constructor.
     *
     * @param array  $payload
     * @param string $encoded
     */
    public function __construct(array! payload, string! encoded)
    {
        let this->data["encoded"] = encoded,
            this->data["payload"] = payload;
    }

    /**
     * @param string     $name
     * @param mixed|null $defaultValue
     *
     * @return mixed|null
     */
    public function get(string! name, var defaultValue = null) -> var | null
    {
        if !this->has(name) {
            return defaultValue;
        }

        return this->data["payload"][name];
    }

    /**
     * @return array
     */
    public function getPayload() -> array
    {
        return this->data["payload"];
    }

    /**
     * @param string $name
     *
     * @return bool
     */
    public function has(string! name) -> bool
    {
        return isset this->data["payload"][name];
    }
}
