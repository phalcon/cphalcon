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

class UrlTest extends PHPUnit_Framework_TestCase
{

	protected function _getDI()
	{

		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('router', function(){
			$router = new Phalcon\Mvc\Router(false);

			$router->add('/admin/:controller/p/:action')->setName('adminProducts');

			$router->add('/api/classes/{class}')->setName('classApi');

			$router->add('/{year}/{month}/{title}')->setName('blogPost');

			$router->add('/wiki/{article:[a-z]+}')->setName('wikipedia');

			return $router;
		});

		return $di;
	}

	public function testUrl()
	{

		$_SERVER['PHP_SELF'] = '/index.php';

		$url = new Phalcon\Mvc\Url();

		$this->assertEquals($url->get(), '/');
		$this->assertEquals($url->get('classes/api/Some'), '/classes/api/Some');

	}

	public function testUrlFor()
	{

		$url = new Phalcon\Mvc\Url();

		$url->setDI($this->_getDI());

		$routes = array(
			array(
				'paths' => array(
					'for' => 'adminProducts',
					'controller' => 'products',
					'action' => 'index'
				),
				'url' => '/admin/products/p/index'
			),
			array(
				'paths' => array(
					'for' => 'classApi',
					'class' => 'Some',
				),
				'url' => '/api/classes/Some'
			),
			array(
				'paths' => array(
					'for' => 'blogPost',
					'year' => '2010',
					'month' => '10',
					'title' => 'cloudflare-anade-recursos-a-tu-servidor',
				),
				'url' => '/2010/10/cloudflare-anade-recursos-a-tu-servidor'
			),
			array(
				'paths' => array(
					'for' => 'wikipedia',
					'article' => 'Television_news'
				),
				'url' => '/wiki/Television_news'
			)
		);

		foreach($routes as $route){
			$this->assertEquals($url->get($route['paths']), $route['url']);
		}

	}

}
