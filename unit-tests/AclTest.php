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

	public function testMemory()
	{
		$acl = new \Phalcon\Acl\Adapter\Memory();
		$acl->setDefaultAction(Phalcon\Acl::DENY);

		$roles = array(
			'Admin' => new \Phalcon\Acl\Role('Admin'),
			'Users' => new \Phalcon\Acl\Role('Users'),
			'Guests' => new \Phalcon\Acl\Role('Guests')
		);

		$resources = array(
			'welcome' => array('index', 'about'),
			'account' => array('index'),
		);

		foreach ($roles as $role => $object) {
			$acl->addRole($object);
		}

		foreach ($resources as $resource => $actions) {
			$acl->addResource(new \Phalcon\Acl\Resource($resource), $actions);
		}
/*
		$this->assertFalse($acl->isAllowed('Admin', 'welcome', 'index'));
		$this->assertFalse($acl->isAllowed('Admin', 'welcome', 'about'));

		$acl->allow('Admin', 'welcome', '*');

		$this->assertTrue($acl->isAllowed('Admin', 'welcome', 'index'));
		$this->assertTrue($acl->isAllowed('Admin', 'welcome', 'about'));

		$this->assertFalse($acl->isAllowed('Admin', 'account', 'index'));
		$this->assertFalse($acl->isAllowed('Admin', 'account', 'about'));

		$acl->allow('Admin', '*', '*');

		$this->assertTrue($acl->isAllowed('Admin', 'welcome', 'index'));
		$this->assertTrue($acl->isAllowed('Admin', 'welcome', 'about'));

		$this->assertTrue($acl->isAllowed('Admin', 'account', 'index'));
		$this->assertTrue($acl->isAllowed('Admin', 'account', 'about'));

		$acl->deny('Admin', '*', '*');

		foreach ($roles as $role => $object) {
			$this->assertFalse($acl->isAllowed($role, 'welcome', 'about'));
		}
*/
		$acl->allow("*", "welcome", "index");

		foreach ($roles as $role => $object) {
			$this->assertTrue($acl->isAllowed($role, 'welcome', 'index'));
		}

		$acl->deny("*", "welcome", "index");

		foreach ($roles as $role => $object) {
			$this->assertFalse($acl->isAllowed($role, 'welcome', 'index'));
		}
/*
		$acl->allow('Admin', '*', 'index');

		foreach ($resources as $resource => $actions) {
			$this->assertTrue($acl->isAllowed('admin', $resource, 'index'));
		}

		$acl->allow('*', '*', 'index');

		$acl->allow('*', '*', '*');
*/
	}

	public function testIssues1513()
	{
		try {
			$acl = new \Phalcon\Acl\Adapter\Memory();
			$acl->setDefaultAction(Phalcon\Acl::DENY);
			$acl->addRole(new \Phalcon\Acl\Role('11'));
			$acl->addResource(new \Phalcon\Acl\Resource('11'), array('index'));
			$this->assertTrue(TRUE);
		} catch (Exception $e) {
			$this->assertTrue(FALSE);
		}
	}

	public function testDeepInherit()
	{

		/**
		 * Set deep inheritance rules and check them
		 */
		$acl = new \Phalcon\Acl\Adapter\Memory();
		$acl->setDefaultAction(\Phalcon\Acl::DENY);

		$roleUser = new \Phalcon\Acl\Role("User", "Basic access");
		$acl->addRole($roleUser);

		$roleManager = new \Phalcon\Acl\Role("Manager", "Extended access");
		$acl->addRole($roleManager, $roleUser);

		$roleAdmin = new \Phalcon\Acl\Role("Administrator", "Super-User role");
		$acl->addRole($roleAdmin, $roleManager);

		$acl->addResource(new \Phalcon\Acl\Resource('Resource'), ['index', 'edit', 'delete', 'add']);

		$acl->allow('User', 'Resource', 'index');

		$acl->allow('Manager', 'Resource', 'edit');
		$acl->allow('Manager', 'Resource', 'add');

		$acl->allow('Administrator', 'Resource', 'delete');
		/**
		 * Administrator should have access to index inherited from User
		 */
		$this->assertTrue($acl->isAllowed('Administrator', 'Resource', 'index'));
		/**
		 * And Administrator should inherit access from Manager
		 */
		$this->assertTrue($acl->isAllowed('Administrator', 'Resource', 'edit'));
		/**
		 * Disallow parent role resource and check if child also not have access
		 */
		$acl->deny('User', 'Resource', 'index');
		$this->assertFalse($acl->isAllowed('Administrator', 'Resource', 'index'));
		/**
		 * Check wildcards
		 */
		$acl->addResource(new \Phalcon\Acl\Resource('Resource2'), ['index', 'edit', 'delete', 'add']);
		$acl->allow('User', 'Resource2', '*');
		$this->assertTrue($acl->isAllowed('Administrator', 'Resource2', 'delete'));
	}
}
