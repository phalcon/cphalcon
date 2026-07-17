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

namespace Phalcon\Tests\Unit\Mvc\Dispatcher\Refactor;

use Exception;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;

/**
 * @todo    : refactor
 */
class DispatcherInitializeMethodTest extends BaseDispatcher
{
    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testInitializeForward(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setControllerName('dispatcher-test-initialize-forward');

        $caughtException = false;

        try {
            $dispatcher->dispatch();
        } catch (Exception $exception) {
            $caughtException = true;
        }

        $this->assertTrue($caughtException);

        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'beforeException: Forwarding inside a controller\'s initialize() method is forbidden',
        ];

        $this->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testInitializeReturnFalse(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setControllerName('dispatcher-test-initialize-return-false');

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

        $this->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testInitializeWithBeforeExceptionBubble(): void
    {
        $dispatcher         = $this->getDispatcher();
        $dispatcherListener = $this->getDispatcherListener();

        $dispatcher->setControllerName('dispatcher-test-initialize-exception');

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function () use ($dispatcherListener) {
                // Returning anything other than <tt>false</tt> should bubble the exception.
                $dispatcherListener->trace(
                    'beforeException: custom before exception bubble'
                );

                return null;
            }
        );

        $caughtException = false;

        try {
            $dispatcher->dispatch();
        } catch (Exception $exception) {
            $caughtException = true;
        }

        $this->assertTrue($caughtException);
        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'beforeException: initialize exception occurred',
            'beforeException: custom before exception bubble',
        ];

        $this->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testInitializeWithBeforeExceptionForward(): void
    {
        $dispatcher         = $this->getDispatcher();
        $dispatcherListener = $this->getDispatcherListener();

        $dispatcher->setControllerName('dispatcher-test-initialize-exception');

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
        );

        $dispatcher->dispatch();

        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'beforeException: initialize exception occurred',
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

        $this->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testInitializeWithBeforeExceptionReturningFalse(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setControllerName('dispatcher-test-initialize-exception');

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function () {
                // Returning <tt>false</tt> should prevent the exception from bubbling up.
                return false;
            }
        );

        $dispatcher->dispatch();

        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'beforeException: initialize exception occurred',
            'afterDispatchLoop',
        ];

        $this->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }
}
