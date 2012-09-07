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

class CliTest extends PHPUnit_Framework_TestCase
{

    public function setup() {

        require_once 'unit-tests/tasks/MainTask.php';
        require_once 'unit-tests/tasks/EchoTask.php';

    }


	public function testTasks()
	{

        $di = new Phalcon\DI();

  		$di->set('data', function(){
  			return "data";
  		});

		$task = new MainTask();
		$task->setDI($di);

		$this->assertEquals($task->requestDiAction(), 'data');
                $this->assertEquals($task->helloAction(), 'Hello !');
                $this->assertEquals($task->helloAction('World'), 'Hello World!');

                $task2 = new EchoTask();
                $task2->setDI($di);
                $this->assertEquals($task2->mainAction(), 'echoMainAction');
	}


    public function testRouters()
   	{

        $di = new Phalcon\DI();

        $di->set('data', function(){
            return "data";
        });

        $router = new \Phalcon\CLI\Router();

        $router->handle(array());
        $this->assertEquals($router->getModuleName(), null);
        $this->assertEquals($router->getTaskName(), null);
        $this->assertEquals($router->getActionName(), null);
        $this->assertEquals($router->getParams(), array());


        $router->handle(array('shell_script_name', 'main'));
        $this->assertEquals($router->getModuleName(), null);
        $this->assertEquals($router->getTaskName(), 'main');
        $this->assertEquals($router->getActionName(), null);
        $this->assertEquals($router->getParams(), array());

        $router->handle(array('shell_script_name', 'echo'));
        $this->assertEquals($router->getModuleName(), null);
        $this->assertEquals($router->getTaskName(), 'echo');
        $this->assertEquals($router->getActionName(), null);
        $this->assertEquals($router->getParams(), array());

        $router->handle(array('shell_script_name', 'main', 'hello'));
        $this->assertEquals($router->getModuleName(), null);
        $this->assertEquals($router->getTaskName(), 'main');
        $this->assertEquals($router->getActionName(), 'hello');
        $this->assertEquals($router->getParams(), array());

        $router->handle(array('shell_script_name', 'main', 'hello', 'arg1', 'arg2'));
        $this->assertEquals($router->getModuleName(), null);
        $this->assertEquals($router->getTaskName(), 'main');
        $this->assertEquals($router->getActionName(), 'hello');
        $this->assertEquals($router->getParams(), array('arg1', 'arg2'));

        $router->handle(array('shell_script_name', 'devtools:main', 'hello', 'arg1', 'arg2'));
        $this->assertEquals($router->getModuleName(), 'devtools');
        $this->assertEquals($router->getTaskName(), 'main');
        $this->assertEquals($router->getActionName(), 'hello');
        $this->assertEquals($router->getParams(), array('arg1', 'arg2'));

        $router->handle(array('shell_script_name', 'devtools:echo', 'hello', 'arg1', 'arg2'));
        $this->assertEquals($router->getModuleName(), 'devtools');
        $this->assertEquals($router->getTaskName(), 'echo');
        $this->assertEquals($router->getActionName(), 'hello');
        $this->assertEquals($router->getParams(), array('arg1', 'arg2'));

   	}

    public function testDispatchers()
   	{

        $di = new Phalcon\DI();

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
        }catch (Exception $e) {
            $this->assertEquals($e->getMessage(), 'Dummy\MainTask task class cannot be loaded');
        }

   	}

    public function testConsoles()
   	{

        $di = new Phalcon\DI();

        $di->set('data', function(){
            return "data";
        });

        $console = new \Phalcon\CLI\Console();
        $console->setDI($di);
        $dispatcher = $console->getDI()->getShared('dispatcher');

        $console->handle(array('shell_script_name'));
        $this->assertEquals($dispatcher->getTaskName(), 'main');
        $this->assertEquals($dispatcher->getActionName(), 'main');
        $this->assertEquals($dispatcher->getParams(), array());
        $this->assertEquals($dispatcher->getReturnedValue(), 'mainAction');

        $console->handle(array('shell_script_name', 'echo'));
        $this->assertEquals($dispatcher->getTaskName(), 'echo');
        $this->assertEquals($dispatcher->getActionName(), 'main');
        $this->assertEquals($dispatcher->getParams(), array());
        $this->assertEquals($dispatcher->getReturnedValue(), 'echoMainAction');

        $console->handle(array('shell_script_name', 'main', 'hello'));
        $this->assertEquals($dispatcher->getTaskName(), 'main');
        $this->assertEquals($dispatcher->getActionName(), 'hello');
        $this->assertEquals($dispatcher->getParams(), array());
        $this->assertEquals($dispatcher->getReturnedValue(), 'Hello !');

        $console->handle(array('shell_script_name', 'main', 'hello', 'World', '######'));
        $this->assertEquals($dispatcher->getTaskName(), 'main');
        $this->assertEquals($dispatcher->getActionName(), 'hello');
        $this->assertEquals($dispatcher->getParams(), array('World', '######'));
        $this->assertEquals($dispatcher->getReturnedValue(), 'Hello World######');

        // testing module
        try {
            $console->handle(array('shell_script_name', 'devtools:main', 'hello', 'World', '######'));
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
            $console->handle(array('shell_script_name', 'main', 'hello', 'World', '!'));
            $this->assertEquals($dispatcher->getTaskName(), 'main');
            $this->assertEquals($dispatcher->getActionName(), 'hello');
            $this->assertEquals($dispatcher->getParams(), array('World'));
            $this->assertEquals($dispatcher->getReturnedValue(), 'Hello World!');
        }catch (Exception $e) {
            $this->assertEquals($e->getMessage(), 'Dummy\MainTask task class cannot be loaded');
        }

    }

    public function testModules() {

        $di = new Phalcon\DI();

        $di->set('data', function(){
            return "data";
        });

        $console = new \Phalcon\CLI\Console();
        $console->setDI($di);

        $expected = array('devtools'=> array('className' =>'dummy', 'path' => 'dummy_file'));

        $console->registerModules($expected);

        $this->assertEquals($console->getModules(), $expected);

        $userModules = array('front'=>array('className'=>'front', 'path'=>'front_file'), 'worker'=>array('className'=>'worker', 'path'=>'worker_file'));

        $expected = array('devtools'=> array('className' =>'dummy', 'path' => 'dummy_file'), 'front'=>array('className'=>'front', 'path'=>'front_file'), 'worker'=>array('className'=>'worker', 'path'=>'worker_file'));
;
        $console->registerModules($userModules);

        $this->assertEquals($console->getModules(), $expected);


    }
}
