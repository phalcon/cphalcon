<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Backend\Libmemcached;

use UnitTester;

class ConnectCest
{
    /**
     * Tests Phalcon\Cache\Backend\Libmemcached :: _connect()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendLibmemcachedConnect(UnitTester $I)
    {
        $I->wantToTest("Cache\Backend\Libmemcached - _connect()");
        
        $cache = $this->getCache();
        $cache->_connect(); // Throws an exception if fails.
    }
}
