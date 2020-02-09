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

namespace Phalcon\Test\Database\DataMapper\Query\Update;

use DatabaseTester;
use PDO;
use Phalcon\DataMapper\Query\QueryFactory;

use function sprintf;
use function var_dump;

class GetStatementCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Update :: getStatement()
     *
     * @since  2020-01-20
     */
    public function dMQueryUpdateGetStatement(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Update - getStatement()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $update     = $factory->newUpdate($connection);
        $quotes     = $connection->getQuoteNames();

        $update
            ->from('co_invoices')
            ->columns(['inv_id', 'inv_cst_id', 'inv_total' => 'total'])
            ->set('inv_status_flag', null)
            ->set('inv_created_date', 'NOW()')
            ->where('inv_total > :totalMax')
            ->where('inv_cst_id = :cstId')
            ->orWhere('inv_status_flag = :flag')
            ->bindValues(
                [
                    'totalMax' => 100,
                    'cstId'    => 4,
                    'flag'     => 'active',
                ]
            )
        ;

        $expected = sprintf(
            "UPDATE co_invoices "
            . "SET "
            . '%1$sinv_id%2$s = :inv_id, '
            . '%1$sinv_cst_id%2$s = :inv_cst_id, '
            . '%1$sinv_total%2$s = :inv_total, '
            . '%1$sinv_status_flag%2$s = NULL, '
            . '%1$sinv_created_date%2$s = NOW() '
            . "WHERE inv_total > :totalMax "
            . "AND inv_cst_id = :cstId "
            . "OR inv_status_flag = :flag",
            $quotes["prefix"],
            $quotes["suffix"]
        );

        $actual   = $update->getStatement();
        $I->assertEquals($expected, $actual);

        $expected = [
            'inv_total' => ['total', PDO::PARAM_STR],
            'cstId'     => [4, PDO::PARAM_INT],
            'flag'      => ['active', PDO::PARAM_STR],
            'totalMax'  => [100, PDO::PARAM_INT],
        ];
        $actual   = $update->getBindValues();
        $I->assertEquals($expected, $actual);

        $update
            ->returning('inv_id', 'inv_cst_id')
            ->returning('inv_total')
        ;

        $expected = sprintf(
            "UPDATE co_invoices "
            . "SET "
            . '%1$sinv_id%2$s = :inv_id, '
            . '%1$sinv_cst_id%2$s = :inv_cst_id, '
            . '%1$sinv_total%2$s = :inv_total, '
            . '%1$sinv_status_flag%2$s = NULL, '
            . '%1$sinv_created_date%2$s = NOW() '
            . "WHERE inv_total > :totalMax "
            . "AND inv_cst_id = :cstId "
            . "OR inv_status_flag = :flag "
            . "RETURNING inv_id, inv_cst_id, inv_total",
            $quotes["prefix"],
            $quotes["suffix"]
        );
        $actual   = $update->getStatement();
        $I->assertEquals($expected, $actual);
    }
}
