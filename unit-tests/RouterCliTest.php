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
  |          Rack Lin <racklin@gmail.com>                                  |
  +------------------------------------------------------------------------+
*/

class RouterCliTest extends PHPUnit_Framework_TestCase
{

	public function testRouters()
	{

		$di = new \Phalcon\DI\FactoryDefault\CLI();

		$di->set('data', function(){
			return "data";
		});

		$router = new \Phalcon\CLI\Router();

		$router->handle(array());
		$this->assertEquals($router->getModuleName(), null);
		$this->assertEquals($router->getTaskName(), null);
		$this->assertEquals($router->getActionName(), null);
		$this->assertEquals($router->getParams(), array());


		$router->handle(array(
			'task' => 'main'
		));
		$this->assertEquals($router->getModuleName(), null);
		$this->assertEquals($router->getTaskName(), 'main');
		$this->assertEquals($router->getActionName(), null);
		$this->assertEquals($router->getParams(), array());

		$router->handle(array(
			'task' => 'echo'
		));
		$this->assertEquals($router->getModuleName(), null);
		$this->assertEquals($router->getTaskName(), 'echo');
		$this->assertEquals($router->getActionName(), null);
		$this->assertEquals($router->getParams(), array());

		$router->handle(array(
			'task' => 'main',
			'action' => 'hello'
		));
		$this->assertEquals($router->getModuleName(), null);
		$this->assertEquals($router->getTaskName(), 'main');
		$this->assertEquals($router->getActionName(), 'hello');
		$this->assertEquals($router->getParams(), array());

		$router->handle(array(
			'task' => 'main',
			'action' => 'hello',
			'arg1',
			'arg2'
		));
		$this->assertEquals($router->getModuleName(), null);
		$this->assertEquals($router->getTaskName(), 'main');
		$this->assertEquals($router->getActionName(), 'hello');
		$this->assertEquals($router->getParams(), array('arg1', 'arg2'));

		$router->handle(array(
			'module' => 'devtools',
			'task' => 'main',
			'action' => 'hello',
			'arg1',
			'arg2'
		));
		$this->assertEquals($router->getModuleName(), 'devtools');
		$this->assertEquals($router->getTaskName(), 'main');
		$this->assertEquals($router->getActionName(), 'hello');
		$this->assertEquals($router->getParams(), array('arg1', 'arg2'));

		$router->handle(array(
			'module' => 'devtools',
			'task' => 'echo',
			'action' => 'hello',
			'arg1',
			'arg2'
		));
		$this->assertEquals($router->getModuleName(), 'devtools');
		$this->assertEquals($router->getTaskName(), 'echo');
		$this->assertEquals($router->getActionName(), 'hello');
		$this->assertEquals($router->getParams(), array('arg1', 'arg2'));

	}

	private function _runTest($router, $test)
	{
		$router->handle($test['uri']);
		$this->assertEquals($router->getModuleName(), $test['module'], "Testing " . $test['uri']);
		$this->assertEquals($router->getTaskName(), $test['task'], "Testing " . $test['uri']);
		$this->assertEquals($router->getActionName(), $test['action'], "Testing " . $test['uri']);
		$this->assertEquals($router->getParams(), $test['params'], "Testing " . $test['uri']);
	}

