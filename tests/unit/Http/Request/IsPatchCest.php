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

class IsPatchCest
{
    /**
     * Tests Phalcon\Http\Request :: isPatch()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpRequestIsPatch(UnitTester $I)
    {
        $I->wantToTest("Http\Request - isPatch()");
        $I->skipTest("Need implementation");
    }
}
