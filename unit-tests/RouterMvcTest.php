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
	public function testNamedRoutes()
	{

		Phalcon\Mvc\Router\Route::reset();

		$router = new Phalcon\Mvc\Router(false);

		$usersFind = $router->add('/api/users/find')->setHttpMethods('GET')->setName('usersFind');
		$usersAdd = $router->add('/api/users/add')->setHttpMethods('POST')->setName('usersAdd');

		$this->assertEquals($usersAdd, $router->getRouteByName('usersAdd'));
		//second check when the same route goes from name lookup
		$this->assertEquals($usersAdd, $router->getRouteByName('usersAdd'));
		$this->assertEquals($usersFind, $router->getRouteById(0));

	}

	public function testExtraSlashes()
	{

		Phalcon\Mvc\Router\Route::reset();

		$router = new Phalcon\Mvc\Router();

		$router->removeExtraSlashes(true);

		$routes = array(
			'/index/' => array(
				'controller' => 'index',
				'action' => '',
			),
			'/session/start/' => array(
				'controller' => 'session',
				'action' => 'start'
			),
			'/users/edit/100/' => array(
				'controller' => 'users',
				'action' => 'edit'
			),
		);

		foreach ($routes as $route => $paths) {
			$router->handle($route);
			$this->assertTrue($router->wasMatched());
			$this->assertEquals($paths['controller'], $router->getControllerName());
			$this->assertEquals($paths['action'], $router->getActionName());
		}

	}

	public function testConverters()
	{

		Phalcon\Mvc\Router\Route::reset();

		$router = new Phalcon\Mvc\Router();

		$router->add('/{controller:[a-z\-]+}/{action:[a-z\-]+}/this-is-a-country')
		->convert('controller', function($controller){
			return str_replace('-', '', $controller);
		})
		->convert('action', function($action){
			return str_replace('-', '', $action);
		});

		$router->add('/([A-Z]+)/([0-9]+)', array(
			'controller' => 1,
			'action' => 'default',
			'id' => 2,
		))
		->convert('controller', function($controller) {
			return strtolower($controller);
		})
		->convert('action', function($action) {
			if ($action == 'default') {
				return 'index';
			}
			return $action;
		})
		->convert('id', function($id) {
			return strrev($id);
		});

		$routes = array(
			'/some-controller/my-action-name/this-is-a-country' => array(
				'controller' => 'somecontroller',
				'action' => 'myactionname',
				'params' => array('this-is-a-country')
			),
			'/BINARY/1101' => array(
				'controller' => 'binary',
				'action' => 'index',
				'params' => array(1011)
			)
		);

		foreach ($routes as $route => $paths) {
			$router->handle($route);
			$this->assertTrue($router->wasMatched());
			$this->assertEquals($paths['controller'], $router->getControllerName());
			$this->assertEquals($paths['action'], $router->getActionName());
		}

	}

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

	public function testShortPaths()
	{
		Phalcon\Mvc\Router\Route::reset();

		$router = new Phalcon\Mvc\Router(false);

		$route = $router->add("/route0", "Feed");
		$this->assertEquals($route->getPaths(), array(
			'controller' => 'feed'
		));

		$route = $router->add("/route1", "Feed::get");
		$this->assertEquals($route->getPaths(), array(
			'controller' => 'feed',
			'action' => 'get',
		));

		$route = $router->add("/route2", "News::Posts::show");
		$this->assertEquals($route->getPaths(), array(
			'module' => 'News',
			'controller' => 'posts',
			'action' => 'show',
		));

		$route = $router->add("/route3", "MyApp\\Controllers\\Posts::show");
		$this->assertEquals($route->getPaths(), array(
			'namespace' => 'MyApp\\Controllers',
			'controller' => 'posts',
			'action' => 'show',
		));

		$route = $router->add("/route3", "MyApp\\Controllers\\::show");
		$this->assertEquals($route->getPaths(), array(
			'controller' => '',
			'action' => 'show',
		));

		$route = $router->add("/route3", "News::MyApp\\Controllers\\Posts::show");
		$this->assertEquals($route->getPaths(), array(
			'module' => 'News',
			'namespace' => 'MyApp\\Controllers',
			'controller' => 'posts',
			'action' => 'show',
		));

		$route = $router->add("/route3", "\\Posts::show");
		$this->assertEquals($route->getPaths(), array(
			'controller' => 'posts',
			'action' => 'show',
		));
	}

	public function testBeforeMatch()
	{
		Phalcon\Mvc\Router\Route::reset();

		$trace = 0;

		$router = new Phalcon\Mvc\Router(false);

		$router
			->add('/static/route')
			->beforeMatch(function() use (&$trace) {
				$trace++;
				return false;
			});

		$router
			->add('/static/route2')
			->beforeMatch(function() use (&$trace) {
				$trace++;
				return true;
			});

		$router->handle();
		$this->assertFalse($router->wasMatched());

		$router->handle('/static/route');
		$this->assertFalse($router->wasMatched());

		$router->handle('/static/route2');
		$this->assertTrue($router->wasMatched());

		$this->assertEquals($trace, 2);
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
