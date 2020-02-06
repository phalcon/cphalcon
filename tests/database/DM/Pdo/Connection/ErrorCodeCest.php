<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DM\Pdo\Connection;

use DatabaseTester;
use Phalcon\DM\Pdo\Connection;

class ErrorCodeCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Connection :: errorCode()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionErrorCode(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - errorCode()');

        /** @var Connection $connection */
        $connection = $I->getDMConnection();

        $actual = $connection->errorCode();
        $I->assertEquals('', $actual);
    }
}
