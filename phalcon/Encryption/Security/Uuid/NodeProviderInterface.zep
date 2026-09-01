
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

use Phalcon\Contracts\Encryption\Security\Uuid\NodeProvider as NodeProviderContract;

/**
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Encryption\Security\Uuid\NodeProvider} instead.
 */
interface NodeProviderInterface extends NodeProviderContract
{
}
