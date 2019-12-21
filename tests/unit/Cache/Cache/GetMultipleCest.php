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

class GetMultipleCest
{
    /**
     * Tests Phalcon\Cache :: getMultiple()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-01
     */
    public function cacheCacheGetMultiple(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - getMultiple()');

        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $instance   = $factory->newInstance('apcu');

        $adapter = new Cache($instance);

        $key1 = uniqid();
        $key2 = uniqid();

        $adapter->set($key1, 'test1');

        $I->assertTrue(
            $adapter->has($key1)
        );

        $adapter->set($key2, 'test2');

        $I->assertTrue(
            $adapter->has($key2)
        );

        $expected = [
            $key1 => 'test1',
            $key2 => 'test2',
        ];
        $actual   = $adapter->getMultiple([$key1, $key2]);
        $I->assertEquals($expected, $actual);

        $expected = [
            $key1     => 'test1',
            $key2     => 'test2',
            'unknown' => 'default-unknown',
        ];
        $actual   = $adapter->getMultiple([$key1, $key2, 'unknown'], 'default-unknown');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Cache :: getMultiple() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-01
     */
    public function cacheCacheGetMultipleException(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - getMultiple() - exception');

        $I->expectThrowable(
            new InvalidArgumentException(
                'The keys need to be an array or instance of Traversable'
            ),
            function () {
                $serializer = new SerializerFactory();
                $factory    = new AdapterFactory($serializer);
                $instance   = $factory->newInstance('apcu');

                $adapter = new Cache($instance);
                $actual  = $adapter->getMultiple(1234);
            }
        );
    }
}
