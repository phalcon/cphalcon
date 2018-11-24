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

class StartsWithCest
{
    /**
     * Tests Phalcon\Text :: startsWith()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textStartsWith(UnitTester $I)
    {
        $actual = Text::startsWith("Hello", "H");
        $I->assertTrue($actual);

        $actual = Text::startsWith("Hello", "He");
        $I->assertTrue($actual);

        $actual = Text::startsWith("Hello", "Hello");
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Text :: startsWith() - empty strings
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textStartsWithEmpty(UnitTester $I)
    {
        $actual = Text::startsWith("", "");
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Text :: startsWith() - finding an empty string
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textStartsWithEmptySearchString(UnitTester $I)
    {
        $actual = Text::startsWith("", "hello");
        $I->assertFalse($actual);
    }


    /**
     * Tests Phalcon\Text :: startsWith() - case insensitive flag
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textStartsWithCaseInsensitive(UnitTester $I)
    {
        $actual = Text::startsWith("Hello", "h");
        $I->assertTrue($actual);

        $actual = Text::startsWith("Hello", "he");
        $I->assertTrue($actual);

        $actual = Text::startsWith("Hello", "hello");
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Text :: startsWith() - case sensitive flag
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textStartsWithCaseSensitive(UnitTester $I)
    {
        $actual = Text::startsWith("Hello", "hello", true);
        $I->assertTrue($actual);

        $actual = Text::startsWith("Hello", "hello", false);
        $I->assertFalse($actual);

        $actual = Text::startsWith("Hello", "h", false);
        $I->assertFalse($actual);
    }
}
