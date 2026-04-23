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

use Memcached as NativeMemcached;
use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\Adapter\RedisCluster;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\Adapter\Weak;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use Redis as NativeRedis;
use RedisCluster as NativeRedisCluster;

use function getOptionsLibmemcached;
use function getOptionsRedis;
use function getOptionsRedisCluster;
use function outputDir;

final class GetAdapterTest extends AbstractUnitTestCase
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
                null,
                'apcu',
            ],
            [
                Libmemcached::class,
                getOptionsLibmemcached(),
                NativeMemcached::class,
                'memcached',
            ],
            [
                Memory::class,
                [],
                null,
                '',
            ],
            [
                Redis::class,
                getOptionsRedis(),
                NativeRedis::class,
                'redis',
            ],
            [
                RedisCluster::class,
                getOptionsRedisCluster(),
                NativeRedisCluster::class,
                'redis',
            ],
            [
                Stream::class,
                [
                    'storageDir' => outputDir(),
                ],
                null,
                '',
            ],
            [
                Weak::class,
                [],
                null,
                '',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testStorageAdapterGetAdapter(
        string $class,
        array $options,
        ?string $expected,
        string $extension,
    ): void {
        if (!empty($extension)) {
            $this->checkExtensionIsLoaded($extension);
        }

        $serializer = new SerializerFactory();
        $adapter    = new $class($serializer, $options);

        $actual = $adapter->getAdapter();

        if (null === $expected) {
            $this->assertNull($actual);
        } else {
            $this->assertInstanceOf($expected, $actual);
        }
    }
}
