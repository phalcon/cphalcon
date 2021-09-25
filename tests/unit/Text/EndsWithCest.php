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

namespace Phalcon\Tests\Unit\Text;

use Phalcon\Text;
use UnitTester;

class EndsWithCest
{
    /**
     * Tests Phalcon\Text :: endsWith()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textEndsWith(UnitTester $I)
    {
        $I->wantToTest('Text - endsWith()');

        $I->assertTrue(
            Text::endsWith('Hello', 'o')
        );

        $I->assertTrue(
            Text::endsWith('Hello', 'lo')
        );

        $I->assertTrue(
            Text::endsWith('Hello', 'Hello')
        );
    }

    /**
     * Tests Phalcon\Text :: endsWith() - empty strings
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textEndsWithEmpty(UnitTester $I)
    {
        $I->wantToTest('Text - endsWith() - empty strings');

        $I->assertFalse(
            Text::endsWith('', '')
        );
    }

    /**
     * Tests Phalcon\Text :: endsWith() - finding an empty string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textEndsWithEmptySearchString(UnitTester $I)
    {
        $I->wantToTest('Text - endsWith() - search empty string');

        $I->assertFalse(
            Text::endsWith('', 'hello')
        );
    }


    /**
     * Tests Phalcon\Text :: endsWith() - case insensitive flag
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textEndsWithCaseInsensitive(UnitTester $I)
    {
        $I->wantToTest('Text - endsWith() - case insensitive flag');

        $I->assertTrue(
            Text::endsWith('Hello', 'O')
        );

        $I->assertTrue(
            Text::endsWith('Hello', 'LO')
        );

        $I->assertTrue(
            Text::endsWith('Hello', 'hello')
        );
    }

    /**
     * Tests Phalcon\Text :: endsWith() - case sensitive flag
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textEndsWithCaseSensitive(UnitTester $I)
    {
        $I->wantToTest('Text - endsWith() - case sensitive flag');

        $I->assertTrue(
            Text::endsWith('Hello', 'hello', true)
        );

        $I->assertFalse(
            Text::endsWith('Hello', 'hello', false)
        );

        $I->assertFalse(
            Text::endsWith('Hello', 'O', false)
        );
    }
}
