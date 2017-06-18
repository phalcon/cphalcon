<?php

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Tag\TagTagHtmlTest
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
class TagTagHtmlTest extends UnitTest
{
    /**
     * Tests tagHtml with name parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlName()
    {
        $this->specify(
            "tagHtml with name parameter returns invalid HTML Strict",
            function () {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside>';

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual = Tag::tagHtml($name);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "tagHtml with name parameter returns invalid HTML XHTML",
            function () {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside></aside>';

                Tag::setDocType(Tag::HTML5);
                $actual = Tag::tagHtml($name);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests tagHtml with name parameter and self close
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testNameSelfClose()
    {
        $this->specify(
            "tagHtml with name parameter and self close returns invalid HTML Strict",
            function () {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside />';

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual = Tag::tagHtml($name, null, true);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "tagHtml with name parameter and self close returns invalid HTML XHTML",
            function () {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside></aside>';

                Tag::setDocType(Tag::HTML5);
                $actual = Tag::tagHtml($name, null, true);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests tagHtml with name parameter and only start
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlNameOnlyStart()
    {
        $this->specify(
            "tagHtml with name parameter and only start returns invalid HTML Strict",
            function () {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside>';

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual = Tag::tagHtml($name, null, null, true);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "tagHtml with name parameter and only start returns invalid HTML XHTML",
            function () {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside>';

                Tag::setDocType(Tag::HTML5);
                $actual = Tag::tagHtml($name, null, null, true);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests tagHtml with name parameter and EOL
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlNameEol()
    {
        $this->specify(
            "tagHtml with name parameter and EOL returns invalid HTML Strict",
            function () {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside>' . PHP_EOL;

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual = Tag::tagHtml($name, null, null, null, true);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "tagHtml with name parameter and EOL returns invalid HTML XHTML",
            function () {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside></aside>' . PHP_EOL;

                Tag::setDocType(Tag::HTML5);
                $actual = Tag::tagHtml($name, null, null, null, true);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests tagHtml with array parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlWithArray()
    {
        $this->specify(
            "tagHtml with array parameter returns invalid HTML Strict",
            function () {
                Tag::resetInput();
                $name     = 'canvas';
                $options  = [
                    'id'     => 'canvas1',
                    'width'  => 300,
                    'height' => 300,
                ];
                $expected = '<canvas id="canvas1" width="300" height="300">';

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual = Tag::tagHtml($name, $options);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "tagHtml with array parameter returns invalid HTML XHTML",
            function () {
                Tag::resetInput();
                $name     = 'canvas';
                $options  = [
                    'id'     => 'canvas1',
                    'width'  => 300,
                    'height' => 300,
                ];
                $expected = '<canvas id="canvas1" width="300" height="300">'
                          . '</canvas>';

                Tag::setDocType(Tag::HTML5);
                $actual = Tag::tagHtml($name, $options);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests tagHtmlClose
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlClose()
    {
        $this->specify(
            "tagHtmlClose returns invalid HTML Strict",
            function () {
                Tag::resetInput();
                $name     = 'canvas';
                $expected = '</canvas>';

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual = Tag::tagHtmlClose($name);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "tagHtmlClose returns invalid HTML XHTML",
            function () {
                Tag::resetInput();
                $name     = 'canvas';
                $expected = '</canvas>';

                Tag::setDocType(Tag::HTML5);
                $actual = Tag::tagHtmlClose($name);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests tagHtmlClose with EOL
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlCloseEol()
    {
        $this->specify(
            "tagHtmlClose with EOL returns invalid HTML Strict",
            function () {
                Tag::resetInput();
                $name     = 'canvas';
                $expected = '</canvas>' . PHP_EOL;

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual = Tag::tagHtmlClose($name, true);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "tagHtmlClose with EOL returns invalid HTML XHTML",
            function () {
                Tag::resetInput();
                $name     = 'canvas';
                $expected = '</canvas>' . PHP_EOL;

                Tag::setDocType(Tag::HTML5);
                $actual = Tag::tagHtmlClose($name, true);

                expect($actual)->equals($expected);
            }
        );
    }
}
