<?php
/**
 * PhalconTestHelper.php
 * \Phalcon\Tag\UnitTest
 *
 * Tests the \Phalcon\Tag component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2013 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

use \Phalcon\Tag as Tg;

class Tag_UnitTest extends Phalcon_Test_UnitTestCase
{
    private $message = "%s does not return proper html element";


    // -------------------------------------------------------------------------
    // Doctype
    // -------------------------------------------------------------------------
    /**
     * Tests the doctype
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testDoctypeSet()
    {
        $doctype  = Tg::HTML5;
        $expected = "<!DOCTYPE html>" . PHP_EOL;
        Tg::setDoctype($doctype);
        $actual   = Tg::getDoctype($doctype);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'Doctype (HTML5)')
        );

    }

    // -------------------------------------------------------------------------
    // Image
    // -------------------------------------------------------------------------
    /**
     * Tests an image tag with a bare minimum of information passed
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testImageBasic()
    {
        $options  = 'img/hello.gif';
        $expected = '<img src="/img/hello.gif">';
        $actual   = Tg::image($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'Image basic')
        );
    }

    /**
     * Tests an image tag with an array passed as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testImageWithArrayBasic()
    {
        $options  = array(
            'img/hello.gif',
            'class' => 'some_class',
        );
        $expected = '<img class="some_class" src="/img/hello.gif">';
        $actual   = Tg::image($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'Image basic with array')
        );
    }

    /**
     * Tests an image tag with the src attribute passed in as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testImageWithSrcInParameters()
    {
        $options  = array(
            'img/hello.gif',
            'src'   => 'img/goodbye.gif',
            'class' => 'some_class',
        );
        $expected = '<img src="/img/goodbye.gif" class="some_class">';
        $actual   = Tg::image($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'Image basic with src in parameters')
        );
    }

    /**
     * Tests an image tag with a bare minimum of information passed
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testImageBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'img/hello.gif';
        $expected = '<img src="/img/hello.gif" />';
        $actual   = Tg::image($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML Image basic')
        );
    }

    /**
     * Tests an image tag with an array passed as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testImageWithArrayBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = array(
            'img/hello.gif',
            'class' => 'some_class',
        );
        $expected = '<img class="some_class" src="/img/hello.gif" />';
        $actual   = Tg::image($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML Image basic with array')
        );
    }

    /**
     * Tests an image tag with the src attribute passed in as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testImageWithSrcInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = array(
            'img/hello.gif',
            'src'   => 'img/goodbye.gif',
            'class' => 'some_class',
        );
        $expected = '<img src="/img/goodbye.gif" class="some_class" />';
        $actual   = Tg::image($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML Image basic with src in parameters')
        );
    }

    // -------------------------------------------------------------------------
    // stylesheetLink
    // -------------------------------------------------------------------------
    /**
     * Tests stylesheetLink for a local link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testStylesheetLinkLocal()
    {
        $options  = 'css/phalcon.css';
        $expected = '<link rel="stylesheet" href="/css/phalcon.css" '
                  . 'type="text/css">';
        $actual   = Tg::stylesheetLink($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'StylesheetLink local')
        );
    }

    /**
     * Tests stylesheetLink with an array passed for a local link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testStylesheetLinkWithArrayLocal()
    {
        $options  = array('css/phalcon.css');
        $expected = '<link rel="stylesheet" href="css/phalcon.css" '
                  . 'type="text/css">';
        $actual   = Tg::stylesheetLink($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'StylesheetLink local with Array')
        );
    }

    /**
     * Tests stylesheetLink with a string as the second parameter - local link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testStylesheetLinkWithStringAsSecondParameterLocal()
    {
        $options  = array('css/phalcon.css');
        $expected = '<link rel="stylesheet" href="css/phalcon.css" '
                  . 'type="text/css">';
        $actual   = Tg::stylesheetLink($options, 'hello');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'StylesheetLink local with string as second parameter'
            )
        );
    }

    /**
     * Tests stylesheetLink for a remote link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testStylesheetLinkRemote()
    {
        $options  = 'http://fonts.googleapis.com/css?family=Rosario';
        $expected = '<link rel="stylesheet" '
                  . 'href="http://fonts.googleapis.com/css?family=Rosario" '
                  . 'type="text/css">';
        $actual   = Tg::stylesheetLink($options, FALSE);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'StylesheetLink remote')
        );
    }

    /**
     * Tests stylesheetLink with an array passed for a remote link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testStylesheetLinkWithArrayRemote()
    {
        $options  = array('http://fonts.googleapis.com/css?family=Rosario');
        $expected = '<link rel="stylesheet" '
                  . 'href="http://fonts.googleapis.com/css?family=Rosario" '
                  . 'type="text/css">';
        $actual   = Tg::stylesheetLink($options, FALSE);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'StylesheetLink remote with Array')
        );
    }

    /**
     * Tests stylesheetLink with a string as the second parameter - remote link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testStylesheetLinkWithStringAsSecondParameterRemote()
    {
        $options  = 'http://fonts.googleapis.com/css?family=Rosario';
        $expected = '<link rel="stylesheet" '
                  . 'href="http://fonts.googleapis.com/css?family=Rosario" '
                  . 'type="text/css">';
        $actual   = Tg::stylesheetLink($options, '0');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'StylesheetLink remote with string as second parameter'
            )
        );
    }

    /**
     * Tests stylesheetLink for a local link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testStylesheetLinkLocalXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'css/phalcon.css';
        $expected = '<link rel="stylesheet" href="/css/phalcon.css" '
                  . 'type="text/css" />';
        $actual   = Tg::stylesheetLink($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML StylesheetLink local')
        );
    }

    /**
     * Tests stylesheetLink with an array passed for a local link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testStylesheetLinkWithArrayLocalXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = array('css/phalcon.css');
        $expected = '<link rel="stylesheet" href="css/phalcon.css" '
                  . 'type="text/css" />';
        $actual   = Tg::stylesheetLink($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML StylesheetLink local with Array')
        );
    }

    /**
     * Tests stylesheetLink with a string as the second parameter - local link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testStylesheetLinkWithStringAsSecondParameterLocalXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = array('css/phalcon.css');
        $expected = '<link rel="stylesheet" href="css/phalcon.css" '
                  . 'type="text/css" />';
        $actual   = Tg::stylesheetLink($options, 'hello');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'StylesheetLink local with string as second parameter'
            )
        );
    }

    /**
     * Tests stylesheetLink for a remote link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testStylesheetLinkRemoteXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'http://fonts.googleapis.com/css?family=Rosario';
        $expected = '<link rel="stylesheet" '
                  . 'href="http://fonts.googleapis.com/css?family=Rosario" '
                  . 'type="text/css" />';
        $actual   = Tg::stylesheetLink($options, FALSE);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML StylesheetLink remote')
        );
    }

    /**
     * Tests stylesheetLink with an array passed for a remote link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testStylesheetLinkWithArrayRemoteXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = array('http://fonts.googleapis.com/css?family=Rosario');
        $expected = '<link rel="stylesheet" '
                  . 'href="http://fonts.googleapis.com/css?family=Rosario" '
                  . 'type="text/css" />';
        $actual   = Tg::stylesheetLink($options, FALSE);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML StylesheetLink remote with Array')
        );
    }

    /**
     * Tests stylesheetLink with a string as the second parameter - remote link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testStylesheetLinkWithStringAsSecondParameterRemoteXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'http://fonts.googleapis.com/css?family=Rosario';
        $expected = '<link rel="stylesheet" '
                  . 'href="http://fonts.googleapis.com/css?family=Rosario" '
                  . 'type="text/css" />';
        $actual   = Tg::stylesheetLink($options, '0');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'StylesheetLink remote with string as second parameter'
            )
        );
    }

    // -------------------------------------------------------------------------
    // javascriptInclude
    // -------------------------------------------------------------------------
    /**
     * Tests javascriptInclude for a local link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testJavascriptIncludeLocal()
    {
        $options  = 'js/phalcon.js';
        $expected = '<script src="/js/phalcon.js" type="text/javascript">'
                  . '</script>';
        $actual   = Tg::javascriptInclude($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'JavascriptInclude local')
        );
    }

    /**
     * Tests javascriptInclude with an array passed for a local link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testJavascriptIncludeWithArrayLocal()
    {
        $options  = array('js/phalcon.js');
        $expected = '<script src="js/phalcon.js" type="text/javascript">'
                  . '</script>';
        $actual   = Tg::javascriptInclude($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'JavascriptInclude local with Array')
        );
    }

    /**
     * Tests javascriptInclude with a string as the second parameter - local link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testJavascriptIncludeWithStringAsSecondParameterLocal()
    {
        $options  = 'js/phalcon.js';
        $expected = '<script src="/js/phalcon.js" type="text/javascript">'
                  . '</script>';
        $actual   = Tg::javascriptInclude($options, 'hello');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message, '
                JavascriptInclude local with string as second parameter'
            )
        );
    }

    /**
     * Tests javascriptInclude for a remote link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testJavascriptIncludeRemote()
    {
        $options  = 'http://my.local.com/js/phalcon.js';
        $expected = '<script src="http://my.local.com/js/phalcon.js" '
                  . 'type="text/javascript"></script>';
        $actual   = Tg::javascriptInclude($options, FALSE);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'JavascriptInclude remote')
        );
    }

    /**
     * Tests javascriptInclude with an array passed for a remote link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testJavascriptIncludeWithArrayRemote()
    {
        $options  = array('http://my.local.com/js/phalcon.js');
        $expected = '<script src="http://my.local.com/js/phalcon.js" '
                  . 'type="text/javascript"></script>';
        $actual   = Tg::javascriptInclude($options, FALSE);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'JavascriptInclude remote with Array')
        );
    }

    /**
     * Tests javascriptInclude with a string as the second parameter - remote link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testJavascriptIncludeWithStringAsSecondParameterRemote()
    {
        $options  = 'http://my.local.com/js/phalcon.js';
        $expected = '<script src="http://my.local.com/js/phalcon.js" '
                  . 'type="text/javascript"></script>';
        $actual   = Tg::javascriptInclude($options, '0');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'JavascriptInclude remote with string as second parameter'
            )
        );
    }

    /**
     * Tests javascriptInclude for a local link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testJavascriptIncludeLocalXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'js/phalcon.js';
        $expected = '<script src="/js/phalcon.js" type="text/javascript">'
                  . '</script>';
        $actual   = Tg::javascriptInclude($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML JavascriptInclude local')
        );
    }

    /**
     * Tests javascriptInclude with an array passed for a local link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testJavascriptIncludeWithArrayLocalXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = array('js/phalcon.js');
        $expected = '<script src="js/phalcon.js" type="text/javascript">'
                  . '</script>';
        $actual   = Tg::javascriptInclude($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML JavascriptInclude local with Array')
        );
    }

    /**
     * Tests javascriptInclude with a string as the second parameter - local link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testJavascriptIncludeWithStringAsSecondParameterLocalXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'js/phalcon.js';
        $expected = '<script src="/js/phalcon.js" type="text/javascript">'
                  . '</script>';
        $actual   = Tg::javascriptInclude($options, 'hello');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message, 'xhtml
                JavascriptInclude local with string as second parameter'
            )
        );
    }

    /**
     * Tests javascriptInclude for a remote link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testJavascriptIncludeRemoteXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'http://my.local.com/js/phalcon.js';
        $expected = '<script src="http://my.local.com/js/phalcon.js" '
                  . 'type="text/javascript"></script>';
        $actual   = Tg::javascriptInclude($options, FALSE);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML JavascriptInclude remote')
        );
    }

    /**
     * Tests javascriptInclude with an array passed for a remote link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testJavascriptIncludeWithArrayRemoteXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = array('http://my.local.com/js/phalcon.js');
        $expected = '<script src="http://my.local.com/js/phalcon.js" '
                  . 'type="text/javascript"></script>';
        $actual   = Tg::javascriptInclude($options, FALSE);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML JavascriptInclude remote with Array')
        );
    }

    /**
     * Tests javascriptInclude with a string as the second parameter - remote link
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testJavascriptIncludeWithStringAsSecondParameterRemoteXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'http://my.local.com/js/phalcon.js';
        $expected = '<script src="http://my.local.com/js/phalcon.js" '
                  . 'type="text/javascript"></script>';
        $actual   = Tg::javascriptInclude($options, '0');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'JavascriptInclude remote with string as second parameter'
            )
        );
    }

    // -------------------------------------------------------------------------
    // resetInput
    // -------------------------------------------------------------------------
    /**
     * Tests resetInput (after a setDefault)
     *
     * @issue 53
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testResetInputSetDefault_T53()
    {
        $options  = 'some_field_name';
        $expected = '<input type="text" name="some_field_name" '
                  . 'id="some_field_name" value="Wall-E">';
        Tg::setDefault('some_field_name', 'Wall-E');
        $actual   = Tg::textField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'resetInput before contains a value')
        );
        Tg::resetInput();

        $expected = '<input type="text" name="some_field_name" '
                  . 'id="some_field_name" value="">';
        $actual   = Tg::textField($options);
        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'resetInput after contains a value')
        );
    }

    /**
     * Tests resetInput (after a displayTo)
     *
     * @issue 53
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testResetInputDisplayTo_T53()
    {
        $options  = 'some_field_name';
        $expected = '<input type="text" name="some_field_name" '
                  . 'id="some_field_name" value="Wall-E">';
        Tg::displayTo('some_field_name', 'Wall-E');
        $actual   = Tg::textField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'resetInput before contains a value')
        );
        Tg::resetInput();

        $expected = '<input type="text" name="some_field_name" '
                  . 'id="some_field_name" value="">';
        $actual   = Tg::textField($options);
        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'resetInput after contains a value')
        );
    }

    /**
     * Tests resetInput (after a setDefault)
     *
     * @issue 53
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testResetInputSetDefaultXHTML_T53()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="text" name="some_field_name" '
                  . 'id="some_field_name" value="Wall-E" />';
        Tg::setDefault('some_field_name', 'Wall-E');
        $actual   = Tg::textField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML resetInput before contains a value')
        );
        Tg::resetInput();

        $expected = '<input type="text" name="some_field_name" '
                  . 'id="some_field_name" value="" />';
        $actual   = Tg::textField($options);
        Tg::setDoctype('');
        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML resetInput after contains a value')
        );
    }

    /**
     * Tests resetInput (after a displayTo)
     *
     * @issue 53
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testResetInputDisplayToXHTML_T53()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="text" name="some_field_name" '
                  . 'id="some_field_name" value="Wall-E" />';
        Tg::displayTo('some_field_name', 'Wall-E');
        $actual   = Tg::textField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML resetInput before contains a value')
        );
        Tg::resetInput();

        $expected = '<input type="text" name="some_field_name" '
                  . 'id="some_field_name" value="" />';
        $actual   = Tg::textField($options);
        Tg::setDoctype('');
        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML resetInput after contains a value')
        );
    }

    // -------------------------------------------------------------------------
    // Text
    // -------------------------------------------------------------------------
    /**
     * Tests testField with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextBasic()
    {
        $options  = 'some_field_name';
        $expected = '<input type="text" name="some_field_name" '
                  . 'id="some_field_name" value="">';
        $actual   = Tg::textField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textField basic')
        );
    }

    /**
     * Tests textField with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextWithArrayBasic()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="text" class="some_class" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::textField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textField with array basic')
        );
    }

    /**
     * Tests textField with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextWithIdInParameters()
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="text" id="some_id" class="some_class" '
                  . 'size="10" name="some_field_name" value="">';
        $actual   = Tg::textField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textField with id in parameters')
        );
    }

    /**
     * Tests textField with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextWithNameAndNotIdInParameters()
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="text" name="some_other_name" '
                  . 'class="some_class" size="10" id="some_field_name" '
                  . 'value="">';
        $actual   = Tg::textField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textField with name and id in parameters')
        );
    }

    /**
     * Tests textField with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextSetDefault()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="text" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value">';
        $actual   = Tg::textField($options);
        Tg::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textField with setDefault')
        );
    }

    /**
     * Tests textField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextDisplayTo()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="text" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value">';
        $actual   = Tg::textField($options);
        Tg::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textField with displayTo')
        );
    }

    /**
     * Tests textField with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextSetDefaultElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<input type="text" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::textField($options);
        Tg::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'textField with setDefault element not present'
            )
        );
    }

    /**
     * Tests textField with displayTo to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextDisplayToElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<input type="text" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::textField($options);
        Tg::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textField with displayTo')
        );
    }

    /**
     * Tests testField with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testTextBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="text" name="some_field_name" '
                  . 'id="some_field_name" value="" />';
        $actual   = Tg::textField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML textField basic')
        );
    }

    /**
     * Tests textField with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testTextWithArrayBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="text" class="some_class" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::textField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML textField with array basic')
        );
    }

    /**
     * Tests textField with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testTextWithIdInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="text" id="some_id" class="some_class" '
                  . 'size="10" name="some_field_name" value="" />';
        $actual   = Tg::textField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML textField with id in parameters')
        );
    }

    /**
     * Tests textField with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testTextWithNameAndNotIdInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="text" name="some_other_name" '
                  . 'class="some_class" size="10" id="some_field_name" '
                  . 'value="" />';
        $actual   = Tg::textField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML textField with name and id in parameters')
        );
    }

    /**
     * Tests textField with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testTextSetDefaultXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="text" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value" />';
        $actual   = Tg::textField($options);
        Tg::setDefault('some_field_name', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML textField with setDefault')
        );
    }

    /**
     * Tests textField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testTextDisplayToXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="text" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value" />';
        $actual   = Tg::textField($options);
        Tg::displayTo('some_field_name', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML textField with displayTo')
        );
    }

    /**
     * Tests textField with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testTextSetDefaultElementNotPresentXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<input type="text" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::textField($options);
        Tg::setDefault('some_field', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'textField with setDefault element not present'
            )
        );
    }

    /**
     * Tests textField with displayTo to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testTextDisplayToElementNotPresentXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<input type="text" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::textField($options);
        Tg::displayTo('some_field', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML textField with displayTo')
        );
    }

    // -------------------------------------------------------------------------
    // Textarea
    // -------------------------------------------------------------------------
    /**
     * Tests textArea with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextareaBasic()
    {
        $options  = 'some_field_name';
        $expected = '<textarea name="some_field_name" id="some_field_name">'
                  . '</textarea>';
        $actual   = Tg::textArea($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textArea basic')
        );
    }

    /**
     * Tests textArea with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextareaWithArrayBasic()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<textarea class="some_class" name="some_field_name" '
                  . 'id="some_field_name"></textarea>';
        $actual   = Tg::textArea($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textArea basic with array')
        );
    }

    /**
     * Tests textArea with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextareaWithIdInParameters()
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<textarea id="some_id" class="some_class" size="10" '
                  . 'name="some_field_name"></textarea>';
        $actual   = Tg::textArea($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textArea with id in parameters')
        );
    }

    /**
     * Tests textArea with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextareaWithNameAndNotIdInParameters()
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<textarea name="some_other_name" class="some_class" '
                  . 'size="10" id="some_field_name"></textarea>';
        $actual   = Tg::textArea($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textArea with name and id in parameters')
        );
    }

    /**
     * Tests textArea with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextareaSetDefault()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<textarea class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name">'
                  . 'some_default_value</textarea>';
        $actual   = Tg::textArea($options);
        Tg::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textArea with setDefault')
        );
    }

    /**
     * Tests textArea with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextareaDisplayTo()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<textarea class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name">'
                  . 'some_default_value</textarea>';
        $actual   = Tg::textArea($options);
        Tg::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textArea with displayTo')
        );
    }

    /**
     * Tests textArea with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextareaSetDefaultElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<textarea class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name">'
                  . '</textarea>';
        $actual   = Tg::textArea($options);
        Tg::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textArea with setDefault')
        );
    }

    /**
     * Tests textArea with displayTo to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testTextareaDisplayToElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<textarea class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name">'
                  . '</textarea>';
        $actual   = Tg::textArea($options);
        Tg::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textArea with displayTo')
        );
    }

    // -------------------------------------------------------------------------
    // hiddenField
    // -------------------------------------------------------------------------
    /**
     * Tests hiddenField with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testHiddenFieldBasic()
    {
        $options  = 'some_field_name';
        $expected = '<input type="hidden" name="some_field_name" '
                  . 'id="some_field_name" value="">';
        $actual   = Tg::hiddenField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'hiddenField basic')
        );
    }

    /**
     * Tests hiddenField with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testHiddenFieldWithArrayBasic()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="hidden" class="some_class" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::hiddenField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'hiddenField basic with array')
        );
    }

    /**
     * Tests hiddenField with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testHiddenFieldWithIdInParameters()
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="hidden" id="some_id" class="some_class" '
                  . 'size="10" name="some_field_name" value="">';
        $actual   = Tg::hiddenField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'hiddenField with id in parameters')
        );
    }

    /**
     * Tests hiddenField with name and no id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testHiddenFieldWithNameAndNotIdInParameters()
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="hidden" name="some_other_name" '
                  . 'class="some_class" size="10" id="some_field_name" '
                  . 'value="">';
        $actual   = Tg::hiddenField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'hiddenField with name and id in parameters'
            )
        );
    }

    /**
     * Tests hiddenField with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testHiddenFieldSetDefault()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="hidden" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value">';
        $actual   = Tg::hiddenField($options);
        Tg::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'hiddenField with setDefault')
        );
    }

    /**
     * Tests hiddenField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testHiddenFieldDisplayTo()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="hidden" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value">';
        $actual   = Tg::hiddenField($options);
        Tg::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'hiddenField with displayTo')
        );
    }

    /**
     * Tests hiddenField with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testHiddenFieldSetDefaultElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<input type="hidden" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::hiddenField($options);
        Tg::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'hiddenField with setDefault')
        );
    }

    /**
     * Tests hiddenField with displayTo to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testHiddenFieldDisplayToElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<input type="hidden" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::hiddenField($options);
        Tg::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'hiddenField with displayTo')
        );
    }

    /**
     * Tests hiddenField with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testHiddenFieldBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="hidden" name="some_field_name" '
                  . 'id="some_field_name" value="" />';
        $actual   = Tg::hiddenField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML hiddenField basic')
        );
    }

    /**
     * Tests hiddenField with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testHiddenFieldWithArrayBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="hidden" class="some_class" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::hiddenField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML hiddenField basic with array')
        );
    }

    /**
     * Tests hiddenField with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testHiddenFieldWithIdInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="hidden" id="some_id" class="some_class" '
                  . 'size="10" name="some_field_name" value="" />';
        $actual   = Tg::hiddenField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML hiddenField with id in parameters')
        );
    }

    /**
     * Tests hiddenField with name and no id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testHiddenFieldWithNameAndNotIdInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="hidden" name="some_other_name" '
                  . 'class="some_class" size="10" id="some_field_name" '
                  . 'value="" />';
        $actual   = Tg::hiddenField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'hiddenField with name and id in parameters'
            )
        );
    }

    /**
     * Tests hiddenField with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testHiddenFieldSetDefaultXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="hidden" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value" />';
        $actual   = Tg::hiddenField($options);
        Tg::setDefault('some_field_name', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML hiddenField with setDefault')
        );
    }

    /**
     * Tests hiddenField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testHiddenFieldDisplayToXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="hidden" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value" />';
        $actual   = Tg::hiddenField($options);
        Tg::displayTo('some_field_name', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML hiddenField with displayTo')
        );
    }

    /**
     * Tests hiddenField with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testHiddenFieldSetDefaultElementNotPresentXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<input type="hidden" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::hiddenField($options);
        Tg::setDefault('some_field', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML hiddenField with setDefault')
        );
    }

    /**
     * Tests hiddenField with displayTo to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testHiddenFieldDisplayToElementNotPresentXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<input type="hidden" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::hiddenField($options);
        Tg::displayTo('some_field', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML hiddenField with displayTo')
        );
    }

    // -------------------------------------------------------------------------
    // passwordField
    // -------------------------------------------------------------------------
    /**
     * Tests passwordField with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testPasswordFieldBasic()
    {
        $options  = 'some_field_name';
        $expected = '<input type="password" name="some_field_name" '
                  . 'id="some_field_name" value="">';
        $actual   = Tg::passwordField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'passwordField basic')
        );
    }

    /**
     * Tests passwordField with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testPasswordFieldWithArrayBasic()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="password" class="some_class" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::passwordField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'passwordField basic with array')
        );
    }

    /**
     * Tests passwordField with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testPasswordFieldWithIdInParameters()
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="password" id="some_id" '
                  . 'class="some_class" size="10" name="some_field_name" '
                  . 'value="">';
        $actual   = Tg::passwordField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'passwordField with id in parameters')
        );
    }

    /**
     * Tests passwordField with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testPasswordFieldWithNameAndNotIdInParameters()
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="password" name="some_other_name" '
                  . 'class="some_class" size="10" id="some_field_name" '
                  . 'value="">';
        $actual   = Tg::passwordField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'passwordField with name and id in parameters'
            )
        );
    }

    /**
     * Tests passwordField with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testPasswordFieldSetDefault()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="password" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value">';
        $actual   = Tg::passwordField($options);
        Tg::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'passwordField with setDefault')
        );
    }

    /**
     * Tests passwordField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testPasswordFieldDisplayTo()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="password" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value">';
        $actual   = Tg::passwordField($options);
        Tg::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'passwordField with displayTo')
        );
    }

    /**
     * Tests passwordField with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testPasswordFieldSetDefaultElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<input type="password" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::passwordField($options);
        Tg::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'passwordField with setDefault')
        );
    }

    /**
     * Tests passwordField with displayTo to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testPasswordFieldDisplayToElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<input type="password" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::passwordField($options);
        Tg::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'passwordField with displayTo')
        );
    }

    /**
     * Tests passwordField with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testPasswordFieldBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="password" name="some_field_name" '
                  . 'id="some_field_name" value="" />';
        $actual   = Tg::passwordField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML passwordField basic')
        );
    }

    /**
     * Tests passwordField with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testPasswordFieldWithArrayBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="password" class="some_class" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::passwordField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML passwordField basic with array')
        );
    }

    /**
     * Tests passwordField with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testPasswordFieldWithIdInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="password" id="some_id" '
                  . 'class="some_class" size="10" name="some_field_name" '
                  . 'value="" />';
        $actual   = Tg::passwordField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML passwordField with id in parameters')
        );
    }

    /**
     * Tests passwordField with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testPasswordFieldWithNameAndNotIdInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="password" name="some_other_name" '
                  . 'class="some_class" size="10" id="some_field_name" '
                  . 'value="" />';
        $actual   = Tg::passwordField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'passwordField with name and id in parameters'
            )
        );
    }

    /**
     * Tests passwordField with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testPasswordFieldSetDefaultXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="password" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value" />';
        $actual   = Tg::passwordField($options);
        Tg::setDefault('some_field_name', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML passwordField with setDefault')
        );
    }

    /**
     * Tests passwordField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testPasswordFieldDisplayToXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="password" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value" />';
        $actual   = Tg::passwordField($options);
        Tg::displayTo('some_field_name', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML passwordField with displayTo')
        );
    }

    /**
     * Tests passwordField with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testPasswordFieldSetDefaultElementNotPresentXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<input type="password" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::passwordField($options);
        Tg::setDefault('some_field', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML passwordField with setDefault')
        );
    }

    /**
     * Tests passwordField with displayTo to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testPasswordFieldDisplayToElementNotPresentXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<input type="password" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::passwordField($options);
        Tg::displayTo('some_field', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML passwordField with displayTo')
        );
    }

    // -------------------------------------------------------------------------
    // fileField
    // -------------------------------------------------------------------------
    /**
     * Tests fileField with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testFileFieldBasic()
    {
        $options  = 'some_field_name';
        $expected = '<input type="file" name="some_field_name" '
                  . 'id="some_field_name" value="">';
        $actual   = Tg::fileField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'fileField basic')
        );
    }

    /**
     * Tests fileField with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testFileFieldWithArrayBasic()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="file" class="some_class" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::fileField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'fileField basic with array')
        );
    }

    /**
     * Tests fileField with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testFileFieldWithIdInParameters()
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="file" id="some_id" class="some_class" '
                  . 'size="10" name="some_field_name" value="">';
        $actual   = Tg::fileField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'fileField with id in parameters')
        );
    }

    /**
     * Tests fileField with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testFileFieldWithNameAndNotIdInParameters()
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="file" name="some_other_name" '
                  . 'class="some_class" size="10" id="some_field_name" '
                  . 'value="">';
        $actual   = Tg::fileField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'fileField with name and id in parameters'
            )
        );
    }

    /**
     * Tests fileField with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testFileFieldSetDefault()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="file" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value">';
        $actual   = Tg::fileField($options);
        Tg::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'fileField with setDefault')
        );
    }

    /**
     * Tests fileField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testFileFieldDisplayTo()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="file" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value">';
        $actual   = Tg::fileField($options);
        Tg::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'fileField with displayTo')
        );
    }

    /**
     * Tests fileField with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testFileFieldSetDefaultElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<input type="file" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::fileField($options);
        Tg::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'fileField with setDefault')
        );
    }

    /**
     * Tests fileField with displayTo to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testFileFieldDisplayToElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<input type="file" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::fileField($options);
        Tg::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'fileField with displayTo')
        );
    }

    /**
     * Tests fileField with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testFileFieldBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="file" name="some_field_name" '
                  . 'id="some_field_name" value="" />';
        $actual   = Tg::fileField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML fileField basic')
        );
    }

    /**
     * Tests fileField with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testFileFieldWithArrayBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="file" class="some_class" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::fileField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML fileField basic with array')
        );
    }

    /**
     * Tests fileField with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testFileFieldWithIdInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="file" id="some_id" class="some_class" '
                  . 'size="10" name="some_field_name" value="" />';
        $actual   = Tg::fileField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML fileField with id in parameters')
        );
    }

    /**
     * Tests fileField with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testFileFieldWithNameAndNotIdInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="file" name="some_other_name" '
                  . 'class="some_class" size="10" id="some_field_name" '
                  . 'value="" />';
        $actual   = Tg::fileField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'fileField with name and id in parameters'
            )
        );
    }

    /**
     * Tests fileField with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testFileFieldSetDefaultXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="file" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value" />';
        $actual   = Tg::fileField($options);
        Tg::setDefault('some_field_name', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML fileField with setDefault')
        );
    }

    /**
     * Tests fileField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testFileFieldDisplayToXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="file" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value" />';
        $actual   = Tg::fileField($options);
        Tg::displayTo('some_field_name', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML fileField with displayTo')
        );
    }

    /**
     * Tests fileField with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testFileFieldSetDefaultElementNotPresentXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<input type="file" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::fileField($options);
        Tg::setDefault('some_field', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML fileField with setDefault')
        );
    }

    /**
     * Tests fileField with displayTo to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testFileFieldDisplayToElementNotPresentXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<input type="file" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::fileField($options);
        Tg::displayTo('some_field', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML fileField with displayTo')
        );
    }

    // -------------------------------------------------------------------------
    // checkField
    // -------------------------------------------------------------------------
    /**
     * Tests checkField with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testCheckFieldBasic()
    {
        $options  = 'some_field_name';
        $expected = '<input type="checkbox" name="some_field_name" '
                  . 'id="some_field_name" value="">';
        $actual   = Tg::checkField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'checkField basic')
        );
    }

    /**
     * Tests checkField with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testCheckFieldWithArrayBasic()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="checkbox" class="some_class" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::checkField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'checkField basic with array')
        );
    }

    /**
     * Tests checkField with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testCheckFieldWithIdInParameters()
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="checkbox" id="some_id" class="some_class" '
                  . 'size="10" name="some_field_name" value="">';
        $actual   = Tg::checkField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'checkField with id in parameters')
        );
    }

    /**
     * Tests checkField with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testCheckFieldWithNameAndNotIdInParameters()
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="checkbox" name="some_other_name" '
                  . 'class="some_class" size="10" id="some_field_name" '
                  . 'value="">';
        $actual   = Tg::checkField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'checkField with name and id in parameters'
            )
        );
    }

    /**
     * Tests checkField with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testCheckFieldSetDefault()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="checkbox" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value">';
        $actual   = Tg::checkField($options);
        Tg::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'checkField with setDefault')
        );
    }

    /**
     * Tests checkField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testCheckFieldDisplayTo()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="checkbox" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value" checked="checked">';
        $actual   = Tg::checkField($options);
        Tg::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'checkField with displayTo')
        );
    }

    /**
     * Tests checkField with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testCheckFieldSetDefaultElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<input type="checkbox" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::checkField($options);
        Tg::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'checkField with setDefault')
        );
    }

    /**
     * Tests checkField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testCheckFieldDisplayToElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<input type="checkbox" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::checkField($options);
        Tg::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'checkField with displayTo')
        );
    }

    /**
     * Tests checkField with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testCheckFieldBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="checkbox" name="some_field_name" '
                  . 'id="some_field_name" value="" />';
        $actual   = Tg::checkField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML checkField basic')
        );
    }

    /**
     * Tests checkField with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testCheckFieldWithArrayBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="checkbox" class="some_class" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::checkField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML checkField basic with array')
        );
    }

    /**
     * Tests checkField with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testCheckFieldWithIdInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="checkbox" id="some_id" class="some_class" '
                  . 'size="10" name="some_field_name" value="" />';
        $actual   = Tg::checkField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML checkField with id in parameters')
        );
    }

    /**
     * Tests checkField with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testCheckFieldWithNameAndNotIdInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="checkbox" name="some_other_name" '
                  . 'class="some_class" size="10" id="some_field_name" '
                  . 'value="" />';
        $actual   = Tg::checkField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'checkField with name and id in parameters'
            )
        );
    }

    /**
     * Tests checkField with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testCheckFieldSetDefaultXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="checkbox" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value" checked="checked" />';
        $actual   = Tg::checkField($options);
        Tg::setDefault('some_field_name', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML checkField with setDefault')
        );
    }

    /**
     * Tests checkField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testCheckFieldDisplayToXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="checkbox" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value" checked="checked" />';
        $actual   = Tg::checkField($options);
        Tg::displayTo('some_field_name', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML checkField with displayTo')
        );
    }

    /**
     * Tests checkField with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testCheckFieldSetDefaultElementNotPresentXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<input type="checkbox" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::checkField($options);
        Tg::setDefault('some_field', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML checkField with setDefault')
        );
    }

    /**
     * Tests checkField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testCheckFieldDisplayToElementNotPresentXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<input type="checkbox" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::checkField($options);
        Tg::displayTo('some_field', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML checkField with displayTo')
        );
    }

    // -------------------------------------------------------------------------
    // radioField
    // -------------------------------------------------------------------------
    /**
     * Tests radioField with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldBasic()
    {
        $options  = 'some_field_name';
        $expected = '<input type="radio" name="some_field_name" '
                  . 'id="some_field_name" value="">';
        $actual   = Tg::radioField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'radioField basic')
        );
    }

    /**
     * Tests radioField with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldWithArrayBasic()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="radio" class="some_class" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::radioField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'radioField basic with array')
        );
    }

    /**
     * Tests radioField with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldWithIdInParameters()
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="radio" id="some_id" class="some_class" '
                  . 'size="10" name="some_field_name" value="">';
        $actual   = Tg::radioField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'radioField with id in parameters')
        );
    }

    /**
     * Tests radioField with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldWithNameAndNotIdInParameters()
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="radio" name="some_other_name" '
                  . 'class="some_class" size="10" id="some_field_name" '
                  . 'value="">';
        $actual   = Tg::radioField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'radioField with name and id in parameters'
            )
        );
    }

    /**
     * Tests radioField with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldSetDefault()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="radio" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value">';
        $actual   = Tg::radioField($options);
        Tg::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'radioField with setDefault')
        );
    }

    /**
     * Tests radioField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldDisplayTo()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="radio" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value">';
        $actual   = Tg::radioField($options);
        Tg::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'radioField with displayTo')
        );
    }

    /**
     * Tests radioField with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldSetDefaultElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<input type="radio" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::radioField($options);
        Tg::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'radioField with setDefault')
        );
    }

    /**
     * Tests radioField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldDisplayToElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<input type="radio" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="">';
        $actual   = Tg::radioField($options);
        Tg::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'radioField with displayTo')
        );
    }

    /**
     * Tests radioField with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="radio" name="some_field_name" '
                  . 'id="some_field_name" value="" />';
        $actual   = Tg::radioField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML radioField basic')
        );
    }

    /**
     * Tests radioField with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldWithArrayBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="radio" class="some_class" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::radioField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML radioField basic with array')
        );
    }

    /**
     * Tests radioField with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldWithIdInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="radio" id="some_id" class="some_class" '
                  . 'size="10" name="some_field_name" value="" />';
        $actual   = Tg::radioField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML radioField with id in parameters')
        );
    }

    /**
     * Tests radioField with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldWithNameAndNotIdInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="radio" name="some_other_name" '
                  . 'class="some_class" size="10" id="some_field_name" '
                  . 'value="" />';
        $actual   = Tg::radioField($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'radioField with name and id in parameters'
            )
        );
    }

    /**
     * Tests radioField with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldSetDefaultXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="radio" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value" />';
        $actual   = Tg::radioField($options);
        Tg::setDefault('some_field_name', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML radioField with setDefault')
        );
    }

    /**
     * Tests radioField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldDisplayToXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="radio" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" '
                  . 'value="some_default_value" />';
        $actual   = Tg::radioField($options);
        Tg::displayTo('some_field_name', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML radioField with displayTo')
        );
    }

    /**
     * Tests radioField with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldSetDefaultElementNotPresentXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<input type="radio" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::radioField($options);
        Tg::setDefault('some_field', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML radioField with setDefault')
        );
    }

    /**
     * Tests radioField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-15
     */
    public function testRadioFieldDisplayToElementNotPresentXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<input type="radio" class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name" value="" />';
        $actual   = Tg::radioField($options);
        Tg::displayTo('some_field', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML radioField with displayTo')
        );
    }

    // -------------------------------------------------------------------------
    // submitButton
    // -------------------------------------------------------------------------
    /**
     * Tests submitButton with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testSubmitButtonBasic()
    {
        $options  = 'some_field_name';
        $expected = '<input type="submit" value="some_field_name">';
        $actual   = Tg::submitButton($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'submitButton basic')
        );
    }

    /**
     * Tests submitButton with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     * @todo   Fix the order
     */
    public function testSubmitButtonWithArrayBasic()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
