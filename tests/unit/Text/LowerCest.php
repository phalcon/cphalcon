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

use Phalcon\Text;
use UnitTester;

/**
 * Class LowerCest
 */
class LowerCest
{
    /**
     * Tests Phalcon\Text :: lower()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textLower(UnitTester $I)
    {
        $I->wantToTest('Text - lower()');
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
     * Tests Phalcon\Text :: lower() - multi-bytes encoding
     *
     * @param UnitTester $I
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-05-06
     */
    public function textLowerMultiBytesEncoding(UnitTester $I)
    {
        $I->wantToTest('Text - lower() - multi byte encoding');
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
