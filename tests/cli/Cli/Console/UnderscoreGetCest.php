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

namespace Phalcon\Test\Cli\Cli\Console;

use CliTester;
use Phalcon\Cli\Dispatcher;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class UnderscoreGetCest
 */
class UnderscoreGetCest
{

    use DiTrait;

    /**
     * Tests Phalcon\Cli\Console :: __get()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since 2018-12-28
     */
    public function cliConsoleUnderscoreGet(CliTester $I)
    {
        $I->wantToTest("Cli\Console - __get()");
        $this->setNewCliFactoryDefault();
        $console = $this->newCliConsole();
        $console->setDI($this->container);

        $expected = Dispatcher::class;
        $actual = $console->dispatcher;
        $I->assertInstanceOf($expected, $actual);

        $expected = $this->container;
        $actual = $console->di;
        $I->assertSame($expected, $actual);
    }
}
