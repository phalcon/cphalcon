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

class ModelsCriteriaTest extends PHPUnit_Framework_TestCase
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
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		});

		$this->_executeTestsNormal($di);
		$this->_executeTestsRenamed($di);
		$this->_executeTestsFromInput($di);
	}

	public function testModelsPostgresql()
	{

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		});

		$this->_executeTestsNormal($di);
		$this->_executeTestsRenamed($di);
		$this->_executeTestsFromInput($di);
	}

	public function testModelsSQLite()
	{

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\SQLite($configSqlite);
		});

		$this->_executeTestsNormal($di);
		$this->_executeTestsRenamed($di);
		$this->_executeTestsFromInput($di);
	}

	protected function _executeTestsNormal($di)
	{

		$personas = Personas::query()->where("estado='I'")->execute();
		$people = People::find("estado='I'");
		$this->assertEquals(count($personas), count($people));

		$personas = Personas::query()->conditions("estado='I'")->execute();
		$people = People::find("estado='I'");
		$this->assertEquals(count($personas), count($people));

		$personas = Personas::query()
			->where("estado='A'")
			->order("nombres")
			->execute();
		$people = People::find(array(
			"estado='A'",
			"order" => "nombres"
		));
		$this->assertEquals(count($personas), count($people));

		$somePersona = $personas->getFirst();
		$somePeople = $people->getFirst();
		$this->assertEquals($somePersona->cedula, $somePeople->cedula);

		//Order + limit
		$personas = Personas::query()
			->where("estado='A'")
			->order("nombres")
			->limit(100)
			->execute();
		$people = People::find(array(
			"estado='A'",
			"order" => "nombres",
			"limit" => 100
		));
		$this->assertEquals(count($personas), count($people));

		$somePersona = $personas->getFirst();
		$somePeople = $people->getFirst();
		$this->assertEquals($somePersona->cedula, $somePeople->cedula);

		//Bind params + Limit
		$personas = Personas::query()
			->where("estado=?1")
			->bind(array(1 => "A"))
			->order("nombres")
			->limit(100)
			->execute();

		$people = People::find(array(
			"estado=?1",
			"bind" => array(1 => "A"),
			"order" => "nombres",
			"limit" => 100
		));
		$this->assertEquals(count($personas), count($people));

		$somePersona = $personas->getFirst();
		$somePeople = $people->getFirst();
		$this->assertEquals($somePersona->cedula, $somePeople->cedula);

		//Limit + Offset
		$personas = Personas::query()
			->where("estado=?1")
			->bind(array(1 => "A"))
			->order("nombres")
			->limit(100, 10)
			->execute();

		$people = People::find(array(
			"estado=?1",
			"bind" => array(1 => "A"),
			"order" => "nombres",
			"limit" => array('number' => 100, 'offset' => 10)
		));
		$this->assertEquals(count($personas), count($people));

		$somePersona = $personas->getFirst();
		$somePeople = $people->getFirst();
		$this->assertEquals($somePersona->cedula, $somePeople->cedula);

		$personas = Personas::query()
			->where("estado=:estado:")
			->bind(array("estado" => "A"))
			->order("nombres")
			->limit(100)
			->execute();

		$people = People::find(array(
			"estado=:estado:",
			"bind" => array("estado" => "A"),
			"order" => "nombres",
			"limit" => 100
		));
		$this->assertEquals(count($personas), count($people));

		$somePersona = $personas->getFirst();
		$somePeople = $people->getFirst();
		$this->assertEquals($somePersona->cedula, $somePeople->cedula);

	}

	protected function _executeTestsRenamed($di)
	{

		$personers = Personers::query()
			->where("status='I'")
			->execute();
		$this->assertTrue(is_object($personers));
		$this->assertEquals(get_class($personers), 'Phalcon\Mvc\Model\Resultset\Simple');

		$personers = Personers::query()
			->conditions("status='I'")
			->execute();
		$this->assertTrue(is_object($personers));
		$this->assertEquals(get_class($personers), 'Phalcon\Mvc\Model\Resultset\Simple');

		$personers = Personers::query()
			->where("status='A'")
			->order("navnes")
			->execute();
		$this->assertTrue(is_object($personers));
		$this->assertEquals(get_class($personers), 'Phalcon\Mvc\Model\Resultset\Simple');

		$somePersoner = $personers->getFirst();
		$this->assertTrue(is_object($somePersoner));
		$this->assertEquals(get_class($somePersoner), 'Personers');

		$personers  = Personers::query()
			->where("status='A'")
			->order("navnes")
			->limit(100)
			->execute();
		$this->assertTrue(is_object($personers));
		$this->assertEquals(get_class($personers), 'Phalcon\Mvc\Model\Resultset\Simple');

		$somePersoner = $personers->getFirst();
		$this->assertTrue(is_object($somePersoner));
		$this->assertEquals(get_class($somePersoner), 'Personers');

		$personers = Personers::query()
			->where("status=?1")
			->bind(array(1 => "A"))
			->order("navnes")
			->limit(100)
			->execute();
		$this->assertTrue(is_object($personers));
		$this->assertEquals(get_class($personers), 'Phalcon\Mvc\Model\Resultset\Simple');

		$somePersoner = $personers->getFirst();
		$this->assertTrue(is_object($somePersoner));
		$this->assertEquals(get_class($somePersoner), 'Personers');

		$personers = Personers::query()
			->where("status=:status:")
			->bind(array("status" => "A"))
			->order("navnes")
			->limit(100)->execute();
		$this->assertTrue(is_object($personers));
		$this->assertEquals(get_class($personers), 'Phalcon\Mvc\Model\Resultset\Simple');

		$somePersoner = $personers->getFirst();
		$this->assertTrue(is_object($somePersoner));
		$this->assertEquals(get_class($somePersoner), 'Personers');
	}

	protected function _executeTestsFromInput($di)
	{

		$data = array();
		$criteria = \Phalcon\Mvc\Model\Criteria::fromInput($di, "Robots", $data);
        $this->assertEquals($criteria->getParams(), NULL);

        $data = array('id' => 1);
		$criteria = \Phalcon\Mvc\Model\Criteria::fromInput($di, "Robots", $data);
        $this->assertEquals($criteria->getParams(), array(
			'conditions' => 'id=:id:',
			'bind' => array(
				'id' => 1,
			),
		));

		$data = array('name' => 'ol');
		$criteria = \Phalcon\Mvc\Model\Criteria::fromInput($di, "Robots", $data);
        $this->assertEquals($criteria->getParams(), array(
			'conditions' => 'name LIKE :name:',
			'bind' => array(
				'name' => '%ol%',
			),
		));

		$data = array('id' => 1, 'name' => 'ol');
		$criteria = \Phalcon\Mvc\Model\Criteria::fromInput($di, "Robots", $data);
		$this->assertEquals($criteria->getParams(), array(
			'conditions' => 'id=:id: AND name LIKE :name:',
			'bind' => array(
				'id' => 1,
				'name' => '%ol%',
			)
		));

		$data = array('id' => 1, 'name' => 'ol', 'other' => true);
		$criteria = \Phalcon\Mvc\Model\Criteria::fromInput($di, "Robots", $data);
		$this->assertEquals($criteria->getParams(), array(
			'conditions' => 'id=:id: AND name LIKE :name:',
			'bind' => array(
				'id' => 1,
				'name' => '%ol%',
			)
		));
	}

}
