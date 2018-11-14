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

class IncrementCest
{
    /**
     * Tests Phalcon\Text :: increment() - string
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testIncrementSimpleString(UnitTester $I)
    {
        $source   = 'file';
        $expected = 'file_1';
        $actual   = Text::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Text :: increment() - already incremented string
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testIncrementAlreadyIncremented(UnitTester $I)
    {
        $source   = 'file_1';
        $expected = 'file_2';
        $actual   = Text::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Text :: increment() - already incremented string twice
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testIncrementAlreadyIncrementedTwice(UnitTester $I)
    {
        $source   = 'file_2';
        $expected = 'file_3';
        $actual   = Text::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Text :: increment() - string with underscore
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testIncrementStringWithUnderscore(UnitTester $I)
    {
        $source   = 'file_';
        $expected = 'file_1';
        $actual   = Text::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Text :: increment() - string with a space at the end
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testIncrementStringWithSpace(UnitTester $I)
    {
        $source   = 'file ';
        $expected = 'file _1';
        $actual   = Text::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Text :: increment() - different separator
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testIncrementStringWithDifferentSeparator(UnitTester $I)
    {
        $source   = 'file';
        $expected = 'file-1';
        $actual   = Text::increment($source, '-');
        $I->assertEquals($expected, $actual);
    }
}
