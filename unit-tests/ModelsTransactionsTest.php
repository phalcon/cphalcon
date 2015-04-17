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

class ModelsTransactionsTest extends PHPUnit_Framework_TestCase {

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
		if (file_exists('unit-tests/models/' . $className . '.php')) {
			require 'unit-tests/models/' . $className . '.php';
		}
	}

	protected function _getDI()
	{

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function(){
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		$di->set('transactionManager', function(){
			return new Phalcon\Mvc\Model\Transaction\Manager();
		});

		return $di;
	}

	/**
	 * @large
	 */
	public function testTransactionsMysql()
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
		});

		$this->_executeTests($di);
	}

	/**
	 * @large
	 */
	public function testTransactionsPostgresql()
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
		});

		$this->_executeTests($di);
	}

	/**
	 * @large
	 */
	public function testTransactionsSqlite()
	{
		require 'unit-tests/config.db.php';
		if (empty($configSqlite)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);
		});

		$this->_executeTests($di);
	}

	protected function _executeTests($di)
	{

		$connection = $di->getShared('db');

		$success = $connection->delete("personas", "cedula LIKE 'T-Cx%'");
		$this->assertTrue($success);

		$numPersonas = Personas::count();
		$this->assertGreaterThan(0, $numPersonas);

		$transactionManager = $di->getShared('transactionManager');

		try {

			$transaction1 = $transactionManager->get();
			$this->assertInstanceOf('Phalcon\Mvc\Model\Transaction', $transaction1);

			$this->assertNotEquals($transaction1->getConnection()->getConnectionId(), $connection->getConnectionId());

			$p = 100;
			for ($i = 0; $i < 10; $i++) {
				$persona = new Personas($di);
				$persona->setTransaction($transaction1);
				$persona->cedula            = 'T-Cx' . $i;
				$persona->tipo_documento_id = 1;
				$persona->nombres           = 'LOST LOST';
				$persona->telefono          = '2';
				$persona->cupo              = 0;
				$persona->estado            = 'A';
				$this->assertTrue($persona->save());
				$p++;
			}

			//We rollback the transaction
			$transaction1->rollback();

			$this->assertTrue(FALSE, 'oh, Why?');

		}
		catch(Phalcon\Mvc\Model\Transaction\Failed $e){
			$this->assertTrue(true);
		}

		//Now we check if the records was correctly rolled back
		$rollbackNumPersonas = Personas::count();
		$this->assertEquals($numPersonas, $rollbackNumPersonas);

		//Creating another transaction
		try {

			$transaction2 = $transactionManager->get();
			$this->assertInstanceOf('Phalcon\Mvc\Model\Transaction', $transaction2);

			$this->assertNotEquals($transaction2->getConnection()->getConnectionId(), $connection->getConnectionId());
			$this->assertNotEquals($transaction1->getConnection()->getConnectionId(), $transaction2->getConnection()->getConnectionId());

			$p = 200;
			for ($i = 0; $i < 15; $i++) {
				$persona = new Personas($di);
				$persona->setTransaction($transaction2);
				$persona->cedula = 'T-Cx'.$p;
				$persona->tipo_documento_id = 1;
				$persona->nombres = 'LOST LOST';
				$persona->telefono = '1';
				$persona->cupo = 0;
				$persona->estado = 'A';
				$this->assertTrue($persona->save());
				$p++;
			}

			//This time we commit the transaction
			$transaction2->commit();

			$commitNumPersonas = Personas::count();
			$this->assertEquals($commitNumPersonas, $numPersonas + 15);

		} catch (Phalcon\Mvc\Model\Transaction\Failed $e) {
			$this->assertTrue(FALSE, 'oh, Why?');
		}

	}

}

