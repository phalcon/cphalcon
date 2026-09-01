
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Security\Uuid;

use Phalcon\Contracts\Encryption\Security\Uuid\Uuid as UuidContract;

/**
 * Marker interface for UUID version adapters.
 *
 * Also carries the standard RFC 4122 namespace UUIDs as constants.
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Encryption\Security\Uuid\Uuid} instead.
 */
interface UuidInterface extends UuidContract
{
}
