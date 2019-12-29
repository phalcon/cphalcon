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

class DeleteCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: delete()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function storageAdapterRedisDelete(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - delete()');

        $serializer = new SerializerFactory();
        $adapter    = new Redis($serializer, getOptionsRedis());

        $key = 'cache-data';
        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);

        $actual = $adapter->delete($key);
        $I->assertTrue($actual);

        $actual = $adapter->has($key);
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: delete() - twice
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function storageAdapterRedisDeleteTwice(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - delete() - twice');

        $serializer = new SerializerFactory();
        $adapter    = new Redis($serializer, getOptionsRedis());

        $key = 'cache-data';
        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);

        $actual = $adapter->delete($key);
        $I->assertTrue($actual);

        $actual = $adapter->delete($key);
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: delete() - unknown
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function storageAdapterRedisDeleteUnknown(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - delete() - unknown');

        $serializer = new SerializerFactory();
        $adapter    = new Redis($serializer, getOptionsRedis());

        $key    = 'cache-data';
        $actual = $adapter->delete($key);
        $I->assertFalse($actual);
    }
}
