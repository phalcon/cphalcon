<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Session\Adapter\Memcache;

use UnitTester;

class ReadCest
{
    /**
     * Tests Phalcon\Session\Adapter\Memcache :: read()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterMemcacheRead(UnitTester $I)
    {
        $I->wantToTest("Session\Adapter\Memcache - read()");
        $I->skipTest("Need implementation");
    }
}
