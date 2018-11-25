<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Session\Adapter\Redis;

use UnitTester;

class GetNameCest
{
    /**
     * Tests Phalcon\Session\Adapter\Redis :: getName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterRedisGetName(UnitTester $I)
    {
        $I->wantToTest("Session\Adapter\Redis - getName()");
        $I->skipTest("Need implementation");
    }
}
