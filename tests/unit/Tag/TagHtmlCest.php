<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Tag;

use Codeception\Example;
use Phalcon\Tag;
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class TagHtmlCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: tagHtml() - name parameter
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2014-09-05
     *
     * @dataProvider tagHtmlNameProvider
     */
    public function tagTagHtmlName(UnitTester $I, Example $example)
    {
        $I->wantToTest('Tag - tagHtml() - name parameter');

        Tag::resetInput();

        $name = $example['name'];

        Tag::setDocType(
            $example['docType']
        );

        $I->assertEquals(
            $example['expected'],
            Tag::tagHtml($name)
        );
    }

    private function tagHtmlNameProvider(): array
    {
        return [
            [
                'name'     => 'aside',
                'docType'  => Tag::XHTML10_STRICT,
                'expected' => '<aside>',
            ],

            [
                'name'     => 'aside',
                'docType'  => Tag::HTML5,
                'expected' => '<aside></aside>',
            ],
        ];
    }

    /**
     * Tests Phalcon\Tag :: tagHtml() - name parameter and self close
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagNameSelfClose(UnitTester $I)
    {
        $I->wantToTest('Tag - tagHtml() - name parameter self close');

        Tag::resetInput();

        $name     = 'aside';
        $expected = '<aside />';

        Tag::setDocType(
            Tag::XHTML10_STRICT
        );

        $actual = Tag::tagHtml($name, null, true);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();

        $name     = 'aside';
        $expected = '<aside></aside>';

        Tag::setDocType(
            Tag::HTML5
        );

        $actual = Tag::tagHtml($name, null, true);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: tagHtml() - name parameter and only start
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagTagHtmlNameOnlyStart(UnitTester $I)
    {
        $I->wantToTest('Tag - tagHtml() - name parameter only start');

        Tag::resetInput();

        $name     = 'aside';
        $expected = '<aside>';

        Tag::setDocType(
            Tag::XHTML10_STRICT
        );

        $actual = Tag::tagHtml($name, null, false, true);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();

        $name     = 'aside';
        $expected = '<aside>';

        Tag::setDocType(
            Tag::HTML5
        );

        $actual = Tag::tagHtml($name, null, false, true);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: tagHtml() - name parameter and EOL
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagTagHtmlNameEol(UnitTester $I)
    {
        $I->wantToTest('Tag - tagHtml() - name parameter EOL');

        Tag::resetInput();

        $name     = 'aside';
        $expected = '<aside>' . PHP_EOL;

        Tag::setDocType(
            Tag::XHTML10_STRICT
        );

        $actual = Tag::tagHtml($name, null, false, false, true);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();

        $name     = 'aside';
        $expected = '<aside></aside>' . PHP_EOL;

        Tag::setDocType(
            Tag::HTML5
        );

        $actual = Tag::tagHtml($name, null, false, false, true);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: tagHtml() - array parameter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagTagHtmlWithArray(UnitTester $I)
    {
        $I->wantToTest('Tag - tagHtml() - array');

        Tag::resetInput();

        $name    = 'canvas';
        $options = [
            'id'     => 'canvas1',
            'width'  => 300,
            'height' => 300,
        ];

        $expected = '<canvas id="canvas1" width="300" height="300">';

        Tag::setDocType(
            Tag::XHTML10_STRICT
        );

        $actual = Tag::tagHtml($name, $options);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();

        $name    = 'canvas';
        $options = [
            'id'     => 'canvas1',
            'width'  => 300,
            'height' => 300,
        ];

        $expected = '<canvas id="canvas1" width="300" height="300"></canvas>';

        Tag::setDocType(
            Tag::HTML5
        );

        $actual = Tag::tagHtml($name, $options);

        $I->assertEquals($expected, $actual);
    }
}
