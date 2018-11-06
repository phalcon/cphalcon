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

class TextStartsWithCest
{
    /**
     * Tests the startsWith function with empty strings
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextStartsWithEmpty(UnitTester $I)
    {
        $actual = Text::startsWith("", "");
        $I->assertFalse($actual);
    }

    /**
     * Tests the startsWith function finding an empty string
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextStartsWithEmptySearchString(UnitTester $I)
    {
        $actual = Text::startsWith("", "hello");
        $I->assertFalse($actual);
    }

    /**
     * Tests the startsWith function
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextStartsWith(UnitTester $I)
    {
        $actual = Text::startsWith("Hello", "H");
        $I->assertTrue($actual);

        $actual = Text::startsWith("Hello", "He");
        $I->assertTrue($actual);

        $actual = Text::startsWith("Hello", "Hello");
        $I->assertTrue($actual);
    }

    /**
     * Tests the startsWith function with case insensitive flag
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextStartsWithCaseInsensitive(UnitTester $I)
    {
        $actual = Text::startsWith("Hello", "h");
        $I->assertTrue($actual);

        $actual = Text::startsWith("Hello", "he");
        $I->assertTrue($actual);

        $actual = Text::startsWith("Hello", "hello");
        $I->assertTrue($actual);
    }

    /**
     * Tests the startsWith function with case sensitive flag
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextStartsWithCaseSensitive(UnitTester $I)
    {
        $actual = Text::startsWith("Hello", "hello", true);
        $I->assertTrue($actual);

        $actual = Text::startsWith("Hello", "hello", false);
        $I->assertFalse($actual);

        $actual = Text::startsWith("Hello", "h", false);
        $I->assertFalse($actual);
    }
}
