<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Request;

use UnitTester;

class IsValidHttpMethodCest
{
    /**
     * Tests Phalcon\Http\Request :: isValidHttpMethod()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpRequestIsValidHttpMethod(UnitTester $I)
    {
        $I->wantToTest("Http\Request - isValidHttpMethod()");
        $I->skipTest("Need implementation");
    }
}
