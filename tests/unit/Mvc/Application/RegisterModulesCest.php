<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Application;

use UnitTester;

class RegisterModulesCest
{
    /**
     * Tests Phalcon\Mvc\Application :: registerModules()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcApplicationRegisterModules(UnitTester $I)
    {
        $I->wantToTest("Mvc\Application - registerModules()");
        $I->skipTest("Need implementation");
    }
}
