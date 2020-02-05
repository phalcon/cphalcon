<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DM\Pdo\Connection;

use DatabaseTester;
use Phalcon\DM\Pdo\Connection;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;

class FetchValueCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Connection :: fetchValue()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionFetchValue(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - fetchValue()');

        /** @var Connection $connection */
        $connection = $I->getDMConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->clear();

        $result = $migration->insert(1);
        $I->assertEquals(1, $result);

        $all = $connection->fetchValue(
            'select inv_total from co_invoices WHERE inv_cst_id = ?',
            [
                0 => 1,
            ]
        );
        $I->assertEquals(101, $all);
    }
}
