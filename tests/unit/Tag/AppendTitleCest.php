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
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

/**
 * Class AppendTitleCest
 */
class AppendTitleCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: appendTitle()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function tagAppendTitle(UnitTester $I)
    {
        $I->wantToTest("Tag - appendTitle()");
        Tag::resetInput();
        Tag::setTitle('Title');
        Tag::appendTitle('Class');

        $expected = "Title";
        $actual   = Tag::getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = "TitleClass";
        $actual   = Tag::getTitle(false, true);
        $I->assertEquals($expected, $actual);

        $expected = "<title>TitleClass</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: appendTitle() - separator
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function tagAppendTitleSeparator(UnitTester $I)
    {
        $I->wantToTest("Tag - appendTitle() - separator");
        Tag::resetInput();
        Tag::setTitle('Title');
        Tag::setTitleSeparator('|');
        Tag::appendTitle('Class');

        $expected = "Title";
        $actual   = Tag::getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = "Title|Class";
        $actual   = Tag::getTitle(false, true);
        $I->assertEquals($expected, $actual);

        $expected = "<title>Title|Class</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: appendTitle() - double call
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function tagAppendTitleDoubleCall(UnitTester $I)
    {
        $I->wantToTest("Tag - appendTitle() - double call");
        Tag::resetInput();
        Tag::setTitle('Main');
        Tag::setTitleSeparator(' - ');
        Tag::appendTitle('Category');
        Tag::appendTitle('Title');

        $expected = "Main";
        $actual   = Tag::getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = "Main - Category - Title";
        $actual   = Tag::getTitle(false, true);
        $I->assertEquals($expected, $actual);

        $expected = "<title>Main - Category - Title</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: appendTitle() - array
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function tagAppendTitleArray(UnitTester $I)
    {
        $I->wantToTest("Tag - appendTitle() - array");
        Tag::resetInput();
        Tag::setTitle('Main');
        Tag::setTitleSeparator(' - ');
        Tag::appendTitle(['Category', 'Title']);

        $expected = "Main";
        $actual   = Tag::getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = "Main - Category - Title";
        $actual   = Tag::getTitle(false, true);
        $I->assertEquals($expected, $actual);

        $expected = "<title>Main - Category - Title</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: appendTitle() - empty array
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function tagAppendTitleEmptyArray(UnitTester $I)
    {
        $I->wantToTest("Tag - appendTitle() - empty array");
        Tag::resetInput();
        Tag::setTitle('Main');
        Tag::setTitleSeparator(' - ');
        Tag::appendTitle('Category');
        Tag::appendTitle([]);

        $expected = "Main";
        $actual   = Tag::getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = "Main";
        $actual   = Tag::getTitle(false, true);
        $I->assertEquals($expected, $actual);

        $expected = "<title>Main</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);
    }
}
