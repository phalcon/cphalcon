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

class RemoveCest
{
    /**
     * Tests Phalcon\Session\Adapter\Redis :: remove()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterRedisRemove(UnitTester $I)
    {
        $I->wantToTest("Session\Adapter\Redis - remove()");
        $I->skipTest("Need implementation");
    }
}
