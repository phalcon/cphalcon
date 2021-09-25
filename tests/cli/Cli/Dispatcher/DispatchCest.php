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

namespace Phalcon\Tests\Cli\Cli\Dispatcher;

use CliTester;
use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\Dispatcher\Exception;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;

class DispatchCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: dispatch()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherDispatch(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - dispatch()');

        // test 1
        $dispatcher = new Dispatcher();
        $dispatcher->setDI(
            new DiFactoryDefault()
        );
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');
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


        // Test 2
        $dispatcher = new Dispatcher();
        $dispatcher->setDI(
            new DiFactoryDefault()
        );
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');
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

        // Test 3
        $dispatcher = new Dispatcher();
        $dispatcher->setDI(
            new DiFactoryDefault()
        );
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');
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

        // Test 4
        $dispatcher = new Dispatcher();
        $dispatcher->setDI(
            new DiFactoryDefault()
        );
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');
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

        //Test 5
        $dispatcher = new Dispatcher();
        $dispatcher->setDI(
            new DiFactoryDefault()
        );
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');
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

    public function testFakeNamespace(CliTester $I)
    {
        $dispatcher = new Dispatcher();

        $dispatcher->setDI(
            new DiFactoryDefault()
        );

        $dispatcher->setDefaultNamespace('Dummy\\');
        $dispatcher->setTaskName('main');
        $dispatcher->setActionName('hello');

        $dispatcher->setParams(
            ['World']
        );

        $I->expectThrowable(
            new Exception(
                'Dummy\MainTask handler class cannot be loaded',
                Exception::EXCEPTION_HANDLER_NOT_FOUND
            ),
            function () use ($dispatcher) {
                $dispatcher->dispatch();
            }
        );
    }
}
