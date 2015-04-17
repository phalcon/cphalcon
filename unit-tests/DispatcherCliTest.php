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

}