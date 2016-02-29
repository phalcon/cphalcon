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

class DispatcherCliTest extends PHPUnit_Framework_TestCase
{

	public function dispatcherAutoloader($className)
	{
		if (file_exists('unit-tests/tasks/'.$className.'.php')) {
			require 'unit-tests/tasks/'.$className.'.php';
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

		$di = new \Phalcon\DI\FactoryDefault\CLI();

		$di->set('data', function(){
			return "data";
		});

		$dispatcher = new \Phalcon\CLI\Dispatcher();
		$dispatcher->setDI($di);
		$dispatcher->dispatch();
		$this->assertEquals($dispatcher->getTaskName(), 'main');
		$this->assertEquals($dispatcher->getActionName(), 'main');
		$this->assertEquals($dispatcher->getParams(), array());
		$this->assertEquals($dispatcher->getReturnedValue(), 'mainAction');

		$dispatcher->setTaskName('echo');
		$dispatcher->dispatch();
		$this->assertEquals($dispatcher->getTaskName(), 'echo');
		$this->assertEquals($dispatcher->getActionName(), 'main');
		$this->assertEquals($dispatcher->getParams(), array());
		$this->assertEquals($dispatcher->getReturnedValue(), 'echoMainAction');

		$dispatcher->setTaskName('main');
		$dispatcher->setActionName('hello');
		$dispatcher->dispatch();
		$this->assertEquals($dispatcher->getTaskName(), 'main');
		$this->assertEquals($dispatcher->getActionName(), 'hello');
		$this->assertEquals($dispatcher->getParams(), array());
		$this->assertEquals($dispatcher->getReturnedValue(), 'Hello !');

		$dispatcher->setActionName('hello');
		$dispatcher->setParams(array('World', '######'));
		$dispatcher->dispatch();
		$this->assertEquals($dispatcher->getTaskName(), 'main');
		$this->assertEquals($dispatcher->getActionName(), 'hello');
		$this->assertEquals($dispatcher->getParams(), array('World', '######'));
		$this->assertEquals($dispatcher->getReturnedValue(), 'Hello World######');

		$dispatcher->setActionName('hello');
		$dispatcher->setParams(array('hello' => 'World', 'goodbye' => 'Everybody'));
		$dispatcher->dispatch();
		$this->assertTrue($dispatcher->hasParam('hello'));
		$this->assertTrue($dispatcher->hasParam('goodbye'));
		$this->assertFalse($dispatcher->hasParam('salutations'));

		// testing namespace
		try {
			$dispatcher->setDefaultNamespace('Dummy\\');
			$dispatcher->setTaskName('main');
			$dispatcher->setActionName('hello');
			$dispatcher->setParams(array('World'));
			$dispatcher->dispatch();
			$this->assertEquals($dispatcher->getTaskName(), 'main');
			$this->assertEquals($dispatcher->getActionName(), 'hello');
			$this->assertEquals($dispatcher->getParams(), array('World'));
			$this->assertEquals($dispatcher->getReturnedValue(), 'Hello World!');
		} catch (Exception $e) {
			$this->assertEquals($e->getMessage(), 'Dummy\MainTask handler class cannot be loaded');
		}

	}

	public function testCliParameters()
	{
		$di = new \Phalcon\DI\FactoryDefault\CLI();

		$dispatcher = new \Phalcon\CLI\Dispatcher();

		$di->setShared("dispatcher", $dispatcher);

		$dispatcher->setDI($di);

		// Test $this->dispatcher->getParams()
		$dispatcher->setTaskName('params');
		$dispatcher->setActionName('params');
		$dispatcher->setParams(array('This', 'Is', 'An', 'Example'));
		$dispatcher->dispatch();
		$this->assertEquals($dispatcher->getReturnedValue(), '$params is the same as $this->dispatcher->getParams()');

		// Test $this->dispatcher->getParam()
		$dispatcher->setTaskName('params');
		$dispatcher->setActionName('param');
		$dispatcher->setParams(array('This', 'Is', 'An', 'Example'));
		$dispatcher->dispatch();
		$this->assertEquals($dispatcher->getReturnedValue(), '$param[0] is the same as $this->dispatcher->getParam(0)');
	}

	public function testCallActionMethod()
	{
		$di = new \Phalcon\DI\FactoryDefault\CLI();

		$dispatcher = new \Phalcon\CLI\Dispatcher();

		$di->setShared("dispatcher", $dispatcher);

		$dispatcher->setDI($di);

		$mainTask = new MainTask();
		$mainTask->setDI($di);

		$this->assertEquals($dispatcher->callActionMethod($mainTask, 'mainAction', []), 'mainAction');
		$this->assertEquals($dispatcher->callActionMethod($mainTask, 'helloAction', ['World']), 'Hello World!');
		$this->assertEquals($dispatcher->callActionMethod($mainTask, 'helloAction', ['World', '.']), 'Hello World.');
	}
}