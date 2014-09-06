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

use \CodeGuy;
use \Phalcon\DI\FactoryDefault as PhDI;
use \Phalcon\Tag as PhTag;

class TagTagHtmlCest
{
    private $message = "%s does not return proper html element";

    public function _before()
    {
        $di = new PhDI();
        PhDI::reset();
        PhTag::setDI($di);
    }

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
        $name     = 'aside';
        $expected = '<aside>';
        $actual   = PhTag::tagHtml($name);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtml bare')
        );
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
        $name     = 'img';
        $expected = '<img />';
        $actual   = PhTag::tagHtml($name, null, true);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtml bare')
        );
    }

    /**
     * Tests the tagHtml with name parameter and self close
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlNameSelfCloseXhtml(CodeGuy $I)
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $name     = 'img';
        $expected = '<img />';
        $actual   = PhTag::tagHtml($name, null, true);
        PhTag::setDoctype('');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtml bare')
        );
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
        $name     = 'aside';
        $expected = '<aside>';
        $actual   = PhTag::tagHtml($name, null, null, true);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtml bare')
        );
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
        $name     = 'aside';
        $expected = '<aside></aside>' . PHP_EOL;
        $actual   = PhTag::tagHtml($name, null, null, null, true);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtml bare')
        );
    }

    /**
     * Tests the tagHtml with name parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTagHtmlWithArray(CodeGuy $I)
    {
        $name     = 'canvas';
        $options  = array(
            'id'     => 'canvas1',
            'width'  => 300,
            'height' => 300,
        );

        $expected = '<canvas id="canvas1" width="300" height="300"></canvas>';
        $actual   = PhTag::tagHtml($name, $options);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtml with options array')
        );
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
        $name     = 'canvas';

        $expected = '</canvas>';
        $actual   = PhTag::tagHtmlClose($name);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtml with options array')
        );
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
        $name     = 'canvas';

        $expected = '</canvas>' . PHP_EOL;
        $actual   = PhTag::tagHtmlClose($name, true);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'tagHtml with options array')
        );
    }
}
