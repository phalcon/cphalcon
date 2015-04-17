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

class ModelsEventsTest extends PHPUnit_Framework_TestCase
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

	protected function _prepareDI(&$trace)
	{
		Phalcon\DI::reset();

		$eventsManager = new Phalcon\Events\Manager();

		$eventsManager->attach('model', function($event, $model) use (&$trace) {
			if (!isset($trace[$event->getType()][get_class($model)])) {
				$trace[$event->getType()][get_class($model)] = 1;
			} else {
				$trace[$event->getType()][get_class($model)]++;
			}
		});

		$di = new Phalcon\DI();

		$di->set('modelsManager', function() use ($eventsManager) {

			$modelsManager = new Phalcon\Mvc\Model\Manager();

			$modelsManager->setEventsManager($eventsManager);

			return $modelsManager;
		}, true);

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		}, true);

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);
	}

	public function testEventsCreate()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$trace = array();

		$this->_prepareDI($trace);

		$robot = new GossipRobots();

		$robot->name = 'Test';
		$robot->year = 2000;
		$robot->type = 'Some Type';
		$robot->datetime = '1970/01/01 00:00:00';
		$robot->text = 'text';

		$robot->trace = &$trace;

		$robot->save();

		$this->assertEquals($trace, array(
			'beforeValidation' => array(
				'GossipRobots' => 2,
			),
			'beforeValidationOnCreate' => array(
				'GossipRobots' => 1,
			),
			'validation' => array(
				'GossipRobots' => 2,
			),
			'afterValidationOnCreate' => array(
				'GossipRobots' => 1,
			),
			'afterValidation' => array(
				'GossipRobots' => 2,
			),
			'beforeSave' => array(
				'GossipRobots' => 2,
			),
			'beforeCreate' => array(
				'GossipRobots' => 1,
			)
		));

	}

	public function testEventsUpdate()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$trace = array();

		$this->_prepareDI($trace);

		$robot = GossipRobots::findFirst();

		$robot->trace = &$trace;

		$robot->save();

		$this->assertEquals($trace, array(
			'beforeValidation' => array(
				'GossipRobots' => 2,
			),
			'beforeValidationOnUpdate' => array(
				'GossipRobots' => 2,
			),
			'validation' => array(
				'GossipRobots' => 2,
			),
			'afterValidationOnUpdate' => array(
				'GossipRobots' => 2,
			),
			'afterValidation' => array(
				'GossipRobots' => 2,
			),
			'beforeSave' => array(
				'GossipRobots' => 2,
			),
			'beforeUpdate' => array(
				'GossipRobots' => 2,
			),
			'afterUpdate' => array(
				'GossipRobots' => 2,
			),
			'afterSave' => array(
				'GossipRobots' => 2,
			),
		));

	}

	public function testEventsDelete()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$trace = array();

		$this->_prepareDI($trace);

		$robot = GossipRobots::findFirst();

		$robot->trace = &$trace;

		$robot->delete();

		$this->assertEquals($trace, array(
			'beforeDelete' => array(
				'GossipRobots' => 1,
			)
		));

	}

}
