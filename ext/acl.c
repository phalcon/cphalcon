
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"

/**
 * Phalcon\Acl
 *
 * This component allows to manage ACL lists. An access control list (ACL) is a list
 * of permissions attached to an object. An ACL specifies which users or system processes
 * are granted access to objects, as well as what operations are allowed on given objects.
 *
 *<code>
 *
 *	$acl = new Phalcon\Acl\Adapter\Memory();
 *
 *	//Default action is deny access
 *	$acl->setDefaultAction(Phalcon\Acl::DENY);
 *
 *	//Create some roles
 *	$roleAdmins = new Phalcon\Acl\Role('Administrators', 'Super-User role');
 *	$roleGuests = new Phalcon\Acl\Role('Guests');
 *
 *	//Add "Guests" role to acl
 *	$acl->addRole($roleGuests);
 *
 *	//Add "Designers" role to acl
 *	$acl->addRole('Designers'));
 *
 *	//Define the "Customers" resource
 *	$customersResource = new Phalcon\Acl\Resource('Customers', 'Customers management');
 *
 *	//Add "customers" resource with a couple of operations
 *	$acl->addResource($customersResource, 'search');
 *	$acl->addResource($customersResource, array('create', 'update'));
 *
 *	//Set access level for roles into resources
 *	$acl->allow('Guests', 'Customers', 'search');
 *	$acl->allow('Guests', 'Customers', 'create');
 *	$acl->deny('Guests', 'Customers', 'update');
 *
 *	//Check whether role has access to the operations
 *	$acl->isAllowed('Guests', 'Customers', 'edit') //Returns 0
 *	$acl->isAllowed('Guests', 'Customers', 'search'); //Returns 1
 *	$acl->isAllowed('Guests', 'Customers', 'create'); //Returns 1
 *
 *</code>
 */


/**
 * Phalcon\Acl initializer
 */
PHALCON_INIT_CLASS(Phalcon_Acl){

	PHALCON_REGISTER_CLASS(Phalcon, Acl, acl, phalcon_acl_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_acl_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_acl_ce, SL("ALLOW"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_acl_ce, SL("DENY"), 0 TSRMLS_CC);

	zend_class_implements(phalcon_acl_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);

	return SUCCESS;
}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\ManagerInterface $eventManager
 */
PHP_METHOD(Phalcon_Acl, setEventsManager){

	zval *events_manager;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &events_manager) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Acl, getEventsManager){


	RETURN_MEMBER(this_ptr, "_eventsManager");
}

