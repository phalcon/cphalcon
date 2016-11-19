<?php

namespace Phalcon\Test\Unit\Mvc;

use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Micro;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Mvc\MicroTest
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
class MicroTest extends UnitTest
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
                $micro = new Micro($di);
                $manager = new Manager();
                $manager->attach(
                    'micro:afterBinding',
                    function (Event $event, Micro $micro) {
                        return false;
                    }
                );
                $micro->setEventsManager($manager);
                $micro->get(
                    '/test',
                    function () {
                        return 'test';
                    }
                );
                expect($micro->handle('/test'))->isEmpty();
            }
        );
    }

    /**
     * Tests after binding middleware
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-11-19
     */
    public function tesAfterBindingMiddleware()
    {
        $this->specify(
            'afterBinding middleware should be called',
            function () {
                $di = new FactoryDefault();
                $micro = new Micro($di);
                $micro->afterBinding(
                    function () {
                        return false;
                    }
                );
                $micro->get(
                    '/test',
                    function () {
                        return 'test';
                    }
                );
                expect($micro->handle('/test'))->isEmpty();
            }
        );
    }
}
