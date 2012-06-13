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

class TransactionsTest extends PHPUnit_Framework_TestCase {

	public function testTransactions(){

		require 'unit-tests/config.db.php';

		Phalcon_Db_Pool::setDefaultDescriptor($configMysql);
		$this->assertTrue(Phalcon_Db_Pool::hasDefaultDescriptor());

		$manager = new Phalcon_Model_Manager();
		$manager->setModelsDir('unit-tests/models/');

		$connection = $manager->getConnection();
		$this->assertTrue(is_object($connection));

		$success = $connection->delete("personas", "cedula LIKE 'T-Cx%'");
		$this->assertTrue($success);

		$numPersonas = Personas::count();
		$this->assertGreaterThan(0, $numPersonas);

		try {

			$transaction1 = Phalcon_Transaction_Manager::get();
			$this->assertInstanceOf('Phalcon_Transaction', $transaction1);

			$this->assertNotEquals($transaction1->getConnection()->getConnectionId(true), $connection->getConnectionId(true));

			$p = 100;
			for($i=0;$i<10;$i++){
				$persona = new Personas($manager);
				$persona->setTransaction($transaction1);
				$persona->cedula = 'T-Cx'.$i;
				$persona->tipo_documento_id = 1;
				$persona->nombres = 'LOST LOST';
				$persona->telefono = '2';
				$persona->cupo = 0;
				$persona->estado = 'A';
				$this->assertTrue($persona->save());
				$p++;
			}

			$transaction1->rollback();

			$this->assertTrue(FALSE, 'oh, Why?');

		}
		catch(Phalcon_Transaction_Failed $e){

		}

		$rollbackNumPersonas = Personas::count();
		$this->assertEquals($numPersonas, $rollbackNumPersonas);

		try {

			$transaction2 = Phalcon_Transaction_Manager::get();
			$this->assertInstanceOf('Phalcon_Transaction', $transaction2);

			$this->assertNotEquals($transaction2->getConnection()->getConnectionId(true), $connection->getConnectionId(true));
			$this->assertNotEquals($transaction1->getConnection()->getConnectionId(true), $transaction2->getConnection()->getConnectionId(true));

			$p = 200;
			for($i=0;$i<15;$i++){
				$persona = new Personas($manager);
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

			$transaction2->commit();

			$commitNumPersonas = Personas::count();
			$this->assertEquals($commitNumPersonas, $numPersonas+15);

		}
		catch(Phalcon_Transaction_Failed $e){
			$this->assertTrue(FALSE, 'oh, Why?');
		}

	}

}

