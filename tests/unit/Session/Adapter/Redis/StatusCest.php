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

class StatusCest
{
    /**
     * Tests Phalcon\Session\Adapter\Redis :: status()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterRedisStatus(UnitTester $I)
    {
        $I->wantToTest("Session\Adapter\Redis - status()");
        $I->skipTest("Need implementation");
    }
}
