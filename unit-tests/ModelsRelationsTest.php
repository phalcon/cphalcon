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

class ModelsRelationsTest extends PHPUnit_Framework_TestCase
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
		$className = str_replace('\\', DIRECTORY_SEPARATOR, $className);
		if (file_exists('unit-tests/models/Relations/' . $className . '.php')) {
			require 'unit-tests/models/Relations/' . $className . '.php';
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
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$di = $this->_getDI();

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

		$this->_executeTestsNormal($di);
		$this->_executeTestsRenamed($di);
		$this->_testIssue938($di);
	}

	public function testModelsPostgresql()
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
		}, true);

		$this->_executeTestsNormal($di);
		$this->_executeTestsRenamed($di);

	}

	public function testModelsSqlite()
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
		}, true);

		$this->_executeTestsNormal($di);
		$this->_executeTestsRenamed($di);
		$this->_testIssue938($di);
	}

	public function _executeTestsNormal($di)
	{

		$manager = $di->getShared('modelsManager');

		$success = $manager->existsBelongsTo('RelationsRobotsParts', 'RelationsRobots');
		$this->assertTrue($success);

		$success = $manager->existsBelongsTo('RelationsRobotsParts', 'RelationsParts');
		$this->assertTrue($success);

		$success = $manager->existsHasMany('RelationsRobots', 'RelationsRobotsParts');
		$this->assertTrue($success);

		$success = $manager->existsHasMany('RelationsParts', 'RelationsRobotsParts');
		$this->assertTrue($success);

		$success = $manager->existsHasManyToMany('RelationsRobots', 'RelationsParts');
		$this->assertTrue($success);

		$robot = RelationsRobots::findFirst();
		$this->assertNotEquals($robot, false);

		$robotsParts = $robot->getRelationsRobotsParts();
		$this->assertEquals(get_class($robotsParts), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robotsParts), 3);

		$parts = $robot->getRelationsParts();
		$this->assertEquals(get_class($parts), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($parts), 3);

		/** Passing parameters to magic methods **/
		$robotsParts = $robot->getRelationsRobotsParts("parts_id = 1");
		$this->assertEquals(get_class($robotsParts), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robotsParts), 1);

		/** Passing parameters to magic methods **/
		$parts = $robot->getRelationsParts("RelationsParts.id = 1");
		$this->assertEquals(get_class($parts), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($parts), 1);

		$robotsParts = $robot->getRelationsRobotsParts(array(
			"parts_id > :parts_id:",
			"bind" => array("parts_id" => 1)
		));
		$this->assertEquals(get_class($robotsParts), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robotsParts), 2);
		$this->assertEquals($robotsParts->getFirst()->parts_id, 2);

		$parts = $robot->getRelationsParts(array(
			"RelationsParts.id > :id:",
			"bind" => array("id" => 1)
		));
		$this->assertEquals(get_class($parts), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($parts), 2);
		$this->assertEquals($parts->getFirst()->id, 2);

		$robotsParts = $robot->getRelationsRobotsParts(array(
			"parts_id > :parts_id:",
			"bind" => array("parts_id" => 1),
			"order" => "parts_id DESC"
		));
		$this->assertEquals(get_class($robotsParts), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robotsParts), 2);
		$this->assertEquals($robotsParts->getFirst()->parts_id, 3);

		/** Magic counting */
		$number = $robot->countRelationsRobotsParts();
		$this->assertEquals($number, 3);

		$part = RelationsParts::findFirst();
		$this->assertNotEquals($part, false);

		$robotsParts = $part->getRelationsRobotsParts();
		$this->assertEquals(get_class($robotsParts), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robotsParts), 1);

		$number = $part->countRelationsRobotsParts();
		$this->assertEquals($number, 1);

		$robotPart = RelationsRobotsParts::findFirst();
		$this->assertNotEquals($robotPart, false);

		$robot = $robotPart->getRelationsRobots();
		$this->assertEquals(get_class($robot), 'RelationsRobots');

		$part = $robotPart->getRelationsParts();
		$this->assertEquals(get_class($part), 'RelationsParts');

		/** Relations in namespaced models */
		$robot = Some\Robots::findFirst();
		$this->assertNotEquals($robot, false);

		$robotsParts = $robot->getRobotsParts();
		$this->assertEquals(get_class($robotsParts), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robotsParts), 3);

		$robotsParts = $robot->getRobotsParts("parts_id = 1");
		$this->assertEquals(get_class($robotsParts), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robotsParts), 1);

		$robotsParts = $robot->getRobotsParts(array(
			"parts_id > :parts_id:",
			"bind" => array("parts_id" => 1),
			"order" => "parts_id DESC"
		));
		$this->assertEquals(get_class($robotsParts), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robotsParts), 2);
		$this->assertEquals($robotsParts->getFirst()->parts_id, 3);

	}

	public function _executeTestsRenamed($di)
	{

		$manager = $di->getShared('modelsManager');

		$success = $manager->existsBelongsTo('RobottersDeles', 'Robotters');
		$this->assertTrue($success);

		$success = $manager->existsBelongsTo('RobottersDeles', 'Deles');
		$this->assertTrue($success);

		$success = $manager->existsHasMany('Robotters', 'RobottersDeles');
		$this->assertTrue($success);

		$success = $manager->existsHasMany('Deles', 'RobottersDeles');
		$this->assertTrue($success);

		$robotter = Robotters::findFirst();
		$this->assertNotEquals($robotter, false);

		$robottersDeles = $robotter->getRobottersDeles();
		$this->assertEquals(get_class($robottersDeles), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robottersDeles), 3);

		/** Passing parameters to magic methods **/
		$robottersDeles = $robotter->getRobottersDeles("delesCode = 1");
		$this->assertEquals(get_class($robottersDeles), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robottersDeles), 1);

		$robottersDeles = $robotter->getRobottersDeles(array(
			"delesCode > :delesCode:",
			"bind" => array("delesCode" => 1)
		));
		$this->assertEquals(get_class($robottersDeles), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robottersDeles), 2);
		$this->assertEquals($robottersDeles->getFirst()->delesCode, 2);

		$robottersDeles = $robotter->getRobottersDeles(array(
			"delesCode > :delesCode:",
			"bind" => array("delesCode" => 1),
			"order" => "delesCode DESC"
		));
		$this->assertEquals(get_class($robottersDeles), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robottersDeles), 2);
		$this->assertEquals($robottersDeles->getFirst()->delesCode, 3);

		/** Magic counting */
		$number = $robotter->countRobottersDeles();
		$this->assertEquals($number, 3);

		$dele = Deles::findFirst();
		$this->assertNotEquals($dele, false);

		$robottersDeles = $dele->getRobottersDeles();
		$this->assertEquals(get_class($robottersDeles), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robottersDeles), 1);

		$number = $dele->countRobottersDeles();
		$this->assertEquals($number, 1);

		$robotterDele = RobottersDeles::findFirst();
		$this->assertNotEquals($robotterDele, false);

		$robotter = $robotterDele->getRobotters();
		$this->assertEquals(get_class($robotter), 'Robotters');

		$dele = $robotterDele->getDeles();
		$this->assertEquals(get_class($dele), 'Deles');

		/** Relations in namespaced models */
		$robotter = Some\Robotters::findFirst();
		$this->assertNotEquals($robotter, false);

		$robottersDeles = $robotter->getRobottersDeles();
		$this->assertEquals(get_class($robottersDeles), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robottersDeles), 3);

		$robottersDeles = $robotter->getRobottersDeles("delesCode = 1");
		$this->assertEquals(get_class($robottersDeles), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robottersDeles), 1);

		$robottersDeles = $robotter->getRobottersDeles(array(
			"delesCode > :delesCode:",
			"bind" => array("delesCode" => 1),
			"order" => "delesCode DESC"
		));
		$this->assertEquals(get_class($robottersDeles), 'Phalcon\Mvc\Model\Resultset\Simple');
		$this->assertEquals(count($robottersDeles), 2);
		$this->assertEquals($robottersDeles->getFirst()->delesCode, 3);

	}

	protected function _testIssue938($di)
	{
		$manager = $di->getShared('modelsManager');
		$db      = $di->getShared('db');

		$this->assertTrue($db->delete('m2m_robots_parts'));
		$this->assertTrue($db->delete('m2m_parts'));
		$this->assertTrue($db->delete('m2m_robots'));

		$success = $manager->existsHasManyToMany('M2MRobots', 'M2MParts');
		$this->assertTrue($success);

		$robot = new M2MRobots();
		$robot->name = 'M2M';

		$part1 = new M2MParts();
		$part1->name = 'Part 1';

		$part2 = new M2MParts();
		$part2->name = 'Part 2';

		$part3 = new M2MParts();
		$part3->name = 'Part 3';

		$part4 = new M2MParts();
		$part4->name = 'Part 4';

		$this->assertTrue($part1->save());
		$this->assertTrue($part2->save());

		$robot->m2mparts = array($part1, $part2, $part3, $part4);

		$this->assertTrue($robot->save());

		$parts = M2MParts::find(array('order' => 'id'));
		$this->assertEquals(count($parts), 4);

		$rp = M2MRobotsParts::find(array('order' => 'robots_id, parts_id'));
		$this->assertEquals(count($rp), 4);

		for ($i=0; $i<count($rp); ++$i) {
			$this->assertEquals($parts[$i]->name, 'Part '. ($i+1));
			$this->assertEquals($rp[$i]->parts_id, $parts[$i]->id);
			$this->assertEquals($rp[$i]->robots_id, $robot->id);
		}
	}
}
