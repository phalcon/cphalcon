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
use UnitTester;

use function getOptionsRedis;

class IncrementCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: increment()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function storageAdapterRedisIncrement(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - increment()');

        $I->skipTest('Check this');

        $serializer = new SerializerFactory();

        $adapter = new Redis(
            $serializer,
            getOptionsRedis()
        );

        $key = 'cache-data';

        $I->assertTrue(
            $adapter->set($key, 1)
        );


        $expected = 2;

        $I->assertEquals(
            $expected,
            $adapter->increment($key)
        );

        $I->assertEquals(
            $expected,
            $adapter->get($key)
        );


        $expected = 10;

        $I->assertEquals(
            $expected,
            $adapter->increment($key, 8)
        );

        $I->assertEquals(
            $expected,
            $adapter->get($key)
        );


        /**
         * unknown key
         */
        $key = 'unknown';

        $I->assertFalse(
            $adapter->increment($key)
        );
    }
}
