<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Cache;

use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache;
use Phalcon\Cache\Exception\InvalidArgumentException;
use Phalcon\Storage\SerializerFactory;
use function uniqid;
use UnitTester;

class SetMultipleCest
{
    /**
     * Tests Phalcon\Cache :: setMultiple()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-01
     */
    public function cacheCacheSetMultiple(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - setMultiple()');

        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $instance   = $factory->newInstance('apcu');

        $adapter = new Cache($instance);

        $key1 = uniqid();
        $key2 = uniqid();
        $adapter->setMultiple(
            [
                $key1 => 'test1',
                $key2 => 'test2',
            ]
        );

        $I->assertTrue(
            $adapter->has($key1)
        );

        $I->assertTrue(
            $adapter->has($key2)
        );

        $expected = [
            $key1     => 'test1',
            $key2     => 'test2',
            'unknown' => 'default-unknown',
        ];
        $actual   = $adapter->getMultiple([$key1, $key2, 'unknown'], 'default-unknown');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Cache :: setMultiple() - exception
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-01
     */
    public function cacheCacheSetMultipleException(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - setMultiple() - exception');

        $I->expectThrowable(
            new InvalidArgumentException('The key contains invalid characters'),
            function () {
                $serializer = new SerializerFactory();
                $factory    = new AdapterFactory($serializer);
                $instance   = $factory->newInstance('apcu');

                $adapter = new Cache($instance);

                $adapter->setMultiple(
                    [
                        'abc$^' => 'test1',
                        'abd$^' => 'test2',
                    ]
                );
            }
        );

        $I->expectThrowable(
            new InvalidArgumentException(
                'The keys need to be an array or instance of Traversable'
            ),
            function () {
                $serializer = new SerializerFactory();
                $factory    = new AdapterFactory($serializer);
                $instance   = $factory->newInstance('apcu');

                $adapter = new Cache($instance);

                $actual = $adapter->setMultiple(1234);
            }
        );
    }
}
