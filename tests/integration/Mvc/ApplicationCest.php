<?php

namespace Phalcon\Test\Integration\Mvc;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Application;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\View;

/**
 * \Phalcon\Test\Integration\Mvc\ApplicationCest
 * Tests the Phalcon\Mvc\Application component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          http://www.phalconphp.com
 * @author        Andres Gutierrez <andres@phalconphp.com>
 * @author        Phalcon Team <team@phalconphp.com>
 * @package       Phalcon\Test\Integration\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ApplicationCest
{
    public function singleModule(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check me');
        $I->wantTo('handle request and get content by using single modules strategy');

        $di = new FactoryDefault();
        $di->set('view', function () {
            $view = new View();
            $view->setViewsDir(dataFolder('fixtures/views/'));

            return $view;
        }, true);

        $application = new Application();
        $application->setDI($di);

        $response = $application->handle("/micro");

        $I->assertEquals('<html>We are here</html>' . PHP_EOL, $response->getContent());
    }

    public function modulesDefinition(IntegrationTester $I)
    {
        $I->wantTo('handle request and get content by using single modules strategy (standard definition)');

        Di::reset();

        $di = new FactoryDefault();
        $di->set('router', function () {
            $router = new Router(false);

            $router->add('/index', [
                'controller' => 'index',
                'module'     => 'frontend',
                'namespace'  => 'Phalcon\Test\Modules\Frontend\Controllers',
            ]);

            return $router;
        });

        $application = new Application();

        $application->registerModules([
            'frontend' => [
                'path'      => dataFolder('fixtures/modules/frontend/Module.php'),
                'className' => 'Phalcon\Test\Modules\Frontend\Module',
            ],
            'backend'  => [
                'path'      => dataFolder('fixtures/modules/backend/Module.php'),
                'className' => 'Phalcon\Test\Modules\Backend\Module',
            ],
        ]);

        $application->setDI($di);

        $response = $application->handle("/index");

        $I->assertEquals('<html>here</html>' . PHP_EOL, $response->getContent());
    }

    public function modulesClosure(IntegrationTester $I)
    {
        $I->wantTo('handle request and get content by using single modules strategy (closure)');

        Di::reset();

        $di = new FactoryDefault();
        $di->set('router', function () {
            $router = new Router(false);

            $router->add('/index', [
                'controller' => 'index',
                'module'     => 'frontend',
                'namespace'  => 'Phalcon\Test\Modules\Frontend\Controllers',
            ]);

            $router->add('/login', [
                'controller' => 'login',
                'module'     => 'backend',
                'namespace'  => 'Phalcon\Test\Modules\Backend\Controllers',
            ]);

            return $router;
        });

        $application = new Application();
        $view        = new View();

        $application->registerModules([
            'frontend' => function ($di) use ($view) {
                /** @var \Phalcon\DiInterface $di */
                $di->set('view', function () use ($view) {
                    $view->setViewsDir(dataFolder('fixtures/modules/frontend/views/'));
                    return $view;
                });
            },
            'backend'  => function ($di) use ($view) {
                /** @var \Phalcon\DiInterface $di */
                $di->set('view', function () use ($view) {
                    $view->setViewsDir(dataFolder('fixtures/modules/backend/views/'));
                    return $view;
                });
            },
        ]);

        $application->setDI($di);

        $response = $application->handle("/login");

        $I->assertEquals('<html>here</html>' . PHP_EOL, $response->getContent());
    }
}
