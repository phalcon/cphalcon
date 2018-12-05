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

class GetDICest
{
    use DiTrait;

    /**
     * Tests Phalcon\Cli\Console :: getDI()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliConsoleGetDI(CliTester $I)
    {
        $I->wantToTest("Cli\Console - getDI()");
        $I->wantToTest("Cli\Console - setDI()");
        $container = $this->newCliFactoryDefault();

        $console = $this->newCliConsole();
        $console->setDI($container);

        $expected = Dispatcher::class;
        $actual   = $console->getDI()->getShared('dispatcher');
        $I->assertInstanceOf($expected, $actual);
    }
}
