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

namespace Phalcon\Tests\Unit\Storage\Adapter;

use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\Adapter\RedisCluster;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\Adapter\Weak;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

use function getOptionsLibmemcached;
use function getOptionsRedis;
use function getOptionsRedisCluster;
use function outputDir;
use function uniqid;

final class DeleteMultipleTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                Apcu::class,
                [],
                'apcu',
            ],
            [
                Libmemcached::class,
                getOptionsLibmemcached(),
                'memcached',
            ],
            [
                Memory::class,
                [],
                '',
            ],
            [
                Redis::class,
                getOptionsRedis(),
                'redis',
            ],
            [
                RedisCluster::class,
                getOptionsRedisCluster(),
                'redis',
            ],
            [
                Stream::class,
                [
                    'storageDir' => outputDir(),
                ],
                '',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2025-01-01
     */
    public function testStorageAdapterDeleteMultiple(
        string $class,
        array $options,
        string $extension
    ): void {
        if (!empty($extension)) {
            $this->checkExtensionIsLoaded($extension);
        }

        $serializer = new SerializerFactory();
        $adapter    = new $class($serializer, $options);

        $key1 = uniqid();
        $key2 = uniqid();
        $key3 = uniqid();

        $adapter->set($key1, 'value1');
        $adapter->set($key2, 'value2');
        $adapter->set($key3, 'value3');

        $this->assertTrue($adapter->has($key1));
        $this->assertTrue($adapter->has($key2));
        $this->assertTrue($adapter->has($key3));

        /**
         * Delete all three — all exist, must return true
         */
        $actual = $adapter->deleteMultiple([$key1, $key2, $key3]);
        $this->assertTrue($actual);

        $this->assertFalse($adapter->has($key1));
        $this->assertFalse($adapter->has($key2));
        $this->assertFalse($adapter->has($key3));

        /**
         * Delete again — keys no longer exist, must return false
         */
        $actual = $adapter->deleteMultiple([$key1, $key2, $key3]);
        $this->assertFalse($actual);

        /**
         * Mix of existing and non-existing keys — must return false
         */
        $key4 = uniqid();
        $key5 = uniqid();
        $adapter->set($key4, 'value4');

        $actual = $adapter->deleteMultiple([$key4, $key5]);
        $this->assertFalse($actual);

        /**
         * key4 was still deleted despite partial failure
         */
        $this->assertFalse($adapter->has($key4));

        /**
         * Delete unknown keys — must return false
         */
        $actual = $adapter->deleteMultiple([uniqid(), uniqid()]);
        $this->assertFalse($actual);
    }

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2025-01-01
     */
    public function testStorageAdapterWeakDeleteMultiple(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Weak($serializer);

        $obj1     = new stdClass();
        $obj1->id = 1;
        $obj2     = new stdClass();
        $obj2->id = 2;
        $obj3     = new stdClass();
        $obj3->id = 3;

        $key1 = uniqid();
        $key2 = uniqid();
        $key3 = uniqid();

        $adapter->set($key1, $obj1);
        $adapter->set($key2, $obj2);
        $adapter->set($key3, $obj3);

        $this->assertTrue($adapter->has($key1));
        $this->assertTrue($adapter->has($key2));
        $this->assertTrue($adapter->has($key3));

        /**
         * Delete all three — all exist, must return true
         */
        $actual = $adapter->deleteMultiple([$key1, $key2, $key3]);
        $this->assertTrue($actual);

        $this->assertFalse($adapter->has($key1));
        $this->assertFalse($adapter->has($key2));
        $this->assertFalse($adapter->has($key3));

        /**
         * Delete again — keys no longer exist, must return false
         */
        $actual = $adapter->deleteMultiple([$key1, $key2, $key3]);
        $this->assertFalse($actual);

        /**
         * Delete unknown keys — must return false
         */
        $actual = $adapter->deleteMultiple([uniqid(), uniqid()]);
        $this->assertFalse($actual);
    }
}
