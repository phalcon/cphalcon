<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Profiler;

use IntegrationTester;
use Phalcon\Db\Profiler\Item;
use Phalcon\Events\Manager;
use Phalcon\Test\Fixtures\Db\ProfilerListener;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class GetLastProfileCest
 */
class GetLastProfileCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
    }



    /**
     * Tests Phalcon\Db\Profiler :: getLastProfile()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbProfilerGetLastProfile(IntegrationTester $I)
    {
        $I->wantToTest('Db\Profiler - getLastProfile()');
        $I->skipTest('Need implementation');
    }



    public function testDbMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $connection = $this->getService('db');

        $this->executeTests($I, $connection);
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



    private function executeTests(IntegrationTester $I, $connection)
    {
        $eventsManager = new Manager();
        $listener      = new ProfilerListener();

        $eventsManager->attach('db', $listener);

        $connection->setEventsManager($eventsManager);

        $connection->query("SELECT * FROM personas LIMIT 3");

        $profiler = $listener->getProfiler();

        $I->assertEquals(
            1,
            $profiler->getNumberTotalStatements()
        );

        $profile = $profiler->getLastProfile();

        $I->assertInstanceOf(
            Item::class,
            $profile
        );

        $I->assertEquals(
            "SELECT * FROM personas LIMIT 3",
            $profile->getSQLStatement()
        );

        $I->assertInternalType(
            'double',
            $profile->getInitialTime()
        );

        $I->assertInternalType(
            'double',
            $profile->getFinalTime()
        );

        $I->assertInternalType(
            'double',
            $profile->getTotalElapsedSeconds()
        );

        $I->assertTrue(
            $profile->getFinalTime() > $profile->getInitialTime()
        );

        $connection->query("SELECT * FROM personas LIMIT 100");

        $I->assertEquals(
            2,
            $profiler->getNumberTotalStatements()
        );

        $profile = $profiler->getLastProfile();

        $I->assertInstanceOf(
            Item::class,
            $profile
        );

        $I->assertEquals(
            "SELECT * FROM personas LIMIT 100",
            $profile->getSQLStatement()
        );

        $I->assertTrue(
            $profile->getFinalTime() > $profile->getInitialTime()
        );
    }
}
