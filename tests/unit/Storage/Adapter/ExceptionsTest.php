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

use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\Adapter\RedisCluster;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\Exception as StorageException;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as HelperException;
use Phalcon\Tests\AbstractUnitTestCase;

use function array_merge;
use function file_put_contents;
use function getOptionsRedis;
use function getOptionsRedisCluster;
use function is_dir;
use function mkdir;
use function outputDir;
use function sleep;
use function uniqid;

final class ExceptionsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageAdapterRedisGetSetFailedAuth(): void
    {
        $this->checkExtensionIsLoaded('redis');

        $this->expectException(StorageException::class);
        $this->expectExceptionMessage(
            'Failed to authenticate with the Redis server'
        );

        $serializer = new SerializerFactory();
        $adapter    = new Redis(
            $serializer,
            array_merge(
                getOptionsRedis(),
                [
                    'auth' => 'something',
                ]
            )
        );

        $adapter->get('test');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageAdapterRedisGetSetFailedSslLocalhost(): void
    {
        $this->checkExtensionIsLoaded('redis');

        $this->expectException(StorageException::class);
//        $this->expectExceptionMessage(
//            'Connection refused'
//        );

        $serializer      = new SerializerFactory();
        $options         = getOptionsRedis();
        $options['host'] = 'tls://127.0.0.1';
        $options['ssl']  = [
            'verify_peer_name' => '127.0.0.1',
            'verify_peer'      => false,
        ];

        $adapter = new Redis($serializer, $options);

        $adapter->get('test');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageAdapterRedisGetSetWrongIndex(): void
    {
        $this->checkExtensionIsLoaded('redis');

        $this->expectException(StorageException::class);
        $this->expectExceptionMessage('Redis server selected database failed');

        $serializer = new SerializerFactory();
        $adapter    = new Redis(
            $serializer,
            array_merge(
                getOptionsRedis(),
                [
                    'index' => 99,
                ]
            )
        );

        $adapter->get('test');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageAdapterStreamGetErrors(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
            ]
        );

        $target = outputDir() . 'ph-strm/te/st/-k/';
        if (true !== is_dir($target)) {
            mkdir($target, 0777, true);
        }

        // Unknown key
        $expected = 'test';
        $actual   = $adapter->get(uniqid(), 'test');
        $this->assertSame($expected, $actual);

        // Invalid stored object
        $actual = file_put_contents(
            $target . 'test-key',
            '{'
        );
        $this->assertNotFalse($actual);

        $expected = 'test';
        $actual   = $adapter->get('test-key', 'test');
        $this->assertSame($expected, $actual);

        // Expiry
        $data = 'Phalcon Framework';

        $actual = $adapter->set('test-key', $data, 1);
        $this->assertTrue($actual);

        sleep(2);

        $expected = 'test';
        $actual   = $adapter->get('test-key', 'test');
        $this->assertSame($expected, $actual);

        $this->safeDeleteFile($target . 'test-key');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-01
     */
    public function testStorageAdapterRedisClusterGetAdapterFailedConnection(): void
    {
        $this->checkExtensionIsLoaded('redis');

        $this->expectException(StorageException::class);
        $this->expectExceptionMessage(
            'Could not connect to the Redis Cluster server due to: '
        );

        $serializer = new SerializerFactory();
        $adapter    = new RedisCluster(
            $serializer,
            [
                'hosts' => ['127.0.0.1:19999'],
            ]
        );

        $adapter->get('test');
    }
}
