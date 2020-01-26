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

class FetchObjectsCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\Connection :: fetchObjects()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionFetchObjects(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - fetchObjects()');

        /** @var Connection $connection */
        $connection = $I->getConnection();
        $invoice    = new Invoices($connection);

        $result = $invoice->insert($connection, 1);
        $I->assertEquals(1, $result);
        $result = $invoice->insert($connection, 2);
        $I->assertEquals(1, $result);
        $result = $invoice->insert($connection, 3);
        $I->assertEquals(1, $result);
        $result = $invoice->insert($connection, 4);
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
    public function connectionFetchObjectsCtor(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - fetchObjects() - ctor');

        /** @var Connection $connection */
        $connection = $I->getConnection();
        $invoice    = new Invoices($connection);

        $result = $invoice->insert($connection, 1);
        $I->assertEquals(1, $result);
        $result = $invoice->insert($connection, 2);
        $I->assertEquals(1, $result);
        $result = $invoice->insert($connection, 3);
        $I->assertEquals(1, $result);
        $result = $invoice->insert($connection, 4);
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
