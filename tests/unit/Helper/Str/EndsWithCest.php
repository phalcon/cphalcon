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

namespace Phalcon\Tests\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

class EndsWithCest
{
    /**
     * Tests Phalcon\Helper\Str :: endsWith()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrEndsWith(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - endsWith()');
        $actual = Str::endsWith('Hello', 'o');
        $I->assertTrue($actual);

        $actual = Str::endsWith('Hello', 'lo');
        $I->assertTrue($actual);

        $actual = Str::endsWith('Hello', 'Hello');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: endsWith() - empty strings
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrEndsWithEmpty(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - endsWith() - empty strings');
        $actual = Str::endsWith('', '');
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: endsWith() - finding an empty string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrEndsWithEmptySearchString(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - endsWith() - search empty string');
        $actual = Str::endsWith('', 'hello');
        $I->assertFalse($actual);
    }


    /**
     * Tests Phalcon\Helper\Str :: endsWith() - case insensitive flag
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrEndsWithCaseInsensitive(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - endsWith() - case insensitive flag');
        $actual = Str::endsWith('Hello', 'O');
        $I->assertTrue($actual);

        $actual = Str::endsWith('Hello', 'LO');
        $I->assertTrue($actual);

        $actual = Str::endsWith('Hello', 'hello');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: endsWith() - case sensitive flag
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrEndsWithCaseSensitive(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - endsWith() - case sensitive flag');
        $actual = Str::endsWith('Hello', 'hello', true);
        $I->assertTrue($actual);

        $actual = Str::endsWith('Hello', 'hello', false);
        $I->assertFalse($actual);

        $actual = Str::endsWith('Hello', 'O', false);
        $I->assertFalse($actual);
    }
}
