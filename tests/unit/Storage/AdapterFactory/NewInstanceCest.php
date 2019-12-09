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

namespace Phalcon\Test\Unit\Storage\AdapterFactory;

use Codeception\Example;
use Phalcon\Factory\Exception;
use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\AdapterFactory;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

use function getOptionsLibmemcached;
use function getOptionsRedis;
use function outputDir;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Storage\AdapterFactory :: newInstance()
     *
     * @dataProvider getExamples
     *
     * @throws Exception
     * @since        2019-05-04
     *
     * @author       Phalcon Team <team@phalcon.io>
     */
    public function storageAdapterFactoryNewInstance(UnitTester $I, Example $example)
    {
        $I->wantToTest('Storage\AdapterFactory - newInstance() - ' . $example[0]);

        $serializer = new SerializerFactory();
        $adapter    = new AdapterFactory($serializer);

        $service = $adapter->newInstance($example[0], $example[2]);

        $class = $example[1];
        $I->assertInstanceOf($class, $service);
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
