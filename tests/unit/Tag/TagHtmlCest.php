<?php
declare(strict_types=1);

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
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

/**
 * Class TagHtmlCest
 */
class TagHtmlCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: tagHtml() - name parameter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagTagHtmlName(UnitTester $I)
    {
        $I->wantToTest("Tag - tagHtml() - name parameter");
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
     * Tests Phalcon\Tag :: tagHtml() - name parameter and self close
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagNameSelfClose(UnitTester $I)
    {
        $I->wantToTest("Tag - tagHtml() - name parameter self close");
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
     * Tests Phalcon\Tag :: tagHtml() - name parameter and only start
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagTagHtmlNameOnlyStart(UnitTester $I)
    {
        $I->wantToTest("Tag - tagHtml() - name parameter only start");
        Tag::resetInput();
        $name     = 'aside';
        $expected = '<aside>';

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::tagHtml($name, null, false, true);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $name     = 'aside';
        $expected = '<aside>';

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::tagHtml($name, null, false, true);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: tagHtml() - name parameter and EOL
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagTagHtmlNameEol(UnitTester $I)
    {
        $I->wantToTest("Tag - tagHtml() - name parameter EOL");
        Tag::resetInput();
        $name     = 'aside';
        $expected = '<aside>' . PHP_EOL;

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::tagHtml($name, null, false, false, true);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $name     = 'aside';
        $expected = '<aside></aside>' . PHP_EOL;

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::tagHtml($name, null, false, false, true);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: tagHtml() - array parameter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function tagTagHtmlWithArray(UnitTester $I)
    {
        $I->wantToTest("Tag - tagHtml() - array");
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
}
