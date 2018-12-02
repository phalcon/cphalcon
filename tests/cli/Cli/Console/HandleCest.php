<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli\Console;

use CliTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class HandleCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Cli\Console :: handle()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliConsoleHandle(CliTester $I)
    {
        $I->wantToTest("Cli\Console - handle()");
        $I->skipTest("TODO - check this");
        $container = $this->newCliFactoryDefault();
        $container->set(
            'data',
            function () {
                return "data";
            }
        );

        $console = $this->newCliConsole();
        $console->setDI($container);
        $dispatcher = $console->getDI()->getShared('dispatcher');

        $console->handle([]);
        $expected = 'main';
        $actual   = $dispatcher->getTaskName();
        $I->assertEquals($expected, $actual);
        $expected = 'main';
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $expected = [];
        $actual   = $dispatcher->getParams();
        $I->assertEquals($expected, $actual);
        $expected = 'mainAction';
        $actual   = $dispatcher->getReturnedValue();
        $I->assertEquals($expected, $actual);

        $console->handle(
            [
                'task' => 'echo',
            ]
        );
        $expected = 'echo';
        $actual   = $dispatcher->getTaskName();
        $I->assertEquals($expected, $actual);
        $expected = 'main';
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $expected = [];
        $actual   = $dispatcher->getParams();
        $I->assertEquals($expected, $actual);
        $expected = 'echoMainAction';
        $actual   = $dispatcher->getReturnedValue();
        $I->assertEquals($expected, $actual);

        $console->handle(
            [
                'task' => 'main',
                'action' => 'hello'
            ]
        );
        $expected = 'main';
        $actual   = $dispatcher->getTaskName();
        $I->assertEquals($expected, $actual);
        $expected = 'hello';
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $expected = [];
        $actual   = $dispatcher->getParams();
        $I->assertEquals($expected, $actual);
        $expected = 'Hello !';
        $actual   = $dispatcher->getReturnedValue();
        $I->assertEquals($expected, $actual);

        $console->handle(
            [
                'task' => 'main',
                'action' => 'hello',
                'World',
                '######'
            ]
        );
        $expected = 'main';
        $actual   = $dispatcher->getTaskName();
        $I->assertEquals($expected, $actual);
        $expected = 'hello';
        $actual   = $dispatcher->getActionName();
        $I->assertEquals($expected, $actual);
        $expected = ['World', '######'];
        $actual   = $dispatcher->getParams();
        $I->assertEquals($expected, $actual);
        $expected = 'Hello World######';
        $actual   = $dispatcher->getReturnedValue();
        $I->assertEquals($expected, $actual);
    }
}
