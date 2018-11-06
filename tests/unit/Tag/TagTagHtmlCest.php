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
class TagTagHtmlTest extends TagBase
{
    /**
     * Tests tagHtml with name parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlName(UnitTester $I)
    {
        $this->specify(
            "tagHtml with name parameter returns invalid HTML Strict",
            function (UnitTester $I) {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside>';

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual = Tag::tagHtml($name);

                $I->assertEquals($expected, $actual);
            }
        );

        $this->specify(
            "tagHtml with name parameter returns invalid HTML XHTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside></aside>';

                Tag::setDocType(Tag::HTML5);
                $actual = Tag::tagHtml($name);

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests tagHtml with name parameter and self close
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testNameSelfClose(UnitTester $I)
    {
        $this->specify(
            "tagHtml with name parameter and self close returns invalid HTML Strict",
            function (UnitTester $I) {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside />';

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual = Tag::tagHtml($name, null, true);

                $I->assertEquals($expected, $actual);
            }
        );

        $this->specify(
            "tagHtml with name parameter and self close returns invalid HTML XHTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside></aside>';

                Tag::setDocType(Tag::HTML5);
                $actual = Tag::tagHtml($name, null, true);

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests tagHtml with name parameter and only start
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlNameOnlyStart(UnitTester $I)
    {
        $this->specify(
            "tagHtml with name parameter and only start returns invalid HTML Strict",
            function (UnitTester $I) {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside>';

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual = Tag::tagHtml($name, null, null, true);

                $I->assertEquals($expected, $actual);
            }
        );

        $this->specify(
            "tagHtml with name parameter and only start returns invalid HTML XHTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside>';

                Tag::setDocType(Tag::HTML5);
                $actual = Tag::tagHtml($name, null, null, true);

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests tagHtml with name parameter and EOL
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlNameEol(UnitTester $I)
    {
        $this->specify(
            "tagHtml with name parameter and EOL returns invalid HTML Strict",
            function (UnitTester $I) {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside>' . PHP_EOL;

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual = Tag::tagHtml($name, null, null, null, true);

                $I->assertEquals($expected, $actual);
            }
        );

        $this->specify(
            "tagHtml with name parameter and EOL returns invalid HTML XHTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $name     = 'aside';
                $expected = '<aside></aside>' . PHP_EOL;

                Tag::setDocType(Tag::HTML5);
                $actual = Tag::tagHtml($name, null, null, null, true);

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests tagHtml with array parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlWithArray(UnitTester $I)
    {
        $this->specify(
            "tagHtml with array parameter returns invalid HTML Strict",
            function (UnitTester $I) {
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

                $I->assertEquals($expected, $actual);
            }
        );

        $this->specify(
            "tagHtml with array parameter returns invalid HTML XHTML",
            function (UnitTester $I) {
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

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests tagHtmlClose
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlClose(UnitTester $I)
    {
        $this->specify(
            "tagHtmlClose returns invalid HTML Strict",
            function (UnitTester $I) {
                Tag::resetInput();
                $name     = 'canvas';
                $expected = '</canvas>';

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual = Tag::tagHtmlClose($name);

                $I->assertEquals($expected, $actual);
            }
        );

        $this->specify(
            "tagHtmlClose returns invalid HTML XHTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $name     = 'canvas';
                $expected = '</canvas>';

                Tag::setDocType(Tag::HTML5);
                $actual = Tag::tagHtmlClose($name);

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests tagHtmlClose with EOL
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlCloseEol(UnitTester $I)
    {
        $this->specify(
            "tagHtmlClose with EOL returns invalid HTML Strict",
            function (UnitTester $I) {
                Tag::resetInput();
                $name     = 'canvas';
                $expected = '</canvas>' . PHP_EOL;

                Tag::setDocType(Tag::XHTML10_STRICT);
                $actual = Tag::tagHtmlClose($name, true);

                $I->assertEquals($expected, $actual);
            }
        );

        $this->specify(
            "tagHtmlClose with EOL returns invalid HTML XHTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $name     = 'canvas';
                $expected = '</canvas>' . PHP_EOL;

                Tag::setDocType(Tag::HTML5);
                $actual = Tag::tagHtmlClose($name, true);

                $I->assertEquals($expected, $actual);
            }
        );
    }
}
