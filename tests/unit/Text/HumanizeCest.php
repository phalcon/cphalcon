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

namespace Phalcon\Test\Unit\Text;

use Codeception\Example;
use Phalcon\Text;
use UnitTester;

class HumanizeCest
{
    /**
     * Tests Phalcon\Text :: humanize()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     *
     * @dataProvider textHumanizeProvider
     */
    public function textHumanize(UnitTester $I, Example $example)
    {
        $I->wantToTest('Text - humanize()');

        $I->assertEquals(
            $example['expected'],
            Text::humanize($example['string'])
        );
    }

    private function textHumanizeProvider(): array
    {
        return [
            [
                'string'   => 'start_a_horse',
                'expected' => 'start a horse',
            ],

            [
                'string'   => 'five-cats',
                'expected' => 'five cats',
            ],

            [
                'string'   => 'kittens-are_cats',
                'expected' => 'kittens are cats',
            ],

            [
                'string'   => " \t Awesome-Phalcon \t ",
                'expected' => 'Awesome Phalcon',
            ],
        ];
    }
}
