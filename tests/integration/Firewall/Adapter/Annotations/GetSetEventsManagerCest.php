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
use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Events\Manager;
use Phalcon\Firewall\Adapter\Annotations;

class GetSetEventsManagerCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Annotations ::
     * getEventsManager()/setEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-12
     */
    public function firewallAdapterAnnotationsGetSetEventsManager(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Annotations - getEventsManager()/setEventsManager()');

        $firewall      = new Annotations(new Memory());
        $eventsManager = new Manager();

        $firewall->setEventsManager($eventsManager);

        $actual = $firewall->getEventsManager();
        $I->assertEquals($eventsManager, $actual);
    }
}
