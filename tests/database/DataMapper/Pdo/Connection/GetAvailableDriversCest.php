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
use PDO;
use Phalcon\DataMapper\Pdo\Connection;

class GetAvailableDriversCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection :: getAvailableDrivers()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionGetAvailableDrivers(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - getAvailableDrivers()');

        /** @var Connection $connection */
        $connection = $I->getDataMapperConnection();

        $expected = PDO::getAvailableDrivers();
        $actual   = $connection::getAvailableDrivers();

        $I->assertEquals($expected, $actual);
    }
}
