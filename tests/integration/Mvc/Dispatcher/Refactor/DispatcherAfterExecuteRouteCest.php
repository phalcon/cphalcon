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

namespace Phalcon\Tests\Integration\Mvc\Dispatcher\Refactor;

use Exception;
use IntegrationTester;
use Phalcon\Tests\Integration\Mvc\Dispatcher\Helper\BaseDispatcher;

/**
 * Class DispatcherAfterExecuteRouteCest
 *
 * @package Phalcon\Tests\Integration\Mvc\Dispatcher
 * @todo: refactor
 */
class DispatcherAfterExecuteRouteCest extends BaseDispatcher
{
    /**
     * Tests the forwarding in the afterExecuteRoute event
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testAfterExecuteRouteForwardOnce(IntegrationTester $I)
    {
        $forwarded  = false;
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:afterExecuteRoute',
            function ($event, $dispatcher) use (&$forwarded) {
                if ($forwarded === false) {
                    $dispatcher->forward(['action' => 'index2']);
                    $forwarded = true;
                }
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
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'index2Action',
            'afterExecuteRoute',
            'afterExecuteRoute-method',
            'afterDispatch',
            'afterDispatchLoop',
        ];

        $I->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * Tests returning <tt>false</tt> inside a afterExecuteRoute event.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testAfterExecuteRouteReturnFalse(IntegrationTester $I)
    {
        $dispatcher         = $this->getDispatcher();
        $dispatcherListener = $this->getDispatcherListener();

        $dispatcher->getEventsManager()->attach(
            'dispatch:afterExecuteRoute',
            function () use ($dispatcherListener) {
                $dispatcherListener->trace('afterExecuteRoute: custom return false');

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
            'initialize-method',
            'afterInitialize',
            'indexAction',
            'afterExecuteRoute',
            'afterExecuteRoute: custom return false',
            'afterDispatchLoop',
        ];

        $I->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * Tests exception handling to ensure exceptions can be properly handled
     * when thrown from inside a afterExecuteRoute event and then ensure the
     * exception is not bubbled when returning with <tt>false</tt>.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testAfterExecuteRouteWithBeforeExceptionReturningFalse(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:afterExecuteRoute',
            function () {
                throw new Exception('afterExecuteRoute exception occurred');
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
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'afterInitialize',
            'indexAction',
            'afterExecuteRoute',
            'beforeException: afterExecuteRoute exception occurred',
            'afterDispatchLoop',
        ];

        $I->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * Tests exception handling to ensure exceptions can be properly handled
     * via beforeException event and then will properly bubble up the stack if
     * anything other than <tt>false</tt> is returned.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testAfterExecuteRouteWithBeforeExceptionBubble(IntegrationTester $I)
    {
        $dispatcher         = $this->getDispatcher();
        $dispatcherListener = $this->getDispatcherListener();

        $dispatcher->getEventsManager()->attach(
            'dispatch:afterExecuteRoute',
            function () {
                throw new Exception('afterExecuteRoute exception occurred');
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
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'afterInitialize',
            'indexAction',
            'afterExecuteRoute',
            'beforeException: afterExecuteRoute exception occurred',
            'beforeException: custom before exception bubble',
        ];

        $I->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * Tests dispatch forward handling inside the beforeException when a
     * afterExecuteRoute exception occurs.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testAfterExecuteRouteWithBeforeExceptionForwardOnce(IntegrationTester $I)
    {
        $forwarded          = false;
        $dispatcher         = $this->getDispatcher();
        $dispatcherListener = $this->getDispatcherListener();

        $dispatcher->getEventsManager()->attach(
            'dispatch:afterExecuteRoute',
            function () use (&$forwarded) {
                if ($forwarded === false) {
                    $forwarded = true;

                    throw new Exception('afterExecuteRoute exception occurred');
                }
            }
        )
        ;

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function ($event, $dispatcher) use ($dispatcherListener) {
                $dispatcherListener->trace('beforeException: custom before exception forward');

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
            'indexAction',
            'afterExecuteRoute',
            'beforeException: afterExecuteRoute exception occurred',
            'beforeException: custom before exception forward',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'index2Action',
            'afterExecuteRoute',
            'afterExecuteRoute-method',
            'afterDispatch',
            'afterDispatchLoop',
        ];

        $I->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }
}
