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

class IsPostCest
{
    /**
     * Tests Phalcon\Http\Request :: isPost()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpRequestIsPost(UnitTester $I)
    {
        $I->wantToTest("Http\Request - isPost()");
        $I->skipTest("Need implementation");
    }
}
