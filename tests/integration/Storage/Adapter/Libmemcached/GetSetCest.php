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

namespace Phalcon\Tests\Integration\Storage\Adapter\Libmemcached;

use Codeception\Example;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\Fixtures\Traits\LibmemcachedTrait;
use stdClass;
use IntegrationTester;

use function getOptionsLibmemcached;

class GetSetCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: get()/set()
     *
     * @dataProvider getExamples
     *
     * @throws Exception
     * @since        2019-03-31
     *
     * @author       Phalcon Team <team@phalcon.io>
     */
    public function storageAdapterLibmemcachedGetSet(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - get()/set() - ' . $example[0]);

        $serializer = new SerializerFactory();

        $adapter = new Libmemcached(
            $serializer,
            getOptionsLibmemcached()
        );

        $key = 'cache-data';

        $I->assertTrue(
            $adapter->set($key, $example[1])
        );

        $expected = $example[1];

        $I->assertEquals(
            $expected,
            $adapter->get($key)
        );
    }

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: get()/set() - custom
     * serializer
     *
     * @throws Exception
     * @since  2019-04-29
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function storageAdapterLibmemcachedGetSetCustomSerializer(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - get()/set() - custom serializer');

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
