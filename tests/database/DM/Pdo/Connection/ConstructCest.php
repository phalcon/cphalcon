<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DM\Pdo\Connection;

use DatabaseTester;
use InvalidArgumentException;
use Phalcon\DM\Pdo\Connection;
use function var_dump;

class ConstructCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Connection :: __construct()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionConstruct(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - __construct()');

        /** @var Connection $connection */
        $connection = $I->getDMConnection();

        $all = $connection->fetchAll('show tables');

        var_dump($all);


        $I->assertInstanceOf(Connection::class, $connection);
    }

    /**
     * Database Tests Phalcon\DM\Pdo\Connection :: __construct() - exception
     *
     * @since  2020-01-20
     */
    public function dMPdoConnectionConstructException(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - __construct() - exception');

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
