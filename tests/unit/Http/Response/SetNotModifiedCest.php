<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Response;

use UnitTester;

class SetNotModifiedCest
{
    /**
     * Tests Phalcon\Http\Response :: setNotModified()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpResponseSetNotModified(UnitTester $I)
    {
        $I->wantToTest("Http\Response - setNotModified()");
        $I->skipTest("Need implementation");
    }
}
