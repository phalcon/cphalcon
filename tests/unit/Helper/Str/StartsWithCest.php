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
 * Class StartsWithCest
 */
class StartsWithCest
{
    /**
     * Tests Phalcon\Helper\Str :: startsWith()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textStartsWith(UnitTester $I)
    {
        $I->wantToTest('Text - startsWith()');
        $actual = Str::startsWith("Hello", "H");
        $I->assertTrue($actual);

        $actual = Str::startsWith("Hello", "He");
        $I->assertTrue($actual);

        $actual = Str::startsWith("Hello", "Hello");
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: startsWith() - empty strings
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textStartsWithEmpty(UnitTester $I)
    {
        $I->wantToTest('Text - startsWith() - empty strings');
        $actual = Str::startsWith("", "");
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: startsWith() - finding an empty string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textStartsWithEmptySearchString(UnitTester $I)
    {
        $I->wantToTest('Text - startsWith() - search empty string');
        $actual = Str::startsWith("", "hello");
        $I->assertFalse($actual);
    }


    /**
     * Tests Phalcon\Helper\Str :: startsWith() - case insensitive flag
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textStartsWithCaseInsensitive(UnitTester $I)
    {
        $I->wantToTest('Text - startsWith() - case insensitive flag');
        $actual = Str::startsWith("Hello", "h");
        $I->assertTrue($actual);

        $actual = Str::startsWith("Hello", "he");
        $I->assertTrue($actual);

        $actual = Str::startsWith("Hello", "hello");
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: startsWith() - case sensitive flag
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textStartsWithCaseSensitive(UnitTester $I)
    {
        $I->wantToTest('Text - startsWith() - case sensitive flag');
        $actual = Str::startsWith("Hello", "hello", true);
        $I->assertTrue($actual);

        $actual = Str::startsWith("Hello", "hello", false);
        $I->assertFalse($actual);

        $actual = Str::startsWith("Hello", "h", false);
        $I->assertFalse($actual);
    }
}
