<?php

namespace Phalcon\Test\Integration\Mvc\Dispatcher;

use Exception;
use IntegrationTester;
use Phalcon\Dispatcher;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\BaseDispatcher;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\DispatcherTestDefaultController;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\DispatcherTestDefaultSimpleController;
use Phalcon\Test\Integration\Mvc\Dispatcher\Helper\DispatcherTestDefaultTwoController;

/**
 * \Phalcon\Test\Integration\Mvc\Dispatcher\DispatcherEventsTest
 * Tests the core functionality of the \Phalcon\Dispatcher and
 * Phalcon\Mvc\Dispatcher classes.
 *
 * @link          https://docs.phalconphp.com/en/latest/reference/dispatching.html
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          http://www.phalconphp.com
 * @author        Andres Gutierrez <andres@phalconphp.com>
 * @author        Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package       Phalcon\Test\Integration\Mvc\Dispatcher
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class DispatcherCest extends BaseDispatcher
{
    /**
     * Tests the default order of dispatch events for basic execution
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testDefaultDispatchLoopEvents(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();
        $handler    = $dispatcher->dispatch();

        $expected = 'Phalcon\Test\Integration\Mvc\Dispatcher\Helper';
        $actual   = $dispatcher->getNamespaceName();
        $I->assertEquals($expected, $actual);
        $expected = 'dispatcher-test-default';
        $actual   = $dispatcher->getControllerName();
        $I->assertEquals($expected, $actual);
        $expected = 'index';
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $expected = DispatcherTestDefaultController::class;
        $actual   = $dispatcher->getControllerClass();
        $I->assertEquals($expected, $actual);
        $actual = $dispatcher->wasForwarded();
        $I->assertFalse($actual);
        $class = DispatcherTestDefaultController::class;
        $I->assertInstanceOf($class, $handler);

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
        $actual   = $this->getDispatcherListener()->getTrace();
        $I->assertEquals($expected, $actual);
    }

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

        $expected = 'Phalcon\Test\Integration\Mvc\Dispatcher\Helper';
        $actual   = $dispatcher->getNamespaceName();
        $I->assertEquals($expected, $actual);
        $expected = 'dispatcher-test-default-simple';
        $actual   = $dispatcher->getControllerName();
        $I->assertEquals($expected, $actual);
        $expected = 'index';
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $expected = DispatcherTestDefaultSimpleController::class;
        $actual   = $dispatcher->getControllerClass();
        $I->assertEquals($expected, $actual);
        $actual = $dispatcher->wasForwarded();
        $I->assertFalse($actual);
        $class = DispatcherTestDefaultSimpleController::class;
        $I->assertInstanceOf($class, $handler);

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
        $actual   = $this->getDispatcherListener()->getTrace();
        $I->assertEquals($expected, $actual);
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

        $expected = 'Phalcon\Test\Integration\Mvc\Dispatcher\Helper';
        $actual   = $dispatcher->getNamespaceName();
        $I->assertEquals($expected, $actual);
        $expected = 'dispatcher-test-default';
        $actual   = $dispatcher->getControllerName();
        $I->assertEquals($expected, $actual);
        $expected = 'index2';
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $expected = $dummyParams;
        $actual   = $dispatcher->getParams();
        $I->assertEquals($expected, $actual);
        $expected = DispatcherTestDefaultController::class;
        $actual   = $dispatcher->getControllerClass();
        $I->assertEquals($expected, $actual);
        $actual = $dispatcher->wasForwarded();
        $I->assertTrue($actual);
        $class = DispatcherTestDefaultController::class;

        $I->assertInstanceOf($class, $handler);
        $class  = DispatcherTestDefaultController::class;
        $actual = $dispatcher->getActiveController();
        $I->assertInstanceOf($class, $actual);
        $class  = DispatcherTestDefaultController::class;
        $actual = $dispatcher->getLastController();
        $I->assertInstanceOf($class, $actual);

        $actual = $dispatcher->wasForwarded();
        $I->assertTrue($actual);

        $expected = 'Phalcon\Test\Integration\Mvc\Dispatcher\Helper';
        $actual   = $dispatcher->getPreviousNamespaceName();
        $I->assertEquals($expected, $actual);
        $expected = 'dispatcher-test-default';
        $actual   = $dispatcher->getPreviousControllerName();
        $I->assertEquals($expected, $actual);
        $expected = 'forwardLocal';
        $actual   = $dispatcher->getPreviousActionName();
        $I->assertEquals($expected, $actual);

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
        $actual   = $this->getDispatcherListener()->getTrace();
        $I->assertEquals($expected, $actual);
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

        $expected = 'Phalcon\Test\Integration\Mvc\Dispatcher\Helper';
        $actual   = $dispatcher->getNamespaceName();
        $I->assertEquals($expected, $actual);
        $expected = 'dispatcher-test-default';
        $actual   = $dispatcher->getControllerName();
        $I->assertEquals($expected, $actual);
        $expected = 'index';
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $expected = $dummyParams;
        $actual   = $dispatcher->getParams();
        $I->assertEquals($expected, $actual);
        $expected = DispatcherTestDefaultController::class;
        $actual   = $dispatcher->getControllerClass();
        $I->assertEquals($expected, $actual);
        $actual = $dispatcher->wasForwarded();
        $I->assertTrue($actual);
        $class = DispatcherTestDefaultController::class;

        $I->assertInstanceOf($class, $handler);
        $class  = DispatcherTestDefaultController::class;
        $actual = $dispatcher->getActiveController();
        $I->assertInstanceOf($class, $actual);
        $class  = DispatcherTestDefaultController::class;
        $actual = $dispatcher->getLastController();
        $I->assertInstanceOf($class, $actual);

        $actual = $dispatcher->wasForwarded();
        $I->assertTrue($actual);

        $expected = 'Phalcon\Test\Integration\Mvc\Dispatcher\Helper';
        $actual   = $dispatcher->getPreviousNamespaceName();
        $I->assertEquals($expected, $actual);
        $expected = 'dispatcher-test-default-two';
        $actual   = $dispatcher->getPreviousControllerName();
        $I->assertEquals($expected, $actual);
        $expected = 'forwardExternal';
        $actual   = $dispatcher->getPreviousActionName();
        $I->assertEquals($expected, $actual);

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
        $actual   = $this->getDispatcherListener()->getTrace();
        $I->assertEquals($expected, $actual);
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

        $expected = 'Phalcon\Test\Integration\Mvc\Dispatcher\Helper';
        $actual   = $dispatcher->getNamespaceName();
        $I->assertEquals($expected, $actual);
        $expected = 'dispatcher-test-default';
        $actual   = $dispatcher->getControllerName();
        $I->assertEquals($expected, $actual);
        $expected = 'returnString';
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $expected = DispatcherTestDefaultController::RETURN_VALUE_STRING;
        $actual   = $dispatcher->getReturnedValue();
        $I->assertEquals($expected, $actual);

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
        $actual   = $this->getDispatcherListener()->getTrace();
        $I->assertEquals($expected, $actual);
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

        $expected = 'Phalcon\Test\Integration\Mvc\Dispatcher\Helper';
        $actual   = $dispatcher->getNamespaceName();
        $I->assertEquals($expected, $actual);
        $expected = 'dispatcher-test-default';
        $actual   = $dispatcher->getControllerName();
        $I->assertEquals($expected, $actual);
        $expected = 'returnInt';
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $expected = DispatcherTestDefaultController::RETURN_VALUE_INT;
        $actual   = $dispatcher->getReturnedValue();
        $I->assertEquals($expected, $actual);

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
        $actual   = $this->getDispatcherListener()->getTrace();
        $I->assertEquals($expected, $actual);
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

        $expected = 'Phalcon\Test\Integration\Mvc\Dispatcher\Helper';
        $actual   = $dispatcher->getNamespaceName();
        $I->assertEquals($expected, $actual);
        $expected = 'dispatcher-test-default';
        $actual   = $dispatcher->getControllerName();
        $I->assertEquals($expected, $actual);
        $expected = 'multiply';
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $expected = $multiply;
        $actual   = $dispatcher->getParams();
        $I->assertEquals($expected, $actual);
        $expected = 24;
        $actual   = $dispatcher->getReturnedValue();
        $I->assertEquals($expected, $actual);

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
        $actual   = $this->getDispatcherListener()->getTrace();
        $I->assertEquals($expected, $actual);
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
                $dispatcher->forward(['action' => 'index2']);
            }
        )
        ;

        $I->expectThrowable(
            new Exception(
                'Dispatcher has detected a cyclic routing causing stability problems',
                Dispatcher::EXCEPTION_CYCLIC_ROUTING
            ),
            function () use ($dispatcher) {
                $dispatcher->dispatch();
            }
        );
    }

    /**
     * Tests handler not found
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testHandlerNotFound(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setControllerName('Non-Existent-Dispatcher-Handler');

        $I->expectThrowable(
            new Exception(
                'Phalcon\Test\Integration\Mvc\Dispatcher\Helper\Non' .
                'ExistentDispatcherHandlerController handler class cannot be loaded',
                Dispatcher::EXCEPTION_HANDLER_NOT_FOUND
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

        $this->getDI()->setShared($dispatcher->getHandlerClass(), function () {
            // Don't return an object
            return 3;
        })
        ;

        $I->expectThrowable(
            new Exception(
                'Invalid handler returned from the services container',
                Dispatcher::EXCEPTION_INVALID_HANDLER
            ),
            function () use ($dispatcher) {
                $dispatcher->dispatch();
            }
        );
    }

    /**
     * Tests invalid handler action specified
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testHandlerActionNotFound(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setActionName('Invalid-Dispatcher-Action-Name');

        $I->expectThrowable(
            new Exception(
                "Action 'Invalid-Dispatcher-Action-Name' was not found on handler 'dispatcher-test-default'",
                Dispatcher::EXCEPTION_ACTION_NOT_FOUND
            ),
            function () use ($dispatcher) {
                $dispatcher->dispatch();
            }
        );
    }

    /**
     * Tests the last handler
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testLastHandler(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->dispatch();

        $class  = DispatcherTestDefaultController::class;
        $actual = $dispatcher->getLastController();
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Tests the last handler on a forward
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testLastHandlerForward(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setActionName('forwardExternal');
        $dispatcher->dispatch();

        $class  = DispatcherTestDefaultTwoController::class;
        $actual = $dispatcher->getLastController();
        $I->assertInstanceOf($class, $actual);
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

        $actual = $dispatcher->getNamespaceName();
        $I->assertNull($actual);
        $expected = 'dispatcher-test-default-no-namespace';
        $actual   = $dispatcher->getControllerName();
        $I->assertEquals($expected, $actual);
        $expected = 'index';
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $class  = 'DispatcherTestDefaultNoNamespaceController';
        $actual = $dispatcher->getControllerClass();
        $I->assertEquals($class, $actual);

        $actual = $dispatcher->wasForwarded();
        $I->assertFalse($actual);
        $class = \DispatcherTestDefaultNoNamespaceController::class;
        $I->assertInstanceOf($class, $handler);

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
        $actual   = $this->getDispatcherListener()->getTrace();
        $I->assertEquals($expected, $actual);
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

        $expected = 'Phalcon\Test\Integration\Mvc\Dispatcher\Helper';
        $actual   = $dispatcher->getNamespaceName();
        $I->assertEquals($expected, $actual);
        $expected = 'dispatcher-test-default';
        $actual   = $dispatcher->getControllerName();
        $I->assertEquals($expected, $actual);
        $expected = 'index';
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $expected = DispatcherTestDefaultController::class;
        $actual   = $dispatcher->getControllerClass();
        $I->assertEquals($expected, $actual);
        $class  = DispatcherTestDefaultController::class;
        $actual = $handler;
        $I->assertInstanceOf($class, $actual);
        $actual = $dispatcher->getActiveController();
        $I->assertInstanceOf($class, $actual);
        $actual = $dispatcher->getLastController();
        $I->assertInstanceOf($class, $actual);

        $actual = $dispatcher->wasForwarded();
        $I->assertTrue($actual);
        $actual = $dispatcher->getPreviousNamespaceName();
        $I->assertNull($actual);
        $expected = 'dispatcher-test-default-no-namespace';
        $actual   = $dispatcher->getPreviousControllerName();
        $I->assertEquals($expected, $actual);
        $expected = 'forwardExternal';
        $actual   = $dispatcher->getPreviousActionName();
        $I->assertEquals($expected, $actual);

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
        $actual   = $this->getDispatcherListener()->getTrace();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests dispatcher resolve capability from defaults
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testDefaultResolve(IntegrationTester $I)
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setNamespaceName('Foo');
        $dispatcher->setControllerName('');
        $dispatcher->setActionName('');

        $expected = 'Foo';
        $actual   = $dispatcher->getNamespaceName();
        $I->assertEquals($expected, $actual);
        $expected = null;
        $actual   = $dispatcher->getControllerName();
        $I->assertEquals($expected, $actual);
        $expected = null;
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $expected = 'Foo\IndexController';
        $actual   = $dispatcher->getControllerClass();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests directly calling controller's action via the dispatcher manually
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testManualCallAction(IntegrationTester $I)
    {
        $multiply = [5, 6];

        $controller = new DispatcherTestDefaultController();
        $controller->setDI($this->getDI());

        $returnValue = $this->getDispatcher()->callActionMethod($controller, 'multiplyAction', $multiply);

        $expected = 30;
        $actual   = $returnValue;
        $I->assertEquals($expected, $actual);
        $expected = ['multiplyAction'];
        $actual   = $this->getDispatcherListener()->getTrace();
        $I->assertEquals($expected, $actual);
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

                $expected = 'Phalcon\Test\Integration\Mvc\Dispatcher\Helper';
                $actual   = $dispatcher->getNamespaceName();
                $I->assertEquals($expected, $actual);
                $expected = 'dispatcher-test-default';
                $actual   = $dispatcher->getControllerName();
                $I->assertEquals($expected, $actual);
                $expected = 'exception';
                $actual   = $dispatcher->getActionName();
                $I->assertEquals($expected, $actual);
                $expected = DispatcherTestDefaultController::class;
                $actual   = $dispatcher->getControllerClass();
                $I->assertEquals($expected, $actual);
                $class  = DispatcherTestDefaultController::class;
                $actual = $dispatcher->getLastController();
                $I->assertInstanceOf($class, $actual);

                $dispatcher->forward([
                    'controller' => 'dispatcher-test-default-two',
                    'action'     => 'index',
                ]);

                return false;
            }
        )
        ;

        $handler = $dispatcher->dispatch();

        $I->assertTrue($beforeExceptionHandled);
        $expected = 'Phalcon\Test\Integration\Mvc\Dispatcher\Helper';
        $actual   = $dispatcher->getNamespaceName();
        $I->assertEquals($expected, $actual);
        $expected = 'dispatcher-test-default-two';
        $actual   = $dispatcher->getControllerName();
        $I->assertEquals($expected, $actual);
        $expected = 'index';
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $expected = DispatcherTestDefaultTwoController::class;
        $actual   = $dispatcher->getControllerClass();
        $I->assertEquals($expected, $actual);
        $class  = DispatcherTestDefaultTwoController::class;
        $actual = $dispatcher->getLastController();
        $I->assertInstanceOf($class, $actual);
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
                $expected               = 'Phalcon\Test\Integration\Mvc\Dispatcher\Helper';
                $actual                 = $dispatcher->getNamespaceName();
                $I->assertEquals($expected, $actual);
                $expected = 'dispatcher-test-default';
                $actual   = $dispatcher->getControllerName();
                $I->assertEquals($expected, $actual);
                $expected = 'exception';
                $actual   = $dispatcher->getActionName();
                $I->assertEquals($expected, $actual);
                $expected = DispatcherTestDefaultController::class;
                $actual   = $dispatcher->getControllerClass();
                $I->assertEquals($expected, $actual);

                $expected = DispatcherTestDefaultController::class;
                $actual   = $dispatcher->getLastController();
                $I->assertEquals($expected, $actual);
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
            $I->assertEquals('Custom error in before exception', $exception->getMessage());
        } finally {
            $I->assertTrue($beforeExceptionHandled);
            $I->assertTrue($caughtException);
            // The string properties get updated
            $expected = 'Phalcon\Test\Integration\Mvc\Dispatcher\Helper';
            $actual   = $dispatcher->getNamespaceName();
            $I->assertEquals($expected, $actual);
            $expected = 'dispatcher-test-default-two';
            $actual   = $dispatcher->getControllerName();
            $I->assertEquals($expected, $actual);
            $expected = 'index';
            $actual   = $dispatcher->getActionName();
            $I->assertEquals($expected, $actual);
            $expected = DispatcherTestDefaultTwoController::class;
            $actual   = $dispatcher->getControllerClass();
            $I->assertEquals($expected, $actual);
            // But not the last controller since dispatching didn't take place
            $class  = DispatcherTestDefaultController::class;
            $actual = $dispatcher->getLastController();
            $I->assertInstanceOf($class . $actual);
        }
    }
}
