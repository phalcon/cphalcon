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

namespace Phalcon\Test\Integration\Firewall\Adapter\Acl;

use IntegrationTester;
use Phalcon\Events\Manager;
use Phalcon\Firewall\Adapter\Acl;

class GetSetEventsManagerCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Acl ::
     * getEventsManager()/setEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-12
     */
    public function firewallAdapterAclGetSetEventsManager(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Acl - getEventsManager()/setEventsManager()');

        $firewall      = new Acl('acl');
        $eventsManager = new Manager();

        $firewall->setEventsManager($eventsManager);

        $actual = $firewall->getEventsManager();
        $I->assertEquals($eventsManager, $actual);
    }
}
