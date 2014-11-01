<?php
/**
 * TextStartsWithTest.php
 * \Phalcon\Text\TextStartsWithTest
 *
 * Tests the Phalcon\Text component
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

namespace Phalcon\Tests\unit\Phalcon\Text;

use \PhalconTest\Text as PhTText;

class TextStartsWithTest extends Helper\TextBase
{
    /**
     * Tests the startsWith function with empty strings
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextStartsWithEmpty()
    {
        $this->specify(
            "startsWith does not return correct result with empty strings",
            function () {
                $actual = PhTText::startsWith("", "");
                expect($actual)->false();
            }
        );
    }

    /**
     * Tests the startsWith function finding an empty string
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextStartsWithEmptySearchString()
    {
        $this->specify(
            "startsWith does not return correct result with empty/something string",
            function () {
                $actual = PhTText::startsWith("", "hello");
                expect($actual)->false();
            }
        );
    }

    /**
     * Tests the startsWith function
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextStartsWith()
    {
        $this->specify(
            "startsWith does not return correct result with matched strings",
            function () {
                $actual = PhTText::startsWith("Hello", "H");
                expect($actual)->true();

                $actual = PhTText::startsWith("Hello", "He");
                expect($actual)->true();

                $actual = PhTText::startsWith("Hello", "Hello");
                expect($actual)->true();
            }
        );
    }

    /**
     * Tests the startsWith function with case insensitive flag
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextStartsWithCaseInsensitive()
    {
        $this->specify(
            "startsWith does not return correct result with case insensitive string",
            function () {
                $actual = PhTText::startsWith("Hello", "h");
                expect($actual)->true();

                $actual = PhTText::startsWith("Hello", "he");
                expect($actual)->true();

                $actual = PhTText::startsWith("Hello", "hello");
                expect($actual)->true();
            }
        );
    }

    /**
     * Tests the startsWith function with case sensitive flag
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextStartsWithCaseSensitive()
    {
        $this->specify(
            "startsWith does not return correct result with case sensitivity",
            function () {
                $actual = PhTText::startsWith("Hello", "hello", true);
                expect($actual)->true();

                $actual = PhTText::startsWith("Hello", "hello", false);
                expect($actual)->false();

                $actual = PhTText::startsWith("Hello", "h", false);
                expect($actual)->false();
            }
        );
    }
}
