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
		$this->assertEquals($html, '<link rel="stylesheet" href="/css/phalcon.css" type="text/css" />'.PHP_EOL);

		$html = \Phalcon\Tag::stylesheetLink(array('css/phalcon.css'));
		$this->assertEquals($html, '<link rel="stylesheet" href="/css/phalcon.css" type="text/css" />'.PHP_EOL);

		$html = \Phalcon\Tag::javascriptInclude('js/phalcon.js');
		$this->assertEquals($html, '<script src="/js/phalcon.js" type="text/javascript"></script>'.PHP_EOL);

		$html = \Phalcon\Tag::javascriptInclude(array('js/phalcon.js'));
		$this->assertEquals($html, '<script src="/js/phalcon.js" type="text/javascript"></script>'.PHP_EOL);
	 }
}
