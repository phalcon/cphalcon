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

namespace Phalcon\Test\Database\DataMapper\Query\Select;

use DatabaseTester;
use Phalcon\DataMapper\Query\QueryFactory;

class DistinctCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: distinct()
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectDistinct(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - distinct()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->distinct()
            ->from('co_invoices')
            ->columns('inv_id', 'inc_cst_id')
        ;

        $expected = "SELECT DISTINCT inv_id, inc_cst_id FROM co_invoices";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: distinct() - twice
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectDistinctTwice(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - distinct() - twice');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->distinct()
            ->distinct()
            ->from('co_invoices')
            ->columns('inv_id', 'inc_cst_id')
        ;

        $expected = "SELECT DISTINCT inv_id, inc_cst_id FROM co_invoices";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: distinct() - unset
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectDistinctUnset(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - distinct() - unset');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->distinct()
            ->distinct(false)
            ->from('co_invoices')
            ->columns('inv_id', 'inc_cst_id')
        ;

        $expected = "SELECT inv_id, inc_cst_id FROM co_invoices";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }
}
