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

namespace Phalcon\Tests\Integration\Db\Profiler;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Events\Manager;
use Phalcon\Tests\Fixtures\Db\ProfilerListener;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use function is_double;

class ResetCest
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
    public function executeTests(IntegrationTester $I, Example $example)
    {
        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $connection = $this->getService('db');

        $eventsManager = new Manager();
        $listener      = new ProfilerListener();

        $eventsManager->attach('db', $listener);

        $connection->setEventsManager($eventsManager);

        $profiler = $listener->getProfiler();

        $connection->query('SELECT * FROM personas LIMIT 3');
        $connection->query('SELECT * FROM personas LIMIT 100');
        $connection->query('SELECT * FROM personas LIMIT 5');
        $connection->query('SELECT * FROM personas LIMIT 10');
        $connection->query('SELECT * FROM personas LIMIT 15');

        $I->assertCount(
            5,
            $profiler->getProfiles()
        );

        $I->assertEquals(
            5,
            $profiler->getNumberTotalStatements()
        );

        $I->assertTrue(is_double($profiler->getTotalElapsedSeconds()));

        $I->assertEquals(
            0,
            $profiler->getPoints()
        );

        $profiler->reset();

        $I->assertCount(
            0,
            $profiler->getProfiles()
        );

        $I->assertEquals(
            0,
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
