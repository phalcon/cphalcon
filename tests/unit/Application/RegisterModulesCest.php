<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Application;

use UnitTester;

class RegisterModulesCest
{
    /**
     * Tests Phalcon\Application :: registerModules()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function applicationRegisterModules(UnitTester $I)
    {
        $I->wantToTest("Application - registerModules()");
        $I->skipTest("Need implementation");
    }
}
