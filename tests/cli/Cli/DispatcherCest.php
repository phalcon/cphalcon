<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
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

        $this->setNewCliFactoryDefault();
    }

    public function testDispatcher1(CliTester $I)
    {
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
    }

    public function testDispatcher2(CliTester $I)
    {
        $dispatcher = new Dispatcher();

        $dispatcher->setDI(
            $this->container
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
    }

    public function testDispatcher3(CliTester $I)
    {
        $dispatcher = new Dispatcher();

        $dispatcher->setDI(
            $this->container
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
    }

    public function testDispatcher4(CliTester $I)
    {
        $dispatcher = new Dispatcher();

        $dispatcher->setDI(
            $this->container
        );

        $dispatcher->setActionName('hello');

        $dispatcher->setParams(
            [
                'World',
                '######',
            ]
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
            [
                'World',
                '######',
            ],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'Hello World######',
            $dispatcher->getReturnedValue()
        );
    }

    public function testDispatcher5(CliTester $I)
    {
        $dispatcher = new Dispatcher();

        $dispatcher->setDI(
            $this->container
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
    }
}
