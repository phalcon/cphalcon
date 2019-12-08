<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

class DecrementCest
{
    /**
     * Tests Phalcon\Helper\Str :: decrement() - string
     *
     * @author Ruud Boon <https://github.com/ruudboon>
     * @since  2019-12-08
     */
    public function helperStrDecrementSimpleString(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - decrement() - string');
        $source   = 'file_2';
        $expected = 'file_1';
        $actual   = Str::decrement($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: decrement() - already decremented string
     *
     * @author Ruud Boon <https://github.com/ruudboon>
     * @since  2019-12-08
     */
    public function helperStrDecrementAlreadyDecremented(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - decrement() - already decremented string');
        $source   = 'file_1';
        $expected = 'file';
        $actual   = Str::decrement($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: decrement() - already decremented string
     * twice
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrDecrementAlreadyDecrementedTwice(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - decrement() - already decremented string twice');
        $source   = 'file_3';
        $expected = 'file_2';
        $actual   = Str::decrement($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: decrement() - string with underscore
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrDecrementStringWithUnderscore(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - decrement() - string with underscore');
        $source   = 'file_';
        $expected = 'file';
        $actual   = Str::decrement($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: decrement() - string with a space at the end
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrDecrementStringWithSpace(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - decrement() - string with a space at the end');
        $source   = 'file _1';
        $expected = 'file ';
        $actual   = Str::decrement($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: decrement() - different separator
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrDecrementStringWithDifferentSeparator(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - decrement() - string with different separator');
        $source   = 'file-1';
        $expected = 'file';
        $actual   = Str::decrement($source, '-');
        $I->assertEquals($expected, $actual);
    }
}
