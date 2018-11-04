<?php

/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
		$this->assertEquals(get_class($profile), 'Phalcon\Db\Profiler\Item');

		$this->assertEquals($profile->getSQLStatement(), "SELECT * FROM personas LIMIT 3");
		$this->assertEquals(gettype($profile->getInitialTime()), "double");
		$this->assertEquals(gettype($profile->getFinalTime()), "double");
		$this->assertEquals(gettype($profile->getTotalElapsedSeconds()), "double");
		$this->assertTrue($profile->getFinalTime()>$profile->getInitialTime());

		$connection->query("SELECT * FROM personas LIMIT 100");

		$this->assertEquals($profiler->getNumberTotalStatements(), 2);

		$profile = $profiler->getLastProfile();
		$this->assertEquals(get_class($profile), 'Phalcon\Db\Profiler\Item');

		$this->assertEquals($profile->getSQLStatement(), "SELECT * FROM personas LIMIT 100");
		$this->assertTrue($profile->getFinalTime() > $profile->getInitialTime());

		$connection->query("SELECT * FROM personas LIMIT 5");
		$connection->query("SELECT * FROM personas LIMIT 10");
		$connection->query("SELECT * FROM personas LIMIT 15");

		$this->assertEquals(count($profiler->getProfiles()), 5);
		$this->assertEquals($profiler->getNumberTotalStatements(), 5);
		$this->assertEquals(gettype($profiler->getTotalElapsedSeconds()), "double");
		$this->assertEquals($profiler->getPoints(), 0);

		$profiler->reset();

		$this->assertEquals(count($profiler->getProfiles()), 0);
		$this->assertEquals($profiler->getNumberTotalStatements(), 0);
	}
}
