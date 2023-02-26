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
use Exception;
use Phalcon\Cli\Console as CliConsole;
use Phalcon\Cli\Console\Exception as ConsoleException;
use Phalcon\Cli\Dispatcher\Exception as DispatcherException;
use Phalcon\Cli\Router\Exception as RouterException;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Events\Event;
use Phalcon\Tests\Fixtures\Tasks\Issue16285Task;
use Phalcon\Tests\Fixtures\Tasks\Issue787Task;
use Phalcon\Tests\Modules\Backend\Module as BackendModule;
use Phalcon\Tests\Modules\Frontend\Module as FrontendModule;

use function codecept_root_dir;
use function dataDir;
use function ob_end_clean;
use function ob_start;
use function shell_exec;

use const PHP_OS_FAMILY;

class HandleCest
{
    /**
     * Tests Phalcon\Cli\Console :: handle()
     *
     * @dataProvider getExamplesHandle
     *
     * @param CliTester $I
     * @param Example   $example
     *
     * @return void
     * @throws ConsoleException
     * @throws RouterException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliConsoleHandle(CliTester $I, Example $example)
    {
        $label         = $example['label'];
        $arguments     = $example['arguments'];
        $taskName      = $example['taskName'];
        $actionName    = $example['actionName'];
        $params        = $example['params'];
        $returnedValue = $example['returnedValue'];

        $I->wantToTest("Cli\Console - handle() " . $label);

        $container = new DiFactoryDefault();

        $container->set(
            'data',
            function () {
                return 'data';
            }
        );

        $console = new CliConsole($container);

        $dispatcher = $console->getDI()
                              ->getShared('dispatcher')
        ;
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');

        $console->handle($arguments);

        $expected = $taskName;
        $actual   = $dispatcher->getTaskName();
        $I->assertSame($expected, $actual);

        $expected = $actionName;
        $actual   = $dispatcher->getActionName();
        $I->assertSame($expected, $actual);

        $expected = $params;
        $actual   = $dispatcher->getParams();
        $I->assertSame($expected, $actual);

        $expected = $returnedValue;
        $actual   = $dispatcher->getReturnedValue();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Cli\Console :: handle() - BackendModules
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function cliConsoleHandleModule(CliTester $I)
    {
        $I->wantToTest("Cli\Console - handle() - BackendModules");

        $console = new CliConsole(new DiFactoryDefault());

        $console->registerModules(
            [
                'frontend' => [
                    'className' => FrontendModule::class,
                    'path'      => dataDir('/fixtures/modules/frontend/Module.php'),
                ],
                'backend'  => [
                    'className' => BackendModule::class,
                    'path'      => dataDir('fixtures/modules/backend/Module.php'),
                ],
            ]
        );

        $dispatcher = $console->dispatcher;
        $dispatcher->setNamespaceName('Phalcon\Tests\Modules\Backend\Tasks');

        $I->expectThrowable(
            new Exception('Task Run'),
            function () use ($console) {
                $console->handle(
                    [
                        'module' => 'backend',
                        'action' => 'throw',
                    ]
                );
            }
        );

        $expected = 'main';
        $actual   = $dispatcher->getTaskName();
        $I->assertSame($expected, $actual);

        $expected = 'throw';
        $actual   = $dispatcher->getActionName();
        $I->assertSame($expected, $actual);

        $expected = 'backend';
        $actual   = $dispatcher->getModuleName();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Cli\Console :: handle()
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function cliConsoleHandleEventBoot(CliTester $I)
    {
        $I->wantToTest("Cli\Console - handle() - Events - console:boot");

        $console = new CliConsole(new DiFactoryDefault());

        $eventsManager = $console->eventsManager;

        $eventsManager->attach(
            'console:boot',
            function (Event $event, $console) {
                throw new Exception('Console Boot Event Fired');
            }
        );

        $I->expectThrowable(
            new Exception('Console Boot Event Fired'),
            function () use ($console) {
                $console->handle();
            }
        );
    }

    /**
     * Tests Phalcon\Cli\Console :: handle()
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function cliConsoleHandleEventBeforeStartModule(CliTester $I)
    {
        $I->wantToTest("Cli\Console - handle() - Events - console:beforeStartModule");

        $console = new CliConsole(new DiFactoryDefault());

        $eventsManager = $console->eventsManager;

        $eventsManager->attach(
            'console:beforeStartModule',
            function (Event $event, $console, $moduleName) {
                throw new Exception('Console Before Start BackendModule Event Fired');
            }
        );

        $console->registerModules(
            [
                'frontend' => [
                    'className' => FrontendModule::class,
                    'path'      => dataDir('fixtures/modules/frontend/Module.php'),
                ],
                'backend'  => [
                    'className' => BackendModule::class,
                ],
            ]
        );

        $console->dispatcher->setNamespaceName('Phalcon\Tests\Modules\Backend\Tasks');

        $I->expectThrowable(
            new Exception('Console Before Start BackendModule Event Fired'),
            function () use ($console) {
                $console->handle(
                    [
                        'module' => 'backend',
                        'action' => 'noop',
                    ]
                );
            }
        );
    }

    /**
     * Tests Phalcon\Cli\Console :: handle()
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function cliConsoleHandleEventAfterStartModule(CliTester $I)
    {
        $I->wantToTest("Cli\Console - handle() - Events - console:afterStartModule");

        $console = new CliConsole(new DiFactoryDefault());

        $eventsManager = $console->eventsManager;

        $console->registerModules(
            [
                'frontend' => [
                    'className' => FrontendModule::class,
                    'path'      => dataDir('fixtures/modules/frontend/Module.php'),
                ],
                'backend'  => [
                    'className' => BackendModule::class,
                ],
            ]
        );

        $console->dispatcher->setNamespaceName('Phalcon\Tests\Modules\Backend\Tasks');

        $eventsManager->attach(
            'console:afterStartModule',
            function (Event $event, $console, $moduleObject) {
                throw new Exception('Console After Start BackendModule Event Fired');
            }
        );

        $I->expectThrowable(
            new Exception('Console After Start BackendModule Event Fired'),
            function () use ($console) {
                $console->handle(
                    [
                        'module' => 'backend',
                        'action' => 'noop',
                    ]
                );
            }
        );
    }

    /**
     * Tests Phalcon\Cli\Console :: handle()
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function cliConsoleHandleEventBeforeHandleTask(CliTester $I)
    {
        $I->wantToTest("Cli\Console - handle() - Events - console:beforeHandleTask");

        $console = new CliConsole(new DiFactoryDefault());

        $eventsManager = $console->eventsManager;

        $eventsManager->attach(
            'console:beforeHandleTask',
            function (Event $event, $console, $moduleObject) {
                throw new Exception('Console Before Handle Task Event Fired');
            }
        );

        $I->expectThrowable(
            new Exception('Console Before Handle Task Event Fired'),
            function () use ($console) {
                $console->handle([]);
            }
        );
    }

    /**
     * Tests Phalcon\Cli\Console :: handle()
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function cliConsoleHandleEventAfterHandleTask(CliTester $I)
    {
        $I->wantToTest("Cli\Console - handle() - Events - console:afterHandleTask");

        $console = new CliConsole(new DiFactoryDefault());

        $eventsManager = $console->eventsManager;

        $eventsManager->attach(
            'console:afterHandleTask',
            function (Event $event, $console, $moduleObject) {
                throw new Exception('Console After Handle Task Event Fired');
            }
        );

        $console->registerModules(
            [
                'frontend' => [
                    'className' => FrontendModule::class,
                    'path'      => dataDir('fixtures/modules/frontend/Module.php'),
                ],
                'backend'  => [
                    'className' => BackendModule::class,
                    'path'      => dataDir('fixtures/modules/backend/Module.php'),
                ],
            ]
        );
        $console->dispatcher->setNamespaceName('Phalcon\Tests\Modules\Backend\Tasks');

        $I->expectThrowable(
            new Exception(
                'Console After Handle Task Event Fired'
            ),
            function () use ($console) {
                $console->handle(
                    [
                        'module' => 'backend',
                        'action' => 'noop',
                    ]
                );
            }
        );
    }

    /**
     * Tests Phalcon\Cli\Console :: handle() - Issue #13724
     * Handling a BackendModule twice causes class already exists error #13724
     * <https://github.com/phalcon/cphalcon/issues/13724>
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2019-01-06
     */
    public function cliConsoleHandle13724(CliTester $I)
    {
        $I->wantToTest("Cli\Console - handle() - Issue #13724");
        $console = new CliConsole(new DiFactoryDefault());

        $dispatcher = $console->dispatcher;
        $dispatcher->setNamespaceName('Phalcon\Tests\Modules\Backend\Tasks');

        $console->registerModules(
            [
                'backend' => [
                    'className' => BackendModule::class,
                    'path'      => dataDir('fixtures/modules/backend/Module.php'),
                ],
            ]
        );

        $console->handle(
            [
                'module' => 'backend',
                'action' => 'noop',
            ]
        );


        $console = new CliConsole(new DiFactoryDefault());

        $dispatcher = $console->dispatcher;
        $dispatcher->setNamespaceName('Phalcon\Tests\Modules\Backend\Tasks');

        $console->registerModules(
            [
                'backend' => [
                    'className' => BackendModule::class,
                    'path'      => dataDir('fixtures/modules/backend/Module.php'),
                ],
            ]
        );

        $console->handle(
            [
                'module' => 'backend',
                'action' => 'noop',
            ]
        );
    }

