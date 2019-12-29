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

namespace Phalcon\Test\Integration\Mvc\Application;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Application;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\View;
use Phalcon\Test\Modules\Backend\Module;

class RegisterModulesCest
{
    public function modulesDefinition(IntegrationTester $I)
    {
        $I->wantTo(
            'handle request and get content by using single modules strategy (standard definition)'
        );

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
                        'namespace'  => 'Phalcon\Test\Modules\Frontend\Controllers',
                    ]
                );

                return $router;
            }
        );

        $application = new Application();

        $application->registerModules(
            [
                'frontend' => [
                    'path'      => dataDir('fixtures/modules/frontend/Module.php'),
                    'className' => \Phalcon\Test\Modules\Frontend\Module::class,
                ],
                'backend'  => [
                    'path'      => dataDir('fixtures/modules/backend/Module.php'),
                    'className' => Module::class,
                ],
            ]
        );

        $application->setDI($di);

        $response = $application->handle('/index');

        $I->assertEquals(
            '<html>here</html>' . PHP_EOL,
            $response->getContent()
        );
    }

    public function modulesClosure(IntegrationTester $I)
    {
        $I->wantTo(
            'handle request and get content by using single modules strategy (closure)'
        );

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
                        'namespace'  => 'Phalcon\Test\Modules\Frontend\Controllers',
                    ]
                );

                $router->add(
                    '/login',
                    [
                        'controller' => 'login',
                        'module'     => 'backend',
                        'namespace'  => 'Phalcon\Test\Modules\Backend\Controllers',
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
                                dataDir('fixtures/modules/frontend/views/')
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
                                dataDir('fixtures/modules/backend/views/')
                            );

                            return $view;
                        }
                    );
                },
            ]
        );

        $application->setDI($di);

        $response = $application->handle('/login');

        $I->assertEquals(
            '<html>here</html>' . PHP_EOL,
            $response->getContent()
        );
    }

    /**
     * Tests Phalcon\Mvc\Application :: registerModules() - bad path throws
     * exception
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-15
     */
    public function mvcApplicationRegisterModulesBadPathThrowsAnException(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Application - registerModules() - bad path throws exception");

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
                        'namespace'  => 'Phalcon\Test\Modules\Frontend\Controllers',
                    ]
                );

                return $router;
            }
        );

        $application = new Application();

        $application->registerModules(
            [
                'frontend' => [
                    'path'      => dataDir('not-a-real-file.php'),
                    'className' => \Phalcon\Test\Modules\Frontend\Module::class,
                ],
            ]
        );

        $application->setDI($di);

        $I->expectException(
            new \Phalcon\Mvc\Application\Exception(
                "Module definition path '" . dataDir('not-a-real-file.php') . "' doesn't exist"
            ),
            function () use ($application) {
                $application->handle('/index');
            }
        );
    }
}
