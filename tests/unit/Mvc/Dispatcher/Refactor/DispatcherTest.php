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

use DispatcherTestDefaultNoNamespaceController;
use Phalcon\Mvc\Dispatcher\Exception;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\DispatcherTestDefaultController;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\DispatcherTestDefaultSimpleController;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\DispatcherTestDefaultTwoController;

/**
 * @todo    : refactor
 */
class DispatcherTest extends BaseDispatcher
{
    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testControllerActionExternalForward(): void
    {
        $dummyParams = [
            'param1' => 1,
            'param2' => 2,
        ];

        $dispatcher = $this->getDispatcher();

        $dispatcher->setControllerName('dispatcher-test-default-two');
        $dispatcher->setActionName('forwardExternal');
        $dispatcher->setParams($dummyParams);

        $handler = $dispatcher->dispatch();

        $this->assertSame(
            'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $this->assertSame(
            'dispatcher-test-default',
            $dispatcher->getControllerName()
        );

        $this->assertSame(
            'index',
            $dispatcher->getActionName()
        );

        $this->assertSame(
            $dummyParams,
            $dispatcher->getParams()
        );

        $this->assertSame(
            DispatcherTestDefaultController::class,
            $dispatcher->getControllerClass()
        );

        $this->assertTrue(
            $dispatcher->wasForwarded()
        );

        $this->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $handler
        );

