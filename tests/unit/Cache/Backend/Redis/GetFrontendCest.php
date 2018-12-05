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

class GetFrontendCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Cache\Backend\Redis :: getFrontend()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendRedisGetFrontend(UnitTester $I)
    {
        $I->wantToTest("Cache\Backend\Redis - getFrontend()");
        $cache = new Redis(new Data(['lifetime' => 20]), $this->options);

        $class  = Data::class;
        $actual = $cache->getFrontend();
        $I->assertInstanceOf($class, $actual);
    }
}
