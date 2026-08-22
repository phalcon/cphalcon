
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Acl_AclTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Acl, AclTypes, phalcon, contracts_acl_acltypes, NULL);

	return SUCCESS;
}

