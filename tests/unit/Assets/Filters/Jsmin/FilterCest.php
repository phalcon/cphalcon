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

namespace Phalcon\Test\Unit\Assets\Filters\Jsmin;

use Phalcon\Assets\Filters\Jsmin;
use UnitTester;

class FilterCest
{
    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: filter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter()');

        $I->skipTest('Need Phalcon implementation');

        $jsmin = new Jsmin();

        $actual = $jsmin->filter('{}}');

        $I->assertEquals(
            "\n" . '{}}',
            $actual
        );
    }

    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: filter() - spaces
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminFilterSpaces(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - spaces');

        $I->skipTest('Need Phalcon implementation');

        $jsmin = new Jsmin();

        $actual = $jsmin->filter(
            'if ( a == b ) {    document . writeln("hello") ; }'
        );

        $I->assertEquals(
            "\n" . 'if(a==b){document.writeln("hello");}',
            $actual
        );
    }

    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: filter() - tabs
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminFilterTabs(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - tabs');

        $I->skipTest('Need Phalcon implementation');

        $jsmin = new Jsmin();

        $actual = $jsmin->filter(
            "\n" . "if ( a == b ) {    document . writeln('\t') ; }"
        );

        $I->assertEquals(
            "\n" . "if(a==b){document.writeln('\t');}",
            $actual
        );
    }

    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: filter() - tabs comment
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminFilterTabsComment(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - tabs comment');

        $I->skipTest('Need Phalcon implementation');

        $jsmin = new Jsmin();

        $actual = $jsmin->filter(
            "/** this is a comment */ if ( a == b ) {    document . writeln('\t') ; /** this is a comment */ }"
        );

        $I->assertEquals(
            "\nif(a==b){document.writeln('\t');}",
            $actual
        );
    }

    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: filter() - tabs newlines
     *
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminFilterEmpty(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - empty');

        $I->skipTest('Need Phalcon implementation');

        $jsmin = new Jsmin();

        $I->assertIsEmpty(
            $jsmin->filter('')
        );
    }

    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: filter() - comment
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminFilterComment(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - comment');

        $I->skipTest('Need Phalcon implementation');

        $jsmin = new Jsmin();

        $I->assertIsEmpty(
            $jsmin->filter('/** this is a comment */')
        );
    }
}
