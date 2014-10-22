<?php
/**
 * TagTagHtmlTest.php
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

class TagTagHtmlTest extends Helper\TagBase
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

                PhTTag::resetInput();
                $name     = 'aside';
                $expected = '<aside>';

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual = PhTTag::tagHtml($name);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "tagHtml with name parameter returns invalid HTML XHTML",
            function () {

                PhTTag::resetInput();
                $name     = 'aside';
                $expected = '<aside></aside>';

                PhTTag::setDocType(PhTTag::HTML5);
                $actual = PhTTag::tagHtml($name);

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

                PhTTag::resetInput();
                $name     = 'aside';
                $expected = '<aside />';

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual = PhTTag::tagHtml($name, null, true);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "tagHtml with name parameter and self close returns invalid HTML XHTML",
            function () {

                PhTTag::resetInput();
                $name     = 'aside';
                $expected = '<aside></aside>';

                PhTTag::setDocType(PhTTag::HTML5);
                $actual = PhTTag::tagHtml($name, null, true);

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

                PhTTag::resetInput();
                $name     = 'aside';
                $expected = '<aside>';

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual = PhTTag::tagHtml($name, null, null, true);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "tagHtml with name parameter and only start returns invalid HTML XHTML",
            function () {

                PhTTag::resetInput();
                $name     = 'aside';
                $expected = '<aside>';

                PhTTag::setDocType(PhTTag::HTML5);
                $actual = PhTTag::tagHtml($name, null, null, true);

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

                PhTTag::resetInput();
                $name     = 'aside';
                $expected = '<aside>' . PHP_EOL;

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual = PhTTag::tagHtml($name, null, null, null, true);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "tagHtml with name parameter and EOL returns invalid HTML XHTML",
            function () {

                PhTTag::resetInput();
                $name     = 'aside';
                $expected = '<aside></aside>' . PHP_EOL;

                PhTTag::setDocType(PhTTag::HTML5);
                $actual = PhTTag::tagHtml($name, null, null, null, true);

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

                PhTTag::resetInput();
                $name     = 'canvas';
                $options  = [
                    'id'     => 'canvas1',
                    'width'  => 300,
                    'height' => 300,
                ];
                $expected = '<canvas id="canvas1" width="300" height="300">';

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual = PhTTag::tagHtml($name, $options);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "tagHtml with array parameter returns invalid HTML XHTML",
            function () {

                PhTTag::resetInput();
                $name     = 'canvas';
                $options  = [
                    'id'     => 'canvas1',
                    'width'  => 300,
                    'height' => 300,
                ];
                $expected = '<canvas id="canvas1" width="300" height="300">'
                          . '</canvas>';

                PhTTag::setDocType(PhTTag::HTML5);
                $actual = PhTTag::tagHtml($name, $options);

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

                PhTTag::resetInput();
                $name     = 'canvas';
                $expected = '</canvas>';

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual = PhTTag::tagHtmlClose($name);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "tagHtmlClose returns invalid HTML XHTML",
            function () {

                PhTTag::resetInput();
                $name     = 'canvas';
                $expected = '</canvas>';

                PhTTag::setDocType(PhTTag::HTML5);
                $actual = PhTTag::tagHtmlClose($name);

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

                PhTTag::resetInput();
                $name     = 'canvas';
                $expected = '</canvas>' . PHP_EOL;

                PhTTag::setDocType(PhTTag::XHTML10_STRICT);
                $actual = PhTTag::tagHtmlClose($name, true);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "tagHtmlClose with EOL returns invalid HTML XHTML",
            function () {

                PhTTag::resetInput();
                $name     = 'canvas';
                $expected = '</canvas>' . PHP_EOL;

                PhTTag::setDocType(PhTTag::HTML5);
                $actual = PhTTag::tagHtmlClose($name, true);

                expect($actual)->equals($expected);
            }
        );
    }
}
