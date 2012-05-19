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

class ModelsValidatorsTest extends PHPUnit_Framework_TestCase {

	public function testModels(){

		$config = array(
			'adapter' => 'Mysql',
			'host' => '127.0.0.1',
			'username' => 'root',
			'password' => '',
			'name' => 'phalcon_test'
		);

		Phalcon_Db_Pool::setDefaultDescriptor($config);
		$this->assertTrue(Phalcon_Db_Pool::hasDefaultDescriptor());

		$manager = new Phalcon_Model_Manager();
		$manager->setModelsDir('unit-tests/models/');

		$success = $manager->load('Subscriptores');
		$this->assertTrue($success);

		$connection = Phalcon_Db_Pool::getConnection();
		$this->assertTrue(is_object($connection));

		$success = $connection->delete("subscriptores");
		$this->assertTrue($success);

		$subscriptor = new Subscriptores();
		$subscriptor->email = 'fuego@hotmail.com';
		$subscriptor->created_at = new Phalcon_Db_RawValue('now()');
		$subscriptor->status = 'P';
		$this->assertTrue($subscriptor->save());

		$subscriptor = new Subscriptores();
		$subscriptor->email = 'fuego?=';
		$subscriptor->created_at = new Phalcon_Db_RawValue('now()');
		$subscriptor->status = 'P';
		$this->assertFalse($subscriptor->save());

		$this->assertEquals(count($subscriptor->getMessages()), 1);

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "email");
		$this->assertEquals($messages[0]->getField(), "email");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'email' should be a valid e-mail");

		$subscriptor->email = 'le_fuego@hotmail.com';
		$subscriptor->status = 'X';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "exclusion");
		$this->assertEquals($messages[0]->getField(), "status");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'status' must not be part of list: X, Z");

		$subscriptor->status = 'A';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "inclusion");
		$this->assertEquals($messages[0]->getField(), "status");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'status' must be part of list: P, I, w");

		$subscriptor->email = 'fuego@hotmail.com';
		$subscriptor->status = 'P';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "unique");
		$this->assertEquals($messages[0]->getField(), "email");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'email' is already present in another record");

		$subscriptor->email = 'na_fuego@hotmail.com';
		$subscriptor->status = 'w';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "regex");
		$this->assertEquals($messages[0]->getField(), "status");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'status' doesn't match regular expression");

	}

}