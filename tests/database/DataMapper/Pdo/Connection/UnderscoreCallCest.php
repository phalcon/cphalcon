<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\DataMapper\Pdo\Connection;

use BadMethodCallException;
use DatabaseTester;
use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Tests\Fixtures\DataMapper\Pdo\ConnectionFixture;

class UnderscoreCallCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection :: __call()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionUnderscoreCall(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - __call()');

        /** @var Connection $connection */
        $connection = new ConnectionFixture(
            $I->getDatabaseDsn(),
            $I->getDatabaseUsername(),
            $I->getDatabasePassword()
        );

        $actual = $connection->callMe('blondie');
        $I->assertEquals('blondie', $actual);
    }

    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection :: __call() - exception
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionUnderscoreCallException(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - __call() - exception');

        $I->expectThrowable(
            new BadMethodCallException(
                "Class 'Phalcon\DataMapper\Pdo\Connection' does not have a method 'unknown'"
            ),
            function () use ($I) {
                /** @var Connection $connection */
                $connection = $I->getDataMapperConnection();

                $connection->unknown();
            }
        );
    }
}
