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
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class GetModulesCest
 */
class GetModulesCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Cli\Console :: getModules()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since 2018-12-26
     */
    public function cliConsoleGetModules(CliTester $I)
    {
        $I->wantToTest("Cli\Console - getModules()");
        $console = $this->newCliConsole();
        $expected = [];
        $actual = $console->getModules();
        $I->assertEquals($expected, $actual);
    }
}
