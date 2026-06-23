
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
 * Canonical contract for an ACL component entity.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Acl_Component)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Acl, Component, phalcon, contracts_acl_component, phalcon_contracts_acl_component_method_entry);

	return SUCCESS;
}

/**
 * Magic method __toString
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Component, __toString);
/**
 * Returns component description
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Component, getDescription);
/**
 * Returns the component name
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Component, getName);
