
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Encryption\Security\Uuid;

/**
 * Canonical marker contract for UUID version adapters.
 *
 * Also carries the standard RFC 4122 namespace UUIDs as constants.
 */
interface Uuid
{
    /**
     * @var string
     */
    const NAMESPACE_DNS  = "6ba7b810-9dad-11d1-80b4-00c04fd430c8";
    /**
     * @var string
     */
    const NAMESPACE_OID  = "6ba7b812-9dad-11d1-80b4-00c04fd430c8";
    /**
     * @var string
     */
    const NAMESPACE_URL  = "6ba7b811-9dad-11d1-80b4-00c04fd430c8";
    /**
     * @var string
     */
    const NAMESPACE_X500 = "6ba7b814-9dad-11d1-80b4-00c04fd430c8";
}
