<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Cache\Adapter\Redis;

use Phalcon\Cache\Adapter\Redis;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use IntegrationTester;

use function getOptionsRedis;

class HasCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Redis :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterRedisGetSetHas(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Redis - has()');

        $serializer = new SerializerFactory();

        $adapter = new Redis(
            $serializer,
            getOptionsRedis()
        );

        $key = uniqid();

        $actual = $adapter->has($key);
        $I->assertFalse($actual);

        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);
    }
}
