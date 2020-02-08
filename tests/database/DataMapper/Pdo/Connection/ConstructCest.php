<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DataMapper\Pdo\Connection;

use DatabaseTester;
use InvalidArgumentException;
use Phalcon\DataMapper\Pdo\Connection;

class ConstructCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection :: __construct()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionConstruct(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - __construct()');

        /** @var Connection $connection */
        $connection = $I->getDataMapperConnection();

        $I->assertInstanceOf(Connection::class, $connection);
    }

    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection :: __construct() - exception
     *
     * @since  2020-01-20
     */
    public function dMPdoConnectionConstructException(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - __construct() - exception');

        $I->expectThrowable(
            new InvalidArgumentException(
                "Driver not supported [random]"
            ),
            function () {
                (new Connection('random:some data'));
            }
        );
    }
}
