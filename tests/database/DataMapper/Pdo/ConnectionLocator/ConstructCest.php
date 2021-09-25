<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\DataMapper\Pdo\ConnectionLocator;

use DatabaseTester;
use Phalcon\DataMapper\Pdo\ConnectionLocator;
use Phalcon\DataMapper\Pdo\ConnectionLocatorInterface;

class ConstructCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\ConnectionLocator :: __construct()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionLocatorConstruct(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\ConnectionLocator - __construct()');

        $connection = $I->getDataMapperConnection();
        $locator    = new ConnectionLocator($connection);

        $I->assertInstanceOf(ConnectionLocatorInterface::class, $locator);
        $I->assertInstanceOf(ConnectionLocator::class, $locator);
    }
}
