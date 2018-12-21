<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli\Console;

use CliTester;
use Phalcon\Cli\Dispatcher;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class SetDICest
{
    use DiTrait;

    /**
     * Tests Phalcon\Cli\Console :: setDI()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliConsoleSetDI(CliTester $I)
    {
        $I->wantToTest("Cli\Console - setDI()");
        $container = $this->newCliFactoryDefault();

        $console = $this->newCliConsole();
        $console->setDI($container);

        $expected = Dispatcher::class;
        $actual   = $console->getDI()->getShared('dispatcher');
        $I->assertInstanceOf($expected, $actual);
    }
}
