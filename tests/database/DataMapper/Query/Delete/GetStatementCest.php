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

namespace Phalcon\Test\Database\DataMapper\Query\Delete;

use DatabaseTester;
use Phalcon\DataMapper\Query\QueryFactory;

class GetStatementCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Delete :: getStatement()
     *
     * @since  2020-01-20
     */
    public function dMQueryDeleteGetStatement(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Delete - getStatement()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $delete     = $factory->newDelete($connection);

        $delete
            ->from('co_invoices')
            ->where('inv_total > :total')
            ->where('inv_cst_id = :cstId')
            ->orWhere('inv_status_flag = :flag')
            ->returning('inv_total', 'inv_cst_id', 'inv_status_flag')
            ->bindValues(
                [
                    'total' => 100,
                    'cstId' => 4,
                    'flag'  => 'active',
                ]
            )
        ;

        $expected = "DELETE FROM co_invoices "
            . "WHERE inv_total > :total "
            . "AND inv_cst_id = :cstId "
            . "OR inv_status_flag = :flag "
            . "RETURNING inv_total, inv_cst_id, inv_status_flag";
        $actual   = $delete->getStatement();
        $I->assertEquals($expected, $actual);
    }
}
