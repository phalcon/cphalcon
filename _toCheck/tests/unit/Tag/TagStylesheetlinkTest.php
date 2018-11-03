<?php

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Tag\TagStylesheetLinkTest
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
class TagStylesheetlinkTest extends UnitTest
{
    /**
     * Tests stylesheetLink with string parameter for a local link
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1486
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-12
     */
    public function testStylesheetLinkStringParameterLocal()
    {
        $this->specify(
            "stylesheetLink with string parameter local returns invalid HTML Strict",
            function () {
                Tag::resetInput();
                $options  = 'css/phalcon.css';
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="/css/phalcon.css" />'
                          . PHP_EOL;

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual   = Tag::stylesheetLink($options);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "stylesheetLink with string parameter local returns invalid HTML HTML5",
            function () {
                Tag::resetInput();
                $options  = 'css/phalcon.css';
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="/css/phalcon.css">'
                          . PHP_EOL;

                Tag::setDocType(Tag::HTML5);
                $actual   = Tag::stylesheetLink($options);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests stylesheetLink with array parameter for a local link
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1486
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-12
     */
    public function testStylesheetLinkArrayParameterLocal()
    {
        $this->specify(
            "stylesheetLink with array parameter local returns invalid HTML Strict",
            function () {
                Tag::resetInput();
                $options  = ['css/phalcon.css'];
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="/css/phalcon.css" />'
                          . PHP_EOL;

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual   = Tag::stylesheetLink($options);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "stylesheetLink with array parameter local returns invalid HTML HTML5",
            function () {
                Tag::resetInput();
                $options  = ['css/phalcon.css'];
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="/css/phalcon.css">'
                          . PHP_EOL;

                Tag::setDocType(Tag::HTML5);
                $actual   = Tag::stylesheetLink($options);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests stylesheetLink with string parameter for a remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testStylesheetLinkStringParameterRemote()
    {
        $this->specify(
            "stylesheetLink with string parameter remote returns invalid HTML Strict",
            function () {
                Tag::resetInput();
                $options  = 'http://phalconphp.com/css/phalcon.css';
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="http://phalconphp.com/css/phalcon.css" />'
                          . PHP_EOL;

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual   = Tag::stylesheetLink($options, false);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "stylesheetLink with string parameter remote returns invalid HTML HTML5",
            function () {
                Tag::resetInput();
                $options  = 'http://phalconphp.com/css/phalcon.css';
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="http://phalconphp.com/css/phalcon.css">'
                          . PHP_EOL;

                Tag::setDocType(Tag::HTML5);
                $actual   = Tag::stylesheetLink($options, false);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests stylesheetLink with array parameter for a remote link
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testStylesheetLinkArrayParameterRemote()
    {
        $this->specify(
            "stylesheetLink with array parameter remote returns invalid HTML Strict",
            function () {
                Tag::resetInput();
                $options  = ['http://phalconphp.com/css/phalcon.css'];
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="http://phalconphp.com/css/phalcon.css" />'
                          . PHP_EOL;

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual   = Tag::stylesheetLink($options, false);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "stylesheetLink with array parameter remote returns invalid HTML HTML5",
            function () {
                Tag::resetInput();
                $options  = ['http://phalconphp.com/css/phalcon.css'];
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="http://phalconphp.com/css/phalcon.css">'
                          . PHP_EOL;

                Tag::setDocType(Tag::HTML5);
                $actual   = Tag::stylesheetLink($options, false);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests stylesheetLink overriding the rel link local
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2142
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-12
     */
    public function testStylesheetLinkOverrideRelLink()
    {
        $this->specify(
            "stylesheetLink overriding rel local returns invalid HTML Strict",
            function () {
                Tag::resetInput();
                $options  = [
                    'css/phalcon.css',
                    'rel' => 'stylesheet/less',
                ];
                $expected = '<link rel="stylesheet/less" type="text/css" '
                          . 'href="/css/phalcon.css" />'
                          . PHP_EOL;

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual   = Tag::stylesheetLink($options);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "stylesheetLink overriding rel local returns invalid HTML Strict",
            function () {
                Tag::resetInput();
                $options  = [
                    'css/phalcon.css',
                    'rel' => 'stylesheet/less',
                ];
                $expected = '<link rel="stylesheet/less" type="text/css" '
                          . 'href="/css/phalcon.css">'
                          . PHP_EOL;

                Tag::setDocType(Tag::HTML5);
                $actual   = Tag::stylesheetLink($options);

                expect($actual)->equals($expected);
            }
        );
    }
}
