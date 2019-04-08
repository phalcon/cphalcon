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

namespace Phalcon\Test\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

/**
 * Class UpperCest
 */
class UpperCest
{
    /**
     * Tests Phalcon\Helper\Str :: upper()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrUpper(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - upper()');
        $expected = 'HELLO';
        $actual   = Str::upper('hello');
        $I->assertEquals($expected, $actual);

        $expected = 'HELLO';
        $actual   = Str::upper('HELLO');
        $I->assertEquals($expected, $actual);

        $expected = '1234';
        $actual   = Str::upper('1234');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: upper() - multi-bytes encoding
     *
     * @param UnitTester $I
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-05-06
     */
    public function helperStrUpperMultiBytesEncoding(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - upper() - multi byte encoding');
        $expected = 'ПРИВЕТ МИР!';
        $actual   = Str::upper('ПРИВЕТ МИР!');
        $I->assertEquals($expected, $actual);

        $expected = 'ПРИВЕТ МИР!';
        $actual   = Str::upper('ПриВЕт Мир!');
        $I->assertEquals($expected, $actual);

        $expected = 'ПРИВЕТ МИР!';
        $actual   = Str::upper('привет мир!');
        $I->assertEquals($expected, $actual);

        $expected = 'MÄNNER';
        $actual   = Str::upper('MÄNNER');
        $I->assertEquals($expected, $actual);

        $expected = 'MÄNNER';
        $actual   = Str::upper('mÄnnER');
        $I->assertEquals($expected, $actual);

        $expected = 'MÄNNER';
        $actual   = Str::upper('männer');
        $I->assertEquals($expected, $actual);
    }
}
