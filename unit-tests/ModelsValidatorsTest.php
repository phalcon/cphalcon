<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

function sqlite_now()
{
	return date('Y-m-d H:i:s');
}

class ModelsValidatorsTest extends PHPUnit_Framework_TestCase
{

	public function __construct()
	{
		date_default_timezone_set('UTC');
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

	public function testValidatorsMysql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

		$this->_testValidatorsNormal($di);
		$this->_testValidatorsRenamed($di);
	}

	public function testValidatorsPostgresql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configPostgresql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		}, true);

		$this->_testValidatorsNormal($di);
		$this->_testValidatorsRenamed($di);
	}

	public function testValidatorsSqlite()
	{
		require 'unit-tests/config.db.php';
		if (empty($configSqlite)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			$conn = new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);
			$conn->getInternalHandler()->sqliteCreateFunction('now', 'sqlite_now', 0);
			return $conn;
		}, true);

		$this->_testValidatorsNormal($di);
		$this->_testValidatorsRenamed($di);
	}

	protected function _testValidatorsNormal($di)
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
		$this->assertEquals($messages[0]->getMessage(), "'created_at' is required");

		//Email
		$subscriptor = new Subscriptores();
		$subscriptor->email = 'fuego?=';
		$subscriptor->created_at = $createdAt;
		$subscriptor->status = 'P';
		$this->assertFalse($subscriptor->save());

		$this->assertEquals(count($subscriptor->getMessages()), 1);

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "Email");
		$this->assertEquals($messages[0]->getField(), "email");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'email' must have a valid e-mail format");

		//ExclusionIn
		$subscriptor->email = 'le_fuego@hotmail.com';
		$subscriptor->status = 'X';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "Exclusion");
		$this->assertEquals($messages[0]->getField(), "status");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'status' must not be part of list: X, Z");

		//InclusionIn
		$subscriptor->status = 'A';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "Inclusion");
		$this->assertEquals($messages[0]->getField(), "status");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'status' must be part of list: P, I, w");

		//Uniqueness validator
		$subscriptor->email = 'fuego@hotmail.com';
		$subscriptor->status = 'P';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "Unique");
		$this->assertEquals($messages[0]->getField(), "email");
		$this->assertEquals($messages[0]->getMessage(), "Value of field: 'email' is already present in another record");

		//Regex validator
		$subscriptor->email = 'na_fuego@hotmail.com';
		$subscriptor->status = 'w';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "Regex");
		$this->assertEquals($messages[0]->getField(), "status");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'status' doesn't match regular expression");

		//too_long
		$subscriptor->email = 'personwholivesinahutsomewhereinthecloud@hotmail.com';
		$subscriptor->status = 'P';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "TooLong");
		$this->assertEquals($messages[0]->getField(), "email");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'email' exceeds the maximum 50 characters");

		//too_short
		$subscriptor->email = 'a@b.co';
		$subscriptor->status = 'P';
		$this->assertFalse($subscriptor->save());

		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "TooShort");
		$this->assertEquals($messages[0]->getField(), "email");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'email' is less than the minimum 7 characters");

		// Issue 1243
		$subscriptor->email = 'user.@domain.com';
		$this->assertFalse($subscriptor->save());
		$messages = $subscriptor->getMessages();
		$this->assertEquals($messages[0]->getType(), "Email");
		$this->assertEquals($messages[0]->getField(), "email");
		$this->assertEquals($messages[0]->getMessage(), "Value of field 'email' must have a valid e-mail format");

		// Issue 1527
		$subscriptor = Subscriptores::findFirst();
		//$this->assertTrue($subscriptor->validation()); // This fails
	}

	protected function _testValidatorsRenamed($di)
	{
		$connection = $di->getShared('db');

		$success = $connection->delete("subscriptores");
		$this->assertTrue($success);

		$createdAt = new Phalcon\Db\RawValue('now()');

		//Save with success
		$abonne = new Abonnes();
		$abonne->courrierElectronique = 'fuego@hotmail.com';
		$abonne->creeA = $createdAt;
		$abonne->statut = 'P';
		$this->assertTrue($abonne->save());

		//PresenceOf
		$abonne = new Abonnes();
		$abonne->courrierElectronique = 'fuego1@hotmail.com';
		$abonne->creeA = null;
		$abonne->statut = 'P';
		$this->assertFalse($abonne->save());

		$this->assertEquals(count($abonne->getMessages()), 1);

		$messages = $abonne->getMessages();
		$this->assertEquals($messages[0]->getType(), "PresenceOf");
		$this->assertEquals($messages[0]->getField(), "creeA");
		$this->assertEquals($messages[0]->getMessage(), "La date de création est nécessaire");

		//Email
		$abonne = new Abonnes();
		$abonne->courrierElectronique = 'fuego?=';
		$abonne->creeA = $createdAt;
		$abonne->statut = 'P';
		$this->assertFalse($abonne->save());

		$this->assertEquals(count($abonne->getMessages()), 1);

		$messages = $abonne->getMessages();
		$this->assertEquals($messages[0]->getType(), "Email");
		$this->assertEquals($messages[0]->getField(), "courrierElectronique");
		$this->assertEquals($messages[0]->getMessage(), "Le courrier électronique est invalide");

		//ExclusionIn
		$abonne->courrierElectronique = 'le_fuego@hotmail.com';
		$abonne->statut = 'X';
		$this->assertFalse($abonne->save());

		$messages = $abonne->getMessages();
		$this->assertEquals($messages[0]->getType(), "Exclusion");
		$this->assertEquals($messages[0]->getField(), "statut");
		$this->assertEquals($messages[0]->getMessage(), 'L\'état ne doit être "X" ou "Z"');

		//InclusionIn
		$abonne->statut = 'A';
		$this->assertFalse($abonne->save());

		$messages = $abonne->getMessages();
		$this->assertEquals($messages[0]->getType(), "Inclusion");
		$this->assertEquals($messages[0]->getField(), "statut");
		$this->assertEquals($messages[0]->getMessage(), 'L\'état doit être "P", "I" ou "w"');

		//Uniqueness validator
		$abonne->courrierElectronique = 'fuego@hotmail.com';
		$abonne->statut = 'P';
		$this->assertFalse($abonne->save());

		$messages = $abonne->getMessages();
		$this->assertEquals($messages[0]->getType(), "Unique");
		$this->assertEquals($messages[0]->getField(), "courrierElectronique");
		$this->assertEquals($messages[0]->getMessage(), 'Le courrier électronique doit être unique');

		//Regex validator
		$abonne->courrierElectronique = 'na_fuego@hotmail.com';
		$abonne->statut = 'w';
		$this->assertFalse($abonne->save());

		$messages = $abonne->getMessages();
		$this->assertEquals($messages[0]->getType(), "Regex");
		$this->assertEquals($messages[0]->getField(), "statut");
		$this->assertEquals($messages[0]->getMessage(), "L'état ne correspond pas à l'expression régulière");

		//too_long
		$abonne->courrierElectronique = 'personwholivesinahutsomewhereinthecloud@hotmail.com';
		$abonne->statut = 'P';
		$this->assertFalse($abonne->save());

		$messages = $abonne->getMessages();
		$this->assertEquals($messages[0]->getType(), "TooLong");
		$this->assertEquals($messages[0]->getField(), "courrierElectronique");
		$this->assertEquals($messages[0]->getMessage(), "Le courrier électronique est trop long");

		//too_short
		$abonne->courrierElectronique = 'a@b.co';
		$abonne->status = 'P';
		$this->assertFalse($abonne->save());

		$messages = $abonne->getMessages();
		$this->assertEquals($messages[0]->getType(), "TooShort");
		$this->assertEquals($messages[0]->getField(), "courrierElectronique");
		$this->assertEquals($messages[0]->getMessage(), "Le courrier électronique est trop court");

		// Issue #885
		$abonne = new Abonnes();
		$abonne->courrierElectronique = 'fuego?=';
		$abonne->creeA = null;
		$abonne->statut = 'P';
		$this->assertFalse($abonne->save());

		$this->assertEquals(count($abonne->getMessages()), 2);

		$messages = $abonne->getMessages();
		$this->assertEquals($messages[0]->getType(), "PresenceOf");
		$this->assertEquals($messages[0]->getField(), "creeA");
		$this->assertEquals($messages[0]->getMessage(), "La date de création est nécessaire");

		$this->assertEquals($messages[1]->getType(), "Email");
		$this->assertEquals($messages[1]->getField(), "courrierElectronique");
		$this->assertEquals($messages[1]->getMessage(), "Le courrier électronique est invalide");

		$messages = $abonne->getMessages('creeA');
		$this->assertEquals(count($messages), 1);
		$this->assertEquals($messages[0]->getType(), "PresenceOf");
		$this->assertEquals($messages[0]->getField(), "creeA");
		$this->assertEquals($messages[0]->getMessage(), "La date de création est nécessaire");

		$messages = $abonne->getMessages('courrierElectronique');
		$this->assertEquals(count($messages), 1);
		$this->assertEquals($messages[0]->getType(), "Email");
		$this->assertEquals($messages[0]->getField(), "courrierElectronique");
		$this->assertEquals($messages[0]->getMessage(), "Le courrier électronique est invalide");
	}

}
