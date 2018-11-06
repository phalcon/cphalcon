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
use Phalcon\Test\Unit\Tag\Helper\TagBase;
use UnitTester;

/**
 * \Phalcon\Test\Unit\Tag\TagTitleTest
 * Tests the \Phalcon\Tag component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Tag
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TagTitleTest extends TagBase
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
        $this->specify(
            "getTitle returns malicious content",
            function (UnitTester $I) {
                Tag::resetInput();
                $value = "Hello </title><script>alert('Got your nose!');</script><title>";

                Tag::setTitle($value);
                $expected = "Hello &lt;/title&gt;&lt;script&gt;alert(&#039;Got your nose!&#039;);&lt;/script&gt;&lt;title&gt;";

                expect(Tag::getTitle(UnitTester $I))->equals($expected);
            }
        );
    }

    /**
     * Tests malicious content in the title
     * @since  2018-11-01
     */
    public function testRenderTitleWithoutMaliciousContent(UnitTester $I)
    {
        $this->specify(
            "getTitle returns malicious content",
            function (UnitTester $I) {
                Tag::resetInput();
                $value = "Hello </title><script>alert('Got your nose!');</script><title>";

                Tag::setTitle($value);
                $expected = "<title>Hello &lt;/title&gt;&lt;script&gt;alert(&#039;Got your nose!&#039;);&lt;/script&gt;&lt;title&gt;</title>" . PHP_EOL;

                expect(Tag::renderTitle(UnitTester $I))->equals($expected);
            }
        );
    }

    /**
     * Tests setTitle
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitle(UnitTester $I)
    {
        $this->specify(
            "setTitle returns incorrect result",
            function (UnitTester $I) {
                Tag::resetInput();
                $value = 'This is my title';
                Tag::setTitle($value);

                expect(Tag::renderTitle(UnitTester $I))->equals("<title>{$value}</title>" . PHP_EOL);

                expect(Tag::getTitle(UnitTester $I))->equals("{$value}");
            }
        );
    }

    /**
     * Tests appendTitle
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testAppendTitle(UnitTester $I)
    {
        $this->specify(
            "appendTitle returns incorrect result",
            function (UnitTester $I) {
                Tag::resetInput();

                Tag::setTitle('Title');
                Tag::appendTitle('Class');

                expect(Tag::getTitle(false, false))->equals("Title");
                expect(Tag::getTitle(false, true))->equals("TitleClass");
                expect(Tag::renderTitle(UnitTester $I))->equals("<title>TitleClass</title>" . PHP_EOL);

                Tag::resetInput();

                Tag::setTitle('This is my title');
                Tag::appendTitle(' - Welcome!');

                expect(Tag::getTitle(false, false))->equals("This is my title");
                expect(Tag::getTitle(false, true))->equals("This is my title - Welcome!");
                expect(Tag::renderTitle(UnitTester $I))->equals("<title>This is my title - Welcome!</title>" . PHP_EOL);

                Tag::resetInput();

                Tag::setTitle('Title');
                Tag::setTitleSeparator('|');
                Tag::appendTitle('Class');

                expect(Tag::getTitle(false, false))->equals("Title");
                expect(Tag::getTitle(false, true))->equals("Title|Class");
                expect(Tag::renderTitle(UnitTester $I))->equals("<title>Title|Class</title>" . PHP_EOL);

                Tag::resetInput();

                Tag::setTitle('Main');
                Tag::setTitleSeparator(' - ');
                Tag::appendTitle('Category');
                Tag::appendTitle('Title');

                expect(Tag::getTitle(false, false))->equals("Main");
                expect(Tag::getTitle(false, true))->equals("Main - Category - Title");
                expect(Tag::renderTitle(UnitTester $I))->equals("<title>Main - Category - Title</title>" . PHP_EOL);

                Tag::resetInput();

                Tag::setTitle('Main');
                Tag::setTitleSeparator(' - ');
                Tag::appendTitle(['Category', 'Title']);

                expect(Tag::getTitle(false, false))->equals("Main");
                expect(Tag::getTitle(false, true))->equals("Main - Category - Title");
                expect(Tag::renderTitle(UnitTester $I))->equals("<title>Main - Category - Title</title>" . PHP_EOL);

                Tag::resetInput();

                Tag::setTitle('Main');
                Tag::setTitleSeparator(' - ');
                Tag::appendTitle('Category');
                Tag::appendTitle([]);

                expect(Tag::getTitle(false, false))->equals("Main");
                expect(Tag::getTitle(false, true))->equals("Main");
                expect(Tag::renderTitle(UnitTester $I))->equals("<title>Main</title>" . PHP_EOL);
            }
        );
    }

    /**
     * Tests prependTitle
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testPrependTitle(UnitTester $I)
    {
        $this->specify(
            "prependTitle returns incorrect result",
            function (UnitTester $I) {
                Tag::resetInput();

                Tag::setTitleSeparator('');
                Tag::setTitle('This is my title');
                Tag::prependTitle('PhalconPHP - ');

                expect(Tag::getTitle(false, false))->equals("This is my title");
                expect(Tag::getTitle(true, false))->equals("PhalconPHP - This is my title");
                expect(Tag::renderTitle(UnitTester $I))->equals("<title>PhalconPHP - This is my title</title>" . PHP_EOL);

                Tag::resetInput();

                Tag::setTitle('Title');
                Tag::setTitleSeparator('|');
                Tag::prependTitle('Class');

                expect(Tag::getTitle(false, false))->equals("Title");
                expect(Tag::getTitle(true, false))->equals("Class|Title");
                expect(Tag::renderTitle(UnitTester $I))->equals("<title>Class|Title</title>" . PHP_EOL);

                Tag::resetInput();

                Tag::setTitle('Main');
                Tag::setTitleSeparator(' - ');
                Tag::prependTitle('Category');
                Tag::prependTitle('Title');

                expect(Tag::getTitle(false, false))->equals("Main");
                expect(Tag::getTitle(true, false))->equals("Title - Category - Main");
                expect(Tag::renderTitle(UnitTester $I))->equals("<title>Title - Category - Main</title>" . PHP_EOL);

                Tag::resetInput();

                Tag::setTitle('Main');
                Tag::setTitleSeparator(' - ');
                Tag::prependTitle(['Category', 'Title']);

                expect(Tag::getTitle(false, false))->equals("Main");
                expect(Tag::getTitle(true, false))->equals("Title - Category - Main");
                expect(Tag::renderTitle(UnitTester $I))->equals("<title>Title - Category - Main</title>" . PHP_EOL);

                Tag::resetInput();

                Tag::setTitle('Main');
                Tag::setTitleSeparator(' - ');
                Tag::prependTitle('Category');
                Tag::prependTitle([]);

                expect(Tag::getTitle(false, false))->equals("Main");
                expect(Tag::getTitle(true, false))->equals("Main");
                expect(Tag::renderTitle(UnitTester $I))->equals("<title>Main</title>" . PHP_EOL);
            }
        );
    }

    /**
     * Tests titleSeparator
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitleSeparator(UnitTester $I)
    {
        $this->specify(
            "titleSeparator returns incorrect result",
            function (UnitTester $I) {
                Tag::resetInput();
                Tag::setTitleSeparator('-');

                expect(Tag::getTitleSeparator(UnitTester $I))->equals("-");
            }
        );
    }

    /**
     * Tests titleSeparator with append
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitleSeparatorAppend(UnitTester $I)
    {
        $this->specify(
            "titleSeparator with append returns incorrect result",
            function (UnitTester $I) {
                Tag::resetInput();
                Tag::setTitle('This is my title');
                Tag::setTitleSeparator('-');
                Tag::appendTitle('PhalconPHP');

                expect(Tag::renderTitle(UnitTester $I))->equals("<title>This is my title-PhalconPHP</title>" . PHP_EOL);
            }
        );
    }

    /**
     * Tests titleSeparator prepend
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitleSeparatorPrepend(UnitTester $I)
    {
        $this->specify(
            "titleSeparator prepend returns incorrect result",
            function (UnitTester $I) {
                Tag::resetInput();
                Tag::setTitle('This is my title');
                Tag::setTitleSeparator('-');
                Tag::prependTitle('PhalconPHP');

                expect(Tag::renderTitle(UnitTester $I))->equals("<title>PhalconPHP-This is my title</title>" . PHP_EOL);
            }
        );
    }
}
