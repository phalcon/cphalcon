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
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class StylesheetLinkCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: stylesheetLink() - string parameter for a local link
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1486
     * @author Phalcon Team <team@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-12
     */
    public function testStylesheetLinkStringParameterLocal(UnitTester $I)
    {
        Tag::resetInput();
        $options  = 'css/phalcon.css';
        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="/css/phalcon.css" />'
            . PHP_EOL;

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::stylesheetLink($options);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $options  = 'css/phalcon.css';
        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="/css/phalcon.css">'
            . PHP_EOL;

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::stylesheetLink($options);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: stylesheetLink() - array parameter for a local link
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1486
     * @author Phalcon Team <team@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-12
     */
    public function testStylesheetLinkArrayParameterLocal(UnitTester $I)
    {
        Tag::resetInput();
        $options  = ['css/phalcon.css'];
        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="/css/phalcon.css" />'
            . PHP_EOL;

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::stylesheetLink($options);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $options  = ['css/phalcon.css'];
        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="/css/phalcon.css">'
            . PHP_EOL;

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::stylesheetLink($options);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: stylesheetLink() - string parameter for a remote
     * link
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function testStylesheetLinkStringParameterRemote(UnitTester $I)
    {
        Tag::resetInput();
        $options  = 'http://phalconphp.com/css/phalcon.css';
        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="http://phalconphp.com/css/phalcon.css" />'
            . PHP_EOL;

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::stylesheetLink($options, false);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $options  = 'http://phalconphp.com/css/phalcon.css';
        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="http://phalconphp.com/css/phalcon.css">'
            . PHP_EOL;

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::stylesheetLink($options, false);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: stylesheetLink() - array parameter for a remote link
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function testStylesheetLinkArrayParameterRemote(UnitTester $I)
    {
        Tag::resetInput();
        $options  = ['http://phalconphp.com/css/phalcon.css'];
        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="http://phalconphp.com/css/phalcon.css" />'
            . PHP_EOL;

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::stylesheetLink($options, false);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $options  = ['http://phalconphp.com/css/phalcon.css'];
        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="http://phalconphp.com/css/phalcon.css">'
            . PHP_EOL;

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::stylesheetLink($options, false);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: stylesheetLink() - overriding the rel link local
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2142
     * @author Phalcon Team <team@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-12
     */
    public function testStylesheetLinkOverrideRelLink(UnitTester $I)
    {
        Tag::resetInput();
        $options  = [
            'css/phalcon.css',
            'rel' => 'stylesheet/less',
        ];
        $expected = '<link rel="stylesheet/less" type="text/css" '
            . 'href="/css/phalcon.css" />'
            . PHP_EOL;

        Tag::setDocType(Tag::XHTML10_STRICT);
        $actual = Tag::stylesheetLink($options);

        $I->assertEquals($expected, $actual);

        Tag::resetInput();
        $options  = [
            'css/phalcon.css',
            'rel' => 'stylesheet/less',
        ];
        $expected = '<link rel="stylesheet/less" type="text/css" '
            . 'href="/css/phalcon.css">'
            . PHP_EOL;

        Tag::setDocType(Tag::HTML5);
        $actual = Tag::stylesheetLink($options);

        $I->assertEquals($expected, $actual);
    }
}
