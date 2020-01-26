<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\DM\Pdo\Connection;

use IntegrationTester;
use Phalcon\DM\Pdo\Connection;
use Phalcon\Test\Fixtures\Migrations\Invoices;

class FetchAssocCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\Connection :: fetchAssoc()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionFetchAssoc(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - fetchAssoc()');

        /** @var Connection $connection */
        $connection = $I->getConnection();
        $invoice = new Invoices();
        $invoice->create($connection);

        $result = $invoice->insert($connection, 1);
        $I->assertEquals(1, $result);
        $result = $invoice->insert($connection, 2);
        $I->assertEquals(1, $result);
        $result = $invoice->insert($connection, 3);
        $I->assertEquals(1, $result);
        $result = $invoice->insert($connection, 4);
        $I->assertEquals(1, $result);

        $all = $connection->fetchAssoc(
            'SELECT * from co_invoices'
        );
        $I->assertCount(4, $all);

        $I->assertEquals(1, $all[1]['inv_id']);
        $I->assertEquals(2, $all[2]['inv_id']);
        $I->assertEquals(3, $all[3]['inv_id']);
        $I->assertEquals(4, $all[4]['inv_id']);
    }
}
