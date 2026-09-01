
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Encryption\Security;

interface PasswordSecurity
{
    public function checkHash(
        string password,
        string passwordHash,
        int maxPassLength = 0
    ) -> bool;

    public function hash(string password, array options = []) -> string;

    public function isLegacyHash(string passwordHash) -> bool;

    public function getHashInformation(string hash) -> array;

    public function getDefaultHash() -> int;

    public function setDefaultHash(int defaultHash) -> <Security>;

    public function getWorkFactor() -> int;

    public function setWorkFactor(int workFactor) -> <Security>;
}
