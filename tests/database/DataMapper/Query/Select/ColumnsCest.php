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

class ColumnsCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: columns()
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectColumns(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - columns()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $actual = $select->hasColumns();
        $I->assertFalse($actual);

        $select
            ->columns('inv_id', 'inv_cst_id', 'COUNT(inv_total)')
            ->from('co_invoices')
        ;

        $expected = "SELECT inv_id, inv_cst_id, COUNT(inv_total) "
            . "FROM co_invoices";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }
}
