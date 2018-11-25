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

class GetModuleCest
{
    /**
     * Tests Phalcon\Cli\Console :: getModule()
     *
     * @param CliTester $I
     * 
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliConsoleGetModule(CliTester $I)
    {
        $I->wantToTest("Cli\Console - getModule()");
        $I->skipTest("Need implementation");
    }
}
