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

class GetIdCest
{
    /**
     * Tests Phalcon\Session\Adapter\Memcache :: getId()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterMemcacheGetId(UnitTester $I)
    {
        $I->wantToTest("Session\Adapter\Memcache - getId()");
        $I->skipTest("Need implementation");
    }
}
