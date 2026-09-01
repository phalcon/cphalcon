
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
 * Generates a version 4 (random) UUID.
 *
 * All 122 non-fixed bits are random. Identical algorithm to
 * Phalcon\Encryption\Security\Random::uuid().
 *
 * @link https://www.ietf.org/rfc/rfc4122.txt
 */
class Version4 extends AbstractUuid
{
    public function __construct()
    {
        var ary;

        let ary = array_values(
            unpack("N1a/n1b/n1c/n1d/n1e/N1f", random_bytes(16))
        );

        let ary[2] = (ary[2] & 0x0fff) | 0x4000,
            ary[3] = (ary[3] & 0x3fff) | 0x8000;

        array_unshift(ary, "%08x-%04x-%04x-%04x-%04x%08x");

        let this->uid = call_user_func_array("sprintf", ary);
    }
}
