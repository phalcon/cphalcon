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
use Phalcon\Db\Profiler\Item;
use Phalcon\Events\Manager;
use Phalcon\Tests\Fixtures\Db\ProfilerListener;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use function is_double;

class GetLastProfileCest
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

        $connection->query('SELECT * FROM personas LIMIT 3');

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
            'SELECT * FROM personas LIMIT 3',
            $profile->getSQLStatement()
        );

        $I->assertTrue(is_double($profile->getInitialTime()));
        $I->assertTrue(is_double($profile->getFinalTime()));
        $I->assertTrue(is_double($profile->getTotalElapsedSeconds()));

        $I->assertTrue(
            $profile->getFinalTime() > $profile->getInitialTime()
        );

        $connection->query('SELECT * FROM personas LIMIT 100');

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
            'SELECT * FROM personas LIMIT 100',
            $profile->getSQLStatement()
        );

        $I->assertTrue(
            $profile->getFinalTime() > $profile->getInitialTime()
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
