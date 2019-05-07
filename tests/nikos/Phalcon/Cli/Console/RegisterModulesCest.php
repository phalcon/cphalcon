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

namespace Phalcon\Test\Unit\Cli\Console;

use UnitTester;

class RegisterModulesCest
{
    /**
     * Tests Phalcon\Cli\Console :: registerModules()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function cliConsoleRegisterModules(UnitTester $I)
    {
        $I->wantToTest('Cli\Console - registerModules()');

        $I->skipTest('Need implementation');
    }
}
