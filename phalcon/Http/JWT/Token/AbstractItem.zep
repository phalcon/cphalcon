
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
 * Class AbstractItem
 *
 * @property array $data
 */
abstract class AbstractItem
{
    /**
     * @var array
     */
    protected data = [];

    /**
     * @return string
     */
    public function getEncoded() -> string
    {
        return this->data["encoded"];
    }
}
