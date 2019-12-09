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

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use UnitTester;

class StartsWithCest
{
    /**
     * Tests Phalcon\Text :: startsWith()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textStartsWith(UnitTester $I)
    {
        $I->wantToTest('Text - startsWith()');

        $I->assertTrue(
            Text::startsWith('Hello', 'H')
        );

        $I->assertTrue(
            Text::startsWith('Hello', 'He')
        );

        $I->assertTrue(
            Text::startsWith('Hello', 'Hello')
        );
    }

    /**
     * Tests Phalcon\Text :: startsWith() - empty strings
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textStartsWithEmpty(UnitTester $I)
    {
        $I->wantToTest('Text - startsWith() - empty strings');

        $I->assertFalse(
            Text::startsWith('', '')
        );
    }

    /**
     * Tests Phalcon\Text :: startsWith() - finding an empty string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textStartsWithEmptySearchString(UnitTester $I)
    {
        $I->wantToTest('Text - startsWith() - search empty string');

        $I->assertFalse(
            Text::startsWith('', 'hello')
        );
    }


    /**
     * Tests Phalcon\Text :: startsWith() - case insensitive flag
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textStartsWithCaseInsensitive(UnitTester $I)
    {
        $I->wantToTest('Text - startsWith() - case insensitive flag');

        $I->assertTrue(
            Text::startsWith('Hello', 'h')
        );

        $I->assertTrue(
            Text::startsWith('Hello', 'he')
        );

        $I->assertTrue(
            Text::startsWith('Hello', 'hello')
        );
    }

    /**
     * Tests Phalcon\Text :: startsWith() - case sensitive flag
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textStartsWithCaseSensitive(UnitTester $I)
    {
        $I->wantToTest('Text - startsWith() - case sensitive flag');

        $I->assertTrue(
            Text::startsWith('Hello', 'hello', true)
        );

        $I->assertFalse(
            Text::startsWith('Hello', 'hello', false)
        );

        $I->assertFalse(
            Text::startsWith('Hello', 'h', false)
        );
    }
}
