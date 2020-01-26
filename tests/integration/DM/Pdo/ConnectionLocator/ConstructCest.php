<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\DM\Pdo\ConnectionLocator;

use IntegrationTester;
use Phalcon\DM\Pdo\ConnectionLocator;
use Phalcon\DM\Pdo\ConnectionLocatorInterface;

class ConstructCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\ConnectionLocator :: __construct()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionLocatorConstruct(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\ConnectionLocator - __construct()');

        $connection1 = $I->getConnection();
        $locator     = new ConnectionLocator(
            function () use ($connection1) {
                return $connection1;
            }
        );
        $I->assertInstanceOf(ConnectionLocatorInterface::class, $locator);
        $I->assertInstanceOf(ConnectionLocator::class, $locator);
    }
}
