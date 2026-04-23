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

use Exception;
use Phalcon\Mvc\Application;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\View;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class HandleTest extends AbstractUnitTestCase
{
    use DiTrait;

    private int $obLevel = 0;

    protected function setUp(): void
    {
        parent::setUp();
        $this->obLevel = ob_get_level();
    }

    protected function tearDown(): void
    {
        while (ob_get_level() > $this->obLevel) {
            ob_end_clean();
        }
        parent::tearDown();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-17
     */
    public function testMvcApplicationHandleDispatcherException(): void
    {
        $this->setNewFactoryDefault();

        $this->container->set(
            'view',
            function () {
                $view = new View();

                $view->setViewsDir(
                    supportDir('assets/views/simple/')
                );

                return $view;
            },
            true
        );

        $eventsManager = $this->container->getShared('eventsManager');

        $this->container->set(
            'dispatcher',
            function () use ($eventsManager) {
                $dispatcher = new Dispatcher();
                $dispatcher->setDefaultNamespace(
                    'Phalcon\Tests\Support\Controllers'
                );

                $eventsManager->attach(
                    'dispatch:beforeException',
                    function ($event, $dispatcher, $exception) {
                        $dispatcher->setReturnedValue(
                            'whoops: ' . $exception->getMessage()
                        );

                        return false;
                    }
                );

                $dispatcher->setEventsManager($eventsManager);

                return $dispatcher;
            }
        );

        $application = new Application();
        $application->setDI($this->container);

        $response = $application->handle('/exception');

        $expected = 'whoops: whups bad controller';
        $actual   = $response->getContent();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-17
     */
    public function testMvcApplicationHandleDispatcherExceptionForward(): void
    {
        $this->setNewFactoryDefault();

        $this->container->set(
            'view',
            function () {
                $view = new View();

                $view->setViewsDir(
                    supportDir('assets/views/simple/')
                );

                return $view;
            },
            true
        );

        $eventsManager = $this->container->getShared('eventsManager');

        $this->container->set(
            'dispatcher',
            function () use ($eventsManager) {
                $dispatcher = new Dispatcher();
                $dispatcher->setDefaultNamespace(
                    'Phalcon\Tests\Support\Controllers'
                );

                $eventsManager->attach(
                    'dispatch:beforeException',
                    function ($event, $dispatcher, $exception) {
                        switch ($exception->getCode()) {
                            case Dispatcher\Exception::EXCEPTION_HANDLER_NOT_FOUND:
                            case Dispatcher\Exception::EXCEPTION_ACTION_NOT_FOUND:
                                $dispatcher->forward([
                                    'controller' => 'init',
                                    'action'     => 'index',
                                ]);

                                return false;
                        }
                    }
                );

                $dispatcher->setEventsManager($eventsManager);

                return $dispatcher;
            }
        );

        $application = new Application();
        $application->setDI($this->container);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Initialize called');

        $application->handle('/not-found');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-01
     */
    public function testMvcApplicationHandleSingleModule(): void
    {
        $this->setNewFactoryDefault();

        $this->container->set(
            'view',
            function () {
                $view = new View();

                $view->setViewsDir(
                    supportDir('assets/views/simple/')
                );

                return $view;
            },
            true
        );

        $this->container->set(
            'dispatcher',
            function () {
                $dispatcher = new Dispatcher();
                $dispatcher->setDefaultNamespace(
                    'Phalcon\Tests\Support\Controllers'
                );

                return $dispatcher;
            }
        );

        $application = new Application();
        $application->setDI($this->container);

        $response = $application->handle('/micro');

        $expected = 'We are here';
        $actual   = $response->getContent();
        $this->assertSame($expected, $actual);
    }
}
