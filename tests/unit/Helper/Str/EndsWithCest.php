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
 * Class EndsWithCest
 */
class EndsWithCest
{
    /**
     * Tests Phalcon\Helper\Str :: endsWith()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textEndsWith(UnitTester $I)
    {
        $I->wantToTest('Text - endsWith()');
        $actual = Str::endsWith("Hello", "o");
        $I->assertTrue($actual);

        $actual = Str::endsWith("Hello", "lo");
        $I->assertTrue($actual);

        $actual = Str::endsWith("Hello", "Hello");
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: endsWith() - empty strings
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textEndsWithEmpty(UnitTester $I)
    {
        $I->wantToTest('Text - endsWith() - empty strings');
        $actual = Str::endsWith("", "");
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: endsWith() - finding an empty string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textEndsWithEmptySearchString(UnitTester $I)
    {
        $I->wantToTest('Text - endsWith() - search empty string');
        $actual = Str::endsWith("", "hello");
        $I->assertFalse($actual);
    }


    /**
     * Tests Phalcon\Helper\Str :: endsWith() - case insensitive flag
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textEndsWithCaseInsensitive(UnitTester $I)
    {
        $I->wantToTest('Text - endsWith() - case insensitive flag');
        $actual = Str::endsWith("Hello", "O");
        $I->assertTrue($actual);

        $actual = Str::endsWith("Hello", "LO");
        $I->assertTrue($actual);

        $actual = Str::endsWith("Hello", "hello");
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: endsWith() - case sensitive flag
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textEndsWithCaseSensitive(UnitTester $I)
    {
        $I->wantToTest('Text - endsWith() - case sensitive flag');
        $actual = Str::endsWith("Hello", "hello", true);
        $I->assertTrue($actual);

        $actual = Str::endsWith("Hello", "hello", false);
        $I->assertFalse($actual);

        $actual = Str::endsWith("Hello", "O", false);
        $I->assertFalse($actual);
    }
}
