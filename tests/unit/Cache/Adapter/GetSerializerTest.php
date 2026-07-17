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

use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Cache\Adapter\Memory;
use Phalcon\Cache\Adapter\Redis;
use Phalcon\Cache\Adapter\RedisCluster;
use Phalcon\Cache\Adapter\Stream;
use Phalcon\Cache\Adapter\Weak;
use Phalcon\Storage\Serializer\SerializerInterface;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use PHPUnit\Framework\Attributes\DataProvider;

final class GetSerializerTest extends AbstractUnitTestCase
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
                RedisCluster::class,
                Talon::settings()->getServiceOptions('redisCluster'),
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-14
     */
    #[DataProvider('getExamples')]
    public function testCacheAdapterGetSerializer(
        string $class,
        array $options,
        string $extension
    ): void {
        if (!empty($extension)) {
            $this->checkExtensionIsLoaded($extension);
        }

        $serializer = new SerializerFactory();
        $adapter    = new $class($serializer, $options);

        $this->assertInstanceOf(SerializerInterface::class, $adapter->getSerializer());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-14
     */
    public function testCacheAdapterWeakGetSerializerReturnsNull(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Weak($serializer);

        $this->assertNull($adapter->getSerializer());
    }
}
