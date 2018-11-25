<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Backend\Memcache;

use UnitTester;

class GetLifetimeCest
{
    /**
     * Tests Phalcon\Cache\Backend\Memcache :: getLifetime()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendMemcacheGetLifetime(UnitTester $I)
    {
        $I->wantToTest("Cache\Backend\Memcache - getLifetime()");
        $I->skipTest("Need implementation");
    }
}
