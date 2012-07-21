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

class RouterRegexTest extends PHPUnit_Framework_TestCase {

	private function _runTest($router, $test){
		$router->handle($test['uri']);
		$this->assertEquals($router->getControllerName(), $test['controller']);
		$this->assertEquals($router->getActionName(), $test['action']);
		$this->assertEquals($router->getParams(), $test['params']);
	}

	public function testRouter(){

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
			)
		);

		$router = new Phalcon\Router\Regex();

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

		$router->add("/feed/{lang:[a-z]+}/blog/{blog:[a-z\-]+}\.{type:[a-z\-]+}", "Feed::get");

		$router->add("/posts/{year:[0-9]+}/s/{title:[a-z\-]+}", "Posts::show");

		foreach($tests as $n => $test){
			$this->_runTest($router, $test);
		}

	}

}
