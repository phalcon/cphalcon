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
use Phalcon\Cache\Frontend\Data;
use Phalcon\Cache\BackendInterface;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use UnitTester;

class DecrementCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Cache\Backend\Redis :: decrement()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testDecrement(UnitTester $I)
    {
        $key    = '_PHCR' . 'decrement';
        $cache  = new Redis(new Data(['lifetime' => 20]), $this->options);

        $I->dontSeeInRedis($key);
        $I->haveInRedis('string', $key, 100);

        $I->assertEquals(99, $cache->decrement('decrement'));
        $I->seeInRedis($key, 99);

        $I->assertEquals(97, $cache->decrement('decrement', 2));
        $I->seeInRedis($key, 97);

        $I->assertEquals(87, $cache->decrement('decrement', 10));
        $I->seeInRedis($key, 87);
    }
}
