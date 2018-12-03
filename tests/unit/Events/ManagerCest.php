<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Events;

use ComponentX;
use ComponentY;
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Test\Fixtures\Listener\FirstListener;
use Phalcon\Test\Fixtures\Listener\SecondListener;
use Phalcon\Test\Fixtures\Listener\ThirdListener;
use UnitTester;
use function dataFolder;

class ManagerCest
{
    protected $listener;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        include_once dataFolder('fixtures/Events/ComponentX.php');
        include_once dataFolder('fixtures/Events/ComponentY.php');
    }

    /**
     * Tests attaching event listeners by event name after detaching all
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1331
     * @author Kamil Skowron <kamil@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function attachingListenersByEventNameAfterDetachingAll(UnitTester $I)
    {
        $first  = new FirstListener();
        $second = new SecondListener();

        $component = new ComponentX();

        $eventsManager = new Manager();
        $eventsManager->attach('log', $first);

        $component->setEventsManager($eventsManager);

        $logListeners = $component->getEventsManager()->getListeners('log');

        $I->assertCount(1, $logListeners);
        $I->assertInstanceOf(FirstListener::class, $logListeners[0]);

        $component->getEventsManager()->attach('log', $second);
        $logListeners = $component->getEventsManager()->getListeners('log');

        $I->assertCount(2, $logListeners);
        $I->assertInstanceOf(FirstListener::class, $logListeners[0]);
        $I->assertInstanceOf(SecondListener::class, $logListeners[1]);

        $component->getEventsManager()->detachAll('log');
        $logListeners = $component->getEventsManager()->getListeners('log');

        $I->assertEmpty($logListeners);

        $component->getEventsManager()->attach('log', $second);
        $logListeners = $component->getEventsManager()->getListeners('log');

        $I->assertCount(1, $logListeners);
        $I->assertInstanceOf(SecondListener::class, $logListeners[0]);
    }

    /**
     * Tests using event listeners
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-08-14
     */
    public function usingEvents(UnitTester $I)
    {
        $listener1 = new ThirdListener();
        $listener1->setTestCase($this, $I);

        $listener2 = new ThirdListener();
        $listener2->setTestCase($this, $I);

        $eventsManager = new Manager();
        $eventsManager->attach('dummy', $listener1);

        $componentX = new ComponentX();
        $componentX->setEventsManager($eventsManager);

        $componentY = new ComponentY();
        $componentY->setEventsManager($eventsManager);

        $componentX->leAction();
        $componentX->leAction();

        $componentY->leAction();
        $componentY->leAction();
        $componentY->leAction();

        $I->assertEquals(2, $listener1->getBeforeCount());
        $I->assertEquals(2, $listener1->getAfterCount());

        $eventsManager->attach('dummy', $listener2);

        $componentX->leAction();
        $componentX->leAction();

        $I->assertEquals(4, $listener1->getBeforeCount());
        $I->assertEquals(4, $listener1->getAfterCount());

        $I->assertEquals(2, $listener2->getBeforeCount());
        $I->assertEquals(2, $listener2->getAfterCount());

        $I->assertSame($listener2, $this->listener);

        $eventsManager->detach('dummy', $listener1);

        $componentX->leAction();
        $componentX->leAction();

        $I->assertEquals(4, $listener1->getBeforeCount());
        $I->assertEquals(4, $listener1->getAfterCount());

        $I->assertEquals(4, $listener2->getBeforeCount());
        $I->assertEquals(4, $listener2->getAfterCount());
    }

    /**
     * Tests using events with priority
     *
     * @test
     * @author Vladimir Khramov <quant13@gmail.com>
     * @since  2014-12-09
     */
    public function usingEventsWithPriority(UnitTester $I)
    {
        $listener1 = new ThirdListener();
        $listener1->setTestCase($this, $I);

        $listener2 = new ThirdListener();
        $listener2->setTestCase($this, $I);

        $eventsManager = new Manager();
        $eventsManager->enablePriorities(true);

        $eventsManager->attach('dummy', $listener1, 100);

        $componentX = new ComponentX();
        $componentX->setEventsManager($eventsManager);

        $componentY = new ComponentY();
        $componentY->setEventsManager($eventsManager);

        $componentX->leAction();
        $componentX->leAction();

        $componentY->leAction();
        $componentY->leAction();
        $componentY->leAction();

        $I->assertEquals(2, $listener1->getBeforeCount());
        $I->assertEquals(2, $listener1->getAfterCount());

        $eventsManager->attach('dummy', $listener2, 150);

        $componentX->leAction();
        $componentX->leAction();

        $I->assertEquals(4, $listener1->getBeforeCount());
        $I->assertEquals(4, $listener1->getAfterCount());

        $I->assertEquals(2, $listener2->getBeforeCount());
        $I->assertEquals(2, $listener2->getAfterCount());

        $I->assertSame($listener1, $this->listener);

        $eventsManager->detach('dummy', $listener1);

        $componentX->leAction();
        $componentX->leAction();

        $I->assertEquals(4, $listener1->getBeforeCount());
        $I->assertEquals(4, $listener1->getAfterCount());

        $I->assertEquals(4, $listener2->getBeforeCount());
        $I->assertEquals(4, $listener2->getAfterCount());
    }

    /**
     * Tests using events propagation
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-11-11
     */
    public function stopEventsInEventsManager(UnitTester $I)
    {
        $number        = 0;
        $eventsManager = new Manager();

        $propagationListener = function (Event $event, $component, $data) use (&$number) {
            $number++;
            $event->stop();
        };

        $eventsManager->attach('some-type', $propagationListener);
        $eventsManager->attach('some-type', $propagationListener);

        $eventsManager->fire('some-type:beforeSome', $this);

        $I->assertEquals(1, $number);
    }

    /**
     * Tests detach handler by using a Closure
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12882
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-06-06
     */
    public function detachClosureListener(UnitTester $I)
    {
        $examples = [true, false];
        foreach ($examples as $enablePriorities) {
            $manager = new Manager();
            $manager->enablePriorities($enablePriorities);

            $handler = function () {
                echo __METHOD__;
            };

            $manager->attach('test:detachable', $handler);
            $events = $I->getProtectedProperty($manager, '_events');

            $I->assertCount(1, $events);
            $I->assertTrue(array_key_exists('test:detachable', $events));
            $I->assertCount(1, $events['test:detachable']);

            $manager->detach('test:detachable', $handler);

            $events = $I->getProtectedProperty($manager, '_events');

            $I->assertCount(1, $events);
            $I->assertTrue(array_key_exists('test:detachable', $events));
            $I->assertCount(0, $events['test:detachable']);
        }
    }

    /**
     * Tests detach handler by using an Object
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12882
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-06-06
     */
    public function detachObjectListener(UnitTester $I)
    {
        $examples = [true, false];
        foreach ($examples as $enablePriorities) {
            $manager = new Manager();
            $manager->enablePriorities($enablePriorities);

            $handler = new \stdClass();
            $manager->attach('test:detachable', $handler);
            $events = $I->getProtectedProperty($manager, '_events');

            $I->assertCount(1, $events);
            $I->assertTrue(array_key_exists('test:detachable', $events));
            $I->assertCount(1, $events['test:detachable']);

            $manager->detach('test:detachable', $handler);

            $events = $I->getProtectedProperty($manager, '_events');

            $I->assertCount(1, $events);
            $I->assertTrue(array_key_exists('test:detachable', $events));
            $I->assertCount(0, $events['test:detachable']);
        }
    }

    public function setLastListener($listener)
    {
        $this->listener = $listener;
    }

    protected function fireEventWithOutput(Manager $manager, $eventType)
    {
        $output = '';

        ob_start();
        $manager->fire($eventType, $this);
        $output .= ob_get_contents();
        ob_end_clean();

        return $output;
    }
}
