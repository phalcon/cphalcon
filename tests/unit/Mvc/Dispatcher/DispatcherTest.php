<?php

namespace Phalcon\Test\Unit\Mvc\Dispatcher;

use Exception;
use Phalcon\Dispatcher;
use Phalcon\Test\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;
use Phalcon\Test\Unit\Mvc\Dispatcher\Helper\DispatcherTestDefaultController;
use Phalcon\Test\Unit\Mvc\Dispatcher\Helper\DispatcherTestDefaultTwoController;
use Phalcon\Test\Unit\Mvc\Dispatcher\Helper\DispatcherTestDefaultSimpleController;

/**
 * \Phalcon\Test\Unit\Mvc\Dispatcher\DispatcherEventsTest
 * Tests the core functionality of the \Phalcon\Dispatcher and Phalcon\Mvc\Dispatcher classes.
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
class DispatcherTest extends BaseDispatcher
{
    /**
     * Tests the default order of dispatch events for basic execution
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testDefaultDispatchLoopEvents()
    {
        $this->specify(
            'The order of dispatch events is not correct',
            function () {
                $dispatcher = $this->getDispatcher();
                $handler = $dispatcher->dispatch();

                expect($dispatcher->getNamespaceName())->equals('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
                expect($dispatcher->getControllerName())->equals('dispatcher-test-default');
                expect($dispatcher->getActionName())->equals('index');
                expect($dispatcher->wasForwarded())->false();
                expect($dispatcher->getControllerClass())->equals(DispatcherTestDefaultController::class);
                expect($handler)->isInstanceOf(DispatcherTestDefaultController::class);

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
     * Tests the default order of dispatch events for basic execution with no custom method handlers
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testDefaultDispatchLoopEventsWithNoHandlers()
    {
        $this->specify(
            'The order of dispatch events is not correct',
            function () {
                $dispatcher = $this->getDispatcher();
                $dispatcher->setControllerName('dispatcher-test-default-simple');
                $handler = $dispatcher->dispatch();

                expect($dispatcher->getNamespaceName())->equals('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
                expect($dispatcher->getControllerName())->equals('dispatcher-test-default-simple');
                expect($dispatcher->getActionName())->equals('index');
                expect($dispatcher->wasForwarded())->false();
                expect($dispatcher->getControllerClass())->equals(DispatcherTestDefaultSimpleController::class);
                expect($handler)->isInstanceOf(DispatcherTestDefaultSimpleController::class);

                expect($this->getDispatcherListener()->getTrace())->equals([
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
                    'afterDispatchLoop'
                ]);
            }
        );
    }

    /**
     * Tests the forwarding inside a controller's action.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testControllerActionLocalForward()
    {
        $this->specify(
            'Forwarding inside a Controller action should immediately begin the next dispatch cycle',
            function () {
                $dummyParams = [
                    'param1' => 1,
                    'param2' => 2
                ];

                $dispatcher = $this->getDispatcher();
                $dispatcher->setControllerName('dispatcher-test-default');
                $dispatcher->setActionName('forwardLocal');
                $dispatcher->setParams($dummyParams);
                $handler = $dispatcher->dispatch();

                expect($dispatcher->getNamespaceName())->equals('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
                expect($dispatcher->getControllerName())->equals('dispatcher-test-default');
                expect($dispatcher->getActionName())->equals('index2');
                expect($dispatcher->getParams())->equals($dummyParams);
                expect($dispatcher->getControllerClass())->equals(DispatcherTestDefaultController::class);
                expect($handler)->isInstanceOf(DispatcherTestDefaultController::class);
                expect($dispatcher->getActiveController())->isInstanceOf(DispatcherTestDefaultController::class);
                expect($dispatcher->getLastController())->isInstanceOf(DispatcherTestDefaultController::class);

                expect($dispatcher->wasForwarded())->true();
                expect($dispatcher->getPreviousNamespaceName())->equals('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
                expect($dispatcher->getPreviousControllerName())->equals('dispatcher-test-default');
                expect($dispatcher->getPreviousActionName())->equals('forwardLocal');

                expect($this->getDispatcherListener()->getTrace())->equals([
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
                    'afterDispatchLoop'
                ]);
            }
        );
    }

    /**
     * Tests the forwarding inside a controller's action.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testControllerActionExternalForward()
    {
        $this->specify(
            'Forwarding inside a Controller action should immediately begin the next dispatch cycle',
            function () {
                $dummyParams = [
                    'param1' => 1,
                    'param2' => 2
                ];

                $dispatcher = $this->getDispatcher();
                $dispatcher->setControllerName('dispatcher-test-default-two');
                $dispatcher->setActionName('forwardExternal');
                $dispatcher->setParams($dummyParams);
                $handler = $dispatcher->dispatch();

                expect($dispatcher->getNamespaceName())->equals('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
                expect($dispatcher->getControllerName())->equals('dispatcher-test-default');
                expect($dispatcher->getActionName())->equals('index');
                expect($dispatcher->getParams())->equals($dummyParams);
                expect($dispatcher->getControllerClass())->equals(DispatcherTestDefaultController::class);
                expect($handler)->isInstanceOf(DispatcherTestDefaultController::class);
                expect($dispatcher->getActiveController())->isInstanceOf(DispatcherTestDefaultController::class);
                expect($dispatcher->getLastController())->isInstanceOf(DispatcherTestDefaultController::class);

                expect($dispatcher->wasForwarded())->true();
                expect($dispatcher->getPreviousNamespaceName())->equals('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
                expect($dispatcher->getPreviousControllerName())->equals('dispatcher-test-default-two');
                expect($dispatcher->getPreviousActionName())->equals('forwardExternal');

                expect($this->getDispatcherListener()->getTrace())->equals([
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
                    'afterDispatchLoop'
                ]);
            }
        );
    }

    /**
     * Tests the string return value from a dispatcher
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testControllerActionReturnValueString()
    {
        $this->specify(
            'Returning a string in the dispatcher should be properly saved in the dispatcher\'s return value',
            function () {
                $dispatcher = $this->getDispatcher();
                $dispatcher->setActionName('returnString');
                $handler = $dispatcher->dispatch();

                expect($dispatcher->getNamespaceName())->equals('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
                expect($dispatcher->getControllerName())->equals('dispatcher-test-default');
                expect($dispatcher->getActionName())->equals('returnString');
                expect($dispatcher->getReturnedValue())->equals(DispatcherTestDefaultController::RETURN_VALUE_STRING);

                expect($this->getDispatcherListener()->getTrace())->equals([
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
                    'afterDispatchLoop'
                ]);
            }
        );
    }

    /**
     * Tests the int return value from a dispatcher
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testControllerActionReturnValueInt()
    {
        $this->specify(
            'Returning an integer in the dispatcher should be properly saved in the dispatcher\'s return value',
            function () {
                $dispatcher = $this->getDispatcher();
                $dispatcher->setActionName('returnInt');
                $dispatcher->dispatch();

                expect($dispatcher->getNamespaceName())->equals('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
                expect($dispatcher->getControllerName())->equals('dispatcher-test-default');
                expect($dispatcher->getActionName())->equals('returnInt');
                expect($dispatcher->getReturnedValue())->equals(DispatcherTestDefaultController::RETURN_VALUE_INT);

                expect($this->getDispatcherListener()->getTrace())->equals([
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
                    'afterDispatchLoop'
                ]);
            }
        );
    }

    /**
     * Tests parameter passing and return value from the dispatcher
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testParamsAndReturnValue()
    {
        $this->specify(
            'Returning an integer in the dispatcher should be properly saved in the dispatcher\'s return value',
            function () {
                $multiply = [ 4, 6 ];

                $dispatcher = $this->getDispatcher();
                $dispatcher->setActionName('multiply');
                $dispatcher->setParams($multiply);
                $dispatcher->dispatch();

                expect($dispatcher->getNamespaceName())->equals('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
                expect($dispatcher->getControllerName())->equals('dispatcher-test-default');
                expect($dispatcher->getActionName())->equals('multiply');
                expect($dispatcher->getParams())->equals($multiply);
                expect($dispatcher->getReturnedValue())->equals(24);

                expect($this->getDispatcherListener()->getTrace())->equals([
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
                    'afterDispatchLoop'
                ]);
            }
        );
    }

    /**
     * Tests cyclical routing
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testCyclicalRouting()
    {
        $this->specify(
            'Specifying an invalid handler should result in a Dispatch exception with code === `Dispatcher::EXCEPTION_HANDLER_NOT_FOUND`',
            function () {
                $dispatcher = $this->getDispatcher();
                $dispatcher->getEventsManager()->attach('dispatch:beforeDispatch', function ($event, $dispatcher) {
                    $dispatcher->forward(['action' => 'index2']);
                });

                try {
                    $dispatcher->dispatch();
                } catch (Exception $exception) {
                    expect($exception->getCode())->equals(Dispatcher::EXCEPTION_CYCLIC_ROUTING);
                }
            }
        );
    }

    /**
     * Tests handler not found
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testHandlerNotFound()
    {
        $this->specify(
            'Specifying an non-existent handler should result in a Dispatch exception with code === `Dispatcher::EXCEPTION_HANDLER_NOT_FOUND`',
            function () {
                $dispatcher = $this->getDispatcher();
                $dispatcher->setControllerName('Non-Existent-Dispatcher-Handler');

                try {
                    $dispatcher->dispatch();
                } catch (Exception $exception) {
                    expect($exception->getCode())->equals(Dispatcher::EXCEPTION_HANDLER_NOT_FOUND);
                }
            }
        );
    }

    /**
     * Tests invalid handler specified
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testHandlerInvalid()
    {
        $this->specify(
            'Specifying an invalid handler should result in a Dispatch exception with code === `Dispatcher::EXCEPTION_INVALID_HANDLER`',
            function () {
                $dispatcher = $this->getDispatcher();
                $dispatcher->setNamespaceName(null);
                $dispatcher->setControllerName('Test');

                $this->getDI()->setShared($dispatcher->getHandlerClass(), function () {
                    // Don't return an object
                    return 3;
                });

                try {
                    $dispatcher->dispatch();
                } catch (Exception $exception) {
                    expect($exception->getCode())->equals(Dispatcher::EXCEPTION_INVALID_HANDLER);
                }
            }
        );
    }

    /**
     * Tests invalid handler action specified
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testHandlerActionNotFound()
    {
        $this->specify(
            'Specifying an invalid handler action should result in a Dispatch exception with code === `Dispatcher::EXCEPTION_ACTION_NOT_FOUND`',
            function () {
                $dispatcher = $this->getDispatcher();
                $dispatcher->setActionName('Invalid-Dispatcher-Action-Name');

                try {
                    $dispatcher->dispatch();
                } catch (Exception $exception) {
                    expect($exception->getCode())->equals(Dispatcher::EXCEPTION_ACTION_NOT_FOUND);
                }
            }
        );
    }

    /**
     * Tests the last handler
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testLastHandler()
    {
        $this->specify(
            'The last handler should be the DispatcherTestDefaultController',
            function () {
                $dispatcher = $this->getDispatcher();
                $dispatcher->dispatch();

                expect($dispatcher->getLastController() instanceof DispatcherTestDefaultController)->equals(true);
            }
        );
    }

    /**
     * Tests the last handler on a forward
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testLastHandlerForward()
    {
        $this->specify(
            'The last handler should be the DispatcherTestDefaultTwoController after forwarding',
            function () {
                $dispatcher = $this->getDispatcher();
                $dispatcher->setActionName('forwardExternal');
                $dispatcher->dispatch();

                expect($dispatcher->getLastController() instanceof DispatcherTestDefaultTwoController)->equals(true);
            }
        );
    }

    /**
     * Tests dispatching without namespaces
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testNoNamespaces()
    {
        // Temporarilly load non-namespaced class
        require_once __DIR__ . '/Helper/DispatcherTestDefaultNoNamespaceController.php';

        $this->specify(
            'Dispatching without namespaces should work properly',
            function () {
                $dispatcher = $this->getDispatcher();
                $dispatcher->setNamespaceName(null);
                $dispatcher->setControllerName('dispatcher-test-default-no-namespace');
                $dispatcher->setActionName('index');
                $handler = $dispatcher->dispatch();

                expect($dispatcher->getNamespaceName())->equals(null);
                expect($dispatcher->getControllerName())->equals('dispatcher-test-default-no-namespace');
                expect($dispatcher->getActionName())->equals('index');
                expect($dispatcher->wasForwarded())->false();
                expect($dispatcher->getControllerClass())->equals(\DispatcherTestDefaultNoNamespaceController::class);
                expect($handler)->isInstanceOf(\DispatcherTestDefaultNoNamespaceController::class);

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
     * Tests dispatching from a controller without namespace to one with namespace namespaces
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testMixingNamespaceForward()
    {
        // Temporarilly load non-namespaced class
        require_once __DIR__ . '/Helper/DispatcherTestDefaultNoNamespaceController.php';

        $this->specify(
            'Dispatching and forwarding between controllers with or without namespaces should work properly',
            function () {
                $dispatcher = $this->getDispatcher();
                $dispatcher->setNamespaceName(null);
                $dispatcher->setControllerName('dispatcher-test-default-no-namespace');
                $dispatcher->setActionName('forwardExternal');
                $handler = $dispatcher->dispatch();

                expect($dispatcher->getNamespaceName())->equals('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
                expect($dispatcher->getControllerName())->equals('dispatcher-test-default');
                expect($dispatcher->getActionName())->equals('index');
                expect($dispatcher->getControllerClass())->equals(DispatcherTestDefaultController::class);
                expect($handler)->isInstanceOf(DispatcherTestDefaultController::class);
                expect($dispatcher->getActiveController())->isInstanceOf(DispatcherTestDefaultController::class);
                expect($dispatcher->getLastController())->isInstanceOf(DispatcherTestDefaultController::class);

                expect($dispatcher->wasForwarded())->true();
                expect($dispatcher->getPreviousNamespaceName())->equals(null);
                expect($dispatcher->getPreviousControllerName())->equals('dispatcher-test-default-no-namespace');
                expect($dispatcher->getPreviousActionName())->equals('forwardExternal');

                expect($this->getDispatcherListener()->getTrace())->equals([
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
                    'afterDispatchLoop'
                ]);
            }
        );
    }

    /**
     * Tests dispatcher resolve capability from defaults
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testDefaultResolve()
    {
        $this->specify(
            'Dispatching and forwarding between controllers with or without namespaces should work properly',
            function () {
                $dispatcher = $this->getDispatcher();
                $dispatcher->setNamespaceName('Foo');
                $dispatcher->setControllerName(null);
                $dispatcher->setActionName(null);

                expect($dispatcher->getNamespaceName())->equals('Foo');
                expect($dispatcher->getControllerName())->equals(null);
                expect($dispatcher->getActionName())->equals(null);
                expect($dispatcher->getControllerClass())->equals('Foo\IndexController');
            }
        );
    }

    /**
     * Tests directly calling controller's action via the dispatcher manually
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testManualCallAction()
    {
        $this->specify(
            'Manually calling the dispatcher action should work similarly to dispaching without any events dispatch.',
            function () {
                $multiply = [ 5, 6 ];

                $controller = new DispatcherTestDefaultController();
                $controller->setDI($this->getDI());

                $returnValue = $this->getDispatcher()->callActionMethod($controller, 'multiplyAction', $multiply);

                expect($returnValue)->equals(30);
                expect($this->getDispatcherListener()->getTrace())->equals([
                    'multiplyAction'
                ]);
            }
        );
    }

    /**
     * Tests the last handler when an exception occurs and is forwarded elsewhere
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testLastHandlerExceptionForward()
    {
        $this->specify(
            'Handling an exception with a new dispatch forward should not bubble the exception.',
            function () {
                $beforeExceptionHandled = false;

                $dispatcher = $this->getDispatcher();
                $dispatcher->setActionName('exception');
                $dispatcher->getEventsManager()->attach('dispatch:beforeException', function ($event, $dispatcher) use (&$beforeExceptionHandled) {
                    $beforeExceptionHandled = true;

                    expect($dispatcher->getNamespaceName())->equals('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
                    expect($dispatcher->getControllerName())->equals('dispatcher-test-default');
                    expect($dispatcher->getActionName())->equals('exception');
                    expect($dispatcher->getControllerClass())->equals(DispatcherTestDefaultController::class);
                    expect($dispatcher->getLastController())->isInstanceOf(DispatcherTestDefaultController::class);

                    $dispatcher->forward([
                        'controller' => 'dispatcher-test-default-two',
                        'action' => 'index'
                    ]);

                    return false;
                });

                $handler = $dispatcher->dispatch();

                expect($beforeExceptionHandled)->true();
                expect($dispatcher->getNamespaceName())->equals('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
                expect($dispatcher->getControllerName())->equals('dispatcher-test-default-two');
                expect($dispatcher->getActionName())->equals('index');
                expect($dispatcher->getControllerClass())->equals(DispatcherTestDefaultTwoController::class);
                expect($dispatcher->getLastController())->isInstanceOf(DispatcherTestDefaultTwoController::class);
            }
        );
    }

    /**
     * Tests throwing a new exception inside before exception.
     *
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testExceptionInBeforeException()
    {
        $this->specify(
            'Throwing a new exceptio in "beforeException" should bubble the exception.',
            function () {
                $beforeExceptionHandled = false;
                $caughtException = false;

                $dispatcher = $this->getDispatcher();
                $dispatcher->setActionName('exception');
                $dispatcher->getEventsManager()->attach('dispatch:beforeException', function ($event, $dispatcher) use (&$beforeExceptionHandled) {
                    $beforeExceptionHandled = true;

                    expect($dispatcher->getNamespaceName())->equals('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
                    expect($dispatcher->getControllerName())->equals('dispatcher-test-default');
                    expect($dispatcher->getActionName())->equals('exception');
                    expect($dispatcher->getControllerClass())->equals(DispatcherTestDefaultController::class);
                    expect($dispatcher->getLastController())->isInstanceOf(DispatcherTestDefaultController::class);

                    // Forwarding; however, will throw a new exception preventing this
                    $dispatcher->forward([
                        'controller' => 'dispatcher-test-default-two',
                        'action' => 'index'
                    ]);

                    throw new Exception('Custom error in before exception');
                });

                try {
                    $handler = $dispatcher->dispatch();
                } catch (Exception $exception) {
                    $caughtException = true;
                    expect($exception->getMessage())->equals('Custom error in before exception');
                } finally {
                    expect($beforeExceptionHandled)->true();
                    expect($caughtException)->true();

                    // The string properties get updated
                    expect($dispatcher->getNamespaceName())->equals('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
                    expect($dispatcher->getControllerName())->equals('dispatcher-test-default-two');
                    expect($dispatcher->getActionName())->equals('index');
                    expect($dispatcher->getControllerClass())->equals(DispatcherTestDefaultTwoController::class);

                    // But not the last controller since dispatching didn't take place
                    expect($dispatcher->getLastController())->isInstanceOf(DispatcherTestDefaultController::class);
                }
            }
        );
    }
}
