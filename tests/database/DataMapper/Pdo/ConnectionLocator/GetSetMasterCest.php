<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DataMapper\Pdo\ConnectionLocator;

use DatabaseTester;
use Phalcon\DataMapper\Pdo\ConnectionLocator;
use function spl_object_hash;

class GetSetMasterCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\ConnectionLocator ::
     * getMaster()/setMaster()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionLocatorGetSetMaster(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\ConnectionLocator - getMaster()/setMaster()');

        $connection1 = $I->getDataMapperConnection();
        $connection2 = $I->getDataMapperConnection();
        $locator     = new ConnectionLocator($connection1);

        $actual = $locator->getMaster();
        $I->assertEquals(spl_object_hash($connection1), spl_object_hash($actual));

        $locator->setMaster($connection2);
        $actual = $locator->getMaster();
        $I->assertEquals(spl_object_hash($connection2), spl_object_hash($actual));
    }
}
