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
use PDO;
use Phalcon\DM\Pdo\Connection;

class GetAvailableDriversCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Connection :: getAvailableDrivers()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionGetAvailableDrivers(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - getAvailableDrivers()');

        /** @var Connection $connection */
        $connection = $I->getDMConnection();

        $expected = PDO::getAvailableDrivers();
        $actual   = $connection::getAvailableDrivers();

        $I->assertEquals($expected, $actual);
    }
}
