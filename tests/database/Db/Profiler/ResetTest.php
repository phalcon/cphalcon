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

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class ResetTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * Executed before each test
     *
     * @return void
     */
    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Profiler :: reset()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbProfilerReset(): void
    {
        $eventsManager = $this->newService('eventsManager');
        $profiler      = $this->newService('profiler');
        $db            = $this->getService('db');

        $eventsManager->attach(
            'db',
            function ($event, $connection) use ($profiler) {
                if ($event->getType() === 'beforeQuery') {
                    $profiler->startProfile($connection->getSQLStatement());
                }

                if ($event->getType() === 'afterQuery') {
                    $profiler->stopProfile();
                }
            }
        );

        $db->setEventsManager($eventsManager);

        $db->query('SELECT * FROM co_invoices LIMIT 3');
        $db->query('SELECT * FROM co_invoices LIMIT 100');
        $db->query('SELECT * FROM co_invoices LIMIT 5');
        $db->query('SELECT * FROM co_invoices LIMIT 10');
        $db->query('SELECT * FROM co_invoices LIMIT 15');

        $this->assertCount(5, $profiler->getProfiles());

        $expected = 5;
        $actual   = $profiler->getNumberTotalStatements();
        $this->assertEquals($expected, $actual);

        $this->assertIsFloat($profiler->getTotalElapsedSeconds());

        $profiler->reset();

        $this->assertCount(0, $profiler->getProfiles());

        $expected = 0;
        $actual   = $profiler->getNumberTotalStatements();
        $this->assertEquals($expected, $actual);
    }
}
