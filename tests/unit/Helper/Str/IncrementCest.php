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
 * Class IncrementCest
 */
class IncrementCest
{
    /**
     * Tests Phalcon\Helper\Str :: increment() - string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textIncrementSimpleString(UnitTester $I)
    {
        $I->wantToTest('Text - increment() - string');
        $source   = 'file';
        $expected = 'file_1';
        $actual   = Str::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: increment() - already incremented string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textIncrementAlreadyIncremented(UnitTester $I)
    {
        $I->wantToTest('Text - increment() - already incremented string');
        $source   = 'file_1';
        $expected = 'file_2';
        $actual   = Str::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: increment() - already incremented string twice
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textIncrementAlreadyIncrementedTwice(UnitTester $I)
    {
        $I->wantToTest('Text - increment() - already incremented string twice');
        $source   = 'file_2';
        $expected = 'file_3';
        $actual   = Str::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: increment() - string with underscore
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textIncrementStringWithUnderscore(UnitTester $I)
    {
        $I->wantToTest('Text - increment() - string with underscore');
        $source   = 'file_';
        $expected = 'file_1';
        $actual   = Str::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: increment() - string with a space at the end
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textIncrementStringWithSpace(UnitTester $I)
    {
        $I->wantToTest('Text - increment() - string with a space at the end');
        $source   = 'file ';
        $expected = 'file _1';
        $actual   = Str::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: increment() - different separator
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textIncrementStringWithDifferentSeparator(UnitTester $I)
    {
        $I->wantToTest('Text - increment() - string with different separator');
        $source   = 'file';
        $expected = 'file-1';
        $actual   = Str::increment($source, '-');
        $I->assertEquals($expected, $actual);
    }
}
