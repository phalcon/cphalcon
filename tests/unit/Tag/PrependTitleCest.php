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
use UnitTester;

class PrependTitleCest
{
    /**
     * Tests Phalcon\Tag :: prependTitle()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-09-05
     */
    public function tagPrependTitle(UnitTester $I)
    {
        $I->wantToTest('Tag - prependTitle()');

        Tag::resetInput();

        Tag::setTitle('Title');

        Tag::prependTitle('Class');

        $I->assertSame(
            'Title',
            Tag::getTitle(false, false)
        );

        $I->assertSame(
            'ClassTitle',
            Tag::getTitle(true, false)
        );

        $I->assertSame(
            '<title>ClassTitle</title>' . PHP_EOL,
            Tag::renderTitle()
        );
    }

    /**
     * Tests Phalcon\Tag :: prependTitle() - separator
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-09-05
     */
    public function tagPrependTitleSeparator(UnitTester $I)
    {
        $I->wantToTest('Tag - prependTitle() - separator');

        Tag::resetInput();

        Tag::setTitle('Title');
        Tag::setTitleSeparator('|');

        Tag::prependTitle('Class');

        $I->assertSame(
            'Title',
            Tag::getTitle(false, false)
        );

        $I->assertSame(
            'Class|Title',
            Tag::getTitle(true, false)
        );

        $I->assertSame(
            '<title>Class|Title</title>' . PHP_EOL,
            Tag::renderTitle()
        );
    }

    /**
     * Tests Phalcon\Tag :: prependTitle() - double call
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-09-05
     */
    public function tagPrependTitleDoubleCall(UnitTester $I)
    {
        $I->wantToTest('Tag - prependTitle() - double call');

        Tag::resetInput();

        Tag::setTitle('Main');
        Tag::setTitleSeparator(' - ');

        Tag::prependTitle('Category');
        Tag::prependTitle('Title');

        $I->assertSame(
            'Main',
            Tag::getTitle(false, false)
        );

        $I->assertSame(
            'Title - Category - Main',
            Tag::getTitle(true, false)
        );

        $I->assertSame(
            '<title>Title - Category - Main</title>' . PHP_EOL,
            Tag::renderTitle()
        );
    }

    /**
     * Tests Phalcon\Tag :: prependTitle() - array
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-09-05
     */
    public function tagPrependTitleArray(UnitTester $I)
    {
        $I->wantToTest('Tag - prependTitle() - array');

        Tag::resetInput();

        Tag::setTitle('Main');
        Tag::setTitleSeparator(' - ');

        Tag::prependTitle(
            ['Category', 'Title']
        );

        $I->assertSame(
            'Main',
            Tag::getTitle(false, false)
        );

        $I->assertSame(
            'Title - Category - Main',
            Tag::getTitle(true, false)
        );

        $I->assertSame(
            '<title>Title - Category - Main</title>' . PHP_EOL,
            Tag::renderTitle()
        );
    }

    /**
     * Tests Phalcon\Tag :: prependTitle() - empty array
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-09-05
     */
    public function tagPrependTitleEmptyArray(UnitTester $I)
    {
        $I->wantToTest('Tag - prependTitle() - empty array');

        Tag::resetInput();

        Tag::setTitle('Main');
        Tag::setTitleSeparator(' - ');

        Tag::prependTitle('Category');

        Tag::prependTitle(
            []
        );

        $I->assertSame(
            'Main',
            Tag::getTitle(false, false)
        );

        $I->assertSame(
            'Main',
            Tag::getTitle(true, false)
        );

        $I->assertSame(
            '<title>Main</title>' . PHP_EOL,
            Tag::renderTitle()
        );
    }
}
