<?php

namespace Phalcon\Test\Unit\Cli;

use Phalcon\Cli\Dispatcher;
use Phalcon\Di\FactoryDefault\Cli as CliFactoryDefault;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Cli\DispatcherTest
 * Tests the \Phalcon\Cli\Dispatcher component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Cli
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class DispatcherTest extends UnitTest
{
    public function testDispatcher()
    {
        $this->specify(
            "CLI Dispatcher doesn't work with typical parameters",
            function () {
                $di = new CliFactoryDefault();

                $di->set(
                    'data',
                    function () {
                        return "data";
                    }
                );

                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                $dispatcher->dispatch();
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('main');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('mainAction');

                $dispatcher->setTaskName('echo');
                $dispatcher->dispatch();
                expect($dispatcher->getTaskName())->equals('echo');
                expect($dispatcher->getActionName())->equals('main');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('echoMainAction');

                $dispatcher->setTaskName('main');
                $dispatcher->setActionName('hello');
                $dispatcher->dispatch();
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('hello');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('Hello !');

                $dispatcher->setActionName('hello');
                $dispatcher->setParams(array('World', '######'));
                $dispatcher->dispatch();
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('hello');
                expect($dispatcher->getParams())->equals(array('World', '######'));
                expect($dispatcher->getReturnedValue())->equals('Hello World######');

                $dispatcher->setActionName('hello');
                $dispatcher->setParams(array('hello' => 'World', 'goodbye' => 'Everybody'));
                $dispatcher->dispatch();
                expect($dispatcher->hasParam('hello'))->true();
                expect($dispatcher->hasParam('goodbye'))->true();
                expect($dispatcher->hasParam('salutations'))->false();

                // testing namespace
                try {
                    $dispatcher->setDefaultNamespace('Dummy\\');
                    $dispatcher->setTaskName('main');
                    $dispatcher->setActionName('hello');
                    $dispatcher->setParams(array('World'));
                    $dispatcher->dispatch();
                    expect($dispatcher->getTaskName())->equals('main');
                    expect($dispatcher->getActionName())->equals('hello');
                    expect($dispatcher->getParams())->equals(array('World'));
                    expect($dispatcher->getReturnedValue())->equals('Hello World!');
                } catch (\Exception $e) {
                    expect($e->getMessage())->equals('Dummy\MainTask handler class cannot be loaded');
                }
            }
        );
    }

    public function testCliParameters()
    {
        $this->specify(
            "CLI Dispatcher doesn't work with custom parameters",
            function () {
                $di = new CliFactoryDefault();

                $dispatcher = new Dispatcher();

                $di->setShared("dispatcher", $dispatcher);

                $dispatcher->setDI($di);

                // Test $this->dispatcher->getParams()
                $dispatcher->setTaskName('params');
                $dispatcher->setActionName('params');
                $dispatcher->setParams(array('This', 'Is', 'An', 'Example'));
                $dispatcher->dispatch();
                expect($dispatcher->getReturnedValue())->equals('$params is the same as $this->dispatcher->getParams()');

                // Test $this->dispatcher->getParam()
                $dispatcher->setTaskName('params');
                $dispatcher->setActionName('param');
                $dispatcher->setParams(array('This', 'Is', 'An', 'Example'));
                $dispatcher->dispatch();
                expect($dispatcher->getReturnedValue())->equals('$param[0] is the same as $this->dispatcher->getParam(0)');
            }
        );
    }

    public function testCallActionMethod()
    {
        $this->specify(
            "CLI Dispatcher's callActionMethod doesn't work as expected",
            function () {
                $di = new CliFactoryDefault();

                $dispatcher = new Dispatcher();

                $di->setShared("dispatcher", $dispatcher);

                $dispatcher->setDI($di);

                $mainTask = new \MainTask();
                $mainTask->setDI($di);

                expect($dispatcher->callActionMethod($mainTask, 'mainAction', []))->equals('mainAction');
                expect($dispatcher->callActionMethod($mainTask, 'helloAction', ['World']))->equals('Hello World!');
                expect($dispatcher->callActionMethod($mainTask, 'helloAction', ['World', '.']))->equals('Hello World.');
            }
        );
    }
}
