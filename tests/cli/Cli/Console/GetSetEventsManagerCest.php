<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli\Console;

use CliTester;
use Phalcon\Cli\Console as CliConsole;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Events\Manager as EventsManager;

class GetSetEventsManagerCest
{
    /**
     * Tests Phalcon\Cli\Console :: getEventsManager()
     * Tests Phalcon\Cli\Console :: setEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function cliConsoleGetSetEventsManager(CliTester $I)
    {
        $I->wantToTest("Cli\Console - getEventsManager() / setEventsManager()");

        $console = new CliConsole(new DiFactoryDefault());

        $eventsManager = new EventsManager();

        $console->setEventsManager($eventsManager);

        $I->assertEquals(
            $eventsManager,
            $console->getEventsManager()
        );
    }
}
