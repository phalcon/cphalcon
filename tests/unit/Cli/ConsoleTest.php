<?php

namespace Phalcon\Test\Unit\Cli;

use Phalcon\Cli\Console;
use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\Router;
use Phalcon\Di;
use Phalcon\Di\FactoryDefault\Cli as CliFactoryDefault;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Cli\ConsoleTest
 * Tests the \Phalcon\Cli\Console component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Cli
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ConsoleTest extends UnitTest
{
    public function testConsoles()
    {
        $this->specify(
            "CLI Console doesn't work with typical parameters",
            function () {
                $di = new CliFactoryDefault();

                $di->set(
                    'data',
                    function () {
                        return "data";
                    }
                );

                $console = new Console();
                $console->setDI($di);
                $dispatcher = $console->getDI()->getShared('dispatcher');

                $console->handle([]);
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('main');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('mainAction');

                $console->handle(
                    [
                        'task' => 'echo',
                    ]
                );

                expect($dispatcher->getTaskName())->equals('echo');
                expect($dispatcher->getActionName())->equals('main');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('echoMainAction');

                $console->handle(
                    [
                        'task' => 'main',
                        'action' => 'hello'
                    ]
                );
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('hello');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('Hello !');

                $console->handle(
                    [
                        'task' => 'main',
                        'action' => 'hello',
                        'World',
                        '######'
                    ]
                );
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('hello');
                expect($dispatcher->getParams())->equals(array('World', '######'));
                expect($dispatcher->getReturnedValue())->equals('Hello World######');
            }
        );

        $this->specify(
            "CLI Console doesn't throw exception when module isn't found",
            function () {
                $di = new CliFactoryDefault();

                $di->set(
                    'data',
                    function () {
                        return "data";
                    }
                );

                $console = new Console();
                $console->setDI($di);
                $dispatcher = $console->getDI()->getShared('dispatcher');

                // testing module
                $console->handle(
                    [
                        'module' => 'devtools',
                        'task' => 'main',
                        'action' => 'hello',
                        'World',
                        '######'
                    ]
                );
            },
            [
                'throws' => [
                    \Phalcon\Cli\Console\Exception::class,
                    "Module 'devtools' isn't registered in the console container"
                ]
            ]
        );

        $this->specify(
            "CLI Console doesn't throw exception when task isn't found",
            function () {
                $di = new CliFactoryDefault();

                $console = new Console();
                $console->setDI($di);
                $dispatcher = $console->getDI()->getShared('dispatcher');

                $dispatcher->setDefaultNamespace('Dummy\\');

                // testing namespace
                $console->handle(
                    [
                        'task' => 'main',
                        'action' => 'hello',
                        'World',
                        '!'
                    ]
                );
            },
            [
                'throws' => [
                    \Phalcon\Cli\Dispatcher\Exception::class,
                    'Dummy\MainTask handler class cannot be loaded'
                ]
            ]
        );
    }

    public function testModules()
    {
        $this->specify(
            "CLI Console doesn't work with modules",
            function () {
                $di = new Di();

                $di->set(
                    'data',
                    function () {
                        return "data";
                    }
                );

                $console = new Console();
                $console->setDI($di);

                $expected = [
                    'devtools'=> [
                        'className' => 'dummy',
                        'path' => 'dummy_file'
                    ]
                ];

                $console->registerModules($expected);

                expect($console->getModules())->equals($expected);

                $userModules = [
                    'front'=> [
                        'className' => 'front',
                        'path' => 'front_file'
                    ],
                    'worker' => [
                        'className' => 'worker',
                        'path' => 'worker_file'
                    ],
                ];

                $expected = [
                    'devtools'=> [
                        'className' => 'dummy',
                        'path' => 'dummy_file'
                    ],
                    'front' => [
                        'className' => 'front',
                        'path' => 'front_file'
                    ],
                    'worker' => [
                        'className' => 'worker',
                        'path'=>'worker_file'
                    ],
                ];

                $console->registerModules($userModules, true);

                expect($console->getModules())->equals($expected);
            }
        );
    }

    public function testIssue787()
    {
        $this->specify(
            "Initializer isn't invoked if has been dispatcher call before",
            function () {
                $di = new CliFactoryDefault();

                $di->setShared(
                    'dispatcher',
                    function () use ($di) {
                        $dispatcher = new Dispatcher();

                        $dispatcher->setDI($di);

                        return $dispatcher;
                    }
                );

                $console = new Console();

                $console->setDI($di);

                $console->handle(
                    array(
                        'task'   => 'issue787',
                        'action' => 'main',
                    )
                );

                expect(class_exists('Issue787Task'))->true();

                $actual   = \Issue787Task::$output;
                $expected = "beforeExecuteRoute" . PHP_EOL . "initialize" . PHP_EOL;
                expect($actual)->equals($expected);
            }
        );
    }

    public function testArgumentArray()
    {
        $this->specify(
            "CLI Console doesn't work with arguments as an array",
            function () {
                $di = new CliFactoryDefault();

                $console = new Console();
                $console->setDI($di);
                $dispatcher = $console->getDI()->getShared('dispatcher');

                $console->setArgument(array(
                    'php',
                ), false)->handle();
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('main');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('mainAction');

                $console->setArgument(array(
                    'php',
                    'echo'
                ), false)->handle();
                expect($dispatcher->getTaskName())->equals('echo');
                expect($dispatcher->getActionName())->equals('main');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('echoMainAction');

                $console->setArgument(array(
                    'php',
                    'main',
                    'hello'
                ), false)->handle();
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('hello');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('Hello !');

                $console->setArgument(array(
                    'php',
                    'main',
                    'hello',
                    'World',
                    '######'
                ), false)->handle();
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('hello');
                expect($dispatcher->getParams())->equals(array('World', '######'));
                expect($dispatcher->getReturnedValue())->equals('Hello World######');
            }
        );

        $this->specify(
            "CLI Console doesn't work with arguments as an array (2)",
            function () {
                $di = new CliFactoryDefault();

                $console = new Console();
                $console->setDI($di);
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
            },
            [
                'throws' => [
                    \Phalcon\Cli\Dispatcher\Exception::class,
                    'Dummy\MainTask handler class cannot be loaded'
                ]
            ]
        );
    }

    public function testArgumentNoShift()
    {
        $this->specify(
            "CLI Console doesn't work with unshifted arguments",
            function () {
                $di = new CliFactoryDefault();

                $console = new Console();
                $console->setDI($di);
                $dispatcher = $console->getDI()->getShared('dispatcher');

                $console->setArgument([], false, false)->handle();
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('main');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('mainAction');

                $console->setArgument(array(
                    'echo'
                ), false, false)->handle();
                expect($dispatcher->getTaskName())->equals('echo');
                expect($dispatcher->getActionName())->equals('main');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('echoMainAction');

                $console->setArgument(array(
                    'main',
                    'hello'
                ), false, false)->handle();
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('hello');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('Hello !');

                $console->setArgument(array(
                    'main',
                    'hello',
                    'World',
                    '######'
                ), false, false)->handle();
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('hello');
                expect($dispatcher->getParams())->equals(array('World', '######'));
                expect($dispatcher->getReturnedValue())->equals('Hello World######');
            }
        );

        $this->specify(
            "CLI Console doesn't work with unshifted arguments (2)",
            function () {
                $di = new CliFactoryDefault();

                $console = new Console();
                $console->setDI($di);
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
            },
            [
                'throws' => [
                    \Phalcon\Cli\Dispatcher\Exception::class,
                    'Dummy\MainTask handler class cannot be loaded'
                ]
            ]
        );
    }

    public function testArgumentRouter()
    {
        $this->specify(
            "CLI Console doesn't work with arguments",
            function () {
                $di = new CliFactoryDefault();

                $di->setShared(
                    'router',
                    function () {
                        $router = new Router(true);

                        return $router;
                    }
                );

                $console = new Console();
                $console->setDI($di);
                $dispatcher = $console->getDI()->getShared('dispatcher');

                $console->setArgument(array(
                    'php'
                ))->handle();
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('main');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('mainAction');

                $console->setArgument(array(
                    'php',
                    'echo'
                ))->handle();
                expect($dispatcher->getTaskName())->equals('echo');
                expect($dispatcher->getActionName())->equals('main');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('echoMainAction');

                $console->setArgument(array(
                    'php',
                    'main',
                    'hello'
                ))->handle();
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('hello');
                expect($dispatcher->getParams())->equals([]);
                expect($dispatcher->getReturnedValue())->equals('Hello !');

                $console->setArgument(array(
                    'php',
                    'main',
                    'hello',
                    'World',
                    '######'
                ))->handle();
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('hello');
                expect($dispatcher->getParams())->equals(array('World', '######'));
                expect($dispatcher->getReturnedValue())->equals('Hello World######');
            }
        );

        $this->specify(
            "CLI Console doesn't work with arguments (2)",
            function () {
                $di = new CliFactoryDefault();

                $di->setShared('router', function () {
                    $router = new Router(true);
                    return $router;
                });

                $console = new Console();
                $console->setDI($di);
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
            },
            [
                'throws' => [
                    \Phalcon\Cli\Dispatcher\Exception::class,
                    'Dummy\MainTask handler class cannot be loaded'
                ]
            ]
        );
    }

    public function testArgumentOptions()
    {
        $this->specify(
            "CLI Console doesn't work with options set in arguments",
            function () {
                $di = new CliFactoryDefault();

                $di->setShared(
                    'router',
                    function () {
                        $router = new Router(true);

                        return $router;
                    }
                );

                $console = new Console();
                $console->setDI($di);
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
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('hello');
                expect($dispatcher->getParams())->equals(array('World', '######'));
                expect($dispatcher->getReturnedValue())->equals('Hello World######');
                expect($dispatcher->getOptions())->equals(array('opt1' => true, 'option2' => true, 'option3' => 'hoge'));
                expect($dispatcher->hasOption('opt1'))->true();
                expect($dispatcher->hasOption('opt2'))->false();

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
                expect($dispatcher->getTaskName())->equals('main');
                expect($dispatcher->getActionName())->equals('hello');
                expect($dispatcher->getParams())->equals(array('World', '######'));
                expect($dispatcher->getReturnedValue())->equals('Hello World######');
                expect($dispatcher->getOptions())->equals(array('opt1' => true, 'option2' => true, 'option3' => 'hoge'));
                expect($dispatcher->getOption('option3'))->equals('hoge');
            }
        );
    }
}
