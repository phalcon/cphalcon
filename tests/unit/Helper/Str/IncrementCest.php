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

namespace Phalcon\Test\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

class IncrementCest
{
    /**
     * Tests Phalcon\Helper\Str :: increment() - string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrIncrementSimpleString(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - increment() - string');
        $source   = 'file';
        $expected = 'file_1';
        $actual   = Str::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: increment() - already incremented string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrIncrementAlreadyIncremented(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - increment() - already incremented string');
        $source   = 'file_1';
        $expected = 'file_2';
        $actual   = Str::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: increment() - already incremented string
     * twice
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrIncrementAlreadyIncrementedTwice(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - increment() - already incremented string twice');
        $source   = 'file_2';
        $expected = 'file_3';
        $actual   = Str::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: increment() - string with underscore
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrIncrementStringWithUnderscore(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - increment() - string with underscore');
        $source   = 'file_';
        $expected = 'file_1';
        $actual   = Str::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: increment() - string with a space at the end
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrIncrementStringWithSpace(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - increment() - string with a space at the end');
        $source   = 'file ';
        $expected = 'file _1';
        $actual   = Str::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: increment() - different separator
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrIncrementStringWithDifferentSeparator(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - increment() - string with different separator');
        $source   = 'file';
        $expected = 'file-1';
        $actual   = Str::increment($source, '-');
        $I->assertEquals($expected, $actual);
    }
}
