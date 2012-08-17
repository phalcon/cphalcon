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

class DispatcherTest extends PHPUnit_Framework_TestCase
{

	public function dispatcherAutoloader($className)
	{
		if (file_exists('unit-tests/controllers/'.$className.'.php')){
			require 'unit-tests/controllers/'.$className.'.php';
		}
	}

	public function testDispatcher()
	{

		spl_autoload_register(array($this, 'dispatcherAutoloader'));

		$di = new Phalcon\DI();

		$dispatcher = new Phalcon\Mvc\Dispatcher();
		$dispatcher->setDI($di);
		$this->assertInstanceOf('Phalcon\DI', $dispatcher->getDI());

		$di->set('dispatcher', $dispatcher);

		$dispatcher->setControllerName('index');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());

		try {
			$dispatcher->dispatch();
			$this->assertTrue(FALSE, 'oh, Why?');
		}
		catch(Phalcon\Exception $e){
			$this->assertEquals($e->getMessage(), "Service 'IndexController' wasn't found in the dependency injection container");
		}

		$dispatcher->setControllerName('essai');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());

		try {
			$dispatcher->dispatch();
			$this->assertTrue(FALSE, 'oh, Why?');
		}
		catch(Phalcon\Exception $e){
			$this->assertEquals($e->getMessage(), "Service 'EssaiController' wasn't found in the dependency injection container");
		}

		$dispatcher->setControllerName('test0');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());

		try {
			$dispatcher->dispatch();
			$this->assertTrue(FALSE, 'oh, Why?');
		}
		catch(Phalcon\Exception $e){
			$this->assertEquals($e->getMessage(), "Service 'Test0Controller' wasn't found in the dependency injection container");
		}

		$dispatcher->setControllerName('test1');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());

		try {
			$dispatcher->dispatch();
			$this->assertTrue(FALSE, 'oh, Why?');
		}
		catch(Phalcon\Exception $e){
			$this->assertEquals($e->getMessage(), "Action 'index' was not found on controller 'test1'");
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
		}
		catch(Phalcon\Exception $e){
			$this->assertEquals($e->getMessage(), "Action 'essai' was not found on controller 'test2'");
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

		spl_autoload_register(array($this, 'dispatcherAutoloader'));

	}

}
