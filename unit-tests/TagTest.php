<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

use Phalcon\Tag as Tag;

class TagTest extends PHPUnit_Framework_TestCase
{

	public function testSelect()
	{
		$data = array(
			"status",
			array("Active" => array('A1' => 'A One', 'A2' => 'A Two'), "B" => "B One")
		);

		$html = <<<HTML
<select id="status" name="status">
	<optgroup label="Active">
	<option value="A1">A One</option>
	<option value="A2">A Two</option>
	</optgroup>
	<option value="B">B One</option>
</select>
HTML;

		$di = new Phalcon\DI\FactoryDefault();
		Tag::setDI($di);
		$ret = Tag::selectStatic($data);

		$this->assertEquals($ret, $html);

		$html = <<<HTML
<select id="status" name="status">
	<optgroup label="Active">
	<option selected="selected" value="A1">A One</option>
	<option value="A2">A Two</option>
	</optgroup>
	<option value="B">B One</option>
</select>
HTML;
		Tag::setDefault("status", "A1");

		$ret = Tag::selectStatic($data);

		$this->assertEquals($ret, $html);
	}

	/**
	 * @see 2402 issue
	 * @link https://github.com/phalcon/cphalcon/issues/2402
	 * @throws Exception
	 */
	public function testDisplayValues()
	{
		Tag::setDefault('property1', 'testVal1');
		Tag::setDefault('property2', 'testVal2');
		Tag::setDefault('property3', 'testVal3');

		$this->assertTrue(Tag::hasValue('property1'));
		$this->assertTrue(Tag::hasValue('property2'));
		$this->assertTrue(Tag::hasValue('property3'));

		$this->assertEquals('testVal1', Tag::getValue('property1'));
		$this->assertEquals('testVal2', Tag::getValue('property2'));
		$this->assertEquals('testVal3', Tag::getValue('property3'));
	}

	public function testSetTitleSeparator()
	{

		Tag::setTitle('Title');
		Tag::appendTitle('Class');

		$this->assertEquals(Tag::getTitle(), '<title>TitleClass</title>'.PHP_EOL);

		Tag::setTitle('Title');
		Tag::setTitleSeparator('|');
		Tag::appendTitle('Class');

		$this->assertEquals(Tag::getTitle(), '<title>Title|Class</title>'.PHP_EOL);
		$this->assertEquals(Tag::getTitleSeparator(), '|');

		Tag::setTitle('Title');
		Tag::setTitleSeparator('|');
		Tag::prependTitle('Class');

		$this->assertEquals(Tag::getTitle(), '<title>Class|Title</title>'.PHP_EOL);
	}

	public function testIssue1486()
    {
		$di = new Phalcon\DI\FactoryDefault();
		$di->getshared('url')->setBaseUri('/');
		\Phalcon\Tag::setDI($di);

		$html = \Phalcon\Tag::stylesheetLink('css/phalcon.css');
		$this->assertEquals($html, '<link rel="stylesheet" type="text/css" href="/css/phalcon.css" />'.PHP_EOL);

		$html = \Phalcon\Tag::stylesheetLink(array('css/phalcon.css'));
		$this->assertEquals($html, '<link rel="stylesheet" type="text/css" href="/css/phalcon.css" />'.PHP_EOL);

		$html = \Phalcon\Tag::javascriptInclude('js/phalcon.js');
		$this->assertEquals($html, '<script type="text/javascript" src="/js/phalcon.js"></script>'.PHP_EOL);

		$html = \Phalcon\Tag::javascriptInclude(array('js/phalcon.js'));
		$this->assertEquals($html, '<script type="text/javascript" src="/js/phalcon.js"></script>'.PHP_EOL);
	 }

	public function testIssue1679()
    {
		$di = new Phalcon\DI\FactoryDefault();
		$di->getshared('url')->setBaseUri('/');
		\Phalcon\Tag::setDI($di);

		// local
		$html = Phalcon\Tag::linkTo('signup/register', 'Register Here!');
		$this->assertEquals($html, '<a href="/signup/register">Register Here!</a>');

		$html = Phalcon\Tag::linkTo(array('signup/register', 'Register Here!'));
		$this->assertEquals($html, '<a href="/signup/register">Register Here!</a>');

		$html = Phalcon\Tag::linkTo(array('signup/register', 'Register Here!', 'class' => 'btn-primary'));
		$this->assertEquals($html, '<a href="/signup/register" class="btn-primary">Register Here!</a>');

		// remote
		$html = Phalcon\Tag::linkTo('http://phalconphp.com/en/', 'Phalcon Home', FALSE);
		$this->assertEquals($html, '<a href="http://phalconphp.com/en/">Phalcon Home</a>');

		$html = Phalcon\Tag::linkTo(array('http://phalconphp.com/en/', 'Phalcon Home', FALSE));
		$this->assertEquals($html, '<a href="http://phalconphp.com/en/">Phalcon Home</a>');

		$html = Phalcon\Tag::linkTo(array('http://phalconphp.com/en/', 'text' => 'Phalcon Home', 'local' => FALSE));
		$this->assertEquals($html, '<a href="http://phalconphp.com/en/">Phalcon Home</a>');

		$html = Phalcon\Tag::linkTo('mailto:dreamsxin@gmail.com', 'dreamsxin@gmail.com', FALSE);
		$this->assertEquals($html, '<a href="mailto:dreamsxin@gmail.com">dreamsxin@gmail.com</a>');
	 }

	public function testIssue2142()
	{
		$di = new Phalcon\DI\FactoryDefault();
		$di->getshared('url')->setBaseUri('/');
		\Phalcon\Tag::setDI($di);

		$html = \Phalcon\Tag::stylesheetLink(array('css/phalcon.css', 'rel' => 'stylesheet/less'));
		$this->assertEquals($html, '<link rel="stylesheet/less" type="text/css" href="/css/phalcon.css" />'.PHP_EOL);
	}

	public function testIssue2002()
	{
		$di = new Phalcon\DI\FactoryDefault();
		$di->getshared('url')->setBaseUri('/');
		\Phalcon\Tag::setDI($di);

		$html = Phalcon\Tag::linkTo(array('signup/register', 'Register Here!', 'class' => 'btn-primary', 'query' => array('from' => 'github', 'token' => '123456')));
		$this->assertEquals($html, '<a href="/signup/register?from=github&amp;token=123456" class="btn-primary">Register Here!</a>');
	}
}
