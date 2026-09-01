
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl;

use Phalcon\Contracts\Acl\RoleAware as RoleAwareContract;

/**
 * Interface for ACL Role aware objects
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Acl\RoleAware} instead.
 */
interface RoleAwareInterface extends RoleAwareContract
{
}
