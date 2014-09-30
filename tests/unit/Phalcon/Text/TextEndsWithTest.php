<?php
/**
 * TextEndsWithTest.php
 * \Phalcon\Text\TextEndsWithTest
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

class TextEndsWithTest extends \Codeception\TestCase\Test
{
    use \Codeception\Specify;


    /**
     * Tests the endsWith function with empty strings
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextEndsWithEmpty()
    {
        $this->specify(
            "endsWith does not return correct result with empty strings",
            function () {
                $actual = PhText::endsWith("", "");
                expect($actual)->false();
            }
        );
    }

    /**
     * Tests the endsWith function with empty search string
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextEndsWithEmptySearchString()
    {
        $this->specify(
            "endsWith does not return correct result with empty/something string",
            function () {
                $actual = PhText::endsWith("", "hello");
                expect($actual)->false();
            }
        );
    }

    /**
     * Tests the endsWith function
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextEndsWith()
    {
        $this->specify(
            "endsWith does not return correct result with matched strings",
            function () {
                $actual = PhText::endsWith("Hello", "o");
                expect($actual)->true();

                $actual = PhText::endsWith("Hello", "lo");
                expect($actual)->true();

                $actual = PhText::endsWith("Hello", "Hello");
                expect($actual)->true();
            }
        );
    }

    /**
     * Tests the endsWith function with case insensitive flag
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextEndsWithCaseInsensitive()
    {
        $this->specify(
            "endsWith does not return correct result with case insensitive string",
            function () {
                $actual = PhText::endsWith("Hello", "O");
                expect($actual)->true();

                $actual = PhText::endsWith("Hello", "LO");
                expect($actual)->true();

                $actual = PhText::endsWith("Hello", "hello");
                expect($actual)->true();
            }
        );
    }

    /**
     * Tests the endsWith function with case sensitive flage
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextEndsWithCaseSensitive()
    {
        $this->specify(
            "endsWith does not return correct result with case sensitivity",
            function () {
                $actual = PhText::endsWith("Hello", "hello", true);
                expect($actual)->true();

                $actual = PhText::endsWith("Hello", "hello", false);
                expect($actual)->false();

                $actual = PhText::endsWith("Hello", "O", false);
                expect($actual)->false();
            }
        );
    }
}