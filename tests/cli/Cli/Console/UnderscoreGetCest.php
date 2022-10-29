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

namespace Phalcon\Tests\Cli\Cli\Console;

use CliTester;
use Phalcon\Cli\Console as CliConsole;
use Phalcon\Cli\Dispatcher;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;

class UnderscoreGetCest
{
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

        $container = new DiFactoryDefault();
        $console   = new CliConsole($container);

        $class = Dispatcher::class;
        $actual = $console->dispatcher;
        $I->assertInstanceOf($class, $actual);

        $actual = $console->di;
        $I->assertSame($container, $actual);
    }
}
