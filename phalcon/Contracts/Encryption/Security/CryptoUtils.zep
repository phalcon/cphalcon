
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Encryption\Security;

use Phalcon\Encryption\Security\Random;

interface CryptoUtils
{
    public function computeHmac(
        string data,
        string key,
        string algorithm,
        bool raw = false
    ) -> string;

    public function getRandom() -> <Random>;

    public function getRandomBytes() -> int;

    public function setRandomBytes( int randomBytes) -> <Security>;

    public function getSaltBytes(int numberBytes = 0) -> string;
}
