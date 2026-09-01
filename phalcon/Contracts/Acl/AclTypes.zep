
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Acl;

use Phalcon\Acl\ComponentAwareInterface;
use Phalcon\Acl\ComponentInterface;
use Phalcon\Acl\RoleAwareInterface;
use Phalcon\Acl\RoleInterface;

/**
 * Central registry of the array shapes used across the Acl namespace.
 *
 * @phpstan-type acl_access_list array<int|string, string>|string
 * @phpstan-type acl_component_name ComponentAwareInterface|ComponentInterface|string
 * @phpstan-type acl_components array<string, ComponentInterface>
 * @phpstan-type acl_role_name RoleAwareInterface|RoleInterface|string
 * @phpstan-type acl_role_to_inherit array<RoleInterface|string>|RoleInterface|string
 * @phpstan-type acl_roles array<string, RoleInterface>
 * @phpstan-type acl_snapshot array{
 *     version: int,
 *     access: array<string, int>,
 *     accessList: array<string, bool>,
 *     components: array<string, string|null>,
 *     componentsNames: array<string, bool>,
 *     roles: array<string, string|null>,
 *     roleInherits: array<string, array<int, string>>,
 *     defaultAccess?: int,
 *     noArgumentsDefaultAction?: int
 * }
 */
interface AclTypes
{
}
