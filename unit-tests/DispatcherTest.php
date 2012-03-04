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

class DispatcherTest extends PHPUnit_Framework_TestCase {

	private $_dispatcher;

	public function setUp(){		
		$this->_dispatcher = new Phalcon_Dispatcher();
	}

	public function testDispatcher(){

		$dispatcher = new Phalcon_Dispatcher();

		$controllersDir = 'unit-tests/controllers/';
		$dispatcher->setControllersDir($controllersDir);
		$this->assertEquals($dispatcher->getControllersDir(), $controllersDir);
		
		$request = Phalcon_Request::getInstance();
		$this->assertInstanceOf('Phalcon_Request', $request);

		$response = Phalcon_Response::getInstance();
		$this->assertInstanceOf('Phalcon_Response', $response);

		$dispatcher->setControllerName('index');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());

		try {
			$dispatcher->dispatch($request, $response);
		}
		catch(Phalcon_Exception $e){
			$this->assertEquals($e->getMessage(), "File for controller class IndexController doesn't exists");		
		}

		$dispatcher->setControllerName('essai');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());

		try {
			$dispatcher->dispatch($request, $response);
		}
		catch(Phalcon_Exception $e){
			$this->assertEquals($e->getMessage(), "File for controller class EssaiController doesn't exists");
		}

		$dispatcher->setControllerName('test0');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());

		try {
			$dispatcher->dispatch($request, $response);
		}
		catch(Phalcon_Exception $e){
			$this->assertEquals($e->getMessage(), "Class Test0Controller was not found on controller file");			
		}

		$dispatcher->setControllerName('test1');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());

		try {
			$dispatcher->dispatch($request, $response);
		}
		catch(Phalcon_Exception $e){
			$this->assertEquals($e->getMessage(), "Action 'index' was not found on controller 'test1'");
		}

		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());
		$controller = $dispatcher->dispatch($request, $response);
		$this->assertInstanceOf('Test2Controller', $controller);

		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('essai');
		$dispatcher->setParams(array());

		try {
			$dispatcher->dispatch($request, $response);
		}
		catch(Phalcon_Exception $e){
			$this->assertEquals($e->getMessage(), "Action 'essai' was not found on controller 'test2'");
		}
	
		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('other');
		$dispatcher->setParams(array());
		$controller = $dispatcher->dispatch($request, $response);
		$this->assertInstanceOf('Test2Controller', $controller);

		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('another');
		$dispatcher->setParams(array());
		$dispatcher->dispatch($request, $response);
		$value = $dispatcher->getReturnedValue();
		$this->assertEquals($value, 100);

		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('anotherTwo');
		$dispatcher->setParams(array(2, "3"));
		$dispatcher->dispatch($request, $response);
		$value = $dispatcher->getReturnedValue();
		$this->assertEquals($value, 5);

		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('anotherthree');
		$dispatcher->setParams(array());
		$dispatcher->dispatch($request, $response);
		$value = $dispatcher->getActionName();
		$this->assertEquals($value, 'anotherfour');

		$this->assertEquals(count($dispatcher->getControllers()), 2);

		//GC
		gc_collect_cycles();

	}

	public function testEvents(){

		$dispatcher = new Phalcon_Dispatcher();

		$controllersDir = 'unit-tests/controllers/';
		$dispatcher->setControllersDir($controllersDir);
		$this->assertEquals($dispatcher->getControllersDir(), $controllersDir);
		
		$request = Phalcon_Request::getInstance();
		$this->assertInstanceOf('Phalcon_Request', $request);

		$response = Phalcon_Response::getInstance();
		$this->assertInstanceOf('Phalcon_Response', $response);

		//beforeDispatch event
		$dispatcher->setControllerName('test5');
		$dispatcher->setActionName('notexists');
		$dispatcher->setParams(array());
		$dispatcher->dispatch($request, $response);
		$value = $dispatcher->getActionName();
		$this->assertEquals($value, 'notexists');		

		//Not found event
		$value = $dispatcher->getReturnedValue();
		$this->assertEquals($value, 'not-found');		

		//afterDispatch event
		$dispatcher->setControllerName('test6');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());
		$dispatcher->dispatch($request, $response);
		$value = $dispatcher->getReturnedValue();
		$this->assertEquals($value, false);	

		//GC
		gc_collect_cycles();

	}

}