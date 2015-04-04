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

	private function _runTest($router, $test)
	{
		$router->handle($test['uri']);
		$this->assertEquals($router->getControllerName(), $test['controller'], "Testing " . $test['uri']);
		$this->assertEquals($router->getActionName(), $test['action'], "Testing " . $test['uri']);
		$this->assertEquals($router->getParams(), $test['params'], "Testing " . $test['uri']);
	}

	public function testRouter()
	{
		Phalcon\Mvc\Router\Route::reset();

		$_GET['_url'] = '';

		$tests = array(
			array(
				'uri' => '',
				'controller' => 'index',
				'action' => 'index',
				'params' => array()
			),
			array(
				'uri' => '/',
				'controller' => 'index',
				'action' => 'index',
				'params' => array()
			),
			array(
				'uri' => '/documentation/index/hellao/aaadpqñda/bbbAdld/cc-ccc',
				'controller' => 'documentation',
				'action' => 'index',
				'params' => array('hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc')
			),
			array(
				'uri' => '/documentation/index/',
				'controller' => 'documentation',
				'action' => 'index',
				'params' => array()
			),
			array(
				'uri' => '/documentation/index',
				'controller' => 'documentation',
				'action' => 'index',
				'params' => array()
			),
			array(
				'uri' => '/documentation/',
				'controller' => 'documentation',
				'action' => null,
				'params' => array()
			),
			array(
				'uri' => '/documentation',
				'controller' => 'documentation',
				'action' => null,
				'params' => array()
			),
			array(
				'uri' => '/system/admin/a/edit/hellao/aaadp',
				'controller' => 'admin',
				'action' => 'edit',
				'params' => array('hellao', 'aaadp')
			),
			array(
				'uri' => '/es/news',
				'controller' => 'news',
				'action' => 'index',
				'params' => array('language' => 'es')
			),
			array(
				'uri' => '/admin/posts/edit/100',
				'controller' => 'posts',
				'action' => 'edit',
				'params' => array('id' => 100)
			),
			array(
				'uri' => '/posts/2010/02/10/title/content',
				'controller' => 'posts',
				'action' => 'show',
				'params' => array('year' => '2010', 'month' => '02', 'day' => '10', 0 => 'title', 1 => 'content')
			),
			array(
				'uri' => '/manual/en/translate.adapter.html',
				'controller' => 'manual',
				'action' => 'show',
				'params' => array('language' => 'en', 'file' => 'translate.adapter')
			),
			array(
				'uri' => '/named-manual/en/translate.adapter.html',
				'controller' => 'manual',
				'action' => 'show',
				'params' => array('language' => 'en', 'file' => 'translate.adapter')
			),
			array(
				'uri' => '/posts/1999/s/le-nice-title',
				'controller' => 'posts',
				'action' => 'show',
				'params' => array('year' => '1999', 'title' => 'le-nice-title')
			),
			array(
				'uri' => '/feed/fr/blog/diaporema.json',
				'controller' => 'feed',
				'action' => 'get',
				'params' => array('lang' => 'fr', 'blog' => 'diaporema', 'type' => 'json')
			),
			array(
				'uri' => '/posts/delete/150',
				'controller' => 'posts',
				'action' => 'delete',
				'params' => array('id' => '150')
			),
			array(
				'uri' => '/very/static/route',
				'controller' => 'static',
				'action' => 'route',
				'params' => array()
			),
		);

		$router = new Phalcon\Mvc\Router();

		$router->add('/', array(
			'controller' => 'index',
			'action' => 'index'
		));

		$router->add('/system/:controller/a/:action/:params', array(
			'controller' => 1,
			'action' => 2,
			'params' => 3,
		));

		$router->add('/([a-z]{2})/:controller', array(
			'controller' => 2,
			'action' => 'index',
			'language' => 1
		));

		$router->add('/admin/:controller/:action/:int', array(
			'controller' => 1,
			'action' => 2,
			'id' => 3
		));

		$router->add('/posts/([0-9]{4})/([0-9]{2})/([0-9]{2})/:params', array(
			'controller' => 'posts',
			'action' => 'show',
			'year' => 1,
			'month' => 2,
			'day' => 3,
			'params' => 4,
		));

		$router->add('/manual/([a-z]{2})/([a-z\.]+)\.html', array(
			'controller' => 'manual',
			'action' => 'show',
			'language' => 1,
			'file' => 2
		));

		$router->add('/named-manual/{language:([a-z]{2})}/{file:[a-z\.]+}\.html', array(
			'controller' => 'manual',
			'action' => 'show',
		));

		$router->add('/very/static/route', array(
			'controller' => 'static',
			'action' => 'route'
		));

		$router->add("/feed/{lang:[a-z]+}/blog/{blog:[a-z\-]+}\.{type:[a-z\-]+}", "Feed::get");

		$router->add("/posts/{year:[0-9]+}/s/{title:[a-z\-]+}", "Posts::show");

		$router->add("/posts/delete/{id}", "Posts::delete");

		$router->add("/show/{id:video([0-9]+)}/{title:[a-z\-]+}", "Videos::show");

		foreach ($tests as $n => $test) {
			$this->_runTest($router, $test);
		}

	}

	public function _testRouterHttp()
	{

		$tests = array(
			array(
				'method' => null,
				'uri' => '/documentation/index/hello',
				'controller' => 'documentation',
				'action' => 'index',
				'params' => array('hello')
			),
			array(
				'method' => 'POST',
				'uri' => '/docs/index',
				'controller' => 'documentation3',
				'action' => 'index',
				'params' => array()
			),
			array(
				'method' => 'GET',
				'uri' => '/docs/index',
				'controller' => 'documentation4',
				'action' => 'index',
				'params' => array()
			),
			array(
				'method' => 'PUT',
				'uri' => '/docs/index',
				'controller' => 'documentation5',
				'action' => 'index',
				'params' => array()
			),
			array(
				'method' => 'DELETE',
				'uri' => '/docs/index',
				'controller' => 'documentation6',
				'action' => 'index',
				'params' => array()
			),
			array(
				'method' => 'OPTIONS',
				'uri' => '/docs/index',
				'controller' => 'documentation7',
				'action' => 'index',
				'params' => array()
			),
			array(
				'method' => 'HEAD',
				'uri' => '/docs/index',
				'controller' => 'documentation8',
				'action' => 'index',
				'params' => array()
			),
		);

		$di = new Phalcon\DI();

		$di->set('request', function(){
			return new Phalcon\Http\Request();
		});

		$router = new Phalcon\Mvc\Router();
		$router->setDI($di);

		$router->add('/docs/index', array(
			'controller' => 'documentation2',
			'action' => 'index'
		));

		$router->addPost('/docs/index', array(
			'controller' => 'documentation3',
			'action' => 'index'
		));

		$router->addGet('/docs/index', array(
			'controller' => 'documentation4',
			'action' => 'index'
		));

		$router->addPut('/docs/index', array(
			'controller' => 'documentation5',
			'action' => 'index'
		));

		$router->addDelete('/docs/index', array(
			'controller' => 'documentation6',
			'action' => 'index'
		));

		$router->addOptions('/docs/index', array(
			'controller' => 'documentation7',
			'action' => 'index'
		));

		$router->addHead('/docs/index', array(
			'controller' => 'documentation8',
			'action' => 'index'
		));

		foreach ($tests as $n => $test) {
			$_SERVER['REQUEST_METHOD'] = $test['method'];
			$this->_runTest($router, $test);
		}
	}

	public function testRouterParams()
	{

		$router = new Phalcon\Mvc\Router();

		$tests = array(
			array(
				'method' => null,
				'uri' => '/some/hattie',
				'controller' => '',
				'action' => '',
				'params' => array('name' => 'hattie')
			),
			array(
				'method' => null,
				'uri' => '/some/hattie/100',
				'controller' => '',
				'action' => '',
				'params' => array('name' => 'hattie', 'id' => 100)
			),
			array(
				'method' => null,
				'uri' => '/some/hattie/100/2011-01-02',
				'controller' => '',
				'action' => '',
				'params' => array('name' => 'hattie', 'id' => 100, 'date' => '2011-01-02')
			),
		);

		$router->add('/some/{name}');
		$router->add('/some/{name}/{id:[0-9]+}');
		$router->add('/some/{name}/{id:[0-9]+}/{date}');

		foreach ($tests as $n => $test) {
			$this->_runTest($router, $test);
		}

	}

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

	public function testNotFoundPaths()
	{
		Phalcon\Mvc\Router\Route::reset();

		$router = new Phalcon\Mvc\Router(false);

		$router->add('/static/route');

		$router->notFound(array(
			'module' => 'module',
			'namespace' => 'namespace',
			'controller' => 'controller',
			'action' => 'action'
		));

		$router->handle();

		$this->assertEquals($router->getControllerName(), 'controller');
		$this->assertEquals($router->getActionName(), 'action');
		$this->assertEquals($router->getModuleName(), 'module');
		$this->assertEquals($router->getNamespaceName(), 'namespace');

	}

	public function testUriSource()
	{
		Phalcon\Mvc\Router\Route::reset();

		$_GET['_url'] = '/some/route';

		$router = new Phalcon\Mvc\Router(false);

		$this->assertEquals($router->getRewriteUri(), '/some/route');

		$router->setUriSource(Phalcon\Mvc\Router::URI_SOURCE_GET_URL);

		$this->assertEquals($router->getRewriteUri(), '/some/route');

		$router->setUriSource(Phalcon\Mvc\Router::URI_SOURCE_SERVER_REQUEST_URI);

		$_SERVER['REQUEST_URI'] = '/some/route';

		$this->assertEquals($router->getRewriteUri(), '/some/route');

		$_SERVER['REQUEST_URI'] = '/some/route?x=1';

		$this->assertEquals($router->getRewriteUri(), '/some/route');
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

	public function testHostnameRouter()
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

		$router->add('/edit', array(
			'controller' => 'posts',
			'action' => 'edit'
		))->setHostname('my.phalconphp.com');

		$router->add('/edit', array(
			'controller' => 'posts2',
			'action' => 'edit2'
		))->setHostname('my2.phalconphp.com');

		$routes = array(
			array(
				'hostname' => 'localhost',
				'controller' => 'posts3'
			),
			array(
				'hostname' => 'my.phalconphp.com',
				'controller' => 'posts'
			),
			array(
				'hostname' => null,
				'controller' => 'posts3'
			),
			array(
				'hostname' => 'my2.phalconphp.com',
				'controller' => 'posts2'
			),
		);

		foreach ($routes as $route) {
			$_SERVER['HTTP_HOST'] = $route['hostname'];
			$router->handle('/edit');
			$this->assertEquals($router->getControllerName(), $route['controller']);
		}

	}

	public function _testHostnameRegexRouter()
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

		$router->add('/edit', array(
			'controller' => 'posts',
			'action' => 'edit'
		))->setHostname('([a-z]+).phalconphp.com');

		$router->add('/edit', array(
			'controller' => 'posts2',
			'action' => 'edit2'
		))->setHostname('mail.([a-z]+).com');

		$routes = array(
			array(
				'hostname' => 'localhost',
				'controller' => 'posts3'
			),
			array(
				'hostname' => 'my.phalconphp.com',
				'controller' => 'posts'
			),
			array(
				'hostname' => null,
				'controller' => 'posts3'
			),
			array(
				'hostname' => 'my.mail.com',
				'controller' => 'posts2'
			),
		);

		foreach ($routes as $route) {
			$_SERVER['HTTP_HOST'] = $route['hostname'];
			$router->handle('/edit');
			$this->assertEquals($router->getControllerName(), $route['controller']);
		}

	}

	public function testHostnameRouteGroup()
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

		$routes = array(
			array(
				'hostname' => 'localhost',
				'controller' => 'posts3'
			),
			array(
				'hostname' => 'my.phalconphp.com',
				'controller' => 'posts'
			),
			array(
				'hostname' => null,
				'controller' => 'posts3'
			)
		);

		foreach ($routes as $route) {
			$_SERVER['HTTP_HOST'] = $route['hostname'];
			$router->handle('/edit');
			$this->assertEquals($router->getControllerName(), $route['controller']);
		}
	}

	public function testHostnameRegexRouteGroup()
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

		$routes = array(
			array(
				'hostname' => 'localhost',
				'controller' => 'posts3'
			),
			array(
				'hostname' => 'my.phalconphp.com',
				'controller' => 'posts'
			),
			array(
				'hostname' => null,
				'controller' => 'posts3'
			)
		);

		foreach ($routes as $route) {
			$_SERVER['HTTP_HOST'] = $route['hostname'];
			$router->handle('/edit');
			$this->assertEquals($router->getControllerName(), $route['controller']);
		}
	}

}
