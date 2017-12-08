<?php

namespace Phalcon\Test\Unit\Assets\Filters;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Assets\Filters\Cssmin;

/**
 * \Phalcon\Test\Unit\Assets\Filters\CssminTest
 * Tests the \Phalcon\Assets\Filters\Cssmin component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Assets\Filters
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CssMinTest extends UnitTest
{
    /**
     * Tests cssmin filter with non-string param
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testFilterCssminWithNonStringParam()
    {
        $this->specify(
            "The cssmin filter needs a string parameter",
            function () {
                $cssmin = new Cssmin();
                $cssmin->filter(new \stdClass());
            },
            ['throws' => ['InvalidArgumentException', "Parameter 'content' must be a string"]]
        );
    }

    /**
     * Tests cssmin filter with empty string
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testFilterCssminEmptyString()
    {
        $this->specify(
            "The cssmin filter with empty parameter does not return empty back",
            function () {
                $cssmin = new Cssmin();

                expect($cssmin->filter(''))->isEmpty();
            }
        );
    }

    /**
     * Tests cssmin filter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsFilterCssmin()
    {
        $this->specify(
            "The cssmin filter with space as parameter does not return correct results",
            function () {
                $cssmin = new Cssmin();
                expect($cssmin->filter(' '))->equals('');
            }
        );

        $this->specify(
            "The cssmin filter with brackets does not return correct results",
            function () {
                $cssmin = new Cssmin();
                expect($cssmin->filter('{}}'))->equals('{}}');
            }
        );

        $this->specify(
            "The cssmin filter with brackets and spaces does not return correct results",
            function () {
                $cssmin = new Cssmin();
                expect($cssmin->filter('.s { d     :        b; }'))->equals('.s{d : b;}');
            }
        );

        $this->specify(
            "The cssmin filter with proper CSS does not compress the contents",
            function () {
                $cssmin   = new Cssmin();
                $source   = ".social-link {display: inline-block; width: 44px; "
                    . "height: 44px; text-align: left; text-indent: "
                    . "-9999px; overflow: hidden; background: "
                    . "url('../images/social-links.png'); }";
                $expected = ".social-link{display: inline-block;width: 44px;"
                    . "height: 44px;text-align: left;text-indent: "
                    . "-9999px;overflow: hidden;background: "
                    . "url('../images/social-links.png');}";
                expect($cssmin->filter($source))->equals($expected);
            }
        );

        $this->specify(
            "The cssmin filter with a lot of spaces does not compress the contents",
            function () {
                $cssmin = new Cssmin();
                expect($cssmin->filter("h2:after         { border-width:         1px; }"))->equals("h2:after{border-width: 1px;}");
            }
        );

        $this->specify(
            "The cssmin filter with complex CSS does not compress the contents",
            function () {
                $cssmin   = new Cssmin();
                $source   = "h1 > p { font-family: 'Helvetica Neue'; }";
                $expected = "h1> p{font-family: 'Helvetica Neue';}";

                expect($cssmin->filter($source))->equals($expected);
            }
        );

        $this->specify(
            "The cssmin filter with complex CSS does not compress the contents",
            function () {
                $cssmin   = new Cssmin();
                $source   = "h1 > p { font-family: 'Helvetica Neue'; }";
                $expected = "h1> p{font-family: 'Helvetica Neue';}";

                expect($cssmin->filter($source))->equals($expected);
            }
        );

        $this->specify(
            "The cssmin filter with complex nested CSS does not compress the contents",
            function () {
                $cssmin   = new Cssmin();
                $source   = ".navbar .nav>li>a { color: #111; "
                    . "text-decoration: underline; }";
                $expected = ".navbar .nav>li>a{color: #111;"
                    . "text-decoration: underline;}";

                expect($cssmin->filter($source))->equals($expected);
            }
        );

        $this->specify(
            "The cssmin filter with complex CSS (line breaks) does not compress the contents",
            function () {
                $sourceFile = PATH_DATA . '/assets/cssmin-01.css';
                $targetFile = PATH_DATA . '/assets/cssmin-01-result.css';

                if (!file_exists($sourceFile) || !file_exists($targetFile)) {
                    $this->markTestIncomplete('Source files missing for this test');
                }

                $cssmin   = new Cssmin();
                $source   = file_get_contents($sourceFile);
                $expected = file_get_contents($targetFile);

                expect($cssmin->filter($source))->equals($expected);
            }
        );
    }
}
