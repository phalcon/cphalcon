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
use Phalcon\Support\Helper\Str\Ucwords;
use UnitTester;

/**
 * Class UcwordsCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class UcwordsCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: ucwords()
     *
     * @dataProvider getData
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function supportHelperStrUcwords(UnitTester $I, Example $example)
    {
        $I->wantToTest('Support\Helper\Str - ucwords()');

        $object   = new Ucwords();
        $expected = $example['expected'];
        $actual   = $object($example['text']);

        $I->assertEquals($expected, $actual);
    }

    /**
     * @return string[][]
     */
    private function getData(): array
    {
        return [
            [
                'text'     => 'hello goodbye',
                'expected' => 'Hello Goodbye',
            ],

            [
                'text'     => 'HELLO GOODBYE',
                'expected' => 'Hello Goodbye',
            ],

            [
                'text'     => '1234',
                'expected' => '1234',
            ],
            [
                'text'     => 'ПРИВЕТ МИР!',
                'expected' => 'Привет Мир!',
            ],

            [
                'text'     => 'ПриВЕт Мир!',
                'expected' => 'Привет Мир!',
            ],

            [
                'text'     => 'привет мир!',
                'expected' => 'Привет Мир!',
            ],

            [
                'text'     => 'MÄNNER MÄNNER',
                'expected' => 'Männer Männer',
            ],

            [
                'text'     => 'mÄnnER mÄnnER',
                'expected' => 'Männer Männer',
            ],

            [
                'text'     => 'männer männer',
                'expected' => 'Männer Männer',
            ],
        ];
    }
}
