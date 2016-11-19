<?php

namespace Phalcon\Test\Unit\Mvc;


use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Http\Response;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Mvc\DispatcherTest
 * Tests the Phalcon\Mvc\Dispatcher component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class DispatcherTest extends UnitTest
{
    /**
     * Tests after binding event
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-11-19
     */
    public function testAfterBindingEvent()
    {
        $this->specify(
            'afterBinding event should be fired',
            function () {
                $di = new FactoryDefault();
                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                $manager = new Manager();
                $manager->attach(
                    'dispatch:afterBinding',
                    function (Event $event, Dispatcher $dispatcher) {
                        $response = new Response();
                        $response->setContent('test');
                        $dispatcher->setReturnedValue($response);

                        return false;
                    }
                );
                $dispatcher->setEventsManager($manager);
                $dispatcher->setActionName('index');
                $dispatcher->setControllerName('test2');
                $dispatcher->dispatch();
                expect($dispatcher->getReturnedValue()->getContent())->equals('test');
            }
        );
    }

    /**
     * Tests after binding callback
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-11-19
     */
    public function testAfterBindingCallback()
    {
        $this->specify(
            'afterBinding callback should be called',
            function () {
                $di = new FactoryDefault();
                $dispatcher = new Dispatcher();
                $dispatcher->setDI($di);
                $dispatcher->setActionName('index');
                $dispatcher->setControllerName('test12');
                $dispatcher->dispatch();
                expect($dispatcher->getReturnedValue())->isEmpty();
            }
        );
    }
}
