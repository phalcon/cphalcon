
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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Acl\AdapterInterface
 *
 * Interface for Phalcon\Acl adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Acl, AdapterInterface, phalcon, acl_adapterinterface, phalcon_acl_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Do a role inherit from another existing role
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, addInherit);

/**
 * Adds a role to the ACL list. Second parameter lets to inherit access data from other existing role
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, addRole);

/**
 * Adds a component to the ACL list
 *
 * Access names can be a particular action, by example
 * search, update, delete, etc or a list of them
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, addComponent);

/**
 * Adds access to components
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, addComponentAccess);

/**
 * Allow access to a role on a component
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, allow);

/**
 * Deny access to a role on a component
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, deny);

/**
 * Removes an access from a component
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, dropComponentAccess);

/**
 * Returns the access which the list is checking if some role can access it
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, getActiveAccess);

/**
 * Returns the role which the list is checking if it's allowed to certain component/access
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, getActiveRole);

/**
 * Returns the component which the list is checking if some role can access it
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, getActiveComponent);

/**
 * Returns the default ACL access level
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, getDefaultAction);

/**
 * Returns the default ACL access level for no arguments provided in
 *isAllowed action if there exists func for accessKey
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, getNoArgumentsDefaultAction);

/**
 * Return an array with every role registered in the list
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, getRoles);

/**
 * Return an array with every component registered in the list
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, getComponents);

/**
 * Check whether a role is allowed to access an action from a component
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, isAllowed);

/**
 * Check whether component exist in the components list
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, isComponent);

/**
 * Check whether role exist in the roles list
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, isRole);

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, setDefaultAction);

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
 * for no arguments provided in isAllowed action if there exists func for accessKey
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, setNoArgumentsDefaultAction);

