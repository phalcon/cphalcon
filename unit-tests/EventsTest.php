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

class LeDummyComponent
{

	protected $_eventsManager;

	public function setEventsManager($eventsManager)
	{
		$this->_eventsManager = $eventsManager;
	}

	public function getEventsManager()
	{
		return $this->_eventsManager;
	}

	public function leAction()
	{
		$this->_eventsManager->fire('dummy:beforeAction', $this, "extra data");
		$this->_eventsManager->fire('dummy:afterAction', $this, array("extra","data"));
	}

}

class LeAnotherComponent
{

	protected $_eventsManager;

	public function setEventsManager($eventsManager)
	{
		$this->_eventsManager = $eventsManager;
	}

	public function leAction()
	{
		$this->_eventsManager->fire('another:beforeAction', $this);
		$this->_eventsManager->fire('another:afterAction', $this);
	}

}

class LeDummyListener
{

	protected $_testCase;

	protected $_before = 0;

	protected $_after = 0;

	public function setTestCase($testCase){
		$this->_testCase = $testCase;
	}

	public function beforeAction($event, $component, $data)
	{
		$this->_testCase->assertInstanceOf('Phalcon\Events\Event', $event);
		$this->_testCase->assertInstanceOf('LeDummyComponent', $component);
		$this->_testCase->assertEquals($data, "extra data");
		$this->_before++;
	}

	public function afterAction($event, $component)
	{
		$this->_testCase->assertInstanceOf('Phalcon\Events\Event', $event);
		$this->_testCase->assertInstanceOf('LeDummyComponent', $component);
		$this->_testCase->assertEquals($event->getData(), array("extra","data"));
		$this->_after++;
	}

	public function getBeforeCount()
	{
		return $this->_before;
	}

	public function getAfterCount()
	{
		return $this->_after;
	}

}

class MyFirstWeakrefListener
{
	public function afterShow()
	{
		echo "show first listener\n";
	}
}

class MySecondWeakrefListener
{
	public function afterShow()
	{
		echo "show second listener\n";
	}
}

class EventsTest extends PHPUnit_Framework_TestCase
{

	public function testEvents()
	{

		$eventsManager = new Phalcon\Events\Manager();

		$listener = new LeDummyListener();
		$listener->setTestCase($this);

		$eventsManager->attach('dummy', $listener);

		$component = new LeDummyComponent();
		$component->setEventsManager($eventsManager);

		$another = new LeAnotherComponent();
		$another->setEventsManager($eventsManager);

		$component->leAction();
		$component->leAction();

		$another->leAction();
		$another->leAction();
		$another->leAction();

		$this->assertEquals($listener->getBeforeCount(), 2);
		$this->assertEquals($listener->getAfterCount(), 2);

		$listener2 = new LeDummyListener();
		$listener2->setTestCase($this);

		$eventsManager->attach('dummy', $listener2);

		$component->leAction();
		$component->leAction();

		$this->assertEquals($listener->getBeforeCount(), 4);
		$this->assertEquals($listener->getAfterCount(), 4);

		$this->assertEquals($listener2->getBeforeCount(), 2);
		$this->assertEquals($listener2->getAfterCount(), 2);

		/*
		//This is failling :(
		$eventsManager->dettach('dummy', $listener);*/

		/*$eventsManager->detachAll('dummy');

		$component->leAction();
		$component->leAction();

		$this->assertEquals($listener->getBeforeCount(), 4);
		$this->assertEquals($listener->getAfterCount(), 4);*/

	}

	public function testEventsPropagation()
	{

		$eventsManager = new Phalcon\Events\Manager();

		$number = 0;
		$propagationListener = function($event, $component, $data) use (&$number) {
			$number++;
			$event->stop();
		};

		$eventsManager->attach('some-type', $propagationListener);
		$eventsManager->attach('some-type', $propagationListener);

		$eventsManager->fire('some-type:beforeSome', $this);

		$this->assertEquals($number, 1);
	}

