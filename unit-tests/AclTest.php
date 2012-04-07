<?php

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

class AclTest extends PHPUnit_Framework_TestCase {

	public function testCache(){

		$acl = new Phalcon_Acl('Memory');

		$acl->setDefaultAction(Phalcon_Acl::DENY);

		$roleAdmins = new Phalcon_Acl_Role('Administrators', 'Super-User role');
		$this->assertEquals($roleAdmins->getName(), 'Administrators');
		$this->assertEquals($roleAdmins->getDescription(), 'Super-User role');

		$roleGuests = new Phalcon_Acl_Role('Guests');
		$this->assertEquals($roleGuests->getName(), 'Guests');
		$this->assertEquals($roleGuests->getDescription(), '');

		$this->assertTrue($acl->addRole($roleGuests));
		$this->assertFalse($acl->addRole($roleGuests));
		$this->assertFalse($acl->addRole('Guests'));

		$this->assertTrue($acl->addRole('Designers'));
		$this->assertFalse($acl->addRole('Designers'));

		$this->assertTrue($acl->isRole('Guests'));
		$this->assertFalse($acl->isRole('ReadOnly'));

		$customersResource = new Phalcon_Acl_Resource('Customers', 'Customers management');
		$this->assertEquals($customersResource->getName(), 'Customers');
		$this->assertEquals($customersResource->getDescription(), 'Customers management');

		$this->assertTrue($acl->addResource($customersResource, 'search'));
		$this->assertTrue($acl->addResource($customersResource, array('create', 'update')));

		$this->assertTrue($acl->isResource('Customers'));
		$this->assertFalse($acl->isResource('Products'));

		$acl->allow('Guests', 'Customers', 'search');
		$acl->allow('Guests', 'Customers', 'create');
		$acl->deny('Guests', 'Customers', 'update');

		$this->assertEquals($acl->isAllowed('Guests', 'Customers', 'edit'), Phalcon_ACL::DENY);
		$this->assertEquals($acl->isAllowed('Guests', 'Customers', 'search'), Phalcon_ACL::ALLOW);
		$this->assertEquals($acl->isAllowed('Guests', 'Customers', 'create'), Phalcon_ACL::ALLOW);

		$this->assertTrue($acl->addRole($roleAdmins, 'Guests'));
		$this->assertFalse($acl->addRole($roleAdmins, 'Guests'));

		$this->assertEquals($acl->isAllowed('Administrators', 'Customers', 'edit'), Phalcon_ACL::DENY);
		$this->assertEquals($acl->isAllowed('Administrators', 'Customers', 'search'), Phalcon_ACL::ALLOW);
		$this->assertEquals($acl->isAllowed('Administrators', 'Customers', 'create'), Phalcon_ACL::ALLOW);

	}

}