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

/**
 * @RoutePrefix("/robots")
 */
class RobotsController
{

	/**
	 * @Get("/")
	 */
	public function indexAction()
	{

	}

	/**
	 * @Get("/edit/{id:[0-9]+}", name="edit-robot")
	 */
	public function editAction($id)
	{

	}

	/**
	 * @Route("/save", methods={"POST", "PUT"}, name="save-robot")
	 */
	public function saveAction()
	{

	}

}

class ProductsController
{

	/**
	 * @Get("/products")
	 */
	public function indexAction()
	{

	}

	/**
	 * @Get("/products/edit/{id:[0-9]+}", name="edit-product")
	 */
	public function editAction($id)
	{

	}

	/**
	 * @Route("/products/save", methods={"POST", "PUT"}, name="save-product")
	 */
	public function saveAction()
	{

	}

}

class RouterMvcAnnotationsTest extends PHPUnit_Framework_TestCase
{
	public function _getDI()
	{
		$di = new Phalcon\DI();
		$di['request'] = new Phalcon\Http\Request();
		$di['annotations'] = new Phalcon\Annotations\Adapter\Memory();
		return $di;
	}

	public function testRouterFullResources()
	{

		$router = new Phalcon\Mvc\Router\Annotations(false);
		$router->setDI($this->_getDI());

		$router->addResource('Robots');
		$router->addResource('Products');

		$router->handle();

		$this->assertEquals(count($router->getRoutes()), 6);

		$route = $router->getRouteByName('save-robot');
		$this->assertTrue(is_object($route));
		$this->assertEquals(get_class($route), 'Phalcon\Mvc\Router\Route');

		$route = $router->getRouteByName('save-product');
		$this->assertTrue(is_object($route));
		$this->assertEquals(get_class($route), 'Phalcon\Mvc\Router\Route');

		$routes = array(
			array(
				'uri' => '/products/save',
				'method' => 'PUT',
				'controller' => 'products',
				'action' => 'save',
				'params' => array()
			),
			array(
				'uri' => '/products/save',
				'method' => 'POST',
				'controller' => 'products',
				'action' => 'save',
				'params' => array()
			),
			array(
				'uri' => '/products/edit/100',
				'method' => 'GET',
				'controller' => 'products',
				'action' => 'edit',
				'params' => array('id' => '100')
			),
			array(
				'uri' => '/products',
				'method' => 'GET',
				'controller' => 'products',
				'action' => 'index',
				'params' => array()
			),
			array(
				'uri' => '/robots/edit/100',
				'method' => 'GET',
				'controller' => 'robots',
				'action' => 'edit',
				'params' => array('id' => '100')
			),
			array(
				'uri' => '/robots',
				'method' => 'GET',
				'controller' => 'robots',
				'action' => 'index',
				'params' => array()
			),
			array(
				'uri' => '/robots/save',
				'method' => 'PUT',
				'controller' => 'robots',
				'action' => 'save',
				'params' => array()
			),
		);

		foreach ($routes as $route) {

			$_SERVER['REQUEST_METHOD'] = $route['method'];
			$router->handle($route['uri']);

			$this->assertEquals($router->getControllerName(), $route['controller']);
			$this->assertEquals($router->getActionName(), $route['action']);
			$this->assertEquals($router->getParams(), $route['params']);
		}
	}

}
