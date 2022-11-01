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
use Codeception\Example;
use Phalcon\Cli\Console as CliConsole;
use Phalcon\Cli\Console\Exception as ConsoleException;
use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Exception as RouterException;
use Phalcon\Di\Exception as DiException;
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

        /** @var Dispatcher $dispatcher */
        $dispatcher = $di->getShared('dispatcher');
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');
        $console->setArgument(
            [
                'php',
                'main',
                'arguments',
                'a',
                'b',
                'c',
                'd',
            ]
        )
                ->handle()
        ;

        $expected = 'main';
        $actual   = $dispatcher->getTaskName();
        $I->assertSame($expected, $actual);

        $expected = 'arguments';
        $actual   = $dispatcher->getActionName();
        $I->assertSame($expected, $actual);

        $expected = ['a', 'b', 'c', 'd'];
        $actual   = $dispatcher->getParameters();
        $I->assertSame($expected, $actual);

        $expected = [];
        $actual   = $dispatcher->getOptions();
        $I->assertSame($expected, $actual);

        $console->setArgument(
            [
                'php',
                '--country=usa',
                '-last',
                'main',
                'arguments',
                'a',
                'b',
            ]
        )
                ->handle()
        ;

        $expected = 'main';
        $actual   = $dispatcher->getTaskName();
        $I->assertSame($expected, $actual);

        $expected = 'arguments';
        $actual   = $dispatcher->getActionName();
        $I->assertSame($expected, $actual);

        $expected = ['a', 'b'];
        $actual   = $dispatcher->getParameters();
        $I->assertSame($expected, $actual);

        $expected = [
            'country' => 'usa',
            'last' => true,
        ];
        $actual   = $dispatcher->getOptions();
        $I->assertSame($expected, $actual);
    }

    /**
     * @dataProvider getExamplesStrShift
     *
     * @param CliTester $I
     * @param Example   $example
     *
     * @return void
     * @throws ConsoleException
     * @throws DiException
     * @throws RouterException
     */
    public function cliConsoleSetArgumentStrShift(CliTester $I, Example $example)
    {
        $label         = $example['label'];
        $str           = $example['str'];
        $shift         = $example['shift'];
        $argument      = $example['argument'];
        $taskName      = $example['taskName'];
        $actionName    = $example['actionName'];
        $params        = $example['params'];
        $returnedValue = $example['returnedValue'];

        $I->wantToTest("Cli\Console - setArgument - str/shift - " . $label);
        $di      = new DiFactoryDefault();
        $console = new CliConsole($di);


        /** @var Dispatcher $dispatcher */
        $dispatcher = $di->getShared('dispatcher');
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');

        $console->setArgument($argument, $str, $shift)
                ->handle()
        ;

        $expected = $taskName;
        $actual   = $dispatcher->getTaskName();
        $I->assertSame($expected, $actual);

        $expected = $actionName;
        $actual   = $dispatcher->getActionName();
        $I->assertSame($expected, $actual);

        $expected = $params;
        $actual   = $dispatcher->getParameters();
        $I->assertSame($expected, $actual);

        $expected = $returnedValue;
        $actual   = $dispatcher->getReturnedValue();
        $I->assertSame($expected, $actual);
    }

    /**
     * @dataProvider getExamplesRouter
     *
     * @param CliTester $I
     * @param Example   $example
     *
     * @return void
     * @throws ConsoleException
     * @throws RouterException
     * @throws DiException
     */
    public function cliConsoleSetArgumentRouter(CliTester $I, Example $example)
    {
        $label         = $example['label'];
        $argument      = $example['argument'];
        $taskName      = $example['taskName'];
        $actionName    = $example['actionName'];
        $params        = $example['params'];
        $returnedValue = $example['returnedValue'];

        $I->wantToTest("Cli\Console - setArgument - router - " . $label);
        $di      = new DiFactoryDefault();
        $console = new CliConsole($di);

        $di->setShared(
            'router',
            function () {
                $router = new Router(true);

                return $router;
            }
        );

        /** @var Dispatcher $dispatcher */
        $dispatcher = $di->getShared('dispatcher');
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');

        $console->setArgument($argument)
                ->handle()
        ;

        $expected = $taskName;
        $actual   = $dispatcher->getTaskName();
        $I->assertSame($expected, $actual);

        $expected = $actionName;
        $actual   = $dispatcher->getActionName();
        $I->assertSame($expected, $actual);

        $expected = $params;
        $actual   = $dispatcher->getParameters();
        $I->assertSame($expected, $actual);

        $expected = $returnedValue;
        $actual   = $dispatcher->getReturnedValue();
        $I->assertSame($expected, $actual);
    }

    /**
     * @return array[]
     */
    private function getExamplesStrShift(): array
    {
        return [
            [
                'label'         => 'default',
                'str'           => false,
                'shift'         => true,
                'argument'      => [
                    'php',
                ],
                'taskName'      => 'main',
                'actionName'    => 'main',
                'params'        => [],
                'returnedValue' => 'mainAction',
            ],
            [
                'label'         => 'one',
                'str'           => false,
                'shift'         => true,
                'argument'      => [
                    'php',
                    'echo',
                ],
                'taskName'      => 'echo',
                'actionName'    => 'main',
                'params'        => [],
                'returnedValue' => 'echoMainAction',
            ],
            [
                'label'         => 'two',
                'str'           => false,
                'shift'         => true,
                'argument'      => [
                    'php',
                    'main',
                    'hello',
                ],
                'taskName'      => 'main',
                'actionName'    => 'hello',
                'params'        => [],
                'returnedValue' => 'Hello !',
            ],
            [
                'label'         => 'four',
                'str'           => false,
                'shift'         => true,
                'argument'      => [
                    'php',
                    'main',
                    'hello',
                    'World',
                    '#####',
                ],
                'taskName'      => 'main',
                'actionName'    => 'hello',
                'params'        => ['World', '#####'],
                'returnedValue' => 'Hello World#####',
            ],
            [
                'label'         => 'default',
                'str'           => false,
                'shift'         => false,
                'argument'      => [],
                'taskName'      => 'main',
                'actionName'    => 'main',
                'params'        => [],
                'returnedValue' => 'mainAction',
            ],
            [
                'label'         => 'one',
                'str'           => false,
                'shift'         => false,
                'argument'      => [
                    'echo',
                ],
                'taskName'      => 'echo',
                'actionName'    => 'main',
                'params'        => [],
                'returnedValue' => 'echoMainAction',
            ],
            [
                'label'         => 'two',
                'str'           => false,
                'shift'         => false,
                'argument'      => [
                    'main',
                    'hello',
                ],
                'taskName'      => 'main',
                'actionName'    => 'hello',
                'params'        => [],
                'returnedValue' => 'Hello !',
            ],
            [
                'label'         => 'four',
                'str'           => false,
                'shift'         => false,
                'argument'      => [
                    'main',
                    'hello',
                    'World',
                    '#####',
                ],
                'taskName'      => 'main',
                'actionName'    => 'hello',
                'params'        => ['World', '#####'],
                'returnedValue' => 'Hello World#####',
            ],
        ];
    }

    /**
     * @return array[]
     */
    private function getExamplesRouter(): array
    {
        return [
            [
                'label'         => 'one',
                'argument'      => [
                    'php',
                ],
                'taskName'      => 'main',
                'actionName'    => 'main',
                'params'        => [],
                'returnedValue' => 'mainAction',
            ],
            [
                'label'         => 'two',
                'argument'      => [
                    'php',
                    'echo',
                ],
                'taskName'      => 'echo',
                'actionName'    => 'main',
                'params'        => [],
                'returnedValue' => 'echoMainAction',
            ],
            [
                'label'         => 'five',
                'argument'      => [
                    'php',
                    'main',
                    'hello',
                    'World',
                    '#####',
                ],
                'taskName'      => 'main',
                'actionName'    => 'hello',
                'params'        => ['World', '#####'],
                'returnedValue' => 'Hello World#####',
            ],
        ];
    }
}
