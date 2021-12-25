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

namespace Phalcon\Tests\Unit\Support\Registry;

use Codeception\Example;
use Phalcon\Support\Registry;
use stdClass;
use UnitTester;

class GetCest
{
    /**
     * Tests Phalcon\Support\Registry :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function registryGet(UnitTester $I)
    {
        $I->wantToTest('Registry - get()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $registry = new Registry($data);

        $I->assertEquals(
            'four',
            $registry->get('three')
        );
    }

    /**
     * Tests Phalcon\Support\Registry :: get() - cast
     *
     * @dataProvider getExamples
     *
     * @since        2019-10-12
     */
    public function registryGetCast(UnitTester $I, Example $example)
    {
        $I->wantToTest('Registry - get() - cast ' . $example[0]);

        $collection = new Registry(
            [
                'value' => $example[1],
            ]
        );

        $I->assertEquals(
            $example[2],
            $collection->get('value', null, $example[0])
        );
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        $sample      = new stdClass();
        $sample->one = 'two';

        return [
            [
                'boolean',
                1,
                true,
            ],
            [
                'bool',
                1,
                true,
            ],
            [
                'integer',
                "123",
                123,
            ],
            [
                'int',
                "123",
                123,
            ],
            [
                'float',
                "123.45",
                123.45,
            ],
            [
                'double',
                "123.45",
                123.45,
            ],
            [
                'string',
                123,
                "123",
            ],
            [
                'array',
                $sample,
                ['one' => 'two'],
            ],
            [
                'object',
                ['one' => 'two'],
                $sample,
            ],
            [
                'null',
                1234,
                null,
            ],
        ];
    }
}
