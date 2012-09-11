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

class ModelsListener
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

class ModelsEventsTest extends PHPUnit_Framework_TestCase
{

	public function __construct()
	{
		spl_autoload_register(array($this, 'modelsAutoloader'));
	}

	public function __destruct()
	{
		spl_autoload_unregister(array($this, 'modelsAutoloader'));
	}

	public function modelsAutoloader($className)
	{
		if (file_exists('unit-tests/models/'.$className.'.php')) {
			require 'unit-tests/models/'.$className.'.php';
		}
	}

	public function testEvents()
	{

		/*Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('modelsManager', function(){
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('modelsMetadata', function(){
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		$di->set('db', function(){
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		});

		$this->_executeTests($di);*/
	}

}