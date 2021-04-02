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

class ForUpdateCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: forUpdate()
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectForUpdate(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - forUpdate()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->forUpdate()
        ;

        $expected = "SELECT * FROM co_invoices FOR UPDATE";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: forUpdate() - unset
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectForUpdateUnset(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - forUpdate() - unset');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->forUpdate()
            ->forUpdate(false)
        ;

        $expected = "SELECT * FROM co_invoices";
        $actual   = $select->getStatement();
        $I->assertEquals($expected, $actual);
    }
}
