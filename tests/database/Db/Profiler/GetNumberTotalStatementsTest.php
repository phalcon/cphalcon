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

final class GetNumberTotalStatementsTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Db\Profiler :: getNumberTotalStatements()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbProfilerGetNumberTotalStatements(): void
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

        $expected = 0;
        $actual   = $profiler->getNumberTotalStatements();
        $this->assertEquals($expected, $actual);

        $db->query('SELECT * FROM co_invoices LIMIT 3');

        $expected = 1;
        $actual   = $profiler->getNumberTotalStatements();
        $this->assertEquals($expected, $actual);

        $db->query('SELECT * FROM co_invoices LIMIT 100');

        $expected = 2;
        $actual   = $profiler->getNumberTotalStatements();
        $this->assertEquals($expected, $actual);

        $db->query('SELECT * FROM co_invoices LIMIT 5');

        $expected = 3;
        $actual   = $profiler->getNumberTotalStatements();
        $this->assertEquals($expected, $actual);
    }
}
