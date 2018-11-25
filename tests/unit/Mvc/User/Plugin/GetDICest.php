<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\User\Plugin;

use UnitTester;

class GetDICest
{
    /**
     * Tests Phalcon\Mvc\User\Plugin :: getDI()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcUserPluginGetDI(UnitTester $I)
    {
        $I->wantToTest("Mvc\User\Plugin - getDI()");
        $I->skipTest("Need implementation");
    }
}
