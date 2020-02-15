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

namespace Phalcon\Test\Integration\Cache\Cache;

use Phalcon\Cache;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Exception\InvalidArgumentException;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

use function uniqid;

class GetSetCest
{
    /**
     * Tests Phalcon\Cache :: get()/set()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-01
     */
    public function cacheCacheSetGet(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - get()');

        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $instance   = $factory->newInstance('apcu');

        $adapter = new Cache($instance);

        $key1 = uniqid();
        $key2 = uniqid();
        $key3 = 'key.' . uniqid();


        $adapter->set($key1, 'test');

        $I->assertTrue(
            $adapter->has($key1)
        );


        $adapter->set($key2, 'test');

        $I->assertTrue(
            $adapter->has($key2)
        );

        $adapter->set($key3, 'test');

        $I->assertTrue(
            $adapter->has($key3)
        );

        $I->assertEquals(
            'test',
            $adapter->get($key1)
        );

        $I->assertEquals(
            'test',
            $adapter->get($key2)
        );

        $I->assertEquals(
            'test',
            $adapter->get($key3)
        );
    }

    /**
     * Tests Phalcon\Cache :: get() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-01
     */
    public function cacheCacheGetSetException(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - get() - exception');

        $I->expectThrowable(
            new InvalidArgumentException('The key contains invalid characters'),
            function () {
                $serializer = new SerializerFactory();
                $factory    = new AdapterFactory($serializer);
                $instance   = $factory->newInstance('apcu');

                $adapter = new Cache($instance);
                $value   = $adapter->get('abc$^');
            }
        );

        $I->expectThrowable(
            new InvalidArgumentException('The key contains invalid characters'),
            function () {
                $serializer = new SerializerFactory();
                $factory    = new AdapterFactory($serializer);
                $instance   = $factory->newInstance('apcu');

                $adapter = new Cache($instance);
                $value   = $adapter->set('abc$^', 'test');
            }
        );
    }
}
