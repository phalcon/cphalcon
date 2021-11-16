<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\DataMapper\Pdo\Connection;

use DatabaseTester;
use PDO;
use Phalcon\DataMapper\Pdo\Connection;

class DebugInfoCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection :: __debugInfo()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionDebugInfo(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - __debugInfo()');

        /** @var Connection $connection */
        $connection = $I->getDataMapperConnection();

        $expected = [
            'arguments' => [
                $I->getDatabaseDsn(),
                '****',
                '****',
                [
                    PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
                ],
                [],
            ],
        ];
        $I->assertEquals($expected, $connection->__debugInfo());
    }
}
