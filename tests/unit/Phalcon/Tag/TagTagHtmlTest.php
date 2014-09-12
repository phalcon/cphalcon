<?php
/**
 * TagTagHtmlTest.php
 * \Phalcon\Tag
 *
 * Tests the \Phalcon\Tag component
 *
 * PhalconPHP Framework
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

use \Phalcon\Tag as PhTag;

class TagTagHtmlTest extends TagBase
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

                $name     = 'aside';
                $expected = '<aside></aside>';

                PhTag::setDocType(PhTag::XHTML10_STRICT);
                $actual = PhTag::tagHtml($name);

                expect($expected)->equals($actual);
            }
        );

        $this->specify(
            "tagHtml with name parameter returns invalid HTML XHTML",
            function () {

                $name     = 'aside';
                $expected = '<aside>';

                PhTag::setDocType(PhTag::HTML5);
                $actual = PhTag::tagHtml($name);

                expect($expected)->equals($actual);
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

                $name     = 'aside';
                $expected = '<aside></aside>';

                PhTag::setDocType(PhTag::XHTML10_STRICT);
                $actual = PhTag::tagHtml($name, null, true);

                expect($expected)->equals($actual);
            }
        );

        $this->specify(
            "tagHtml with name parameter and self close returns invalid HTML XHTML",
            function () {

                $name     = 'aside';
                $expected = '<aside />';

                PhTag::setDocType(PhTag::HTML5);
                $actual = PhTag::tagHtml($name, null, true);

                expect($expected)->equals($actual);
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

                $name     = 'aside';
                $expected = '<aside>';

                PhTag::setDocType(PhTag::XHTML10_STRICT);
                $actual = PhTag::tagHtml($name, null, null, true);

                expect($expected)->equals($actual);
            }
        );

        $this->specify(
            "tagHtml with name parameter and only start returns invalid HTML XHTML",
            function () {

                $name     = 'aside';
                $expected = '<aside>';

                PhTag::setDocType(PhTag::HTML5);
                $actual = PhTag::tagHtml($name, null, null, true);

                expect($expected)->equals($actual);
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

                $name     = 'aside';
                $expected = '<aside>' . PHP_EOL;

                PhTag::setDocType(PhTag::XHTML10_STRICT);
                $actual = PhTag::tagHtml($name, null, null, null, true);

                expect($expected)->equals($actual);
            }
        );

        $this->specify(
            "tagHtml with name parameter and EOL returns invalid HTML XHTML",
            function () {

                $name     = 'aside';
                $expected = '<aside></aside>' . PHP_EOL;

                PhTag::setDocType(PhTag::HTML5);
                $actual = PhTag::tagHtml($name, null, null, null, true);

                expect($expected)->equals($actual);
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

                $name     = 'canvas';
                $options  = [
                    'id'     => 'canvas1',
                    'width'  => 300,
                    'height' => 300,
                ];
                $expected = '<canvas id="canvas1" width="300" height="300">'
                          . '</canvas>';

                PhTag::setDocType(PhTag::XHTML10_STRICT);
                $actual = PhTag::tagHtml($name, $options);

                expect($expected)->equals($actual);
            }
        );

        $this->specify(
            "tagHtml with array parameter returns invalid HTML XHTML",
            function () {

                $name     = 'canvas';
                $options  = [
                    'id'     => 'canvas1',
                    'width'  => 300,
                    'height' => 300,
                ];
                $expected = '<canvas id="canvas1" width="300" height="300">';

                PhTag::setDocType(PhTag::HTML5);
                $actual = PhTag::tagHtml($name, $options);

                expect($expected)->equals($actual);
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

                $name     = 'canvas';
                $expected = '</canvas>';

                PhTag::setDocType(PhTag::XHTML10_STRICT);
                $actual = PhTag::tagHtmlClose($name);

                expect($expected)->equals($actual);
            }
        );

        $this->specify(
            "tagHtmlClose returns invalid HTML XHTML",
            function () {

                $name     = 'canvas';
                $expected = '<canvas id="canvas1" width="300" height="300">';

                PhTag::setDocType(PhTag::HTML5);
                $actual = PhTag::tagHtmlClose($name);

                expect($expected)->equals($actual);
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

                $name     = 'canvas';
                $expected = '</canvas>' . PHP_EOL;

                PhTag::setDocType(PhTag::XHTML10_STRICT);
                $actual = PhTag::tagHtmlClose($name);

                expect($expected)->equals($actual);
            }
        );

        $this->specify(
            "tagHtmlClose with EOL returns invalid HTML XHTML",
            function () {

                $name     = 'canvas';
                $expected = '</canvas>' . PHP_EOL;

                PhTag::setDocType(PhTag::HTML5);
                $actual = PhTag::tagHtmlClose($name);

                expect($expected)->equals($actual);
            }
        );
    }
}
