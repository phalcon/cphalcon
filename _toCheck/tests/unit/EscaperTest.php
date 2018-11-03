<?php

namespace Phalcon\Test\Unit;

use Phalcon\Escaper;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\EscaperTest
 * Tests the \Phalcon\Escaper component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class EscaperTest extends UnitTest
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
                $escaper  = new Escaper();
                expect($escaper->escapeHtml("<h1></h1>"))->equals('&lt;h1&gt;&lt;/h1&gt;');
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
                $escaper = new Escaper();
                $escaper->setEncoding('UTF-8');

                expect($escaper->getEncoding())->equals('UTF-8');
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
                $escaper  = new Escaper();
                $escaper->setHtmlQuoteType(ENT_HTML401);

                expect($escaper->escapeHtmlAttr("That's right"))->equals("That&#039;s right");
            }
        );

        $this->specify(
            'The escaper does not return the correct result with ENT_XHTML',
            function () {
                $escaper  = new Escaper();
                $escaper->setHtmlQuoteType(ENT_XML1);

                expect($escaper->escapeHtmlAttr("That's right"))->equals("That&#039;s right");
            }
        );

        $this->specify(
            'The escaper does not return the correct result with ENT_XHTML',
            function () {
                $escaper  = new Escaper();
                $escaper->setHtmlQuoteType(ENT_XHTML);

                expect($escaper->escapeHtmlAttr("That's right"))->equals("That&#039;s right");
            }
        );

        $this->specify(
            'The escaper does not return the correct result with ENT_HTML5',
            function () {
                $escaper  = new Escaper();
                $escaper->setHtmlQuoteType(ENT_HTML5);

                expect($escaper->escapeHtmlAttr("That's right"))->equals("That&#039;s right");
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
                $escaper = new Escaper();
                expect($escaper->detectEncoding('ḂḃĊċḊḋḞḟĠġṀṁ'))->equals('UTF-8');
            }
        );

        $this->specify(
            'The escaper does not detect the encoding correctly ISO-8859-1',
            function () {
                $escaper = new Escaper();
                expect($escaper->detectEncoding(chr(172) . chr(128) . chr(159) . 'ḂḃĊċḊḋḞḟĠġṀṁ'))->equals('ISO-8859-1');
            }
        );

        $this->specify(
            'The escaper does not detect the encoding correctly UTF-8',
            function () {
                $escaper = new Escaper();
                expect($escaper->detectEncoding('\0\0\0H\0\0\0i'))->equals('UTF-8');
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
                if (!extension_loaded('mbstring')) {
                    $this->markTestSkipped('Warning: mbstring extension is not loaded');
                }

                $escaper = new Escaper();
                expect($escaper->normalizeEncoding('Hello'))->equals(mb_convert_encoding('Hello', 'UTF-32', 'UTF-8'));
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
                $escaper = new Escaper();

                $source = ".émotion { background: "
                    . "url('http://phalconphp.com/a.php?c=d&e=f'); }";
                $expected = '\2e \e9 motion\20 \7b \20 background\3a \20 url\28 '
                    . '\27 http\3a \2f \2f phalconphp\2e com\2f a\2e php'
                    . '\3f c\3d d\26 e\3d f\27 \29 \3b \20 \7d ';

                expect($escaper->escapeCss($source))->equals($expected);
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
                $escaper = new Escaper();

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

                expect($escaper->escapeJs($source))->equals($expected);
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
                $escaper = new Escaper();
                expect($escaper->escapeUrl("http://phalconphp.com/a.php?c=d&e=f"))->equals('http%3A%2F%2Fphalconphp.com%2Fa.php%3Fc%3Dd%26e%3Df');
            }
        );
    }
}
