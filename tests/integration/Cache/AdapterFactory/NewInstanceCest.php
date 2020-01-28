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

namespace Phalcon\Test\Integration\Cache\AdapterFactory;

use Codeception\Example;
use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Cache\Adapter\Memory;
use Phalcon\Cache\Adapter\Redis;
use Phalcon\Cache\Adapter\Stream;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Factory\Exception;
use Phalcon\Storage\Serializer\Json;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

use function getOptionsLibmemcached;
use function getOptionsRedis;
use function outputDir;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Cache\AdapterFactory :: newInstance()
     *
     * @dataProvider getExamples
     *
     * @throws Exception
     * @since        2019-05-04
     *
     * @author       Phalcon Team <team@phalcon.io>
     */
    public function cacheAdapterFactoryNewInstance(UnitTester $I, Example $example)
    {
        $I->wantToTest('Storage\AdapterFactory - newInstance() - ' . $example[0]);

        $serializer = new SerializerFactory();
        $adapter    = new AdapterFactory($serializer);

        $service = $adapter->newInstance($example[0], $example[2]);

        $I->assertInstanceOf(
            $example[1],
            $service
        );

        // Given `serializer` parameter
        $adapter = new AdapterFactory($serializer);
        $service = $adapter->newInstance($example[0], $example[3]);

        $I->assertInstanceOf(
            $example[1],
            $service
        );
    }

    /**
     * Tests Phalcon\Storage\SerializerFactory :: newInstance() - exception
     *
     * @throws Exception
     * @since  2019-05-04
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function storageSerializerFactoryNewInstanceException(UnitTester $I)
    {
        $I->wantToTest('Storage\SerializerFactory - newInstance() - exception');

        $I->expectThrowable(
            new Exception('Service unknown is not registered'),
            function () {
                $serializer = new SerializerFactory();
                $adapter    = new AdapterFactory($serializer);

                $service = $adapter->newInstance('unknown');
            }
        );
    }

    private function getExamples(): array
    {
        $jsonSerializer        = new Json();
        $optionsWithSerializer = [
            'serializer' => $jsonSerializer,
        ];
        return [
            [
                'apcu',
                Apcu::class,
                [],
                $optionsWithSerializer,
            ],
            [
                'libmemcached',
                Libmemcached::class,
                getOptionsLibmemcached(),
                array_merge(getOptionsLibmemcached(), $optionsWithSerializer),
            ],
            [
                'memory',
                Memory::class,
                [],
                $optionsWithSerializer,
            ],
            [
                'redis',
                Redis::class,
                getOptionsRedis(),
                array_merge(getOptionsRedis(), $optionsWithSerializer),
            ],
            [
                'stream',
                Stream::class,
                [
                    'storageDir' => outputDir(),
                ],
                [
                    'storageDir' => outputDir(),
                    'serializer' => $jsonSerializer,
                ],
            ],
        ];
    }
}
