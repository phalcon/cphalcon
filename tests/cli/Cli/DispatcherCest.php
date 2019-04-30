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
        require_once dataDir('fixtures/tasks/EchoTask.php');
        require_once dataDir('fixtures/tasks/MainTask.php');
        require_once dataDir('fixtures/tasks/ParamsTask.php');

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

        $dispatcher->setDI(
            $this->container
        );



        $dispatcher->dispatch();

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'main',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            [],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'mainAction',
            $dispatcher->getReturnedValue()
        );



        $dispatcher->setTaskName('echo');

        $dispatcher->dispatch();

        $I->assertEquals(
            'echo',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'main',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            [],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'echoMainAction',
            $dispatcher->getReturnedValue()
        );



        $dispatcher->setTaskName('main');
        $dispatcher->setActionName('hello');

        $dispatcher->dispatch();

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'hello',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            [],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'Hello !',
            $dispatcher->getReturnedValue()
        );



        $dispatcher->setActionName('hello');

        $dispatcher->setParams(
            ['World', '######']
        );

        $dispatcher->dispatch();

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'hello',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            array('World', '######'),
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'Hello World######',
            $dispatcher->getReturnedValue()
        );



        $dispatcher->setActionName('hello');

        $dispatcher->setParams(
            [
                'hello'   => 'World',
                'goodbye' => 'Everybody',
            ]
        );

        $dispatcher->dispatch();

        $I->assertTrue(
            $dispatcher->hasParam('hello')
        );

        $I->assertTrue(
            $dispatcher->hasParam('goodbye')
        );

        $I->assertFalse(
            $dispatcher->hasParam('salutations')
        );

        // testing namespace
        try {
            $dispatcher->setDefaultNamespace('Dummy\\');
            $dispatcher->setTaskName('main');
            $dispatcher->setActionName('hello');

            $dispatcher->setParams(
                ['World']
            );

            $dispatcher->dispatch();

            $I->assertEquals(
                'main',
                $dispatcher->getTaskName()
            );

            $I->assertEquals(
                'hello',
                $dispatcher->getActionName()
            );

            $I->assertEquals(
                ['World'],
                $dispatcher->getParams()
            );

            $I->assertEquals(
                'Hello World!',
                $dispatcher->getReturnedValue()
            );
        } catch (\Exception $e) {
            $I->assertEquals(
                'Dummy\MainTask handler class cannot be loaded',
                $e->getMessage()
            );
        }
    }

    public function testCliParameters(CliTester $I)
    {
        $dispatcher = new Dispatcher();

        $this->container->setShared("dispatcher", $dispatcher);

        $dispatcher->setDI(
            $this->container
        );

        // Test $this->dispatcher->getParams()
        $dispatcher->setTaskName('params');
        $dispatcher->setActionName('params');

        $dispatcher->setParams(
            ['This', 'Is', 'An', 'Example']
        );

        $dispatcher->dispatch();

        $I->assertEquals(
            'Action params are the same as $this->dispatcher->getParams()',
            $dispatcher->getReturnedValue()
        );

        // Test $this->dispatcher->getParam()
        $dispatcher->setTaskName('params');
        $dispatcher->setActionName('param');

        $dispatcher->setParams(
            ['This', 'Is', 'An', 'Example']
        );

        $dispatcher->dispatch();

        $I->assertEquals(
            '$param[0] is the same as $this->dispatcher->getParam(0)',
            $dispatcher->getReturnedValue()
        );
    }
}
