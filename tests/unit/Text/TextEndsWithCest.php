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

class TextEndsWithCest
{
    /**
     * Tests the endsWith function with empty strings
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextEndsWithEmpty(UnitTester $I)
    {
        $actual = Text::endsWith("", "");
        $I->assertFalse($actual);
    }

    /**
     * Tests the endsWith function with empty search string
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextEndsWithEmptySearchString(UnitTester $I)
    {
        $actual = Text::endsWith("", "hello");
        $I->assertFalse($actual);
    }

    /**
     * Tests the endsWith function
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextEndsWith(UnitTester $I)
    {
        $actual = Text::endsWith("Hello", "o");
        $I->assertTrue($actual);

        $actual = Text::endsWith("Hello", "lo");
        $I->assertTrue($actual);

        $actual = Text::endsWith("Hello", "Hello");
        $I->assertTrue($actual);
    }

    /**
     * Tests the endsWith function with case insensitive flag
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextEndsWithCaseInsensitive(UnitTester $I)
    {
        $actual = Text::endsWith("Hello", "O");
        $I->assertTrue($actual);

        $actual = Text::endsWith("Hello", "LO");
        $I->assertTrue($actual);

        $actual = Text::endsWith("Hello", "hello");
        $I->assertTrue($actual);
    }

    /**
     * Tests the endsWith function with case sensitive flage
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextEndsWithCaseSensitive(UnitTester $I)
    {
        $actual = Text::endsWith("Hello", "hello", true);
        $I->assertTrue($actual);

        $actual = Text::endsWith("Hello", "hello", false);
        $I->assertFalse($actual);

        $actual = Text::endsWith("Hello", "O", false);
        $I->assertFalse($actual);
    }
}
