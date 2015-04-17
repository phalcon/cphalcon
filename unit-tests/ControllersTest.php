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

}
