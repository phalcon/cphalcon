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

use DatabaseTester;
use PDO;
use Phalcon\DataMapper\Query\QueryFactory;

use function sprintf;

class GetStatementCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Insert :: getStatement()
     *
     * @since  2020-01-20
     */
    public function dMQueryInsertGetStatement(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Insert - getStatement()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $insert     = $factory->newInsert($connection);
        $quotes     = $connection->getQuoteNames();

        $insert
            ->into('co_invoices')
            ->columns(['inv_cst_id', 'inv_total' => 'total'])
            ->set('inv_id', null)
            ->set('inv_status_flag', 1)
            ->set('inv_created_date', 'NOW()')
            ->columns(['inv_cst_id' => 1])
            ->returning(['inv_id', 'inv_cst_id'])
            ->returning(['inv_total'])
        ;

        $expected = sprintf(
            "INSERT INTO co_invoices ("
            . '%1$sinv_cst_id%2$s, '
            . '%1$sinv_total%2$s, '
            . '%1$sinv_id%2$s, '
            . '%1$sinv_status_flag%2$s, '
            . '%1$sinv_created_date%2$s'
            . ') VALUES ('
            . ':inv_cst_id, '
            . ':inv_total, '
            . 'NULL, '
            . '1, '
            . 'NOW()) '
            . "RETURNING inv_id, inv_cst_id, inv_total",
            $quotes["prefix"],
            $quotes["suffix"]
        );
        $actual   = $insert->getStatement();
        $I->assertEquals($expected, $actual);

        $expected = [
            'inv_total'  => ['total', PDO::PARAM_STR],
            'inv_cst_id' => [1, PDO::PARAM_INT],
        ];
        $actual   = $insert->getBindValues();
        $I->assertEquals($expected, $actual);
    }
}
