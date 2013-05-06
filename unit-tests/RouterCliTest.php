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

class RouterCliTest extends PHPUnit_Framework_TestCase
{

	public function testRouters()
	{

		$di = new \Phalcon\DI\FactoryDefault\CLI();

		$di->set('data', function(){
			return "data";
		});

		$router = new \Phalcon\CLI\Router();

		$router->handle(array());
		$this->assertEquals($router->getModuleName(), null);
		$this->assertEquals($router->getTaskName(), null);
		$this->assertEquals($router->getActionName(), null);
		$this->assertEquals($router->getParams(), array());


		$router->handle(array(
			'task' => 'main'
		));
		$this->assertEquals($router->getModuleName(), null);
		$this->assertEquals($router->getTaskName(), 'main');
		$this->assertEquals($router->getActionName(), null);
		$this->assertEquals($router->getParams(), array());

		$router->handle(array(
			'task' => 'echo'
		));
		$this->assertEquals($router->getModuleName(), null);
		$this->assertEquals($router->getTaskName(), 'echo');
		$this->assertEquals($router->getActionName(), null);
		$this->assertEquals($router->getParams(), array());

		$router->handle(array(
			'task' => 'main',
			'action' => 'hello'
		));
		$this->assertEquals($router->getModuleName(), null);
		$this->assertEquals($router->getTaskName(), 'main');
		$this->assertEquals($router->getActionName(), 'hello');
		$this->assertEquals($router->getParams(), array());

		$router->handle(array(
			'task' => 'main',
			'action' => 'hello',
			'arg1',
			'arg2'
		));
		$this->assertEquals($router->getModuleName(), null);
		$this->assertEquals($router->getTaskName(), 'main');
		$this->assertEquals($router->getActionName(), 'hello');
		$this->assertEquals($router->getParams(), array('arg1', 'arg2'));

		$router->handle(array(
			'module' => 'devtools',
			'task' => 'main',
			'action' => 'hello',
			'arg1',
			'arg2'
		));
		$this->assertEquals($router->getModuleName(), 'devtools');
		$this->assertEquals($router->getTaskName(), 'main');
		$this->assertEquals($router->getActionName(), 'hello');
		$this->assertEquals($router->getParams(), array('arg1', 'arg2'));

		$router->handle(array(
			'module' => 'devtools',
			'task' => 'echo',
			'action' => 'hello',
			'arg1',
			'arg2'
		));
		$this->assertEquals($router->getModuleName(), 'devtools');
		$this->assertEquals($router->getTaskName(), 'echo');
		$this->assertEquals($router->getActionName(), 'hello');
		$this->assertEquals($router->getParams(), array('arg1', 'arg2'));

	}

}