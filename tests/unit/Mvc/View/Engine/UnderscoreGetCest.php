<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\View\Engine;

use UnitTester;

class UnderscoreGetCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine :: __get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewEngineUnderscoreGet(UnitTester $I)
    {
        $I->wantToTest("Mvc\View\Engine - __get()");
        $I->skipTest("Need implementation");
    }
}
