<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DM\Pdo\ConnectionLocator;

use DatabaseTester;
use Phalcon\DM\Pdo\ConnectionLocator;
use Phalcon\DM\Pdo\ConnectionLocatorInterface;

class ConstructCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\ConnectionLocator :: __construct()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionLocatorConstruct(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\ConnectionLocator - __construct()');

        $connection1 = $I->getDMConnection();
        $locator     = new ConnectionLocator(
            function () use ($connection1) {
                return $connection1;
            }
        );
        $I->assertInstanceOf(ConnectionLocatorInterface::class, $locator);
        $I->assertInstanceOf(ConnectionLocator::class, $locator);
    }
}
