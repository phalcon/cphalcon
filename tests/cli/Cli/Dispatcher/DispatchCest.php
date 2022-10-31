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
        $dispatcher->setDI(new DiFactoryDefault());
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');
        $dispatcher->dispatch();

        $expected = 'main';
        $actual   = $dispatcher->getTaskName();
        $I->assertSame($expected, $actual);

        $expected = 'main';
        $actual   = $dispatcher->getActionName();
        $I->assertSame($expected, $actual);

        $expected = [];
        $actual   = $dispatcher->getParams();
        $I->assertSame($expected, $actual);

        $expected = 'mainAction';
        $actual   = $dispatcher->getReturnedValue();
        $I->assertSame($expected, $actual);

        // Test 2
        $dispatcher = new Dispatcher();
        $dispatcher->setDI(new DiFactoryDefault());
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');
        $dispatcher->setTaskName('echo');
        $dispatcher->dispatch();

        $expected = 'echo';
        $actual   = $dispatcher->getTaskName();
        $I->assertSame($expected, $actual);

        $expected = 'main';
        $actual   = $dispatcher->getActionName();
        $I->assertSame($expected, $actual);

        $expected = [];
        $actual   = $dispatcher->getParams();
        $I->assertSame($expected, $actual);

        $expected = 'echoMainAction';
        $actual   = $dispatcher->getReturnedValue();
        $I->assertSame($expected, $actual);

        // Test 3
        $dispatcher = new Dispatcher();
        $dispatcher->setDI(new DiFactoryDefault());
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');
        $dispatcher->setTaskName('main');
        $dispatcher->setActionName('hello');
        $dispatcher->dispatch();

        $expected = 'main';
        $actual   = $dispatcher->getTaskName();
        $I->assertSame($expected, $actual);

        $expected = 'hello';
        $actual   = $dispatcher->getActionName();
        $I->assertSame($expected, $actual);

        $expected = [];
        $actual   = $dispatcher->getParams();
        $I->assertSame($expected, $actual);

        $expected = 'Hello !';
        $actual   = $dispatcher->getReturnedValue();
        $I->assertSame($expected, $actual);

        // Test 4
        $dispatcher = new Dispatcher();
        $dispatcher->setDI(new DiFactoryDefault());
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');
        $dispatcher->setActionName('hello');
        $dispatcher->setParams(
            [
                'World',
                '#####',
            ]
        );
        $dispatcher->dispatch();

        $expected = 'main';
        $actual   = $dispatcher->getTaskName();
        $I->assertSame($expected, $actual);

        $expected = 'hello';
        $actual   = $dispatcher->getActionName();
        $I->assertSame($expected, $actual);

        $expected = [
            'World',
            '#####',
        ];
        $actual   = $dispatcher->getParams();
        $I->assertSame($expected, $actual);

        $expected = 'Hello World#####';
        $actual   = $dispatcher->getReturnedValue();
        $I->assertSame($expected, $actual);

        //Test 5
        $dispatcher = new Dispatcher();
        $dispatcher->setDI(new DiFactoryDefault());
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');
        $dispatcher->setActionName('hello');
        $dispatcher->setParams(
            [
                'hello'   => 'World',
                'goodbye' => 'Everybody',
            ]
        );
        $dispatcher->dispatch();


        $actual = $dispatcher->hasParam('hello');
        $I->assertTrue($actual);
        $actual = $dispatcher->hasParam('goodbye');
        $I->assertTrue($actual);
        $actual = $dispatcher->hasParam('salutations');
        $I->assertFalse($actual);
    }

    public function testFakeNamespace(CliTester $I)
    {
        $dispatcher = new Dispatcher();

        $dispatcher->setDI(new DiFactoryDefault());

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
