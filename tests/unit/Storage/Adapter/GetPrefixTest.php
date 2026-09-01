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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use PHPUnit\Framework\Attributes\DataProvider;

use function array_merge;

final class GetPrefixTest extends AbstractUnitTestCase
{
    public static function getExamples(): array
    {
        return [
            [
                Apcu::class,
                [
                ],
                'ph-apcu-',
                'apcu',
            ],
            [
                Apcu::class,
                [
                    'prefix' => '',
                ],
                '',
                'apcu',
            ],
            [
                Apcu::class,
                [
                    'prefix' => 'my-prefix',
                ],
                'my-prefix',
                'apcu',
            ],
            [
                Libmemcached::class,
                array_merge(
                    [
                        'client' => [],
                        'servers' => [
                            Talon::settings()->getServiceOptions('memcached')
                        ]
                    ],
                    [
                    ]
                ),
                'ph-memc-',
                'memcached',
            ],
            [
                Libmemcached::class,
                array_merge(
                    [
                        'client' => [],
                        'servers' => [
                            Talon::settings()->getServiceOptions('memcached')
                        ]
                    ],
                    [
                        'prefix' => '',
                    ]
                ),
                '',
                'memcached',
            ],
            [
                Libmemcached::class,
                array_merge(
                    [
                        'client' => [],
                        'servers' => [
                            Talon::settings()->getServiceOptions('memcached')
                        ]
                    ],
                    [
                        'prefix' => 'my-prefix',
                    ]
                ),
                'my-prefix',
                'memcached',
            ],
            [
                Memory::class,
                [
                ],
                'ph-memo-',
                '',
            ],
            [
                Memory::class,
                [
                    'prefix' => '',
                ],
                '',
                '',
            ],
            [
                Memory::class,
                [
                    'prefix' => 'my-prefix',
                ],
                'my-prefix',
                '',
            ],
            [
                Redis::class,
                array_merge(
                    Talon::settings()->getServiceOptions('redis'),
                    [
                    ]
                ),
                'ph-reds-',
                'redis',
            ],
            [
                Redis::class,
                array_merge(
                    Talon::settings()->getServiceOptions('redis'),
                    [
                        'prefix' => '',
                    ]
                ),
                '',
                'redis',
            ],
            [
                Redis::class,
                array_merge(
                    Talon::settings()->getServiceOptions('redis'),
                    [
                        'prefix' => 'my-prefix',
                    ]
                ),
                'my-prefix',
                'redis',
            ],
            [
                RedisCluster::class,
                array_merge(
                    Talon::settings()->getServiceOptions('redisCluster'),
                    [
                    ]
                ),
                'ph-redc-',
                'redis',
            ],
            [
                RedisCluster::class,
                array_merge(
                    Talon::settings()->getServiceOptions('redisCluster'),
                    [
                        'prefix' => '',
                    ]
                ),
                '',
                'redis',
            ],
            [
                RedisCluster::class,
                array_merge(
                    Talon::settings()->getServiceOptions('redisCluster'),
                    [
                        'prefix' => 'my-prefix',
                    ]
                ),
                'my-prefix',
                'redis',
            ],
            [
                Stream::class,
                [
                    'storageDir' => Talon::settings()->outputPath() . '/',
                ],
                'ph-strm',
                '',
            ],
            [
                Stream::class,
                [
                    'storageDir' => Talon::settings()->outputPath() . '/',
                    'prefix'     => '',
                ],
                '',
                '',
            ],
            [
                Stream::class,
                [
                    'storageDir' => Talon::settings()->outputPath() . '/',
                    'prefix'     => 'my-prefix',
                ],
                'my-prefix',
                '',
            ],
            [
                Weak::class,
                [
                ],
                '',
                '',
            ],
            [
                Weak::class,
                [
                    'prefix' => '',
                ],
                '',
                '',
            ],
            [
                Weak::class,
                [
                    'prefix' => 'my-prefix',
                ],
                '',
                '',
            ],
        ];
    }

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    #[DataProvider('getExamples')]
    public function testStorageAdapterGetSetPrefix(
        string $class,
        array $options,
        string $expected,
        string $extension
    ): void {
        if (!empty($extension)) {
            $this->checkExtensionIsLoaded($extension);
        }

        $serializer = new SerializerFactory();
        $adapter    = new $class($serializer, $options);

        $actual = $adapter->getPrefix();
        $this->assertSame($expected, $actual);
    }
}
