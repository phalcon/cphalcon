<?php

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Text\TextEndsWithTest
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
class TextEndsWithTest extends UnitTest
{
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
                $actual = Text::endsWith("", "");
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
                $actual = Text::endsWith("", "hello");
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
                $actual = Text::endsWith("Hello", "o");
                expect($actual)->true();

                $actual = Text::endsWith("Hello", "lo");
                expect($actual)->true();

                $actual = Text::endsWith("Hello", "Hello");
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
                $actual = Text::endsWith("Hello", "O");
                expect($actual)->true();

                $actual = Text::endsWith("Hello", "LO");
                expect($actual)->true();

                $actual = Text::endsWith("Hello", "hello");
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
                $actual = Text::endsWith("Hello", "hello", true);
                expect($actual)->true();

                $actual = Text::endsWith("Hello", "hello", false);
                expect($actual)->false();

                $actual = Text::endsWith("Hello", "O", false);
                expect($actual)->false();
            }
        );
    }
}
