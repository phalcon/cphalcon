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

class EndsWithCest
{
    /**
     * Tests Phalcon\Text :: endsWith()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textEndsWith(UnitTester $I)
    {
        $actual = Text::endsWith("Hello", "o");
        $I->assertTrue($actual);

        $actual = Text::endsWith("Hello", "lo");
        $I->assertTrue($actual);

        $actual = Text::endsWith("Hello", "Hello");
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Text :: endsWith() - empty strings
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textEndsWithEmpty(UnitTester $I)
    {
        $actual = Text::endsWith("", "");
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Text :: endsWith() - finding an empty string
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textEndsWithEmptySearchString(UnitTester $I)
    {
        $actual = Text::endsWith("", "hello");
        $I->assertFalse($actual);
    }


    /**
     * Tests Phalcon\Text :: endsWith() - case insensitive flag
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textEndsWithCaseInsensitive(UnitTester $I)
    {
        $actual = Text::endsWith("Hello", "O");
        $I->assertTrue($actual);

        $actual = Text::endsWith("Hello", "LO");
        $I->assertTrue($actual);

        $actual = Text::endsWith("Hello", "hello");
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Text :: endsWith() - case sensitive flag
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textEndsWithCaseSensitive(UnitTester $I)
    {
        $actual = Text::endsWith("Hello", "hello", true);
        $I->assertTrue($actual);

        $actual = Text::endsWith("Hello", "hello", false);
        $I->assertFalse($actual);

        $actual = Text::endsWith("Hello", "O", false);
        $I->assertFalse($actual);
    }
}
