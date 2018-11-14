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

class TagTagHtmlCest extends TagBase
{
    /**
     * Tests tagHtml with name parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlName(UnitTester $I)
    {
        Tag::resetInput();
        $name     = 'aside';
        $expected = '<aside>';

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::tagHtml($name);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $name     = 'aside';
        $expected = '<aside></aside>';

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::tagHtml($name);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests tagHtml with name parameter and self close
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testNameSelfClose(UnitTester $I)
    {
        Tag::resetInput();
        $name     = 'aside';
        $expected = '<aside />';

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::tagHtml($name, null, true);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $name     = 'aside';
        $expected = '<aside></aside>';

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::tagHtml($name, null, true);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests tagHtml with name parameter and only start
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlNameOnlyStart(UnitTester $I)
    {
        Tag::resetInput();
        $name     = 'aside';
        $expected = '<aside>';

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::tagHtml($name, null, null, true);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $name     = 'aside';
        $expected = '<aside>';

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::tagHtml($name, null, null, true);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests tagHtml with name parameter and EOL
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlNameEol(UnitTester $I)
    {
        Tag::resetInput();
        $name     = 'aside';
        $expected = '<aside>' . PHP_EOL;

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::tagHtml($name, null, null, null, true);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $name     = 'aside';
        $expected = '<aside></aside>' . PHP_EOL;

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::tagHtml($name, null, null, null, true);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests tagHtml with array parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlWithArray(UnitTester $I)
    {
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

    /**
     * Tests tagHtmlClose
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlClose(UnitTester $I)
    {
        Tag::resetInput();
        $name     = 'canvas';
        $expected = '</canvas>';

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::tagHtmlClose($name);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $name     = 'canvas';
        $expected = '</canvas>';

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::tagHtmlClose($name);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests tagHtmlClose with EOL
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTagHtmlCloseEol(UnitTester $I)
    {
        Tag::resetInput();
        $name     = 'canvas';
        $expected = '</canvas>' . PHP_EOL;

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::tagHtmlClose($name, true);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $name     = 'canvas';
        $expected = '</canvas>' . PHP_EOL;

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::tagHtmlClose($name, true);

        $I->assertEquals($expected, $actual);
    }
}
