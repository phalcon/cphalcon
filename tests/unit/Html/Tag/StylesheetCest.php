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

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\TagSetupTrait;
use UnitTester;

/**
 * Class StylesheetCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class StylesheetCest
{
    use DiTrait;
    use TagSetupTrait;

    /**
     * Tests Phalcon\Html\Tag :: stylesheet() - local
     *
     * @param UnitTester $I
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function htmlTagStylesheetRemote(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - stylesheet() - remote');
        $tag = new Tag();
        $tag->setDI($this->container);
        $url      = 'http://phalconphp.com/css/phalcon.css';
        $options  = ['local' => false];
        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="http://phalconphp.com/css/phalcon.css" />'
            . PHP_EOL;

        $actual = $tag
            ->setDocType(Tag::XHTML10_STRICT)
            ->stylesheet($url, $options)
        ;
        $I->assertEquals($expected, $actual);

        $expected = '<link rel="stylesheet" type="text/css" '
            . 'href="http://phalconphp.com/css/phalcon.css">'
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
     * @param UnitTester $I
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
