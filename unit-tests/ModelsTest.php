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

use Phalcon\Mvc\Model\Message as ModelMessage;

class ModelsTest extends PHPUnit_Framework_TestCase
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

		return $di;
	}

	public function testModelsMysql()
	{

		$di = $this->_getDI();

		$di->set('db', function(){

			require 'unit-tests/config.db.php';

			$db = new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);

			$db->delete("personas", "estado='X'");

			return $db;
		});

		$this->_executeTests($di);
	}

	public function testModelsPostgresql()
	{

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';

			$db = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);

			$db->delete("personas", "estado='X'");

			return $db;
		});

		$this->_executeTests($di);
	}

	public function testModelsSqlite()
	{

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';

			$db = new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);

			$db->delete("personas", "estado='X'");

			return $db;
		});

		$this->_executeTests($di);
	}

	protected function _executeTests($di){

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
		$this->assertTrue(is_object($people));

		$persona = Personas::findFirst("estado='I'");
		$this->assertTrue(is_object($persona));

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

		$params = array("estado=?1", "bind" => array(1 => 'A'), "order" => "nombres DESC", "limit" => 30);
		$people = People::findFirst($params);
		$persona = Personas::findFirst($params);
		$this->assertEquals($people->nombres, $persona->nombres);
		$this->assertEquals($people->estado, $persona->estado);

		$params = array("estado=:estado:", "bind" => array("estado" => 'A'), "order" => "nombres DESC", "limit" => 30);
		$people = People::findFirst($params);
		$persona = Personas::findFirst($params);
		$this->assertEquals($people->nombres, $persona->nombres);
		$this->assertEquals($people->estado, $persona->estado);

		$robot = Robots::findFirst(1);
		$this->assertEquals(get_class($robot), 'Robots');

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

		$params = array("estado=?1", "bind" => array(1 => "A"), "order" => "nombres", "limit" => 100);
		$personas = Personas::find($params);
		$people = People::find($params);
		$this->assertEquals(count($personas), count($people));

		$params = array("estado=:estado:", "bind" => array("estado" => "A"), "order" => "nombres", "limit" => 100);
		$personas = Personas::find($params);
		$people = People::find($params);
		$this->assertEquals(count($personas), count($people));

		$number = 0;
		$peoples = Personas::find(array("conditions" => "estado='A'", "order" => "nombres", "limit" => 20));
		foreach($peoples as $people){
			$number++;
		}
		$this->assertEquals($number, 20);

		$persona = new Personas($di);
		$persona->cedula = 'CELL'.mt_rand(0, 9999);
		$this->assertFalse($persona->save());

		//Messages
		$this->assertEquals(count($persona->getMessages()), 4);

		$messages = array(
			0 => ModelMessage::__set_state(array(
				'_type' => 'PresenceOf',
				'_message' => 'tipo_documento_id is required',
				'_field' => 'tipo_documento_id',
			)),
			1 => ModelMessage::__set_state(array(
				'_type' => 'PresenceOf',
				'_message' => 'nombres is required',
				'_field' => 'nombres',
			)),
			2 => ModelMessage::__set_state(array(
				'_type' => 'PresenceOf',
				'_message' => 'cupo is required',
				'_field' => 'cupo',
			)),
			3 => ModelMessage::__set_state(array(
				'_type' => 'PresenceOf',
				'_message' => 'estado is required',
				'_field' => 'estado',
			)),
		);
		$this->assertEquals($persona->getMessages(), $messages);

		//Save
		$persona = new Personas($di);
		$persona->cedula = 'CELL'.mt_rand(0, 9999);
		$persona->tipo_documento_id = 1;
		$persona->nombres = 'LOST';
		$persona->telefono = '1';
		$persona->cupo = 20000;
		$persona->estado = 'A';
		$this->assertTrue($persona->save());

		$persona = new Personas($di);
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

	}


}
