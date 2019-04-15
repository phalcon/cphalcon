<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Filters\Jsmin;

use Phalcon\Assets\Filters\Jsmin;
use UnitTester;

/**
 * Class FilterCest
 */
class FilterCest
{
    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: filter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter()');
        $I->skipTest('Need Phalcon implementation');
        $jsmin = new Jsmin();

        $expected = "\n" . '{}}';
        $actual   = $jsmin->filter('{}}');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: filter() - spaces
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminFilterSpaces(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - spaces');
        $I->skipTest('Need Phalcon implementation');
        $jsmin = new Jsmin();

        $expected = "\n" . 'if(a==b){document.writeln("hello");}';
        $actual   = $jsmin->filter('if ( a == b ) {    document . writeln("hello") ; }');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: filter() - tabs
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminFilterTabs(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - tabs');
        $I->skipTest('Need Phalcon implementation');
        $jsmin = new Jsmin();

        $expected = "\n" . "if(a==b){document.writeln('\t');}";
        $actual   = $jsmin->filter("\n" . "if ( a == b ) {    document . writeln('\t') ; }");
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: filter() - tabs comment
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminFilterTabsComment(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - tabs comment');
        $I->skipTest('Need Phalcon implementation');
        $jsmin = new Jsmin();

        $source   = "/** this is a comment */ if ( a == b ) {    document . writeln('\t') ; /** this is a comment */ }";
        $expected = "\nif(a==b){document.writeln('\t');}";
        $actual   = $jsmin->filter($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: filter() - tabs newlines
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminFilterTabsCommentNewlines(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - tabs newlines');
        $I->skipTest('Need Phalcon implementation');
        $jsmin = new Jsmin();

        $expected = "\n" . 'a=100;';
        $actual   = $jsmin->filter("\t\ta\t\r\n= \n \r\n100;\t");
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: filter() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminFilterEmpty(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - empty');
        $I->skipTest('Need Phalcon implementation');
        $jsmin = new Jsmin();

        $actual = $jsmin->filter('');
        $I->assertIsEmpty($actual);
    }

    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: filter() - comment
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminFilterComment(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - comment');
        $I->skipTest('Need Phalcon implementation');
        $jsmin = new Jsmin();

        $actual = $jsmin->filter('/** this is a comment */');
        $I->assertIsEmpty($actual);
    }
}
