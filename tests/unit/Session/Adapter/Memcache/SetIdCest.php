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

class SetIdCest
{
    /**
     * Tests Phalcon\Session\Adapter\Memcache :: setId()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterMemcacheSetId(UnitTester $I)
    {
        $I->wantToTest("Session\Adapter\Memcache - setId()");
        $I->skipTest("Need implementation");
    }
}
