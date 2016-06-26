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

class RouterMvcTest extends PHPUnit_Framework_TestCase
{
	public function testGroups()
	{
		Phalcon\Mvc\Router\Route::reset();

		$router = new Phalcon\Mvc\Router(false);

		$blog = new Phalcon\Mvc\Router\Group(array(
			'module' => 'blog',
			'controller' => 'index'
		));

		$blog->setPrefix('/blog');

		$blog->add('/save', array(
			'action' => 'save'
		));

		$blog->add('/edit/{id}', array(
			'action' => 'edit'
		));

		$blog->add('/about', array(
			'controller' => 'about',
			'action' => 'index'
		));

		$router->mount($blog);

		$routes = array(
			'/blog/save' => array(
				'module' => 'blog',
				'controller' => 'index',
				'action' => 'save',
			),
			'/blog/edit/1' => array(
				'module' => 'blog',
				'controller' => 'index',
				'action' => 'edit'
			),
			'/blog/about' => array(
				'module' => 'blog',
				'controller' => 'about',
				'action' => 'index'
			),
		);

		foreach ($routes as $route => $paths) {
			$router->handle($route);
			$this->assertTrue($router->wasMatched());
			$this->assertEquals($paths['module'], $router->getModuleName());
			$this->assertEquals($paths['controller'], $router->getControllerName());
			$this->assertEquals($paths['action'], $router->getActionName());
			$this->assertEquals($blog, $router->getMatchedRoute()->getGroup());
		}
	}

	/**
	 * @dataProvider hostnamedRoutesProvider
	 */
	public function testHostnameRouteGroup($actualHost, $expectedHost, $controller)
	{
		Phalcon\Mvc\Router\Route::reset();

		$di = new Phalcon\DI();

		$di->set('request', function(){
			return new Phalcon\Http\Request();
		});

		$router = new Phalcon\Mvc\Router(false);

		$router->setDI($di);

		$router->add('/edit', array(
			'controller' => 'posts3',
			'action' => 'edit3'
		));

		$group = new Phalcon\Mvc\Router\Group();

		$group->setHostname('my.phalconphp.com');

		$group->add('/edit', array(
			'controller' => 'posts',
			'action' => 'edit'
		));

		$router->mount($group);

		$_SERVER['HTTP_HOST'] = $actualHost;
		$router->handle('/edit');
		$this->assertEquals($router->getControllerName(), $controller);
		$this->assertEquals($router->getMatchedRoute()->getHostname(), $expectedHost);
	}

	/**
	 * @dataProvider hostnamedRegexRoutesProvider
	 */
	public function testHostnameRegexRouteGroup($actualHost, $expectedHost, $controller)
	{
		Phalcon\Mvc\Router\Route::reset();

		$di = new Phalcon\DI();

		$di->set('request', function(){
			return new Phalcon\Http\Request();
		});

		$router = new Phalcon\Mvc\Router(false);

		$router->setDI($di);

		$router->add('/edit', array(
			'controller' => 'posts3',
			'action' => 'edit3'
		));

		$group = new Phalcon\Mvc\Router\Group();

		$group->setHostname('([a-z]+).phalconphp.com');

		$group->add('/edit', array(
			'controller' => 'posts',
			'action' => 'edit'
		));

		$router->mount($group);

		$_SERVER['HTTP_HOST'] = $actualHost;
		$router->handle('/edit');
		$this->assertEquals($router->getControllerName(), $controller);
		$this->assertEquals($router->getMatchedRoute()->getHostname(), $expectedHost);
	}

	public function hostnamedRegexRoutesProvider()
	{
		return array(
			array('localhost', null, 'posts3'),
			array('my.phalconphp.com', '([a-z]+).phalconphp.com', 'posts'),
			array(null, null, 'posts3'),
		);
	}

	public function hostnamedRoutesProvider()
	{
		return array(
			array('localhost', null, 'posts3'),
			array('my.phalconphp.com', 'my.phalconphp.com', 'posts'),
			array(null, null, 'posts3'),
		);
	}
}
