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
use Phalcon\Events\Manager;
use Phalcon\Test\Fixtures\Db\ProfilerListener;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetNumberTotalStatementsCest
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

        $profiler = $listener->getProfiler();

        $I->assertEquals(
            0,
            $profiler->getNumberTotalStatements()
        );

        $connection->query('SELECT * FROM personas LIMIT 3');

        $I->assertEquals(
            1,
            $profiler->getNumberTotalStatements()
        );

        $connection->query('SELECT * FROM personas LIMIT 100');

        $I->assertEquals(
            2,
            $profiler->getNumberTotalStatements()
        );

        $connection->query('SELECT * FROM personas LIMIT 5');

        $I->assertEquals(
            3,
            $profiler->getNumberTotalStatements()
        );
    }
}