    public function cliConsoleHandleModuleDoesNotExists(CliTester $I)
    {
        $I->wantToTest("Cli\Console - handle() - Throw exception when module does not exists");

        $console = new CliConsole(new DiFactoryDefault());
        $I->expectThrowable(
            new ConsoleException(
                "Module 'devtools' isn't registered in the console container"
            ),
            function () use ($console) {
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

    public function cliConsoleHandleTaskDoesNotExists(CliTester $I)
    {
        $I->wantToTest("Cli\Console - handle() - Throw exception when task does not exists");

        $console = new CliConsole(new DiFactoryDefault());

        $console->dispatcher->setDefaultNamespace('Dummy\\');

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

    public function cliConsoleHandle787(CliTester $I)
    {
        $console = new CliConsole(new DiFactoryDefault());
        $console->dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');

        $console->handle(
            [
                'task'   => 'issue787',
                'action' => 'main',
            ]
        );

        $I->assertSame(
            'beforeExecuteRoute' . PHP_EOL . 'initialize' . PHP_EOL,
            Issue787Task::$output
        );
    }

    public function cliConsoleHandle16285(CliTester $I)
    {
        $console = new CliConsole(new DiFactoryDefault());
        $console->handle(
            [
                'task'   => Issue16285Task::class,
                'action' => 'main',
            ]
        );

        $I->assertSame('main', Issue16285Task::$output);
    }

    /**
     * @param CliTester $I
     *
     * @issue  16186
     * @return void
     */
    public function cliConsoleHandleNoAction(CliTester $I)
    {
        $I->wantToTest("Cli\Console - handle() - no action");

        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to check this under Windows');
        }

        $script = codecept_root_dir() . 'tests/testbed/cli.php ';

        ob_start();
        $actual = shell_exec('sudo php ' . $script . 'print');
        ob_end_clean();

        $expected = 'printMainAction';
        $I->assertSame($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamplesHandle(): array
    {
        return [
            [
                'label'         => 'default',
                'arguments'     => [],
                'taskName'      => 'main',
                'actionName'    => 'main',
                'params'        => [],
                'returnedValue' => 'mainAction',
            ],
            [
                'label'         => 'task',
                'arguments'     => [
                    'task' => 'echo',
                ],
                'taskName'      => 'echo',
                'actionName'    => 'main',
                'params'        => [],
                'returnedValue' => 'echoMainAction',
            ],
            [
                'label'         => 'task action',
                'arguments'     => [
                    'task'   => 'main',
                    'action' => 'hello',
                ],
                'taskName'      => 'main',
                'actionName'    => 'hello',
                'params'        => [],
                'returnedValue' => 'Hello !',
            ],
            [
                'label'         => 'task action params',
                'arguments'     => [
                    'task'   => 'main',
                    'action' => 'hello',
                    'World',
                    '#####',
                ],
                'taskName'      => 'main',
                'actionName'    => 'hello',
                'params'        => [
                    'World',
                    '#####',
                ],
                'returnedValue' => 'Hello World#####',
            ],
        ];
    }
}
