<?php

namespace Phalcon\Tests\Unit\Mvc\Dispatcher\Helper;

use Phalcon\Di\Di;
use Phalcon\Dispatcher\DispatcherInterface;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Http\Response;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Tests\AbstractUnitTestCase;

/**
 * @author        Andres Gutierrez <andres@phalcon.io>
 * @author        Nikolaos Dimopoulos <nikos@phalcon.io>
 */
abstract class BaseDispatcher extends AbstractUnitTestCase
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
    public function setUp(): void
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
                $dispatcher->setNamespaceName('Phalcon\Tests\Unit\Mvc\Dispatcher\Helper');
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
    protected function getDispatcher(): DispatcherInterface
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
