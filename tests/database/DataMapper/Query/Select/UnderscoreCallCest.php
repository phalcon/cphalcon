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

use BadMethodCallException;
use DatabaseTester;
use PDOStatement;
use Phalcon\DataMapper\Query\QueryFactory;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;

class UnderscoreCallCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: __call()
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectUnderscoreCall(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - __call()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);
        (new InvoicesMigration($connection));

        $select->from('co_invoices');
        $expected = [];
        $actual   = $select->fetchAll();
        $I->assertEquals($expected, $actual);
        $I->assertInstanceOf(PDOStatement::class, $select->perform());
    }

    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: __call() - exception
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectUnderscoreCallException(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - __call()');

        $I->expectThrowable(
            new BadMethodCallException(
                'Unknown method: [unknown]'
            ),
            function () use ($I) {
                $connection = $I->getDataMapperConnection();
                $factory    = new QueryFactory();
                $select     = $factory->newSelect($connection);

                $select->from('co_invoices');
                $select->unknown();
            }
        );
    }
}
