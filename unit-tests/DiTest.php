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

class DiTest extends PHPUnit_Framework_TestCase {

	protected $_di;

	public function setUp(){
		$this->_di = new \Phalcon\DI();
	}

	public function testSetString(){

		$this->_di->set('request1', 'Phalcon\Http\Request');

		$request = $this->_di->get('request1');
		$this->assertEquals(get_class($request), 'Phalcon\Http\Request');
	}

	public function testSetAnonymousFunction(){

		$this->_di->set('request2', function(){
			return new Phalcon\Http\Request();
		});

		$request = $this->_di->get('request2');
		$this->assertEquals(get_class($request), 'Phalcon\Http\Request');
	}

	public function testSetArray(){

		$this->_di->set('request3', array(
			'className' => 'Phalcon\Http\Request'
		));

		$request = $this->_di->get('request3');
		$this->assertEquals(get_class($request), 'Phalcon\Http\Request');
	}

	public function testAtempt(){

		$this->_di->set('request4', function(){
			return new Phalcon\Http\Request();
		});

		$this->_di->attempt('request4', function(){
			return new stdClass();
		});

		$this->_di->attempt('request5', function(){
			return new stdClass();
		});

		$request = $this->_di->get('request4');
		$this->assertEquals(get_class($request), 'Phalcon\Http\Request');

		$request = $this->_di->get('request5');
		$this->assertEquals(get_class($request), 'stdClass');

	}

	public function testHas(){

		$this->_di->set('request6', function(){
			return new Phalcon\Http\Request();
		});

		$this->assertTrue($this->_di->has('request6'));
		$this->assertFalse($this->_di->has('request7'));
	}

	public function testShared(){

		$this->_di->set('dateObject', function(){
			$object = new stdClass();
			$object->date = microtime(true);
			return $object;
		});

		$dateObject = $this->_di->getShared('dateObject');
		$this->assertEquals(get_class($dateObject), 'stdClass');

		$dateObject2 = $this->_di->getShared('dateObject');
		$this->assertEquals(get_class($dateObject), 'stdClass');

		$this->assertEquals($dateObject->date, $dateObject2->date);

	}

	public function testMagicCall(){

		$this->_di->set('request8', 'Phalcon\Http\Request');

		$request = $this->_di->getRequest8();
		$this->assertEquals(get_class($request), 'Phalcon\Http\Request');
	}

}