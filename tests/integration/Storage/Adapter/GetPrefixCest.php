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
use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use IntegrationTester;

use function array_merge;
use function getOptionsRedis;
use function outputDir;

class GetPrefixCest
{
    /**
     * Tests Phalcon\Storage\Adapter\* :: getPrefix()
     *
     * @dataProvider getExamples
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageAdapterGetSetPrefix(IntegrationTester $I, Example $example)
    {
        $I->wantToTest(
            'Storage\Adapter\'' . $example['className'] . ' - getPrefix() - ' . $example['label']
        );

        $extension  = $example['extension'];
        $class      = $example['class'];
        $options    = $example['options'];

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $serializer = new SerializerFactory();
        $adapter = new $class($serializer, $options);

        $expected = $example['expected'];
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }

    private function getExamples(): array
    {
        return [
            [
                'className' => 'Apcu',
                'label'     => 'default',
                'class'     => Apcu::class,
                'options'   => [
                ],
                'expected'  => 'ph-apcu-',
                'extension' => 'apcu',
            ],
            [
                'className' => 'Apcu',
                'label'     => 'empty',
                'class'     => Apcu::class,
                'options'   => [
                    'prefix' => '',
                ],
                'expected'  => '',
                'extension' => 'apcu',
            ],
            [
                'className' => 'Apcu',
                'label'     => 'prefix set',
                'class'     => Apcu::class,
                'options'   => [
                    'prefix' => 'my-prefix',
                ],
                'expected'  => 'my-prefix',
                'extension' => 'apcu',
            ],
            [
                'className' => 'Libmemcached',
                'label'     => 'default',
                'class'     => Libmemcached::class,
                'options'   => array_merge(
                    getOptionsLibmemcached(),
                    [
                    ]
                ),
                'expected'  => 'ph-memc-',
                'extension' => 'memcached',
            ],
            [
                'className' => 'Libmemcached',
                'label'     => 'empty',
                'class'     => Libmemcached::class,
                'options'   => array_merge(
                    getOptionsLibmemcached(),
                    [
                        'prefix' => '',
                    ]
                ),
                'expected'  => '',
                'extension' => 'memcached',
            ],
            [
                'className' => 'Libmemcached',
                'label'     => 'prefix set',
                'class'     => Libmemcached::class,
                'options'   => array_merge(
                    getOptionsLibmemcached(),
                    [
                        'prefix' => 'my-prefix',
                    ]
                ),
                'expected'  => 'my-prefix',
                'extension' => 'memcached',
            ],
            [
                'className' => 'Memory',
                'label'     => 'default',
                'class'     => Memory::class,
                'options'   => [
                ],
                'expected'  => 'ph-memo-',
                'extension' => '',
            ],
            [
                'className' => 'Memory',
                'label'     => 'empty',
                'class'     => Memory::class,
                'options'   => [
                    'prefix' => '',
                ],
                'expected'  => '',
                'extension' => '',
            ],
            [
                'className' => 'Memory',
                'label'     => 'prefix set',
                'class'     => Memory::class,
                'options'   => [
                    'prefix' => 'my-prefix',
                ],
                'expected'  => 'my-prefix',
                'extension' => '',
            ],
            [
                'className' => 'Redis',
                'label'     => 'default',
                'class'     => Redis::class,
                'options'   => array_merge(
                    getOptionsRedis(),
                    [
                    ]
                ),
                'expected'  => 'ph-reds-',
                'extension' => 'redis',
            ],
            [
                'className' => 'Redis',
                'label'     => 'empty',
                'class'     => Redis::class,
                'options'   => array_merge(
                    getOptionsRedis(),
                    [
                        'prefix' => '',
                    ]
                ),
                'expected'  => '',
                'extension' => 'redis',
            ],
            [
                'className' => 'Redis',
                'label'     => 'prefix set',
                'class'     => Redis::class,
                'options'   => array_merge(
                    getOptionsRedis(),
                    [
                        'prefix' => 'my-prefix',
                    ]
                ),
                'expected'  => 'my-prefix',
                'extension' => 'redis',
            ],
            [
                'className' => 'Stream',
                'label'     => 'default',
                'class'     => Stream::class,
                'options'   => [
                    'storageDir' => outputDir(),
                ],
                'expected'  => 'ph-strm',
                'extension' => '',
            ],
            [
                'className' => 'Stream',
                'label'     => 'empty',
                'class'     => Stream::class,
                'options'   => [
                    'storageDir' => outputDir(),
                    'prefix'     => '',
                ],
                'expected'  => '',
                'extension' => '',
            ],
            [
                'className' => 'Stream',
                'label'     => 'prefix set',
                'class'     => Stream::class,
                'options'   => [
                    'storageDir' => outputDir(),
                    'prefix'     => 'my-prefix',
                ],
                'expected'  => 'my-prefix',
                'extension' => '',
            ],
        ];
    }
}
