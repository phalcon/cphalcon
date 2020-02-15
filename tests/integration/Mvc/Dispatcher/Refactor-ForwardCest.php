<?php

namespace Phalcon\Test\Integration\Mvc\Dispatcher;

use IntegrationTester;
use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Application;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\View;

use function dataDir;

/**
 * \Phalcon\Test\Integration\Mvc\Dispatcher\ForwardCest
 * Tests the Phalcon\Mvc\Dispatcher
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          http://www.phalcon.io
 * @author        Phalcon Team <team@phalcon.io>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalcon.io
 * so that we can send you a copy immediately.
 */
class RefactorForwardCest
{
    /**
     * @issue https://github.com/phalcon/cphalcon/issues/11819
     */
    public function handlingException(IntegrationTester $I)
    {
        $di = new FactoryDefault();

        $di->set(
            'view',
            function () {
                $view = new View();

                $view->setViewsDir(
                    dataDir('fixtures/views/')
                );

                return $view;
            },
            true
        );

        $eventsManager = new Manager();

        $eventsManager->attach(
            'dispatch:beforeException',
            function ($event, $dispatcher, $exception) {
                $dispatcher->forward(
                    [
                        'namespace'  => 'Phalcon\Test\Controllers',
                        'controller' => 'exception',
                        'action'     => 'second',
                    ]
                );

                // Prevent the exception from bubbling
                return false;
            }
        );

        $dispatcher = new Dispatcher();

        $dispatcher->setEventsManager($eventsManager);

        $di->setShared('dispatcher', $dispatcher);

        $application = new Application();

        $application->setEventsManager(
            new Manager()
        );

        $application->setDI($di);

        $response = $application->handle('/exception');

        $I->assertSame(
            'I should be displayed',
            $response->getContent()
        );
    }
}
