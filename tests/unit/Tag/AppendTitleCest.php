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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Helpers\TagSetup;
use UnitTester;

class AppendTitleCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: appendTitle()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-09-05
     */
    public function tagAppendTitle(UnitTester $I)
    {
        $I->wantToTest('Tag - appendTitle()');

        Tag::resetInput();

        Tag::setTitle('Title');

        Tag::appendTitle('Class');

        $I->assertEquals(
            'Title',
            Tag::getTitle(false, false)
        );

        $I->assertEquals(
            'TitleClass',
            Tag::getTitle(false, true)
        );

        $I->assertEquals(
            '<title>TitleClass</title>' . PHP_EOL,
            Tag::renderTitle()
        );
    }

    /**
     * Tests Phalcon\Tag :: appendTitle() - separator
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-09-05
     */
    public function tagAppendTitleSeparator(UnitTester $I)
    {
        $I->wantToTest('Tag - appendTitle() - separator');

        Tag::resetInput();

        Tag::setTitle('Title');
        Tag::setTitleSeparator('|');

        Tag::appendTitle('Class');

        $I->assertEquals(
            'Title',
            Tag::getTitle(false, false)
        );

        $I->assertEquals(
            'Title|Class',
            Tag::getTitle(false, true)
        );

        $I->assertEquals(
            '<title>Title|Class</title>' . PHP_EOL,
            Tag::renderTitle()
        );
    }

    /**
     * Tests Phalcon\Tag :: appendTitle() - double call
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-09-05
     */
    public function tagAppendTitleDoubleCall(UnitTester $I)
    {
        $I->wantToTest('Tag - appendTitle() - double call');

        Tag::resetInput();

        Tag::setTitle('Main');
        Tag::setTitleSeparator(' - ');

        Tag::appendTitle('Category');
        Tag::appendTitle('Title');

        $I->assertEquals(
            'Main',
            Tag::getTitle(false, false)
        );

        $I->assertEquals(
            'Main - Category - Title',
            Tag::getTitle(false, true)
        );

        $I->assertEquals(
            '<title>Main - Category - Title</title>' . PHP_EOL,
            Tag::renderTitle()
        );
    }

    /**
     * Tests Phalcon\Tag :: appendTitle() - array
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-09-05
     */
    public function tagAppendTitleArray(UnitTester $I)
    {
        $I->wantToTest('Tag - appendTitle() - array');

        Tag::resetInput();

        Tag::setTitle('Main');
        Tag::setTitleSeparator(' - ');

        Tag::appendTitle(['Category', 'Title']);

        $I->assertEquals(
            'Main',
            Tag::getTitle(false, false)
        );

        $I->assertEquals(
            'Main - Category - Title',
            Tag::getTitle(false, true)
        );

        $I->assertEquals(
            '<title>Main - Category - Title</title>' . PHP_EOL,
            Tag::renderTitle()
        );
    }

    /**
     * Tests Phalcon\Tag :: appendTitle() - empty array
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-09-05
     */
    public function tagAppendTitleEmptyArray(UnitTester $I)
    {
        $I->wantToTest('Tag - appendTitle() - empty array');

        Tag::resetInput();

        Tag::setTitle('Main');
        Tag::setTitleSeparator(' - ');

        Tag::appendTitle('Category');
        Tag::appendTitle([]);

        $I->assertEquals(
            'Main',
            Tag::getTitle(false, false)
        );

        $I->assertEquals(
            'Main',
            Tag::getTitle(false, true)
        );

        $I->assertEquals(
            '<title>Main</title>' . PHP_EOL,
            Tag::renderTitle()
        );
    }
}
