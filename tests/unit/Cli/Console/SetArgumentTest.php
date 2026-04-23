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

namespace Phalcon\Tests\Unit\Cli\Console;

use Phalcon\Cli\Console as CliConsole;
use Phalcon\Cli\Console\Exception as ConsoleException;
use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Exception as RouterException;
use Phalcon\Di\Exception as DiException;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Tests\AbstractUnitTestCase;

final class SetArgumentTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getExamplesRouter(): array
    {
        return [
            [
                [
                    'php',
                ],
                'main',
                'main',
                [],
                'mainAction',
            ],
            [
                [
                    'php',
                    'echo',
                ],
                'echo',
                'main',
                [],
                'echoMainAction',
            ],
            [
                [
                    'php',
                    'main',
                    'hello',
                    'World',
                    '#####',
                ],
                'main',
                'hello',
                ['World', '#####'],
                'Hello World#####',
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getExamplesStrShift(): array
    {
        return [
            [
                false,
                true,
                [
                    'php',
                ],
                'main',
                'main',
                [],
                'mainAction',
            ],
            [
                false,
                true,
                [
                    'php',
                    'echo',
                ],
                'echo',
                'main',
                [],
                'echoMainAction',
            ],
            [
                false,
                true,
                [
                    'php',
                    'main',
                    'hello',
                ],
                'main',
                'hello',
                [],
                'Hello !',
            ],
            [
                false,
                true,
                [
                    'php',
                    'main',
                    'hello',
                    'World',
                    '#####',
                ],
                'main',
                'hello',
                ['World', '#####'],
                'Hello World#####',
            ],
            [
                false,
                false,
                [],
                'main',
                'main',
                [],
                'mainAction',
            ],
            [
                false,
                false,
                [
                    'echo',
                ],
                'echo',
                'main',
                [],
                'echoMainAction',
            ],
            [
                false,
                false,
                [
                    'main',
                    'hello',
                ],
                'main',
                'hello',
                [],
                'Hello !',
            ],
            [
                false,
                false,
                [
                    'main',
                    'hello',
                    'World',
                    '#####',
                ],
                'main',
                'hello',
                ['World', '#####'],
                'Hello World#####',
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-11-13
     * @since  2018-12-26
     */
    public function testCliConsoleSetArgument(): void
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

        /** @var Dispatcher $dispatcher */
        $dispatcher = $di->getShared('dispatcher');
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Support\Tasks');
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
        $this->assertSame($expected, $actual);

        $expected = 'arguments';
        $actual   = $dispatcher->getActionName();
        $this->assertSame($expected, $actual);

        $expected = ['a', 'b', 'c', 'd'];
        $actual   = $dispatcher->getParameters();
        $this->assertSame($expected, $actual);

        $expected = [];
        $actual   = $dispatcher->getOptions();
        $this->assertSame($expected, $actual);

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
        $this->assertSame($expected, $actual);

        $expected = 'arguments';
        $actual   = $dispatcher->getActionName();
        $this->assertSame($expected, $actual);

        $expected = ['a', 'b'];
        $actual   = $dispatcher->getParameters();
        $this->assertSame($expected, $actual);

        $expected = [
            'country' => 'usa',
            'last'    => true,
        ];
        $actual   = $dispatcher->getOptions();
        $this->assertSame($expected, $actual);
    }

    /**
     * @dataProvider getExamplesRouter
     *
     */
    public function testCliConsoleSetArgumentRouter(
        array $argument,
        string $taskName,
        string $actionName,
        array $params,
        mixed $returnedValue
    ): void {
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
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Support\Tasks');

        $console->setArgument($argument)
                ->handle()
        ;

        $expected = $taskName;
        $actual   = $dispatcher->getTaskName();
        $this->assertSame($expected, $actual);

        $expected = $actionName;
        $actual   = $dispatcher->getActionName();
        $this->assertSame($expected, $actual);

        $expected = $params;
        $actual   = $dispatcher->getParameters();
        $this->assertSame($expected, $actual);

        $expected = $returnedValue;
        $actual   = $dispatcher->getReturnedValue();
        $this->assertSame($expected, $actual);
    }

    /**
     * @dataProvider getExamplesStrShift
     *
     */
    public function testCliConsoleSetArgumentStrShift(
        bool $str,
        bool $shift,
        array $argument,
        string $taskName,
        string $actionName,
        array $params,
        mixed $returnedValue
    ): void {
        $di      = new DiFactoryDefault();
        $console = new CliConsole($di);


        /** @var Dispatcher $dispatcher */
        $dispatcher = $di->getShared('dispatcher');
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Support\Tasks');

        $console->setArgument($argument, $str, $shift)
                ->handle()
        ;

        $expected = $taskName;
        $actual   = $dispatcher->getTaskName();
        $this->assertSame($expected, $actual);

        $expected = $actionName;
        $actual   = $dispatcher->getActionName();
        $this->assertSame($expected, $actual);

        $expected = $params;
        $actual   = $dispatcher->getParameters();
        $this->assertSame($expected, $actual);

        $expected = $returnedValue;
        $actual   = $dispatcher->getReturnedValue();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testCliConsoleSetArgumentNonString(): void
    {
        $console = new CliConsole(new DiFactoryDefault());

        // Integer argument — not a string, covers the else branch
        $actual = $console->setArgument([42], false, false);

        // setArgument() returns $this
        $this->assertSame($console, $actual);
    }
}
