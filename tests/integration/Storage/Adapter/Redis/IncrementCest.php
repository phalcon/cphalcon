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

namespace Phalcon\Test\Integration\Storage\Adapter\Redis;

use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use IntegrationTester;

use function getOptionsRedis;
use function uniqid;

class IncrementCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: increment()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function storageAdapterRedisIncrement(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - increment()');

        $serializer = new SerializerFactory();
        $adapter    = new Redis($serializer, getOptionsRedis());

        $key = uniqid('increment-');

        /**
         * Key does not exist
         */
        $I->assertFalse($adapter->has($key));

        /**
         * Key does not exist, sets it to 0 and then increments it by 1
         */
        $expected = 1;
        $actual   = $adapter->increment($key);
        $I->assertEquals($expected, $actual);
        $I->assertTrue($adapter->has($key));

        /**
         * Get: new value in key - still 1
         */
        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);

        /**
         * A few increments
         */
        $expected = 2;
        $actual   = $adapter->increment($key);
        $I->assertEquals($expected, $actual);

        $expected = 3;
        $actual   = $adapter->increment($key);
        $I->assertEquals($expected, $actual);

        $expected = 4;
        $actual   = $adapter->increment($key);
        $I->assertEquals($expected, $actual);

        /**
         * Now increment by 10. We should get 24
         */
        $expected = 14;
        $actual   = $adapter->increment($key, 10);
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
