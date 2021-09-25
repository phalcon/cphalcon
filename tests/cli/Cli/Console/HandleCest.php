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
use Exception;
use Phalcon\Cli\Console as CliConsole;
use Phalcon\Cli\Console\Exception as ConsoleException;
use Phalcon\Cli\Dispatcher\Exception as DispatcherException;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Events\Event;
use Phalcon\Tests\Fixtures\Tasks\Issue787Task;
use Phalcon\Tests\Modules\Backend\Module as BackendModule;
use Phalcon\Tests\Modules\Frontend\Module as FrontendModule;

class HandleCest
{
    /**
     * Tests Phalcon\Cli\Console :: handle()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function handle(CliTester $I)
    {
        $I->wantToTest("Cli\Console - handle()");

        $container = new DiFactoryDefault();

        $container->set(
            'data',
            function () {
                return 'data';
            }
        );

        $console = new CliConsole($container);

        $dispatcher = $console->getDI()->getShared('dispatcher');
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');

        $console->handle([]);

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

        $console->handle(
            [
                'task' => 'echo',
            ]
        );

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

        $console->handle(
            [
                'task'   => 'main',
                'action' => 'hello',
            ]
        );

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

        $console->handle(
            [
                'task'   => 'main',
                'action' => 'hello',
                'World',
                '######',
            ]
        );

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

    /**
     * Tests Phalcon\Cli\Console :: handle() - BackendModules
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function handleModule(CliTester $I)
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


        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'throw',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            'backend',
            $dispatcher->getModuleName()
        );
    }

    /**
     * Tests Phalcon\Cli\Console :: handle()
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function handleEventBoot(CliTester $I)
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
                $console->handle(
                    []
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
    public function handleEventBeforeStartModule(CliTester $I)
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
    public function handleEventAfterStartModule(CliTester $I)
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
    public function handleEventBeforeHandleTask(CliTester $I)
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
    public function handleEventAfterHandleTask(CliTester $I)
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
    public function handle13724(CliTester $I)
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

    public function shouldThrowExceptionWhenModuleDoesNotExists(CliTester $I)
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

    public function shouldThrowExceptionWhenTaskDoesNotExists(CliTester $I)
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

    public function testIssue787(CliTester $I)
    {
        $console = new CliConsole(new DiFactoryDefault());
        $console->dispatcher->setDefaultNamespace('Phalcon\Tests\Fixtures\Tasks');

        $console->handle(
            [
                'task'   => 'issue787',
                'action' => 'main',
            ]
        );

        $I->assertEquals(
            'beforeExecuteRoute' . PHP_EOL . 'initialize' . PHP_EOL,
            Issue787Task::$output
        );
    }
}
