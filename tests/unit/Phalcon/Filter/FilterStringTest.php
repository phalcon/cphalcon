<?php
/**
 * FilterStringTest.php
 * \Phalcon\Text\FilterStringTest
 *
 * Tests the Phalcon\Filter component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Filter;

class FilterStringTest extends Helper\FilterBase
{
    /**
     * Tests the filter with a string (US characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringStringFilter()
    {
        $this->specify(
            "sanitize string with latin characters does not return correct data",
            function () {
                $value    = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>';
                $expected = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
                $this->sanitizer('string', $expected, $value);
            }
        );
    }

    /**
     * Tests the filter with a string with french quotes
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringStringFrenchQuotesFilter()
    {
        $this->specify(
            "sanitize string with latin characters does not return correct data",
            function () {
                $value    = "{[<within french quotes>]}";
                $expected = '{[]}';
                $this->sanitizer('string', $expected, $value);
            }
        );
    }

    /**
     * Tests the filter with a string (International characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringUTF8StringFilter()
    {
        $this->specify(
            "sanitize string with international characters does not return correct data",
            function () {

                $value    = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>';
                $expected = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
                $this->sanitizer('string', $expected, $value);

                $value    = '{[<buenos días 123 καλημέρα! 早安>]}';
                $expected = '{[]}';
                $this->sanitizer('string', $expected, $value);

            }
        );
    }

    /**
     * Tests the filter with an array filter (US characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringArrayFilter()
    {
        $this->specify(
            "sanitize string with array latin characters characters does not return correct data",
            function () {
                $value    = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>';
                $expected = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
                $this->sanitizer(['string'], $expected, $value);
            }
        );
    }

    /**
     * Tests the filter with an array filter (International characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringUTF8ArrayFilter()
    {
        $this->specify(
            "sanitize string with array international characters characters does not return correct data",
            function () {
                $value    = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>';
                $expected = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
                $this->sanitizer(['string'], $expected, $value);
            }
        );
    }

    /**
     * Tests the filter with a string (no filtering) (US characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringStringFilterValidString()
    {
        $this->specify(
            "sanitize string with a valid latin string does not return correct data",
            function () {
                $value    = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
                $expected = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
                $this->sanitizer('string', $expected, $value);
            }
        );
    }

    /**
     * Tests the filter with a string (no filtering) (International characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringUTF8StringFilterValidString()
    {
        $this->specify(
            "sanitize string with a valid international string does not return correct data",
            function () {
                $value    = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
                $expected = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
                $this->sanitizer('string', $expected, $value);
            }
        );
    }

    /**
     * Tests the filter with an array filter (no filtering) (US characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeArrayFilterValidString()
    {
        $this->specify(
            "sanitize string array with a valid latin string does not return correct data",
            function () {
                $value    = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
                $expected = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
                $this->sanitizer(['string'], $expected, $value);
            }
        );
    }

    /**
     * Tests the filter with an array filter (no filtering)
     * (International characters)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeUTF8ArrayFilterValidStringNoFilter()
    {
        $this->specify(
            "sanitize string array with a valid latin string does not return correct data",
            function () {
                $value    = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
                $expected = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
                $this->sanitizer(['string'], $expected, $value);
            }
        );
    }
}
