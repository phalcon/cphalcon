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

class ModelsResultsetTest extends PHPUnit_Framework_TestCase
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

	protected function _prepareTestMysql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			return false;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

		return true;
	}

	protected function _prepareTestPostgresql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configPostgresql)) {
			return false;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
		}, true);

		return true;
	}

	protected function _prepareTestSqlite()
	{
		require 'unit-tests/config.db.php';
		if (empty($configSqlite)) {
			return false;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);
		}, true);

		return true;
	}

	public function testResultsetNormalMysql()
	{
		if (!$this->_prepareTestMysql()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$robots = Robots::find(array(
			'order' => 'id'
		));

		$this->_applyTests($robots);
	}

	public function testResultsetBindingMysql()
	{
		if (!$this->_prepareTestMysql()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$initialId = 0;
		$finalId = 4;

		$robots = Robots::find(array(
			'conditions' => 'id > :id1: and id < :id2:',
			'bind' => array('id1' => $initialId, 'id2' => $finalId),
			'order' => 'id'
		));

		$this->_applyTests($robots);
	}

	public function testResultsetNormalPostgresql()
	{
		if (!$this->_prepareTestPostgresql()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$robots = Robots::find(array('order' => 'id'));

		$this->_applyTests($robots);
	}

	public function testResultsetBindingPostgresql()
	{
		if (!$this->_prepareTestPostgresql()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$initialId = 0;
		$finalId = 4;

		$robots = Robots::find(array(
			'conditions' => 'id > :id1: and id < :id2:',
			'bind' => array('id1' => $initialId, 'id2' => $finalId),
			'order' => 'id'
		));

		$this->_applyTests($robots);
	}

	public function testResultsetNormalSqlite()
	{
		if (!$this->_prepareTestSqlite()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$robots = Robots::find(array('order' => 'id'));

		$this->_applyTests($robots);
	}

	public function testResultsetBindingSqlite()
	{
		if (!$this->_prepareTestSqlite()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$initialId = 0;
		$finalId = 4;

		$robots = Robots::find(array(
			'conditions' => 'id > :id1: and id < :id2:',
			'bind' => array('id1' => $initialId, 'id2' => $finalId),
			'order' => 'id'
		));

		$this->_applyTests($robots);
	}

	public function _applyTests($robots)
	{

		$this->assertEquals(count($robots), 3);
		$this->assertEquals($robots->count(), 3);

		//Using a foreach
		$number = 0;
		foreach ($robots as $robot) {
			$this->assertEquals($robot->id, $number+1);
			$number++;
		}
		$this->assertEquals($number, 3);

		//Using a while
		$number = 0;
		$robots->rewind();
		while ($robots->valid()) {
			$robot = $robots->current();
			$this->assertEquals($robot->id, $number+1);
			$robots->next();
			$number++;
		}
		$this->assertEquals($number, 3);

		$robots->seek(1);
		$robots->valid();
		$robot = $robots->current();
		$this->assertEquals($robot->id, 2);

		$robot = $robots->getFirst();
		$this->assertEquals($robot->id, 1);

		$robot = $robots->getLast();
		$this->assertEquals($robot->id, 3);

		$robot = $robots[0];
		$this->assertEquals($robot->id, 1);

		$robot = $robots[2];
		$this->assertEquals($robot->id, 3);

		$this->assertFalse(isset($robots[4]));

		$filtered = $robots->filter(function($robot){
			if ($robot->id < 3) {
				return $robot;
			}
		});

		$this->assertEquals(count($filtered), 2);
		$this->assertEquals($filtered[0]->id, 1);
		$this->assertEquals($filtered[1]->id, 2);

	}

	public function _applyTestsBig($personas)
	{

		$this->assertEquals(count($personas), 33);
		$this->assertEquals($personas->count(), 33);

		//Using a foreach
		$number = 0;
		foreach ($personas as $persona) {
			$number++;
		}
		$this->assertEquals($number, 33);

		//Using a while
		$number = 0;
		$personas->rewind();
		while ($personas->valid()) {
			$persona = $personas->current();
			$personas->next();
			$number++;
		}
		$this->assertEquals($number, 33);

		$personas->seek(1);
		$personas->valid();
		$persona = $personas->current();
		$this->assertEquals(get_class($persona), 'Personas');

		$persona = $personas->getFirst();
		$this->assertEquals(get_class($persona), 'Personas');

		$persona = $personas->getLast();
		$this->assertEquals(get_class($persona), 'Personas');

		$persona = $personas[0];
		$this->assertEquals(get_class($persona), 'Personas');

		$persona = $personas[2];
		$this->assertEquals(get_class($persona), 'Personas');

		$this->assertFalse(isset($personas[40]));

	}

	public function testSerializeNormalMysql()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$this->_prepareTestMysql();

		$data = serialize(Robots::find(array('order' => 'id')));

		$robots = unserialize($data);

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTests($robots);

	}

	public function testSerializeBindingsMysql()
	{
		if (!$this->_prepareTestMysql()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$initialId = 0;
		$finalId = 4;

		$data = serialize(Robots::find(array(
			'conditions' => 'id > :id1: and id < :id2:',
			'bind' => array('id1' => $initialId, 'id2' => $finalId),
			'order' => 'id'
		)));

		$robots = unserialize($data);

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTests($robots);

	}

	public function testSerializeNormalPostgresql()
	{
		if (!$this->_prepareTestPostgresql()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$data = serialize(Robots::find(array('order' => 'id')));

		$robots = unserialize($data);

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTests($robots);

	}

	public function testSerializeBindingsPostgresql()
	{
		if (!$this->_prepareTestPostgresql()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$initialId = 0;
		$finalId = 4;

		$data = serialize(Robots::find(array(
			'conditions' => 'id > :id1: and id < :id2:',
			'bind' => array('id1' => $initialId, 'id2' => $finalId),
			'order' => 'id'
		)));

		$robots = unserialize($data);

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTests($robots);

	}

	public function testSerializeNormalSqlite()
	{
		if (!$this->_prepareTestSqlite()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$data = serialize(Robots::find(array('order' => 'id')));

		$robots = unserialize($data);

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTests($robots);

	}

	public function testSerializeBindingsSqlite()
	{
		if (!$this->_prepareTestSqlite()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$initialId = 0;
		$finalId = 4;

		$data = serialize(Robots::find(array(
			'conditions' => 'id > :id1: and id < :id2:',
			'bind' => array('id1' => $initialId, 'id2' => $finalId),
			'order' => 'id'
		)));

		$robots = unserialize($data);

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTests($robots);

	}

	public function testSerializeBigMysql()
	{
		if (!$this->_prepareTestMysql()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$data = serialize(Personas::find(array(
			'limit' => 33
		)));

		$personas = unserialize($data);

		$this->assertEquals(get_class($personas), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTestsBig($personas);

	}

	public function testSerializeBigPostgresql()
	{
		if (!$this->_prepareTestPostgresql()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$data = serialize(Personas::find(array(
			'limit' => 33
		)));

		$personas = unserialize($data);

		$this->assertEquals(get_class($personas), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTestsBig($personas);

	}

	public function testSerializeBigSqlite()
	{
		if (!$this->_prepareTestSqlite()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$data = serialize(Personas::find(array(
			'limit' => 33
		)));

		$personas = unserialize($data);

		$this->assertEquals(get_class($personas), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTestsBig($personas);

	}

	public function testResultsetNormalZero()
	{
		if (!$this->_prepareTestMysql()) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$robots = Robots::find('id > 1000');

		$this->assertEquals(count($robots), 0);
		$this->assertEquals($robots->count(), 0);

		//Using a foreach
		$number = 0;
		foreach ($robots as $robot) {
			$number++;
		}
		$this->assertEquals($number, 0);

		//Using a while
		$number = 0;
		$robots->rewind();
		while ($robots->valid()) {
			$robots->next();
			$number++;
		}
		$this->assertEquals($number, 0);

		$robots->seek(1);
		$robots->valid();
		$robot = $robots->current();
		$this->assertFalse($robot);

		$robot = $robots->getFirst();
		$this->assertFalse($robot);

		$robot = $robots->getLast();
		$this->assertFalse($robot);

		try {
			$robot = $robots[0];
			$this->assertFalse(true);
		}
		catch(Exception $e){
			$this->assertEquals($e->getMessage(), 'The index does not exist in the cursor');
		}

		try {
			$robot = $robots[2];
			$this->assertFalse(true);
		}
		catch(Exception $e){
			$this->assertEquals($e->getMessage(), 'The index does not exist in the cursor');
		}

		$this->assertFalse(isset($robots[0]));
	}

}