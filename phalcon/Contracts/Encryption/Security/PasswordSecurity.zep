
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Encryption\Security;

use Phalcon\Contracts\Encryption\EncryptionTypes;

/**
 * @phpstan-import-type encryption_hash_information from EncryptionTypes
 * @phpstan-import-type encryption_hash_options from EncryptionTypes
 */
interface PasswordSecurity
{
    public function checkHash(
        string password,
        string passwordHash,
        int maxPassLength = 0
    ) -> bool;

    public function getDefaultHash() -> int;

    /**
     * @phpstan-return encryption_hash_information
     */
    public function getHashInformation(string hash) -> array;

    public function getWorkFactor() -> int;

    /**
     * @phpstan-param encryption_hash_options $options
     */
    public function hash(string password, array options = []) -> string;

    public function isLegacyHash(string passwordHash) -> bool;

    public function setDefaultHash(int defaultHash) -> <Security>;

    public function setWorkFactor(int workFactor) -> <Security>;
}
