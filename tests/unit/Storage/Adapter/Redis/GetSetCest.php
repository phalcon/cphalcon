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

namespace Phalcon\Test\Unit\Storage\Adapter\Redis;

use Codeception\Example;
use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\Exception;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use stdClass;
use function uniqid;
use UnitTester;
use function array_merge;
use function getOptionsRedis;

/**
 * Class GetSetCest
 */
class GetSetCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: get()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws Exception
     * @since        2019-03-31
     *
     * @author       Phalcon Team <team@phalconphp.com>
     */
    public function storageAdapterRedisGetSet(UnitTester $I, Example $example)
    {
        $I->wantToTest('Storage\Adapter\Redis - get()/set() - ' . $example[0]);
        $adapter = new Redis(getOptionsRedis());

        $key = 'cache-data';

        $result = $adapter->set($key, $example[1]);
        $I->assertTrue($result);

        $expected = $example[1];
        $actual   = $adapter->get($key);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: get() - persistent
     *
     * @param UnitTester $I
     *
     * @since  2019-03-31
     * @author Phalcon Team <team@phalconphp.com>
     *
     * @throws Exception
     */
    public function storageAdapterRedisGetSetPersistent(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - get()/set() - persistent');
        $adapter = new Redis(
            array_merge(
                getOptionsRedis(),
                [
                    'persistent' => true,
                ]
            )
        );

        $key = uniqid();
        $result = $adapter->set($key, 'test');
        $I->assertTrue($result);

        $expected = 'test';
        $actual   = $adapter->get($key);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: get() - wrong index
     *
     * @param UnitTester $I
     *
     * @since  2019-03-31
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function storageAdapterRedisGetSetWrongIndex(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - get()/set() - wrong index');
        $I->expectThrowable(
            new Exception('Redis server selected database failed'),
            function () {
                $adapter = new Redis(
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
     * Tests Phalcon\Storage\Adapter\Redis :: get() - failed auth
     *
     * @param UnitTester $I
     *
     * @since  2019-03-31
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function storageAdapterRedisGetSetFailedAuth(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - get()/set() - failed auth');
        $I->expectThrowable(
            new Exception('Failed to authenticate with the Redis server'),
            function () {
                $adapter = new Redis(
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
     * Tests Phalcon\Storage\Adapter\Redis :: get()/set() - custom serializer
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since  2019-04-29
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function storageAdapterRedisGetSetCustomSerializer(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - get()/set() - custom serializer');
        $adapter = new Redis(
            array_merge(
                getOptionsRedis(),
                [
                    'defaultSerializer' => 'Base64',
                ]
            )
        );

        $key    = 'cache-data';
        $source = 'Phalcon Framework';
        $result = $adapter->set($key, $source);
        $I->assertTrue($result);

        $actual = $adapter->get($key);
        $I->assertEquals($source, $actual);
    }

    /**
     * @return array
     */
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
