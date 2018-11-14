<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Escaper;

use Phalcon\Escaper;
use UnitTester;
use const ENT_XHTML;

class EscaperCest
{
    /**
     * Tests whether a key exists in the array
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testEscaperHtml(UnitTester $I)
    {
        $escaper  = new Escaper();
        $expected = '&lt;h1&gt;&lt;/h1&gt;';
        $actual   = $escaper->escapeHtml("<h1></h1>");
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the getEncoding and setEncoding
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-16
     */
    public function testGetSetEncoding(UnitTester $I)
    {
        $escaper = new Escaper();
        $escaper->setEncoding('UTF-8');

        $expected = 'UTF-8';
        $actual   = $escaper->getEncoding();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the normalizeEncoding with various quote types
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-16
     */
    public function testEscapeAttrWithDifferentEncodings(UnitTester $I)
    {
        $escaper = new Escaper();

        $escaper->setHtmlQuoteType(ENT_HTML401);
        $expected = "That&#039;s right";
        $actual   = $escaper->escapeHtmlAttr("That's right");
        $I->assertEquals($expected, $actual);

        $escaper->setHtmlQuoteType(ENT_XML1);
        $expected = "That&#039;s right";
        $actual   = $escaper->escapeHtmlAttr("That's right");
        $I->assertEquals($expected, $actual);

        $escaper->setHtmlQuoteType(ENT_XHTML);
        $expected = "That&#039;s right";
        $actual   = $escaper->escapeHtmlAttr("That's right");
        $I->assertEquals($expected, $actual);

        $escaper->setHtmlQuoteType(ENT_HTML5);
        $expected = "That&#039;s right";
        $actual   = $escaper->escapeHtmlAttr("That's right");
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the detectEncoding
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-16
     */
    public function testDetectEncoding(UnitTester $I)
    {
        $escaper = new Escaper();

        $source   = 'ḂḃĊċḊḋḞḟĠġṀṁ';
        $expected = 'UTF-8';
        $actual   = $escaper->detectEncoding($source);
        $I->assertEquals($expected, $actual);


        $source   = chr(172) . chr(128) . chr(159) . 'ḂḃĊċḊḋḞḟĠġṀṁ';
        $expected = 'ISO-8859-1';
        $actual   = $escaper->detectEncoding($source);
        $I->assertEquals($expected, $actual);

        $source   = '\0\0\0H\0\0\0i';
        $expected = 'UTF-8';
        $actual   = $escaper->detectEncoding($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the normalizeEncoding
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-16
     */
    public function testNormalizeEncoding(UnitTester $I, $scenario)
    {
        if (!extension_loaded('mbstring')) {
            $scenario->skip('Warning: mbstring extension is not loaded');
        }

        $escaper = new Escaper();

        $expected = mb_convert_encoding('Hello', 'UTF-32', 'UTF-8');
        $actual   = $escaper->normalizeEncoding('Hello');

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the escapeCss
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-16
     */
    public function testEscapeCss(UnitTester $I)
    {
        $escaper  = new Escaper();
        $source   = ".émotion { background: "
            . "url('http://phalconphp.com/a.php?c=d&e=f'); }";
        $expected = '\2e \e9 motion\20 \7b \20 background\3a \20 url\28 '
            . '\27 http\3a \2f \2f phalconphp\2e com\2f a\2e php'
            . '\3f c\3d d\26 e\3d f\27 \29 \3b \20 \7d ';
        $actual   = $escaper->escapeCss($source);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the escapeJs
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-16
     */
    public function testEscapeJs(UnitTester $I)
    {
        $escaper  = new Escaper();
        $source   = "function createtoc () {"
            . "var h2s = document.getElementsByTagName('H2');"
            . "l = toc.appendChild(document.createElement('ol'));"
            . "for (var i=0; i<h2s.length; i++) {"
            . "var h2 = h2s[i].firstChild.innerHTML;"
            . "var h = document.createElement('li');"
            . "l.appendChild(h);"
            . "}}";
        $expected = 'function createtoc () {'
            . 'var h2s \x3d document.getElementsByTagName(\x27H2\x27);'
            . 'l \x3d toc.appendChild(document.createElement(\x27ol\x27));'
            . 'for (var i\x3d0; i\x3ch2s.length; i++) {'
            . 'var h2 \x3d h2s[i].firstChild.innerHTML;'
            . 'var h \x3d document.createElement(\x27li\x27);'
            . 'l.appendChild(h);'
            . '}}';
        $actual   = $escaper->escapeJs($source);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the escapeUrl
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-16
     */
    public function testEscapeUrl(UnitTester $I)
    {
        $escaper  = new Escaper();
        $expected = 'http%3A%2F%2Fphalconphp.com%2Fa.php%3Fc%3Dd%26e%3Df';
        $actual   = $escaper->escapeUrl("http://phalconphp.com/a.php?c=d&e=f");

        $I->assertEquals($expected, $actual);
    }
}
