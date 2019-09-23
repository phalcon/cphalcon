<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli\Console;

use CliTester;
use function dataDir;
use Exception;
use Phalcon\Events\Event;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Modules\Backend\Module;

class HandleCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Cli\Console :: handle()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliConsoleHandle(CliTester $I)
    {
        require_once dataDir('fixtures/tasks/MainTask.php');
        require_once dataDir('fixtures/tasks/EchoTask.php');

        $I->wantToTest("Cli\Console - handle()");

        $container = $this->newCliFactoryDefault();

        $container->set(
            'data',
            function () {
                return 'data';
            }
        );

        $console = $this->newCliConsole();

        $console->setDI($container);

        $dispatcher = $console->getDI()->getShared('dispatcher');

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
     * Tests Phalcon\Cli\Console :: handle() - Modules
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function cliConsoleHandleModule(CliTester $I)
    {
        require_once dataDir('fixtures/modules/backend/tasks/MainTask.php');

        $I->wantToTest("Cli\Console - handle() - Modules");

        $console = $this->newCliConsole();

        $this->setNewCliFactoryDefault();

        $console->setDI($this->container);

        $console->registerModules(
            [
                'frontend' => [
                    'className' => \Phalcon\Test\Modules\Frontend\Module::class,
                    'path'      => dataDir('/fixtures/modules/frontend/Module.php'),
                ],
                'backend'  => [
                    'className' => \Phalcon\Test\Modules\Backend\Module::class,
                    'path'      => dataDir('fixtures/modules/backend/Module.php'),
                ],
            ]
        );

        $console->dispatcher->setNamespaceName('Phalcon\\Test\\Modules\\Backend\\Tasks');

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

        $dispatcher = $console->dispatcher;

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
    public function cliConsoleHandleEventBoot(CliTester $I)
    {
        $I->wantToTest("Cli\Console - handle() - Events - console:boot");

        $this->setNewCliFactoryDefault();
        $this->setDiEventsManager();

        $eventsManager = $this->container->getShared('eventsManager');

        $eventsManager->attach(
            'console:boot',
            function (Event $event, $console) {
                throw new Exception('Console Boot Event Fired');
            }
        );

        $console = $this->newCliConsole();

        $console->setDI($this->container);

        $console->setEventsManager($eventsManager);

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
    public function cliConsoleHandleEventBeforeStartModule(CliTester $I)
    {
        require_once dataDir('fixtures/modules/backend/tasks/MainTask.php');

        $I->wantToTest("Cli\Console - handle() - Events - console:beforeStartModule");

        $this->setNewCliFactoryDefault();
        $this->setDiEventsManager();

        $eventsManager = $this->container->getShared('eventsManager');

        $console = $this->newCliConsole();

        $console->setDI($this->container);

        $console->setEventsManager($eventsManager);

        $eventsManager->attach(
            'console:beforeStartModule',
            function (Event $event, $console, $moduleName) {
                throw new Exception('Console Before Start Module Event Fired');
            }
        );

        $console->registerModules(
            [
                'frontend' => [
                    'className' => \Phalcon\Test\Modules\Frontend\Module::class,
                    'path'      => dataDir('fixtures/modules/frontend/Module.php'),
                ],
                'backend'  => [
                    'className' => Module::class,
                ],
            ]
        );

        $console->dispatcher->setNamespaceName(
            'Phalcon\\Test\\Modules\\Backend\\Tasks'
        );

        $I->expectThrowable(
            new Exception('Console Before Start Module Event Fired'),
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
        require_once dataDir('fixtures/modules/backend/tasks/MainTask.php');

        $I->wantToTest("Cli\Console - handle() - Events - console:afterStartModule");

        $this->setNewCliFactoryDefault();
        $this->setDiEventsManager();

        $eventsManager = $this->container->getShared('eventsManager');

        $console = $this->newCliConsole();

        $console->setDI($this->container);

        $console->setEventsManager($eventsManager);

        $console->registerModules(
            [
                'frontend' => [
                    'className' => \Phalcon\Test\Modules\Frontend\Module::class,
                    'path'      => dataDir('fixtures/modules/frontend/Module.php'),
                ],
                'backend'  => [
                    'className' => Module::class,
                ],
            ]
        );

        $eventsManager->attach(
            'console:afterStartModule',
            function (Event $event, $console, $moduleObject) {
                throw new Exception('Console After Start Module Event Fired');
            }
        );

        $I->expectThrowable(
            new Exception('Console After Start Module Event Fired'),
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
        require_once dataDir('fixtures/modules/backend/tasks/MainTask.php');

        $I->wantToTest("Cli\Console - handle() - Events - console:beforeHandleTask");

        $this->setNewCliFactoryDefault();
        $this->setDiEventsManager();

        $eventsManager = $this->container->getShared('eventsManager');

        $console = $this->newCliConsole();

        $console->setDI($this->container);
        $console->setEventsManager($eventsManager);

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
        require_once dataDir('fixtures/modules/backend/tasks/MainTask.php');

        $I->wantToTest("Cli\Console - handle() - Events - console:afterHandleTask");

        $this->setNewCliFactoryDefault();
        $this->setDiEventsManager();

        $eventsManager = $this->container->getShared('eventsManager');

        $console = $this->newCliConsole();

        $console->setDI($this->container);

        $console->setEventsManager($eventsManager);

        $eventsManager->attach(
            'console:afterHandleTask',
            function (Event $event, $console, $moduleObject) {
                throw new Exception('Console After Handle Task Event Fired');
            }
        );

        $console->registerModules(
            [
                'frontend' => [
                    'className' => \Phalcon\Test\Modules\Frontend\Module::class,
                    'path'      => dataDir('fixtures/modules/frontend/Module.php'),
                ],
                'backend'  => [
                    'className' => Module::class,
                ],
            ]
        );

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
     * Handling a module twice causes class already exists error #13724
     * <https://github.com/phalcon/cphalcon/issues/13724>
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2019-01-06
     */
    public function cliConsoleHandle13724(CliTester $I)
    {
        require_once dataDir('fixtures/modules/backend/tasks/MainTask.php');

        $I->wantToTest("Cli\Console - handle() - Issue #13724");


        $console = $this->newCliConsole();

        $this->setNewCliFactoryDefault();

        $console->setDI($this->container);

        $console->registerModules(
            [
                'backend' => [
                    'className' => Module::class,
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


        $console = $this->newCliConsole();

        $this->setNewCliFactoryDefault();

        $console->setDI($this->container);

        $console->registerModules(
            [
                'backend' => [
                    'className' => Module::class,
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
}
