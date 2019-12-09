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

namespace Phalcon\Test\Unit\Cache\Cache;

use Phalcon\Cache;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Exception\InvalidArgumentException;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

use function uniqid;

class DeleteMultipleCest
{
    /**
     * Tests Phalcon\Cache :: deleteMultiple()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-01
     */
    public function cacheCacheDeleteMultiple(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - deleteMultiple()');

        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $instance   = $factory->newInstance('apcu');

        $adapter = new Cache($instance);

        $key1 = uniqid();
        $key2 = uniqid();
        $key3 = uniqid();

        $adapter->setMultiple(
            [
                $key1 => 'test1',
                $key2 => 'test2',
                $key3 => 'test3',
            ]
        );

        $I->assertTrue(
            $adapter->has($key1)
        );

        $I->assertTrue(
            $adapter->has($key2)
        );

        $I->assertTrue(
            $adapter->has($key3)
        );

        $I->assertTrue(
            $adapter->deleteMultiple(
                [
                    $key1,
                    $key2,
                ]
            )
        );

        $I->assertFalse(
            $adapter->has($key1)
        );

        $I->assertFalse(
            $adapter->has($key2)
        );

        $I->assertTrue(
            $adapter->has($key3)
        );
    }

    /**
     * Tests Phalcon\Cache :: deleteMultiple() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-01
     */
    public function cacheCacheDeleteMultipleException(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - deleteMultiple() - exception');

        $I->expectThrowable(
            new InvalidArgumentException('The keys need to be an array or instance of Traversable'),
            function () {
                $serializer = new SerializerFactory();
                $factory    = new AdapterFactory($serializer);
                $instance   = $factory->newInstance('apcu');

                $adapter = new Cache($instance);
                $actual  = $adapter->deleteMultiple(1234);
            }
        );
    }
}
