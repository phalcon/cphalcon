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

class ModelsTest extends PHPUnit_Framework_TestCase {

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
		
		$modelManager = new Phalcon_Model_Manager();
		$modelManager->setModelsDir('unit-tests/models/');

		$Personas = $modelManager->getModel('Personas');		
		$this->assertEquals(get_class($Personas), 'Personas');

		$People = $modelManager->getModel('People');
		$this->assertEquals(get_class($People), 'People');

		$connection = $Personas->getConnection();
		$this->assertEquals($connection, Phalcon_Db_Pool::getConnection());	

		$manager = People::getManager();
		$this->assertEquals(get_class($manager), 'Phalcon_Model_Manager');

		//Count tests
		$this->assertEquals(People::count(), Personas::count());
		
		$params = array();
		$this->assertEquals(People::count($params), Personas::count($params));

		$params = array("estado='I'");
		$this->assertEquals(People::count($params), Personas::count($params));

		$params = "estado='I'";
		$this->assertEquals(People::count($params), Personas::count($params));

		$params = array("conditions" => "estado='I'");
		$this->assertEquals(People::count($params), Personas::count($params));

		//Find first
		$people = People::findFirst();
		$this->assertTrue(is_object($people));
		$this->assertEquals(get_class($people), 'People');

		$persona = Personas::findFirst();
		$this->assertEquals($people->nombres, $persona->nombres);
		$this->assertEquals($people->estado, $persona->estado);

		$people = People::findFirst("estado='I'");
		$persona = Personas::findFirst("estado='I'");
		$this->assertEquals($people->nombres, $persona->nombres);
		$this->assertEquals($people->estado, $persona->estado);

		$people = People::findFirst(array("estado='I'"));
		$persona = Personas::findFirst(array("estado='I'"));
		$this->assertEquals($people->nombres, $persona->nombres);
		$this->assertEquals($people->estado, $persona->estado);

		$params = array("conditions" => "estado='I'");
		$people = People::findFirst($params);
		$persona = Personas::findFirst($params);
		$this->assertEquals($people->nombres, $persona->nombres);
		$this->assertEquals($people->estado, $persona->estado);

		$params = array("conditions" => "estado='A'", "order" => "nombres");
		$people = People::findFirst($params);
		$persona = Personas::findFirst($params);
		$this->assertEquals($people->nombres, $persona->nombres);
		$this->assertEquals($people->estado, $persona->estado);

		$params = array("estado='A'", "order" => "nombres DESC", "limit" => 30);
		$people = People::findFirst($params);
		$persona = Personas::findFirst($params);
		$this->assertEquals($people->nombres, $persona->nombres);
		$this->assertEquals($people->estado, $persona->estado);

		//Find tests
		$personas = Personas::find();
		$people = People::find();
		$this->assertEquals(count($personas), count($people));

		$personas = Personas::find("estado='I'");
		$people = People::find("estado='I'");
		$this->assertEquals(count($personas), count($people));

		$personas = Personas::find(array("estado='I'"));
		$people = People::find(array("estado='I'"));
		$this->assertEquals(count($personas), count($people));

		$personas = Personas::find(array("estado='A'", "order" => "nombres"));
		$people = People::find(array("estado='A'", "order" => "nombres"));
		$this->assertEquals(count($personas), count($people));

		$personas = Personas::find(array("estado='A'", "order" => "nombres", "limit" => 100));
		$people = People::find(array("estado='A'", "order" => "nombres", "limit" => 100));
		$this->assertEquals(count($personas), count($people));

		$number = 0;
		$peoples = Personas::find(array("conditions" => "estado='A'", "order" => "nombres", "limit" => 20));
		foreach($peoples as $people){
			$number++;
		}
		$this->assertEquals($number, 20);

		$persona = new Personas($modelManager);
		$persona->cedula = 'CELL'.mt_rand(0, 9999);
		$this->assertFalse($persona->save());

		//Messages
		$this->assertEquals(count($persona->getMessages()), 4);

		$messages = array(
			0 => Phalcon_Model_Message::__set_state(array(
				'_type' => 'PresenceOf',
				'_message' => 'tipo_documento is required',
				'_field' => 'tipo_documento_id',
			)),
			1 => Phalcon_Model_Message::__set_state(array(
				'_type' => 'PresenceOf',
				'_message' => 'nombres is required',
				'_field' => 'nombres',
			)),
			2 => Phalcon_Model_Message::__set_state(array(
				'_type' => 'PresenceOf',
				'_message' => 'cupo is required',
				'_field' => 'cupo',
			)),
			3 => Phalcon_Model_Message::__set_state(array(
				'_type' => 'PresenceOf',
				'_message' => 'estado is required',
				'_field' => 'estado',
			)),
		);
		$this->assertEquals($persona->getMessages(), $messages);

		//Save
		$persona = new Personas($modelManager);
		$persona->cedula = 'CELL'.mt_rand(0, 9999);
		$persona->tipo_documento_id = 1;
		$persona->nombres = 'LOST';
		$persona->telefono = '1';
		$persona->cupo = 20000;
		$persona->estado = 'A';
		$this->assertTrue($persona->save());

		$persona = new Personas($modelManager);
		$persona->cedula = 'CELL'.mt_rand(0, 9999);
		$persona->tipo_documento_id = 1;
		$persona->nombres = 'LOST LOST';
		$persona->telefono = '2';
		$persona->cupo = 0;
		$persona->estado = 'X';
		$this->assertTrue($persona->save());

		$persona = Personas::findFirst(array("estado='X'"));
		$this->assertNotEquals($persona, false);
		$this->assertEquals($persona->nombres, 'LOST LOST');
		$this->assertEquals($persona->estado, 'X');

		//Grouping
		$difEstados = People::count(array("distinct" => "estado"));
		$this->assertEquals($difEstados, 3);

		$group = People::count(array("group" => "estado"));
		$this->assertEquals(count($group), 3);

		//Deleting
		$before = People::count();
		$this->assertTrue($persona->delete());
		$this->assertEquals($before-1, People::count());

		//GC
		gc_collect_cycles();

	}


}