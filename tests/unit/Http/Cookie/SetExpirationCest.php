<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Cookie;

use UnitTester;

class SetExpirationCest
{
    /**
     * Tests Phalcon\Http\Cookie :: setExpiration()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpCookieSetExpiration(UnitTester $I)
    {
        $I->wantToTest("Http\Cookie - setExpiration()");
        $I->skipTest("Need implementation");
    }
}
