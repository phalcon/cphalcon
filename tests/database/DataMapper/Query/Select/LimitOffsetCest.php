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

namespace Phalcon\Tests\Database\DataMapper\Query\Select;

use Codeception\Stub;
use DatabaseTester;
use Phalcon\DataMapper\Query\QueryFactory;

class LimitOffsetCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: limit()/offset()
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectLimitOffset(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - limit()/offset()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->limit(10)
        ;

        $expected = "SELECT * FROM co_invoices LIMIT 10";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);

        $select->offset(50);

        $expected = "SELECT * FROM co_invoices LIMIT 10 OFFSET 50";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: limit()/offset() -
     * MSSSQL
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectLimitOffsetMssql(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - limit()/offset() - MSSQL');

        $connection     = $I->getDataMapperConnection();
        $mockConnection = Stub::make(
            $connection,
            [
                'getDriverName' => 'sqlsrv',
            ]
        );
        $factory        = new QueryFactory();
        $select         = $factory->newSelect($mockConnection);

        $select
            ->from('co_invoices')
            ->limit(10)
        ;

        $expected = "SELECT TOP 10 * FROM co_invoices";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);

        $select->offset(50);

        $expected = "SELECT * FROM co_invoices "
            . "OFFSET 50 ROWS FETCH NEXT 10 ROWS ONLY";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }
}
