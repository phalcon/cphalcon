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

class FetchAffectedCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Connection :: fetchAffected()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionFetchAffected(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - fetchAffected()');

        /** @var Connection $connection */
        $connection = $I->getDMConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->clear();

        $result = $migration->insert(1);
        $I->assertEquals(1, $result);
        $result = $migration->insert(2);
        $I->assertEquals(1, $result);
        $result = $migration->insert(3);
        $I->assertEquals(1, $result);
        $result = $migration->insert(4);
        $I->assertEquals(1, $result);

        $all = $connection->fetchAffected(
            'delete from co_invoices'
        );
        $I->assertEquals(4, $all);
    }
}
