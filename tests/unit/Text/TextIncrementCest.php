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

class TextIncrementCest
{
    /**
     * Tests the increment function
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextIncrementSimpleString(UnitTester $I)
    {
        $source   = 'file';
        $expected = 'file_1';
        $actual   = Text::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the increment function with an already incremented string
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextIncrementAlreadyIncremented(UnitTester $I)
    {
        $source   = 'file_1';
        $expected = 'file_2';
        $actual   = Text::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the increment function for an already incremented string twice
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextIncrementAlreadyIncrementedTwice(UnitTester $I)
    {
        $source   = 'file_2';
        $expected = 'file_3';
        $actual   = Text::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the increment function for a string with underscore
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextIncrementStringWithUnderscore(UnitTester $I)
    {
        $source   = 'file_';
        $expected = 'file_1';
        $actual   = Text::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the increment function for a string with a space at the end
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextIncrementStringWithSpace(UnitTester $I)
    {
        $source   = 'file ';
        $expected = 'file _1';
        $actual   = Text::increment($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the increment function with a different separator
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextIncrementStringWithDifferentSeparator(UnitTester $I)
    {
        $source   = 'file';
        $expected = 'file-1';
        $actual   = Text::increment($source, '-');
        $I->assertEquals($expected, $actual);
    }
}
