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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Helpers\TagSetup;
use UnitTester;

class StylesheetLinkCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: stylesheetLink() - string parameter for a local link
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1486
     * @author Phalcon Team <team@phalcon.io>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-12
     */
    public function tagStylesheetLinkStringParameterLocal(UnitTester $I)
    {
        $I->wantToTest('Tag - stylesheetLink() - string parameter for a local link');

        Tag::resetInput();

        $options  = 'css/phalcon.css';
        $expected = '<link rel="stylesheet" type="text/css" href="/css/phalcon.css" />' . PHP_EOL;

        Tag::setDocType(
            Tag::XHTML10_STRICT
        );

        $actual = Tag::stylesheetLink($options);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();

        $options  = 'css/phalcon.css';
        $expected = '<link rel="stylesheet" type="text/css" href="/css/phalcon.css">' . PHP_EOL;

        Tag::setDocType(
            Tag::HTML5
        );

        $actual = Tag::stylesheetLink($options);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: stylesheetLink() - array parameter for a local link
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1486
     * @author Phalcon Team <team@phalcon.io>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-12
     */
    public function tagStylesheetLinkArrayParameterLocal(UnitTester $I)
    {
        $I->wantToTest('Tag - stylesheetLink() - array parameter for a local link');

        Tag::resetInput();

        $options  = ['css/phalcon.css'];
        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="/css/phalcon.css" />'
            . PHP_EOL;

        Tag::setDocType(
            Tag::XHTML10_STRICT
        );

        $actual = Tag::stylesheetLink($options);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();

        $options  = ['css/phalcon.css'];
        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="/css/phalcon.css">'
            . PHP_EOL;

        Tag::setDocType(
            Tag::HTML5
        );

        $actual = Tag::stylesheetLink($options);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: stylesheetLink() - string parameter for a remote
     * link
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-12
     */
    public function tagStylesheetLinkStringParameterRemote(UnitTester $I)
    {
        $I->wantToTest('Tag - stylesheetLink() - string parameter for a remote');

        Tag::resetInput();

        $options  = 'http://phalcon.io/css/phalcon.css';
        $expected = '<link rel="stylesheet" type="text/css" href="http://phalcon.io/css/phalcon.css" />' . PHP_EOL;

        Tag::setDocType(
            Tag::XHTML10_STRICT
        );

        $actual = Tag::stylesheetLink($options, false);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();

        $options  = 'http://phalcon.io/css/phalcon.css';
        $expected = '<link rel="stylesheet" type="text/css" href="http://phalcon.io/css/phalcon.css">' . PHP_EOL;

        Tag::setDocType(
            Tag::HTML5
        );

        $actual = Tag::stylesheetLink($options, false);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: stylesheetLink() - array parameter for a remote link
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-12
     */
    public function tagStylesheetLinkArrayParameterRemote(UnitTester $I)
    {
        $I->wantToTest('Tag - stylesheetLink() - array parameter for a remote link');

        Tag::resetInput();

        $options  = ['http://phalcon.io/css/phalcon.css'];
        $expected = '<link rel="stylesheet" type="text/css" href="http://phalcon.io/css/phalcon.css" />' . PHP_EOL;

        Tag::setDocType(
            Tag::XHTML10_STRICT
        );

        $actual = Tag::stylesheetLink($options, false);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();

        $options  = ['http://phalcon.io/css/phalcon.css'];
        $expected = '<link rel="stylesheet" type="text/css" href="http://phalcon.io/css/phalcon.css">' . PHP_EOL;

        Tag::setDocType(
            Tag::HTML5
        );

        $actual = Tag::stylesheetLink($options, false);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: stylesheetLink() - overriding the rel link local
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2142
     * @author Phalcon Team <team@phalcon.io>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-12
     */
    public function tagStylesheetLinkOverrideRelLink(UnitTester $I)
    {
        $I->wantToTest('Tag - stylesheetLink() - overriding the rel link local');

        Tag::resetInput();

        $options = [
            'css/phalcon.css',
            'rel' => 'stylesheet/less',
        ];

        $expected = '<link rel="stylesheet/less" type="text/css" href="/css/phalcon.css" />' . PHP_EOL;

        Tag::setDocType(
            Tag::XHTML10_STRICT
        );

        $actual = Tag::stylesheetLink($options);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();

        $options = [
            'css/phalcon.css',
            'rel' => 'stylesheet/less',
        ];

        $expected = '<link rel="stylesheet/less" type="text/css" href="/css/phalcon.css">' . PHP_EOL;

        Tag::setDocType(
            Tag::HTML5
        );

        $actual = Tag::stylesheetLink($options);

        $I->assertEquals($expected, $actual);
    }
}
