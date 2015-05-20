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

class InjectableComponent
{
	public $response;

	public $other;

	public function __construct($response=null)
	{
		$this->response = $response;
	}

	public function setResponse($response)
	{
		$this->response = $response;
	}

	public function getResponse()
	{
		return $this->response;
	}
}

class SimpleComponent
{

}

class SomeComponent
{

	public $someProperty = false;

	public function __construct($value)
	{
		$this->someProperty = $value;
	}

}

class Service1242
{
}

class DiTest extends PHPUnit_Framework_TestCase
{

	protected $_di;

	public function setUp()
	{
		Phalcon\Di::reset();
		$this->_di = new \Phalcon\Di();
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

	public function testGetServices()
	{

		$expectedServices = array(
			'service1' => Phalcon\Di\Service::__set_state(array(
				'_name' => 'service1',
				'_definition' => 'some-service',
				'_shared' => false,
				'_sharedInstance' => NULL,
			)),
			'service2' => Phalcon\Di\Service::__set_state(array(
				'_name' => 'service2',
				'_definition' => 'some-other-service',
				'_shared' => false,
				'_sharedInstance' => NULL,
			))
		);

		$this->_di->set('service1', 'some-service');
		$this->_di->set('service2', 'some-other-service');
		$this->assertEquals($this->_di->getServices(), $expectedServices);
	}

	public function testGetRawService()
	{
		$this->_di->set('service1', 'some-service');
		$this->assertEquals($this->_di->getRaw('service1'), 'some-service');
	}

	public function testArrayAccess()
	{
		$this->_di['simple'] = 'SimpleComponent';
		$this->assertEquals(get_class($this->_di['simple']), 'SimpleComponent');
	}

	public function testComplexInjection()
	{

		$response = new Phalcon\Http\Response();
		$this->_di->set('response', $response);

		//Injection of parameters in the constructor
		$this->_di->set('simpleConstructor',
			array(
				'className' => 'InjectableComponent',
				'arguments' => array(
					array('type' => 'parameter', 'value' => 'response')
				)
			)
		);

		//Injection of simple setters
		$this->_di->set('simpleSetters',
			array(
				'className' => 'InjectableComponent',
				'calls' => array(
					array(
						'method' => 'setResponse',
						'arguments' => array(
							array('type' => 'parameter', 'value' => 'response'),
						)
					),
				)
			)
		);

		//Injection of properties
		$this->_di->set('simpleProperties',
			array(
				'className' => 'InjectableComponent',
				'properties' => array(
					array(
						'name' => 'response', 'value' => array('type' => 'parameter', 'value' => 'response')
					),
				)
			)
		);

		//Injection of parameters in the constructor resolving the service parameter
		$this->_di->set('complexConstructor',
			array(
				'className' => 'InjectableComponent',
				'arguments' => array(
					array('type' => 'service', 'name' => 'response')
				)
			)
		);

		//Injection of simple setters resolving the service parameter
		$this->_di->set('complexSetters',
			array(
				'className' => 'InjectableComponent',
				'calls' => array(
					array(
						'method' => 'setResponse',
						'arguments' => array(
							array('type' => 'service', 'name' => 'response')
						)
					),
				)
			)
		);

		//Injection of properties resolving the service parameter
		$this->_di->set('complexProperties',
			array(
				'className' => 'InjectableComponent',
				'properties' => array(
					array(
						'name' => 'response', 'value' => array('type' => 'service', 'name' => 'response')
					),
				)
			)
		);

		$component = $this->_di->get('simpleConstructor');
		$this->assertTrue(is_string($component->getResponse()));
		$this->assertEquals($component->getResponse(), 'response');

		$component = $this->_di->get('simpleSetters');
		$this->assertTrue(is_string($component->getResponse()));
		$this->assertEquals($component->getResponse(), 'response');

		$component = $this->_di->get('simpleProperties');
		$this->assertTrue(is_string($component->getResponse()));
		$this->assertEquals($component->getResponse(), 'response');

		$component = $this->_di->get('complexConstructor');
		$this->assertTrue(is_object($component->getResponse()));
		$this->assertEquals($component->getResponse(), $response);

		$component = $this->_di->get('complexSetters');
		$this->assertTrue(is_object($component->getResponse()));
		$this->assertEquals($component->getResponse(), $response);

		$component = $this->_di->get('complexProperties');
		$this->assertTrue(is_object($component->getResponse()));
		$this->assertEquals($component->getResponse(), $response);
	}

	public function testFactoryDefault()
	{
		$factoryDefault = new Phalcon\Di\FactoryDefault();

		$request = $factoryDefault->get('request');
		$this->assertEquals(get_class($request), 'Phalcon\Http\Request');

		$response = $factoryDefault->get('response');
		$this->assertEquals(get_class($response), 'Phalcon\Http\Response');

		$filter = $factoryDefault->get('filter');
		$this->assertEquals(get_class($filter), 'Phalcon\Filter');

		$escaper = $factoryDefault->get('escaper');
		$this->assertEquals(get_class($escaper), 'Phalcon\Escaper');

		$url = $factoryDefault->get('url');
		$this->assertEquals(get_class($url), 'Phalcon\Mvc\Url');

		$flash = $factoryDefault->get('flash');
		$this->assertEquals(get_class($flash), 'Phalcon\Flash\Direct');

		$dispatcher = $factoryDefault->get('dispatcher');
		$this->assertEquals(get_class($dispatcher), 'Phalcon\Mvc\Dispatcher');

		$modelsManager = $factoryDefault->get('modelsManager');
		$this->assertEquals(get_class($modelsManager), 'Phalcon\Mvc\Model\Manager');

		$modelsMetadata = $factoryDefault->get('modelsMetadata');
		$this->assertEquals(get_class($modelsMetadata), 'Phalcon\Mvc\Model\MetaData\Memory');

		$router = $factoryDefault->get('router');
		$this->assertEquals(get_class($router), 'Phalcon\Mvc\Router');

		$session = $factoryDefault->get('session');
		$this->assertEquals(get_class($session), 'Phalcon\Session\Adapter\Files');

		$security = $factoryDefault->get('security');
		$this->assertEquals(get_class($security), 'Phalcon\Security');

	}

	public function testStaticDi()
	{
		$di = Phalcon\Di::getDefault();
		$this->assertInstanceOf('Phalcon\Di', $di);
	}

	public function testCrash()
	{
		$di = new Phalcon\Di\FactoryDefault();
		$bag = $di->get('sessionBag', array('dummy'));
		$this->assertTrue(true);
	}

    	/**
     	* Prior to 2.0.0 exception message was "Service 'servicewhichdoesnotexist' wasn't found in the dependency injection container"
     	*
     	* @expectedException \Phalcon\Di\Exception
     	* @expectedExceptionMessage Service 'servicewhichdoesnotexist' wasn't found in the dependency injection container
     	*/
    	public function testGettingNonExistentServiceShouldThrowExceptionWithExpectedMessage()
    	{
        	$di = new \Phalcon\DI\FactoryDefault();
        	$di->get('servicewhichdoesnotexist');
    	}

	public function testIssue1242()
	{
		$di = new \Phalcon\Di();
		$di->set('resolved', function() { return new Service1242(); });
		$di->set('notresolved', function() { return new Service1242(); });

		$this->assertFalse($di->getService('resolved')->isResolved());
		$this->assertFalse($di->getService('notresolved')->isResolved());

		$di->get('resolved');

		$this->assertTrue($di->getService('resolved')->isResolved());
		$this->assertFalse($di->getService('notresolved')->isResolved());
	}
}
