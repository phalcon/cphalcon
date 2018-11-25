<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Flash\Session;

use UnitTester;

class MessageCest
{
    /**
     * Tests Phalcon\Flash\Session :: message()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function flashSessionMessage(UnitTester $I)
    {
        $I->wantToTest("Flash\Session - message()");
        $I->skipTest("Need implementation");
    }
}
