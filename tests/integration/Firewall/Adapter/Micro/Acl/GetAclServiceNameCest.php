<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Firewall\Adapter\Micro\Acl;

use IntegrationTester;

class GetAclServiceNameCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Micro\Acl :: getAclServiceName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-12
     */
    public function firewallAdapterMicroAclGetAclServiceName(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Micro\Acl - getAclServiceName()');

        $I->skipTest('Need implementation');
    }
}
