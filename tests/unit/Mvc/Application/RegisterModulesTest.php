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

namespace Phalcon\Tests\Unit\Mvc\Application;

use Phalcon\Di\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Application;
use Phalcon\Mvc\Application\Exception;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\View;
use Phalcon\Tests\Support\Modules\Backend\Module as BackendModule;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Modules\Frontend\Module as FrontendModule;

final class RegisterModulesTest extends AbstractUnitTestCase
{
    public function tearDown(): void
    {
        Di::reset();
    }

    public function testModulesDefinition(): void
    {
        Di::reset();

        $di = new FactoryDefault();

        $di->set(
            'router',
            function () {
                $router = new Router(false);

                $router->add(
                    '/index',
                    [
                        'controller' => 'index',
                        'module'     => 'frontend',
                        'namespace'  => 'Phalcon\Tests\Support\Modules\Frontend\Controllers',
                    ]
                );

                return $router;
            }
        );

        $application = new Application();

        $application->registerModules(
            [
                'frontend' => [
                    'path'      => supportDir('Modules/Frontend/Module.php'),
                    'className' => FrontendModule::class,
                ],
                'backend'  => [
                    'path'      => supportDir('Modules/Backend/Module.php'),
                    'className' => BackendModule::class,
                ],
            ]
        );

        $application->setDI($di);

        $response = $application->handle('/index');

        $expected = '<html>here</html>' . PHP_EOL;
        $actual   = $response->getContent();
        $this->assertEquals($expected, $actual);
    }

    public function testModulesClosure(): void
    {
        Di::reset();

        $di = new FactoryDefault();

        $di->set(
            'router',
            function () {
                $router = new Router(false);

                $router->add(
                    '/index',
                    [
                        'controller' => 'index',
                        'module'     => 'frontend',
                        'namespace'  => 'Phalcon\Tests\Support\Modules\Frontend\Controllers',
                    ]
                );

                $router->add(
                    '/login',
                    [
                        'controller' => 'login',
                        'module'     => 'backend',
                        'namespace'  => 'Phalcon\Tests\Support\Modules\Backend\Controllers',
                    ]
                );

                return $router;
            }
        );

        $application = new Application();
        $view        = new View();

        $application->registerModules(
            [
                'frontend' => function (DiInterface $di) use ($view) {
                    $di->set(
                        'view',
                        function () use ($view) {
                            $view->setViewsDir(
                                supportDir('Modules/Frontend/views/')
                            );

                            return $view;
                        }
                    );
                },
                'backend'  => function (DiInterface $di) use ($view) {
                    $di->set(
                        'view',
                        function () use ($view) {
                            $view->setViewsDir(
                                supportDir('Modules/Backend/views/')
                            );

                            return $view;
                        }
                    );
                },
            ]
        );

        $application->setDI($di);

        $response = $application->handle('/login');

        $expected = '<html>here</html>' . PHP_EOL;
        $actual   = $response->getContent();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-15
     */
    public function testMvcApplicationRegisterModulesBadPathThrowsAnException(): void
    {
        Di::reset();

        $di = new FactoryDefault();

        $di->set(
            'router',
            function () {
                $router = new Router(false);

                $router->add(
                    '/index',
                    [
                        'controller' => 'index',
                        'module'     => 'frontend',
                        'namespace'  => 'Phalcon\Tests\Support\Modules\Frontend\Controllers',
                    ]
                );

                return $router;
            }
        );

        $application = new Application();

        $application->registerModules(
            [
                'frontend' => [
                    'path'      => supportDir('not-a-real-file.php'),
                    'className' => FrontendModule::class,
                ],
            ]
        );

        $application->setDI($di);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Module definition path '"
            . supportDir('not-a-real-file.php')
            . "' does not exist"
        );

        $application->handle('/index');
    }
}
