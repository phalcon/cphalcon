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

class SendHeadersOnHandleRequestCest
{
    /**
     * Tests Phalcon\Mvc\Application :: sendHeadersOnHandleRequest()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcApplicationSendHeadersOnHandleRequest(UnitTester $I)
    {
        $I->wantToTest("Mvc\Application - sendHeadersOnHandleRequest()");
        $I->skipTest("Need implementation");
    }
}
