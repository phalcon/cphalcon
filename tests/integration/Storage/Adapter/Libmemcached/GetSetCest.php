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
use IntegrationTester;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\Exception as StorageException;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as HelperException;
use Phalcon\Tests\Fixtures\Traits\LibmemcachedTrait;
use stdClass;

use function getOptionsLibmemcached;

class GetSetCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: get()/set()
     *
     * @dataProvider getExamples
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @throws StorageException
     * @throws HelperException
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function storageAdapterLibmemcachedGetSet(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - get()/set() - ' . $example[0]);

        $serializer = new SerializerFactory();
        $adapter    = new Libmemcached(
            $serializer,
            getOptionsLibmemcached()
        );

        $key    = uniqid();
        $actual = $adapter->set($key, $example[1]);
        $I->assertTrue($actual);

        $expected = $example[1];
        $actual   = $adapter->get($key);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: get()/set() - custom
     * serializer
     *
     * @param IntegrationTester $I
     *
     * @throws StorageException
     * @throws HelperException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageAdapterLibmemcachedGetSetCustomSerializer(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - get()/set() - custom serializer');

        $serializer = new SerializerFactory();
        $adapter    = new Libmemcached(
            $serializer,
            array_merge(
                getOptionsLibmemcached(),
                [
                    'defaultSerializer' => 'Base64',
                ]
            )
        );

        $key    = uniqid();
        $source = 'Phalcon Framework';
        $actual = $adapter->set($key, $source);
        $I->assertTrue($actual);

        $expected = $source;
        $actual   = $adapter->get($key);
        $I->assertEquals($expected, $actual);
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
