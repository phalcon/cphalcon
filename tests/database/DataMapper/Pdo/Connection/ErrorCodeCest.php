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
use Phalcon\DataMapper\Pdo\Connection;

class ErrorCodeCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection :: errorCode()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionErrorCode(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - errorCode()');

        /** @var Connection $connection */
        $connection = $I->getDataMapperConnection();

        $actual = $connection->errorCode();
        $I->assertEquals('', $actual);
    }
}
