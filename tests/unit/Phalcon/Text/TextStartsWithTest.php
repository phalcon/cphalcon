<?php
/**
 * TextStartsWithTest.php
 * \Phalcon\Text\TextStartsWithTest
 *
 * Tests the Phalcon\Text component
 *
 * PhalconPHP Framework
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

use Phalcon\Text as PhText;

class TextStartsWithTest extends \Codeception\TestCase\Test
{
    use \Codeception\Specify;

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
                $actual = PhText::startsWith("", "");
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
                $actual = PhText::startsWith("", "hello");
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
                $actual = PhText::startsWith("Hello", "H");
                expect($actual)->true();

                $actual = PhText::startsWith("Hello", "He");
                expect($actual)->true();

                $actual = PhText::startsWith("Hello", "Hello");
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
                $actual = PhText::startsWith("Hello", "h");
                expect($actual)->true();

                $actual = PhText::startsWith("Hello", "he");
                expect($actual)->true();

                $actual = PhText::startsWith("Hello", "hello");
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
                $actual = PhText::startsWith("Hello", "hello", true);
                expect($actual)->true();

                $actual = PhText::startsWith("Hello", "hello", false);
                expect($actual)->false();

                $actual = PhText::startsWith("Hello", "h", false);
                expect($actual)->false();
            }
        );
    }
}