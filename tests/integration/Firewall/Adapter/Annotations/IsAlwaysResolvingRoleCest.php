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

class IsAlwaysResolvingRoleCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Annotations :: isAlwaysResolvingRole()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-12
     */
    public function firewallAdapterAnnotationsIsAlwaysResolvingRole(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Annotations - isAlwaysResolvingRole()');

        $I->skipTest('Need implementation');
    }
}
