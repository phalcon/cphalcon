<?php
/**
 * EscaperTest.php
 * \Phalcon\Escaper
 *
 * Tests the \Phalcon\Escaper component
 *
 * PhalconPHP Framework
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

namespace Phalcon\Tests\unit\Phalcon\Translate\Adapter\NativeArray;

use \Phalcon\Escaper as PhEscaper;

class EscaperTest extends \Codeception\TestCase\Test
{
    use \Codeception\Specify;

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

                $escaper  = new PhEscaper();
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

                $escaper = new PhEscaper();

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

                $escaper  = new PhEscaper();
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

                $escaper  = new PhEscaper();
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

                $escaper  = new PhEscaper();
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

                $escaper  = new PhEscaper();
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

                $escaper = new PhEscaper();

                $expected = 'UTF-8';
                $source   = 'ḂḃĊċḊḋḞḟĠġṀṁ';
                $actual   = $escaper->detectEncoding($source);

                expect($actual)->equals($expected);

            }
        );

        $this->specify(
            'The escaper does not detect the encoding correctly ISO-8859-1',
            function () {

                $escaper = new PhEscaper();

                $expected = 'ISO-8859-1';
                $source   = chr(172) . chr(128) . chr(159) . 'ḂḃĊċḊḋḞḟĠġṀṁ';
                $actual   = $escaper->detectEncoding($source);

                expect($actual)->equals($expected);

            }
        );

        $this->specify(
            'The escaper does not detect the encoding correctly UTF-8',
            function () {

                $escaper = new PhEscaper();

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

                $escaper = new PhEscaper();

                $source   = 'Hello';
                $expected = mb_convert_encoding($source, 'UTF-32', 'UTF-8');
                $actual   = $escaper->normalizeEncoding($source);

                expect($actual)->equals($expected);

            }
        );
    }
/*
	* public function escapeCss(string css) -> string
     * Escape javascript strings by replacing non-alphanumeric chars by their hexadecimal escaped representation
	* public function escapeJs(string js) -> string
     * Escapes a URL. Internally uses rawurlencode
	* public function escapeUrl(string url) -> string
 */


}