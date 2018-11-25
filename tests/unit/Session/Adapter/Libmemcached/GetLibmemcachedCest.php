<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Session\Adapter\Libmemcached;

use UnitTester;

class GetLibmemcachedCest
{
    /**
     * Tests Phalcon\Session\Adapter\Libmemcached :: getLibmemcached()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterLibmemcachedGetLibmemcached(UnitTester $I)
    {
        $I->wantToTest("Session\Adapter\Libmemcached - getLibmemcached()");
        $I->skipTest("Need implementation");
    }
}
