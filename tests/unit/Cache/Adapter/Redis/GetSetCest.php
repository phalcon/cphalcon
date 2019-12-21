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

namespace Phalcon\Test\Unit\Cache\Adapter\Redis;

use Codeception\Example;
use Phalcon\Cache\Adapter\Redis;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use stdClass;
use UnitTester;

use function array_merge;
use function getOptionsRedis;
use function uniqid;

class GetSetCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Redis :: get()
     *
     * @dataProvider getExamples
     *
     * @throws Exception
     * @since        2019-03-31
     *
     * @author       Phalcon Team <team@phalcon.io>
     */
    public function cacheAdapterRedisGetSet(UnitTester $I, Example $example)
    {
        $I->wantToTest('Cache\Adapter\Redis - get()/set() - ' . $example[0]);

        $serializer = new SerializerFactory();
        $adapter    = new Redis($serializer, getOptionsRedis());

        $key = 'cache-data';

        $result = $adapter->set($key, $example[1]);
        $I->assertTrue($result);

        $expected = $example[1];
        $actual   = $adapter->get($key);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Cache\Adapter\Redis :: get() - persistent
     *
     * @throws Exception
     * @author Phalcon Team <team@phalcon.io>
     *
     * @since  2019-03-31
     */
    public function cacheAdapterRedisGetSetPersistent(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Redis - get()/set() - persistent');

        $serializer = new SerializerFactory();
        $adapter    = new Redis(
            $serializer,
            array_merge(
                getOptionsRedis(),
                [
                    'persistent' => true,
                ]
            )
        );

        $key = uniqid();

        $I->assertTrue(
            $adapter->set($key, 'test')
        );

        $expected = 'test';

        $I->assertEquals(
            $expected,
            $adapter->get($key)
        );
    }

    /**
     * Tests Phalcon\Cache\Adapter\Redis :: get() - wrong index
     *
     * @since  2019-03-31
     * @author Phalcon Team <team@phalcon.io>
     */
    public function cacheAdapterRedisGetSetWrongIndex(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Redis - get()/set() - wrong index');
        $I->expectThrowable(
            new Exception('Redis server selected database failed'),
            function () {
                $serializer = new SerializerFactory();

                $adapter = new Redis(
                    $serializer,
                    array_merge(
                        getOptionsRedis(),
                        [
                            'index' => 99,
                        ]
                    )
                );

                $adapter->get('test');
            }
        );
    }

    /**
     * Tests Phalcon\Cache\Adapter\Redis :: get() - failed auth
     *
     * @since  2019-03-31
     * @author Phalcon Team <team@phalcon.io>
     */
    public function cacheAdapterRedisGetSetFailedAuth(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Redis - get()/set() - failed auth');
        $I->expectThrowable(
            new Exception('Failed to authenticate with the Redis server'),
            function () {
                $serializer = new SerializerFactory();

                $adapter = new Redis(
                    $serializer,
                    array_merge(
                        getOptionsRedis(),
                        [
                            'auth' => 'something',
                        ]
                    )
                );

                $adapter->get('test');
            }
        );
    }

    /**
     * Tests Phalcon\Cache\Adapter\Redis :: get()/set() - custom serializer
     *
     * @throws Exception
     * @since  2019-04-29
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function cacheAdapterRedisGetSetCustomSerializer(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Redis - get()/set() - custom serializer');

        $serializer = new SerializerFactory();

        $adapter = new Redis(
            $serializer,
            array_merge(
                getOptionsRedis(),
                [
                    'defaultSerializer' => 'Base64',
                ]
            )
        );

        $key    = 'cache-data';
        $source = 'Phalcon Framework';

        $I->assertTrue(
            $adapter->set($key, $source)
        );


        $I->assertEquals(
            $source,
            $adapter->get($key)
        );
    }

    private function getExamples(): array
    {
        return [
            [
                'string',
                'random string',
            ],
            [
                'integer',
                123456,
            ],
            [
                'float',
                123.456,
            ],
            [
                'boolean',
                true,
            ],
            [
                'object',
                new stdClass(),
            ],
        ];
    }
}
