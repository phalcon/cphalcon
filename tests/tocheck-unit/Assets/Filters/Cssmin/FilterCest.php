<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Assets\Filters\Cssmin;

use Phalcon\Assets\Filters\Cssmin;
use UnitTester;

class FilterCest
{
    /**
     * Tests Phalcon\Assets\Filters\Cssmin :: filter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-10
     */
    public function assetsFiltersCssminFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Cssmin - filter()');

        $I->skipTest('Need Phalcon implementation');

        $cssmin = new Cssmin();

        $expected = '{}}';
        $actual   = $cssmin->filter('{}}');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Filters\Cssmin :: filter() - spaces
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-10
     */
    public function assetsFiltersCssminFilterSpaces(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Cssmin - filter() - spaces');

        $I->skipTest('Need Phalcon implementation');

        $cssmin = new Cssmin();

        $expected = '.s{d : b;}';
        $actual   = $cssmin->filter('.s { d     :        b; }');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Filters\Cssmin :: filter() - attributes spaces
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-10
     */
    public function assetsFiltersCssminFilterAttributesSpaces(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Cssmin - filter() - attributes spaces');

        $I->skipTest('Need Phalcon implementation');

        $cssmin = new Cssmin();

        $source   = '.social-link {display: inline-block; width: 44px; '
            . 'height: 44px; text-align: left; text-indent: '
            . '-9999px; overflow: hidden; background: '
            . "url('../images/social-links.png'); }";
        $expected = '.social-link{display: inline-block;width: 44px;'
            . 'height: 44px;text-align: left;text-indent: '
            . '-9999px;overflow: hidden;background: '
            . "url('../images/social-links.png');}";
        $actual   = $cssmin->filter($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Filters\Cssmin :: filter() - class spaces
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-10
     */
    public function assetsFiltersCssminFilterClassSpaces(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Cssmin - filter() - class spaces');

        $I->skipTest('Need Phalcon implementation');

        $cssmin = new Cssmin();

        $expected = 'h2:after{border-width: 1px;}';
        $actual   = $cssmin->filter('h2:after         { border-width:         1px; }');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Filters\Cssmin :: filter() - class inheritance
     * spaces
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-10
     */
    public function assetsFiltersCssminFilterClassInheritanceSpaces(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Cssmin - filter() - class inheritance spaces');

        $I->skipTest('Need Phalcon implementation');

        $cssmin = new Cssmin();

        $source   = "h1 > p { font-family: 'Helvetica Neue'; }";
        $expected = "h1> p{font-family: 'Helvetica Neue';}";
        $actual   = $cssmin->filter($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Filters\Cssmin :: filter() - complex
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-10
     */
    public function assetsFiltersCssminFilterComples(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Cssmin - filter() - complex');

        $I->skipTest('Need Phalcon implementation');

        $cssmin = new Cssmin();

        $source   = '.navbar .nav>li>a { color: #111; '
            . 'text-decoration: underline; }';
        $expected = '.navbar .nav>li>a{color: #111;'
            . 'text-decoration: underline;}';
        $actual   = $cssmin->filter($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Filters\Cssmin :: filter() - load files
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-10
     */
    public function assetsFiltersCssminFilterLoadFiles(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Cssmin - filter() - load files');

        $I->skipTest('Need Phalcon implementation');

        $cssmin = new Cssmin();

        $sourceFile = dataDir('/assets/assets/cssmin-01.css');
        $targetFile = dataDir('/assets/assets/cssmin-01-result.css');

        $I->assertFileExists($sourceFile);
        $I->assertFileExists($targetFile);

        $source   = file_get_contents($sourceFile);
        $expected = file_get_contents($targetFile);
        $actual   = $cssmin->filter($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Filters\Cssmin :: filter() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-10
     */
    public function assetsFiltersCssminFilterEmpty(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Cssmin - filter() - empty');

        $I->skipTest('Need Phalcon implementation');

        $cssmin = new Cssmin();

        $I->assertEmpty(
            $cssmin->filter('')
        );
    }

    /**
     * Tests cssmin filter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-10
     */
    public function testAssetsFilterCssmin(UnitTester $I)
    {
    }
}
