<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\DataMapper\Pdo\Connection;

use DatabaseTester;
use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Resultset;
use stdClass;

class FetchObjectCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection :: fetchObject()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionFetchObject(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - fetchObject()');

        /** @var Connection $connection */
        $connection = $I->getDataMapperConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->clear();

        $result = $migration->insert(1, 1, 1, null, 101);
        $I->assertEquals(1, $result);

        $all = $connection->fetchObject(
            'select inv_id, inv_total from co_invoices WHERE inv_id = ?',
            [
                0 => 1,
            ]
        );

        $I->assertInstanceOf(stdClass::class, $all);
        $I->assertEquals(1, $all->inv_id);
        $I->assertEquals(101, $all->inv_total);
    }

    /**
     * Tests Phalcon\DataMapper\Pdo\Connection :: fetchObject() - ctor
     *
     * @since  2020-01-25
     */
    public function connectionFetchObjectCtor(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - fetchObject() - ctor');

        /** @var Connection $connection */
        $connection = $I->getDataMapperConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->clear();

        $result = $migration->insert(1, 1, 1, null, 101);
        $I->assertEquals(1, $result);

        $all = $connection->fetchObject(
            'select inv_id, inv_total from co_invoices WHERE inv_id = ?',
            [
                0 => 1,
            ],
            Resultset::class,
            [
                'vader',
            ]
        );

        $I->assertInstanceOf(Resultset::class, $all);
        $I->assertEquals('vader', $all->calculated);
        $I->assertEquals(1, $all->inv_id);
        $I->assertEquals(101, $all->inv_total);
    }
}
