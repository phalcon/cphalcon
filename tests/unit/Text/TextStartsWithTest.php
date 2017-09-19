<?php

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Text\TextStartsWithTest
 * Tests the \Phalcon\Text component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TextStartsWithTest extends UnitTest
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
                $actual = Text::startsWith("", "");
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
                $actual = Text::startsWith("", "hello");
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
                $actual = Text::startsWith("Hello", "H");
                expect($actual)->true();

                $actual = Text::startsWith("Hello", "He");
                expect($actual)->true();

                $actual = Text::startsWith("Hello", "Hello");
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
                $actual = Text::startsWith("Hello", "h");
                expect($actual)->true();

                $actual = Text::startsWith("Hello", "he");
                expect($actual)->true();

                $actual = Text::startsWith("Hello", "hello");
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
                $actual = Text::startsWith("Hello", "hello", true);
                expect($actual)->true();

                $actual = Text::startsWith("Hello", "hello", false);
                expect($actual)->false();

                $actual = Text::startsWith("Hello", "h", false);
                expect($actual)->false();
            }
        );
    }
}
