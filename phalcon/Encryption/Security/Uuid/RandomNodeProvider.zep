
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
 * Generates a random 48-bit node with the multicast bit set.
 *
 * Used as a fallback when no hardware MAC address is available.
 *
 * @link https://www.ietf.org/rfc/rfc4122.txt Section 4.5
 */
class RandomNodeProvider implements NodeProviderInterface
{
    /**
     * Returns a random 12-character hex node with the multicast bit set.
     */
    public function getNode() -> string
    {
        var nodeBytes;

        let nodeBytes = random_bytes(6);
        let nodeBytes = chr(ord(substr(nodeBytes, 0, 1)) | 0x01) . substr(nodeBytes, 1);

        return bin2hex(nodeBytes);
    }
}
