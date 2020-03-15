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

namespace Phalcon\Test\Integration\Cache\Adapter\Libmemcached;

use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use IntegrationTester;

use function getOptionsLibmemcached;

class ClearCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Libmemcached :: clear()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterLibmemcachedClear(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Libmemcached - clear()');

        $serializer = new SerializerFactory();

        $adapter = new Libmemcached(
            $serializer,
            getOptionsLibmemcached()
        );

        $key1 = uniqid();
        $key2 = uniqid();
        $adapter->set($key1, 'test');

        $I->assertTrue(
            $adapter->has($key1)
        );

        $adapter->set($key1, 'test');

        $I->assertTrue(
            $adapter->has($key1)
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
     * Tests Phalcon\Cache\Adapter\Libmemcached :: clear() - twice
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterLibmemcachedClearTwice(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Libmemcached - clear() - twice');

        $serializer = new SerializerFactory();

        $adapter = new Libmemcached(
            $serializer,
            getOptionsLibmemcached()
        );

        $key = 'key-1';
        $adapter->set($key, 'test');

        $I->assertTrue(
            $adapter->has($key)
        );

        $key = 'key-2';
        $adapter->set($key, 'test');

        $I->assertTrue(
            $adapter->has($key)
        );

        $I->assertTrue(
            $adapter->clear()
        );

        $I->assertTrue(
            $adapter->clear()
        );
    }
}
