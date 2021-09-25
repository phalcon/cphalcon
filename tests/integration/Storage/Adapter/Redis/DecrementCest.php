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

namespace Phalcon\Tests\Integration\Storage\Adapter\Redis;

use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\Fixtures\Traits\RedisTrait;
use IntegrationTester;

use function getOptionsRedis;
use function uniqid;

class DecrementCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: decrement()
     *
     * @throws Exception
     * @since  2019-03-31
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function storageAdapterRedisDecrement(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - decrement()');

        $serializer = new SerializerFactory();
        $adapter    = new Redis($serializer, getOptionsRedis());

        $key = uniqid('decrement-');

        /**
         * Key does not exist
         */
        $I->assertFalse($adapter->has($key));

        /**
         * Key does not exist. Increment it 10 times
         */
        $adapter->increment($key);
        $adapter->increment($key);
        $adapter->increment($key);
        $adapter->increment($key);
        $adapter->increment($key);
        $adapter->increment($key);
        $adapter->increment($key);
        $adapter->increment($key);
        $adapter->increment($key);
        $adapter->increment($key);

        /**
         * Get: new value in key - 10
         */
        $expected = 10;
        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);

        /**
         * A few decrements
         */
        $expected = 9;
        $actual   = $adapter->decrement($key);
        $I->assertEquals($expected, $actual);

        $expected = 8;
        $actual   = $adapter->decrement($key);
        $I->assertEquals($expected, $actual);

        $expected = 7;
        $actual   = $adapter->decrement($key);
        $I->assertEquals($expected, $actual);

        /**
         * Now increment by 10. We should get 24
         */
        $expected = 2;
        $actual   = $adapter->decrement($key, 5);
        $I->assertEquals($expected, $actual);

        /**
         * Get check
         */
        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);

        /**
         * Cleanup
         */
        $actual = $adapter->delete($key);
        $I->assertTrue($actual);
    }
}
