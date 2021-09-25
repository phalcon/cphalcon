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

namespace Phalcon\Tests\Integration\Mvc\Dispatcher\Refactor;

use Exception;
use IntegrationTester;
use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Application;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\View;

/**
 * Class RefactorForwardCest
 *
 * @package Phalcon\Tests\Integration\Mvc\Dispatcher
 * @todo: refactor
 */
class ForwardCest
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
                        'namespace'  => 'Phalcon\Tests\Controllers',
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
