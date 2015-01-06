<?php
/**
 * PhalconTestHelper.php
 * \Phalcon\Tag\UnitTest
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

namespace Phalcon\Test\Tag;

class UnitTest extends \Phalcon\Test\UnitTestCase
{
	private $message = "%s does not return proper html element";


	// -------------------------------------------------------------------------
	// Doctype
	// -------------------------------------------------------------------------
	/**
	 * Tests the doctype
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testDoctypeSet()
	{
		$doctype  = \Phalcon\Tag::HTML5;
		$expected = "<!DOCTYPE html>" . PHP_EOL;
		\Phalcon\Tag::setDoctype($doctype);
		$actual   = \Phalcon\Tag::getDoctype($doctype);
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testImageBasic()
	{
		$options  = 'img/hello.gif';
		$expected = '<img src="/img/hello.gif">';
		$actual   = \Phalcon\Tag::image($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'Image basic')
		);
	}

	/**
	 * Tests an image tag with an array passed as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testImageWithArrayBasic()
	{
		$options  = array(
			'img/hello.gif',
			'class' => 'some_class',
		);
		$expected = '<img src="/img/hello.gif" class="some_class">';
		$actual   = \Phalcon\Tag::image($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'Image basic with array')
		);
	}

	/**
	 * Tests an image tag with the src attribute passed in as a parameter
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$actual   = \Phalcon\Tag::image($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'Image basic with src in parameters')
		);
	}

	/**
	 * Tests an image tag with a bare minimum of information passed
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testImageBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'img/hello.gif';
		$expected = '<img src="/img/hello.gif" />';
		$actual   = \Phalcon\Tag::image($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML Image basic')
		);
	}

	/**
	 * Tests an image tag with an array passed as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testImageWithArrayBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = array(
			'img/hello.gif',
			'class' => 'some_class',
		);
		$expected = '<img src="/img/hello.gif" class="some_class" />';
		$actual   = \Phalcon\Tag::image($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML Image basic with array')
		);
	}

	/**
	 * Tests an image tag with the src attribute passed in as a parameter
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testImageWithSrcInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = array(
			'img/hello.gif',
			'src'   => 'img/goodbye.gif',
			'class' => 'some_class',
		);
		$expected = '<img src="/img/goodbye.gif" class="some_class" />';
		$actual   = \Phalcon\Tag::image($options);
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testStylesheetLinkLocal()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::HTML5);

		$options  = 'css/phalcon.css';
		$expected = '<link rel="stylesheet" type="text/css" href="/css/phalcon.css">' . PHP_EOL;
		$actual   = \Phalcon\Tag::stylesheetLink($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'StylesheetLink local')
		);
	}

	/**
	 * Tests stylesheetLink with an array passed for a local link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testStylesheetLinkWithArrayLocal()
	{
		$options  = array('css/phalcon.css');
		$expected = '<link rel="stylesheet" type="text/css" href="/css/phalcon.css">' . PHP_EOL;
		$actual   = \Phalcon\Tag::stylesheetLink($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'StylesheetLink local with Array')
		);
	}

	/**
	 * Tests stylesheetLink with a string as the second parameter - local link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testStylesheetLinkWithStringAsSecondParameterLocal()
	{
		$options  = array('css/phalcon.css');
		$expected = '<link rel="stylesheet" type="text/css" href="/css/phalcon.css">' . PHP_EOL;
		$actual   = \Phalcon\Tag::stylesheetLink($options, 'hello');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testStylesheetLinkRemote()
	{
		$options  = 'http://fonts.googleapis.com/css?family=Rosario';
		$expected = '<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Rosario">' . PHP_EOL;
		$actual   = \Phalcon\Tag::stylesheetLink($options, false);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'StylesheetLink remote')
		);
	}

	/**
	 * Tests stylesheetLink with an array passed for a remote link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testStylesheetLinkWithArrayRemote()
	{
		$options  = array('http://fonts.googleapis.com/css?family=Rosario');
		$expected = '<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Rosario">' . PHP_EOL;
		$actual   = \Phalcon\Tag::stylesheetLink($options, false);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'StylesheetLink remote with Array')
		);
	}

	/**
	 * Tests stylesheetLink with a string as the second parameter - remote link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testStylesheetLinkWithStringAsSecondParameterRemote()
	{
		$options  = 'http://fonts.googleapis.com/css?family=Rosario';
		$expected = '<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Rosario">' . PHP_EOL;
		$actual   = \Phalcon\Tag::stylesheetLink($options, '0');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testStylesheetLinkLocalXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'css/phalcon.css';
		$expected = '<link rel="stylesheet" type="text/css" href="/css/phalcon.css" />' . PHP_EOL;
		$actual   = \Phalcon\Tag::stylesheetLink($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML StylesheetLink local')
		);
	}

	/**
	 * Tests stylesheetLink with an array passed for a local link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testStylesheetLinkWithArrayLocalXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = array('css/phalcon.css');
		$expected = '<link rel="stylesheet" type="text/css" href="/css/phalcon.css" />' . PHP_EOL;
		$actual   = \Phalcon\Tag::stylesheetLink($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML StylesheetLink local with Array')
		);
	}

	/**
	 * Tests stylesheetLink with a string as the second parameter - local link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testStylesheetLinkWithStringAsSecondParameterLocalXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = array('css/phalcon.css');
		$expected = '<link rel="stylesheet" type="text/css" href="/css/phalcon.css" />' . PHP_EOL;
		$actual   = \Phalcon\Tag::stylesheetLink($options, 'hello');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testStylesheetLinkRemoteXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'http://fonts.googleapis.com/css?family=Rosario';
		$expected = '<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Rosario" />' . PHP_EOL;
		$actual   = \Phalcon\Tag::stylesheetLink($options, FALSE);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML StylesheetLink remote')
		);
	}

	/**
	 * Tests stylesheetLink with an array passed for a remote link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testStylesheetLinkWithArrayRemoteXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = array('http://fonts.googleapis.com/css?family=Rosario');
		$expected = '<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Rosario" />' . PHP_EOL;
		$actual   = \Phalcon\Tag::stylesheetLink($options, FALSE);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML StylesheetLink remote with Array')
		);
	}

	/**
	 * Tests stylesheetLink with a string as the second parameter - remote link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testStylesheetLinkWithStringAsSecondParameterRemoteXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'http://fonts.googleapis.com/css?family=Rosario';
		$expected = '<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Rosario" />' . PHP_EOL;
		$actual   = \Phalcon\Tag::stylesheetLink($options, '0');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testJavascriptIncludeLocal()
	{
		$options  = 'js/phalcon.js';
		$expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
		$actual   = \Phalcon\Tag::javascriptInclude($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'JavascriptInclude local')
		);
	}

	/**
	 * Tests javascriptInclude with an array passed for a local link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testJavascriptIncludeWithArrayLocal()
	{
		$options  = array('js/phalcon.js');
		$expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
		$actual   = \Phalcon\Tag::javascriptInclude($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'JavascriptInclude local with Array')
		);
	}

	/**
	 * Tests javascriptInclude with a string as the second parameter - local link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testJavascriptIncludeWithStringAsSecondParameterLocal()
	{
		$options  = 'js/phalcon.js';
		$expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
		$actual   = \Phalcon\Tag::javascriptInclude($options, 'hello');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf(
				$this->message,
				'JavascriptInclude local with string as second parameter'
			)
		);
	}

	/**
	 * Tests javascriptInclude for a remote link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testJavascriptIncludeRemote()
	{
		$options  = 'http://my.local.com/js/phalcon.js';
		$expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
		$actual   = \Phalcon\Tag::javascriptInclude($options, false);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'JavascriptInclude remote')
		);
	}

	/**
	 * Tests javascriptInclude with an array passed for a remote link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testJavascriptIncludeWithArrayRemote()
	{
		$options  = array('http://my.local.com/js/phalcon.js');
		$expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
		$actual   = \Phalcon\Tag::javascriptInclude($options, false);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'JavascriptInclude remote with Array')
		);
	}

	/**
	 * Tests javascriptInclude with a string as the second parameter - remote link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testJavascriptIncludeWithStringAsSecondParameterRemote()
	{
		$options  = 'http://my.local.com/js/phalcon.js';
		$expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
		$actual   = \Phalcon\Tag::javascriptInclude($options, '0');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testJavascriptIncludeLocalXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'js/phalcon.js';
		$expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
		$actual   = \Phalcon\Tag::javascriptInclude($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML JavascriptInclude local')
		);
	}

	/**
	 * Tests javascriptInclude with an array passed for a local link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testJavascriptIncludeWithArrayLocalXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = array('js/phalcon.js');
		$expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
		$actual   = \Phalcon\Tag::javascriptInclude($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML JavascriptInclude local with Array')
		);
	}

	/**
	 * Tests javascriptInclude with a string as the second parameter - local link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testJavascriptIncludeWithStringAsSecondParameterLocalXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'js/phalcon.js';
		$expected = '<script type="text/javascript" src="/js/phalcon.js"></script>' . PHP_EOL;
		$actual   = \Phalcon\Tag::javascriptInclude($options, 'hello');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf(
				$this->message,
				'xhtml JavascriptInclude local with string as second parameter'
			)
		);
	}

	/**
	 * Tests javascriptInclude for a remote link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testJavascriptIncludeRemoteXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'http://my.local.com/js/phalcon.js';
		$expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
		$actual   = \Phalcon\Tag::javascriptInclude($options, false);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML JavascriptInclude remote')
		);
	}

	/**
	 * Tests javascriptInclude with an array passed for a remote link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testJavascriptIncludeWithArrayRemoteXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = array('http://my.local.com/js/phalcon.js');
		$expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
		$actual   = \Phalcon\Tag::javascriptInclude($options, false);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML JavascriptInclude remote with Array')
		);
	}

	/**
	 * Tests javascriptInclude with a string as the second parameter - remote link
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testJavascriptIncludeWithStringAsSecondParameterRemoteXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'http://my.local.com/js/phalcon.js';
		$expected = '<script type="text/javascript" src="http://my.local.com/js/phalcon.js"></script>' . PHP_EOL;
		$actual   = \Phalcon\Tag::javascriptInclude($options, '0');
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testResetInputSetDefaultT53()
	{
		$options  = 'some_field_name';
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="Wall-E">';
		\Phalcon\Tag::setDefault('some_field_name', 'Wall-E');
		$actual   = \Phalcon\Tag::textField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'resetInput before contains a value')
		);
		\Phalcon\Tag::resetInput();

		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="">';
		$actual   = \Phalcon\Tag::textField($options);
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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testResetInputDisplayToT53()
	{
		$options  = 'some_field_name';
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="Wall-E">';
		\Phalcon\Tag::displayTo('some_field_name', 'Wall-E');
		$actual   = \Phalcon\Tag::textField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'resetInput before contains a value')
		);
		\Phalcon\Tag::resetInput();

		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="">';
		$actual   = \Phalcon\Tag::textField($options);
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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testResetInputSetDefaultXHTMLT53()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'some_field_name';
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="Wall-E" />';
		\Phalcon\Tag::setDefault('some_field_name', 'Wall-E');
		$actual   = \Phalcon\Tag::textField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML resetInput before contains a value')
		);
		\Phalcon\Tag::resetInput();

		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="" />';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::setDoctype('');
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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testResetInputDisplayToXHTMLT53()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'some_field_name';
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="Wall-E" />';
		\Phalcon\Tag::displayTo('some_field_name', 'Wall-E');
		$actual   = \Phalcon\Tag::textField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML resetInput before contains a value')
		);
		\Phalcon\Tag::resetInput();

		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="" />';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::setDoctype('');
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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testTextBasic()
	{
		$options  = 'some_field_name';
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="">';
		$actual   = \Phalcon\Tag::textField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'textField basic')
		);
	}

	/**
	 * Tests textField with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testTextWithArrayBasic()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
		);
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="" class="some_class">';
		$actual   = \Phalcon\Tag::textField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'textField with array basic')
		);
	}

	/**
	 * Tests textField with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="text" id="some_id" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::textField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'textField with id in parameters')
		);
	}

	/**
	 * Tests textField with name and not id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="text" id="some_field_name" name="some_other_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::textField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'textField with name and id in parameters')
		);
	}

	/**
	 * Tests textField with setDefault
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testTextSetDefault()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::setDefault('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'textField with setDefault')
		);
	}

	/**
	 * Tests textField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testTextDisplayTo()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::displayTo('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'textField with displayTo')
		);
	}

	/**
	 * Tests textField with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testTextSetDefaultElementNotPresent()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::setDefault('some_field', '');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testTextDisplayToElementNotPresent()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::displayTo('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'textField with displayTo')
		);
	}

	/**
	 * Tests testField with string as a parameter
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testTextBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'some_field_name';
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="" />';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML textField basic')
		);
	}

	/**
	 * Tests textField with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testTextWithArrayBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
		);
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="" class="some_class" />';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML textField with array basic')
		);
	}

	/**
	 * Tests textField with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testTextWithIdInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'id'    => 'some_id',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="text" id="some_id" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML textField with id in parameters')
		);
	}

	/**
	 * Tests textField with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testTextWithArrayName()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name[]',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="text" name="some_field_name[]" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML textField with id in parameters')
		);
	}

	/**
	 * Tests textField with name and not id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testTextWithNameAndNotIdInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'name'  => 'some_other_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="text" id="some_field_name" name="some_other_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML textField with name and id in parameters')
		);
	}

	/**
	 * Tests textField with setDefault
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testTextSetDefaultXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::setDefault('some_field_name', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML textField with setDefault')
		);
	}

	/**
	 * Tests textField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testTextDisplayToXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::displayTo('some_field_name', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML textField with displayTo')
		);
	}

	/**
	 * Tests textField with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testTextSetDefaultElementNotPresentXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::setDefault('some_field', '');
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testTextDisplayToElementNotPresentXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<input type="text" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::textField($options);
		\Phalcon\Tag::displayTo('some_field', '');
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testTextareaBasic()
	{
		$options  = 'some_field_name';
		$expected = '<textarea id="some_field_name" name="some_field_name"></textarea>';
		$actual   = \Phalcon\Tag::textArea($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'textArea basic')
		);
	}

	/**
	 * Tests textArea with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testTextareaWithArrayBasic()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
		);
		$expected = '<textarea id="some_field_name" name="some_field_name" class="some_class"></textarea>';
		$actual   = \Phalcon\Tag::textArea($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'textArea basic with array')
		);
	}

	/**
	 * Tests textArea with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<textarea id="some_id" name="some_field_name" class="some_class" size="10"></textarea>';
		$actual   = \Phalcon\Tag::textArea($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'textArea with id in parameters')
		);
	}

	/**
	 * Tests textArea with name and not id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<textarea id="some_field_name" name="some_other_name" class="some_class" size="10"></textarea>';
		$actual   = \Phalcon\Tag::textArea($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'textArea with name and id in parameters')
		);
	}

	/**
	 * Tests textArea with setDefault
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testTextareaSetDefault()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<textarea id="some_field_name" name="some_field_name" class="some_class" size="10">some_default_value</textarea>';
		$actual   = \Phalcon\Tag::textArea($options);
		\Phalcon\Tag::setDefault('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'textArea with setDefault')
		);
	}

	/**
	 * Tests textArea with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testTextareaDisplayTo()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<textarea id="some_field_name" name="some_field_name" class="some_class" size="10">some_default_value</textarea>';
		$actual   = \Phalcon\Tag::textArea($options);
		\Phalcon\Tag::displayTo('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'textArea with displayTo')
		);
	}

	/**
	 * Tests textArea with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testTextareaSetDefaultElementNotPresent()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<textarea id="some_field_name" name="some_field_name" class="some_class" size="10"></textarea>';
		$actual   = \Phalcon\Tag::textArea($options);
		\Phalcon\Tag::setDefault('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'textArea with setDefault')
		);
	}

	/**
	 * Tests textArea with displayTo to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testTextareaDisplayToElementNotPresent()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<textarea id="some_field_name" name="some_field_name" class="some_class" size="10"></textarea>';
		$actual   = \Phalcon\Tag::textArea($options);
		\Phalcon\Tag::displayTo('some_field', '');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testHiddenFieldBasic()
	{
		$options  = 'some_field_name';
		$expected = '<input type="hidden" id="some_field_name" name="some_field_name" value="">';
		$actual   = \Phalcon\Tag::hiddenField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'hiddenField basic')
		);
	}

	/**
	 * Tests hiddenField with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testHiddenFieldWithArrayBasic()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
		);
		$expected = '<input type="hidden" id="some_field_name" name="some_field_name" value="" class="some_class">';
		$actual   = \Phalcon\Tag::hiddenField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'hiddenField basic with array')
		);
	}

	/**
	 * Tests hiddenField with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="hidden" id="some_id" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::hiddenField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'hiddenField with id in parameters')
		);
	}

	/**
	 * Tests hiddenField with name and no id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="hidden" id="some_field_name" name="some_other_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::hiddenField($options);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testHiddenFieldSetDefault()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<input type="hidden" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::hiddenField($options);
		\Phalcon\Tag::setDefault('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'hiddenField with setDefault')
		);
	}

	/**
	 * Tests hiddenField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testHiddenFieldDisplayTo()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<input type="hidden" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::hiddenField($options);
		\Phalcon\Tag::displayTo('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'hiddenField with displayTo')
		);
	}

	/**
	 * Tests hiddenField with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testHiddenFieldSetDefaultElementNotPresent()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<input type="hidden" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::hiddenField($options);
		\Phalcon\Tag::setDefault('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'hiddenField with setDefault')
		);
	}

	/**
	 * Tests hiddenField with displayTo to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testHiddenFieldDisplayToElementNotPresent()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<input type="hidden" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::hiddenField($options);
		\Phalcon\Tag::displayTo('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'hiddenField with displayTo')
		);
	}

	/**
	 * Tests hiddenField with string as a parameter
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testHiddenFieldBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'some_field_name';
		$expected = '<input type="hidden" id="some_field_name" name="some_field_name" value="" />';
		$actual   = \Phalcon\Tag::hiddenField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML hiddenField basic')
		);
	}

	/**
	 * Tests hiddenField with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testHiddenFieldWithArrayBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
		);
		$expected = '<input type="hidden" id="some_field_name" name="some_field_name" value="" class="some_class" />';
		$actual   = \Phalcon\Tag::hiddenField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML hiddenField basic with array')
		);
	}

	/**
	 * Tests hiddenField with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testHiddenFieldWithIdInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'id'    => 'some_id',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="hidden" id="some_id" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::hiddenField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML hiddenField with id in parameters')
		);
	}

	/**
	 * Tests hiddenField with name and no id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testHiddenFieldWithNameAndNotIdInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'name'  => 'some_other_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="hidden" id="some_field_name" name="some_other_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::hiddenField($options);
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testHiddenFieldSetDefaultXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<input type="hidden" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::hiddenField($options);
		\Phalcon\Tag::setDefault('some_field_name', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML hiddenField with setDefault')
		);
	}

	/**
	 * Tests hiddenField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testHiddenFieldDisplayToXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<input type="hidden" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::hiddenField($options);
		\Phalcon\Tag::displayTo('some_field_name', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML hiddenField with displayTo')
		);
	}

	/**
	 * Tests hiddenField with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testHiddenFieldSetDefaultElementNotPresentXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<input type="hidden" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::hiddenField($options);
		\Phalcon\Tag::setDefault('some_field', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML hiddenField with setDefault')
		);
	}

	/**
	 * Tests hiddenField with displayTo to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testHiddenFieldDisplayToElementNotPresentXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<input type="hidden" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::hiddenField($options);
		\Phalcon\Tag::displayTo('some_field', '');
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testPasswordFieldBasic()
	{
		$options  = 'some_field_name';
		$expected = '<input type="password" id="some_field_name" name="some_field_name" value="">';
		$actual   = \Phalcon\Tag::passwordField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'passwordField basic')
		);
	}

	/**
	 * Tests passwordField with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testPasswordFieldWithArrayBasic()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
		);
		$expected = '<input type="password" id="some_field_name" name="some_field_name" value="" class="some_class">';
		$actual   = \Phalcon\Tag::passwordField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'passwordField basic with array')
		);
	}

	/**
	 * Tests passwordField with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="password" id="some_id" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::passwordField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'passwordField with id in parameters')
		);
	}

	/**
	 * Tests passwordField with name and not id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="password" id="some_field_name" name="some_other_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::passwordField($options);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testPasswordFieldSetDefault()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<input type="password" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::passwordField($options);
		\Phalcon\Tag::setDefault('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'passwordField with setDefault')
		);
	}

	/**
	 * Tests passwordField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testPasswordFieldDisplayTo()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<input type="password" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::passwordField($options);
		\Phalcon\Tag::displayTo('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'passwordField with displayTo')
		);
	}

	/**
	 * Tests passwordField with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testPasswordFieldSetDefaultElementNotPresent()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<input type="password" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::passwordField($options);
		\Phalcon\Tag::setDefault('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'passwordField with setDefault')
		);
	}

	/**
	 * Tests passwordField with displayTo to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testPasswordFieldDisplayToElementNotPresent()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<input type="password" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::passwordField($options);
		\Phalcon\Tag::displayTo('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'passwordField with displayTo')
		);
	}

	/**
	 * Tests passwordField with string as a parameter
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testPasswordFieldBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'some_field_name';
		$expected = '<input type="password" id="some_field_name" name="some_field_name" value="" />';
		$actual   = \Phalcon\Tag::passwordField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML passwordField basic')
		);
	}

	/**
	 * Tests passwordField with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testPasswordFieldWithArrayBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
		);
		$expected = '<input type="password" id="some_field_name" name="some_field_name" value="" class="some_class" />';
		$actual   = \Phalcon\Tag::passwordField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML passwordField basic with array')
		);
	}

	/**
	 * Tests passwordField with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testPasswordFieldWithIdInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'id'    => 'some_id',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="password" id="some_id" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::passwordField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML passwordField with id in parameters')
		);
	}

	/**
	 * Tests passwordField with name and not id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testPasswordFieldWithNameAndNotIdInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'name'  => 'some_other_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="password" id="some_field_name" name="some_other_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::passwordField($options);
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testPasswordFieldSetDefaultXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<input type="password" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::passwordField($options);
		\Phalcon\Tag::setDefault('some_field_name', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML passwordField with setDefault')
		);
	}

	/**
	 * Tests passwordField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testPasswordFieldDisplayToXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<input type="password" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::passwordField($options);
		\Phalcon\Tag::displayTo('some_field_name', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML passwordField with displayTo')
		);
	}

	/**
	 * Tests passwordField with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testPasswordFieldSetDefaultElementNotPresentXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<input type="password" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::passwordField($options);
		\Phalcon\Tag::setDefault('some_field', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML passwordField with setDefault')
		);
	}

	/**
	 * Tests passwordField with displayTo to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testPasswordFieldDisplayToElementNotPresentXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<input type="password" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::passwordField($options);
		\Phalcon\Tag::displayTo('some_field', '');
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testFileFieldBasic()
	{
		$options  = 'some_field_name';
		$expected = '<input type="file" id="some_field_name" name="some_field_name" value="">';
		$actual   = \Phalcon\Tag::fileField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'fileField basic')
		);
	}

	/**
	 * Tests fileField with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testFileFieldWithArrayBasic()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
		);
		$expected = '<input type="file" id="some_field_name" name="some_field_name" value="" class="some_class">';
		$actual   = \Phalcon\Tag::fileField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'fileField basic with array')
		);
	}

	/**
	 * Tests fileField with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="file" id="some_id" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::fileField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'fileField with id in parameters')
		);
	}

	/**
	 * Tests fileField with name and not id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="file" id="some_field_name" name="some_other_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::fileField($options);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testFileFieldSetDefault()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<input type="file" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::fileField($options);
		\Phalcon\Tag::setDefault('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'fileField with setDefault')
		);
	}

	/**
	 * Tests fileField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testFileFieldDisplayTo()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<input type="file" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::fileField($options);
		\Phalcon\Tag::displayTo('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'fileField with displayTo')
		);
	}

	/**
	 * Tests fileField with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testFileFieldSetDefaultElementNotPresent()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<input type="file" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::fileField($options);
		\Phalcon\Tag::setDefault('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'fileField with setDefault')
		);
	}

	/**
	 * Tests fileField with displayTo to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testFileFieldDisplayToElementNotPresent()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<input type="file" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::fileField($options);
		\Phalcon\Tag::displayTo('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'fileField with displayTo')
		);
	}

	/**
	 * Tests fileField with string as a parameter
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testFileFieldBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'some_field_name';
		$expected = '<input type="file" id="some_field_name" name="some_field_name" value="" />';
		$actual   = \Phalcon\Tag::fileField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML fileField basic')
		);
	}

	/**
	 * Tests fileField with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testFileFieldWithArrayBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
		);
		$expected = '<input type="file" id="some_field_name" name="some_field_name" value="" class="some_class" />';
		$actual   = \Phalcon\Tag::fileField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML fileField basic with array')
		);
	}

	/**
	 * Tests fileField with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testFileFieldWithIdInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'id'    => 'some_id',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="file" id="some_id" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::fileField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML fileField with id in parameters')
		);
	}

	/**
	 * Tests fileField with name and not id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testFileFieldWithNameAndNotIdInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'name'  => 'some_other_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="file" id="some_field_name" name="some_other_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::fileField($options);
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testFileFieldSetDefaultXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<input type="file" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::fileField($options);
		\Phalcon\Tag::setDefault('some_field_name', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML fileField with setDefault')
		);
	}

	/**
	 * Tests fileField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testFileFieldDisplayToXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<input type="file" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::fileField($options);
		\Phalcon\Tag::displayTo('some_field_name', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML fileField with displayTo')
		);
	}

	/**
	 * Tests fileField with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testFileFieldSetDefaultElementNotPresentXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<input type="file" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::fileField($options);
		\Phalcon\Tag::setDefault('some_field', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML fileField with setDefault')
		);
	}

	/**
	 * Tests fileField with displayTo to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testFileFieldDisplayToElementNotPresentXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<input type="file" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::fileField($options);
		\Phalcon\Tag::displayTo('some_field', '');
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testCheckFieldBasic()
	{
		$options  = 'some_field_name';
		$expected = '<input type="checkbox" id="some_field_name" name="some_field_name" value="">';
		$actual   = \Phalcon\Tag::checkField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'checkField basic')
		);
	}

	/**
	 * Tests checkField with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testCheckFieldWithArrayBasic()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
		);
		$expected = '<input type="checkbox" id="some_field_name" name="some_field_name" value="" class="some_class">';
		$actual   = \Phalcon\Tag::checkField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'checkField basic with array')
		);
	}

	/**
	 * Tests checkField with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="checkbox" id="some_id" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::checkField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'checkField with id in parameters')
		);
	}

	/**
	 * Tests checkField with name and not id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="checkbox" id="some_field_name" name="some_other_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::checkField($options);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testCheckFieldSetDefault()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<input type="checkbox" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" checked="checked">';
		$actual   = \Phalcon\Tag::checkField($options);
		\Phalcon\Tag::setDefault('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'checkField with setDefault')
		);
	}

	/**
	 * Tests checkField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testCheckFieldDisplayTo()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<input type="checkbox" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" checked="checked">';
		$actual   = \Phalcon\Tag::checkField($options);
		\Phalcon\Tag::displayTo('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'checkField with displayTo')
		);
	}

	/**
	 * Tests checkField with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testCheckFieldSetDefaultElementNotPresent()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<input type="checkbox" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::checkField($options);
		\Phalcon\Tag::setDefault('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'checkField with setDefault')
		);
	}

	/**
	 * Tests checkField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testCheckFieldDisplayToElementNotPresent()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<input type="checkbox" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::checkField($options);
		\Phalcon\Tag::displayTo('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'checkField with displayTo')
		);
	}

	/**
	 * Tests checkField with string as a parameter
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testCheckFieldBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'some_field_name';
		$expected = '<input type="checkbox" id="some_field_name" name="some_field_name" value="" />';
		$actual   = \Phalcon\Tag::checkField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML checkField basic')
		);
	}

	/**
	 * Tests checkField with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testCheckFieldWithArrayBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
		);
		$expected = '<input type="checkbox" id="some_field_name" name="some_field_name" value="" class="some_class" />';
		$actual   = \Phalcon\Tag::checkField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML checkField basic with array')
		);
	}

	/**
	 * Tests checkField with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testCheckFieldWithIdInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'id'    => 'some_id',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="checkbox" id="some_id" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::checkField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML checkField with id in parameters')
		);
	}

	/**
	 * Tests checkField with name and not id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testCheckFieldWithNameAndNotIdInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'name'  => 'some_other_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="checkbox" id="some_field_name" name="some_other_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::checkField($options);
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testCheckFieldSetDefaultXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<input type="checkbox" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" checked="checked" />';
		$actual   = \Phalcon\Tag::checkField($options);
		\Phalcon\Tag::setDefault('some_field_name', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML checkField with setDefault')
		);
	}

	/**
	 * Tests checkField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testCheckFieldDisplayToXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<input type="checkbox" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" checked="checked" />';
		$actual   = \Phalcon\Tag::checkField($options);
		\Phalcon\Tag::displayTo('some_field_name', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML checkField with displayTo')
		);
	}

	/**
	 * Tests checkField with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testCheckFieldSetDefaultElementNotPresentXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<input type="checkbox" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::checkField($options);
		\Phalcon\Tag::setDefault('some_field', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML checkField with setDefault')
		);
	}

	/**
	 * Tests checkField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testCheckFieldDisplayToElementNotPresentXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<input type="checkbox" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::checkField($options);
		\Phalcon\Tag::displayTo('some_field', '');
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-15
	 */
	public function testRadioFieldBasic()
	{
		$options  = 'some_field_name';
		$expected = '<input type="radio" id="some_field_name" name="some_field_name" value="">';
		$actual   = \Phalcon\Tag::radioField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'radioField basic')
		);
	}

	/**
	 * Tests radioField with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-15
	 */
	public function testRadioFieldWithArrayBasic()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
		);
		$expected = '<input type="radio" id="some_field_name" name="some_field_name" value="" class="some_class">';
		$actual   = \Phalcon\Tag::radioField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'radioField basic with array')
		);
	}

	/**
	 * Tests radioField with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="radio" id="some_id" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::radioField($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'radioField with id in parameters')
		);
	}

	/**
	 * Tests radioField with name and not id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="radio" id="some_field_name" name="some_other_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::radioField($options);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-15
	 */
	public function testRadioFieldSetDefault()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<input type="radio" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" checked="checked">';
		$actual   = \Phalcon\Tag::radioField($options);
		\Phalcon\Tag::setDefault('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'radioField with setDefault')
		);
	}

	/**
	 * Tests radioField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-15
	 */
	public function testRadioFieldDisplayTo()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<input type="radio" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" checked="checked">';
		$actual   = \Phalcon\Tag::radioField($options);
		\Phalcon\Tag::displayTo('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'radioField with displayTo')
		);
	}

	/**
	 * Tests radioField with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-15
	 */
	public function testRadioFieldSetDefaultElementNotPresent()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<input type="radio" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::radioField($options);
		\Phalcon\Tag::setDefault('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'radioField with setDefault')
		);
	}

	/**
	 * Tests radioField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-15
	 */
	public function testRadioFieldDisplayToElementNotPresent()
	{
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<input type="radio" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::radioField($options);
		\Phalcon\Tag::displayTo('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'radioField with displayTo')
		);
	}

	/**
	 * Tests radioField with string as a parameter
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-15
	 */
	public function testRadioFieldBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'some_field_name';
		$expected = '<input type="radio" id="some_field_name" name="some_field_name" value="" />';
		$actual   = \Phalcon\Tag::radioField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML radioField basic')
		);
	}

	/**
	 * Tests radioField with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-15
	 */
	public function testRadioFieldWithArrayBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
		);
		$expected = '<input type="radio" id="some_field_name" name="some_field_name" value="" class="some_class" />';
		$actual   = \Phalcon\Tag::radioField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML radioField basic with array')
		);
	}

	/**
	 * Tests radioField with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-15
	 */
	public function testRadioFieldWithIdInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'id'    => 'some_id',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="radio" id="some_id" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::radioField($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML radioField with id in parameters')
		);
	}

	/**
	 * Tests radioField with name and not id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-15
	 */
	public function testRadioFieldWithNameAndNotIdInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'name'  => 'some_other_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="radio" id="some_field_name" name="some_other_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::radioField($options);
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-15
	 */
	public function testRadioFieldSetDefaultXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<input type="radio" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" checked="checked" />';
		$actual   = \Phalcon\Tag::radioField($options);
		\Phalcon\Tag::setDefault('some_field_name', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML radioField with setDefault')
		);
	}

	/**
	 * Tests radioField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-15
	 */
	public function testRadioFieldDisplayToXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<input type="radio" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" checked="checked" />';
		$actual   = \Phalcon\Tag::radioField($options);
		\Phalcon\Tag::displayTo('some_field_name', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML radioField with displayTo')
		);
	}

	/**
	 * Tests radioField with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-15
	 */
	public function testRadioFieldSetDefaultElementNotPresentXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<input type="radio" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::radioField($options);
		\Phalcon\Tag::setDefault('some_field', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML radioField with setDefault')
		);
	}

	/**
	 * Tests radioField with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-15
	 */
	public function testRadioFieldDisplayToElementNotPresentXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<input type="radio" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::radioField($options);
		\Phalcon\Tag::displayTo('some_field', '');
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testSubmitButtonBasic()
	{
		$options  = 'some_field_name';
		$expected = '<input type="submit" value="some_field_name">';
		$actual   = \Phalcon\Tag::submitButton($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'submitButton basic')
		);
	}

	/**
	 * Tests submitButton with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="submit" value="some_field_name" class="some_class">';
		$actual   = \Phalcon\Tag::submitButton($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'submitButton basic with array')
		);
	}

	/**
	 * Tests submitButton with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="submit" id="some_id" value="some_field_name" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::submitButton($options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'submitButton with id in parameters')
		);
	}

	/**
	 * Tests submitButton with name and not id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<input type="submit" name="some_other_name" value="some_field_name" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::submitButton($options);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<input type="submit" value="some_field_name" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::submitButton($options);
		\Phalcon\Tag::setDefault('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'submitButton with setDefault')
		);
	}

	/**
	 * Tests submitButton with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<input type="submit" value="some_field_name" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::submitButton($options);
		\Phalcon\Tag::displayTo('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'submitButton with displayTo')
		);
	}

	/**
	 * Tests submitButton with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<input type="submit" value="some_field_name" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::submitButton($options);
		\Phalcon\Tag::setDefault('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'submitButton with setDefault')
		);
	}

	/**
	 * Tests submitButton with displayTo to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<input type="submit" value="some_field_name" class="some_class" size="10">';
		$actual   = \Phalcon\Tag::submitButton($options);
		\Phalcon\Tag::displayTo('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'submitButton with displayTo')
		);
	}

	/**
	 * Tests submitButton with string as a parameter
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testSubmitButtonBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options  = 'some_field_name';
		$expected = '<input type="submit" value="some_field_name" />';
		$actual   = \Phalcon\Tag::submitButton($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML submitButton basic')
		);
	}

	/**
	 * Tests submitButton with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 * @todo   Fix the order
	 */
	public function testSubmitButtonWithArrayBasicXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
		);

		$expected = '<input type="submit" value="some_field_name" class="some_class" />';
		$actual   = \Phalcon\Tag::submitButton($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML submitButton basic with array')
		);
	}

	/**
	 * Tests submitButton with id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 * @todo   Fix the order
	 */
	public function testSubmitButtonWithIdInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'id'    => 'some_id',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="submit" id="some_id" value="some_field_name" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::submitButton($options);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML submitButton with id in parameters')
		);
	}

	/**
	 * Tests submitButton with name and not id in parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 * @todo   Fix the order
	 */
	public function testSubmitButtonWithNameAndNotIdInParametersXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'name'  => 'some_other_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		$expected = '<input type="submit" name="some_other_name" value="some_field_name" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::submitButton($options);
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 * @todo   Fix the order
	 */
	public function testSubmitButtonSetDefaultXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
		$expected = '<input type="submit" value="some_field_name" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::submitButton($options);
		\Phalcon\Tag::setDefault('some_field_name', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML submitButton with setDefault')
		);
	}

	/**
	 * Tests submitButton with displayTo
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 * @todo   Fix the order
	 */
	public function testSubmitButtonDisplayToXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
		$expected = '<input type="submit" value="some_field_name" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::submitButton($options);
		\Phalcon\Tag::displayTo('some_field_name', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML submitButton with displayTo')
		);
	}

	/**
	 * Tests submitButton with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 * @todo   Fix the order
	 */
	public function testSubmitButtonSetDefaultElementNotPresentXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'some_default_value');
		$expected = '<input type="submit" value="some_field_name" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::submitButton($options);
		\Phalcon\Tag::setDefault('some_field', '');
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML submitButton with setDefault')
		);
	}

	/**
	 * Tests submitButton with displayTo to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 * @todo   Fix the order
	 */
	public function testSubmitButtonDisplayToElementNotPresentXHTML()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$options = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'some_default_value');
		$expected = '<input type="submit" value="some_field_name" class="some_class" size="10" />';
		$actual   = \Phalcon\Tag::submitButton($options);
		\Phalcon\Tag::displayTo('some_field', '');
		\Phalcon\Tag::setDoctype('');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testSelectStaticStringThrowsException()
	{
		$name    = 'some_field_name';
		$options = 'some_values';

		try {
			$actual   = \Phalcon\Tag::selectStatic($name, $options);
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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testSelectStaticWithArrayBasic()
	{
		$name    = 'some_field_name';
		$options = array(
			'A' => 'Active',
			'I' => 'Inactive',
		);
		$expected = '<select id="some_field_name" name="some_field_name">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($name, $options);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<select id="some_id" name="some_field_name" class="some_class">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($params, $options);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<select id="some_id" name="some_field_name" class="some_class">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($params, $options);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<select id="some_field_name" name="some_field_name" class="some_class">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($params, $options);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testSelectStaticSetDefault()
	{
		$params = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'I');
		$options = array(
			'A' => 'Active',
			'I' => 'Inactive',
		);
		$expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($params, $options);
		\Phalcon\Tag::setDefault('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'selectStatic with setDefault')
		);
	}

	/**
	 * Tests selectStatic with setDefault
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testSelectStaticDisplayTo()
	{
		$params = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'I');
		$options = array(
			'A' => 'Active',
			'I' => 'Inactive',
		);
		$expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($params, $options);
		\Phalcon\Tag::displayTo('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'selectStatic with setDefault')
		);
	}

	/**
	 * Tests selectStatic with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testSelectStaticSetDefaultElementNotPresent()
	{
		$params = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'I');
		$options = array(
			'A' => 'Active',
			'I' => 'Inactive',
		);
		$expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($params, $options);
		\Phalcon\Tag::setDefault('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'selectStatic with setDefault')
		);
	}

	/**
	 * Tests selectStatic with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-11-29
	 */
	public function testSelectStaticDisplayToElementNotPresent()
	{
		$params = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'I');
		$options = array(
			'A' => 'Active',
			'I' => 'Inactive',
		);
		$expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($params, $options);
		\Phalcon\Tag::displayTo('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'selectStatic with setDefault')
		);
	}

	/**
	 * Tests selectStatic with string as a parameter throws exception
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testSelectStaticStringThrowsExceptionXHTML()
	{
		$name    = 'some_field_name';
		$options = 'some_values';

		try {
			$actual   = \Phalcon\Tag::selectStatic($name, $options);
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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testSelectStaticWithArrayBasicXHTML()
	{
		$name    = 'some_field_name';
		$options = array(
			'A' => 'Active',
			'I' => 'Inactive',
		);
		$expected = '<select id="some_field_name" name="some_field_name">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($name, $options);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<select id="some_id" name="some_field_name" class="some_class">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($params, $options);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<select id="some_id" name="some_field_name" class="some_class">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($params, $options);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$expected = '<select id="some_field_name" name="some_field_name" class="some_class">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($params, $options);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testSelectStaticSetDefaultXHTML()
	{
		$params = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field_name', 'I');
		$options = array(
			'A' => 'Active',
			'I' => 'Inactive',
		);
		$expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($params, $options);
		\Phalcon\Tag::setDefault('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML selectStatic with setDefault')
		);
	}

	/**
	 * Tests selectStatic with setDefault
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testSelectStaticDisplayToXHTML()
	{
		$params = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field_name', 'I');
		$options = array(
			'A' => 'Active',
			'I' => 'Inactive',
		);
		$expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($params, $options);
		\Phalcon\Tag::displayTo('some_field_name', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML selectStatic with setDefault')
		);
	}

	/**
	 * Tests selectStatic with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testSelectStaticSetDefaultElementNotPresentXHTML()
	{
		$params = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::setDefault('some_field', 'I');
		$options = array(
			'A' => 'Active',
			'I' => 'Inactive',
		);
		$expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($params, $options);
		\Phalcon\Tag::setDefault('some_field', '');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'XHTML selectStatic with setDefault')
		);
	}

	/**
	 * Tests selectStatic with setDefault to an non existent element
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-10-26
	 */
	public function testSelectStaticDisplayToElementNotPresentXHTML()
	{
		$params = array(
			'some_field_name',
			'class' => 'some_class',
			'size'  => '10',
		);
		\Phalcon\Tag::displayTo('some_field', 'I');
		$options = array(
			'A' => 'Active',
			'I' => 'Inactive',
		);
		$expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
				  . chr(9) . '<option value="A">Active</option>' . PHP_EOL
				  . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
				  . '</select>';
		$actual   = \Phalcon\Tag::selectStatic($params, $options);
		\Phalcon\Tag::displayTo('some_field', '');

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-05
	 */
	public function testSetTitle()
	{
		$value = 'This is my title';

		\Phalcon\Tag::setTitle($value);

		$expected = "<title>{$value}</title>" . PHP_EOL;
		$actual   = \Phalcon\Tag::getTitle();

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'setTitle')
		);
	}

	/**
	 * Tests appendTitle
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-05
	 */
	public function testAppendTitle()
	{
		$value = 'This is my title';

		\Phalcon\Tag::setTitle($value);

		$append = ' - Welcome!';

		\Phalcon\Tag::appendTitle($append);

		$expected = "<title>{$value}{$append}</title>" . PHP_EOL;
		$actual   = \Phalcon\Tag::getTitle();

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'appendTitle')
		);
	}

	/**
	 * Tests prependTitle
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-05
	 */
	public function testPrependTitle()
	{
		$value = 'This is my title';

		\Phalcon\Tag::setTitle($value);

		$prepend = 'PhalconPHP -';

		\Phalcon\Tag::prependTitle($prepend);

		$expected = "<title>{$prepend}{$value}</title>" . PHP_EOL;
		$actual   = \Phalcon\Tag::getTitle();

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-08
	 */
	public function testLinkToWithStringAsURLAndName()
	{
		$url  = 'some_url';
		$name = 'some_name';

		$expected = '<a href="/some_url">some_name</a>';
		$actual   = \Phalcon\Tag::linkTo($url, $name);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'linkTo with strings as parameters')
		);
	}

	/**
	 * Tests linkTo with empty string as URL and string as name parameter
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-08
	 */
	public function testLinkToWithEmptyStringAsURLAndStringAsName()
	{
		$url  = '';
		$name = 'some_name';

		$expected = '<a href="/">some_name</a>';
		$actual   = \Phalcon\Tag::linkTo($url, $name);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'linkTo with empty URL and string as name')
		);
	}

	/**
	 * Tests linkTo with array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-08
	 */
	public function testLinkToWithArrayBasic()
	{
		$params = array(
			'some_url',
			'some_name',
		);
		$expected = '<a href="/some_url">some_name</a>';
		$actual   = \Phalcon\Tag::linkTo($params);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'linkTo with array as parameters')
		);
	}

	/**
	 * Tests linkTo with named array as parameters
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2012-09-08
	 */
	public function testLinkToWithArrayNamedBasic()
	{
		$params = array(
			'action' => 'some_url',
			'text'   => 'some_name',
		);
		$expected = '<a href="/some_url">some_name</a>';
		$actual   = \Phalcon\Tag::linkTo($params);

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
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
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
		$actual   = \Phalcon\Tag::linkTo($params);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf(
				$this->message,
				'linkTo with named array as parameters (full params)'
			)
		);
	}


	/**
	 * Tests the tagHtml with name parameter
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2013-04-04
	 */
	public function testTagHtmlName()
	{
		$name     = 'aside';
		$expected = '<aside></aside>';
		$actual   = \Phalcon\Tag::tagHtml($name);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'tagHtml bare')
		);
	}

	/**
	 * Tests the tagHtml with name parameter and self close
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2013-04-04
	 */
	public function testTagHtmlNameSelfClose()
	{
		$name     = 'img';
		$expected = '<img></img>';
		$actual   = \Phalcon\Tag::tagHtml($name, null, true);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'tagHtml bare')
		);
	}

	/**
	 * Tests the tagHtml with name parameter and self close
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2013-04-04
	 */
	public function testTagHtmlNameSelfCloseXhtml()
	{
		\Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
		$name     = 'img';
		$expected = '<img />';
		$actual   = \Phalcon\Tag::tagHtml($name, null, true);
		\Phalcon\Tag::setDoctype('');

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'tagHtml bare')
		);
	}

	/**
	 * Tests the tagHtml with name parameter and only start
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2013-04-04
	 */
	public function testTagHtmlNameOnlyStart()
	{
		$name     = 'aside';
		$expected = '<aside>';
		$actual   = \Phalcon\Tag::tagHtml($name, null, null, true);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'tagHtml bare')
		);
	}

	/**
	 * Tests the tagHtml with name parameter
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2013-04-04
	 */
	public function testTagHtmlNameEol()
	{
		$name     = 'aside';
		$expected = '<aside></aside>' . PHP_EOL;
		$actual   = \Phalcon\Tag::tagHtml($name, null, null, null, true);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'tagHtml bare')
		);
	}

	/**
	 * Tests the tagHtml with name parameter
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2013-04-22
	 */
	public function testTagHtmlWithArray()
	{
		$name     = 'canvas';
		$options  = array(
			'id'     => 'canvas1',
			'width'  => 300,
			'height' => 300,
			'value'  => '123',
		);

		$expected = '<canvas id="canvas1" value="123" width="300" height="300"></canvas>';
		$actual   = \Phalcon\Tag::tagHtml($name, $options);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'tagHtml with options array')
		);
	}

	/**
	 * Tests the tagHtmlClose
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2013-04-22
	 */
	public function testTagHtmlClose()
	{
		$name     = 'canvas';

		$expected = '</canvas>';
		$actual   = \Phalcon\Tag::tagHtmlClose($name);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'tagHtml with options array')
		);
	}

	/**
	 * Tests the tagHtmlClose with EOL
	 *
	 * @author Nikos Dimopoulos <nikos@phalconphp.com>
	 * @since  2013-04-22
	 */
	public function testTagHtmlCloseEol()
	{
		$name     = 'canvas';

		$expected = '</canvas>' . PHP_EOL;
		$actual   = \Phalcon\Tag::tagHtmlClose($name, true);

		$this->assertEquals(
			$expected,
			$actual,
			sprintf($this->message, 'tagHtml with options array')
		);
	}

}
