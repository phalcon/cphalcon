
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
 * Canonical contract for an ACL role entity.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Acl_Role)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Acl, Role, phalcon, contracts_acl_role, phalcon_contracts_acl_role_method_entry);

	return SUCCESS;
}

/**
 * Magic method __toString
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Role, __toString);
/**
 * Returns role description
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Role, getDescription);
/**
 * Returns the role name
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Role, getName);
