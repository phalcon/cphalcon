<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DataMapper\Query\Insert;

use Codeception\Stub;
use DatabaseTester;
use Phalcon\DataMapper\Query\QueryFactory;
use Phalcon\Test\Fixtures\Migrations\Invoices;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;

use function uniqid;

class GetLastInsertIdCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Insert :: getLastInsertId()
     *
     * @since  2020-01-20
     */
    public function dMQueryInsertGetLastInsertId(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Insert - getLastInsertId()');

        $connection     = $I->getDataMapperConnection();
        $mockConnection = Stub::make(
            $connection,
            [
                'lastInsertId' => "12345",
            ]
        );
        $factory        = new QueryFactory();
        $insert         = $factory->newInsert($mockConnection);

        $name = uniqid('inv-');
        $insert
            ->into('co_invoices')
            ->columns(
                [
                    'inv_cst_id'      => 1,
                    'inv_status_flag' => 1,
                    'inv_title'       => $name,
                    'inv_total'       => 100.00,
                ]
            )
            ->set(
                'inv_created_at',
                $I->getDatabaseNow($connection->getDriverName())
            )
        ;

        $invId = $insert->getLastInsertId();
        $I->assertEquals("12345", $invId);
    }

    /**
     * Database Tests Phalcon\DataMapper\Query\Insert :: getLastInsertId() - real
     *
     * @since  2020-01-20
     */
    public function dMQueryInsertGetLastInsertIdReal(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Insert - getLastInsertId()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $insert     = $factory->newInsert($connection);
        (new InvoicesMigration($connection));

        $name = uniqid('inv-');
        $insert
            ->into('co_invoices')
            ->columns(
                [
                    'inv_cst_id'      => 1,
                    'inv_status_flag' => 1,
                    'inv_title'       => $name,
                    'inv_total'       => 100.00,
                ]
            )
            ->set(
                'inv_created_at',
                $I->getDatabaseNow($connection->getDriverName())
            )
        ;

        $insert->perform();
        $invId = $insert->getLastInsertId();

        $sql           = 'SELECT inv_id '
            . 'FROM co_invoices '
            . 'WHERE inv_title = "' . $name . '"';
        $result        = $connection->fetchOne($sql);
        $existingInvId = $result['inv_id'];

        $I->assertEquals($existingInvId, $invId);
    }
}
