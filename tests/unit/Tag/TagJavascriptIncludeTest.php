<?php

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Tag\TagJavascriptIncludeTest
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
class TagJavascriptIncludeTest extends UnitTest
{
    /**
     * Tests iavascriptInclude with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeLocal()
    {
        $this->specify(
            "iavascriptInclude with string parameter local link returns invalid HTML",
            function () {
                Tag::resetInput();
                $options  = 'js/phalcon.js';
                $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
                $actual   = Tag::javascriptInclude($options);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests iavascriptInclude with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeWithArrayLocal()
    {
        $this->specify(
            "javascriptInclude with array parameter local link returns invalid HTML",
            function () {
                Tag::resetInput();
                $options  = ['js/phalcon.js'];
                $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
                $actual   = Tag::javascriptInclude($options);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests javascriptInclude with a string as the second parameter - local link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeWithStringAsSecondParameterLocal()
    {
        $this->specify(
            "javascriptInclude with a string as the second parameter local link returns invalid HTML",
            function () {
                Tag::resetInput();
                $options  = ['js/phalcon.js'];
                $expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
                $actual   = Tag::javascriptInclude($options, 'hello');

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests javascriptInclude for a remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeRemote()
    {
        $this->specify(
            "iavascriptInclude with a string parameter remote link returns invalid HTML",
            function () {
                Tag::resetInput();
                $options  = 'http://my.local.com/js/phalcon.js';
                $expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
                $actual   = Tag::javascriptInclude($options, false);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests javascriptInclude with array parameter for a remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testJavascriptIncludeWithArrayRemote()
    {
        $this->specify(
            "iavascriptInclude with array second parameter remote link returns invalid HTML",
            function () {
                Tag::resetInput();
                $options  = ['http://my.local.com/js/phalcon.js'];
                $expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
                $actual   = Tag::javascriptInclude($options, false);

                expect($actual)->equals($expected);
            }
        );
    }
}
