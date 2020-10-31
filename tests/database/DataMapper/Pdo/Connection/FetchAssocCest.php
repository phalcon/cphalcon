<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DataMapper\Pdo\Connection;

use DatabaseTester;
use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;

class FetchAssocCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection :: fetchAssoc()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionFetchAssoc(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - fetchAssoc()');

        /** @var Connection $connection */
        $connection = $I->getDataMapperConnection();
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
