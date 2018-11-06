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

class TextUpperLowerCest
{
    /**
     * Tests the upper function
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
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
     * Tests the upper function for multi-bytes encoding
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

    /**
     * Tests the lower function
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testLower(UnitTester $I)
    {
        $expected = 'hello';
        $actual   = Text::lower('hello');
        $I->assertEquals($expected, $actual);

        $expected = 'hello';
        $actual   = Text::lower('HELLO');
        $I->assertEquals($expected, $actual);

        $expected = '1234';
        $actual   = Text::lower('1234');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the lower function for multi-bytes encoding
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-05-06
     */
    public function testLowerMultiBytesEncoding(UnitTester $I)
    {
        $expected = 'привет мир!';
        $actual   = Text::lower('привет мир!');
        $I->assertEquals($expected, $actual);

        $expected = 'привет мир!';
        $actual   = Text::lower('ПриВЕт Мир!');
        $I->assertEquals($expected, $actual);

        $expected = 'привет мир!';
        $actual   = Text::lower('ПРИВЕТ МИР!');
        $I->assertEquals($expected, $actual);


        $expected = 'männer';
        $actual   = Text::lower('männer');
        $I->assertEquals($expected, $actual);

        $expected = 'männer';
        $actual   = Text::lower('mÄnnER');
        $I->assertEquals($expected, $actual);

        $expected = 'männer';
        $actual   = Text::lower('MÄNNER');
        $I->assertEquals($expected, $actual);
    }
}
