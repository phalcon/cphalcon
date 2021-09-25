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

use DatabaseTester;
use Phalcon\DataMapper\Query\QueryFactory;

class FromCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: from()
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectFrom(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - from()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->from('co_customers')
        ;

        $expected = "SELECT * FROM co_invoices, co_customers";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: from() - empty
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectFromEmpty(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - from() - empty');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);


        $expected = "SELECT *";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }
}
