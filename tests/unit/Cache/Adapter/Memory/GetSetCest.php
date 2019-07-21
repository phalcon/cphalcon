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

namespace Phalcon\Test\Unit\Cache\Adapter\Memory;

use Codeception\Example;
use Phalcon\Cache\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use stdClass;
use UnitTester;

class GetSetCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Memory :: get()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-03-31
     */
    public function cacheAdapterMemoryGetSet(UnitTester $I, Example $example)
    {
        $I->wantToTest('Cache\Adapter\Memory - get()/set() - ' . $example[0]);

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $key = uniqid();

        $I->assertTrue(
            $adapter->set($key, $example[1])
        );

        $I->assertEquals(
            $example[1],
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
