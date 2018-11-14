<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use UnitTester;

class UpperCest
{
    /**
     * Tests Phalcon\Text :: upper()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testUpper(UnitTester $I)
    {
        $expected = 'HELLO';
        $actual   = Text::upper('hello');
        $I->assertEquals($expected, $actual);

        $expected = 'HELLO';
        $actual   = Text::upper('HELLO');
        $I->assertEquals($expected, $actual);

        $expected = '1234';
        $actual   = Text::upper('1234');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Text :: upper() - multi-bytes encoding
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-05-06
     */
    public function testUpperMultiBytesEncoding(UnitTester $I)
    {
        $expected = 'ПРИВЕТ МИР!';
        $actual   = Text::upper('ПРИВЕТ МИР!');
        $I->assertEquals($expected, $actual);

        $expected = 'ПРИВЕТ МИР!';
        $actual   = Text::upper('ПриВЕт Мир!');
        $I->assertEquals($expected, $actual);

        $expected = 'ПРИВЕТ МИР!';
        $actual   = Text::upper('привет мир!');
        $I->assertEquals($expected, $actual);

        $expected = 'MÄNNER';
        $actual   = Text::upper('MÄNNER');
        $I->assertEquals($expected, $actual);

        $expected = 'MÄNNER';
        $actual   = Text::upper('mÄnnER');
        $I->assertEquals($expected, $actual);

        $expected = 'MÄNNER';
        $actual   = Text::upper('männer');
        $I->assertEquals($expected, $actual);
    }
}
