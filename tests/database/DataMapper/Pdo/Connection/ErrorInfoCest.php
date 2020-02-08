<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DataMapper\Pdo\Connection;

use DatabaseTester;
use Phalcon\DataMapper\Pdo\Connection;

class ErrorInfoCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection :: errorInfo()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionErrorInfo(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - errorInfo()');

        /** @var Connection $connection */
        $connection = $I->getDataMapperConnection();

        $actual = $connection->errorInfo();
        $expect = ['', null, null];

        $I->assertEquals($expect, $actual);
    }
}
