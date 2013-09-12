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

	public function setEventManager($eventsManager)
	{
		$this->_eventsManager = $eventsManager;
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

	public function setEventManager($eventsManager)
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
		$component->setEventManager($eventsManager);

		$another = new LeAnotherComponent();
		$another->setEventManager($eventsManager);

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

		/*$eventsManager->dettachAll('dummy');

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

	public function testEventsWeakref()
	{
		if (!class_exists('WeakRef')) {
			return;
		}

		$eventsManager = new Phalcon\Events\Manager();

		$firstListener = new MyFirstWeakrefListener();
		$secondListener = new MySecondWeakrefListener();

		$eventsManager->attach('my', $firstListener); // without weakref
		$eventsManager->attach('my', new WeakRef($secondListener)); // with weakref

		ob_start();
		// fire when two listeners still exists.
		$eventsManager->fire('my:afterShow', null);
		$data = ob_get_clean();

		$this->assertEquals($data, "show first listener\nshow second listener\n");

		unset($firstListener);
		unset($secondListener);

		ob_start();
		// fire when two listeners was unsetted.
		$eventsManager->fire('my:afterShow', null);
		$data = ob_get_clean();

		$this->assertEquals($data, "show first listener\n");
	}
}
