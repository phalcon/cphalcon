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
use PDO;
use Phalcon\DM\Pdo\Connection;

class GetSetAttributeCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\Connection ::
     * getAttribute()/setAttribute()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionGetSetAttribute(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Connection - getAttribute()/setAttribute()');

        /** @var Connection $connection */
        $connection = $I->getConnection();

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
