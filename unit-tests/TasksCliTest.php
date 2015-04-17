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
  |          Rack Lin <racklin@gmail.com>                                  |
  +------------------------------------------------------------------------+
*/

class TasksCliTest extends PHPUnit_Framework_TestCase
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

	public function testTasks()
	{

		$di = new \Phalcon\DI\FactoryDefault\CLI();

		$di['registry'] = function()
		{
			$registry = new \Phalcon\Registry;
			$registry->data = 'data';
			return $registry;
		};

		$task = new MainTask();
		$task->setDI($di);

		$this->assertEquals($task->requestRegistryAction(), 'data');
		$this->assertEquals($task->helloAction(), 'Hello !');
		$this->assertEquals($task->helloAction('World'), 'Hello World!');

		$task2 = new EchoTask();
		$task2->setDI($di);
		$this->assertEquals($task2->mainAction(), 'echoMainAction');
	}

}