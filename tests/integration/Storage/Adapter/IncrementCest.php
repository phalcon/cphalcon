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

use function getOptionsLibmemcached;
use function getOptionsRedis;
use function outputDir;
use function uniqid;

class IncrementCest
{
    /**
     * Tests Phalcon\Storage\Adapter\* :: increment()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function storageAdapterIncrement(IntegrationTester $I, Example $example)
    {
        $I->wantToTest(
            sprintf(
                'Storage\Adapter\%s - increment()',
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

        $key    = uniqid();
        $result = $adapter->set($key, 1);
        $I->assertTrue($result);

        $expected = 2;
        $actual   = $adapter->increment($key);
        $I->assertSame($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertSame($expected, $actual);

        $expected = 20;
        $actual   = $adapter->increment($key, 18);
        $I->assertSame($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertSame($expected, $actual);

        /**
         * unknown key
         */
        $key      = uniqid();
        $expected = $example['unknown'];
        $actual   = $adapter->increment($key);
        $I->assertSame($expected, $actual);

        if ('Stream' === $example['className']) {
            $I->safeDeleteDirectory(outputDir('ph-strm'));
        }
    }

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: increment()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageAdapterRedisIncrement(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - increment()');

        $I->checkExtensionIsLoaded('redis');

        $serializer = new SerializerFactory();
        $adapter    = new Redis($serializer, getOptionsRedis());

        $key      = uniqid();
        $expected = 1;
        $actual   = $adapter->increment($key, 1);
        $I->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);

        $expected = 2;
        $actual   = $adapter->increment($key);
        $I->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);

        $expected = 10;
        $actual   = $adapter->increment($key, 8);
        $I->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);

        /**
         * unknown key
         */
        $key      = uniqid();
        $expected = 1;
        $actual   = $adapter->increment($key);
        $I->assertSame($expected, $actual);
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
                'unknown'   => 1,
            ],
            [
                'className' => 'Libmemcached',
                'class'     => Libmemcached::class,
                'options'   => getOptionsLibmemcached(),
                'extension' => 'memcached',
                'unknown'   => false,
            ],
            [
                'className' => 'Memory',
                'class'     => Memory::class,
                'options'   => [],
                'extension' => '',
                'unknown'   => false,
            ],
            [
                'className' => 'Stream',
                'class'     => Stream::class,
                'options'   => [
                    'storageDir' => outputDir(),
                ],
                'extension' => '',
                'unknown'   => false,
            ],
        ];
    }
}
