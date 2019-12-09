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

class GetActiveRoleCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Acl :: getActiveRole()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-12
     */
    public function firewallAdapterAclGetActiveRole(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Acl - getActiveRole()');

        $I->skipTest('Need implementation');
    }
}
