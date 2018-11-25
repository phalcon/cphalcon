<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Backend\Redis;

use Phalcon\Cache\Backend\Redis;
use Phalcon\Cache\BackendInterface;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use UnitTester;

class IncrementCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Cache\Backend\Redis :: increment()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendRedisIncrement(UnitTester $I)
    {
        $I->wantToTest("Cache\Backend\Redis - increment()");
        $key   = '_PHCR' . 'decrement';
        $cache = new Redis(new Data(['lifetime' => 20]), $this->options);

        $I->dontSeeInRedis($key);
        $I->haveInRedis('string', $key, 1);

        $I->assertEquals(2, $cache->increment('increment'));
        $I->seeInRedis($key, 2);

        $I->assertEquals(4, $cache->increment('increment', 2));
        $I->seeInRedis($key, 4);

        $I->assertEquals(14, $cache->increment('increment', 10));
        $I->seeInRedis($key, 14);
    }
}
