<?php
/**
 * TagTagHtmlCest.php
 * \Phalcon\Tag
 *
 * Tests the \Phalcon\Tag component
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

namespace Phalcon\Tests\unit\Phalcon\Tag;

use \CodeGuy;
use \Phalcon\Tag as PhTag;

class TagTagHtmlCest extends TagBase
{
    /**
     * Tests the tagHtml with name parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlName(CodeGuy $I)
    {
        $this->tagHtmlName($I, false);
    }

    /**
     * Tests the tagHtml with name parameter XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlNameXHTML(CodeGuy $I)
    {
        $this->tagHtmlName($I, true);
    }

    /**
     * Tests the tagHtml with name parameter and self close
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlNameSelfClose(CodeGuy $I)
    {
        $this->tagHtmlNameSelfClose($I, false);
    }

    /**
     * Tests the tagHtml with name parameter and self close XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlNameSelfCloseXHTML(CodeGuy $I)
    {
        $this->tagHtmlNameSelfClose($I, true);
    }

    /**
     * Tests the tagHtml with name parameter and only start
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlNameOnlyStart(CodeGuy $I)
    {
        $this->tagHtmlNameOnlyStart($I, false);
    }

    /**
     * Tests the tagHtml with name parameter and only start XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlNameOnlyStartXHTML(CodeGuy $I)
    {
        $this->tagHtmlNameOnlyStart($I, true);
    }

    /**
     * Tests the tagHtml with name parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlNameEol(CodeGuy $I)
    {
        $this->tagHtmlNameEol($I, false);
    }

    /**
     * Tests the tagHtml with name parameter XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlNameEolXHTML(CodeGuy $I)
    {
        $this->tagHtmlNameEol($I, true);
    }

    /**
     * Tests the tagHtml with array parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlWithArray(CodeGuy $I)
    {
        $this->tagHtmlWithArray($I, false);
    }

    /**
     * Tests the tagHtml with array parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlWithArrayXHTML(CodeGuy $I)
    {
        $this->tagHtmlWithArray($I, true);
    }

    /**
     * Tests the tagHtmlClose
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlClose(CodeGuy $I)
    {
        $this->tagHtmlClose($I, false);
    }

    /**
     * Tests the tagHtmlClose XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlCloseXHTML(CodeGuy $I)
    {
        $this->tagHtmlClose($I, true);
    }

    /**
     * Tests the tagHtmlClose with EOL
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlCloseEol(CodeGuy $I)
    {
        $this->tagHtmlCloseEol($I, false);
    }

    /**
     * Tests the tagHtmlClose with EOL XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlCloseEolXHTML(CodeGuy $I)
    {
        $this->tagHtmlCloseEol($I, true);
    }

    /**
     * PRIVATE METHODS
     */

    /**
     * Runs the test for tagHtml with name parameter for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function tagHtmlName(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $name     = 'aside';
        $expected = ($xhtml) ? '<aside>' : '<aside></aside>';
        $message  = ($xhtml) ? ' XHTML'  : '';
        $actual   = PhTag::tagHtml($name);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtml bare' . $message)
        );
    }

    /**
     * Runs the test for tagHtml with name parameter and self close for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function tagHtmlNameSelfClose(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $name     = 'aside';
        $expected = ($xhtml) ? '<aside />' : '<aside></aside>';
        $message  = ($xhtml) ? ' XHTML'    : '';
        $actual   = PhTag::tagHtml($name, null, true);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtml with self close bare' . $message)
        );
    }

    /**
     * Runs the test for tagHtml with name parameter and only start for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function tagHtmlNameOnlyStart(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $name     = 'aside';
        $expected = '<aside>';
        $message  = ($xhtml) ? ' XHTML' : '';
        $actual   = PhTag::tagHtml($name, null, null, true);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtml bare only start' . $message)
        );
    }

    /**
     * Runs the test for tagHtml with name parameter for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function tagHtmlNameEol(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $name     = 'aside';
        $expected = (($xhtml) ? '<aside>' : '<aside></aside>') . PHP_EOL;
        $message  =  ($xhtml) ? ' XHTML'  : '';
        $actual   = PhTag::tagHtml($name, null, null, null, true);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtml bare with EOL' . $message)
        );
    }

    /**
     * Runs the test for tagHtml with name parameter for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function tagHtmlWithArray(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $name     = 'canvas';
        $options  = array(
            'id'     => 'canvas1',
            'width'  => 300,
            'height' => 300,
        );

        $expected  = '<canvas id="canvas1" width="300" height="300">';
        $expected .= ($xhtml) ? '' : '</canvas>';
        $message   = ($xhtml) ? ' XHTML'  : '';
        $actual    = PhTag::tagHtml($name, $options);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtml with options array' . $message)
        );
    }

    /**
     * Runs the test for tagHtmlClose for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function tagHtmlClose(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $name     = 'canvas';
        $expected = '</canvas>';
        $message  = ($xhtml) ? ' XHTML' : '';
        $actual   = PhTag::tagHtmlClose($name);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtmlClose' . $message)
        );
    }

    /**
     * Runs the test for tagHtmlClose with EOL for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function tagHtmlCloseEol(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $name     = 'canvas';
        $expected = '</canvas>' . PHP_EOL;
        $message  = ($xhtml) ? ' XHTML' : '';
        $actual   = PhTag::tagHtmlClose($name, true);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtmlClose with EOL' . $message)
        );
    }

}
