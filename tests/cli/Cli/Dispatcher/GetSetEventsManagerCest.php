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

namespace Phalcon\Test\Cli\Cli\Dispatcher;

use CliTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetSetEventsManagerCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Cli\Dispatcher :: getEventsManager()/setEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherGetSetEventsManager(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getEventsManager()/setEventsManager()');

        $console = $this->newService('console');
        $manager = $this->newService('eventsManager');

        $console->setEventsManager($manager);

        $actual = $console->getEventsManager();
        $I->assertEquals($manager, $actual);
    }
}
