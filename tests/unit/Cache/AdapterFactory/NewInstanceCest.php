<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\AdapterFactory;

use Codeception\Example;
use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Cache\Adapter\Memory;
use Phalcon\Cache\Adapter\Redis;
use Phalcon\Cache\Adapter\Stream;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Exception;
use Phalcon\Storage\SerializerFactory;
use UnitTester;
use function getOptionsLibmemcached;
use function getOptionsRedis;
use function outputDir;

/**
 * Class NewInstanceCest
 */
class NewInstanceCest
{
    /**
     * Tests Phalcon\Cache\AdapterFactory :: newInstance()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since        2019-05-04
     *
     * @author       Phalcon Team <team@phalconphp.com>
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
     * @param UnitTester $I
     *
     * @throws Exception
     * @since  2019-05-04
     *
     * @author Phalcon Team <team@phalconphp.com>
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

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            ['apcu', Apcu::class, []],
            ['libmemcached', Libmemcached::class, getOptionsLibmemcached()],
            ['memory', Memory::class, []],
            ['redis', Redis::class, getOptionsRedis()],
            ['stream', Stream::class, ['cacheDir' => outputDir()]],
        ];
    }
}
