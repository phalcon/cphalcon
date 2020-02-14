
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Security\JWT\Token;

/**
 * Class Item
 */
class Signature extends AbstractItem
{
    /**
     * Signature constructor.
     *
     * @param string $hash
     * @param string $encoded
     */
    public function __construct(string! hash = "", string! encoded = "")
    {
        let this->data["encoded"] = encoded,
            this->data["hash"]    = hash;
    }

    /**
     * @return string
     */
    public function getHash() -> string
    {
        return this->data["hash"];
    }
}
