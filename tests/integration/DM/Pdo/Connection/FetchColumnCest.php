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

class FetchColumnCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\Connection :: fetchColumn()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionFetchCol(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - fetchColumn()');

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

        $all = $connection->fetchColumn(
            'select * from co_invoices'
        );

        $I->assertIsArray($all);
        $I->assertEquals(1, $all[0]);
        $I->assertEquals(2, $all[1]);
        $I->assertEquals(3, $all[2]);

        $all = $connection->fetchColumn(
            'select * from co_invoices',
            [],
            4
        );

        /**
         * Intentionally casting things as an array because I don't want
         * drivers to fail based on how many decimals they can hold
         */
        $I->assertIsArray($all);
        $I->assertEquals(101, (int) $all[0]);
        $I->assertEquals(102, (int) $all[1]);
        $I->assertEquals(103, (int) $all[2]);
    }
}
