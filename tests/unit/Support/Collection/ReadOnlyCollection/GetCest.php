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

namespace Phalcon\Tests\Unit\Support\Collection\ReadOnlyCollection;

use Codeception\Example;
use Phalcon\Support\Collection\ReadOnlyCollection;
use stdClass;
use UnitTester;

class GetCest
{
    /**
     * Tests Phalcon\Support\Collection\ReadOnlyCollection :: get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionGet(UnitTester $I)
    {
        $I->wantToTest('Support\Collection\ReadOnlyCollection - get()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new ReadOnlyCollection($data);
        $expected   = 'four';

        $actual = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $actual = $collection->get('THREE');
        $I->assertEquals($expected, $actual);

        $actual = $collection->get(uniqid(), 'four');
        $I->assertEquals($expected, $actual);

        $actual = $collection['three'];
        $I->assertEquals($expected, $actual);

        $actual = $collection->three;
        $I->assertEquals($expected, $actual);

        $actual = $collection->offsetGet('three');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Collection :: get() - cast
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function helperArrGetCast(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Collection\ReadOnlyCollection - get() - cast ' . $example[0]);

        $collection = new ReadOnlyCollection(
            [
                'value' => $example[1],
            ]
        );

        $expected = $example[2];
        $actual   = $collection->get('value', null, $example[0]);
        $I->assertEquals($expected, $actual);
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
