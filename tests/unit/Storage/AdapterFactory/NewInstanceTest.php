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

namespace Phalcon\Tests\Unit\Storage\AdapterFactory;

use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\Adapter\RedisCluster;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\Adapter\Weak;
use Phalcon\Storage\AdapterFactory;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use PHPUnit\Framework\Attributes\DataProvider;

use function uniqid;

final class NewInstanceTest extends AbstractUnitTestCase
{
    public static function getExamples(): array
    {
        return [
            [
                'apcu',
                Apcu::class,
                [],
            ],
            [
                'libmemcached',
                Libmemcached::class,
                [
                    'client' => [],
                    'servers' => [
                        Talon::settings()->getServiceOptions('memcached')
                    ]
                ],
            ],
            [
                'memory',
                Memory::class,
                [],
            ],
            [
                'redis',
                Redis::class,
                Talon::settings()->getServiceOptions('redis'),
            ],
            [
                'rediscluster',
                RedisCluster::class,
                Talon::settings()->getServiceOptions('redisCluster'),
            ],
            [
                'stream',
                Stream::class,
                [
                    'storageDir' => Talon::settings()->outputPath() . '/',
                ],
            ],
            [
                'weak',
                Weak::class,
                [],
            ],
        ];
    }

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('getExamples')]
    public function testStorageAdapterFactoryNewInstance(
        string $name,
        string $class,
        array $options
    ): void {
        $serializer = new SerializerFactory();
        $adapter    = new AdapterFactory($serializer);

        $service = $adapter->newInstance($name, $options);

        $this->assertInstanceOf($class, $service);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageSerializerFactoryNewInstanceException(): void
    {
        $name = uniqid();
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Service ' . $name . ' is not registered'
        );

        $serializer = new SerializerFactory();
        $adapter    = new AdapterFactory($serializer);

        $service = $adapter->newInstance($name);
    }
}
