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

namespace Phalcon\Test\Unit\Storage\Adapter\Redis;

use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use UnitTester;

use function getOptionsRedis;

class ClearCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: clear()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function storageAdapterRedisClear(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - clear()');

        $serializer = new SerializerFactory();

        $adapter = new Redis(
            $serializer,
            getOptionsRedis()
        );

        $key1 = uniqid();
        $key2 = uniqid();

        $adapter->set($key1, 'test');

        $I->assertTrue(
            $adapter->has($key1)
        );

        $adapter->set($key2, 'test');

        $I->assertTrue(
            $adapter->has($key2)
        );

        $I->assertTrue(
            $adapter->clear()
        );

        $I->assertFalse(
            $adapter->has($key1)
        );

        $I->assertFalse(
            $adapter->has($key2)
        );
    }

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: clear() - twice
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function storageAdapterRedisClearTwice(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - clear() - twice');

        $serializer = new SerializerFactory();

        $adapter = new Redis(
            $serializer,
            getOptionsRedis()
        );

        $key1 = uniqid();
        $key2 = uniqid();

        $adapter->set($key1, 'test');

        $I->assertTrue(
            $adapter->has($key1)
        );

        $adapter->set($key2, 'test');

        $I->assertTrue(
            $adapter->has($key2)
        );

        $I->assertTrue(
            $adapter->clear()
        );

        $I->assertTrue(
            $adapter->clear()
        );
    }
}
