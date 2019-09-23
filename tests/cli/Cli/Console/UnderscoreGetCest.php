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

namespace Phalcon\Test\Cli\Cli\Console;

use CliTester;
use Phalcon\Cli\Dispatcher;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class UnderscoreGetCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Cli\Console :: __get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-28
     */
    public function cliConsoleUnderscoreGet(CliTester $I)
    {
        $I->wantToTest("Cli\Console - __get()");

        $this->setNewCliFactoryDefault();

        $console = $this->newCliConsole();

        $console->setDI(
            $this->container
        );

        $I->assertInstanceOf(
            Dispatcher::class,
            $console->dispatcher
        );

        $I->assertSame(
            $this->container,
            $console->di
        );
    }
}
