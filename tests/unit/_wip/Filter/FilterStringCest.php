<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Filter;

use Phalcon\Filter;
use Phalcon\Test\Unit\Filter\Helper\FilterBase;
use UnitTester;

class FilterStringCest extends FilterBase
{
    /**
     * Tests the filter with a string (US characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringStringFilter(UnitTester $I)
    {
        $value    = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>';
        $expected = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
        $this->sanitizer($I, 'string', $expected, $value);
    }

    /**
     * Tests the filter with a string with french quotes
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringStringFrenchQuotesFilter(UnitTester $I)
    {
        $value    = "{[<within french quotes>]}";
        $expected = '{[]}';
        $this->sanitizer($I, 'string', $expected, $value);
    }

    /**
     * Tests the filter with a string (International characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringUTF8StringFilter(UnitTester $I)
    {
        $value    = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>';
        $expected = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
        $this->sanitizer($I, 'string', $expected, $value);

        $value    = '{[<buenos días 123 καλημέρα! 早安>]}';
        $expected = '{[]}';
        $this->sanitizer($I, 'string', $expected, $value);
    }

    /**
     * Tests the filter with an array filter (US characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringArrayFilter(UnitTester $I)
    {
        $value    = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>';
        $expected = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
        $this->sanitizer($I, ['string'], $expected, $value);
    }

    /**
     * Tests the filter with an array filter (International characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringUTF8ArrayFilter(UnitTester $I)
    {
        $value    = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>';
        $expected = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
        $this->sanitizer($I, ['string'], $expected, $value);
    }

    /**
     * Tests the filter with a string (no filtering) (US characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringStringFilterValidString(UnitTester $I)
    {
        $value    = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
        $expected = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
        $this->sanitizer($I, 'string', $expected, $value);
    }

    /**
     * Tests the filter with a string (no filtering) (International characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringUTF8StringFilterValidString(UnitTester $I)
    {
        $value    = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
        $expected = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
        $this->sanitizer($I, 'string', $expected, $value);
    }

    /**
     * Tests the filter with an array filter (no filtering) (US characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeArrayFilterValidString(UnitTester $I)
    {
        $value    = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
        $expected = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
        $this->sanitizer($I, ['string'], $expected, $value);
    }

    /**
     * Tests the filter with an array filter (no filtering)
     * (International characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeUTF8ArrayFilterValidStringNoFilter(UnitTester $I)
    {
        $value    = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
        $expected = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
        $this->sanitizer($I, ['string'], $expected, $value);
    }
}
