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

class ModelsValidatorsTest extends PHPUnit_Framework_TestCase
{

	public function __construct()
	{
		spl_autoload_register(array($this, 'modelsAutoloader'));
	}

	public function __destruct()
	{
		spl_autoload_unregister(array($this, 'modelsAutoloader'));
	}

	public function modelsAutoloader($className)
	{
		if (file_exists('unit-tests/models/'.$className.'.php')) {
			require 'unit-tests/models/'.$className.'.php';
		}
	}

	protected function _getDI(){

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function(){
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		return $di;
	}

	public function testValidatorsMysql(){

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		});

		$this->_testValidators($di);
	}

	public function testValidatorsPostgresql(){

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		});

		$this->_testValidators($di);
	}

	protected function _testValidators($di)
	{

		$connection = $di->getShared('db');

		$success = $connection->delete("subscriptores");
		$this->assertTrue($success);

		$createdAt = new Phalcon\Db\RawValue('now()');

		//Save with success
		$subscriptor = new Subscriptores();
		$subscriptor->email = 'fuego@hotmail.com';
		$subscriptor->created_at = $createdAt;
		$subscriptor->status = 'P';
		$this->assertTrue($subscriptor->save());

		//PresenceOf
		$subscriptor = new Subscriptores();
		$subscriptor->email = 'fuego1@hotmail.com';
		$subscriptor->created_at = null;
		$subscriptor->status = 'P';
		$this->assertFalse($subscriptor->save());

		$this->assertEquals(count($subscriptor->getMessages()), 1);

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "PresenceOf");
		$this->assertEquals($messages[0]->getField(), "created_at");
		$this->assertEquals($messages[0]->getMessage(), "The field 'created_at' is required");

		//Email
		$subscriptor = new Subscriptores();
		$subscriptor->email = 'fuego?=';
		$subscriptor->created_at = $createdAt;
		$subscriptor->status = 'P';
		$this->assertFalse($subscriptor->save());

		$this->assertEquals(count($subscriptor->getMessages()), 1);

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "email");
		$this->assertEquals($messages[0]->getField(), "email");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'email' must have a valid e-mail format");

		//ExclusionIn
		$subscriptor->email = 'le_fuego@hotmail.com';
		$subscriptor->status = 'X';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "exclusion");
		$this->assertEquals($messages[0]->getField(), "status");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'status' must not be part of list: X, Z");

		//InclusionIn
		$subscriptor->status = 'A';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "inclusion");
		$this->assertEquals($messages[0]->getField(), "status");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'status' must be part of list: P, I, w");

		//Uniqueness validator
		$subscriptor->email = 'fuego@hotmail.com';
		$subscriptor->status = 'P';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "unique");
		$this->assertEquals($messages[0]->getField(), "email");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'email' is already present in another record");

		//Regex validator
		$subscriptor->email = 'na_fuego@hotmail.com';
		$subscriptor->status = 'w';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "regex");
		$this->assertEquals($messages[0]->getField(), "status");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'status' doesn't match regular expression");

		//too_long
		$subscriptor->email = 'personwholivesinahutsomewhereinthecloud@hotmail.com';
		$subscriptor->status = 'P';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "too_long");
		$this->assertEquals($messages[0]->getField(), "email");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'email' exceeds the maximum 50 characters");

		//too_short
		$subscriptor->email = 'a@b.co';
		$subscriptor->status = 'P';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "too_short");
		$this->assertEquals($messages[0]->getField(), "email");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'email' is less than the minimum 7 characters");

	}

}
