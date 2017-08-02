<?php

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;

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
class TagTitleTest extends UnitTest
{
    /**
     * Tests malicious content in the title
     *
     * @issue  11185
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-13
     */
    public function testGetTitleWithoutMaliciousContent()
    {
        $this->specify(
            "getTitle returns malicious content",
            function () {
                $tag = new Tag();

                $value = "Hello </title><script>alert('Got your nose!');</script><title>";

                $tag->setTitle($value);
                $expected = "<title>Hello &lt;/title&gt;&lt;script&gt;alert(&#039;Got your nose!&#039;);&lt;/script&gt;&lt;title&gt;</title>" . PHP_EOL;

                expect($tag->getTitle())->equals($expected);
            }
        );
    }

    /**
     * Tests setTitle
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitle()
    {
        $this->specify(
            "setTitle returns incorrect result",
            function () {
                $tag = new Tag();

                $value = 'This is my title';
                $tag->setTitle($value);

                expect($tag->getTitle())->equals("<title>{$value}</title>" . PHP_EOL);
                
                expect($tag->getTitle(false))->equals("{$value}");
            }
        );
    }

    /**
     * Tests appendTitle
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testAppendTitle()
    {
        $this->specify(
            "appendTitle returns incorrect result",
            function () {
                $tag = new Tag();

                $tag->setTitle('Title');
                $tag->appendTitle('Class');

                expect($tag->getTitle())->equals("<title>TitleClass</title>" . PHP_EOL);

                $tag = new Tag();

                $tag->setTitle('This is my title');
                $tag->appendTitle(' - Welcome!');

                expect($tag->getTitle())->equals("<title>This is my title - Welcome!</title>" . PHP_EOL);

                $tag = new Tag();

                $tag->setTitle('Title');
                $tag->setTitleSeparator('|');
                $tag->appendTitle('Class');

                expect($tag->getTitle())->equals("<title>Title|Class</title>" . PHP_EOL);

                $tag = new Tag();
                
                $tag->setTitle('Main');
                $tag->setTitleSeparator(' - ');
                $tag->appendTitle('Category');
                $tag->appendTitle('Title');
                
                expect($tag->getTitle())->equals("<title>Main - Category - Title</title>" . PHP_EOL);
            }
        );
    }

    /**
     * Tests prependTitle
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testPrependTitle()
    {
        $this->specify(
            "prependTitle returns incorrect result",
            function () {
                $tag = new Tag();

                $tag->setTitleSeparator('');
                $tag->setTitle('This is my title');
                $tag->prependTitle('PhalconPHP - ');

                expect($tag->getTitle())->equals("<title>PhalconPHP - This is my title</title>" . PHP_EOL);

                $tag = new Tag();
                
                $tag->setTitle('Title');
                $tag->setTitleSeparator('|');
                $tag->prependTitle('Class');

                expect($tag->getTitle())->equals('<title>Class|Title</title>' . PHP_EOL);

                $tag = new Tag();
                
                $tag->setTitle('Main');
                $tag->setTitleSeparator(' - ');
                $tag->prependTitle('Category');
                $tag->prependTitle('Title');
                
                expect($tag->getTitle())->equals("<title>Title - Category - Main</title>" . PHP_EOL);
            }
        );
    }

    /**
     * Tests titleSeparator
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitleSeparator()
    {
        $this->specify(
            "titleSeparator returns incorrect result",
            function () {
                $tag = new Tag();

                $tag->setTitleSeparator('-');

                expect($tag->getTitleSeparator())->equals("-");
            }
        );
    }

    /**
     * Tests titleSeparator with append
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitleSeparatorAppend()
    {
        $this->specify(
            "titleSeparator with append returns incorrect result",
            function () {
                $tag = new Tag();

                $tag->setTitle('This is my title');
                $tag->setTitleSeparator('-');
                $tag->appendTitle('PhalconPHP');

                expect($tag->getTitle())->equals("<title>This is my title-PhalconPHP</title>" . PHP_EOL);
            }
        );
    }

    /**
     * Tests titleSeparator prepend
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-05
     */
    public function testSetTitleSeparatorPrepend()
    {
        $this->specify(
            "titleSeparator prepend returns incorrect result",
            function () {
                $tag = new Tag();

                $tag->setTitle('This is my title');
                $tag->setTitleSeparator('-');
                $tag->prependTitle('PhalconPHP');

                expect($tag->getTitle())->equals("<title>PhalconPHP-This is my title</title>" . PHP_EOL);
            }
        );
    }
}
