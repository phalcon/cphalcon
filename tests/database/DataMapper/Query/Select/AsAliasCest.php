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

class AsAliasCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: asAlias()
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectAsAlias(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - asAlias()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->asAlias('inv')
        ;

        $expected = "(SELECT * FROM co_invoices) AS inv";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }
}