//        $expected = '<input type="submit" value="some_field_name" '
//                  . 'class="some_class">';
        $expected = '<input type="submit" class="some_class" '
                  . 'value="some_field_name">';
        $actual   = Tg::submitButton($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'submitButton basic with array')
        );
    }

    /**
     * Tests submitButton with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     * @todo   Fix the order
     */
    public function testSubmitButtonWithIdInParameters()
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="submit" id="some_id" class="some_class" '
                  . 'size="10" value="some_field_name">';
        $actual   = Tg::submitButton($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'submitButton with id in parameters')
        );
    }

    /**
     * Tests submitButton with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     * @todo   Fix the order
     */
    public function testSubmitButtonWithNameAndNotIdInParameters()
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="submit" name="some_other_name" '
                  . 'class="some_class" size="10" value="some_field_name">';
        $actual   = Tg::submitButton($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'submitButton with name and id in parameters'
            )
        );
    }

    /**
     * Tests submitButton with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     * @todo   Fix the order
     */
    public function testSubmitButtonSetDefault()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="submit" class="some_class" size="10" '
                  . 'value="some_field_name">';
        $actual   = Tg::submitButton($options);
        Tg::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'submitButton with setDefault')
        );
    }

    /**
     * Tests submitButton with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     * @todo   Fix the order
     */
    public function testSubmitButtonDisplayTo()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="submit" class="some_class" size="10" '
                  . 'value="some_field_name">';
        $actual   = Tg::submitButton($options);
        Tg::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'submitButton with displayTo')
        );
    }

    /**
     * Tests submitButton with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     * @todo   Fix the order
     */
    public function testSubmitButtonSetDefaultElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<input type="submit" class="some_class" size="10" '
                  . 'value="some_field_name">';
        $actual   = Tg::submitButton($options);
        Tg::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'submitButton with setDefault')
        );
    }

    /**
     * Tests submitButton with displayTo to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     * @todo   Fix the order
     */
    public function testSubmitButtonDisplayToElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<input type="submit" class="some_class" size="10" '
                  . 'value="some_field_name">';
        $actual   = Tg::submitButton($options);
        Tg::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'submitButton with displayTo')
        );
    }

    /**
     * Tests submitButton with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testSubmitButtonBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="submit" value="some_field_name" />';
        $actual   = Tg::submitButton($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML submitButton basic')
        );
    }

    /**
     * Tests submitButton with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     * @todo   Fix the order
     */
    public function testSubmitButtonWithArrayBasicXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
