<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

class DispatcherMvcTest extends PHPUnit_Framework_TestCase
{

	public function dispatcherAutoloader($className)
	{
		if (file_exists('unit-tests/controllers/'.$className.'.php')) {
			require 'unit-tests/controllers/'.$className.'.php';
		}
	}

	public function __construct()
	{
		spl_autoload_register(array($this, 'dispatcherAutoloader'));
	}

	public function __destruct()
	{
		spl_autoload_unregister(array($this, 'dispatcherAutoloader'));
	}

	public function testDispatcher()
	{

		Phalcon\DI::reset();

		$di = new Phalcon\Di();

		$di->set('response', new \Phalcon\Http\Response());

		$dispatcher = new Phalcon\Mvc\Dispatcher();
		$dispatcher->setDI($di);
		$this->assertInstanceOf('Phalcon\Di', $dispatcher->getDI());

		$di->set('dispatcher', $dispatcher);

		$dispatcher->setControllerName('index');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());

		try {
			$dispatcher->dispatch();
			$this->assertTrue(FALSE, 'oh, Why?');
		} catch (Phalcon\Exception $e) {
			$this->assertEquals($e->getMessage(), "IndexController handler class cannot be loaded");
			$this->assertInstanceOf('Phalcon\Mvc\Dispatcher\Exception', $e);
		}

		$dispatcher->setControllerName('essai');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());

		try {
			$dispatcher->dispatch();
			$this->assertTrue(FALSE, 'oh, Why?');
		} catch (Phalcon\Exception $e){
			$this->assertEquals($e->getMessage(), "EssaiController handler class cannot be loaded");
			$this->assertInstanceOf('Phalcon\Mvc\Dispatcher\Exception', $e);
		}

		$dispatcher->setControllerName('test0');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());

		try {
			$dispatcher->dispatch();
			$this->assertTrue(FALSE, 'oh, Why?');
		} catch(Phalcon\Exception $e) {
			$this->assertEquals($e->getMessage(), "Test0Controller handler class cannot be loaded");
			$this->assertInstanceOf('Phalcon\Mvc\Dispatcher\Exception', $e);
		}

		$dispatcher->setControllerName('test1');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());

		try {
			$dispatcher->dispatch();
			$this->assertTrue(FALSE, 'oh, Why?');
		} catch (Phalcon\Exception $e) {
			$this->assertEquals($e->getMessage(), "Action 'index' was not found on handler 'test1'");
		}

		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());
		$controller = $dispatcher->dispatch();
		$this->assertInstanceOf('Test2Controller', $controller);

		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('essai');
		$dispatcher->setParams(array());

		try {
			$dispatcher->dispatch();
			$this->assertTrue(FALSE, 'oh, Why?');
		} catch (Phalcon\Exception $e) {
			$this->assertEquals($e->getMessage(), "Action 'essai' was not found on handler 'test2'");
		}

		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('other');
		$dispatcher->setParams(array());
		$controller = $dispatcher->dispatch();
		$this->assertInstanceOf('Test2Controller', $controller);

		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('another');
		$dispatcher->setParams(array());
		$dispatcher->dispatch();
		$value = $dispatcher->getReturnedValue();
		$this->assertEquals($value, 100);

		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('anotherTwo');
		$dispatcher->setParams(array(2, "3"));
		$dispatcher->dispatch();
		$value = $dispatcher->getReturnedValue();
		$this->assertEquals($value, 5);

		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('anotherthree');
		$dispatcher->setParams(array());
		$dispatcher->dispatch();
		$value = $dispatcher->getActionName();
		$this->assertEquals($value, 'anotherfour');
		$value = $dispatcher->getReturnedValue();
		$this->assertEquals($value, 120);

		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('anotherFive');
		$dispatcher->setParams(array("param1" => 2, "param2" => 3));
		$dispatcher->dispatch();
		$value = $dispatcher->getReturnedValue();
		$this->assertEquals($value, 5);

		$dispatcher->setControllerName('test7');
		$dispatcher->setActionName('service');
		$dispatcher->setParams(array());
		$dispatcher->dispatch();
		$value = $dispatcher->getReturnedValue();
		$this->assertEquals($value, "hello");

		$value = $dispatcher->getControllerClass();
		$this->assertEquals($value, "Test7Controller");
	}

	public function testDispatcherForward()
	{
		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		//$di->set('response', new \Phalcon\Http\Response());

		$dispatcher = new Phalcon\Mvc\Dispatcher();
		$dispatcher->setDI($di);

		$di->set('dispatcher', $dispatcher);

		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());

		$dispatcher->forward(array('controller' => 'test3', 'action' => 'other'));

		$value = $dispatcher->getControllerName();
		$this->assertEquals($value, 'test3');

		$value = $dispatcher->getActionName();
		$this->assertEquals($value, 'other');

		$value = $dispatcher->getPreviousControllerName();
		$this->assertEquals($value, 'test2');

		$value = $dispatcher->getPreviousActionName();
		$this->assertEquals($value, 'index');
	}

	public function testGetControllerClass()
	{
		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$dispatcher = new Phalcon\Mvc\Dispatcher();
		$dispatcher->setDI($di);

		$di->set('dispatcher', $dispatcher);

		// With namespace
		$dispatcher->setNamespaceName('Foo\Bar');
		$dispatcher->setControllerName('test');

		$value = $dispatcher->getControllerClass();
		$this->assertEquals($value, 'Foo\Bar\TestController');

		// Without namespace
		$dispatcher->setNamespaceName(null);
		$dispatcher->setControllerName('Test');

		$value = $dispatcher->getControllerClass();
		$this->assertEquals('TestController', $value);
	}

	public function testDefaultsResolve()
	{
		Phalcon\DI::reset();
		$di = new Phalcon\DI();

		$dispatcher = new Phalcon\Mvc\Dispatcher();
		$dispatcher->setDI($di);

		$di->set('dispatcher', $dispatcher);

		$dispatcher->setDefaultNamespace('Foo');

		$value = $dispatcher->getControllerClass();
		$this->assertEquals('Foo\IndexController', $value);
	}

}
