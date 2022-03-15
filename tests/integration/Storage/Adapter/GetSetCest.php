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

namespace Phalcon\Tests\Integration\Storage\Adapter;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use stdClass;

use function array_merge;
use function getOptionsLibmemcached;
use function getOptionsRedis;
use function outputDir;
use function sprintf;
use function uniqid;

class GetSetCest
{
    /**
     * Tests Phalcon\Storage\Adapter\* :: get()/set()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function storageAdapterGetSet(IntegrationTester $I, Example $example)
    {
        $className = $example[0];
        $label     = $example[1];
        $extension = $example[2];
        $class     = $example[3];
        $options   = $example[4];
        $value     = $example[5];

        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - get()/set() - %s',
                $className,
                $label
            )
        );

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $serializer = new SerializerFactory();
        $adapter    = new $class($serializer, $options);

        $key = uniqid('k-');

        $result = $adapter->set($key, $value);
        $I->assertTrue($result);

        $result = $adapter->has($key);
        $I->assertTrue($result);

        /**
         * This will issue delete
         */
        $result = $adapter->set($key, $value, 0);
        $I->assertTrue($result);

        $result = $adapter->has($key);
        $I->assertFalse($result);
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        return [
            [
                'Apcu',
                'null',
                'apcu',
                Apcu::class,
                [],
                null,
            ],
            [
                'Apcu',
                'true',
                'apcu',
                Apcu::class,
                [],
                true,
            ],
            [
                'Apcu',
                'false',
                'apcu',
                Apcu::class,
                [],
                false,
            ],
            [
                'Apcu',
                'integer',
                'apcu',
                Apcu::class,
                [],
                123456,
            ],
            [
                'Apcu',
                'float',
                'apcu',
                Apcu::class,
                [],
                123.456,
            ],
            [
                'Apcu',
                'string',
                'apcu',
                Apcu::class,
                [],
                uniqid(),
            ],
            [
                'Apcu',
                'object',
                'apcu',
                Apcu::class,
                [],
                new stdClass(),
            ],
            [
                'Libmemcached',
                'null',
                'memcached',
                Libmemcached::class,
                getOptionsLibmemcached(),
                null,
            ],
            [
                'Libmemcached',
                'true',
                'memcached',
                Libmemcached::class,
                getOptionsLibmemcached(),
                true,
            ],
            [
                'Libmemcached',
                'false',
                'memcached',
                Libmemcached::class,
                getOptionsLibmemcached(),
                false,
            ],
            [
                'Libmemcached',
                'integer',
                'memcached',
                Libmemcached::class,
                getOptionsLibmemcached(),
                123456,
            ],
            [
                'Libmemcached',
                'float',
                'memcached',
                Libmemcached::class,
                getOptionsLibmemcached(),
                123.456,
            ],
            [
                'Libmemcached',
                'string',
                'memcached',
                Libmemcached::class,
                getOptionsLibmemcached(),
                uniqid(),
            ],
            [
                'Libmemcached',
                'object',
                'memcached',
                Libmemcached::class,
                getOptionsLibmemcached(),
                new stdClass(),
            ],
            [
                'Libmemcached',
                'custom serializer',
                'memcached',
                Libmemcached::class,
                array_merge(
                    getOptionsLibmemcached(),
                    [
                        'defaultSerializer' => 'Base64',
                    ]
                ),
                uniqid(),
            ],
            [
                'Memory',
                'null',
                '',
                Memory::class,
                [],
                null,
            ],
            [
                'Memory',
                'true',
                '',
                Memory::class,
                [],
                true,
            ],
            [
                'Memory',
                'false',
                '',
                Memory::class,
                [],
                false,
            ],
            [
                'Memory',
                'integer',
                '',
                Memory::class,
                [],
                123456,
            ],
            [
                'Memory',
                'float',
                '',
                Memory::class,
                [],
                123.456,
            ],
            [
                'Memory',
                'string',
                '',
                Memory::class,
                [],
                uniqid(),
            ],
            [
                'Memory',
                'object',
                '',
                Memory::class,
                [],
                new stdClass(),
            ],
            [
                'Redis',
                'null',
                'redis',
                Redis::class,
                getOptionsRedis(),
                null,
            ],
            [
                'Redis',
                'true',
                'redis',
                Redis::class,
                getOptionsRedis(),
                true,
            ],
            [
                'Redis',
                'false',
                'redis',
                Redis::class,
                getOptionsRedis(),
                false,
            ],
            [
                'Redis',
                'integer',
                'redis',
                Redis::class,
                getOptionsRedis(),
                123456,
            ],
            [
                'Redis',
                'float',
                'redis',
                Redis::class,
                getOptionsRedis(),
                123.456,
            ],
            [
                'Redis',
                'string',
                'redis',
                Redis::class,
                getOptionsRedis(),
                uniqid(),
            ],
            [
                'Redis',
                'object',
                'redis',
                Redis::class,
                getOptionsRedis(),
                new stdClass(),
            ],
            [
                'Redis',
                'custom serializer',
                'redis',
                Redis::class,
                array_merge(
                    getOptionsRedis(),
                    [
                        'defaultSerializer' => 'Base64',
                    ]
                ),
                uniqid(),
            ],
            [
                'Redis',
                'persistent',
                'redis',
                Redis::class,
                array_merge(
                    getOptionsRedis(),
                    [
                        'persistent' => true,
                    ]
                ),
                uniqid(),
            ],
            [
                'Stream',
                'null',
                '',
                Stream::class,
                [
                    'storageDir' => outputDir(),
                ],
                null,
            ],
            [
                'Stream',
                'true',
                '',
                Stream::class,
                [
                    'storageDir' => outputDir(),
                ],
                true,
            ],
            [
                'Stream',
                'false',
                '',
                Stream::class,
                [
                    'storageDir' => outputDir(),
                ],
                false,
            ],
            [
                'Stream',
                'integer',
                '',
                Stream::class,
                [
                    'storageDir' => outputDir(),
                ],
                123456,
            ],
            [
                'Stream',
                'float',
                '',
                Stream::class,
                [
                    'storageDir' => outputDir(),
                ],
                123.456,
            ],
            [
                'Stream',
                'string',
                '',
                Stream::class,
                [
                    'storageDir' => outputDir(),
                ],
                uniqid(),
            ],
            [
                'Stream',
                'object',
                '',
                Stream::class,
                [
                    'storageDir' => outputDir(),
                ],
                new stdClass(),
            ],
        ];
    }
}
