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

class TagTest extends PHPUnit_Framework_TestCase {

	public function setUp(){
		$front = Phalcon\Controller\Front::getInstance();
		$front->setBaseUri('/');
	}

	public function testTags(){		

		Tag::displayTo('hello', 'lol');

		//textFields
		$this->assertEquals(Tag::textField('hello'), '<input type="text" id="hello" value="lol" name="hello"  />');
		$this->assertEquals(Tag::textField(array('hello')), '<input type="text" id="hello" value="lol" name="hello"  />');

		$params = array('id' => 'hello');
		$this->assertEquals(Tag::textField($params), '<input type="text" id="hello" value="lol" id="hello" name="hello"  />');

		$params = array('id' => 'hello', 'value' => 'miami');
		$this->assertEquals(Tag::textField($params), '<input type="text" id="hello" value="miami" id="hello" name="hello"  />');

		$params = array('hellou', 'name' => 'hello', 'value' => 'miami');
		$this->assertEquals(Tag::textField($params), '<input type="text" id="hellou" value="miami" name="hello"  />');

		//passwordField
		$this->assertEquals(Tag::passwordField('hello'), '<input type="password" id="hello" value="lol" name="hello"  />');
		$this->assertEquals(Tag::passwordField(array('hello')), '<input type="password" id="hello" value="lol" name="hello"  />');

		//hiddenField
		$this->assertEquals(Tag::hiddenField('hello'), '<input type="hidden" id="hello" value="lol" name="hello"  />');
		$this->assertEquals(Tag::hiddenField(array('hello')), '<input type="hidden" id="hello" value="lol" name="hello"  />');

		//fileField
		$this->assertEquals(Tag::fileField('hello'), '<input type="file" id="hello" value="lol" name="hello"  />');
		$this->assertEquals(Tag::fileField(array('hello')), '<input type="file" id="hello" value="lol" name="hello"  />');

		//checkField
		$this->assertEquals(Tag::checkField('hello'), '<input type="checkbox" id="hello" value="lol" name="hello"  />');
		$this->assertEquals(Tag::checkField(array('hello')), '<input type="checkbox" id="hello" value="lol" name="hello"  />');

		//Links
		$this->assertEquals(Tag::linkTo('', 'home'), '<a href="/" >home</a>');
		$this->assertEquals(Tag::linkTo('index', 'home'), '<a href="/index" >home</a>');

		$params = array('index', 'home');
		$this->assertEquals(Tag::linkTo($params), '<a href="/index" >home</a>');

		$params = array('action' => 'index', 'text' => 'home');
		$this->assertEquals(Tag::linkTo($params), '<a href="/index" >home</a>');

		$params = array('action' => 'index', 'text' => 'home', 'class' => 'btn btn-primary');
		$this->assertEquals(Tag::linkTo($params), '<a href="/index"  class="btn btn-primary" >home</a>');

		$params = array('action' => 'index', 'text' => 'home', 'confirm' => 'more lol?');
		$this->assertEquals(Tag::linkTo($params), '<a href="/index"  onclick="if(!confirm(\'more lol?\')) { return false; }; " >home</a>');

		$params = array('action' => 'index', 'text' => 'home', 'confirm' => 'more lol?', 'onclick' => 'yeah()');
		$this->assertEquals(Tag::linkTo($params), '<a href="/index"  onclick="if(!confirm(\'more lol?\')) { return false; }; yeah()" >home</a>');

		//Submits
		$this->assertEquals(Tag::submitButton('lol'), '<input type="submit" value="lol"  />');
		$this->assertEquals(Tag::submitButton(array('lol')), '<input type="submit" value="lol"  />');

		//Select Static
		$values = array(
			'A' => 'Action',
			'T' => 'Tonight',
			'C' => 'Crystal'
		);
		$this->assertEquals(Tag::selectStatic('horror', $values), '<select id="horror" name="horror">
	<option value="A">Action</option>
	<option value="T">Tonight</option>
	<option value="C">Crystal</option>
</select>');

		$params = array('horror', $values, 'value' => 'C');
		$this->assertEquals(Tag::selectStatic($params), '<select id="horror" name="horror">
	<option value="A">Action</option>
	<option value="T">Tonight</option>
	<option selected="selected" value="C">Crystal</option>
</select>');

		$params = array('horror', $values, 'value' => 'C', 'dummyText' => 'more');
		$this->assertEquals(Tag::selectStatic($params), '<select id="horror" name="horror">
	<option value="A">Action</option>
	<option value="T">Tonight</option>
	<option selected="selected" value="C">Crystal</option>
</select>');

		$params = array('horror', $values, 'value' => 'C', 'useDummy' => true);
		$this->assertEquals(Tag::selectStatic($params), '<select id="horror" name="horror" useDummy="1">
	<option value="">Choose...</option>
	<option value="A">Action</option>
	<option value="T">Tonight</option>
	<option selected="selected" value="C">Crystal</option>
</select>');

	}

	public function testSelect(){

		Phalcon\Db\Pool::reset();
		Phalcon\Model\Manager::reset();

		require 'unit-tests/config.db.php';

		Phalcon\Db\Pool::setDefaultDescriptor($configMysql);
		$this->assertTrue(Phalcon\Db\Pool::hasDefaultDescriptor());

		$modelManager = new Phalcon\Model\Manager();
		$modelManager->setModelsDir('unit-tests/models/');

		$robots = Robots::find();

		$params = array('nice', $robots, 'using' => array('id', 'name'));
		$this->assertEquals(Tag::select($params), '<select id="nice" name="nice">
	<option value="1">Robotina</option>
	<option value="2">Astro Boy</option>
	<option value="3">Terminator</option>
</select>');

		$params = array('nice', $robots, 'using' => array('id', 'name'), 'value' => '2');
		$this->assertEquals(Tag::select($params), '<select id="nice" name="nice">
	<option value="1">Robotina</option>
	<option selected="selected" value="2">Astro Boy</option>
	<option value="3">Terminator</option>
</select>');


	}

	public function testForm(){

		//Dispatcher
		$dispatcher = new Phalcon\Dispatcher();

		$request = Phalcon\Request::getInstance();
		$this->assertInstanceOf('Phalcon\Request', $request);

		$response = Phalcon\Response::getInstance();
		$this->assertInstanceOf('Phalcon\Response', $response);

		$basePath = './';
		$dispatcher->setBasePath($basePath);
		$this->assertEquals($dispatcher->getBasePath(), $basePath);

		$controllersDir = 'unit-tests/controllers/';
		$dispatcher->setControllersDir($controllersDir);
		$this->assertEquals($dispatcher->getControllersDir(), $controllersDir);

		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('other');
		$dispatcher->setParams(array());

		$dispatcher->dispatch($request, $response);

		Tag::setDispatcher($dispatcher);

		$this->assertEquals(Tag::form('controller/index'), '<form action="/controller/index/" method= "post" >');

		$params = array('controller/index', 'method' => 'get');
		$this->assertEquals(Tag::form($params), '<form action="/controller/index/" method= "get" >');
	}

	public function testStaticLinksRel(){

		//Images
		$this->assertEquals(Tag::image("img/hello.gif"), '<img src="/img/hello.gif">'.PHP_EOL);
		$this->assertEquals(Tag::image(array("img/hello.gif", "alt" => "hello image")), '<img alt="hello image" src="/img/hello.gif">'.PHP_EOL);

		//CSS stylesheetlinks
		$this->assertEquals(Tag::stylesheetLink("http://fonts.googleapis.com/css?family=Rosario", false), '<link rel="stylesheet" href="http://fonts.googleapis.com/css?family=Rosario" type="text/css">'.PHP_EOL);
		$this->assertEquals(Tag::stylesheetLink("css/style.css"), '<link rel="stylesheet" href="/css/style.css" type="text/css">'.PHP_EOL);

		//Javascript includes
		$this->assertEquals(Tag::javascriptInclude('javascript/jquery.min.js'), '<script src="/javascript/jquery.min.js"  type="text/javascript" ></script>'.PHP_EOL);
		$this->assertEquals(Tag::javascriptInclude('http://localhost/javascript/jquery.min.js', false), '<script src="http://localhost/javascript/jquery.min.js"  type="text/javascript" ></script>'.PHP_EOL);

	}

	public function testTitle(){

		Tag::setTitle('A title');
		$this->assertEquals(Tag::getTitle(), '<title>A title</title>'.PHP_EOL);

		Tag::appendTitle(' - Append title');
		$this->assertEquals(Tag::getTitle(), '<title>A title - Append title</title>'.PHP_EOL);

		Tag::prependTitle('Prepend title - ');
		$this->assertEquals(Tag::getTitle(), '<title>Prepend title - A title - Append title</title>'.PHP_EOL);

	}

}
