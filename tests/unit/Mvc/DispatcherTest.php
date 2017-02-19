<?php

namespace Phalcon\Test\Unit\Mvc;

use Phalcon\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Http\Response;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Mvc\DispatcherTest
 * Tests the Phalcon\Mvc\Dispatcher component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class DispatcherTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        Di::reset();
    }



    public function testDispatcher()
    {
        $this->specify(
            "Dispatcher doesn't throw exception when handler can't be loaded",
            function () {
                $di = new Di();

                $di->set("response", new Response());

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                expect($dispatcher->getDI())->isInstanceOf("Phalcon\\Di");

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("index");
                $dispatcher->setActionName("index");
                $dispatcher->setParams([]);

                $dispatcher->dispatch();
            },
            [
                "throws" => [
                    \Phalcon\Mvc\Dispatcher\Exception::class,
                    "IndexController handler class cannot be loaded"
                ]
            ]
        );

        $this->specify(
            "Dispatcher doesn't throw exception when handler can't be loaded (2)",
            function () {
                $di = new Di();

                $di->set("response", new Response());

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                expect($dispatcher->getDI())->isInstanceOf("Phalcon\\Di");

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("essai");
                $dispatcher->setActionName("index");
                $dispatcher->setParams([]);

                $dispatcher->dispatch();
            },
            [
                "throws" => [
                    \Phalcon\Mvc\Dispatcher\Exception::class,
                    "EssaiController handler class cannot be loaded"
                ]
            ]
        );

        $this->specify(
            "Dispatcher doesn't throw exception when handler can't be loaded (3)",
            function () {
                $di = new Di();

                $di->set("response", new Response());

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                expect($dispatcher->getDI())->isInstanceOf("Phalcon\\Di");

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("test0");
                $dispatcher->setActionName("index");
                $dispatcher->setParams([]);

                $dispatcher->dispatch();
            },
            [
                "throws" => [
                    \Phalcon\Mvc\Dispatcher\Exception::class,
                    "Test0Controller handler class cannot be loaded"
                ]
            ]
        );

        $this->specify(
            "Dispatcher doesn't throw exception when action can't be found",
            function () {
                $di = new Di();

                $di->set("response", new Response());

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                expect($dispatcher->getDI())->isInstanceOf("Phalcon\\Di");

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("test1");
                $dispatcher->setActionName("index");
                $dispatcher->setParams([]);

                $dispatcher->dispatch();
            },
            [
                "throws" => [
                    \Phalcon\Mvc\Dispatcher\Exception::class,
                    "Action 'index' was not found on handler 'test1'"
                ]
            ]
        );

        $this->specify(
            "Dispatcher doesn't return controller after dispatching",
            function () {
                $di = new Di();

                $di->set("response", new Response());

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                expect($dispatcher->getDI())->isInstanceOf("Phalcon\\Di");

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("test2");
                $dispatcher->setActionName("index");
                $dispatcher->setParams([]);
                $controller = $dispatcher->dispatch();
                expect($controller)->isInstanceOf("Test2Controller");
            }
        );

        $this->specify(
            "Dispatcher doesn't throw exception when action can't be found (2)",
            function () {
                $di = new Di();

                $di->set("response", new Response());

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                expect($dispatcher->getDI())->isInstanceOf("Phalcon\\Di");

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("test2");
                $dispatcher->setActionName("essai");
                $dispatcher->setParams([]);

                $dispatcher->dispatch();
            },
            [
                "throws" => [
                    \Phalcon\Mvc\Dispatcher\Exception::class,
                    "Action 'essai' was not found on handler 'test2'"
                ]
            ]
        );

        $this->specify(
            "Dispatcher doesn't work as expected",
            function () {
                $di = new Di();

                $di->set("response", new Response());

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                expect($dispatcher->getDI())->isInstanceOf("Phalcon\\Di");

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("test2");
                $dispatcher->setActionName("other");
                $dispatcher->setParams([]);
                $controller = $dispatcher->dispatch();
                expect($controller)->isInstanceOf("Test2Controller");
            }
        );

        $this->specify(
            "Dispatcher doesn't work as expected (2)",
            function () {
                $di = new Di();

                $di->set("response", new Response());

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                expect($dispatcher->getDI())->isInstanceOf("Phalcon\\Di");

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("test2");
                $dispatcher->setActionName("another");
                $dispatcher->setParams([]);
                $dispatcher->dispatch();
                $value = $dispatcher->getReturnedValue();
                expect($value)->equals(100);
            }
        );

        $this->specify(
            "Dispatcher doesn't work as expected (3)",
            function () {
                $di = new Di();

                $di->set("response", new Response());

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                expect($dispatcher->getDI())->isInstanceOf("Phalcon\\Di");

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("test2");
                $dispatcher->setActionName("anotherTwo");
                $dispatcher->setParams([2, "3"]);
                $dispatcher->dispatch();
                $value = $dispatcher->getReturnedValue();
                expect($value)->equals(5);
            }
        );

        $this->specify(
            "Dispatcher doesn't work as expected (4)",
            function () {
                $di = new Di();

                $di->set("response", new Response());

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                expect($dispatcher->getDI())->isInstanceOf("Phalcon\\Di");

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("test2");
                $dispatcher->setActionName("anotherthree");
                $dispatcher->setParams([]);
                $dispatcher->dispatch();
                $value = $dispatcher->getActionName();
                expect($value)->equals("anotherfour");
                $value = $dispatcher->getReturnedValue();
                expect($value)->equals(120);
            }
        );

        $this->specify(
            "Dispatcher doesn't work as expected (5)",
            function () {
                $di = new Di();

                $di->set("response", new Response());

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                expect($dispatcher->getDI())->isInstanceOf("Phalcon\\Di");

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("test2");
                $dispatcher->setActionName("anotherFive");
                $dispatcher->setParams(["param1" => 2, "param2" => 3]);
                $dispatcher->dispatch();
                $value = $dispatcher->getReturnedValue();
                expect($value)->equals(5);
            }
        );

        $this->specify(
            "Dispatcher doesn't work as expected (6)",
            function () {
                $di = new Di();

                $di->set("response", new Response());

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                expect($dispatcher->getDI())->isInstanceOf("Phalcon\\Di");

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("test7");
                $dispatcher->setActionName("service");
                $dispatcher->setParams([]);
                $dispatcher->dispatch();
                $value = $dispatcher->getReturnedValue();
                expect($value)->equals("hello");

                $value = $dispatcher->getControllerClass();
                expect($value)->equals("Test7Controller");
            }
        );
    }

    public function testDispatcherForward()
    {
        $this->specify(
            "MVC Dispatcher doesn't forward properly",
            function () {
                $di = new Di();

                //$di->set("response", new Response());

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("test2");
                $dispatcher->setActionName("index");
                $dispatcher->setParams([]);

                $dispatcher->forward(
                    [
                        "controller" => "test3",
                        "action"     => "other",
                    ]
                );

                $value = $dispatcher->getControllerName();
                expect($value)->equals("test3");

                $value = $dispatcher->getActionName();
                expect($value)->equals("other");

                $value = $dispatcher->getPreviousNamespaceName();
                expect($value)->equals("");

                $value = $dispatcher->getPreviousControllerName();
                expect($value)->equals("test2");

                $value = $dispatcher->getPreviousActionName();
                expect($value)->equals("index");
            }
        );
    }

    public function testDispatcherForward2()
    {
        $this->specify(
            "MVC Dispatcher doesn't forward properly (2)",
            function () {
                $di = new Di();

                //$di->set("response", new Response());

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("test2");
                $dispatcher->setActionName("index");
                $dispatcher->setParams([]);

                $dispatcher->forward(
                    [
                        "namespace"  => "MyNamespace\\Controllers",
                        "controller" => "namespaced",
                        "action"     => "index"
                    ]
                );

                $value = $dispatcher->getNamespaceName();
                expect($value)->equals("MyNamespace\\Controllers");

                $value = $dispatcher->getControllerName();
                expect($value)->equals("namespaced");

                $value = $dispatcher->getActionName();
                expect($value)->equals("index");

                $value = $dispatcher->getPreviousNamespaceName();
                expect($value)->equals("");

                $value = $dispatcher->getPreviousControllerName();
                expect($value)->equals("test2");

                $value = $dispatcher->getPreviousActionName();
                expect($value)->equals("index");
            }
        );
    }

    public function testGetControllerClass()
    {
        $this->specify(
            "MVC Dispatcher doesn't calculate the controller class properly",
            function () {
                $di = new Di();

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);

                $di->set("dispatcher", $dispatcher);

                // With namespace
                $dispatcher->setNamespaceName("Foo\Bar");
                $dispatcher->setControllerName("test");

                $value = $dispatcher->getControllerClass();
                expect($value)->equals("Foo\Bar\TestController");

                // Without namespace
                $dispatcher->setNamespaceName(null);
                $dispatcher->setControllerName("Test");

                $value = $dispatcher->getControllerClass();
                expect($value)->equals("TestController");
            }
        );
    }

    public function testDefaultsResolve()
    {
        $this->specify(
            "Dispatcher defaults are not resolved correctly",
            function () {
                $di = new Di();

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);

                $di->set("dispatcher", $dispatcher);

                $dispatcher->setDefaultNamespace("Foo");

                $value = $dispatcher->getControllerClass();
                expect($value)->equals("Foo\IndexController");
            }
        );
    }

    public function testCallActionMethod()
    {
        $this->specify(
            "Action method isn't called properly",
            function () {
                $di = new FactoryDefault();

                $dispatcher = new Dispatcher();

                $di->setShared("dispatcher", $dispatcher);

                $dispatcher->setDI($di);

                $mainTask = new \Test2Controller();
                $mainTask->setDI($di);

                $actionMethod = $dispatcher->callActionMethod(
                    $mainTask,
                    "anotherTwoAction",
                    [1, 2]
                );

                expect($actionMethod)->equals(3);
            }
        );
    }

    public function testLastController()
    {
        $this->specify(
            "Dispatcher doesn't store the last controller",
            function () {
                $di = new Di();
            
                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                
                $di->set("dispatcher", $dispatcher);

                $dispatcher->setControllerName("failure");
                $dispatcher->setActionName("exception");
                $dispatcher->setParams([]);

                try {
                    $dispatcher->dispatch();
                    expect(false)->true();
                } catch (\Exception $e) {
                    expect($e->getMessage())->equals("failure by exception");
                    expect($dispatcher->getLastController())->isInstanceOf("FailureController");
                }
            }
        );
    }
}
