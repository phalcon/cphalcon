
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-uuid
 * @link    https://github.com/sinbadxiii/cphalcon-uuid
 */

namespace Phalcon\Encryption\Security\Uuid;

/**
 * Generates a version 3 (name-based MD5) UUID.
 *
 * Given a namespace UUID and a name string, produces a deterministic UUID
 * by hashing namespace bytes + name with MD5, then stamping version/variant.
 *
 * @link https://www.ietf.org/rfc/rfc4122.txt
 */
class Version3 extends AbstractUuid
{
    public function __construct( string namespaceName,  string name)
    {
        var hash;

        let hash = md5(this->namespaceToBytes(namespaceName) . name, true);
        let hash = substr_replace(hash, chr((ord(substr(hash, 6, 1)) & 0x0f) | 0x30), 6, 1);
        let hash = substr_replace(hash, chr((ord(substr(hash, 8, 1)) & 0x3f) | 0x80), 8, 1);

        let this->uid = this->format(bin2hex(hash));
    }
}
