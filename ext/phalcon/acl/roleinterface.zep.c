
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
 * Interface for Phalcon\Acl\Role
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Acl\Role} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_RoleInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Acl, RoleInterface, phalcon, acl_roleinterface, NULL);

	zend_class_implements(phalcon_acl_roleinterface_ce, 1, phalcon_contracts_acl_role_ce);
	return SUCCESS;
}

