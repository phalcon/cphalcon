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

class DispatcherListener
{

	protected $_test;

	protected $_trace = '';

	protected $_stop = '';

	protected $_actionName;

	public function __construct($test)
	{
		$this->_test = $test;
	}

	public function stopAt($eventName)
	{
		$this->_trace = array();
		$this->_stop = $eventName;
	}

	public function setActionName($actionName)
	{
		$this->_actionName = $actionName;
	}

	public function beforeDispatch(Phalcon\Events\Event $event, Phalcon\Mvc\Dispatcher $dispatcher)
	{
		$this->_trace[] = 'beforeDispatch';
		$this->_test->assertEquals('test2', $dispatcher->getControllerName());
		$this->_test->assertEquals($this->_actionName, $dispatcher->getActionName());
		if ($this->_stop == 'beforeDispatch') {
			return false;
		}
	}

	public function beforeExecuteRoute(Phalcon\Events\Event $event, Phalcon\Mvc\Dispatcher $dispatcher)
	{
		$this->_trace[] = 'beforeExecuteRoute';
		$this->_test->assertEquals('test2', $dispatcher->getControllerName());
		$this->_test->assertEquals($this->_actionName, $dispatcher->getActionName());
		if ($this->_stop == 'beforeExecuteRoute') {
			return false;
		}
	}

	public function afterExecuteRoute(Phalcon\Events\Event $event, Phalcon\Mvc\Dispatcher $dispatcher)
	{
		$this->_trace[] = 'afterExecuteRoute';
		$this->_test->assertEquals('test2', $dispatcher->getControllerName());
		$this->_test->assertEquals($this->_actionName, $dispatcher->getActionName());
	}

	public function afterDispatch(Phalcon\Events\Event $event, Phalcon\Mvc\Dispatcher $dispatcher)
	{
		$this->_trace[] = 'afterDispatch';
		$this->_test->assertEquals('test2', $dispatcher->getControllerName());
		$this->_test->assertEquals($this->_actionName, $dispatcher->getActionName());
	}

	public function beforeNotFoundAction(Phalcon\Events\Event $event, Phalcon\Mvc\Dispatcher $dispatcher)
	{
		$this->_trace[] = 'beforeNotFoundAction';
		$this->_test->assertEquals('test2', $dispatcher->getControllerName());
		$this->_test->assertEquals($this->_actionName, $dispatcher->getActionName());
		return false;
	}

	public function clearTrace()
	{
		$this->_trace = array();
	}

	public function getTrace()
	{
		return $this->_trace;
	}

}

class DispatcherMvcEventsTest extends PHPUnit_Framework_TestCase
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

	public function testEvents()
	{

		$di = new Phalcon\DI();

		$di->set('response', function(){
			return new \Phalcon\Http\Response();
		});

		$listener = new DispatcherListener($this);

		$eventsManager = new Phalcon\Events\Manager();
		$eventsManager->attach('dispatch', $listener);

		$dispatcher = new Phalcon\Mvc\Dispatcher();
		$dispatcher->setDI($di);
		$dispatcher->setEventsManager($eventsManager);

		$listener->setActionName('index');
		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('index');
		$dispatcher->setParams(array());
		$dispatcher->dispatch();

		$trace = join('-', $listener->getTrace());
		$this->assertEquals($trace, 'beforeDispatch-beforeExecuteRoute-afterExecuteRoute-afterDispatch');

		//Stop at beforeDispatch event
		$listener->stopAt('beforeDispatch');
		$dispatcher->dispatch();

		$trace = join('-', $listener->getTrace());
		$this->assertEquals($trace, 'beforeDispatch');

		//Stop at beforeExecuteRoute event
		$listener->stopAt('beforeExecuteRoute');
		$dispatcher->dispatch();

		$trace = join('-', $listener->getTrace());
		$this->assertEquals($trace, 'beforeDispatch-beforeExecuteRoute');

		$listener->clearTrace();

		//Dispatch a not existing action
		$listener->setActionName('notExists');
		$dispatcher->setControllerName('test2');
		$dispatcher->setActionName('notExists');
		$dispatcher->setParams(array());
		$dispatcher->dispatch();

		$trace = join('-', $listener->getTrace());
		$this->assertEquals($trace, 'beforeDispatch-beforeNotFoundAction');

	}

}
