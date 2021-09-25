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

namespace Phalcon\Tests\Cli\Cli\Console;

use CliTester;
use Phalcon\Cli\Console as CliConsole;
use Phalcon\Cli\Router;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;

class SetArgumentCest
{
    /**
     * Tests Phalcon\Cli\Console :: setArgument()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function cliConsoleSetArgument(CliTester $I)
    {
        $I->wantToTest("Cli\Console - setArgument()");

        $di      = new DiFactoryDefault();
        $console = new CliConsole($di);

        $di->setShared(
            'router',
            function () {
                $router = new Router(true);

                return $router;
            }
        );

        $dispatcher = $di->getShared('dispatcher');
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');
        $console->setArgument([
            'php',
            '--foo=bar',
            '-bar',
            'main',
            'hello',
            'a',
            'B',
        ])->handle()
        ;

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'hello',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            ['a', 'B'],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            [
                'foo' => 'bar',
                'bar' => true,
            ],
            $dispatcher->getOptions()
        );
    }

    public function testArgumentArray(CliTester $I)
    {
        $di      = new DiFactoryDefault();
        $console = new CliConsole($di);


        $dispatcher = $di->getShared('dispatcher');
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');

        $console->setArgument(
            [
                'php',
            ],
            false
        )->handle()
        ;

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

        $console->setArgument(
            [
                'php',
                'echo',
            ],
            false
        )->handle()
        ;

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

        $console->setArgument(
            [
                'php',
                'main',
                'hello',
            ],
            false
        )->handle()
        ;

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

        $console->setArgument(
            [
                'php',
                'main',
                'hello',
                'World',
                '######',
            ],
            false
        )->handle()
        ;

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'hello',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            ['World', '######'],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'Hello World######',
            $dispatcher->getReturnedValue()
        );
    }

    public function testArgumentNoShift(CliTester $I)
    {
        $di      = new DiFactoryDefault();
        $console = new CliConsole($di);

        $dispatcher = $di->getShared('dispatcher');
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');

        $console->setArgument(
            [],
            false,
            false
        )->handle()
        ;

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

        $console->setArgument(
            [
                'echo',
            ],
            false,
            false
        )->handle()
        ;

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

        $console->setArgument([
            'main',
            'hello',
        ], false, false)->handle()
        ;

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

        $console->setArgument(
            [
                'main',
                'hello',
                'World',
                '######',
            ],
            false,
            false
        )->handle()
        ;

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'hello',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            ['World', '######'],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'Hello World######',
            $dispatcher->getReturnedValue()
        );
    }

    public function testArgumentRouter(CliTester $I)
    {
        $di      = new DiFactoryDefault();
        $console = new CliConsole($di);

        $di->setShared(
            'router',
            function () {
                $router = new Router(true);

                return $router;
            }
        );

        $dispatcher = $di->getShared('dispatcher');
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');


        $console->setArgument(
            [
                'php',
            ]
        )->handle()
        ;

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


        $console->setArgument(
            [
                'php',
                'echo',
            ]
        )->handle()
        ;

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


        $console->setArgument(
            [
                'php',
                'main',
                'hello',
            ]
        )->handle()
        ;

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


        $console->setArgument(
            [
                'php',
                'main',
                'hello',
                'World',
                '######',
            ]
        )->handle()
        ;

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'hello',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            ['World', '######'],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'Hello World######',
            $dispatcher->getReturnedValue()
        );
    }
}
