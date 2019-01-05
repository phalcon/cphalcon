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
 * Class IncrementCest
 */
class IncrementCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Backend\Libmemcached :: increment()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendLibmemcachedIncrement(UnitTester $I)
    {
        $I->wantTo('Cache\Backend\Libmemcached - increment()');

        $key   = 'increment';
        $cache = $this->getDataCache();

        $I->dontSeeInLibmemcached($key);
        $I->haveInLibmemcached($key, 1);

        $I->assertEquals(2, $cache->increment($key));
        $I->seeInLibmemcached($key, 2);

        $I->assertEquals(4, $cache->increment($key, 2));
        $I->seeInLibmemcached($key, 4);

        $I->assertEquals(14, $cache->increment($key, 10));
        $I->seeInLibmemcached($key, 14);
    }
}