	public function testRouter()
	{
		Phalcon\Cli\Router\Route::reset();

		$tests = array(
			array(
				'uri' => '',
				'module' => null,
				'task' => null,
				'action' => null,
				'params' => array()
			),
			array(
				'uri' => ' ',
				'module' => 'devtools',
				'task' => 'main',
				'action' => 'hello',
				'params' => array()
			),
			array(
				'uri' => 'documentation index hellao aaadpqñda bbbAdld cc-ccc',
				'module' => null,
				'task' => 'documentation',
				'action' => 'index',
				'params' => array('hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc')
			),
			array(
				'uri' => ' documentation index',
				'module' => null,
				'task' => 'documentation',
				'action' => 'index',
				'params' => array()
			),
			array(
				'uri' => 'documentation index ',
				'module' => null,
				'task' => 'documentation',
				'action' => 'index',
				'params' => array()
			),
			array(
				'uri' => 'documentation index',
				'module' => null,
				'task' => 'documentation',
				'action' => 'index',
				'params' => array()
			),
			array(
				'uri' => 'documentation ',
				'module' => null,
				'task' => 'documentation',
				'action' => null,
				'params' => array()
			),
			array(
				'uri' => 'system admin a edit hellao aaadp',
				'module' => null,
				'task' => 'admin',
				'action' => 'edit',
				'params' => array('hellao', 'aaadp')
			),
			array(
				'uri' => 'es news',
				'module' => null,
				'task' => 'news',
				'action' => 'index',
				'params' => array('language' => 'es')
			),
			array(
				'uri' => 'admin posts edit 100',
				'module' => 'admin',
				'task' => 'posts',
				'action' => 'edit',
				'params' => array('id' => 100)
			),
			array(
				'uri' => 'posts 2010 02 10 title content',
				'module' => null,
				'task' => 'posts',
				'action' => 'show',
				'params' => array('year' => '2010', 'month' => '02', 'day' => '10', 0 => 'title', 1 => 'content')
			),
			array(
				'uri' => 'manual en translate.adapter.txt',
				'module' => null,
				'task' => 'manual',
				'action' => 'show',
				'params' => array('language' => 'en', 'file' => 'translate.adapter')
			),
			array(
				'uri' => 'named-manual en translate.adapter.txt',
				'module' => null,
				'task' => 'manual',
				'action' => 'show',
				'params' => array('language' => 'en', 'file' => 'translate.adapter')
			),
			array(
				'uri' => 'posts 1999 s le-nice-title',
				'module' => null,
				'task' => 'posts',
				'action' => 'show',
				'params' => array('year' => '1999', 'title' => 'le-nice-title')
			),
			array(
				'uri' => 'feed fr blog diaporema.json',
				'module' => null,
				'task' => 'feed',
				'action' => 'get',
				'params' => array('lang' => 'fr', 'blog' => 'diaporema', 'type' => 'json')
			),
			array(
				'uri' => 'posts delete 150',
				'module' => null,
				'task' => 'posts',
				'action' => 'delete',
				'params' => array('id' => '150')
			),
			array(
				'uri' => 'very static route',
				'module' => null,
				'task' => 'static',
				'action' => 'route',
				'params' => array()
			),
		);

		$router = new \Phalcon\CLI\Router();

		$router->add(' ', array(
			'module' => 'devtools',
			'task' => 'main',
			'action' => 'hello',
		));

		$router->add('system :task a :action :params', array(
			'task' => 1,
			'action' => 2,
			'params' => 3,
		));

		$router->add('([a-z]{2}) :task', array(
			'task' => 2,
			'action' => 'index',
			'language' => 1
		));

		$router->add('admin :task :action :int', array(
			'module' => 'admin',
			'task' => 1,
			'action' => 2,
			'id' => 3
		));

		$router->add('posts ([0-9]{4}) ([0-9]{2}) ([0-9]{2}) :params', array(
			'task' => 'posts',
			'action' => 'show',
			'year' => 1,
			'month' => 2,
			'day' => 3,
			'params' => 4,
		));

		$router->add('manual ([a-z]{2}) ([a-z\.]+)\.txt', array(
			'task' => 'manual',
			'action' => 'show',
			'language' => 1,
			'file' => 2
		));

		$router->add('named-manual {language:([a-z]{2})} {file:[a-z\.]+}\.txt', array(
			'task' => 'manual',
			'action' => 'show',
		));

		$router->add('very static route', array(
			'task' => 'static',
			'action' => 'route'
		));

		$router->add("feed {lang:[a-z]+} blog {blog:[a-z\-]+}\.{type:[a-z\-]+}", "Feed::get");

		$router->add("posts {year:[0-9]+} s {title:[a-z\-]+}", "Posts::show");

		$router->add("posts delete {id}", "Posts::delete");

		$router->add("show {id:video([0-9]+)} {title:[a-z\-]+}", "Videos::show");

		foreach ($tests as $n => $test) {
			$this->_runTest($router, $test);
		}

	}

	public function testRouterParams()
	{

		$router = new Phalcon\Cli\Router();

		$tests = array(
			array(
				'uri' => 'some hattie',
				'module' => null,
				'task' => '',
				'action' => '',
				'params' => array('name' => 'hattie')
			),
			array(
				'uri' => 'some hattie 100',
				'module' => null,
				'task' => '',
				'action' => '',
				'params' => array('name' => 'hattie', 'id' => 100)
			),
			array(
				'uri' => 'some hattie 100 2011-01-02',
				'module' => null,
				'task' => '',
				'action' => '',
				'params' => array('name' => 'hattie', 'id' => 100, 'date' => '2011-01-02')
			),
		);

		$router->add('some {name}');
		$router->add('some {name} {id:[0-9]+}');
		$router->add('some {name} {id:[0-9]+} {date}');

		foreach ($tests as $n => $test) {
			$this->_runTest($router, $test);
		}

	}

