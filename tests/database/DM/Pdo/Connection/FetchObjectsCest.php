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
use Phalcon\Test\Fixtures\Resultset;
use stdClass;

class FetchObjectsCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Connection :: fetchObjects()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionFetchObjects(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - fetchObjects()');

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

        $all = $connection->fetchObjects(
            'SELECT * from co_invoices'
        );
        $I->assertCount(4, $all);

        $I->assertInstanceOf(stdClass::class, $all[0]);
        $I->assertInstanceOf(stdClass::class, $all[1]);
        $I->assertInstanceOf(stdClass::class, $all[2]);
        $I->assertInstanceOf(stdClass::class, $all[3]);

        $I->assertEquals(1, $all[0]->inv_id);
        $I->assertEquals(2, $all[1]->inv_id);
        $I->assertEquals(3, $all[2]->inv_id);
        $I->assertEquals(4, $all[3]->inv_id);
    }

    /**
     * Tests Phalcon\DM\Pdo\Connection :: fetchObjects() - ctor
     *
     * @since  2020-01-25
     */
    public function connectionFetchObjectsCtor(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - fetchObjects() - ctor');

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

        $all = $connection->fetchObjects(
            'SELECT * from co_invoices',
            [],
            Resultset::class,
            [
                'darth',
            ]
        );
        $I->assertCount(4, $all);

        $I->assertInstanceOf(Resultset::class, $all[0]);
        $I->assertInstanceOf(Resultset::class, $all[1]);
        $I->assertInstanceOf(Resultset::class, $all[2]);
        $I->assertInstanceOf(Resultset::class, $all[3]);

        $I->assertEquals(1, $all[0]->inv_id);
        $I->assertEquals(2, $all[1]->inv_id);
        $I->assertEquals(3, $all[2]->inv_id);
        $I->assertEquals(4, $all[3]->inv_id);

        $I->assertEquals('darth', $all[0]->calculated);
        $I->assertEquals('darth', $all[1]->calculated);
        $I->assertEquals('darth', $all[2]->calculated);
        $I->assertEquals('darth', $all[3]->calculated);
    }
}
