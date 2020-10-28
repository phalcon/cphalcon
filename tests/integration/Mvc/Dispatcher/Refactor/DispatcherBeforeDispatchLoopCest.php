<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Mvc\Dispatcher\Refactor;

use Exception;
use IntegrationTester;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\BaseDispatcher;;

/**
 * Class DispatcherBeforeDispatchLoopCest
 *
 * @package Phalcon\Test\Integration\Mvc\Dispatcher
 * @todo: refactor
 */
class DispatcherBeforeDispatchLoopCest extends BaseDispatcher
{
    /**
     * Tests the forwarding in the beforeDispatchLoop event
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopForward(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function ($event, $dispatcher) {
                $dispatcher->forward(
                    [
                        'action' => 'index2',
                    ]
                );
            }
        )
        ;

        $dispatcher->dispatch();

        $expected = [
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
            'afterDispatchLoop',
        ];

        $actual = $this->getDispatcherListener()->getTrace();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests returning <tt>false</tt> inside a beforeDispatchLoop event.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopReturnFalse(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function () {
                return false;
            }
        )
        ;

        $dispatcher->dispatch();

        $expected = [
            'beforeDispatchLoop',
        ];

        $actual = $this->getDispatcherListener()->getTrace();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests returning <tt>false</tt> inside a beforeDispatchLoop event with
     * multiple returned items in event listeners.
     *
     * Currently, we only value the return from the last item; therefore, for
     * libraries and plugins that hook into dispatcher events that need to
     * cancel the event, the event should additionally be stopped() to ensure
     * proper flow.
     *
     * This test case SHOULD be altered in 4.0 along with any other
     * corresponding documentation changes for stopping. E.g. switching to
     * event->stop() opposed to returning false.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopBaselinePrePhalcon40MultipleReturnFalseMixed(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function () {
                return false;
            }
        )
        ;

        // Unfortunately, we really need to collect all responses or use the Event stopping property
        // instead of return <tt>false</tt>. The following statement breaks the ability to stop the chain.

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function () {
                return true;
            }
        )
        ;

        $dispatcher->dispatch();

        $expected = [
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
            'afterDispatchLoop',
        ];

        $actual = $this->getDispatcherListener()->getTrace();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests returning <tt>false</tt> inside a beforeDispatchLoop event with
     * multiple returned items in event listeners.
     *
     * Currently, we only value the return from the last item; therefore, for
     * libraries and plugins that hook into dispatcher events that need to
     * cancel the event, the event should additionally be stopped() to ensure
     * proper flow.
     *
     * This test case SHOULD be altered in 4.0 along with any other
     * corresponding documentation changes for stopping. E.g. switching to
     * event->stop() opposed to returning false.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopBaselinePrePhalcon40MultipleReturnFalse(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function () {
                return false;
            }
        )
        ;

        // Unfortunately, we really need to collect all responses or use the Event stopping property
        // instead of return <tt>false</tt>. The following statement breaks the ability to stop the chain.
        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function () {
                return false;
            }
        )
        ;

        $dispatcher->dispatch();


        $expected = [
            'beforeDispatchLoop',
        ];

        $actual = $this->getDispatcherListener()->getTrace();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests exception handling to ensure exceptions can be properly handled
     * when thrown from inside a beforeDispatchLoop event and then ensure the
     * exception is not bubbled when returning with <tt>false</tt>.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopWithBeforeExceptionReturningFalse(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function () {
                throw new Exception('beforeDispatchLoop exception occurred');
            }
        )
        ;

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function () {
                return false;
            }
        )
        ;

        $dispatcher->dispatch();


        $expected = [
            'beforeDispatchLoop',
            'beforeException: beforeDispatchLoop exception occurred',
        ];

        $actual = $this->getDispatcherListener()->getTrace();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests exception handling to ensure exceptions can be properly handled
     * via beforeException event and then will properly bubble up the stack if
     * anything other than <tt>false</tt> is returned.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopWithBeforeExceptionBubble(IntegrationTester $I)
    {
        $dispatcher         = $this->getDispatcher();
        $dispatcherListener = $this->getDispatcherListener();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatchLoop',
            function () {
                throw new Exception('beforeDispatchLoop exception occurred');
            }
        )
        ;

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function () use ($dispatcherListener) {
                $dispatcherListener->trace('beforeException: custom before exception bubble');

                return null;
            }
        )
        ;

        $I->expectThrowable(
            Exception::class,
            function () use ($dispatcher) {
                $dispatcher->dispatch();
            }
        );

        $expected = [
            'beforeDispatchLoop',
            'beforeException: beforeDispatchLoop exception occurred',
            'beforeException: custom before exception bubble',
        ];
        $actual   = $this->getDispatcherListener()->getTrace();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests dispatch forward handling inside the beforeException when a
     * beforeDispatchLoop exception occurs.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeDispatchLoopWithBeforeExceptionForward(IntegrationTester $I)
    {
        $dispatcher         = $this->getDispatcher();
        $dispatcherListener = $this->getDispatcherListener();

        $dispatcher->getEventsManager()->attach('dispatch:beforeDispatchLoop', function () {
            throw new Exception('beforeDispatchLoop exception occurred');
        })
        ;
        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function ($event, $dispatcher) use ($dispatcherListener) {
                $dispatcherListener->trace(
                    'beforeException: custom before exception forward'
                );

                $dispatcher->forward(
                    [
                        'action' => 'index2',
                    ]
                );
            }
        )
        ;

        $dispatcher->dispatch();

        $expected = [
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
            'afterDispatchLoop',
        ];
        $actual   = $this->getDispatcherListener()->getTrace();
        $I->assertEquals($expected, $actual);
    }
}
