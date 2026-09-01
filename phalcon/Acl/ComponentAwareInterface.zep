
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl;

use Phalcon\Contracts\Acl\ComponentAware as ComponentAwareContract;

/**
 * Interface for ACL Component aware objects
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Acl\ComponentAware} instead.
 */
interface ComponentAwareInterface extends ComponentAwareContract
{
}
