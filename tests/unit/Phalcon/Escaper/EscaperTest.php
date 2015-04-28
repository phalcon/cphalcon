<?php
/**
 * EscaperTest.php
 * \Phalcon\Escaper
 *
 * Tests the \Phalcon\Escaper component
 *
 * Phalcon Framework
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

namespace Phalcon\Tests\unit\Phalcon\Escaper;

use \PhalconTest\Escaper as PhTEscaper;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class EscaperTest extends TBase
{
    /**
     * Tests whether a key exists in the array
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testEscaperHtml()
    {
        $this->specify(
            "The escaper does not escape string correctly",
            function () {

                $escaper  = new PhTEscaper();
                $source   = "<h1></h1>";
                $expected = '&lt;h1&gt;&lt;/h1&gt;';
                $actual   = $escaper->escapeHtml($source);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the getEncoding and setEncoding
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-16
     */
    public function testGetSetEncoding()
    {
        $this->specify(
            'The escaper does not set/get the encoding correctly',
            function () {

                $escaper = new PhTEscaper();

                $expected = 'UTF-8';
                $escaper->setEncoding($expected);
                $actual = $escaper->getEncoding();

                expect($actual)->equals($expected);

            }
        );
    }

    /**
     * Tests the normalizeEncoding with various quote types
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-16
     */
    public function testEscapeAttrWithDifferentEncodings()
    {
        $this->specify(
            'The escaper does not return the correct result with ENT_HTML401',
            function () {

                $escaper  = new PhTEscaper();
                $escaper->setHtmlQuoteType(ENT_HTML401);
                $source   = "That's right";
                $expected = "That&#039;s right";
                $actual   = $escaper->escapeHtmlAttr($source);

                expect($actual)->equals($expected);

            }
        );

        $this->specify(
            'The escaper does not return the correct result with ENT_XHTML',
            function () {

                $escaper  = new PhTEscaper();
                $escaper->setHtmlQuoteType(ENT_XML1);
                $source   = "That's right";
                $expected = "That&#039;s right";
                $actual   = $escaper->escapeHtmlAttr($source);

                expect($actual)->equals($expected);

            }
        );

        $this->specify(
            'The escaper does not return the correct result with ENT_XHTML',
            function () {

                $escaper  = new PhTEscaper();
                $escaper->setHtmlQuoteType(ENT_XHTML);
                $source   = "That's right";
                $expected = "That&#039;s right";
                $actual   = $escaper->escapeHtmlAttr($source);

                expect($actual)->equals($expected);

            }
        );

        $this->specify(
            'The escaper does not return the correct result with ENT_HTML5',
            function () {

                $escaper  = new PhTEscaper();
                $escaper->setHtmlQuoteType(ENT_HTML5);
                $source   = "That's right";
                $expected = "That&#039;s right";
                $actual   = $escaper->escapeHtmlAttr($source);

                expect($actual)->equals($expected);

            }
        );
    }

    /**
     * Tests the detectEncoding
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-16
     */
    public function testDetectEncoding()
    {
        $this->specify(
            'The escaper does not detect the encoding correctly UTF-8',
            function () {

                $escaper = new PhTEscaper();

                $expected = 'UTF-8';
                $source   = 'ḂḃĊċḊḋḞḟĠġṀṁ';
                $actual   = $escaper->detectEncoding($source);

                expect($actual)->equals($expected);

            }
        );

        $this->specify(
            'The escaper does not detect the encoding correctly ISO-8859-1',
            function () {

                $escaper = new PhTEscaper();

                $expected = 'ISO-8859-1';
                $source   = chr(172) . chr(128) . chr(159) . 'ḂḃĊċḊḋḞḟĠġṀṁ';
                $actual   = $escaper->detectEncoding($source);

                expect($actual)->equals($expected);

            }
        );

        $this->specify(
            'The escaper does not detect the encoding correctly UTF-8',
            function () {

                $escaper = new PhTEscaper();

                $expected = 'UTF-8';
                $source   = '\0\0\0H\0\0\0i';
                $actual   = $escaper->detectEncoding($source);

                expect($actual)->equals($expected);

            }
        );
    }

    /**
     * Tests the normalizeEncoding
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-16
     */
    public function testNormalizeEncoding()
    {
        $this->specify(
            'The escaper with normalizeEncoding does not return the correct result ',
            function () {

                $escaper = new PhTEscaper();

                $source   = 'Hello';
                $expected = mb_convert_encoding($source, 'UTF-32', 'UTF-8');
                $actual   = $escaper->normalizeEncoding($source);

                expect($actual)->equals($expected);

            }
        );
    }

    /**
     * Tests the escapeCss
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-16
     */
    public function testEscapeCss()
    {
        $this->specify(
            'The escaper with escapeCss does not return the correct result ',
            function () {

                $escaper = new PhTEscaper();

                $source   = ".émotion { background: "
                          . "url('http://phalconphp.com/a.php?c=d&e=f'); }";
                $expected = '\2e \e9 motion\20 \7b \20 background\3a \20 url\28 '
                          . '\27 http\3a \2f \2f phalconphp\2e com\2f a\2e php'
                          . '\3f c\3d d\26 e\3d f\27 \29 \3b \20 \7d ';
                $actual   = $escaper->escapeCss($source);

                expect($actual)->equals($expected);

            }
        );
    }

    /**
     * Tests the escapeJs
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-16
     */
    public function testEscapeJs()
    {
        $this->specify(
            'The escaper with escapeJs does not return the correct result ',
            function () {

                $escaper = new PhTEscaper();

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

                expect($actual)->equals($expected);

            }
        );
    }

    /**
     * Tests the escapeUrl
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-16
     */
    public function testEscapeUrl()
    {
        $this->specify(
            'The escaper with escapeCss does not return the correct result ',
            function () {

                $escaper = new PhTEscaper();

                $source   = "http://phalconphp.com/a.php?c=d&e=f";
                $expected = 'http%3A%2F%2Fphalconphp.com%2Fa.php%3Fc%3Dd%26e%3Df';
                $actual   = $escaper->escapeUrl($source);

                expect($actual)->equals($expected);

            }
        );
    }
}
