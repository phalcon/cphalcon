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

use Phalcon\Db\Pool as Pool;

class ControllersTest extends PHPUnit_Framework_TestCase {

	public function testControllers(){

		require 'unit-tests/config.db.php';

		Pool::setDefaultDescriptor($configMysql);
		$this->assertTrue(Pool::hasDefaultDescriptor());

		$model = new Phalcon\Model\Manager();
		$model->setModelsDir('unit-tests/models/');

		$view = new Phalcon\View();
		$view->setViewsDir('unit-tests/views/');

		$dispatcher = new Phalcon\Dispatcher();

		$request = Phalcon\Request::getInstance();
		$response = Phalcon\Response::getInstance();

		$dispatcher->setBasePath('./');
		$dispatcher->setControllersDir('tests/controllers/');

		require 'unit-tests/controllers/Test4Controller.php';

		$controller = new Test4Controller($dispatcher, $request, $response, $view, $model);

		$_POST['email'] = ';ans@ecom.com';
		$this->assertEquals($controller->requestAction(), 'ans@ecom.com');

		$controller->viewAction();
		$this->assertEquals(count($view->getParamsToView()), 1);

		$records = $controller->modelAction();
		$this->assertEquals(get_class($records), 'Phalcon\Model\Resultset');

	}

}