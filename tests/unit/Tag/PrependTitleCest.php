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

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use UnitTester;

class PrependTitleCest
{
    /**
     * Tests Phalcon\Tag :: prependTitle()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function tagPrependTitle(UnitTester $I)
    {
        $I->wantToTest("Tag - prependTitle()");
        Tag::resetInput();
        Tag::setTitle('Title');
        Tag::prependTitle('Class');

        $expected = "Title";
        $actual   = Tag::getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = "ClassTitle";
        $actual   = Tag::getTitle(true, false);
        $I->assertEquals($expected, $actual);

        $expected = "<title>ClassTitle</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: prependTitle() - separator
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function tagPrependTitleSeparator(UnitTester $I)
    {
        $I->wantToTest("Tag - prependTitle() - separator");
        Tag::resetInput();
        Tag::setTitle('Title');
        Tag::setTitleSeparator('|');
        Tag::prependTitle('Class');

        $expected = "Title";
        $actual   = Tag::getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = "Class|Title";
        $actual   = Tag::getTitle(true, false);
        $I->assertEquals($expected, $actual);

        $expected = "<title>Class|Title</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: prependTitle() - double call
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function tagPrependTitleDoubleCall(UnitTester $I)
    {
        $I->wantToTest("Tag - prependTitle() - double call");
        Tag::resetInput();
        Tag::setTitle('Main');
        Tag::setTitleSeparator(' - ');
        Tag::prependTitle('Category');
        Tag::prependTitle('Title');

        $expected = "Main";
        $actual   = Tag::getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = "Title - Category - Main";
        $actual   = Tag::getTitle(true, false);
        $I->assertEquals($expected, $actual);

        $expected = "<title>Title - Category - Main</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: prependTitle() - array
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function tagPrependTitleArray(UnitTester $I)
    {
        $I->wantToTest("Tag - prependTitle() - array");
        Tag::resetInput();
        Tag::setTitle('Main');
        Tag::setTitleSeparator(' - ');
        Tag::prependTitle(['Category', 'Title']);

        $expected = "Main";
        $actual   = Tag::getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = "Title - Category - Main";
        $actual   = Tag::getTitle(true, false);
        $I->assertEquals($expected, $actual);

        $expected = "<title>Title - Category - Main</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: prependTitle() - empty array
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function tagPrependTitleEmptyArray(UnitTester $I)
    {
        $I->wantToTest("Tag - prependTitle() - empty array");
        Tag::resetInput();
        Tag::setTitle('Main');
        Tag::setTitleSeparator(' - ');
        Tag::prependTitle('Category');
        Tag::prependTitle([]);

        $expected = "Main";
        $actual   = Tag::getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = "Main";
        $actual   = Tag::getTitle(true, false);
        $I->assertEquals($expected, $actual);

        $expected = "<title>Main</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);
    }
}
