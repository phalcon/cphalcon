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

class UnderscoreSetCest
{
    /**
     * Tests Phalcon\Session\Adapter\Memcache :: __set()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterMemcacheUnderscoreSet(UnitTester $I)
    {
        $I->wantToTest("Session\Adapter\Memcache - __set()");
        $I->skipTest("Need implementation");
    }
}
