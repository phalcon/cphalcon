<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\DM\Pdo\Connection;

use IntegrationTester;
use Phalcon\DM\Pdo\Connection;

class ErrorInfoCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\Connection :: errorInfo()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionErrorInfo(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - errorInfo()');

        /** @var Connection $connection */
        $connection = $I->getConnection();

        $actual = $connection->errorInfo();
        $expect = ['', null, null];

        $I->assertEquals($expect, $actual);
    }
}
