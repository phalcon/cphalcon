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
use Phalcon\Cli\Console;
use Phalcon\Cli\Console\Exception as ConsoleException;
use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\Dispatcher\Exception as DispatcherException;
use Phalcon\Cli\Router;
use Phalcon\Di;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use function dataFolder;

class ConsoleCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    public function shouldThrowExceptionWhenModuleDoesNotExists(CliTester $I)
    {
        $I->expectThrowable(
            new ConsoleException("Module 'devtools' isn't registered in the console container"),
            function () {
                $this->container->set(
                    'data',
                    function () {
                        return "data";
                    }
                );

                $console = new Console();
                $console->setDI($this->container);

                // testing module
                $console->handle(
                    [
                        'module' => 'devtools',
                        'task'   => 'main',
                        'action' => 'hello',
                        'World',
                        '######',
                    ]
                );
            }
        );
    }

    public function shouldThrowExceptionWhenTaskDoesNotExists(CliTester $I)
    {
        $I->expectThrowable(
            new DispatcherException("Dummy\MainTask handler class cannot be loaded", 2),
            function () {
                $this->container->set(
                    'data',
                    function () {
                        return "data";
                    }
                );

                $console = new Console();
                $console->setDI($this->container);
                $dispatcher = $console->getDI()->getShared('dispatcher');

                $dispatcher->setDefaultNamespace('Dummy\\');

                // testing namespace
                $console->handle(
                    [
                        'task'   => 'main',
                        'action' => 'hello',
                        'World',
                        '!',
                    ]
                );
            }
        );
    }

    public function testModules(CliTester $I)
    {
        $this->container->set(
            'data',
            function () {
                return "data";
            }
        );

        $console = new Console();
        $console->setDI($this->container);

        $expected = [
            'devtools' => [
                'className' => 'dummy',
                'path'      => 'dummy_file',
            ],
        ];

        $console->registerModules($expected);

        $I->assertEquals($expected, $console->getModules());

        $userModules = [
            'front'  => [
                'className' => 'front',
                'path'      => 'front_file',
            ],
            'worker' => [
                'className' => 'worker',
                'path'      => 'worker_file',
            ],
        ];

        $expected = [
            'devtools' => [
                'className' => 'dummy',
                'path'      => 'dummy_file',
            ],
            'front'    => [
                'className' => 'front',
                'path'      => 'front_file',
            ],
            'worker'   => [
                'className' => 'worker',
                'path'      => 'worker_file',
            ],
        ];

        $console->registerModules($userModules, true);

        $I->assertEquals($expected, $console->getModules());
    }

    public function testIssue787(CliTester $I)
    {
        require_once dataFolder('fixtures/tasks/Issue787Task.php');

        $dispatcher = new Dispatcher();
        $dispatcher->setDI($this->container);
        $this->container->setShared('dispatcher', $dispatcher);

        $console = new Console();
        $console->setDI($this->container);
        $console->handle(
            [
                'task'   => 'issue787',
                'action' => 'main',
            ]
        );

        $I->assertTrue(class_exists('Issue787Task'));

        $actual   = \Issue787Task::$output;
        $expected = "beforeExecuteRoute" . PHP_EOL . "initialize" . PHP_EOL;
        $I->assertEquals($expected, $actual);
    }

    public function testArgumentArray(CliTester $I)
    {
        /**
         * @todo Check the loader why those are not being autoloaded
         */
        require_once dataFolder('fixtures/tasks/EchoTask.php');
        require_once dataFolder('fixtures/tasks/MainTask.php');

        $console = new Console();
        $console->setDI($this->container);
        $dispatcher = $console->getDI()->getShared('dispatcher');

        $console->setArgument(array(
            'php',
        ), false)->handle();
        $I->assertEquals($dispatcher->getTaskName(), 'main');
        $I->assertEquals($dispatcher->getActionName(), 'main');
        $I->assertEquals($dispatcher->getParams(), []);
        $I->assertEquals($dispatcher->getReturnedValue(), 'mainAction');

        $console->setArgument(array(
            'php',
            'echo'
        ), false)->handle();
        $I->assertEquals($dispatcher->getTaskName(), 'echo');
        $I->assertEquals($dispatcher->getActionName(), 'main');
        $I->assertEquals($dispatcher->getParams(), []);
        $I->assertEquals($dispatcher->getReturnedValue(), 'echoMainAction');

        $console->setArgument(array(
            'php',
            'main',
            'hello'
        ), false)->handle();
        $I->assertEquals($dispatcher->getTaskName(), 'main');
        $I->assertEquals($dispatcher->getActionName(), 'hello');
        $I->assertEquals($dispatcher->getParams(), []);
        $I->assertEquals($dispatcher->getReturnedValue(), 'Hello !');

        $console->setArgument(array(
            'php',
            'main',
            'hello',
            'World',
            '######'
        ), false)->handle();
        $I->assertEquals($dispatcher->getTaskName(), 'main');
        $I->assertEquals($dispatcher->getActionName(), 'hello');
        $I->assertEquals($dispatcher->getParams(), array('World', '######'));
        $I->assertEquals($dispatcher->getReturnedValue(), 'Hello World######');
    }

    public function testArgumentNoShift(CliTester $I)
    {
        $console = new Console();
        $console->setDI($this->container);
        $dispatcher = $console->getDI()->getShared('dispatcher');

        $console->setArgument([], false, false)->handle();
        $I->assertEquals($dispatcher->getTaskName(), 'main');
        $I->assertEquals($dispatcher->getActionName(), 'main');
        $I->assertEquals($dispatcher->getParams(), []);
        $I->assertEquals($dispatcher->getReturnedValue(), 'mainAction');

        $console->setArgument(array(
            'echo'
        ), false, false)->handle();
        $I->assertEquals($dispatcher->getTaskName(), 'echo');
        $I->assertEquals($dispatcher->getActionName(), 'main');
        $I->assertEquals($dispatcher->getParams(), []);
        $I->assertEquals($dispatcher->getReturnedValue(), 'echoMainAction');

        $console->setArgument(array(
            'main',
            'hello'
        ), false, false)->handle();
        $I->assertEquals($dispatcher->getTaskName(), 'main');
        $I->assertEquals($dispatcher->getActionName(), 'hello');
        $I->assertEquals($dispatcher->getParams(), []);
        $I->assertEquals($dispatcher->getReturnedValue(), 'Hello !');

        $console->setArgument(array(
            'main',
            'hello',
            'World',
            '######'
        ), false, false)->handle();
        $I->assertEquals($dispatcher->getTaskName(), 'main');
        $I->assertEquals($dispatcher->getActionName(), 'hello');
        $I->assertEquals($dispatcher->getParams(), array('World', '######'));
        $I->assertEquals($dispatcher->getReturnedValue(), 'Hello World######');
    }

    public function shouldThrowExceptionWithUnshiftedArguments(CliTester $I)
    {
        $I->expectThrowable(
            new DispatcherException('Dummy\MainTask handler class cannot be loaded', 2),
            function () {
                $console = new Console();
                $console->setDI($this->container);
                $dispatcher = $console->getDI()->getShared('dispatcher');

                // testing namespace
                $dispatcher->setDefaultNamespace('Dummy\\');

                $console->setArgument(array(
                    'main',
                    'hello',
                    'World',
                    '!'
                ), false, false);

                $console->handle();
            }
        );
    }

    public function shouldThrowExceptionWithArgumentsAsAnArray(CliTester $I)
    {
        $I->expectThrowable(
            new DispatcherException('Dummy\MainTask handler class cannot be loaded', 2),
            function () {
                $console = new Console();
                $console->setDI($this->container);
                $dispatcher = $console->getDI()->getShared('dispatcher');

                // testing namespace
                $dispatcher->setDefaultNamespace('Dummy\\');

                $console->setArgument(array(
                    'php',
                    'main',
                    'hello',
                    'World',
                    '!'
                ), false);

                $console->handle();
            }
        );
    }

    /**
     * @test
     *
     * @expectedException        \Phalcon\Cli\Dispatcher\Exception
     * @expectedExceptionMessage Dummy\MainTask handler class cannot be loaded
     */
    public function shouldThrowExceptionWithArguments(CliTester $I)
    {
        $I->expectThrowable(
            new DispatcherException('Dummy\MainTask handler class cannot be loaded', 2),
            function () {
                $this->container->setShared('router', function () {
                    $router = new Router(true);
                    return $router;
                });

                $console = new Console();
                $console->setDI($this->container);
                $dispatcher = $console->getDI()->getShared('dispatcher');

                // testing namespace
                $dispatcher->setDefaultNamespace('Dummy\\');

                $console->setArgument(array(
                    'php',
                    'main',
                    'hello',
                    'World',
                    '!'
                ));

                $console->handle();
            }
        );
    }

    public function testArgumentRouter(CliTester $I)
    {
        $this->container->setShared(
            'router',
            function () {
                $router = new Router(true);

                return $router;
            }
        );

        $console = new Console();
        $console->setDI($this->container);
        $dispatcher = $console->getDI()->getShared('dispatcher');

        $console->setArgument(array(
            'php'
        ))->handle();
        $I->assertEquals($dispatcher->getTaskName(), 'main');
        $I->assertEquals($dispatcher->getActionName(), 'main');
        $I->assertEquals($dispatcher->getParams(), []);
        $I->assertEquals($dispatcher->getReturnedValue(), 'mainAction');

        $console->setArgument(array(
            'php',
            'echo'
        ))->handle();
        $I->assertEquals($dispatcher->getTaskName(), 'echo');
        $I->assertEquals($dispatcher->getActionName(), 'main');
        $I->assertEquals($dispatcher->getParams(), []);
        $I->assertEquals($dispatcher->getReturnedValue(), 'echoMainAction');

        $console->setArgument(array(
            'php',
            'main',
            'hello'
        ))->handle();
        $I->assertEquals($dispatcher->getTaskName(), 'main');
        $I->assertEquals($dispatcher->getActionName(), 'hello');
        $I->assertEquals($dispatcher->getParams(), []);
        $I->assertEquals($dispatcher->getReturnedValue(), 'Hello !');

        $console->setArgument(array(
            'php',
            'main',
            'hello',
            'World',
            '######'
        ))->handle();
        $I->assertEquals($dispatcher->getTaskName(), 'main');
        $I->assertEquals($dispatcher->getActionName(), 'hello');
        $I->assertEquals($dispatcher->getParams(), array('World', '######'));
        $I->assertEquals($dispatcher->getReturnedValue(), 'Hello World######');
    }

    public function testArgumentOptions(CliTester $I)
    {
        $this->container->setShared(
            'router',
            function () {
                $router = new Router(true);

                return $router;
            }
        );

        $console = new Console();
        $console->setDI($this->container);
        $dispatcher = $console->getDI()->getShared('dispatcher');

        $console->setArgument(array(
            'php',
            '-opt1',
            '--option2',
            '--option3=hoge',
            'main',
            'hello',
            'World',
            '######'
        ))->handle();
        $I->assertEquals($dispatcher->getTaskName(), 'main');
        $I->assertEquals($dispatcher->getActionName(), 'hello');
        $I->assertEquals($dispatcher->getParams(), array('World', '######'));
        $I->assertEquals($dispatcher->getReturnedValue(), 'Hello World######');
        $I->assertEquals($dispatcher->getOptions(), array('opt1' => true, 'option2' => true, 'option3' => 'hoge'));
        $I->assertTrue($dispatcher->hasOption('opt1'));
        $I->assertFalse($dispatcher->hasOption('opt2'));

        $console->setArgument(array(
            'php',
            'main',
            '-opt1',
            'hello',
            '--option2',
            'World',
            '--option3=hoge',
            '######'
        ))->handle();
        $I->assertEquals($dispatcher->getTaskName(), 'main');
        $I->assertEquals($dispatcher->getActionName(), 'hello');
        $I->assertEquals($dispatcher->getParams(), array('World', '######'));
        $I->assertEquals($dispatcher->getReturnedValue(), 'Hello World######');
        $I->assertEquals($dispatcher->getOptions(), array('opt1' => true, 'option2' => true, 'option3' => 'hoge'));
        $I->assertEquals($dispatcher->getOption('option3'), 'hoge');
    }
}
