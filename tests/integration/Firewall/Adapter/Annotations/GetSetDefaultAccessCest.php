<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Firewall\Adapter\Annotations;

use IntegrationTester;
use Phalcon\Acl\Enum;
use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Firewall\Adapter\Annotations;

class GetSetDefaultAccessCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Annotations ::
     * getDefaultAccess()/setDefaultAccess()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-12
     */
    public function firewallAdapterAnnotationsGetSetDefaultAccess(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Annotations - getDefaultAccess()/setDefaultAccess()');

        $firewall = new Annotations(new Memory());
        $firewall->setDefaultAccess(Enum::ALLOW);

        $actual = $firewall->getDefaultAccess();
        $I->assertEquals(Enum::ALLOW, $actual);
    }
}
