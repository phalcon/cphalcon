<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2016 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file LICENSE.txt.                             |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Forms\Element\Password;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Forms\Form;
use Phalcon\Mvc\View;
use Phalcon\Escaper;
use Phalcon\Mvc\Url;
use Phalcon\Tag;
use Phalcon\Di;

class SomeObject implements Iterator, Countable
{
	private $_data = array();

	private $_pointer = 0;

	public function __construct($data)
	{
		$this->_data = $data;
	}

	public function count()
	{
		return count($this->_data);
	}

	public function current()
	{
		return $this->_data[$this->_pointer];
	}

	public function key()
	{
		return $this->_pointer;
	}

	public function next()
	{
		++$this->_pointer;
	}

	public function rewind()
	{
		$this->_pointer = 0;
	}

	public function valid()
	{
		return $this->_pointer < count($this->_data);
	}
}

function phalcon_prepare_virtual_path($path, $separator) {
	$virtual_str = '';

	if (!is_string($path) || !is_string($separator)) {
		if (is_string($path)) {
			return $path;
		} else {
			return "";
		}
	}

	for ($i = 0; $i < strlen($path); $i++) {
		$ch = $path[$i];
		if ($ch == '\0') {
			break;
		}
		if ($ch == '/' || $ch == '\\' || $ch == ':') {
			$virtual_str .= $separator;
		} else {
			$virtual_str .= strtolower($ch);
		}
	}

	return $virtual_str;
}

class ViewEnginesVoltTest extends PHPUnit_Framework_TestCase
{
	public function testVoltCompileFileExtends()
	{
		@unlink('unit-tests/views/test10/children.volt.php');
		@unlink('unit-tests/views/test10/children2.volt.php');
		@unlink('unit-tests/views/test10/parent.volt%%e%%.php');

		$volt = new Compiler();

		//With blocks and extending
		$volt->compile('unit-tests/views/test10/children.volt');

		$compilation = file_get_contents('unit-tests/views/test10/children.volt.php');
		$this->assertEquals(
			$compilation,
			'<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"><html lang="en"><html xmlns="http://www.w3.org/1999/xhtml"><head><style type="text/css">.important { color: #336699; }</style><title>Index - My Webpage</title></head><body><div id="content"><h1>Index</h1><p class="important">Welcome on my awesome homepage.</p></div><div id="footer">&copy; Copyright 2012 by <a href="http://domain.invalid/">you</a>.</div></body>'
		);

		//with blocks and two-way blocks
		$volt->compile('unit-tests/views/test10/children2.volt');

		$compilation = file_get_contents('unit-tests/views/test10/children2.volt.php');
		$this->assertEquals(
			$compilation,
			'<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"><html lang="en"><html xmlns="http://www.w3.org/1999/xhtml"><head><style type="text/css">.important { color: #336699; } </style> <link rel="stylesheet" href="style.css" /> <title>Index - My Webpage</title></head><body><div id="content"><h1>Index</h1><p class="important">Welcome to my awesome homepage.</p></div><div id="footer">&copy; Copyright 2012 by <a href="http://domain.invalid/">you</a>.</div></body>'
		);

	}

	public function testVoltCompileFileExtendsMultiple()
	{

		@unlink('unit-tests/views/templates/a.volt%%e%%.php');
		@unlink('unit-tests/views/templates/b.volt%%e%%.php');
		@unlink('unit-tests/views/templates/c.volt.php');

		$volt = new Compiler();

		//With blocks and extending
		$volt->compile('unit-tests/views/templates/c.volt');

		$compilation = trim(file_get_contents('unit-tests/views/templates/c.volt.php'));
		$this->assertEquals($compilation, "[A[###[B]###]]");

	}

	public function testVoltCompilerFileOptions()
	{
		$di = new Phalcon\DI();
		$view = new Phalcon\Mvc\View();

		$volt = new Phalcon\Mvc\View\Engine\Volt($view, $di);

		$volt->setOptions(array(
			"compiledPath" => "unit-tests/cache/",
			"compiledSeparator" => ".",
			"compiledExtension" => ".compiled"
		));

		@unlink('unit-tests/views/test10/index.volt.php');
		@unlink('unit-tests/cache/unit-tests.views.test10.index.volt.compiled');

		//Render simple view
		$view->start();
		$volt->render('unit-tests/views/test10/index.volt', array('song' => 'Lights'), true);
		$view->finish();

		$path = 'unit-tests/cache/' . phalcon_prepare_virtual_path(realpath("unit-tests/"), ".") . '.views.test10.index.volt.compiled';

		$this->assertTrue(file_exists($path));
		$this->assertEquals(file_get_contents($path), 'Hello <?= $song ?>!');
		$this->assertEquals($view->getContent(), 'Hello Lights!');
	}

	public function testVoltEngineBuiltInFunctions()
	{

		@unlink('unit-tests/views/test11/index.volt.php');

		$di = new Phalcon\DI();

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.volt' => 'Phalcon\Mvc\View\Engine\Volt'
		));

		$view->setVar('arr', array(1, 2, 3, 4));
		$view->setVar('obj', new SomeObject(array(1, 2, 3, 4)));
		$view->setVar('str', 'hello');
		$view->setVar('no_str', 1234);

		$view->start();
		$view->render('test11', 'index');
		$view->finish();

		$this->assertEquals(
			$view->getContent(),
			'Length Array: 4Length Object: 4Length String: 5Length No String: 4Slice Array: 1,2,3,4Slice Array: 2,3Slice Array: 1,2,3Slice Object: 2,3,4Slice Object: 2,3Slice Object: 1,2Slice String: helSlice String: elSlice String: lloSlice No String: 123Slice No String: 23Slice No String: 34'
		);
	}

	protected function removeFiles($files)
	{
		if (!is_array($files)) {
			$files = array($files);
		}
		foreach ($files as $file) {
			if (file_exists($file) && is_readable($file)) {
				@unlink($file);
			}
		}
	}
}
