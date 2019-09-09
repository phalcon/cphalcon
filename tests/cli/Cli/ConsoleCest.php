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
use function dataDir;
use Issue787Task;
use Phalcon\Cli\Console;
use Phalcon\Cli\Console\Exception as ConsoleException;
use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\Dispatcher\Exception as DispatcherException;
use Phalcon\Cli\Router;
use Phalcon\Test\Fixtures\Traits\DiTrait;

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
            new ConsoleException(
                "Module 'devtools' isn't registered in the console container"
            ),
            function () {
                $this->container->set(
                    'data',
                    function () {
                        return 'data';
                    }
                );

                $console = new Console();

                $console->setDI(
                    $this->container
                );

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
        $this->container->set(
            'data',
            function () {
                return 'data';
            }
        );

        $console = new Console();

        $console->setDI(
            $this->container
        );

        $dispatcher = $console->getDI()->getShared('dispatcher');

        $dispatcher->setDefaultNamespace('Dummy\\');

        $I->expectThrowable(
            new DispatcherException(
                "Dummy\MainTask handler class cannot be loaded",
                2
            ),
            function () use ($console) {
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
                return 'data';
            }
        );

        $console = new Console();

        $console->setDI(
            $this->container
        );

        $expected = [
            'devtools' => [
                'className' => 'dummy',
                'path'      => 'dummy_file',
            ],
        ];

        $console->registerModules($expected);

        $I->assertEquals(
            $expected,
            $console->getModules()
        );

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

        $I->assertEquals(
            $expected,
            $console->getModules()
        );
    }

    public function testIssue787(CliTester $I)
    {
        require_once dataDir('fixtures/tasks/Issue787Task.php');

        $dispatcher = new Dispatcher();

        $dispatcher->setDI(
            $this->container
        );

        $this->container->setShared('dispatcher', $dispatcher);

        $console = new Console();

        $console->setDI($this->container);

        $console->handle(
            [
                'task'   => 'issue787',
                'action' => 'main',
            ]
        );

        $I->assertTrue(
            class_exists('Issue787Task')
        );

        $I->assertEquals(
            'beforeExecuteRoute' . PHP_EOL . 'initialize' . PHP_EOL,
            Issue787Task::$output
        );
    }

    public function shouldThrowExceptionWithUnshiftedArguments(CliTester $I)
    {
        $console = new Console();

        $console->setDI(
            $this->container
        );

        $dispatcher = $console->getDI()->getShared('dispatcher');

        // testing namespace
        $dispatcher->setDefaultNamespace('Dummy\\');

        $console->setArgument(
            [
                'main',
                'hello',
                'World',
                '!',
            ],
            false,
            false
        );

        $I->expectThrowable(
            new DispatcherException(
                'Dummy\MainTask handler class cannot be loaded',
                2
            ),
            function () use ($console) {
                $console->handle();
            }
        );
    }

    public function shouldThrowExceptionWithArgumentsAsAnArray(CliTester $I)
    {
        $console = new Console();

        $console->setDI(
            $this->container
        );

        $dispatcher = $console->getDI()->getShared('dispatcher');

        // testing namespace
        $dispatcher->setDefaultNamespace('Dummy\\');

        $console->setArgument(
            [
                'php',
                'main',
                'hello',
                'World',
                '!',
            ],
            false
        );

        $I->expectThrowable(
            new DispatcherException(
                'Dummy\MainTask handler class cannot be loaded',
                2
            ),
            function () use ($console) {
                $console->handle();
            }
        );
    }

    /**
     * @test
     *
     * @expectedException        DispatcherException
     * @expectedExceptionMessage Dummy\MainTask handler class cannot be loaded
     */
    public function shouldThrowExceptionWithArguments(CliTester $I)
    {
        $this->container->setShared(
            'router',
            function () {
                $router = new Router(true);

                return $router;
            }
        );

        $console = new Console();

        $console->setDI(
            $this->container
        );

        $dispatcher = $console->getDI()->getShared('dispatcher');

        // testing namespace
        $dispatcher->setDefaultNamespace('Dummy\\');

        $console->setArgument(
            [
                'php',
                'main',
                'hello',
                'World',
                '!',
            ]
        );

        $I->expectThrowable(
            new DispatcherException(
                'Dummy\MainTask handler class cannot be loaded',
                2
            ),
            function () use ($console) {
                $console->handle();
            }
        );
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

        $console->setDI(
            $this->container
        );

        $dispatcher = $console->getDI()->getShared('dispatcher');


        $console->setArgument(
            [
                'php',
                '-opt1',
                '--option2',
                '--option3=hoge',
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

        $I->assertEquals(
            [
                'opt1'    => true,
                'option2' => true,
                'option3' => 'hoge',
            ],
            $dispatcher->getOptions()
        );

        $I->assertTrue(
            $dispatcher->hasOption('opt1')
        );

        $I->assertFalse(
            $dispatcher->hasOption('opt2')
        );


        $console->setArgument(
            [
                'php',
                'main',
                '-opt1',
                'hello',
                '--option2',
                'World',
                '--option3=hoge',
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

        $I->assertEquals(
            [
                'opt1'    => true,
                'option2' => true,
                'option3' => 'hoge',
            ],
            $dispatcher->getOptions()
        );

        $I->assertEquals(
            'hoge',
            $dispatcher->getOption('option3')
        );
    }
}
