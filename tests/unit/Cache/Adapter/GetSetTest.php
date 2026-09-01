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

namespace Phalcon\Tests\Unit\Cache\Adapter;

use ArrayObject;
use DateInterval;
use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Cache\Adapter\Memory;
use Phalcon\Cache\Adapter\Redis;
use Phalcon\Cache\Adapter\RedisCluster;
use Phalcon\Cache\Adapter\Stream;
use Phalcon\Cache\Adapter\Weak;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use PHPUnit\Framework\Attributes\DataProvider;
use SplObjectStorage;
use SplQueue;
use stdClass;

use function array_merge;
use function file_get_contents;
use function sort;
use function uniqid;

final class GetSetTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getAdapters(): array
    {
        return [
            [
                Apcu::class,
                [],
                'apcu',
            ],
            [
                Libmemcached::class,
                [
                    'client' => [],
                    'servers' => [
                        Talon::settings()->getServiceOptions('memcached')
                    ]
                ],
                'memcached',
            ],
            [
                Memory::class,
                [],
                '',
            ],
            [
                Redis::class,
                Talon::settings()->getServiceOptions('redis'),
                'redis',
            ],
            [
                Stream::class,
                [
                    'storageDir' => Talon::settings()->outputPath() . '/',
                ],
                '',
            ],
        ];
    }
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                'apcu',
                Apcu::class,
                [],
                null,
            ],
            [
                'apcu',
                Apcu::class,
                [],
                true,
            ],
            [
                'apcu',
                Apcu::class,
                [],
                false,
            ],
            [
                'apcu',
                Apcu::class,
                [],
                123456,
            ],
            [
                'apcu',
                Apcu::class,
                [],
                123.456,
            ],
            [
                'apcu',
                Apcu::class,
                [],
                uniqid(),
            ],
            [
                'apcu',
                Apcu::class,
                [],
                new stdClass(),
            ],
            [
                'memcached',
                Libmemcached::class,
                [
                    'client' => [],
                    'servers' => [
                        Talon::settings()->getServiceOptions('memcached')
                    ]
                ],
                null,
            ],
            [
                'memcached',
                Libmemcached::class,
                [
                    'client' => [],
                    'servers' => [
                        Talon::settings()->getServiceOptions('memcached')
                    ]
                ],
                true,
            ],
            [
                'memcached',
                Libmemcached::class,
                [
                    'client' => [],
                    'servers' => [
                        Talon::settings()->getServiceOptions('memcached')
                    ]
                ],
                false,
            ],
            [
                'memcached',
                Libmemcached::class,
                [
                    'client' => [],
                    'servers' => [
                        Talon::settings()->getServiceOptions('memcached')
                    ]
                ],
                123456,
            ],
            [
                'memcached',
                Libmemcached::class,
                [
                    'client' => [],
                    'servers' => [
                        Talon::settings()->getServiceOptions('memcached')
                    ]
                ],
                123.456,
            ],
            [
                'memcached',
                Libmemcached::class,
                [
                    'client' => [],
                    'servers' => [
                        Talon::settings()->getServiceOptions('memcached')
                    ]
                ],
                uniqid(),
            ],
            [
                'memcached',
                Libmemcached::class,
                [
                    'client' => [],
                    'servers' => [
                        Talon::settings()->getServiceOptions('memcached')
                    ]
                ],
                new stdClass(),
            ],
            [
                'memcached',
                Libmemcached::class,
                array_merge(
                    [
                        'client' => [],
                        'servers' => [
                            Talon::settings()->getServiceOptions('memcached')
                        ]
                    ],
                    [
                        'defaultSerializer' => 'Base64',
                    ]
                ),
                uniqid(),
            ],
            [
                '',
                Memory::class,
                [],
                null,
            ],
            [
                '',
                Memory::class,
                [],
                true,
            ],
            [
                '',
                Memory::class,
                [],
                false,
            ],
            [
                '',
                Memory::class,
                [],
                123456,
            ],
            [
                '',
                Memory::class,
                [],
                123.456,
            ],
            [
                '',
                Memory::class,
                [],
                uniqid(),
            ],
            [
                '',
                Memory::class,
                [],
                new stdClass(),
            ],
            [
                'redis',
                Redis::class,
                Talon::settings()->getServiceOptions('redis'),
                null,
            ],
            [
                'redis',
                Redis::class,
                Talon::settings()->getServiceOptions('redis'),
                true,
            ],
            [
                'redis',
                Redis::class,
                Talon::settings()->getServiceOptions('redis'),
                false,
            ],
            [
                'redis',
                Redis::class,
                Talon::settings()->getServiceOptions('redis'),
                123456,
            ],
            [
                'redis',
                Redis::class,
                Talon::settings()->getServiceOptions('redis'),
                123.456,
            ],
            [
                'redis',
                Redis::class,
                Talon::settings()->getServiceOptions('redis'),
                uniqid(),
            ],
            [
                'redis',
                Redis::class,
                Talon::settings()->getServiceOptions('redis'),
                new stdClass(),
            ],
            [
                'redis',
                Redis::class,
                array_merge(
                    Talon::settings()->getServiceOptions('redis'),
                    [
                        'defaultSerializer' => 'Base64',
                    ]
                ),
                uniqid(),
            ],
            [
                'redis',
                Redis::class,
                array_merge(
                    Talon::settings()->getServiceOptions('redis'),
                    [
                        'persistent' => true,
                    ]
                ),
                uniqid(),
            ],
            [
                'redis',
                RedisCluster::class,
                Talon::settings()->getServiceOptions('redisCluster'),
                null,
            ],
            [
                'redis',
                RedisCluster::class,
                Talon::settings()->getServiceOptions('redisCluster'),
                true,
            ],
            [
                'redis',
                RedisCluster::class,
                Talon::settings()->getServiceOptions('redisCluster'),
                false,
            ],
            [
                'redis',
                RedisCluster::class,
                Talon::settings()->getServiceOptions('redisCluster'),
                123456,
            ],
            [
                'redis',
                RedisCluster::class,
                Talon::settings()->getServiceOptions('redisCluster'),
                123.456,
            ],
            [
                'redis',
                RedisCluster::class,
                Talon::settings()->getServiceOptions('redisCluster'),
                uniqid(),
            ],
            [
                'redis',
                RedisCluster::class,
                Talon::settings()->getServiceOptions('redisCluster'),
                new stdClass(),
            ],
            [
                '',
                Stream::class,
                [
                    'storageDir' => Talon::settings()->outputPath() . '/',
                ],
                null,
            ],
            [
                '',
                Stream::class,
                [
                    'storageDir' => Talon::settings()->outputPath() . '/',
                ],
                true,
            ],
            [
                '',
                Stream::class,
                [
                    'storageDir' => Talon::settings()->outputPath() . '/',
                ],
                false,
            ],
            [
                '',
                Stream::class,
                [
                    'storageDir' => Talon::settings()->outputPath() . '/',
                ],
                123456,
            ],
            [
                '',
                Stream::class,
                [
                    'storageDir' => Talon::settings()->outputPath() . '/',
                ],
                123.456,
            ],
            [
                '',
                Stream::class,
                [
                    'storageDir' => Talon::settings()->outputPath() . '/',
                ],
                uniqid(),
            ],
            [
                '',
                Stream::class,
                [
                    'storageDir' => Talon::settings()->outputPath() . '/',
                ],
                new stdClass(),
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-14
     */
    public function testCacheAdapterStreamGetSetWithDateInterval(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Stream(
            $serializer,
            ['storageDir' => Talon::settings()->outputPath() . '/']
        );

        $key = uniqid();
        $ttl = new DateInterval('PT2H');

        $result = $adapter->set($key, 'test-value', $ttl);
        $this->assertTrue($result);

        $expected = 'test-value';
        $actual   = $adapter->get($key);
        $this->assertSame($expected, $actual);

        $adapter->delete($key);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/16348
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-06-01
     */
    public function testCacheAdapterStreamGetWithPrefix(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Stream(
            $serializer,
            [
                'storageDir' => Talon::settings()->outputPath() . '/',
                'prefix'     => 'en',
            ]
        );

        $target = Talon::settings()->outputPath('en/');

        $actual = $adapter->set('men', 123);
        $this->assertTrue($actual);
        $this->assertEquals(123, $adapter->get('men'));

        $actual = $adapter->set('barmen', 'abc');
        $this->assertTrue($actual);
        $this->assertEquals('abc', $adapter->get('barmen'));

        $actual = $adapter->set('bar', 'xyz');
        $this->assertTrue($actual);
        $this->assertEquals('xyz', $adapter->get('bar'));

        $expected = ['enbar', 'enbarmen', 'enmen'];
        $actual   = $adapter->getKeys();
        sort($actual);
        $this->assertEquals($expected, $actual);

        $this->safeDeleteDirectory($target);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testCacheAdapterStreamSet(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Stream(
            $serializer,
            [
                'storageDir' => Talon::settings()->outputPath() . '/',
            ]
        );

        $data   = 'Phalcon Framework';
        $actual = $adapter->set('test-key', $data);
        $this->assertTrue($actual);

        $target   = Talon::settings()->outputPath('ph-strm/te/st/-k/');
        $expected = 's:3:"ttl";i:3600;s:7:"content";s:25:"s:17:"Phalcon Framework";";}';
        $actual   = file_get_contents($target . 'test-key');
        $this->assertStringContainsString($expected, $actual);

        $this->safeDeleteFile($target . 'test-key');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testCacheAdapterWeakGetSet(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Weak($serializer);

        $objects = [
            new stdClass(),
            new ArrayObject(),
            new SplObjectStorage(),
            new SplQueue(),
        ];

        foreach ($objects as $object) {
            $key    = uniqid();
            $result = $adapter->set($key, $object);
            $this->assertTrue($result);

            $expected = $object;
            $actual   = $adapter->get($key);
            $this->assertEquals($expected, $actual);
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-14
     */
    public function testCacheAdapterWeakGetSetGcObject(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Weak($serializer);

        $key = uniqid();
        $obj = new stdClass();

        $adapter->set($key, $obj);
        $this->assertTrue($adapter->has($key));

        // Release the only strong reference so the GC can collect the object
        unset($obj);
        gc_collect_cycles();

        // get() finds a dead WeakRef, deletes the key, and returns null
        $actual = $adapter->get($key);
        $this->assertNull($actual);

        // Key must have been cleaned up during the get() call
        $this->assertFalse($adapter->has($key));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-14
     */
    public function testCacheAdapterWeakSetDuplicateKey(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Weak($serializer);

        $key  = uniqid();
        $obj1 = new stdClass();
        $obj2 = new stdClass();

        $result = $adapter->set($key, $obj1);
        $this->assertTrue($result);

        // Second set on existing key returns true but keeps the first reference
        $result = $adapter->set($key, $obj2);
        $this->assertTrue($result);

        // Original object is still returned
        $actual = $adapter->get($key);
        $this->assertSame($obj1, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    #[DataProvider('getExamples')]
    public function testStorageAdapterGetSet(
        string $extension,
        string $class,
        array $options,
        mixed $value
    ): void {
        if (!empty($extension)) {
            $this->checkExtensionIsLoaded($extension);
        }

        $serializer = new SerializerFactory();
        $adapter    = new $class($serializer, $options);

        $key = uniqid('k-');

        $result = $adapter->set($key, $value);
        $this->assertTrue($result);

        $result = $adapter->has($key);
        $this->assertTrue($result);

        /**
         * This will issue delete
         */
        $result = $adapter->set($key, $value, 0);
        $this->assertTrue($result);

        $result = $adapter->has($key);
        $this->assertFalse($result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    #[DataProvider('getAdapters')]
    public function testStorageAdapterGetSetWithZeroTtl(
        string $class,
        array $options,
        string $extension
    ): void {
        if (!empty($extension)) {
            $this->checkExtensionIsLoaded($extension);
        }

        $serializer = new SerializerFactory();
        $adapter    = new $class($serializer, $options);

        $key = uniqid();

        $result = $adapter->set($key, "test");
        $this->assertTrue($result);

        $result = $adapter->has($key);
        $this->assertTrue($result);

        /**
         * This will issue delete
         */
        $result = $adapter->set($key, "test", 0);
        $this->assertTrue($result);

        $result = $adapter->has($key);
        $this->assertFalse($result);
    }
}
