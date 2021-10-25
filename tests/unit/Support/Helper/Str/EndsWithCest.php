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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Phalcon\Support\Helper\Str\EndsWith;
use UnitTester;

/**
 * Class EndsWithCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class EndsWithCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: endsWith()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrEndsWith(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - endsWith()');

        $object = new EndsWith();
        $actual = $object('Hello', 'o');
        $I->assertTrue($actual);

        $actual = $object('Hello', 'lo');
        $I->assertTrue($actual);

        $actual = $object('Hello', 'Hello');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Str :: endsWith() - empty strings
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrEndsWithEmpty(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - endsWith() - empty strings');

        $object = new EndsWith();
        $actual = $object('', '');
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Str :: endsWith() - finding an empty string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrEndsWithEmptySearchString(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - endsWith() - search empty string');

        $object = new EndsWith();
        $actual = $object('', 'hello');
        $I->assertFalse($actual);
    }


    /**
     * Tests Phalcon\Support\Helper\Str :: endsWith() - case insensitive flag
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrEndsWithCaseInsensitive(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - endsWith() - case insensitive flag');

        $object = new EndsWith();
        $actual = $object('Hello', 'O');
        $I->assertTrue($actual);

        $actual = $object('Hello', 'LO');
        $I->assertTrue($actual);

        $actual = $object('Hello', 'hello');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Str :: endsWith() - case sensitive flag
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrEndsWithCaseSensitive(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - endsWith() - case sensitive flag');

        $object = new EndsWith();
        $actual = $object('Hello', 'hello', true);
        $I->assertTrue($actual);

        $actual = $object('Hello', 'hello', false);
        $I->assertFalse($actual);

        $actual = $object('Hello', 'O', false);
        $I->assertFalse($actual);
    }
}
