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

use Phalcon\Controller\Front as ControllerFront;
use Phalcon\Config as Config;

class ControllerFrontTest extends PHPUnit_Framework_TestCase {

	public function testControllerNoDbFront(){

		ControllerFront::reset();

		$config = new Config(array(
			'phalcon' => array(
				'controllersDir' => 'unit-tests/controllers/',
				'modelsDir' => 'unit-tests/models/',
				'viewsDir' => 'unit-tests/views/',
				'basePath' => './'
			)
		));

		$front = ControllerFront::getInstance();

		$_GET['_url'] = 'test3/other';

		$front->setConfig($config);
		$response = $front->dispatchLoop();

		$this->assertEquals($response->getContent(), '<html>lolhere</html>'."\n");

	}

	public function testControllerDbFront(){

		ControllerFront::reset();

		$config = new Config(array(
			'database' => array(
				'adapter' => 'Mysql',
				'host' => '127.0.0.1',
				'username' => 'root',
				'password' => '',
				'name' => 'phalcon_test'
			),
			'phalcon' => array(
				'controllersDir' => 'unit-tests/controllers/',
				'modelsDir' => 'unit-tests/models/',
				'viewsDir' => 'unit-tests/views/',
				'basePath' => './'
			)
		));

		$front = ControllerFront::getInstance();

		$_GET['_url'] = 'test3/query';
		$front->setConfig($config);
		$response = $front->dispatchLoop();

		$this->assertEquals($response->getContent(), '<html>lolRobotina</html>'."\n");

	}

	public function testControllerRouterRewriteFront(){

		ControllerFront::reset();

		$config = new Config(array(
			'phalcon' => array(
				'controllersDir' => 'unit-tests/controllers/',
				'modelsDir' => 'unit-tests/models/',
				'viewsDir' => 'unit-tests/views/',
				'basePath' => './'
			)
		));

		$front = ControllerFront::getInstance();

		$router = new Phalcon\Router\Rewrite();

		$router->handle('test3/coolVar');

		$front->setRouter($router);
		$front->setConfig($config);

		$response = $front->dispatchLoop();

		$this->assertEquals($response->getContent(), '<html>lol<p>got-the-life</p></html>'."\n");

	}

	public function testControllerRouterRegexFront(){

		ControllerFront::reset();

		$config = new Config(array(
			'phalcon' => array(
				'controllersDir' => 'unit-tests/controllers/',
				'modelsDir' => 'unit-tests/models/',
				'viewsDir' => 'unit-tests/views/',
				'basePath' => './'
			)
		));

		$front = ControllerFront::getInstance();

		$router = new Phalcon\Router\Regex();

		$router->handle('/test3/coolVar');

		$front->setRouter($router);
		$front->setConfig($config);

		$response = $front->dispatchLoop();

		$this->assertEquals($response->getContent(), '<html>lol<p>got-the-life</p></html>'."\n");

	}

}
