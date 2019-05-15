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

namespace Phalcon\Test\Unit\Firewall\Adapter\Acl;

use Phalcon\Events\Manager;
use Phalcon\Firewall\Adapter\Acl;
use UnitTester;

class GetSetEventsManagerCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Acl :: getEventsManager()/setEventsManager()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-12
     */
    public function firewallAdapterAclGetSetEventsManager(UnitTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Acl - getEventsManager()/setEventsManager()');

        $firewall = new Acl('acl');
        $eventsManager = new Manager();

        $firewall->setEventsManager($eventsManager);

        $actual = $firewall->getEventsManager();
        $I->assertEquals($eventsManager, $actual);
    }
}
