<?php

/*
	+------------------------------------------------------------------------+
	| Phalcon Framework                                                      |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
    |          ZhuZongXin <dreamsxin@qq.com>                                 |
	+------------------------------------------------------------------------+
*/

class UrlTest extends PHPUnit_Framework_TestCase
{
	public function testUrl()
	{
		Phalcon\DI::reset();

		//Create a default DI
		$di = new Phalcon\DI();
		
		$di['router'] = function() {
			$router = new \Phalcon\Mvc\Router(FALSE);
			$router->add('/:controller/:action', array(
				'controller' => 1,
				'action' => 2
			))->setHostName('phalconphp.com')->setName('test');
			return $router;
		};

		$di->set('url', function(){
			$url = new Phalcon\Mvc\Url();
			$url->setBaseUri('/');
			return $url;
		});

		$url = $di->url->get(array('for' => 'test', 'hostname' => true, 'controller' => 'index', 'action' => 'test'));
		$this->assertEquals($url, 'phalconphp.com/index/test');
	}
}
