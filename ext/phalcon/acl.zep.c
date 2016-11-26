
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * Phalcon\Acl
 *
 * This component allows to manage ACL lists. An access control list (ACL) is a list
 * of permissions attached to an object. An ACL specifies which users or system processes
 * are granted access to objects, as well as what operations are allowed on given objects.
 *
 *<code>
 * use Phalcon\Acl;
 * use Phalcon\Acl\Role;
 * use Phalcon\Acl\Resource;
 * use Phalcon\Acl\Adapter\Memory;
 *
 * $acl = new Memory();
 *
 * // Default action is deny access
 * $acl->setDefaultAction(Acl::DENY);
 *
 * // Create some roles
 * $roleAdmins = new Role("Administrators", "Super-User role");
 * $roleGuests = new Role("Guests");
 *
 * // Add "Guests" role to acl
 * $acl->addRole($roleGuests);
 *
 * // Add "Designers" role to acl
 * $acl->addRole("Designers");
 *
 * // Define the "Customers" resource
 * $customersResource = new Resource("Customers", "Customers management");
 *
 * // Add "customers" resource with a couple of operations
 * $acl->addResource($customersResource, "search");
 * $acl->addResource($customersResource, ["create", "update"]);
 *
 * // Set access level for roles into resources
 * $acl->allow("Guests", "Customers", "search");
 * $acl->allow("Guests", "Customers", "create");
 * $acl->deny("Guests", "Customers", "update");
 *
 * // Check whether role has access to the operations
 * $acl->isAllowed("Guests", "Customers", "edit"); // Returns 0
 * $acl->isAllowed("Guests", "Customers", "search"); // Returns 1
 * $acl->isAllowed("Guests", "Customers", "create"); // Returns 1
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Acl, phalcon, acl, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_class_constant_long(phalcon_acl_ce, SL("ALLOW"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_acl_ce, SL("DENY"), 0 TSRMLS_CC);

	return SUCCESS;

}

