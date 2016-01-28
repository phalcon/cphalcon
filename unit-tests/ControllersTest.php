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

class ControllersTest extends PHPUnit_Framework_TestCase
{

	public function testControllers()
	{
		$di = new Phalcon\DI();

		$di->set('view', function(){
			$view = new Phalcon\Mvc\View();
			$view->setViewsDir('unit-tests/views/');
			return $view;
		});

		$di->set('request', function(){
			return new Phalcon\Http\Request();
		});

		$di->set('filter', function(){
			return new Phalcon\Filter();
		});

		if (!class_exists('Test4Controller', false)) {
			require __DIR__ . '/controllers/Test4Controller.php';
		}

		$controller = new Test4Controller();
		$controller->setDI($di);

		$_POST['email'] = ';ans@ecom.com';
		$this->assertEquals($controller->requestAction(), 'ans@ecom.com');

		$view = $di->getShared('view');

		$controller->viewAction();
		$this->assertEquals(count($view->getParamsToView()), 1);
	}

	public function testModelBinding()
	{
		require 'unit-tests/config.db.php';
		if (empty($configMysql)) {
			$this->markTestSkipped("Skipped");
			return;
		}

		Phalcon\DI::reset();
		$di = new Phalcon\Di();

		$di->set('modelsManager', function() {
			return new Phalcon\Mvc\Model\Manager();
		});

		$di->set('modelsMetadata', function() {
			return new Phalcon\Mvc\Model\Metadata\Memory();
		});

		$di->set('db', function() {
			require 'unit-tests/config.db.php';
			return new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
		}, true);

		$dispatcher = new Phalcon\Mvc\Dispatcher();
		$dispatcher->setModelBinding(true);
		$dispatcher->setDI($di);
		$this->assertInstanceOf('Phalcon\Di', $dispatcher->getDI());

		$di->set('dispatcher', $dispatcher);

		if (!class_exists('People', false)) {
			require __DIR__ . '/models/People.php';
		}

		if (!class_exists('Test10Controller', false)) {
			require __DIR__ . '/controllers/Test10Controller.php';
		}

		if (!class_exists('Test9Controller', false)) {
			require __DIR__ . '/controllers/Test9Controller.php';
		}

		//Model to test with
		$model = People::findFirst();

		$dispatcher->setControllerName('test10');
		$dispatcher->setActionName('view');
		$dispatcher->setParams(array(0 => $model->cedula));

		$dispatcher->dispatch();
		$this->assertInstanceOf('People', $dispatcher->getReturnedValue());
		$this->assertEquals($dispatcher->getReturnedValue()->cedula, $model->cedula);

		//Reset dispatcher
		$dispatcher = new Phalcon\Mvc\Dispatcher();
		$dispatcher->setDI($di);
		$this->assertInstanceOf('Phalcon\Di', $dispatcher->getDI());

		$di->set('dispatcher', $dispatcher);

		$dispatcher->setControllerName('test9');
		$dispatcher->setActionName('view');
		$dispatcher->setParams(array(0 => $model->cedula));

		try {
			$dispatcher->dispatch();
		}catch (Exception $e) {
			$error = (bool) strpos($e->getMessage(), 'must be an instance of Phalcon\Mvc\Model');
			$this->assertTrue($error);
		}

		$dispatcher->setModelBinding(true);
		$dispatcher->dispatch();

		$this->assertInstanceOf('People', $dispatcher->getReturnedValue());
		$this->assertEquals($dispatcher->getReturnedValue()->cedula, $model->cedula);
    }
}
