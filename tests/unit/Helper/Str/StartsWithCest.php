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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrStartsWith(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - startsWith()');
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrStartsWithEmpty(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - startsWith() - empty strings');
        $actual = Str::startsWith("", "");
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: startsWith() - finding an empty string
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrStartsWithEmptySearchString(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - startsWith() - search empty string');
        $actual = Str::startsWith("", "hello");
        $I->assertFalse($actual);
    }


    /**
     * Tests Phalcon\Helper\Str :: startsWith() - case insensitive flag
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrStartsWithCaseInsensitive(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - startsWith() - case insensitive flag');
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrStartsWithCaseSensitive(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - startsWith() - case sensitive flag');
        $actual = Str::startsWith("Hello", "hello", true);
        $I->assertTrue($actual);

        $actual = Str::startsWith("Hello", "hello", false);
        $I->assertFalse($actual);

        $actual = Str::startsWith("Hello", "h", false);
        $I->assertFalse($actual);
    }
}
