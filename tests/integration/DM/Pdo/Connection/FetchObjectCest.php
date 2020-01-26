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
use Phalcon\Test\Fixtures\Resultset;
use stdClass;

class FetchObjectCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\Connection :: fetchObject()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionFetchObject(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - fetchObject()');

        /** @var Connection $connection */
        $connection = $I->getConnection();
        $invoice = new Invoices();
        $invoice->create($connection);

        $result = $invoice->insert($connection, 1);
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
     * Tests Phalcon\DM\Pdo\Connection :: fetchObject() - ctor
     *
     * @since  2020-01-25
     */
    public function connectionFetchObjectCtor(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - fetchObject() - ctor');

        /** @var Connection $connection */
        $connection = $I->getConnection();
        $invoice = new Invoices();
        $invoice->create($connection);

        $result = $invoice->insert($connection, 1);
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
