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

use InvalidArgumentException;
use Phalcon\Assets\Filters\Cssmin;
use UnitTester;

class CssMinCest
{
    /**
     * Tests cssmin filter with non-string param
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-10
     */
    public function testFilterCssminWithNonStringParam(UnitTester $I, $scenario)
    {
        $scenario->skip('TODO: Check Exception');
        $I->expectThrowable(
            new InvalidArgumentException("Parameter 'content' must be a string"),
            function () {
                $cssmin = new Cssmin([]);
                $cssmin->filter(new \stdClass());
            }
        );
    }

    /**
     * Tests cssmin filter with empty string
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-10
     */
    public function testFilterCssminEmptyString(UnitTester $I)
    {
        $cssmin = new Cssmin();
        $actual = $cssmin->filter('');
        $I->assertEmpty($actual);
    }

    /**
     * Tests cssmin filter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsFilterCssmin(UnitTester $I, $scenario)
    {
        $cssmin   = new Cssmin();
        $expected = '';
        $actual   = $cssmin->filter(' ');
        $I->assertEquals($expected, $actual);

        $expected = '{}}';
        $actual   = $cssmin->filter('{}}');
        $I->assertEquals($expected, $actual);

        $expected = '.s{d : b;}';
        $actual   = $cssmin->filter('.s { d     :        b; }');
        $I->assertEquals($expected, $actual);

        $source   = ".social-link {display: inline-block; width: 44px; "
            . "height: 44px; text-align: left; text-indent: "
            . "-9999px; overflow: hidden; background: "
            . "url('../images/social-links.png'); }";
        $expected = ".social-link{display: inline-block;width: 44px;"
            . "height: 44px;text-align: left;text-indent: "
            . "-9999px;overflow: hidden;background: "
            . "url('../images/social-links.png');}";
        $actual   = $cssmin->filter($source);
        $I->assertEquals($expected, $actual);

        $expected = "h2:after{border-width: 1px;}";
        $actual   = $cssmin->filter("h2:after         { border-width:         1px; }");
        $I->assertEquals($expected, $actual);

        $source   = "h1 > p { font-family: 'Helvetica Neue'; }";
        $expected = "h1> p{font-family: 'Helvetica Neue';}";
        $actual   = $cssmin->filter($source);
        $I->assertEquals($expected, $actual);

        $source   = "h1 > p { font-family: 'Helvetica Neue'; }";
        $expected = "h1> p{font-family: 'Helvetica Neue';}";
        $actual   = $cssmin->filter($source);
        $I->assertEquals($expected, $actual);

        $source   = ".navbar .nav>li>a { color: #111; "
            . "text-decoration: underline; }";
        $expected = ".navbar .nav>li>a{color: #111;"
            . "text-decoration: underline;}";
        $actual   = $cssmin->filter($source);
        $I->assertEquals($expected, $actual);

        $sourceFile = PATH_DATA . '/assets/assets/cssmin-01.css';
        $targetFile = PATH_DATA . '/assets/assets/cssmin-01-result.css';

        if (!file_exists($sourceFile) || !file_exists($targetFile)) {
            $scenario->skip('Source files missing for this test');
        }

        $source   = file_get_contents($sourceFile);
        $expected = file_get_contents($targetFile);
        $actual   = $cssmin->filter($source);
        $I->assertEquals($expected, $actual);
    }
}
