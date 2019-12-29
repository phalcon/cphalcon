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

namespace Phalcon\Test\Unit\Storage\Adapter\Memory;

use Codeception\Example;
use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use stdClass;
use UnitTester;

class GetSetCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Memory :: get()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-03-31
     */
    public function storageAdapterMemoryGetSet(UnitTester $I, Example $example)
    {
        $I->wantToTest('Storage\Adapter\Memory - get()/set() - ' . $example[0]);

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $key = uniqid();

        $result = $adapter->set($key, $example[1]);
        $I->assertTrue($result);

        $expected = $example[1];
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
