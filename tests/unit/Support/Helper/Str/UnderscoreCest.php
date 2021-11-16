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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Codeception\Example;
use Phalcon\Support\Helper\Str\Underscore;
use UnitTester;

/**
 * Class UnderscoreCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class UnderscoreCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: underscore()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function supportHelperStrUnderscore(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - underscore() - ' . $example[0]);

        $object = new Underscore();

        $expected = $example[2];
        $actual   = $object($example[1]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return string[][]
     */
    private function getExamples(): array
    {
        return [
            [
                'spaces',
                'start a horse',
                'start_a_horse',
            ],
            [
                'tabs',
                "five\tcats",
                'five_cats',
            ],
            [
                'more spaces',
                ' look behind ',
                'look_behind',
            ],
            [
                'more tabs',
                " \t Awesome \t  \t Phalcon ",
                'Awesome_Phalcon',
            ],
        ];
    }
}
