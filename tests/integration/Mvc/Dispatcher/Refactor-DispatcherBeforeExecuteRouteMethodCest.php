<?php

namespace Phalcon\Test\Integration\Mvc\Dispatcher;

use Exception;
use IntegrationTester;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\BaseDispatcher;

/**
 * \Phalcon\Test\Integration\Mvc\Dispatcher\DispatcherBeforeExecuteRouteMethodTest
 * Tests the \Phalcon\Dispatcher and Phalcon\Mvc\Dispatcher
 * "beforeExecuteRoute" controller method.
 *
 * @link          https://docs.phalcon.io/en/latest/reference/dispatching.html
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          http://www.phalcon.io
 * @author        Andres Gutierrez <andres@phalcon.io>
 * @author        Nikolaos Dimopoulos <nikos@phalcon.io>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalcon.io
 * so that we can send you a copy immediately.
 */
class DispatcherBeforeExecuteRouteMethodCest extends BaseDispatcher
{
    /**
     * Tests the forwarding in the beforeExecuteRoute method
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeExecuteRouteForwardOnce(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setControllerName(
            'dispatcher-test-before-execute-route-forward'
        );

        $dispatcher->dispatch();

        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
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
     * Tests returning <tt>false</tt> inside a beforeExecuteRoute method.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeExecuteRouteReturnFalse(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setControllerName(
            'dispatcher-test-before-execute-route-return-false'
        );

        $dispatcher->dispatch();

        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'afterDispatchLoop',
        ];

        $actual = $this->getDispatcherListener()->getTrace();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests exception handling to ensure exceptions can be properly handled
     * when thrown from inside a beforeExecuteRoute method and then ensure the
     * exception is not bubbled when returning with <tt>false</tt>.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeExecuteRouteWithBeforeExceptionReturningFalse(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setControllerName(
            'dispatcher-test-before-execute-route-exception'
        );

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
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'beforeException: beforeExecuteRoute exception occurred',
            'afterDispatchLoop',
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
    public function testBeforeExecuteRouteWithBeforeExceptionBubble(IntegrationTester $I)
    {
        $dispatcher         = $this->getDispatcher();
        $dispatcherListener = $this->getDispatcherListener();

        $dispatcher->setControllerName(
            'dispatcher-test-before-execute-route-exception'
        );

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function () use ($dispatcherListener) {
                $dispatcherListener->trace(
                    'beforeException: custom before exception bubble'
                );

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
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'beforeException: beforeExecuteRoute exception occurred',
            'beforeException: custom before exception bubble',
        ];

        $actual = $this->getDispatcherListener()->getTrace();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests dispatch forward handling inside the beforeException when a
     * beforeExecuteRoute method exception occurs.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testBeforeExecuteRouteWithBeforeExceptionForward(IntegrationTester $I)
    {
        $dispatcher         = $this->getDispatcher();
        $dispatcherListener = $this->getDispatcherListener();

        $dispatcher->setControllerName(
            'dispatcher-test-before-execute-route-exception'
        );

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function ($event, $dispatcher) use ($dispatcherListener) {
                $dispatcherListener->trace(
                    'beforeException: custom before exception forward'
                );

                $dispatcher->forward(
                    [
                        'controller' => 'dispatcher-test-default',
                        'action'     => 'index',
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
            'beforeException: beforeExecuteRoute exception occurred',
            'beforeException: custom before exception forward',
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
}
