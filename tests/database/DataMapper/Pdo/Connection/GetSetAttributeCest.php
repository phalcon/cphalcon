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

class GetSetAttributeCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection ::
     * getAttribute()/setAttribute()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionGetSetAttribute(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - getAttribute()/setAttribute()');

        /** @var Connection $connection */
        $connection = $I->getDataMapperConnection();

        $I->assertEquals(
            PDO::ERRMODE_EXCEPTION,
            $connection->getAttribute(PDO::ATTR_ERRMODE)
        );

        $connection->setAttribute(
            PDO::ATTR_ERRMODE,
            PDO::ERRMODE_WARNING
        );

        $I->assertEquals(
            PDO::ERRMODE_WARNING,
            $connection->getAttribute(PDO::ATTR_ERRMODE)
        );
    }
}
