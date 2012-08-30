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

class AclTest extends PHPUnit_Framework_TestCase
{

	public function testAcl()
	{

		$acl = new Phalcon\Acl\Adapter\Memory();

		$acl->setDefaultAction(Phalcon\Acl::DENY);

		$roleAdmins = new Phalcon\Acl\Role('Administrators', 'Super-User role');
		$this->assertEquals($roleAdmins->getName(), 'Administrators');
		$this->assertEquals($roleAdmins->getDescription(), 'Super-User role');

		$roleGuests = new Phalcon\Acl\Role('Guests');
		$this->assertEquals($roleGuests->getName(), 'Guests');
		$this->assertEquals($roleGuests->getDescription(), '');

		$this->assertTrue($acl->addRole($roleGuests));
		$this->assertFalse($acl->addRole($roleGuests));
		$this->assertFalse($acl->addRole('Guests'));

		$this->assertTrue($acl->addRole('Designers'));
		$this->assertFalse($acl->addRole('Designers'));

		$this->assertTrue($acl->isRole('Guests'));
		$this->assertFalse($acl->isRole('ReadOnly'));

		$customersResource = new Phalcon\Acl\Resource('Customers', 'Customers management');
		$this->assertEquals($customersResource->getName(), 'Customers');
		$this->assertEquals($customersResource->getDescription(), 'Customers management');

		$this->assertTrue($acl->addResource($customersResource, 'search'));
		$this->assertTrue($acl->addResource($customersResource, array('create', 'update')));

		$this->assertTrue($acl->isResource('Customers'));
		$this->assertFalse($acl->isResource('Products'));

		$acl->allow('Guests', 'Customers', 'search');
		$acl->allow('Guests', 'Customers', 'create');
		$acl->deny('Guests', 'Customers', 'update');

		$this->assertEquals($acl->isAllowed('Guests', 'Customers', 'edit'), Phalcon\Acl::DENY);
		$this->assertEquals($acl->isAllowed('Guests', 'Customers', 'search'), Phalcon\Acl::ALLOW);
		$this->assertEquals($acl->isAllowed('Guests', 'Customers', 'create'), Phalcon\Acl::ALLOW);

		$this->assertTrue($acl->addRole($roleAdmins, 'Guests'));
		$this->assertFalse($acl->addRole($roleAdmins, 'Guests'));

		$this->assertEquals($acl->isAllowed('Administrators', 'Customers', 'edit'), Phalcon\Acl::DENY);
		$this->assertEquals($acl->isAllowed('Administrators', 'Customers', 'search'), Phalcon\Acl::ALLOW);
		$this->assertEquals($acl->isAllowed('Administrators', 'Customers', 'create'), Phalcon\Acl::ALLOW);

		//Serialize ACL list
		file_put_contents('unit-tests/acl/acl.data', serialize($acl));

		$aclObject = unserialize(file_get_contents('unit-tests/acl/acl.data'));
		$this->assertEquals(get_class($aclObject), 'Phalcon\Acl\Adapter\Memory');

		$this->assertTrue($aclObject->isRole('Guests'));
		$this->assertFalse($aclObject->isRole('ReadOnly'));

		$this->assertTrue($aclObject->isResource('Customers'));
		$this->assertFalse($aclObject->isResource('Products'));

		$this->assertEquals($aclObject->isAllowed('Administrators', 'Customers', 'edit'), Phalcon\Acl::DENY);
		$this->assertEquals($aclObject->isAllowed('Administrators', 'Customers', 'search'), Phalcon\Acl::ALLOW);
		$this->assertEquals($aclObject->isAllowed('Administrators', 'Customers', 'create'), Phalcon\Acl::ALLOW);

	}

}
