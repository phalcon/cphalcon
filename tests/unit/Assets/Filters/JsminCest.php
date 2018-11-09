<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Filters;

use Phalcon\Assets\Exception;
use Phalcon\Assets\Filters\Jsmin;
use UnitTester;

class JsminCest
{
    /**
     * Tests jsmin filter with non-string param
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testFilterJsminWithNonStringParam(UnitTester $I, $scenario)
    {
        $scenario->skip('TODO: Check exception');
        $I->expectThrowable(
            new \InvalidArgumentException("Parameter 'content' must be a string"),
            function () {
                $jsmin = new Jsmin();
                $jsmin->filter(new \stdClass());
            }
        );
    }

    /**
     * Tests jsmin filter with unterminated comment
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testFilterJsminUnterminatedComment(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception('Unterminated comment.'),
            function () {
                $jsmin = new Jsmin();
                $jsmin->filter('/*');
            }
        );
    }

    /**
     * Tests jsmin filter with unterminated string literal
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testFilterJsminUnterminatedStringLiteral(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception('Unterminated string literal.'),
            function () {
                $jsmin = new Jsmin();
                $jsmin->filter('a = "');
            }
        );
    }

    /**
     * Tests jsmin filter with unterminated Regular Expression literal
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testFilterJsminUnterminatedRegexpLiteral(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception('Unterminated Regular Expression literal.'),
            function () {
                $jsmin = new Jsmin();
                $jsmin->filter('b = /[a-z]+');
            }
        );
    }

    /**
     * Tests jsmin filter with empty string
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testFilterJsminEmptyString(UnitTester $I)
    {
        $jsmin  = new Jsmin();
        $actual = $jsmin->filter('');
        $I->assertIsEmpty($actual);
    }

    /**
     * Tests jsmin filter with comment
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testFilterJsminComment(UnitTester $I)
    {
        $jsmin = new Jsmin();

        $actual = $jsmin->filter('/** this is a comment */');
        $I->assertIsEmpty($actual);
    }

    /**
     * Tests cssmin filter
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testAssetsFilterJsmin(UnitTester $I, $scenario)
    {
        $scenario->skip('TODO: Check the fourth assertion');
        $jsmin = new Jsmin();

        $expected = "\n" . '{}}';
        $actual   = $jsmin->filter('{}}');
        $I->assertEquals($expected, $actual);

        $expected = "\n" . 'if(a==b){document.writeln("hello");}';
        $actual   = $jsmin->filter('if ( a == b ) {    document . writeln("hello") ; }');
        $I->assertEquals($expected, $actual);

        $expected = "\n" . "if(a==b){document.writeln('\t');}";
        $actual   = $jsmin->filter("\n" . "if ( a == b ) {    document . writeln('\t') ; }");
        $I->assertEquals($expected, $actual);

        $expected = "/** this is a comment */ if ( a == b ) {    document . writeln('\t') ; /** this is a comment */ }";
        $actual   = $jsmin->filter("\n" . "if(a==b){document.writeln('\t');}");
        $I->assertEquals($expected, $actual);

        $expected = "\n" . 'a=100;';
        $actual   = $jsmin->filter("\t\ta\t\r\n= \n \r\n100;\t");
        $I->assertEquals($expected, $actual);
    }
}
