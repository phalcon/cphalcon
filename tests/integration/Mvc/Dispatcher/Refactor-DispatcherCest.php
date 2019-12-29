<?php

namespace Phalcon\Test\Integration\Mvc\Dispatcher;

use DispatcherTestDefaultNoNamespaceController;
use IntegrationTester;
use Phalcon\Dispatcher\Exception;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\BaseDispatcher;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\DispatcherTestDefaultController;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\DispatcherTestDefaultSimpleController;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\DispatcherTestDefaultTwoController;

/**
 * \Phalcon\Test\Integration\Mvc\Dispatcher\DispatcherEventsTest
 * Tests the core functionality of the \Phalcon\Dispatcher and
 * Phalcon\Mvc\Dispatcher classes.
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
class DispatcherCest extends BaseDispatcher
{
    /**
     * Tests the default order of dispatch events for basic execution with no
     * custom method handlers
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testDefaultDispatchLoopEventsWithNoHandlers(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setControllerName('dispatcher-test-default-simple');

        $handler = $dispatcher->dispatch();

        $I->assertEquals(
            'Phalcon\Test\Integration\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $I->assertEquals(
            'dispatcher-test-default-simple',
            $dispatcher->getControllerName()
        );

        $I->assertEquals(
            'index',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            DispatcherTestDefaultSimpleController::class,
            $dispatcher->getControllerClass()
        );

        $I->assertFalse(
            $dispatcher->wasForwarded()
        );

        $I->assertInstanceOf(
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

        $I->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * Tests the forwarding inside a controller's action.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testControllerActionLocalForward(IntegrationTester $I)
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

        $I->assertEquals(
            'Phalcon\Test\Integration\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $I->assertEquals(
            'dispatcher-test-default',
            $dispatcher->getControllerName()
        );

        $I->assertEquals(
            'index2',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            $dummyParams,
            $dispatcher->getParams()
        );

        $I->assertEquals(
            DispatcherTestDefaultController::class,
            $dispatcher->getControllerClass()
        );

        $I->assertTrue(
            $dispatcher->wasForwarded()
        );

        $I->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $handler
        );

        $I->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $dispatcher->getActiveController()
        );

        $I->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $dispatcher->getLastController()
        );

        $I->assertTrue(
            $dispatcher->wasForwarded()
        );

        $I->assertEquals(
            'Phalcon\Test\Integration\Mvc\Dispatcher\Helper',
            $dispatcher->getPreviousNamespaceName()
        );

        $I->assertEquals(
            'dispatcher-test-default',
            $dispatcher->getPreviousControllerName()
        );

        $I->assertEquals(
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

        $I->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * Tests the forwarding inside a controller's action.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testControllerActionExternalForward(IntegrationTester $I)
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

        $I->assertEquals(
            'Phalcon\Test\Integration\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $I->assertEquals(
            'dispatcher-test-default',
            $dispatcher->getControllerName()
        );

        $I->assertEquals(
            'index',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            $dummyParams,
            $dispatcher->getParams()
        );

        $I->assertEquals(
            DispatcherTestDefaultController::class,
            $dispatcher->getControllerClass()
        );

        $I->assertTrue(
            $dispatcher->wasForwarded()
        );

        $I->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $handler
        );

        $I->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $dispatcher->getActiveController()
        );

        $I->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $dispatcher->getLastController()
        );

        $I->assertTrue(
            $dispatcher->wasForwarded()
        );

        $I->assertEquals(
            'Phalcon\Test\Integration\Mvc\Dispatcher\Helper',
            $dispatcher->getPreviousNamespaceName()
        );

        $I->assertEquals(
            'dispatcher-test-default-two',
            $dispatcher->getPreviousControllerName()
        );

        $I->assertEquals(
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

        $I->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * Tests the string return value from a dispatcher
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testControllerActionReturnValueString(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setActionName('returnString');

        $handler = $dispatcher->dispatch();

        $I->assertEquals(
            'Phalcon\Test\Integration\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $I->assertEquals(
            'dispatcher-test-default',
            $dispatcher->getControllerName()
        );

        $I->assertEquals(
            'returnString',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
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

        $I->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * Tests the int return value from a dispatcher
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testControllerActionReturnValueInt(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setActionName('returnInt');

        $dispatcher->dispatch();

        $I->assertEquals(
            'Phalcon\Test\Integration\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $I->assertEquals(
            'dispatcher-test-default',
            $dispatcher->getControllerName()
        );

        $I->assertEquals(
            'returnInt',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
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

        $I->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * Tests parameter passing and return value from the dispatcher
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testParamsAndReturnValue(IntegrationTester $I)
    {
        $multiply = [4, 6];

        $dispatcher = $this->getDispatcher();

        $dispatcher->setActionName('multiply');
        $dispatcher->setParams($multiply);

        $dispatcher->dispatch();

        $I->assertEquals(
            'Phalcon\Test\Integration\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $I->assertEquals(
            'dispatcher-test-default',
            $dispatcher->getControllerName()
        );

        $I->assertEquals(
            'multiply',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            $multiply,
            $dispatcher->getParams()
        );

        $I->assertEquals(
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

        $I->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * Tests cyclical routing
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testCyclicalRouting(IntegrationTester $I)
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
        )
        ;

        $I->expectThrowable(
            new Exception(
                'Dispatcher has detected a cyclic routing causing stability problems',
                Exception::EXCEPTION_CYCLIC_ROUTING
            ),
            function () use ($dispatcher) {
                $dispatcher->dispatch();
            }
        );
    }

    /**
     * Tests invalid handler specified
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testHandlerInvalid(IntegrationTester $I)
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
        )
        ;

        $I->expectThrowable(
            new Exception(
                'Invalid handler returned from the services container',
                Exception::EXCEPTION_INVALID_HANDLER
            ),
            function () use ($dispatcher) {
                $dispatcher->dispatch();
            }
        );
    }

    /**
     * Tests dispatching without namespaces
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testNoNamespaces(IntegrationTester $I)
    {
        // Temporarily load non-namespaced class
        require_once __DIR__ . '/Helper/DispatcherTestDefaultNoNamespaceController.php';

        $dispatcher = $this->getDispatcher();

        $dispatcher->setNamespaceName('');
        $dispatcher->setControllerName('dispatcher-test-default-no-namespace');
        $dispatcher->setActionName('index');

        $handler = $dispatcher->dispatch();

        $I->assertNull(
            $dispatcher->getNamespaceName()
        );

        $I->assertEquals(
            'dispatcher-test-default-no-namespace',
            $dispatcher->getControllerName()
        );

        $I->assertEquals(
            'index',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            'DispatcherTestDefaultNoNamespaceController',
            $dispatcher->getControllerClass()
        );

        $I->assertFalse(
            $dispatcher->wasForwarded()
        );

        $I->assertInstanceOf(
            DispatcherTestDefaultNoNamespaceController::class,
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

        $I->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * Tests dispatching from a controller without namespace to one with
     * namespace namespaces
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testMixingNamespaceForward(IntegrationTester $I)
    {
        // Temporarily load non-namespaced class
        require_once __DIR__ . '/Helper/DispatcherTestDefaultNoNamespaceController.php';

        $dispatcher = $this->getDispatcher();

        $dispatcher->setNamespaceName('');
        $dispatcher->setControllerName('dispatcher-test-default-no-namespace');
        $dispatcher->setActionName('forwardExternal');

        $handler = $dispatcher->dispatch();

        $I->assertEquals(
            'Phalcon\Test\Integration\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $I->assertEquals(
            'dispatcher-test-default',
            $dispatcher->getControllerName()
        );

        $I->assertEquals(
            'index',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            DispatcherTestDefaultController::class,
            $dispatcher->getControllerClass()
        );

        $I->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $handler
        );

        $I->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $dispatcher->getActiveController()
        );

        $I->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $dispatcher->getLastController()
        );

        $I->assertTrue(
            $dispatcher->wasForwarded()
        );

        $I->assertNull(
            $dispatcher->getPreviousNamespaceName()
        );

        $I->assertEquals(
            'dispatcher-test-default-no-namespace',
            $dispatcher->getPreviousControllerName()
        );

        $I->assertEquals(
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

        $I->assertEquals(
            $expected,
            $this->getDispatcherListener()->getTrace()
        );
    }

    /**
     * Tests the last handler when an exception occurs and is forwarded
     * elsewhere
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testLastHandlerExceptionForward(IntegrationTester $I)
    {
        $beforeExceptionHandled = false;

        $dispatcher = $this->getDispatcher();

        $dispatcher->setActionName('exception');

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function ($event, $dispatcher) use (&$beforeExceptionHandled, $I) {
                $beforeExceptionHandled = true;

                $I->assertEquals(
                    'Phalcon\Test\Integration\Mvc\Dispatcher\Helper',
                    $dispatcher->getNamespaceName()
                );

                $I->assertEquals(
                    'dispatcher-test-default',
                    $dispatcher->getControllerName()
                );

                $I->assertEquals(
                    'exception',
                    $dispatcher->getActionName()
                );

                $I->assertEquals(
                    DispatcherTestDefaultController::class,
                    $dispatcher->getControllerClass()
                );

                $I->assertInstanceOf(
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
        )
        ;

        $handler = $dispatcher->dispatch();

        $I->assertTrue($beforeExceptionHandled);

        $I->assertEquals(
            'Phalcon\Test\Integration\Mvc\Dispatcher\Helper',
            $dispatcher->getNamespaceName()
        );

        $I->assertEquals(
            'dispatcher-test-default-two',
            $dispatcher->getControllerName()
        );

        $I->assertEquals(
            'index',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            DispatcherTestDefaultTwoController::class,
            $dispatcher->getControllerClass()
        );

        $I->assertInstanceOf(
            DispatcherTestDefaultTwoController::class,
            $dispatcher->getLastController()
        );
    }

    /**
     * Tests throwing a new exception inside before exception.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testExceptionInBeforeException(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check this test');

        $beforeExceptionHandled = false;
        $caughtException        = false;

        $dispatcher = $this->getDispatcher();

        $dispatcher->setActionName('exception');

        $dispatcher->getEventsManager()->attach(
            'dispatch:beforeException',
            function ($event, $dispatcher) use (&$beforeExceptionHandled, $I) {
                $beforeExceptionHandled = true;

                $I->assertEquals(
                    'Phalcon\Test\Integration\Mvc\Dispatcher\Helper',
                    $dispatcher->getNamespaceName()
                );

                $I->assertEquals(
                    'dispatcher-test-default',
                    $dispatcher->getControllerName()
                );

                $I->assertEquals(
                    'exception',
                    $dispatcher->getActionName()
                );

                $I->assertEquals(
                    DispatcherTestDefaultController::class,
                    $dispatcher->getControllerClass()
                );

                $I->assertEquals(
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
        )
        ;

        try {
            $handler = $dispatcher->dispatch();
        } catch (Exception $exception) {
            $caughtException = true;

            $I->assertEquals(
                'Custom error in before exception',
                $exception->getMessage()
            );
        } finally {
            $I->assertTrue($beforeExceptionHandled);
            $I->assertTrue($caughtException);

            // The string properties get updated

            $I->assertEquals(
                'Phalcon\Test\Integration\Mvc\Dispatcher\Helper',
                $dispatcher->getNamespaceName()
            );

            $I->assertEquals(
                'dispatcher-test-default-two',
                $dispatcher->getControllerName()
            );

            $I->assertEquals(
                'index',
                $dispatcher->getActionName()
            );

            $I->assertEquals(
                DispatcherTestDefaultTwoController::class,
                $dispatcher->getControllerClass()
            );

            // But not the last controller since dispatching didn't take place
            $I->assertInstanceOf(
                DispatcherTestDefaultController::class,
                $dispatcher->getLastController()
            );
        }
    }
}
