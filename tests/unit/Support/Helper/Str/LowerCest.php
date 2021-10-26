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

use Phalcon\Support\Helper\Str\Lower;
use UnitTester;

/**
 * Class LowerCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class LowerCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: lower()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrLower(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - lower()');

        $object = new Lower();

        $expected = 'hello';
        $actual   = $object('hello');
        $I->assertEquals($expected, $actual);

        $expected = 'hello';
        $actual   = $object('HELLO');
        $I->assertEquals($expected, $actual);

        $expected = '1234';
        $actual   = $object('1234');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Str :: lower() - multi-bytes encoding
     *
     * @param UnitTester $I
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-05-06
     */
    public function supportHelperStrLowerMultiBytesEncoding(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - lower() - multi byte encoding');

        $object = new Lower();

        $expected = 'привет мир!';
        $actual   = $object('привет мир!');
        $I->assertEquals($expected, $actual);

        $expected = 'привет мир!';
        $actual   = $object('ПриВЕт Мир!');
        $I->assertEquals($expected, $actual);

        $expected = 'привет мир!';
        $actual   = $object('ПРИВЕТ МИР!');
        $I->assertEquals($expected, $actual);


        $expected = 'männer';
        $actual   = $object('männer');
        $I->assertEquals($expected, $actual);

        $expected = 'männer';
        $actual   = $object('mÄnnER');
        $I->assertEquals($expected, $actual);

        $expected = 'männer';
        $actual   = $object('MÄNNER');
        $I->assertEquals($expected, $actual);
    }
}
