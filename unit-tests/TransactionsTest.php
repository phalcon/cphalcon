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

		$numPersonas = Personas::count();
		$this->assertGreaterThan(0, $numPersonas);

		try {

			$transaction = Phalcon_Transaction_Manager::get();
			$this->assertInstanceOf('Phalcon_Transaction', $transaction);

			for($i=0;$i<10;$i++){
				$persona = new Personas($manager);
				$persona->setTransaction($transaction);
				$persona->cedula = 'T-Cx'.mt_rand(80000, 100000);
				$persona->tipo_documento_id = 1;
				$persona->nombres = 'LOST LOST';
				$persona->telefono = '2';
				$persona->cupo = 0;
				$persona->estado = 'A';
				$this->assertTrue($persona->save());
				
			}

			$transaction->rollback();

			$this->assertTrue(FALSE, 'oh, Why?');
			
		}
		catch(Phalcon_Transaction_Failed $e){
			$rollbackNumPersonas = Personas::count();
			$this->assertEquals($numPersonas, $rollbackNumPersonas);			
		}

		try {

			$transaction = Phalcon_Transaction_Manager::get();
			$this->assertInstanceOf('Phalcon_Transaction', $transaction);			

			for($i=0;$i<15;$i++){
				$persona = new Personas($manager);
				$persona->setTransaction($transaction);
				$persona->cedula = 'T-Cx'.mt_rand(80000, 100000);
				$persona->tipo_documento_id = 1;
				$persona->nombres = 'LOST LOST';
				$persona->telefono = '1';
				$persona->cupo = 0;
				$persona->estado = 'A';
				$this->assertTrue($persona->save());
			}

			$transaction->commit();

			$commitNumPersonas = Personas::count();
			$this->assertEquals($commitNumPersonas, $numPersonas+15);				

		}
		catch(Phalcon_Transaction_Failed $e){
			$this->assertTrue(FALSE, 'oh, Why?');
		}

	}

}

