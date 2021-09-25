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

namespace Phalcon\Tests\Unit\Support\Helper\Str\Interpolate;

use Codeception\Example;
use Phalcon\Support\Helper\Str\Interpolate;
use UnitTester;

class InvokeCest
{
    /**
     * Tests Phalcon\Support\Helper\Str\Interpolate :: __invoke
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-04-28
     */
    public function supportHelperStrInterpolateInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str\Interpolate - invoke - ' . $example[0]);

        $expected = $example[1];
        $format   = $example[2];
        $context  = $example[3];
        $actual   = (new Interpolate())($format, $context);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'date',
                '2020-09-09 is the date',
                '%date% is the date',
                [
                    'date' => '2020-09-09',
                ],
            ],
            [
                'date/level',
                '2020-09-09 is the date CRITICAL is the level',
                '%date% is the date %level% is the level',
                [
                    'date'  => '2020-09-09',
                    'level' => 'CRITICAL',
                ],
            ],
            [
                'empty',
                'no format',
                'no format',
                [
                    'date' => '2020-09-09',
                ],
            ],
            [
                'date',
                '2020-09-09 is the date',
                '%date% is the date',
                [
                    'date' => '2020-09-09',
                ],
            ],
            [
                'date and context',
                '2020-09-09 is the date AAA is context',
                '%date% is the date %stub% is context',
                [
                    'date' => '2020-09-09',
                    'stub' => 'AAA',
                ],
            ],
        ];
    }
}
