<?php

namespace Phalcon\Test\Integration\Mvc;

use Phalcon\Di;
use IntegrationTester;
use Phalcon\Mvc\View;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Application;
use Phalcon\Di\FactoryDefault;

/**
 * \Phalcon\Test\Integration\Mvc\ApplicationCest
 * Tests the Phalcon\Mvc\Application component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Integration\Mvc
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
        $I->wantTo('handle request and get content by using single modules strategy');

        $di = new FactoryDefault();
        $di->set('view', function () {
            $view = new View();
            $view->setViewsDir(PATH_DATA . 'views/');

            return $view;
        }, true);

        $application = new Application();
        $application->setDI($di);

        $_GET['_url'] = '/test2';
        $I->assertEquals('<html>We are here</html>' . PHP_EOL, $application->handle()->getContent());
    }

    public function modulesDefinition(IntegrationTester $I)
    {
        $I->wantTo('handle request and get content by using single modules strategy (standard definition)');

        Di::reset();
        $_GET['_url'] = '/index';

        $di = new FactoryDefault();
        $di->set('router', function () {
            $router = new Router(false);

            $router->add('/index', [
                'controller' => 'index',
                'module'     => 'frontend',
                'namespace'  => 'Phalcon\Test\Modules\Frontend\Controllers'
            ]);

            return $router;
        });

        $application = new Application();

        $application->registerModules([
            'frontend' => [
                'path'      => PATH_DATA . 'modules/frontend/Module.php',
                'className' => 'Phalcon\Test\Modules\Frontend\Module',
            ],
            'backend' => [
                'path'      => PATH_DATA . 'modules/backend/Module.php',
                'className' => 'Phalcon\Test\Modules\Backend\Module',
            ],
        ]);

        $application->setDI($di);
        $I->assertEquals('<html>here</html>' . PHP_EOL, $application->handle()->getContent());
    }

    public function modulesClosure(IntegrationTester $I)
    {
        $I->wantTo('handle request and get content by using single modules strategy (closure)');

        Di::reset();
        $_GET['_url'] = '/login';

        $di = new FactoryDefault();
        $di->set('router', function () {
            $router = new Router(false);

            $router->add('/index', [
                'controller' => 'index',
                'module'     => 'frontend',
                'namespace'  => 'Phalcon\Test\Modules\Frontend\Controllers'
            ]);

            $router->add('/login', [
                'controller' => 'login',
                'module'     => 'backend',
                'namespace'  => 'Phalcon\Test\Modules\Backend\Controllers'
            ]);

            return $router;
        });

        $application = new Application();
        $view = new View();

        $application->registerModules([
            'frontend' => function ($di) use ($view) {
                /** @var \Phalcon\DiInterface $di */
                $di->set('view', function () use ($view) {
                    $view->setViewsDir(PATH_DATA . 'modules/frontend/views/');
                    return $view;
                });
            },
            'backend' => function ($di) use ($view) {
                /** @var \Phalcon\DiInterface $di */
                $di->set('view', function () use ($view) {
                    $view->setViewsDir(PATH_DATA . 'modules/backend/views/');
                    return $view;
                });
            },
        ]);

        $application->setDI($di);
        $I->assertEquals('<html>here</html>' . PHP_EOL, $application->handle()->getContent());
    }
}
