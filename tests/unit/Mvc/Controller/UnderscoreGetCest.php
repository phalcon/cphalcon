<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Controller;

use UnitTester;

class UnderscoreGetCest
{
    /**
     * Tests Phalcon\Mvc\Controller :: __get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcControllerUnderscoreGet(UnitTester $I)
    {
        $I->wantToTest("Mvc\Controller - __get()");
        $I->skipTest("Need implementation");
    }
}
