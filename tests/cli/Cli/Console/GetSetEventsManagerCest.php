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
use Phalcon\Events\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetSetEventsManagerCest
{
    use DiTrait;

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
        $I->wantToTest("Cli\Console - getEventsManager()");
        $I->wantToTest("Cli\Console - setEventsManager()");

        $console = $this->newCliConsole();

        $eventsManager = $this->newEventsManager();

        $console->setEventsManager($eventsManager);

        $I->assertInstanceOf(
            Manager::class,
            $console->getEventsManager()
        );
    }
}
