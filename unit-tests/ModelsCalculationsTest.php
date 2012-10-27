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

class ModelsCalculationsTest extends PHPUnit_Framework_TestCase
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

	public function testCalculationsMysql(){

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/app/config/config.inc.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		});

		$this->_executeTests();

	}

	public function testCalculationsPostgresql()
	{

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/app/config/config.inc.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		});

		$this->_executeTests($di);

	}

	public function testCalculationsSqlite()
	{

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/app/config/config.inc.php';
			return new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);
		});

		$this->_executeTests($di);
	}

	protected function _executeTests()
	{

		//Count calculations
		$rowcount = Personnes::count();
		$this->assertEquals($rowcount, 2180);

		$rowcount = Personnes::count(array('distinct' => 'estado'));
		$this->assertEquals($rowcount, 2);

		$rowcount = Personnes::count("estado='A'");
		$this->assertEquals($rowcount, 2178);

		$group = Personnes::count(array("group" => "estado"));
		$this->assertEquals(2, count($group));

		$group = Personnes::count(array("group" => "estado", "order" => "estado"));
		$this->assertEquals(2, count($group));

		$results = array('A' => 2178, 'I' => 2);
		foreach($group as $row){
			$this->assertEquals($results[$row->estado], $row->rowcount);
		}

		$this->assertEquals($group[0]->rowcount, 2178);
		$this->assertEquals($group[1]->rowcount, 2);

		$group = Personnes::count(array("group" => "estado"));
		$this->assertEquals(2, count($group));

		$group = Personnes::count(array("group" => "ciudad_id"));
		$this->assertEquals(285, count($group));

		$group = Personnes::count(array("group" => "ciudad_id", "order" => "rowcount DESC"));
		$this->assertEquals($group[0]->rowcount, 727);

		//Summatory
		$total = Personnes::sum(array("column" => "cupo"));
		$this->assertEquals(995066020.00, $total);

		$total = Personnes::sum(array("column" => "cupo", "conditions" => "estado='I'"));
		$this->assertEquals(567020.00, $total);

		$group = Personnes::sum(array("column" => "cupo", "group" => "estado"));
		$this->assertEquals(2, count($group));

		$results = array('A' => 994499000.00, 'I' => 567020.00);
		foreach($group as $row){
			$this->assertEquals($results[$row->estado], $row->sumatory);
		}

		$group = Personnes::sum(array("column" => "cupo", "group" => "ciudad_id", "order" => "sumatory DESC"));
		$this->assertEquals($group[0]->sumatory, 358467690.00);

		//Average
		$total = Personnes::average(array("column" => "cupo"));
		$this->assertEquals(456452.30, sprintf("%.2f", $total));

		$total = Personnes::average(array("column" => "cupo", "conditions" => "estado='I'"));
		$this->assertEquals(283510.00, $total);

		$group = Personnes::average(array("column" => "cupo", "group" => "estado"));
		$this->assertEquals(2, count($group));

		$results = array('A' => 456611.11, 'I' => 283510.00);
		foreach($group as $row){
			$this->assertEquals($results[$row->estado], sprintf("%.2f", $row->average));
		}

		$group = Personnes::average(array("column" => "cupo", "group" => "ciudad_id", "order" => "average DESC"));
		$this->assertEquals($group[0]->average, 996200.00);

		//Maximum
		$max = Personnes::maximum(array("column" => "ciudad_id"));
		$this->assertEquals($max, 302172);

		$max = Personnes::maximum(array("column" => "ciudad_id", "conditions" => "estado='I'"));
		$this->assertEquals($max, 127591);

		$group = Personnes::maximum(array("column" => "ciudad_id", "group" => "estado"));
		$this->assertEquals(2, count($group));

		$results = array('A' => 302172, 'I' => 127591);
		foreach($group as $row){
			$this->assertEquals($results[$row->estado], $row->maximum);
		}

		$group = Personnes::maximum(array("column" => "ciudad_id", "group" => "estado", "order" => "maximum DESC"));
		$this->assertEquals($group[0]->maximum, 302172);

		//Minimum
		$max = Personnes::minimum(array("column" => "ciudad_id"));
		$this->assertEquals($max, 20404);

		$max = Personnes::minimum(array("column" => "ciudad_id", "conditions" => "estado='I'"));
		$this->assertEquals($max, 127591);

		$group = Personnes::minimum(array("column" => "ciudad_id", "group" => "estado"));
		$this->assertEquals(2, count($group));

		$results = array('A' => 20404, 'I' => 127591);
		foreach($group as $row){
			$this->assertEquals($results[$row->estado], $row->minimum);
		}

		$group = Personnes::minimum(array("column" => "ciudad_id", "group" => "estado", "order" => "minimum DESC"));
		$this->assertEquals($group[0]->minimum, 127591);

		$group = Personnes::minimum(array("column" => "ciudad_id", "group" => "estado", "order" => "minimum ASC"));
		$this->assertEquals($group[0]->minimum, 20404);

	}


}