	public function testNamedRoutes()
	{

		Phalcon\Cli\Router\Route::reset();

		$router = new Phalcon\Cli\Router(false);

		$usersFind = $router->add('api users find')->setName('usersFind');
		$usersAdd = $router->add('api users add')->setName('usersAdd');

		$this->assertEquals($usersAdd, $router->getRouteByName('usersAdd'));
		$this->assertEquals($usersAdd, $router->getRouteByName('usersAdd'));
		$this->assertEquals($usersFind, $router->getRouteById(0));

	}

	public function testConverters()
	{

		Phalcon\Cli\Router\Route::reset();

		$router = new Phalcon\Cli\Router();

		$router->add('{task:[a-z\-]+} {action:[a-z\-]+} this-is-a-country')
		->convert('task', function($task){
			return str_replace('-', '', $task);
		})
		->convert('action', function($action){
			return str_replace('-', '', $action);
		});

		$router->add('([A-Z]+) ([0-9]+)', array(
			'task' => 1,
			'action' => 'default',
			'id' => 2,
		))
		->convert('task', function($task) {
			return strtolower($task);
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
			'some-controller my-action-name this-is-a-country' => array(
				'task' => 'somecontroller',
				'action' => 'myactionname',
				'params' => array('this-is-a-country')
			),
			'BINARY 1101' => array(
				'task' => 'binary',
				'action' => 'index',
				'params' => array(1011)
			)
		);

		foreach ($routes as $route => $paths) {
			$router->handle($route);
			$this->assertTrue($router->wasMatched());
			$this->assertEquals($paths['task'], $router->getTaskName());
			$this->assertEquals($paths['action'], $router->getActionName());
		}

	}

	public function testShortPaths()
	{
		Phalcon\Cli\Router\Route::reset();

		$router = new Phalcon\Cli\Router(false);

		$route = $router->add("route0", "Feed");
		$this->assertEquals($route->getPaths(), array(
			'task' => 'feed'
		));

		$route = $router->add("route1", "Feed::get");
		$this->assertEquals($route->getPaths(), array(
			'task' => 'feed',
			'action' => 'get',
		));

		$route = $router->add("route2", "News::Posts::show");
		$this->assertEquals($route->getPaths(), array(
			'module' => 'News',
			'task' => 'posts',
			'action' => 'show',
		));

		$route = $router->add("route3", "MyApp\\Tasks\\Posts::show");
		$this->assertEquals($route->getPaths(), array(
			'namespace' => 'MyApp\\Tasks',
			'task' => 'posts',
			'action' => 'show',
		));

		$route = $router->add("route3", "MyApp\\Tasks\\::show");
		$this->assertEquals($route->getPaths(), array(
			'task' => '',
			'action' => 'show',
		));

		$route = $router->add("route3", "News::MyApp\\Tasks\\Posts::show");
		$this->assertEquals($route->getPaths(), array(
			'module' => 'News',
			'namespace' => 'MyApp\\Tasks',
			'task' => 'posts',
			'action' => 'show',
		));

		$route = $router->add("route3", "\\Posts::show");
		$this->assertEquals($route->getPaths(), array(
			'task' => 'posts',
			'action' => 'show',
		));
	}

	public function testBeforeMatch()
	{
		Phalcon\Cli\Router\Route::reset();

		$trace = 0;

		$router = new Phalcon\Cli\Router(false);

		$router
			->add('static route')
			->beforeMatch(function() use (&$trace) {
				$trace++;
				return false;
			});

		$router
			->add('static route2')
			->beforeMatch(function() use (&$trace) {
				$trace++;
				return true;
			});

		$router->handle();
		$this->assertFalse($router->wasMatched());

		$router->handle('static route');
		$this->assertFalse($router->wasMatched());

		$router->handle('static route2');
		$this->assertTrue($router->wasMatched());

		$this->assertEquals($trace, 2);
	}

	public function testDelimiter()
	{
		Phalcon\Cli\Router\Route::reset();
		Phalcon\Cli\Router\Route::delimiter('/');

		$tests = array(
			array(
				'uri' => '/',
				'module' => 'devtools',
				'task' => 'main',
				'action' => 'hello',
				'params' => array()
			),
			array(
				'uri' => '/documentation/index/hellao/aaadpqñda/bbbAdld/cc-ccc',
				'module' => null,
				'task' => 'documentation',
				'action' => 'index',
				'params' => array('hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc')
			),
			array(
				'uri' => '/documentation/index/',
				'module' => null,
				'task' => 'documentation',
				'action' => 'index',
				'params' => array()
			),
			array(
				'uri' => '/documentation/index',
				'module' => null,
				'task' => 'documentation',
				'action' => 'index',
				'params' => array()
			),
			array(
				'uri' => '/documentation/',
				'module' => null,
				'task' => 'documentation',
				'action' => null,
				'params' => array()
			),
			array(
				'uri' => '/system/admin/a/edit/hellao/aaadp',
				'module' => null,
				'task' => 'admin',
				'action' => 'edit',
				'params' => array('hellao', 'aaadp')
			),
			array(
				'uri' => '/es/news',
				'module' => null,
				'task' => 'news',
				'action' => 'index',
				'params' => array('language' => 'es')
			),
			array(
				'uri' => '/admin/posts/edit/100',
				'module' => 'admin',
				'task' => 'posts',
				'action' => 'edit',
				'params' => array('id' => 100)
			),
			array(
				'uri' => '/posts/2010/02/10/title/content',
				'module' => null,
				'task' => 'posts',
				'action' => 'show',
				'params' => array('year' => '2010', 'month' => '02', 'day' => '10', 0 => 'title', 1 => 'content')
			),
			array(
				'uri' => '/manual/en/translate.adapter.txt',
				'module' => null,
				'task' => 'manual',
				'action' => 'show',
				'params' => array('language' => 'en', 'file' => 'translate.adapter')
			),
			array(
				'uri' => '/named-manual/en/translate.adapter.txt',
				'module' => null,
				'task' => 'manual',
				'action' => 'show',
				'params' => array('language' => 'en', 'file' => 'translate.adapter')
			),
			array(
				'uri' => '/posts/1999/s/le-nice-title',
				'module' => null,
				'task' => 'posts',
				'action' => 'show',
				'params' => array('year' => '1999', 'title' => 'le-nice-title')
			),
			array(
				'uri' => '/feed/fr/blog/diaporema.json',
				'module' => null,
				'task' => 'feed',
				'action' => 'get',
				'params' => array('lang' => 'fr', 'blog' => 'diaporema', 'type' => 'json')
			),
			array(
				'uri' => '/posts/delete/150',
				'module' => null,
				'task' => 'posts',
				'action' => 'delete',
				'params' => array('id' => '150')
			),
			array(
				'uri' => '/very/static/route',
				'module' => null,
				'task' => 'static',
				'action' => 'route',
				'params' => array()
			),
		);

		$router = new \Phalcon\CLI\Router();

		$router->add('/', array(
			'module' => 'devtools',
			'task' => 'main',
			'action' => 'hello',
		));

		$router->add('/system/:task/a/:action/:params', array(
			'task' => 1,
			'action' => 2,
			'params' => 3,
		));

		$router->add('/([a-z]{2})/:task', array(
			'task' => 2,
			'action' => 'index',
			'language' => 1
		));

		$router->add('/admin/:task/:action/:int', array(
			'module' => 'admin',
			'task' => 1,
			'action' => 2,
			'id' => 3
		));

		$router->add('/posts/([0-9]{4})/([0-9]{2})/([0-9]{2})/:params', array(
			'task' => 'posts',
			'action' => 'show',
			'year' => 1,
			'month' => 2,
			'day' => 3,
			'params' => 4,
		));

		$router->add('/manual/([a-z]{2})/([a-z\.]+)\.txt', array(
			'task' => 'manual',
			'action' => 'show',
			'language' => 1,
			'file' => 2
		));

		$router->add('/named-manual/{language:([a-z]{2})}/{file:[a-z\.]+}\.txt', array(
			'task' => 'manual',
			'action' => 'show',
		));

		$router->add('/very/static/route', array(
			'task' => 'static',
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

}
