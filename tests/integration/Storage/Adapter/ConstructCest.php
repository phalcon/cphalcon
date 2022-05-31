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
use DateInterval;
use IntegrationTester;
use Phalcon\Storage\Adapter\AdapterInterface;
use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\Exception as StorageException;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as SupportException;
use Phalcon\Tests\Fixtures\Storage\Adapter\Libmemcached as LibmemcachedFixture;

use function getOptionsLibmemcached;
use function getOptionsRedis;
use function outputDir;
use function sprintf;

class ConstructCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: __construct() - exception
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageAdapterStreamConstructException(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - __construct() - exception');

        $I->expectThrowable(
            new StorageException("The 'storageDir' must be specified in the options"),
            function () {
                $serializer = new SerializerFactory();
                (new Stream($serializer));
            }
        );
    }

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: __construct() - empty
     * options
     *
     * @param IntegrationTester $I
     *
     * @throws SupportException
     * @since  2020-09-09
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function storageAdapterLibmemcachedConstructEmptyOptions(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - __construct() - empty options');

        $I->checkExtensionIsLoaded('memcached');
        $serializer = new SerializerFactory();
        $adapter    = new LibmemcachedFixture($serializer);

        $expected = [
            'servers' => [
                0 => [
                    'host'   => '127.0.0.1',
                    'port'   => 11211,
                    'weight' => 1,
                ],
            ],
        ];
        $actual   = $adapter->getOptions();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: __construct() - getTtl
     * options
     *
     * @param IntegrationTester $I
     *
     * @throws SupportException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageAdapterLibmemcachedConstructGetTtl(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - __construct() - getTtl');

        $I->checkExtensionIsLoaded('memcached');
        $serializer = new SerializerFactory();
        $adapter    = new LibmemcachedFixture(
            $serializer,
            getOptionsLibmemcached()
        );

        $expected = 3600;
        $actual   = $adapter->getTtl(null);
        $I->assertSame($expected, $actual);

        $expected = 20;
        $actual   = $adapter->getTtl(20);
        $I->assertSame($expected, $actual);

        $time     = new DateInterval('PT5S');
        $expected = 5;
        $actual   = $adapter->getTtl($time);
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Adapter\* :: __construct()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function storageAdapterConstruct(IntegrationTester $I, Example $example)
    {
        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - __construct()',
                $example['className']
            )
        );

        $extension = $example['extension'];
        $class     = $example['class'];
        $options   = $example['options'];

        if (!empty($extension)) {
            $I->checkExtensionIsLoaded($extension);
        }

        $serializer = new SerializerFactory();
        $adapter    = new $class($serializer, $options);

        $I->assertInstanceOf($class, $adapter);
        $I->assertInstanceOf(AdapterInterface::class, $adapter);
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        return [
            [
                'className' => 'Apcu',
                'class'     => Apcu::class,
                'options'   => [],
                'extension' => 'apcu',
            ],
            [
                'className' => 'Libmemcached',
                'class'     => Libmemcached::class,
                'options'   => getOptionsLibmemcached(),
                'extension' => 'memcached',
            ],
            [
                'className' => 'Memory',
                'label'     => 'default',
                'class'     => Memory::class,
                'options'   => [],
                'extension' => '',
            ],
            [
                'className' => 'Redis',
                'label'     => 'default',
                'class'     => Redis::class,
                'options'   => getOptionsRedis(),
                'extension' => 'redis',
            ],
            [
                'className' => 'Stream',
                'label'     => 'default',
                'class'     => Stream::class,
                'options'   => [
                    'storageDir' => outputDir(),
                ],
                'extension' => '',
            ],
        ];
    }
}
