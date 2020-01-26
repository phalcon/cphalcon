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

use function spl_object_hash;

class GetSetMasterCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\ConnectionLocator ::
     * getMaster()/setMaster()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionLocatorGetSetMaster(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\ConnectionLocator - getMaster()/setMaster()');

        $connection1 = $I->getConnection();
        $connection2 = $I->getConnection();
        $locator     = new ConnectionLocator($connection1);

        $actual = $locator->getMaster();
        $I->assertEquals(spl_object_hash($connection1), spl_object_hash($actual));

        $locator->setMaster($connection2);
        $actual = $locator->getMaster();
        $I->assertEquals(spl_object_hash($connection2), spl_object_hash($actual));
    }
}
