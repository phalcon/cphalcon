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

use Phalcon\Tag;

class DIDescendant extends Phalcon\DI {}

class TagTest extends PHPUnit_Framework_TestCase
{

	public function setUp()
	{
	}

	public function testIssue744()
	{
		$v = new Phalcon\Tag;

		try {
			$v->setDI(0);
			$this->assertTrue(false);
		}
		catch (Exception $e) {
			$this->assertTrue(true);
		}

		try {
			$v->setDI(new stdClass());
			$this->assertTrue(false);
		}
		catch (Exception $e) {
			$this->assertTrue(true);
		}

		try {
			$v->setDI(new Phalcon\DI());
			$this->assertTrue(true);
		}
		catch (Exception $e) {
			$this->assertTrue(false);
		}

		try {
			$v->setDI(new DIDescendant());
			$this->assertTrue(true);
		}
		catch (Exception $e) {
			$this->assertTrue(false);
		}

		try {
			$v->setDefaults(0);
			$this->assertTrue(false);
		}
		catch (Exception $e) {
			$this->assertTrue(true);
		}
	}

	public function testIssue947()
        {
		$di = new Phalcon\DI\FactoryDefault();
		Tag::setDI($di);

		$html = Tag::radioField(array(
		    'test',
		    'value' => 1,
		    'checked' => 'checked'
		));
		$pos = strpos($html, 'checked="checked"');
		$this->assertTrue($pos !== FALSE);

		$html = Tag::radioField(array(
		    'test',
		    'value' => 0
		));
		$pos = strpos($html, 'checked="checked"');
		$this->assertTrue($pos === FALSE);

		Tag::setDefault("test", "0");
		$html = Tag::radioField(array(
		    'test',
		    'value' => 0
		));
		$pos = strpos($html, 'checked="checked"');
		$this->assertTrue($pos !== FALSE);
	}

	public function testIssue1216()
	{
		$di = new \Phalcon\DI\FactoryDefault();

		$actual   = \Phalcon\Tag::linkTo(array('url"', '<>', 'class' => 'class"'));
		$expected = '<a class="class&quot;" href="/url&quot;"><></a>';
		$this->assertEquals($expected, $actual);

		$actual   = \Phalcon\Tag::textField(array('name"'));
		$expected = '<input name="name&quot;" id="name&quot;" value="" type="text" />';
		$this->assertEquals($expected, $actual);

		$actual   = \Phalcon\Tag::checkField(array('name"'));
		$expected = '<input name="name&quot;" id="name&quot;" value="" type="checkbox" />';
		$this->assertEquals($expected, $actual);

		$actual   = \Phalcon\Tag::form(array('<', 'method' => '>'));
		$expected = '<form method="&gt;" action="/&lt;">';
		$this->assertEquals($expected, $actual);

		$actual   = \Phalcon\Tag::textArea(array('<', 'cols' => '<'));
		$expected = '<textarea cols="&lt;" name="&lt;" id="&lt;"></textarea>';
		$this->assertEquals($expected, $actual);

		$actual   = \Phalcon\Tag::stylesheetLink(array('href' => '<', 'local' => false, 'type' => '>'));
		$expected = '<link rel="stylesheet" href="&lt;" type="&gt;" />' . PHP_EOL;
		$this->assertEquals($expected, $actual);

		$actual   = \Phalcon\Tag::javascriptInclude(array('src' => '<', 'local' => false, 'type' => '>'));
		$expected = '<script src="&lt;" type="&gt;"></script>' . PHP_EOL;
		$this->assertEquals($expected, $actual);

		$actual   = \Phalcon\Tag::image(array('src' => '<', 'alt' => '>'), false);
		$expected = '<img src="&lt;" alt="&gt;" />';
		$this->assertEquals($expected, $actual);

		$actual   = \Phalcon\Tag::tagHtml('br', array('class' => '<'), true, false, false);
		$expected = '<br class="&lt;" />';
		$this->assertEquals($expected, $actual);

		$actual   = \Phalcon\Tag\Select::selectField(array('name' => '<', 'value' => '>', 'id' => ''), array('"' => '"', '>' => 'test'));
		$expected = '<select name="&lt;" id="">' . PHP_EOL . "\t" . '<option value="&quot;">"</option>' . PHP_EOL . "\t" . '<option selected="selected" value="&gt;">test</option>' . PHP_EOL . '</select>';
		$this->assertEquals($expected, $actual);
	}
}
