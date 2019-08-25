<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\TagSetupTrait;
use UnitTester;

class StylesheetCest
{
    use DiTrait;
    use TagSetupTrait;

    /**
     * Tests Phalcon\Html\Tag :: stylesheet() - local
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1486
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-12
     */
    public function htmlTagStylesheet(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - stylesheet() - local');
        $tag = new Tag();
        $tag->setDI($this->container);
        $url      = 'css/phalcon.css';
        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="/css/phalcon.css" />'
            . PHP_EOL;

        $actual = $tag
            ->setDocType(Tag::XHTML10_STRICT)
            ->stylesheet($url)
        ;

        $I->assertEquals($expected, $actual);

        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="/css/phalcon.css">'
            . PHP_EOL;
        $actual   = $tag
            ->setDocType(Tag::HTML5)
            ->stylesheet($url)
        ;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: stylesheet() - remote
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-12
     */
    public function htmlTagStylesheetRemote(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - stylesheet() - remote');
        $tag = new Tag();
        $tag->setDI($this->container);
        $url      = 'http://phalcon.io/css/phalcon.css';
        $options  = ['local' => false];
        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="http://phalcon.io/css/phalcon.css" />'
            . PHP_EOL;

        $actual = $tag
            ->setDocType(Tag::XHTML10_STRICT)
            ->stylesheet($url, $options)
        ;
        $I->assertEquals($expected, $actual);

        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="http://phalcon.io/css/phalcon.css">'
            . PHP_EOL;
        $actual   = $tag
            ->setDocType(Tag::HTML5)
            ->stylesheet($url)
        ;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: stylesheet() - override rel
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2142
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2014-09-12
     */
    public function htmlTagStylesheetOverrideRel(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - stylesheet() - override rel');
        $tag = new Tag();
        $tag->setDI($this->container);
        $url      = 'css/phalcon.css';
        $options  = ['rel' => 'stylesheet/less'];
        $expected = '<link rel="stylesheet/less" type="text/css" '
            . 'href="/css/phalcon.css" />'
            . PHP_EOL;

        $actual = $tag
            ->setDocType(Tag::XHTML10_STRICT)
            ->stylesheet($url, $options)
        ;
        $I->assertEquals($expected, $actual);

        $expected = '<link rel="stylesheet/less" type="text/css" '
            . 'href="/css/phalcon.css">'
            . PHP_EOL;
        $actual   = $tag
            ->setDocType(Tag::HTML5)
            ->stylesheet($url, $options)
        ;
        $I->assertEquals($expected, $actual);
    }
}
