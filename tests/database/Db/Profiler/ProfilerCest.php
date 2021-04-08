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

namespace Phalcon\Tests\Database\Db\Profiler;

use DatabaseTester;
use Phalcon\Db\Profiler\Item;
use Phalcon\Storage\Exception;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

use Phalcon\Tests\Models\Invoices;

use function uniqid;

class ProfilerCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Db\Profiler :: full
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-11-30
     *
     * @group  mysql
     */
    public function dbProfilerFull(DatabaseTester $I)
    {
        $I->wantToTest('Db\Profiler - full');

        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        $eventsManager = $this->newService('eventsManager');
        $profiler      = $this->newService('profiler');
        $connection    = $this->getService('db');

        $eventsManager->attach(
            'db',
            function ($event, $connection) use ($profiler) {
                if ($event->getType() === 'beforeQuery') {
                    $profiler->startProfile(
                        $connection->getSQLStatement()
                    );
                }

                if ($event->getType() === 'afterQuery') {
                    $profiler->stopProfile();
                }
            }
        );

        $connection->setEventsManager($eventsManager);

        $migration = new InvoicesMigration($I->getConnection());
        $title = uniqid('tit-');
        $migration->insert(10, 20, 1, $title,100);

        $invoices = Invoices::find();

        $expected = 1;
        $actual   = $invoices->count();
        $I->assertEquals($expected, $actual);

        $profiles = $profiler->getProfiles();
        $I->assertCount(3, $profiles);

        /** @var Item $first */
        $first = $profiles[0];

//        $expected = '';
//        $actual   = $first->getFinalTime();
//        $I->assertEquals($expected, $actual);

        $expected = '';
        $actual   = $first->getTotalElapsedSeconds();
        $I->assertEquals($expected, $actual);

        $expected = '';
        $actual   = $first->getInitialTime();
        $I->assertEquals($expected, $actual);

        $expected = '';
        $actual   = $first->getSqlStatement();
        $I->assertEquals($expected, $actual);
    }
}
