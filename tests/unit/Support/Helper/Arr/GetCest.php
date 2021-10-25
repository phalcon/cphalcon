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

namespace Phalcon\Tests\Unit\Support\Helper\Arr;

use Codeception\Example;
use Phalcon\Support\Helper\Arr\Get;
use stdClass;
use UnitTester;

/**
 * Class GetCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Arr
 */
class GetCest
{
    /**
     * Tests Phalcon\Support\Helper\Arr :: get() - numeric
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrGetNumeric(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - get() - numeric');

        $object     = new Get();
        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $expected = 'Phalcon';
        $actual   = $object($collection, 1, 'Error');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Arr :: get() - string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrGetString(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - get() - string');

        $object     = new Get();
        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $expected = 'Framework';
        $actual   = $object($collection, 'suffix', 'Error');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Arr :: get() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrGetDefault(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - get() - default');

        $object     = new Get();
        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $expected = 'Error';
        $actual   = $object($collection, 'unknown', 'Error');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Arr :: get() - cast
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function supportHelperArrGetCast(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Arr - get() - cast ' . $example[0]);

        $object     = new Get();
        $collection = [
            'value' => $example[1],
        ];

        $expected = $example[2];
        $actual   = $object($collection, 'value', null, $example[0]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array[]
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
