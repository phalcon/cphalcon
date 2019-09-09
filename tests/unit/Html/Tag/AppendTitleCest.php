<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\TagSetupTrait;
use UnitTester;

class AppendTitleCest
{
    use DiTrait;
    use TagSetupTrait;

    /**
     * Tests Phalcon\Html\Tag :: appendTitle()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function htmlTagAppendTitle(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - appendTitle()');

        $tag = new Tag();
        $tag->setDI($this->container);

        $tag
            ->setTitle('Title')
            ->appendTitle(['Class'])
        ;

        $I->assertEquals(
            'Title',
            $tag->getTitle(false, false)
        );

        $I->assertEquals(
            'TitleClass',
            $tag->getTitle(false, true)
        );

        $I->assertEquals(
            '<title>TitleClass</title>' . PHP_EOL,
            $tag->renderTitle()
        );
    }

    /**
     * Tests Phalcon\Html\Tag :: appendTitle() - string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function htmlTagAppendTitleString(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - appendTitle() - string');

        $tag = new Tag();
        $tag->setDI($this->container);

        $tag
            ->setTitle('Title')
            ->appendTitle('Class')
        ;

        $I->assertEquals(
            'Title',
            $tag->getTitle(false, false)
        );

        $I->assertEquals(
            'TitleClass',
            $tag->getTitle(false, true)
        );

        $I->assertEquals(
            '<title>TitleClass</title>' . PHP_EOL,
            $tag->renderTitle()
        );
    }

    /**
     * Tests Phalcon\Html\Tag :: appendTitle() - separator
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function htmlTagAppendTitleSeparator(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - appendTitle() - separator');

        $tag = new Tag();
        $tag->setDI($this->container);

        $tag
            ->setTitle('Title')
            ->setTitleSeparator('|')
            ->appendTitle(['Class'])
        ;

        $I->assertEquals(
            'Title',
            $tag->getTitle(false, false)
        );

        $I->assertEquals(
            'Title|Class',
            $tag->getTitle(false, true)
        );

        $I->assertEquals(
            '<title>Title|Class</title>' . PHP_EOL,
            $tag->renderTitle()
        );
    }

    /**
     * Tests Phalcon\Html\Tag :: appendTitle() - double call
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function htmlTagAppendTitleDoubleCall(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - appendTitle() - double call');

        $tag = new Tag();
        $tag->setDI($this->container);

        $tag
            ->setTitle('Main')
            ->setTitleSeparator(' - ')
            ->appendTitle('Category')
            ->appendTitle('Title')
        ;

        $expected = 'Main';
        $actual   = $tag->getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = 'Main - Category - Title';
        $actual   = $tag->getTitle(false, true);
        $I->assertEquals($expected, $actual);

        $expected = '<title>Main - Category - Title</title>' . PHP_EOL;
        $actual   = $tag->renderTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: appendTitle() - many
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function htmlTagAppendTitleMany(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - appendTitle() - many');

        $tag = new Tag();
        $tag->setDI($this->container);

        $tag
            ->setTitle('Main')
            ->setTitleSeparator(' - ')
            ->appendTitle(['Category', 'Title'])
        ;

        $expected = 'Main';
        $actual   = $tag->getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = 'Main - Category - Title';
        $actual   = $tag->getTitle(false, true);
        $I->assertEquals($expected, $actual);

        $expected = '<title>Main - Category - Title</title>' . PHP_EOL;
        $actual   = $tag->renderTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: appendTitle() - empty array
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function htmlTagAppendTitleEmptyArray(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - appendTitle() - empty array');

        $tag = new Tag();
        $tag->setDI($this->container);

        $tag
            ->setTitle('Main')
            ->setTitleSeparator(' - ')
            ->appendTitle([])
        ;

        $expected = 'Main';
        $actual   = $tag->getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = 'Main';
        $actual   = $tag->getTitle(false, true);
        $I->assertEquals($expected, $actual);

        $expected = '<title>Main</title>' . PHP_EOL;
        $actual   = $tag->renderTitle();
        $I->assertEquals($expected, $actual);
    }
}
