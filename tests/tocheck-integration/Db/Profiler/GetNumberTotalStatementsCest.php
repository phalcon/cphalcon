<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Db\Profiler;

use Codeception\Example;
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

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * @dataProvider adaptersProvider
     */
    public function testDb(IntegrationTester $I, Example $example)
    {
        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $connection = $this->getService('db');

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

    private function adaptersProvider(): array
    {
        return [
            [
                'Mysql',
            ],
            [
                'Postgresql',
            ],
            [
                'Sqlite',
            ],
        ];
    }
}