        $this->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $dispatcher->getActiveController()
        );

        $this->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $dispatcher->getLastController()
        );

        $this->assertTrue(
            $dispatcher->wasForwarded()
        );

        $this->assertSame(
            'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
            $dispatcher->getPreviousNamespaceName()
        );

        $this->assertSame(
            'dispatcher-test-default-two',
            $dispatcher->getPreviousControllerName()
        );

        $this->assertSame(
            'forwardExternal',
            $dispatcher->getPreviousActionName()
        );

        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'afterInitialize',
            'forwardExternalAction',
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

        $this->assertSame(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testControllerActionLocalForward(): void
    {
        $dummyParams = [
            'param1' => 1,
            'param2' => 2,
        ];

        $dispatcher = $this->getDispatcher();

        $dispatcher->setControllerName('dispatcher-test-default');
        $dispatcher->setActionName('forwardLocal');
        $dispatcher->setParams($dummyParams);

        $handler = $dispatcher->dispatch();

        $this->assertSame(
            'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $this->assertSame(
            'dispatcher-test-default',
            $dispatcher->getControllerName()
        );

        $this->assertSame(
            'index2',
            $dispatcher->getActionName()
        );

        $this->assertSame(
            $dummyParams,
            $dispatcher->getParams()
        );

        $this->assertSame(
            DispatcherTestDefaultController::class,
            $dispatcher->getControllerClass()
        );

        $this->assertTrue(
            $dispatcher->wasForwarded()
        );

        $this->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $handler
        );

        $this->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $dispatcher->getActiveController()
        );

        $this->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $dispatcher->getLastController()
        );

        $this->assertTrue(
            $dispatcher->wasForwarded()
        );

        $this->assertSame(
            'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
            $dispatcher->getPreviousNamespaceName()
        );

        $this->assertSame(
            'dispatcher-test-default',
            $dispatcher->getPreviousControllerName()
        );

        $this->assertSame(
            'forwardLocal',
            $dispatcher->getPreviousActionName()
        );

        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'afterInitialize',
            'forwardLocalAction',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'index2Action',
            'afterExecuteRoute',
            'afterExecuteRoute-method',
            'afterDispatch',
            'afterDispatchLoop',
        ];

        $this->assertSame(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testControllerActionReturnValueInt(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setActionName('returnInt');

        $dispatcher->dispatch();

        $this->assertSame(
            'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $this->assertSame(
            'dispatcher-test-default',
            $dispatcher->getControllerName()
        );

        $this->assertSame(
            'returnInt',
            $dispatcher->getActionName()
        );

        $this->assertSame(
            DispatcherTestDefaultController::RETURN_VALUE_INT,
            $dispatcher->getReturnedValue()
        );

        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'afterInitialize',
            'returnIntAction',
            'afterExecuteRoute',
            'afterExecuteRoute-method',
            'afterDispatch',
            'afterDispatchLoop',
        ];

        $this->assertSame(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testControllerActionReturnValueString(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setActionName('returnString');

        $dispatcher->dispatch();

        $this->assertSame(
            'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $this->assertSame(
            'dispatcher-test-default',
            $dispatcher->getControllerName()
        );

        $this->assertSame(
            'returnString',
            $dispatcher->getActionName()
        );

        $this->assertSame(
            DispatcherTestDefaultController::RETURN_VALUE_STRING,
            $dispatcher->getReturnedValue()
        );

        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'afterInitialize',
            'returnStringAction',
            'afterExecuteRoute',
            'afterExecuteRoute-method',
            'afterDispatch',
            'afterDispatchLoop',
        ];

        $this->assertSame(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testCyclicalRouting(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeDispatch',
            function ($event, $dispatcher) {
                $dispatcher->forward(
                    [
                        'action' => 'index2',
                    ]
                );
            }
        );

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Dispatcher has detected a cyclic routing causing stability problems'
        );
        $this->expectExceptionCode(Exception::EXCEPTION_CYCLIC_ROUTING);

        $dispatcher->dispatch();
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testDefaultDispatchLoopEventsWithNoHandlers(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setControllerName('dispatcher-test-default-simple');

        $handler = $dispatcher->dispatch();

        $this->assertSame(
            'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $this->assertSame(
            'dispatcher-test-default-simple',
            $dispatcher->getControllerName()
        );

        $this->assertSame(
            'index',
            $dispatcher->getActionName()
        );

        $this->assertSame(
            DispatcherTestDefaultSimpleController::class,
            $dispatcher->getControllerClass()
        );

        $this->assertFalse(
            $dispatcher->wasForwarded()
        );

        $this->assertInstanceOf(
            DispatcherTestDefaultSimpleController::class,
            $handler
        );

        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            // See https://github.com/phalcon/cphalcon/pull/13112
            // We now fire the `afterInitialize` for all cases even when the controller does not
            // have the `initialize()` method
            'afterInitialize',
            'indexAction',
            'afterExecuteRoute',
            'afterDispatch',
            'afterDispatchLoop',
        ];

        $this->assertSame(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testExceptionInBeforeException(): void
    {
        $beforeExceptionHandled = false;
        $caughtException        = false;

        $dispatcher = $this->getDispatcher();

        $dispatcher->setActionName('exception');

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function ($event, $dispatcher) use (&$beforeExceptionHandled) {
                $beforeExceptionHandled = true;

                $this->assertSame(
                    'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
                    $dispatcher->getNamespaceName()
                );

                $this->assertSame(
                    'dispatcher-test-default',
                    $dispatcher->getControllerName()
                );

                $this->assertSame(
                    'exception',
                    $dispatcher->getActionName()
                );

                $this->assertSame(
                    DispatcherTestDefaultController::class,
                    $dispatcher->getControllerClass()
                );

                $this->assertInstanceOf(
                    DispatcherTestDefaultController::class,
                    $dispatcher->getLastController()
                );

                // Forwarding; however, will throw a new exception preventing this
                $dispatcher->forward(
                    [
                        'controller' => 'dispatcher-test-default-two',
                        'action'     => 'index',
                    ]
                );

                throw new Exception('Custom error in before exception');
            }
        );

        try {
            $handler = $dispatcher->dispatch();
        } catch (Exception $exception) {
            $caughtException = true;

            $this->assertSame(
                'Custom error in before exception',
                $exception->getMessage()
            );
        } finally {
            $this->assertTrue($beforeExceptionHandled);
            $this->assertTrue($caughtException);

            // The string properties get updated

            $this->assertSame(
                'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
                $dispatcher->getNamespaceName()
            );

            $this->assertSame(
                'dispatcher-test-default-two',
                $dispatcher->getControllerName()
            );

            $this->assertSame(
                'index',
                $dispatcher->getActionName()
            );

            $this->assertSame(
                DispatcherTestDefaultTwoController::class,
                $dispatcher->getControllerClass()
            );

            // But not the last controller since dispatching didn't take place
            $this->assertInstanceOf(
                DispatcherTestDefaultController::class,
                $dispatcher->getLastController()
            );
        }
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testHandlerInvalid(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setNamespaceName('');
        $dispatcher->setControllerName('Test');

        $this->getDI()->setShared(
            $dispatcher->getHandlerClass(),
            function () {
                // Don't return an object
                return 3;
            }
        );

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Invalid handler returned from the services container'
        );
        $this->expectExceptionCode(Exception::EXCEPTION_INVALID_HANDLER);

        $dispatcher->dispatch();
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testLastHandlerExceptionForward(): void
    {
        $beforeExceptionHandled = false;

        $dispatcher = $this->getDispatcher();

        $dispatcher->setActionName('exception');

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function ($event, $dispatcher) use (&$beforeExceptionHandled) {
                $beforeExceptionHandled = true;

                $this->assertSame(
                    'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
                    $dispatcher->getNamespaceName()
                );

                $this->assertSame(
                    'dispatcher-test-default',
                    $dispatcher->getControllerName()
                );

                $this->assertSame(
                    'exception',
                    $dispatcher->getActionName()
                );

                $this->assertSame(
                    DispatcherTestDefaultController::class,
                    $dispatcher->getControllerClass()
                );

                $this->assertInstanceOf(
                    DispatcherTestDefaultController::class,
                    $dispatcher->getLastController()
                );

                $dispatcher->forward(
                    [
                        'controller' => 'dispatcher-test-default-two',
                        'action'     => 'index',
                    ]
                );

                return false;
            }
        );

        $handler = $dispatcher->dispatch();

        $this->assertTrue($beforeExceptionHandled);

        $this->assertSame(
            'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $this->assertSame(
            'dispatcher-test-default-two',
            $dispatcher->getControllerName()
        );

        $this->assertSame(
            'index',
            $dispatcher->getActionName()
        );

        $this->assertSame(
            DispatcherTestDefaultTwoController::class,
            $dispatcher->getControllerClass()
        );

        $this->assertInstanceOf(
            DispatcherTestDefaultTwoController::class,
            $dispatcher->getLastController()
        );
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testMixingNamespaceForward(): void
    {
        // Temporarily load non-namespaced class
        require_once __DIR__ . '/../Helper/DispatcherTestDefaultNoNamespaceController.php';

        $dispatcher = $this->getDispatcher();

        $dispatcher->setNamespaceName('');
        $dispatcher->setControllerName('dispatcher-test-default-no-namespace');
        $dispatcher->setActionName('forwardExternal');

        $handler = $dispatcher->dispatch();

        $this->assertSame(
            'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $this->assertSame(
            'dispatcher-test-default',
            $dispatcher->getControllerName()
        );

        $this->assertSame(
            'index',
            $dispatcher->getActionName()
        );

        $this->assertSame(
            DispatcherTestDefaultController::class,
            $dispatcher->getControllerClass()
        );

        $this->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $handler
        );

        $this->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $dispatcher->getActiveController()
        );

        $this->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $dispatcher->getLastController()
        );

        $this->assertTrue(
            $dispatcher->wasForwarded()
        );

        $this->assertEmpty(
            $dispatcher->getPreviousNamespaceName()
        );

        $this->assertSame(
            'dispatcher-test-default-no-namespace',
            $dispatcher->getPreviousControllerName()
        );

        $this->assertSame(
            'forwardExternal',
            $dispatcher->getPreviousActionName()
        );

        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'afterInitialize',
            'forwardExternalAction',
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

        $this->assertSame(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testNoNamespaces(): void
    {
        // Temporarily load non-namespaced class
        require_once __DIR__ . '/../Helper/DispatcherTestDefaultNoNamespaceController.php';

        $dispatcher = $this->getDispatcher();

        $dispatcher->setNamespaceName('');
        $dispatcher->setControllerName('dispatcher-test-default-no-namespace');
        $dispatcher->setActionName('index');

        $handler = $dispatcher->dispatch();

        $this->assertEmpty(
            $dispatcher->getNamespaceName()
        );

        $this->assertSame(
            'dispatcher-test-default-no-namespace',
            $dispatcher->getControllerName()
        );

        $this->assertSame(
            'index',
            $dispatcher->getActionName()
        );

        $this->assertSame(
            'DispatcherTestDefaultNoNamespaceController',
            $dispatcher->getControllerClass()
        );

        $this->assertFalse(
            $dispatcher->wasForwarded()
        );

        $this->assertInstanceOf(
            DispatcherTestDefaultNoNamespaceController::class, // @phpstan-ignore class.notFound
            $handler
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
            'afterExecuteRoute-method',
            'afterDispatch',
            'afterDispatchLoop',
        ];

        $this->assertSame(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testParamsAndReturnValue(): void
    {
        $multiply = [4, 6];

        $dispatcher = $this->getDispatcher();

        $dispatcher->setActionName('multiply');
        $dispatcher->setParams($multiply);

        $dispatcher->dispatch();

        $this->assertSame(
            'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $this->assertSame(
            'dispatcher-test-default',
            $dispatcher->getControllerName()
        );

        $this->assertSame(
            'multiply',
            $dispatcher->getActionName()
        );

        $this->assertSame(
            $multiply,
            $dispatcher->getParams()
        );

        $this->assertSame(
            24,
            $dispatcher->getReturnedValue()
        );

        $expected = [
            'beforeDispatchLoop',
            'beforeDispatch',
            'beforeExecuteRoute',
            'beforeExecuteRoute-method',
            'initialize-method',
            'afterInitialize',
            'multiplyAction',
            'afterExecuteRoute',
            'afterExecuteRoute-method',
            'afterDispatch',
            'afterDispatchLoop',
        ];

        $this->assertSame(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }
}
