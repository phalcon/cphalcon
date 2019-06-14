<?php

namespace Phalcon\Test\Integration\Mvc\Dispatcher\Helper;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Http\Response;
use Phalcon\Mvc\Dispatcher;

/**
 * \Phalcon\Test\Integration\Mvc\Dispatcher\Helper\BaseDispatcher
 * Base IntegrationTest to assist with testing various \Phalcon\Dispatcher,
 * Phalcon\Mvc\Dispatcher, and other related components.
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          http://www.phalconphp.com
 * @author        Andres Gutierrez <andres@phalconphp.com>
 * @author        Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
abstract class BaseDispatcher
{
    /**
     * @var Di
     */
    private $di;

    /**
     * Executed before each test.
     *
     * Ensure the depenendency injector and corresponding services including
     * the
     * dispatcher, response, and dispatcher listener are reset prior to each
     * test.
     */
    public function _before(IntegrationTester $I)
    {
        $dispatcherListener = new DispatcherListener();

        Di::reset();

        $this->di = new Di();

        $this->di->setShared(
            'response',
            new Response()
        );

        $this->di->setShared(
            'dispatcherListener',
            $dispatcherListener
        );

        $this->di->setShared(
            'dispatcher',
            function () use ($dispatcherListener) {
                // New dispatcher instance
                $dispatcher = new Dispatcher();

                // Initialize defaults such that these don't need to be specified everywhere
                $dispatcher->setNamespaceName('Phalcon\Test\Integration\Mvc\Dispatcher\Helper');
                $dispatcher->setControllerName('dispatcher-test-default');
                $dispatcher->setActionName('index');

                // Ensure this gets called prior to any custom event listening which has a default priority of 100
                $eventsManager = new EventsManager();

                $eventsManager->attach(
                    'dispatch',
                    $dispatcherListener,
                    200
                );

                $dispatcher->setEventsManager($eventsManager);

                return $dispatcher;
            }
        );
    }

    /**
     * Returns the current Dependency Injector.
     */
    protected function getDI(): Di
    {
        return $this->di;
    }

    /**
     * Returns the current dispatcher instance.
     */
    protected function getDispatcher(): Dispatcher
    {
        return $this->di->getShared('dispatcher');
    }

    /**
     * Returns the current dispatcher listener instance.
     */
    protected function getDispatcherListener(): DispatcherListener
    {
        return $this->di->getShared('dispatcherListener');
    }
}
