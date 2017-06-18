<?php

namespace Phalcon\Test\Unit\Assets\Filters;

use Phalcon\Assets\Filters\Jsmin;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Assets\Filters\JsminTest
 * Tests the \Phalcon\Assets\Filters\Jsmin component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Assets\Filters
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class JsminTest extends UnitTest
{
    /**
     * Tests jsmin filter with non-string param
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testFilterJsminWithNonStringParam()
    {
        $this->specify(
            "The jsmin filter needs a string parameter",
            function () {
                $jsmin = new Jsmin();
                $jsmin->filter(new \stdClass());
            },
            ['throws' => ['InvalidArgumentException', "Parameter 'content' must be a string"]]
        );
    }

    /**
     * Tests jsmin filter with unterminated comment
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testFilterJsminUnterminatedComment()
    {
        $this->specify(
            "The jsmin with unterminated comment does not throws exception",
            function () {
                $jsmin = new Jsmin();
                $jsmin->filter('/*');
            },
            ['throws' => ['Phalcon\Assets\Exception', "Unterminated comment."]]
        );
    }

    /**
     * Tests jsmin filter with unterminated string literal
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testFilterJsminUnterminatedStringLiteral()
    {
        $this->specify(
            "The jsmin with unterminated string literal does not throws exception",
            function () {
                $jsmin = new Jsmin();
                $jsmin->filter('a = "');
            },
            ['throws' => ['Phalcon\Assets\Exception', "Unterminated string literal."]]
        );
    }

    /**
     * Tests jsmin filter with unterminated Regular Expression literal
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testFilterJsminUnterminatedRegexpLiteral()
    {
        $this->specify(
            "The jsmin with unterminated Regular Expression literal does not throws exception",
            function () {
                $jsmin = new Jsmin();
                $jsmin->filter('b = /[a-z]+');
            },
            ['throws' => ['Phalcon\Assets\Exception', "Unterminated Regular Expression literal."]]
        );
    }

    /**
     * Tests jsmin filter with empty string
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testFilterJsminEmptyString()
    {
        $this->specify(
            "The jsmin filter with empty parameter does not return empty back",
            function () {
                $jsmin = new Jsmin();

                expect($jsmin->filter(''))->isEmpty();
            }
        );
    }

    /**
     * Tests jsmin filter with comment
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testFilterJsminComment()
    {
        $this->specify(
            "The jsmin filter with comment parameter return comment back",
            function () {
                $jsmin = new Jsmin();

                expect($jsmin->filter('/** this is a comment */'))->isEmpty();
            }
        );
    }

    /**
     * Tests cssmin filter
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testAssetsFilterJsmin()
    {
        $this->specify(
            "The jsmin filter does not work correctly",
            function () {
                $jsmin = new Jsmin();

                expect($jsmin->filter('{}}'))->equals("\n" . '{}}');
                expect($jsmin->filter('if ( a == b ) {    document . writeln("hello") ; }'))->equals("\n" . 'if(a==b){document.writeln("hello");}');
                expect($jsmin->filter("if ( a == b ) {    document . writeln('\t') ; }"))->equals("\n" . "if(a==b){document.writeln('\t');}");
                expect($jsmin->filter("/** this is a comment */ if ( a == b ) {    document . writeln('\t') ; /** this is a comment */ }"))->equals("\n" . "if(a==b){document.writeln('\t');}");
                expect($jsmin->filter("\t\ta\t\r\n= \n \r\n100;\t"))->equals("\n" . 'a=100;');
            }
        );
    }
}
