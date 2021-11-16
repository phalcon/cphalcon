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

namespace Phalcon\Tests\Integration\Cache\AdapterFactory;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Cache\Adapter\Memory;
use Phalcon\Cache\Adapter\Redis;
use Phalcon\Cache\Adapter\Stream;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Exception\Exception;
use Phalcon\Storage\SerializerFactory;

use function getOptionsLibmemcached;
use function getOptionsRedis;
use function outputDir;
use function uniqid;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Cache\AdapterFactory :: newInstance()
     *
     * @dataProvider getExamples
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @throws Exception
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function cacheAdapterFactoryNewInstance(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Cache\AdapterFactory - newInstance() - ' . $example[0]);

        $serializer = new SerializerFactory();
        $adapter    = new AdapterFactory($serializer);

        $service = $adapter->newInstance($example[0], $example[2]);

        $class = $example[1];
        $I->assertInstanceOf($class, $service);
    }

    /**
     * Tests Phalcon\Storage\SerializerFactory :: newInstance() - exception
     *
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerFactoryNewInstanceException(IntegrationTester $I)
    {
        $I->wantToTest('Storage\SerializerFactory - newInstance() - exception');

        $name = uniqid();
        $I->expectThrowable(
            new Exception('Service ' . $name . ' is not registered'),
            function () use ($name) {
                $serializer = new SerializerFactory();
                $adapter    = new AdapterFactory($serializer);

                $service = $adapter->newInstance($name);
            }
        );
    }


    private function getExamples(): array
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
                getOptionsLibmemcached(),
            ],
            [
                'memory',
                Memory::class,
                [],
            ],
            [
                'redis',
                Redis::class,
                getOptionsRedis(),
            ],
            [
                'stream',
                Stream::class,
                [
                    'storageDir' => outputDir(),
                ],
            ],
        ];
    }
}
