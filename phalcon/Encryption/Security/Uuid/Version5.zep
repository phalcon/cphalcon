
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
 * Generates a version 5 (name-based SHA-1) UUID.
 *
 * Given a namespace UUID and a name string, produces a deterministic UUID
 * by hashing namespace bytes + name with SHA-1 (first 16 bytes used),
 * then stamping version/variant bits.
 *
 * @link https://www.ietf.org/rfc/rfc4122.txt
 */
class Version5 extends AbstractUuid
{
    public function __construct( string namespaceName,  string name)
    {
        var hash;

        let hash = substr(sha1(this->namespaceToBytes(namespaceName) . name, true), 0, 16);
        let hash = substr_replace(hash, chr((ord(substr(hash, 6, 1)) & 0x0f) | 0x50), 6, 1);
        let hash = substr_replace(hash, chr((ord(substr(hash, 8, 1)) & 0x3f) | 0x80), 8, 1);

        let this->uid = this->format(bin2hex(hash));
    }
}
