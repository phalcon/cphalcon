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
use Phalcon\Storage\Exception as StorageException;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception;
use Phalcon\Support\Exception as HelperException;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Storage\Fake\FakeApcuApcuDelete;
use Phalcon\Tests\Unit\Storage\Fake\FakeStreamUnlink;
use stdClass;

use function array_merge;
use function getOptionsLibmemcached;
use function getOptionsRedis;
use function getOptionsRedisCluster;
use function outputDir;
use function uniqid;

final class ClearTest extends AbstractUnitTestCase
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageAdapterApcuClearDeleteError(): void
    {
        $this->checkExtensionIsLoaded('apcu');

        $serializer = new SerializerFactory();
        $adapter    = new FakeApcuApcuDelete($serializer);

        $key1 = uniqid();
        $key2 = uniqid();
        $adapter->set($key1, 'test');
        $actual = $adapter->has($key1);
        $this->assertTrue($actual);

        $adapter->set($key2, 'test');
        $actual = $adapter->has($key2);
        $this->assertTrue($actual);

        $actual = $adapter->clear();
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageAdapterApcuClearIteratorError(): void
    {
        $this->checkExtensionIsLoaded('apcu');

        $serializer = new SerializerFactory();
        $adapter    = new FakeApcuApcuDelete($serializer);

        $key1 = uniqid();
        $key2 = uniqid();
        $adapter->set($key1, 'test');
        $actual = $adapter->has($key1);
        $this->assertTrue($actual);

        $adapter->set($key2, 'test');
        $actual = $adapter->has($key2);
        $this->assertTrue($actual);

        $actual = $adapter->clear();
        $this->assertFalse($actual);
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testStorageAdapterClear(
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
        $adapter->set($key1, 'test');
        $actual = $adapter->has($key1);
        $this->assertTrue($actual);

        $adapter->set($key2, 'test');
        $actual = $adapter->has($key2);
        $this->assertTrue($actual);

        $actual = $adapter->clear();
        $this->assertTrue($actual);

        $actual = $adapter->has($key1);
        $this->assertFalse($actual);

        $actual = $adapter->has($key2);
        $this->assertFalse($actual);

        /**
         * Call clear twice to ensure it returns true
         */
        $actual = $adapter->clear();
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageAdapterStreamClearCannotDeleteFile(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new FakeStreamUnlink(
            $serializer,
            [
                'storageDir' => outputDir(),
            ],
        );

        $key1 = uniqid();
        $key2 = uniqid();
        $adapter->set($key1, 'test');
        $actual = $adapter->has($key1);
        $this->assertTrue($actual);

        $adapter->set($key2, 'test');
        $actual = $adapter->has($key2);
        $this->assertTrue($actual);

        $actual = $adapter->clear();
        $this->assertFalse($actual);

        $this->safeDeleteDirectory(outputDir('ph-strm'));
    }

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2023-07-17
     */
    public function testStorageAdapterWealClear(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Weak($serializer);

        $obj1     = new stdClass();
        $obj1->id = 1;
        $obj2     = new stdClass();
        $obj2->id = 2;
        $key1     = uniqid();
        $key2     = uniqid();
        $adapter->set($key1, $obj1);
        $adapter->set($key2, $obj2);

        $temp = $adapter->get($key1);
        $this->assertEquals($temp, $adapter->get($key1));
        $this->assertEquals($temp, $obj1);

        $temp = $adapter->get($key2);
        $this->assertEquals($temp, $adapter->get($key2));
        $this->assertEquals($temp, $obj2);

        $actual = $adapter->clear();
        $this->assertTrue($actual);
        $actual = $adapter->has($key1);
        $this->assertFalse($actual);

        $actual = $adapter->has($key2);
        $this->assertFalse($actual);

        $actual = $adapter->clear();
        $this->assertTrue($actual);
    }

    /**
     * @return array[]
     */
    public static function getExamplesClearWithPrefix(): array
    {
        return [
            [
                Apcu::class,
                [],
                'apcu',
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
                Stream::class,
                [
                    'storageDir' => outputDir(),
                ],
                '',
            ],
        ];
    }

    /**
     * @dataProvider getExamplesClearWithPrefix
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2024-10-31
     */
    public function testStorageAdapterClearWithPrefix(
        string $class,
        array $options,
        string $extension
    ): void {
        if (!empty($extension)) {
            $this->checkExtensionIsLoaded($extension);
        }

        $serializer = new SerializerFactory();
        $adapter1   = new $class($serializer, array_merge($options, ['prefix' => 'test-one-']));
        $adapter2   = new $class($serializer, array_merge($options, ['prefix' => 'test-two-']));

        $key1 = uniqid();
        $key2 = uniqid();

        $adapter1->set($key1, 'test-one');
        $adapter2->set($key2, 'test-two');

        $this->assertTrue($adapter1->has($key1));
        $this->assertTrue($adapter2->has($key2));

        /**
         * Clearing adapter1 must not remove adapter2's key
         */
        $actual = $adapter1->clear();
        $this->assertTrue($actual);

        $this->assertFalse($adapter1->has($key1));
        $this->assertTrue($adapter2->has($key2));

        /**
         * Clean up adapter2
         */
        $adapter2->clear();

        if ($class === Stream::class) {
            $this->safeDeleteDirectory(outputDir('test-one-'));
            $this->safeDeleteDirectory(outputDir('test-two-'));
        }
    }
}
