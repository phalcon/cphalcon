<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db;

use IntegrationTester;
use Phalcon\Events\Manager;
use Phalcon\Test\Fixtures\Db\ProfilerListener;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class DbProfilerCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
    }

    public function testDbMysql(IntegrationTester $I)
    {
        $this->setDiMysql();
        $connection = $this->getService('db');

        $this->executeTests($I, $connection);
    }

    private function executeTests(IntegrationTester $I, $connection)
    {
        $eventsManager = new Manager();
        $listener      = new ProfilerListener();

        $eventsManager->attach('db', $listener);
        $connection->setEventsManager($eventsManager);
        $connection->query("SELECT * FROM personas LIMIT 3");

        $profiler = $listener->getProfiler();

        $I->assertEquals($profiler->getNumberTotalStatements(), 1);

        $profile = $profiler->getLastProfile();
        $I->assertInstanceOf('Phalcon\Db\Profiler\Item', $profile);

        $I->assertEquals($profile->getSQLStatement(), "SELECT * FROM personas LIMIT 3");
        $I->assertInternalType('double', $profile->getInitialTime());
        $I->assertInternalType('double', $profile->getFinalTime());
        $I->assertInternalType('double', $profile->getTotalElapsedSeconds());
        $I->assertTrue($profile->getFinalTime() > $profile->getInitialTime());

        $connection->query("SELECT * FROM personas LIMIT 100");

        $I->assertEquals($profiler->getNumberTotalStatements(), 2);

        $profile = $profiler->getLastProfile();
        $I->assertInstanceOf('Phalcon\Db\Profiler\Item', $profile);

        $I->assertEquals($profile->getSQLStatement(), "SELECT * FROM personas LIMIT 100");
        $I->assertTrue($profile->getFinalTime() > $profile->getInitialTime());

        $connection->query("SELECT * FROM personas LIMIT 5");
        $connection->query("SELECT * FROM personas LIMIT 10");
        $connection->query("SELECT * FROM personas LIMIT 15");

        $I->assertCount(5, $profiler->getProfiles());
        $I->assertEquals($profiler->getNumberTotalStatements(), 5);
        $I->assertInternalType('double', $profiler->getTotalElapsedSeconds());
        $I->assertEquals($profiler->getPoints(), 0);

        $profiler->reset();

        $I->assertCount(0, $profiler->getProfiles());
        $I->assertEquals($profiler->getNumberTotalStatements(), 0);
    }

    public function testDbPostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();
        $connection = $this->getService('db');

        $this->executeTests($I, $connection);
    }

    public function testDbSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();
        $connection = $this->getService('db');

        $this->executeTests($I, $connection);
    }
}
