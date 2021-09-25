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

use Phalcon\Helper\Str;
use UnitTester;

class LowerCest
{
    /**
     * Tests Phalcon\Helper\Str :: lower()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrLower(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - lower()');
        $expected = 'hello';
        $actual   = Str::lower('hello');
        $I->assertEquals($expected, $actual);

        $expected = 'hello';
        $actual   = Str::lower('HELLO');
        $I->assertEquals($expected, $actual);

        $expected = '1234';
        $actual   = Str::lower('1234');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: lower() - multi-bytes encoding
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-05-06
     */
    public function helperStrLowerMultiBytesEncoding(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - lower() - multi byte encoding');
        $expected = 'привет мир!';
        $actual   = Str::lower('привет мир!');
        $I->assertEquals($expected, $actual);

        $expected = 'привет мир!';
        $actual   = Str::lower('ПриВЕт Мир!');
        $I->assertEquals($expected, $actual);

        $expected = 'привет мир!';
        $actual   = Str::lower('ПРИВЕТ МИР!');
        $I->assertEquals($expected, $actual);


        $expected = 'männer';
        $actual   = Str::lower('männer');
        $I->assertEquals($expected, $actual);

        $expected = 'männer';
        $actual   = Str::lower('mÄnnER');
        $I->assertEquals($expected, $actual);

        $expected = 'männer';
        $actual   = Str::lower('MÄNNER');
        $I->assertEquals($expected, $actual);
    }
}
