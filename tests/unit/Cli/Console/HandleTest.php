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

use Exception;
use Phalcon\Cli\Console as CliConsole;
use Phalcon\Cli\Console\Exception as ConsoleException;
use Phalcon\Cli\Dispatcher\Exception as DispatcherException;
use Phalcon\Cli\Router\Exception as RouterException;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Events\Event;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Modules\Backend\Module as BackendModule;
use Phalcon\Tests\Support\Modules\Frontend\Module as FrontendModule;
use Phalcon\Tests\Support\Tasks\Issue787Task;

use function ob_end_clean;
use function ob_start;
use function rootDir;
use function shell_exec;

final class HandleTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getExamplesHandle(): array
    {
        return [
            [
                [],
                'main',
                'main',
                [],
                'mainAction',
            ],
            [
                [
                    'task' => 'echo',
                ],
                'echo',
                'main',
                [],
                'echoMainAction',
            ],
            [
                [
                    'task'   => 'main',
                    'action' => 'hello',
                ],
                'main',
                'hello',
                [],
                'Hello !',
            ],
            [
                [
                    'task'   => 'main',
                    'action' => 'hello',
                    'World',
                    '#####',
                ],
                'main',
                'hello',
                [
                    'World',
                    '#####',
                ],
                'Hello World#####',
            ],
        ];
    }

    /**
     * @dataProvider getExamplesHandle
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliConsoleHandle(
        array $arguments,
        string $taskName,
        string $actionName,
        array $params,
        mixed $returnedValue
    ): void {
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
        $dispatcher->setDefaultNamespace('Phalcon\Tests\Support\Tasks');

        $console->handle($arguments);

        $expected = $taskName;
        $actual   = $dispatcher->getTaskName();
        $this->assertSame($expected, $actual);

        $expected = $actionName;
        $actual   = $dispatcher->getActionName();
        $this->assertSame($expected, $actual);

        $expected = $params;
        $actual   = $dispatcher->getParams();
        $this->assertSame($expected, $actual);

        $expected = $returnedValue;
        $actual   = $dispatcher->getReturnedValue();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2019-01-06
     */
    public function testCliConsoleHandle13724(): void
    {
        $console = new CliConsole(new DiFactoryDefault());

        $dispatcher = $console->dispatcher;
        $dispatcher->setNamespaceName('Phalcon\Tests\Support\Modules\Backend\Tasks');

        $console->registerModules(
            [
                'backend' => [
                    'className' => BackendModule::class,
                    'path'      => supportDir('Modules/Backend/Module.php'),
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
        $dispatcher->setNamespaceName('Phalcon\Tests\Support\Modules\Backend\Tasks');

        $console->registerModules(
            [
                'backend' => [
                    'className' => BackendModule::class,
                    'path'      => supportDir('Modules/Backend/Module.php'),
                ],
            ]
        );

        $console->handle(
            [
                'module' => 'backend',
                'action' => 'noop',
            ]
        );

        /**
         * If we are here there were no errors
         */
        $this->assertTrue(true);
    }

    public function testCliConsoleHandle787(): void
    {
        $console = new CliConsole(new DiFactoryDefault());
        $console->dispatcher->setDefaultNamespace('Phalcon\Tests\Support\Tasks');

        $console->handle(
            [
                'task'   => 'issue787',
                'action' => 'main',
            ]
        );

        $this->assertSame(
            'beforeExecuteRoute' . PHP_EOL . 'initialize' . PHP_EOL,
            Issue787Task::$output
        );
    }

    /**
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function testCliConsoleHandleEventAfterHandleTask(): void
    {
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
                    'path'      => supportDir('Modules/Frontend/Module.php'),
                ],
                'backend'  => [
                    'className' => BackendModule::class,
                    'path'      => supportDir('Modules/Backend/Module.php'),
                ],
            ]
        );
        $console->dispatcher->setNamespaceName('Phalcon\Tests\Support\Modules\Backend\Tasks');

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Console After Handle Task Event Fired'
        );

        $console->handle(
            [
                'module' => 'backend',
                'action' => 'noop',
            ]
        );
    }

    /**
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function testCliConsoleHandleEventAfterStartModule(): void
    {
        $console = new CliConsole(new DiFactoryDefault());

        $eventsManager = $console->eventsManager;

        $console->registerModules(
            [
                'frontend' => [
                    'className' => FrontendModule::class,
                    'path'      => supportDir('Modules/Frontend/Module.php'),
                ],
                'backend'  => [
                    'className' => BackendModule::class,
                ],
            ]
        );

        $console->dispatcher->setNamespaceName('Phalcon\Tests\Support\Modules\Backend\Tasks');

        $eventsManager->attach(
            'console:afterStartModule',
            function (Event $event, $console, $moduleObject) {
                throw new Exception('Console After Start BackendModule Event Fired');
            }
        );

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Console After Start BackendModule Event Fired'
        );

        $console->handle(
            [
                'module' => 'backend',
                'action' => 'noop',
            ]
        );
    }

    /**
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function testCliConsoleHandleEventBeforeHandleTask(): void
    {
        $console = new CliConsole(new DiFactoryDefault());

        $eventsManager = $console->eventsManager;

        $eventsManager->attach(
            'console:beforeHandleTask',
            function (Event $event, $console, $moduleObject) {
                throw new Exception('Console Before Handle Task Event Fired');
            }
        );

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Console Before Handle Task Event Fired'
        );

        $console->handle([]);
    }

    /**
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function testCliConsoleHandleEventBeforeStartModule(): void
    {
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
                    'path'      => supportDir('Modules/Frontend/Module.php'),
                ],
                'backend'  => [
                    'className' => BackendModule::class,
                ],
            ]
        );

        $console->dispatcher->setNamespaceName('Phalcon\Tests\Support\Modules\Backend\Tasks');

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Console Before Start BackendModule Event Fired'
        );

        $console->handle(
            [
                'module' => 'backend',
                'action' => 'noop',
            ]
        );
    }

    /**
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function testCliConsoleHandleEventBoot(): void
    {
        $console = new CliConsole(new DiFactoryDefault());

        $eventsManager = $console->eventsManager;

        $eventsManager->attach(
            'console:boot',
            function (Event $event, $console) {
                throw new Exception('Console Boot Event Fired');
            }
        );

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Console Boot Event Fired');

        $console->handle();
    }

    /**
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function testCliConsoleHandleModule(): void
    {
        $console = new CliConsole(new DiFactoryDefault());

        $console->registerModules(
            [
                'frontend' => [
                    'className' => FrontendModule::class,
                    'path'      => supportDir('Modules/Frontend/Module.php'),
                ],
                'backend'  => [
                    'className' => BackendModule::class,
                    'path'      => supportDir('Modules/Backend/Module.php'),
                ],
            ]
        );

        $dispatcher = $console->dispatcher;
        $dispatcher->setNamespaceName('Phalcon\Tests\Support\Modules\Backend\Tasks');

        try {
            $console->handle(
                [
                    'module' => 'backend',
                    'action' => 'throw',
                ]
            );
            $this->fail('Expected Exception was not thrown');
        } catch (Exception $e) {
            $this->assertSame('Task Run', $e->getMessage());
        }

        $expected = 'main';
        $actual   = $dispatcher->getTaskName();
        $this->assertSame($expected, $actual);

        $expected = 'throw';
        $actual   = $dispatcher->getActionName();
        $this->assertSame($expected, $actual);

        $expected = 'backend';
        $actual   = $dispatcher->getModuleName();
        $this->assertSame($expected, $actual);
    }

    public function testCliConsoleHandleModuleDoesNotExists(): void
    {
        $console = new CliConsole(new DiFactoryDefault());

        $this->expectException(ConsoleException::class);
        $this->expectExceptionMessage(
            "Module 'devtools' isn't registered in the console container"
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

    /**
     * @issue 16186
     */
    public function testCliConsoleHandleNoAction(): void
    {
        $module   = '';
        if (!env('GITHUB_RUN_ID')) {
            $module = '-d extension=' . rootDir() . 'ext/modules/phalcon.so ';
        }
        $script = rootDir() . 'tests/testbed/cli.php ';

        ob_start();
        $actual = shell_exec('php ' . $module . $script . 'print');
        ob_end_clean();

        $expected = 'printMainAction';
        $this->assertSame($expected, $actual);
    }

    public function testCliConsoleHandleTaskDoesNotExists(): void
    {
        $console = new CliConsole(new DiFactoryDefault());

        $console->dispatcher->setDefaultNamespace('Dummy\\');

        $this->expectException(DispatcherException::class);
        $this->expectExceptionMessage(
            "Dummy\MainTask handler class cannot be loaded",
        );
        $this->expectExceptionCode(2);

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

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testCliConsoleHandleNoDi(): void
    {
        $this->expectException(ConsoleException::class);
        $this->expectExceptionMessage(
            'A dependency injection container is required to access internal services'
        );

        $console = new CliConsole();
        $console->handle();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testCliConsoleHandleBootEventReturnsFalse(): void
    {
        $console       = new CliConsole(new DiFactoryDefault());
        $eventsManager = $console->eventsManager;

        $eventsManager->attach(
            'console:boot',
            function () {
                return false;
            }
        );

        $actual = $console->handle();
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testCliConsoleHandleBeforeStartModuleReturnsFalse(): void
    {
        $console       = new CliConsole(new DiFactoryDefault());
        $eventsManager = $console->eventsManager;

        $console->registerModules(
            [
                'backend' => [
                    'className' => BackendModule::class,
                    'path'      => supportDir('Modules/Backend/Module.php'),
                ],
            ]
        );

        $eventsManager->attach(
            'console:beforeStartModule',
            function () {
                return false;
            }
        );

        $actual = $console->handle(['module' => 'backend']);
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testCliConsoleHandleInvalidModuleDefinition(): void
    {
        $this->expectException(ConsoleException::class);
        $this->expectExceptionMessage('Invalid module definition path');

        $console = new CliConsole(new DiFactoryDefault());

        // Register a module as a non-array value
        $console->registerModules(['backend' => 'not-an-array']);

        $console->handle(['module' => 'backend']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testCliConsoleHandleAfterStartModuleReturnsFalse(): void
    {
        $console       = new CliConsole(new DiFactoryDefault());
        $eventsManager = $console->eventsManager;

        $console->registerModules(
            [
                'backend' => [
                    'className' => BackendModule::class,
                    'path'      => supportDir('Modules/Backend/Module.php'),
                ],
            ]
        );

        $eventsManager->attach(
            'console:afterStartModule',
            function () {
                return false;
            }
        );

        $actual = $console->handle(['module' => 'backend']);
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testCliConsoleHandleBeforeHandleTaskReturnsFalse(): void
    {
        $console       = new CliConsole(new DiFactoryDefault());
        $eventsManager = $console->eventsManager;

        $eventsManager->attach(
            'console:beforeHandleTask',
            function () {
                return false;
            }
        );

        $actual = $console->handle([]);
        $this->assertFalse($actual);
    }
}
