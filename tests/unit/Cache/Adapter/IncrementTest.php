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
use Phalcon\Storage\SerializerFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use PHPUnit\Framework\Attributes\DataProvider;

use function uniqid;

final class IncrementTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                'Apcu',
                Apcu::class,
                [],
                'apcu',
                1,
            ],
            [
                'Libmemcached',
                Libmemcached::class,
                [
                    'client' => [],
                    'servers' => [
                        Talon::settings()->getServiceOptions('memcached')
                    ]
                ],
                'memcached',
                false,
            ],
            [
                'Memory',
                Memory::class,
                [],
                '',
                false,
            ],
            [
                'Redis',
                Redis::class,
                Talon::settings()->getServiceOptions('redis'),
                'redis',
                1
            ],
            [
                'RedisCluster',
                RedisCluster::class,
                Talon::settings()->getServiceOptions('redisCluster'),
                'redis',
                1
            ],
            [
                'Stream',
                Stream::class,
                [
                    'storageDir' => Talon::settings()->outputPath() . '/',
                ],
                '',
                false,
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    #[DataProvider('getExamples')]
    public function testCacheAdapterIncrement(
        string $className,
        string $class,
        array $options,
        string $extension,
        mixed $unknown
    ): void {
        if (!empty($extension)) {
            $this->checkExtensionIsLoaded($extension);
        }

        $serializer = new SerializerFactory();
        $adapter    = new $class($serializer, $options);

        $key    = uniqid();
        $result = $adapter->set($key, 10);
        $this->assertTrue($result);

        $expected = 11;
        $actual   = $adapter->increment($key);
        $this->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $this->assertEquals($expected, $actual);

        $expected = 20;
        $actual   = $adapter->increment($key, 9);
        $this->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $this->assertEquals($expected, $actual);

        /**
         * unknown key
         */
        $key      = uniqid();
        $expected = $unknown;
        $actual   = $adapter->increment($key);
        $this->assertEquals($expected, $actual);

        if ('Stream' === $className) {
            $this->safeDeleteDirectory(Talon::settings()->outputPath('ph-strm'));
        }
    }
}
