<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DM\Pdo\Connection;

use DatabaseTester;
use Phalcon\DM\Pdo\Connection;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;

class FetchPairsCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Connection :: fetchPairs()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionFetchPairs(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - fetchPairs()');

        /** @var Connection $connection */
        $connection = $I->getDMConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->clear();

        $result = $migration->insert(1, 1, 1, null, 101);
        $I->assertEquals(1, $result);
        $result = $migration->insert(2, 1, 1, null, 102);
        $I->assertEquals(1, $result);
        $result = $migration->insert(3, 1, 1, null, 103);
        $I->assertEquals(1, $result);
        $result = $migration->insert(4, 1, 1, null, 104);
        $I->assertEquals(1, $result);

        $all = $connection->fetchPairs(
            'SELECT inv_id, inv_total from co_invoices'
        );
        $I->assertCount(4, $all);

        $expected = [
            1 => 101.00,
            2 => 102.00,
            3 => 103.00,
            4 => 104.00,
        ];

        $I->assertEquals($expected, $all);
    }
}
