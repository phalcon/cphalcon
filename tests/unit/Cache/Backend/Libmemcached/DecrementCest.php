<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Backend\Libmemcached;

use Phalcon\Test\Fixtures\Traits\Cache\LibmemcachedTrait;
use UnitTester;

/**
 * Class DecrementCest
 */
class DecrementCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Backend\Libmemcached :: decrement()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendLibmemcachedDecrement(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Libmemcached - decrement()');

        $key   = 'decrement';
        $cache = $this->getDataCache();

        $I->dontSeeInLibmemcached($key);
        $I->haveInLibmemcached($key, 100);

        $I->assertEquals(99, $cache->decrement($key));
        $I->seeInLibmemcached($key, 99);

        $I->assertEquals(97, $cache->decrement($key, 2));
        $I->seeInLibmemcached($key, 97);

        $I->assertEquals(87, $cache->decrement($key, 10));
        $I->seeInLibmemcached($key, 87);
    }
}
