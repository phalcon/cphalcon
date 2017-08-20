<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file LICENSE.txt.                             |
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

		return $di;
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

		return $di;
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

		return $di;
	}

	public function testResultsetNormalMysql()
	{
		$di = $this->_prepareTestMysql();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$modelsManager = $di->get("modelsManager");

		$robotsRepository = $modelsManager->getRepository(Robots::class);

		$robots = $robotsRepository->find(array(
			'order' => 'id'
		));

		$this->_applyTests($robots);
	}

	public function testResultsetBindingMysql()
	{
		$di = $this->_prepareTestMysql();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$initialId = 0;
		$finalId = 4;

		$modelsManager = $di->get("modelsManager");

		$robotsRepository = $modelsManager->getRepository(Robots::class);

		$robots = $robotsRepository->find(array(
			'conditions' => 'id > :id1: and id < :id2:',
			'bind' => array('id1' => $initialId, 'id2' => $finalId),
			'order' => 'id'
		));

		$this->_applyTests($robots);
	}

	public function testResultsetNormalPostgresql()
	{
		$di = $this->_prepareTestPostgresql();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$modelsManager = $di->get("modelsManager");

		$robotsRepository = $modelsManager->getRepository(Robots::class);

		$robots = $robotsRepository->find(array('order' => 'id'));

		$this->_applyTests($robots);
	}

	public function testResultsetBindingPostgresql()
	{
		$di = $this->_prepareTestPostgresql();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$initialId = 0;
		$finalId = 4;

		$modelsManager = $di->get("modelsManager");

		$robotsRepository = $modelsManager->getRepository(Robots::class);

		$robots = $robotsRepository->find(array(
			'conditions' => 'id > :id1: and id < :id2:',
			'bind' => array('id1' => $initialId, 'id2' => $finalId),
			'order' => 'id'
		));

		$this->_applyTests($robots);
	}

	public function testResultsetNormalSqlite()
	{
		$di = $this->_prepareTestSqlite();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$modelsManager = $di->get("modelsManager");

		$robotsRepository = $modelsManager->getRepository(Robots::class);

		$robots = $robotsRepository->find(array('order' => 'id'));

		$this->_applyTests($robots);
	}

	public function testResultsetBindingSqlite()
	{
		$di = $this->_prepareTestSqlite();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$initialId = 0;
		$finalId = 4;

		$modelsManager = $di->get("modelsManager");

		$robotsRepository = $modelsManager->getRepository(Robots::class);

		$robots = $robotsRepository->find(array(
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

		$di = $this->_prepareTestMysql();

		$modelsManager = $di->get("modelsManager");

		$robotsRepository = $modelsManager->getRepository(Robots::class);

		$data = serialize($robotsRepository->find(array('order' => 'id')));

		$robots = unserialize($data);

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTests($robots);

	}

	public function testSerializeBindingsMysql()
	{
		$di = $this->_prepareTestMysql();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$initialId = 0;
		$finalId = 4;

		$modelsManager = $di->get("modelsManager");

		$robotsRepository = $modelsManager->getRepository(Robots::class);

		$data = serialize($robotsRepository->find(array(
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
		$di = $this->_prepareTestPostgresql();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$modelsManager = $di->get("modelsManager");

		$robotsRepository = $modelsManager->getRepository(Robots::class);

		$data = serialize($robotsRepository->find(array('order' => 'id')));

		$robots = unserialize($data);

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTests($robots);

	}

	public function testSerializeBindingsPostgresql()
	{
		$di = $this->_prepareTestPostgresql();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$initialId = 0;
		$finalId = 4;

		$modelsManager = $di->get("modelsManager");

		$robotsRepository = $modelsManager->getRepository(Robots::class);

		$data = serialize($robotsRepository->find(array(
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
		$di = $this->_prepareTestSqlite();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$modelsManager = $di->get("modelsManager");

		$robotsRepository = $modelsManager->getRepository(Robots::class);

		$data = serialize($robotsRepository->find(array('order' => 'id')));

		$robots = unserialize($data);

		$this->assertEquals(get_class($robots), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTests($robots);

	}

	public function testSerializeBindingsSqlite()
	{
		$di = $this->_prepareTestSqlite();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$initialId = 0;
		$finalId = 4;

		$modelsManager = $di->get("modelsManager");

		$robotsRepository = $modelsManager->getRepository(Robots::class);

		$data = serialize($robotsRepository->find(array(
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
		$di = $this->_prepareTestMysql();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$modelsManager = $di->get("modelsManager");

		$personasRepository = $modelsManager->getRepository(Personas::class);

		$data = serialize($personasRepository->find(array(
			'limit' => 33
		)));

		$personas = unserialize($data);

		$this->assertEquals(get_class($personas), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTestsBig($personas);

	}

	public function testSerializeBigPostgresql()
	{
		$di = $this->_prepareTestPostgresql();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$modelsManager = $di->get("modelsManager");

		$personasRepository = $modelsManager->getRepository(Personas::class);

		$data = serialize($personasRepository->find(array(
			'limit' => 33
		)));

		$personas = unserialize($data);

		$this->assertEquals(get_class($personas), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTestsBig($personas);

	}

	public function testSerializeBigSqlite()
	{
		$di = $this->_prepareTestSqlite();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$modelsManager = $di->get("modelsManager");

		$personasRepository = $modelsManager->getRepository(Personas::class);

		$data = serialize($personasRepository->find(array(
			'limit' => 33
		)));

		$personas = unserialize($data);

		$this->assertEquals(get_class($personas), 'Phalcon\Mvc\Model\Resultset\Simple');

		$this->_applyTestsBig($personas);

	}

	public function testResultsetNormalZero()
	{
		$di = $this->_prepareTestMysql();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$modelsManager = $di->get("modelsManager");

		$robotsRepository = $modelsManager->getRepository(Robots::class);

		$robots = $robotsRepository->find('id > 1000');

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
	
	public function testResultsetAppendIterator()
	{
		$di = $this->_prepareTestMysql();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}
		
		$modelsManager = $di->get("modelsManager");

		$robotsRepository = $modelsManager->getRepository(Robots::class);

		// see http://php.net/manual/en/appenditerator.construct.php
		$iterator = new \AppendIterator();
		$robots_first = $robotsRepository->find(array('limit' => 2));
		$robots_second = $robotsRepository->find(array('limit' => 1, 'offset' => 2));
		
		$robots_first_0 = $robots_first[0];
		$robots_first_1 = $robots_first[1];
		$robots_second_0 = $robots_second[0];
		
		$iterator->append($robots_first);
		$iterator->append($robots_second);
		
		$iterator->rewind();
		$this->assertTrue($iterator->valid());
		$this->assertEquals($iterator->key(), 0);
		$this->assertEquals($iterator->getIteratorIndex(), 0);
		$this->assertEquals(get_class($iterator->current()), 'Robots');
		$this->assertEquals($robots_first_0->name, $iterator->current()->name);
		
		$iterator->next();
		$this->assertTrue($iterator->valid());
		$this->assertEquals($iterator->key(), 1);
		$this->assertEquals($iterator->getIteratorIndex(), 0);
		$this->assertEquals(get_class($iterator->current()), 'Robots');
		$this->assertEquals($robots_first_1->name, $iterator->current()->name);
		
		$iterator->next();
		$this->assertTrue($iterator->valid());
		$this->assertEquals($iterator->key(), 0);
		$this->assertEquals($iterator->getIteratorIndex(), 1);
		$this->assertEquals(get_class($iterator->current()), 'Robots');
		$this->assertEquals($robots_second_0->name, $iterator->current()->name);
		
		$iterator->next();
		$this->assertFalse($iterator->valid());
	}
	
	public function testBigResultsetIteration()
	{
		$di = $this->_prepareTestSqlite();

		if (!$di) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$modelsManager = $di->get("modelsManager");

		$personasRepository = $modelsManager->getRepository(Personas::class);

		// Resultsets count > 25 use fetch for one row at a time
		$personas = $personasRepository->find(array(
			'limit' => 33
		));
		
		$this->assertEquals(count($personas), 33);
		
		$this->assertEquals(get_class($personas->getLast()), 'Personas');
		
		// take first object as reference
		$persona_first = $personas[0];
		$this->assertEquals(get_class($persona_first), 'Personas');
		
		// make sure objects are the same -> object was not recreared
		$this->assertSame($personas[0], $persona_first);
		$this->assertSame($personas->current(), $persona_first);
		$personas->rewind();
		$this->assertTrue($personas->valid());
		$this->assertSame($personas->current(), $persona_first);
		
		// second element
		$personas->next();
		$this->assertTrue($personas->valid());
		$persona_second = $personas->current();
		$this->assertSame($persona_second, $personas[1]);
		
		// move to last element
		$this->assertSame($personas->getLast(), $personas[32]);
		
		// invalid element
		$personas->seek(33);
		$this->assertFalse($personas->valid());
		$this->assertFalse($personas->current());
		try {
			$persona = $personas[33];
			$this->assertFalse(true);
		}
		catch(Exception $e){
			$this->assertEquals($e->getMessage(), 'The index does not exist in the cursor');
		}
		
		// roll-back-cursor -> query needs to be reexecuted
		// first object was now recreated... different instance, but equal content
		$this->assertNotSame($personas[0], $persona_first);
		$this->assertEquals($personas[0], $persona_first);
		$persona_first = $personas[0];
		
		// toArray also re-executes the query and invalidates internal pointer
		$array = $personas->toArray();
		$this->assertEquals(count($array), 33);
		
		// internal query is re-executed again and set to first 
		$this->assertNotSame($personas[0], $persona_first);
		$this->assertEquals($personas[0], $persona_first);
		
		// move to second element and validate
		$personas->next();
		$this->assertTrue($personas->valid());
		$this->assertEquals(get_class($personas[1]), 'Personas');
		$this->assertSame($personas->current(), $personas[1]);
		$this->assertEquals($persona_second, $personas[1]);
		
		// pick some random indices
		$this->assertEquals(get_class($personas[12]), 'Personas');
		$this->assertEquals(get_class($personas[23]), 'Personas');
		$this->assertEquals(get_class($personas[23]), 'Personas');
	}
}
