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

	public function __construct()
	{
		spl_autoload_register(array($this, 'internalAutoloader'));
	}

	public function __destruct()
	{
		spl_autoload_unregister(array($this, 'internalAutoloader'));
	}

	public function internalAutoloader($className)
	{
		if (file_exists('unit-tests/models/'.$className.'.php')) {
			require 'unit-tests/models/'.$className.'.php';
		}
	}

	protected function _loadDI()
	{
		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('url', function(){
			$url = new Phalcon\Mvc\Url();
			$url->setBaseUri('/');
			return $url;
		});

		$di->set('dispatcher', function(){
			$dispatcher = new Phalcon\Mvc\Dispatcher();
			$dispatcher->setControllerName('test2');
			$dispatcher->setActionName('other');
			$dispatcher->setParams(array());
			return $dispatcher;
		});

		$di->set('modelsManager', function(){
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		});

		return $di;

	}

	public function testDoctype()
	{

		$this->_loadDI();

		Tag::setDoctype(Tag::HTML401_STRICT);
		$this->assertEquals(Tag::getDoctype(), '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN"' . PHP_EOL . "\t" . '"http://www.w3.org/TR/html4/strict.dtd">' . PHP_EOL);

	}

	public function testTags()
	{

		$this->_loadDI();

		Tag::displayTo('hello', 'lol');

		Tag::setDoctype(Tag::XHTML10_STRICT);

		//textFields
		$this->assertEquals(Tag::textField('hello'), '<input type="text" name="hello" id="hello" value="lol" />');
		$this->assertEquals(Tag::textField(array('hello')), '<input type="text" name="hello" id="hello" value="lol" />');

		$params = array('id' => 'hello');
		$this->assertEquals(Tag::textField($params), '<input type="text" id="hello" name="hello" value="lol" />');

		$params = array('id' => 'hello', 'value' => 'miami');
		$this->assertEquals(Tag::textField($params), '<input type="text" id="hello" value="miami" name="hello" />');

		$params = array('hellou', 'name' => 'hello', 'value' => 'miami');
		$this->assertEquals(Tag::textField($params), '<input type="text" name="hello" value="miami" id="hellou" />');

		//passwordField
		$this->assertEquals(Tag::passwordField('hello'), '<input type="password" name="hello" id="hello" value="lol" />');
		$this->assertEquals(Tag::passwordField(array('hello')), '<input type="password" name="hello" id="hello" value="lol" />');

		//hiddenField
		$this->assertEquals(Tag::hiddenField('hello'), '<input type="hidden" name="hello" id="hello" value="lol" />');
		$this->assertEquals(Tag::hiddenField(array('hello')), '<input type="hidden" name="hello" id="hello" value="lol" />');

		//fileField
		$this->assertEquals(Tag::fileField('hello'), '<input type="file" name="hello" id="hello" value="lol" />');
		$this->assertEquals(Tag::fileField(array('hello')), '<input type="file" name="hello" id="hello" value="lol" />');

		//checkField
		$this->assertEquals(Tag::checkField('hello'), '<input type="checkbox" name="hello" id="hello" value="lol" checked="checked" />');
		$this->assertEquals(Tag::checkField(array('hello')), '<input type="checkbox" name="hello" id="hello" value="lol" checked="checked" />');
		$this->assertEquals(Tag::checkField(array('hello', 'value' => 0)), '<input type="checkbox" value="0" name="hello" id="hello" />');
		$this->assertEquals(Tag::checkField(array('hello', 'value' => 1)), '<input type="checkbox" value="1" name="hello" id="hello" />');

		//radioField
		$this->assertEquals(Tag::radioField('hello'), '<input type="radio" name="hello" id="hello" value="lol" />');
		$this->assertEquals(Tag::radioField(array('hello')), '<input type="radio" name="hello" id="hello" value="lol" />');

		//Links
		$this->assertEquals(Tag::linkTo('', 'home'), '<a href="/">home</a>');
		$this->assertEquals(Tag::linkTo('index', 'home'), '<a href="/index">home</a>');

		$params = array('index', 'home');
		$this->assertEquals(Tag::linkTo($params), '<a href="/index">home</a>');

		$params = array('action' => 'index', 'text' => 'home');
		$this->assertEquals(Tag::linkTo($params), '<a href="/index">home</a>');

		$params = array('action' => 'index', 'text' => 'home', 'class' => 'btn btn-primary');
		$this->assertEquals(Tag::linkTo($params), '<a href="/index" class="btn btn-primary">home</a>');

		//Submits
		$this->assertEquals(Tag::submitButton('lol'), '<input type="submit" value="lol" />');
		$this->assertEquals(Tag::submitButton(array('lol')), '<input type="submit" value="lol" />');

		//Select Static
		$values = array(
			'A' => 'Action',
			'T' => 'Tonight',
			'C' => 'Crystal'
		);
		$this->assertEquals(Tag::selectStatic('horror', $values), '<select name="horror" id="horror">
	<option value="A">Action</option>
	<option value="T">Tonight</option>
	<option value="C">Crystal</option>
</select>');

		$params = array('horror', $values, 'value' => 'C');
		$this->assertEquals(Tag::selectStatic($params), '<select name="horror" id="horror">
	<option value="A">Action</option>
	<option value="T">Tonight</option>
	<option selected="selected" value="C">Crystal</option>
</select>');

		$params = array('horror', $values, 'value' => 'C', 'useEmpty' => true);
		$this->assertEquals(Tag::selectStatic($params), '<select name="horror" id="horror">
	<option value="">Choose...</option>
	<option value="A">Action</option>
	<option value="T">Tonight</option>
	<option selected="selected" value="C">Crystal</option>
</select>');

		$params = array('horror', $values, 'value' => 'C', 'useEmpty' => true, 'emptyValue' => '@', 'emptyText' => 'Seleccione...');
		$this->assertEquals(Tag::selectStatic($params), '<select name="horror" id="horror">
	<option value="@">Seleccione...</option>
	<option value="A">Action</option>
	<option value="T">Tonight</option>
	<option selected="selected" value="C">Crystal</option>
</select>');

	}

	public function testSelect()
	{

		$this->_loadDI();

		$robots = Robots::find();

		$params = array('nice', $robots, 'using' => array('id', 'name'));
		$this->assertEquals(Tag::select($params), '<select name="nice" id="nice">
	<option value="1">Robotina</option>
	<option value="2">Astro Boy</option>
	<option value="3">Terminator</option>
</select>');

		$params = array('nice', $robots, 'using' => array('id', 'name'), 'value' => '2');
		$this->assertEquals(Tag::select($params), '<select name="nice" id="nice">
	<option value="1">Robotina</option>
	<option selected="selected" value="2">Astro Boy</option>
	<option value="3">Terminator</option>
</select>');


	}

	public function testForm()
	{

		$this->_loadDI();

		$this->assertEquals(Tag::form('controller/index'), '<form action="/controller/index/" method="post">');

		$params = array('controller/index', 'method' => 'get');
		$this->assertEquals(Tag::form($params), '<form action="/controller/index/" method="get">');
	}

	public function testStaticLinksRel()
	{

		$this->_loadDI();

		//Images
		$this->assertEquals(Tag::image("img/hello.gif"), '<img src="/img/hello.gif" />');
		$this->assertEquals(Tag::image(array("img/hello.gif", "alt" => "hello image")), '<img alt="hello image" src="/img/hello.gif" />');

		//CSS stylesheetlinks
		$this->assertEquals(Tag::stylesheetLink("http://fonts.googleapis.com/css?family=Rosario", false), '<link rel="stylesheet" href="http://fonts.googleapis.com/css?family=Rosario" type="text/css" />');
		$this->assertEquals(Tag::stylesheetLink("css/style.css"), '<link rel="stylesheet" href="/css/style.css" type="text/css" />');

		//Javascript includes
		$this->assertEquals(Tag::javascriptInclude('javascript/jquery.min.js'), '<script src="/javascript/jquery.min.js" type="text/javascript"></script>');
		$this->assertEquals(Tag::javascriptInclude('http://localhost/javascript/jquery.min.js', false), '<script src="http://localhost/javascript/jquery.min.js" type="text/javascript"></script>');

	}

	public function testTitle()
	{

		$this->_loadDI();

		Tag::setTitle('A title');
		$this->assertEquals(Tag::getTitle(), '<title>A title</title>'.PHP_EOL);

		Tag::appendTitle(' - Append title');
		$this->assertEquals(Tag::getTitle(), '<title>A title - Append title</title>'.PHP_EOL);

		Tag::prependTitle('Prepend title - ');
		$this->assertEquals(Tag::getTitle(), '<title>Prepend title - A title - Append title</title>'.PHP_EOL);

	}

	public function testResetInput()
	{
		$this->_loadDI();

		$options  = 'some_field_name';

		$expectedWithValue = '<input type="text" name="some_field_name" id="some_field_name" value="Wall-E" />';
		$expectedWithoutValue = '<input type="text" name="some_field_name" id="some_field_name" value="" />';

		//With setDefault
		Tag::setDefault('some_field_name', 'Wall-E');
		$actual = Tag::textField($options);
		$this->assertEquals($expectedWithValue, $actual);

		//Reset input
		Tag::resetInput();

		$actual = Tag::textField($options);
		$this->assertEquals($expectedWithoutValue, $actual);


		$_POST['some_field_name'] = 'Wall-E';
		$actual = Tag::textField($options);
		$this->assertEquals($expectedWithValue, $actual);

		//Reset input
		Tag::resetInput();

		$actual = Tag::textField($options);
		$this->assertEquals($expectedWithoutValue, $actual);

	}

	public function testTextarea()
	{

		$options = 'some_field_name';
        $expected = '<textarea name="some_field_name" id="some_field_name"></textarea>';
        $actual = Tag::textArea($options);
        $this->assertEquals($expected, $actual);

        $options = array('some_field_name', 'class' => 'some_class');
        $expected = '<textarea class="some_class" name="some_field_name" '
                  . 'id="some_field_name"></textarea>';
        $actual = Tag::textArea($options);

        $this->assertEquals($expected, $actual);
	}

}