//        $expected = '<input type="submit" value="some_field_name" '
//                  . 'class="some_class" />';
        $expected = '<input type="submit" class="some_class" '
                  . 'value="some_field_name" />';
        $actual   = Tg::submitButton($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML submitButton basic with array')
        );
    }

    /**
     * Tests submitButton with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     * @todo   Fix the order
     */
    public function testSubmitButtonWithIdInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="submit" id="some_id" class="some_class" '
                  . 'size="10" value="some_field_name" />';
        $actual   = Tg::submitButton($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML submitButton with id in parameters')
        );
    }

    /**
     * Tests submitButton with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     * @todo   Fix the order
     */
    public function testSubmitButtonWithNameAndNotIdInParametersXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="submit" name="some_other_name" '
                  . 'class="some_class" size="10" value="some_field_name" />';
        $actual   = Tg::submitButton($options);
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'submitButton with name and id in parameters'
            )
        );
    }

    /**
     * Tests submitButton with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     * @todo   Fix the order
     */
    public function testSubmitButtonSetDefaultXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="submit" class="some_class" size="10" '
                  . 'value="some_field_name" />';
        $actual   = Tg::submitButton($options);
        Tg::setDefault('some_field_name', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML submitButton with setDefault')
        );
    }

    /**
     * Tests submitButton with displayTo
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     * @todo   Fix the order
     */
    public function testSubmitButtonDisplayToXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="submit" class="some_class" size="10" '
                  . 'value="some_field_name" />';
        $actual   = Tg::submitButton($options);
        Tg::displayTo('some_field_name', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML submitButton with displayTo')
        );
    }

    /**
     * Tests submitButton with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     * @todo   Fix the order
     */
    public function testSubmitButtonSetDefaultElementNotPresentXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'some_default_value');
        $expected = '<input type="submit" class="some_class" size="10" '
                  . 'value="some_field_name" />';
        $actual   = Tg::submitButton($options);
        Tg::setDefault('some_field', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML submitButton with setDefault')
        );
    }

    /**
     * Tests submitButton with displayTo to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     * @todo   Fix the order
     */
    public function testSubmitButtonDisplayToElementNotPresentXHTML()
    {
        Tg::setDoctype(Tg::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'some_default_value');
        $expected = '<input type="submit" class="some_class" size="10" '
                  . 'value="some_field_name" />';
        $actual   = Tg::submitButton($options);
        Tg::displayTo('some_field', '');
        Tg::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML submitButton with displayTo')
        );
    }

    // -------------------------------------------------------------------------
    // selectStatic
    // -------------------------------------------------------------------------
    /**
     * Tests selectStatic with string as a parameter throws exception
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testSelectStaticStringThrowsException()
    {
        $name    = 'some_field_name';
        $options = 'some_values';

        try {
            $actual   = Tg::selectStatic($name, $options);
        } catch (\Phalcon\Tag\Exception $e) {
            // This is where we need to be
        }

        $this->assertInstanceOf(
            'Phalcon\Tag\Exception',
            $e,
            'selectStatic does not throw correct exception with wrong parameters'
        );
    }

    /**
     * Tests selectStatic with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testSelectStaticWithArrayBasic()
    {
        $name    = 'some_field_name';
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select name="some_field_name" '
                  . 'id="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($name, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'selectStatic basic with array')
        );
    }

    /**
     * Tests selectStatic with id in parameters
     *
     * @issue  54
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testSelectStaticWithIdInParameters_T54()
    {
        $params = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
        );
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_id" class="some_class" '
                  . 'name="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($params, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'selectStatic with id in parameters'
            )
        );
    }

    /**
     * Tests selectStatic with name and not id in parameters
     *
     * @issue  54
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testSelectStaticWithNameAndNotIdInParameters_T54()
    {
        $params = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
        );
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_id" class="some_class" '
                  . 'name="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($params, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'selectStatic with name and id in parameters'
            )
        );
    }

    /**
     * Tests selectStatic with value in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testSelectStaticWithValueInParameters()
    {
        $params = array(
            'some_field_name',
            'value' => 'I',
            'class' => 'some_class',
        );
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select class="some_class" '
                  . 'name="some_field_name" id="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" '
                  . 'value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($params, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'selectStatic with value in parameters'
            )
        );
    }

    /**
     * Tests selectStatic with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testSelectStaticSetDefault()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" '
                  . 'value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($params, $options);
        Tg::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testSelectStaticDisplayTo()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" '
                  . 'value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($params, $options);
        Tg::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testSelectStaticSetDefaultElementNotPresent()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($params, $options);
        Tg::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testSelectStaticDisplayToElementNotPresent()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($params, $options);
        Tg::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with string as a parameter throws exception
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testSelectStaticStringThrowsExceptionXHTML()
    {
        $name    = 'some_field_name';
        $options = 'some_values';

        try {
            $actual   = Tg::selectStatic($name, $options);
        } catch (\Phalcon\Tag\Exception $e) {
            // This is where we need to be
        }

        $this->assertInstanceOf(
            'Phalcon\Tag\Exception',
            $e,
            'selectStatic does not throw correct exception with wrong parameters'
        );
    }

    /**
     * Tests selectStatic with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testSelectStaticWithArrayBasicXHTML()
    {
        $name    = 'some_field_name';
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select name="some_field_name" '
                  . 'id="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($name, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML selectStatic basic with array')
        );
    }

    /**
     * Tests selectStatic with id in parameters
     *
     * @issue  54
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testSelectStaticWithIdInParameters_T54XHTML()
    {
        $params = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
        );
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_id" class="some_class" '
                  . 'name="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($params, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'selectStatic with id in parameters'
            )
        );
    }

    /**
     * Tests selectStatic with name and not id in parameters
     *
     * @issue  54
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testSelectStaticWithNameAndNotIdInParameters_T54XHTML()
    {
        $params = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
        );
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_id" class="some_class" '
                  . 'name="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($params, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'selectStatic with name and id in parameters'
            )
        );
    }

    /**
     * Tests selectStatic with value in parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testSelectStaticWithValueInParametersXHTML()
    {
        $params = array(
            'some_field_name',
            'value' => 'I',
            'class' => 'some_class',
        );
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select class="some_class" '
                  . 'name="some_field_name" id="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" '
                  . 'value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($params, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'selectStatic with value in parameters'
            )
        );
    }

    /**
     * Tests selectStatic with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testSelectStaticSetDefaultXHTML()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field_name', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" '
                  . 'value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($params, $options);
        Tg::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with setDefault
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testSelectStaticDisplayToXHTML()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field_name', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" '
                  . 'value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($params, $options);
        Tg::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testSelectStaticSetDefaultElementNotPresentXHTML()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::setDefault('some_field', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($params, $options);
        Tg::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-26
     */
    public function testSelectStaticDisplayToElementNotPresentXHTML()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        Tg::displayTo('some_field', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select class="some_class" size="10" '
                  . 'name="some_field_name" id="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::selectStatic($params, $options);
        Tg::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML selectStatic with setDefault')
        );
    }

    // -------------------------------------------------------------------------
    // setTitle, appendTitle, prependTitle
    // -------------------------------------------------------------------------
    /**
     * Tests setTitle
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-05
     */
    public function testSetTitle()
    {
        $value = 'This is my title';

        Tg::setTitle($value);

        $expected = "<title>{$value}</title>" . PHP_EOL;
        $actual   = Tg::getTitle();

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'setTitle')
        );
    }

    /**
     * Tests appendTitle
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-05
     */
    public function testAppendTitle()
    {
        $value = 'This is my title';

        Tg::setTitle($value);

        $append = ' - Welcome!';

        Tg::appendTitle($append);

        $expected = "<title>{$value}{$append}</title>" . PHP_EOL;
        $actual   = Tg::getTitle();

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'appendTitle')
        );
    }

    /**
     * Tests prependTitle
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-05
     */
    public function testPrependTitle()
    {
        $value = 'This is my title';

        Tg::setTitle($value);

        $prepend = 'PhalconPHP -';

        Tg::prependTitle($prepend);

        $expected = "<title>{$prepend}{$value}</title>" . PHP_EOL;
        $actual   = Tg::getTitle();

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'prependTitle')
        );
    }

    // -------------------------------------------------------------------------
    // linkTo
    // -------------------------------------------------------------------------
    /**
     * Tests linkTo with string as url and name parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-08
     */
    public function testLinkToWithStringAsURLAndName()
    {
        $url  = 'some_url';
        $name = 'some_name';

        $expected = '<a href="/some_url">some_name</a>';
        $actual   = Tg::linkTo($url, $name);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'linkTo with strings as parameters')
        );
    }

    /**
     * Tests linkTo with empty string as URL and string as name parameter
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-08
     */
    public function testLinkToWithEmptyStringAsURLAndStringAsName()
    {
        $url  = '';
        $name = 'some_name';

        $expected = '<a href="/">some_name</a>';
        $actual   = Tg::linkTo($url, $name);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'linkTo with empty URL and string as name')
        );
    }

    /**
     * Tests linkTo with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-08
     */
    public function testLinkToWithArrayBasic()
    {
        $params = array(
            'some_url',
            'some_name',
        );
        $expected = '<a href="/some_url">some_name</a>';
        $actual   = Tg::linkTo($params);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'linkTo with array as parameters')
        );
    }

    /**
     * Tests linkTo with named array as parameters
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-08
     */
    public function testLinkToWithArrayNamedBasic()
    {
        $params = array(
            'action' => 'some_url',
            'text'   => 'some_name',
        );
        $expected = '<a href="/some_url">some_name</a>';
        $actual   = Tg::linkTo($params);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'linkTo with named array as parameters basic'
            )
        );
    }

    /**
     * Tests linkTo with named array as parameters (more than the basic)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-08
     */
    public function testLinkToWithArrayNamed()
    {
        $params = array(
            'action' => 'some_url',
            'text'   => 'some_name',
            'class'  => 'btn btn-primary',
        );
        $expected = '<a href="/some_url" class="btn btn-primary">some_name</a>';
        $actual   = Tg::linkTo($params);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'linkTo with named array as parameters (full params)'
            )
        );
    }
}