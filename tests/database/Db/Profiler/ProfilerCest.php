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
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Invoices;

use function substr;
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
        $title     = uniqid('tit-');
        $migration->insert(10, 20, 1, $title, 100);

        $invoices = Invoices::find();

        $expected = 1;
        $actual   = $invoices->count();
        $I->assertSame($expected, $actual);

        $profiles = $profiler->getProfiles();
        $I->assertCount(3, $profiles);

        /** @var Item $first */
        $first = $profiles[0];

        $nanoseconds = $first->getTotalElapsedNanoseconds();
        $miliseconds = $nanoseconds / 1000000;
        $seconds     = $miliseconds / 1000;

        $miliseconds = substr((string) $miliseconds, 0, 5);
        $seconds     = substr((string) $seconds, 0, 5);

        $expected = $miliseconds;
        $actual   = substr((string) $first->getTotalElapsedMilliseconds(), 0, 5);
        $I->assertSame($expected, $actual);

        $expected = $seconds;
        $actual   = substr((string) $first->getTotalElapsedSeconds(), 0, 5);
        $I->assertSame($expected, $actual);

        /**
         * Profile
         */
        $elapsed = $profiles[0]->getTotalElapsedSeconds()
            + $profiles[1]->getTotalElapsedSeconds()
            + $profiles[2]->getTotalElapsedSeconds();

        $elapsed = substr((string) $elapsed, 0, 5);

        $expected = $elapsed;
        $actual   = substr((string) $profiler->getTotalElapsedSeconds(), 0, 5);
        $I->assertSame($expected, $actual);

        $expected = 3;
        $actual   = $profiler->getNumberTotalStatements();
        $I->assertSame($expected, $actual);
    }
}
