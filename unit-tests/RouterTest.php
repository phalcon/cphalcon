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

class RouterTest extends PHPUnit_Framework_TestCase
{

	private function _runTest($router, $test)
	{
		$router->handle($test['uri']);
		$this->assertEquals($router->getControllerName(), $test['controller']);
		$this->assertEquals($router->getActionName(), $test['action']);
		$this->assertEquals($router->getParams(), $test['params']);
	}

	public function testRouter()
	{

		$tests = array(
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

		$router->add('/very/static/route', array(
			'controller' => 'static',
			'action' => 'route'
		));

		$router->add("/feed/{lang:[a-z]+}/blog/{blog:[a-z\-]+}\.{type:[a-z\-]+}", "Feed::get");

		$router->add("/posts/{year:[0-9]+}/s/{title:[a-z\-]+}", "Posts::show");

		$router->add("/posts/delete/{id}", "Posts::delete");

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
		$this->assertEquals($usersFind, $router->getRouteById(0));

	}

}
