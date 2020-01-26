<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\DM\Pdo\Connection;

use IntegrationTester;
use Phalcon\DM\Pdo\Connection;
use Phalcon\Test\Fixtures\Migrations\Invoices;

class QueryCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\Connection :: query()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionQuery(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - query()');

        /** @var Connection $connection */
        $connection = $I->getConnection();
        $invoice = new Invoices();
        $invoice->create($connection);

        $result = $invoice->insert($connection, 1);
        $I->assertEquals(1, $result);

        $all = $connection
            ->query('select * from co_invoices WHERE inv_id = 1')
            ->fetch()
        ;

        $I->assertIsArray($all);
        $I->assertEquals(1, $all['inv_id']);
        $I->assertArrayHasKey('inv_id', $all);
        $I->assertArrayHasKey('inv_cst_id', $all);
        $I->assertArrayHasKey('inv_status_flag', $all);
        $I->assertArrayHasKey('inv_title', $all);
        $I->assertArrayHasKey('inv_total', $all);
        $I->assertArrayHasKey('inv_created_at', $all);
    }
}
