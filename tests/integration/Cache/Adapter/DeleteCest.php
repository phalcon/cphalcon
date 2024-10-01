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

namespace Phalcon\Tests\Integration\Cache\Adapter;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Cache\Adapter\Memory;
use Phalcon\Cache\Adapter\Redis;
use Phalcon\Cache\Adapter\Stream;
use Phalcon\Cache\Adapter\Weak;
use Phalcon\Storage\SerializerFactory;

use function getOptionsLibmemcached;
use function getOptionsRedis;
use function outputDir;
use function sprintf;
use function uniqid;

class DeleteCest
{
    /**
     * Tests Phalcon\Cache\Adapter\* :: delete()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function cacheAdapterDelete(IntegrationTester $I, Example $example)
    {
        $I->wantToTest(
            sprintf(
                'Cache\Adapter\%s - delete()',
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

        $key = uniqid();
        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);

        $actual = $adapter->delete($key);
        $I->assertTrue($actual);

        $actual = $adapter->has($key);
        $I->assertFalse($actual);

        /**
         * Call clear twice to ensure it returns false
         */
        $actual = $adapter->delete($key);
        $I->assertFalse($actual);

        /**
         * Delete unknown
         */
        $key    = uniqid();
        $actual = $adapter->delete($key);
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Cache\Adapter\Weak :: delete()
     *
     * @param IntegrationTester $I
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2023-07-17
     */
    public function cacheAdapterWeakDelete(IntegrationTester $I)
    {

        $I->wantToTest('Cache\Adapter\Weak - delete()');

        $serializer = new SerializerFactory();
        $adapter    = new Weak($serializer);

        $obj1 = new \stdClass();
        $obj1->id = 1;
        $obj2 = new \stdClass();
        $obj2->id = 2;


        $key1 = uniqid();
        $key2 = uniqid();
        $adapter->set($key1, $obj1);
        $adapter->set($key2, $obj2);

        $actual = $adapter->has($key1);
        $I->assertTrue($actual);
        $actual = $adapter->has($key2);
        $I->assertTrue($actual);

        unset($obj1);
        gc_collect_cycles();
        $I->assertEquals(null, $adapter->get($key1));

        $temp = $adapter->get($key2);
        unset($obj2);
        gc_collect_cycles();
        $I->assertEquals($temp, $adapter->get($key2));

        unset($temp);
        $actual = $adapter->delete($key2);
        $I->assertTrue($actual);
        $actual = $adapter->delete($key2);
        $I->assertFalse($actual);

        $key = uniqid();
        $actual = $adapter->delete($key);
        $I->assertFalse($actual);
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
