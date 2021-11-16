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

class SubSelectCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: subSelect()
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectSubSelect(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - subSelect()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from(
                $select
                    ->subSelect()
                    ->columns("inv_id")
                    ->from('co_invoices')
                    ->asAlias('inv')
                    ->getStatement()
            );

        $expected = "SELECT * FROM (SELECT inv_id FROM co_invoices) AS inv";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }
}
