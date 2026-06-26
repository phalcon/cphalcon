
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
 * Canonical contract for ACL role-aware objects.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Acl_RoleAware)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Acl, RoleAware, phalcon, contracts_acl_roleaware, phalcon_contracts_acl_roleaware_method_entry);

	return SUCCESS;
}

/**
 * Returns role name
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_RoleAware, getRoleName);
