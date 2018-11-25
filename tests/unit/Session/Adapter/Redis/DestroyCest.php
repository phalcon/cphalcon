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

class DestroyCest
{
    /**
     * Tests Phalcon\Session\Adapter\Redis :: destroy()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterRedisDestroy(UnitTester $I)
    {
        $I->wantToTest("Session\Adapter\Redis - destroy()");
        $I->skipTest("Need implementation");
    }
}
