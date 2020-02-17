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
use PDO;
use Phalcon\DataMapper\Query\QueryFactory;

class JoinCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: join() - left
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectJoinLeft(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - join() - left');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->join($select::JOIN_LEFT, 'co_customers', 'inv_cst_id = cst_id')
        ;

        $expected = "SELECT * FROM co_invoices "
            . "LEFT JOIN co_customers ON inv_cst_id = cst_id";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: join() - on right
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectJoinRight(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - join() - on right');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->join($select::JOIN_RIGHT, 'co_customers', 'inv_cst_id = cst_id')
        ;

        $expected = "SELECT * FROM co_invoices "
            . "RIGHT JOIN co_customers ON inv_cst_id = cst_id";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: join() - inner
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectJoinInner(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - join() - inner');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->join($select::JOIN_INNER, 'co_customers', 'inv_cst_id = cst_id')
        ;


        $expected = "SELECT * FROM co_invoices "
            . "INNER JOIN co_customers ON inv_cst_id = cst_id";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: join()
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectJoinNatural(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - join() - natural');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->join($select::JOIN_NATURAL, 'co_customers', 'inv_cst_id = cst_id')
        ;

        $expected = "SELECT * FROM co_invoices "
            . "NATURAL JOIN co_customers ON inv_cst_id = cst_id";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: join() - with bind
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectJoinWithBind(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - join() - with bind');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->join(
                $select::JOIN_LEFT,
                'co_customers',
                'inv_cst_id = cst_id AND cst_status_flag = ',
                1
            )
            ->appendJoin(' AND cst_name LIKE ', '%john%')
        ;

        $expected = "SELECT * FROM co_invoices "
            . "LEFT JOIN co_customers ON inv_cst_id = cst_id "
            . "AND cst_status_flag = :__1__ AND cst_name LIKE :__2__";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);

        $expected = [
            '__1__' => [1, PDO::PARAM_INT],
            '__2__' => ['%john%', PDO::PARAM_STR],
        ];
        $actual   = $select->getBindValues();
        $I->assertEquals($expected, $actual);
    }
}
