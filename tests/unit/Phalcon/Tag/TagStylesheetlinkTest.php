<?php
/**
 * TagStylesheetLinkTest.php
 * \Phalcon\Tag
 *
 * Tests the \Phalcon\Tag component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Tag;

use \PhalconTest\Tag as PhTTag;

class TagStylesheetLinkTest extends Helper\TagBase
{
    /**
     * Tests stylesheetLink with string parameter for a local link
     *
     * @issue  1486
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-12
     */
    public function testStylesheetLinkStringParameterLocal()
    {
        $this->specify(
            "stylesheetLink with string parameter local returns invalid HTML Strict",
            function () {

                PhTTag::resetInput();
                $options  = 'css/phalcon.css';
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="/css/phalcon.css" />'
                          . PHP_EOL;

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual   = PhTTag::stylesheetLink($options);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "stylesheetLink with string parameter local returns invalid HTML HTML5",
            function () {

                PhTTag::resetInput();
                $options  = 'css/phalcon.css';
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="/css/phalcon.css">'
                          . PHP_EOL;

                PhTTag::setDocType(PhTTag::HTML5);
                $actual   = PhTTag::stylesheetLink($options);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests stylesheetLink with array parameter for a local link
     *
     * @issue  1486
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-12
     */
    public function testStylesheetLinkArrayParameterLocal()
    {
        $this->specify(
            "stylesheetLink with array parameter local returns invalid HTML Strict",
            function () {

                PhTTag::resetInput();
                $options  = ['css/phalcon.css'];
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="/css/phalcon.css" />'
                          . PHP_EOL;

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual   = PhTTag::stylesheetLink($options);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "stylesheetLink with array parameter local returns invalid HTML HTML5",
            function () {

                PhTTag::resetInput();
                $options  = ['css/phalcon.css'];
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="/css/phalcon.css">'
                          . PHP_EOL;

                PhTTag::setDocType(PhTTag::HTML5);
                $actual   = PhTTag::stylesheetLink($options);

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

                PhTTag::resetInput();
                $options  = 'http://phalconphp.com/css/phalcon.css';
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="http://phalconphp.com/css/phalcon.css" />'
                          . PHP_EOL;

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual   = PhTTag::stylesheetLink($options, false);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "stylesheetLink with string parameter remote returns invalid HTML HTML5",
            function () {

                PhTTag::resetInput();
                $options  = 'http://phalconphp.com/css/phalcon.css';
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="http://phalconphp.com/css/phalcon.css">'
                          . PHP_EOL;

                PhTTag::setDocType(PhTTag::HTML5);
                $actual   = PhTTag::stylesheetLink($options, false);

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

                PhTTag::resetInput();
                $options  = ['http://phalconphp.com/css/phalcon.css'];
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="http://phalconphp.com/css/phalcon.css" />'
                          . PHP_EOL;

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual   = PhTTag::stylesheetLink($options, false);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "stylesheetLink with array parameter remote returns invalid HTML HTML5",
            function () {

                PhTTag::resetInput();
                $options  = ['http://phalconphp.com/css/phalcon.css'];
                $expected = '<link rel="stylesheet" type="text/css" '
                          . 'href="http://phalconphp.com/css/phalcon.css">'
                          . PHP_EOL;

                PhTTag::setDocType(PhTTag::HTML5);
                $actual   = PhTTag::stylesheetLink($options, false);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests stylesheetLink overriding the rel link local
     *
     * @issue  2142
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-12
     */
    public function testStylesheetLinkOverrideRelLink()
    {
        $this->specify(
            "stylesheetLink overriding rel local returns invalid HTML Strict",
            function () {

                PhTTag::resetInput();
                $options  = [
                    'css/phalcon.css',
                    'rel' => 'stylesheet/less',
                ];
                $expected = '<link rel="stylesheet/less" type="text/css" '
                          . 'href="/css/phalcon.css" />'
                          . PHP_EOL;

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual   = PhTTag::stylesheetLink($options);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "stylesheetLink overriding rel local returns invalid HTML Strict",
            function () {

                PhTTag::resetInput();
                $options  = [
                    'css/phalcon.css',
                    'rel' => 'stylesheet/less',
                ];
                $expected = '<link rel="stylesheet/less" type="text/css" '
                          . 'href="/css/phalcon.css">'
                          . PHP_EOL;

                PhTTag::setDocType(PhTTag::HTML5);
                $actual   = PhTTag::stylesheetLink($options);

                expect($actual)->equals($expected);
            }
        );
    }
}
