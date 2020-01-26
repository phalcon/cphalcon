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

class FetchGroupCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\Connection :: fetchGroup()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionFetchGroup(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - fetchGroup()');

        /** @var Connection $connection */
        $connection = $I->getConnection();
        $invoice    = new Invoices($connection);

        $result = $invoice->insert($connection, 1);
        $I->assertEquals(1, $result);
        $result = $invoice->insert($connection, 2);
        $I->assertEquals(1, $result);
        $result = $invoice->insert($connection, 3);
        $I->assertEquals(1, $result);
        $result = $invoice->insert($connection, 4);
        $I->assertEquals(1, $result);

        $all = $connection->fetchGroup(
            'SELECT inv_status_flag, inv_id, inv_total from co_invoices'
        );

        $I->assertEquals(2, $all[0][0]['inv_id']);
        $I->assertEquals(4, $all[0][1]['inv_id']);
        $I->assertEquals(1, $all[1][0]['inv_id']);
        $I->assertEquals(3, $all[1][1]['inv_id']);
    }
}
