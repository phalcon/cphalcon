<?php

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
use Phalcon\Test\Unit\Tag\Helper\TagHelper;
use UnitTester;

class TagTitleCest extends TagHelper
{
    /**
     * Tests malicious content in the title
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11185
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-13
     */
    public function testGetTitleWithoutMaliciousContent(UnitTester $I)
    {
        Tag::resetInput();
        $value = "Hello </title><script>alert('Got your nose!');</script><title>";

        Tag::setTitle($value);
        $expected = "Hello &lt;/title&gt;&lt;script&gt;alert(&#039;Got your nose!&#039;);&lt;/script&gt;&lt;title&gt;";
        $actual   = Tag::getTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests malicious content in the title
     *
     * @since  2018-11-01
     */
    public function testRenderTitleWithoutMaliciousContent(UnitTester $I)
    {
        Tag::resetInput();
        $value = "Hello </title><script>alert('Got your nose!');</script><title>";

        Tag::setTitle($value);
        $expected = "<title>Hello &lt;/title&gt;&lt;script&gt;alert(&#039;Got your nose!&#039;);&lt;/script&gt;&lt;title&gt;</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests setTitle
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitle(UnitTester $I)
    {
        Tag::resetInput();
        $value = 'This is my title';
        Tag::setTitle($value);

        $expected = "<title>{$value}</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);

        $expected = "{$value}";
        $actual   = Tag::getTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests appendTitle
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function testAppendTitle(UnitTester $I)
    {
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

        Tag::resetInput();

        Tag::setTitle('This is my title');
        Tag::appendTitle(' - Welcome!');

        $expected = "This is my title";
        $actual   = Tag::getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = "This is my title - Welcome!";
        $actual   = Tag::getTitle(false, true);
        $I->assertEquals($expected, $actual);

        $expected = "<title>This is my title - Welcome!</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);

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

    /**
     * Tests prependTitle
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function testPrependTitle(UnitTester $I)
    {
        Tag::resetInput();

        Tag::setTitleSeparator('');
        Tag::setTitle('This is my title');
        Tag::prependTitle('PhalconPHP - ');

        $expected = "This is my title";
        $actual   = Tag::getTitle(false, false);
        $I->assertEquals($expected, $actual);

        $expected = "PhalconPHP - This is my title";
        $actual   = Tag::getTitle(true, false);
        $I->assertEquals($expected, $actual);

        $expected = "<title>PhalconPHP - This is my title</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);

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

    /**
     * Tests titleSeparator
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitleSeparator(UnitTester $I)
    {
        Tag::resetInput();
        Tag::setTitleSeparator('-');

        $expected = "-";
        $actual   = Tag::getTitleSeparator();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests titleSeparator with append
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitleSeparatorAppend(UnitTester $I)
    {
        Tag::resetInput();
        Tag::setTitle('This is my title');
        Tag::setTitleSeparator('-');
        Tag::appendTitle('PhalconPHP');

        $expected = "<title>This is my title-PhalconPHP</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests titleSeparator prepend
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitleSeparatorPrepend(UnitTester $I)
    {
        Tag::resetInput();
        Tag::setTitle('This is my title');
        Tag::setTitleSeparator('-');
        Tag::prependTitle('PhalconPHP');

        $expected = "<title>PhalconPHP-This is my title</title>" . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);
    }
}
