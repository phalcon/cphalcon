<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\DM\Pdo\Connection;

use IntegrationTester;
use InvalidArgumentException;
use Phalcon\DM\Pdo\Connection;

class ConstructCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\Connection :: __construct()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionConstruct(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - __construct()');

        /** @var Connection $connection */
        $connection = $I->getConnection();

        $I->assertInstanceOf(Connection::class, $connection);
    }

    /**
     * Integration Tests Phalcon\DM\Pdo\Connection :: __construct() - exception
     *
     * @since  2020-01-20
     */
    public function dMPdoConnectionConstructException(IntegrationTester $I)
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
