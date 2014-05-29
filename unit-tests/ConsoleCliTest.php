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
  |          Rack Lin <racklin@gmail.com>                                  |
  +------------------------------------------------------------------------+
*/

class ConsoleCliTest extends PHPUnit_Framework_TestCase
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

	public function testConsoles()
	{

		$di = new Phalcon\DI\FactoryDefault\CLI();

		$di->set('data', function(){
			return "data";
		});

		$console = new \Phalcon\CLI\Console();
		$console->setDI($di);
		$dispatcher = $console->getDI()->getShared('dispatcher');

		$console->handle(array());
		$this->assertEquals($dispatcher->getTaskName(), 'main');
		$this->assertEquals($dispatcher->getActionName(), 'main');
		$this->assertEquals($dispatcher->getParams(), array());
		$this->assertEquals($dispatcher->getReturnedValue(), 'mainAction');

		$console->handle(array(
			'task' => 'echo'
		));

		$this->assertEquals($dispatcher->getTaskName(), 'echo');
		$this->assertEquals($dispatcher->getActionName(), 'main');
		$this->assertEquals($dispatcher->getParams(), array());
		$this->assertEquals($dispatcher->getReturnedValue(), 'echoMainAction');

		$console->handle(array(
			'task' => 'main',
			'action' => 'hello'
		));
		$this->assertEquals($dispatcher->getTaskName(), 'main');
		$this->assertEquals($dispatcher->getActionName(), 'hello');
		$this->assertEquals($dispatcher->getParams(), array());
		$this->assertEquals($dispatcher->getReturnedValue(), 'Hello !');

		$console->handle(array(
			'task' => 'main',
			'action' => 'hello',
			'World',
			'######'
		));
		$this->assertEquals($dispatcher->getTaskName(), 'main');
		$this->assertEquals($dispatcher->getActionName(), 'hello');
		$this->assertEquals($dispatcher->getParams(), array('World', '######'));
		$this->assertEquals($dispatcher->getReturnedValue(), 'Hello World######');

		// testing module
		try {
			$console->handle(array(
				'module' => 'devtools',
				'task' => 'main',
				'action' => 'hello',
				'World',
				'######'
			));
			$this->assertEquals($dispatcher->getTaskName(), 'main');
			$this->assertEquals($dispatcher->getActionName(), 'hello');
			$this->assertEquals($dispatcher->getParams(), array('World', '######'));
			$this->assertEquals($dispatcher->getReturnedValue(), 'Hello World######');
		} catch (Exception $e) {
			$this->assertEquals($e->getMessage(), "Module 'devtools' isn't registered in the console container");
		}

		// testing namespace
		try {

			$dispatcher->setDefaultNamespace('Dummy\\');
			$console->handle(array(
				'task' => 'main',
				'action' => 'hello',
				'World',
				'!'
			));
			$this->assertEquals($dispatcher->getTaskName(), 'main');
			$this->assertEquals($dispatcher->getActionName(), 'hello');
			$this->assertEquals($dispatcher->getParams(), array('World'));
			$this->assertEquals($dispatcher->getReturnedValue(), 'Hello World!');
		} catch (Exception $e) {
			$this->assertEquals($e->getMessage(), 'Dummy\MainTask handler class cannot be loaded');
		}

	}

	public function testModules()
	{

		$di = new Phalcon\DI();

		$di->set('data', function(){
			return "data";
		});

		$console = new \Phalcon\CLI\Console();
		$console->setDI($di);

		$expected = array(
			'devtools'=> array(
				'className' => 'dummy',
				'path' => 'dummy_file'
			)
		);

		$console->registerModules($expected);

		$this->assertEquals($console->getModules(), $expected);

		$userModules = array(
			'front'=> array(
				'className' => 'front',
				'path' => 'front_file'
			),
			'worker' => array(
				'className' => 'worker',
				'path' => 'worker_file'
			)
		);

		$expected = array(
			'devtools'=> array(
				'className' => 'dummy',
				'path' => 'dummy_file'
			),
			'front' => array(
				'className' => 'front',
				'path' => 'front_file'
			),
			'worker' => array(
				'className' => 'worker',
				'path'=>'worker_file'
			)
		);

		$console->addModules($userModules);

		$this->assertEquals($console->getModules(), $expected);


	}

	public function testIssue787()
	{
		$di = new \Phalcon\DI\FactoryDefault\CLI();

		$di->setShared('dispatcher', function() use ($di)
		{
			$dispatcher = new Phalcon\CLI\Dispatcher;
			$dispatcher->setDI($di);
			return $dispatcher;
		});

		$console = new \Phalcon\CLI\Console();
		$console->setDI($di);
		$console->handle(array('task' => 'issue787', 'action' => 'main'));

		$this->assertTrue(class_exists('Issue787Task'));

		$actual   = Issue787Task::$output;
		$expected = "beforeExecuteRoute".PHP_EOL."initialize".PHP_EOL;
		$this->assertEquals($actual, $expected);
	}
}
