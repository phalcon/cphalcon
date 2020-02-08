<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DataMapper\Pdo\Connection\Decorated;

use DatabaseTester;
use PDO;
use Phalcon\DataMapper\Pdo\Connection\Decorated;
use Phalcon\DataMapper\Pdo\Exception\CannotDisconnect;

class DisconnectCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection\Decorated :: disconnect()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionDecoratedDisconnect(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection\Decorated - disconnect()');

        $I->expectThrowable(
            new CannotDisconnect(
                "Cannot disconnect a Decorated connection instance"
            ),
            function () use ($I) {
                $connection = new PDO(
                    $I->getDatabaseDsn(),
                    $I->getDatabaseUsername(),
                    $I->getDatabasePassword()
                );

                $decorated = new Decorated($connection);
                $decorated->disconnect();
            }
        );
    }
}
