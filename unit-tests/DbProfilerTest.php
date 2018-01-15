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

use PHPUnit\Framework\TestCase;

class DbProfiler extends Phalcon\Db\Profiler
{

	private $_points = 0;

	public function beforeStartProfile($profile)
	{
		$this->_points++;
	}

	public function afterEndProfile($profile)
	{
		$this->_points--;
	}

	public function getPoints()
	{
		return $this->_points;
	}

}

class DbProfilerListener
{

	protected $_profiler;

	public function __construct()
	{
		$this->_profiler = new DbProfiler();
	}

	public function beforeQuery($event, $connection)
	{
		$this->_profiler->startProfile(
			$connection->getSQLStatement(),
			$connection->getSQLVariables(),
			$connection->getSQLBindTypes()
		);
	}

	public function afterQuery($event, $connection)
	{
		$this->_profiler->stopProfile();
	}

	public function getProfiler()
	{
		return $this->_profiler;
	}

}

class DbProfilerTest extends TestCase
{

	public function testDbMysql()
	{

		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$connection = new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);

		$this->_executeTests($connection);
	}

	public function testDbPostgresql()
	{

		require 'unit-tests/config.db.php';
		if (empty($configPostgresql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$connection = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);

		$this->_executeTests($connection);
	}

	public function testDbSqlite()
	{

		require 'unit-tests/config.db.php';
		if (empty($configSqlite)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		$connection = new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);

		$this->_executeTests($connection);
	}

	public function _executeTests($connection)
	{

		$eventsManager = new Phalcon\Events\Manager();

		$listener = new DbProfilerListener();

		$eventsManager->attach('db', $listener);

		$connection->setEventsManager($eventsManager);

		$connection->query("SELECT * FROM personas LIMIT 3");

		$profiler = $listener->getProfiler();

		$this->assertEquals($profiler->getNumberTotalStatements(), 1);

		$profile = $profiler->getLastProfile();
		$this->assertInstanceOf('Phalcon\Db\Profiler\Item', $profile);

		$this->assertEquals($profile->getSQLStatement(), "SELECT * FROM personas LIMIT 3");
		$this->assertInternalType('double', $profile->getInitialTime());
		$this->assertInternalType('double', $profile->getFinalTime());
		$this->assertInternalType('double', $profile->getTotalElapsedSeconds());
		$this->assertTrue($profile->getFinalTime()>$profile->getInitialTime());

		$connection->query("SELECT * FROM personas LIMIT 100");

		$this->assertEquals($profiler->getNumberTotalStatements(), 2);

		$profile = $profiler->getLastProfile();
		$this->assertInstanceOf('Phalcon\Db\Profiler\Item', $profile);

		$this->assertEquals($profile->getSQLStatement(), "SELECT * FROM personas LIMIT 100");
		$this->assertTrue($profile->getFinalTime() > $profile->getInitialTime());

		$connection->query("SELECT * FROM personas LIMIT 5");
		$connection->query("SELECT * FROM personas LIMIT 10");
		$connection->query("SELECT * FROM personas LIMIT 15");

		$this->assertCount(5, $profiler->getProfiles());
		$this->assertEquals($profiler->getNumberTotalStatements(), 5);
		$this->assertInternalType('double', $profiler->getTotalElapsedSeconds());
		$this->assertEquals($profiler->getPoints(), 0);

		$profiler->reset();

		$this->assertCount(0, $profiler->getProfiles());
		$this->assertEquals($profiler->getNumberTotalStatements(), 0);
	}
}
