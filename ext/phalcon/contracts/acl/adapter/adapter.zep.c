
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
 * Canonical contract for Phalcon\Acl adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Acl_Adapter_Adapter)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Acl\\Adapter, Adapter, phalcon, contracts_acl_adapter_adapter, phalcon_contracts_acl_adapter_adapter_method_entry);

	return SUCCESS;
}

/**
 * Do a role inherit from another existing role
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, addInherit);
/**
 * Adds a role to the ACL list. Second parameter lets to inherit access data
 * from other existing role
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, addRole);
/**
 * Adds a component to the ACL list
 *
 * Access names can be a particular action, by example
 * search, update, delete, etc. or a list of them
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, addComponent);
/**
 * Adds access to components
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, addComponentAccess);
/**
 * Allow access to a role on a component
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, allow);
/**
 * Deny access to a role on a component
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, deny);
/**
 * Removes access from a component
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, dropComponentAccess);
/**
 * Returns the access which the list is checking if some role can access it
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, getActiveAccess);
/**
 * Returns the role which the list is checking if it's allowed to certain
 * component/access
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, getActiveRole);
/**
 * Returns the component which the list is checking if some role can access
 * it
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, getActiveComponent);
/**
 * Return an array with every component registered in the list
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, getComponents);
/**
 * Returns the default ACL access level
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, getDefaultAction);
/**
 * Returns the inherited roles for a passed role name. If no role name
 * has been specified it will return the whole array. If the role has not
 * been found it returns an empty array
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, getInheritedRoles);
/**
 * Returns the default ACL access level for no arguments provided in
 * isAllowed action if there exists func for accessKey
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, getNoArgumentsDefaultAction);
/**
 * Return an array with every role registered in the list
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, getRoles);
/**
 * Check whether a role is allowed to access an action from a component
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, isAllowed);
/**
 * Check whether component exist in the components list
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, isComponent);
/**
 * Check whether role exist in the roles list
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, isRole);
/**
 * Sets the default access level (Phalcon\Acl\Enum::ALLOW or Phalcon\Acl\Enum::DENY)
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, setDefaultAction);
/**
 * Sets the default access level (Phalcon\Acl\Enum::ALLOW or Phalcon\Acl\Enum::DENY)
 * for no arguments provided in isAllowed action if there exists func for
 * accessKey
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Adapter, setNoArgumentsDefaultAction);
