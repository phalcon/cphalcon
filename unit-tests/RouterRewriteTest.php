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

class RouterRewriteTest extends PHPUnit_Framework_TestCase {

	private function _runTest($router, $test){
		
		if($test['type']=='handle'){
			if(isset($test['url'])){
				$_GET['_url'] = $test['url'];
			} else {
				unset($_GET['_url']);
			}
			$router->handle();
		}

		if(isset($test['controller'])){		
			$this->assertEquals($router->getControllerName(), $test['controller']);		
		}

		if(isset($test['action'])){		
			$this->assertEquals($router->getActionName(), $test['action']);		
		}
	}

	public function testRouter(){

		$tests = array(
			array(
				'name' => 'No uri route info',
				'type' => 'handle',
				'controller' => null,
				'action' => null,
				'params' => array()
			),
			array(
				'name' => 'Route info /controller',
				'type' => 'handle',
				'url' => 'controller',
				'controller' => 'controller',
				'action' => null,
				'params' => array()
			),
			array(
				'name' => 'Route info /controller/index',
				'type' => 'handle',
				'url' => 'controller/index',
				'controller' => 'controller',
				'action' => 'index',
				'params' => array()
			),
			array(
				'name' => 'Route info /controller/index/p1',
				'type' => 'handle',
				'url' => 'controller/index/p1',
				'controller' => 'controller',
				'action' => 'index',
				'params' => array('p1')
			),
			array(
				'name' => 'Route info /controller/index/p1/param2',
				'type' => 'handle',
				'url' => 'controller/index/p1/param2',
				'controller' => 'controller',
				'action' => 'index',
				'params' => array('p1', 'param2')
			),
			array(
				'name' => 'Route info /controller/lol',
				'type' => 'handle',
				'url' => 'controller/lol',
				'controller' => 'controller',
				'action' => 'lol',
				'params' => array()
			),
			array(
				'name' => 'Route info /controller//p1',
				'type' => 'handle',
				'url' => 'controller//p1',
				'controller' => 'controller',
				'action' => null,
				'params' => array('p1')
			),
			array(
				'name' => 'Route info ///p1',
				'type' => 'handle',
				'url' => '///p1',
				'controller' => null,
				'action' => null,
				'params' => array('p1')
			),
			array(
				'name' => 'Route info /controller0/index1',
				'type' => 'handle',
				'url' => 'controller0/index1',
				'controller' => 'controller0',
				'action' => 'index1',
				'params' => array()
			),
		);

		foreach($tests as $test){
			$router = new Phalcon_Router_Rewrite();
			$this->_runTest($router, $test);		
		}	

	}
	
}
