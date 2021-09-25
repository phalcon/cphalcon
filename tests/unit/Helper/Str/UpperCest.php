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

namespace Phalcon\Tests\Unit\Helper\Str;

use Codeception\Example;
use Phalcon\Helper\Str;
use UnitTester;

class UpperCest
{
    /**
     * Tests Phalcon\Helper\Str :: upper()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-04-06
     *
     * @dataProvider basicProvider
     */
    public function helperStrUpper(UnitTester $I, Example $example)
    {
        $I->wantToTest('Helper\Str - upper()');

        $I->assertEquals(
            $example['expected'],
            Str::upper(
                $example['text']
            )
        );
    }

    /**
     * Tests Phalcon\Helper\Str :: upper() - multi-bytes encoding
     *
     * @author       Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since        2015-05-06
     *
     * @dataProvider multiBytesEncodingProvider
     */
    public function helperStrUpperMultiBytesEncoding(UnitTester $I, Example $example)
    {
        $I->wantToTest('Helper\Str - upper() - multi byte encoding');

        $I->assertEquals(
            $example['expected'],
            Str::upper(
                $example['text']
            )
        );
    }

    private function basicProvider(): array
    {
        return [
            [
                'text'     => 'hello',
                'expected' => 'HELLO',
            ],

            [
                'text'     => 'HELLO',
                'expected' => 'HELLO',
            ],

            [
                'text'     => '1234',
                'expected' => '1234',
            ],
        ];
    }

    private function multiBytesEncodingProvider(): array
    {
        return [
            [
                'text'     => 'ПРИВЕТ МИР!',
                'expected' => 'ПРИВЕТ МИР!',
            ],

            [
                'text'     => 'ПриВЕт Мир!',
                'expected' => 'ПРИВЕТ МИР!',
            ],

            [
                'text'     => 'привет мир!',
                'expected' => 'ПРИВЕТ МИР!',
            ],

            [
                'text'     => 'MÄNNER',
                'expected' => 'MÄNNER',
            ],

            [
                'text'     => 'mÄnnER',
                'expected' => 'MÄNNER',
            ],

            [
                'text'     => 'männer',
                'expected' => 'MÄNNER',
            ],
        ];
    }
}
