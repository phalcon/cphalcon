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

namespace Phalcon\Test\Integration\Firewall\Adapter\Acl;

use IntegrationTester;
use Phalcon\Acl\Enum;
use Phalcon\Firewall\Adapter\Acl;

class GetSetDefaultAccessCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Acl :: getDefaultAccess()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-12
     */
    public function firewallAdapterAclGetDefaultAccess(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Acl - getDefaultAccess()');

        $firewall = new Acl('acl');
        $firewall->setDefaultAccess(Enum::ALLOW);

        $actual = $firewall->getDefaultAccess();
        $I->assertEquals(Enum::ALLOW, $actual);
    }
}
