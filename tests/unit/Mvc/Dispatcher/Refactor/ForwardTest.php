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

namespace Phalcon\Tests\Unit\Mvc\Dispatcher\Refactor;

use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Application;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\View;
use Phalcon\Tests\AbstractUnitTestCase;

/**
 * @todo    : refactor
 */
class ForwardTest extends AbstractUnitTestCase
{
    /**
     * @issue https://github.com/phalcon/cphalcon/issues/11819
     */
    public function testMvcDispatcherDispatchLoopEventsWithForward(): void
    {
        $di = new FactoryDefault();

        $di->set(
            'view',
            function () {
                $view = new View();

                $view->setViewsDir(
                    supportDir('assets/views/')
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
                        'namespace' => 'Phalcon\Tests\Support\Controllers',
                        'controller' => 'exception',
                        'action' => 'second',
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
        $application->setEventsManager(new Manager());
        $application->setDI($di);

        $response = $application->handle('/exception');

        $this->assertSame('I should be displayed', $response->getContent());

        /**
         * Close buffers
         */
        $di->getShared('view')->finish();
    }
}