	/**
	 * "Attaching event listeners by event name fails if preceded by
	 * detachment of all listeners for that type."
	 *
	 * Test contains 4 steps:
	 * - assigning event manager to dummy service with single log event
	 *   listener attached
	 * - attaching second log listener
	 * - detaching all log listeners
	 * - attaching different listener
	 *
	 * @see https://github.com/phalcon/cphalcon/issues/1331
	 */
	public function testBug1331()
	{
		$di = new Phalcon\Di;
		$di->set('componentX', function() use ($di) {
			$component = new LeDummyComponent();
			$eventsManager = new Phalcon\Events\Manager;
			$eventsManager->attach('log', $di->get('MyFirstWeakrefListener'));
			$component->setEventsManager($eventsManager);
			return $component;
		});

		$di->set('firstListener', 'MyFirstWeakrefListener');
		$di->set('secondListener', 'MySecondWeakrefListener');

		// ----- TESTING STEP 1 - SIGNLE 'LOG' LISTENER ATTACHED

		$component = $di->get('componentX');

		$logListeners = $component->getEventsManager()->getListeners('log');

		$this->assertCount(1, $logListeners);
		$this->assertInstanceOf('MyFirstWeakrefListener', $logListeners[0]);

		// ----- TESTING STEP 2 - SECOND 'LOG' LISTENER ATTACHED

		$component->getEventsManager()->attach('log', $di->get('MySecondWeakrefListener'));

		$logListeners = $component->getEventsManager()->getListeners('log');

		$this->assertCount(2, $logListeners);
		$firstLister  = array_shift($logListeners);
		$secondLister = array_shift($logListeners);
		$this->assertInstanceOf('MyFirstWeakrefListener', $firstLister);
		$this->assertInstanceOf('MySecondWeakrefListener', $secondLister);

		// ----- TESTING STEP 3 - ALL 'LOG' LISTENER DETACHED

		$component->getEventsManager()->detachAll('log');

		$logListeners = $component->getEventsManager()->getListeners('log');
		$this->assertEmpty($logListeners);

		// ----- TESTING STEP 4 - SINGLE 'LOG' LISTENER ATTACHED SECOND TIME

		$component->getEventsManager()->attach('log', $di->get('MySecondWeakrefListener'));

		$logListeners = $component->getEventsManager()->getListeners('log');

		$this->assertCount(1, $logListeners);
		$this->assertInstanceOf('MySecondWeakrefListener', $logListeners[0]);
	}

	/**
	 * "Attaching event listeners by event name fails if preceded by
	 * detachment of all listeners for that type."
	 *
	 * Test contains 4 steps:
	 * - assigning event manager to dummy service with single log event
	 *   listener attached
	 * - attaching second log listener
	 * - detaching all log listeners
	 * - attaching different listener
	 *
	 * NOTE: This test looks the same as above but it checks detachAll()
	 * instead of detachAll() method. To be DELETED when detachAll()
	 * will not supported any more.
	 *
	 * @see https://github.com/phalcon/cphalcon/issues/1331
	 */
	public function testBug1331BackwardCompatibility()
	{
		$di = new Phalcon\Di;
		$di->set('componentX', function() use ($di) {
			$component = new LeDummyComponent();
			$eventsManager = new Phalcon\Events\Manager;
			$eventsManager->attach('log', $di->get('MyFirstWeakrefListener'));
			$component->setEventsManager($eventsManager);
			return $component;
		});

		$di->set('firstListener', 'MyFirstWeakrefListener');
		$di->set('secondListener', 'MySecondWeakrefListener');

		// ----- TESTING STEP 1 - SIGNLE 'LOG' LISTENER ATTACHED

		$component = $di->get('componentX');

		$logListeners = $component->getEventsManager()->getListeners('log');

		$this->assertCount(1, $logListeners);
		$this->assertInstanceOf('MyFirstWeakrefListener', $logListeners[0]);

		// ----- TESTING STEP 2 - SECOND 'LOG' LISTENER ATTACHED

		$component->getEventsManager()->attach('log', $di->get('MySecondWeakrefListener'));

		$logListeners = $component->getEventsManager()->getListeners('log');

		$this->assertCount(2, $logListeners);
		$firstLister  = array_shift($logListeners);
		$secondLister = array_shift($logListeners);
		$this->assertInstanceOf('MyFirstWeakrefListener', $firstLister);
		$this->assertInstanceOf('MySecondWeakrefListener', $secondLister);

		// ----- TESTING STEP 3 - ALL 'LOG' LISTENER DETACHED

		$component->getEventsManager()->detachAll('log');

		$logListeners = $component->getEventsManager()->getListeners('log');
		$this->assertEmpty($logListeners);

		// ----- TESTING STEP 4 - SINGLE 'LOG' LISTENER ATTACHED SECOND TIME

		$component->getEventsManager()->attach('log', $di->get('MySecondWeakrefListener'));

		$logListeners = $component->getEventsManager()->getListeners('log');

		$this->assertCount(1, $logListeners);
		$this->assertInstanceOf('MySecondWeakrefListener', $logListeners[0]);
	}
}
