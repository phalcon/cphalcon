<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli;

use CliTester;
use Phalcon\Cli\Dispatcher;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class DispatcherCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        /**
         * @todo Check the loader
         */
        require_once dataFolder('fixtures/tasks/EchoTask.php');
        require_once dataFolder('fixtures/tasks/MainTask.php');
        require_once dataFolder('fixtures/tasks/ParamsTask.php');

        $this->setNewCliFactoryDefault();
    }

    public function testDispatcher(CliTester $I)
    {

        $this->container->set(
            'data',
            function () {
                return "data";
            }
        );

        $dispatcher = new Dispatcher();
        $dispatcher->setDI($this->container);
        $dispatcher->dispatch();
        $I->assertEquals($dispatcher->getTaskName(), 'main');
        $I->assertEquals($dispatcher->getActionName(), 'main');
        $I->assertEquals($dispatcher->getParams(), []);
        $I->assertEquals($dispatcher->getReturnedValue(), 'mainAction');

        $dispatcher->setTaskName('echo');
        $dispatcher->dispatch();
        $I->assertEquals($dispatcher->getTaskName(), 'echo');
        $I->assertEquals($dispatcher->getActionName(), 'main');
        $I->assertEquals($dispatcher->getParams(), []);
        $I->assertEquals($dispatcher->getReturnedValue(), 'echoMainAction');

        $dispatcher->setTaskName('main');
        $dispatcher->setActionName('hello');
        $dispatcher->dispatch();
        $I->assertEquals($dispatcher->getTaskName(), 'main');
        $I->assertEquals($dispatcher->getActionName(), 'hello');
        $I->assertEquals($dispatcher->getParams(), []);
        $I->assertEquals($dispatcher->getReturnedValue(), 'Hello !');

        $dispatcher->setActionName('hello');
        $dispatcher->setParams(array('World', '######'));
        $dispatcher->dispatch();
        $I->assertEquals($dispatcher->getTaskName(), 'main');
        $I->assertEquals($dispatcher->getActionName(), 'hello');
        $I->assertEquals($dispatcher->getParams(), array('World', '######'));
        $I->assertEquals($dispatcher->getReturnedValue(), 'Hello World######');

        $dispatcher->setActionName('hello');
        $dispatcher->setParams(array('hello' => 'World', 'goodbye' => 'Everybody'));
        $dispatcher->dispatch();
        $I->assertTrue($dispatcher->hasParam('hello'));
        $I->assertTrue($dispatcher->hasParam('goodbye'));
        $I->assertFalse($dispatcher->hasParam('salutations'));

        // testing namespace
        try {
            $dispatcher->setDefaultNamespace('Dummy\\');
            $dispatcher->setTaskName('main');
            $dispatcher->setActionName('hello');
            $dispatcher->setParams(array('World'));
            $dispatcher->dispatch();
            $I->assertEquals($dispatcher->getTaskName(), 'main');
            $I->assertEquals($dispatcher->getActionName(), 'hello');
            $I->assertEquals($dispatcher->getParams(), array('World'));
            $I->assertEquals($dispatcher->getReturnedValue(), 'Hello World!');
        } catch (\Exception $e) {
            $I->assertEquals($e->getMessage(), 'Dummy\MainTask handler class cannot be loaded');
        }
    }

    public function testCliParameters(CliTester $I)
    {
        $dispatcher = new Dispatcher();

        $this->container->setShared("dispatcher", $dispatcher);
        $dispatcher->setDI($this->container);

        // Test $this->dispatcher->getParams()
        $dispatcher->setTaskName('params');
        $dispatcher->setActionName('params');
        $dispatcher->setParams(array('This', 'Is', 'An', 'Example'));
        $dispatcher->dispatch();
        $I->assertEquals($dispatcher->getReturnedValue(), 'Action params are the same as $this->dispatcher->getParams()');

        // Test $this->dispatcher->getParam()
        $dispatcher->setTaskName('params');
        $dispatcher->setActionName('param');
        $dispatcher->setParams(array('This', 'Is', 'An', 'Example'));
        $dispatcher->dispatch();
        $I->assertEquals($dispatcher->getReturnedValue(), '$param[0] is the same as $this->dispatcher->getParam(0)');
    }
}
