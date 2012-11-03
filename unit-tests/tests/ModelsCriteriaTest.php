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
		if (file_exists('unit-tests/app/models/'.$className.'.php')) {
			require 'unit-tests/app/models/'.$className.'.php';
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
			require PATH_CONFIG . 'config.inc.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		});

		$this->_executeTests($di);
	}

	public function testModelsPostgresql()
	{
		$di = $this->_getDI();

		$di->set('db', function(){
			require PATH_CONFIG . 'config.inc.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		});

		$this->_executeTests($di);
	}

	public function testModelsSQLite()
	{

		$di = $this->_getDI();

		$di->set('db', function(){
			require PATH_CONFIG . 'config.inc.php';
			return new Phalcon\Db\Adapter\Pdo\SQLite($configSqlite);
		});

		$this->_executeTests($di);
	}


	protected function _executeTests($di)
	{

		$personas = Personas::query()->where("estado='I'")->execute();
		$people = People::find("estado='I'");
		$this->assertEquals(count($personas), count($people));

		$personas = Personas::query()->conditions("estado='I'")->execute();
		$people = People::find("estado='I'");
		$this->assertEquals(count($personas), count($people));

		$personas = Personas::query()->where("estado='A'")->order("nombres")->execute();
		$people = People::find(array("estado='A'", "order" => "nombres"));
		$this->assertEquals(count($personas), count($people));

		$somePersona = $personas->getFirst();
		$somePeople = $people->getFirst();
		$this->assertEquals($somePersona->cedula, $somePeople->cedula);

		$personas = Personas::query()->where("estado='A'")->order("nombres")->limit(100)->execute();
		$people = People::find(array("estado='A'", "order" => "nombres", "limit" => 100));
		$this->assertEquals(count($personas), count($people));

		$somePersona = $personas->getFirst();
		$somePeople = $people->getFirst();
		$this->assertEquals($somePersona->cedula, $somePeople->cedula);

		$personas = Personas::query()
			->where("estado=?1")
			->bind(array(1 => "A"))
			->order("nombres")
			->limit(100)->execute();
		$people = People::find(array("estado=?1", "bind" => array(1 => "A"), "order" => "nombres", "limit" => 100));
		$this->assertEquals(count($personas), count($people));

		$somePersona = $personas->getFirst();
		$somePeople = $people->getFirst();
		$this->assertEquals($somePersona->cedula, $somePeople->cedula);

		$personas = Personas::query()
			->where("estado=:estado:")
			->bind(array("estado" => "A"))
			->order("nombres")
			->limit(100)->execute();
		$people = People::find(array("estado=:estado:", "bind" => array("estado" => "A"), "order" => "nombres", "limit" => 100));
		$this->assertEquals(count($personas), count($people));

		$somePersona = $personas->getFirst();
		$somePeople = $people->getFirst();
		$this->assertEquals($somePersona->cedula, $somePeople->cedula);

	}


}
