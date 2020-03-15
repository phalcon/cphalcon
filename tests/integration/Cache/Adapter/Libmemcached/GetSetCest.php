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

namespace Phalcon\Test\Integration\Cache\Adapter\Libmemcached;

use Codeception\Example;
use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use stdClass;
use IntegrationTester;

use function getOptionsLibmemcached;

class GetSetCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Libmemcached :: get()/set()
     *
     * @dataProvider getExamples
     *
     * @throws Exception
     * @since        2019-03-31
     *
     * @author       Phalcon Team <team@phalcon.io>
     */
    public function cacheAdapterLibmemcachedGetSet(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Cache\Adapter\Libmemcached - get()/set() - ' . $example[0]);

        $serializer = new SerializerFactory();
        $adapter    = new Libmemcached($serializer, getOptionsLibmemcached());

        $key = 'cache-data';

        $I->assertTrue(
            $adapter->set($key, $example[1])
        );

        $I->assertEquals(
            $example[1],
            $adapter->get($key)
        );
    }

    /**
     * Tests Phalcon\Cache\Adapter\Libmemcached :: get()/set() - custom
     * serializer
     *
     * @throws Exception
     * @since  2019-04-29
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function cacheAdapterLibmemcachedGetSetCustomSerializer(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Libmemcached - get()/set() - custom serializer');

        $serializer = new SerializerFactory();

        $adapter = new Libmemcached(
            $serializer,
            array_merge(
                getOptionsLibmemcached(),
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
                'boolean true',
                true,
            ],
            [
                'boolean false',
                false,
            ],
            [
                'null',
                null,
            ],
            [
                'object',
                new stdClass(),
            ],
        ];
    }
}
