<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\DataMapper\Pdo\Connection;

use DatabaseTester;
use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;

class FetchColumnCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection :: fetchColumn()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionFetchCol(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - fetchColumn()');

        /** @var Connection $connection */
        $connection = $I->getDataMapperConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->clear();

        $result = $migration->insert(1, 1, 1, null, 101);
        $I->assertEquals(1, $result);
        $result = $migration->insert(2, 1, 1, null, 102);
        $I->assertEquals(1, $result);
        $result = $migration->insert(3, 1, 1, null, 103);
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
