<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Firewall\Adapter\Acl;

use IntegrationTester;

class SetRoleCacheCallbackCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Acl :: setRoleCacheCallback()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-12
     */
    public function firewallAdapterAclSetRoleCacheCallback(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Acl - setRoleCacheCallback()');

        $I->skipTest('Need implementation');
    }
}
