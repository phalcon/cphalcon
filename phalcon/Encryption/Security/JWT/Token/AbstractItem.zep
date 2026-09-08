
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Security\JWT\Token;

use Phalcon\Contracts\Encryption\EncryptionTypes;

/**
 * Abstract helper class for Tokens
 *
 * @phpstan-import-type encryption_jwt_item_data from EncryptionTypes
 */
abstract class AbstractItem
{
    /**
     * @phpstan-var encryption_jwt_item_data
     */
    protected array data = [];

    public function getEncoded() -> string
    {
        return this->data["encoded"];
    }
}
