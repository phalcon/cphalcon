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

class SomeComponent
{

	public $someProperty = false;

	public function __construct($value)
	{
		$this->someProperty = $value;
	}

}

class DiTest extends PHPUnit_Framework_TestCase
{

	protected $_di;

	public function setUp()
	{
		Phalcon\DI::reset();
		$this->_di = new \Phalcon\DI();
	}

	public function testSetString()
	{

		$this->_di->set('request1', 'Phalcon\Http\Request');

		$request = $this->_di->get('request1');
		$this->assertEquals(get_class($request), 'Phalcon\Http\Request');
	}

	public function testSetAnonymousFunction()
	{

		$this->_di->set('request2', function(){
			return new Phalcon\Http\Request();
		});

		$request = $this->_di->get('request2');
		$this->assertEquals(get_class($request), 'Phalcon\Http\Request');
	}

	public function testSetArray()
	{

		$this->_di->set('request3', array(
			'className' => 'Phalcon\Http\Request'
		));

		$request = $this->_di->get('request3');
		$this->assertEquals(get_class($request), 'Phalcon\Http\Request');
	}

	public function testAtempt()
	{

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

	public function testHas()
	{

		$this->_di->set('request6', function(){
			return new Phalcon\Http\Request();
		});

		$this->assertTrue($this->_di->has('request6'));
		$this->assertFalse($this->_di->has('request7'));
	}

	public function testShared()
	{

		$this->_di->set('dateObject', function(){
			$object = new stdClass();
			$object->date = microtime(true);
			return $object;
		});

		$dateObject = $this->_di->getShared('dateObject');
		$this->assertEquals(get_class($dateObject), 'stdClass');
		$this->assertTrue($this->_di->wasFreshInstance());

		$dateObject2 = $this->_di->getShared('dateObject');
		$this->assertEquals(get_class($dateObject), 'stdClass');

		$this->assertEquals($dateObject->date, $dateObject2->date);

	}

	public function testMagicCall()
	{

		$this->_di->set('request8', 'Phalcon\Http\Request');

		$request = $this->_di->getRequest8();
		$this->assertEquals(get_class($request), 'Phalcon\Http\Request');

		$this->_di->setRequest9('Phalcon\Http\Request');
		$request = $this->_di->get('request9');
		$this->assertEquals(get_class($request), 'Phalcon\Http\Request');

	}

	public function testParameters()
	{
		$this->_di->set('someComponent1', function($v){
			return new SomeComponent($v);
		});

		$this->_di->set('someComponent2', 'SomeComponent');

		$someComponent1 = $this->_di->get('someComponent1', array(100));
		$this->assertEquals($someComponent1->someProperty, 100);

		$someComponent2 = $this->_di->get('someComponent2', array(50));
		$this->assertEquals($someComponent2->someProperty, 50);
	}

	public function testFactoryDefault()
	{
		$factoryDefault = new Phalcon\DI\FactoryDefault();

		$request = $factoryDefault->get('request');
		$this->assertEquals(get_class($request), 'Phalcon\Http\Request');

		$response = $factoryDefault->get('response');
		$this->assertEquals(get_class($response), 'Phalcon\Http\Response');

		$filter = $factoryDefault->get('filter');
		$this->assertEquals(get_class($filter), 'Phalcon\Filter');

		$url = $factoryDefault->get('url');
		$this->assertEquals(get_class($url), 'Phalcon\Mvc\Url');

		$flash = $factoryDefault->get('flash');
		$this->assertEquals(get_class($flash), 'Phalcon\Flash\Direct');

		$dispatcher = $factoryDefault->get('dispatcher');
		$this->assertEquals(get_class($dispatcher), 'Phalcon\Mvc\Dispatcher');

		$modelsManager = $factoryDefault->get('modelsManager');
		$this->assertEquals(get_class($modelsManager), 'Phalcon\Mvc\Model\Manager');
	}

	public function testStaticDi()
	{
		$di = Phalcon\DI::getDefault();
		$this->assertInstanceOf('Phalcon\DI', $di);
	}

}