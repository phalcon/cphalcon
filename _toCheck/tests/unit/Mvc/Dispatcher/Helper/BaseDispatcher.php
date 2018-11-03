<?php

namespace Phalcon\Test\Unit\Mvc\Dispatcher\Helper;

use Phalcon\Di;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Http\Response;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Unit\Mvc\Dispatcher\Helper\DispatcherListener;

/**
 * \Phalcon\Test\Unit\Mvc\Dispatcher\Helper\BaseDispatcher
 * Base UnitTest to assist with testing various \Phalcon\Dispatcher, Phalcon\Mvc\Dispatcher, and
 * other related components.
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\Dispatcher\Helper
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
abstract class BaseDispatcher extends UnitTest
{
    /**
     * @var \Phalcon\Di
     */
    private $di;

    /**
     * Executed before each test.
     *
     * Ensure the depenendency injector and corresponding services including the
     * dispatcher, response, and dispatcher listener are reset prior to each test.
     */
    protected function _before()
    {
        parent::_before();

        $dispatcherListener = new DispatcherListener();

        Di::reset();
        $this->di = new Di();
        $this->di->setShared('response', new Response());
        $this->di->setShared('dispatcherListener', $dispatcherListener);
        $this->di->setShared('dispatcher', function () use ($dispatcherListener) {
            // New dispatcher instance
            $dispatcher = new Dispatcher();

            // Initialize defaults such that these don't need to be specified everywhere
            $dispatcher->setNamespaceName('Phalcon\Test\Unit\Mvc\Dispatcher\Helper');
            $dispatcher->setControllerName('dispatcher-test-default');
            $dispatcher->setActionName('index');

            // Ensure this gets called prior to any custom event listening which has a default priority of 100
            $eventsManager = new EventsManager();
            $eventsManager->attach('dispatch', $dispatcherListener, 200);

            $dispatcher->setEventsManager($eventsManager);

            return $dispatcher;
        });
    }

    /**
     * Returns the current Dependency Injector.
     *
     * @return \Phalcon\Di
     */
    protected function getDI()
    {
        return $this->di;
    }

    /**
     * Returns the current dispatcher instance.
     *
     * @return \Phalcon\Mvc\Dispatcher
     */
    protected function getDispatcher()
    {
        return $this->di->getShared('dispatcher');
    }

    /**
     * Returns the current dispatcher listener instance.
     *
     * @return \Phalcon\Test\Unit\Mvc\Dispatcher\Helper\DispatcherListener
     */
    protected function getDispatcherListener()
    {
        return $this->di->getShared('dispatcherListener');
    }
}
