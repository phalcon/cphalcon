<?php

namespace Phalcon\Test\Unit\Mvc\Dispatcher;

use Exception;
use Phalcon\Test\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;

/**
 * \Phalcon\Test\Unit\Mvc\Dispatcher\DispatcherBeforeDispatchLoopTest
 * Tests the \Phalcon\Dispatcher and Phalcon\Mvc\Dispatcher "beforeDispatchLoop" event.
 *
 * @link https://docs.phalconphp.com/en/latest/reference/dispatching.html
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\Dispatcher
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class DispatcherBeforeDispatchLoopTest extends BaseDispatcher
{
    /**
     * Tests the forwarding in the beforeDispatchLoop event
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopForward()
    {
        $this->specify(
            'Forwarding inside the beforeDispatchLoop should cancel the default route and forward immediately',
            function () {
                $dispatcher = $this->getDispatcher();

                $dispatcher->getEventsManager()->attach('dispatch:beforeDispatchLoop', function ($event, $dispatcher) {
                    $dispatcher->forward(['action' => 'index2']);
                });

                $dispatcher->dispatch();

                expect($this->getDispatcherListener()->getTrace())->equals([
                    'beforeDispatchLoop',
                    'beforeDispatch',
                    'beforeExecuteRoute',
                    'beforeExecuteRoute-method',
                    'initialize-method',
                    'afterInitialize',
                    'index2Action',
                    'afterExecuteRoute',
                    'afterExecuteRoute-method',
                    'afterDispatch',
                    'afterDispatchLoop'
                ]);
            }
        );
    }

    /**
     * Tests returning <tt>false</tt> inside a beforeDispatchLoop event.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopReturnFalse()
    {
        $this->specify(
            'Returning false inside a "dispatch:beforeDispatchLoop" event should immediately cancel dispatching',
            function () {
                $dispatcher = $this->getDispatcher();

                $dispatcher->getEventsManager()->attach('dispatch:beforeDispatchLoop', function () {
                    return false;
                });
                $dispatcher->dispatch();

                expect($this->getDispatcherListener()->getTrace())->equals([
                    'beforeDispatchLoop'
                ]);
            }
        );
    }

    /**
     * Tests returning <tt>false</tt> inside a beforeDispatchLoop event with multiple returned items
     * in event listeners.
     *
     * Currently, we only value the return from the last item; therefore, for libraries and plugins
     * that hook into dispatcher events that need to cancel the event, the event should additionally
     * be stopped() to ensure proper flow.
     *
     * This test case SHOULD be altered in 4.0 along with any other corresponding documentation
     * changes for stopping. E.g. switching to event->stop() opposed to returning false.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopBaselinePrePhalcon40MultipleReturnFalseMixed()
    {
        $this->specify(
            'Returning false inside a "dispatch:beforeDispatchLoop" event should immediately cancel dispatching',
            function () {
                $dispatcher = $this->getDispatcher();

                $dispatcher->getEventsManager()->attach('dispatch:beforeDispatchLoop', function () {
                    return false;
                });
                // Unfortunately, we really need to collect all responses or use the Event stopping property
                // instead of return <tt>false</tt>. The following statement breaks the ability to stop the chain.

                $dispatcher->getEventsManager()->attach('dispatch:beforeDispatchLoop', function () {
                    return true;
                });

                $dispatcher->dispatch();

                expect($this->getDispatcherListener()->getTrace())->equals([
                    'beforeDispatchLoop',
                    'beforeDispatch',
                    'beforeExecuteRoute',
                    'beforeExecuteRoute-method',
                    'initialize-method',
                    'afterInitialize',
                    'indexAction',
                    'afterExecuteRoute',
                    'afterExecuteRoute-method',
                    'afterDispatch',
                    'afterDispatchLoop'
                ]);
            }
        );
    }

    /**
     * Tests returning <tt>false</tt> inside a beforeDispatchLoop event with multiple returned items
     * in event listeners.
     *
     * Currently, we only value the return from the last item; therefore, for libraries and plugins
     * that hook into dispatcher events that need to cancel the event, the event should additionally
     * be stopped() to ensure proper flow.
     *
     * This test case SHOULD be altered in 4.0 along with any other corresponding documentation
     * changes for stopping. E.g. switching to event->stop() opposed to returning false.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopBaselinePrePhalcon40MultipleReturnFalse()
    {
        $this->specify(
            'Returning false inside a "dispatch:beforeDispatchLoop" event should immediately cancel dispatching',
            function () {
                $dispatcher = $this->getDispatcher();

                $dispatcher->getEventsManager()->attach('dispatch:beforeDispatchLoop', function () {
                    return false;
                });
                // Unfortunately, we really need to collect all responses or use the Event stopping property
                // instead of return <tt>false</tt>. The following statement breaks the ability to stop the chain.
                $dispatcher->getEventsManager()->attach('dispatch:beforeDispatchLoop', function () {
                    return false;
                });

                $dispatcher->dispatch();

                expect($this->getDispatcherListener()->getTrace())->equals([
                    'beforeDispatchLoop',
                ]);
            }
        );
    }

    /**
     * Tests exception handling to ensure exceptions can be properly handled when thrown from
     * inside a beforeDispatchLoop event and then ensure the exception is not bubbled when
     * returning with <tt>false</tt>.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopWithBeforeExceptionReturningFalse()
    {
        $this->specify(
            'Returning false inside a "dispatch:beforeException" event should cancel dispatching and prevent bubbling of the exception',
            function () {
                $dispatcher = $this->getDispatcher();

                $dispatcher->getEventsManager()->attach('dispatch:beforeDispatchLoop', function () {
                    throw new Exception('beforeDispatchLoop exception occurred');
                });
                $dispatcher->getEventsManager()->attach('dispatch:beforeException', function () {
                    return false;
                });

                $dispatcher->dispatch();

                expect($this->getDispatcherListener()->getTrace())->equals([
                    'beforeDispatchLoop',
                    'beforeException: beforeDispatchLoop exception occurred'
                ]);
            }
        );
    }

    /**
     * Tests exception handling to ensure exceptions can be properly handled via beforeException event and
     * then will properly bubble up the stack if anything other than <tt>false</tt> is returned.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopWithBeforeExceptionBubble()
    {
        $this->specify(
            'Returning anything other than false inside a "dispatch:beforeException" event should bubble the exception',
            function () {
                $dispatcher = $this->getDispatcher();
                $dispatcherListener = $this->getDispatcherListener();

                $dispatcher->getEventsManager()->attach('dispatch:beforeDispatchLoop', function () {
                    throw new Exception('beforeDispatchLoop exception occurred');
                });
                $dispatcher->getEventsManager()->attach('dispatch:beforeException', function () use ($dispatcherListener) {
                    $dispatcherListener->trace('beforeException: custom before exception bubble');
                    return null;
                });

                $caughtException = false;
                try {
                    $dispatcher->dispatch();
                } catch (Exception $exception) {
                    $caughtException = true;
                }

                expect($caughtException)->equals(true);
                expect($this->getDispatcherListener()->getTrace())->equals([
                    'beforeDispatchLoop',
                    'beforeException: beforeDispatchLoop exception occurred',
                    'beforeException: custom before exception bubble'
                ]);
            }
        );
    }

    /**
     * Tests dispatch forward handling inside the beforeException when a beforeDispatchLoop exception occurs.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopWithBeforeExceptionForward()
    {
        $this->specify(
            'Forwarding inside a "dispatch:beforeException" event (and without returning false) should properly forward the dispatcher without the exception bubbling',
            function () {
                $dispatcher = $this->getDispatcher();
                $dispatcherListener = $this->getDispatcherListener();

                $dispatcher->getEventsManager()->attach('dispatch:beforeDispatchLoop', function () {
                    throw new Exception('beforeDispatchLoop exception occurred');
                });
                $dispatcher->getEventsManager()->attach('dispatch:beforeException', function ($event, $dispatcher) use ($dispatcherListener) {
                    $dispatcherListener->trace('beforeException: custom before exception forward');
                    $dispatcher->forward(['action' => 'index2']);
                });

                $dispatcher->dispatch();

                expect($this->getDispatcherListener()->getTrace())->equals([
                    'beforeDispatchLoop',
                    'beforeException: beforeDispatchLoop exception occurred',
                    'beforeException: custom before exception forward',
                    'beforeDispatch',
                    'beforeExecuteRoute',
                    'beforeExecuteRoute-method',
                    'initialize-method',
                    'afterInitialize',
                    'index2Action',
                    'afterExecuteRoute',
                    'afterExecuteRoute-method',
                    'afterDispatch',
                    'afterDispatchLoop'
                ]);
            }
        );
    }
}
